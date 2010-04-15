
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
// Wrapper Implementation for Class: oaOffset = oaInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOffset_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOffset_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaOffsetObject* self = (PyoaOffsetObject*)gself;
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
    // Case: (oaOffset)
    {
        PyParamoaOffset p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOffset_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaOffset, Choices are:\n"
        "    ()\n"
        "    (oaOffset)\n"
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
oaOffset_dealloc(PyObject* gself)
{
    PyoaOffsetObject* self = (PyoaOffsetObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaOffset_repr(PyObject *ob)
{
    PyParamoaOffset value;
    int convert_status=PyoaOffset_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyLong_FromLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaOffset_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOffset v1;
    PyParamoaOffset v2;
    int convert_status1=PyoaOffset_Convert(ob1,&v1);
    int convert_status2=PyoaOffset_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaOffset_Convert(PyObject* ob,PyParamoaOffset* result)
{
  if (ob == NULL) return 1;
  if (PyoaOffset_Check(ob)) {
    result->SetData(((PyoaOffsetObject*)ob)->value);
    return 1;
  }
  if (PyInt_Check(ob)) {
    long val = PyInt_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaOffset value=oaOffset(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaOffset");
      return 0;
    }
    result->GiveData(new oaOffset(value));
    return 1;
  }
  if (PyLong_Check(ob)) {
    long val = PyLong_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaOffset value=oaOffset(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaOffset");
      return 0;
    }
    result->GiveData(new oaOffset(value));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
                  "cann't convert object to oaOffset");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaOffset_FromoaOffset(const oaOffset& value)
{
  PyObject* gself = PyoaOffset_Type.tp_alloc(&PyoaOffset_Type,0);
  if (gself == NULL) return gself;
  PyoaOffsetObject* self = (PyoaOffsetObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaOffset_FromoaOffset(oaOffset* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaOffset_Type.tp_alloc(&PyoaOffset_Type,0);
  if (gself == NULL) return gself;
  PyoaOffsetObject* self = (PyoaOffsetObject*)gself;
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
static char oaOffset_assign_doc[] =
"Class: oaOffset, Function: assign\n"
"  Paramegers: (oaOffset)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaOffset_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOffset data;
    int convert_status=PyoaOffset_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaOffset p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOffset_Convert,&p1)) {
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
static char oaOffset_int_doc[] =
"Class: oaOffset, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaOffset_int(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOffset data;
    int convert_status=PyoaOffset_Convert(ob,&data);
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
static char oaOffset_long_doc[] =
"Class: oaOffset, Function: long\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaOffset_long(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOffset data;
    int convert_status=PyoaOffset_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyLong_FromLong(data.Data());
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
static PyMethodDef oaOffset_methodlist[] = {
    {"assign",(PyCFunction)oaOffset_assign,METH_VARARGS,oaOffset_assign_doc},
    {"int",(PyCFunction)oaOffset_int,METH_VARARGS,oaOffset_int_doc},
    {"long",(PyCFunction)oaOffset_long,METH_VARARGS,oaOffset_long_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaOffset_nonzero(PyObject* ob)
{
  PyParamoaOffset p;
  int s=PyoaOffset_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaOffset_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaOffset p1;
  int s1=PyoaOffset_Convert(*ob1,&p1);
  if (s1==0) return 1;
  if (PyInt_Check(*ob2)) {
    *ob1 = PyInt_FromLong(p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  else if (PyLong_Check(*ob2)) {
    *ob1 = PyLong_FromLong(p1.Data());
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
static PyObject* oaOffset_int(PyObject* ob)
{
  PyParamoaOffset p;
  int s=PyoaOffset_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaOffset_long(PyObject* ob)
{
  PyParamoaOffset p;
  int s=PyoaOffset_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaOffset_float(PyObject* ob)
{
  PyParamoaOffset p;
  int s=PyoaOffset_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaOffsetAsNumber = {
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
  (inquiry)oaOffset_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaOffset_coerce, /*nb_coerce*/
  (unaryfunc)oaOffset_int, /*nb_int*/
  (unaryfunc)oaOffset_long, /*nb_long*/
  (unaryfunc)oaOffset_float, /*nb_float*/
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
static char oaOffset_doc[] =
"Class: oaOffset\n"
"  The oaOffset utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaOffset()\n"
"    Signature: oaOffset||\n"
"    This is the default constructor for the oaOffset class. This constructor creates a zero valued oaOffset.\n"
"  Paramegers: (oaOffset)\n"
"    Calls: (const oaOffset&)\n"
"    Signature: oaOffset||cref-oaOffset,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOffset_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOffset",
    sizeof(PyoaOffsetObject),
    0,
    oaOffset_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaOffset_compare,    /* tp_compare */
    oaOffset_repr,      /* tp_repr */
    &oaOffsetAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaOffset_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOffset_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaOffset_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaOffset_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOffset_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOffset_Type)<0) {
      printf("** PyType_Ready failed for: oaOffset\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOffset",
           (PyObject*)(&PyoaOffset_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOffset\n");
       return -1;
    }
    return 0;
}

