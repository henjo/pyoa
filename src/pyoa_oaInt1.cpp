
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
// Wrapper Implementation for Class: oaInt1
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInt1_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInt1_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaInt1Object* self = (PyoaInt1Object*)gself;
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
    // Case: (oaInt1)
    {
        PyParamoaInt1 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInt1_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaInt1, Choices are:\n"
        "    ()\n"
        "    (oaInt1)\n"
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
oaInt1_dealloc(PyObject* gself)
{
    PyoaInt1Object* self = (PyoaInt1Object*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaInt1_repr(PyObject *ob)
{
    PyParamoaInt1 value;
    int convert_status=PyoaInt1_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyInt_FromLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaInt1_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInt1 v1;
    PyParamoaInt1 v2;
    int convert_status1=PyoaInt1_Convert(ob1,&v1);
    int convert_status2=PyoaInt1_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaInt1_Convert(PyObject* ob,PyParamoaInt1* result)
{
  if (ob == NULL) return 1;
  if (PyoaInt1_Check(ob)) {
    result->SetData(((PyoaInt1Object*)ob)->value);
    return 1;
  }
  long val = PyInt_AsLong(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  oaInt1 value=oaInt1(val);
  if (  ((long) value) != val) {
    PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaInt1");
    return 0;
  }
  result->GiveData(new oaInt1(value));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaInt1_FromoaInt1(const oaInt1& value)
{
  PyObject* gself = PyoaInt1_Type.tp_alloc(&PyoaInt1_Type,0);
  if (gself == NULL) return gself;
  PyoaInt1Object* self = (PyoaInt1Object*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaInt1_FromoaInt1(oaInt1* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaInt1_Type.tp_alloc(&PyoaInt1_Type,0);
  if (gself == NULL) return gself;
  PyoaInt1Object* self = (PyoaInt1Object*)gself;
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
static char oaInt1_assign_doc[] =
"Class: oaInt1, Function: assign\n"
"  Paramegers: (oaInt1)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaInt1_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInt1 data;
    int convert_status=PyoaInt1_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaInt1 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInt1_Convert,&p1)) {
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
static char oaInt1_int_doc[] =
"Class: oaInt1, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaInt1_int(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInt1 data;
    int convert_status=PyoaInt1_Convert(ob,&data);
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
static PyMethodDef oaInt1_methodlist[] = {
    {"assign",(PyCFunction)oaInt1_assign,METH_VARARGS,oaInt1_assign_doc},
    {"int",(PyCFunction)oaInt1_int,METH_VARARGS,oaInt1_int_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaInt1_nonzero(PyObject* ob)
{
  PyParamoaInt1 p;
  int s=PyoaInt1_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaInt1_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaInt1 p1;
  int s1=PyoaInt1_Convert(*ob1,&p1);
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
static PyObject* oaInt1_int(PyObject* ob)
{
  PyParamoaInt1 p;
  int s=PyoaInt1_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaInt1_long(PyObject* ob)
{
  PyParamoaInt1 p;
  int s=PyoaInt1_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaInt1_float(PyObject* ob)
{
  PyParamoaInt1 p;
  int s=PyoaInt1_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaInt1AsNumber = {
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
  (inquiry)oaInt1_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaInt1_coerce, /*nb_coerce*/
  (unaryfunc)oaInt1_int, /*nb_int*/
  (unaryfunc)oaInt1_long, /*nb_long*/
  (unaryfunc)oaInt1_float, /*nb_float*/
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
static char oaInt1_doc[] =
"Class: oaInt1\n"
"  The oaInt1 utility class represents 1 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaInt1()\n"
"    Signature: oaInt1||\n"
"    This is the default constructor for the oaInt1 class. This constructor creates a zero valued oaInt1.\n"
"  Paramegers: (oaInt1)\n"
"    Calls: (const oaInt1&)\n"
"    Signature: oaInt1||cref-oaInt1,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInt1_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInt1",
    sizeof(PyoaInt1Object),
    0,
    oaInt1_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaInt1_compare,    /* tp_compare */
    oaInt1_repr,      /* tp_repr */
    &oaInt1AsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaInt1_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInt1_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaInt1_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaInt1_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInt1_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInt1_Type)<0) {
      printf("** PyType_Ready failed for: oaInt1\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInt1",
           (PyObject*)(&PyoaInt1_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInt1\n");
       return -1;
    }
    return 0;
}

