
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
// Wrapper Implementation for Class: oaChar
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaChar_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaChar_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaCharObject* self = (PyoaCharObject*)gself;
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
    // Case: (oaChar)
    {
        PyParamoaChar p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaChar_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaChar, Choices are:\n"
        "    ()\n"
        "    (oaChar)\n"
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
oaChar_dealloc(PyObject* gself)
{
    PyoaCharObject* self = (PyoaCharObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaChar_str(PyObject *ob)
{
    PyParamoaChar value;
    int convert_status=PyoaChar_Convert(ob,&value);
    assert(convert_status!=0);
    char buffer[4];
    buffer[0]=value.Data();
    return PyString_FromStringAndSize(buffer,1);
}
// ------------------------------------------------------------------
static PyObject*
oaChar_repr(PyObject *ob)
{
    PyObject* str=oaChar_str(ob);
    PyObject* result=PyObject_Repr(str);
    Py_DECREF(str);
    return result;
}

// ------------------------------------------------------------------
static int
oaChar_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaChar v1;
    PyParamoaChar v2;
    int convert_status1=PyoaChar_Convert(ob1,&v1);
    int convert_status2=PyoaChar_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaChar_Convert(PyObject* ob,PyParamoaChar* result)
{
  if (ob == NULL) return 1;
  if (PyoaChar_Check(ob)) {
    result->SetData(((PyoaCharObject*)ob)->value);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    if (len!=1) {
      PyErr_SetString(PyExc_TypeError,
                      "string of length 1 required for oaChar");
      return 0;
    }
    result->GiveData(new oaChar(s[0]));
    return 1;
  }
  if (PyInt_Check(ob)) {
    long val = PyInt_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaChar value=oaChar(val);
    if ( ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaChar");
      return 0;
    }
    result->GiveData(new oaChar(value));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaChar Failed");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaChar_FromoaChar(const oaChar& value)
{
  PyObject* gself = PyoaChar_Type.tp_alloc(&PyoaChar_Type,0);
  if (gself == NULL) return gself;
  PyoaCharObject* self = (PyoaCharObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaChar_FromoaChar(oaChar* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaByte_Type.tp_alloc(&PyoaByte_Type,0);
  if (gself == NULL) return gself;
  PyoaCharObject* self = (PyoaCharObject*)gself;
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
static char oaChar_assign_doc[] =
"Class: oaChar, Function: assign\n"
"  Paramegers: (oaChar)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaChar_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaChar data;
    int convert_status=PyoaChar_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaChar p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaChar_Convert,&p1)) {
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
static char oaChar_str_doc[] =
"Class: oaChar, Function: str\n"
"  Paramegers: ()\n"
"    This function returns the current value as a str.\n"
;

static PyObject*
oaChar_str(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaChar data;
    int convert_status=PyoaChar_Convert(ob,&data);
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
static PyMethodDef oaChar_methodlist[] = {
    {"assign",(PyCFunction)oaChar_assign,METH_VARARGS,oaChar_assign_doc},
    {"str",(PyCFunction)oaChar_str,METH_VARARGS,oaChar_str_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaChar_doc[] =
"Class: oaChar\n"
"  The oaChar utility class a single char.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaChar()\n"
"    Signature: oaChar||\n"
"    This is the default constructor for the oaChar class. This constructor creates an empty oaChar.\n"
"  Paramegers: (oaChar)\n"
"    Calls: (const oaChar&)\n"
"    Signature: oaChar||cref-oaChar,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaChar_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaChar",
    sizeof(PyoaCharObject),
    0,
    oaChar_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaChar_compare,    /* tp_compare */
    oaChar_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaChar_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaChar_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaChar_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaChar_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaChar_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaChar_Type)<0) {
      printf("** PyType_Ready failed for: oaChar\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaChar",
           (PyObject*)(&PyoaChar_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaChar\n");
       return -1;
    }
    return 0;
}

