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
# Repr hints
#--------------------------------------------------------------------
#

def GetReprHints():
    #----------------------------------------
    # Code to generate Reprs
    #  For a given class, list the code to build its
    #  string repr. The final value should be named: sresult
    #----------------------------------------
    getNameByString="""\
    oaString sresult;
    value.DataCall()->getName(sresult);
"""
    getNameByViaDefString="""\
    oaString sresult;
    value.DataCall()->getViaDefName(sresult);
"""
    getNameByScalarName="""\
    oaScalarName name;
    oaString sresult;
    value.DataCall()->getName(name);
    name.get(sresult);
"""
    getNameBySimpleName="""\
    oaSimpleName name;
    oaString sresult;
    value.DataCall()->getName(name);
    name.get(sresult);
"""
    getNameByName="""\
    oaName name;
    oaString sresult;
    value.DataCall()->getName(name);
    name.get(sresult);
"""
    getNameByGet="""\
    oaString sresult;
    value.DataCall()->get(sresult);
"""
    getNameByBaseName="""\
    oaString sresult;
    value.DataCall()->getBaseName(sresult);
"""
    getNameByCellView="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaScalarName name;
    oaString str;
    value.DataCall()->getCell()->getName(name);
    name.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getView()->getName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getNameByLibCellView="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaScalarName name;
    oaString str;
    value.DataCall()->getLibName(name);
    name.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getCellName(name);
    name.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getViewName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getNameByDesignLibCellView="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaScalarName name;
    oaString str;
    value.DataCall()->getDesign()->getLibName(name);
    name.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getDesign()->getCellName(name);
    name.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getDesign()->getViewName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getNameByLib="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaScalarName name;
    oaString str;
    value.DataCall()->getLibName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getNameByInstPin="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaSimpleName sname;
    oaName name;
    oaString str;
    if (value.DataCall()->getInst()->isValid()) {
      value.DataCall()->getInst()->getName(sname);
      sname.get(str);
    }
    else {
      str="-";
    }
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getInstTerm()->getTermName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getNameByInstTerm="""\
    oaString sresult;
    oaString sep=\" \";
    sep[(oaUInt4)0]=oacInternalHierDelimiter;
    oaSimpleName sname;
    oaName name;
    oaString str;
    if (value.DataCall()->getInst()->isValid()) {
      value.DataCall()->getInst()->getName(sname);
      sname.get(str);
    }
    else {
      str="-";
    }
    sname.get(str);
    sresult+=oaString(str);
    sresult+=sep;
    value.DataCall()->getTermName(name);
    name.get(str);
    sresult+=oaString(str);
"""
    getPoint="""\
    oaChar sresult[64];
    sprintf(sresult,\"[%d,%d]\",value.DataCall()->x(),value.DataCall()->y());
"""
    getBox="""\
    oaChar sresult[128];
    sprintf(sresult,\"[[%d,%d],[%d,%d]]\",value.DataCall()->left(),value.DataCall()->bottom(),value.DataCall()->right(),value.DataCall()->top());
"""
        
    hints={
            'oaLib':getNameByScalarName,
            'oaCell':getNameByScalarName,
            'oaView':getNameByScalarName,
            'oaCellView':getNameByCellView,
            'oaDesign':getNameByLibCellView,
            'oaBlock':getNameByDesignLibCellView,
            'oaTech':getNameByLib,
            'oaModule':getNameByScalarName,
            'oaDMFile':getNameByString,
            
            'oaModAssignment':getNameByString,
            'oaModBusNetDef':getNameByScalarName,
            'oaModBusTermDef':getNameByScalarName,
            'oaModInst':getNameBySimpleName,
            'oaModInstHeader':getNameByLibCellView,
            'oaModInstTerm':getNameByInstTerm,
            'oaModModulesInstHeader':getNameByScalarName,
            'oaModNet':getNameByName,
            'oaModScalarNet':getNameByScalarName,
            'oaModTerm':getNameByName,
            'oaModScalarTerm':getNameByScalarName,
            'oaModVectorInstDef':getNameByScalarName,

            'oaOccAssignment':getNameByString,
            'oaOccBusNetDef':getNameByScalarName,
            'oaOccBusTermDef':getNameByScalarName,
            'oaOccInst':getNameBySimpleName,
            'oaOccInstHeader':getNameByLibCellView,
            'oaOccInstTerm':getNameByInstTerm,
            'oaOccModulesInstHeader':getNameByScalarName,
            'oaOccNet':getNameByName,
            'oaOccScalarNet':getNameByScalarName,
            'oaOccTerm':getNameByName,
            'oaOccScalarTerm':getNameByScalarName,
            'oaOccVectorInstDef':getNameByScalarName,

            'oaLayer':getNameByString,
            'oaPoint':getPoint,
            'oaBox':getBox,
            'oaPurpose':getNameByString,
            'oaSiteDef':getNameByString,
            'oaViaDef':getNameByString,
            'oaProp':getNameByString,
            'oaGroup':getNameByString,
            'oaCluster':getNameByString,
            'oaScanChain':getNameByString,
            'oaViaHeader':getNameByViaDefString,

            'oaAssignment':getNameByString,
            'oaBusNetDef':getNameByScalarName,
            'oaBusTermDef':getNameByScalarName,
            'oaInst':getNameBySimpleName,
            'oaInstHeader':getNameByLibCellView,
            'oaInstPin':getNameByInstPin,
            'oaInstTerm':getNameByInstTerm,
            'oaNet':getNameByName,
            'oaScalarNet':getNameByScalarName,
            'oaPin':getNameByString,
            'oaTerm':getNameByName,
            'oaScalarTerm':getNameByScalarName,
            'oaVectorInstDef':getNameByScalarName,
            'oaArrayInst':getNameByScalarName,
            'oaScalarInst':getNameByScalarName,

#            'oaConnectDef'
#            'oaRowHeader'
#            'oaScanChainInst'
#            'oaScanChainSet'
#            'oaSteiner'
#            'oaTrackPattern'
#            'oaBlockage':getNameByString,
            'oaCellViewBoundary':getNameByString,
            'oaClusterBoundary':getNameByString,
#            'oaPRBounday':
#            'oaSnapBoundary':
#            'oaMarker':
#            'oaRoute':
            'oaRow':getNameByString,
#            'oaShape':

            'oaScalarName':getNameByGet,
            'oaSimpleName':getNameByGet,
            'oaBundleName':getNameByGet,
            'oaVectorName':getNameByGet,
            'oaVectorBitName':getNameByGet,
            'oaName':getNameByGet,
            'oaNameMem':getNameByBaseName,
            }
    return hints
    
    