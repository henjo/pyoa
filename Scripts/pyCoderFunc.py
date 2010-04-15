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
# This file contains classes for genesis class descriptions.
# These descriptions describe how each genesis class is to be
# wrapped in python.
# These description will be used to automatically build the
# C++ wrapper code for these objects as python extensions.
#--------------------------------------------------------------------

import copy
import types
import string

# ----------------------------
def GenLine(fp):
    fp.write("// ------------------------------------------------------------------\n")

# ----------------------------
def GenTry(fp):
    fp.write("  try {\n")
    
# ----------------------------
def GenCatch(fp,end='NULL'):
    fp.write("""\
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return %s;
  }
"""%(end))
    
# ===================================================================
# Sort function for functions
def SortFunctionName(f1s,f2s):
    if (f1s.mName<f2s.mName): return -1
    return 1
    
# -------------------------------------
# Change Param types from strings to objects
def PrepareParam(dict,param,cls,where):
    if (type(param.mType)==types.StringType or
        type(param.mType)==types.UnicodeType):
        base=dict.get(param.mType)
        if (not base):
            raise ("Undefined param class name: %s, in class: %s, %s, desc: %s"%
                   (param.mType,cls.mName,where,param.mDesc))
        param.mType=base
    else:
        print "** Unknown Param Type: ",param.mType,type(param.mType)

# -------------------------------------
# Return a type def
def ExpandTagSig(tag,clsname):
    result=""
    if (tag=='simple'):
        result+=clsname
    elif (tag=='const'):
        result+='const '+clsname
    elif (tag=='ptr'):
        result+=clsname+'*'
    elif (tag=='ptrref'):
        result+=clsname+'*&'
    elif (tag=='ref'):
        result+=clsname+'&'
    elif (tag=='cref'):
        result+='const '+clsname+'&'
    elif (tag=='cptr'):
        result+='const '+clsname+'*'
    return result

# -------------------------------------
# Return a full tag
def ExpandSig(sig,clsname):
  name,value,params=string.split(sig,'|')
  if (value=='void-void'):
    result='void'
  elif (value==' '):
    result=''
  else:
    result=ExpandTagSig(value,clsname)
  result+=' %s('%name
  if (params and params[-1]==','): params=params[:-1]
  first=1
  if (params):
    for param in string.split(params,','):
      if (first): first=0
      else: result+=','
      if (len(string.split(param,'-'))!=2):
        raise 'Error: "%s" @ "%s"'%(param,params)
      typ,cls=string.split(param,'-')
      result+=ExpandTagSig(typ,cls)
  result+=')'
  return result
  
# ===================================================================
class cParamDesc:
    __doc__="cParamDesc - Container for a function parameter description"
    def __init__(self,
        type,           # Required: Type of object
        name='',
        desc=None,      # Description
        tag=None,       # Tag for parameter type
        utag=None,      # Use tag
        varset=None,    # Variable Initialization from set
        varcheck=None,   # Variable Check
        varprecount=None,   # Variable PreCount
        varpostcount=None,   # Variable PreCount
        varaof=None,    # Variable is an address of
        varsized=None,  # Variable is an array, that is auto-sized
        varcopy=None,   # Variable is and address of, but needs a new copy
        varlock=None,   # Variable is an address that needs locking
        varrecord=None,  # Record value in record variable
        varnovalidate=None, # Db valud is not to be validated
     ):
        self.mName=name
        self.mType=type
        self.mTag=tag
        self.mUseTag=utag
        self.mDesc=desc
        self.mVarSet=varset
        self.mVarCheck=varcheck
        self.mVarPreCount=varprecount
        self.mVarPostCount=varpostcount
        self.mVarSized=varsized
        self.mVarAof=varaof
        self.mVarCopy=varcopy
        self.mVarLock=varlock
        self.mVarRecord=varrecord
        self.mVarNovalidate=varnovalidate

        self.mArray=None
        if (self.mVarPreCount or self.mVarPostCount or self.mVarCheck or self.mVarSized):
            self.mArray=1

# ===================================================================
class cParamListDesc:
    __doc__="cParamListDesc - Container for a list of parameters"
    def __init__(self,lst,fun):
        self.mList=lst
        self.mFun=None

    # -------------------------------------
    # Generate the local variables needed for
    #  parameters to a function call
    def GenParamVars(self,fp,indent):
        i=1
        for param in self.mList:
            if (param.mArray):
                fp.write("%*sPyParam%s_Array p%d;\n"%(indent,"",param.mType.mName,i))
            else:
                fp.write("%*sPyParam%s p%d;\n"%(indent,"",param.mType.mName,i))
            i+=1
            
    # -------------------------------------
    # Generate the control string to PyArg_ParseTuple
    #  that is needed to parse the input parameters
    def GenParamParseData(self,fp):
        i=1
        for param in self.mList:
            fp.write("O&")
            i+=1

    # -------------------------------------
    # Generate the arguments to PyArg_ParseTuple
    #  that is needed to fetch the input parameters
    def GenParamParseArgs(self,fp,indent):
        i=1
        for param in self.mList:
            if (param.mArray):
                fp.write(",\n%*s&Py%s_Array_Convert,&p%d"%(indent,"",param.mType.mName,i))
            elif (param.mVarAof):
                fp.write(",\n%*s&Py%s_ConvertAof,&p%d"%(indent,"",param.mType.mName,i))
            else:
                fp.write(",\n%*s&Py%s_Convert,&p%d"%(indent,"",param.mType.mName,i))
            i+=1

    # ----------------------------
    # Generate the ParseTuple Command
    def GenParamParseTuple(self,fp,indent,cls=None):
        fp.write("%*sif (PyArg_ParseTuple(args,\""%(indent,""))
        self.GenParamParseData(fp)
        fp.write("\"")
        self.GenParamParseArgs(fp,indent+6)
        fp.write(")) {\n")
        i=1
        for param in self.mList:
            if (param.mVarSet):
                lines=string.split(param.mVarSet,"\n")
                fp.write("%*s%s\n"%(indent+4,"",lines[0]))
            if (param.mVarCheck):
                lines=string.split(param.mVarCheck,"\n")
                if (len(lines)==2):
                    fp.write("%*sif (!%s) {\n"%(indent+4,"",lines[0]))
                    fp.write("%*sPyErr_SetString(PyExc_TypeError,\n"%(indent+8,""))
                    fp.write("%*s\"%s\");\n"%(indent+12,"",lines[1]))
                    fp.write("%*sreturn NULL;\n"%(indent+8,""))
                    fp.write("%*s}\n"%(indent+4,""))
                elif (len(lines)==1):
                    fp.write("%*s%s;\n"%(indent+4,"",lines[0]))
            if (param.mType.mIsDb and param.mUseTag!='ref' and not param.mVarAof and 
                  not param.mArray and not param.mVarNovalidate):
                fp.write("%*sif (!PyValidateDbObject(p%d.Data(),%d)) return NULL;\n"%(indent+4,"",i,i))
            i+=1
        i=1
        for param in self.mList:
            if (param.mVarRecord):
                fp.write("%*sself->%s=p%d.Data();\n"%(indent+4,"",param.mVarRecord,i))
            if (param.mVarLock):
                fp.write("%*sPyoaLockObject(self->locks,PyTuple_GetItem(args,%d));\n"%(indent+4,"",i-1))
            i+=1

    # -------------------------------------
    # Gen the end of the ParseTuple
    def GenParamEndParse(self,fp,indent):
        fp.write("%*s}\n"%(indent,""))
        
    # -------------------------------------
    # Generate the arguments to a function call
    def GenParamVarAccess(self,indent):
        i=1
        result=""
        for param in self.mList:
            if (i>1): result+=(",")
            if (param.mVarPreCount):
                result+=("p%d.Len(),"%i)

            if (param.mVarAof):
                result+=("p%d.DataAof()"%i)
            elif (param.mVarCopy):
                result+=("new %s(p%d.Data())"%(param.mType.mTypeName,i))
            elif (param.mArray):
                result+=("p%d.Data()"%i)
            else:
                result+=("p%d.Data()"%i)

            if (param.mVarPostCount):
                result+=(",p%d.Len()"%i)
            i+=1
        return result

    # -------------------------------------
    # Generate a description of the required input arguments for this call
    def GenParamChoice(self,cls=None):
        choice="("
        i=1
        for param in self.mList:
            if (i>1): choice+=","
            if (param.mArray):
                choice+='['+param.mType.mName+']'
            else:
                choice+=param.mType.mName
            i+=1
        choice+=")"
        return choice

    # -------------------------------------
    # Generate a description of the required input arguments for this call
    def GenParamCall(self,cls=None):
        i=1
        result=""
        for param in self.mList:
            if (i>1): result+=(",")
            result+=ExpandTagSig(param.mTag,param.mType.mName)
            result+=" "+param.mName
            i+=1
        return result

    # -------------------------------------
    # Generate the arguments to a function call
    def GenFunctionDeclaration(self):
        i=1
        result=""
        for param in self.mList:
            if (i>1): result+=(",")
            result+=ExpandTagSig(param.mTag,param.mType.mName)
            result+=" p%d"%i
            i+=1
        return result

    # -------------------------------------
    # Generate the arguments to a function call
    def GenFunctionArgs(self):
        i=1
        result=""
        for param in self.mList:
            if (i>1): result+=(",")
            result+="p%d"%i
            i+=1
        return result

    # -------------------------------------
    # Generate the arguments from a virtual function call
    def GenVirtualArgs(self,fp,indent):
        fp.write("%*sPyObject* args=PyTuple_New(%d);\n"%(indent,"",len(self.mList)))
        i=1
        for param in self.mList:
            fp.write("%*sPyTuple_SetItem(args,%d,%s);\n"%
                     (indent,"",i-1,param.mType.GenVirtualArg("p%d"%i,param)))
            i+=1

    # -------------------------------------
    # Generate browser data
    def GenBrowserData(self):
        data=""
        for param in self.mList:
            if (param.mUseTag!='ref'): return None
            data+=',%s'%param.mType.mName
        return data

# ===================================================================
# cFunGroupDesc
# ===================================================================
class cFunGroupDesc:
    __doc__="cFunGroupDesc - Container for a group of functions with the same name"
    def __init__(self,
                 name,
                 funs):
        self.mName=name
        self.mFuns=funs
        
    # ----------------------------
    # Change string class references to objects in functions
    def Prepare(self,dict,cls,prefix):
        for fun in self.mFuns:
            fun.Prepare(dict,cls,prefix)
        for fun in self.mFuns:
            fun.mGroup=self

    # ----------------------------
    # Check
    def Check(self,cls):
        insigs={}
        for fun in self.mFuns:
            insig=","
            for param in fun.mParams.mList:
                insig+=param.mType.mName+','
            insigs[insig]=insigs.get(insig,0)+1
        for key,value in insigs.items():
            if (value>1):
                print ("Multiple functions with same parameters found in class: %s, function: %s, Desc: %s"%
                       (cls.mName,self.mName,insigs))

        for fun in self.mFuns:
            fun.Check(cls)
    
    # ----------------------------
    # GetFunctionName
    def GetFunName(self,cls):
        return self.mFuns[0].GetFunName(cls)
        
    # ----------------------------
    # Generate the doc string for a function call
    def GenFunDoc(self,fp,cls):
        self.mFuns[0].GenFunDoc(fp,cls,self.mFuns)

    # ----------------------------
    # GenCode
    def GenCode(self,fp,cls):
        funs=self.mFuns
        funs[0].GenCode(fp,cls,funs)

    # ----------------------------
    # GenVirtualDeclaration
    def GenVirtualDeclaration(self,fp,did):
        for fun in self.mFuns:
            fun.GenVirtualDeclaration(fp,did)
            
    # ----------------------------
    # GenVirtualBody
    def GenVirtualBody(self,fp,did,cls,base):
        for fun in self.mFuns:
            fun.GenVirtualBody(fp,did,cls,base)
            
# ===================================================================
# cFunDesc
# ===================================================================
class cFunDesc:
    __doc__="cFunDesc - Container for a function description"
    def __init__(self,
        name,           # Required: name of function
        call=None,      # Real function call, default = name
        value=None,     # return class for access/fun modes
        value_tag=None, # tag type for value
        value_utag=None,# use tag
        value_init=None,# Init code for array value return
        value_dref=0,   # Returned ptr can be drefed
        value_copy=0,   # Returned ptr should be copied
        value_alloc=0,  # returned a ptr that we now own
        value_borrow=0, # returned a ptr that we borrow
        value_rmconst=0, # returan a const db ptr that can be un-const
        params=[],      # parameter descriptions
                        #  Entered as a list of cParamDescs and then converted
                        #  here to a cParamListDesc class
        isiter=0,       # Is an iterator function
        ismanual=0,     # The implementation will be manually provided
        desc=None,      # Description
        virt=None,      # Virtual status
        const=None,
        sig=None,
      ):
        self.mName=name
        self.mCall=call
        if (call==None): self.mCall=name
        self.mValue=value
        self.mValueTag=value_tag
        self.mValueUseTag=value_utag
        self.mValueInit=value_init
        self.mValueDref=value_dref
        self.mValueCopy=value_copy
        self.mValueAlloc=value_alloc
        self.mValueBorrow=value_borrow
        self.mValueRmConst=value_rmconst
        self.mValueRef=None
        if (self.mValueUseTag=='ref'):
            self.mValueRef=1
        self.mParams=cParamListDesc(params,self)
        self.mDesc=desc
        self.mSig=sig
        self.mIsIter=isiter
        self.mIsManual=ismanual
        #self.mClass=cls
        if (virt=='non-virtual'): self.mVirt=None
        else: self.mVirt=virt
        self.mConst=const
        self.mChecked=0 # avoid multiple calls to check

        self.mResultCount=0
        if (self.mValue): self.mResultCount+=1
        self.mGroup=self
        
        self.mValueArray=0  # For Now

    # ----------------------------
    # Change string class references to objects in functions
    def Prepare(self,dict,cls,prefix):
        for param in self.mParams.mList:
            PrepareParam(dict,param,cls,'%sfunction: %s'%(prefix,self.mName))

        if (self.mValue):
            base=dict.get(self.mValue)
            if (not base):
                raise str("Undefined return value class name: %s in class: %s in %sfunction: %s"%
                       (self.mValue,cls.mName,prefix,self.mName))
            self.mValue=base

    # ----------------------------
    # Check
    def Check(self,cls):
        self.mChecked=1
    
    # ----------------------------
    # Generate the function name
    def GetFunName(self,cls):
        return "%s_%s"%(cls.mName,self.mName)

    # ----------------------------
    # Generate the function name
    def GetCallName(self,cls):
        if (self.mVirt==None or cls.mVirt==0):
            return "data.DataCall()->%s"%self.mCall
        else:
            return "data.DataCall()->%s::%s"%(cls.mName,self.mCall)
    
    # ----------------------------
    # Generate the required vars
    def GenCodeVars(self,fp,indent,cls):
        self.mParams.GenParamVars(fp,indent)
        
    # ----------------------------
    # Generate Result start
    def GenResultStart(self):
        if (self.mValueDref or self.mValueAlloc or self.mValueBorrow or self.mValueInit):
           if (self.mValueUseTag=='cptr'):
               return "%s* result=(%s*)("%(self.mValue.mTypeName,self.mValue.mTypeName)
           else:
               return "%s* result=("%(self.mValue.mTypeName)
        if (self.mValueCopy):
           return "%s* result= new %s(*("%(self.mValue.mTypeName,self.mValue.mName)

        if (self.mValueRef):
            return "%s* result=&("%self.mValue.mTypeName
        if (self.mValue.mIsPtr and not self.mValue.mIsDb):
            if (self.mValue.mNoCopy and self.mValueUseTag=='cref'):
               return "const %s& result= ("%(self.mValue.mTypeName)
            else:
               return "%s* result= new %s("%(self.mValue.mTypeName,self.mValue.mName)
        if (self.mValueRmConst):
            return "%s result=(%s)("%(self.mValue.mTypeName,self.mValue.mTypeName)
        return "%s result= ("%self.mValue.mTypeName
     
    def GenResultEnd(self):
        if (self.mValueCopy):
            return "))"
        return ")"
    
    # ----------------------------
    # Generate the function call
    def GenCodeFunCall(self,fp,indent,cls):
        fp.write("%*s"%(indent,""))
        if (self.mValue):
            fp.write("%s"%self.GenResultStart())
        fp.write("%s(%s)"%(self.GetCallName(cls),
                           self.mParams.GenParamVarAccess(indent+2)))
        if (self.mValue):
            fp.write("%s"%self.GenResultEnd())
            
        fp.write(";\n")

        if (self.mValue):
            if (self.mValueDref or self.mValueAlloc or self.mValueBorrow):
                fp.write("%*sif (result==NULL) {\n"%(indent,""))
                fp.write("%*sPy_INCREF(Py_None);\n"%(indent+4,""))
                fp.write("%*sreturn Py_None;\n"%(indent+4,""))
                fp.write("%*s}\n"%(indent,""))
        
    # ----------------------------
    # Generate the single result
    def GenCodeSingleResult(self,fp,indent,cls):
        if (not self.mValue): return
        typename=self.mValue.mName
        if (self.mValueInit!=None):
            if (self.mValueInit!=''):
                s="Py%s_Array_From%s_Array(result,%s,ob)"%(typename,typename,self.mValueInit)
            else:
                s="Py%s_Array_From%s_Array(result,ob)"%(typename,typename)
        elif (self.mValueDref):
            s="Py%s_From%s(result,1,ob)"%(typename,typename)
        elif (self.mValueCopy):
            s="Py%s_From%s(result,0,NULL)"%(typename,typename)
        elif (self.mValueAlloc):
            s="Py%s_From%s(result,0,NULL)"%(typename,typename)
        elif (self.mValueBorrow):
            s="Py%s_From%s(result,1,NULL)"%(typename,typename)
        elif (self.mValueRef):
            s="Py%s_From%s(result,1,ob)"%(typename,typename)
        elif (self.mValue.mIsPtr and not self.mValue.mIsDb):
            if (self.mValue.mNoCopy and self.mValueUseTag=='cref'):
                # Type cast to remove const for now, TBD const classes
                s="Py%s_From%s((%s*)(&result),1,ob)"%(typename,typename,typename)
                print "** Generating Ref object from CRef object: %s::%s %s "%(cls.mName,self.mName,self.mSig)
            elif (self.mValue.mNoCopy and self.mValueUseTag=='simple'):
                # Type cast to remove const for now, TBD const classes
                s="Py%s_From%s(result,0,NULL)"%(typename,typename)
                print "** Generating Copy of object from Simple object: %s::%s %s "%(cls.mName,self.mName,self.mSig)
            else:
                s="Py%s_From%s(result,0,NULL)"%(typename,typename)
        else:
            s="Py%s_From%s(result)"%(typename,typename)
        fp.write("%*sreturn %s;\n"%(indent,"",s))
        
    # ----------------------------
    # Generate virutal function error
    def GenPureVirtualError(self,fp,indent,cls):
        fp.write("%*sPyErr_SetString(PyExc_TypeError,\n"%(indent,""))
        fp.write("%*s    \"Call to Pure-Virtual Function class: %s, function: %s\");\n"%
                 (indent,"",cls.mName,self.mName))
        fp.write("%*sreturn NULL;\n"%(indent+4,""))
        
    # ----------------------------
    # Generate the body code for a function
    def GenCodeFunTest(self,fp,indent,cls):
        self.GenCodeVars(fp,indent,cls)

        self.mParams.GenParamParseTuple(fp,indent)
        indent+=4

        if (self.mVirt=='pure-virtual'):
            self.GenPureVirtualError(fp,indent,cls)
        else:
            
            self.GenCodeFunCall(fp,indent,cls)

            if (self.mResultCount==0):
                fp.write("%*sPy_INCREF(Py_None);\n"%(indent,""))
                fp.write("%*sreturn Py_None;\n"%(indent,""))
            else:
                if (self.mIsIter):
                    fp.write("%*sif (result==NULL) {\n"%(indent,""))
                    fp.write("%*sPyErr_SetObject(PyExc_StopIteration,Py_None);\n"%(indent+4,""))
                    fp.write("%*sreturn NULL;\n"%(indent+4,""))
                    fp.write("%*s}\n"%(indent,""))
                self.GenCodeSingleResult(fp,indent,cls)

        indent-=4
        self.mParams.GenParamEndParse(fp,indent)

    # ----------------------------
    # Generate the doc string for a function call
    def GenFunDoc(self,fp,cls,funs=[]):
        fp.write("static char %s_doc[] = \n"%self.GetFunName(cls))
        fp.write("\"Class: %s, Function: %s\\n\"\n"%(cls.mName,self.mName))
        if (len(funs)==1):
            fp.write("\"  Paramegers: %s\\n\"\n"%self.mParams.GenParamChoice())
            fp.write("\"    Calls: %s\\n\"\n"%(self.GetCall()))
            fp.write("\"    Signature: %s\\n\"\n"%self.mSig)
            data=self.mParams.GenBrowserData()
            if (data!=None):
                if (self.mValue): data='1'+data
                else: data='0'+data
                fp.write("\"    BrowseData: %s\\n\"\n"%data)
            if (self.mDesc):
                for line in self.mDesc.split("\n"):
                    line=string.replace(line,'\\','\\\\')
                    line=string.replace(line,'"','\\"')
                    fp.write("\"    %s\\n\"\n"%line)
        else:
            for fun in funs:
                fp.write("\"  Paramegers: %s\\n\"\n"%fun.mParams.GenParamChoice())
                fp.write("\"    Calls: %s\\n\"\n"%(fun.GetCall()))
                fp.write("\"    Signature: %s\\n\"\n"%fun.mSig)
                data=fun.mParams.GenBrowserData()
                if (data!=None):
                    if (fun.mValue): data='1'+data
                    else: data='0'+data
                    fp.write("\"    BrowseData: %s\\n\"\n"%data)
                if (fun.mDesc):
                    for line in fun.mDesc.split("\n"):
                        line=string.replace(line,'\\','\\\\')
                        line=string.replace(line,'"','\\"')
                        fp.write("\"    %s\\n\"\n"%line)
        fp.write(";\n\n")
            
    # ----------------------------
    # Generate heading block for a function
    def GenCodeStart(self,fp,cls,funs=[]):
        self.GenFunDoc(fp,cls,funs)
        fp.write("""static PyObject*
%s(PyObject* ob, PyObject *args)
{
"""%(self.GetFunName(cls)))
        GenTry(fp)

    # ----------------------------
    # Generate code to fetch the self object
    def GenCodeFetchSelf(self,fp,cls):
        fp.write("    PyParam%s data;\n"%cls.mName)
        fp.write("    int convert_status=Py%s_Convert(ob,&data);\n"%cls.mName)
        fp.write("    assert(convert_status!=0);\n")
        fp.write("    Py%sObject* self=(Py%sObject*)ob;\n"%(cls.mName,cls.mName))
        if (cls.mIsDb):
            fp.write("    if (!PyValidateDbObject(data.Data(),0)) return NULL;\n")
        fp.write("\n")
        
    # ----------------------------
    # Generate closing block for a function
    def GenCodeEnd(self,fp,cls,end='NULL'):
        GenCatch(fp,end)
        fp.write("}\n\n")

    # ----------------------------
    # GenCode
    def GenCode(self,fp,cls,funs=[]):
        if (self.mIsManual):
            self.mGroup.GenFunDoc(fp,cls)
            fp.write("extern PyObject* %s(PyObject *self, PyObject *args);\n\n"%
                self.GetFunName(cls))
            return
        self.GenCodeStart(fp,cls,funs)
        self.GenCodeFetchSelf(fp,cls)

        if (len(funs)==1):
            self.GenCodeFunTest(fp,4,cls)
            fp.write("    return NULL;\n")
        else:
            choices=[]
            for fun in funs:
                choice=fun.mParams.GenParamChoice()
                fp.write("    // Case: %s\n"%(choice))
                fp.write("    {\n")
                fun.GenCodeFunTest(fp,8,cls)
                fp.write("    }\n")
                fp.write("    PyErr_Clear();\n")
                choices.append(choice)

            fp.write("    PyErr_SetString(PyExc_TypeError,\n")
            fp.write("        \"No Arg-Matching Function found for class: %s, function: %s, Choices are:\\n\"\n"%
                 (cls.mName,self.mName))
            for choice in choices:
                fp.write("        \"    %s\\n\"\n"%choice)
            fp.write("    );\n")
            fp.write("    return NULL;\n")
            
        self.GenCodeEnd(fp,cls)

    # ----------------------------
    # Get Call
    def GetCall(self):
        str=""
        if (self.mVirt):
            str+="virtual "
        if (self.mValue):
            str+=ExpandTagSig(self.mValueTag,self.mValue.mName)
        else:
            str+="void"
        str+=(" %s(%s)"%(self.mName,self.mParams.GenParamCall()))
        if (self.mConst=='yes'):
            str+=' const'
        return str
        
    # ----------------------------
    # GenVirtualDeclaration
    def GenVirtualDeclaration(self,fp,did):
        if (self.mVirt==None): return None
        str="virtual "
        if (self.mValue):
            str+=ExpandTagSig(self.mValueTag,self.mValue.mName)
        else:
            str+="void"
        str+=(" %s(%s)"%(self.mName,self.mParams.GenFunctionDeclaration()))
        if (self.mConst=='yes'):
            str+=' const'
        if (did.has_key(str)): return
        fp.write("    %s;\n"%str)
        did[str]=1
    
    # ----------------------------
    # GenVirtualBody
    def GenVirtualBody(self,fp,did,cls,base):
        if (self.mVirt==None): return None
        clsname=cls.mName
        str=""
        if (self.mValue):
            str+=ExpandTagSig(self.mValueTag,self.mValue.mName)
        else:
            str+="void"
        str+=(" pyv_%s::%s(%s)"%(clsname,self.mName,self.mParams.GenFunctionDeclaration()))
        if (self.mConst=='yes'):
            str+=' const'
        if (did.has_key(str)): return

        did[str]=1
        GenLine(fp)
        fp.write("""\
%s
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,\"%s\");
"""%(str, # Declaration
     self.mName, # GetAttr
     ))
        # TBD should allow the base function to be called here.
        #if (self.mVirt!='pure-virtual'):
        #  fp.write("    if (!md) return %s::%s(...);")
        fp.write("""\
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException(\"Python Virtual Function %s::%s was unable to find a callable python routine.\");
    }
"""%(cls.mName,self.mName, # Error
     ))

        self.mParams.GenVirtualArgs(fp,4)

        fp.write("""\
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException(\"Python Virtual Function %s::%s had an error.\");
    }
"""%(cls.mName,self.mName, # Error
     ))
        if (self.mValue):
            res=self.mValue.GenVirtualResult(fp,'result','rv',self)
        fp.write("    Py_DECREF(result);\n")
        if (self.mValue):
            fp.write("    return %s;\n"%res)
    

#        if (self.mVirt=='pure-virtual'):
#            fp.write("   throw oaError(oacOSError);\n")  # Should raise my own error
#        else:
#            fp.write("    ")
#            if (self.mValue):
#                fp.write("return ")
#            fp.write("%s::%s(%s);\n"%(base.mName,self.mName,self.mParams.GenFunctionArgs()))
        fp.write("}\n\n")
    
# ===================================================================
class cGlobalFunDesc(cFunDesc):
    __doc__="cGlobalFunDesc - Conatiner for global functions"
    def __init__(self,**kw):
        cFunDesc.__init__(self,**kw)

    # ----------------------------
    # Generate the function name
    def GetCallName(self,cls,item=None):
        return "%s"%(self.mCall)
    
    # ----------------------------
    # Generate code to fetch the self object
    def GenCodeFetchSelf(self,fp,cls):
        #fp.write("// Global-GenCodeFetchSelf\n")
        pass

# ===================================================================
class cStaticFunDesc(cFunDesc):
    __doc__="cStaticFunDesc - Conatiner for static functions"
    def __init__(self,**kw):
        cFunDesc.__init__(self,**kw)

    # ----------------------------
    # Generate the function name
    def GetFunName(self,cls):
        return "%s_static_%s"%(cls.mName,self.mName)

    # ----------------------------
    # Generate the function name
    def GetCallName(self,cls,item=None):
        return "%s::%s"%(cls.mName,self.mCall)
    
    # ----------------------------
    # Generate code to fetch the self object
    def GenCodeFetchSelf(self,fp,cls):
        #fp.write("// Static-GenCodeFetchSelf\n")
        pass

# ===================================================================
class cIndexGetFunDesc(cFunDesc):
    __doc__="cOperatorGetFunDesc - Conatiner for operator get [] functions"
    def __init__(self,**kw):
        kw['call']='operator[]'
        self.mRangeCheck=kw['range_check']
        del kw['range_check']
        cFunDesc.__init__(self,**kw)

    # ----------------------------
    # Check
    def Check(self,cls):
        if (self.mResultCount==0):
            raise ("IndexGetFuncDesc without return value in function: %s in class: %s"%
                  (self.mName,cls.mName))

        ic=len(self.mParams.mList)
        if (ic!=1):
           raise ("Wrong Input parameters found in IndexGetFuncDesc class: %s, function: %s, Desc: %s"%
                  (cls.mName,self.mName,param.mDesc))

    # ----------------------------
    # Generate heading block for a function
    def GenCodeStart(self,fp,cls):
        self.mGroup.GenFunDoc(fp,cls)
        fp.write("""static PyObject*
%s(PyObject* ob,Pyoa_ssize_t index)
{
"""%(self.GetFunName(cls)))
        if (not cls.mIsGlobal):
            fp.write("  Py%sObject* self=(Py%sObject*)ob;\n"%(
                     cls.mName,cls.mName))
        GenTry(fp)

    # ----------------------------
    # Generate the body code for a function
    def GenCode(self,fp,cls):
        indent=4
        self.GenCodeStart(fp,cls)
        self.GenCodeFetchSelf(fp,cls)
        self.GenCodeVars(fp,indent,cls)

        if (self.mRangeCheck):
            fp.write("%*sif (index<0 || index>=%s) {\n"%(indent,"",self.mRangeCheck))
            fp.write("%*s    PyObject* err=PyString_FromString(\"index out of range\");\n"%(indent,""))
            fp.write("%*s    PyErr_SetObject(PyExc_IndexError, err);\n"%(indent,""))
            fp.write("%*s    Py_DECREF(err);\n"%(indent,""))
            fp.write("%*s    return NULL;\n"%(indent,""))
            fp.write("%*s}\n"%(indent,""))
        fp.write("%*s"%(indent,""))
        fp.write("%s"%self.GenResultStart())
        fp.write("data.Data()[index]")
        fp.write("%s"%self.GenResultEnd())
        fp.write(";\n")

        self.GenCodeSingleResult(fp,indent,cls)
        self.GenCodeEnd(fp,cls)

        # Generate Length Function
        if (self.mRangeCheck):
            fp.write("""static Pyoa_ssize_t
%s_length(PyObject* ob)
{
"""%(self.GetFunName(cls) ))
            self.GenCodeFetchSelf(fp,cls)
            fp.write("    return %s;\n"%(self.mRangeCheck))
            fp.write("}\n\n");

# ===================================================================
class cIndexSetFunDesc(cFunDesc):
    __doc__="cOperatorSetFunDesc - Conatiner for operator set [] functions"
    def __init__(self,**kw):
        kw['call']='operator[]'
        self.mRangeCheck=kw['range_check']
        del kw['range_check']
        cFunDesc.__init__(self,**kw)

    # ----------------------------
    # Check
    def Check(self,cls):
        if (self.mResultCount==0):
            raise ("IndexSetFuncDesc without return value in function: %s in class: %s"%
                  (self.mName,cls.mName))

        ic=len(self.mParams.mList)
        if (ic!=1):
           raise ("Wrong Input parameters found in IndexGetFuncDesc class: %s, function: %s, Desc: %s"%
                  (cls.mName,self.mName,param.mDesc))

    # ----------------------------
    # Generate heading block for a function
    def GenCodeStart(self,fp,cls):
        self.mGroup.GenFunDoc(fp,cls)
        fp.write("""static int
%s(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
"""%self.GetFunName(cls))
        GenTry(fp)

    # ----------------------------
    # Generate the body code for a function
    def GenCode(self,fp,cls):
        indent=4
        self.GenCodeStart(fp,cls)
        self.GenCodeFetchSelf(fp,cls)
        self.GenCodeVars(fp,indent,cls)

        if (self.mRangeCheck):
            fp.write("%*sif (index<0 || index>=%s) {\n"%(indent,"",self.mRangeCheck))
            fp.write("%*s    PyObject* err=PyString_FromString(\"index out of range\");\n"%(indent,""))
            fp.write("%*s    PyErr_SetObject(PyExc_IndexError, err);\n"%(indent,""))
            fp.write("%*s    Py_DECREF(err);\n"%(indent,""))
            fp.write("%*s    return -1;\n"%(indent,""))
            fp.write("%*s}\n"%(indent,""))
        fp.write("    PyParam%s result;\n"%self.mValue.mName)
        fp.write("%*sif (Py%s_Convert(value,&result)==0) return -1;\n"%(indent,"",self.mValue.mName))
        if (self.mParams.mList[0].mVarLock):
            fp.write("%*sPyoaLockObject(self->locks,value);\n"%(indent,""))
        fp.write("%*sdata.Data()[index]=result.Data();\n"%(indent,""))
        fp.write("%*sreturn 0;\n"%(indent,""))

        self.GenCodeEnd(fp,cls,'-1')

# ===================================================================
class cConDesc:
    __doc__="cConDesc - Container for a constructor description"
    def __init__(self,
        name=None,
        params=[],  # function parameter descriptions
        desc=None,         # Description
        sig=None,
        ismanual=0,
        virt=None,   # Ignore
        const=None,  # Ignore
        #cls=None,
      ):
        self.mParams=cParamListDesc(params,self)
        self.mDesc=desc
        #self.mClass=cls
        self.mSig=sig
        self.mIsManual=ismanual
        self.mName=name

    # ----------------------------
    # All our objects will look immuttable to Python.
    # Thus the value pointer is never NULL.
    # We allways do all of new's work, as that what C++ does.
    def GenCodeConTest(self,fp,cls,indent):
        choice=self.mParams.GenParamChoice(cls)
        fp.write("%*s// Case: %s\n"%(indent,"",choice))
        fp.write("%*s{\n"%(indent,""))
        indent+=4
        self.mParams.GenParamVars(fp,indent)
        self.mParams.GenParamParseTuple(fp,indent,cls)
        indent+=4
        if (cls.mIsDb):
            raise "** Constructor call for DB object: %s"%cls.mName
        if (not cls.mIsPtr):
            raise "** Constructor call for Non Ptr object: %s"%cls.mName
        if (not cls.mVirt):
            fp.write("%*sself->value = %s new %s(%s);\n"%
                     (indent,"",cls.GetDownCast(),cls.mName,
                      self.mParams.GenParamVarAccess(indent+2)))
        else:
            fp.write("%*sif (is_raw) {\n"%(indent,""))
            fp.write("%*sself->value = %s new %s(%s);\n"%
                     (indent+4,"",cls.GetDownCast(),cls.mName,
                      self.mParams.GenParamVarAccess(indent+2)))
            fp.write("%*s}\n"%(indent,""))
            fp.write("%*selse {\n"%(indent,""))
            fp.write("%*spyv_%s* p=new pyv_%s(%s);\n"%
                     (indent+4,"",cls.mName,cls.mName,
                      self.mParams.GenParamVarAccess(indent+2)))
            fp.write("%*sp->pyob=self;\n"%(indent+4,""))
            fp.write("%*sself->value= %sp;\n"%(indent+4,"",cls.GetDownCast()))
            fp.write("%*s}\n"%(indent,""))
        fp.write("%*sreturn bself;\n"%(indent,""))
        indent-=4
        fp.write("%*s}\n"%(indent,""))
        indent-=4
        fp.write("%*s}\n"%(indent,""))
        return choice

    # ----------------------------
    def GenChoices(self,cls):
        choice=self.mParams.GenParamChoice(cls)
        return choice

    # ----------------------------
    def GenCall(self,cls):
        result="%s(%s)"%(cls.mName,self.mParams.GenParamCall(cls))
        return result

    # ----------------------------
    # GenVirtualDeclaration
    def GenVirtualDeclaration(self,fp,clsname):
        str="pyv_%s(%s)"%(clsname,self.mParams.GenFunctionDeclaration())
        fp.write("    %s;\n"%str)
    
    # ----------------------------
    # GenVirtualBody
    def GenVirtualBody(self,fp,clsname):
        GenLine(fp)
        str="pyv_%s::pyv_%s(%s)"%(clsname,clsname,self.mParams.GenFunctionDeclaration())
        fp.write("%s\n"%str)
        fp.write(" : pyob(NULL),\n")
        fp.write("   %s(%s)\n"%(clsname,self.mParams.GenFunctionArgs()))
        fp.write("{\n")
        fp.write("}\n\n")

# ===================================================================

