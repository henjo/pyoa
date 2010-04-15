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
import pprint
from pyCoderFunc import *
import pyCoderClassArray

# ===================================================================
# General Code Generating  Functions
# ===================================================================
# ----------------------------
def GenLine(fp):
    fp.write("// ------------------------------------------------------------------\n")

# ----------------------------
def GenCommentBlock(fp,cmt):
    fp.write("\n")
    GenLine(fp)
    for line in cmt.split("\n"):
        fp.write("// %s\n"%line)
    GenLine(fp)
    fp.write("\n")

# ----------------------------
def GenMajorCommentBlock(fp,cmt):
    fp.write("\n")
    fp.write("// ==================================================================\n")
    for line in cmt.split("\n"):
        fp.write("// %s\n"%line)
    fp.write("// ==================================================================\n")
    fp.write("\n")

# ----------------------------
def GenCopyright(fp):
    fp.write("""
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/
""")

# ===================================================================
# Constants that are returned by HasDeclaration for a class:
kClassDeclaration_None=0
kClassDeclaration_Builtin=1  # int, charr*, ...
kClassDeclaration_Native=2   # User types that are implemented as Builtins
kClassDeclaration_Enum=3     # Enums
kClassDeclaration_Full=4     # Full Type

# ===================================================================
    # ===============================================================
class cClassDesc:
    __doc__="cClassDesc - Container for a class description"
    # The default class implementation is for allocated classes.
    # The python object owns a copy of the class object that it keeps
    #  with a pointer to that object.
    def __init__(self,
        name,              # Required: name of class
        typename=None,     # Typename to use for data
        base=None,         # Base class name
        constructors=[],   # Constructor Functions
        methods=[],        # List of callable methods
        static_methods=[], # List of callable static methods
        gets=[],           # Get attribute calls
        sets=[],           # Set attribute calls
        igets=[],          # operator[] get
        isets=[],          # operator[] set
        no_copy=0,         # Set for alloc mode classes without copy constructor
        has_copy=0,        # Has an explicit copy constructor
        no_assign=0,       # Set for alloc mode classes that diss-allow assign
        pure_virt=0,       # Has pure_virtual
        virt=0,            # Has virtual members
        repr=None,         # Custom code for repr
        compare='pointer', # Compare mode: pointer, object, math,  None
        desc=None,         # Description
        sig=None,
        class_init=None,   # Init value for default constructor
        class_casts=(),    # Upcast data
        typedef=None,      # Typedef for a template
        typedefdb=None,    # Typedef for a db ptr
        record=None,       # Record data in ptyhon object
        lock=None,         # Class has object locks
        manmath=None,      # Has Manual Math functions
        # ----------------------------------
        # Configuration data about the class type
        array=0,           # Class used as array
        aof=0,             # Class used as aof
        with_borrow=0,     # Supports Borrow
        is_ptr=1,          # Base object is a pointer
        is_db=0,       # Is a db class
        has_declaration=kClassDeclaration_Full, # Has a Declaration
        has_implementation=1,
      ):
        self.mIsGlobal=0  # Not the global module
        self.mName=name
        self.mTypeName=typename
        if (typename==None):
            self.mTypeName=self.mName
        self.mBase=base
        self.mConstructors=constructors
        self.mMethods=methods
        self.mStaticMethods=static_methods
        self.mIndexGetMethods=igets
        self.mIndexSetMethods=isets
        self.mDerived=[]
        self.mTypeDepth=0
        self.mNoCopy=no_copy
        self.mHasCopy=has_copy
        self.mNoAssign=no_assign
        self.mPureVirt=pure_virt
        self.mVirt=virt
        self.mRepr=repr
        self.mCompare=compare
        self.mDesc=desc
        self.mSig=sig
        self.mClassInit=class_init
        self.mClassCasts=class_casts
        self.mTypedef=typedef
        self.mTypedefDb=typedefdb
        self.mRecord=record
        self.mLock=lock
        self.mManualMath=manmath
        
        self.mArray=array
        self.mAof=aof
        self.mWithBorrow=with_borrow
        self.mIsPtr=is_ptr
        self.mIsDb=is_db
        self.mHasDeclaration=has_declaration
        self.mHasImplementation=has_implementation
        

    # ===============================================================
    # These function are used to Prepare the raw data descripions
    #  for use in code generation.
    # ===============================================================

    # ----------------------------
    # Prepare the class by changing all class name references to object references
    #  Both in the class and in all function parameters.
    #  Also expand out function for optional parameters to be overloaded functions.
    def Prepare(self,dict):
        if (self.mBase):
            base=dict.get(self.mBase)
            if (not base):
                raise "Undefined base class name: %s in class: %s"%(self.mBase,self.mName)
            self.mBase=base
            base.mDerived.append(self)

        #---------------------------
        # Link Param types
        for con in self.mConstructors:
            for param in con.mParams.mList:
                PrepareParam(dict,param,self,'constructor')

        for att in ['mMethods','mStaticMethods']:
            getattr(self,att).sort(SortFunctionName)
            for funs in getattr(self,att):
                funs.Prepare(dict,self,'')
                funs.Check(self)
            
        for att in ['mIndexGetMethods','mIndexSetMethods']:
            getattr(self,att).sort(SortFunctionName)
            for fun in getattr(self,att):
                fun.Prepare(dict,self,'')
                fun.Check(self)

        #---------------------------
        # Check for Duplicate Names:
        dups={}
        for att in ['mMethods']:
            for fun in getattr(self,att):
                name=fun.mName
                dups[name]=dups.get(name,0)+1
        for name,value in dups.items():
            if (value>1):
                pprint.pprint(dups)
                raise str("Duplicate Function Name: %s, found in Class: %s"%(name,self.mName))
        
    # ----------------------------
    # Set the Depth of a class. How many levels from the base is it.
    #  Also set mRootBase to the lowest base class
    def SetDepth(self):
        base=self.mBase
        while (base):
            self.mTypeDepth+=1
            if (base.mVirt): self.mVirt=1
            if (not base.mBase): break
            base=base.mBase
        self.mRootBase=base
        
    # ===============================================================
    # These function can be overriden to easily change how code
    # is generated for a given class type
    # ===============================================================
    
    # ----------------------------
    # Return the type of declaration used by the class.
    # ----------------------------
    def HasDeclaration(self):
        return self.mHasDeclaration
    
    # ----------------------------
    # Returns true if there is a code file required for this class
    def HasImplementation(self):
        return self.mHasImplementation
    
    # ----------------------------
    # Return the type name used 
    def GetTypeName(self):
        return self.mTypeName

    # ----------------------------
    # Return the code to down cast a local value
    #  to the base type for storage in the object.
    # Used in constructors, and From function
    def GetDownCast(self,second=0):
        if (self.mRootBase):
            if (not second):
                return "(%s*) "%self.mRootBase.mName
            else:
                return "(%s**) "%self.mRootBase.mName
        else:
            return ""
        
    # ----------------------------
    # Return the code to up cast a base type
    #  for use in as a local value.
    # Used in Convert function
    def GetUpCast(self,second=0):
        if (self.mRootBase):
            if (not second):
                return "(%s*)"%self.mName
            else:
                return "(%s**)"%self.mName
        else:
            return ""
        
    # ----------------------------
    # Generate the variable cast for virtual args
    def GenVirtualArg(self,var,param):
        tag=param.mTag
        if (self.mIsPtr and not self.mIsDb):
            if (tag=='ref'):
                return "Py%s_From%s(&%s,1)"%(self.mName,self.mName,var)
            elif (tag=='cref'):
                return "Py%s_From%s((%s*)(&%s),1)"%(self.mName,self.mName,self.mName,var)
            elif (tag=='ptr'):
                return "Py%s_From%s(%s,1)"%(self.mName,self.mName,var)
            elif (tag=='cptr'):
                return "Py%s_From%s((%s*)(%s),1)"%(self.mName,self.mName,self.mName,var)
            elif (tag=='simple'):
                return "Py%s_From%s(&%s,1)"%(self.mName,self.mName,var)
        elif (self.mIsPtr and self.mIsDb):
            if (tag=='ptr'):
                return "Py%s_From%s(%s)"%(self.mName,self.mName,var)
            elif (tag=='cptr'):
                return "Py%s_From%s((%s*)(%s))"%(self.mName,self.mName,self.mName,var)
        elif (not self.mIsPtr):
            if (tag=='simple'):
                return "Py%s_From%s(%s)"%(self.mName,self.mName,var)

        raise "Can't do tag: %s in GenVirtualArgs class: %s"%(tag,self.mName)
        
    # ----------------------------
    # Generate the result from a virtual function
    def GenVirtualResult(self,fp,var,rvar,fun):
        tag=fun.mValueUseTag
        if (not self.mIsPtr and tag=='simple'):
            fp.write("    PyParam%s %s;\n"%(self.mName,rvar))
            fp.write("    if (Py%s_Convert(%s,&rv)==0) {\n"%(self.mName,var))
            fp.write("        throw oaPythonException(\"Python Virtual Function %s::%s has incorrect return type.\");\n"%
                     (self.mName,fun.mName))
            fp.write("    }\n")
            return "%s.Data()"%rvar
        if (self.mIsPtr and not self.mIsDb and tag=='simple'):
            fp.write("    PyParam%s %s;\n"%(self.mName,rvar))
            fp.write("    if (Py%s_Convert(%s,&%s)==0) {\n"%(self.mName,var,rvar))
            fp.write("        throw oaPythonException(\"Python Virtual Function %s::%s has incorrect return type.\");\n"%
                     (self.mName,fun.mName))
            fp.write("    }\n")
            return "%s.Data()"%rvar

        raise str("Can't do tag: %s in GenVirtualResult class: %s %s"%(tag,self.mName,fun.mSig))
    
    # ===============================================================
    # These function control the generation of the header file
    # ===============================================================

    # ----------------------------
    # Generate the Class to wrap a class that has virtual functions
    # ----------------------------
    def GenVClassDeclaration(self,fp,did=None):
        if (not self.mVirt): return
        start=0
        if (did==None):
            start=1
            did={}
            fp.write("""\
PYTHON_OPENACCESS_CLASS pyv_%s: public %s {
public:
    Py%sObject* pyob;
    // Constructors
"""%(self.mName,self.mName,
     self.mName))
            for con in self.mConstructors:
                con.GenVirtualDeclaration(fp,self.mName)
            
            if (not self.mNoCopy):
                fp.write("    pyv_%s(const %s& p);\n"%(self.mName,self.mName))
        
        fp.write("    // From: %s\n"%self.mName)

        for fun in self.mMethods:
            fun.GenVirtualDeclaration(fp,did)

        if (self.mBase):
            self.mBase.GenVClassDeclaration(fp,did)

        if (start):
            fp.write("};\n\n")
        
    # ----------------------------
    # Generate the code for declaring a typedef
    # ----------------------------
    def GenTypedefDeclaration(self,fp):
        if (self.mTypedef):
            fp.write("%s;\n"%self.mTypedef)
        if (self.mTypedefDb):
            fp.write("%s;\n"%self.mTypedefDb)
            
    # ----------------------------
    # Generate the code for declaring a typedef
    # ----------------------------
    def GenTypenameDeclaration(self,fp):
        fp.write("typedef %s PyType%s;\n"%(self.mTypeName,self.mName))

    # ----------------------------
    # Generate the code for declaring an arrayed type
    # ----------------------------
    def GenArrayDeclaration(self,fp):
        if (self.mArray=='auto'):
            fp.write("""
typedef Pyoa_Array<PyType%s> %s_Array;
typedef Pyoa_ArrayObject<PyType%s> Py%s_ArrayObject;
typedef Pyoa_Array<PyType%s> PyParam%s_Array;
PYTHON_OPENACCESS_EXTERN PyTypeObject Py%s_Array_Type;
PYTHON_OPENACCESS_EXTERN int Py%s_Array_TypeInit(PyObject* dict); 
PYTHON_OPENACCESS_EXTERN int Py%s_Array_Convert(PyObject* obj,PyParam%s_Array* result);
PYTHON_OPENACCESS_EXTERN PyObject* Py%s_Array_From%s_Array(const %s_Array& value);
PYTHON_OPENACCESS_EXTERN PyObject* Py%s_Array_From%s_Array(PyType%s* value,Pyoa_ssize_t len,PyObject* lock); 
PYTHON_OPENACCESS_EXTERN PyObject* Py%s_Array_CreateList(PyParam%s_Array& value);
#define Py%s_Array_Check(op) PyObject_TypeCheck(op, &Py%s_Array_Type)
#define Py%s_Array_CheckExact(op) PyObject_TypeCheck((op)->ob_type == &Py%s_Array_Type)
  
"""%(self.mName,self.mName, # typedefs
     self.mName,self.mName,
     self.mName,self.mName,
     self.mName, # EXTERN(PyTypeObject)
     self.mName,
     self.mName,self.mName,
     self.mName,self.mName,self.mName, # EXTERN(PyObject*) 
     self.mName,self.mName,self.mName,
     self.mName,self.mName,
     self.mName,self.mName, # #define
     self.mName,self.mName,
))
        
    # ----------------------------
    # Generate the code for declaring the python objects
    # layout in the header file.
    # The C++ object pointers are allways stored as a pointer
    #  to the base object.
    #  This allows multiple inheritence in C++ at least.
    # ----------------------------
    def GenObjectDeclaration(self,fp):
        if (self.mRootBase): basename=self.mRootBase.mName
        else: basename=self.mName
        fp.write("typedef struct {\n")
        fp.write("    PyObject_VAR_HEAD\n")
        if (self.mIsDb):
          fp.write("    %s* data;\n"%(basename))
          fp.write("    %s** value;\n"%(basename))
        else:
          fp.write("    %s* value;\n"%(basename))
        fp.write("    PyObject* locks;\n")
        fp.write("    int borrow;\n")
        if (self.mRecord):
            for typ,name in self.mRecord:
                fp.write("    %s %s;\n"%(typ,name))
        fp.write("} Py%sObject;\n\n"%(self.mName))
        
    # ----------------------------
    # Generate the Type declaration
    def GenTypeDeclaration(self,fp):
        if (self.mIsDb):
            fp.write("typedef PyParamDbObject<%s> PyParam%s;\n"%(self.mName,self.mName))
        else:
            if (self.mPureVirt):
                fp.write("typedef PyParamVirtualObject<%s> PyParam%s;\n"%(self.mName,self.mName))
            else:
                fp.write("typedef PyParamObject<%s> PyParam%s;\n"%(self.mName,self.mName))
        fp.write("""\
PYTHON_OPENACCESS_EXTERN PyTypeObject Py%s_Type;
PYTHON_OPENACCESS_EXTERN int Py%s_TypeInit(PyObject* dict);
"""%(self.mName,
     self.mName))

    # ----------------------------
    # Generate the Type Check macros
    def GenCheckDeclaration(self,fp):
        fp.write("""\
#define Py%s_Check(op) PyObject_TypeCheck(op, &Py%s_Type)
#define Py%s_CheckExact(op) PyObject_TypeCheck((op)->ob_type == &Py%s_Type)
"""%(self.mName,self.mName,
     self.mName,self.mName,
     ))

    # ----------------------------
    # Generate the From function declaration
    def GenFromDeclaration(self,fp):
        if (self.mIsPtr):
            if (not self.mIsDb):
                fp.write("PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(%s* ob,int borrow=0,PyObject* lock=NULL);\n"%
                         (self.mName,self.mName,self.mName))
                if (self.mArray):
                    fp.write("PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(const %s& ob);\n"%
                             (self.mName,self.mName,self.mName))
            else:
                fp.write("PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(%s* ob);\n"%
                         (self.mName,self.mName,self.mName))
                fp.write("PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(%s** ob,int borrow,PyObject* lock=NULL);\n"%
                         (self.mName,self.mName,self.mName))
        else:
            fp.write("PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(%s ob);\n"%
                     (self.mName,self.mName,self.mName))


    # ----------------------------
    # Generate the Convert function declaration
    def GenConvertDeclaration(self,fp):
        fp.write("""\
PYTHON_OPENACCESS_EXTERN int Py%s_Convert(PyObject*,PyParam%s* result);
"""%(self.mName,self.mName))
        if (self.mAof):
            fp.write("""\
PYTHON_OPENACCESS_EXTERN int Py%s_ConvertAof(PyObject*,PyParam%s* result);
"""%(self.mName,self.mName))

    # ----------------------------
    # Generate the Math Declaration
    def GenMathDeclaration(self,fp):
        if (self.mManualMath):
            fp.write("""
PYTHON_OPENACCESS_EXTERN PyNumberMethods %sAsNumber;        
"""%(self.mName,
     ))

    # ----------------------------
    # Generate the Header declaration for the class
    # Since IsNative is known, we will do the work
    #  here so the derived class doesn't have to.
    def GenHeaderDeclaration(self,fp):
        if (self.HasDeclaration()==kClassDeclaration_None): return
        GenCommentBlock(fp,"Class: %s"%self.mName)
        if (self.HasDeclaration()==kClassDeclaration_Full):
            self.GenObjectDeclaration(fp)
            self.GenVClassDeclaration(fp)
        if (self.HasDeclaration()>=kClassDeclaration_Enum):
            self.GenTypeDeclaration(fp)
        if (self.HasDeclaration()>=kClassDeclaration_Native):
            self.GenConvertDeclaration(fp)
            self.GenFromDeclaration(fp)
        if (self.HasDeclaration()==kClassDeclaration_Full):
            self.GenCheckDeclaration(fp)
            self.GenMathDeclaration(fp)
        self.GenArrayDeclaration(fp)

    # ===============================================================
    # Functions that generat the implemenation code
    # ===============================================================

    # ----------------------------
    # Implment the From function
    def GenImplementFrom(self,fp):
        if (self.mIsDb):
            self.GenImplementFromDb(fp)
        elif (self.mIsPtr):
            self.GenImplementFromPtr(fp)
        else:
           raise "Enum/Manual"

    # ----------------------------
    # Implment the From function
    def GenImplementFromDb(self,fp):
        GenLine(fp)
        fp.write("""\
PyObject* Py%s_From%s(%s** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        %s* data=*value;
"""%(self.mName,self.mName,self.mName,self.mName))
        for clsname,check in self.mClassCasts:
            fp.write("        if (%s) return Py%s_From%s((%s**)value,borrow,lock);\n"%(
                check,clsname,clsname,clsname))
            
        fp.write("""\
        PyObject* bself = Py%s_Type.tp_alloc(&Py%s_Type,0);
        if (bself == NULL) return bself;
        Py%sObject* self = (Py%sObject*)bself;
        self->value = %svalue;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
"""%(self.mName,self.mName, # alloc
     self.mName,self.mName, # mself
     self.GetDownCast(1)))

        GenLine(fp)
        fp.write("""\
PyObject* Py%s_From%s(%s* data)
{
    if (data) {
"""%(self.mName,self.mName,self.mName))
        for clsname,check in self.mClassCasts:
            fp.write("        if (%s) return Py%s_From%s((%s*)data);\n"%(
                check,clsname,clsname,clsname))
        fp.write("""\
       PyObject* bself = Py%s_Type.tp_alloc(&Py%s_Type,0);
       if (bself == NULL) return bself;
       Py%sObject* self = (Py%sObject*)bself;
       self->data = %sdata;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
"""%(self.mName,self.mName, # alloc
     self.mName,self.mName, # mself
     self.GetDownCast(),
     ))

    # ----------------------------
    # Implment the From function
    def GenImplementFromPtr(self,fp):
        GenLine(fp)
        fp.write("""\
PyObject* Py%s_From%s(%s* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = Py%s_Type.tp_alloc(&Py%s_Type,0);
        if (bself == NULL) return bself;
        Py%sObject* self = (Py%sObject*)bself;
        self->value = %s data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
"""%(self.mName,self.mName,self.mName, # Function
     self.mName,self.mName, # alloc
     self.mName,self.mName, # mself
     self.GetDownCast()))

        if (self.mArray):
            GenLine(fp)
            fp.write("""\
PyObject* Py%s_From%s(const %s& data)
{
    PyObject* bself = Py%s_Type.tp_alloc(&Py%s_Type,0);
    if (bself == NULL) return bself;
    Py%sObject* self = (Py%sObject*)bself;
    self->value = %s new %s(data);
    self->borrow = 0;
    self->locks = NULL;
    return bself;
}
"""%(self.mName,self.mName,self.mName, # Function
     self.mName,self.mName, # alloc
     self.mName,self.mName, # mself
     self.GetDownCast(),self.mName,
     ))

    # ----------------------------
    # Implement the Convert Function
    def GenImplementConvert(self,fp):
        if (self.mIsDb):
            self.GenImplementConvertDb(fp)
        elif (self.mIsPtr):
            self.GenImplementConvertPtr(fp)
        else:
           raise "Enum/Manual"
        
            
    # ----------------------------
    # Implement the Convert Function
    def GenImplementConvertDb(self,fp):
        GenLine(fp)
        fp.write("""\
int
Py%s_Convert(PyObject* ob,PyParam%s* result)
{
    if (ob == NULL) return 1;
    if (Py%s_Check(ob)) {
        result->SetData( %s ((Py%sObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: %s Failed");
    return 0;
}
"""%(self.mName,self.mName,  # Convert
     self.mName, # Check
     self.GetUpCast(1),self.mName, # Result
     self.mName, # Error
     ))


    # ----------------------------
    # Implement the Convert Function
    def GenImplementConvertPtr(self,fp):
        GenLine(fp)
        fp.write("""\
int
Py%s_Convert(PyObject* ob,PyParam%s* result)
{
    if (ob == NULL) return 1;
    if (Py%s_Check(ob)) {
        result->SetData( %s ((Py%sObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: %s Failed");
    return 0;
}
"""%(self.mName,self.mName,  # Convert
     self.mName, # Check
     self.GetUpCast(),self.mName, # Result
     self.mName, # Error
     ))
        if (self.mAof):
            fp.write("""\
int
Py%s_ConvertAof(PyObject* ob,PyParam%s* result)
{
    if (ob == NULL) return 1;
    if (ob==Py_None) {
        result->SetData(NULL);
        return 1;
    }
    if (Py%s_Check(ob)) {
        result->SetData( %s ((Py%sObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: %s Failed");
    return 0;
}
"""%(self.mName,self.mName,  # Convert
     self.mName, # Check
     self.GetUpCast(),self.mName, # Result
     self.mName, # Error
     ))

    # ----------------------------
    # Implement the Convert Function
    def GenImplementArray(self,fp,native):
        if (self.mArray):
            pyCoderClassArray.GetArrayImplementation(fp,self.mName,self.mTypeName,native)

    # ----------------------------
    def Gen_tp_alloc(self,fp):
        pass

    # ----------------------------
    def Gen_tp_alloc_entry(self):
        return "PyType_GenericAlloc,\t"
    

    # ----------------------------
    def Gen_tp_init(self,fp):
        pass

    # ----------------------------
    def Gen_tp_init_entry(self):
        return "0,\t\t\t\t\t"
    

    # ----------------------------
    # Special case for copy constructor
    def Gen_tp_new_copy(self,fp):
        fp.write("""    // Case: (%s)
    {
        PyParam%s p1;
        if (PyArg_ParseTuple(args,(char*)\"O&\",
              &Py%s_Convert,&p1)) {
"""%(self.mName,
     self.mName,
     self.mName,
     ))
        indent=12
        if (self.mRecord):
            fp.write("%*sPy%sObject* cself=((Py%sObject*)PyTuple_GetItem(args,0));\n"%(
                indent,"",self.mName,self.mName))
        if (not self.mVirt):
            if (self.mIsDb):
                fp.write("%*sself->data=p1.Data();\n"%(indent,""))
                fp.write("%*sself->value=&(self->data);\n"%(indent,""))
            else:
                fp.write("%*sself->value=%s new %s(p1.Data());\n"%(
                    indent,"",self.GetDownCast(),self.mName))
        else:
            fp.write("%*sif (is_raw) {\n"%(indent,""))
            fp.write("%*sself->value=%s new %s(p1.Data());\n"%(
                indent+4,"",
                self.GetDownCast(),self.mName))
            fp.write("%*s}\n"%(indent,""))
            fp.write("%*selse {\n"%(indent,""))
            fp.write("%*spyv_%s* p=new pyv_%s(p1.Data());\n"%(
                indent+4,"",
                self.mName,self.mName))
            fp.write("%*sp->pyob=self;\n"%(indent,""))
            fp.write("%*sself->value=%sp;\n"%(
                indent+4,"",
                self.GetDownCast(),
                ))
            fp.write("%*s}\n"%(indent,""))

        if (self.mRecord):
            for typ,name in self.mRecord:
                fp.write("%*sself->%s=cself->%s;\n"%(indent,"",name,name))
        fp.write("""\
            return bself;
        }
    }
""")
        if (self.mIsDb): # empty/NULL constructor case
            fp.write("""    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)\"\")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
""")

    # ----------------------------
    # All our objects will look immuttable to Python.
    # Thus the value pointer is never NULL.
    # We allways do all of new's work, as that what C++ does.
    def Gen_tp_new(self,fp):
        GenLine(fp)
        manual=0
        for con in self.mConstructors:
            if (con.mIsManual): manual=1
        if (manual):
            fp.write("PyObject*\n")
        else:
            fp.write("static PyObject*\n")
        
        fp.write("%s_new(PyTypeObject *type, PyObject *args, PyObject *kwds)"%(self.mName))
        if (manual):
            fp.write(";\n\n")
            return
        else:
            fp.write("\n{\n")
            
        GenTry(fp)
        fp.write("""\
    int is_raw=(type==&Py%s_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    Py%sObject* self = (Py%sObject*)bself;
    self->locks = NULL;
"""%(self.mName,self.mName,self.mName))
        fp.write("    self->borrow = 0;\n")
        fp.write("    static char *kwlist [] = { NULL } ;\n")
        if (self.mPureVirt):
            fp.write("""\
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: %s");
    }
    else {
        pyv_%s* p = new pyv_%s();
        p->pyob=self;
        self->value= %s p;
        return bself;
    }
"""%(self.mName,
     self.mName,self.mName,
     self.GetDownCast()))

        else:
            choices=[]
            for con in self.mConstructors:
                choice=con.GenCodeConTest(fp,self,4)
                choices.append(choice)
                fp.write("    PyErr_Clear();\n")
            
            # Don't do copy if there disabled, 
            # or there was an explict copy which we just did. 
            if (not self.mNoCopy and not self.mHasCopy):
                self.Gen_tp_new_copy(fp)
                choices.append("(%s)"%self.mName)
                fp.write("    PyErr_Clear();\n")

            fp.write("    PyErr_SetString(PyExc_TypeError,\n")
            fp.write("        \"No Arg-Matching Constructor found for class: %s, Choices are:\\n\"\n"%
                (self.mName))
            for choice in choices:
                fp.write("        \"    %s\\n\"\n"%choice)
            fp.write("    );\n")
        fp.write("    Py_DECREF(self);\n")
        fp.write("    return NULL;\n")
        GenCatch(fp)
        fp.write("}\n\n")

    # ----------------------------
    def Gen_tp_new_entry(self):
        return "%s_new,\t"%self.mName


    # ----------------------------
    def Gen_tp_dealloc(self,fp):
        GenLine(fp)
        fp.write("""\
static void
%s_tp_dealloc(Py%sObject* self)
{
"""%(self.mName,self.mName))

        if (not self.mPureVirt and self.mIsPtr and not self.mIsDb):
            fp.write("""\
    if (!self->borrow) {
        delete %s(self->value);
    }
    Py_XDECREF(self->locks);
"""%(self.GetUpCast()))

        fp.write("""\
    self->ob_type->tp_free((PyObject*)self);
}

""")

    # ----------------------------
    def Gen_tp_dealloc_entry(self):
        return "(destructor)%s_tp_dealloc,\t"%self.mName


    # ----------------------------
    def Gen_tp_free(self,fp):
        pass

    # ----------------------------
    def Gen_tp_free_entry(self):
        return "_PyObject_Del,\t"
    

    # ----------------------------
    # Generate the string representation
    def Gen_tp_repr(self,fp):
        GenLine(fp)
        fp.write("""static PyObject*
%s_tp_repr(PyObject *ob)
{
    PyParam%s value;
    int convert_status=Py%s_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
"""%(self.mName, # repr
     self.mName, # value
     self.mName, # assert
     ))

        l=len(self.mName)+18+4
        if (self.mRepr):
            local_repr="""%s
    char addr[%d];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString(\"<%s::\");
    buffer+=oaString(addr);
    buffer+=oaString(\"::\");
    buffer+=oaString(sresult);
    buffer+=oaString(\">\");
    result=PyString_FromString((char*)(const char*)buffer);
"""%(self.mRepr,l,self.mName)

            if (self.mIsDb):
                local_repr='    '+string.replace(local_repr,'\n','\n    ')
                fp.write("""\
    if (!value.Data()) {
        oaString buffer(\"<%s::NULL>\");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
%s
    }
"""%(self.mName,local_repr))
            else:
                fp.write("%s"%local_repr)

        else:
            fp.write("""
    char buffer[%d];
    sprintf(buffer,\"<%s::\" DISPLAY_FORMAT \">\",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
"""%(l, # char[]
     self.mName, #sprintf
     ))
        fp.write("""\
    return result;
}
        
""")

    # ----------------------------
    def Gen_tp_repr_entry(self):
        return "(reprfunc)%s_tp_repr,\t"%self.mName
    

    # ----------------------------
    # For print call _repr and print it
    def Gen_tp_print(self,fp):
        return
        GenLine(fp)
        fp.write("""static PyObject*
%s_tp_print(PyObject *ob,FILE* fp,int flags)
{
    PyObject* s=%s_repr(ob);
    fputs(PyString_AsString(s),fp);
    Py_DECREF(s);
    return 0;
}
        
"""%(self.mName,self.mName))

    # ----------------------------
    def Gen_tp_print_entry(self):
        return "0,\t"
        #return "(printfunc)%s_tp_print,\t"%self.mName
    

    # ----------------------------
    # Geneate the compare operation
    def Gen_tp_compare(self,fp):
        if (not self.mCompare): return
        GenLine(fp)
        fp.write("""static int
%s_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParam%s v1;
    PyParam%s v2;
    int convert_status1=Py%s_Convert(ob1,&v1);
    int convert_status2=Py%s_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
"""%(self.mName, # compare
     self.mName, # v1
     self.mName, #v2
     self.mName, # status1
     self.mName, # status2
    ))
        if (self.mCompare!='pointer'):
            fp.write("    if (v1.Data()==v2.Data()) return 0;\n")
            if (self.mCompare=='math'):
                fp.write("    if (v1.Data()<v2.Data()) return -1;\n")
        fp.write("""\
    return 1;
}
        
""")

    # ----------------------------
    def Gen_tp_compare_entry(self):
        if (self.mCompare):
            return "(cmpfunc)%s_tp_compare,\t"%self.mName
        else:
            return "0,\t\t\t\t\t"
    
    # ----------------------------
    # Generate the interator functions
    def Gen_tp_iternext(self,fp):
        pass

    # ----------------------------
    def Gen_tp_iternext_entry(self):
        return "0,\t\t\t\t\t"

    # ----------------------------
    # Generate the interator functions
    def Gen_tp_getiter(self,fp):
        pass

    # ----------------------------
    def Gen_tp_getiter_entry(self):
        return "0,\t\t\t\t\t"

    # ----------------------------
    # Generate the interator functions
    def Gen_tp_seq(self,fp):
        if (len(self.mIndexGetMethods)==0): return
        GenLine(fp)
        fp.write("""
static PySequenceMethods %s_as_sequence = {
"""%(self.mName))
        if (self.mIndexGetMethods[0].mRangeCheck):
            fp.write("    (Pyoa_inquiry)%s_length, /* sq_length */\n"%(
              self.mIndexGetMethods[0].GetFunName(self)))
        else:
            fp.write("    (Pyoa_inquiry)0,\t\t/* sq_length */\n")
        fp.write("""\
    (Pyoa_binaryfunc)0,\t\t/* sq_concat */
    (Pyoa_intargfunc)0,\t\t/* sq_repeat */
    (Pyoa_intargfunc)%s,\t/* sq_item */
"""%(self.mIndexGetMethods[0].GetFunName(self)))

        if (len(self.mIndexSetMethods)!=0):
            fp.write("""\
    (Pyoa_intintargfunc)0,\t\t/* sq_slice */
    (Pyoa_intobjargproc)%s,\t/* sq_ass_item */
"""%(self.mIndexSetMethods[0].GetFunName(self)))
        fp.write("""\
};
""")
        

    # ----------------------------
    def Gen_tp_math_entry(self):
        if (self.mManualMath):
            return "&%sAsNumber,\t"%self.mName
        else:
            return "0,\t\t\t\t\t"

    # ----------------------------
    def Gen_tp_seq_entry(self):
        if (len(self.mIndexGetMethods)==0):
            return "0,\t\t\t\t\t"
        else:
            return "&%s_as_sequence,\t"%self.mName

    # ----------------------------
    # Generate the Implementation of wrap a class that has virtual functions
    # ----------------------------
    def GenVClassCode(self,fp,did=None,cls=None):
        if (not self.mVirt): return
        if (did==None):
            GenCommentBlock(fp,"Virtual Functions:")
            cls=self
            did={}
            for con in self.mConstructors:
                con.GenVirtualBody(fp,self.mName)
            
            if (not self.mNoCopy):
                GenLine(fp)
                fp.write("""\
pyv_%s::pyv_%s(const %s& p)
 : pyob(NULL),
   %s(p)
{
}

"""%(self.mName,self.mName,self.mName, # func
     self.mName, # call
     ))

        for fun in self.mMethods:
            fun.GenVirtualBody(fp,did,cls,self)

        if (self.mBase):
            self.mBase.GenVClassCode(fp,did,cls)
        
    # ----------------------------
    # Generate the methods
    def GenMethods(self,fp):
        # -------------------------
        for att in ['mIndexGetMethods','mIndexSetMethods']:
            funs=getattr(self,att)
            if (funs):
                GenCommentBlock(fp,att[1:]+':')
                for fun in funs:
                    GenLine(fp)
                    fun.GenCode(fp,self)

        # -------------------------
        if (self.mMethods):
            GenCommentBlock(fp,"FunctionMethods:")
            for fun in self.mMethods:
                GenLine(fp)
                fun.GenCode(fp,self)
            if (self.mIsDb):
                self.GenIsNull(fp)
                
            if (not self.mNoAssign):
                self.GenAssign(fp)
            
            
    # ----------------------------
    # Generate the set
    def GenAssign(self,fp):
            fp.write("""\
static char %s_assign_doc[] = 
"Class: %s, Function: set\\n"
"  Paramegers: (oaDouble)\\n"
"    This function sets the current value.\\n"
;

static PyObject*
%s_tp_assign(PyObject* ob, PyObject *args)
{
  PyParam%s data;
  int convert_status=Py%s_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParam%s p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &Py%s_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

"""%((self.mName,)*7))

    # ----------------------------
    # Generate IsNull
    def GenIsNull(self,fp):
        GenLine(fp)
        fp.write("""\
static char %s_isNull_doc[] =
"Class: %s, Function: isNull\\n"
"  Parameters: () \\n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\\n"
;

static PyObject*
%s_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParam%s data;
    int convert_status=Py%s_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
"""%(self.mName,self.mName, # doc
     self.mName, # Fun
     self.mName, # Param
     self.mName, # Convert
     ))
     
    # ----------------------------
    # Generate the tp_methods table
    def Gen_tp_methods(self,fp):
        if (len(self.mMethods)==0): return
        
        GenCommentBlock(fp," Function Methods Table:")
        fp.write("static PyMethodDef %s_methodlist[] = {\n"%(self.mName))
        for funs in self.mMethods:
            fp.write("    {\"%s\",(PyCFunction)%s,METH_VARARGS,%s_doc},\n"%
                     (funs.mName,funs.GetFunName(self),funs.GetFunName(self)))
        if (self.mIsDb):
            fp.write("    {\"isNull\",(PyCFunction)%s_tp_isNull,METH_VARARGS,%s_isNull_doc},\n"%
                (self.mName,self.mName))
        if (not self.mNoAssign):
            fp.write("    {\"assign\",(PyCFunction)%s_tp_assign,METH_VARARGS,%s_assign_doc},\n"%
                (self.mName,self.mName))
        fp.write("   {NULL,NULL,0,NULL}\n")
        fp.write("};\n")
        fp.write("\n")
        
    # ----------------------------
    def Gen_tp_methods_entry(self):
        if (len(self.mMethods)==0):
            return "0,\t\t\t\t\t"
        else:
            return "%s_methodlist,\t"%self.mName


    # ----------------------------
    def Gen_tp_base_entry(self):
        if (self.mBase):
            return "&Py%s_Type,\t"%self.mBase.mName
        return "0,\t\t\t\t\t"


    # ----------------------------
    # Generate class tp_doc data
    def Gen_tp_doc(self,fp):
        GenLine(fp)
        fp.write("static char %s_doc[] = \n"%(self.mName))
        fp.write("\"Class: %s\\n\"\n"%(self.mName))
        if (self.mDesc):
            for line in self.mDesc.split("\n"):
                line=string.replace(line,'\\','\\\\')
                line=string.replace(line,'"','\\"')
                fp.write("\"  %s\\n\"\n"%line)
        choices=[]
        fp.write("\"Constructors:\\n\"\n")
        for con in self.mConstructors:
            fp.write("\"  Paramegers: %s\\n\"\n"%con.GenChoices(self))
            fp.write("\"    Calls: %s\\n\"\n"%con.GenCall(self))
            fp.write("\"    Signature: %s\\n\"\n"%con.mSig)
            if (con.mDesc):
                for line in con.mDesc.split("\n"):
                    line=string.replace(line,'\\','\\\\')
                    line=string.replace(line,'"','\\"')
                    fp.write("\"    %s\\n\"\n"%line)

        if (not self.mNoCopy):
            fp.write("\"  Paramegers: (%s)\\n\"\n"%self.mName)
            fp.write("\"    Calls: (const %s&)\\n\"\n"%(self.mName))
            fp.write("\"    Signature: %s||cref-%s,\\n\"\n"%(self.mName,self.mName))

        fp.write(";\n\n")
            
    # ----------------------------
    def Gen_tp_doc_entry(self):
        return "%s_doc,\t"%self.mName
    

    # ----------------------------
    # Generate the TypeObject description
    def GenTypObject(self,fp):
        GenLine(fp)
        fp.write("""PyTypeObject Py%s_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "%s",
    sizeof(Py%sObject),
    0,
    %s/* tp_dealloc */
    %s/* tp_print */
    0,\t\t\t\t\t/* tp_getattr */
    0,\t\t\t\t\t/* tp_setattr */
    %s/* tp_compare */
    %s/* tp_repr */
    %s/* tp_as_number */
    %s/* tp_as_sequence */
    0,\t\t\t\t\t/* tp_as_mapping */
    0,\t\t\t\t\t/* tp_as_hash */
    0,\t\t\t\t\t/* tp_as_call */
    0,\t\t\t\t\t/* tp_str */
    0,\t\t\t\t\t/* tp_getattro */
    0,\t\t\t\t\t/* tp_setattro */
    0,\t\t\t\t\t/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    %s/* tp_doc */
    0,\t\t\t\t\t/* tp_traverse */
    0,\t\t\t\t\t/* tp_clear */
    0,\t\t\t\t\t/* tp_richcompre */
    0,\t\t\t\t\t/* tp_weaklistoffset */
    %s/* tp_iter */
    %s/* tp_iternext */
    %s/* tp_methods */
    0,\t\t\t\t\t/* tp_members */
    0,\t\t\t\t\t/* tp_getset */
    %s/* tp_base */
    0,\t\t\t\t\t/* tp_dict */
    0,\t\t\t\t\t/* tp_descr_get */
    0,\t\t\t\t\t/* tp_descr_set */
    0,\t\t\t\t\t/* tp_dictoffset */
    %s/* tp_init */
    %s/* tp_alloc */
    %s/* tp_new */
    %s/* tp_free */
};

"""%(self.mName, # type
     self.mName, # name
     self.mName, # size
     self.Gen_tp_dealloc_entry(),
     self.Gen_tp_print_entry(),
     self.Gen_tp_compare_entry(),
     self.Gen_tp_repr_entry(),
     self.Gen_tp_math_entry(),
     self.Gen_tp_seq_entry(),
     self.Gen_tp_doc_entry(),
     self.Gen_tp_getiter_entry(),
     self.Gen_tp_iternext_entry(),
     self.Gen_tp_methods_entry(),
     self.Gen_tp_base_entry(),
     self.Gen_tp_init_entry(),
     self.Gen_tp_alloc_entry(),
     self.Gen_tp_new_entry(),
     self.Gen_tp_free_entry(),
     ))


    # ----------------------------
    # Generate static methods
    # These are built as plain python functions
    #   and then added to the types dictionary.
    def GenStaticMethods(self,fp):
        if (self.mStaticMethods):
            GenCommentBlock(fp,"Static FunctionMethods:")
            for funs in self.mStaticMethods:
                GenLine(fp)
                funs.GenCode(fp,self)
            
    # ----------------------------
    # Generate a table of static methods
    def GenStaticMethodTable(self,fp):
        if (len(self.mStaticMethods)==0): return
        
        GenLine(fp)
        fp.write("static PyMethodDef %s_staticmethodlist[] = {\n"%(self.mName))
        for funs in self.mStaticMethods:
            fp.write("    {\"static_%s\",(PyCFunction)%s,METH_VARARGS,%s_doc},\n"%
                     (funs.mName,funs.GetFunName(self),funs.GetFunName(self)))
        fp.write("   {NULL,NULL,0,NULL}\n")
        fp.write("};\n")
        fp.write("\n")

    # ----------------------------
    # Code to initialize the TypeObject,
    #   add the type to the module dictionary
    #   add the static members to the type dictionary
    # This will be call in the module init routine.
    def GenStaticMethodFun(self,fp):
        GenCommentBlock(fp," Type Init:")
        fp.write("""int
Py%s_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&Py%s_Type)<0) {
      printf(\"** PyType_Ready failed for: %s\\n\");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,\"%s\",
           (PyObject*)(&Py%s_Type))<0) {
       printf(\"** Failed to add type name to module dictionary for: %s\\n\");
       return -1;
    }
"""%(self.mName, # Init
     self.mName, # Ready
     self.mName, # Error
     self.mName,self.mName, # SetString
     self.mName, # Error
     ))
        if (self.mStaticMethods):
            fp.write("""\

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=Py%s_Type.tp_dict;
    for(method=%s_staticmethodlist;method->ml_name!=NULL;method++) {
        value=PyCFunction_New(method,NULL);
    if (value==NULL) return -1;
        if (PyDict_SetItemString(dict,method->ml_name,value)!=0) {
        Py_DECREF(value);
            printf(\"** Failed to add static function to module dictionary for: %%s\\n\",
                method->ml_name);
            return -1;
        }
        Py_DECREF(value);
    }
"""%(self.mName, # Type
     self.mName, # for
     ))

        fp.write("    return 0;\n")
        fp.write("}\n\n")
        
    # ----------------------------
    # Generate the C implemenation file for the class
    def GenImplementation(self,fp):
        GenMajorCommentBlock(fp,"Wrapper Implementation for Class: %s"%self.mName)
        GenMajorCommentBlock(fp,"Alloc/Dealloc Routines")
        self.Gen_tp_new(fp)
        self.Gen_tp_alloc(fp)
        self.Gen_tp_init(fp)
        self.Gen_tp_free(fp)
        self.Gen_tp_dealloc(fp)
        self.Gen_tp_free(fp)
        self.Gen_tp_repr(fp)
        self.Gen_tp_print(fp)
        self.Gen_tp_compare(fp)
        self.Gen_tp_getiter(fp)
        self.Gen_tp_iternext(fp)
        self.GenImplementConvert(fp)
        self.GenImplementFrom(fp)
        self.GenVClassCode(fp)
        self.GenMethods(fp)
        self.Gen_tp_methods(fp)
        GenCommentBlock(fp," Type Object:")
        self.Gen_tp_seq(fp)
        self.Gen_tp_doc(fp)
        self.GenTypObject(fp)
        self.GenStaticMethods(fp)
        self.GenStaticMethodTable(fp)
        self.GenStaticMethodFun(fp)
        self.GenImplementArray(fp,0)

    # ----------------------------
    # Generate the C function that checks the variables range
    # Also needed for templates with args of these native types
    def GenNativeFunctions(self,fp):
        fp.write("""
static char openaccess_%s_doc[] = 
"Class: openaccess, Function: %s\\n"
"  Paramegers: (%s)\\n"
;

static PyObject*
openaccess_%s(PyObject* ob, PyObject *args)
{
  try {
    %s p1;
    if (PyArg_ParseTuple(args,"O&",
          &Py%s_Convert,&p1)) {
        return Py%s_From%s(p1);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

"""%(self.mName, # static
     self.mName, # Class Function
     self.mName, # Parameters
     self.mName, # openaccess_
     self.mName, # Var
     self.mName, # Convert
     self.mName,self.mName, # From
     ))

# ===================================================================
# Alloc classes own the pointer to the object. This is the default
# ===================================================================
class cAllocClassDesc(cClassDesc):
    __doc__="cAllocBaseClassDesc - Class description for alloc mode clases that are base classes"
    def __init__(self,name,**kw):
        kw['with_borrow']=1
        cClassDesc.__init__(*(self,name),**kw)


# ===================================================================
# Iter classes own the pointer to the object. This is the default
# ===================================================================
class cIterClassDesc(cClassDesc):
    __doc__="cItercBaseClassDesc - Class description for alloc-iter mode clases that are base classes"
    def __init__(self,name,**kw):
        dict=copy.copy(kw)

        self.mType=dict.get('type')
        if (self.mType==None):
            raise ("type not specified on IterClass: %s"%name)
        del dict['type']

        self.mFun=dict.get('fun')
        if (self.mFun==None):
            raise ("fun not specified on IterClass: %s"%name)
        del dict['fun']
        cClassDesc.__init__(*(self,name),**dict)

        fun=None
        for funx in self.mMethods:
            if (funx.mName==self.mFun):
                fun=funx
                break
        if (fun==None):
            raise ("fun not found on IterClass: %s"%name)
        self.mFunFun=fun.mFuns[0]
            
        self.mMethods.append(cFunGroupDesc(name='next',
                                           funs=[cFunDesc(name='next',
                                                     call=self.mFun,
                                                     value=self.mType,
                                                     value_tag='ptr',
                                                     value_utag='simple',
                                                     sig='next|ptr-%s|,'%(self.mType),
                                                     isiter=1,
                                                     ismanual=self.mFunFun.mIsManual,
                                                     desc="get next value or raise StopIteration"),]))

    # ===============================================================
    # These function convert type names in the intial descriptions
    # to object references. Call by cMainDesc in PrepareClass
    # ===============================================================
    def Prepare(self,dict):
        cClassDesc.Prepare(self,dict)

        base=dict.get(self.mType)
        if (not base):
            raise "Undefined Iter type class name: %s in class: %s"%(self.mType,self.mName)
        self.mType=base

    # ----------------------------
    # Generate the interator functions
    def Gen_tp_iternext(self,fp):
        GenLine(fp)
        if (self.mFunFun.mIsManual):
            fp.write("PyObject* %s_iternext(PyObject *self);\n\n"%self.mName)
            return
        fp.write("""\
static PyObject*
%s_iternext(PyObject *self)
{
"""%(self.mName))
        GenTry(fp)
        fp.write("""\
    PyParam%s ob;
    int convert_status=Py%s_Convert(self,&ob);
    assert(convert_status!=0);
    %s* result;
    result=ob.DataCall()->%s();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return Py%s_From%s(result);
"""%(self.mName, # op
     self.mName, # convert
     self.mType.mName, # result
     self.mFun, # call
     self.mType.mName,self.mType.mName # return
     ))
     
        GenCatch(fp)
        fp.write("}\n\n")

    # ----------------------------
    def Gen_tp_iternext_entry(self):
        return "(iternextfunc)%s_iternext,\t"%(self.mName)

    # ----------------------------
    # Generate the interator functions
    def Gen_tp_getiter(self,fp):
        GenLine(fp)
        fp.write("""\
static PyObject*
%s_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

"""%(self.mName, # iterget
     ))

    # ----------------------------
    def Gen_tp_getiter_entry(self):
        return "(getiterfunc)%s_getiter,\t"%(self.mName)

# ===================================================================
# Borrow classes don't own the pointer to the object
# ===================================================================
class cDbClassDesc(cClassDesc):
    __doc__="cBorrowClassDesc - Class description for borrow mode clases"
    def __init__(self,name,**kw):
        kw['is_db']=1
        cClassDesc.__init__(*(self,name),**kw)

                           
# ===================================================================
# Enum/classes can be converted to/from native python objects.
# ===================================================================
class cEnumClassDesc(cClassDesc):
    __doc__="cEnumClassDesc - Class description for native enum clases"
    def __init__(self,name,values=None,texts=None,desc=None,):
        cClassDesc.__init__(self,name,desc=desc,is_ptr=0,
                            has_declaration=kClassDeclaration_Enum,
                            has_implementation=1)
        self.mValues=string.split(values)
        if (texts==None):
            self.mTexts=string.split(values)
        else:
            self.mTexts=string.split(texts)

    # ----------------------------
    # Generate the Type declaration
    def GenTypeDeclaration(self,fp):
        fp.write("typedef PyParamEnumObject<%s> PyParam%s;\n"%(self.mName,self.mName))
        fp.write("""\
PYTHON_OPENACCESS_EXTERN int Py%s_TypeInit(PyObject* dict);
"""%(self.mName))

    # ----------------------------
    # Implment the From function
    def GenImplementFromEnum(self,fp):
        GenLine(fp)
        fp.write("""
PyObject* Py%s_From%s(%s ob)
{
"""%(self.mName,self.mName,self.mName))

        for i in range(len(self.mTexts)):
            fp.write("    if (ob==%s) return PyString_FromString(\"%s\");\n"%
                     (self.mValues[i],self.mTexts[i]))

        fp.write("""
    Py_INCREF(Py_None);
    return Py_None;
}
""")
                 
    # ----------------------------
    # Implement the Convert Function
    def GenImplementConvertEnum(self,fp):
        GenLine(fp)
        fp.write("""
int
Py%s_Convert(PyObject* ob,PyParam%s* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
"""%(self.mName,self.mName,  # Convert
     ))
        for i in range(len(self.mTexts)):
            fp.write("        if (strcasecmp(str,\"%s\")==0) { result->SetData(%s); return 1;}\n"%
                     (self.mTexts[i],self.mValues[i]))

        fp.write("""\
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((%s)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: %s Failed");
    return 0;
}
"""%(self.mName, # result
     self.mName, # Error
     ))

    # ----------------------------
    # A function to convert int<>string as the type converter
    def GenStaticMethod(self,fp):
        GenCommentBlock(fp," Enum Typecast function:")
        fp.write("""\
static PyObject*
Py%s_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    %s e;
    if (PyArg_ParseTuple(args,(char*)\"i\",&v)) {
       return Py%s_From%s(%s(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)\"O&\",&Py%s_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char %s_doc[] =
\"Type convert function for enum: %s\";
                               
static PyMethodDef Py%s_method =
  {\"%s\",(PyCFunction)Py%s_TypeFunction,METH_VARARGS,%s_doc};
  
"""%(self.mName, # Function
     self.mName, # var e
     self.mName,self.mName,self.mName, # return
     self.mName,
     self.mName, # doc
     self.mName, # doc string
     self.mName, # method
     self.mName,self.mName,self.mName, # method entry
     ))


    # ----------------------------
    # Code to initialize the enum values into the module dictionary
    def GenStaticMethodFun(self,fp):
        GenCommentBlock(fp," Enum Init:")
        fp.write("""int
Py%s_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
"""%(self.mName, # Init
     ))

        for i in range(len(self.mTexts)):
            fp.write("""\
    value=PyString_FromString(\"%s\");
    PyDict_SetItemString(mod_dict,\"%s\",value);
    Py_DECREF(value);
"""%(self.mTexts[i],self.mTexts[i]))
        
        fp.write("""
    // Put Enum name function in Dictionary
    value=PyCFunction_New(&Py%s_method,NULL);
    if (PyDict_SetItemString(mod_dict,\"%s\",value)!=0) {
    Py_DECREF(value);
        printf(\"** Failed to add enum function to module dictionary for: %s\\n\");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}
"""%(self.mName, #value
     self.mName, #setitem
     self.mName, #Error
    ))

    # ----------------------------
    # Generate the C implemenation file for the class
    def GenImplementation(self,fp):
        GenMajorCommentBlock(fp,"Wrapper Implementation for Class: %s"%self.mName)
        self.GenImplementConvertEnum(fp)
        self.GenImplementFromEnum(fp)
        self.GenStaticMethod(fp)
        self.GenStaticMethodFun(fp)

# ===================================================================
# Manual classes can be used for arrayed elements
# Their convert functions have been manually coded.
# ===================================================================
class cManualClassDesc(cClassDesc):
    __doc__="cManualClassDesc - Class description for manual clases"
    def __init__(self,name,choice,
                 array=0,
                 aof=0,
                 builtin=0,
                 typedef=None,
                 desc=None):
        cClassDesc.__init__(self,name,desc=desc,is_ptr=0,
                            typedef=typedef,
                            has_declaration=kClassDeclaration_Native,
                            has_implementation=0)
        self.mArray=array
        self.mAof=aof
        self.mBuiltin=builtin
        self.mChoice=choice.split("\n")

    # ----------------------------
    def GenHeaderDeclaration(self,fp):
        if (self.mBuiltin): return
        GenCommentBlock(fp,"Manual Class: %s"%self.mName)
        fp.write("""\
typedef Pyoa_Object<%s> Py%sObject;
typedef PyParamObject<%s> PyParam%s;
PYTHON_OPENACCESS_EXTERN PyTypeObject Py%s_Type;
PYTHON_OPENACCESS_EXTERN int Py%s_TypeInit(PyObject* dict);
PYTHON_OPENACCESS_EXTERN int Py%s_Convert(PyObject* obj,PyParam%s* result);
PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(const %s& value);
PYTHON_OPENACCESS_EXTERN PyObject* Py%s_From%s(%s* value,int borrow,PyObject* lock);
#define Py%s_Check(op) PyObject_TypeCheck(op, &Py%s_Type) 
#define Py%s_CheckExact(op) PyObject_TypeCheck((op)->ob_type == &Py%s_Type) 

"""%((self.mName,)*18))
        if (self.mAof):
            fp.write("PYTHON_OPENACCESS_EXTERN int Py%s_ConvertAof(PyObject* obj,PyParam%s* result);\n"%(
                self.mName,self.mName))

        self.GenArrayDeclaration(fp)

    # ----------------------------
    # Generate the variable cast for virtual args
    def GenVirtualArg(self,var,param):
        tag=param.mTag
        if (tag=='ptr'):
            return "Py%s_Array_From%s_Array((const %s*)%s)"%(self.mName,self.mName,self.mName,var)
        elif (tag=='cptr'):
            return "Py%s_Array_From%s_Array(%s)"%(self.mName,self.mName,var)
        elif (tag=='simple'):
            return "Py%s_From%s(%s)"%(self.mName,self.mName,var)
        elif (tag=='cref'):
            return "Py%s_From%s(%s)"%(self.mName,self.mName,var)
        elif (tag=='ref'):
            return "Py%s_From%s(%s)"%(self.mName,self.mName,var)

        raise "Can't do tag: %s in GenVirtualArgs class: %s"%(tag,self.mName)
