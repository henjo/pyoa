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
import sys

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
# General Array Implementation
# ===================================================================

def GetArrayImplementation(fp,name,typename,native):
  GenMajorCommentBlock(fp,"Array for class: %s"%name)
  args=[]
  #for i in range(45): args.append(name)
  #args.append(typename)
  #for i in range(6): args.append(name)
  #args.append(typename)
  #for i in range(72): args.append(name)

  for i in range(122): args.append(name)
  args=tuple(args)
  
  fp.write("""\
// ------------------------------------------------------------------
static PyObject*
%s_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&Py%s_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    Py%s_ArrayObject* self = (Py%s_ArrayObject*)gself;
    self->borrow = 0;
    self->locks=NULL;
    static char *kwlist [] = { NULL } ;
    /* Case: () */ 
    {
        if (PyArg_ParseTuple(args,"")) {
            return gself;
        }
    }
    PyErr_Clear();
    /* Case: (int) */
    {
        int p1;
        if (PyArg_ParseTuple(args,(char*)"i",&p1)) {
            self->data.SetLen(p1);
            return gself;
        }
    }
    PyErr_Clear();
    /* Case: (%s_Array) */
    {
        PyParam%s_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &Py%s_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: %s_Array, Choices are:\\n"
        "    ()\\n"
        "    (int)\\n"
        "    (%s_Array)\\n"
    );
    Py_DECREF(gself);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
%s_Array_dealloc(PyObject* gself)
{
    Py%s_ArrayObject* self = (Py%s_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
%s_Array_str(PyObject *ob)
{
    PyParam%s_Array value;
    int convert_status=Py%s_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=Py%s_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
%s_Array_repr(PyObject *ob)
{
    PyParam%s_Array value;
    int convert_status=Py%s_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=Py%s_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
%s_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParam%s_Array p1;
    PyParam%s_Array p2;
    int s1=Py%s_Array_Convert(ob1,&p1);
    int s2=Py%s_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=Py%s_Array_CreateList(p1);
    PyObject* l2=Py%s_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
Py%s_Array_Convert(PyObject* ob,PyParam%s_Array* result)
{
  Pyoa_ssize_t len,i;
  if (Py%s_Array_Check(ob)) {
    Py%s_ArrayObject* self = (Py%s_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParam%s data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!Py%s_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParam%s data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!Py%s_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: %s_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* Py%s_Array_From%s_Array(const %s_Array& value)
{
  PyObject* gself = Py%s_Array_Type.tp_alloc(&Py%s_Array_Type,0);
  if (gself == NULL) return gself;
  Py%s_ArrayObject* self = (Py%s_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* Py%s_Array_From%s_Array(PyType%s* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = Py%s_Array_Type.tp_alloc(&Py%s_Array_Type,0);
  if (gself == NULL) return gself;
  Py%s_ArrayObject* self = (Py%s_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* Py%s_Array_CreateList(PyParam%s_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=Py%s_From%s(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char %s_Array_assign_doc[] = 
"Class: %s_Array, Function: assign\\n"
"  Paramegers: (%s_Array)\\n"
"    This function assigns the current value.\\n"
;

static PyObject*
%s_Array_assign(PyObject* ob, PyObject *args)
{
  Py%s_ArrayObject* self=(Py%s_ArrayObject*)ob;
  try {
    PyParam%s_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &Py%s_Array_Convert,&p1)) {
        self->data=p1;
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
// ------------------------------------------------------------------
static char %s_Array_list_doc[] = 
"Class: %s_Array, Function: list\\n"
"  Paramegers: ()\\n"
"    This function returns the current value as a list.\\n"
;

static PyObject*
%s_Array_list(PyObject* ob, PyObject *args)
{
  Py%s_ArrayObject* self=(Py%s_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return Py%s_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef %s_Array_methodlist[] = {
    {"assign",(PyCFunction)%s_Array_assign,METH_VARARGS,%s_Array_assign_doc},
    {"list",(PyCFunction)%s_Array_list,METH_VARARGS,%s_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
%s_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  Py%s_ArrayObject* self=(Py%s_ArrayObject*)ob;
  try {
    PyParam%s_Array data;
    int convert_status=Py%s_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return Py%s_From%s(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
%s_Array_index_get_length(PyObject* ob)
{
    PyParam%s_Array data;
    int convert_status=Py%s_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
%s_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParam%s_Array data;
    PyParam%s dataitem;
    int convert_status=Py%s_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (Py%s_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char %s_Array_doc[] =
"Class: %s_Array\\n"
"  The %s_Array utility class provides an array of %s.\\n"
"Constructors:\\n"
"  Paramegers: ()\\n"
"    Calls: %s_Array()\\n"
"    Signature: %s_Array||\\n"
"    This is the default constructor for the %s_Array class. This constructor creates an empty %s_Array.\\n"
"  Paramegers: (%s_Array)\\n"
"    Calls: (const %s_Array&)\\n"
"    Signature: %s_Array||cref-%s_Array,\\n"
;

// ------------------------------------------------------------------
static PySequenceMethods %s_Array_as_sequence = {
    (Pyoa_inquiry)%s_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)%s_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)%s_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject Py%s_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "%s_Array",
    sizeof(Py%s_ArrayObject),
    0,
    %s_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    %s_Array_compare,    /* tp_compare */
    %s_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &%s_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    %s_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    %s_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    %s_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    %s_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
Py%s_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&Py%s_Array_Type)<0) {
      printf("** PyType_Ready failed for: %s_Array\\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"%s_Array",
           (PyObject*)(&Py%s_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: %s_Array\\n");
       return -1;
    }
    return 0;
}

"""%args)

