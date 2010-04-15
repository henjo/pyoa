
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
// Wrapper Implementation for Class: oaUInt8
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaUInt8_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaUInt8_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaUInt8Object* self = (PyoaUInt8Object*)gself;
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
    // Case: (oaUInt8)
    {
        PyParamoaUInt8 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt8_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaUInt8, Choices are:\n"
        "    ()\n"
        "    (oaUInt8)\n"
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
oaUInt8_dealloc(PyObject* gself)
{
    PyoaUInt8Object* self = (PyoaUInt8Object*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaUInt8_repr(PyObject *ob)
{
    PyParamoaUInt8 value;
    int convert_status=PyoaUInt8_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyLong_FromUnsignedLongLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaUInt8_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaUInt8 v1;
    PyParamoaUInt8 v2;
    int convert_status1=PyoaUInt8_Convert(ob1,&v1);
    int convert_status2=PyoaUInt8_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaUInt8_Convert(PyObject* ob,PyParamoaUInt8* result)
{
  if (ob == NULL) return 1;
  if (PyoaUInt8_Check(ob)) {
    result->SetData(((PyoaUInt8Object*)ob)->value);
    return 1;
  }
  unsigned PYOA_LONG_LONG val = PyLong_AsUnsignedLongLong(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  oaUInt8 value=oaUInt8(val);
  if (  ((unsigned PYOA_LONG_LONG) value) != val) {
    PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaUInt8");
    return 0;
  }
  result->GiveData(new oaUInt8(value));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaUInt8_FromoaUInt8(const oaUInt8& value)
{
  PyObject* gself = PyoaUInt8_Type.tp_alloc(&PyoaUInt8_Type,0);
  if (gself == NULL) return gself;
  PyoaUInt8Object* self = (PyoaUInt8Object*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaUInt8_FromoaUInt8(oaUInt8* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaUInt8_Type.tp_alloc(&PyoaUInt8_Type,0);
  if (gself == NULL) return gself;
  PyoaUInt8Object* self = (PyoaUInt8Object*)gself;
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
static char oaUInt8_assign_doc[] =
"Class: oaUInt8, Function: assign\n"
"  Paramegers: (oaUInt8)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaUInt8_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaUInt8 data;
    int convert_status=PyoaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaUInt8 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaUInt8_Convert,&p1)) {
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
static char oaUInt8_long_doc[] =
"Class: oaUInt8, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaUInt8_long(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaUInt8 data;
    int convert_status=PyoaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyLong_FromUnsignedLongLong(data.Data());
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
static PyMethodDef oaUInt8_methodlist[] = {
    {"assign",(PyCFunction)oaUInt8_assign,METH_VARARGS,oaUInt8_assign_doc},
    {"long",(PyCFunction)oaUInt8_long,METH_VARARGS,oaUInt8_long_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaUInt8_nonzero(PyObject* ob)
{
  PyParamoaUInt8 p;
  int s=PyoaUInt8_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaUInt8_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaUInt8 p1;
  int s1=PyoaUInt8_Convert(*ob1,&p1);
  if (s1==0) return 1;
  else if (PyLong_Check(*ob2)) {
    *ob1 = PyLong_FromUnsignedLongLong(p1.Data());
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
static PyObject* oaUInt8_long(PyObject* ob)
{
  PyParamoaUInt8 p;
  int s=PyoaUInt8_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromUnsignedLongLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaUInt8_float(PyObject* ob)
{
  PyParamoaUInt8 p;
  int s=PyoaUInt8_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaUInt8AsNumber = {
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
  (inquiry)oaUInt8_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaUInt8_coerce, /*nb_coerce*/
  0, /*nb_int*/
  (unaryfunc)oaUInt8_long, /*nb_long*/
  (unaryfunc)oaUInt8_float, /*nb_float*/
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
static char oaUInt8_doc[] =
"Class: oaUInt8\n"
"  The oaUInt8 utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8()\n"
"    Signature: oaUInt8||\n"
"    This is the default constructor for the oaUInt8 class. This constructor creates a zero valued oaUInt8.\n"
"  Paramegers: (oaUInt8)\n"
"    Calls: (const oaUInt8&)\n"
"    Signature: oaUInt8||cref-oaUInt8,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaUInt8_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaUInt8",
    sizeof(PyoaUInt8Object),
    0,
    oaUInt8_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaUInt8_compare,    /* tp_compare */
    oaUInt8_repr,      /* tp_repr */
    &oaUInt8AsNumber,   /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaUInt8_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaUInt8_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaUInt8_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaUInt8_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaUInt8_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaUInt8_Type)<0) {
      printf("** PyType_Ready failed for: oaUInt8\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaUInt8",
           (PyObject*)(&PyoaUInt8_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaUInt8\n");
       return -1;
    }
    return 0;
}

