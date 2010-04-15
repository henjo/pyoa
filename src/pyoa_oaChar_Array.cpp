
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

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaChar_Array
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaChar_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaChar_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaChar_ArrayObject* self = (PyoaChar_ArrayObject*)gself;
    self->value = &(self->data);
    self->borrow = 0;
    self->locks=NULL;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            return gself;
        }
    }
    PyErr_Clear();
    // Case: (int)
    {
        int p1;
        if (PyArg_ParseTuple(args,(char*)"i",&p1)) {
            self->data.SetLen(p1);
            return gself;
        }
    }
    PyErr_Clear();
    // Case: (oaChar_Array)
    {
        PyParamoaChar_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaChar_Array_Convert,&p1)) {
            self->data=p1;
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaChar_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaChar_Array)\n"
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
oaChar_Array_dealloc(PyObject* gself)
{
    PyoaChar_ArrayObject* self = (PyoaChar_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaChar_Array_str(PyObject *ob)
{
    PyParamoaChar_Array value;
    int convert_status=PyoaChar_Array_Convert(ob,&value);
    assert(convert_status!=0);
    return PyString_FromString(value.Data());
}
// ------------------------------------------------------------------
static PyObject*
oaChar_Array_repr(PyObject *ob)
{
    PyObject* str=oaChar_Array_str(ob);
    PyObject* result=PyObject_Repr(str);
    Py_DECREF(str);
    return result;
}

// ------------------------------------------------------------------
static int
oaChar_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaChar_Array v1;
    PyParamoaChar_Array v2;
    int convert_status1=PyoaChar_Array_Convert(ob1,&v1);
    int convert_status2=PyoaChar_Array_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    return strcmp(v1.Data(),v2.Data());
}

// ------------------------------------------------------------------
int
PyoaChar_Array_Convert(PyObject* ob,PyParamoaChar_Array* result)
{
  if (ob == NULL) return 1;
  if (PyoaChar_Array_Check(ob)) {
    PyoaChar_ArrayObject* self=(PyoaChar_ArrayObject*)ob;
    result->SetUse(self->data);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    result->SetUse(s,len);
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaChar_Array Failed");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaChar_Array_FromoaChar_Array(const oaChar_Array& value)
{
  PyObject* gself = PyoaChar_Array_Type.tp_alloc(&PyoaChar_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaChar_ArrayObject* self = (PyoaChar_ArrayObject*)gself;
  self->data = value;
  self->value= &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaChar_Array_FromoaChar_Array(const oaChar* value,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaChar_Array_Type.tp_alloc(&PyoaChar_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaChar_ArrayObject* self = (PyoaChar_ArrayObject*)gself;
  self->data.SetLen(strlen(value));
  self->data.Copy(value);
  self->value= &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaChar_Array_assign_doc[] =
"Class: oaChar_Array, Function: assign\n"
"  Paramegers: (oaChar_Array)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaChar_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaChar_ArrayObject* self=(PyoaChar_ArrayObject*)ob;
  try {
    PyParamoaChar_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaChar_Array_Convert,&p1)) {
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
static char oaChar_Array_list_doc[] =
"Class: oaChar_Array, Function: str\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaChar_Array_list(PyObject* ob, PyObject *args)
{
  PyoaChar_ArrayObject* self=(PyoaChar_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      int i;
      PyObject* lst=PyList_New(self->data.Len());
      for(i=0;i<self->data.Len();i++) {
        PyObject* ob=PyoaChar_FromoaChar(self->data.Data()[i]);
        PyList_SetItem(lst,i,ob);
      }
      return lst;
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
static PyMethodDef oaChar_Array_methodlist[] = {
    {"assign",(PyCFunction)oaChar_Array_assign,METH_VARARGS,oaChar_Array_assign_doc},
    {"list",(PyCFunction)oaChar_Array_list,METH_VARARGS,oaChar_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
// Sequenct Methods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static PyObject*
oaChar_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaChar_ArrayObject* self=(PyoaChar_ArrayObject*)ob;
  try {
    PyParamoaChar_Array data;
    int convert_status=PyoaChar_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaChar_FromoaChar(data.Data()[index]);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaChar_Array_index_get_length(PyObject* ob)
{
    PyParamoaChar_Array data;
    int convert_status=PyoaChar_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaChar_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaChar_Array data;
    PyParamoaChar dataitem;
    int convert_status=PyoaChar_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaChar_Convert(value,&dataitem)==0) return -1;
    data.Data()[index]=dataitem.Data();
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaChar_Array_doc[] =
"Class: oaChar_Array\n"
"  The oaChar_Array utility class provides an array of charaters.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaChar_Array()\n"
"    Signature: oaChar_Array||\n"
"    This is the default constructor for the oaChar_Array class. This constructor creates an empty oaChar_Array.\n"
"  Paramegers: (oaChar_Array)\n"
"    Calls: (const oaChar_Array&)\n"
"    Signature: oaChar_Array||cref-oaChar_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaChar_Array_as_sequence = {
    (Pyoa_inquiry)oaChar_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaChar_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaChar_Array_index_set,      /* sq_ass_item */
};
// ------------------------------------------------------------------
PyTypeObject PyoaChar_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaChar_Array",
    sizeof(PyoaChar_ArrayObject),
    0,
    oaChar_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaChar_Array_compare,    /* tp_compare */
    oaChar_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaChar_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaChar_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaChar_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaChar_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaChar_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaChar_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaChar_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaChar_Array\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaChar_Array",
           (PyObject*)(&PyoaChar_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaChar_Array\n");
       return -1;
    }
    return 0;
}

