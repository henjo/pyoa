
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
// Wrapper Implementation for Class: oaComplex_oaDouble
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaComplex_oaDouble_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaComplex_oaDouble_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaComplex_oaDoubleObject* self = (PyoaComplex_oaDoubleObject*)gself;
    self->data = oaComplex_oaDouble(0,0);
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
    // Case: (oaComplex_oaDouble)
    {
        PyParamoaComplex_oaDouble p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaComplex_oaDouble_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaComplex_oaDouble, Choices are:\n"
        "    ()\n"
        "    (oaComplex_oaDouble)\n"
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
oaComplex_oaDouble_dealloc(PyObject* gself)
{
    PyoaComplex_oaDoubleObject* self = (PyoaComplex_oaDoubleObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaComplex_oaDouble_repr(PyObject *ob)
{
    PyParamoaComplex_oaDouble value;
    int convert_status=PyoaComplex_oaDouble_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyComplex_FromDoubles(value.Data().real(),value.Data().imag());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaComplex_oaDouble_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaComplex_oaDouble v1;
    PyParamoaComplex_oaDouble v2;
    int convert_status1=PyoaComplex_oaDouble_Convert(ob1,&v1);
    int convert_status2=PyoaComplex_oaDouble_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data().real()==v2.Data().real() &&
        v1.Data().imag()==v2.Data().imag()) return 0;
    return -1;
}

// ------------------------------------------------------------------
int
PyoaComplex_oaDouble_Convert(PyObject* ob,PyParamoaComplex_oaDouble* result)
{
  if (ob == NULL) return 1;
  if (PyoaComplex_oaDouble_Check(ob)) {
    result->SetData(((PyoaComplex_oaDoubleObject*)ob)->value);
    return 1;
  }
  Py_complex val = PyComplex_AsCComplex(ob);
  if (val.real==-1 && PyErr_Occurred()) return 0;
  result->GiveData(new oaComplex_oaDouble(val.real,val.imag));
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaComplex_oaDouble_FromoaComplex_oaDouble(const oaComplex_oaDouble& value)
{
  PyObject* gself = PyoaComplex_oaDouble_Type.tp_alloc(&PyoaComplex_oaDouble_Type,0);
  if (gself == NULL) return gself;
  PyoaComplex_oaDoubleObject* self = (PyoaComplex_oaDoubleObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaComplex_oaDouble_FromoaComplex_oaDouble(oaComplex_oaDouble* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaComplex_oaDouble_Type.tp_alloc(&PyoaComplex_oaDouble_Type,0);
  if (gself == NULL) return gself;
  PyoaComplex_oaDoubleObject* self = (PyoaComplex_oaDoubleObject*)gself;
  self->data = oaComplex_oaDouble(0,0);;
  self->value = value;
  self->borrow = borrow;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaComplex_oaDouble_assign_doc[] =
"Class: oaComplex_oaDouble, Function: assign\n"
"  Paramegers: (oaComplex_oaDouble)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaComplex_oaDouble_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaComplex_oaDouble data;
    int convert_status=PyoaComplex_oaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaComplex_oaDouble p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaComplex_oaDouble_Convert,&p1)) {
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
static char oaComplex_oaDouble_complex_doc[] =
"Class: oaComplex_oaDouble, Function: complex\n"
"  Paramegers: ()\n"
"    This function returns the current value as a complex.\n"
;

static PyObject*
oaComplex_oaDouble_complex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaComplex_oaDouble data;
    int convert_status=PyoaComplex_oaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyComplex_FromDoubles(data.Data().real(),data.Data().imag());
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
static PyMethodDef oaComplex_oaDouble_methodlist[] = {
    {"assign",(PyCFunction)oaComplex_oaDouble_assign,METH_VARARGS,oaComplex_oaDouble_assign_doc},
    {"complex",(PyCFunction)oaComplex_oaDouble_complex,METH_VARARGS,oaComplex_oaDouble_complex_doc},
   {NULL,NULL,0,NULL}
};

// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaComplex_oaDouble_nonzero(PyObject* ob)
{
  PyParamoaComplex_oaDouble p;
  int s=PyoaComplex_oaDouble_Convert(ob,&p);
  assert(s!=0);
  return p.Data().real()!=0.0 && p.Data().imag()!=0.0;
}
// -----------------------------------------------------
static int oaComplex_oaDouble_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaComplex_oaDouble p1;
  int s1=PyoaComplex_oaDouble_Convert(*ob1,&p1);
  if (s1==0) return 1;
  if (PyComplex_Check(*ob2)) {
    *ob1 = PyComplex_FromDoubles(p1.Data().real(),p1.Data().imag());
    Py_INCREF(*ob2);
    return 0;
  }
  return 1; /* Can't do it */
}
// -----------------------------------------------------
PyNumberMethods oaComplex_oaDoubleAsNumber = {
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
  (inquiry)oaComplex_oaDouble_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaComplex_oaDouble_coerce, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
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
static char oaComplex_oaDouble_doc[] =
"Class: oaComplex_oaDouble\n"
"  The oaComplex_oaDouble utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaComplex_oaDouble()\n"
"    Signature: oaComplex_oaDouble||\n"
"    This is the default constructor for the oaComplex_oaDouble class. This constructor creates a zero valued oaComplex_oaDouble.\n"
"  Paramegers: (oaComplex_oaDouble)\n"
"    Calls: (const oaComplex_oaDouble&)\n"
"    Signature: oaComplex_oaDouble||cref-oaComplex_oaDouble,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaComplex_oaDouble_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaComplex_oaDouble",
    sizeof(PyoaComplex_oaDoubleObject),
    0,
    oaComplex_oaDouble_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaComplex_oaDouble_compare,    /* tp_compare */
    oaComplex_oaDouble_repr,      /* tp_repr */
    &oaComplex_oaDoubleAsNumber,    /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaComplex_oaDouble_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaComplex_oaDouble_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaComplex_oaDouble_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaComplex_oaDouble_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaComplex_oaDouble_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaComplex_oaDouble_Type)<0) {
      printf("** PyType_Ready failed for: oaComplex_oaDouble\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaComplex_oaDouble",
           (PyObject*)(&PyoaComplex_oaDouble_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaComplex_oaDouble\n");
       return -1;
    }
    return 0;
}

