
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
// Wrapper Implementation for Class: oaByte_Array
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaByte_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaByte_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaByte_ArrayObject* self = (PyoaByte_ArrayObject*)gself;
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
    // Case: (oaByte_Array)
    {
        PyParamoaByte_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaByte_Array_Convert,&p1)) {
            self->data=p1;
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaByte_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaByte_Array)\n"
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
oaByte_Array_dealloc(PyObject* gself)
{
    PyoaByte_ArrayObject* self = (PyoaByte_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaByte_Array_str(PyObject *ob)
{
    PyParamoaByte_Array value;
    int convert_status=PyoaByte_Array_Convert(ob,&value);
    assert(convert_status!=0);
    return PyString_FromString((const char*)(value.Data()));
}
// ------------------------------------------------------------------
static PyObject*
oaByte_Array_repr(PyObject *ob)
{
    PyObject* str=oaByte_Array_str(ob);
    PyObject* result=PyObject_Repr(str);
    Py_DECREF(str);
    return result;
}

// ------------------------------------------------------------------
static int
oaByte_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaByte_Array v1;
    PyParamoaByte_Array v2;
    int convert_status1=PyoaByte_Array_Convert(ob1,&v1);
    int convert_status2=PyoaByte_Array_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    return strcmp((const char*)(v1.Data()),
      (const char*)(v2.Data()));
}

// ------------------------------------------------------------------
int
PyoaByte_Array_Convert(PyObject* ob,PyParamoaByte_Array* result)
{
  if (ob == NULL) return 1;
  if (PyoaByte_Array_Check(ob)) {
    PyoaByte_ArrayObject* self=(PyoaByte_ArrayObject*)ob;
    result->SetUse(self->data);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    result->SetUse((oaByte*)s,len);
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaByte_Array Failed");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaByte_Array_FromoaByte_Array(const oaByte_Array& value)
{
  PyObject* gself = PyoaByte_Array_Type.tp_alloc(&PyoaByte_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaByte_ArrayObject* self = (PyoaByte_ArrayObject*)gself;
  self->data = value;
  self->value= &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}
// ------------------------------------------------------------------
PyObject* PyoaByte_Array_FromoaByte_Array(const oaByte* value,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaByte_Array_Type.tp_alloc(&PyoaByte_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaByte_ArrayObject* self = (PyoaByte_ArrayObject*)gself;
  self->data.SetLen(len);
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
static char oaByte_Array_assign_doc[] =
"Class: oaByte_Array, Function: assign\n"
"  Paramegers: (oaByte_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaByte_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaByte_ArrayObject* self=(PyoaByte_ArrayObject*)ob;
  try {
    PyParamoaByte_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaByte_Array_Convert,&p1)) {
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
static char oaByte_Array_list_doc[] =
"Class: oaByte_Array, Function: str\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaByte_Array_list(PyObject* ob, PyObject *args)
{
  PyoaByte_ArrayObject* self=(PyoaByte_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      int i;
      PyObject* lst=PyList_New(self->data.Len());
      for(i=0;i<self->data.Len();i++) {
        PyObject* ob=PyoaByte_FromoaByte(self->data.Data()[i]);
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
static PyMethodDef oaByte_Array_methodlist[] = {
    {"assign",(PyCFunction)oaByte_Array_assign,METH_VARARGS,oaByte_Array_assign_doc},
    {"list",(PyCFunction)oaByte_Array_list,METH_VARARGS,oaByte_Array_list_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
// Sequenct Methods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static PyObject*
oaByte_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaByte_ArrayObject* self=(PyoaByte_ArrayObject*)ob;
  try {
    PyParamoaByte_Array data;
    int convert_status=PyoaByte_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaByte_FromoaByte(data.Data()[index]);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaByte_Array_index_get_length(PyObject* ob)
{
    PyParamoaByte_Array data;
    int convert_status=PyoaByte_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaByte_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaByte_Array data;
    PyParamoaByte dataitem;
    int convert_status=PyoaByte_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaByte_Convert(value,&dataitem)==0) return -1;
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
static char oaByte_Array_doc[] =
"Class: oaByte_Array\n"
"  The oaByte_Array utility class provides an array of bytes.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaByte_Array()\n"
"    Signature: oaByte_Array||\n"
"    This is the default constructor for the oaByte_Array class. This constructor creates an empty oaByte_Array.\n"
"  Paramegers: (oaByte_Array)\n"
"    Calls: (const oaByte_Array&)\n"
"    Signature: oaByte_Array||cref-oaByte_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaByte_Array_as_sequence = {
    (Pyoa_inquiry)oaByte_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaByte_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaByte_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaByte_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaByte_Array",
    sizeof(PyoaByte_ArrayObject),
    0,
    oaByte_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaByte_Array_compare,    /* tp_compare */
    oaByte_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaByte_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaByte_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaByte_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaByte_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaByte_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaByte_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaByte_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaByte_Array\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaByte_Array",
           (PyObject*)(&PyoaByte_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaByte_Array\n");
       return -1;
    }
    return 0;
}

