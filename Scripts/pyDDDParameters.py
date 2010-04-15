#*******************************************************************
#   Copyright 2002-2008  LSI Corporation
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#*******************************************************************
#
#--------------------------------------------------------------------
# Part of DoxData2Desc
#   Patch the parameter directions
#--------------------------------------------------------------------
#

import string
import copy
import sys
import re
import types

#--------------------------------------------------------------------
# Function Parameter direction, as use is determined from the
# argument type of the parameter. The following table summarizes
# how this is done:
#
#         BorrowClasses              OwnClasses   
# tag     Param    ReturnValue       Param    ReturnValue
# -------------------------------------------------------
# simple   X       X                 param    out
# cptr     param   out               special  special
# ptr      param   out               special  special
# ptrref   param   X                 X        X
# ref      X       X                 param    param
# cref     X       X                 param    out
#
# tag - is how the value is passed:
#   simple - this is pass by value:  void fun(TYPE param)
#   cptr   - const pointer:          void fun(const TYPE* param)
#   ptr    - pointer:                void fun(TYPE* param)
#   ptrref - reference to pointer:   void fun(TYPE*& param)
#   ref    - reference               void fun(TYPE& param)
#   cref   - const reference         void fun(const TYPE& param)
# These are the only type supported. Parameter passing other than
# these is not supported by the translator.
#
# Classes are divided into 2 categories:
#   BorrowClasses - For these OpenAcces owns the object.
#                   The end application only has pointers to the objects.
#                   Examples: oaCellView, oaNet,
#   OwnClasses    - For these the application owns the objects memory.
#                   The end application can call the constructors.
#                   Examples: oaString, oaScalarName.
#
# The pass types given in the table above are:
#   param - a parameter
#   out   - an output return value
#   X     - Not supported. Functions with this type will generate
#           translator function link warnings, and will not be translated.
#   special - Special case, more details are required:
#     case 1: Parameters must have one of the following hints:
#       aof - The variable is passed by address, even though
#                    it is of an OwnClasses type.
#                    Passing it's address if OK.
#       lock - The current object keeps a reference to the original python object.
#       record - The parameters value needs to be recorded in the python object.
#       copy - The variable is passed by address, and the routine will
#                     own the memory, so create a new copy to give it.
#       check - The pointer is a pointer to an array of objects.
#                      From Python a list will be required.
#                      The length of the list must match a
#                      specified constraint.
#       pre - The pointer is a pointer to an array of objects.
#                      From Python a list will be required.
#                      The length of the list is passed as a parameter
#                      before the list.
#       post - The pointer is a pointer to an array of objects.
#                      From Python a list will be required.
#                      The length of the list is passed as a parameter
#                      after the list.
#       novalidate - Allow a NULL DB value.
#  
#     case 2: Output function return value must have one of the following hints:
#       init  - The pointer points to an output array.
#                    The result will be a python list of objects.
#                    The original python object must be locked.
#                    The constraint determines how the list is sized.
#       dref -  The output pointer points to a new object that can
#                    be used as is, but we don't own the memory.
#                    The orginal python object must be locked.
#       alloc - The output pointer points to a new object that
#                    can be used as is, but we now own the memory.
#       borrow - The output pointer points to a new object that
#                    can be used as is, but we don't own the memory.
#                    This is the same as ptr, but no lock happens.
#       copy - The output point points to existing memory that is const.
#                    The memory should be copied to make a new object.
#       rmconst - The return value is const DB pointer, and it is safe
#                 to remove the const.
#
#   simple return values result in a getfuns when there is a matching
#    setfun call.
#
#  Some classes required that data other that the object pointer be
#  recorded in python. This is specified with the 'record' hint.
#--------------------------------------------------------------------

IN=0
OUT=1
BI=2
        
# ==========================================
# Build Function Return value
def PrepareReturnValue(data,fun,clsname):
  funsig=fun['sig']
  funname=fun['name']
  pvalue=fun['type_link']
  rtag=pvalue['utag'] # use tag

  if (rtag!='void'):
    rcls=pvalue['cls']
    iscls=pvalue['iscls']
    db=pvalue['isdb']
    fun['value']=rcls['name']
    fun['value_tag']=pvalue['tag']
    fun['value_utag']=pvalue['utag']
    hints=data.vGetParameterHintData(clsname,funsig)
    if (fun.get('manual',0)):
      pass
    elif (hints and hints[0].has_key('init')):
      fun['value_init']=hints[0]['init']
      if (not rcls.has_key('array')): 
        rcls['array']='auto'
    elif (hints and hints[0].has_key('dref')):
      fun['value_dref']=1
    elif (hints and hints[0].has_key('alloc')):
      fun['value_alloc']=1
    elif (hints and hints[0].has_key('copy')):
      fun['value_copy']=1
    elif (hints and hints[0].has_key('borrow')):
      fun['value_borrow']=1
    elif (iscls and rcls.has_key('size') and ((rtag=='ptr' or rtag=='cptr'))):
      fun['value_init']=rcls['size']
      if (not rcls.has_key('array')): 
        rcls['array']='auto'
    elif (hints and hints[0].has_key('rmconst')):
      fun['value_rmconst']=1
    elif (iscls):
      if (rtag=='ref' or rtag=='simple' or rtag=='cref'): # or rtag=='cptr'):
        pass
      else:
        print "** Bad Function Return type in Function: %s, class: %s, sig:\n    %s"%(funname,clsname,funsig)
        return 0
    else:
      if (rtag=='simple'):
        pass
      else:
        print "** Bad Function Return type in Function: %s, class: %s, sig:\n    %s"%(funname,clsname,funsig)
        return 0
  return 1
    
# ==========================================
# Build Params - Get data about a functions parameter list
# and build the description data for it.
#  Returns [params,opt]
def BuildParams(data,fun,clsname):
  funname=fun['name']
  sig=fun['sig']
  if (fun.has_key('manual')):
    return [[],(0,)]
  if (fun['linked']<1): return [[],(0,)]
  virt_fun=0
  if (fun['virt']=='virtual'): virt_fun=1
  params=[]
  c=1
  opti=-1
  post=0
  hints=data.vGetParameterHintData(clsname,sig)

  for param in fun['param']:
    pvalue=param['type_link']
    tag=pvalue['tag']
    utag=pvalue['utag']
    cls=pvalue['cls']
    iscls=pvalue['iscls']
    rsig=pvalue['sig']
    db=pvalue['isdb']

    if (param.has_key('defval') and opti<0):
      opti=c-1
    if (cls==None):
      print "Skipping Unlinked Opt params in Function: %s, class: %s, sig:\n    %s"%(funname,clsname,sig)
      break

    dct={
      'type':cls['name'],
      'tag':tag,
      'utag':utag,
      'tag':tag,
      'name':param.get('declname',''),
      }
    if (param.has_key('desc')):
      dct['desc']=param['desc']

    if (utag=='ptr' or utag=='cptr'):
      if (hints and hints[c].has_key('check')):
        dct['varcheck']=hints[c]['check']
        if (not cls.has_key('array')): 
          cls['array']='auto'
      elif (hints and hints[c].has_key('pre')):
        dct['varprecount']=1
        del params[-1]
        if (not cls.has_key('array')): 
          cls['array']='auto'
      elif (hints and hints[c].has_key('post')):
        dct['varpostcount']=1
        post=1
        if (not cls.has_key('array')): 
          cls['array']='auto'
      elif (hints and hints[c].has_key('aof')):
        dct['varaof']=1
        cls['aof']=1
      elif (hints and hints[c].has_key('copy')):
        dct['varcopy']=1
      elif (iscls and cls.has_key('size')):
        dct['varsized']=1
      else:
        print "** Missing Required Ptr-Tag in Function: %s, class: %s, sig:\n    %s %d"%(funname,clsname,sig,c)

    if (hints and hints[c].has_key('record')):
      dct['varrecord']=hints[c]['record']
    if (hints and hints[c].has_key('lock')):
      dct['varlock']=1
    if (hints and hints[c].has_key('novalidate')):
      dct['varnovalidate']=1

    c+=1
    params.append(['cParamDesc',dct])
    if (post):
      if (post==1): post=2
      else:
        post=0
        del params[-1]
  ln=len(params)
  if (opti<0): opti=ln
  return [params,range(opti,ln+1)]
             

