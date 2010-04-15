
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
// Wrapper Implementation for Class: oaFloat
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloat_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaFloatObject* self = (PyoaFloatObject*)gself;
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
    // Case: (oaFloat)
    {
        PyParamoaFloat p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloat_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaFloat, Choices are:\n"
        "    ()\n"
        "    (oaFloat)\n"
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
oaFloat_dealloc(PyObject* gself)
{
    PyoaFloatObject* self = (PyoaFloatObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaFloat_repr(PyObject *ob)
{
    PyParamoaFloat value;
    int convert_status=PyoaFloat_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyFloat_FromDouble(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaFloat_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloat v1;
    PyParamoaFloat v2;
    int convert_status1=PyoaFloat_Convert(ob1,&v1);
    int convert_status2=PyoaFloat_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaFloat_Convert(PyObject* ob,PyParamoaFloat* result)
{
  if (ob == NULL) return 1;
  if (PyoaFloat_Check(ob)) {
    result->SetData(((PyoaFloatObject*)ob)->value);
    return 1;
  }
  double val = PyFloat_AsDouble(ob);
  if (val==-1 && PyErr_Occurred()) return 0;
  result->GiveData(new oaFloat(val));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaFloat_FromoaFloat(const oaFloat& value)
{
  PyObject* gself = PyoaFloat_Type.tp_alloc(&PyoaFloat_Type,0);
  if (gself == NULL) return gself;
  PyoaFloatObject* self = (PyoaFloatObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaFloat_FromoaFloat(oaFloat* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaFloat_Type.tp_alloc(&PyoaFloat_Type,0);
  if (gself == NULL) return gself;
  PyoaFloatObject* self = (PyoaFloatObject*)gself;
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
static char oaFloat_assign_doc[] =
"Class: oaFloat, Function: assign\n"
"  Paramegers: (oaFloat)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaFloat_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloat data;
    int convert_status=PyoaFloat_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloat_Convert,&p1)) {
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
static char oaFloat_float_doc[] =
"Class: oaFloat, Function: float\n"
"  Paramegers: ()\n"
"    This function returns the current value as a float.\n"
;

static PyObject*
oaFloat_float(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloat data;
    int convert_status=PyoaFloat_Convert(ob,&data);
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
static PyMethodDef oaFloat_methodlist[] = {
    {"assign",(PyCFunction)oaFloat_assign,METH_VARARGS,oaFloat_assign_doc},
    {"float",(PyCFunction)oaFloat_float,METH_VARARGS,oaFloat_float_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaFloat_nonzero(PyObject* ob)
{
  PyParamoaFloat p;
  int s=PyoaFloat_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0.0;
}
// -----------------------------------------------------
static int oaFloat_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaFloat p1;
  int s1=PyoaFloat_Convert(*ob1,&p1);
  if (s1==0) return 1;
  if (PyFloat_Check(*ob2)) {
    *ob1 = PyFloat_FromDouble((double)p1.Data());
    Py_INCREF(*ob2);
    return 0;
  }
  return 1; /* Can't do it */
}
// -----------------------------------------------------
static PyObject* oaFloat_float(PyObject* ob)
{
  PyParamoaFloat p;
  int s=PyoaFloat_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaFloatAsNumber = {
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
  (inquiry)oaFloat_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaFloat_coerce, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  (unaryfunc)oaFloat_float, /*nb_float*/
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
static char oaFloat_doc[] =
"Class: oaFloat\n"
"  The oaFloat utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaFloat()\n"
"    Signature: oaFloat||\n"
"    This is the default constructor for the oaFloat class. This constructor creates a zero valued oaFloat.\n"
"  Paramegers: (oaFloat)\n"
"    Calls: (const oaFloat&)\n"
"    Signature: oaFloat||cref-oaFloat,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloat_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloat",
    sizeof(PyoaFloatObject),
    0,
    oaFloat_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaFloat_compare,    /* tp_compare */
    oaFloat_repr,      /* tp_repr */
    &oaFloatAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaFloat_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloat_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaFloat_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaFloat_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloat_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloat_Type)<0) {
      printf("** PyType_Ready failed for: oaFloat\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloat",
           (PyObject*)(&PyoaFloat_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloat\n");
       return -1;
    }
    return 0;
}

