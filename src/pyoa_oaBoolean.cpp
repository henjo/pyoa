
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
// Wrapper Implementation for Class: oaBoolean
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBoolean_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBoolean_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaBooleanObject* self = (PyoaBooleanObject*)gself;
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
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBoolean_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBoolean, Choices are:\n"
        "    ()\n"
        "    (oaBoolean)\n"
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
oaBoolean_dealloc(PyObject* gself)
{
    PyoaBooleanObject* self = (PyoaBooleanObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaBoolean_repr(PyObject *ob)
{
    PyParamoaBoolean value;
    int convert_status=PyoaBoolean_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyInt_FromLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaBoolean_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBoolean v1;
    PyParamoaBoolean v2;
    int convert_status1=PyoaBoolean_Convert(ob1,&v1);
    int convert_status2=PyoaBoolean_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v1.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaBoolean_Convert(PyObject* ob,PyParamoaBoolean* result)
{
  if (ob == NULL) return 1;
  if (PyoaBoolean_Check(ob)) {
    result->SetData(((PyoaBooleanObject*)ob)->value);
    return 1;
  }
  long val = PyInt_AsLong(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  oaBoolean value=oaBoolean(val);
  if (  ((long) value) != val) {
    PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaBoolean");
    return 0;
  }
  result->GiveData(new oaBoolean(value));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaBoolean_FromoaBoolean(const oaBoolean& value)
{
  PyObject* gself = PyoaBoolean_Type.tp_alloc(&PyoaBoolean_Type,0);
  if (gself == NULL) return gself;
  PyoaBooleanObject* self = (PyoaBooleanObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaBoolean_FromoaBoolean(oaBoolean* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaBoolean_Type.tp_alloc(&PyoaBoolean_Type,0);
  if (gself == NULL) return gself;
  PyoaBooleanObject* self = (PyoaBooleanObject*)gself;
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
static char oaBoolean_assign_doc[] =
"Class: oaBoolean, Function: assign\n"
"  Paramegers: (oaBoolean)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaBoolean_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBoolean data;
    int convert_status=PyoaBoolean_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBoolean_Convert,&p1)) {
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
static char oaBoolean_int_doc[] =
"Class: oaBoolean, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaBoolean_int(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBoolean data;
    int convert_status=PyoaBoolean_Convert(ob,&data);
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
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaBoolean_methodlist[] = {
    {"assign",(PyCFunction)oaBoolean_assign,METH_VARARGS,oaBoolean_assign_doc},
    {"int",(PyCFunction)oaBoolean_int,METH_VARARGS,oaBoolean_int_doc},
   {NULL,NULL,0,NULL}
};

// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaBoolean_nonzero(PyObject* ob)
{
  PyParamoaBoolean p;
  int s=PyoaBoolean_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaBoolean_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaBoolean p1;
  int s1=PyoaBoolean_Convert(*ob1,&p1);
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
static PyObject* oaBoolean_int(PyObject* ob)
{
  PyParamoaBoolean p;
  int s=PyoaBoolean_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaBoolean_long(PyObject* ob)
{
  PyParamoaBoolean p;
  int s=PyoaBoolean_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaBoolean_float(PyObject* ob)
{
  PyParamoaBoolean p;
  int s=PyoaBoolean_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaBooleanAsNumber = {
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
  (inquiry)oaBoolean_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaBoolean_coerce, /*nb_coerce*/
  (unaryfunc)oaBoolean_int, /*nb_int*/
  (unaryfunc)oaBoolean_long, /*nb_long*/
  (unaryfunc)oaBoolean_float, /*nb_float*/
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
static char oaBoolean_doc[] =
"Class: oaBoolean\n"
"  The oaBoolean utility class represents 1 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean()\n"
"    Signature: oaBoolean||\n"
"    This is the default constructor for the oaBoolean class. This constructor creates a zero valued oaBoolean.\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: (const oaBoolean&)\n"
"    Signature: oaBoolean||cref-oaBoolean,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBoolean_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBoolean",
    sizeof(PyoaBooleanObject),
    0,
    oaBoolean_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaBoolean_compare,    /* tp_compare */
    oaBoolean_repr,      /* tp_repr */
    &oaBooleanAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaBoolean_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBoolean_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaBoolean_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaBoolean_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBoolean_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBoolean_Type)<0) {
      printf("** PyType_Ready failed for: oaBoolean\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBoolean",
           (PyObject*)(&PyoaBoolean_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBoolean\n");
       return -1;
    }
    return 0;
}

