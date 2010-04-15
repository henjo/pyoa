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

import pprint
import string
import os
import types
import traceback
import copy
import sys
import re

import pyDoxData2Desc
import oaDDDReprHints
import oaDDDFunctionHints
import oaDDDPatch

# ===================================================================
class cOaDoxData2Desc(pyDoxData2Desc.cDoxData2Desc):
  # ==========================================
  def __init__(self):
    pyDoxData2Desc.cDoxData2Desc.__init__(self)

    self.mHintReprByBase=oaDDDReprHints.GetReprHints()
    self.mFunctionHints=oaDDDFunctionHints.GetFunctionHints()
    
  # ==========================================
  # ==========================================
  # User callback to patch the full dataset before
  # any other processing is done
  def vPatchDataSet(self):
    oaDDDPatch.PatchClasses(self)

  # ==========================================
  # ==========================================
  # User callback to skip a class name
  def vShouldSkipTemplateClass(self,classname):
    if (not hasattr(self,'mHintSkipTemplateClass')):
      self.mHintSkipTemplateClass={
        "oaVoidPointerAppDef":1,
        "oaHashTbl":1,
        "oaHashIter":1,
        "oaTraits":1,
        "oaBaseTraits":1,
        "oaRevisionTraits":1,
        "SRef":1,
      }
    if (self.mHintSkipTemplateClass.has_key(classname)): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to add additionall template specializations
  #  data is a dict:
  #   key - class name
  #   value - dict:  class_specialization_name / list of template param values
  def vAddTemplateSpecializations(self,specialized):
    # add Complex and ComplexArray
    self.AddTemplateSpecialization(specialized,u'oaComplex',[u'oaFloat'])
    self.AddTemplateSpecialization(specialized,u'oaComplex',[u'oaDouble'])
    self.AddTemplateSpecialization(specialized,u'oaArray',[u'oaComplex_oaFloat'])
    self.AddTemplateSpecialization(specialized,u'oaArray',[u'oaComplex_oaDouble'])
    self.AddTemplateSpecialization(specialized,u'oaComplexArray',[u'oaFloat'])
    self.AddTemplateSpecialization(specialized,u'oaComplexArray',[u'oaDouble'])
    
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaNet*',u'oaTerm*'])
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaNet*',u'oaName'])
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaNet*',u'oaUInt4'])
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaModNet*',u'oaModTerm*'])
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaModNet*',u'oaName'])
    self.AddTemplateSpecialization(specialized,u'oaNetTermPair',[u'oaModNet*',u'oaUInt4'])

    # Make Iters for all the Collections
    dct=specialized.get(u'oaCollection',{})
    for key,values in dct.items():
      self.AddTemplateSpecialization(specialized,u'oaIter',[values[0]])
      
    # Do all the extension types
    ExtensionsTypes=[
      u'oaBooleanAppDef',
      u'oaDataAppDef',
      u'oaDoubleAppDef',
      u'oaFloatAppDef',
      u'oaIntAppDef',
      u'oaInterPointerAppDef',
      u'oaIntraPointerAppDef',
      u'oaStringAppDef',
      u'oaTimeAppDef',
      u'oaVarDataAppDef',
      #'oaVoidPointerAppDef',
    ]
    # Build list of extendable objects
    ExtendableTypes=['oaAppObject']
    for item in self.mData:
      if (item['category']!='class'): continue
      if (not item.has_key('enums')): continue
      if (item['name'][0:8]=='oaTraits'): continue
      for enum in item['enums'].values():
        if (not enum.has_key('values')): continue
        for value in enum['values']:
          if (value.get('name','')=='dtIndex'):
            ExtendableTypes.append(item['name'])
            break
            
    self.vReportData("ExtendableTypes",ExtendableTypes)

    # Add the templated cases
    for name in ExtensionsTypes:
      for ext in ExtendableTypes:
        self.AddTemplateSpecialization(specialized,name,[ext])
        
    # For each oaTraits Specialization with a modTypeType typedef
    # add a oaVersionedObserver Specialization and oaStdObserver Specialization
    self.mObserverBasePatch={}
    for key,values in specialized['oaTraits'].items():
      clsname='oaTraits<%s>'%values[0]
      for item in self.mData:
        if (item['category']!='class'): continue
        if (item['name']!=clsname): continue
        typ=item.get('typedefs',{}).get('modTypeType',{}).get('type',None)
        if (typ==None): continue
        vvalues=[values[0],u'oacObserverRevision']
        if (values[0]=='oaTech'):
            vvalues[1]=u'oacTechObserverVersion2'
        self.AddTemplateSpecialization(specialized,u'oaObserver',vvalues)
        svalues=[values[0],typ]
        self.AddTemplateSpecialization(specialized,u'oaStdObserver',svalues)

        # Patch the oaVersionedObserver bases class as well
        cname = 'oaObserver_%s_%s'%(vvalues[0],vvalues[1])
        self.mObserverBasePatch[cname]='oaStdObserver_%s_%s'%(values[0],typ)
        break

    #del specialized['oaTraits']

  # ==========================================
  # Support routine for Propagating specialization
  # of derived classes to the bases.
  # Return a list of class names to propagate
  def vGetTemplatePropagations(self):
    data=[
      'oaSubset',       # -> oaArray
      'oaComplexArray', # -> oaArray
      'oaArray',        # -> oaArrayBase
    ]
    return data

  # ==========================================
  # ==========================================
  # User callback to skip a class name
  def vShouldSkipClass(self,classname):
    if (not hasattr(self,'mHintSkipClass')):
      self.mHintSkipClass={
        # Skip these beause they shouldn't be wrapped
        'oaPcellEvalObserver':1,
        #'oaCPPPcellDef':1,
        #'oaDataObserver':1,
        #'oaPcellDataObserver':1,
        'oaPcellObserver':1,
        #'oaCPPPcellDataObserver':1,
        #'oaTextDataObserver':1,
        #'oaCPPTextDataObserver':1,
        'oaMemory':1,
        # These don't need to be wrapped and have problems
        # with the ... constructor call, and no distructor.
        'oaDDError':1,
        'oaDDFatal':1,
        'oaSocket':1,
        'oaClientSocket':1,
        'oaServerSocket':1,
        'oaMutex':1,
        'oaScriptEngineLink':1,
        'oaDMFileSys':1,
        'oaDMFileSys::IFSLockD':1,
        'oaRevisionTraits_oaTech':1,
        'oaTextLink':1,
        'SRef_IText':1,

        # Skipping
        'oaEnumIterState':1,
        'oaTextDisplayIterState':1,
        
        # These exist in DOX file, but not .h
        #'oaDMDataTransaction':1,
        #'oaDMLibTransaction':1,
        #'oaDMTransaction':1,
        'oaBusNetBitCollection':1,
        'oaBusNetBitIter':1,
        'oaBusTermBitCollection':1,
        'oaBusTermBitIter':1,

        'oaNetCollection':1,
        'oaNetInBundleCollection':1,
        'oaNetIter':1,
        'oaNetNetCollection':1,
        'oaTermInBundleCollection':1,
        'oaTermIter':1,
        'oaTermTermCollection':1,
        'oaSubHeaderCollection':1,
        
        # These are special ext typedefs th
        'IBaseIter':1,
        'IBaseSequence':1,
        'oaDMTurbo_1_1IDMLibServer':1,
        'oaDMTurbo_1_1IDMLibServerMgr':1,
        'oaPlugIn':1,
        'oaPlugInError':1,
        'oaPlugInMgr':1,
        'oaPlugInMgrCleaner':1,
      }

    if (self.mHintSkipClass.has_key(classname)): return 1
    if (classname[0:8]=='oaTraits'): return 1
    if (classname[0:12]=='oaBaseTraits'): return 1
    if (classname[0:9]=='oaDMTurbo'): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to skip a base classname name
  #   called from a dirived class
  def vShouldSkipDerivedClass(self,classname):
    if (classname=='oaException'): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to patch the templat map data
  def vPathTmpData(self):
    pass
    
  # ==========================================
  # ==========================================
  # User callback to patch the template data
  def vCustomizeTemplateData(self):
    for clsname,basename in self.mObserverBasePatch.items():
      for item in self.mData:
        if (item['category']!='class'): continue
        if (item['name']!=clsname): continue
        if (len(item['bases'])==0):
          item['bases']=[basename]
        break

    for item in self.mData:
      if (item['category']!='class'): continue
      item['name']=self.lPatchObserverName(item['name'])
      if (item.has_key('template_typedef')):
        item['template_typedef']=self.lPatchObserverName(item['template_typedef'])
      # Patch values:
      for cat in ['functions','sfunctions']:
        for fun in item[cat]:
          fun['type']=self.lPatchObserverName(fun['type'])
          fun['name']=self.lPatchObserverName(fun['name'])
          for param in fun['param']:
            param['type']=self.lPatchObserverName(param['type'])
    
  def lPatchObserverName(self,name):
    name=re.sub("oaObserver_([a-zA-Z0-9]*)_([a-zA-Z0-9]*)","oaObserver_\\1",name)
    return name

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
    if (self.mHintReprByBase.has_key(classname)):
      return self.mHintReprByBase[classname]
    return None

  # ==========================================
  # ==========================================
  # User callback to determine Db classes
  def vIsDbClass(self,classname):
    if (classname=='oaObject'): return 1
    if (classname=='oaVCSystem'): return 1
    if (classname=='oaEvalTextLink'): return 1
    if (classname=='oaPcellLink'): return 1
    if (classname=='oaBuildInfo'): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine Typedef should be skipped
  def vShouldSkipTypedef(self,name):
    if (not hasattr(self,'mHintSkipTypedef')):
      self.mHintSkipTypedef={ 
        # These types are done manually
        'oaChar':1,
        'oaByte':1,  
        'oaUIntPtr':1,  # Not Used
        'uintPtr':1, # Not Used
        'qsortCmpFunc':1, # Only used by Array::sort, need to remove
      }

    if (self.mHintSkipTypedef.has_key(name)): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if Enum should be skipped
  # We use this just to record the enums name repr functions
  def vShouldSkipEnum(self,name):
    # HINT
    if (name=='ArgTypeEnum'): return 1
    if (name=='MsgId'): return 1
    if (name=='oaObjectDomainModTypeEnum'): return 1
    if (name=='oaNetDomainModTypeEnum'): return 1
    if (name[-4:]=='Enum'):
      tname=name[:-4]
      if (name=='oaWaferFeatureEnum'):
        tname='oaWaferFeatureType'
      if (name=='oaWaferUnitsEnum'):
        tname='oaWaferUnitsType'
      self.mHintReprByBase[tname]="    oaString sresult(value.DataCall()->getName());\n"
    return 0

  # ==========================================
  # User callback to determine if Define should be skipped
  def vShouldSkipDefine(self,name):
    #if (name[0:2]=='oa' or name=='TRUE' or name=='FALSE'): return 1
    if (name=='TRUE' or name=='FALSE'): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a global function is manual
  def vIsManualGlobalFunction(self,sig):
    if (not hasattr(self,'mHintManualGlobal')):
      self.mHintManualGlobal={
        'oaBaseInit|void-void|simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,':1,
        'oaTechInit|void-void|simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,':1,
        'oaDesignInit|void-void|simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,':1,
        'oaDMInit|void-void|simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,':1,
        'oaWaferInit|void-void|simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,':1,
        'oaStartDaemon|void-void|cptr-char,':1,
      }

    if (self.mHintManualGlobal.has_key(sig)): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function is manual
  def vIsManualClassFunction(self,clsname,sig):
    if (not hasattr(self,'mHintManual')):
      self.mHintManual={
        'oaBuildInfo':{
          'getPackages|pptr-oaBuildInfo|':1,  # Complex list
        },
        'oaRegionQuery':{
          'getTopCellView|cptr-oaCellView|':1, # Need to remove const
        },
        # Special Iterators
        'oaDMObjectStatusRefIter':{
          'getNext|simple-oaDMObjectStatusRef|':1, # returns an object
        },
        'oaDMObjectVersionRefIter':{
          'getNext|simple-oaDMObjectVersionRef|':1, # returns an object
        },
        'oaDirIter':{
          'getNext|simple-oaBoolean|ref-oaString,':1, # boolean return and String parameter
        },
        'oaEnumPropIter':{
          'getNext|simple-oaBoolean|ref-oaString,':1, # boolean return and String parameter
        },
        'oaMemNetIter':{
          'getNext|ptr-oaNet|ref-oaUInt4,':1, # returns net and index
        },
        'oaModMemNetIter':{
          'getNext|ptr-oaModNet|ref-oaUInt4,':1, # returns net and index
        },
        'oaOccMemNetIter':{
          'getNext|ptr-oaOccNet|ref-oaUInt4,':1, # returns net and index
        },
        'oaVCVersionIter':{
          'getNext|simple-oaVCVersion|':1, # returns an object
        },
        'oaTech':{
          'getAppDefsByDataTypeIter|simple-oaIter_oaAppDef|simple-oaTechDataType,':1, # needs typecast
        },
      }

    if (self.mHintManual.has_key(clsname)):
      if (self.mHintManual[clsname].has_key(sig)): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a global function is skipped
  def vIsSkipGlobalFunction(self,sig):
    if (not hasattr(self,'mHintSkipGlobalFun')):
      self.mHintSkipGlobalFun=[
        # Skip these because they are templated
        r'oaMin|simple-obj|simple-obj,simple-obj,',
        r'oaMax|simple-obj|simple-obj,simple-obj,',
        r'oaRoundUpToGranularity|simple-obj|simple-obj,simple-obj,',
        r'oaRoundDownToGranularity|simple-obj|simple-obj,simple-obj,',
        r'operator\+|simple-oaComplex<obj>|cref-oaComplex<obj>,cref-oaComplex<obj>,',
        r'operator-|simple-oaComplex<obj>|cref-oaComplex<obj>,cref-oaComplex<obj>,',
        r'operator \*|simple-oaComplex<obj>|cref-oaComplex<obj>,cref-oaComplex<obj>,',
        r'operator/|simple-oaComplex<obj>|cref-oaComplex<obj>,cref-oaComplex<obj>,',
        r'oaSwap|void-void|ref-T,cptr-oaByte,',
        # Skip for type
        r'oaSwap|void-void|ref-oaComplex<oaFloat>,cptr-oaByte,',
        r'oaSwap|void-void|.*',
        r'oaDMFatal|simple-|simple-oaUInt4,simple-...,',
        # Define in a dox file
        r'find|ptr-oaLayer|cptr-oaTech,simple-oaLayerNum,',
        # This seems to be defined.
        'getTerm|ptr-oaModBitTerm|',
        # Don't need these from python
        'limitedDifference|simple-oaInt4|simple-oaInt4,simple-oaUInt4,',
        'limitedSum|simple-oaInt4|simple-oaInt4,simple-oaUInt4,',
        'oaStrIsEqual|simple-oaBoolean|cptr-char,cptr-char,simple-oaBoolean,',
        # Old Functions to skip, as new interface is used
        'oaBaseInit|void-void|simple-oaUInt4,simple-oaUInt4,',
        'oaTechInit|void-void|simple-oaUInt4,simple-oaUInt4,',
        'oaDesignInit|void-void|simple-oaUInt4,simple-oaUInt4,',
        'oaDMInit|void-void|simple-oaUInt4,simple-oaUInt4,',
        'oaWaferInit|void-void|simple-oaUInt4,simple-oaUInt4,',

      ]

    for key in self.mHintSkipGlobalFun:
      key=string.replace(key,'|','\\|')
      if (re.search("^"+key+"$",sig)!=None): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function is skipped
  def vIsSkipClassFunction(self,clsname,sig):
    if (not hasattr(self,'mHintSkipFun')):
      self.mHintSkipFun={ 
      # Set1: These just reduce the Link-Error message.
      #  These are things we don't want to implement
      r'oaBaseMemNetCollection': [
        # These use an undefined type: oaDatabase
        r'oaBaseMemNetCollection||ptr-oaDatabase,ptr-oaObject,simple-oaUInt4,',
      ],

      # Set2: This are in the header files, but not really implemented
      #  Theare are here to avoid link errors.
      #r'oaCollection_oaConstraintDef_oaSession':{
      #  r'oaCollection_oaConstraintDef_oaSession||cref-oaCollection_oaConstraintDef_oaSession,':1,
      #  r'includes|simple-oaBoolean|.*':1,
      #},
      #r'oaCollection_oaConstraintParamDef_oaSession':{
      #  r'oaCollection_oaConstraintParamDef_oaSession||cref-oaCollection_oaConstraintParamDef_oaSession,':1,
      #  r'includes|simple-oaBoolean|.*':1,
      #},
      r'oaBaseIter':{
        r'reset|void-void|cref-oaBaseCollection,':1,
      },
      # These AppDefs for oaAppObject should not be used.
      r'oaBooleanAppDef_oaAppObject':{
        r'get|ptr-oaBooleanAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaBooleanAppDef_oaAppObject|cref-oaString,simple-oaBoolean,.*':1,
        r'find|ptr-oaBooleanAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaDataAppDef_oaAppObject':{
        r'get|ptr-oaDataAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaDataAppDef_oaAppObject|cref-oaString,simple-oaUInt4,.*':1,
        r'find|ptr-oaDataAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaDoubleAppDef_oaAppObject':{
        r'get|ptr-oaDoubleAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaDoubleAppDef_oaAppObject|cref-oaString,simple-oaDouble,.*':1,
        r'find|ptr-oaDoubleAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaFloatAppDef_oaAppObject':{
        r'get|ptr-oaFloatAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaFloatAppDef_oaAppObject|cref-oaString,simple-oaFloat,.*':1,
        r'find|ptr-oaFloatAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaIntAppDef_oaAppObject':{
        r'get|ptr-oaIntAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaIntAppDef_oaAppObject|cref-oaString,simple-oaInt4,.*':1,
        r'find|ptr-oaIntAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaInterPointerAppDef_oaAppObject':{
        r'get|ptr-oaInterPointerAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaInterPointerAppDef_oaAppObject|cref-oaString,simple-oaBoolean,.*':1,
        r'find|ptr-oaInterPointerAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaIntraPointerAppDef_oaAppObject':{
        r'get|ptr-oaIntraPointerAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaIntraPointerAppDef_oaAppObject|cref-oaString,simple-oaBoolean,.*':1,
        r'find|ptr-oaIntraPointerAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaStringAppDef_oaAppObject':{
        r'get|ptr-oaStringAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaStringAppDef_oaAppObject|cref-oaString,cref-oaString,.*':1,
        r'find|ptr-oaStringAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaTimeAppDef_oaAppObject':{
        r'get|ptr-oaTimeAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaTimeAppDef_oaAppObject|cref-oaString,simple-oaTime,.*':1,
        r'find|ptr-oaTimeAppDef_oaAppObject|cref-oaString,':1,
      },
      r'oaVarDataAppDef_oaAppObject':{
        r'get|ptr-oaVarDataAppDef_oaAppObject|cref-oaString,':1,
        r'get|ptr-oaVarDataAppDef_oaAppObject|cref-oaString,simple-oaBoolean,.*':1,
        r'get|ptr-oaVarDataAppDef_oaAppObject|cref-oaString,simple-oaUInt4,.*':1,
        r'find|ptr-oaVarDataAppDef_oaAppObject|cref-oaString,':1,
      },

      # Set3: These are skipped because they shouldn't be used in python.
      # Mostly do to memory issues
      r'oaMapFile':{
        r'map|.*':1,
        r'unmap|.*':1,
        r'getFirstWindow|.*':1,
        r'closeWindows|.*':1,
      },
      r'oaMapFileWindow':{
        r'oaMapFileWindow||ptr-oaByte,simple-oaUInt4,simple-oaUInt8,ref-oaMapFile,':1,
        r'map|.*':1,
        r'unmap|.*':1,
        r'getNext|.*':1,
      },
      r'oaMapWindow':{
        r'oaMapWindow|.*':1,
        r'getBytes|.*':1,
      },
      r'oaNameSpace':{
        'get|void-void|cptr-oaByte,ref-oaString,ref-oaUInt4,':1
      },
      r'oaPackedData':{
        r'oaPackedData|.*':1,
        r'data|.*':1,
      },
      # Virutal base functions that don't need access
      r'oaArray_.*':{
        r'operator==|simple-oaBoolean|cref-oaArray_.*,':1,
        r'operator!=|simple-oaBoolean|cref-oaArray_.*,':1,
        # Didn't implement passing a sort function to array class
        r'sort|void-void|.*':1,
      }, 
      r'oaArrayBase_.*':{
        #r'getElements|.*':1,
      },
      # Access to oaCollection constructors isn't needed
      r'oaCollection_.*':{
        r'oaCollection_.*||cptr-.*,':1,
      },  
      # Find will not compile for this class
      r'oa2DLookupTbl_oaInt4_oaInt4_oaViaDefArrayValue':{
        r'find|.*':1,
      },
      # create without array conflict with with array in python, so remove it.
      r'oaParasiticNetwork':{
        r'create|ptr-oaParasiticNetwork|ptr-oaDesignObject,ptr-oaAnalysisPoint,':1,
      },
    }
    
    for ckey,cvalue in self.mHintSkipFun.items():
      if (re.search("^"+ckey+"$",clsname)!=None):
        for key in cvalue:
          key=string.replace(key,'|','\\|')
          if (re.search("^"+key+"$",sig)!=None): 
            #print "SKIP:",sig
            return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class constructor messages should be skipped
  def vIsIgnoreClassConstructor(self,clsname):
    if (not hasattr(self,'mHintSkipClassConstructor')):
      # These are listed just to cut down on the error messages
      self.mHintSkipClassConstructor={
        'oaBaseMemNetCollection':1,
        'oaConstraintInGroupIter':1,
        'oaCPPPcellDef':1,
        'oaDataObserver':1,
        'oaDesignUndoObserver':1,
        'oaDirIter':1,
        'oaEnumCollection':1,
        'oaEnumIterState':1,
        'oaMapWindow':1,
        'oaMemNetCollection':1,
        'oaModMemNetCollection':1,
        'oaNameSpace':1,
        'oaOccMemNetCollection':1,
        'oaOccTraverser':1,
        'oaPackedData':1,
        'oaPcellDef':1,
        'oaRegionQuery':1,
        'oaTermCollection':1,
        'oaTimer':1,
      }
      self.mHintSkipClassConstructorWild=[
        #r'oaBaseCallback_.*',
        #r'oaBaseCallback_.*',
        #r'oaDesignObjectCallback_.*',
        #r'oaTechObjectCallback_.*',
        #r'oaWaferObjectCallback_.*',
        r'oaCollection_.*',
      ]
      
    if (self.mHintSkipClassConstructor.has_key(clsname)):
      return 1
    for key in self.mHintSkipClassConstructorWild:
      key=string.replace(key,'|','\\|')
      if (re.search("^"+key+"$",clsname)!=None):
        return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class should diss-allow assign
  def vIsNoAssignClass(self,clsname):
    if (not hasattr(self,'mHintNoAssignClass')):
      self.mHintNoAssignClass={
        'oaConstraintInGroupIter':1,   
        'oaIter_oaConstraint':1,                           
        'oaIter_oaSimpleConstraint':1,                           
        'oaIter_oaLayerConstraint':1,                           
        'oaIter_oaLayerPairConstraint':1,                           
        'oaIter_oaLayerArrayConstraint':1,                           
      }
      self.mHintNoAssignClassWild=[
      ]
    if (self.mHintNoAssignClass.has_key(clsname)):
      return 1
    for key in self.mHintNoAssignClassWild:
      key=string.replace(key,'|','\\|')
      if (re.search("^"+key+"$",clsname)!=None):
        return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class should allow virtual
  def vAllowVirtualClass(self,clsname):
    if (clsname.find('Observer')>=0): return 1
    if (clsname.find('Query')>=0): return 1
    #if (clsname=='IEvalText'): return 1
    #if (clsname=='IPcell'): return 1
    #if (clsname=='IPcellGen'): return 1
    #if (clsname=='oaPcellDef'): return 1
    return 0

  # ==========================================
  # ==========================================
  # User callback to determine if a class function should allow virtual
  def vAllowVirtualFunction(self,clsname,sig):
    #if (clsname=='oaVCCallback' and 
    #    sig=='onVCMessageOut|simple-oaVCCallbackResult|cref-oaString,ptr-oaDMObject,simple-oaVCOperation,simple-oaVCMessageType,cref-oaString,'): 
    #  return 0
    return self.vAllowVirtualClass(clsname)

  # ==========================================
  # ==========================================
  # User callback to customize data before writting
  #   Use to add iterators
  def vCustomizeData(self):
    self._FindCollections()
    self._FindOaObjectClasses()
    return None

  # ==========================================
  # Find Collection template types
  def _FindCollections(self):
    sys.stderr.write("Finding Collection Classes:\n")
    self.mIterTable={}
    # Mannually add these 2 mappings
    self.mCollectionTable={
      u'oaEnumCollection':u'oaEnumPropIter',
      u'oaTextDisplayCollection':u'oaTextDisplayIter',
    }
    self.mIterSkipTable={
      'oaBaseMemNetIter':1,
      'oaBaseIter':1,
    }
    # Do template based classes
    for key,value in self.mTemplateCases['oaCollection'].items():
      iterclsname='oaIter_%s'%value[0]
      colclsname='oaCollection_%s'%key
      self.mIterTable[iterclsname]=1
      self.mCollectionTable[colclsname]=iterclsname
    # Do other special cased iterators
    for item in self.mData:
      # Find Iter classes by name
      if (item['category']!='class'): continue
      if (item['name'][0:6]=='oaIter' or item['name'][-4:]!='Iter'): continue
      if (self.mIterSkipTable.has_key(item['name'])): continue
      self.mIterTable[item['name']]=1
      for fun in item['functions']:
        # find constructors with 1 param
        if (fun['name']!=item['name']): continue
        if (len(fun['param'])!=1): continue
        param=fun['param'][0]
        parts=string.split(param['type'])
        # Record constructor type in the tables
        construct=None
        if (len(parts)==2 and parts[1]=='&'):
          if (parts[0]!=item['name']): construct=parts[0]
        elif (len(parts)==3 and parts[0]=='const' and parts[2]=='&'):
          if (parts[1]!=item['name']): construct=parts[1]
        if (construct):
          self.mCollectionTable[construct]=item['name']
    self.vReportData("CollectionTable",self.mCollectionTable)
    self.vReportData("IterTable",self.mIterTable)

    self.mOaTypeEnums={}
    for item in self.mData:
      if (item['category']!='file'): continue
      for fitem in item['enums'].values():
        if (fitem['name']=='oaTypeEnum'):
          for v in fitem['values']:
            self.mOaTypeEnums[v['name']]=1
          break
    self.vReportData("OaTypeEnums",self.mOaTypeEnums)

  # ==========================================
  # Find OA Object Classes
  def _FindOaObjectClasses(self):
    self.mOaObjectDerivedClasses={}
    for clsname,cls in self.mClasses.items():
      if (cls.get('base',None)==None): continue
      rootbasename=cls['rootbase']['name']
      basename=cls['base']['name']
      if (rootbasename!='oaObject'): continue
      dct=self.mOaObjectDerivedClasses.get(basename,{})
      self.mOaObjectDerivedClasses[basename]=dct
      dct[clsname]=1

    self.vReportData("ClassTree",self.mOaObjectDerivedClasses)

    #----------------------------------------
    # Object Casting Hints
    # Format: ['objectType to build','Validation Code']
    # This data insures that objects always endup as the
    #   lowest (most derived) class possible.
    # Note this data is tuples, and gets directly copied to the output file.
    # This table is now auto-generated
    #----------------------------------------
    self.mHintFromCasts={}
    self._FindCastData('oaObject')
    for key,dct in self.mHintFromCasts.items():
      lst=[]
      for skey,svalue in dct.items():
        lst.append((skey,svalue))
      lst=tuple(lst)
      self.mHintFromCasts[key]=lst

    self.vReportData("CastHints",self.mHintFromCasts)
    
  # ==========================================
  # FindCastData
  def _FindCastData(self,clsname):
    #print "_FindCastData",clsname
    dct={}
    rawclsname=self._GetRawClsname(clsname)
    if (rawclsname!=clsname):
      #print "  Skipping Templated Cast Type:",clsname
      return dct
    # see if we a a leaf class
    if (not self.mOaObjectDerivedClasses.has_key(clsname)):
      st='data->getType()==oac%sType'%(rawclsname[2:])
      dct[rawclsname]=st
      return dct
    dclsnames=self.mOaObjectDerivedClasses[clsname].keys()
    cls=self.mClasses[clsname]
    # walk our derived classes
    for dclsname in dclsnames:
      rawdclsname=self._GetRawClsname(dclsname)
      # Sometimes the is function is in the base class
      # So look in all bases classes
      wwcls=self.mClasses[clsname]
      wcls=wwcls
      while (1):
        wclsname=wcls['name']
        isname='is'+rawdclsname[2:]
        if (self._FindFunction(wcls,isname)):
          if (rawclsname[-6:]=='Object' and rawdclsname[2:]==rawclsname[2:-6]):
            # Skip for base oaXXXObject and derived oaXXX
            pass
          else:
            dct[rawdclsname]='data->%s()'%isname
            break
        if (rawdclsname[-6:]=='Object'):
          isname='is'+rawdclsname[2:-6]
          if (self._FindFunction(wcls,isname)):
            dct[rawdclsname]='data->%s()'%isname
            break
        if (wclsname=='oaObject'): break
        wcls=wcls['base']
      # Fetch child data
      child_dct=self._FindCastData(dclsname)
      # IF no is function use data from child
      if (not dct.has_key(rawdclsname)):
        for key,value in child_dct.items():
          dct[key]=value
      # if we have a create function, include another entry (oaText)
      if (rawdclsname in ['oaText']):
        st='data->getType()==oac%sType'%(rawdclsname[2:])
        dct[rawdclsname]=st
    self.mHintFromCasts[rawclsname]=dct
    return dct
      
  # ==========================================
  # Find a member function
  def _FindFunction(self,cls,funname):
    funs=cls['functions']
    st=0
    for fun in funs:
      if (fun['name']==funname): 
        st=1
        break
    return st

  # ==========================================
  # Find a static member function
  def _FindSFunction(self,cls,funname):
    funs=cls['sfunctions']
    st=0
    for fun in funs:
      if (fun['name']==funname): 
        st=1
        break
    return st

  # ==========================================
  # Find a member function
  def _GetRawClsname(self,clsname):
    loc=clsname.find('_')
    if (loc>0):
      return clsname[:loc]
    return clsname

  # ==========================================
  # ==========================================
  # User callback to get range check data for operator[] functions
  def vGetRangeCheck(self,clsname):
    if (not hasattr(self,'mHintIndexRangeCheck')):
      #----------------------------------------
      # Range Check on index.
      # These function are array lookup(index) functions, for which
      # the application needs to only pass a valid index.
      # Here we specify a function that returns the number of members, so
      # the generated code can valid the index.
      #----------------------------------------
      self.mHintIndexRangeCheck={
        'oaArray_.*':'data.Data().getNumElements()',
        'oaArrayBase_.*':'data.Data().getNumElements()',
        'oaAntennaAreaArray':'data.Data().getNumValues()',
        'oaBundleName':'data.Data().getNumMembers()',
        'oaComplexArray_.*':'data.Data().getNumElements()',
        'oaMapWindow':'data.Data().getSize()',
        'oaNameBase':'data.Data().getNumMembers()',
        'oaParamArray':'data.Data().getNumParams()',
        'oaPointArray':'data.Data().getNumElements()',
        'oaSimpleName':'data.Data().getNumMembers()',
        'oaViaDefArray':'data.Data().getNumValues()',
        'oaMfgLayerArray':'data.Data().getNumValues()',

        'oaNetTermArrayBase_.*':'data.Data().getNumElements()',
        'oaModNetTermArray':'data.Data().getNumElements()',
        'oaModNetTermNameArray':'data.Data().getNumElements()',
        'oaModNetTermPosArray':'data.Data().getNumElements()',
        'oaNetTermArray':'data.Data().getNumElements()',
        'oaNetTermNameArray':'data.Data().getNumElements()',
        'oaNetTermPosArray':'data.Data().getNumElements()',

        #'oaRouteLayerSpecArray':'data.Data().getNumValues()',
        #'oaPoleResidueArray':'data.Data().getNumReceivers()',
        #'oaRouteElementArray':'data.Data().getNumElements()',
        #'oaElmoreArray':'data.Data().getNumReceivers()',
        }

    for key,value in self.mHintIndexRangeCheck.items():
      if (re.search("^"+key+"$",clsname)!=None): return value
    return None

  # ==========================================
  # ==========================================
  # User callback to customize class before final write
  #   Use to add Iter functions from Collections
  def vCustomizeClassFunctions(self,cls):
    self._BuildClassIterFunctions(cls,'methods')
    self._BuildClassIterFunctions(cls,'static_methods')
    return None

  # ==========================================
  # Build Class Iter Functions
  def _BuildClassIterFunctions(self,mcls,ftype):
    clsname=mcls['name']
    additions=[]
    for fun in mcls[ftype]:
      if (not fun.has_key('value')): continue
      value=fun['value']
      if (not self.mCollectionTable.has_key(value)): continue
      newfun=copy.copy(fun)
      newname=fun['name']+'Iter'
      newfun['name']=newname
      newfun['call']=fun['name']
      newfun['desc']='This function returns an Iterator over the following collection: '+fun['desc']
      newfun['value']=self.mCollectionTable[value]
      newsig=string.replace(fun['sig'],value,self.mCollectionTable[value],1)
      newsig=string.replace(newsig,fun['name'],newfun['name'])
      newfun['sig']=newsig
      if (self.vIsManualClassFunction(clsname,newsig)):
        newfun['manual']=1
      additions.append(newfun)
    for fun in additions:
      mcls[ftype].append(fun)

  # ==========================================
  # ==========================================
  # User callback to add parameters to a constructor call
  #  Needed for virtual class without a default constructor
  def vGetConstructorParameters(self,clsname):
    return ''

  # ==========================================
  # ==========================================
  # User callback to get class cast data
  def vGetClassCastData(self,clsname):
    if (self.mHintFromCasts.has_key(clsname)):
      return self.mHintFromCasts[clsname]
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetRecordData(self,clsname):
    if (not hasattr(self,'mHintRecordData')):
      self.mHintRecordData={
        r'oaDataAppDef_.*':(('oaUInt4','size'),),
        }

    for key,value in self.mHintRecordData.items():
      if (re.search("^"+key+"$",clsname)!=None): return value
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetLockData(self,clsname):
    if (not hasattr(self,'mHintLockData')):
      self.mHintLockData={
        'oaVia':1,
        'oaRouteElement':1,
        'oaRouteElementArray':1,
        'oaLumpedElmore':1,
        'oaPiElmore':1,
        'oaPiPoleResidue':1,
        }

    if (self.mHintLockData.has_key(clsname)):
      return self.mHintLockData[clsname]
    return None

  # ==========================================
  # ==========================================
  # User callback to get record data
  def vGetMathData(self,clsname):
    if (not hasattr(self,'mHintMathData')):
      self.mHintMathData={
        'oaPoint':1,
      }

    if (self.mHintMathData.has_key(clsname)):
      return self.mHintMathData[clsname]
    return None

  # ==========================================
  # ==========================================
  # User callback to get the iterator function name if a class
  #  is an iterator
  def vGetIterFunction(self,clsname):
    if (self.mIterTable.has_key(clsname)): return 'getNext'
    return None

  # ==========================================
  # ==========================================
  # User callback to get see if class supports compare
  def vGetCompareData(self,clsname):
    if (not hasattr(self,'mHintCompareObject')):
      self.mHintCompareObject={
        'oaBox':1,
        'oaCoreBoxSpec':1,
        'oaHierPath':1,
        'oaLayerMap':1,
        'oaPoint':1,
        'oaPointArray':1,
        'oaRouteElementArray':1,
        'oaSegment':1,
        'oaSiteRef':1,
        'oaTimeStamp':1,
        'oaTransform':1,
        'oaVector':1,
        
        # These have been checked to be in the code
        'oaAntennaArea':1,
        'oaBundleName':1,
        'oaDMAttr':1,
        'oaDualInt':1,
        'oaName':1,
        'oaParam':1,
        'oaParamArray':1,
        'oaScalarName':1,
        'oaSegStyle':1,
        'oaSimpleName':1,
        'oaVectorBitName':1,
        'oaVectorName':1,
        'oaViaParam':1,
        }

    if (self.mHintCompareObject.has_key(clsname)): return 1
    return None

  # ==========================================
  # ==========================================
  # User callback to get parameter hint data
  def vGetParameterHintData(self,clsname,sig):
    dct={}
    for key,value in self.mFunctionHints.items():
      if (re.search("^"+key+"$",clsname)!=None):
        for k,v in value.items():
          dct[k]=v
    data=None
    for key,value in dct.items():
      key=string.replace(key,'|','\\|')
      if (re.search("^"+key+"$",sig)!=None):
        data=value
        break
    return data
  
  # ==========================================
  # ==========================================
  # User callback to get a report file
  def vGetReportFile(self,name):
    path="Logs/Report-%s.log"%name
    fp=open(path,'w')
    return fp
    
  # ==========================================
  # ==========================================
  # User callback to report data structures
  def vReportData(self,name,data):
    fp=self.vGetReportFile(name)
    pprint.pprint(data,fp)
    fp.close()

# ===================================================================
# ===================================================================
def Process():
  P=cOaDoxData2Desc()
  outputfile="OpenAccessDesc.py"

  # find and process input doxdata files
  indir="DoxData"
  files=[]
  print "Finding Files:"
  sys.stderr.write("Finding Files:\n")
  for name in os.listdir(indir):
    parts=string.split(name,'.')
    if (name=="__init__.py"): continue
    if (len(parts)!=2): continue
    if (parts[1]!='py'): continue
    if (parts[0][0]=='_'): continue
    name=parts[0]
    files.append(name)
  P.ReadInputFiles(indir,files)

  # Process data and generate output file

  P.ProcessData(outputfile)

# ===================================================================
if (__name__=="__main__"):
  Process()
    
