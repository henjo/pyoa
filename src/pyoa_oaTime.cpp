
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
#include <math.h>

// ==================================================================
// Wrapper Implementation for Class: oaTime
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaTime_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaTime_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaTimeObject* self = (PyoaTimeObject*)gself;
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
    // Case: (oaTime)
    {
        PyParamoaTime p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaTime_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaTime, Choices are:\n"
        "    ()\n"
        "    (oaTime)\n"
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
oaTime_dealloc(PyObject* gself)
{
    PyoaTimeObject* self = (PyoaTimeObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaTime_repr(PyObject *ob)
{
    PyParamoaTime value;
    int convert_status=PyoaTime_Convert(ob,&value);
    assert(convert_status!=0);
    double dvalue=(double)(value.Data());
    PyObject* ivalue=PyFloat_FromDouble(dvalue);
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaTime_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaTime v1;
    PyParamoaTime v2;
    int convert_status1=PyoaTime_Convert(ob1,&v1);
    int convert_status2=PyoaTime_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaTime_Convert(PyObject* ob,PyParamoaTime* result)
{
  if (ob == NULL) return 1;
  if (PyoaTime_Check(ob)) {
    result->SetData(((PyoaTimeObject*)ob)->value);
    return 1;
  }
  double val = PyFloat_AsDouble(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  oaTime value(floor(val));
  result->GiveData(new oaTime(value));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaTime_FromoaTime(const oaTime& value)
{
  PyObject* gself = PyoaTime_Type.tp_alloc(&PyoaTime_Type,0);
  if (gself == NULL) return gself;
  PyoaTimeObject* self = (PyoaTimeObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaTime_FromoaTime(oaTime* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaTime_Type.tp_alloc(&PyoaTime_Type,0);
  if (gself == NULL) return gself;
  PyoaTimeObject* self = (PyoaTimeObject*)gself;
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
static char oaTime_assign_doc[] =
"Class: oaTime, Function: assign\n"
"  Paramegers: (oaTime)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaTime_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTime data;
    int convert_status=PyoaTime_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaTime p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaTime_Convert,&p1)) {
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
static char oaTime_float_doc[] =
"Class: oaTime, Function: float\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaTime_float(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTime data;
    int convert_status=PyoaTime_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyFloat_FromDouble((double)(data.Data()));
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
static PyMethodDef oaTime_methodlist[] = {
    {"assign",(PyCFunction)oaTime_assign,METH_VARARGS,oaTime_assign_doc},
    {"float",(PyCFunction)oaTime_float,METH_VARARGS,oaTime_float_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaTime_nonzero(PyObject* ob)
{
  PyParamoaTime p;
  int s=PyoaTime_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaTime_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaTime p1;
  int s1=PyoaTime_Convert(*ob1,&p1);
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
static PyObject* oaTime_int(PyObject* ob)
{
  PyParamoaTime p;
  int s=PyoaTime_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaTime_long(PyObject* ob)
{
  PyParamoaTime p;
  int s=PyoaTime_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaTime_float(PyObject* ob)
{
  PyParamoaTime p;
  int s=PyoaTime_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaTimeAsNumber = {
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
  (inquiry)oaTime_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaTime_coerce, /*nb_coerce*/
  (unaryfunc)oaTime_int, /*nb_int*/
  (unaryfunc)oaTime_long, /*nb_long*/
  (unaryfunc)oaTime_float, /*nb_float*/
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
static char oaTime_doc[] =
"Class: oaTime\n"
"  The oaTime utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaTime()\n"
"    Signature: oaTime||\n"
"    This is the default constructor for the oaTime class. This constructor creates a zero valued oaTime.\n"
"  Paramegers: (oaTime)\n"
"    Calls: (const oaTime&)\n"
"    Signature: oaTime||cref-oaTime,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaTime_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaTime",
    sizeof(PyoaTimeObject),
    0,
    oaTime_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaTime_compare,    /* tp_compare */
    oaTime_repr,      /* tp_repr */
    &oaTimeAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaTime_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaTime_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaTime_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaTime_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaTime_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaTime_Type)<0) {
      printf("** PyType_Ready failed for: oaTime\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaTime",
           (PyObject*)(&PyoaTime_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaTime\n");
       return -1;
    }
    return 0;
}

