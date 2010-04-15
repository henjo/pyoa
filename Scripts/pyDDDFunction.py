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
#   Patch the return type on oaCollection type case
#--------------------------------------------------------------------
#

import string
import copy
import sys
import re
import pyDDDParameters
import pprint

# ===============================================================
# ==========================================
# Find the type of a parametere, that we understand.
#  Inputs:
#    name  - the type name
#    tag - the pass mechanism
#    resval - 1 for function return value, 0 for parameters
#  The return value is a dict with the following entries:
#    tag - the input parameter type. the following are supported
#            simple - simple pass by value:   (TYPE x)
#            const - const pass by value:     (const TYPE x)
#            ptr - pass by pointer:           (TYPE* x)
#            cptr - pass by const pointer:    (const TYPE* x)
#            pptr - pass by pointer2:         (TYPE** x)
#            cpptr - pass by const pointer2:  (const TYPE** x)
#            ref - pass by reference:         (TYPE& x)
#            cref - const pass by reference   (const TYPE& x)
#            ptrref - ponter reference        (TYPE*& x)
#            cptrref - const ponter reference (const TYPE*& x)
#    sig - the signature of the parameter= tag-name
#    iscls - 1 for a class type, 0 otherwise
#    isdb - 1 for a db class, 0 otherwise
def FindTypeName(self,name,tag,resval):
  dct={
      'tag':tag,
      'utag':tag,
      'cls':None,
      'iscls':0,
      'isdb':0,
      }
  dct['sig']='%s-%s'%(tag,name)
  if (self.mClasses.has_key(name)):
    db=self.mClasses[name]['db']
    dct['isdb']=db
    #print "=== ",name,br
    if (db):
      if (tag=='ptr'):
        dct['utag']='simple'
      elif (tag=='cptr'):
        if (resval): 
          dct['utag']='simpleconst'
        else:
          dct['utag']='simple'
      elif (tag=='ptrref'):
        dct['utag']='ref'
      elif (tag=='pptr'):
        dct['utag']='ptr'
      elif (tag=='cpptr'):
        if (resval): return dct # NA
        dct['utag']='cptr'
      elif (tag=='cptrref'):
        if (resval): return dct # NA
        dct['utag']='cref'
      else:
        return dct
    else:
      #if (tag=='ptrref' and not resval): return dct
      if (tag=='ptrref'): return dct
      if (tag=='cptrref'): return dct
      #if (tag=='cptr' and resval and name!='char'): 
      #  return dct

    dct['cls']=self.mClasses[name]
    dct['iscls']=1
    return dct

  if (self.mEnums.has_key(name)):
    if (tag!='simple' and tag!='const'): return dct
    dct['cls']=self.mEnums[name]
    return dct

  return dct
    
# ==========================================
# Find the a type reference
# decode the parameter description into its tag, type, and name
def FindTypeRef(self,name,resval=0):
  name=string.replace(name,'*',' * ')
  name=string.replace(name,'&',' & ')
  parts=string.split(name)
  dct={
      'tag':'simple',
      'utag':'simple',
      'sig':'simple-'+name,
      'cls':None,
      'iscls':0,
      'isdb':0,
      }
  if (len(parts)==0):
    print "** Bad Name",name
    return dct

  if (parts[0]=='virtual'):
    parts=parts[1:]
    name=name[8:]

  # This allows 'char *' as builtin
  #result=FindTypeName(self,name,'simple',resval)
  #if (result['cls']!=None): return result

  # Check by parts
  if (len(parts)==1):
    if (parts[0]=='void' and resval):
      dct={
          'tag':'void',
          'utag':'void',
          'sig':'void-void',
          'cls':None,
          'iscls':0,
          'isdb':0,
      }
      return dct
    return FindTypeName(self,parts[0],'simple',resval)
  if (len(parts)==2):
    if (parts[1]=='*'):
      return FindTypeName(self,parts[0],'ptr',resval)
    if (parts[1]=='&'):
      return FindTypeName(self,parts[0],'ref',resval)
    if (parts[0]=='const'):
      return FindTypeName(self,parts[1],'simple',resval)
    return dct
  if (len(parts)==3):
    if (parts[0]=='const' and parts[2]=='&'):
      return FindTypeName(self,parts[1],'cref',resval)
    if (parts[0]=='const' and parts[2]=='*'):
      return FindTypeName(self,parts[1],'cptr',resval)
    if (parts[1]=='*' and parts[2]=='*'):
      return FindTypeName(self,parts[0],'pptr',resval)
    if (parts[1]=='*' and parts[2]=='&'):
      return FindTypeName(self,parts[0],'ptrref',resval)
    return dct
  if (len(parts)==4):
    if (parts[0]=='const' and parts[2]=='*' and parts[3]=='&'):
      return FindTypeName(self,parts[1],'cptrref',resval)
    if (parts[0]=='const' and parts[2]=='*' and parts[3]=='*'):
      return FindTypeName(self,parts[1],'cpptr',resval)
  return dct
        
# ===============================================================
# ==========================================
# Find the return type and parameter type of a global function
def LinkGlobalFunction(data,fun):
  linked=1
  linkerror=[]
  funname=fun['name']
  if (fun.has_key('template')):
    linked=0
    linkerror.append("Templated functions not supported")

  #-------------------------------------------
  # Find result type
  rettype=fun['type']
  rvalue=FindTypeRef(data,rettype,1)
  sig=funname+'|'
  sig+=rvalue['sig']+'|'
  fun['type_link']=rvalue
  if (rvalue['tag']!='void' and rvalue['cls']==None):
    linked=0
    linkerror.append("Return value: %s"%rvalue['tag'])

  #-------------------------------------------
  # Find parameter type
  index=1
  for param in fun['param']:
    paramtype=param['type']
    value=FindTypeRef(data,paramtype)
    sig+=(value['sig']+',')
    param['type_link']=value
    #if (value['cls']==None and not param.has_key('defval')):
    if (value['cls']==None):
      linked=0
      linkerror.append("Parameter "+str(index))
    index+=1

  #-------------------------------------------
  # Set Manual
  if (linked and data.vIsManualGlobalFunction(sig)):
    fun['manual']=1
    linked=1
  skip=data.vIsSkipGlobalFunction(sig)
  if (skip): linked=0
  if (not linked and not skip):
    print "-- Function Link Error: %s, sig: %s %s"%(funname,sig,linkerror)
  fun['linked']=linked
  fun['sig']=sig
  return linked

# ==========================================
# Find the return type and parameter type of a class function
def LinkClassFunction(data,fun,cls):
  linked=1
  linkerror=[]
  clsname=cls['name']
  desname='~'+clsname
  funname=fun['name']
  funnames=string.split(funname)
  rettype=fun['type']
  sig=funname+'|'

  if (fun.has_key('template')):
    linked=0
    linkerror.append("Templated functions not supported")

  #-------------------------------------------
  # Find result type
  if (funname==clsname or funname==desname):  # Const/Dest
    sig+='|'
  else:
    if (len(funnames)>=2 and funnames[0]=='operator' and rettype==''): # TypeCast
      rettype=string.join(funnames[1:])
    rvalue=FindTypeRef(data,rettype,1)
    if (rvalue==None):
      print "** No return type for function:",funname
    sig+=rvalue['sig']+'|'
    fun['type_link']=rvalue
    if (rvalue['tag']!='void' and rvalue['cls']==None):
      linked=0
      linkerror.append("Return value: %s"%rettype)

  #-------------------------------------------
  # Find parameter type
  index=1
  for param in fun['param']:
    paramtype=param['type']
    value=FindTypeRef(data,paramtype,0)
    sig+=(value['sig']+',')
    param['type_link']=value
    #if (value['cls']==None and not param.has_key('defval')):
    if (value['cls']==None):
      linked=0
      linkerror.append("Parameter "+str(index))
    index+=1

  #-------------------------------------------
  # Set Manual
  if (linked and data.vIsManualClassFunction(clsname,sig)):
    fun['manual']=1
    linked=1

  #-------------------------------------------
  # Record data
  skip=data.vIsSkipClassFunction(clsname,sig)
  if (skip): linked=0
  if (not linked and not skip):
    print "-- Function Link Error: %s::%s, sig: %s %s"%(clsname,funname,sig,linkerror)

  if (data.vAllowVirtualClass(clsname)):
    clsvirt=fun.get('virt','')
    if (clsvirt=='virtual' or clsvirt=='pure-virtual'):
      cls['virt']=1
    if (clsvirt=='pure-virtual'):
      cls['pure-virt']=1
      
  if (fun['virt']=='virtual' and not data.vAllowVirtualFunction(clsname,sig)):
    fun['virt']='non-virtual'
    
  fun['linked']=linked
  fun['sig']=sig
  return linked

# ==========================================
# Find the return type and parameter type of all functions
def LinkAllFunctions(data):
  print "Linking Global Functions"
  sys.stderr.write("Linking Global Functions:\n")
  newfuns=[]
  for fun in data.mFunctions:
    if (LinkGlobalFunction(data,fun)>0):
     newfuns.append(fun)
  data.mFunctions=newfuns

  sys.stderr.write("Linking Class Functions:\n")
  clsnames=data.mClasses.keys()
  clsnames.sort()
  for clsname in clsnames:
    cls=data.mClasses[clsname]
    clsname=cls['name']
    if (cls['category']=='manual'): continue
    print "Linking Class Functions:",clsname

    #---------------------------------
    # Remove hidden functions
    for md in ['functions','sfunctions']:
      newlst=[]
      for fun in cls[md]:
        #print "  Check Protect Class Function:",fun['name']
        if (fun['protect']=='public'): 
          newlst.append(fun)
      cls[md]=newlst

    #---------------------------------
    # Link the functions    
    for md in ['functions','sfunctions']:
      newfuns=[]
      for fun in cls[md]:
        #print "  Link Class Function:",fun['name']
        if (LinkClassFunction(data,fun,cls)>0):
          newfuns.append(fun)
      cls[md]=newfuns

    #---------------------------------
    # Remove Duplicate operator[]    
    rop=None
    cop=None
    for fun in cls['functions']:
      if (fun['name']=='operator[]'): 
        rtag=fun['type_link']['utag']
        if (rtag=='ref'): rop=fun
        elif (rtag=='cref' or rtag=='simple'): cop=fun
    if (rop!=None and cop!=None):
      newfuns=[]
      for fun in cls['functions']:
        if (fun['name']=='operator[]'):
          rtag=fun['type_link']['utag']
          if (rtag=='cref' or rtag=='simple'): continue
        newfuns.append(fun)
      cls['functions']=newfuns

    #-------------------------------------------
    # Find missing copy constructors
    if (not cls.get('db',0)):
      needed=0
      # need a constructor if the class is not db and
      # it contains pointer member variables.
      for var in cls['vars'].values():
        rvalue=FindTypeRef(data,var['type'],0)
        if (rvalue['tag']!='void' and rvalue['cls']==None): 
          needed=1
          break
        if (rvalue['cls']['name']==clsname): continue  # skips ptrs to self in callbacks
        if (rvalue['cls'].get('db',0)): continue # ptrs to db classes are ok
        if (rvalue['tag']=='ptr' or rvalue['tag']=='cptr'): 
          needed=1
          break
      # Look for constructors
      has_copy=0
      has_eq=0
      has_constr=0
      for fun in cls['functions']:
        #if (clsname=='oaComplexArray_oaDouble'):
        #  print "FUN:",
        #  pprint.pprint(fun)
        if (fun['name']=='operator='): has_eq=1
        if (fun['name']!=clsname): continue
        has_constr=1
        params=fun['param']
        if (len(params)!=1): continue
        type=params[0]['type_link']
        if (type['cls']!=None and 
            type['cls']['name']==clsname and 
            (type['tag']=='ref' or type['tag']=='cref')):
          has_copy=1
      if (has_copy):
        cls['has_copy']=1
      skip=data.vIsIgnoreClassConstructor(clsname)
      if (needed):
        if (not has_copy and has_constr):
          if (not skip):
            print "-- Missing CopyConstructor: %s"%(clsname)
          cls['no_copy']=1
        # The missing_eq check is not working
        #if (missing_eq):
        #    print "** Missing operator=: %s"%(clsname)
        #    cls['no_copy']=1
      if (not has_constr):
        if (not skip):
          print "-- Missing any constructor: %s"%(clsname)
        cls['no_constr']=1
        cls['no_copy']=1
      no_assign=data.vIsNoAssignClass(clsname)
      if (no_assign):
        cls['no_assign']=1
        print "-- Skipping assign: %s"%(clsname)

  #-------------------------------------------
  # Update Virtuals from base classes
  for clsname in clsnames:
    cls=data.mClasses[clsname]
    clsname=cls['name']
    if (cls['category']=='manual'): continue
    if (data.vAllowVirtualClass(clsname)):
      base=cls
      while base!=None:
        if (base.has_key('virt')):
          cls['virt']=1
          break
        base=base['base']
            
            
                
