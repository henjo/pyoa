
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
// Wrapper Implementation for Class: oaUInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaUInt4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaUInt4_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaUInt4Object* self = (PyoaUInt4Object*)gself;
    self->data = 0;
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
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaUInt4, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
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
oaUInt4_dealloc(PyObject* gself)
{
    PyoaUInt4Object* self = (PyoaUInt4Object*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaUInt4_repr(PyObject *ob)
{
    PyParamoaUInt4 value;
    int convert_status=PyoaUInt4_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyLong_FromUnsignedLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaUInt4_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaUInt4 v1;
    PyParamoaUInt4 v2;
    int convert_status1=PyoaUInt4_Convert(ob1,&v1);
    int convert_status2=PyoaUInt4_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}


// ------------------------------------------------------------------
int
PyoaUInt4_Convert(PyObject* ob,PyParamoaUInt4* result)
{
  if (ob == NULL) return 1;
  if (PyoaUInt4_Check(ob)) {
    result->SetData(((PyoaUInt4Object*)ob)->value);
    return 1;
  }
  if (PyInt_Check(ob)) {
    unsigned long val = PyInt_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaUInt4 value=oaUInt4(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaUInt4");
      return 0;
    }
    result->GiveData(new oaUInt4(value));
    return 1;
  }
  if (PyLong_Check(ob)) {
    unsigned long val = PyLong_AsUnsignedLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaUInt4 value=oaUInt4(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaUInt4");
      return 0;
    }
    result->GiveData(new oaUInt4(value));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
                  "cann't convert object to oaUInt4");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaUInt4_FromoaUInt4(const oaUInt4& value)
{
  PyObject* gself = PyoaUInt4_Type.tp_alloc(&PyoaUInt4_Type,0);
  if (gself == NULL) return gself;
  PyoaUInt4Object* self = (PyoaUInt4Object*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaUInt4_FromoaUInt4(oaUInt4* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaUInt4_Type.tp_alloc(&PyoaUInt4_Type,0);
  if (gself == NULL) return gself;
  PyoaUInt4Object* self = (PyoaUInt4Object*)gself;
  self->data = 0;
  self->value = value;
  self->borrow = borrow;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaUInt4_assign_doc[] =
"Class: oaUInt4, Function: assign\n"
"  Paramegers: (oaUInt4)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaUInt4_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaUInt4 data;
    int convert_status=PyoaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaUInt4_Convert,&p1)) {
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
static char oaUInt4_int_doc[] =
"Class: oaUInt4, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaUInt4_int(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaUInt4 data;
    int convert_status=PyoaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyInt_FromLong(data.Data());
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
static char oaUInt4_long_doc[] =
"Class: oaUInt4, Function: long\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaUInt4_long(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaUInt4 data;
    int convert_status=PyoaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyLong_FromUnsignedLong(data.Data());
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
static PyMethodDef oaUInt4_methodlist[] = {
    {"assign",(PyCFunction)oaUInt4_assign,METH_VARARGS,oaUInt4_assign_doc},
    {"int",(PyCFunction)oaUInt4_int,METH_VARARGS,oaUInt4_int_doc},
    {"long",(PyCFunction)oaUInt4_long,METH_VARARGS,oaUInt4_long_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaUInt4_nonzero(PyObject* ob)
{
  PyParamoaUInt4 p;
  int s=PyoaUInt4_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaUInt4_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaUInt4 p1;
  int s1=PyoaUInt4_Convert(*ob1,&p1);
  if (s1==0) return 1;
  if (PyInt_Check(*ob2)) {
    *ob1 = PyInt_FromLong(p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  else if (PyLong_Check(*ob2)) {
    *ob1 = PyLong_FromUnsignedLong(p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  else if (PyFloat_Check(*ob2)) {
    *ob1 = PyFloat_FromDouble((double)p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  return 1; /* Can't do it */
}
// -----------------------------------------------------
static PyObject* oaUInt4_int(PyObject* ob)
{
  PyParamoaUInt4 p;
  int s=PyoaUInt4_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaUInt4_long(PyObject* ob)
{
  PyParamoaUInt4 p;
  int s=PyoaUInt4_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromUnsignedLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaUInt4_float(PyObject* ob)
{
  PyParamoaUInt4 p;
  int s=PyoaUInt4_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaUInt4AsNumber = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  (inquiry)oaUInt4_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaUInt4_coerce, /*nb_coerce*/
  (unaryfunc)oaUInt4_int, /*nb_int*/
  (unaryfunc)oaUInt4_long, /*nb_long*/
  (unaryfunc)oaUInt4_float, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/

  0, /*ng_inplace_add*/
  0, /*ng_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/

  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
};

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaUInt4_doc[] =
"Class: oaUInt4\n"
"  The oaUInt4 utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4()\n"
"    Signature: oaUInt4||\n"
"    This is the default constructor for the oaUInt4 class. This constructor creates a zero valued oaUInt4.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: (const oaUInt4&)\n"
"    Signature: oaUInt4||cref-oaUInt4,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaUInt4_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaUInt4",
    sizeof(PyoaUInt4Object),
    0,
    oaUInt4_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaUInt4_compare,    /* tp_compare */
    oaUInt4_repr,      /* tp_repr */
    &oaUInt4AsNumber,   /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaUInt4_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaUInt4_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaUInt4_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaUInt4_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaUInt4_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaUInt4_Type)<0) {
      printf("** PyType_Ready failed for: oaUInt4\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaUInt4",
           (PyObject*)(&PyoaUInt4_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaUInt4\n");
       return -1;
    }
    return 0;
}

