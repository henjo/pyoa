
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
// Wrapper Implementation for Class: oaDouble
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDouble_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDouble_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaDoubleObject* self = (PyoaDoubleObject*)gself;
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
    // Case: (oaDouble)
    {
        PyParamoaDouble p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDouble_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDouble, Choices are:\n"
        "    ()\n"
        "    (oaDouble)\n"
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
oaDouble_dealloc(PyObject* gself)
{
    PyoaDoubleObject* self = (PyoaDoubleObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaDouble_repr(PyObject *ob)
{
    PyParamoaDouble value;
    int convert_status=PyoaDouble_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyFloat_FromDouble(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaDouble_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDouble v1;
    PyParamoaDouble v2;
    int convert_status1=PyoaDouble_Convert(ob1,&v1);
    int convert_status2=PyoaDouble_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaDouble_Convert(PyObject* ob,PyParamoaDouble* result)
{
  if (ob == NULL) return 1;
  if (PyoaDouble_Check(ob)) {
    result->SetData(((PyoaDoubleObject*)ob)->value);
    return 1;
  }
  double val = PyFloat_AsDouble(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  result->GiveData(new oaDouble(val));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaDouble_FromoaDouble(const oaDouble& value)
{
  PyObject* gself = PyoaDouble_Type.tp_alloc(&PyoaDouble_Type,0);
  if (gself == NULL) return gself;
  PyoaDoubleObject* self = (PyoaDoubleObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDouble_FromoaDouble(oaDouble* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaDouble_Type.tp_alloc(&PyoaDouble_Type,0);
  if (gself == NULL) return gself;
  PyoaDoubleObject* self = (PyoaDoubleObject*)gself;
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
static char oaDouble_assign_doc[] =
"Class: oaDouble, Function: assign\n"
"  Paramegers: (oaDouble)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaDouble_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDouble data;
    int convert_status=PyoaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaDouble p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDouble_Convert,&p1)) {
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
static char oaDouble_float_doc[] =
"Class: oaDouble, Function: float\n"
"  Paramegers: ()\n"
"    This function returns the current value as a float.\n"
;

static PyObject*
oaDouble_float(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDouble data;
    int convert_status=PyoaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyFloat_FromDouble(data.Data());
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
static PyMethodDef oaDouble_methodlist[] = {
    {"assign",(PyCFunction)oaDouble_assign,METH_VARARGS,oaDouble_assign_doc},
    {"float",(PyCFunction)oaDouble_float,METH_VARARGS,oaDouble_float_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaDouble_nonzero(PyObject* ob)
{
  PyParamoaDouble p;
  int s=PyoaDouble_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0.0;
}
// -----------------------------------------------------
static int oaDouble_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaDouble p1;
  int s1=PyoaDouble_Convert(*ob1,&p1);
  if (s1==0) return 1;
  if (PyFloat_Check(*ob2)) {
    *ob1 = PyFloat_FromDouble((double)p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  return 1; /* Can't do it */
}
// -----------------------------------------------------
static PyObject* oaDouble_float(PyObject* ob)
{
  PyParamoaDouble p;
  int s=PyoaDouble_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaDoubleAsNumber = {
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
  (inquiry)oaDouble_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaDouble_coerce, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  (unaryfunc)oaDouble_float, /*nb_float*/
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
static char oaDouble_doc[] =
"Class: oaDouble\n"
"  The oaDouble utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDouble()\n"
"    Signature: oaDouble||\n"
"    This is the default constructor for the oaDouble class. This constructor creates a zero valued oaDouble.\n"
"  Paramegers: (oaDouble)\n"
"    Calls: (const oaDouble&)\n"
"    Signature: oaDouble||cref-oaDouble,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDouble_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDouble",
    sizeof(PyoaDoubleObject),
    0,
    oaDouble_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaDouble_compare,    /* tp_compare */
    oaDouble_repr,      /* tp_repr */
    &oaDoubleAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaDouble_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDouble_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaDouble_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaDouble_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDouble_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDouble_Type)<0) {
      printf("** PyType_Ready failed for: oaDouble\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDouble",
           (PyObject*)(&PyoaDouble_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDouble\n");
       return -1;
    }
    return 0;
}

