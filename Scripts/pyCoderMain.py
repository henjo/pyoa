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

import types
import sys
import copy
from pyCoderClass import *
from pyCoderFunc import *

# ===================================================================

# ===================================================================
# Define Constant Description
# ===================================================================
class cDefDesc:
    __doc__="cDefDesc - Class description for a define value"
    def __init__(self,name,value,desc):
        self.mName=name
        self.mValue=value
        self.mDesc=desc
        self.mCodeValue=value

# ===================================================================
# Define Main Code Generation class
# ===================================================================
class cMain:
    def __init__(self,data,dirname,fileprefix,packagename,modulename):
        self.mData=data
        self.mDirName=dirname
        self.mFilePrefix=fileprefix
        self.mPackageName=packagename
        self.mName=packagename
        self.mModuleName=modulename
        
        self.mClsData=data['clsdata']
        self.mFunData=data['fundata']
        self.mDefData=data['defdata']
        self.mTmpData=data['tmpdata']
        self.mClasses={}
        for item in self.mClsData:
            self.mClasses[item.mName]=item
            
        self.mBlockSize=50


    # -------------------------------------
    # Callback for Personalization Defines
    def vGenDefs(self,fp):
        pass

    # -------------------------------------
    # Callback to generate the __init__.py file
    def vGenInitFile(self):
        pass

    # -------------------------------------
    # Callback for Personalization Includes
    def vGenIncludes(self,fp):
        pass

    # -------------------------------------
    # Callback for Getting other source files
    def vGetSourceFiles(self):
        return ['src',[]]

    # -------------------------------------
    # Callback for Getting other source files
    def vGenCustomOutputs(self):
        pass

    # -------------------------------------
    # -------------------------------------
    # Prepare the functions
    def PrepareFunctions(self):
        self.mFunctions=self.mFunData
        self.mFunctions.sort(SortFunctionName)

        for funs in self.mFunctions:
            funs.Prepare(self.mClasses,None,'')
            funs.Check(None)
            
    # -------------------------------------
    # SortClass
    #  Sort by lowest level classes, then by name
    def SortClass(self,cls1,cls2):
        if (cls1.mName<cls2.mName): return -1
        return 1
                
    # -------------------------------------
    # Write Temp file, and check for changes
    # Using this Open and Close insures that only
    #  files that change, get re-written.
    #  Then 'make' will only need to build wan't changed.
    def OpenWrite(self,name):
        self.mFileName=name
        fp=file('test.txt','w')
        return fp

    def CloseWrite(self,fp):
        fp.close()
        fpn=file('test.txt','r')
        try:
            fpo=file(self.mFileName,'r')
        except:
            fpo=None
        match=0
        if (fpo!=None):
            datan=fpn.read()
            datao=fpo.read()
            if (datan==datao): match=1
            fpo.close()
        fpn.close()
        if (match):
            print "  Skipping"
            return
        fpn=file('test.txt','r')
        fpo=file(self.mFileName,'w')
        data=fpn.read()
        fpo.write(data)
        fpo.close()
        fpn.close()
            
    # -------------------------------------
    # Process the given class
    def GenHeader(self):
        name="%s/%s_header.h"%(self.mDirName,self.mFilePrefix)
        print "Writing file:",name
        fp=self.OpenWrite(name)
        GenCopyright(fp)
        fp.write("""
#ifndef %s_header_h
#define %s_header_h

#ifndef PYOADONTINCLUDEHEADERS
#include "Python.h"
#include "structmember.h"
#include <string.h>

"""%(self.mFilePrefix,self.mFilePrefix))
        self.vGenIncludes(fp)
        fp.write("#endif\n")

        GenMajorCommentBlock(fp,"Declare Typedefs")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Full):
                cls.GenTypedefDeclaration(fp)

        GenMajorCommentBlock(fp,"Declare Type Typedefs")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Full or
                cls.HasDeclaration()==kClassDeclaration_Native):
              cls.GenTypenameDeclaration(fp)
              
        GenMajorCommentBlock(fp,"Declare Manual Classes")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Native):
                cls.GenHeaderDeclaration(fp)

        GenMajorCommentBlock(fp,"Declare Enum Classes")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Enum):
                cls.GenHeaderDeclaration(fp)

        GenMajorCommentBlock(fp,"Declare Wrapped Classes")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Full):
                cls.GenHeaderDeclaration(fp)

        fp.write("""
#endif
""")
        self.CloseWrite(fp)

    # -------------------------------------
    # Process the given class
    def GenArrayTypedefs(self):
        name="%s/%s_array.cpp"%(self.mDirName,self.mFilePrefix)
        print "Writing file:",name
        fp=self.OpenWrite(name)
        GenCopyright(fp)
        fp.write("""
#include "%s_header.h"
"""%(self.mFilePrefix))

        GenMajorCommentBlock(fp,"Declare Array Converts for Typedefs")
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Native):
                if (cls.mArray=='auto'):
                  cls.GenImplementArray(fp,1)
        self.CloseWrite(fp)

    # -------------------------------------
    # Process the given class
    def GenImplementation(self,cls):
        if (not cls.HasImplementation()): return

        name="%s/%s_%s.cpp"%(self.mDirName,self.mFilePrefix,cls.mName)
        print "Writing file:",name
        fp=self.OpenWrite(name)
        GenCopyright(fp)

        fp.write("""
#include "%s_header.h"

"""%(self.mFilePrefix))

        cls.GenImplementation(fp)
        self.CloseWrite(fp)

    # -------------------------------------
    # Generate the Module Functions
    def GenModuleFunctions(self,fp):
        GenCommentBlock(fp," Function Methods:")
        for funs in self.mFunctions:
            GenLine(fp)
            funs.GenCode(fp,self)
        #for cls in self.mClsData:
        #    if (cls.HasDeclaration()==kClassDeclaration_Native):
        #        if (cls.mName[0:2]!='oa'): continue
        #        GenLine(fp)
        #        cls.GenNativeFunctions(fp)
        
        GenCommentBlock(fp," Function Methods Table:")
        fp.write("static PyMethodDef %s_methods[] = {\n"%(self.mPackageName))
        for funs in self.mFunctions:
            fp.write("    {\"%s\",(PyCFunction)%s_%s,METH_VARARGS,%s_%s_doc},\n"%
                     (funs.mName,self.mPackageName,funs.mName,self.mPackageName,funs.mName))
        #for cls in self.mClsData:
        #    if (cls.HasDeclaration()==kClassDeclaration_Native):
        #        if (cls.mName[0:2]!='oa'): continue
        #        fp.write("    {\"%s\",(PyCFunction)%s_%s,METH_VARARGS,%s_%s_doc},\n"%
        #                 (cls.mName,self.mPackageName,cls.mName,self.mPackageName,cls.mName))

        fp.write("   {NULL,NULL,0,NULL}\n")
        fp.write("};\n")
        fp.write("\n")

    # -------------------------------------
    # Generate the Defines
    def GenDefs(self,fp):
        self.vGenDefs(fp)
        for mac in self.mDefData:
            typ,value=mac.mCodeValue
            if (typ=='int'):
                fp.write("  def=PyInt_FromLong(%s);\n"%value)
            elif (typ=='long'):
                fp.write("  def=PyLong_FromLongLong(LONG64(%s));\n"%value)
            elif (typ=='float'):
                fp.write("  def=PyFloat_FromDouble(%s);\n"%value)
            else:
                value=string.replace(value,'\\','\\\\')
                value=string.replace(value,'"','\\"')
                fp.write("  def=PyString_FromString(\"%s\");\n"%value)
            fp.write("  PyDict_SetItemString(dict,\"%s\",def);\n"%mac.mName)
            fp.write("  Py_DECREF(def);\n")
        
    # -------------------------------------
    # Generate the Module
    def GenModule(self):
        name="%s/%s_main.cpp"%(self.mDirName,self.mFilePrefix)
        print "Writing file:",name
        fp=self.OpenWrite(name)
        GenCopyright(fp)
        GenMajorCommentBlock(fp,"Main module for: %s"%self.mPackageName)
        fp.write("""
#include "%s_header.h"

static char %s_doc[]="%s exentions module";

#ifdef WIN32
#define LONG64(x) x##i64
#else
#define LONG64(x) x##LL
#endif

"""%(self.mFilePrefix, # include
     self.mPackageName,self.mPackageName, # doc
     ))

        self.GenModuleFunctions(fp)
        GenCommentBlock(fp," Initialization Function:")
        fp.write("""
static void commoninit(PyObject* mod,PyObject* dict)
{
""")


        # -----------------------
        # Define define constants
        fp.write("""
  // Enter Defines in the dictionary
  PyObject* def;
""")
        self.GenDefs(fp)

        # -----------------------
        # Define all the type names
        fp.write("""
  // Add all the types to the dictionary
""")
        for cls in self.mClsData:
            if (not cls.HasImplementation()): continue
#            fp.write("  if (Py%s_TypeInit(dict)<0) return;\n"%cls.mName)
            fp.write("  Py%s_TypeInit(dict);\n"%cls.mName)
        for cls in self.mClsData:
            if (cls.HasDeclaration()==kClassDeclaration_Native):
                if (cls.mName[0:2]=='oa'):
                    fp.write("  Py%s_TypeInit(dict);\n"%cls.mName)
        for cls in self.mClsData:
            if (cls.mArray=='auto' or 
                (cls.mName[0:2]=='oa' and cls.mArray=='manual')):
                fp.write("  Py%s_Array_TypeInit(dict);\n"%cls.mName)

        # -----------------------
        # Define dct's of Templated classes
        fp.write("""
  // Add the templated classes to the dictionary
  PyObject* template_dict;
  PyObject* template_dict2;
  PyObject* obj_type;
  PyObject* obj_type2;
  PyObject* template_type;
""")
        for key,cases in self.mTmpData:
            case=cases[0]
            if (type(case)==types.TupleType):
              sz=len(case)
            else:
              sz=1
            if (str(key)=='oaObserver'):
              sz=1
              dct={}
              for case1,case2 in cases:
                dct[case1]=1
              cases=dct.keys()
            fp.write("\n")
            fp.write("  // Template: %s\n"%(str(key)))
            if (sz==1):
                fp.write("  template_dict=PyDict_New();\n")
                for case in cases:
                    fp.write("  obj_type=PyDict_GetItemString(dict,\"%s\");\n"%case)
                    fp.write("  template_type=PyDict_GetItemString(dict,\"%s_%s\");\n"%(key,case))
                    fp.write("  PyDict_SetItem(template_dict,obj_type,template_type);\n")
                fp.write("  PyDict_SetItemString(dict,\"%s\",template_dict);\n"%key)
                fp.write("  Py_DECREF(template_dict);\n")
            if (sz==2):
                dct={}
                for case1,case2 in cases:
                    dct2=dct.get(case1,{})
                    dct2[case2]=1
                    dct[case1]=dct2
                fp.write("  template_dict=PyDict_New();\n")
                for case1,value in dct.items():
                    fp.write("  template_dict2=PyDict_New();\n")
                    fp.write("  obj_type=PyDict_GetItemString(dict,\"%s\");\n"%case1)
                    for case2 in value.keys():
                        fp.write("    obj_type2=PyDict_GetItemString(dict,\"%s\");\n"%case2)
                        fp.write("    template_type=PyDict_GetItemString(dict,\"%s_%s_%s\");\n"%(key,case1,case2))
                        fp.write("    PyDict_SetItem(template_dict2,obj_type2,template_type);\n")
                    fp.write("  PyDict_SetItem(template_dict,obj_type,template_dict2);\n")
                fp.write("  PyDict_SetItemString(dict,\"%s\",template_dict);\n"%key)
                fp.write("  Py_DECREF(template_dict);\n")
                
            
        # -----------------------
        # Close
        fp.write("\n}\n\n")

        # -----------------------
        # NT InitRoutine
        fp.write("""
#ifdef WIN32
extern "C" void __declspec(dllexport)
#else
extern "C" void 
#endif
init%s()
{
  PyObject* mod;
  PyObject* dict;

  // Initialize the Module
  mod=Py_InitModule3((char*)"%s",%s_methods,(char*)%s_doc);

  // Fetch its dictionary
  dict=PyModule_GetDict(mod);

  commoninit(mod,dict);
}

"""%(self.mModuleName, # init
     self.mModuleName,self.mPackageName,self.mPackageName, # InitModule
     ))

        # -----------------------
        # Sun InitRoutine
        fp.write("""
extern "C" void 
initlib%s()
{
  PyObject* mod;
  PyObject* dict;

  // Initialize the Module
  mod=Py_InitModule3((char*)"lib%s",%s_methods,(char*)%s_doc);

  // Fetch its dictionary
  dict=PyModule_GetDict(mod);
  
  commoninit(mod,dict);
}


"""%(self.mModuleName, # init
     self.mModuleName,self.mPackageName,self.mPackageName, # InitModule
     ))

        self.CloseWrite(fp)
        
    # -------------------------------------
    # Generate list of files
    def GenFileList(self):
        wrapfiles=[]
        for name in ['main','array']:
            wrapfiles.append('%s_%s'%(self.mFilePrefix,name))

        for cls in self.mClsData:
            if (not cls.HasImplementation()): continue
            wrapfiles.append('%s_%s'%(self.mFilePrefix,cls.mName))
        self.mWrapFiles=wrapfiles

        self.mSourcePrefix,self.mSourceFiles=self.vGetSourceFiles()
        print "Source Files:",self.mSourceFiles
        
    # -------------------------------------
    # Generate file Blocks
    def GenBlocks(self):
        allfiles=[]
        for name in self.mSourceFiles: allfiles.append(name)
        for name in self.mWrapFiles: allfiles.append(name)
        block=1
        self.mBlockSize=50
        count=0
        for name in allfiles:
            if (count>=self.mBlockSize):
                self.CloseWrite(fp)
                count=0
            if (count==0):
                oname='%s/block%d.cpp'%(self.mDirName,block)
                print "Writing file:",oname
                fp=self.OpenWrite(oname)
                block+=1
            count+=1
            #print "  Including:",name
            if (name in self.mSourceFiles):
                fpr=open('%s/%s.cpp'%(self.mSourcePrefix,name))
            else:
                fpr=open('%s/%s.cpp'%(self.mDirName,name))
            line=fpr.readline()
            while(line):
                fp.write(line)
                line=fpr.readline()
            fpr.close()
        self.CloseWrite(fp)
                 
    # -------------------------------------
    # Generate file setup
    def GenSetup(self):
        allfiles=[]
        for name in self.mSourceFiles: allfiles.append(name)
        for name in self.mWrapFiles: allfiles.append(name)
        block=1
        self.mBlockSize=50
        count=0
        for name in allfiles:
            if (count>=self.mBlockSize):
                count=0
            if (count==0):
                block+=1
            count+=1
            
        name='setup.py'
        print "Updating file:",name
        fp=open(name,"r")
        predata=[]
        postdata=[]
        line=fp.readline()
        while (line):
            predata.append(line)
            if (string.find(line,'PackageSources')>=0): break
            line=fp.readline()
        
        line=fp.readline()
        while (line):
            if (string.find(line,']')>=0):break
            line=fp.readline()
        postdata.append(line)
        line=fp.readline()
        while (line):
            postdata.append(line)
            line=fp.readline()
        fp.close()
        
        fp=self.OpenWrite(name)
        for line in predata:
            fp.write(line)
        for i in range(1,block):
            fp.write("      '%s/block%d.cpp',\n"%(self.mDirName,i))
        for line in postdata:
            fp.write(line)
        self.CloseWrite(fp)
                 
    # -------------------------------------
    # Process All defined classes
    def Process(self):
        self.mIsGlobal=1
        
        for cls in self.mClsData:
            cls.Prepare(self.mClasses)

        self.PrepareFunctions()
            
        for cls in self.mClsData:
            cls.SetDepth()

        self.mClsData.sort(self.SortClass)

        self.GenHeader()
        self.GenArrayTypedefs()
        self.GenModule()
        for cls in self.mClsData:
            self.GenImplementation(cls)

        self.GenFileList()
        self.GenBlocks()
        self.GenSetup()
        self.vGenCustomOutputs()
        self.vGenInitFile()
        
