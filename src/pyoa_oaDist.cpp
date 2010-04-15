
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
// Wrapper Implementation for Class: oaDist = oaUInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDist_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDist_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaDistObject* self = (PyoaDistObject*)gself;
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
    // Case: (oaDist)
    {
        PyParamoaDist p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDist_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDist, Choices are:\n"
        "    ()\n"
        "    (oaDist)\n"
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
oaDist_dealloc(PyObject* gself)
{
    PyoaDistObject* self = (PyoaDistObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaDist_repr(PyObject *ob)
{
    PyParamoaDist value;
    int convert_status=PyoaDist_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* ivalue=PyLong_FromUnsignedLong(value.Data());
    PyObject* result=PyObject_Repr(ivalue);
    Py_DECREF(ivalue);
    return result;
}

// ------------------------------------------------------------------
static int
oaDist_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDist v1;
    PyParamoaDist v2;
    int convert_status1=PyoaDist_Convert(ob1,&v1);
    int convert_status2=PyoaDist_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.Data()==v2.Data()) return 0;
    if (v1.Data()>v2.Data()) return 1;
    return -1;
}


// ------------------------------------------------------------------
int
PyoaDist_Convert(PyObject* ob,PyParamoaDist* result)
{
  if (ob == NULL) return 1;
  if (PyoaDist_Check(ob)) {
    result->SetData(((PyoaDistObject*)ob)->value);
    return 1;
  }
  if (PyInt_Check(ob)) {
    unsigned long val = PyInt_AsLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaDist value=oaDist(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaDist");
      return 0;
    }
    result->GiveData(new oaDist(value));
    return 1;
  }
  if (PyLong_Check(ob)) {
    unsigned long val = PyLong_AsUnsignedLong(ob);
    if (val==-1 && PyErr_Occurred()) return 0;
    oaDist value=oaDist(val);
    if (  ((long) value) != val) {
      PyErr_SetString(PyExc_TypeError,
                       "value is out of range for oaDist");
      return 0;
    }
    result->GiveData(new oaDist(value));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
                  "cann't convert object to oaDist");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaDist_FromoaDist(const oaDist& value)
{
  PyObject* gself = PyoaDist_Type.tp_alloc(&PyoaDist_Type,0);
  if (gself == NULL) return gself;
  PyoaDistObject* self = (PyoaDistObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDist_FromoaDist(oaDist* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaDist_Type.tp_alloc(&PyoaDist_Type,0);
  if (gself == NULL) return gself;
  PyoaDistObject* self = (PyoaDistObject*)gself;
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
static char oaDist_assign_doc[] =
"Class: oaDist, Function: assign\n"
"  Paramegers: (oaDist)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaDist_assign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDist data;
    int convert_status=PyoaDist_Convert(ob,&data);
    assert(convert_status!=0);
    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDist_Convert,&p1)) {
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
static char oaDist_int_doc[] =
"Class: oaDist, Function: int\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaDist_int(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDist data;
    int convert_status=PyoaDist_Convert(ob,&data);
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
static char oaDist_long_doc[] =
"Class: oaDist, Function: long\n"
"  Paramegers: ()\n"
"    This function returns the current value as an integer.\n"
;

static PyObject*
oaDist_long(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDist data;
    int convert_status=PyoaDist_Convert(ob,&data);
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
static PyMethodDef oaDist_methodlist[] = {
    {"assign",(PyCFunction)oaDist_assign,METH_VARARGS,oaDist_assign_doc},
    {"int",(PyCFunction)oaDist_int,METH_VARARGS,oaDist_int_doc},
    {"long",(PyCFunction)oaDist_long,METH_VARARGS,oaDist_long_doc},
   {NULL,NULL,0,NULL}
};
// -----------------------------------------------------
// Math
// -----------------------------------------------------
static int oaDist_nonzero(PyObject* ob)
{
  PyParamoaDist p;
  int s=PyoaDist_Convert(ob,&p);
  assert(s!=0);
  return p.Data()!=0;
}
// -----------------------------------------------------
static int oaDist_coerce(PyObject** ob1,PyObject** ob2)
{
  PyParamoaDist p1;
  int s1=PyoaDist_Convert(*ob1,&p1);
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
static PyObject* oaDist_int(PyObject* ob)
{
  PyParamoaDist p;
  int s=PyoaDist_Convert(ob,&p);
  assert(s!=0);
  return PyInt_FromLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaDist_long(PyObject* ob)
{
  PyParamoaDist p;
  int s=PyoaDist_Convert(ob,&p);
  assert(s!=0);
  return PyLong_FromUnsignedLong(p.Data());
}
// -----------------------------------------------------
static PyObject* oaDist_float(PyObject* ob)
{
  PyParamoaDist p;
  int s=PyoaDist_Convert(ob,&p);
  assert(s!=0);
  return PyFloat_FromDouble((double)p.Data());
}
// -----------------------------------------------------
PyNumberMethods oaDistAsNumber = {
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
  (inquiry)oaDist_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  oaDist_coerce, /*nb_coerce*/
  (unaryfunc)oaDist_int, /*nb_int*/
  (unaryfunc)oaDist_long, /*nb_long*/
  (unaryfunc)oaDist_float, /*nb_float*/
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
static char oaDist_doc[] =
"Class: oaDist\n"
"  The oaDist utility class represents 2 Byte numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDist()\n"
"    Signature: oaDist||\n"
"    This is the default constructor for the oaDist class. This constructor creates a zero valued oaDist.\n"
"  Paramegers: (oaDist)\n"
"    Calls: (const oaDist&)\n"
"    Signature: oaDist||cref-oaDist,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDist_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDist",
    sizeof(PyoaDistObject),
    0,
    oaDist_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaDist_compare,    /* tp_compare */
    oaDist_repr,      /* tp_repr */
    &oaDistAsNumber,   /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaDist_repr,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDist_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaDist_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaDist_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDist_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDist_Type)<0) {
      printf("** PyType_Ready failed for: oaDist\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDist",
           (PyObject*)(&PyoaDist_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDist\n");
       return -1;
    }
    return 0;
}

