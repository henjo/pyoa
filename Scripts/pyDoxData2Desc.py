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
# Convert the DoxData (generate by pyXml2DoxData) into
#  wrapper description data.
#--------------------------------------------------------------------
#
from pyCoderClass import *
from pyCoderFunc import *
from pyCoderMain import *

import pprint
import string
import os
import types
import traceback
import copy
import sys

import pyDDDFindTemplateTypes
import pyDDDFindClasses
import pyDDDFunction
import pyDDDParameters
import pyDDDPatchData

# ===================================================================
class cDoxData2Desc:
    # ==========================================
  def __init__(self):
    #----------------------------------------
    # List of things to keep
    #----------------------------------------
    self.mData=[]     # Input Data
    self.mClasses={}    # All the classes
    self.mTypedefs={}   # All the typedefs
    self.mFunctions=[]   # All the global functions
    self.mEnums={}       # All the global enums
    self.mDefines={}     # All the global defines
    self.mVars={}        # All the global vars

    #----------------------------------------
    # List of things to generate
    #----------------------------------------
    self.mClsData=[]     # Classes
    self.mFunData=[]     # Functions
    self.mDefData=[]     # Defines
    self.mTmpData=[]     # Template information

    #----------------------------------------
    # Define output order of keys in arguments
    #----------------------------------------
    self.mOutputKeyOrder=['name','type','desc','sig','call','value','params',
                          'constructors','methods','gets','sets','igets','isets','ops',
                          ]
             
  # ===============================================================
  # ===============================================================
  # Begin of user definable callbacks


  # ==========================================
  # ==========================================
  # User callback to patch the full dataset before
  # any other processing is done
  def vPatchDataSet(self):
    pass

  # ==========================================
  # ==========================================
  # User callback to skip a class name
  def vShouldSkipTemplateClass(self,classname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to add additionall template specializations
  #  data is a dict:
  #   key - class name
  #   value - dict:  class_specialization_name / list of template param values
  def vAddTemplateSpecializations(self,specialized):
    pass

  # ==========================================
  # Support routine for Add a new specialization
  def AddTemplateSpecialization(self,specialized,clsname,spllist):
    pyDDDFindTemplateTypes._AddTemplateSpecialization(self,specialized,clsname,spllist)

  # ==========================================
  # Support routine for Propagating specialization
  # of derived classes to the bases.
  # Return a list of class names to propagate
  def vGetTemplatePropagations(self):
    return []

  # ==========================================
  # ==========================================
  # User callback to patch the templat map data
  def vPathTmpData(self):
    pass
    
  # ==========================================
  # ==========================================
  # User callback to patch the template data
  def vCustomizeTemplateData(self):
    pass

  # ==========================================
  # ==========================================
  # User callback to skip a class name
  def vShouldSkipClass(self,classname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to skip a base classname name
  #   called from a dirived class
  def vShouldSkipDerivedClass(self,classname):
    return 0

  # ==========================================
  # ==========================================
  # User callback get repr description
  def vGetClassRepr(self,classname):
    return None

  # ==========================================
  # ==========================================
  # User callback get repr description based on 
  # a base class
  def vGetClassReprByBaseClass(self,classname):
    return None

  # ==========================================
  # ==========================================
  # User callback to determine Db classes
  def vIsDbClass(self,classname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Typedef should be skipped
  def vShouldSkipTypedef(self,name):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Function should be skipped
  def vShouldSkipFunction(self,name):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Define should be skipped
  def vShouldSkipDefine(self,name):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Enum should be skipped
  def vShouldSkipEnum(self,name):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Var should be skipped
  def vShouldSkipVar(self,name):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a global function is manual
  def vIsManualGlobalFunction(self,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function is manual
  def vIsManualClassFunction(self,clsname,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a global function is skipped
  def vIsSkipGlobalFunction(self,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function is skipped
  def vIsSkipClassFunction(self,clsname,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class constructor messages should be skipped
  def vIsIgnoreClassConstructor(self,clsname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class should diss-allow assign
  def vIsNoAssignClass(self,clsname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class should allow virtual
  def vAllowVirtualClass(self,clsname):
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function should allow virtual
  def vAllowVirtualFunction(self,clsname,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to customize data before writting
  #   Use to add iterators
  def vCustomizeData(self,clsname,sig):
    return 0

  # ==========================================
  # ==========================================
  # User callback to get range check data for operator[] functions
  def vGetRangeCheck(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to customize class before final write
  #   Use to add Iter functions from Collections
  def vCustomizeClassFunctions(self,cls):
    return None

  # ==========================================
  # ==========================================
  # User callback to add parameters to a constructor call
  #  Needed for virtual class without a default constructor
  def vGetConstructorParameters(self,cls):
    return ''

  # ==========================================
  # ==========================================
  # User callback to get class cast data
  def vGetClassCastData(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetRecordData(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetLockData(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetMathData(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to get the iterator function name if a class
  #  is an iterator
  def vGetIterFunction(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to get see if class supports compare
  def vGetCompareData(self,clsname):
    return None

  # ==========================================
  # ==========================================
  # User callback to report data structures
  def vReportData(self,name,data):
    pass
    
  # ==========================================
  # ==========================================
  # User callback to get a report file
  def vGetReportFile(self,name):
    return None

  # ==========================================
  # ==========================================
  # User callback to get parameter hint data
  def vGetParameterHintData(clsname,funsig):
    return None
    
  # ===============================================================
  # ===============================================================

  # ==========================================
  # Record Typedefs
  def FindTypedefs(self,fdata):
    for item in fdata['typedefs'].values():
      name=item['name']
      if (self.mClasses.has_key(name)): continue
      if (self.vShouldSkipTypedef(name)): continue
      self.mTypedefs[name]=item

  # ==========================================
  # Record Functions
  def FindFunctions(self,fdata):
    for item in fdata['functions']:
      name=item['name']
      if (self.vShouldSkipFunction(name)): continue
      self.mFunctions.append(item)

  # ==========================================
  # Record Defines
  def FindDefines(self,fdata):
    for item in fdata['defines'].values():
      name=item['name']
      if (self.vShouldSkipDefine(name)): continue
      self.mDefines[name]=item

  # ==========================================
  # Record Enums
  def FindEnums(self,fdata):
    for item in fdata['enums'].values():
      name=item['name']
      if (self.vShouldSkipEnum(name)): continue
      self.mEnums[name]=item

  # ==========================================
  # Record Vars
  def FindVars(self,fdata):
    for item in fdata['vars'].values():
      name=item['name']
      if (self.vShouldSkipVar(name)): continue
      self.mVars[name]=item

  # ==========================================
  # Process File Data to find typedefs,function,enums,defines
  def ProcessFileData(self):
    sys.stderr.write("Processing Global Data:\n")
    for item in self.mData:
      if (item['category']=='file'):
        self.FindTypedefs(item)
        self.FindFunctions(item)
        self.FindEnums(item)
        self.FindDefines(item)
        self.FindVars(item)


  # ===============================================================
  # ==========================================
  # Build Enums - Generate output data for enums
  def BuildEnums(self):
    for enum in self.mEnums.values():
      name=enum['name']
      values=""
      texts=""
      slist=""
      for item in enum['values']:
        values+=(" "+item['name'])
        texts+=(" "+item['name'])
        if (slist): slist+="\n"
        slist+=item['name']

      desc=enum['detaileddescription']
      if (desc==''):
        desc=enum['briefdescription']
        if (desc==''):
            desc='Enum type '+name
      desc+='\nValues:\n'+slist

      self.mClsData.append(['cEnumClassDesc',
                           {'name':name,
                            'values':values,
                            'texts':texts,
                            'desc':desc}])
      slist=string.replace(slist,"\n"," ")

  # ==========================================
  # Build Defines - Generate output data for defines
  def BuildDefines(self):
    values=[]
    for define in self.mDefines.values():
      name=define['name']

      if (len(define['param'])==0):
        value=define['body']
        if (value[0]=="'" and value[-1]=="'"):
          value=value[1:-1]

        desc=define['detaileddescription']
        if (desc==''):
          desc=define['briefdescription']
          if (desc==''):
            desc='Define value '+name
        desc+=' Value: '+value

        values.append({'name':name,
                       'value':value,
                       'desc':desc})

    # Convert Numeric strings to int values
    results={}
    for item in values:
      value=item['value']
      name=item['name']
      # allow L and LL
      if (value[-1]=='l' or value[-1]=='L'):
        value=value[:-1]
      if (value[-1]=='l' or value[-1]=='L'):
        value=value[:-1]
      # allow U - unsigned
      if (value[-1]=='u' or value[-1]=='U'):
        value=value[:-1]
      try:
        result=eval(value)
      except:
        continue
      if (type(result)==types.IntType):
        item['result']=('int',value)
        results[name]=result
      elif (type(result)==types.LongType):
        item['result']=('long',value)
        results[name]=result
      elif (type(result)==types.FloatType):
        item['result']=('float',value)
        results[name]=result
      elif (type(result)==types.StringType):
        item['result']=('string',str(result))
        results[name]=result

    # Convert Numeric expressions to int values
    for i in range(2):
      print '--------'
      for item in values:
        value=item['value']
        name=item['name']
        if (item.has_key('result')): continue
        value=string.replace(value,"\\","")
        try:
          result=eval(value,results)
        except:
          continue
        if (type(result)==types.IntType):
          item['result']=('int',hex(result))
          results[name]=result
        elif (type(result)==types.LongType):
          result=hex(result)
          if (result[-1]=='l' or result[-1]=='L'): result=result[:-1]
          if (result[-1]=='l' or result[-1]=='L'): result=result[:-1]
          item['result']=('long',result)
          results[name]=result
        elif (type(result)==types.FloatType):
          item['result']=('float',str(result))
          results[name]=result

    # Generate the output data
    for item in values:
      name=item['name']
      desc=item['desc']
      if (item.has_key('result')):
        value=item['result']
      else:
        value=('string',item['value'])
      self.mDefData.append(['cDefDesc',
                            {'name':name,
                             'value':value,
                             'desc':desc}])

  # ==========================================
  # Build Typedef - Generate output data for typedefs
  def BuildTypedef(self,item):
    name=item['name']

    desc=item['detaileddescription']
    if (desc==''):
      desc=item['briefdescription']
      if (desc==''):
        desc='Typedef type '+name

    if (item['category']=='manual'):
      dct={'name':name,
           'desc':desc,
           'choice':item['choice'],
           }
      if (item.has_key('template_name')):
        dct['typedef']="typedef %s %s"%(
            item['template_name'],item['template_typedef'])

      if (item.has_key('array')):
        dct['array']=item['array']
      if (item.has_key('builtin')):
        dct['builtin']=1
      if (item.has_key('aof')):
        dct['aof']=1

      self.mClsData.append(['cManualClassDesc',dct])

    # All typdefs must currently have a manual mapping
    #elif (item['category']=='typedef'):
    #  dct={'name':name,
    #       'desc':desc,
    #       }
    #  if (item.has_key('array')):
    #    dct['array']=item['array']
    #  self.mClsData.append(['cNativeClassDesc',dct])
    elif (item['category']=='typedef'):
      print "** Skipping Typedef: %s"%name

    else:
      raise "Unknown/Unsupported thing in BuildTypedef: %s/%s"%(item['category'],str(name))

  # ==========================================
  # Build Typedefs
  def BuildTypedefs(self):
    for typedef in self.mTypedefs.values():
      self.BuildTypedef(typedef)

  # ==========================================
  # Build Functions
  def PrepareGlobalFunctions(self):
    newfuns=[]
    for fun in self.mFunctions:
      funname=fun['name']
      if (funname[0:8]=='operator'):
        print "Skipping Global Operator Function: %s"%funname
        continue

      desc=fun['detaileddescription']
      if (desc==''):
        desc=fun['briefdescription']
        if (desc==''):
          desc='Function '+funname
      fun['desc']=desc

      params,opt=pyDDDParameters.BuildParams(self,fun,'global')
      # Expand optional params
      for i in opt:
        newfun=copy.copy(fun)
        prms=params[:i]
        newfun['params']=prms

        if (not pyDDDParameters.PrepareReturnValue(self,newfun,'global')):
          continue
        newfuns.append(newfun)

    self.mFunctions=newfuns

  # ==========================================
  # Build Functions Dct
  def BuildFunctionDct(self,fun,manual=0):
    dct={'name':fun['name'],
         'sig':fun['sig'],
         'desc':fun['desc'],
         }
    if (manual): dct['ismanual']=1
    if (fun['params']):
      dct['params']=fun['params']
    for key in ['value','value_tag','value_utag','value_init','value_ref',
                'value_alloc','value_dref','value_borrow','value_lock',
                'value_copy', 'value_rmconst',
                'range_check','call','ismanual','isiter','virt','const']:
      if (fun.has_key(key)):
        dct[key]=fun[key]
    return dct

  # ==========================================
  # Build Functions
  def BuildGlobalFunctions(self):
    groups={}
    for fun in self.mFunctions:
      funname=fun['name']
      group=groups.get(funname,[])
      group.append(fun)
      groups[funname]=group

    for funname,group in groups.items():
      manual=0
      for fun in group:
        if (fun.has_key('manual')): manual=1
      fung=[]
      for fun in group:
        dct=self.BuildFunctionDct(fun,manual)
        fung.append(['cGlobalFunDesc',dct])

      dct={'name':funname,
           'funs':fung,
           }
      self.mFunData.append(['cFunGroupDesc',dct])

  # ==========================================
  # Prepare Class Functions (members)
  def PrepareClassFunctions(self,cls):
    clsname=cls['name']
    desname='~'+clsname
    cons=[]
    funs=[]
    igets=[]
    isets=[]
    ops=[]
    #----------------------------------------------
    # Walk all the functions
    for fun in cls['functions']:
      funname=fun['name']
      funnamesplit=string.split(funname)
      if (funname==desname): 
        continue # destructor
      desc=fun['detaileddescription']
      if (desc==''):
        desc=fun['briefdescription']
        if (desc==''):
          if (funname==clsname):
            desc='Constructor '+funname
          else:
            desc='Function '+funname
      fun['desc']=desc

      #----------------------------------------------
      # Expand optional params
      params,opt=pyDDDParameters.BuildParams(self,fun,clsname)
      for i in opt:
        prms=params[:i]
        newfun=copy.copy(fun)
        newfun['params']=prms

        funsig=newfun['sig']
        funvirt=newfun['virt']
        funconst=newfun['const']
        if (funname==clsname):
          cons.append(newfun)
          continue

        pvalue=newfun['type_link']
        rtag=pvalue['utag']
        rcls=pvalue['cls']

        #----------------------------------------------
        # Check for output value
        if (not pyDDDParameters.PrepareReturnValue(self,newfun,clsname)):
          continue

        #----------------------------------------------
        # Check for index function
        if (funname=='operator[]'):
          if (funvirt=='virtual'):
            print "** Index Function is virtual: %s, in Class: %s Sig: %s"%(funname,clsname,funsig)
            continue
          newfun['call']=funname
          range_check=self.vGetRangeCheck(clsname)
          if (not range_check):
            print "** Range Check not specified for Class: %s Sig: %s"%(clsname,funsig)
            continue
          newfun['range_check']=range_check
          if (rtag=='ref'):
            newfun['name']='index_set'
            isets.append(newfun)
            newfun=copy.copy(newfun)
            newfun['name']='index_get'
            igets.append(newfun)
          elif (rtag=='cref' or rtag=='simple'):
            newfun['name']='index_get'
            igets.append(newfun)
          else:
            print "** Bad return type on operator[] for Class: %s Sig: %s"%(clsname,funsig)
            continue

        #----------------------------------------------
        # Check for operator typecast function
        elif (funname[0:9]=='operator '):
          if (funvirt=='virtual'):
            print "** Operator Function is virtual: %s, in Class: %s Sig: %s"%(funname,clsname,funsig)
            continue
          newfun['call']=funname
          newname=funname[9:]
          newname=string.replace(newname,'<',' <')
          newname=string.replace(newname,'*',' *') 
          index=string.find(newname,' ')
          if (index>=0): newname=newname[:index]
          newfun['name']=newname
          funs.append(newfun)
        #----------------------------------------------
        # Check for operator function
        elif (funname[0:8]=='operator'):
          if (funvirt=='virtual'):
            print "** Operator Function is virtual: %s, in Class: %s Sig: %s"%(funname,clsname,funsig)
            continue
          newfun['call']=funname
          newfun['name']=string.replace(funname,' ','_')
          ops.append(newfun)
        #----------------------------------------------
        # Otherwi:use normal function
        else:
          funs.append(newfun)

    #----------------------------------------------
    # Record all data
    if (len(igets)>1):
      raise str("Multiple Get operator[] found in Class: %s"%clsname)
    if (len(isets)>1):
      raise str("Multiple Set operator[] found in Class: %s"%clsname)

    cls['constructors']=cons
    cls['methods']=funs
    cls['igets']=igets
    cls['isets']=isets
    for fun in ops:
      if (fun['name']=='operator==' and self.vGetCompareData(clsname)): continue
      if (fun['name']=='operator!=' and self.vGetCompareData(clsname)): continue
      print "Skipping Operator Function: %s, in Class: %s"%(fun['name'],clsname)

  # ==========================================
  # Build Class Functions (members)
  def BuildClassFunctions(self,cls):
    clsname=cls['name']
    clsdct=cls['data']
    cons=cls['constructors']
    funs=cls['methods']
    igets=cls['igets']
    isets=cls['isets']

    #----------------------------------------------
    groups={}
    for fun in funs:
      funname=fun['name']
      group=groups.get(funname,[])
      group.append(fun)
      groups[funname]=group

    genfuns=[]
    for funname,group in groups.items():
      fung=[]
      manual=0
      for fun in group:
        if (fun.has_key('manual')): manual=1
      for fun in group:
        dct=self.BuildFunctionDct(fun,manual)
        fung.append(['cFunDesc',dct])

      dct={'name':funname,
           'funs':fung,
           }
      genfuns.append(['cFunGroupDesc',dct])
    if (genfuns): clsdct['methods']=genfuns

    #----------------------------------------------
    if (igets):
      dct=self.BuildFunctionDct(igets[0])
      genigets=[ ['cIndexGetFunDesc',dct] ]
      clsdct['igets']=genigets

    #----------------------------------------------
    if (isets):
      dct=self.BuildFunctionDct(isets[0])
      genisets=[ ['cIndexSetFunDesc',dct] ]
      clsdct['isets']=genisets

    #----------------------------------------------
    if (cons):
      gencons=[]
      manual=0
      for fun in cons:
        if (fun.has_key('manual')): manual=1
      for fun in cons:
        dct=self.BuildFunctionDct(fun,manual)
        gencons.append(['cConDesc',dct])
      clsdct['constructors']=gencons


  # ==========================================
  # Check Class Functions
  #  Find duplicate name and parameter functions
  def CheckClassFunctions(self,cls):
    #---------------------------------
    # Rename Ref Functions
    newlist=[]
    for fun in cls['methods']:
      name=fun['name']
      if (name[0:8]=='operator'): 
        newlist.append(fun)
        continue
      if (fun.get('value_utag','')=='cref' or fun.get('value_utag','')=='simple'):
        drop=0
        for fun2 in cls['methods']:
          if (fun2['name']!=name): continue
          if (fun2.get('value_utag','')=='ref'):
            drop=1
            break
        if (not drop):
          newlist.append(fun)
      else:
        newlist.append(fun)
    cls['methods']=newlist

    #---------------------------------
    return
    groups={}
    for fun in cls['methods']:
      funname=fun['name']
      group=groups.get(funname,[])
      group.append(fun)
      groups[funname]=group

    for funname,group in groups.items():
      cases={}
      for fun in group:
        sig=fun['sig']
        parts=string.split(sig,'|')
        params=parts[2]
        data=cases.get(params,[])
        data.append(parts)
        cases[params]=data
      for param,data in cases.items():
        if (len(data)==1): continue
        print "** Found Duplicate Functions in class:",cls['name'],'Function:',funname,'Cases:',str(data)

  # ==========================================
  # Build Class SFunctions (static functions)
  def PrepareClassStaticFunctions(self,cls):
    clsname=cls['name']
    newfuns=[]
    for fun in cls['sfunctions']:
      funname=fun['name']

      desc=fun['detaileddescription']
      if (desc==''):
        desc=fun['briefdescription']
        if (desc==''):
          desc='Function '+funname
      fun['desc']=desc

      params,opt=pyDDDParameters.BuildParams(self,fun,clsname)
      # Expand optional params
      for i in opt:
        newfun=copy.copy(fun)
        prms=params[:i]
        newfun['params']=prms

        if (not pyDDDParameters.PrepareReturnValue(self,newfun,clsname)):
          continue
        newfuns.append(newfun)
    cls['static_methods']=newfuns

  # ==========================================
  # Build Class SFunctions (static functions)
  def BuildClassStaticFunctions(self,cls):
    clsname=cls['name']
    clsdct=cls['data']
    groups={}
    for fun in cls['static_methods']:
      funname=fun['name']
      group=groups.get(funname,[])
      group.append(fun)
      groups[funname]=group

    fung=[]
    for funname,group in groups.items():
      manual=0
      funs=[]
      for fun in group:
        if (fun.has_key('manual')): manual=1
      for fun in group:
        dct=self.BuildFunctionDct(fun,manual)
        funs.append(['cStaticFunDesc',dct])

      dct={'name':funname,
           'funs':funs,
           }
      fung.append(['cFunGroupDesc',dct])
    if (fung): clsdct['static_methods']=fung

  # ==========================================
  # Check Class Constructor
  def CheckClassConstructor(self,cls):
    clsname=cls['name']
    clsdct=cls['data']
    base=cls

    #--------------------------
    # Find Constructor
    found=0
    for fun in cls['functions']:
      funname=fun['name']
      if (funname!=clsname): continue
      found=1
    if (not found):
      clsdct['class_init']=self.vGetConstructorParameters(clsname)

    #--------------------------
    dt=self.vGetClassCastData(clsname)
    if (dt):
      clsdct['class_casts']=dt

    #--------------------------
    if (cls.has_key('template_name')):
      clsdct['typedef']="typedef %s %s"%(
          cls['template_name'],cls['template_typedef'])

    #--------------------------
    if (cls['db']):
      clsdct['typedefdb']="typedef %s* %sp"%(clsname,clsname)
      clsdct['typename']='%sp'%(clsname)
    else:
      clsdct['typename']=clsname

    #--------------------------
    record=self.vGetRecordData(clsname)
    if (record):
      clsdct['record']=record

    #--------------------------
    lock=self.vGetLockData(clsname)
    if (lock):
      clsdct['lock']=lock

    #--------------------------
    math=self.vGetMathData(clsname)
    if (math):
      clsdct['manmath']=1

  # ==========================================
  # Prepare Classes
  def PrepareClasses(self):
    clsnames=self.mClasses.keys()
    clsnames.sort()
    for key in clsnames:
      cls=self.mClasses[key]
      name=cls['name']
      realname=cls.get('template_typedef',name)
      if (cls['category']=='manual'):
        continue

      desc=cls['detaileddescription']
      if (desc==''):
        desc=cls['briefdescription']
        if (desc==''):
          desc='Class type '+realname

      dct={'name':realname,
           'desc':desc,
          }
      cls['data']=dct

      self.PrepareClassFunctions(cls)
      self.PrepareClassStaticFunctions(cls)
      self.vCustomizeClassFunctions(cls)
      self.CheckClassFunctions(cls)

  # ==========================================
  # Build Classes
  def BuildClasses(self):
    clsnames=self.mClasses.keys()
    clsnames.sort()
    for key in clsnames:
      cls=self.mClasses[key]
      clsname=cls['name']
      realname=cls.get('template_typedef',clsname)
      if (cls['category']=='manual'):
        self.BuildTypedef(cls)
        continue

      self.BuildClassFunctions(cls)
      self.BuildClassStaticFunctions(cls)
      self.CheckClassConstructor(cls)

      dct=cls['data']
      if (cls.has_key('array')):
        dct['array']=cls['array']
      if (cls.has_key('aof')):
        dct['aof']=1
      if (cls.has_key('virt')):
        dct['virt']=1
      if (cls.has_key('pure-virt')):
        dct['pure_virt']=1
      if (cls['base']!=None):
        dct['base']=cls['base']['name']
      if (cls.has_key('repr')):
        dct['repr']=cls['repr']
      if (cls.has_key('varlock')):
        dct['lock']=1
      if (cls.has_key('varnovalidate')):
        dct['novalidate']=1
      if (cls.has_key('no_copy')):
        dct['no_copy']=1
      if (cls.has_key('has_copy')):
        dct['has_copy']=1
      if (cls.has_key('no_assign')):
        dct['no_assign']=1

      if (cls['db']):
        self.mClsData.append(['cDbClassDesc',dct])
      else:
        funname=self.vGetIterFunction(clsname)
        isitr=None
        if (funname!=None):
          for fun in cls['functions']:
            if (fun['name']==funname):
              isitr=fun
              break
        if (isitr!=None):
          fun=isitr
          rcls=fun['type_link']['cls']
          #sys.stderr.write('%s %s\n'%(str(fun['type_link']),str(rcls)))
          dct['type']=rcls['name']
          dct['fun']=funname
          self.mClsData.append(['cIterClassDesc',dct])
        else:
          compare=self.vGetCompareData(clsname)
          if (compare):
            dct['compare']='object'
          self.mClsData.append(['cAllocClassDesc',dct])

  # ===============================================================
  # ==========================================
  def WriteDict(self,key,dct,indent):
    first=1
    self.mFp.write("%*s%s(\n"%(indent,"",key))
    keys=dct.keys()
    orderkeys=[]
    for key in self.mOutputKeyOrder:
      if key in keys:
        orderkeys.append(key)
        keys.remove(key)
    for key in keys:
      orderkeys.append(key)

    for key in orderkeys:
      value=dct[key]
      if (first): first=0
      else: self.mFp.write(",\n")
      self.mFp.write("%*s%s="%(indent+4,"",key))
      self.WriteValue(value,indent)
    self.mFp.write(")")

  # ==========================================
  def WriteList(self,lst,indent):
    first=1
    self.mFp.write("[\n")
    for key,dct in lst:
      if (first): first=0
      else: self.mFp.write(",\n")
      self.WriteDict(key,dct,indent+4)
    self.mFp.write("]")

  # ==========================================
  def WriteTuple(self,lst,indent):
    first=1
    self.mFp.write("(\n")
    for value in lst:
      if (first): first=0
      else: self.mFp.write("\n")
      self.mFp.write("%*s"%(indent+4,''))
      self.WriteValue(value,indent)
      self.mFp.write(",")
    self.mFp.write(")")

  # ==========================================
  def WriteValue(self,value,indent):
    if (type(value)==types.ListType):
      self.WriteList(value,indent+4)
    elif (type(value)==types.TupleType):
      self.WriteTuple(value,indent+4)
    elif (type(value)==types.DictType):
      self.WriteList(value,indent+4)
    else:
      if (type(value)==types.IntType):
        self.mFp.write("%d"%value)
      else:
        value=repr(value)
        self.mFp.write("%s"%value)

  # ==========================================
  # Write the output data to its file
  def WriteOutput(self,file):
    print "Writting Description File:",file
    sys.stderr.write("Writting Description File: %s\n"%file)
    self.mFp=open(file,"w")
    self.mFp.write("""\
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
# The following code description was generated by pyDoxData2Desc.
#  This used the data descriptions generated by pyXml2DoxData.
#--------------------------------------------------------------------

from pyCoderClass import *
from pyCoderFunc import *
from pyCoderMain import *

Data={
'clsdata':""")
#        pprint.pprint(self.mClsData,self.mFp)
    self.WriteList(self.mClsData,0)
    self.mFp.write(""",
'fundata':""")
    self.WriteList(self.mFunData,0)
    self.mFp.write(""",
'defdata':""")
    self.WriteList(self.mDefData,0)
    self.mFp.write(""",
'tmpdata':""")
    self.WriteTuple(self.mTmpData,0)
    self.mFp.write(""",
}

""")
    self.mFp.close()

  # ===============================================================

  # ==========================================
  def ProcessData(self,file):
    print "Start Processing"
    sys.stderr.write("Start Processing\n")

    # Classify the input data
    pyDDDPatchData.PatchData(self)
    pyDDDFindTemplateTypes.RemoveEmptyData(self)
    pyDDDFindTemplateTypes.ExpandTemplateDefaults(self)
    pyDDDFindTemplateTypes.FindTemplateTypes(self)
    pyDDDFindTemplateTypes.ExpandTemplateTypes(self)
    self.vCustomizeTemplateData()

    pyDDDFindClasses.FindClasses(self)
    self.ProcessFileData()

    # Link Inheritance
    pyDDDFindClasses.FindClassBases(self)
    pyDDDFunction.LinkAllFunctions(self)
    self.vCustomizeData()
    # TBD self.LinkVars()

    # Build Data
    sys.stderr.write("Building Description Data:\n")
    self.BuildEnums()
    self.BuildDefines()
    self.BuildTypedefs()
    self.PrepareGlobalFunctions()
    self.BuildGlobalFunctions()
    self.PrepareClasses()
    self.BuildClasses()
    # TBD self.BuildVars()

    self.WriteOutput(file)

  # ==========================================
  # Read a set of .py files from the given directory
  def ReadInputFiles(self,indir,files):
    print "Reading Files from:",indir
    sys.stderr.write("Reading Files from: %s\n"%indir)
    cwd=os.getcwd()
    sys.path.append(cwd)

    for file in files:
      cmd="from %s.%s import data"%(indir,file)
      NS={}
      exec cmd in NS
      for item in NS['data']:
          self.mData.append(item)

# ===================================================================
# ===================================================================
    
