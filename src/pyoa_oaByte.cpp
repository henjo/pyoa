
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
// Wrapper Implementation for Class: oaByte
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaByte_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaByte_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaByteObject* self = (PyoaByteObject*)gself;
    self->data = '\0';
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
    // Case: (oaByte)
    {
        PyParamoaByte p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaByte_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaByte, Choices are:\n"
        "    ()\n"
        "    (oaByte)\n"
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
oaByte_dealloc(PyObject* gself)
{
    PyoaByteObject* self = (PyoaByteObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaByte_str(PyObject *ob)
{
    PyParamoaByte value;
    int convert_status=PyoaByte_Convert(ob,&value);
    assert(convert_status!=0);
    char buffer[4];
    buffer[0]=value.Data();
    return PyString_FromStringAndSize(buffer,1);
}
// ------------------------------------------------------------------
static PyObject*
oaByte_repr(PyObject *ob)
{
    PyObject* str=oaByte_str(ob);
    return PyObject_Repr(str);
}

// ------------------------------------------------------------------
static int
oaByte_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaByte v1;
    PyParamoaByte v2;
    int convert_status1=PyoaByte_Convert(ob1,&v1);
    int convert_status2=PyoaByte_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaByte_Convert(PyObject* ob,PyParamoaByte* result)
{
  if (ob == NULL) return 1;
  if (PyoaByte_Check(ob)) {
    result->SetData(((PyoaByteObject*)ob)->value);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    if (len!=1) {
      PyErr_SetString(PyExc_TypeError,
                      "string of length 1 required for oaByte");
      return 0;
    }
    result->GiveData(new oaByte(s[0]));
    return 1;
  }
  if (PyInt_Check(ob)) {
    long val = PyInt_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaByte value=oaByte(val);
    if ( ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaByte");
      return 0;
    }
    result->GiveData(new oaByte(value));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaByte Failed");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaByte_FromoaByte(const oaByte& value)
{
  PyObject* gself = PyoaByte_Type.tp_alloc(&PyoaByte_Type,0);
  if (gself == NULL) return gself;
  PyoaByteObject* self = (PyoaByteObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaByte_FromoaByte(oaByte* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaByte_Type.tp_alloc(&PyoaByte_Type,0);
  if (gself == NULL) return gself;
  PyoaByteObject* self = (PyoaByteObject*)gself;
  self->data = 0;
  self->value = value;
  self->borrow = 0;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaByte_assign_doc[] =
"Class: oaByte, Function: assign\n"
"  Paramegers: (oaByte)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaByte_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaByte data;
    int convert_status=PyoaByte_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaByte p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaByte_Convert,&p1)) {
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
// ------------------------------------------------------------------
static char oaByte_str_doc[] =
"Class: oaByte, Function: str\n"
"  Paramegers: ()\n"
"    This function returns the current value as a str.\n"
;

static PyObject*
oaByte_str(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaByte data;
    int convert_status=PyoaByte_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      char buffer[4];
      buffer[0]=data.Data();
      buffer[1]='\0';
      return PyString_FromStringAndSize(buffer,1);
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
static PyMethodDef oaByte_methodlist[] = {
    {"assign",(PyCFunction)oaByte_assign,METH_VARARGS,oaByte_assign_doc},
    {"str",(PyCFunction)oaByte_str,METH_VARARGS,oaByte_str_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaByte_doc[] =
"Class: oaByte\n"
"  The oaByte utility class provides a single byte.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaByte()\n"
"    Signature: oaByte||\n"
"    This is the default constructor for the oaByte class. This constructor creates an empty oaByte.\n"
"  Paramegers: (oaByte)\n"
"    Calls: (const oaByte&)\n"
"    Signature: oaByte||cref-oaByte,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaByte_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaByte",
    sizeof(PyoaByteObject),
    0,
    oaByte_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaByte_compare,    /* tp_compare */
    oaByte_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaByte_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaByte_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaByte_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaByte_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaByte_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaByte_Type)<0) {
      printf("** PyType_Ready failed for: oaByte\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaByte",
           (PyObject*)(&PyoaByte_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaByte\n");
       return -1;
    }
    return 0;
}

