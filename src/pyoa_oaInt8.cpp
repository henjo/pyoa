
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
// Wrapper Implementation for Class: oaInt8
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInt8_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInt8_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaInt8Object* self = (PyoaInt8Object*)gself;
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
    // Case: (oaInt8)
    {
        PyParamoaInt8 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInt8_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaInt8, Choices are:\n"
        "    ()\n"
        "    (oaInt8)\n"
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
oaInt8_dealloc(PyObject* gself)
{
    PyoaInt8Object* self = (PyoaInt8Object*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaInt8_repr(PyObject *ob)
{
    PyParamoaInt8 value;
    int convert_status=PyoaInt8_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyLong_FromLongLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaInt8_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInt8 v1;
    PyParamoaInt8 v2;
    int convert_status1=PyoaInt8_Convert(ob1,&v1);
    int convert_status2=PyoaInt8_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaInt8_Convert(PyObject* ob,PyParamoaInt8* result)
{
  if (ob == NULL) return 1;
  if (PyoaInt8_Check(ob)) {
    result->SetData(((PyoaInt8Object*)ob)->value);
    return 1;
  }
  PYOA_LONG_LONG val = PyLong_AsLongLong(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  oaInt8 value=oaInt8(val);
  if (  ((PYOA_LONG_LONG) value) != val) {
    PyErr_SetString(PyExc_TypeError,
                     "value is out of range for oaInt8");
    return 0;
  }
  result->GiveData(new oaInt8(value));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaInt8_FromoaInt8(const oaInt8& value)
{
  PyObject* gself = PyoaInt8_Type.tp_alloc(&PyoaInt8_Type,0);
  if (gself == NULL) return gself;
  PyoaInt8Object* self = (PyoaInt8Object*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaInt8_FromoaInt8(oaInt8* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaInt8_Type.tp_alloc(&PyoaInt8_Type,0);
  if (gself == NULL) return gself;
  PyoaInt8Object* self = (PyoaInt8Object*)gself;
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
static char oaInt8_assign_doc[] =
"Class: oaInt8, Function: assign\n"
"  Paramegers: (oaInt8)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaInt8_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInt8 data;
    int convert_status=PyoaInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaInt8 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInt8_Convert,&p1)) {
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
static char oaInt8_long_doc[] =
"Class: oaInt8, Function: long\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaInt8_long(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInt8 data;
    int convert_status=PyoaInt8_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyLong_FromLongLong(data.Data());
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
static PyMethodDef oaInt8_methodlist[] = {
    {"assign",(PyCFunction)oaInt8_assign,METH_VARARGS,oaInt8_assign_doc},
    {"long",(PyCFunction)oaInt8_long,METH_VARARGS,oaInt8_long_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaInt8_nonzero(PyObject* ob)
{
  PyParamoaInt8 p;
  int s=PyoaInt8_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaInt8_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaInt8 p1;
  int s1=PyoaInt8_Convert(*ob1,&p1);
  if (s1==0) return 1;
  else if (PyLong_Check(*ob2)) {
    *ob1 = PyLong_FromLongLong(p1.Data());
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
static PyObject* oaInt8_long(PyObject* ob)
{
  PyParamoaInt8 p;
  int s=PyoaInt8_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromLongLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaInt8_float(PyObject* ob)
{
  PyParamoaInt8 p;
  int s=PyoaInt8_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaInt8AsNumber = {
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
  (inquiry)oaInt8_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaInt8_coerce, /*nb_coerce*/
  0, /*nb_int*/
  (unaryfunc)oaInt8_long, /*nb_long*/
  (unaryfunc)oaInt8_float, /*nb_float*/
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
static char oaInt8_doc[] =
"Class: oaInt8\n"
"  The oaInt8 utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaInt8()\n"
"    Signature: oaInt8||\n"
"    This is the default constructor for the oaInt8 class. This constructor creates a zero valued oaInt8.\n"
"  Paramegers: (oaInt8)\n"
"    Calls: (const oaInt8&)\n"
"    Signature: oaInt8||cref-oaInt8,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInt8_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInt8",
    sizeof(PyoaInt8Object),
    0,
    oaInt8_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaInt8_compare,    /* tp_compare */
    oaInt8_repr,      /* tp_repr */
    &oaInt8AsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaInt8_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInt8_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaInt8_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaInt8_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInt8_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInt8_Type)<0) {
      printf("** PyType_Ready failed for: oaInt8\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInt8",
           (PyObject*)(&PyoaInt8_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInt8\n");
       return -1;
    }
    return 0;
}

