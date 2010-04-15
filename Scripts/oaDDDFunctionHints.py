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
# Function hints
#--------------------------------------------------------------------
#

#----------------------------------------
# Functions Hints. 
#   Hints are arranged by a dict indexed by class.
#   Within the class is a dict indexed by function signature.
#   Within each signature is a list of dict's
#     The first is for the output, then one per parameter.
# Specify the direction of arguments that can't be
# automatically determined.
# Value is a list of integers, one for each parameter
#----------------------------------------

def GetFunctionHints():
 hints={
  'oaAnalysisLib':{   
    'create|ptr-oaAnalysisLib|ptr-oaTech,cref-oaString,cref-oaString,cptr-oaScalarName,cptr-oaScalarName,cptr-oaScalarName,':
         [{}, {}, {}, {}, {'aof':1,}, {'aof':1,}, {'aof':1,} ],
  },
  'oaAppProp':{
    'setValue|void-void|simple-oaUInt4,cptr-oaByte,':
        [{}, {}, {'pre':1,} ],
    'create|ptr-oaAppProp|ptr-oaObject,cref-oaString,cref-oaString,simple-oaUInt4,cptr-oaByte,':
        [{}, {}, {}, {}, {}, {'pre':1,} ],
    'getValue|void-void|ptr-oaByte,':
       [{}, {'check':'(data.Data()->getSize()!=p1.Len())\nnumber of bytes does not match property size'} ],
  },
  'oaArray_.*':{
    'getElements|cptr-oa.*|':
      [{'init':'(data.Data().getNumElements())'} ],
    'getElements|cpptr-oa.*|':
      [{'init':'(data.Data().getNumElements())'} ],
    'oaArray_.*||cptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
    'oaArray_.*||cpptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
  },
  'oaArrayBase_.*':{
    'getElements|cptr-oa.*|':
      [{'init':'(data.Data().getNumElements())'} ],
    'getElements|cpptr-oa.*|':
      [{'init':'(data.Data().getNumElements())'} ],
    'oaArrayBase_.*||cptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
    'oaArrayBase_.*||cpptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
    'set|void-void|cptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
    'set|void-void|cpptr-.*,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
  },
  'oaAreaBoundary':{
    'create|ptr-oaAreaBoundary|ptr-oaBlock,cref-oaString,cref-oaPointArray,cptr-oaString,':
      [{}, {}, {}, {}, {'check':'(p3.Data().getNumElements()==p4.Len())\nnumber of edges does not match number of points',} ],
    'create|ptr-oaAreaBoundary|ptr-oaBlock,cref-oaPointArray,cptr-oaString,':
      [{}, {}, {}, {'check':'(p2.Data().getNumElements()==p3.Len())\nnumber of edges does not match number of points',} ],
  },
  'oaArrayInst':{
    'create|ptr-oaArrayInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,simple-oaOffset,simple-oaOffset,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,simple-oaPlacementStatus,':
        [{}, {}, {}, {}, {}, {}, {}, {}, {}, {'aof':1,}, {},],
    'create|ptr-oaArrayInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,simple-oaOffset,simple-oaOffset,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,simple-oaPlacementStatus,':
        [{}, {}, {}, {}, {}, {}, {}, {}, {'aof':1,}, {},],
    'create|ptr-oaArrayInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,simple-oaOffset,simple-oaOffset,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,simple-oaPlacementStatus,':
        [{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {'aof':1,}, {},],
    'create|ptr-oaArrayInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,simple-oaOffset,simple-oaOffset,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,simple-oaPlacementStatus,':
        [{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {'aof':1,}, {},],
  },
  'oaBox':{
    'toPoints|void-void|ptr-oaPoint,':
        [{}, {'check':'(p1.Len()!=4)\nnumber of points must be 4'} ],
  },
  'oaBoundary':{
    'getEdgeNames|void-void|ptr-oaString,':
        [{}, {'check':'(data.Data()->getNumEdges()!=p1.Len())\nnumber of edges does not match number of points',} ],
    'setEdges|void-void|cref-oaPointArray,cptr-oaString,':
       [{}, {}, {'check':'(p1.Data().getNumElements()==p2.Len())\nnumber of edges does not match number of points',} ],
  },
  'oaClusterBoundary':{
    'create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaString,cref-oaPointArray,cptr-oaString,':
      [{}, {}, {}, {}, {'check':'(p3.Data().getNumElements()==p4.Len())\nnumber of edges does not match number of points',} ],
    'create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaPointArray,cptr-oaString,':
      [{}, {}, {}, {'check':'(p2.Data().getNumElements()==p3.Len())\nnumber of edges does not match number of points',} ],
  },
  'oaComplexArray_.*':{
    'getElements|ptr-oaComplex_.*|':
       [{'init':'(data.Data().getNumElements())'} ],
  },
  'oaCustomVia':{
    'create|ptr-oaCustomVia|ptr-oaBlock,cptr-oaCustomViaDef,cref-oaTransform,cptr-oaParamArray,':
       [{}, {}, {}, {}, {'aof':1,} ],
  },
  'oaDataAppDef_.*':{
    'set|void-void|ptr-.*,cptr-oaByte,':
       [{}, {}, {'check':'(data.Data()->getSize()!=p2.Len())\nnumber of bytes does not match oaDataAppDef::getSize',}, ],
    'get|void-void|cptr-.*,ptr-oaByte,':
       [{}, {}, {'check':'(data.Data()->getSize()!=p2.Len())\nnumber of bytes does not match oaDataAppDef::getSize',}, ],
    'getDefault|void-void|ptr-oaByte,':
       [{}, {'check':'(data.Data()->getSize()!=p1.Len())\nnumber of bytes does not match oaDataAppDef::getSize',}, ],
    'get|ptr-oaDataAppDef_.*|cref-oaString,simple-oaUInt4,cptr-oaByte,simple-oaBoolean,':
       [{}, {}, {}, {'pre':1,}, {}],
    'get|ptr-oaDataAppDef_.*|cref-oaString,cptr-oaAppObjectDef,simple-oaUInt4,cptr-oaByte,simple-oaBoolean,':
       [{}, {}, {}, {}, {'pre':1,}, {}],
  },
  'oaDerivedLayer':{
     'create|ptr-oaDerivedLayer|ptr-oaTech,cptr-oaLayer,cptr-oaLayer,cptr-oaDerivedLayerDef,cref-oaString,simple-oaLayerNum,cptr-oaDerivedLayerParamArray,':
         [{}, {}, {}, {}, {}, {}, {}, {'aof':1}, ],
     'create|ptr-oaDerivedLayer|ptr-oaTech,cptr-oaLayer,cptr-oaDerivedLayerDef,cref-oaString,simple-oaLayerNum,cptr-oaDerivedLayerParamArray,':
         [{}, {}, {}, {}, {}, {}, {'aof':1}, ],
     'find|ptr-oaDerivedLayer|cptr-oaTech,simple-oaLayerNum,simple-oaLayerNum,cptr-oaDerivedLayerDef,cptr-oaDerivedLayerParamArray,simple-oaBoolean,':
         [{}, {}, {}, {}, {}, {'aof':1}, {}, ],
     'find|ptr-oaDerivedLayer|cptr-oaTech,simple-oaLayerNum,cptr-oaDerivedLayerDef,cptr-oaDerivedLayerParamArray,simple-oaBoolean,':
         [{}, {}, {}, {}, {'aof':1},{}, ],
  },
  'oaDesign':{
     'open|ptr-oaDesign|ptr-oaStdViaDef,ptr-oaViaParam,':
         [{}, {}, {'aof':1}, ],
     'open|ptr-oaDesign|ptr-oaCustomViaDef,ptr-oaParamArray,':
         [{}, {}, {'aof':1}, ],
     'getPcellDef|ptr-oaPcellDef|':
         [{'dref':1}, ],
     'defineSuperMaster|void-void|ptr-oaPcellDef,cref-oaParamArray,':
         [{}, {'aof':1}, {}, ],
  },
  'oaDualIntArray':{
    'oaDualIntArray||cptr-oaDualInt,simple-oaUInt4,':
       [{}, {'post':1}, {}, ],
  },
  'oaEnumProp':{
    'create|ptr-oaEnumProp|ptr-oaObject,cref-oaString,cref-oaString,simple-oaUInt4,cptr-oaString,':
       [{}, {}, {}, {}, {}, {'pre':1,} ],
  },
  #'oaEvalText':{
  # 'setCallback|void-void|ptr-oaTextDataCallback,':
  #     [{}, {'aof':1, } ],
  # 'create|ptr-oaEvalText|ptr-oaCellView,simple-oaLayerNum,simple-oaPurposeNum,cref-oaString,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaUInt4,ptr-oaTextDataCallback,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,':
  #     [{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, {} ],
  # 'getCallback|ptr-oaTextDataCallback|':
  #     [{'borrow':1, }, ],
  #  },
  'oaFile':{
    'read|simple-oaUInt4|ptr-oaByte,simple-oaUInt4,':
       [{}, {'post':1}, {}, ],
    'write|simple-oaUInt4|ptr-oaByte,simple-oaUInt4,':
       [{}, {'post':1}, {}, ],
  },
  'oaInstTerm':{
     'create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,.*':
       [{}, {'novalidate':1}, {}, {}, {}, {}, ],
  },
  'oaLayerArrayConstraint':{
    'create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaLayerConstraint':{
    'create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaLayerPairConstraint':{
    'create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaLib':{
    'create|ptr-oaLib|cref-oaScalarName,cref-oaString,simple-oaLibMode,cref-oaString,cptr-oaDMAttrArray,':
       [{}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaLibDef':{
    'create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, {'aof':1, },],
  },
  'oaModInstTerm':{
     'create|ptr-oaModInstTerm|ptr-oaModNet,ptr-oaModInst,.*':
       [{}, {'novalidate':1}, {}, {}, {}, {}, ],
  },
  'oaModScalarInst':{
    'create|ptr-oaModScalarInst|ptr-oaModule,ptr-oaDesign,cref-oaScalarName,cptr-oaParamArray,':
       [{}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaModScalarInst|ptr-oaModule,ptr-oaDesign,cptr-oaParamArray,':
       [{}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaModScalarInst|ptr-oaModule,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaModScalarInst|ptr-oaModule,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaModVectorInst':{
    'create|ptr-oaModVectorInst|ptr-oaModule,ptr-oaDesign,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaModVectorInst|ptr-oaModule,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaModVectorInstBit':{
    'create|ptr-oaModVectorInstBit|ptr-oaModule,ptr-oaDesign,cref-oaScalarName,simple-oaUInt4,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {'aof':1, }, ],
    'create|ptr-oaModVectorInstBit|ptr-oaModule,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaUInt4,cptr-oaParamArray,':
       [{}, {}, {}, {}, {}, {}, {}, {'aof':1, }, ],
  },
  'oaName':{
    'getVectorBit|ptr-oaVectorBitName|':
       [{'dref':1}, ],
    'getVector|ptr-oaVectorName|':
       [{'dref':1}, ],
    'getScalar|ptr-oaScalarName|':
       [{'dref':1}, ],
    'getBundle|ptr-oaBundleName|':
       [{'dref':1}, ],
  },
  'oaNameSpace':{
    'getVectorBitName|void-void|cptr-oaNameMem,simple-oaUInt4,simple-oaUInt4,ref-oaString,ref-oaUInt4,':
        [{},{'post':1, }, {}, {}, {}, {}, ],
    'getMemberArray|void-void|cptr-oaNameMem,simple-oaUInt4,ref-oaString,ref-oaUInt4,':
        [{},{'post':1, }, {}, {}, {}, ],
  },
  'oaNetTermPair_.*':{
    'getNet|cptr-oa.*':
        [{'rmconst':1}, ],
  },
  
  'oaPackedData':{
    'readBytes|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaByte,':
       [{}, {}, {}, {'pre':1,} ],
    'readByteArray|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaByte,':
       [{}, {}, {}, {'pre':1,} ],
    'readUInt2Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaUInt2,':
       [{}, {}, {}, {'pre':1,} ],
    'readInt2Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaInt2,':
       [{}, {}, {}, {'pre':1,} ],
    'readUInt4Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaUInt4,':
       [{}, {}, {}, {'pre':1,} ],
    'readInt4Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaInt4,':
       [{}, {}, {}, {'pre':1,} ],
    'readUInt8Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaUInt8,':
       [{}, {}, {}, {'pre':1,} ],
    'readInt8Array|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaInt8,':
       [{}, {}, {}, {'pre':1,} ],
    'readFloatArray|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaFloat,':
       [{}, {}, {}, {'pre':1,} ],
    'readDoubleArray|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaDouble,':
       [{}, {}, {}, {'pre':1,} ],
    'readPointArray|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaPoint,':
       [{}, {}, {}, {'pre':1,} ],
    'readBoxArray|void-void|ref-oaUInt4,simple-oaUInt4,ptr-oaBox,':
       [{}, {}, {}, {'pre':1,} ],

    'writeBytes|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaByte,':
       [{}, {}, {}, {'pre':1, } ],
    'writeByteArray|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaByte,':
       [{}, {}, {}, {'pre':1, } ],
    'writeUInt2Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaUInt2,':
       [{}, {}, {}, {'pre':1, } ],
    'writeInt2Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaInt2,':
       [{}, {}, {}, {'pre':1, } ],
    'writeUInt4Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaUInt4,':
       [{}, {}, {}, {'pre':1, } ],
    'writeInt4Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaInt4,':
       [{}, {}, {}, {'pre':1, } ],
    'writeUInt8Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaUInt8,':
       [{}, {}, {}, {'pre':1, } ],
    'writeInt8Array|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaInt8,':
       [{}, {}, {}, {'pre':1, } ],
    'writeFloatArray|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaFloat,':
       [{}, {}, {}, {'pre':1, } ],
    'writeDoubleArray|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaDouble,':
       [{}, {}, {}, {'pre':1, } ],
    'writePointArray|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaPoint,':
       [{}, {}, {}, {'pre':1, } ],
    'writeBoxArray|void-void|ref-oaUInt4,simple-oaUInt4,cptr-oaBox,':
       [{}, {}, {}, {'pre':1, } ],

    #'swapUInt2|void-void|ref-oaUInt2,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==2)\nnumber of bytes must be 2',} ],
    #'swapInt2|void-void|ref-oaInt2,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==2)\nnumber of bytes must be 2',} ],
    #'swapUInt4|void-void|ref-oaUInt4,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==4)\nnumber of bytes must be 4',} ],
    #'swapInt4|void-void|ref-oaInt4,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==4)\nnumber of bytes must be 4',} ],
    #'swapUInt8|void-void|ref-oaUInt8,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==8)\nnumber of bytes must be 8',} ],
    #'swapInt8|void-void|ref-oaInt8,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==8)\nnumber of bytes must be 8',} ],
    #'swapDouble|void-void|ref-oaDouble,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==8)\nnumber of bytes must be 8',} ],
    #'swapFloat|void-void|ref-oaFloat,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==4)\nnumber of bytes must be 4',} ],
    #'swapTime|void-void|ref-oaTime,cptr-oaByte,':
    #   [{}, {}, {'check':'(p2.Len()==4)\nnumber of bytes must be 4',} ],
  },
  'oaParam':{
    'getAppVal|void-void|ptr-oaByte,':
       [{}, {'check':'(data.Data().getNumBytes()!=p1.Len())\nnumber of bytes does not match parameter size'} ],
    'oaParam||cref-oaString,cref-oaString,simple-oaUInt4,cptr-oaByte,':
       [{}, {}, {}, {}, {'pre':1,} ],
    'setAppVal|void-void|simple-oaUInt4,cptr-oaByte,':
       [{}, {}, {'pre':1,} ],
  },
  'oaParasiticNetwork':{
    'create|ptr-oaParasiticNetwork|ptr-oaDesignObject,simple-oaUInt4,pptr-oaAnalysisPoint,':
       [{}, {}, {}, {'pre':1,}, ],
  },
  'oaPcellLink':{
    'getPcellDef|ptr-oaPcellDef|cref-oaString,':
       [{'dref':1}, {},],
  },
  'oaPointArray':{
    #'getPoints|ptr-oaPoint|':
    #   [{'init':'(data.Data().getNumElements())'} ],
    'oaPointArray||cptr-oaPoint,simple-oaUInt4,':
       [{}, {'post':1,}, {}],
  },
  'oaPRBoundary':{
    'create|ptr-oaPRBoundary|ptr-oaBlock,cref-oaPointArray,cptr-oaString,':
       [{}, {}, {}, {'check':'(p2.Data().getNumElements()==p3.Len())\nnumber of edges does not match number of points', } ],
  },
  'oaScalarInst':{
   'create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
   'create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {'aof':1, }, {}, {}, ],
   'create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
   'create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
  },
  'oaScanChain':{
    'create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,':
      [{}, {}, {}, {}, {}, {'aof':1,}, {}, ],
  },
  'oaSimpleConstraint':{
    'create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {'aof':1, } ],
    'create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,':
       [{}, {}, {}, {}, {}, {'aof':1, } ],
  },
  'oaSimpleName':{
    'getVectorBit|ptr-oaVectorBitName|':
       [{'dref':1}, ],
    'getVector|ptr-oaVectorName|':
       [{'dref':1}, ],
    'getScalar|ptr-oaScalarName|':
       [{'dref':1}, ],
  },
  'oaSnapBoundary':{
    'create|ptr-oaSnapBoundary|ptr-oaBlock,cref-oaPointArray,cptr-oaString,':
      [{}, {}, {}, {'check':'(p2.Data().getNumElements()==p3.Len())\nnumber of edges does not match number of points', } ],
  },
  'oaStdVia':{
    'create|ptr-oaStdVia|ptr-oaBlock,cptr-oaStdViaDef,cref-oaTransform,cptr-oaViaParam,':
       [{}, {}, {}, {}, {'aof':1, } ],
  },
  'oaVCVersion':{
    'compare|simple-oaVersionComp|cptr-oaVCVersion,':
       [{}, {'aof':1, } ],
  },
  'oaVarDataAppDef_.*':{
    'set|void-void|ptr-oa.*,simple-oaUInt4,cptr-oaByte,':
       [{}, {}, {}, {'pre':1,}, ],
    'get|void-void|cptr-oa.*,ptr-oaByte,':
      [{}, {}, {'check':'(data.Data()->getSize(p1.Data())==p2.Len())\nnumber bytes does not match object data', } ],
    'getDefault|void-void|ptr-oaByte,':
      [{}, {'check':'(data.Data()->getDefaultSize()==p1.Len())\nnumber bytes does not match default size', } ],
    'get|ptr-oaVarDataAppDef_.*|cref-oaString,simple-oaUInt4,cptr-oaByte,simple-oaBoolean,':
       [{}, {}, {}, {'pre':1,}, {}, ],
    'get|ptr-oaVarDataAppDef_.*|cref-oaString,cptr-oaAppObjectDef,simple-oaUInt4,cptr-oaByte,simple-oaBoolean,':
       [{}, {}, {}, {}, {'pre':1,}, {}, ],
  },
  'oaVectorInst':{
   'create|ptr-oaVectorInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
   'create|ptr-oaVectorInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
  },
  'oaVectorInstBit':{
    'create|ptr-oaVectorInstBit|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,simple-oaUInt4,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
    'create|ptr-oaVectorInstBit|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaUInt4,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,':
       [{}, {}, {}, {}, {}, {}, {}, {}, {'aof':1, }, {}, {}, ],
  },
 }

 return hints
  
