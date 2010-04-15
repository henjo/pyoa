
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
// Wrapper Implementation for Class: oaArray_oaComplex_oaDouble
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaComplex_oaDouble_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaComplex_oaDouble_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaComplex_oaDoubleObject* self = (PyoaArray_oaComplex_oaDoubleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaArray_oaComplex_oaDouble();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaArray_oaComplex_oaDouble(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaComplex_oaDouble)
    {
        PyParamoaArray_oaComplex_oaDouble p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaComplex_oaDouble_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaArray_oaComplex_oaDouble(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaComplex_oaDouble])
    {
        PyParamoaComplex_oaDouble_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplex_oaDouble_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaArray_oaComplex_oaDouble(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaComplex_oaDouble, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaComplex_oaDouble)\n"
        "    ([oaComplex_oaDouble])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaComplex_oaDouble_tp_dealloc(PyoaArray_oaComplex_oaDoubleObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaComplex_oaDouble*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaComplex_oaDouble_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaComplex_oaDouble value;
    int convert_status=PyoaArray_oaComplex_oaDouble_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaArray_oaComplex_oaDouble::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaComplex_oaDouble_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaComplex_oaDouble v1;
    PyParamoaArray_oaComplex_oaDouble v2;
    int convert_status1=PyoaArray_oaComplex_oaDouble_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaComplex_oaDouble_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaComplex_oaDouble_Convert(PyObject* ob,PyParamoaArray_oaComplex_oaDouble* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaComplex_oaDouble_Check(ob)) {
        result->SetData( (oaArray_oaComplex_oaDouble*) ((PyoaArray_oaComplex_oaDoubleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaComplex_oaDouble Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaComplex_oaDouble_FromoaArray_oaComplex_oaDouble(oaArray_oaComplex_oaDouble* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaComplex_oaDouble_Type.tp_alloc(&PyoaArray_oaComplex_oaDouble_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaComplex_oaDoubleObject* self = (PyoaArray_oaComplex_oaDoubleObject*)bself;
        self->value = (oaArrayBase_oaComplex_oaDouble*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaDouble_append_doc[] = 
"Class: oaArray_oaComplex_oaDouble, Function: append\n"
"  Paramegers: (oaComplex_oaDouble)\n"
"    Calls: void append(const oaComplex_oaDouble& element)\n"
"    Signature: append|void-void|cref-oaComplex_oaDouble,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaComplex_oaDouble)\n"
"    Calls: void append(const oaArray_oaComplex_oaDouble& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaComplex_oaDouble,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaComplex_oaDouble_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaDouble data;
    int convert_status=PyoaArray_oaComplex_oaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaDoubleObject* self=(PyoaArray_oaComplex_oaDoubleObject*)ob;

    // Case: (oaComplex_oaDouble)
    {
        PyParamoaComplex_oaDouble p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplex_oaDouble_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaComplex_oaDouble)
    {
        PyParamoaArray_oaComplex_oaDouble p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaComplex_oaDouble_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaComplex_oaDouble, function: append, Choices are:\n"
        "    (oaComplex_oaDouble)\n"
        "    (oaArray_oaComplex_oaDouble)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaDouble_find_doc[] = 
"Class: oaArray_oaComplex_oaDouble, Function: find\n"
"  Paramegers: (oaComplex_oaDouble)\n"
"    Calls: oaUInt4 find(const oaComplex_oaDouble& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaComplex_oaDouble,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaComplex_oaDouble_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaDouble data;
    int convert_status=PyoaArray_oaComplex_oaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaDoubleObject* self=(PyoaArray_oaComplex_oaDoubleObject*)ob;

    PyParamoaComplex_oaDouble p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplex_oaDouble_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaDouble_remove_doc[] = 
"Class: oaArray_oaComplex_oaDouble, Function: remove\n"
"  Paramegers: (oaComplex_oaDouble)\n"
"    Calls: void remove(const oaComplex_oaDouble& element)\n"
"    Signature: remove|void-void|cref-oaComplex_oaDouble,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaComplex_oaDouble_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaDouble data;
    int convert_status=PyoaArray_oaComplex_oaDouble_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaDoubleObject* self=(PyoaArray_oaComplex_oaDoubleObject*)ob;

    PyParamoaComplex_oaDouble p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplex_oaDouble_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaComplex_oaDouble_assign_doc[] = 
"Class: oaArray_oaComplex_oaDouble, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaComplex_oaDouble_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaComplex_oaDouble data;
  int convert_status=PyoaArray_oaComplex_oaDouble_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaComplex_oaDouble p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaComplex_oaDouble_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaComplex_oaDouble_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaComplex_oaDouble_append,METH_VARARGS,oaArray_oaComplex_oaDouble_append_doc},
    {"find",(PyCFunction)oaArray_oaComplex_oaDouble_find,METH_VARARGS,oaArray_oaComplex_oaDouble_find_doc},
    {"remove",(PyCFunction)oaArray_oaComplex_oaDouble_remove,METH_VARARGS,oaArray_oaComplex_oaDouble_remove_doc},
    {"assign",(PyCFunction)oaArray_oaComplex_oaDouble_tp_assign,METH_VARARGS,oaArray_oaComplex_oaDouble_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaDouble_doc[] = 
"Class: oaArray_oaComplex_oaDouble\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaComplex_oaDouble()\n"
"    Signature: oaArray_oaComplex_oaDouble||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaComplex_oaDouble(oaUInt4 size)\n"
"    Signature: oaArray_oaComplex_oaDouble||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaComplex_oaDouble)\n"
"    Calls: oaArray_oaComplex_oaDouble(const oaArray_oaComplex_oaDouble& array)\n"
"    Signature: oaArray_oaComplex_oaDouble||cref-oaArray_oaComplex_oaDouble,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaComplex_oaDouble])\n"
"    Calls: oaArray_oaComplex_oaDouble(const oaComplex_oaDouble* array)\n"
"    Signature: oaArray_oaComplex_oaDouble||cptr-oaComplex_oaDouble,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaComplex_oaDouble)\n"
"    Calls: (const oaArray_oaComplex_oaDouble&)\n"
"    Signature: oaArray_oaComplex_oaDouble||cref-oaArray_oaComplex_oaDouble,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaComplex_oaDouble_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaComplex_oaDouble",
    sizeof(PyoaArray_oaComplex_oaDoubleObject),
    0,
    (destructor)oaArray_oaComplex_oaDouble_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaComplex_oaDouble_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaComplex_oaDouble_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaComplex_oaDouble_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaComplex_oaDouble_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaComplex_oaDouble_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaComplex_oaDouble_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaComplex_oaDouble_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaComplex_oaDouble_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaComplex_oaDouble\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaComplex_oaDouble",
           (PyObject*)(&PyoaArray_oaComplex_oaDouble_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaComplex_oaDouble\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaComplex_oaFloat
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaComplex_oaFloat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaComplex_oaFloat_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaComplex_oaFloatObject* self = (PyoaArray_oaComplex_oaFloatObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaArray_oaComplex_oaFloat();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaArray_oaComplex_oaFloat(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaComplex_oaFloat)
    {
        PyParamoaArray_oaComplex_oaFloat p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaComplex_oaFloat_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaArray_oaComplex_oaFloat(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaComplex_oaFloat])
    {
        PyParamoaComplex_oaFloat_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplex_oaFloat_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaArray_oaComplex_oaFloat(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaComplex_oaFloat, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaComplex_oaFloat)\n"
        "    ([oaComplex_oaFloat])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaComplex_oaFloat_tp_dealloc(PyoaArray_oaComplex_oaFloatObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaComplex_oaFloat*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaComplex_oaFloat_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaComplex_oaFloat value;
    int convert_status=PyoaArray_oaComplex_oaFloat_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaArray_oaComplex_oaFloat::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaComplex_oaFloat_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaComplex_oaFloat v1;
    PyParamoaArray_oaComplex_oaFloat v2;
    int convert_status1=PyoaArray_oaComplex_oaFloat_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaComplex_oaFloat_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaComplex_oaFloat_Convert(PyObject* ob,PyParamoaArray_oaComplex_oaFloat* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaComplex_oaFloat_Check(ob)) {
        result->SetData( (oaArray_oaComplex_oaFloat*) ((PyoaArray_oaComplex_oaFloatObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaComplex_oaFloat Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaComplex_oaFloat_FromoaArray_oaComplex_oaFloat(oaArray_oaComplex_oaFloat* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaComplex_oaFloat_Type.tp_alloc(&PyoaArray_oaComplex_oaFloat_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaComplex_oaFloatObject* self = (PyoaArray_oaComplex_oaFloatObject*)bself;
        self->value = (oaArrayBase_oaComplex_oaFloat*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaFloat_append_doc[] = 
"Class: oaArray_oaComplex_oaFloat, Function: append\n"
"  Paramegers: (oaComplex_oaFloat)\n"
"    Calls: void append(const oaComplex_oaFloat& element)\n"
"    Signature: append|void-void|cref-oaComplex_oaFloat,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaComplex_oaFloat)\n"
"    Calls: void append(const oaArray_oaComplex_oaFloat& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaComplex_oaFloat,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaComplex_oaFloat_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaFloat data;
    int convert_status=PyoaArray_oaComplex_oaFloat_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaFloatObject* self=(PyoaArray_oaComplex_oaFloatObject*)ob;

    // Case: (oaComplex_oaFloat)
    {
        PyParamoaComplex_oaFloat p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplex_oaFloat_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaComplex_oaFloat)
    {
        PyParamoaArray_oaComplex_oaFloat p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaComplex_oaFloat_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaComplex_oaFloat, function: append, Choices are:\n"
        "    (oaComplex_oaFloat)\n"
        "    (oaArray_oaComplex_oaFloat)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaFloat_find_doc[] = 
"Class: oaArray_oaComplex_oaFloat, Function: find\n"
"  Paramegers: (oaComplex_oaFloat)\n"
"    Calls: oaUInt4 find(const oaComplex_oaFloat& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaComplex_oaFloat,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaComplex_oaFloat_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaFloat data;
    int convert_status=PyoaArray_oaComplex_oaFloat_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaFloatObject* self=(PyoaArray_oaComplex_oaFloatObject*)ob;

    PyParamoaComplex_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplex_oaFloat_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaFloat_remove_doc[] = 
"Class: oaArray_oaComplex_oaFloat, Function: remove\n"
"  Paramegers: (oaComplex_oaFloat)\n"
"    Calls: void remove(const oaComplex_oaFloat& element)\n"
"    Signature: remove|void-void|cref-oaComplex_oaFloat,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaComplex_oaFloat_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaComplex_oaFloat data;
    int convert_status=PyoaArray_oaComplex_oaFloat_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaComplex_oaFloatObject* self=(PyoaArray_oaComplex_oaFloatObject*)ob;

    PyParamoaComplex_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplex_oaFloat_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaComplex_oaFloat_assign_doc[] = 
"Class: oaArray_oaComplex_oaFloat, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaComplex_oaFloat_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaComplex_oaFloat data;
  int convert_status=PyoaArray_oaComplex_oaFloat_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaComplex_oaFloat p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaComplex_oaFloat_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaComplex_oaFloat_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaComplex_oaFloat_append,METH_VARARGS,oaArray_oaComplex_oaFloat_append_doc},
    {"find",(PyCFunction)oaArray_oaComplex_oaFloat_find,METH_VARARGS,oaArray_oaComplex_oaFloat_find_doc},
    {"remove",(PyCFunction)oaArray_oaComplex_oaFloat_remove,METH_VARARGS,oaArray_oaComplex_oaFloat_remove_doc},
    {"assign",(PyCFunction)oaArray_oaComplex_oaFloat_tp_assign,METH_VARARGS,oaArray_oaComplex_oaFloat_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaComplex_oaFloat_doc[] = 
"Class: oaArray_oaComplex_oaFloat\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaComplex_oaFloat()\n"
"    Signature: oaArray_oaComplex_oaFloat||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaComplex_oaFloat(oaUInt4 size)\n"
"    Signature: oaArray_oaComplex_oaFloat||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaComplex_oaFloat)\n"
"    Calls: oaArray_oaComplex_oaFloat(const oaArray_oaComplex_oaFloat& array)\n"
"    Signature: oaArray_oaComplex_oaFloat||cref-oaArray_oaComplex_oaFloat,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaComplex_oaFloat])\n"
"    Calls: oaArray_oaComplex_oaFloat(const oaComplex_oaFloat* array)\n"
"    Signature: oaArray_oaComplex_oaFloat||cptr-oaComplex_oaFloat,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaComplex_oaFloat)\n"
"    Calls: (const oaArray_oaComplex_oaFloat&)\n"
"    Signature: oaArray_oaComplex_oaFloat||cref-oaArray_oaComplex_oaFloat,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaComplex_oaFloat_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaComplex_oaFloat",
    sizeof(PyoaArray_oaComplex_oaFloatObject),
    0,
    (destructor)oaArray_oaComplex_oaFloat_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaComplex_oaFloat_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaComplex_oaFloat_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaComplex_oaFloat_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaComplex_oaFloat_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaComplex_oaFloat_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaComplex_oaFloat_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaComplex_oaFloat_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaComplex_oaFloat_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaComplex_oaFloat\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaComplex_oaFloat",
           (PyObject*)(&PyoaArray_oaComplex_oaFloat_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaComplex_oaFloat\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaConstraintParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaConstraintParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaConstraintParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaConstraintParamObject* self = (PyoaArray_oaConstraintParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaArray_oaConstraintParam();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaArray_oaConstraintParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaConstraintParam)
    {
        PyParamoaArray_oaConstraintParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaConstraintParam_Convert,&p1)) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaArray_oaConstraintParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaConstraintParam])
    {
        PyParamoaConstraintParam_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintParam_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaArray_oaConstraintParam(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaConstraintParam, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaConstraintParam)\n"
        "    ([oaConstraintParam])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaConstraintParam_tp_dealloc(PyoaArray_oaConstraintParamObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaConstraintParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaConstraintParam_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaConstraintParam value;
    int convert_status=PyoaArray_oaConstraintParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaArray_oaConstraintParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaConstraintParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaConstraintParam v1;
    PyParamoaArray_oaConstraintParam v2;
    int convert_status1=PyoaArray_oaConstraintParam_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaConstraintParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaConstraintParam_Convert(PyObject* ob,PyParamoaArray_oaConstraintParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaConstraintParam_Check(ob)) {
        result->SetData( (oaArray_oaConstraintParam*) ((PyoaArray_oaConstraintParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaConstraintParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaConstraintParam_FromoaArray_oaConstraintParam(oaArray_oaConstraintParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaConstraintParam_Type.tp_alloc(&PyoaArray_oaConstraintParam_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaConstraintParamObject* self = (PyoaArray_oaConstraintParamObject*)bself;
        self->value = (oaArrayBase_oaConstraintParam*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaConstraintParam_append_doc[] = 
"Class: oaArray_oaConstraintParam, Function: append\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaConstraintParam,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaConstraintParam)\n"
"    Calls: void append(const oaArray_oaConstraintParam& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaConstraintParam,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaConstraintParam_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaConstraintParam data;
    int convert_status=PyoaArray_oaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaConstraintParamObject* self=(PyoaArray_oaConstraintParamObject*)ob;

    // Case: (oaConstraintParam)
    {
        PyParamoaConstraintParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintParam_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaConstraintParam)
    {
        PyParamoaArray_oaConstraintParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaConstraintParam_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaConstraintParam, function: append, Choices are:\n"
        "    (oaConstraintParam)\n"
        "    (oaArray_oaConstraintParam)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaConstraintParam_find_doc[] = 
"Class: oaArray_oaConstraintParam, Function: find\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaConstraintParam,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaConstraintParam_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaConstraintParam data;
    int convert_status=PyoaArray_oaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaConstraintParamObject* self=(PyoaArray_oaConstraintParamObject*)ob;

    PyParamoaConstraintParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParam_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaConstraintParam_remove_doc[] = 
"Class: oaArray_oaConstraintParam, Function: remove\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaConstraintParam,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaConstraintParam_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaConstraintParam data;
    int convert_status=PyoaArray_oaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaConstraintParamObject* self=(PyoaArray_oaConstraintParamObject*)ob;

    PyParamoaConstraintParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParam_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaConstraintParam_assign_doc[] = 
"Class: oaArray_oaConstraintParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaConstraintParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaConstraintParam data;
  int convert_status=PyoaArray_oaConstraintParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaConstraintParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaConstraintParam_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaConstraintParam_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaConstraintParam_append,METH_VARARGS,oaArray_oaConstraintParam_append_doc},
    {"find",(PyCFunction)oaArray_oaConstraintParam_find,METH_VARARGS,oaArray_oaConstraintParam_find_doc},
    {"remove",(PyCFunction)oaArray_oaConstraintParam_remove,METH_VARARGS,oaArray_oaConstraintParam_remove_doc},
    {"assign",(PyCFunction)oaArray_oaConstraintParam_tp_assign,METH_VARARGS,oaArray_oaConstraintParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaConstraintParam_doc[] = 
"Class: oaArray_oaConstraintParam\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaConstraintParam()\n"
"    Signature: oaArray_oaConstraintParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaConstraintParam(oaUInt4 size)\n"
"    Signature: oaArray_oaConstraintParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaConstraintParam)\n"
"    Calls: oaArray_oaConstraintParam(const oaArray_oaConstraintParam& array)\n"
"    Signature: oaArray_oaConstraintParam||cref-oaArray_oaConstraintParam,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaConstraintParam])\n"
"    Calls: oaArray_oaConstraintParam( array)\n"
"    Signature: oaArray_oaConstraintParam||cpptr-oaConstraintParam,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaConstraintParam)\n"
"    Calls: (const oaArray_oaConstraintParam&)\n"
"    Signature: oaArray_oaConstraintParam||cref-oaArray_oaConstraintParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaConstraintParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaConstraintParam",
    sizeof(PyoaArray_oaConstraintParamObject),
    0,
    (destructor)oaArray_oaConstraintParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaConstraintParam_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaConstraintParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaConstraintParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaConstraintParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaConstraintParam_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaConstraintParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaConstraintParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaConstraintParam_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaConstraintParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaConstraintParam",
           (PyObject*)(&PyoaArray_oaConstraintParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaConstraintParam\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaDBType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDBType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaDBType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaDBTypeObject* self = (PyoaArray_oaDBTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDBType*)  new oaArray_oaDBType();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDBType*)  new oaArray_oaDBType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDBType)
    {
        PyParamoaArray_oaDBType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDBType_Convert,&p1)) {
            self->value = (oaArrayBase_oaDBType*)  new oaArray_oaDBType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaDBType])
    {
        PyParamoaDBType_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDBType_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaDBType*)  new oaArray_oaDBType(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaDBType, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaDBType)\n"
        "    ([oaDBType])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaDBType_tp_dealloc(PyoaArray_oaDBTypeObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaDBType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDBType_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaDBType value;
    int convert_status=PyoaArray_oaDBType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaArray_oaDBType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaDBType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaDBType v1;
    PyParamoaArray_oaDBType v2;
    int convert_status1=PyoaArray_oaDBType_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaDBType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaDBType_Convert(PyObject* ob,PyParamoaArray_oaDBType* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaDBType_Check(ob)) {
        result->SetData( (oaArray_oaDBType*) ((PyoaArray_oaDBTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaDBType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaDBType_FromoaArray_oaDBType(oaArray_oaDBType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaDBType_Type.tp_alloc(&PyoaArray_oaDBType_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaDBTypeObject* self = (PyoaArray_oaDBTypeObject*)bself;
        self->value = (oaArrayBase_oaDBType*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDBType_append_doc[] = 
"Class: oaArray_oaDBType, Function: append\n"
"  Paramegers: (oaDBType)\n"
"    Calls: void append(const oaDBType& element)\n"
"    Signature: append|void-void|cref-oaDBType,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaDBType)\n"
"    Calls: void append(const oaArray_oaDBType& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaDBType,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaDBType_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDBType data;
    int convert_status=PyoaArray_oaDBType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDBTypeObject* self=(PyoaArray_oaDBTypeObject*)ob;

    // Case: (oaDBType)
    {
        PyParamoaDBType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDBType_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDBType)
    {
        PyParamoaArray_oaDBType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDBType_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaDBType, function: append, Choices are:\n"
        "    (oaDBType)\n"
        "    (oaArray_oaDBType)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDBType_find_doc[] = 
"Class: oaArray_oaDBType, Function: find\n"
"  Paramegers: (oaDBType)\n"
"    Calls: oaUInt4 find(const oaDBType& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaDBType,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaDBType_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDBType data;
    int convert_status=PyoaArray_oaDBType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDBTypeObject* self=(PyoaArray_oaDBTypeObject*)ob;

    PyParamoaDBType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDBType_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDBType_remove_doc[] = 
"Class: oaArray_oaDBType, Function: remove\n"
"  Paramegers: (oaDBType)\n"
"    Calls: void remove(const oaDBType& element)\n"
"    Signature: remove|void-void|cref-oaDBType,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaDBType_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDBType data;
    int convert_status=PyoaArray_oaDBType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDBTypeObject* self=(PyoaArray_oaDBTypeObject*)ob;

    PyParamoaDBType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDBType_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaDBType_assign_doc[] = 
"Class: oaArray_oaDBType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaDBType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaDBType data;
  int convert_status=PyoaArray_oaDBType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaDBType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaDBType_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaDBType_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaDBType_append,METH_VARARGS,oaArray_oaDBType_append_doc},
    {"find",(PyCFunction)oaArray_oaDBType_find,METH_VARARGS,oaArray_oaDBType_find_doc},
    {"remove",(PyCFunction)oaArray_oaDBType_remove,METH_VARARGS,oaArray_oaDBType_remove_doc},
    {"assign",(PyCFunction)oaArray_oaDBType_tp_assign,METH_VARARGS,oaArray_oaDBType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDBType_doc[] = 
"Class: oaArray_oaDBType\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaDBType()\n"
"    Signature: oaArray_oaDBType||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaDBType(oaUInt4 size)\n"
"    Signature: oaArray_oaDBType||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaDBType)\n"
"    Calls: oaArray_oaDBType(const oaArray_oaDBType& array)\n"
"    Signature: oaArray_oaDBType||cref-oaArray_oaDBType,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaDBType])\n"
"    Calls: oaArray_oaDBType(const oaDBType* array)\n"
"    Signature: oaArray_oaDBType||cptr-oaDBType,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaDBType)\n"
"    Calls: (const oaArray_oaDBType&)\n"
"    Signature: oaArray_oaDBType||cref-oaArray_oaDBType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaDBType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaDBType",
    sizeof(PyoaArray_oaDBTypeObject),
    0,
    (destructor)oaArray_oaDBType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaDBType_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaDBType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaDBType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaDBType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaDBType_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaDBType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaDBType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaDBType_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaDBType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaDBType",
           (PyObject*)(&PyoaArray_oaDBType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaDBType\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaDMAttr
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDMAttr_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaDMAttr_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaDMAttrObject* self = (PyoaArray_oaDMAttrObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaArray_oaDMAttr();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaArray_oaDMAttr(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDMAttr)
    {
        PyParamoaArray_oaDMAttr p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDMAttr_Convert,&p1)) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaArray_oaDMAttr(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaDMAttr])
    {
        PyParamoaDMAttr_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDMAttr_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaArray_oaDMAttr(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaDMAttr, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaDMAttr)\n"
        "    ([oaDMAttr])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaDMAttr_tp_dealloc(PyoaArray_oaDMAttrObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaDMAttr*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDMAttr_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaDMAttr value;
    int convert_status=PyoaArray_oaDMAttr_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaArray_oaDMAttr::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaDMAttr_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaDMAttr v1;
    PyParamoaArray_oaDMAttr v2;
    int convert_status1=PyoaArray_oaDMAttr_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaDMAttr_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaDMAttr_Convert(PyObject* ob,PyParamoaArray_oaDMAttr* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaDMAttr_Check(ob)) {
        result->SetData( (oaArray_oaDMAttr*) ((PyoaArray_oaDMAttrObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaDMAttr Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaDMAttr_FromoaArray_oaDMAttr(oaArray_oaDMAttr* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaDMAttr_Type.tp_alloc(&PyoaArray_oaDMAttr_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaDMAttrObject* self = (PyoaArray_oaDMAttrObject*)bself;
        self->value = (oaArrayBase_oaDMAttr*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDMAttr_append_doc[] = 
"Class: oaArray_oaDMAttr, Function: append\n"
"  Paramegers: (oaDMAttr)\n"
"    Calls: void append(const oaDMAttr& element)\n"
"    Signature: append|void-void|cref-oaDMAttr,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaDMAttr)\n"
"    Calls: void append(const oaArray_oaDMAttr& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaDMAttr,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaDMAttr_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDMAttr data;
    int convert_status=PyoaArray_oaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDMAttrObject* self=(PyoaArray_oaDMAttrObject*)ob;

    // Case: (oaDMAttr)
    {
        PyParamoaDMAttr p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDMAttr_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDMAttr)
    {
        PyParamoaArray_oaDMAttr p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDMAttr_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaDMAttr, function: append, Choices are:\n"
        "    (oaDMAttr)\n"
        "    (oaArray_oaDMAttr)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDMAttr_find_doc[] = 
"Class: oaArray_oaDMAttr, Function: find\n"
"  Paramegers: (oaDMAttr)\n"
"    Calls: oaUInt4 find(const oaDMAttr& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaDMAttr,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaDMAttr_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDMAttr data;
    int convert_status=PyoaArray_oaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDMAttrObject* self=(PyoaArray_oaDMAttrObject*)ob;

    PyParamoaDMAttr p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMAttr_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDMAttr_remove_doc[] = 
"Class: oaArray_oaDMAttr, Function: remove\n"
"  Paramegers: (oaDMAttr)\n"
"    Calls: void remove(const oaDMAttr& element)\n"
"    Signature: remove|void-void|cref-oaDMAttr,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaDMAttr_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDMAttr data;
    int convert_status=PyoaArray_oaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDMAttrObject* self=(PyoaArray_oaDMAttrObject*)ob;

    PyParamoaDMAttr p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMAttr_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaDMAttr_assign_doc[] = 
"Class: oaArray_oaDMAttr, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaDMAttr_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaDMAttr data;
  int convert_status=PyoaArray_oaDMAttr_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaDMAttr p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaDMAttr_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaDMAttr_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaDMAttr_append,METH_VARARGS,oaArray_oaDMAttr_append_doc},
    {"find",(PyCFunction)oaArray_oaDMAttr_find,METH_VARARGS,oaArray_oaDMAttr_find_doc},
    {"remove",(PyCFunction)oaArray_oaDMAttr_remove,METH_VARARGS,oaArray_oaDMAttr_remove_doc},
    {"assign",(PyCFunction)oaArray_oaDMAttr_tp_assign,METH_VARARGS,oaArray_oaDMAttr_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDMAttr_doc[] = 
"Class: oaArray_oaDMAttr\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaDMAttr()\n"
"    Signature: oaArray_oaDMAttr||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaDMAttr(oaUInt4 size)\n"
"    Signature: oaArray_oaDMAttr||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaDMAttr)\n"
"    Calls: oaArray_oaDMAttr(const oaArray_oaDMAttr& array)\n"
"    Signature: oaArray_oaDMAttr||cref-oaArray_oaDMAttr,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaDMAttr])\n"
"    Calls: oaArray_oaDMAttr(const oaDMAttr* array)\n"
"    Signature: oaArray_oaDMAttr||cptr-oaDMAttr,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaDMAttr)\n"
"    Calls: (const oaArray_oaDMAttr&)\n"
"    Signature: oaArray_oaDMAttr||cref-oaArray_oaDMAttr,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaDMAttr_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaDMAttr",
    sizeof(PyoaArray_oaDMAttrObject),
    0,
    (destructor)oaArray_oaDMAttr_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaDMAttr_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaDMAttr_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaDMAttr_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaDMAttr_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaDMAttr_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaDMAttr_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaDMAttr_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaDMAttr_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaDMAttr\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaDMAttr",
           (PyObject*)(&PyoaArray_oaDMAttr_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaDMAttr\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaDerivedLayerParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDerivedLayerParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaDerivedLayerParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaDerivedLayerParamObject* self = (PyoaArray_oaDerivedLayerParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDerivedLayerParam*)  new oaArray_oaDerivedLayerParam();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDerivedLayerParam*)  new oaArray_oaDerivedLayerParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDerivedLayerParam)
    {
        PyParamoaArray_oaDerivedLayerParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDerivedLayerParam_Convert,&p1)) {
            self->value = (oaArrayBase_oaDerivedLayerParam*)  new oaArray_oaDerivedLayerParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaDerivedLayerParam])
    {
        PyParamoaDerivedLayerParam_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDerivedLayerParam_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaDerivedLayerParam*)  new oaArray_oaDerivedLayerParam(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaDerivedLayerParam, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaDerivedLayerParam)\n"
        "    ([oaDerivedLayerParam])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaDerivedLayerParam_tp_dealloc(PyoaArray_oaDerivedLayerParamObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaDerivedLayerParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDerivedLayerParam_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaDerivedLayerParam value;
    int convert_status=PyoaArray_oaDerivedLayerParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaArray_oaDerivedLayerParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaDerivedLayerParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaDerivedLayerParam v1;
    PyParamoaArray_oaDerivedLayerParam v2;
    int convert_status1=PyoaArray_oaDerivedLayerParam_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaDerivedLayerParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaDerivedLayerParam_Convert(PyObject* ob,PyParamoaArray_oaDerivedLayerParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaDerivedLayerParam_Check(ob)) {
        result->SetData( (oaArray_oaDerivedLayerParam*) ((PyoaArray_oaDerivedLayerParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaDerivedLayerParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaDerivedLayerParam_FromoaArray_oaDerivedLayerParam(oaArray_oaDerivedLayerParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaDerivedLayerParam_Type.tp_alloc(&PyoaArray_oaDerivedLayerParam_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaDerivedLayerParamObject* self = (PyoaArray_oaDerivedLayerParamObject*)bself;
        self->value = (oaArrayBase_oaDerivedLayerParam*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDerivedLayerParam_append_doc[] = 
"Class: oaArray_oaDerivedLayerParam, Function: append\n"
"  Paramegers: (oaDerivedLayerParam)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaDerivedLayerParam,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaDerivedLayerParam)\n"
"    Calls: void append(const oaArray_oaDerivedLayerParam& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaDerivedLayerParam,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaDerivedLayerParam_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDerivedLayerParam data;
    int convert_status=PyoaArray_oaDerivedLayerParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDerivedLayerParamObject* self=(PyoaArray_oaDerivedLayerParamObject*)ob;

    // Case: (oaDerivedLayerParam)
    {
        PyParamoaDerivedLayerParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDerivedLayerParam_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDerivedLayerParam)
    {
        PyParamoaArray_oaDerivedLayerParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDerivedLayerParam_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaDerivedLayerParam, function: append, Choices are:\n"
        "    (oaDerivedLayerParam)\n"
        "    (oaArray_oaDerivedLayerParam)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDerivedLayerParam_find_doc[] = 
"Class: oaArray_oaDerivedLayerParam, Function: find\n"
"  Paramegers: (oaDerivedLayerParam)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaDerivedLayerParam,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaDerivedLayerParam_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDerivedLayerParam data;
    int convert_status=PyoaArray_oaDerivedLayerParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDerivedLayerParamObject* self=(PyoaArray_oaDerivedLayerParamObject*)ob;

    PyParamoaDerivedLayerParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParam_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDerivedLayerParam_remove_doc[] = 
"Class: oaArray_oaDerivedLayerParam, Function: remove\n"
"  Paramegers: (oaDerivedLayerParam)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaDerivedLayerParam,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaDerivedLayerParam_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDerivedLayerParam data;
    int convert_status=PyoaArray_oaDerivedLayerParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDerivedLayerParamObject* self=(PyoaArray_oaDerivedLayerParamObject*)ob;

    PyParamoaDerivedLayerParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParam_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaDerivedLayerParam_assign_doc[] = 
"Class: oaArray_oaDerivedLayerParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaDerivedLayerParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaDerivedLayerParam data;
  int convert_status=PyoaArray_oaDerivedLayerParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaDerivedLayerParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaDerivedLayerParam_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaDerivedLayerParam_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaDerivedLayerParam_append,METH_VARARGS,oaArray_oaDerivedLayerParam_append_doc},
    {"find",(PyCFunction)oaArray_oaDerivedLayerParam_find,METH_VARARGS,oaArray_oaDerivedLayerParam_find_doc},
    {"remove",(PyCFunction)oaArray_oaDerivedLayerParam_remove,METH_VARARGS,oaArray_oaDerivedLayerParam_remove_doc},
    {"assign",(PyCFunction)oaArray_oaDerivedLayerParam_tp_assign,METH_VARARGS,oaArray_oaDerivedLayerParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDerivedLayerParam_doc[] = 
"Class: oaArray_oaDerivedLayerParam\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaDerivedLayerParam()\n"
"    Signature: oaArray_oaDerivedLayerParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaDerivedLayerParam(oaUInt4 size)\n"
"    Signature: oaArray_oaDerivedLayerParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaDerivedLayerParam)\n"
"    Calls: oaArray_oaDerivedLayerParam(const oaArray_oaDerivedLayerParam& array)\n"
"    Signature: oaArray_oaDerivedLayerParam||cref-oaArray_oaDerivedLayerParam,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaDerivedLayerParam])\n"
"    Calls: oaArray_oaDerivedLayerParam( array)\n"
"    Signature: oaArray_oaDerivedLayerParam||cpptr-oaDerivedLayerParam,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaDerivedLayerParam)\n"
"    Calls: (const oaArray_oaDerivedLayerParam&)\n"
"    Signature: oaArray_oaDerivedLayerParam||cref-oaArray_oaDerivedLayerParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaDerivedLayerParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaDerivedLayerParam",
    sizeof(PyoaArray_oaDerivedLayerParamObject),
    0,
    (destructor)oaArray_oaDerivedLayerParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaDerivedLayerParam_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaDerivedLayerParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaDerivedLayerParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaDerivedLayerParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaDerivedLayerParam_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaDerivedLayerParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaDerivedLayerParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaDerivedLayerParam_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaDerivedLayerParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaDerivedLayerParam",
           (PyObject*)(&PyoaArray_oaDerivedLayerParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaDerivedLayerParam\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaDesignObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDesignObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaDesignObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaDesignObjectObject* self = (PyoaArray_oaDesignObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaArray_oaDesignObject();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaArray_oaDesignObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDesignObject)
    {
        PyParamoaArray_oaDesignObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDesignObject_Convert,&p1)) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaArray_oaDesignObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaDesignObject])
    {
        PyParamoaDesignObject_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDesignObject_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaArray_oaDesignObject(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaDesignObject, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaDesignObject)\n"
        "    ([oaDesignObject])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaDesignObject_tp_dealloc(PyoaArray_oaDesignObjectObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaDesignObject*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDesignObject_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaDesignObject value;
    int convert_status=PyoaArray_oaDesignObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaArray_oaDesignObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaDesignObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaDesignObject v1;
    PyParamoaArray_oaDesignObject v2;
    int convert_status1=PyoaArray_oaDesignObject_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaDesignObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaDesignObject_Convert(PyObject* ob,PyParamoaArray_oaDesignObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaDesignObject_Check(ob)) {
        result->SetData( (oaArray_oaDesignObject*) ((PyoaArray_oaDesignObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaDesignObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaDesignObject_FromoaArray_oaDesignObject(oaArray_oaDesignObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaDesignObject_Type.tp_alloc(&PyoaArray_oaDesignObject_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaDesignObjectObject* self = (PyoaArray_oaDesignObjectObject*)bself;
        self->value = (oaArrayBase_oaDesignObject*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDesignObject_append_doc[] = 
"Class: oaArray_oaDesignObject, Function: append\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaDesignObject,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaDesignObject)\n"
"    Calls: void append(const oaArray_oaDesignObject& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaDesignObject,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaDesignObject_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDesignObject data;
    int convert_status=PyoaArray_oaDesignObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDesignObjectObject* self=(PyoaArray_oaDesignObjectObject*)ob;

    // Case: (oaDesignObject)
    {
        PyParamoaDesignObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDesignObject_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDesignObject)
    {
        PyParamoaArray_oaDesignObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDesignObject_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaDesignObject, function: append, Choices are:\n"
        "    (oaDesignObject)\n"
        "    (oaArray_oaDesignObject)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDesignObject_find_doc[] = 
"Class: oaArray_oaDesignObject, Function: find\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaDesignObject,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaDesignObject_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDesignObject data;
    int convert_status=PyoaArray_oaDesignObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDesignObjectObject* self=(PyoaArray_oaDesignObjectObject*)ob;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDesignObject_remove_doc[] = 
"Class: oaArray_oaDesignObject, Function: remove\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaDesignObject,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaDesignObject_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDesignObject data;
    int convert_status=PyoaArray_oaDesignObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDesignObjectObject* self=(PyoaArray_oaDesignObjectObject*)ob;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaDesignObject_assign_doc[] = 
"Class: oaArray_oaDesignObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaDesignObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaDesignObject data;
  int convert_status=PyoaArray_oaDesignObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaDesignObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaDesignObject_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaDesignObject_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaDesignObject_append,METH_VARARGS,oaArray_oaDesignObject_append_doc},
    {"find",(PyCFunction)oaArray_oaDesignObject_find,METH_VARARGS,oaArray_oaDesignObject_find_doc},
    {"remove",(PyCFunction)oaArray_oaDesignObject_remove,METH_VARARGS,oaArray_oaDesignObject_remove_doc},
    {"assign",(PyCFunction)oaArray_oaDesignObject_tp_assign,METH_VARARGS,oaArray_oaDesignObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDesignObject_doc[] = 
"Class: oaArray_oaDesignObject\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaDesignObject()\n"
"    Signature: oaArray_oaDesignObject||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaDesignObject(oaUInt4 size)\n"
"    Signature: oaArray_oaDesignObject||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaDesignObject)\n"
"    Calls: oaArray_oaDesignObject(const oaArray_oaDesignObject& array)\n"
"    Signature: oaArray_oaDesignObject||cref-oaArray_oaDesignObject,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaDesignObject])\n"
"    Calls: oaArray_oaDesignObject( array)\n"
"    Signature: oaArray_oaDesignObject||cpptr-oaDesignObject,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaDesignObject)\n"
"    Calls: (const oaArray_oaDesignObject&)\n"
"    Signature: oaArray_oaDesignObject||cref-oaArray_oaDesignObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaDesignObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaDesignObject",
    sizeof(PyoaArray_oaDesignObjectObject),
    0,
    (destructor)oaArray_oaDesignObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaDesignObject_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaDesignObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaDesignObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaDesignObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaDesignObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaDesignObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaDesignObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaDesignObject_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaDesignObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaDesignObject",
           (PyObject*)(&PyoaArray_oaDesignObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaDesignObject\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaDualInt
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDualInt_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaDualInt_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaDualIntObject* self = (PyoaArray_oaDualIntObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDualInt*)  new oaArray_oaDualInt();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDualInt*)  new oaArray_oaDualInt(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDualInt)
    {
        PyParamoaArray_oaDualInt p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDualInt_Convert,&p1)) {
            self->value = (oaArrayBase_oaDualInt*)  new oaArray_oaDualInt(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaDualInt])
    {
        PyParamoaDualInt_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDualInt_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaDualInt*)  new oaArray_oaDualInt(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaDualInt, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaDualInt)\n"
        "    ([oaDualInt])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaDualInt_tp_dealloc(PyoaArray_oaDualIntObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaDualInt*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaDualInt_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaDualInt value;
    int convert_status=PyoaArray_oaDualInt_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaArray_oaDualInt::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaDualInt_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaDualInt v1;
    PyParamoaArray_oaDualInt v2;
    int convert_status1=PyoaArray_oaDualInt_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaDualInt_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaDualInt_Convert(PyObject* ob,PyParamoaArray_oaDualInt* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaDualInt_Check(ob)) {
        result->SetData( (oaArray_oaDualInt*) ((PyoaArray_oaDualIntObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaDualInt Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaDualInt_FromoaArray_oaDualInt(oaArray_oaDualInt* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaDualInt_Type.tp_alloc(&PyoaArray_oaDualInt_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaDualIntObject* self = (PyoaArray_oaDualIntObject*)bself;
        self->value = (oaArrayBase_oaDualInt*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDualInt_append_doc[] = 
"Class: oaArray_oaDualInt, Function: append\n"
"  Paramegers: (oaDualInt)\n"
"    Calls: void append(const oaDualInt& element)\n"
"    Signature: append|void-void|cref-oaDualInt,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaDualInt)\n"
"    Calls: void append(const oaArray_oaDualInt& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaDualInt,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaDualInt_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDualInt data;
    int convert_status=PyoaArray_oaDualInt_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDualIntObject* self=(PyoaArray_oaDualIntObject*)ob;

    // Case: (oaDualInt)
    {
        PyParamoaDualInt p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDualInt_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaDualInt)
    {
        PyParamoaArray_oaDualInt p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaDualInt_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaDualInt, function: append, Choices are:\n"
        "    (oaDualInt)\n"
        "    (oaArray_oaDualInt)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDualInt_find_doc[] = 
"Class: oaArray_oaDualInt, Function: find\n"
"  Paramegers: (oaDualInt)\n"
"    Calls: oaUInt4 find(const oaDualInt& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaDualInt,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaDualInt_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDualInt data;
    int convert_status=PyoaArray_oaDualInt_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDualIntObject* self=(PyoaArray_oaDualIntObject*)ob;

    PyParamoaDualInt p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDualInt_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaDualInt_remove_doc[] = 
"Class: oaArray_oaDualInt, Function: remove\n"
"  Paramegers: (oaDualInt)\n"
"    Calls: void remove(const oaDualInt& element)\n"
"    Signature: remove|void-void|cref-oaDualInt,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaDualInt_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaDualInt data;
    int convert_status=PyoaArray_oaDualInt_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaDualIntObject* self=(PyoaArray_oaDualIntObject*)ob;

    PyParamoaDualInt p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDualInt_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaDualInt_assign_doc[] = 
"Class: oaArray_oaDualInt, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaDualInt_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaDualInt data;
  int convert_status=PyoaArray_oaDualInt_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaDualInt p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaDualInt_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaDualInt_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaDualInt_append,METH_VARARGS,oaArray_oaDualInt_append_doc},
    {"find",(PyCFunction)oaArray_oaDualInt_find,METH_VARARGS,oaArray_oaDualInt_find_doc},
    {"remove",(PyCFunction)oaArray_oaDualInt_remove,METH_VARARGS,oaArray_oaDualInt_remove_doc},
    {"assign",(PyCFunction)oaArray_oaDualInt_tp_assign,METH_VARARGS,oaArray_oaDualInt_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaDualInt_doc[] = 
"Class: oaArray_oaDualInt\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaDualInt()\n"
"    Signature: oaArray_oaDualInt||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaDualInt(oaUInt4 size)\n"
"    Signature: oaArray_oaDualInt||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaDualInt)\n"
"    Calls: oaArray_oaDualInt(const oaArray_oaDualInt& array)\n"
"    Signature: oaArray_oaDualInt||cref-oaArray_oaDualInt,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaDualInt])\n"
"    Calls: oaArray_oaDualInt(const oaDualInt* array)\n"
"    Signature: oaArray_oaDualInt||cptr-oaDualInt,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaDualInt)\n"
"    Calls: (const oaArray_oaDualInt&)\n"
"    Signature: oaArray_oaDualInt||cref-oaArray_oaDualInt,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaDualInt_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaDualInt",
    sizeof(PyoaArray_oaDualIntObject),
    0,
    (destructor)oaArray_oaDualInt_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaDualInt_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaDualInt_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaDualInt_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaDualInt_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaDualInt_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaDualInt_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaDualInt_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaDualInt_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaDualInt\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaDualInt",
           (PyObject*)(&PyoaArray_oaDualInt_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaDualInt\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaFeature
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaFeature_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaFeature_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaFeatureObject* self = (PyoaArray_oaFeatureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaFeature*)  new oaArray_oaFeature();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaFeature*)  new oaArray_oaFeature(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaFeature)
    {
        PyParamoaArray_oaFeature p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaFeature_Convert,&p1)) {
            self->value = (oaArrayBase_oaFeature*)  new oaArray_oaFeature(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaFeature])
    {
        PyParamoaFeature_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaFeature_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaFeature*)  new oaArray_oaFeature(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaFeature, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaFeature)\n"
        "    ([oaFeature])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaFeature_tp_dealloc(PyoaArray_oaFeatureObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaFeature*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaFeature_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaFeature value;
    int convert_status=PyoaArray_oaFeature_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaArray_oaFeature::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaFeature_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaFeature v1;
    PyParamoaArray_oaFeature v2;
    int convert_status1=PyoaArray_oaFeature_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaFeature_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaFeature_Convert(PyObject* ob,PyParamoaArray_oaFeature* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaFeature_Check(ob)) {
        result->SetData( (oaArray_oaFeature*) ((PyoaArray_oaFeatureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaFeature Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaFeature_FromoaArray_oaFeature(oaArray_oaFeature* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaFeature_Type.tp_alloc(&PyoaArray_oaFeature_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaFeatureObject* self = (PyoaArray_oaFeatureObject*)bself;
        self->value = (oaArrayBase_oaFeature*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaFeature_append_doc[] = 
"Class: oaArray_oaFeature, Function: append\n"
"  Paramegers: (oaFeature)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaFeature,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaFeature)\n"
"    Calls: void append(const oaArray_oaFeature& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaFeature,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaFeature_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFeature data;
    int convert_status=PyoaArray_oaFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFeatureObject* self=(PyoaArray_oaFeatureObject*)ob;

    // Case: (oaFeature)
    {
        PyParamoaFeature p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaFeature_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaFeature)
    {
        PyParamoaArray_oaFeature p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaFeature_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaFeature, function: append, Choices are:\n"
        "    (oaFeature)\n"
        "    (oaArray_oaFeature)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaFeature_find_doc[] = 
"Class: oaArray_oaFeature, Function: find\n"
"  Paramegers: (oaFeature)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaFeature,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaFeature_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFeature data;
    int convert_status=PyoaArray_oaFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFeatureObject* self=(PyoaArray_oaFeatureObject*)ob;

    PyParamoaFeature p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFeature_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaFeature_remove_doc[] = 
"Class: oaArray_oaFeature, Function: remove\n"
"  Paramegers: (oaFeature)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaFeature,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaFeature_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFeature data;
    int convert_status=PyoaArray_oaFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFeatureObject* self=(PyoaArray_oaFeatureObject*)ob;

    PyParamoaFeature p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFeature_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaFeature_assign_doc[] = 
"Class: oaArray_oaFeature, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaFeature_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaFeature data;
  int convert_status=PyoaArray_oaFeature_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaFeature p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaFeature_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaFeature_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaFeature_append,METH_VARARGS,oaArray_oaFeature_append_doc},
    {"find",(PyCFunction)oaArray_oaFeature_find,METH_VARARGS,oaArray_oaFeature_find_doc},
    {"remove",(PyCFunction)oaArray_oaFeature_remove,METH_VARARGS,oaArray_oaFeature_remove_doc},
    {"assign",(PyCFunction)oaArray_oaFeature_tp_assign,METH_VARARGS,oaArray_oaFeature_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaFeature_doc[] = 
"Class: oaArray_oaFeature\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaFeature()\n"
"    Signature: oaArray_oaFeature||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaFeature(oaUInt4 size)\n"
"    Signature: oaArray_oaFeature||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaFeature)\n"
"    Calls: oaArray_oaFeature(const oaArray_oaFeature& array)\n"
"    Signature: oaArray_oaFeature||cref-oaArray_oaFeature,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaFeature])\n"
"    Calls: oaArray_oaFeature( array)\n"
"    Signature: oaArray_oaFeature||cpptr-oaFeature,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaFeature)\n"
"    Calls: (const oaArray_oaFeature&)\n"
"    Signature: oaArray_oaFeature||cref-oaArray_oaFeature,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaFeature_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaFeature",
    sizeof(PyoaArray_oaFeatureObject),
    0,
    (destructor)oaArray_oaFeature_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaFeature_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaFeature_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaFeature_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaFeature_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaFeature_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaFeature_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaFeature_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaFeature_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaFeature\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaFeature",
           (PyObject*)(&PyoaArray_oaFeature_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaFeature\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaFig
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaFig_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaFig_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaFigObject* self = (PyoaArray_oaFigObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaFig*)  new oaArray_oaFig();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaFig*)  new oaArray_oaFig(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaFig)
    {
        PyParamoaArray_oaFig p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaFig_Convert,&p1)) {
            self->value = (oaArrayBase_oaFig*)  new oaArray_oaFig(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaFig])
    {
        PyParamoaFig_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaFig_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaFig*)  new oaArray_oaFig(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaFig, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaFig)\n"
        "    ([oaFig])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaFig_tp_dealloc(PyoaArray_oaFigObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaFig*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaFig_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaFig value;
    int convert_status=PyoaArray_oaFig_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaArray_oaFig::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaFig_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaFig v1;
    PyParamoaArray_oaFig v2;
    int convert_status1=PyoaArray_oaFig_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaFig_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaFig_Convert(PyObject* ob,PyParamoaArray_oaFig* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaFig_Check(ob)) {
        result->SetData( (oaArray_oaFig*) ((PyoaArray_oaFigObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaFig Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaFig_FromoaArray_oaFig(oaArray_oaFig* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaFig_Type.tp_alloc(&PyoaArray_oaFig_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaFigObject* self = (PyoaArray_oaFigObject*)bself;
        self->value = (oaArrayBase_oaFig*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaFig_append_doc[] = 
"Class: oaArray_oaFig, Function: append\n"
"  Paramegers: (oaFig)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaFig,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaFig)\n"
"    Calls: void append(const oaArray_oaFig& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaFig,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaFig_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFig data;
    int convert_status=PyoaArray_oaFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFigObject* self=(PyoaArray_oaFigObject*)ob;

    // Case: (oaFig)
    {
        PyParamoaFig p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaFig_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaFig)
    {
        PyParamoaArray_oaFig p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaFig_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaFig, function: append, Choices are:\n"
        "    (oaFig)\n"
        "    (oaArray_oaFig)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaFig_find_doc[] = 
"Class: oaArray_oaFig, Function: find\n"
"  Paramegers: (oaFig)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaFig,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaFig_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFig data;
    int convert_status=PyoaArray_oaFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFigObject* self=(PyoaArray_oaFigObject*)ob;

    PyParamoaFig p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFig_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaFig_remove_doc[] = 
"Class: oaArray_oaFig, Function: remove\n"
"  Paramegers: (oaFig)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaFig,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaFig_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaFig data;
    int convert_status=PyoaArray_oaFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaFigObject* self=(PyoaArray_oaFigObject*)ob;

    PyParamoaFig p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFig_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaFig_assign_doc[] = 
"Class: oaArray_oaFig, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaFig_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaFig data;
  int convert_status=PyoaArray_oaFig_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaFig p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaFig_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaFig_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaFig_append,METH_VARARGS,oaArray_oaFig_append_doc},
    {"find",(PyCFunction)oaArray_oaFig_find,METH_VARARGS,oaArray_oaFig_find_doc},
    {"remove",(PyCFunction)oaArray_oaFig_remove,METH_VARARGS,oaArray_oaFig_remove_doc},
    {"assign",(PyCFunction)oaArray_oaFig_tp_assign,METH_VARARGS,oaArray_oaFig_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaFig_doc[] = 
"Class: oaArray_oaFig\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaFig()\n"
"    Signature: oaArray_oaFig||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaFig(oaUInt4 size)\n"
"    Signature: oaArray_oaFig||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaFig)\n"
"    Calls: oaArray_oaFig(const oaArray_oaFig& array)\n"
"    Signature: oaArray_oaFig||cref-oaArray_oaFig,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaFig])\n"
"    Calls: oaArray_oaFig( array)\n"
"    Signature: oaArray_oaFig||cpptr-oaFig,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaFig)\n"
"    Calls: (const oaArray_oaFig&)\n"
"    Signature: oaArray_oaFig||cref-oaArray_oaFig,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaFig_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaFig",
    sizeof(PyoaArray_oaFigObject),
    0,
    (destructor)oaArray_oaFig_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaFig_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaFig_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaFig_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaFig_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaFig_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaFig_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaFig_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaFig\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaFig",
           (PyObject*)(&PyoaArray_oaFig_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaFig\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaLayerMap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLayerMap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaLayerMap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaLayerMapObject* self = (PyoaArray_oaLayerMapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaArray_oaLayerMap();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaArray_oaLayerMap(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLayerMap)
    {
        PyParamoaArray_oaLayerMap p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLayerMap_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaArray_oaLayerMap(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaLayerMap])
    {
        PyParamoaLayerMap_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerMap_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaArray_oaLayerMap(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaLayerMap, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaLayerMap)\n"
        "    ([oaLayerMap])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaLayerMap_tp_dealloc(PyoaArray_oaLayerMapObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaLayerMap*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLayerMap_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaLayerMap value;
    int convert_status=PyoaArray_oaLayerMap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaArray_oaLayerMap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaLayerMap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaLayerMap v1;
    PyParamoaArray_oaLayerMap v2;
    int convert_status1=PyoaArray_oaLayerMap_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaLayerMap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaLayerMap_Convert(PyObject* ob,PyParamoaArray_oaLayerMap* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaLayerMap_Check(ob)) {
        result->SetData( (oaArray_oaLayerMap*) ((PyoaArray_oaLayerMapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaLayerMap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaLayerMap_FromoaArray_oaLayerMap(oaArray_oaLayerMap* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaLayerMap_Type.tp_alloc(&PyoaArray_oaLayerMap_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaLayerMapObject* self = (PyoaArray_oaLayerMapObject*)bself;
        self->value = (oaArrayBase_oaLayerMap*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLayerMap_append_doc[] = 
"Class: oaArray_oaLayerMap, Function: append\n"
"  Paramegers: (oaLayerMap)\n"
"    Calls: void append(const oaLayerMap& element)\n"
"    Signature: append|void-void|cref-oaLayerMap,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaLayerMap)\n"
"    Calls: void append(const oaArray_oaLayerMap& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaLayerMap,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaLayerMap_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerMap data;
    int convert_status=PyoaArray_oaLayerMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerMapObject* self=(PyoaArray_oaLayerMapObject*)ob;

    // Case: (oaLayerMap)
    {
        PyParamoaLayerMap p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerMap_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLayerMap)
    {
        PyParamoaArray_oaLayerMap p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLayerMap_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaLayerMap, function: append, Choices are:\n"
        "    (oaLayerMap)\n"
        "    (oaArray_oaLayerMap)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLayerMap_find_doc[] = 
"Class: oaArray_oaLayerMap, Function: find\n"
"  Paramegers: (oaLayerMap)\n"
"    Calls: oaUInt4 find(const oaLayerMap& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaLayerMap,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaLayerMap_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerMap data;
    int convert_status=PyoaArray_oaLayerMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerMapObject* self=(PyoaArray_oaLayerMapObject*)ob;

    PyParamoaLayerMap p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerMap_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLayerMap_remove_doc[] = 
"Class: oaArray_oaLayerMap, Function: remove\n"
"  Paramegers: (oaLayerMap)\n"
"    Calls: void remove(const oaLayerMap& element)\n"
"    Signature: remove|void-void|cref-oaLayerMap,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaLayerMap_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerMap data;
    int convert_status=PyoaArray_oaLayerMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerMapObject* self=(PyoaArray_oaLayerMapObject*)ob;

    PyParamoaLayerMap p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerMap_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaLayerMap_assign_doc[] = 
"Class: oaArray_oaLayerMap, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaLayerMap_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaLayerMap data;
  int convert_status=PyoaArray_oaLayerMap_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaLayerMap p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaLayerMap_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaLayerMap_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaLayerMap_append,METH_VARARGS,oaArray_oaLayerMap_append_doc},
    {"find",(PyCFunction)oaArray_oaLayerMap_find,METH_VARARGS,oaArray_oaLayerMap_find_doc},
    {"remove",(PyCFunction)oaArray_oaLayerMap_remove,METH_VARARGS,oaArray_oaLayerMap_remove_doc},
    {"assign",(PyCFunction)oaArray_oaLayerMap_tp_assign,METH_VARARGS,oaArray_oaLayerMap_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLayerMap_doc[] = 
"Class: oaArray_oaLayerMap\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaLayerMap()\n"
"    Signature: oaArray_oaLayerMap||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaLayerMap(oaUInt4 size)\n"
"    Signature: oaArray_oaLayerMap||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaLayerMap)\n"
"    Calls: oaArray_oaLayerMap(const oaArray_oaLayerMap& array)\n"
"    Signature: oaArray_oaLayerMap||cref-oaArray_oaLayerMap,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaLayerMap])\n"
"    Calls: oaArray_oaLayerMap(const oaLayerMap* array)\n"
"    Signature: oaArray_oaLayerMap||cptr-oaLayerMap,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaLayerMap)\n"
"    Calls: (const oaArray_oaLayerMap&)\n"
"    Signature: oaArray_oaLayerMap||cref-oaArray_oaLayerMap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaLayerMap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaLayerMap",
    sizeof(PyoaArray_oaLayerMapObject),
    0,
    (destructor)oaArray_oaLayerMap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaLayerMap_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaLayerMap_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaLayerMap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaLayerMap_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaLayerMap_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaLayerMap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaLayerMap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaLayerMap_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaLayerMap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaLayerMap",
           (PyObject*)(&PyoaArray_oaLayerMap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaLayerMap\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaLayerNum
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLayerNum_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaLayerNum_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaLayerNumObject* self = (PyoaArray_oaLayerNumObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaArray_oaLayerNum();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaArray_oaLayerNum(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLayerNum)
    {
        PyParamoaArray_oaLayerNum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLayerNum_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaArray_oaLayerNum(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaLayerNum])
    {
        PyParamoaLayerNum_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerNum_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaArray_oaLayerNum(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaLayerNum, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaLayerNum)\n"
        "    ([oaLayerNum])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaLayerNum_tp_dealloc(PyoaArray_oaLayerNumObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaLayerNum*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLayerNum_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaLayerNum value;
    int convert_status=PyoaArray_oaLayerNum_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaArray_oaLayerNum::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaLayerNum_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaLayerNum v1;
    PyParamoaArray_oaLayerNum v2;
    int convert_status1=PyoaArray_oaLayerNum_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaLayerNum_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaLayerNum_Convert(PyObject* ob,PyParamoaArray_oaLayerNum* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaLayerNum_Check(ob)) {
        result->SetData( (oaArray_oaLayerNum*) ((PyoaArray_oaLayerNumObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaLayerNum Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaLayerNum_FromoaArray_oaLayerNum(oaArray_oaLayerNum* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaLayerNum_Type.tp_alloc(&PyoaArray_oaLayerNum_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaLayerNumObject* self = (PyoaArray_oaLayerNumObject*)bself;
        self->value = (oaArrayBase_oaLayerNum*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLayerNum_append_doc[] = 
"Class: oaArray_oaLayerNum, Function: append\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void append(const oaLayerNum& element)\n"
"    Signature: append|void-void|cref-oaLayerNum,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaLayerNum)\n"
"    Calls: void append(const oaArray_oaLayerNum& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaLayerNum,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaLayerNum_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerNum data;
    int convert_status=PyoaArray_oaLayerNum_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerNumObject* self=(PyoaArray_oaLayerNumObject*)ob;

    // Case: (oaLayerNum)
    {
        PyParamoaLayerNum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerNum_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLayerNum)
    {
        PyParamoaArray_oaLayerNum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLayerNum_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaLayerNum, function: append, Choices are:\n"
        "    (oaLayerNum)\n"
        "    (oaArray_oaLayerNum)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLayerNum_find_doc[] = 
"Class: oaArray_oaLayerNum, Function: find\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: oaUInt4 find(const oaLayerNum& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaLayerNum,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaLayerNum_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerNum data;
    int convert_status=PyoaArray_oaLayerNum_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerNumObject* self=(PyoaArray_oaLayerNumObject*)ob;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLayerNum_remove_doc[] = 
"Class: oaArray_oaLayerNum, Function: remove\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void remove(const oaLayerNum& element)\n"
"    Signature: remove|void-void|cref-oaLayerNum,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaLayerNum_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLayerNum data;
    int convert_status=PyoaArray_oaLayerNum_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLayerNumObject* self=(PyoaArray_oaLayerNumObject*)ob;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaLayerNum_assign_doc[] = 
"Class: oaArray_oaLayerNum, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaLayerNum_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaLayerNum data;
  int convert_status=PyoaArray_oaLayerNum_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaLayerNum p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaLayerNum_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaLayerNum_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaLayerNum_append,METH_VARARGS,oaArray_oaLayerNum_append_doc},
    {"find",(PyCFunction)oaArray_oaLayerNum_find,METH_VARARGS,oaArray_oaLayerNum_find_doc},
    {"remove",(PyCFunction)oaArray_oaLayerNum_remove,METH_VARARGS,oaArray_oaLayerNum_remove_doc},
    {"assign",(PyCFunction)oaArray_oaLayerNum_tp_assign,METH_VARARGS,oaArray_oaLayerNum_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLayerNum_doc[] = 
"Class: oaArray_oaLayerNum\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaLayerNum()\n"
"    Signature: oaArray_oaLayerNum||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaLayerNum(oaUInt4 size)\n"
"    Signature: oaArray_oaLayerNum||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaLayerNum)\n"
"    Calls: oaArray_oaLayerNum(const oaArray_oaLayerNum& array)\n"
"    Signature: oaArray_oaLayerNum||cref-oaArray_oaLayerNum,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaLayerNum])\n"
"    Calls: oaArray_oaLayerNum(const oaLayerNum* array)\n"
"    Signature: oaArray_oaLayerNum||cptr-oaLayerNum,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaLayerNum)\n"
"    Calls: (const oaArray_oaLayerNum&)\n"
"    Signature: oaArray_oaLayerNum||cref-oaArray_oaLayerNum,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaLayerNum_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaLayerNum",
    sizeof(PyoaArray_oaLayerNumObject),
    0,
    (destructor)oaArray_oaLayerNum_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaLayerNum_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaLayerNum_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaLayerNum_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaLayerNum_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaLayerNum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaLayerNum_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaLayerNum_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaLayerNum_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaLayerNum\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaLayerNum",
           (PyObject*)(&PyoaArray_oaLayerNum_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaLayerNum\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaLibObject* self = (PyoaArray_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLib*)  new oaArray_oaLib();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLib*)  new oaArray_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLib)
    {
        PyParamoaArray_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLib_Convert,&p1)) {
            self->value = (oaArrayBase_oaLib*)  new oaArray_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaLib])
    {
        PyParamoaLib_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLib_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaLib*)  new oaArray_oaLib(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaLib, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaLib)\n"
        "    ([oaLib])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaLib_tp_dealloc(PyoaArray_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaLib value;
    int convert_status=PyoaArray_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaArray_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaLib v1;
    PyParamoaArray_oaLib v2;
    int convert_status1=PyoaArray_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaLib_Convert(PyObject* ob,PyParamoaArray_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaLib_Check(ob)) {
        result->SetData( (oaArray_oaLib*) ((PyoaArray_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaLib_FromoaArray_oaLib(oaArray_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaLib_Type.tp_alloc(&PyoaArray_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaLibObject* self = (PyoaArray_oaLibObject*)bself;
        self->value = (oaArrayBase_oaLib*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLib_append_doc[] = 
"Class: oaArray_oaLib, Function: append\n"
"  Paramegers: (oaLib)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaLib,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaLib)\n"
"    Calls: void append(const oaArray_oaLib& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaLib,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaLib_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLib data;
    int convert_status=PyoaArray_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLibObject* self=(PyoaArray_oaLibObject*)ob;

    // Case: (oaLib)
    {
        PyParamoaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLib_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaLib)
    {
        PyParamoaArray_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaLib_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaLib, function: append, Choices are:\n"
        "    (oaLib)\n"
        "    (oaArray_oaLib)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLib_find_doc[] = 
"Class: oaArray_oaLib, Function: find\n"
"  Paramegers: (oaLib)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaLib,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaLib_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLib data;
    int convert_status=PyoaArray_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLibObject* self=(PyoaArray_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaLib_remove_doc[] = 
"Class: oaArray_oaLib, Function: remove\n"
"  Paramegers: (oaLib)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaLib,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaLib_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaLib data;
    int convert_status=PyoaArray_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaLibObject* self=(PyoaArray_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaLib_assign_doc[] = 
"Class: oaArray_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaLib data;
  int convert_status=PyoaArray_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaLib_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaLib_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaLib_append,METH_VARARGS,oaArray_oaLib_append_doc},
    {"find",(PyCFunction)oaArray_oaLib_find,METH_VARARGS,oaArray_oaLib_find_doc},
    {"remove",(PyCFunction)oaArray_oaLib_remove,METH_VARARGS,oaArray_oaLib_remove_doc},
    {"assign",(PyCFunction)oaArray_oaLib_tp_assign,METH_VARARGS,oaArray_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaLib_doc[] = 
"Class: oaArray_oaLib\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaLib()\n"
"    Signature: oaArray_oaLib||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaLib(oaUInt4 size)\n"
"    Signature: oaArray_oaLib||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaLib)\n"
"    Calls: oaArray_oaLib(const oaArray_oaLib& array)\n"
"    Signature: oaArray_oaLib||cref-oaArray_oaLib,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaLib])\n"
"    Calls: oaArray_oaLib( array)\n"
"    Signature: oaArray_oaLib||cpptr-oaLib,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaLib)\n"
"    Calls: (const oaArray_oaLib&)\n"
"    Signature: oaArray_oaLib||cref-oaArray_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaLib",
    sizeof(PyoaArray_oaLibObject),
    0,
    (destructor)oaArray_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaLib_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaLib",
           (PyObject*)(&PyoaArray_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaLib\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaModTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaModTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaModTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaModTermObject* self = (PyoaArray_oaModTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaModTerm*)  new oaArray_oaModTerm();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaModTerm*)  new oaArray_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaModTerm)
    {
        PyParamoaArray_oaModTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaModTerm_Convert,&p1)) {
            self->value = (oaArrayBase_oaModTerm*)  new oaArray_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaModTerm])
    {
        PyParamoaModTerm_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaModTerm_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaModTerm*)  new oaArray_oaModTerm(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaModTerm, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaModTerm)\n"
        "    ([oaModTerm])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaModTerm_tp_dealloc(PyoaArray_oaModTermObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaModTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaModTerm_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaModTerm value;
    int convert_status=PyoaArray_oaModTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaArray_oaModTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaModTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaModTerm v1;
    PyParamoaArray_oaModTerm v2;
    int convert_status1=PyoaArray_oaModTerm_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaModTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaModTerm_Convert(PyObject* ob,PyParamoaArray_oaModTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaModTerm_Check(ob)) {
        result->SetData( (oaArray_oaModTerm*) ((PyoaArray_oaModTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaModTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaModTerm_FromoaArray_oaModTerm(oaArray_oaModTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaModTerm_Type.tp_alloc(&PyoaArray_oaModTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaModTermObject* self = (PyoaArray_oaModTermObject*)bself;
        self->value = (oaArrayBase_oaModTerm*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaModTerm_append_doc[] = 
"Class: oaArray_oaModTerm, Function: append\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaModTerm,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaModTerm)\n"
"    Calls: void append(const oaArray_oaModTerm& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaModTerm,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaModTerm_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaModTerm data;
    int convert_status=PyoaArray_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaModTermObject* self=(PyoaArray_oaModTermObject*)ob;

    // Case: (oaModTerm)
    {
        PyParamoaModTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaModTerm_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaModTerm)
    {
        PyParamoaArray_oaModTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaModTerm_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaModTerm, function: append, Choices are:\n"
        "    (oaModTerm)\n"
        "    (oaArray_oaModTerm)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaModTerm_find_doc[] = 
"Class: oaArray_oaModTerm, Function: find\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaModTerm,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaModTerm_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaModTerm data;
    int convert_status=PyoaArray_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaModTermObject* self=(PyoaArray_oaModTermObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaModTerm_remove_doc[] = 
"Class: oaArray_oaModTerm, Function: remove\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaModTerm,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaModTerm_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaModTerm data;
    int convert_status=PyoaArray_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaModTermObject* self=(PyoaArray_oaModTermObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaModTerm_assign_doc[] = 
"Class: oaArray_oaModTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaModTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaModTerm data;
  int convert_status=PyoaArray_oaModTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaModTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaModTerm_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaModTerm_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaModTerm_append,METH_VARARGS,oaArray_oaModTerm_append_doc},
    {"find",(PyCFunction)oaArray_oaModTerm_find,METH_VARARGS,oaArray_oaModTerm_find_doc},
    {"remove",(PyCFunction)oaArray_oaModTerm_remove,METH_VARARGS,oaArray_oaModTerm_remove_doc},
    {"assign",(PyCFunction)oaArray_oaModTerm_tp_assign,METH_VARARGS,oaArray_oaModTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaModTerm_doc[] = 
"Class: oaArray_oaModTerm\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaModTerm()\n"
"    Signature: oaArray_oaModTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaModTerm(oaUInt4 size)\n"
"    Signature: oaArray_oaModTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaModTerm)\n"
"    Calls: oaArray_oaModTerm(const oaArray_oaModTerm& array)\n"
"    Signature: oaArray_oaModTerm||cref-oaArray_oaModTerm,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaModTerm])\n"
"    Calls: oaArray_oaModTerm( array)\n"
"    Signature: oaArray_oaModTerm||cpptr-oaModTerm,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaModTerm)\n"
"    Calls: (const oaArray_oaModTerm&)\n"
"    Signature: oaArray_oaModTerm||cref-oaArray_oaModTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaModTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaModTerm",
    sizeof(PyoaArray_oaModTermObject),
    0,
    (destructor)oaArray_oaModTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaModTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaModTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaModTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaModTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaModTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaModTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaModTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaModTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaModTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaModTerm",
           (PyObject*)(&PyoaArray_oaModTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaModTerm\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaObjectObject* self = (PyoaArray_oaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaObject*)  new oaArray_oaObject();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaObject*)  new oaArray_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaObject)
    {
        PyParamoaArray_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaObject_Convert,&p1)) {
            self->value = (oaArrayBase_oaObject*)  new oaArray_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaObject])
    {
        PyParamoaObject_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaObject_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaObject*)  new oaArray_oaObject(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaObject, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaObject)\n"
        "    ([oaObject])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaObject_tp_dealloc(PyoaArray_oaObjectObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaObject*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaObject_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaObject value;
    int convert_status=PyoaArray_oaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaArray_oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaObject v1;
    PyParamoaArray_oaObject v2;
    int convert_status1=PyoaArray_oaObject_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaObject_Convert(PyObject* ob,PyParamoaArray_oaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaObject_Check(ob)) {
        result->SetData( (oaArray_oaObject*) ((PyoaArray_oaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaObject_FromoaArray_oaObject(oaArray_oaObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaObject_Type.tp_alloc(&PyoaArray_oaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaObjectObject* self = (PyoaArray_oaObjectObject*)bself;
        self->value = (oaArrayBase_oaObject*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaObject_append_doc[] = 
"Class: oaArray_oaObject, Function: append\n"
"  Paramegers: (oaObject)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaObject,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaObject)\n"
"    Calls: void append(const oaArray_oaObject& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaObject,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaObject_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaObject data;
    int convert_status=PyoaArray_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaObjectObject* self=(PyoaArray_oaObjectObject*)ob;

    // Case: (oaObject)
    {
        PyParamoaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaObject_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaObject)
    {
        PyParamoaArray_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaObject_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaObject, function: append, Choices are:\n"
        "    (oaObject)\n"
        "    (oaArray_oaObject)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaObject_find_doc[] = 
"Class: oaArray_oaObject, Function: find\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaObject,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaObject_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaObject data;
    int convert_status=PyoaArray_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaObjectObject* self=(PyoaArray_oaObjectObject*)ob;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaObject_remove_doc[] = 
"Class: oaArray_oaObject, Function: remove\n"
"  Paramegers: (oaObject)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaObject,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaObject_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaObject data;
    int convert_status=PyoaArray_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaObjectObject* self=(PyoaArray_oaObjectObject*)ob;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaObject_assign_doc[] = 
"Class: oaArray_oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaObject data;
  int convert_status=PyoaArray_oaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaObject_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaObject_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaObject_append,METH_VARARGS,oaArray_oaObject_append_doc},
    {"find",(PyCFunction)oaArray_oaObject_find,METH_VARARGS,oaArray_oaObject_find_doc},
    {"remove",(PyCFunction)oaArray_oaObject_remove,METH_VARARGS,oaArray_oaObject_remove_doc},
    {"assign",(PyCFunction)oaArray_oaObject_tp_assign,METH_VARARGS,oaArray_oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaObject_doc[] = 
"Class: oaArray_oaObject\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaObject()\n"
"    Signature: oaArray_oaObject||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaObject(oaUInt4 size)\n"
"    Signature: oaArray_oaObject||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaObject)\n"
"    Calls: oaArray_oaObject(const oaArray_oaObject& array)\n"
"    Signature: oaArray_oaObject||cref-oaArray_oaObject,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaObject])\n"
"    Calls: oaArray_oaObject( array)\n"
"    Signature: oaArray_oaObject||cpptr-oaObject,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaObject)\n"
"    Calls: (const oaArray_oaObject&)\n"
"    Signature: oaArray_oaObject||cref-oaArray_oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaObject",
    sizeof(PyoaArray_oaObjectObject),
    0,
    (destructor)oaArray_oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaObject",
           (PyObject*)(&PyoaArray_oaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaObject\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaOccTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaOccTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaOccTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaOccTermObject* self = (PyoaArray_oaOccTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaOccTerm*)  new oaArray_oaOccTerm();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaOccTerm*)  new oaArray_oaOccTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaOccTerm)
    {
        PyParamoaArray_oaOccTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaOccTerm_Convert,&p1)) {
            self->value = (oaArrayBase_oaOccTerm*)  new oaArray_oaOccTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaOccTerm])
    {
        PyParamoaOccTerm_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaOccTerm_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaOccTerm*)  new oaArray_oaOccTerm(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaOccTerm, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaOccTerm)\n"
        "    ([oaOccTerm])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaOccTerm_tp_dealloc(PyoaArray_oaOccTermObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaOccTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaOccTerm_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaOccTerm value;
    int convert_status=PyoaArray_oaOccTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaArray_oaOccTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaOccTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaOccTerm v1;
    PyParamoaArray_oaOccTerm v2;
    int convert_status1=PyoaArray_oaOccTerm_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaOccTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaOccTerm_Convert(PyObject* ob,PyParamoaArray_oaOccTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaOccTerm_Check(ob)) {
        result->SetData( (oaArray_oaOccTerm*) ((PyoaArray_oaOccTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaOccTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaOccTerm_FromoaArray_oaOccTerm(oaArray_oaOccTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaOccTerm_Type.tp_alloc(&PyoaArray_oaOccTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaOccTermObject* self = (PyoaArray_oaOccTermObject*)bself;
        self->value = (oaArrayBase_oaOccTerm*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaOccTerm_append_doc[] = 
"Class: oaArray_oaOccTerm, Function: append\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaOccTerm,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaOccTerm)\n"
"    Calls: void append(const oaArray_oaOccTerm& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaOccTerm,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaOccTerm_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaOccTerm data;
    int convert_status=PyoaArray_oaOccTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaOccTermObject* self=(PyoaArray_oaOccTermObject*)ob;

    // Case: (oaOccTerm)
    {
        PyParamoaOccTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaOccTerm_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaOccTerm)
    {
        PyParamoaArray_oaOccTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaOccTerm_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaOccTerm, function: append, Choices are:\n"
        "    (oaOccTerm)\n"
        "    (oaArray_oaOccTerm)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaOccTerm_find_doc[] = 
"Class: oaArray_oaOccTerm, Function: find\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaOccTerm,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaOccTerm_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaOccTerm data;
    int convert_status=PyoaArray_oaOccTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaOccTermObject* self=(PyoaArray_oaOccTermObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaOccTerm_remove_doc[] = 
"Class: oaArray_oaOccTerm, Function: remove\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaOccTerm,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaOccTerm_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaOccTerm data;
    int convert_status=PyoaArray_oaOccTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaOccTermObject* self=(PyoaArray_oaOccTermObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaOccTerm_assign_doc[] = 
"Class: oaArray_oaOccTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaOccTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaOccTerm data;
  int convert_status=PyoaArray_oaOccTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaOccTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaOccTerm_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaOccTerm_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaOccTerm_append,METH_VARARGS,oaArray_oaOccTerm_append_doc},
    {"find",(PyCFunction)oaArray_oaOccTerm_find,METH_VARARGS,oaArray_oaOccTerm_find_doc},
    {"remove",(PyCFunction)oaArray_oaOccTerm_remove,METH_VARARGS,oaArray_oaOccTerm_remove_doc},
    {"assign",(PyCFunction)oaArray_oaOccTerm_tp_assign,METH_VARARGS,oaArray_oaOccTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaOccTerm_doc[] = 
"Class: oaArray_oaOccTerm\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaOccTerm()\n"
"    Signature: oaArray_oaOccTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaOccTerm(oaUInt4 size)\n"
"    Signature: oaArray_oaOccTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaOccTerm)\n"
"    Calls: oaArray_oaOccTerm(const oaArray_oaOccTerm& array)\n"
"    Signature: oaArray_oaOccTerm||cref-oaArray_oaOccTerm,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaOccTerm])\n"
"    Calls: oaArray_oaOccTerm( array)\n"
"    Signature: oaArray_oaOccTerm||cpptr-oaOccTerm,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaOccTerm)\n"
"    Calls: (const oaArray_oaOccTerm&)\n"
"    Signature: oaArray_oaOccTerm||cref-oaArray_oaOccTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaOccTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaOccTerm",
    sizeof(PyoaArray_oaOccTermObject),
    0,
    (destructor)oaArray_oaOccTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaOccTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaOccTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaOccTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaOccTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaOccTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaOccTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaOccTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaOccTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaOccTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaOccTerm",
           (PyObject*)(&PyoaArray_oaOccTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaOccTerm\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaParamObject* self = (PyoaArray_oaParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaParam*)  new oaArray_oaParam();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaParam*)  new oaArray_oaParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaParam)
    {
        PyParamoaArray_oaParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaParam_Convert,&p1)) {
            self->value = (oaArrayBase_oaParam*)  new oaArray_oaParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaParam])
    {
        PyParamoaParam_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaParam_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaParam*)  new oaArray_oaParam(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaParam, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaParam)\n"
        "    ([oaParam])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaParam_tp_dealloc(PyoaArray_oaParamObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaParam_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaParam value;
    int convert_status=PyoaArray_oaParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaArray_oaParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaParam v1;
    PyParamoaArray_oaParam v2;
    int convert_status1=PyoaArray_oaParam_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaParam_Convert(PyObject* ob,PyParamoaArray_oaParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaParam_Check(ob)) {
        result->SetData( (oaArray_oaParam*) ((PyoaArray_oaParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaParam_FromoaArray_oaParam(oaArray_oaParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaParam_Type.tp_alloc(&PyoaArray_oaParam_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaParamObject* self = (PyoaArray_oaParamObject*)bself;
        self->value = (oaArrayBase_oaParam*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaParam_append_doc[] = 
"Class: oaArray_oaParam, Function: append\n"
"  Paramegers: (oaParam)\n"
"    Calls: void append(const oaParam& element)\n"
"    Signature: append|void-void|cref-oaParam,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaParam)\n"
"    Calls: void append(const oaArray_oaParam& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaParam,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaParam_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaParam data;
    int convert_status=PyoaArray_oaParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaParamObject* self=(PyoaArray_oaParamObject*)ob;

    // Case: (oaParam)
    {
        PyParamoaParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaParam_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaParam)
    {
        PyParamoaArray_oaParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaParam_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaParam, function: append, Choices are:\n"
        "    (oaParam)\n"
        "    (oaArray_oaParam)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaParam_find_doc[] = 
"Class: oaArray_oaParam, Function: find\n"
"  Paramegers: (oaParam)\n"
"    Calls: oaUInt4 find(const oaParam& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaParam,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaParam_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaParam data;
    int convert_status=PyoaArray_oaParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaParamObject* self=(PyoaArray_oaParamObject*)ob;

    PyParamoaParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParam_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaParam_remove_doc[] = 
"Class: oaArray_oaParam, Function: remove\n"
"  Paramegers: (oaParam)\n"
"    Calls: void remove(const oaParam& element)\n"
"    Signature: remove|void-void|cref-oaParam,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaParam_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaParam data;
    int convert_status=PyoaArray_oaParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaParamObject* self=(PyoaArray_oaParamObject*)ob;

    PyParamoaParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParam_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaParam_assign_doc[] = 
"Class: oaArray_oaParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaParam data;
  int convert_status=PyoaArray_oaParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaParam_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaParam_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaParam_append,METH_VARARGS,oaArray_oaParam_append_doc},
    {"find",(PyCFunction)oaArray_oaParam_find,METH_VARARGS,oaArray_oaParam_find_doc},
    {"remove",(PyCFunction)oaArray_oaParam_remove,METH_VARARGS,oaArray_oaParam_remove_doc},
    {"assign",(PyCFunction)oaArray_oaParam_tp_assign,METH_VARARGS,oaArray_oaParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaParam_doc[] = 
"Class: oaArray_oaParam\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaParam()\n"
"    Signature: oaArray_oaParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaParam(oaUInt4 size)\n"
"    Signature: oaArray_oaParam||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaParam)\n"
"    Calls: oaArray_oaParam(const oaArray_oaParam& array)\n"
"    Signature: oaArray_oaParam||cref-oaArray_oaParam,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaParam])\n"
"    Calls: oaArray_oaParam(const oaParam* array)\n"
"    Signature: oaArray_oaParam||cptr-oaParam,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaParam)\n"
"    Calls: (const oaArray_oaParam&)\n"
"    Signature: oaArray_oaParam||cref-oaArray_oaParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaParam",
    sizeof(PyoaArray_oaParamObject),
    0,
    (destructor)oaArray_oaParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaParam_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaParam_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaParam_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaParam",
           (PyObject*)(&PyoaArray_oaParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaParam\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaPointObject* self = (PyoaArray_oaPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaPoint*)  new oaArray_oaPoint();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaArray_oaPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaPoint)
    {
        PyParamoaArray_oaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaPoint_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaArray_oaPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaPoint])
    {
        PyParamoaPoint_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaArray_oaPoint(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaPoint, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaPoint)\n"
        "    ([oaPoint])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaPoint_tp_dealloc(PyoaArray_oaPointObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaPoint_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaPoint value;
    int convert_status=PyoaArray_oaPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaArray_oaPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaPoint v1;
    PyParamoaArray_oaPoint v2;
    int convert_status1=PyoaArray_oaPoint_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaPoint_Convert(PyObject* ob,PyParamoaArray_oaPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaPoint_Check(ob)) {
        result->SetData( (oaArray_oaPoint*) ((PyoaArray_oaPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaPoint_FromoaArray_oaPoint(oaArray_oaPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaPoint_Type.tp_alloc(&PyoaArray_oaPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaPointObject* self = (PyoaArray_oaPointObject*)bself;
        self->value = (oaArrayBase_oaPoint*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaPoint_append_doc[] = 
"Class: oaArray_oaPoint, Function: append\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void append(const oaPoint& element)\n"
"    Signature: append|void-void|cref-oaPoint,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaPoint)\n"
"    Calls: void append(const oaArray_oaPoint& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaPoint,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaPoint_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaPoint data;
    int convert_status=PyoaArray_oaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaPointObject* self=(PyoaArray_oaPointObject*)ob;

    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaPoint)
    {
        PyParamoaArray_oaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaPoint_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaPoint, function: append, Choices are:\n"
        "    (oaPoint)\n"
        "    (oaArray_oaPoint)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaPoint_find_doc[] = 
"Class: oaArray_oaPoint, Function: find\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaUInt4 find(const oaPoint& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaPoint,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaPoint_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaPoint data;
    int convert_status=PyoaArray_oaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaPointObject* self=(PyoaArray_oaPointObject*)ob;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaPoint_remove_doc[] = 
"Class: oaArray_oaPoint, Function: remove\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void remove(const oaPoint& element)\n"
"    Signature: remove|void-void|cref-oaPoint,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaPoint_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaPoint data;
    int convert_status=PyoaArray_oaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaPointObject* self=(PyoaArray_oaPointObject*)ob;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaPoint_assign_doc[] = 
"Class: oaArray_oaPoint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaPoint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaPoint data;
  int convert_status=PyoaArray_oaPoint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaPoint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaPoint_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaPoint_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaPoint_append,METH_VARARGS,oaArray_oaPoint_append_doc},
    {"find",(PyCFunction)oaArray_oaPoint_find,METH_VARARGS,oaArray_oaPoint_find_doc},
    {"remove",(PyCFunction)oaArray_oaPoint_remove,METH_VARARGS,oaArray_oaPoint_remove_doc},
    {"assign",(PyCFunction)oaArray_oaPoint_tp_assign,METH_VARARGS,oaArray_oaPoint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaPoint_doc[] = 
"Class: oaArray_oaPoint\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaPoint()\n"
"    Signature: oaArray_oaPoint||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaPoint(oaUInt4 size)\n"
"    Signature: oaArray_oaPoint||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaPoint)\n"
"    Calls: oaArray_oaPoint(const oaArray_oaPoint& array)\n"
"    Signature: oaArray_oaPoint||cref-oaArray_oaPoint,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaPoint])\n"
"    Calls: oaArray_oaPoint(const oaPoint* array)\n"
"    Signature: oaArray_oaPoint||cptr-oaPoint,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaPoint)\n"
"    Calls: (const oaArray_oaPoint&)\n"
"    Signature: oaArray_oaPoint||cref-oaArray_oaPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaPoint",
    sizeof(PyoaArray_oaPointObject),
    0,
    (destructor)oaArray_oaPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaPoint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaPoint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaPoint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaPoint",
           (PyObject*)(&PyoaArray_oaPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaPoint\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaSiteRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaSiteRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaSiteRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaSiteRefObject* self = (PyoaArray_oaSiteRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaSiteRef*)  new oaArray_oaSiteRef();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaSiteRef*)  new oaArray_oaSiteRef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaSiteRef)
    {
        PyParamoaArray_oaSiteRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaSiteRef_Convert,&p1)) {
            self->value = (oaArrayBase_oaSiteRef*)  new oaArray_oaSiteRef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaSiteRef])
    {
        PyParamoaSiteRef_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSiteRef_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaSiteRef*)  new oaArray_oaSiteRef(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaSiteRef, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaSiteRef)\n"
        "    ([oaSiteRef])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaSiteRef_tp_dealloc(PyoaArray_oaSiteRefObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaSiteRef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaSiteRef_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaSiteRef value;
    int convert_status=PyoaArray_oaSiteRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaArray_oaSiteRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaSiteRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaSiteRef v1;
    PyParamoaArray_oaSiteRef v2;
    int convert_status1=PyoaArray_oaSiteRef_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaSiteRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaSiteRef_Convert(PyObject* ob,PyParamoaArray_oaSiteRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaSiteRef_Check(ob)) {
        result->SetData( (oaArray_oaSiteRef*) ((PyoaArray_oaSiteRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaSiteRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaSiteRef_FromoaArray_oaSiteRef(oaArray_oaSiteRef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaSiteRef_Type.tp_alloc(&PyoaArray_oaSiteRef_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaSiteRefObject* self = (PyoaArray_oaSiteRefObject*)bself;
        self->value = (oaArrayBase_oaSiteRef*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaSiteRef_append_doc[] = 
"Class: oaArray_oaSiteRef, Function: append\n"
"  Paramegers: (oaSiteRef)\n"
"    Calls: void append(const oaSiteRef& element)\n"
"    Signature: append|void-void|cref-oaSiteRef,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaSiteRef)\n"
"    Calls: void append(const oaArray_oaSiteRef& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaSiteRef,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaSiteRef_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaSiteRef data;
    int convert_status=PyoaArray_oaSiteRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaSiteRefObject* self=(PyoaArray_oaSiteRefObject*)ob;

    // Case: (oaSiteRef)
    {
        PyParamoaSiteRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSiteRef_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaSiteRef)
    {
        PyParamoaArray_oaSiteRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaSiteRef_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaSiteRef, function: append, Choices are:\n"
        "    (oaSiteRef)\n"
        "    (oaArray_oaSiteRef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaSiteRef_find_doc[] = 
"Class: oaArray_oaSiteRef, Function: find\n"
"  Paramegers: (oaSiteRef)\n"
"    Calls: oaUInt4 find(const oaSiteRef& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaSiteRef,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaSiteRef_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaSiteRef data;
    int convert_status=PyoaArray_oaSiteRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaSiteRefObject* self=(PyoaArray_oaSiteRefObject*)ob;

    PyParamoaSiteRef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSiteRef_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaSiteRef_remove_doc[] = 
"Class: oaArray_oaSiteRef, Function: remove\n"
"  Paramegers: (oaSiteRef)\n"
"    Calls: void remove(const oaSiteRef& element)\n"
"    Signature: remove|void-void|cref-oaSiteRef,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaSiteRef_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaSiteRef data;
    int convert_status=PyoaArray_oaSiteRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaSiteRefObject* self=(PyoaArray_oaSiteRefObject*)ob;

    PyParamoaSiteRef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSiteRef_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaSiteRef_assign_doc[] = 
"Class: oaArray_oaSiteRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaSiteRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaSiteRef data;
  int convert_status=PyoaArray_oaSiteRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaSiteRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaSiteRef_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaSiteRef_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaSiteRef_append,METH_VARARGS,oaArray_oaSiteRef_append_doc},
    {"find",(PyCFunction)oaArray_oaSiteRef_find,METH_VARARGS,oaArray_oaSiteRef_find_doc},
    {"remove",(PyCFunction)oaArray_oaSiteRef_remove,METH_VARARGS,oaArray_oaSiteRef_remove_doc},
    {"assign",(PyCFunction)oaArray_oaSiteRef_tp_assign,METH_VARARGS,oaArray_oaSiteRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaSiteRef_doc[] = 
"Class: oaArray_oaSiteRef\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaSiteRef()\n"
"    Signature: oaArray_oaSiteRef||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaSiteRef(oaUInt4 size)\n"
"    Signature: oaArray_oaSiteRef||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaSiteRef)\n"
"    Calls: oaArray_oaSiteRef(const oaArray_oaSiteRef& array)\n"
"    Signature: oaArray_oaSiteRef||cref-oaArray_oaSiteRef,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaSiteRef])\n"
"    Calls: oaArray_oaSiteRef(const oaSiteRef* array)\n"
"    Signature: oaArray_oaSiteRef||cptr-oaSiteRef,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaSiteRef)\n"
"    Calls: (const oaArray_oaSiteRef&)\n"
"    Signature: oaArray_oaSiteRef||cref-oaArray_oaSiteRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaSiteRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaSiteRef",
    sizeof(PyoaArray_oaSiteRefObject),
    0,
    (destructor)oaArray_oaSiteRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaSiteRef_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaSiteRef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaSiteRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaSiteRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaSiteRef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaSiteRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaSiteRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaSiteRef_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaSiteRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaSiteRef",
           (PyObject*)(&PyoaArray_oaSiteRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaSiteRef\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaString
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaString_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaString_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaStringObject* self = (PyoaArray_oaStringObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaString*)  new oaArray_oaString();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaString*)  new oaArray_oaString(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaString)
    {
        PyParamoaArray_oaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaString_Convert,&p1)) {
            self->value = (oaArrayBase_oaString*)  new oaArray_oaString(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaString])
    {
        PyParamoaString_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaString*)  new oaArray_oaString(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaString, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaString)\n"
        "    ([oaString])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaString_tp_dealloc(PyoaArray_oaStringObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaString*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaString_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaString value;
    int convert_status=PyoaArray_oaString_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaArray_oaString::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaString_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaString v1;
    PyParamoaArray_oaString v2;
    int convert_status1=PyoaArray_oaString_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaString_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaString_Convert(PyObject* ob,PyParamoaArray_oaString* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaString_Check(ob)) {
        result->SetData( (oaArray_oaString*) ((PyoaArray_oaStringObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaString Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaString_FromoaArray_oaString(oaArray_oaString* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaString_Type.tp_alloc(&PyoaArray_oaString_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaStringObject* self = (PyoaArray_oaStringObject*)bself;
        self->value = (oaArrayBase_oaString*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaString_append_doc[] = 
"Class: oaArray_oaString, Function: append\n"
"  Paramegers: (oaString)\n"
"    Calls: void append(const oaString& element)\n"
"    Signature: append|void-void|cref-oaString,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaString)\n"
"    Calls: void append(const oaArray_oaString& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaString,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaString_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaString data;
    int convert_status=PyoaArray_oaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaStringObject* self=(PyoaArray_oaStringObject*)ob;

    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaString)
    {
        PyParamoaArray_oaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaString_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaString, function: append, Choices are:\n"
        "    (oaString)\n"
        "    (oaArray_oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaString_find_doc[] = 
"Class: oaArray_oaString, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaUInt4 find(const oaString& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaString,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaString_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaString data;
    int convert_status=PyoaArray_oaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaStringObject* self=(PyoaArray_oaStringObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaString_remove_doc[] = 
"Class: oaArray_oaString, Function: remove\n"
"  Paramegers: (oaString)\n"
"    Calls: void remove(const oaString& element)\n"
"    Signature: remove|void-void|cref-oaString,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaString_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaString data;
    int convert_status=PyoaArray_oaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaStringObject* self=(PyoaArray_oaStringObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaString_assign_doc[] = 
"Class: oaArray_oaString, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaString_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaString data;
  int convert_status=PyoaArray_oaString_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaString p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaString_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaString_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaString_append,METH_VARARGS,oaArray_oaString_append_doc},
    {"find",(PyCFunction)oaArray_oaString_find,METH_VARARGS,oaArray_oaString_find_doc},
    {"remove",(PyCFunction)oaArray_oaString_remove,METH_VARARGS,oaArray_oaString_remove_doc},
    {"assign",(PyCFunction)oaArray_oaString_tp_assign,METH_VARARGS,oaArray_oaString_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaString_doc[] = 
"Class: oaArray_oaString\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaString()\n"
"    Signature: oaArray_oaString||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaString(oaUInt4 size)\n"
"    Signature: oaArray_oaString||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaString)\n"
"    Calls: oaArray_oaString(const oaArray_oaString& array)\n"
"    Signature: oaArray_oaString||cref-oaArray_oaString,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaString])\n"
"    Calls: oaArray_oaString(const oaString* array)\n"
"    Signature: oaArray_oaString||cptr-oaString,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaString)\n"
"    Calls: (const oaArray_oaString&)\n"
"    Signature: oaArray_oaString||cref-oaArray_oaString,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaString_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaString",
    sizeof(PyoaArray_oaStringObject),
    0,
    (destructor)oaArray_oaString_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaString_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaString_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaString_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaString_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaString_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaString_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaString_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaString_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaString\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaString",
           (PyObject*)(&PyoaArray_oaString_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaString\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaTechObject* self = (PyoaArray_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaTech*)  new oaArray_oaTech();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaTech*)  new oaArray_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTech)
    {
        PyParamoaArray_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTech_Convert,&p1)) {
            self->value = (oaArrayBase_oaTech*)  new oaArray_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaTech])
    {
        PyParamoaTech_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTech_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaTech*)  new oaArray_oaTech(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaTech, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaTech)\n"
        "    ([oaTech])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaTech_tp_dealloc(PyoaArray_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaTech value;
    int convert_status=PyoaArray_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaArray_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaTech v1;
    PyParamoaArray_oaTech v2;
    int convert_status1=PyoaArray_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaTech_Convert(PyObject* ob,PyParamoaArray_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaTech_Check(ob)) {
        result->SetData( (oaArray_oaTech*) ((PyoaArray_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaTech_FromoaArray_oaTech(oaArray_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaTech_Type.tp_alloc(&PyoaArray_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaTechObject* self = (PyoaArray_oaTechObject*)bself;
        self->value = (oaArrayBase_oaTech*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTech_append_doc[] = 
"Class: oaArray_oaTech, Function: append\n"
"  Paramegers: (oaTech)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaTech,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaTech)\n"
"    Calls: void append(const oaArray_oaTech& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaTech,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaTech_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTech data;
    int convert_status=PyoaArray_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechObject* self=(PyoaArray_oaTechObject*)ob;

    // Case: (oaTech)
    {
        PyParamoaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTech_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTech)
    {
        PyParamoaArray_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTech_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaTech, function: append, Choices are:\n"
        "    (oaTech)\n"
        "    (oaArray_oaTech)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTech_find_doc[] = 
"Class: oaArray_oaTech, Function: find\n"
"  Paramegers: (oaTech)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaTech,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaTech_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTech data;
    int convert_status=PyoaArray_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechObject* self=(PyoaArray_oaTechObject*)ob;

    PyParamoaTech p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTech_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTech_remove_doc[] = 
"Class: oaArray_oaTech, Function: remove\n"
"  Paramegers: (oaTech)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaTech,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaTech_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTech data;
    int convert_status=PyoaArray_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechObject* self=(PyoaArray_oaTechObject*)ob;

    PyParamoaTech p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTech_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaTech_assign_doc[] = 
"Class: oaArray_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaTech data;
  int convert_status=PyoaArray_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaTech_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaTech_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaTech_append,METH_VARARGS,oaArray_oaTech_append_doc},
    {"find",(PyCFunction)oaArray_oaTech_find,METH_VARARGS,oaArray_oaTech_find_doc},
    {"remove",(PyCFunction)oaArray_oaTech_remove,METH_VARARGS,oaArray_oaTech_remove_doc},
    {"assign",(PyCFunction)oaArray_oaTech_tp_assign,METH_VARARGS,oaArray_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTech_doc[] = 
"Class: oaArray_oaTech\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaTech()\n"
"    Signature: oaArray_oaTech||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaTech(oaUInt4 size)\n"
"    Signature: oaArray_oaTech||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaTech)\n"
"    Calls: oaArray_oaTech(const oaArray_oaTech& array)\n"
"    Signature: oaArray_oaTech||cref-oaArray_oaTech,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaTech])\n"
"    Calls: oaArray_oaTech( array)\n"
"    Signature: oaArray_oaTech||cpptr-oaTech,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaTech)\n"
"    Calls: (const oaArray_oaTech&)\n"
"    Signature: oaArray_oaTech||cref-oaArray_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaTech",
    sizeof(PyoaArray_oaTechObject),
    0,
    (destructor)oaArray_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaTech_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaTech",
           (PyObject*)(&PyoaArray_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaTech\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaTechHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTechHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaTechHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaTechHeaderObject* self = (PyoaArray_oaTechHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaTechHeader*)  new oaArray_oaTechHeader();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaTechHeader*)  new oaArray_oaTechHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTechHeader)
    {
        PyParamoaArray_oaTechHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTechHeader_Convert,&p1)) {
            self->value = (oaArrayBase_oaTechHeader*)  new oaArray_oaTechHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaTechHeader])
    {
        PyParamoaTechHeader_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTechHeader_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaTechHeader*)  new oaArray_oaTechHeader(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaTechHeader, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaTechHeader)\n"
        "    ([oaTechHeader])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaTechHeader_tp_dealloc(PyoaArray_oaTechHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaTechHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTechHeader_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaTechHeader value;
    int convert_status=PyoaArray_oaTechHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaArray_oaTechHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaTechHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaTechHeader v1;
    PyParamoaArray_oaTechHeader v2;
    int convert_status1=PyoaArray_oaTechHeader_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaTechHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaTechHeader_Convert(PyObject* ob,PyParamoaArray_oaTechHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaTechHeader_Check(ob)) {
        result->SetData( (oaArray_oaTechHeader*) ((PyoaArray_oaTechHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaTechHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaTechHeader_FromoaArray_oaTechHeader(oaArray_oaTechHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaTechHeader_Type.tp_alloc(&PyoaArray_oaTechHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaTechHeaderObject* self = (PyoaArray_oaTechHeaderObject*)bself;
        self->value = (oaArrayBase_oaTechHeader*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTechHeader_append_doc[] = 
"Class: oaArray_oaTechHeader, Function: append\n"
"  Paramegers: (oaTechHeader)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaTechHeader,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaTechHeader)\n"
"    Calls: void append(const oaArray_oaTechHeader& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaTechHeader,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaTechHeader_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTechHeader data;
    int convert_status=PyoaArray_oaTechHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechHeaderObject* self=(PyoaArray_oaTechHeaderObject*)ob;

    // Case: (oaTechHeader)
    {
        PyParamoaTechHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTechHeader_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTechHeader)
    {
        PyParamoaArray_oaTechHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTechHeader_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaTechHeader, function: append, Choices are:\n"
        "    (oaTechHeader)\n"
        "    (oaArray_oaTechHeader)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTechHeader_find_doc[] = 
"Class: oaArray_oaTechHeader, Function: find\n"
"  Paramegers: (oaTechHeader)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaTechHeader,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaTechHeader_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTechHeader data;
    int convert_status=PyoaArray_oaTechHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechHeaderObject* self=(PyoaArray_oaTechHeaderObject*)ob;

    PyParamoaTechHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechHeader_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTechHeader_remove_doc[] = 
"Class: oaArray_oaTechHeader, Function: remove\n"
"  Paramegers: (oaTechHeader)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaTechHeader,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaTechHeader_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTechHeader data;
    int convert_status=PyoaArray_oaTechHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTechHeaderObject* self=(PyoaArray_oaTechHeaderObject*)ob;

    PyParamoaTechHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechHeader_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaTechHeader_assign_doc[] = 
"Class: oaArray_oaTechHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaTechHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaTechHeader data;
  int convert_status=PyoaArray_oaTechHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaTechHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaTechHeader_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaTechHeader_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaTechHeader_append,METH_VARARGS,oaArray_oaTechHeader_append_doc},
    {"find",(PyCFunction)oaArray_oaTechHeader_find,METH_VARARGS,oaArray_oaTechHeader_find_doc},
    {"remove",(PyCFunction)oaArray_oaTechHeader_remove,METH_VARARGS,oaArray_oaTechHeader_remove_doc},
    {"assign",(PyCFunction)oaArray_oaTechHeader_tp_assign,METH_VARARGS,oaArray_oaTechHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTechHeader_doc[] = 
"Class: oaArray_oaTechHeader\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaTechHeader()\n"
"    Signature: oaArray_oaTechHeader||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaTechHeader(oaUInt4 size)\n"
"    Signature: oaArray_oaTechHeader||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaTechHeader)\n"
"    Calls: oaArray_oaTechHeader(const oaArray_oaTechHeader& array)\n"
"    Signature: oaArray_oaTechHeader||cref-oaArray_oaTechHeader,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaTechHeader])\n"
"    Calls: oaArray_oaTechHeader( array)\n"
"    Signature: oaArray_oaTechHeader||cpptr-oaTechHeader,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaTechHeader)\n"
"    Calls: (const oaArray_oaTechHeader&)\n"
"    Signature: oaArray_oaTechHeader||cref-oaArray_oaTechHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaTechHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaTechHeader",
    sizeof(PyoaArray_oaTechHeaderObject),
    0,
    (destructor)oaArray_oaTechHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaTechHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaTechHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaTechHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaTechHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaTechHeader_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaTechHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaTechHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaTechHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaTechHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaTechHeader",
           (PyObject*)(&PyoaArray_oaTechHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaTechHeader\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaTermObject* self = (PyoaArray_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaTerm*)  new oaArray_oaTerm();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaTerm*)  new oaArray_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTerm)
    {
        PyParamoaArray_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTerm_Convert,&p1)) {
            self->value = (oaArrayBase_oaTerm*)  new oaArray_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaTerm])
    {
        PyParamoaTerm_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTerm_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaTerm*)  new oaArray_oaTerm(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaTerm, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaTerm)\n"
        "    ([oaTerm])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaTerm_tp_dealloc(PyoaArray_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaTerm value;
    int convert_status=PyoaArray_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaArray_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaTerm v1;
    PyParamoaArray_oaTerm v2;
    int convert_status1=PyoaArray_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaTerm_Convert(PyObject* ob,PyParamoaArray_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaTerm_Check(ob)) {
        result->SetData( (oaArray_oaTerm*) ((PyoaArray_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaTerm_FromoaArray_oaTerm(oaArray_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaTerm_Type.tp_alloc(&PyoaArray_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaTermObject* self = (PyoaArray_oaTermObject*)bself;
        self->value = (oaArrayBase_oaTerm*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTerm_append_doc[] = 
"Class: oaArray_oaTerm, Function: append\n"
"  Paramegers: (oaTerm)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaTerm,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaTerm)\n"
"    Calls: void append(const oaArray_oaTerm& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaTerm,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaTerm_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTerm data;
    int convert_status=PyoaArray_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTermObject* self=(PyoaArray_oaTermObject*)ob;

    // Case: (oaTerm)
    {
        PyParamoaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTerm_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaTerm)
    {
        PyParamoaArray_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaTerm_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaTerm, function: append, Choices are:\n"
        "    (oaTerm)\n"
        "    (oaArray_oaTerm)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTerm_find_doc[] = 
"Class: oaArray_oaTerm, Function: find\n"
"  Paramegers: (oaTerm)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaTerm,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaTerm_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTerm data;
    int convert_status=PyoaArray_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTermObject* self=(PyoaArray_oaTermObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaTerm_remove_doc[] = 
"Class: oaArray_oaTerm, Function: remove\n"
"  Paramegers: (oaTerm)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaTerm,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaTerm_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaTerm data;
    int convert_status=PyoaArray_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTermObject* self=(PyoaArray_oaTermObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaTerm_assign_doc[] = 
"Class: oaArray_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaTerm data;
  int convert_status=PyoaArray_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaTerm_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaTerm_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaTerm_append,METH_VARARGS,oaArray_oaTerm_append_doc},
    {"find",(PyCFunction)oaArray_oaTerm_find,METH_VARARGS,oaArray_oaTerm_find_doc},
    {"remove",(PyCFunction)oaArray_oaTerm_remove,METH_VARARGS,oaArray_oaTerm_remove_doc},
    {"assign",(PyCFunction)oaArray_oaTerm_tp_assign,METH_VARARGS,oaArray_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaTerm_doc[] = 
"Class: oaArray_oaTerm\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaTerm()\n"
"    Signature: oaArray_oaTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaTerm(oaUInt4 size)\n"
"    Signature: oaArray_oaTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaTerm)\n"
"    Calls: oaArray_oaTerm(const oaArray_oaTerm& array)\n"
"    Signature: oaArray_oaTerm||cref-oaArray_oaTerm,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaTerm])\n"
"    Calls: oaArray_oaTerm( array)\n"
"    Signature: oaArray_oaTerm||cpptr-oaTerm,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaTerm)\n"
"    Calls: (const oaArray_oaTerm&)\n"
"    Signature: oaArray_oaTerm||cref-oaArray_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaTerm",
    sizeof(PyoaArray_oaTermObject),
    0,
    (destructor)oaArray_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaTerm",
           (PyObject*)(&PyoaArray_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaTerm\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaTypeObject* self = (PyoaArray_oaTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaType*)  new oaArray_oaType();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaType*)  new oaArray_oaType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaType)
    {
        PyParamoaArray_oaType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaType_Convert,&p1)) {
            self->value = (oaArrayBase_oaType*)  new oaArray_oaType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaType])
    {
        PyParamoaType_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaType_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaType*)  new oaArray_oaType(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaType, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaType)\n"
        "    ([oaType])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaType_tp_dealloc(PyoaArray_oaTypeObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaType_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaType value;
    int convert_status=PyoaArray_oaType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaArray_oaType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaType v1;
    PyParamoaArray_oaType v2;
    int convert_status1=PyoaArray_oaType_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaType_Convert(PyObject* ob,PyParamoaArray_oaType* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaType_Check(ob)) {
        result->SetData( (oaArray_oaType*) ((PyoaArray_oaTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaType_FromoaArray_oaType(oaArray_oaType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaType_Type.tp_alloc(&PyoaArray_oaType_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaTypeObject* self = (PyoaArray_oaTypeObject*)bself;
        self->value = (oaArrayBase_oaType*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaType_append_doc[] = 
"Class: oaArray_oaType, Function: append\n"
"  Paramegers: (oaType)\n"
"    Calls: void append(const oaType& element)\n"
"    Signature: append|void-void|cref-oaType,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaType)\n"
"    Calls: void append(const oaArray_oaType& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaType,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaType_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaType data;
    int convert_status=PyoaArray_oaType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTypeObject* self=(PyoaArray_oaTypeObject*)ob;

    // Case: (oaType)
    {
        PyParamoaType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaType_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaType)
    {
        PyParamoaArray_oaType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaType_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaType, function: append, Choices are:\n"
        "    (oaType)\n"
        "    (oaArray_oaType)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaType_find_doc[] = 
"Class: oaArray_oaType, Function: find\n"
"  Paramegers: (oaType)\n"
"    Calls: oaUInt4 find(const oaType& element) const\n"
"    Signature: find|simple-oaUInt4|cref-oaType,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaType_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaType data;
    int convert_status=PyoaArray_oaType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTypeObject* self=(PyoaArray_oaTypeObject*)ob;

    PyParamoaType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaType_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaType_remove_doc[] = 
"Class: oaArray_oaType, Function: remove\n"
"  Paramegers: (oaType)\n"
"    Calls: void remove(const oaType& element)\n"
"    Signature: remove|void-void|cref-oaType,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaType_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaType data;
    int convert_status=PyoaArray_oaType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaTypeObject* self=(PyoaArray_oaTypeObject*)ob;

    PyParamoaType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaType_Convert,&p1)) {
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaType_assign_doc[] = 
"Class: oaArray_oaType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaType data;
  int convert_status=PyoaArray_oaType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaType_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaType_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaType_append,METH_VARARGS,oaArray_oaType_append_doc},
    {"find",(PyCFunction)oaArray_oaType_find,METH_VARARGS,oaArray_oaType_find_doc},
    {"remove",(PyCFunction)oaArray_oaType_remove,METH_VARARGS,oaArray_oaType_remove_doc},
    {"assign",(PyCFunction)oaArray_oaType_tp_assign,METH_VARARGS,oaArray_oaType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaType_doc[] = 
"Class: oaArray_oaType\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaType()\n"
"    Signature: oaArray_oaType||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaType(oaUInt4 size)\n"
"    Signature: oaArray_oaType||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaType)\n"
"    Calls: oaArray_oaType(const oaArray_oaType& array)\n"
"    Signature: oaArray_oaType||cref-oaArray_oaType,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaType])\n"
"    Calls: oaArray_oaType(const oaType* array)\n"
"    Signature: oaArray_oaType||cptr-oaType,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaType)\n"
"    Calls: (const oaArray_oaType&)\n"
"    Signature: oaArray_oaType||cref-oaArray_oaType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaType",
    sizeof(PyoaArray_oaTypeObject),
    0,
    (destructor)oaArray_oaType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaType_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaType_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaType_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaType",
           (PyObject*)(&PyoaArray_oaType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaType\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaValueObject* self = (PyoaArray_oaValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaValue*)  new oaArray_oaValue();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaValue*)  new oaArray_oaValue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaValue)
    {
        PyParamoaArray_oaValue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaValue_Convert,&p1)) {
            self->value = (oaArrayBase_oaValue*)  new oaArray_oaValue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaValue])
    {
        PyParamoaValue_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaValue_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaValue*)  new oaArray_oaValue(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaValue, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaValue)\n"
        "    ([oaValue])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaValue_tp_dealloc(PyoaArray_oaValueObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaValue_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaValue value;
    int convert_status=PyoaArray_oaValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaArray_oaValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaValue v1;
    PyParamoaArray_oaValue v2;
    int convert_status1=PyoaArray_oaValue_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaValue_Convert(PyObject* ob,PyParamoaArray_oaValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaValue_Check(ob)) {
        result->SetData( (oaArray_oaValue*) ((PyoaArray_oaValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaValue_FromoaArray_oaValue(oaArray_oaValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaValue_Type.tp_alloc(&PyoaArray_oaValue_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaValueObject* self = (PyoaArray_oaValueObject*)bself;
        self->value = (oaArrayBase_oaValue*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaValue_append_doc[] = 
"Class: oaArray_oaValue, Function: append\n"
"  Paramegers: (oaValue)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaValue,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaValue)\n"
"    Calls: void append(const oaArray_oaValue& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaValue,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaValue_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaValue data;
    int convert_status=PyoaArray_oaValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaValueObject* self=(PyoaArray_oaValueObject*)ob;

    // Case: (oaValue)
    {
        PyParamoaValue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaValue_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaValue)
    {
        PyParamoaArray_oaValue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaValue_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaValue, function: append, Choices are:\n"
        "    (oaValue)\n"
        "    (oaArray_oaValue)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaValue_find_doc[] = 
"Class: oaArray_oaValue, Function: find\n"
"  Paramegers: (oaValue)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaValue,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaValue_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaValue data;
    int convert_status=PyoaArray_oaValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaValueObject* self=(PyoaArray_oaValueObject*)ob;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaValue_remove_doc[] = 
"Class: oaArray_oaValue, Function: remove\n"
"  Paramegers: (oaValue)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaValue,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaValue_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaValue data;
    int convert_status=PyoaArray_oaValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaValueObject* self=(PyoaArray_oaValueObject*)ob;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaValue_assign_doc[] = 
"Class: oaArray_oaValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaValue data;
  int convert_status=PyoaArray_oaValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaValue_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaValue_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaValue_append,METH_VARARGS,oaArray_oaValue_append_doc},
    {"find",(PyCFunction)oaArray_oaValue_find,METH_VARARGS,oaArray_oaValue_find_doc},
    {"remove",(PyCFunction)oaArray_oaValue_remove,METH_VARARGS,oaArray_oaValue_remove_doc},
    {"assign",(PyCFunction)oaArray_oaValue_tp_assign,METH_VARARGS,oaArray_oaValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaValue_doc[] = 
"Class: oaArray_oaValue\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaValue()\n"
"    Signature: oaArray_oaValue||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaValue(oaUInt4 size)\n"
"    Signature: oaArray_oaValue||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaValue)\n"
"    Calls: oaArray_oaValue(const oaArray_oaValue& array)\n"
"    Signature: oaArray_oaValue||cref-oaArray_oaValue,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaValue])\n"
"    Calls: oaArray_oaValue( array)\n"
"    Signature: oaArray_oaValue||cpptr-oaValue,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaValue)\n"
"    Calls: (const oaArray_oaValue&)\n"
"    Signature: oaArray_oaValue||cref-oaArray_oaValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaValue",
    sizeof(PyoaArray_oaValueObject),
    0,
    (destructor)oaArray_oaValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaValue_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaValue_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaValue",
           (PyObject*)(&PyoaArray_oaValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaValue\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaArray_oaViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaArray_oaViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaArray_oaViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaArray_oaViaDefObject* self = (PyoaArray_oaViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaViaDef*)  new oaArray_oaViaDef();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaViaDef*)  new oaArray_oaViaDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaViaDef)
    {
        PyParamoaArray_oaViaDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaViaDef_Convert,&p1)) {
            self->value = (oaArrayBase_oaViaDef*)  new oaArray_oaViaDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaViaDef])
    {
        PyParamoaViaDef_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaViaDef_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaViaDef*)  new oaArray_oaViaDef(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaArray_oaViaDef, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaArray_oaViaDef)\n"
        "    ([oaViaDef])\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaArray_oaViaDef_tp_dealloc(PyoaArray_oaViaDefObject* self)
{
    if (!self->borrow) {
        delete (oaArray_oaViaDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaArray_oaViaDef_tp_repr(PyObject *ob)
{
    PyParamoaArray_oaViaDef value;
    int convert_status=PyoaArray_oaViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaArray_oaViaDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaArray_oaViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaArray_oaViaDef v1;
    PyParamoaArray_oaViaDef v2;
    int convert_status1=PyoaArray_oaViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaArray_oaViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaArray_oaViaDef_Convert(PyObject* ob,PyParamoaArray_oaViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaArray_oaViaDef_Check(ob)) {
        result->SetData( (oaArray_oaViaDef*) ((PyoaArray_oaViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaArray_oaViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaArray_oaViaDef_FromoaArray_oaViaDef(oaArray_oaViaDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaArray_oaViaDef_Type.tp_alloc(&PyoaArray_oaViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaArray_oaViaDefObject* self = (PyoaArray_oaViaDefObject*)bself;
        self->value = (oaArrayBase_oaViaDef*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaViaDef_append_doc[] = 
"Class: oaArray_oaViaDef, Function: append\n"
"  Paramegers: (oaViaDef)\n"
"    Calls: void append( element)\n"
"    Signature: append|void-void|cptrref-oaViaDef,\n"
"    This function appends the specified element to the end of this array. This function will increase the size of the array if necessary and will increment the number of elements in the array.\n"
"    element\n"
"    The element to append to this array\n"
"  Paramegers: (oaArray_oaViaDef)\n"
"    Calls: void append(const oaArray_oaViaDef& arrayIn)\n"
"    Signature: append|void-void|cref-oaArray_oaViaDef,\n"
"    oaArray::append\n"
"    This function appends the specified array to the end of this array. This function will increase the size of the array if necessary to fit the specified array contents and will update the number of elements in this array.\n"
"    arrayIn\n"
"    The array of elements to append to this array\n"
;

static PyObject*
oaArray_oaViaDef_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaViaDef data;
    int convert_status=PyoaArray_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaViaDefObject* self=(PyoaArray_oaViaDefObject*)ob;

    // Case: (oaViaDef)
    {
        PyParamoaViaDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaViaDef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaArray_oaViaDef)
    {
        PyParamoaArray_oaViaDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaArray_oaViaDef_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaArray_oaViaDef, function: append, Choices are:\n"
        "    (oaViaDef)\n"
        "    (oaArray_oaViaDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaViaDef_find_doc[] = 
"Class: oaArray_oaViaDef, Function: find\n"
"  Paramegers: (oaViaDef)\n"
"    Calls: oaUInt4 find( element) const\n"
"    Signature: find|simple-oaUInt4|cptrref-oaViaDef,\n"
"    This function searches this array for the specified element. The position of the element in the array is returned if found. Otherwise, the value oacNullIndex is returned.\n"
"    element\n"
"    The element to search for in this array\n"
;

static PyObject*
oaArray_oaViaDef_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaViaDef data;
    int convert_status=PyoaArray_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaViaDefObject* self=(PyoaArray_oaViaDefObject*)ob;

    PyParamoaViaDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (data.DataCall()->find(p1.Data()));
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaArray_oaViaDef_remove_doc[] = 
"Class: oaArray_oaViaDef, Function: remove\n"
"  Paramegers: (oaViaDef)\n"
"    Calls: void remove( element)\n"
"    Signature: remove|void-void|cptrref-oaViaDef,\n"
"    This function removes the specified element from this array, shifting the remaining elements up to fill in the gap. The number of elements is decremented accordingly.\n"
"    element\n"
"    The element to remove from this array\n"
;

static PyObject*
oaArray_oaViaDef_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaArray_oaViaDef data;
    int convert_status=PyoaArray_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaArray_oaViaDefObject* self=(PyoaArray_oaViaDefObject*)ob;

    PyParamoaViaDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->remove(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaArray_oaViaDef_assign_doc[] = 
"Class: oaArray_oaViaDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaArray_oaViaDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaArray_oaViaDef data;
  int convert_status=PyoaArray_oaViaDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaArray_oaViaDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaArray_oaViaDef_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaArray_oaViaDef_methodlist[] = {
    {"append",(PyCFunction)oaArray_oaViaDef_append,METH_VARARGS,oaArray_oaViaDef_append_doc},
    {"find",(PyCFunction)oaArray_oaViaDef_find,METH_VARARGS,oaArray_oaViaDef_find_doc},
    {"remove",(PyCFunction)oaArray_oaViaDef_remove,METH_VARARGS,oaArray_oaViaDef_remove_doc},
    {"assign",(PyCFunction)oaArray_oaViaDef_tp_assign,METH_VARARGS,oaArray_oaViaDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaArray_oaViaDef_doc[] = 
"Class: oaArray_oaViaDef\n"
"  The oaArray class is an abstract class that is the base for many of the array classes used in the OpenAccess API. The oaArray<> template extends the oaArrayBase<> template with some higher-level operations that allow it to function more like a typical container. It supports the basic management facilities for an array of a specified element type. This includes sizing of the array and operators to access and manipulate the data it contains.\n"
"  Different objects derive an array class that is specific to what they need to manipulate with the array, such as the oaTermArray and oaModTermArray classes. These object specific arrays may add to the basic capabilities provided by the oaArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaArray_oaViaDef()\n"
"    Signature: oaArray_oaViaDef||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaArray_oaViaDef(oaUInt4 size)\n"
"    Signature: oaArray_oaViaDef||simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array allocated with enough storage to hold the number of elements specified by size .\n"
"    size\n"
"    Specifies the storage to allocate for size elements\n"
"  Paramegers: (oaArray_oaViaDef)\n"
"    Calls: oaArray_oaViaDef(const oaArray_oaViaDef& array)\n"
"    Signature: oaArray_oaViaDef||cref-oaArray_oaViaDef,\n"
"    This is the constructor for the oaArray<T> template class that constructs an array by making a copy of the specified array.\n"
"    array\n"
"    The array to be copied\n"
"  Paramegers: ([oaViaDef])\n"
"    Calls: oaArray_oaViaDef( array)\n"
"    Signature: oaArray_oaViaDef||cpptr-oaViaDef,simple-oaUInt4,\n"
"    This is the constructor for the oaArray<T> template that uses a C-style array[] of T elements to specify the initial contents of the array.\n"
"    array[]\n"
"    C-style array of T elements\n"
"    numElementsIn\n"
"    number of elements\n"
"  Paramegers: (oaArray_oaViaDef)\n"
"    Calls: (const oaArray_oaViaDef&)\n"
"    Signature: oaArray_oaViaDef||cref-oaArray_oaViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaArray_oaViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaArray_oaViaDef",
    sizeof(PyoaArray_oaViaDefObject),
    0,
    (destructor)oaArray_oaViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaArray_oaViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaArray_oaViaDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaArray_oaViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaArray_oaViaDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArrayBase_oaViaDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaArray_oaViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaArray_oaViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaArray_oaViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaArray_oaViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaArray_oaViaDef",
           (PyObject*)(&PyoaArray_oaViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaArray_oaViaDef\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignAssignmentObject* self = (PyoaAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaAssignAssignment)
    {
        PyParamoaAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignAssignment_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignAssignment, Choices are:\n"
        "    (oaAssignAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignAssignment_tp_dealloc(PyoaAssignAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaAssignAssignment value;
    int convert_status=PyoaAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaAssignAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[40];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaAssignAssignment::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignAssignment v1;
    PyParamoaAssignAssignment v2;
    int convert_status1=PyoaAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignAssignment_Convert(PyObject* ob,PyParamoaAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignAssignment_Check(ob)) {
        result->SetData( (oaAssignAssignment**) ((PyoaAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignAssignment_FromoaAssignAssignment(oaAssignAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaAssignAssignment* data=*value;
        PyObject* bself = PyoaAssignAssignment_Type.tp_alloc(&PyoaAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignAssignmentObject* self = (PyoaAssignAssignmentObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignAssignment_FromoaAssignAssignment(oaAssignAssignment* data)
{
    if (data) {
       PyObject* bself = PyoaAssignAssignment_Type.tp_alloc(&PyoaAssignAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaAssignAssignmentObject* self = (PyoaAssignAssignmentObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignAssignment_getAssignmentDef_doc[] = 
"Class: oaAssignAssignment, Function: getAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void getAssignmentDef(oaAssignmentDef& aDef) const\n"
"    Signature: getAssignmentDef|void-void|ref-oaAssignmentDef,\n"
"    BrowseData: 0,oaAssignmentDef\n"
"    This function retrieves the data associated with this assignment and returns it in the assignmentDef argument.\n"
;

static PyObject*
oaAssignAssignment_getAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignAssignment data;
    int convert_status=PyoaAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignAssignmentObject* self=(PyoaAssignAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAssignmentDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAssignmentDef_Convert,&p1)) {
        data.DataCall()->getAssignmentDef(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignAssignment_setAssignmentDef_doc[] = 
"Class: oaAssignAssignment, Function: setAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void setAssignmentDef(const oaAssignmentDef& aDef)\n"
"    Signature: setAssignmentDef|void-void|cref-oaAssignmentDef,\n"
"    This function sets the data for this assignment from the specified assignmentDef .\n"
"    oacInvalidAssignmentDef\n"
;

static PyObject*
oaAssignAssignment_setAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignAssignment data;
    int convert_status=PyoaAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignAssignmentObject* self=(PyoaAssignAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAssignmentDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAssignmentDef_Convert,&p1)) {
        data.DataCall()->setAssignmentDef(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignAssignment_isNull_doc[] =
"Class: oaAssignAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaAssignAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaAssignAssignment data;
    int convert_status=PyoaAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaAssignAssignment_assign_doc[] = 
"Class: oaAssignAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAssignAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAssignAssignment data;
  int convert_status=PyoaAssignAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAssignAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAssignAssignment_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAssignAssignment_methodlist[] = {
    {"getAssignmentDef",(PyCFunction)oaAssignAssignment_getAssignmentDef,METH_VARARGS,oaAssignAssignment_getAssignmentDef_doc},
    {"setAssignmentDef",(PyCFunction)oaAssignAssignment_setAssignmentDef,METH_VARARGS,oaAssignAssignment_setAssignmentDef_doc},
    {"isNull",(PyCFunction)oaAssignAssignment_tp_isNull,METH_VARARGS,oaAssignAssignment_isNull_doc},
    {"assign",(PyCFunction)oaAssignAssignment_tp_assign,METH_VARARGS,oaAssignAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignAssignment_doc[] = 
"Class: oaAssignAssignment\n"
"  The oaAssignAssignment class implements a connection assignment that specifies assignment definition values to replace those specified in a corresponding oaConnectDef or a previously encountered oaAssignAssignment. Applications interpreting the connectivity continue searching up the design hierarchy for a connection assignment with the name specified in the oaAssignAssignment. If none is found, the assignment value is the default net name.\n"
"  This type of connection assignment is useful for integrating a block of intellectual property that contain connection definition. An oaAssignAssignment can be used to insure that connectivity traversal applications search for connection assignments consistently in the entire design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaAssignAssignment)\n"
"    Calls: (const oaAssignAssignment&)\n"
"    Signature: oaAssignAssignment||cref-oaAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignAssignment",
    sizeof(PyoaAssignAssignmentObject),
    0,
    (destructor)oaAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAssignAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignAssignment_static_create_doc[] = 
"Class: oaAssignAssignment, Function: create\n"
"  Paramegers: (oaInst,oaString,oaAssignmentDef)\n"
"    Calls: oaAssignAssignment* create(const oaInst* inst,const oaString& name,const oaAssignmentDef& aDef)\n"
"    Signature: create|ptr-oaAssignAssignment|cptr-oaInst,cref-oaString,cref-oaAssignmentDef,\n"
"    This function creates an oaAssignAssignment with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance on which to create the connection assignment\n"
"    name\n"
"    The name to give to this assignment. This name should correspond to the lookup name specified in the assignment definition of an oaNetConnectDef or oaTermConnectDef object.\n"
"    assignmentDef\n"
"    Specifies the assignment definition values to replace those of a corresponding oaNetConnectDef or oaTermConnectDef object.\n"
"    oacInstHasAssignment\n"
"    oacInvalidAssignmentDef\n"
;

static PyObject*
oaAssignAssignment_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst p1;
    PyParamoaString p2;
    PyParamoaAssignmentDef p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaInst_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaAssignmentDef_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaAssignAssignmentp result= (oaAssignAssignment::create(p1.Data(),p2.Data(),p3.Data()));
        return PyoaAssignAssignment_FromoaAssignAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaAssignAssignment_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaAssignAssignment_static_create,METH_VARARGS,oaAssignAssignment_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignAssignment",
           (PyObject*)(&PyoaAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignAssignment\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaAssignAssignment_Type.tp_dict;
    for(method=oaAssignAssignment_staticmethodlist;method->ml_name!=NULL;method++) {
        value=PyCFunction_New(method,NULL);
    if (value==NULL) return -1;
        if (PyDict_SetItemString(dict,method->ml_name,value)!=0) {
        Py_DECREF(value);
            printf("** Failed to add static function to module dictionary for: %s\n",
                method->ml_name);
            return -1;
        }
        Py_DECREF(value);
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignValueObject* self = (PyoaAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaAssignValue)
    {
        PyParamoaAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignValue_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignValue, Choices are:\n"
        "    (oaAssignValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignValue_tp_dealloc(PyoaAssignValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaAssignValue value;
    int convert_status=PyoaAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaAssignValue::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[35];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaAssignValue::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignValue v1;
    PyParamoaAssignValue v2;
    int convert_status1=PyoaAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignValue_Convert(PyObject* ob,PyParamoaAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignValue_Check(ob)) {
        result->SetData( (oaAssignValue**) ((PyoaAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignValue_FromoaAssignValue(oaAssignValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaAssignValue* data=*value;
        PyObject* bself = PyoaAssignValue_Type.tp_alloc(&PyoaAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignValueObject* self = (PyoaAssignValueObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignValue_FromoaAssignValue(oaAssignValue* data)
{
    if (data) {
       PyObject* bself = PyoaAssignValue_Type.tp_alloc(&PyoaAssignValue_Type,0);
       if (bself == NULL) return bself;
       PyoaAssignValueObject* self = (PyoaAssignValueObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignValue_getValue_doc[] = 
"Class: oaAssignValue, Function: getValue\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getValue(oaSimpleName& netName) const\n"
"    Signature: getValue|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function returns the netName of this oaAssignValue object. This netName specifies the name of a single-bit net to use to in resolving the connections associated with a corresponding oaConnectDef object in the design hierarchy.\n"
;

static PyObject*
oaAssignValue_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignValue data;
    int convert_status=PyoaAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignValueObject* self=(PyoaAssignValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSimpleName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSimpleName_Convert,&p1)) {
        data.DataCall()->getValue(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignValue_setValue_doc[] = 
"Class: oaAssignValue, Function: setValue\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setValue(const oaScalarName& netName)\n"
"    Signature: setValue|void-void|cref-oaScalarName,\n"
"    This function sets the netName value of this oaAssignValue object.\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void setValue(const oaVectorBitName& netName)\n"
"    Signature: setValue|void-void|cref-oaVectorBitName,\n"
"    This function sets the netName value of this oaAssignValue object.\n"
;

static PyObject*
oaAssignValue_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignValue data;
    int convert_status=PyoaAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignValueObject* self=(PyoaAssignValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->setValue(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->setValue(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaAssignValue, function: setValue, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaVectorBitName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignValue_isNull_doc[] =
"Class: oaAssignValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaAssignValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaAssignValue data;
    int convert_status=PyoaAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaAssignValue_assign_doc[] = 
"Class: oaAssignValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAssignValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAssignValue data;
  int convert_status=PyoaAssignValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAssignValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAssignValue_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAssignValue_methodlist[] = {
    {"getValue",(PyCFunction)oaAssignValue_getValue,METH_VARARGS,oaAssignValue_getValue_doc},
    {"setValue",(PyCFunction)oaAssignValue_setValue,METH_VARARGS,oaAssignValue_setValue_doc},
    {"isNull",(PyCFunction)oaAssignValue_tp_isNull,METH_VARARGS,oaAssignValue_isNull_doc},
    {"assign",(PyCFunction)oaAssignValue_tp_assign,METH_VARARGS,oaAssignValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignValue_doc[] = 
"Class: oaAssignValue\n"
"  The oaAssignValue class implements a connection assignment that specifies\n"
"  the name of the net to use in place of the name of the net associated with the corresponding oaNetConnectDef object\n"
"  the name of the net to use to externally connect to the terminal associated with the corresponding oaTermConnectDef object\n"
"Constructors:\n"
"  Paramegers: (oaAssignValue)\n"
"    Calls: (const oaAssignValue&)\n"
"    Signature: oaAssignValue||cref-oaAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignValue",
    sizeof(PyoaAssignValueObject),
    0,
    (destructor)oaAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAssignValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignValue_static_create_doc[] = 
"Class: oaAssignValue, Function: create\n"
"  Paramegers: (oaInst,oaString,oaScalarName)\n"
"    Calls: oaAssignValue* create(const oaInst* inst,const oaString& name,const oaScalarName& netName)\n"
"    Signature: create|ptr-oaAssignValue|cptr-oaInst,cref-oaString,cref-oaScalarName,\n"
"    This function creates an oaAssignValue object with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance this assign will be attached to. It will apply to ConnectDefs in the hierarchy underneath this instance.\n"
"    name\n"
"    The name to give to the assignment. This name should correspond to the assignment name specified in the assignment definition in an oaNetConnectDef or oaTermConnectDef .\n"
"    netName\n"
"    The name of a scalar net to be used when resolving the connectivity associated with oaNetConnectDef and oaTermConnectDef objects in a design hierarchy.\n"
"    oacInstHasAssignment\n"
"  Paramegers: (oaInst,oaString,oaVectorBitName)\n"
"    Calls: oaAssignValue* create(const oaInst* inst,const oaString& name,const oaVectorBitName& netName)\n"
"    Signature: create|ptr-oaAssignValue|cptr-oaInst,cref-oaString,cref-oaVectorBitName,\n"
"    This function creates an oaAssignValue object with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance this assign will be attached to. It will apply to ConnectDefs in the hierarchy underneath this instance.\n"
"    name\n"
"    The name to give to the assignment. This name should correspond to the assignment name specified in the assignment definition in an oaNetConnectDef or oaTermConnectDef object.\n"
"    netName\n"
"    The name of a single-bit bus net used to resolve the connectivity associated with oaNetConnectDef and oaTermConnectDef objects in a design hierarchy.\n"
"    oacInstHasAssignment\n"
;

static PyObject*
oaAssignValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaInst,oaString,oaScalarName)
    {
        PyParamoaInst p1;
        PyParamoaString p2;
        PyParamoaScalarName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaScalarName_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAssignValuep result= (oaAssignValue::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaAssignValue_FromoaAssignValue(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaString,oaVectorBitName)
    {
        PyParamoaInst p1;
        PyParamoaString p2;
        PyParamoaVectorBitName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaVectorBitName_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAssignValuep result= (oaAssignValue::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaAssignValue_FromoaAssignValue(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaAssignValue, function: create, Choices are:\n"
        "    (oaInst,oaString,oaScalarName)\n"
        "    (oaInst,oaString,oaVectorBitName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaAssignValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaAssignValue_static_create,METH_VARARGS,oaAssignValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignValue",
           (PyObject*)(&PyoaAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaAssignValue_Type.tp_dict;
    for(method=oaAssignValue_staticmethodlist;method->ml_name!=NULL;method++) {
        value=PyCFunction_New(method,NULL);
    if (value==NULL) return -1;
        if (PyDict_SetItemString(dict,method->ml_name,value)!=0) {
        Py_DECREF(value);
            printf("** Failed to add static function to module dictionary for: %s\n",
                method->ml_name);
            return -1;
        }
        Py_DECREF(value);
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignedNetSpec
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignedNetSpec_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignedNetSpec_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignedNetSpecObject* self = (PyoaAssignedNetSpecObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaAssignedNetSpec();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDesignObject*)  new oaAssignedNetSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAssignedNetSpec)
    {
        PyParamoaAssignedNetSpec p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignedNetSpec_Convert,&p1)) {
            self->value=(oaArrayBase_oaDesignObject*)  new oaAssignedNetSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignedNetSpec, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaAssignedNetSpec)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignedNetSpec_tp_dealloc(PyoaAssignedNetSpecObject* self)
{
    if (!self->borrow) {
        delete (oaAssignedNetSpec*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignedNetSpec_tp_repr(PyObject *ob)
{
    PyParamoaAssignedNetSpec value;
    int convert_status=PyoaAssignedNetSpec_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaAssignedNetSpec::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignedNetSpec_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignedNetSpec v1;
    PyParamoaAssignedNetSpec v2;
    int convert_status1=PyoaAssignedNetSpec_Convert(ob1,&v1);
    int convert_status2=PyoaAssignedNetSpec_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignedNetSpec_Convert(PyObject* ob,PyParamoaAssignedNetSpec* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignedNetSpec_Check(ob)) {
        result->SetData( (oaAssignedNetSpec*) ((PyoaAssignedNetSpecObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignedNetSpec Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignedNetSpec_FromoaAssignedNetSpec(oaAssignedNetSpec* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaAssignedNetSpec_Type.tp_alloc(&PyoaAssignedNetSpec_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignedNetSpecObject* self = (PyoaAssignedNetSpecObject*)bself;
        self->value = (oaArrayBase_oaDesignObject*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignedNetSpec_doc[] = 
"Class: oaAssignedNetSpec\n"
"  This class implements an array of pointers to design objects that may be either connectDef objects or assignment objects in either the module or occurence domain. The common use of objects for this class is to extract the assigned net functionality from an occurrence net, terminal or instTerm for diagnostic use.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaAssignedNetSpec()\n"
"    Signature: oaAssignedNetSpec||simple-oaUInt4,\n"
"    This is the constructor for the oaAssignedNetSpec class. It constructs an array of object pointers of the specified size.\n"
"    sizeIn\n"
"    The initial size of the array\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaAssignedNetSpec(oaUInt4 sizeIn)\n"
"    Signature: oaAssignedNetSpec||simple-oaUInt4,\n"
"    This is the constructor for the oaAssignedNetSpec class. It constructs an array of object pointers of the specified size.\n"
"    sizeIn\n"
"    The initial size of the array\n"
"  Paramegers: (oaAssignedNetSpec)\n"
"    Calls: (const oaAssignedNetSpec&)\n"
"    Signature: oaAssignedNetSpec||cref-oaAssignedNetSpec,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignedNetSpec_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignedNetSpec",
    sizeof(PyoaAssignedNetSpecObject),
    0,
    (destructor)oaAssignedNetSpec_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignedNetSpec_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignedNetSpec_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignedNetSpec_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaDesignObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignedNetSpec_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignedNetSpec_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignedNetSpec_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignedNetSpec\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignedNetSpec",
           (PyObject*)(&PyoaAssignedNetSpec_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignedNetSpec\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignmentObject* self = (PyoaAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaAssignment)
    {
        PyParamoaAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignment_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignment, Choices are:\n"
        "    (oaAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignment_tp_dealloc(PyoaAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignment_tp_repr(PyObject *ob)
{
    PyParamoaAssignment value;
    int convert_status=PyoaAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaAssignment::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignment v1;
    PyParamoaAssignment v2;
    int convert_status1=PyoaAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignment_Convert(PyObject* ob,PyParamoaAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignment_Check(ob)) {
        result->SetData( (oaAssignment**) ((PyoaAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignment_FromoaAssignment(oaAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaAssignment* data=*value;
        if (data->getType()==oacAssignAssignmentType) return PyoaAssignAssignment_FromoaAssignAssignment((oaAssignAssignment**)value,borrow,lock);
        if (data->getType()==oacAssignValueType) return PyoaAssignValue_FromoaAssignValue((oaAssignValue**)value,borrow,lock);
        PyObject* bself = PyoaAssignment_Type.tp_alloc(&PyoaAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignmentObject* self = (PyoaAssignmentObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignment_FromoaAssignment(oaAssignment* data)
{
    if (data) {
        if (data->getType()==oacAssignAssignmentType) return PyoaAssignAssignment_FromoaAssignAssignment((oaAssignAssignment*)data);
        if (data->getType()==oacAssignValueType) return PyoaAssignValue_FromoaAssignValue((oaAssignValue*)data);
       PyObject* bself = PyoaAssignment_Type.tp_alloc(&PyoaAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaAssignmentObject* self = (PyoaAssignmentObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignment_destroy_doc[] = 
"Class: oaAssignment, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this assignment, removing it from the database.\n"
;

static PyObject*
oaAssignment_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentObject* self=(PyoaAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->destroy();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignment_getInst_doc[] = 
"Class: oaAssignment, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the instance with which this assignment is associated.\n"
;

static PyObject*
oaAssignment_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentObject* self=(PyoaAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getInst());
        return PyoaInst_FromoaInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignment_getName_doc[] = 
"Class: oaAssignment, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this assignment in the given name string. This is the name searched for when resolving the connections for the oaNetConnectDef and oaTermConnectDef objects.\n"
;

static PyObject*
oaAssignment_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentObject* self=(PyoaAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignment_setInst_doc[] = 
"Class: oaAssignment, Function: setInst\n"
"  Paramegers: (oaInst)\n"
"    Calls: void setInst(oaInst* inst)\n"
"    Signature: setInst|void-void|ptr-oaInst,\n"
"    This function changes the instance with which this assignment is associated.\n"
"    oacInstAndAssignmentNotInSameBlock\n"
;

static PyObject*
oaAssignment_setInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentObject* self=(PyoaAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInst_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setInst(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignment_setName_doc[] = 
"Class: oaAssignment, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the assignment name for this assignment object.\n"
;

static PyObject*
oaAssignment_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentObject* self=(PyoaAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignment_isNull_doc[] =
"Class: oaAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaAssignment data;
    int convert_status=PyoaAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaAssignment_assign_doc[] = 
"Class: oaAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAssignment data;
  int convert_status=PyoaAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAssignment_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAssignment_methodlist[] = {
    {"destroy",(PyCFunction)oaAssignment_destroy,METH_VARARGS,oaAssignment_destroy_doc},
    {"getInst",(PyCFunction)oaAssignment_getInst,METH_VARARGS,oaAssignment_getInst_doc},
    {"getName",(PyCFunction)oaAssignment_getName,METH_VARARGS,oaAssignment_getName_doc},
    {"setInst",(PyCFunction)oaAssignment_setInst,METH_VARARGS,oaAssignment_setInst_doc},
    {"setName",(PyCFunction)oaAssignment_setName,METH_VARARGS,oaAssignment_setName_doc},
    {"isNull",(PyCFunction)oaAssignment_tp_isNull,METH_VARARGS,oaAssignment_isNull_doc},
    {"assign",(PyCFunction)oaAssignment_tp_assign,METH_VARARGS,oaAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignment_doc[] = 
"Class: oaAssignment\n"
"  The oaAssignment class is the base class for all types of connection assignments. The oaAssignment objects specify the overriding assignments for the connection definitions specified in corresponding oaConnectDef objects. Together, these objects allow you to specify how nets are to be connected to by name in a design hierarchy.\n"
"  The oaAssignment class can be observed by deriving from\n"
"  See oaNetConnectDef and oaTermConnectDef for information on the specific type of connection definition. See oaAssignValue and oaAssignAssignment for information on the specific type of connection assignment.\n"
"Constructors:\n"
"  Paramegers: (oaAssignment)\n"
"    Calls: (const oaAssignment&)\n"
"    Signature: oaAssignment||cref-oaAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignment",
    sizeof(PyoaAssignmentObject),
    0,
    (destructor)oaAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignment_static_find_doc[] = 
"Class: oaAssignment, Function: find\n"
"  Paramegers: (oaInst,oaString)\n"
"    Calls: oaAssignment* find(const oaInst* inst,const oaString& name)\n"
"    Signature: find|ptr-oaAssignment|cptr-oaInst,cref-oaString,\n"
"    This function searches the specified instance for an assignment with the specified lookup name .\n"
"    A pointer to the assignment, if found\n"
;

static PyObject*
oaAssignment_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaInst_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaAssignmentp result= (oaAssignment::find(p1.Data(),p2.Data()));
        return PyoaAssignment_FromoaAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaAssignment_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaAssignment_static_find,METH_VARARGS,oaAssignment_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignment",
           (PyObject*)(&PyoaAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignment\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaAssignment_Type.tp_dict;
    for(method=oaAssignment_staticmethodlist;method->ml_name!=NULL;method++) {
        value=PyCFunction_New(method,NULL);
    if (value==NULL) return -1;
        if (PyDict_SetItemString(dict,method->ml_name,value)!=0) {
        Py_DECREF(value);
            printf("** Failed to add static function to module dictionary for: %s\n",
                method->ml_name);
            return -1;
        }
        Py_DECREF(value);
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignmentAttrType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignmentAttrType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignmentAttrType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignmentAttrTypeObject* self = (PyoaAssignmentAttrTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaAssignmentAttrTypeEnum)
    {
        PyParamoaAssignmentAttrTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAssignmentAttrTypeEnum_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaAssignmentAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaAssignmentAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAttrType)
    {
        PyParamoaAttrType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAttrType_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaAssignmentAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAssignmentAttrType)
    {
        PyParamoaAssignmentAttrType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignmentAttrType_Convert,&p1)) {
            self->value=(oaAttrType*)  new oaAssignmentAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignmentAttrType, Choices are:\n"
        "    (oaAssignmentAttrTypeEnum)\n"
        "    (oaString)\n"
        "    (oaAttrType)\n"
        "    (oaAssignmentAttrType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignmentAttrType_tp_dealloc(PyoaAssignmentAttrTypeObject* self)
{
    if (!self->borrow) {
        delete (oaAssignmentAttrType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignmentAttrType_tp_repr(PyObject *ob)
{
    PyParamoaAssignmentAttrType value;
    int convert_status=PyoaAssignmentAttrType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[42];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaAssignmentAttrType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignmentAttrType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignmentAttrType v1;
    PyParamoaAssignmentAttrType v2;
    int convert_status1=PyoaAssignmentAttrType_Convert(ob1,&v1);
    int convert_status2=PyoaAssignmentAttrType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignmentAttrType_Convert(PyObject* ob,PyParamoaAssignmentAttrType* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignmentAttrType_Check(ob)) {
        result->SetData( (oaAssignmentAttrType*) ((PyoaAssignmentAttrTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignmentAttrType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignmentAttrType_FromoaAssignmentAttrType(oaAssignmentAttrType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaAssignmentAttrType_Type.tp_alloc(&PyoaAssignmentAttrType_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignmentAttrTypeObject* self = (PyoaAssignmentAttrTypeObject*)bself;
        self->value = (oaAttrType*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignmentAttrType_getName_doc[] = 
"Class: oaAssignmentAttrType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    The function returns the name string associated with the encapsulated #oaAssignmentAttrTypeEnum object.\n"
;

static PyObject*
oaAssignmentAttrType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentAttrType data;
    int convert_status=PyoaAssignmentAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentAttrTypeObject* self=(PyoaAssignmentAttrTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaString result= (data.DataCall()->getName());
        return PyoaString_FromoaString(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignmentAttrType_getValue_doc[] = 
"Class: oaAssignmentAttrType, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaAssignmentAttrTypeEnum getValue() const\n"
"    Signature: getValue|simple-oaAssignmentAttrTypeEnum|\n"
"    BrowseData: 1\n"
"    This function returns the integer enum value of this assign attribute type.\n"
;

static PyObject*
oaAssignmentAttrType_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentAttrType data;
    int convert_status=PyoaAssignmentAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentAttrTypeObject* self=(PyoaAssignmentAttrTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaAssignmentAttrTypeEnum result= (data.DataCall()->getValue());
        return PyoaAssignmentAttrTypeEnum_FromoaAssignmentAttrTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaAssignmentAttrType_assign_doc[] = 
"Class: oaAssignmentAttrType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAssignmentAttrType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAssignmentAttrType data;
  int convert_status=PyoaAssignmentAttrType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAssignmentAttrType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAssignmentAttrType_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAssignmentAttrType_methodlist[] = {
    {"getName",(PyCFunction)oaAssignmentAttrType_getName,METH_VARARGS,oaAssignmentAttrType_getName_doc},
    {"getValue",(PyCFunction)oaAssignmentAttrType_getValue,METH_VARARGS,oaAssignmentAttrType_getValue_doc},
    {"assign",(PyCFunction)oaAssignmentAttrType_tp_assign,METH_VARARGS,oaAssignmentAttrType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignmentAttrType_doc[] = 
"Class: oaAssignmentAttrType\n"
"  The oaAssignmentAttrType class is a wrapper for the the enumerated values that represent the different attributes of an oaAssignment object that can be referenced by an oaAttrDisplay object.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaAssignmentAttrTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaAssignmentAttrTypeEnum)\n"
"    Calls: oaAssignmentAttrType(oaAssignmentAttrTypeEnum vIn)\n"
"    Signature: oaAssignmentAttrType||simple-oaAssignmentAttrTypeEnum,\n"
"    This function constructs an instance of an oaAssignmentAttrType class using the specified #oaAssignmentAttrTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaAssignmentAttrType(const oaString& name)\n"
"    Signature: oaAssignmentAttrType||cref-oaString,\n"
"    This function constructs an instance of an oaAssignmentAttrType class using the #oaAssignmentAttrTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaAssignmentAttrTypeEnum.\n"
"    oacInvalidAssignmentAttrTypeName\n"
"  Paramegers: (oaAttrType)\n"
"    Calls: oaAssignmentAttrType(oaAttrType attr)\n"
"    Signature: oaAssignmentAttrType||simple-oaAttrType,\n"
"    This function constructs an oaAssignmentAttrType class using the oaAttrType as input to support the class down-cast.\n"
"  Paramegers: (oaAssignmentAttrType)\n"
"    Calls: (const oaAssignmentAttrType&)\n"
"    Signature: oaAssignmentAttrType||cref-oaAssignmentAttrType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignmentAttrType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignmentAttrType",
    sizeof(PyoaAssignmentAttrTypeObject),
    0,
    (destructor)oaAssignmentAttrType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignmentAttrType_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignmentAttrType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignmentAttrType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAssignmentAttrType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAttrType_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignmentAttrType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignmentAttrType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignmentAttrType_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignmentAttrType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignmentAttrType",
           (PyObject*)(&PyoaAssignmentAttrType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignmentAttrType\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignmentAttrTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaAssignmentAttrTypeEnum_Convert(PyObject* ob,PyParamoaAssignmentAttrTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNameAssignmentAttrType")==0) { result->SetData(oacNameAssignmentAttrType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaAssignmentAttrTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignmentAttrTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaAssignmentAttrTypeEnum_FromoaAssignmentAttrTypeEnum(oaAssignmentAttrTypeEnum ob)
{
    if (ob==oacNameAssignmentAttrType) return PyString_FromString("oacNameAssignmentAttrType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaAssignmentAttrTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaAssignmentAttrTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaAssignmentAttrTypeEnum_FromoaAssignmentAttrTypeEnum(oaAssignmentAttrTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaAssignmentAttrTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaAssignmentAttrTypeEnum_doc[] =
"Type convert function for enum: oaAssignmentAttrTypeEnum";
                               
static PyMethodDef PyoaAssignmentAttrTypeEnum_method =
  {"oaAssignmentAttrTypeEnum",(PyCFunction)PyoaAssignmentAttrTypeEnum_TypeFunction,METH_VARARGS,oaAssignmentAttrTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaAssignmentAttrTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNameAssignmentAttrType");
    PyDict_SetItemString(mod_dict,"oacNameAssignmentAttrType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaAssignmentAttrTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaAssignmentAttrTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaAssignmentAttrTypeEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaAssignmentDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAssignmentDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAssignmentDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAssignmentDefObject* self = (PyoaAssignmentDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaAssignmentDef();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaScalarName)
    {
        PyParamoaString p1;
        PyParamoaScalarName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaScalarName_Convert,&p2)) {
            self->value =  new oaAssignmentDef(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaVectorBitName)
    {
        PyParamoaString p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            self->value =  new oaAssignmentDef(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAssignmentDef)
    {
        PyParamoaAssignmentDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAssignmentDef_Convert,&p1)) {
            self->value= new oaAssignmentDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAssignmentDef, Choices are:\n"
        "    ()\n"
        "    (oaString,oaScalarName)\n"
        "    (oaString,oaVectorBitName)\n"
        "    (oaAssignmentDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAssignmentDef_tp_dealloc(PyoaAssignmentDefObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAssignmentDef_tp_repr(PyObject *ob)
{
    PyParamoaAssignmentDef value;
    int convert_status=PyoaAssignmentDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaAssignmentDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAssignmentDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAssignmentDef v1;
    PyParamoaAssignmentDef v2;
    int convert_status1=PyoaAssignmentDef_Convert(ob1,&v1);
    int convert_status2=PyoaAssignmentDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAssignmentDef_Convert(PyObject* ob,PyParamoaAssignmentDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaAssignmentDef_Check(ob)) {
        result->SetData(  ((PyoaAssignmentDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignmentDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAssignmentDef_FromoaAssignmentDef(oaAssignmentDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaAssignmentDef_Type.tp_alloc(&PyoaAssignmentDef_Type,0);
        if (bself == NULL) return bself;
        PyoaAssignmentDefObject* self = (PyoaAssignmentDefObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignmentDef_assignmentName_doc[] = 
"Class: oaAssignmentDef, Function: assignmentName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& assignmentName() const\n"
"    Signature: assignmentName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns a const reference to the assignment name in this oaAssignmentDef. The assignmentName is the name of an oaAssignment to search for when resolving the connectivity for a corresponding oaNetConnectDef or oaTermConnectDef object.\n"
;

static PyObject*
oaAssignmentDef_assignmentName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentDef data;
    int convert_status=PyoaAssignmentDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentDefObject* self=(PyoaAssignmentDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaString result= (data.DataCall()->assignmentName());
        return PyoaString_FromoaString(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignmentDef_defaultName_doc[] = 
"Class: oaAssignmentDef, Function: defaultName\n"
"  Paramegers: ()\n"
"    Calls: const oaSimpleName& defaultName() const\n"
"    Signature: defaultName|cref-oaSimpleName|\n"
"    BrowseData: 1\n"
"    This function returns a const reference to the oaSimpleName stored in this oaAssignmentDef. The name is either an oaScalarName or oaVectorBitName and specifies a single-bit net name. You can query the name type in order to access the corresponding oaScalarName or oaVectorBitName information.\n"
;

static PyObject*
oaAssignmentDef_defaultName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentDef data;
    int convert_status=PyoaAssignmentDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentDefObject* self=(PyoaAssignmentDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSimpleName* result= new oaSimpleName(data.DataCall()->defaultName());
        return PyoaSimpleName_FromoaSimpleName(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignmentDef_setAssignmentName_doc[] = 
"Class: oaAssignmentDef, Function: setAssignmentName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setAssignmentName(const oaString& assignName)\n"
"    Signature: setAssignmentName|void-void|cref-oaString,\n"
"    This function changes the assignment name in this assignment definition.\n"
;

static PyObject*
oaAssignmentDef_setAssignmentName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentDef data;
    int convert_status=PyoaAssignmentDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentDefObject* self=(PyoaAssignmentDefObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setAssignmentName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAssignmentDef_setDefaultName_doc[] = 
"Class: oaAssignmentDef, Function: setDefaultName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setDefaultName(const oaScalarName& defaultN)\n"
"    Signature: setDefaultName|void-void|cref-oaScalarName,\n"
"    This function changes the default net name in this assignment definition.\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void setDefaultName(const oaVectorBitName& defaultN)\n"
"    Signature: setDefaultName|void-void|cref-oaVectorBitName,\n"
"    This function changes the default net name in this assignment definition.\n"
;

static PyObject*
oaAssignmentDef_setDefaultName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAssignmentDef data;
    int convert_status=PyoaAssignmentDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAssignmentDefObject* self=(PyoaAssignmentDefObject*)ob;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->setDefaultName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->setDefaultName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaAssignmentDef, function: setDefaultName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaVectorBitName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaAssignmentDef_assign_doc[] = 
"Class: oaAssignmentDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAssignmentDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAssignmentDef data;
  int convert_status=PyoaAssignmentDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAssignmentDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAssignmentDef_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAssignmentDef_methodlist[] = {
    {"assignmentName",(PyCFunction)oaAssignmentDef_assignmentName,METH_VARARGS,oaAssignmentDef_assignmentName_doc},
    {"defaultName",(PyCFunction)oaAssignmentDef_defaultName,METH_VARARGS,oaAssignmentDef_defaultName_doc},
    {"setAssignmentName",(PyCFunction)oaAssignmentDef_setAssignmentName,METH_VARARGS,oaAssignmentDef_setAssignmentName_doc},
    {"setDefaultName",(PyCFunction)oaAssignmentDef_setDefaultName,METH_VARARGS,oaAssignmentDef_setDefaultName_doc},
    {"assign",(PyCFunction)oaAssignmentDef_tp_assign,METH_VARARGS,oaAssignmentDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAssignmentDef_doc[] = 
"Class: oaAssignmentDef\n"
"  The oaAssignmentDef class is a utility class used with the oaConnectDef and oaAssigAssignment objects. The oaAssignmentDef class specifies an assignment name and a default net name. The assignment name specifies the name of an oaAssignment to search for when resolving connectivity associated with an oaConnectDef .\n"
"  When an oaAssignmentDef is used with an oaNetConnectDef , the default net name specifies the name to default to for the net if a corresponding assignment is not found.\n"
"  When an oaAssignmentDef is used with an oaTermConnectDef , the default net name specifies the name to default to for the net to externally connect the terminal to if a corresponding assignment is not found.\n"
"  When an oaAssignmentDef is used with an oaAssignAssignment , its assignment name and default net name override those on the corresponding oaConnectDef and the search for a matching assignment continues using the new assignment name. If an assignment is still not found, then the default net name in the oaAssignAssignment is used to resolve the connectivity.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaAssignmentDef()\n"
"    Signature: oaAssignmentDef||\n"
"    This function constructs an empty oaAssignmentDef object. This is useful for constructing an oaAssignmentDef object that can be used to get the connection definition from an oaConnectDef or oaAssigAssignment object.\n"
"  Paramegers: (oaString,oaScalarName)\n"
"    Calls: oaAssignmentDef(const oaString& assignName,const oaScalarName& defaultN)\n"
"    Signature: oaAssignmentDef||cref-oaString,cref-oaScalarName,\n"
"    This function constructs an oaAssignmentDef object with the given assignmentName and defaultName where the defaultName is an oaScalarName .\n"
"    assignmentName\n"
"    This specifies the name of the assignment to search for when resolving the connectivity for a corresponding oaConnectDef\n"
"    defaultName\n"
"    This is the net name to default to if no matching oaAssignment is found\n"
"  Paramegers: (oaString,oaVectorBitName)\n"
"    Calls: oaAssignmentDef(const oaString& assignN,const oaVectorBitName& defaultN)\n"
"    Signature: oaAssignmentDef||cref-oaString,cref-oaVectorBitName,\n"
"    This function constructs an oaAssignmentDef object with the given assignmentName and defaultName where the defaultName is an oaVectorBitName .\n"
"    assignmentName\n"
"    This specifies the name of the assignment to search for when resolving the connectivity for an associated oaConnectDef\n"
"    defaultName\n"
"    This is the net name to default to if no matching oaAssignment is found\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: (const oaAssignmentDef&)\n"
"    Signature: oaAssignmentDef||cref-oaAssignmentDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAssignmentDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAssignmentDef",
    sizeof(PyoaAssignmentDefObject),
    0,
    (destructor)oaAssignmentDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAssignmentDef_tp_compare,	/* tp_compare */
    (reprfunc)oaAssignmentDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAssignmentDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAssignmentDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAssignmentDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAssignmentDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAssignmentDef_Type)<0) {
      printf("** PyType_Ready failed for: oaAssignmentDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAssignmentDef",
           (PyObject*)(&PyoaAssignmentDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAssignmentDef\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAssignmentModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaAssignmentModTypeEnum_Convert(PyObject* ob,PyParamoaAssignmentModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameAssignmentModType")==0) { result->SetData(oacSetNameAssignmentModType); return 1;}
        if (strcasecmp(str,"oacSetInstAssignmentModType")==0) { result->SetData(oacSetInstAssignmentModType); return 1;}
        if (strcasecmp(str,"oacAssignValueSetValueAssignmentModType")==0) { result->SetData(oacAssignValueSetValueAssignmentModType); return 1;}
        if (strcasecmp(str,"oacAssignAssignSetDefAssignmentModType")==0) { result->SetData(oacAssignAssignSetDefAssignmentModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaAssignmentModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAssignmentModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(oaAssignmentModTypeEnum ob)
{
    if (ob==oacSetNameAssignmentModType) return PyString_FromString("oacSetNameAssignmentModType");
    if (ob==oacSetInstAssignmentModType) return PyString_FromString("oacSetInstAssignmentModType");
    if (ob==oacAssignValueSetValueAssignmentModType) return PyString_FromString("oacAssignValueSetValueAssignmentModType");
    if (ob==oacAssignAssignSetDefAssignmentModType) return PyString_FromString("oacAssignAssignSetDefAssignmentModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaAssignmentModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaAssignmentModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(oaAssignmentModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaAssignmentModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaAssignmentModTypeEnum_doc[] =
"Type convert function for enum: oaAssignmentModTypeEnum";
                               
static PyMethodDef PyoaAssignmentModTypeEnum_method =
  {"oaAssignmentModTypeEnum",(PyCFunction)PyoaAssignmentModTypeEnum_TypeFunction,METH_VARARGS,oaAssignmentModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaAssignmentModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameAssignmentModType");
    PyDict_SetItemString(mod_dict,"oacSetNameAssignmentModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetInstAssignmentModType");
    PyDict_SetItemString(mod_dict,"oacSetInstAssignmentModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAssignValueSetValueAssignmentModType");
    PyDict_SetItemString(mod_dict,"oacAssignValueSetValueAssignmentModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAssignAssignSetDefAssignmentModType");
    PyDict_SetItemString(mod_dict,"oacAssignAssignSetDefAssignmentModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaAssignmentModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaAssignmentModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaAssignmentModTypeEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAttrDisplayObject* self = (PyoaAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaAttrDisplay)
    {
        PyParamoaAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAttrDisplay_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAttrDisplay, Choices are:\n"
        "    (oaAttrDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAttrDisplay_tp_dealloc(PyoaAttrDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaAttrDisplay value;
    int convert_status=PyoaAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAttrDisplay v1;
    PyParamoaAttrDisplay v2;
    int convert_status1=PyoaAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAttrDisplay_Convert(PyObject* ob,PyParamoaAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaAttrDisplay_Check(ob)) {
        result->SetData( (oaAttrDisplay**) ((PyoaAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAttrDisplay_FromoaAttrDisplay(oaAttrDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaAttrDisplay* data=*value;
        PyObject* bself = PyoaAttrDisplay_Type.tp_alloc(&PyoaAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaAttrDisplayObject* self = (PyoaAttrDisplayObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaAttrDisplay_FromoaAttrDisplay(oaAttrDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaAttrDisplay_Type.tp_alloc(&PyoaAttrDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaAttrDisplayObject* self = (PyoaAttrDisplayObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAttrDisplay_getAttribute_doc[] = 
"Class: oaAttrDisplay, Function: getAttribute\n"
"  Paramegers: ()\n"
"    Calls: oaAttrType getAttribute() const\n"
"    Signature: getAttribute|simple-oaAttrType|\n"
"    BrowseData: 1\n"
"    This function returns the attribute displayed by this oaAttrDisplay object.\n"
;

static PyObject*
oaAttrDisplay_getAttribute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAttrDisplay data;
    int convert_status=PyoaAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAttrDisplayObject* self=(PyoaAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaAttrType* result= new oaAttrType(data.DataCall()->getAttribute());
        return PyoaAttrType_FromoaAttrType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAttrDisplay_getObject_doc[] = 
"Class: oaAttrDisplay, Function: getObject\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getObject() const\n"
"    Signature: getObject|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns the object whose attribute is displayed by this oaAttrDisplay object.\n"
;

static PyObject*
oaAttrDisplay_getObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAttrDisplay data;
    int convert_status=PyoaAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAttrDisplayObject* self=(PyoaAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaObjectp result= (data.DataCall()->getObject());
        return PyoaObject_FromoaObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAttrDisplay_getText_doc[] = 
"Class: oaAttrDisplay, Function: getText\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getText(const oaNameSpace& ns,oaString& text) const\n"
"    Signature: getText|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the value of this attribute display according to the given nameSpace. The nameSpace is only valid for name type attributes.\n"
;

static PyObject*
oaAttrDisplay_getText(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAttrDisplay data;
    int convert_status=PyoaAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAttrDisplayObject* self=(PyoaAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaNameSpace p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNameSpace_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        data.DataCall()->getText(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaAttrDisplay_isNull_doc[] =
"Class: oaAttrDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaAttrDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaAttrDisplay data;
    int convert_status=PyoaAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaAttrDisplay_assign_doc[] = 
"Class: oaAttrDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAttrDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAttrDisplay data;
  int convert_status=PyoaAttrDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAttrDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAttrDisplay_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAttrDisplay_methodlist[] = {
    {"getAttribute",(PyCFunction)oaAttrDisplay_getAttribute,METH_VARARGS,oaAttrDisplay_getAttribute_doc},
    {"getObject",(PyCFunction)oaAttrDisplay_getObject,METH_VARARGS,oaAttrDisplay_getObject_doc},
    {"getText",(PyCFunction)oaAttrDisplay_getText,METH_VARARGS,oaAttrDisplay_getText_doc},
    {"isNull",(PyCFunction)oaAttrDisplay_tp_isNull,METH_VARARGS,oaAttrDisplay_isNull_doc},
    {"assign",(PyCFunction)oaAttrDisplay_tp_assign,METH_VARARGS,oaAttrDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAttrDisplay_doc[] = 
"Class: oaAttrDisplay\n"
"  The oaAttrDisplay is a shape similar to an oaText object, except it presents a string that is the value of a specific, built-in attribute of the attached object. Whenever the value of the attribute changes, calling the getText function on this oaAttrDisplay object returns the updated text string that represents the new attribute value.\n"
"  The oaAttrDisplay is contained in the design that contains the attached design object.\n"
"  Note: The attribute is specified using one of many defined values. Each object type has its own set of values.\n"
"Constructors:\n"
"  Paramegers: (oaAttrDisplay)\n"
"    Calls: (const oaAttrDisplay&)\n"
"    Signature: oaAttrDisplay||cref-oaAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAttrDisplay",
    sizeof(PyoaAttrDisplayObject),
    0,
    (destructor)oaAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaAttrDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAttrDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAttrDisplay_static_create_doc[] = 
"Class: oaAttrDisplay, Function: create\n"
"  Paramegers: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
"    Calls: oaAttrDisplay* create(oaObject* object,oaAttrType attribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height)\n"
"    Signature: create|ptr-oaAttrDisplay|ptr-oaObject,simple-oaAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaAttrDisplay object that displays the specified attribute of the specified object. The object must be contained in a design database, and the attribute must be an attribute type of the object.\n"
"    object\n"
"    A pointer to the owner object\n"
"    attribute\n"
"    The attribute of interest on the owner object\n"
"    layer\n"
"    The layer on which the attrDisplay is created\n"
"    purpose\n"
"    The purpose on which the attrDisplay is created\n"
"    origin\n"
"    The location of the origin of the attrDisplay\n"
"    alignment\n"
"    The horizontal and vertical alignment of the display text with respect to the origin\n"
"    orient\n"
"    The orientation of the text\n"
"    font\n"
"    The font style in which the text is displayed\n"
"    height\n"
"    The height of the display text in user units\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    A boolean value that indicates if an overbar is used in the display of this value\n"
"    visible\n"
"    A boolean value that indicates if this attrDisplay is displayed; this allows the application to turn on or off the attrDisplay display without having to delete it from the database\n"
"    drafting\n"
"    A boolean value that indicates if the text for this attrDisplay should always be drawn left to right or top to bottom (if drafting is true and the orientation of this attrDisplay is mirrored, the text is drawn backwards)\n"
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
"    Calls: oaAttrDisplay* create(oaObject* object,oaAttrType attribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format)\n"
"    Signature: create|ptr-oaAttrDisplay|ptr-oaObject,simple-oaAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaAttrDisplay object that displays the specified attribute of the specified object. The object must be contained in a design database, and the attribute must be an attribute type of the object.\n"
"    object\n"
"    A pointer to the owner object\n"
"    attribute\n"
"    The attribute of interest on the owner object\n"
"    layer\n"
"    The layer on which the attrDisplay is created\n"
"    purpose\n"
"    The purpose on which the attrDisplay is created\n"
"    origin\n"
"    The location of the origin of the attrDisplay\n"
"    alignment\n"
"    The horizontal and vertical alignment of the display text with respect to the origin\n"
"    orient\n"
"    The orientation of the text\n"
"    font\n"
"    The font style in which the text is displayed\n"
"    height\n"
"    The height of the display text in user units\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    A boolean value that indicates if an overbar is used in the display of this value\n"
"    visible\n"
"    A boolean value that indicates if this attrDisplay is displayed; this allows the application to turn on or off the attrDisplay display without having to delete it from the database\n"
"    drafting\n"
"    A boolean value that indicates if the text for this attrDisplay should always be drawn left to right or top to bottom (if drafting is true and the orientation of this attrDisplay is mirrored, the text is drawn backwards)\n"
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
"    Calls: oaAttrDisplay* create(oaObject* object,oaAttrType attribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar)\n"
"    Signature: create|ptr-oaAttrDisplay|ptr-oaObject,simple-oaAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaAttrDisplay object that displays the specified attribute of the specified object. The object must be contained in a design database, and the attribute must be an attribute type of the object.\n"
"    object\n"
"    A pointer to the owner object\n"
"    attribute\n"
"    The attribute of interest on the owner object\n"
"    layer\n"
"    The layer on which the attrDisplay is created\n"
"    purpose\n"
"    The purpose on which the attrDisplay is created\n"
"    origin\n"
"    The location of the origin of the attrDisplay\n"
"    alignment\n"
"    The horizontal and vertical alignment of the display text with respect to the origin\n"
"    orient\n"
"    The orientation of the text\n"
"    font\n"
"    The font style in which the text is displayed\n"
"    height\n"
"    The height of the display text in user units\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    A boolean value that indicates if an overbar is used in the display of this value\n"
"    visible\n"
"    A boolean value that indicates if this attrDisplay is displayed; this allows the application to turn on or off the attrDisplay display without having to delete it from the database\n"
"    drafting\n"
"    A boolean value that indicates if the text for this attrDisplay should always be drawn left to right or top to bottom (if drafting is true and the orientation of this attrDisplay is mirrored, the text is drawn backwards)\n"
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
"    Calls: oaAttrDisplay* create(oaObject* object,oaAttrType attribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible)\n"
"    Signature: create|ptr-oaAttrDisplay|ptr-oaObject,simple-oaAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaAttrDisplay object that displays the specified attribute of the specified object. The object must be contained in a design database, and the attribute must be an attribute type of the object.\n"
"    object\n"
"    A pointer to the owner object\n"
"    attribute\n"
"    The attribute of interest on the owner object\n"
"    layer\n"
"    The layer on which the attrDisplay is created\n"
"    purpose\n"
"    The purpose on which the attrDisplay is created\n"
"    origin\n"
"    The location of the origin of the attrDisplay\n"
"    alignment\n"
"    The horizontal and vertical alignment of the display text with respect to the origin\n"
"    orient\n"
"    The orientation of the text\n"
"    font\n"
"    The font style in which the text is displayed\n"
"    height\n"
"    The height of the display text in user units\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    A boolean value that indicates if an overbar is used in the display of this value\n"
"    visible\n"
"    A boolean value that indicates if this attrDisplay is displayed; this allows the application to turn on or off the attrDisplay display without having to delete it from the database\n"
"    drafting\n"
"    A boolean value that indicates if the text for this attrDisplay should always be drawn left to right or top to bottom (if drafting is true and the orientation of this attrDisplay is mirrored, the text is drawn backwards)\n"
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
"    Calls: oaAttrDisplay* create(oaObject* object,oaAttrType attribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible,oaBoolean drafting)\n"
"    Signature: create|ptr-oaAttrDisplay|ptr-oaObject,simple-oaAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaAttrDisplay object that displays the specified attribute of the specified object. The object must be contained in a design database, and the attribute must be an attribute type of the object.\n"
"    object\n"
"    A pointer to the owner object\n"
"    attribute\n"
"    The attribute of interest on the owner object\n"
"    layer\n"
"    The layer on which the attrDisplay is created\n"
"    purpose\n"
"    The purpose on which the attrDisplay is created\n"
"    origin\n"
"    The location of the origin of the attrDisplay\n"
"    alignment\n"
"    The horizontal and vertical alignment of the display text with respect to the origin\n"
"    orient\n"
"    The orientation of the text\n"
"    font\n"
"    The font style in which the text is displayed\n"
"    height\n"
"    The height of the display text in user units\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    A boolean value that indicates if an overbar is used in the display of this value\n"
"    visible\n"
"    A boolean value that indicates if this attrDisplay is displayed; this allows the application to turn on or off the attrDisplay display without having to delete it from the database\n"
"    drafting\n"
"    A boolean value that indicates if the text for this attrDisplay should always be drawn left to right or top to bottom (if drafting is true and the orientation of this attrDisplay is mirrored, the text is drawn backwards)\n"
"    oacNonDesignTextDisplay\n"
;

static PyObject*
oaAttrDisplay_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)
    {
        PyParamoaObject p1;
        PyParamoaAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAttrDisplayp result= (oaAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data()));
            return PyoaAttrDisplay_FromoaAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)
    {
        PyParamoaObject p1;
        PyParamoaAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAttrDisplayp result= (oaAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data()));
            return PyoaAttrDisplay_FromoaAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAttrDisplayp result= (oaAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data()));
            return PyoaAttrDisplay_FromoaAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAttrDisplayp result= (oaAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data()));
            return PyoaAttrDisplay_FromoaAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        PyParamoaBoolean p13;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12,
              &PyoaBoolean_Convert,&p13)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaAttrDisplayp result= (oaAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data(),p13.Data()));
            return PyoaAttrDisplay_FromoaAttrDisplay(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaAttrDisplay, function: create, Choices are:\n"
        "    (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
        "    (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
        "    (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
        "    (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
        "    (oaObject,oaAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaAttrDisplay_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaAttrDisplay_static_create,METH_VARARGS,oaAttrDisplay_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAttrDisplay",
           (PyObject*)(&PyoaAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAttrDisplay\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaAttrDisplay_Type.tp_dict;
    for(method=oaAttrDisplay_staticmethodlist;method->ml_name!=NULL;method++) {
        value=PyCFunction_New(method,NULL);
    if (value==NULL) return -1;
        if (PyDict_SetItemString(dict,method->ml_name,value)!=0) {
        Py_DECREF(value);
            printf("** Failed to add static function to module dictionary for: %s\n",
                method->ml_name);
            return -1;
        }
        Py_DECREF(value);
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAttrType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaAttrType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaAttrType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaAttrTypeObject* self = (PyoaAttrTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaAttrType();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAttrType)
    {
        PyParamoaAttrType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaAttrType_Convert,&p1)) {
            self->value= new oaAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaAttrType, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaAttrType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaAttrType_tp_dealloc(PyoaAttrTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaAttrType_tp_repr(PyObject *ob)
{
    PyParamoaAttrType value;
    int convert_status=PyoaAttrType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaAttrType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaAttrType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaAttrType v1;
    PyParamoaAttrType v2;
    int convert_status1=PyoaAttrType_Convert(ob1,&v1);
    int convert_status2=PyoaAttrType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaAttrType_Convert(PyObject* ob,PyParamoaAttrType* result)
{
    if (ob == NULL) return 1;
    if (PyoaAttrType_Check(ob)) {
        result->SetData(  ((PyoaAttrTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAttrType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaAttrType_FromoaAttrType(oaAttrType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaAttrType_Type.tp_alloc(&PyoaAttrType_Type,0);
        if (bself == NULL) return bself;
        PyoaAttrTypeObject* self = (PyoaAttrTypeObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAttrType_getRawValue_doc[] = 
"Class: oaAttrType, Function: getRawValue\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRawValue()\n"
"    Signature: getRawValue|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the value of this attribute type.\n"
;

static PyObject*
oaAttrType_getRawValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaAttrType data;
    int convert_status=PyoaAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaAttrTypeObject* self=(PyoaAttrTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getRawValue());
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaAttrType_assign_doc[] = 
"Class: oaAttrType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaAttrType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaAttrType data;
  int convert_status=PyoaAttrType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaAttrType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaAttrType_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaAttrType_methodlist[] = {
    {"getRawValue",(PyCFunction)oaAttrType_getRawValue,METH_VARARGS,oaAttrType_getRawValue_doc},
    {"assign",(PyCFunction)oaAttrType_tp_assign,METH_VARARGS,oaAttrType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaAttrType_doc[] = 
"Class: oaAttrType\n"
"  The oaAttrType class is an abstract base class for a set of enum wrapper classes that specify attributes of various objects that can be used by an oaAttrDisplay . See the classes derived from oaAttrType for the specific attributes that are supported for this purpose.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaAttrType()\n"
"    Signature: oaAttrType||\n"
"    This function constructs an empty oaAttrType object.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaAttrType(oaUInt4 valueIn)\n"
"    Signature: oaAttrType||simple-oaUInt4,\n"
"    This function constructs an oaAttrType object that takes an oaUInt4 value as input.\n"
"  Paramegers: (oaAttrType)\n"
"    Calls: (const oaAttrType&)\n"
"    Signature: oaAttrType||cref-oaAttrType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaAttrType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaAttrType",
    sizeof(PyoaAttrTypeObject),
    0,
    (destructor)oaAttrType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaAttrType_tp_compare,	/* tp_compare */
    (reprfunc)oaAttrType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaAttrType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaAttrType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaAttrType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaAttrType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaAttrType_Type)<0) {
      printf("** PyType_Ready failed for: oaAttrType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaAttrType",
           (PyObject*)(&PyoaAttrType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaAttrType\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaAvatarModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaAvatarModTypeEnum_Convert(PyObject* ob,PyParamoaAvatarModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetIncarnationAvatarModType")==0) { result->SetData(oacSetIncarnationAvatarModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaAvatarModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaAvatarModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaAvatarModTypeEnum_FromoaAvatarModTypeEnum(oaAvatarModTypeEnum ob)
{
    if (ob==oacSetIncarnationAvatarModType) return PyString_FromString("oacSetIncarnationAvatarModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaAvatarModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaAvatarModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaAvatarModTypeEnum_FromoaAvatarModTypeEnum(oaAvatarModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaAvatarModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaAvatarModTypeEnum_doc[] =
"Type convert function for enum: oaAvatarModTypeEnum";
                               
static PyMethodDef PyoaAvatarModTypeEnum_method =
  {"oaAvatarModTypeEnum",(PyCFunction)PyoaAvatarModTypeEnum_TypeFunction,METH_VARARGS,oaAvatarModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaAvatarModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetIncarnationAvatarModType");
    PyDict_SetItemString(mod_dict,"oacSetIncarnationAvatarModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaAvatarModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaAvatarModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaAvatarModTypeEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaBaseCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBaseCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBaseCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBaseCollectionObject* self = (PyoaBaseCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaObject,oaUInt4)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaBaseCollection(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaUInt4,oaDomain)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        PyParamoaDomain p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2,
              &PyoaDomain_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaBaseCollection(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        PyParamoaDomain p3;
        PyParamoaCollTypeEnum p4;
        PyParamoaUInt4 p5;
        PyParamoaUInt4 p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaCollTypeEnum_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaUInt4_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaBaseCollection(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4,oaObject)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        PyParamoaDomain p3;
        PyParamoaCollTypeEnum p4;
        PyParamoaUInt4 p5;
        PyParamoaUInt4 p6;
        PyParamoaObject p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaCollTypeEnum_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaUInt4_Convert,&p6,
              &PyoaObject_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p7.Data(),7)) return NULL;
            self->value =  new oaBaseCollection(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value =  new oaBaseCollection(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBaseCollection, Choices are:\n"
        "    (oaObject,oaUInt4)\n"
        "    (oaObject,oaUInt4,oaDomain)\n"
        "    (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4)\n"
        "    (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4,oaObject)\n"
        "    (oaBaseCollection)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBaseCollection_tp_dealloc(PyoaBaseCollectionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBaseCollection_tp_repr(PyObject *ob)
{
    PyParamoaBaseCollection value;
    int convert_status=PyoaBaseCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaBaseCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBaseCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBaseCollection v1;
    PyParamoaBaseCollection v2;
    int convert_status1=PyoaBaseCollection_Convert(ob1,&v1);
    int convert_status2=PyoaBaseCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBaseCollection_Convert(PyObject* ob,PyParamoaBaseCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaBaseCollection_Check(ob)) {
        result->SetData(  ((PyoaBaseCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBaseCollection_FromoaBaseCollection(oaBaseCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBaseCollection_Type.tp_alloc(&PyoaBaseCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaBaseCollectionObject* self = (PyoaBaseCollectionObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseCollection_getCount_doc[] = 
"Class: oaBaseCollection, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of objects in the collection.\n"
;

static PyObject*
oaBaseCollection_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseCollection data;
    int convert_status=PyoaBaseCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseCollectionObject* self=(PyoaBaseCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getCount());
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseCollection_includes_doc[] = 
"Class: oaBaseCollection, Function: includes\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaBoolean includes(const oaObject* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaObject,\n"
"    This function returns a boolean value indicating whether the specified object is included in this collection.\n"
;

static PyObject*
oaBaseCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseCollection data;
    int convert_status=PyoaBaseCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseCollectionObject* self=(PyoaBaseCollectionObject*)ob;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (data.DataCall()->includes(p1.Data()));
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseCollection_isEmpty_doc[] = 
"Class: oaBaseCollection, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether this collection is empty.\n"
;

static PyObject*
oaBaseCollection_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseCollection data;
    int convert_status=PyoaBaseCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseCollectionObject* self=(PyoaBaseCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isEmpty());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBaseCollection_assign_doc[] = 
"Class: oaBaseCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBaseCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBaseCollection data;
  int convert_status=PyoaBaseCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBaseCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBaseCollection_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBaseCollection_methodlist[] = {
    {"getCount",(PyCFunction)oaBaseCollection_getCount,METH_VARARGS,oaBaseCollection_getCount_doc},
    {"includes",(PyCFunction)oaBaseCollection_includes,METH_VARARGS,oaBaseCollection_includes_doc},
    {"isEmpty",(PyCFunction)oaBaseCollection_isEmpty,METH_VARARGS,oaBaseCollection_isEmpty_doc},
    {"assign",(PyCFunction)oaBaseCollection_tp_assign,METH_VARARGS,oaBaseCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseCollection_doc[] = 
"Class: oaBaseCollection\n"
"  The oaBaseCollection class is the base class for the oaCollection classes. The class is not used directly by callers, but it contains functions inherited by the oaCollection classes.\n"
"Constructors:\n"
"  Paramegers: (oaObject,oaUInt4)\n"
"    Calls: oaBaseCollection(const oaObject* object,oaUInt4 dataTypeIn)\n"
"    Signature: oaBaseCollection||cptr-oaObject,simple-oaUInt4,\n"
"    Constructor oaBaseCollection\n"
"  Paramegers: (oaObject,oaUInt4,oaDomain)\n"
"    Calls: oaBaseCollection(const oaObject* object,oaUInt4 dataTypeIn,oaDomain domain)\n"
"    Signature: oaBaseCollection||cptr-oaObject,simple-oaUInt4,simple-oaDomain,\n"
"    Constructor oaBaseCollection\n"
"  Paramegers: (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4)\n"
"    Calls: oaBaseCollection(const oaObject* object,oaUInt4 assocDataType,oaDomain domain,oaCollTypeEnum typeIn,oaUInt4 flagsIn,oaUInt4 objFlagsIn)\n"
"    Signature: oaBaseCollection||cptr-oaObject,simple-oaUInt4,simple-oaDomain,simple-oaCollTypeEnum,simple-oaUInt4,simple-oaUInt4,cptr-oaObject,\n"
"    Constructor oaBaseCollection\n"
"  Paramegers: (oaObject,oaUInt4,oaDomain,oaCollTypeEnum,oaUInt4,oaUInt4,oaObject)\n"
"    Calls: oaBaseCollection(const oaObject* object,oaUInt4 assocDataType,oaDomain domain,oaCollTypeEnum typeIn,oaUInt4 flagsIn,oaUInt4 objFlagsIn,const oaObject* scopeObjIn)\n"
"    Signature: oaBaseCollection||cptr-oaObject,simple-oaUInt4,simple-oaDomain,simple-oaCollTypeEnum,simple-oaUInt4,simple-oaUInt4,cptr-oaObject,\n"
"    Constructor oaBaseCollection\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaBaseCollection(const oaBaseCollection& coll)\n"
"    Signature: oaBaseCollection||cref-oaBaseCollection,\n"
"    Constructor oaBaseCollection\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: (const oaBaseCollection&)\n"
"    Signature: oaBaseCollection||cref-oaBaseCollection,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBaseCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBaseCollection",
    sizeof(PyoaBaseCollectionObject),
    0,
    (destructor)oaBaseCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBaseCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaBaseCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBaseCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBaseCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBaseCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBaseCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBaseCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaBaseCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBaseCollection",
           (PyObject*)(&PyoaBaseCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBaseCollection\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBaseDataTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaBaseDataTypeEnum_Convert(PyObject* ob,PyParamoaBaseDataTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBaseDatabaseDataType")==0) { result->SetData(oacBaseDatabaseDataType); return 1;}
        if (strcasecmp(str,"oacBaseAppObjectDataType")==0) { result->SetData(oacBaseAppObjectDataType); return 1;}
        if (strcasecmp(str,"oacBasePropDataType")==0) { result->SetData(oacBasePropDataType); return 1;}
        if (strcasecmp(str,"oacBaseGroupDataType")==0) { result->SetData(oacBaseGroupDataType); return 1;}
        if (strcasecmp(str,"oacBaseGroupMemDataType")==0) { result->SetData(oacBaseGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacBaseAvatarDataType")==0) { result->SetData(oacBaseAvatarDataType); return 1;}
        if (strcasecmp(str,"oacBaseValueDataType")==0) { result->SetData(oacBaseValueDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintParamDefDataType")==0) { result->SetData(oacBaseConstraintParamDefDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintParamDataType")==0) { result->SetData(oacBaseConstraintParamDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintDefDataType")==0) { result->SetData(oacBaseConstraintDefDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintDataType")==0) { result->SetData(oacBaseConstraintDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintGroupDataType")==0) { result->SetData(oacBaseConstraintGroupDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintGroupMemDataType")==0) { result->SetData(oacBaseConstraintGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacBaseConstraintGroupHeaderDataType")==0) { result->SetData(oacBaseConstraintGroupHeaderDataType); return 1;}
        if (strcasecmp(str,"oacBaseFeatureDataType")==0) { result->SetData(oacBaseFeatureDataType); return 1;}
        if (strcasecmp(str,"oacBaseFeaturePolicyDataType")==0) { result->SetData(oacBaseFeaturePolicyDataType); return 1;}
        if (strcasecmp(str,"oacBaseDerivedLayerParamDefDataType")==0) { result->SetData(oacBaseDerivedLayerParamDefDataType); return 1;}
        if (strcasecmp(str,"oacBaseDerivedLayerDefDataType")==0) { result->SetData(oacBaseDerivedLayerDefDataType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaBaseDataTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseDataTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaBaseDataTypeEnum_FromoaBaseDataTypeEnum(oaBaseDataTypeEnum ob)
{
    if (ob==oacBaseDatabaseDataType) return PyString_FromString("oacBaseDatabaseDataType");
    if (ob==oacBaseAppObjectDataType) return PyString_FromString("oacBaseAppObjectDataType");
    if (ob==oacBasePropDataType) return PyString_FromString("oacBasePropDataType");
    if (ob==oacBaseGroupDataType) return PyString_FromString("oacBaseGroupDataType");
    if (ob==oacBaseGroupMemDataType) return PyString_FromString("oacBaseGroupMemDataType");
    if (ob==oacBaseAvatarDataType) return PyString_FromString("oacBaseAvatarDataType");
    if (ob==oacBaseValueDataType) return PyString_FromString("oacBaseValueDataType");
    if (ob==oacBaseConstraintParamDefDataType) return PyString_FromString("oacBaseConstraintParamDefDataType");
    if (ob==oacBaseConstraintParamDataType) return PyString_FromString("oacBaseConstraintParamDataType");
    if (ob==oacBaseConstraintDefDataType) return PyString_FromString("oacBaseConstraintDefDataType");
    if (ob==oacBaseConstraintDataType) return PyString_FromString("oacBaseConstraintDataType");
    if (ob==oacBaseConstraintGroupDataType) return PyString_FromString("oacBaseConstraintGroupDataType");
    if (ob==oacBaseConstraintGroupMemDataType) return PyString_FromString("oacBaseConstraintGroupMemDataType");
    if (ob==oacBaseConstraintGroupHeaderDataType) return PyString_FromString("oacBaseConstraintGroupHeaderDataType");
    if (ob==oacBaseFeatureDataType) return PyString_FromString("oacBaseFeatureDataType");
    if (ob==oacBaseFeaturePolicyDataType) return PyString_FromString("oacBaseFeaturePolicyDataType");
    if (ob==oacBaseDerivedLayerParamDefDataType) return PyString_FromString("oacBaseDerivedLayerParamDefDataType");
    if (ob==oacBaseDerivedLayerDefDataType) return PyString_FromString("oacBaseDerivedLayerDefDataType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaBaseDataTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaBaseDataTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaBaseDataTypeEnum_FromoaBaseDataTypeEnum(oaBaseDataTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaBaseDataTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaBaseDataTypeEnum_doc[] =
"Type convert function for enum: oaBaseDataTypeEnum";
                               
static PyMethodDef PyoaBaseDataTypeEnum_method =
  {"oaBaseDataTypeEnum",(PyCFunction)PyoaBaseDataTypeEnum_TypeFunction,METH_VARARGS,oaBaseDataTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaBaseDataTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBaseDatabaseDataType");
    PyDict_SetItemString(mod_dict,"oacBaseDatabaseDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseAppObjectDataType");
    PyDict_SetItemString(mod_dict,"oacBaseAppObjectDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBasePropDataType");
    PyDict_SetItemString(mod_dict,"oacBasePropDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseGroupDataType");
    PyDict_SetItemString(mod_dict,"oacBaseGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacBaseGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseAvatarDataType");
    PyDict_SetItemString(mod_dict,"oacBaseAvatarDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseValueDataType");
    PyDict_SetItemString(mod_dict,"oacBaseValueDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintParamDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintParamDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintDefDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintGroupDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseConstraintGroupHeaderDataType");
    PyDict_SetItemString(mod_dict,"oacBaseConstraintGroupHeaderDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseFeatureDataType");
    PyDict_SetItemString(mod_dict,"oacBaseFeatureDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseFeaturePolicyDataType");
    PyDict_SetItemString(mod_dict,"oacBaseFeaturePolicyDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseDerivedLayerParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacBaseDerivedLayerParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseDerivedLayerDefDataType");
    PyDict_SetItemString(mod_dict,"oacBaseDerivedLayerDefDataType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaBaseDataTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaBaseDataTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaBaseDataTypeEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaBaseIter
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBaseIter_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBaseIter_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBaseIterObject* self = (PyoaBaseIterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value =  new oaBaseIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBaseIter)
    {
        PyParamoaBaseIter p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseIter_Convert,&p1)) {
            self->value =  new oaBaseIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBaseIter, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaBaseIter)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBaseIter_tp_dealloc(PyoaBaseIterObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBaseIter_tp_repr(PyObject *ob)
{
    PyParamoaBaseIter value;
    int convert_status=PyoaBaseIter_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaBaseIter::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBaseIter_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBaseIter v1;
    PyParamoaBaseIter v2;
    int convert_status1=PyoaBaseIter_Convert(ob1,&v1);
    int convert_status2=PyoaBaseIter_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBaseIter_Convert(PyObject* ob,PyParamoaBaseIter* result)
{
    if (ob == NULL) return 1;
    if (PyoaBaseIter_Check(ob)) {
        result->SetData(  ((PyoaBaseIterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseIter Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBaseIter_FromoaBaseIter(oaBaseIter* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBaseIter_Type.tp_alloc(&PyoaBaseIter_Type,0);
        if (bself == NULL) return bself;
        PyoaBaseIterObject* self = (PyoaBaseIterObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseIter_getNext_doc[] = 
"Class: oaBaseIter, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getNext()\n"
"    Signature: getNext|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaBaseIter_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseIter data;
    int convert_status=PyoaBaseIter_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseIterObject* self=(PyoaBaseIterObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaObjectp result= (data.DataCall()->getNext());
        return PyoaObject_FromoaObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseIter_reset_doc[] = 
"Class: oaBaseIter, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    This function resets the iterator to the start of the associated collection.\n"
;

static PyObject*
oaBaseIter_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseIter data;
    int convert_status=PyoaBaseIter_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseIterObject* self=(PyoaBaseIterObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->reset();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBaseIter_assign_doc[] = 
"Class: oaBaseIter, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBaseIter_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBaseIter data;
  int convert_status=PyoaBaseIter_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBaseIter p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBaseIter_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBaseIter_methodlist[] = {
    {"getNext",(PyCFunction)oaBaseIter_getNext,METH_VARARGS,oaBaseIter_getNext_doc},
    {"reset",(PyCFunction)oaBaseIter_reset,METH_VARARGS,oaBaseIter_reset_doc},
    {"assign",(PyCFunction)oaBaseIter_tp_assign,METH_VARARGS,oaBaseIter_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseIter_doc[] = 
"Class: oaBaseIter\n"
"  The oaBaseIter class is an abstract base class for the oaIter Template class. The oaBaseIter class is not used directly by callers, but the class has functions that are inherited by the oaIter class.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaBaseIter(const oaBaseCollection& coll)\n"
"    Signature: oaBaseIter||cref-oaBaseCollection,\n"
"    Constructor oaBaseIter\n"
"  Paramegers: (oaBaseIter)\n"
"    Calls: oaBaseIter(const oaBaseIter& iter)\n"
"    Signature: oaBaseIter||cref-oaBaseIter,\n"
"    Constructor oaBaseIter\n"
"  Paramegers: (oaBaseIter)\n"
"    Calls: (const oaBaseIter&)\n"
"    Signature: oaBaseIter||cref-oaBaseIter,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBaseIter_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBaseIter",
    sizeof(PyoaBaseIterObject),
    0,
    (destructor)oaBaseIter_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBaseIter_tp_compare,	/* tp_compare */
    (reprfunc)oaBaseIter_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBaseIter_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBaseIter_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBaseIter_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBaseIter_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBaseIter_Type)<0) {
      printf("** PyType_Ready failed for: oaBaseIter\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBaseIter",
           (PyObject*)(&PyoaBaseIter_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBaseIter\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBaseMemNetCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBaseMemNetCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBaseMemNetCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBaseMemNetCollectionObject* self = (PyoaBaseMemNetCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBaseMemNetCollection, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBaseMemNetCollection_tp_dealloc(PyoaBaseMemNetCollectionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBaseMemNetCollection_tp_repr(PyObject *ob)
{
    PyParamoaBaseMemNetCollection value;
    int convert_status=PyoaBaseMemNetCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaBaseMemNetCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBaseMemNetCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBaseMemNetCollection v1;
    PyParamoaBaseMemNetCollection v2;
    int convert_status1=PyoaBaseMemNetCollection_Convert(ob1,&v1);
    int convert_status2=PyoaBaseMemNetCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBaseMemNetCollection_Convert(PyObject* ob,PyParamoaBaseMemNetCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaBaseMemNetCollection_Check(ob)) {
        result->SetData(  ((PyoaBaseMemNetCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseMemNetCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBaseMemNetCollection_FromoaBaseMemNetCollection(oaBaseMemNetCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBaseMemNetCollection_Type.tp_alloc(&PyoaBaseMemNetCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaBaseMemNetCollectionObject* self = (PyoaBaseMemNetCollectionObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseMemNetCollection_getCount_doc[] = 
"Class: oaBaseMemNetCollection, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount()\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of objects in the collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database checks all the members of the collection.\n"
;

static PyObject*
oaBaseMemNetCollection_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseMemNetCollection data;
    int convert_status=PyoaBaseMemNetCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseMemNetCollectionObject* self=(PyoaBaseMemNetCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getCount());
        return PyoaUInt4_FromoaUInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseMemNetCollection_includes_doc[] = 
"Class: oaBaseMemNetCollection, Function: includes\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaBoolean includes(const oaObject* objectIn)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaObject,\n"
"    Function includes\n"
;

static PyObject*
oaBaseMemNetCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseMemNetCollection data;
    int convert_status=PyoaBaseMemNetCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseMemNetCollectionObject* self=(PyoaBaseMemNetCollectionObject*)ob;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (data.DataCall()->includes(p1.Data()));
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseMemNetCollection_isEmpty_doc[] = 
"Class: oaBaseMemNetCollection, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty()\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function determines if there are any members in the collection.\n"
;

static PyObject*
oaBaseMemNetCollection_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseMemNetCollection data;
    int convert_status=PyoaBaseMemNetCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseMemNetCollectionObject* self=(PyoaBaseMemNetCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isEmpty());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBaseMemNetCollection_assign_doc[] = 
"Class: oaBaseMemNetCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBaseMemNetCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBaseMemNetCollection data;
  int convert_status=PyoaBaseMemNetCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBaseMemNetCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBaseMemNetCollection_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBaseMemNetCollection_methodlist[] = {
    {"getCount",(PyCFunction)oaBaseMemNetCollection_getCount,METH_VARARGS,oaBaseMemNetCollection_getCount_doc},
    {"includes",(PyCFunction)oaBaseMemNetCollection_includes,METH_VARARGS,oaBaseMemNetCollection_includes_doc},
    {"isEmpty",(PyCFunction)oaBaseMemNetCollection_isEmpty,METH_VARARGS,oaBaseMemNetCollection_isEmpty_doc},
    {"assign",(PyCFunction)oaBaseMemNetCollection_tp_assign,METH_VARARGS,oaBaseMemNetCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseMemNetCollection_doc[] = 
"Class: oaBaseMemNetCollection\n"
"  This is the abstract base class of the derived member net collection classes. Member nets can be used to trace the connectivity implied by the use of multi-bit nets and connections.\n"
"  The member net collection classes represent collections of nets that the starting net is a member of.\n"
"  See the derived classes for more details.\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBaseMemNetCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBaseMemNetCollection",
    sizeof(PyoaBaseMemNetCollectionObject),
    0,
    (destructor)oaBaseMemNetCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBaseMemNetCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaBaseMemNetCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBaseMemNetCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBaseMemNetCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBaseMemNetCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBaseMemNetCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBaseMemNetCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaBaseMemNetCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBaseMemNetCollection",
           (PyObject*)(&PyoaBaseMemNetCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBaseMemNetCollection\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBaseMemNetIter
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBaseMemNetIter_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBaseMemNetIter_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBaseMemNetIterObject* self = (PyoaBaseMemNetIterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseMemNetCollection)
    {
        PyParamoaBaseMemNetCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseMemNetCollection_Convert,&p1)) {
            self->value =  new oaBaseMemNetIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBaseMemNetIter)
    {
        PyParamoaBaseMemNetIter p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseMemNetIter_Convert,&p1)) {
            self->value =  new oaBaseMemNetIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBaseMemNetIter, Choices are:\n"
        "    (oaBaseMemNetCollection)\n"
        "    (oaBaseMemNetIter)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBaseMemNetIter_tp_dealloc(PyoaBaseMemNetIterObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBaseMemNetIter_tp_repr(PyObject *ob)
{
    PyParamoaBaseMemNetIter value;
    int convert_status=PyoaBaseMemNetIter_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaBaseMemNetIter::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBaseMemNetIter_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBaseMemNetIter v1;
    PyParamoaBaseMemNetIter v2;
    int convert_status1=PyoaBaseMemNetIter_Convert(ob1,&v1);
    int convert_status2=PyoaBaseMemNetIter_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBaseMemNetIter_Convert(PyObject* ob,PyParamoaBaseMemNetIter* result)
{
    if (ob == NULL) return 1;
    if (PyoaBaseMemNetIter_Check(ob)) {
        result->SetData(  ((PyoaBaseMemNetIterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseMemNetIter Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBaseMemNetIter_FromoaBaseMemNetIter(oaBaseMemNetIter* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBaseMemNetIter_Type.tp_alloc(&PyoaBaseMemNetIter_Type,0);
        if (bself == NULL) return bself;
        PyoaBaseMemNetIterObject* self = (PyoaBaseMemNetIterObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseMemNetIter_getNext_doc[] = 
"Class: oaBaseMemNetIter, Function: getNext\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObject* getNext(oaUInt4& arg)\n"
"    Signature: getNext|ptr-oaObject|ref-oaUInt4,\n"
"    BrowseData: 1,oaUInt4\n"
"    Function getNext\n"
;

static PyObject*
oaBaseMemNetIter_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseMemNetIter data;
    int convert_status=PyoaBaseMemNetIter_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseMemNetIterObject* self=(PyoaBaseMemNetIterObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaObjectp result= (data.DataCall()->getNext(p1.Data()));
        return PyoaObject_FromoaObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseMemNetIter_reset_doc[] = 
"Class: oaBaseMemNetIter, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    This function restarts the iterator. The next call to getNext() for this oaBaseMemNetIter returns the first object in the collection.\n"
;

static PyObject*
oaBaseMemNetIter_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseMemNetIter data;
    int convert_status=PyoaBaseMemNetIter_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseMemNetIterObject* self=(PyoaBaseMemNetIterObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->reset();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBaseMemNetIter_assign_doc[] = 
"Class: oaBaseMemNetIter, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBaseMemNetIter_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBaseMemNetIter data;
  int convert_status=PyoaBaseMemNetIter_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBaseMemNetIter p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBaseMemNetIter_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBaseMemNetIter_methodlist[] = {
    {"getNext",(PyCFunction)oaBaseMemNetIter_getNext,METH_VARARGS,oaBaseMemNetIter_getNext_doc},
    {"reset",(PyCFunction)oaBaseMemNetIter_reset,METH_VARARGS,oaBaseMemNetIter_reset_doc},
    {"assign",(PyCFunction)oaBaseMemNetIter_tp_assign,METH_VARARGS,oaBaseMemNetIter_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseMemNetIter_doc[] = 
"Class: oaBaseMemNetIter\n"
"  The oaBaseMemNetIter class is the abstract base class for the derived member net iterator classes. The member net iterator classes return member nets of a member net collection ( oaBaseMemNetCollection ). A collection of member nets is all those nets of whom the current net is a member. Because all nets are members of themselves, this iterator will always return at least one net.\n"
"  For example, a collection of member nets for net a would contain all of the following nets:\n"
"  a\n"
"  x,y,a\n"
"  a*4\n"
"  The member net index is returned in the getNext() function. This index indicates the member position of the specified net in the collection. For the example above, the iterator would return the following values:\n"
"  a 0\n"
"  x,y,a 2\n"
"  a*4 0\n"
"  a*4 1\n"
"  a*4 2\n"
"  a*4 3\n"
"  This particular collection and iterator are primarily for those applications that want to traverse single-bit connectivity.\n"
"Constructors:\n"
"  Paramegers: (oaBaseMemNetCollection)\n"
"    Calls: oaBaseMemNetIter(const oaBaseMemNetCollection& cl)\n"
"    Signature: oaBaseMemNetIter||cref-oaBaseMemNetCollection,\n"
"    Constructor oaBaseMemNetIter\n"
"  Paramegers: (oaBaseMemNetIter)\n"
"    Calls: oaBaseMemNetIter(const oaBaseMemNetIter& iterIn)\n"
"    Signature: oaBaseMemNetIter||cref-oaBaseMemNetIter,\n"
"    Constructor oaBaseMemNetIter\n"
"  Paramegers: (oaBaseMemNetIter)\n"
"    Calls: (const oaBaseMemNetIter&)\n"
"    Signature: oaBaseMemNetIter||cref-oaBaseMemNetIter,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBaseMemNetIter_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBaseMemNetIter",
    sizeof(PyoaBaseMemNetIterObject),
    0,
    (destructor)oaBaseMemNetIter_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBaseMemNetIter_tp_compare,	/* tp_compare */
    (reprfunc)oaBaseMemNetIter_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBaseMemNetIter_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBaseMemNetIter_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBaseMemNetIter_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBaseMemNetIter_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBaseMemNetIter_Type)<0) {
      printf("** PyType_Ready failed for: oaBaseMemNetIter\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBaseMemNetIter",
           (PyObject*)(&PyoaBaseMemNetIter_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBaseMemNetIter\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBaseMsgIds
// ==================================================================

// ------------------------------------------------------------------

int
PyoaBaseMsgIds_Convert(PyObject* ob,PyParamoaBaseMsgIds* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacOSError")==0) { result->SetData(oacOSError); return 1;}
        if (strcasecmp(str,"oacInvalidAPIRev")==0) { result->SetData(oacInvalidAPIRev); return 1;}
        if (strcasecmp(str,"oacInvalidFileAccessMode")==0) { result->SetData(oacInvalidFileAccessMode); return 1;}
        if (strcasecmp(str,"oacFileNotWritable")==0) { result->SetData(oacFileNotWritable); return 1;}
        if (strcasecmp(str,"oacUnableToRemove")==0) { result->SetData(oacUnableToRemove); return 1;}
        if (strcasecmp(str,"oacUnableToRename")==0) { result->SetData(oacUnableToRename); return 1;}
        if (strcasecmp(str,"oacInvalidFileSize")==0) { result->SetData(oacInvalidFileSize); return 1;}
        if (strcasecmp(str,"oacInvalidMapFileWindow")==0) { result->SetData(oacInvalidMapFileWindow); return 1;}
        if (strcasecmp(str,"oacInvalidSetMapWindowFile")==0) { result->SetData(oacInvalidSetMapWindowFile); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseFile")==0) { result->SetData(oacInvalidDatabaseFile); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseIndex")==0) { result->SetData(oacInvalidDatabaseIndex); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseSize")==0) { result->SetData(oacInvalidDatabaseSize); return 1;}
        if (strcasecmp(str,"oacDeletedDatabase")==0) { result->SetData(oacDeletedDatabase); return 1;}
        if (strcasecmp(str,"oacMismatchDatabaseID")==0) { result->SetData(oacMismatchDatabaseID); return 1;}
        if (strcasecmp(str,"oacCannotUpgrade")==0) { result->SetData(oacCannotUpgrade); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseAccessMode")==0) { result->SetData(oacInvalidDatabaseAccessMode); return 1;}
        if (strcasecmp(str,"oacInvalidProp")==0) { result->SetData(oacInvalidProp); return 1;}
        if (strcasecmp(str,"oacPropNameUsed")==0) { result->SetData(oacPropNameUsed); return 1;}
        if (strcasecmp(str,"oacInvalidObjForProp")==0) { result->SetData(oacInvalidObjForProp); return 1;}
        if (strcasecmp(str,"oacInvalidGroupTypeName")==0) { result->SetData(oacInvalidGroupTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidGroupDeleteWhenTypeName")==0) { result->SetData(oacInvalidGroupDeleteWhenTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidGroup")==0) { result->SetData(oacInvalidGroup); return 1;}
        if (strcasecmp(str,"oacInvalidObjForGroup")==0) { result->SetData(oacInvalidObjForGroup); return 1;}
        if (strcasecmp(str,"oacInvalidGroupObject")==0) { result->SetData(oacInvalidGroupObject); return 1;}
        if (strcasecmp(str,"oacGroupMemberNotInSameDB")==0) { result->SetData(oacGroupMemberNotInSameDB); return 1;}
        if (strcasecmp(str,"oacGroupMemberNotInDomain")==0) { result->SetData(oacGroupMemberNotInDomain); return 1;}
        if (strcasecmp(str,"oacInvalidUniqueGroupName")==0) { result->SetData(oacInvalidUniqueGroupName); return 1;}
        if (strcasecmp(str,"oacInvalidGroupForSameObj")==0) { result->SetData(oacInvalidGroupForSameObj); return 1;}
        if (strcasecmp(str,"oacInvalidGroupForLeader")==0) { result->SetData(oacInvalidGroupForLeader); return 1;}
        if (strcasecmp(str,"oacMultipleGroupLeader")==0) { result->SetData(oacMultipleGroupLeader); return 1;}
        if (strcasecmp(str,"oacInvalidGroupLeader")==0) { result->SetData(oacInvalidGroupLeader); return 1;}
        if (strcasecmp(str,"oacInvalidGroupMem")==0) { result->SetData(oacInvalidGroupMem); return 1;}
        if (strcasecmp(str,"oacInvalidGroupForMemberMove")==0) { result->SetData(oacInvalidGroupForMemberMove); return 1;}
        if (strcasecmp(str,"oacInvalidGroupTypeForMemberMove")==0) { result->SetData(oacInvalidGroupTypeForMemberMove); return 1;}
        if (strcasecmp(str,"oacInvalidMoveLeader")==0) { result->SetData(oacInvalidMoveLeader); return 1;}
        if (strcasecmp(str,"oacUnableToOpenDir")==0) { result->SetData(oacUnableToOpenDir); return 1;}
        if (strcasecmp(str,"oacInvalidValueForIntRange")==0) { result->SetData(oacInvalidValueForIntRange); return 1;}
        if (strcasecmp(str,"oacInvalidValueForFloatRange")==0) { result->SetData(oacInvalidValueForFloatRange); return 1;}
        if (strcasecmp(str,"oacInvalidEnumValue")==0) { result->SetData(oacInvalidEnumValue); return 1;}
        if (strcasecmp(str,"oacInvalidName")==0) { result->SetData(oacInvalidName); return 1;}
        if (strcasecmp(str,"oacInvalidNameTypeName")==0) { result->SetData(oacInvalidNameTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidNameLength")==0) { result->SetData(oacInvalidNameLength); return 1;}
        if (strcasecmp(str,"oacInvalidNameSyntax")==0) { result->SetData(oacInvalidNameSyntax); return 1;}
        if (strcasecmp(str,"oacInvalidNameChar")==0) { result->SetData(oacInvalidNameChar); return 1;}
        if (strcasecmp(str,"oacStepNameInvalid")==0) { result->SetData(oacStepNameInvalid); return 1;}
        if (strcasecmp(str,"oacIndexedNameInvalid")==0) { result->SetData(oacIndexedNameInvalid); return 1;}
        if (strcasecmp(str,"oacVectorNameInvalid")==0) { result->SetData(oacVectorNameInvalid); return 1;}
        if (strcasecmp(str,"oacHierNameInvalid")==0) { result->SetData(oacHierNameInvalid); return 1;}
        if (strcasecmp(str,"oacInvalidNameIndex")==0) { result->SetData(oacInvalidNameIndex); return 1;}
        if (strcasecmp(str,"oacInvalidVectorValue")==0) { result->SetData(oacInvalidVectorValue); return 1;}
        if (strcasecmp(str,"oacBundleNameInvalid")==0) { result->SetData(oacBundleNameInvalid); return 1;}
        if (strcasecmp(str,"oacProgrammableCharTaken")==0) { result->SetData(oacProgrammableCharTaken); return 1;}
        if (strcasecmp(str,"oacProgrammableCharInvalid")==0) { result->SetData(oacProgrammableCharInvalid); return 1;}
        if (strcasecmp(str,"oacNameNotIndexed")==0) { result->SetData(oacNameNotIndexed); return 1;}
        if (strcasecmp(str,"oacBitNotInRangeForName")==0) { result->SetData(oacBitNotInRangeForName); return 1;}
        if (strcasecmp(str,"oacInvalidDesignObjectForAppDef")==0) { result->SetData(oacInvalidDesignObjectForAppDef); return 1;}
        if (strcasecmp(str,"oacInvalidDesignObjectForInterAppDef")==0) { result->SetData(oacInvalidDesignObjectForInterAppDef); return 1;}
        if (strcasecmp(str,"oacInvalidDesignObjectForIntraAppDef")==0) { result->SetData(oacInvalidDesignObjectForIntraAppDef); return 1;}
        if (strcasecmp(str,"oacInvalidAppDef")==0) { result->SetData(oacInvalidAppDef); return 1;}
        if (strcasecmp(str,"oacAppDefExists")==0) { result->SetData(oacAppDefExists); return 1;}
        if (strcasecmp(str,"oacInvalidAppObjectDef")==0) { result->SetData(oacInvalidAppObjectDef); return 1;}
        if (strcasecmp(str,"oacDeletedAppObject")==0) { result->SetData(oacDeletedAppObject); return 1;}
        if (strcasecmp(str,"oacInvalidAppObject")==0) { result->SetData(oacInvalidAppObject); return 1;}
        if (strcasecmp(str,"oacDeleteLockedTree")==0) { result->SetData(oacDeleteLockedTree); return 1;}
        if (strcasecmp(str,"oacMemGetFailed")==0) { result->SetData(oacMemGetFailed); return 1;}
        if (strcasecmp(str,"oacMemResizeFailed")==0) { result->SetData(oacMemResizeFailed); return 1;}
        if (strcasecmp(str,"oacNoObjectDB")==0) { result->SetData(oacNoObjectDB); return 1;}
        if (strcasecmp(str,"oacInvalidObjectTypeName")==0) { result->SetData(oacInvalidObjectTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidOrientName")==0) { result->SetData(oacInvalidOrientName); return 1;}
        if (strcasecmp(str,"oacInvalidInterpolateTypeName")==0) { result->SetData(oacInvalidInterpolateTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidExtrapolateTypeName")==0) { result->SetData(oacInvalidExtrapolateTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidDomainName")==0) { result->SetData(oacInvalidDomainName); return 1;}
        if (strcasecmp(str,"oacInvalidParamTypeName")==0) { result->SetData(oacInvalidParamTypeName); return 1;}
        if (strcasecmp(str,"oacNotASession")==0) { result->SetData(oacNotASession); return 1;}
        if (strcasecmp(str,"oacInvalidSession")==0) { result->SetData(oacInvalidSession); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintParamTypeName")==0) { result->SetData(oacInvalidConstraintParamTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidSimpleConstraintTypeName")==0) { result->SetData(oacInvalidSimpleConstraintTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidLayerConstraintTypeName")==0) { result->SetData(oacInvalidLayerConstraintTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidLayerPairConstraintTypeName")==0) { result->SetData(oacInvalidLayerPairConstraintTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidDBTypeName")==0) { result->SetData(oacInvalidDBTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintParamDef")==0) { result->SetData(oacInvalidConstraintParamDef); return 1;}
        if (strcasecmp(str,"oacConstraintParamDefExists")==0) { result->SetData(oacConstraintParamDefExists); return 1;}
        if (strcasecmp(str,"oacConstraintParamDefHasReference")==0) { result->SetData(oacConstraintParamDefHasReference); return 1;}
        if (strcasecmp(str,"oacUnableToDestroyBuiltInType")==0) { result->SetData(oacUnableToDestroyBuiltInType); return 1;}
        if (strcasecmp(str,"oacValueInvalidForConstraintParamDef")==0) { result->SetData(oacValueInvalidForConstraintParamDef); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintParam")==0) { result->SetData(oacInvalidConstraintParam); return 1;}
        if (strcasecmp(str,"oacConstraintParamAlreadyOwned")==0) { result->SetData(oacConstraintParamAlreadyOwned); return 1;}
        if (strcasecmp(str,"oacCantDestroyOwnedConstraintParam")==0) { result->SetData(oacCantDestroyOwnedConstraintParam); return 1;}
        if (strcasecmp(str,"oacInvalidObjForConstraintParam")==0) { result->SetData(oacInvalidObjForConstraintParam); return 1;}
        if (strcasecmp(str,"oacConstraintParamNotInSameDB")==0) { result->SetData(oacConstraintParamNotInSameDB); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintDef")==0) { result->SetData(oacInvalidConstraintDef); return 1;}
        if (strcasecmp(str,"oacConstraintDefExists")==0) { result->SetData(oacConstraintDefExists); return 1;}
        if (strcasecmp(str,"oacConstraintDefHasReference")==0) { result->SetData(oacConstraintDefHasReference); return 1;}
        if (strcasecmp(str,"oacInvalidValueForConstraintDef")==0) { result->SetData(oacInvalidValueForConstraintDef); return 1;}
        if (strcasecmp(str,"oacInvalidDBForConstraintDef")==0) { result->SetData(oacInvalidDBForConstraintDef); return 1;}
        if (strcasecmp(str,"oacInvalidObjForConstraintDef")==0) { result->SetData(oacInvalidObjForConstraintDef); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintType")==0) { result->SetData(oacInvalidConstraintType); return 1;}
        if (strcasecmp(str,"oacConstraintNameExists")==0) { result->SetData(oacConstraintNameExists); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseForLayerConstraint")==0) { result->SetData(oacInvalidDatabaseForLayerConstraint); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseForLayerPairConstraint")==0) { result->SetData(oacInvalidDatabaseForLayerPairConstraint); return 1;}
        if (strcasecmp(str,"oacValueAlreadyOwned")==0) { result->SetData(oacValueAlreadyOwned); return 1;}
        if (strcasecmp(str,"oacCantDestroyOwnedValue")==0) { result->SetData(oacCantDestroyOwnedValue); return 1;}
        if (strcasecmp(str,"oacInvalidValueType")==0) { result->SetData(oacInvalidValueType); return 1;}
        if (strcasecmp(str,"oacInvalidObjForValue")==0) { result->SetData(oacInvalidObjForValue); return 1;}
        if (strcasecmp(str,"oacIllDefinedTblSpecified")==0) { result->SetData(oacIllDefinedTblSpecified); return 1;}
        if (strcasecmp(str,"oacValueNotInSameDatabase")==0) { result->SetData(oacValueNotInSameDatabase); return 1;}
        if (strcasecmp(str,"oacInvalidValueForCopy")==0) { result->SetData(oacInvalidValueForCopy); return 1;}
        if (strcasecmp(str,"oacEmptyArrayValue")==0) { result->SetData(oacEmptyArrayValue); return 1;}
        if (strcasecmp(str,"oacInvalidValueArrayValue")==0) { result->SetData(oacInvalidValueArrayValue); return 1;}
        if (strcasecmp(str,"oacInvalidDefaultValueForTblValue")==0) { result->SetData(oacInvalidDefaultValueForTblValue); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintGroup")==0) { result->SetData(oacInvalidConstraintGroup); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintGroupMem")==0) { result->SetData(oacInvalidConstraintGroupMem); return 1;}
        if (strcasecmp(str,"oacInvalidObjForConstraintGroup")==0) { result->SetData(oacInvalidObjForConstraintGroup); return 1;}
        if (strcasecmp(str,"oacConstraintGroupNameExists")==0) { result->SetData(oacConstraintGroupNameExists); return 1;}
        if (strcasecmp(str,"oacConstraintGroupAlreadyHasObj")==0) { result->SetData(oacConstraintGroupAlreadyHasObj); return 1;}
        if (strcasecmp(str,"oacConstraintGroupMemberNotInValidDB")==0) { result->SetData(oacConstraintGroupMemberNotInValidDB); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintGroupForMemberMove")==0) { result->SetData(oacInvalidConstraintGroupForMemberMove); return 1;}
        if (strcasecmp(str,"oacInvalidConstraintGroupHeader")==0) { result->SetData(oacInvalidConstraintGroupHeader); return 1;}
        if (strcasecmp(str,"oacInvalidObjForConstraintGroupHeader")==0) { result->SetData(oacInvalidObjForConstraintGroupHeader); return 1;}
        if (strcasecmp(str,"oacCannotDeleteObject")==0) { result->SetData(oacCannotDeleteObject); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseForObject")==0) { result->SetData(oacInvalidDatabaseForObject); return 1;}
        if (strcasecmp(str,"oacInvalidBusSyntax")==0) { result->SetData(oacInvalidBusSyntax); return 1;}
        if (strcasecmp(str,"oacInvalidBitValue")==0) { result->SetData(oacInvalidBitValue); return 1;}
        if (strcasecmp(str,"oacInvalidParenSyntax")==0) { result->SetData(oacInvalidParenSyntax); return 1;}
        if (strcasecmp(str,"oacFirstCharInvalid")==0) { result->SetData(oacFirstCharInvalid); return 1;}
        if (strcasecmp(str,"oacInvalidCharFollowingEscChar")==0) { result->SetData(oacInvalidCharFollowingEscChar); return 1;}
        if (strcasecmp(str,"oacInvalidNameKeywordConflict")==0) { result->SetData(oacInvalidNameKeywordConflict); return 1;}
        if (strcasecmp(str,"oacInvalidNumberSyntax")==0) { result->SetData(oacInvalidNumberSyntax); return 1;}
        if (strcasecmp(str,"oacInvalidCharFollowingHexChar")==0) { result->SetData(oacInvalidCharFollowingHexChar); return 1;}
        if (strcasecmp(str,"oacNotYetSupported")==0) { result->SetData(oacNotYetSupported); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseForValue")==0) { result->SetData(oacInvalidDatabaseForValue); return 1;}
        if (strcasecmp(str,"oacCorruptedDatabase")==0) { result->SetData(oacCorruptedDatabase); return 1;}
        if (strcasecmp(str,"oacInternalError")==0) { result->SetData(oacInternalError); return 1;}
        if (strcasecmp(str,"oacCannotBeCalled")==0) { result->SetData(oacCannotBeCalled); return 1;}
        if (strcasecmp(str,"oacSocketGeneralError")==0) { result->SetData(oacSocketGeneralError); return 1;}
        if (strcasecmp(str,"oacCannotResetMutex")==0) { result->SetData(oacCannotResetMutex); return 1;}
        if (strcasecmp(str,"oacCannotCreateMutex")==0) { result->SetData(oacCannotCreateMutex); return 1;}
        if (strcasecmp(str,"oacInvalidDatabase")==0) { result->SetData(oacInvalidDatabase); return 1;}
        if (strcasecmp(str,"oacInvalidMajorAPIRev")==0) { result->SetData(oacInvalidMajorAPIRev); return 1;}
        if (strcasecmp(str,"oacInvalidCategoryName")==0) { result->SetData(oacInvalidCategoryName); return 1;}
        if (strcasecmp(str,"oacInvalidDataModelModTypeName")==0) { result->SetData(oacInvalidDataModelModTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidFeature")==0) { result->SetData(oacInvalidFeature); return 1;}
        if (strcasecmp(str,"oacCannotDowngradeDatabase")==0) { result->SetData(oacCannotDowngradeDatabase); return 1;}
        if (strcasecmp(str,"oacDataNotCompatibleOnOpen")==0) { result->SetData(oacDataNotCompatibleOnOpen); return 1;}
        if (strcasecmp(str,"oacDataNotCompatibleOnOpenInAppendMode")==0) { result->SetData(oacDataNotCompatibleOnOpenInAppendMode); return 1;}
        if (strcasecmp(str,"oacDataNotCompatibleOnOpenInEditableMode")==0) { result->SetData(oacDataNotCompatibleOnOpenInEditableMode); return 1;}
        if (strcasecmp(str,"oacDataNotCompatibleOnSave")==0) { result->SetData(oacDataNotCompatibleOnSave); return 1;}
        if (strcasecmp(str,"oacInvalidDataModelRev")==0) { result->SetData(oacInvalidDataModelRev); return 1;}
        if (strcasecmp(str,"oacInconsistentDataModelRev")==0) { result->SetData(oacInconsistentDataModelRev); return 1;}
        if (strcasecmp(str,"oacCannotOpenHugeDatabase")==0) { result->SetData(oacCannotOpenHugeDatabase); return 1;}
        if (strcasecmp(str,"oacInvalidRangeTypeName")==0) { result->SetData(oacInvalidRangeTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidBoundsForRange")==0) { result->SetData(oacInvalidBoundsForRange); return 1;}
        if (strcasecmp(str,"oacInvalidTypeForRange")==0) { result->SetData(oacInvalidTypeForRange); return 1;}
        if (strcasecmp(str,"oacInvalidBoundForRange")==0) { result->SetData(oacInvalidBoundForRange); return 1;}
        if (strcasecmp(str,"oacInvalidLayerArrayConstraintTypeName")==0) { result->SetData(oacInvalidLayerArrayConstraintTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidDistanceMeasureTypeName")==0) { result->SetData(oacInvalidDistanceMeasureTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidWidthLengthTableTypeName")==0) { result->SetData(oacInvalidWidthLengthTableTypeName); return 1;}
        if (strcasecmp(str,"oacCannotMoveImplicitConstraintGroupMem")==0) { result->SetData(oacCannotMoveImplicitConstraintGroupMem); return 1;}
        if (strcasecmp(str,"oacCannotDestroyImplicitConstraintGroupMem")==0) { result->SetData(oacCannotDestroyImplicitConstraintGroupMem); return 1;}
        if (strcasecmp(str,"oacInvalidDatabaseForLayerArrayConstraint")==0) { result->SetData(oacInvalidDatabaseForLayerArrayConstraint); return 1;}
        if (strcasecmp(str,"oacInvalidAlignmentTypeName")==0) { result->SetData(oacInvalidAlignmentTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidInterpolateTypeForTable")==0) { result->SetData(oacInvalidInterpolateTypeForTable); return 1;}
        if (strcasecmp(str,"oacInvalidExtrapolateTypeForTable")==0) { result->SetData(oacInvalidExtrapolateTypeForTable); return 1;}
        if (strcasecmp(str,"oacInvalidLayerArrayForLayerArrayConstraint")==0) { result->SetData(oacInvalidLayerArrayForLayerArrayConstraint); return 1;}
        if (strcasecmp(str,"oacCannotCreateValueInDesignDBWithNoBlocks")==0) { result->SetData(oacCannotCreateValueInDesignDBWithNoBlocks); return 1;}
        if (strcasecmp(str,"oacCannotDestroyConstraintGroupContainingImplicitMem")==0) { result->SetData(oacCannotDestroyConstraintGroupContainingImplicitMem); return 1;}
        if (strcasecmp(str,"oacCannotUpgradeOverwrittenDatabase")==0) { result->SetData(oacCannotUpgradeOverwrittenDatabase); return 1;}
        if (strcasecmp(str,"oacInvalidSessionObject")==0) { result->SetData(oacInvalidSessionObject); return 1;}
        if (strcasecmp(str,"oacInvalidObject")==0) { result->SetData(oacInvalidObject); return 1;}
        if (strcasecmp(str,"oacCannotSaveDataModelRev")==0) { result->SetData(oacCannotSaveDataModelRev); return 1;}
        if (strcasecmp(str,"oacCannotRepairCorruptedAppData")==0) { result->SetData(oacCannotRepairCorruptedAppData); return 1;}
        if (strcasecmp(str,"oacCannotKillProcess")==0) { result->SetData(oacCannotKillProcess); return 1;}
        if (strcasecmp(str,"oacCannotCreateProcess")==0) { result->SetData(oacCannotCreateProcess); return 1;}
        if (strcasecmp(str,"oacChildProcessError")==0) { result->SetData(oacChildProcessError); return 1;}
        if (strcasecmp(str,"oacCreateFileMappingFailed")==0) { result->SetData(oacCreateFileMappingFailed); return 1;}
        if (strcasecmp(str,"oacResetFileMappingFailed")==0) { result->SetData(oacResetFileMappingFailed); return 1;}
        if (strcasecmp(str,"oacFileMappingFailed")==0) { result->SetData(oacFileMappingFailed); return 1;}
        if (strcasecmp(str,"oacMemMapCloseFailed")==0) { result->SetData(oacMemMapCloseFailed); return 1;}
        if (strcasecmp(str,"oacMemMapWriteFailed")==0) { result->SetData(oacMemMapWriteFailed); return 1;}
        if (strcasecmp(str,"oacFileTruncateFailed")==0) { result->SetData(oacFileTruncateFailed); return 1;}
        if (strcasecmp(str,"oacGetFullPathFailed")==0) { result->SetData(oacGetFullPathFailed); return 1;}
        if (strcasecmp(str,"oacFileOpenFailed")==0) { result->SetData(oacFileOpenFailed); return 1;}
        if (strcasecmp(str,"oacFileCloseFailed")==0) { result->SetData(oacFileCloseFailed); return 1;}
        if (strcasecmp(str,"oacFileReadFailed")==0) { result->SetData(oacFileReadFailed); return 1;}
        if (strcasecmp(str,"oacFileWriteFailed")==0) { result->SetData(oacFileWriteFailed); return 1;}
        if (strcasecmp(str,"oacFileGetInfoFailed")==0) { result->SetData(oacFileGetInfoFailed); return 1;}
        if (strcasecmp(str,"oacFileCopyFailed")==0) { result->SetData(oacFileCopyFailed); return 1;}
        if (strcasecmp(str,"oacFileSetAttrFailed")==0) { result->SetData(oacFileSetAttrFailed); return 1;}
        if (strcasecmp(str,"oacDirCreateFailed")==0) { result->SetData(oacDirCreateFailed); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaBaseMsgIds)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseMsgIds Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaBaseMsgIds_FromoaBaseMsgIds(oaBaseMsgIds ob)
{
    if (ob==oacOSError) return PyString_FromString("oacOSError");
    if (ob==oacInvalidAPIRev) return PyString_FromString("oacInvalidAPIRev");
    if (ob==oacInvalidFileAccessMode) return PyString_FromString("oacInvalidFileAccessMode");
    if (ob==oacFileNotWritable) return PyString_FromString("oacFileNotWritable");
    if (ob==oacUnableToRemove) return PyString_FromString("oacUnableToRemove");
    if (ob==oacUnableToRename) return PyString_FromString("oacUnableToRename");
    if (ob==oacInvalidFileSize) return PyString_FromString("oacInvalidFileSize");
    if (ob==oacInvalidMapFileWindow) return PyString_FromString("oacInvalidMapFileWindow");
    if (ob==oacInvalidSetMapWindowFile) return PyString_FromString("oacInvalidSetMapWindowFile");
    if (ob==oacInvalidDatabaseFile) return PyString_FromString("oacInvalidDatabaseFile");
    if (ob==oacInvalidDatabaseIndex) return PyString_FromString("oacInvalidDatabaseIndex");
    if (ob==oacInvalidDatabaseSize) return PyString_FromString("oacInvalidDatabaseSize");
    if (ob==oacDeletedDatabase) return PyString_FromString("oacDeletedDatabase");
    if (ob==oacMismatchDatabaseID) return PyString_FromString("oacMismatchDatabaseID");
    if (ob==oacCannotUpgrade) return PyString_FromString("oacCannotUpgrade");
    if (ob==oacInvalidDatabaseAccessMode) return PyString_FromString("oacInvalidDatabaseAccessMode");
    if (ob==oacInvalidProp) return PyString_FromString("oacInvalidProp");
    if (ob==oacPropNameUsed) return PyString_FromString("oacPropNameUsed");
    if (ob==oacInvalidObjForProp) return PyString_FromString("oacInvalidObjForProp");
    if (ob==oacInvalidGroupTypeName) return PyString_FromString("oacInvalidGroupTypeName");
    if (ob==oacInvalidGroupDeleteWhenTypeName) return PyString_FromString("oacInvalidGroupDeleteWhenTypeName");
    if (ob==oacInvalidGroup) return PyString_FromString("oacInvalidGroup");
    if (ob==oacInvalidObjForGroup) return PyString_FromString("oacInvalidObjForGroup");
    if (ob==oacInvalidGroupObject) return PyString_FromString("oacInvalidGroupObject");
    if (ob==oacGroupMemberNotInSameDB) return PyString_FromString("oacGroupMemberNotInSameDB");
    if (ob==oacGroupMemberNotInDomain) return PyString_FromString("oacGroupMemberNotInDomain");
    if (ob==oacInvalidUniqueGroupName) return PyString_FromString("oacInvalidUniqueGroupName");
    if (ob==oacInvalidGroupForSameObj) return PyString_FromString("oacInvalidGroupForSameObj");
    if (ob==oacInvalidGroupForLeader) return PyString_FromString("oacInvalidGroupForLeader");
    if (ob==oacMultipleGroupLeader) return PyString_FromString("oacMultipleGroupLeader");
    if (ob==oacInvalidGroupLeader) return PyString_FromString("oacInvalidGroupLeader");
    if (ob==oacInvalidGroupMem) return PyString_FromString("oacInvalidGroupMem");
    if (ob==oacInvalidGroupForMemberMove) return PyString_FromString("oacInvalidGroupForMemberMove");
    if (ob==oacInvalidGroupTypeForMemberMove) return PyString_FromString("oacInvalidGroupTypeForMemberMove");
    if (ob==oacInvalidMoveLeader) return PyString_FromString("oacInvalidMoveLeader");
    if (ob==oacUnableToOpenDir) return PyString_FromString("oacUnableToOpenDir");
    if (ob==oacInvalidValueForIntRange) return PyString_FromString("oacInvalidValueForIntRange");
    if (ob==oacInvalidValueForFloatRange) return PyString_FromString("oacInvalidValueForFloatRange");
    if (ob==oacInvalidEnumValue) return PyString_FromString("oacInvalidEnumValue");
    if (ob==oacInvalidName) return PyString_FromString("oacInvalidName");
    if (ob==oacInvalidNameTypeName) return PyString_FromString("oacInvalidNameTypeName");
    if (ob==oacInvalidNameLength) return PyString_FromString("oacInvalidNameLength");
    if (ob==oacInvalidNameSyntax) return PyString_FromString("oacInvalidNameSyntax");
    if (ob==oacInvalidNameChar) return PyString_FromString("oacInvalidNameChar");
    if (ob==oacStepNameInvalid) return PyString_FromString("oacStepNameInvalid");
    if (ob==oacIndexedNameInvalid) return PyString_FromString("oacIndexedNameInvalid");
    if (ob==oacVectorNameInvalid) return PyString_FromString("oacVectorNameInvalid");
    if (ob==oacHierNameInvalid) return PyString_FromString("oacHierNameInvalid");
    if (ob==oacInvalidNameIndex) return PyString_FromString("oacInvalidNameIndex");
    if (ob==oacInvalidVectorValue) return PyString_FromString("oacInvalidVectorValue");
    if (ob==oacBundleNameInvalid) return PyString_FromString("oacBundleNameInvalid");
    if (ob==oacProgrammableCharTaken) return PyString_FromString("oacProgrammableCharTaken");
    if (ob==oacProgrammableCharInvalid) return PyString_FromString("oacProgrammableCharInvalid");
    if (ob==oacNameNotIndexed) return PyString_FromString("oacNameNotIndexed");
    if (ob==oacBitNotInRangeForName) return PyString_FromString("oacBitNotInRangeForName");
    if (ob==oacInvalidDesignObjectForAppDef) return PyString_FromString("oacInvalidDesignObjectForAppDef");
    if (ob==oacInvalidDesignObjectForInterAppDef) return PyString_FromString("oacInvalidDesignObjectForInterAppDef");
    if (ob==oacInvalidDesignObjectForIntraAppDef) return PyString_FromString("oacInvalidDesignObjectForIntraAppDef");
    if (ob==oacInvalidAppDef) return PyString_FromString("oacInvalidAppDef");
    if (ob==oacAppDefExists) return PyString_FromString("oacAppDefExists");
    if (ob==oacInvalidAppObjectDef) return PyString_FromString("oacInvalidAppObjectDef");
    if (ob==oacDeletedAppObject) return PyString_FromString("oacDeletedAppObject");
    if (ob==oacInvalidAppObject) return PyString_FromString("oacInvalidAppObject");
    if (ob==oacDeleteLockedTree) return PyString_FromString("oacDeleteLockedTree");
    if (ob==oacMemGetFailed) return PyString_FromString("oacMemGetFailed");
    if (ob==oacMemResizeFailed) return PyString_FromString("oacMemResizeFailed");
    if (ob==oacNoObjectDB) return PyString_FromString("oacNoObjectDB");
    if (ob==oacInvalidObjectTypeName) return PyString_FromString("oacInvalidObjectTypeName");
    if (ob==oacInvalidOrientName) return PyString_FromString("oacInvalidOrientName");
    if (ob==oacInvalidInterpolateTypeName) return PyString_FromString("oacInvalidInterpolateTypeName");
    if (ob==oacInvalidExtrapolateTypeName) return PyString_FromString("oacInvalidExtrapolateTypeName");
    if (ob==oacInvalidDomainName) return PyString_FromString("oacInvalidDomainName");
    if (ob==oacInvalidParamTypeName) return PyString_FromString("oacInvalidParamTypeName");
    if (ob==oacNotASession) return PyString_FromString("oacNotASession");
    if (ob==oacInvalidSession) return PyString_FromString("oacInvalidSession");
    if (ob==oacInvalidConstraintParamTypeName) return PyString_FromString("oacInvalidConstraintParamTypeName");
    if (ob==oacInvalidSimpleConstraintTypeName) return PyString_FromString("oacInvalidSimpleConstraintTypeName");
    if (ob==oacInvalidLayerConstraintTypeName) return PyString_FromString("oacInvalidLayerConstraintTypeName");
    if (ob==oacInvalidLayerPairConstraintTypeName) return PyString_FromString("oacInvalidLayerPairConstraintTypeName");
    if (ob==oacInvalidDBTypeName) return PyString_FromString("oacInvalidDBTypeName");
    if (ob==oacInvalidConstraintParamDef) return PyString_FromString("oacInvalidConstraintParamDef");
    if (ob==oacConstraintParamDefExists) return PyString_FromString("oacConstraintParamDefExists");
    if (ob==oacConstraintParamDefHasReference) return PyString_FromString("oacConstraintParamDefHasReference");
    if (ob==oacUnableToDestroyBuiltInType) return PyString_FromString("oacUnableToDestroyBuiltInType");
    if (ob==oacValueInvalidForConstraintParamDef) return PyString_FromString("oacValueInvalidForConstraintParamDef");
    if (ob==oacInvalidConstraintParam) return PyString_FromString("oacInvalidConstraintParam");
    if (ob==oacConstraintParamAlreadyOwned) return PyString_FromString("oacConstraintParamAlreadyOwned");
    if (ob==oacCantDestroyOwnedConstraintParam) return PyString_FromString("oacCantDestroyOwnedConstraintParam");
    if (ob==oacInvalidObjForConstraintParam) return PyString_FromString("oacInvalidObjForConstraintParam");
    if (ob==oacConstraintParamNotInSameDB) return PyString_FromString("oacConstraintParamNotInSameDB");
    if (ob==oacInvalidConstraintDef) return PyString_FromString("oacInvalidConstraintDef");
    if (ob==oacConstraintDefExists) return PyString_FromString("oacConstraintDefExists");
    if (ob==oacConstraintDefHasReference) return PyString_FromString("oacConstraintDefHasReference");
    if (ob==oacInvalidValueForConstraintDef) return PyString_FromString("oacInvalidValueForConstraintDef");
    if (ob==oacInvalidDBForConstraintDef) return PyString_FromString("oacInvalidDBForConstraintDef");
    if (ob==oacInvalidObjForConstraintDef) return PyString_FromString("oacInvalidObjForConstraintDef");
    if (ob==oacInvalidConstraintType) return PyString_FromString("oacInvalidConstraintType");
    if (ob==oacConstraintNameExists) return PyString_FromString("oacConstraintNameExists");
    if (ob==oacInvalidDatabaseForLayerConstraint) return PyString_FromString("oacInvalidDatabaseForLayerConstraint");
    if (ob==oacInvalidDatabaseForLayerPairConstraint) return PyString_FromString("oacInvalidDatabaseForLayerPairConstraint");
    if (ob==oacValueAlreadyOwned) return PyString_FromString("oacValueAlreadyOwned");
    if (ob==oacCantDestroyOwnedValue) return PyString_FromString("oacCantDestroyOwnedValue");
    if (ob==oacInvalidValueType) return PyString_FromString("oacInvalidValueType");
    if (ob==oacInvalidObjForValue) return PyString_FromString("oacInvalidObjForValue");
    if (ob==oacIllDefinedTblSpecified) return PyString_FromString("oacIllDefinedTblSpecified");
    if (ob==oacValueNotInSameDatabase) return PyString_FromString("oacValueNotInSameDatabase");
    if (ob==oacInvalidValueForCopy) return PyString_FromString("oacInvalidValueForCopy");
    if (ob==oacEmptyArrayValue) return PyString_FromString("oacEmptyArrayValue");
    if (ob==oacInvalidValueArrayValue) return PyString_FromString("oacInvalidValueArrayValue");
    if (ob==oacInvalidDefaultValueForTblValue) return PyString_FromString("oacInvalidDefaultValueForTblValue");
    if (ob==oacInvalidConstraintGroup) return PyString_FromString("oacInvalidConstraintGroup");
    if (ob==oacInvalidConstraintGroupMem) return PyString_FromString("oacInvalidConstraintGroupMem");
    if (ob==oacInvalidObjForConstraintGroup) return PyString_FromString("oacInvalidObjForConstraintGroup");
    if (ob==oacConstraintGroupNameExists) return PyString_FromString("oacConstraintGroupNameExists");
    if (ob==oacConstraintGroupAlreadyHasObj) return PyString_FromString("oacConstraintGroupAlreadyHasObj");
    if (ob==oacConstraintGroupMemberNotInValidDB) return PyString_FromString("oacConstraintGroupMemberNotInValidDB");
    if (ob==oacInvalidConstraintGroupForMemberMove) return PyString_FromString("oacInvalidConstraintGroupForMemberMove");
    if (ob==oacInvalidConstraintGroupHeader) return PyString_FromString("oacInvalidConstraintGroupHeader");
    if (ob==oacInvalidObjForConstraintGroupHeader) return PyString_FromString("oacInvalidObjForConstraintGroupHeader");
    if (ob==oacCannotDeleteObject) return PyString_FromString("oacCannotDeleteObject");
    if (ob==oacInvalidDatabaseForObject) return PyString_FromString("oacInvalidDatabaseForObject");
    if (ob==oacInvalidBusSyntax) return PyString_FromString("oacInvalidBusSyntax");
    if (ob==oacInvalidBitValue) return PyString_FromString("oacInvalidBitValue");
    if (ob==oacInvalidParenSyntax) return PyString_FromString("oacInvalidParenSyntax");
    if (ob==oacFirstCharInvalid) return PyString_FromString("oacFirstCharInvalid");
    if (ob==oacInvalidCharFollowingEscChar) return PyString_FromString("oacInvalidCharFollowingEscChar");
    if (ob==oacInvalidNameKeywordConflict) return PyString_FromString("oacInvalidNameKeywordConflict");
    if (ob==oacInvalidNumberSyntax) return PyString_FromString("oacInvalidNumberSyntax");
    if (ob==oacInvalidCharFollowingHexChar) return PyString_FromString("oacInvalidCharFollowingHexChar");
    if (ob==oacNotYetSupported) return PyString_FromString("oacNotYetSupported");
    if (ob==oacInvalidDatabaseForValue) return PyString_FromString("oacInvalidDatabaseForValue");
    if (ob==oacCorruptedDatabase) return PyString_FromString("oacCorruptedDatabase");
    if (ob==oacInternalError) return PyString_FromString("oacInternalError");
    if (ob==oacCannotBeCalled) return PyString_FromString("oacCannotBeCalled");
    if (ob==oacSocketGeneralError) return PyString_FromString("oacSocketGeneralError");
    if (ob==oacCannotResetMutex) return PyString_FromString("oacCannotResetMutex");
    if (ob==oacCannotCreateMutex) return PyString_FromString("oacCannotCreateMutex");
    if (ob==oacInvalidDatabase) return PyString_FromString("oacInvalidDatabase");
    if (ob==oacInvalidMajorAPIRev) return PyString_FromString("oacInvalidMajorAPIRev");
    if (ob==oacInvalidCategoryName) return PyString_FromString("oacInvalidCategoryName");
    if (ob==oacInvalidDataModelModTypeName) return PyString_FromString("oacInvalidDataModelModTypeName");
    if (ob==oacInvalidFeature) return PyString_FromString("oacInvalidFeature");
    if (ob==oacCannotDowngradeDatabase) return PyString_FromString("oacCannotDowngradeDatabase");
    if (ob==oacDataNotCompatibleOnOpen) return PyString_FromString("oacDataNotCompatibleOnOpen");
    if (ob==oacDataNotCompatibleOnOpenInAppendMode) return PyString_FromString("oacDataNotCompatibleOnOpenInAppendMode");
    if (ob==oacDataNotCompatibleOnOpenInEditableMode) return PyString_FromString("oacDataNotCompatibleOnOpenInEditableMode");
    if (ob==oacDataNotCompatibleOnSave) return PyString_FromString("oacDataNotCompatibleOnSave");
    if (ob==oacInvalidDataModelRev) return PyString_FromString("oacInvalidDataModelRev");
    if (ob==oacInconsistentDataModelRev) return PyString_FromString("oacInconsistentDataModelRev");
    if (ob==oacCannotOpenHugeDatabase) return PyString_FromString("oacCannotOpenHugeDatabase");
    if (ob==oacInvalidRangeTypeName) return PyString_FromString("oacInvalidRangeTypeName");
    if (ob==oacInvalidBoundsForRange) return PyString_FromString("oacInvalidBoundsForRange");
    if (ob==oacInvalidTypeForRange) return PyString_FromString("oacInvalidTypeForRange");
    if (ob==oacInvalidBoundForRange) return PyString_FromString("oacInvalidBoundForRange");
    if (ob==oacInvalidLayerArrayConstraintTypeName) return PyString_FromString("oacInvalidLayerArrayConstraintTypeName");
    if (ob==oacInvalidDistanceMeasureTypeName) return PyString_FromString("oacInvalidDistanceMeasureTypeName");
    if (ob==oacInvalidWidthLengthTableTypeName) return PyString_FromString("oacInvalidWidthLengthTableTypeName");
    if (ob==oacCannotMoveImplicitConstraintGroupMem) return PyString_FromString("oacCannotMoveImplicitConstraintGroupMem");
    if (ob==oacCannotDestroyImplicitConstraintGroupMem) return PyString_FromString("oacCannotDestroyImplicitConstraintGroupMem");
    if (ob==oacInvalidDatabaseForLayerArrayConstraint) return PyString_FromString("oacInvalidDatabaseForLayerArrayConstraint");
    if (ob==oacInvalidAlignmentTypeName) return PyString_FromString("oacInvalidAlignmentTypeName");
    if (ob==oacInvalidInterpolateTypeForTable) return PyString_FromString("oacInvalidInterpolateTypeForTable");
    if (ob==oacInvalidExtrapolateTypeForTable) return PyString_FromString("oacInvalidExtrapolateTypeForTable");
    if (ob==oacInvalidLayerArrayForLayerArrayConstraint) return PyString_FromString("oacInvalidLayerArrayForLayerArrayConstraint");
    if (ob==oacCannotCreateValueInDesignDBWithNoBlocks) return PyString_FromString("oacCannotCreateValueInDesignDBWithNoBlocks");
    if (ob==oacCannotDestroyConstraintGroupContainingImplicitMem) return PyString_FromString("oacCannotDestroyConstraintGroupContainingImplicitMem");
    if (ob==oacCannotUpgradeOverwrittenDatabase) return PyString_FromString("oacCannotUpgradeOverwrittenDatabase");
    if (ob==oacInvalidSessionObject) return PyString_FromString("oacInvalidSessionObject");
    if (ob==oacInvalidObject) return PyString_FromString("oacInvalidObject");
    if (ob==oacCannotSaveDataModelRev) return PyString_FromString("oacCannotSaveDataModelRev");
    if (ob==oacCannotRepairCorruptedAppData) return PyString_FromString("oacCannotRepairCorruptedAppData");
    if (ob==oacCannotKillProcess) return PyString_FromString("oacCannotKillProcess");
    if (ob==oacCannotCreateProcess) return PyString_FromString("oacCannotCreateProcess");
    if (ob==oacChildProcessError) return PyString_FromString("oacChildProcessError");
    if (ob==oacCreateFileMappingFailed) return PyString_FromString("oacCreateFileMappingFailed");
    if (ob==oacResetFileMappingFailed) return PyString_FromString("oacResetFileMappingFailed");
    if (ob==oacFileMappingFailed) return PyString_FromString("oacFileMappingFailed");
    if (ob==oacMemMapCloseFailed) return PyString_FromString("oacMemMapCloseFailed");
    if (ob==oacMemMapWriteFailed) return PyString_FromString("oacMemMapWriteFailed");
    if (ob==oacFileTruncateFailed) return PyString_FromString("oacFileTruncateFailed");
    if (ob==oacGetFullPathFailed) return PyString_FromString("oacGetFullPathFailed");
    if (ob==oacFileOpenFailed) return PyString_FromString("oacFileOpenFailed");
    if (ob==oacFileCloseFailed) return PyString_FromString("oacFileCloseFailed");
    if (ob==oacFileReadFailed) return PyString_FromString("oacFileReadFailed");
    if (ob==oacFileWriteFailed) return PyString_FromString("oacFileWriteFailed");
    if (ob==oacFileGetInfoFailed) return PyString_FromString("oacFileGetInfoFailed");
    if (ob==oacFileCopyFailed) return PyString_FromString("oacFileCopyFailed");
    if (ob==oacFileSetAttrFailed) return PyString_FromString("oacFileSetAttrFailed");
    if (ob==oacDirCreateFailed) return PyString_FromString("oacDirCreateFailed");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaBaseMsgIds_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaBaseMsgIds e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaBaseMsgIds_FromoaBaseMsgIds(oaBaseMsgIds(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaBaseMsgIds_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaBaseMsgIds_doc[] =
"Type convert function for enum: oaBaseMsgIds";
                               
static PyMethodDef PyoaBaseMsgIds_method =
  {"oaBaseMsgIds",(PyCFunction)PyoaBaseMsgIds_TypeFunction,METH_VARARGS,oaBaseMsgIds_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaBaseMsgIds_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacOSError");
    PyDict_SetItemString(mod_dict,"oacOSError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAPIRev");
    PyDict_SetItemString(mod_dict,"oacInvalidAPIRev",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidFileAccessMode");
    PyDict_SetItemString(mod_dict,"oacInvalidFileAccessMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileNotWritable");
    PyDict_SetItemString(mod_dict,"oacFileNotWritable",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnableToRemove");
    PyDict_SetItemString(mod_dict,"oacUnableToRemove",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnableToRename");
    PyDict_SetItemString(mod_dict,"oacUnableToRename",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidFileSize");
    PyDict_SetItemString(mod_dict,"oacInvalidFileSize",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidMapFileWindow");
    PyDict_SetItemString(mod_dict,"oacInvalidMapFileWindow",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidSetMapWindowFile");
    PyDict_SetItemString(mod_dict,"oacInvalidSetMapWindowFile",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseFile");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseFile",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseIndex");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseIndex",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseSize");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseSize",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeletedDatabase");
    PyDict_SetItemString(mod_dict,"oacDeletedDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMismatchDatabaseID");
    PyDict_SetItemString(mod_dict,"oacMismatchDatabaseID",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotUpgrade");
    PyDict_SetItemString(mod_dict,"oacCannotUpgrade",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseAccessMode");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseAccessMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidProp");
    PyDict_SetItemString(mod_dict,"oacInvalidProp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPropNameUsed");
    PyDict_SetItemString(mod_dict,"oacPropNameUsed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForProp");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForProp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupDeleteWhenTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupDeleteWhenTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroup");
    PyDict_SetItemString(mod_dict,"oacInvalidGroup",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForGroup");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForGroup",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupObject");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGroupMemberNotInSameDB");
    PyDict_SetItemString(mod_dict,"oacGroupMemberNotInSameDB",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGroupMemberNotInDomain");
    PyDict_SetItemString(mod_dict,"oacGroupMemberNotInDomain",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidUniqueGroupName");
    PyDict_SetItemString(mod_dict,"oacInvalidUniqueGroupName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupForSameObj");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupForSameObj",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupForLeader");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupForLeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMultipleGroupLeader");
    PyDict_SetItemString(mod_dict,"oacMultipleGroupLeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupLeader");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupLeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupMem");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupMem",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupForMemberMove");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupForMemberMove",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidGroupTypeForMemberMove");
    PyDict_SetItemString(mod_dict,"oacInvalidGroupTypeForMemberMove",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidMoveLeader");
    PyDict_SetItemString(mod_dict,"oacInvalidMoveLeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnableToOpenDir");
    PyDict_SetItemString(mod_dict,"oacUnableToOpenDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueForIntRange");
    PyDict_SetItemString(mod_dict,"oacInvalidValueForIntRange",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueForFloatRange");
    PyDict_SetItemString(mod_dict,"oacInvalidValueForFloatRange",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidEnumValue");
    PyDict_SetItemString(mod_dict,"oacInvalidEnumValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidName");
    PyDict_SetItemString(mod_dict,"oacInvalidName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidNameTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameLength");
    PyDict_SetItemString(mod_dict,"oacInvalidNameLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameSyntax");
    PyDict_SetItemString(mod_dict,"oacInvalidNameSyntax",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameChar");
    PyDict_SetItemString(mod_dict,"oacInvalidNameChar",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStepNameInvalid");
    PyDict_SetItemString(mod_dict,"oacStepNameInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacIndexedNameInvalid");
    PyDict_SetItemString(mod_dict,"oacIndexedNameInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVectorNameInvalid");
    PyDict_SetItemString(mod_dict,"oacVectorNameInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHierNameInvalid");
    PyDict_SetItemString(mod_dict,"oacHierNameInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameIndex");
    PyDict_SetItemString(mod_dict,"oacInvalidNameIndex",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidVectorValue");
    PyDict_SetItemString(mod_dict,"oacInvalidVectorValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBundleNameInvalid");
    PyDict_SetItemString(mod_dict,"oacBundleNameInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacProgrammableCharTaken");
    PyDict_SetItemString(mod_dict,"oacProgrammableCharTaken",value);
    Py_DECREF(value);
    value=PyString_FromString("oacProgrammableCharInvalid");
    PyDict_SetItemString(mod_dict,"oacProgrammableCharInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNameNotIndexed");
    PyDict_SetItemString(mod_dict,"oacNameNotIndexed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBitNotInRangeForName");
    PyDict_SetItemString(mod_dict,"oacBitNotInRangeForName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDesignObjectForAppDef");
    PyDict_SetItemString(mod_dict,"oacInvalidDesignObjectForAppDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDesignObjectForInterAppDef");
    PyDict_SetItemString(mod_dict,"oacInvalidDesignObjectForInterAppDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDesignObjectForIntraAppDef");
    PyDict_SetItemString(mod_dict,"oacInvalidDesignObjectForIntraAppDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAppDef");
    PyDict_SetItemString(mod_dict,"oacInvalidAppDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAppDefExists");
    PyDict_SetItemString(mod_dict,"oacAppDefExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAppObjectDef");
    PyDict_SetItemString(mod_dict,"oacInvalidAppObjectDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeletedAppObject");
    PyDict_SetItemString(mod_dict,"oacDeletedAppObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAppObject");
    PyDict_SetItemString(mod_dict,"oacInvalidAppObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeleteLockedTree");
    PyDict_SetItemString(mod_dict,"oacDeleteLockedTree",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMemGetFailed");
    PyDict_SetItemString(mod_dict,"oacMemGetFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMemResizeFailed");
    PyDict_SetItemString(mod_dict,"oacMemResizeFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNoObjectDB");
    PyDict_SetItemString(mod_dict,"oacNoObjectDB",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjectTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidObjectTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidOrientName");
    PyDict_SetItemString(mod_dict,"oacInvalidOrientName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidInterpolateTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidInterpolateTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidExtrapolateTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidExtrapolateTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDomainName");
    PyDict_SetItemString(mod_dict,"oacInvalidDomainName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidParamTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidParamTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNotASession");
    PyDict_SetItemString(mod_dict,"oacNotASession",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidSession");
    PyDict_SetItemString(mod_dict,"oacInvalidSession",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintParamTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintParamTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidSimpleConstraintTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidSimpleConstraintTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidLayerConstraintTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidLayerConstraintTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidLayerPairConstraintTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidLayerPairConstraintTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDBTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidDBTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintParamDef");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintParamDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamDefExists");
    PyDict_SetItemString(mod_dict,"oacConstraintParamDefExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamDefHasReference");
    PyDict_SetItemString(mod_dict,"oacConstraintParamDefHasReference",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnableToDestroyBuiltInType");
    PyDict_SetItemString(mod_dict,"oacUnableToDestroyBuiltInType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacValueInvalidForConstraintParamDef");
    PyDict_SetItemString(mod_dict,"oacValueInvalidForConstraintParamDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintParam");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintParam",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamAlreadyOwned");
    PyDict_SetItemString(mod_dict,"oacConstraintParamAlreadyOwned",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCantDestroyOwnedConstraintParam");
    PyDict_SetItemString(mod_dict,"oacCantDestroyOwnedConstraintParam",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForConstraintParam");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForConstraintParam",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamNotInSameDB");
    PyDict_SetItemString(mod_dict,"oacConstraintParamNotInSameDB",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintDef");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintDefExists");
    PyDict_SetItemString(mod_dict,"oacConstraintDefExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintDefHasReference");
    PyDict_SetItemString(mod_dict,"oacConstraintDefHasReference",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueForConstraintDef");
    PyDict_SetItemString(mod_dict,"oacInvalidValueForConstraintDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDBForConstraintDef");
    PyDict_SetItemString(mod_dict,"oacInvalidDBForConstraintDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForConstraintDef");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForConstraintDef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintType");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintNameExists");
    PyDict_SetItemString(mod_dict,"oacConstraintNameExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseForLayerConstraint");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseForLayerConstraint",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseForLayerPairConstraint");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseForLayerPairConstraint",value);
    Py_DECREF(value);
    value=PyString_FromString("oacValueAlreadyOwned");
    PyDict_SetItemString(mod_dict,"oacValueAlreadyOwned",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCantDestroyOwnedValue");
    PyDict_SetItemString(mod_dict,"oacCantDestroyOwnedValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueType");
    PyDict_SetItemString(mod_dict,"oacInvalidValueType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForValue");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacIllDefinedTblSpecified");
    PyDict_SetItemString(mod_dict,"oacIllDefinedTblSpecified",value);
    Py_DECREF(value);
    value=PyString_FromString("oacValueNotInSameDatabase");
    PyDict_SetItemString(mod_dict,"oacValueNotInSameDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueForCopy");
    PyDict_SetItemString(mod_dict,"oacInvalidValueForCopy",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEmptyArrayValue");
    PyDict_SetItemString(mod_dict,"oacEmptyArrayValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidValueArrayValue");
    PyDict_SetItemString(mod_dict,"oacInvalidValueArrayValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDefaultValueForTblValue");
    PyDict_SetItemString(mod_dict,"oacInvalidDefaultValueForTblValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintGroup");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintGroup",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintGroupMem");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintGroupMem",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForConstraintGroup");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForConstraintGroup",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupNameExists");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupNameExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupAlreadyHasObj");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupAlreadyHasObj",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupMemberNotInValidDB");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupMemberNotInValidDB",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintGroupForMemberMove");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintGroupForMemberMove",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidConstraintGroupHeader");
    PyDict_SetItemString(mod_dict,"oacInvalidConstraintGroupHeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObjForConstraintGroupHeader");
    PyDict_SetItemString(mod_dict,"oacInvalidObjForConstraintGroupHeader",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotDeleteObject");
    PyDict_SetItemString(mod_dict,"oacCannotDeleteObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseForObject");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseForObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidBusSyntax");
    PyDict_SetItemString(mod_dict,"oacInvalidBusSyntax",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidBitValue");
    PyDict_SetItemString(mod_dict,"oacInvalidBitValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidParenSyntax");
    PyDict_SetItemString(mod_dict,"oacInvalidParenSyntax",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFirstCharInvalid");
    PyDict_SetItemString(mod_dict,"oacFirstCharInvalid",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidCharFollowingEscChar");
    PyDict_SetItemString(mod_dict,"oacInvalidCharFollowingEscChar",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNameKeywordConflict");
    PyDict_SetItemString(mod_dict,"oacInvalidNameKeywordConflict",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidNumberSyntax");
    PyDict_SetItemString(mod_dict,"oacInvalidNumberSyntax",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidCharFollowingHexChar");
    PyDict_SetItemString(mod_dict,"oacInvalidCharFollowingHexChar",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNotYetSupported");
    PyDict_SetItemString(mod_dict,"oacNotYetSupported",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseForValue");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseForValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCorruptedDatabase");
    PyDict_SetItemString(mod_dict,"oacCorruptedDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInternalError");
    PyDict_SetItemString(mod_dict,"oacInternalError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotBeCalled");
    PyDict_SetItemString(mod_dict,"oacCannotBeCalled",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSocketGeneralError");
    PyDict_SetItemString(mod_dict,"oacSocketGeneralError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotResetMutex");
    PyDict_SetItemString(mod_dict,"oacCannotResetMutex",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotCreateMutex");
    PyDict_SetItemString(mod_dict,"oacCannotCreateMutex",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabase");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidMajorAPIRev");
    PyDict_SetItemString(mod_dict,"oacInvalidMajorAPIRev",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidCategoryName");
    PyDict_SetItemString(mod_dict,"oacInvalidCategoryName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDataModelModTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidDataModelModTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidFeature");
    PyDict_SetItemString(mod_dict,"oacInvalidFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotDowngradeDatabase");
    PyDict_SetItemString(mod_dict,"oacCannotDowngradeDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDataNotCompatibleOnOpen");
    PyDict_SetItemString(mod_dict,"oacDataNotCompatibleOnOpen",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDataNotCompatibleOnOpenInAppendMode");
    PyDict_SetItemString(mod_dict,"oacDataNotCompatibleOnOpenInAppendMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDataNotCompatibleOnOpenInEditableMode");
    PyDict_SetItemString(mod_dict,"oacDataNotCompatibleOnOpenInEditableMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDataNotCompatibleOnSave");
    PyDict_SetItemString(mod_dict,"oacDataNotCompatibleOnSave",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDataModelRev");
    PyDict_SetItemString(mod_dict,"oacInvalidDataModelRev",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInconsistentDataModelRev");
    PyDict_SetItemString(mod_dict,"oacInconsistentDataModelRev",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotOpenHugeDatabase");
    PyDict_SetItemString(mod_dict,"oacCannotOpenHugeDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidRangeTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidRangeTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidBoundsForRange");
    PyDict_SetItemString(mod_dict,"oacInvalidBoundsForRange",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidTypeForRange");
    PyDict_SetItemString(mod_dict,"oacInvalidTypeForRange",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidBoundForRange");
    PyDict_SetItemString(mod_dict,"oacInvalidBoundForRange",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidLayerArrayConstraintTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidLayerArrayConstraintTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDistanceMeasureTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidDistanceMeasureTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWidthLengthTableTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidWidthLengthTableTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotMoveImplicitConstraintGroupMem");
    PyDict_SetItemString(mod_dict,"oacCannotMoveImplicitConstraintGroupMem",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotDestroyImplicitConstraintGroupMem");
    PyDict_SetItemString(mod_dict,"oacCannotDestroyImplicitConstraintGroupMem",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDatabaseForLayerArrayConstraint");
    PyDict_SetItemString(mod_dict,"oacInvalidDatabaseForLayerArrayConstraint",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAlignmentTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidAlignmentTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidInterpolateTypeForTable");
    PyDict_SetItemString(mod_dict,"oacInvalidInterpolateTypeForTable",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidExtrapolateTypeForTable");
    PyDict_SetItemString(mod_dict,"oacInvalidExtrapolateTypeForTable",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidLayerArrayForLayerArrayConstraint");
    PyDict_SetItemString(mod_dict,"oacInvalidLayerArrayForLayerArrayConstraint",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotCreateValueInDesignDBWithNoBlocks");
    PyDict_SetItemString(mod_dict,"oacCannotCreateValueInDesignDBWithNoBlocks",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotDestroyConstraintGroupContainingImplicitMem");
    PyDict_SetItemString(mod_dict,"oacCannotDestroyConstraintGroupContainingImplicitMem",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotUpgradeOverwrittenDatabase");
    PyDict_SetItemString(mod_dict,"oacCannotUpgradeOverwrittenDatabase",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidSessionObject");
    PyDict_SetItemString(mod_dict,"oacInvalidSessionObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidObject");
    PyDict_SetItemString(mod_dict,"oacInvalidObject",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotSaveDataModelRev");
    PyDict_SetItemString(mod_dict,"oacCannotSaveDataModelRev",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotRepairCorruptedAppData");
    PyDict_SetItemString(mod_dict,"oacCannotRepairCorruptedAppData",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotKillProcess");
    PyDict_SetItemString(mod_dict,"oacCannotKillProcess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotCreateProcess");
    PyDict_SetItemString(mod_dict,"oacCannotCreateProcess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacChildProcessError");
    PyDict_SetItemString(mod_dict,"oacChildProcessError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCreateFileMappingFailed");
    PyDict_SetItemString(mod_dict,"oacCreateFileMappingFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacResetFileMappingFailed");
    PyDict_SetItemString(mod_dict,"oacResetFileMappingFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileMappingFailed");
    PyDict_SetItemString(mod_dict,"oacFileMappingFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMemMapCloseFailed");
    PyDict_SetItemString(mod_dict,"oacMemMapCloseFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMemMapWriteFailed");
    PyDict_SetItemString(mod_dict,"oacMemMapWriteFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileTruncateFailed");
    PyDict_SetItemString(mod_dict,"oacFileTruncateFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGetFullPathFailed");
    PyDict_SetItemString(mod_dict,"oacGetFullPathFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileOpenFailed");
    PyDict_SetItemString(mod_dict,"oacFileOpenFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileCloseFailed");
    PyDict_SetItemString(mod_dict,"oacFileCloseFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileReadFailed");
    PyDict_SetItemString(mod_dict,"oacFileReadFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileWriteFailed");
    PyDict_SetItemString(mod_dict,"oacFileWriteFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileGetInfoFailed");
    PyDict_SetItemString(mod_dict,"oacFileGetInfoFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileCopyFailed");
    PyDict_SetItemString(mod_dict,"oacFileCopyFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFileSetAttrFailed");
    PyDict_SetItemString(mod_dict,"oacFileSetAttrFailed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDirCreateFailed");
    PyDict_SetItemString(mod_dict,"oacDirCreateFailed",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaBaseMsgIds_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaBaseMsgIds",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaBaseMsgIds\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaBaseObserver
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBaseObserver_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBaseObserver_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBaseObserverObject* self = (PyoaBaseObserverObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value =  new oaBaseObserver(p1.Data());
            }
            else {
                pyv_oaBaseObserver* p=new pyv_oaBaseObserver(p1.Data());
                p->pyob=self;
                self->value= p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value =  new oaBaseObserver(p1.Data(),p2.Data());
            }
            else {
                pyv_oaBaseObserver* p=new pyv_oaBaseObserver(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBaseObserver)
    {
        PyParamoaBaseObserver p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBaseObserver_Convert,&p1)) {
            if (is_raw) {
                self->value= new oaBaseObserver(p1.Data());
            }
            else {
                pyv_oaBaseObserver* p=new pyv_oaBaseObserver(p1.Data());
            p->pyob=self;
                self->value=p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBaseObserver, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaBaseObserver)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBaseObserver_tp_dealloc(PyoaBaseObserverObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBaseObserver_tp_repr(PyObject *ob)
{
    PyParamoaBaseObserver value;
    int convert_status=PyoaBaseObserver_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaBaseObserver::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBaseObserver_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBaseObserver v1;
    PyParamoaBaseObserver v2;
    int convert_status1=PyoaBaseObserver_Convert(ob1,&v1);
    int convert_status2=PyoaBaseObserver_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBaseObserver_Convert(PyObject* ob,PyParamoaBaseObserver* result)
{
    if (ob == NULL) return 1;
    if (PyoaBaseObserver_Check(ob)) {
        result->SetData(  ((PyoaBaseObserverObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBaseObserver Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBaseObserver_FromoaBaseObserver(oaBaseObserver* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBaseObserver_Type.tp_alloc(&PyoaBaseObserver_Type,0);
        if (bself == NULL) return bself;
        PyoaBaseObserverObject* self = (PyoaBaseObserverObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// Virtual Functions:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
pyv_oaBaseObserver::pyv_oaBaseObserver(oaUInt4 p1)
 : pyob(NULL),
   oaBaseObserver(p1)
{
}

// ------------------------------------------------------------------
pyv_oaBaseObserver::pyv_oaBaseObserver(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaBaseObserver(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaBaseObserver::pyv_oaBaseObserver(const oaBaseObserver& p)
 : pyob(NULL),
   oaBaseObserver(p)
{
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseObserver_enable_doc[] = 
"Class: oaBaseObserver, Function: enable\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void enable(oaBoolean enabledIn)\n"
"    Signature: enable|void-void|simple-oaBoolean,\n"
"    oaBaseObserver::enable\n"
"    This function sets the enabled status of this observer according to the enabledIn parameter passed to the function.\n"
"    enabledIn\n"
"    specify true to set enable this observer; false to disable this observer.\n"
;

static PyObject*
oaBaseObserver_enable(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseObserver data;
    int convert_status=PyoaBaseObserver_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseObserverObject* self=(PyoaBaseObserverObject*)ob;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->enable(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBaseObserver_isEnabled_doc[] = 
"Class: oaBaseObserver, Function: isEnabled\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEnabled() const\n"
"    Signature: isEnabled|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaBaseObserver::isEnabled\n"
"    This function returns true if this observer is enabled; otherwise, it returns false .\n"
;

static PyObject*
oaBaseObserver_isEnabled(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBaseObserver data;
    int convert_status=PyoaBaseObserver_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBaseObserverObject* self=(PyoaBaseObserverObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isEnabled());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBaseObserver_assign_doc[] = 
"Class: oaBaseObserver, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBaseObserver_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBaseObserver data;
  int convert_status=PyoaBaseObserver_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBaseObserver p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBaseObserver_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBaseObserver_methodlist[] = {
    {"enable",(PyCFunction)oaBaseObserver_enable,METH_VARARGS,oaBaseObserver_enable_doc},
    {"isEnabled",(PyCFunction)oaBaseObserver_isEnabled,METH_VARARGS,oaBaseObserver_isEnabled_doc},
    {"assign",(PyCFunction)oaBaseObserver_tp_assign,METH_VARARGS,oaBaseObserver_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBaseObserver_doc[] = 
"Class: oaBaseObserver\n"
"  The oaBaseObserver <> class is a base class for oaObservers. It supports functions that set and get the enabled status of an observer object.\n"
"  See oaObserver for information on using OpenAccess observer classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaBaseObserver(oaUInt4 priorityIn)\n"
"    Signature: oaBaseObserver||simple-oaUInt4,simple-oaBoolean,\n"
"    This is the constructor for the oaBaseObserver class. Observers are ordered by priority from lowest to highest.\n"
"    priorityIn\n"
"    priority of this observer relative to other BaseObservers\n"
"    enabledIn\n"
"    Determines whether this observer is called when an observed event occurs\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaBaseObserver(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaBaseObserver||simple-oaUInt4,simple-oaBoolean,\n"
"    This is the constructor for the oaBaseObserver class. Observers are ordered by priority from lowest to highest.\n"
"    priorityIn\n"
"    priority of this observer relative to other BaseObservers\n"
"    enabledIn\n"
"    Determines whether this observer is called when an observed event occurs\n"
"  Paramegers: (oaBaseObserver)\n"
"    Calls: (const oaBaseObserver&)\n"
"    Signature: oaBaseObserver||cref-oaBaseObserver,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBaseObserver_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBaseObserver",
    sizeof(PyoaBaseObserverObject),
    0,
    (destructor)oaBaseObserver_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBaseObserver_tp_compare,	/* tp_compare */
    (reprfunc)oaBaseObserver_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBaseObserver_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBaseObserver_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBaseObserver_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBaseObserver_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBaseObserver_Type)<0) {
      printf("** PyType_Ready failed for: oaBaseObserver\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBaseObserver",
           (PyObject*)(&PyoaBaseObserver_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBaseObserver\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBasePackedData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBasePackedData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBasePackedData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBasePackedDataObject* self = (PyoaBasePackedDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaBasePackedData();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaBasePackedData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBasePackedData)
    {
        PyParamoaBasePackedData p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBasePackedData_Convert,&p1)) {
            self->value= new oaBasePackedData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBasePackedData, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaBasePackedData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBasePackedData_tp_dealloc(PyoaBasePackedDataObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBasePackedData_tp_repr(PyObject *ob)
{
    PyParamoaBasePackedData value;
    int convert_status=PyoaBasePackedData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaBasePackedData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBasePackedData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBasePackedData v1;
    PyParamoaBasePackedData v2;
    int convert_status1=PyoaBasePackedData_Convert(ob1,&v1);
    int convert_status2=PyoaBasePackedData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBasePackedData_Convert(PyObject* ob,PyParamoaBasePackedData* result)
{
    if (ob == NULL) return 1;
    if (PyoaBasePackedData_Check(ob)) {
        result->SetData(  ((PyoaBasePackedDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBasePackedData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBasePackedData_FromoaBasePackedData(oaBasePackedData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBasePackedData_Type.tp_alloc(&PyoaBasePackedData_Type,0);
        if (bself == NULL) return bself;
        PyoaBasePackedDataObject* self = (PyoaBasePackedDataObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBasePackedData_grid_doc[] = 
"Class: oaBasePackedData, Function: grid\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4& grid()\n"
"    Signature: grid|ref-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function grid\n"
;

static PyObject*
oaBasePackedData_grid(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBasePackedData data;
    int convert_status=PyoaBasePackedData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBasePackedDataObject* self=(PyoaBasePackedDataObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4* result=&(data.DataCall()->grid());
        return PyoaUInt4_FromoaUInt4(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBasePackedData_assign_doc[] = 
"Class: oaBasePackedData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBasePackedData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBasePackedData data;
  int convert_status=PyoaBasePackedData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBasePackedData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBasePackedData_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBasePackedData_methodlist[] = {
    {"grid",(PyCFunction)oaBasePackedData_grid,METH_VARARGS,oaBasePackedData_grid_doc},
    {"assign",(PyCFunction)oaBasePackedData_tp_assign,METH_VARARGS,oaBasePackedData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBasePackedData_doc[] = 
"Class: oaBasePackedData\n"
"  This class is not used directly by applications.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaBasePackedData()\n"
"    Signature: oaBasePackedData||simple-oaUInt4,\n"
"    Constructor oaBasePackedData\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaBasePackedData(oaUInt4 gridIn)\n"
"    Signature: oaBasePackedData||simple-oaUInt4,\n"
"    Constructor oaBasePackedData\n"
"  Paramegers: (oaBasePackedData)\n"
"    Calls: (const oaBasePackedData&)\n"
"    Signature: oaBasePackedData||cref-oaBasePackedData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBasePackedData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBasePackedData",
    sizeof(PyoaBasePackedDataObject),
    0,
    (destructor)oaBasePackedData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBasePackedData_tp_compare,	/* tp_compare */
    (reprfunc)oaBasePackedData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBasePackedData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBasePackedData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBasePackedData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBasePackedData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBasePackedData_Type)<0) {
      printf("** PyType_Ready failed for: oaBasePackedData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBasePackedData",
           (PyObject*)(&PyoaBasePackedData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBasePackedData\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBitInstObject* self = (PyoaBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBitInst)
    {
        PyParamoaBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBitInst_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBitInst, Choices are:\n"
        "    (oaBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBitInst_tp_dealloc(PyoaBitInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBitInst_tp_repr(PyObject *ob)
{
    PyParamoaBitInst value;
    int convert_status=PyoaBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaBitInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[31];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaBitInst::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBitInst v1;
    PyParamoaBitInst v2;
    int convert_status1=PyoaBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBitInst_Convert(PyObject* ob,PyParamoaBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaBitInst_Check(ob)) {
        result->SetData( (oaBitInst**) ((PyoaBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBitInst_FromoaBitInst(oaBitInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaBitInst* data=*value;
        if (data->getType()==oacVectorInstBitType) return PyoaVectorInstBit_FromoaVectorInstBit((oaVectorInstBit**)value,borrow,lock);
        if (data->getType()==oacScalarInstType) return PyoaScalarInst_FromoaScalarInst((oaScalarInst**)value,borrow,lock);
        if (data->getType()==oacArrayInstType) return PyoaArrayInst_FromoaArrayInst((oaArrayInst**)value,borrow,lock);
        PyObject* bself = PyoaBitInst_Type.tp_alloc(&PyoaBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaBitInstObject* self = (PyoaBitInstObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaBitInst_FromoaBitInst(oaBitInst* data)
{
    if (data) {
        if (data->getType()==oacVectorInstBitType) return PyoaVectorInstBit_FromoaVectorInstBit((oaVectorInstBit*)data);
        if (data->getType()==oacScalarInstType) return PyoaScalarInst_FromoaScalarInst((oaScalarInst*)data);
        if (data->getType()==oacArrayInstType) return PyoaArrayInst_FromoaArrayInst((oaArrayInst*)data);
       PyObject* bself = PyoaBitInst_Type.tp_alloc(&PyoaBitInst_Type,0);
       if (bself == NULL) return bself;
       PyoaBitInstObject* self = (PyoaBitInstObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitInst_doc[] = 
"Class: oaBitInst\n"
"  The oaBitInst class is the base class for scalar instances of a design master.\n"
"Constructors:\n"
"  Paramegers: (oaBitInst)\n"
"    Calls: (const oaBitInst&)\n"
"    Signature: oaBitInst||cref-oaBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBitInst",
    sizeof(PyoaBitInstObject),
    0,
    (destructor)oaBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBitInst",
           (PyObject*)(&PyoaBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBitInst\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBitNetObject* self = (PyoaBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBitNet)
    {
        PyParamoaBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBitNet_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBitNet, Choices are:\n"
        "    (oaBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBitNet_tp_dealloc(PyoaBitNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBitNet_tp_repr(PyObject *ob)
{
    PyParamoaBitNet value;
    int convert_status=PyoaBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaBitNet::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[30];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaBitNet::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBitNet v1;
    PyParamoaBitNet v2;
    int convert_status1=PyoaBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBitNet_Convert(PyObject* ob,PyParamoaBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaBitNet_Check(ob)) {
        result->SetData( (oaBitNet**) ((PyoaBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBitNet_FromoaBitNet(oaBitNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaBitNet* data=*value;
        if (data->getType()==oacScalarNetType) return PyoaScalarNet_FromoaScalarNet((oaScalarNet**)value,borrow,lock);
        if (data->getType()==oacBusNetBitType) return PyoaBusNetBit_FromoaBusNetBit((oaBusNetBit**)value,borrow,lock);
        PyObject* bself = PyoaBitNet_Type.tp_alloc(&PyoaBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaBitNetObject* self = (PyoaBitNetObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaBitNet_FromoaBitNet(oaBitNet* data)
{
    if (data) {
        if (data->getType()==oacScalarNetType) return PyoaScalarNet_FromoaScalarNet((oaScalarNet*)data);
        if (data->getType()==oacBusNetBitType) return PyoaBusNetBit_FromoaBusNetBit((oaBusNetBit*)data);
       PyObject* bself = PyoaBitNet_Type.tp_alloc(&PyoaBitNet_Type,0);
       if (bself == NULL) return bself;
       PyoaBitNetObject* self = (PyoaBitNetObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitNet_breakEquivalence_doc[] = 
"Class: oaBitNet, Function: breakEquivalence\n"
"  Paramegers: ()\n"
"    Calls: void breakEquivalence()\n"
"    Signature: breakEquivalence|void-void|\n"
"    BrowseData: 0\n"
"    This function breaks the net equivalence between this net and all other nets that are equivalent.\n"
"    oacNetHasNoEquivNet\n"
;

static PyObject*
oaBitNet_breakEquivalence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->breakEquivalence();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getConnStatus_doc[] = 
"Class: oaBitNet, Function: getConnStatus\n"
"  Paramegers: ()\n"
"    Calls: oaConnStatus getConnStatus() const\n"
"    Signature: getConnStatus|simple-oaConnStatus|\n"
"    BrowseData: 1\n"
"    This function returns the setting for this net that determines if optimization is allowed to change its connectivity.\n"
;

static PyObject*
oaBitNet_getConnStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConnStatus* result= new oaConnStatus(data.DataCall()->getConnStatus());
        return PyoaConnStatus_FromoaConnStatus(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getConnectDef_doc[] = 
"Class: oaBitNet, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaNetConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaNetConnectDef|\n"
"    BrowseData: 1\n"
"    This function returns the connection definition associated with this net if there is one. Otherwise, NULL is returned.\n"
;

static PyObject*
oaBitNet_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaNetConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaNetConnectDef_FromoaNetConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getEquivalentNets_doc[] = 
"Class: oaBitNet, Function: getEquivalentNets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBitNet_oaBitNet getEquivalentNets() const\n"
"    Signature: getEquivalentNets|simple-oaCollection_oaBitNet_oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaBitNet_getEquivalentNets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBitNet_oaBitNet* result= new oaCollection_oaBitNet_oaBitNet(data.DataCall()->getEquivalentNets());
        return PyoaCollection_oaBitNet_oaBitNet_FromoaCollection_oaBitNet_oaBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getEquivalentNetsIter_doc[] = 
"Class: oaBitNet, Function: getEquivalentNetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaBitNet getEquivalentNetsIter() const\n"
"    Signature: getEquivalentNetsIter|simple-oaIter_oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaBitNet_getEquivalentNetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaBitNet* result= new oaIter_oaBitNet(data.DataCall()->getEquivalentNets());
        return PyoaIter_oaBitNet_FromoaIter_oaBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getOriginal_doc[] = 
"Class: oaBitNet, Function: getOriginal\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getOriginal() const\n"
"    Signature: getOriginal|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the original net for this bit net.\n"
;

static PyObject*
oaBitNet_getOriginal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getOriginal());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getParasiticConfidence_doc[] = 
"Class: oaBitNet, Function: getParasiticConfidence\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void getParasiticConfidence(oaUInt4& minValue,oaUInt4& maxValue) const\n"
"    Signature: getParasiticConfidence|void-void|ref-oaUInt4,ref-oaUInt4,\n"
"    BrowseData: 0,oaUInt4,oaUInt4\n"
"    This function returns the minimum and maximum parasitic confidence values. These values are can be between 0 and 100.\n"
"    minValue\n"
"    A reference to an integer to be populated with the minimum value\n"
"    maxValue\n"
"    A reference to an integer to be populated with the maximum value\n"
;

static PyObject*
oaBitNet_getParasiticConfidence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->getParasiticConfidence(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getPreferredEquivalent_doc[] = 
"Class: oaBitNet, Function: getPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getPreferredEquivalent() const\n"
"    Signature: getPreferredEquivalent|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the preferred equivalent net associated with this net. If this net does not have any equivalents, the net itself is returned since it is considered the preferred equivalent of itself.\n"
;

static PyObject*
oaBitNet_getPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getPreferredEquivalent());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getRoutePattern_doc[] = 
"Class: oaBitNet, Function: getRoutePattern\n"
"  Paramegers: ()\n"
"    Calls: oaRoutePattern getRoutePattern() const\n"
"    Signature: getRoutePattern|simple-oaRoutePattern|\n"
"    BrowseData: 1\n"
"    This function returns the routePattern value of this net.\n"
;

static PyObject*
oaBitNet_getRoutePattern(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRoutePattern* result= new oaRoutePattern(data.DataCall()->getRoutePattern());
        return PyoaRoutePattern_FromoaRoutePattern(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getShieldNet1_doc[] = 
"Class: oaBitNet, Function: getShieldNet1\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getShieldNet1() const\n"
"    Signature: getShieldNet1|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    Nets can have up to 2 other nets that will be routed in parallel with it to shield it from signal noise. Shield nets are usually power or ground nets. This function returns the first shield net for this net if it exists.\n"
"    When an oaRoute is created on that shield net that will provide this shielding then the route will point to this net as its shielded net. See oaRoute::getShielding1 for that relationship.\n"
;

static PyObject*
oaBitNet_getShieldNet1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getShieldNet1());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getShieldNet2_doc[] = 
"Class: oaBitNet, Function: getShieldNet2\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getShieldNet2() const\n"
"    Signature: getShieldNet2|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the second shield net for this net if it exists.\n"
;

static PyObject*
oaBitNet_getShieldNet2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getShieldNet2());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_getVoltage_doc[] = 
"Class: oaBitNet, Function: getVoltage\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getVoltage() const\n"
"    Signature: getVoltage|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the voltage for this net.\n"
;

static PyObject*
oaBitNet_getVoltage(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getVoltage());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_isOriginal_doc[] = 
"Class: oaBitNet, Function: isOriginal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOriginal() const\n"
"    Signature: isOriginal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this net is an original net.\n"
;

static PyObject*
oaBitNet_isOriginal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOriginal());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_isPreferredEquivalent_doc[] = 
"Class: oaBitNet, Function: isPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isPreferredEquivalent() const\n"
"    Signature: isPreferredEquivalent|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this net is the preferred equivalent net in a set of equivalent nets. true is also returned if the net does not have any equivalents.\n"
;

static PyObject*
oaBitNet_isPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isPreferredEquivalent());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_makeEquivalent_doc[] = 
"Class: oaBitNet, Function: makeEquivalent\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void makeEquivalent(oaBitNet* equivNet)\n"
"    Signature: makeEquivalent|void-void|ptr-oaBitNet,\n"
"    This function sets this net and the specified net as equivalent.\n"
"    equivNet\n"
"    The net to establish equivalency with.\n"
"    oacInvalidNet\n"
"    oacNetEquivNetNotInSameBlock\n"
"    oacTermMustJoinSameNet\n"
;

static PyObject*
oaBitNet_makeEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->makeEquivalent(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setConnStatus_doc[] = 
"Class: oaBitNet, Function: setConnStatus\n"
"  Paramegers: (oaConnStatus)\n"
"    Calls: void setConnStatus(oaConnStatus status)\n"
"    Signature: setConnStatus|void-void|simple-oaConnStatus,\n"
"    This function sets the connectivity status for this net which determines if optimization is allowed to change its connectivity.\n"
"    status\n"
"    The new oaConnStatus value for this net.\n"
;

static PyObject*
oaBitNet_setConnStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaConnStatus p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConnStatus_Convert,&p1)) {
        data.DataCall()->setConnStatus(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setOriginal_doc[] = 
"Class: oaBitNet, Function: setOriginal\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void setOriginal(oaBitNet* original)\n"
"    Signature: setOriginal|void-void|ptr-oaBitNet,\n"
"    This function sets the original net for this bit net. This net becomes a derived net of the original net. Setting a net's original net to itself does nothing. Setting the original net to NULL will unset the original net.\n"
"    original\n"
"    The net that this net will be considered derived from\n"
"    oacOriginalNetNotInSameBlock\n"
;

static PyObject*
oaBitNet_setOriginal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setOriginal(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setParasiticConfidence_doc[] = 
"Class: oaBitNet, Function: setParasiticConfidence\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setParasiticConfidence(oaUInt4 value)\n"
"    Signature: setParasiticConfidence|void-void|simple-oaUInt4,\n"
"    This function sets the minimum and maximum parasitic confidence values for this net. Since only one value is specified, the minimum and maximum values are the same. The parasitic confidence values must be between 0 and 100.\n"
"    value\n"
"    The value to the confidence values to for this net.\n"
"    oacInvalidParasiticConfidenceValue\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void setParasiticConfidence(oaUInt4 minValue,oaUInt4 maxValue)\n"
"    Signature: setParasiticConfidence|void-void|simple-oaUInt4,simple-oaUInt4,\n"
"    This function sets the minimum and maximum parasitic confidence values for this net. These values must be between 0 and 100.\n"
"    minValue\n"
"    A reference to an integer to be populated with the minimum value\n"
"    maxValue\n"
"    A reference to an integer to be populated with the maximum value\n"
"    oacInvalidParasiticConfidenceValue\n"
;

static PyObject*
oaBitNet_setParasiticConfidence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            data.DataCall()->setParasiticConfidence(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaUInt4)
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            data.DataCall()->setParasiticConfidence(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaBitNet, function: setParasiticConfidence, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setPreferredEquivalent_doc[] = 
"Class: oaBitNet, Function: setPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: void setPreferredEquivalent()\n"
"    Signature: setPreferredEquivalent|void-void|\n"
"    BrowseData: 0\n"
"    This function sets this net to the preferred net of a set of equivalent nets. If this net does not have any equivalents, this function does nothing.\n"
;

static PyObject*
oaBitNet_setPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->setPreferredEquivalent();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setRoutePattern_doc[] = 
"Class: oaBitNet, Function: setRoutePattern\n"
"  Paramegers: (oaRoutePattern)\n"
"    Calls: void setRoutePattern(oaRoutePattern routePattern)\n"
"    Signature: setRoutePattern|void-void|simple-oaRoutePattern,\n"
"    This function sets the routePattern for this net to the specified value.\n"
"    routePattern\n"
"    The new oaRoutePattern value for this net.\n"
;

static PyObject*
oaBitNet_setRoutePattern(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRoutePattern p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoutePattern_Convert,&p1)) {
        data.DataCall()->setRoutePattern(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setShieldNet1_doc[] = 
"Class: oaBitNet, Function: setShieldNet1\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void setShieldNet1(oaBitNet* shieldNet)\n"
"    Signature: setShieldNet1|void-void|ptr-oaBitNet,\n"
"    This function sets shield net 1 for this net to the specified net. Setting the shield net to NULL unsets the shield net. A net can have zero, one, or two shield nets.\n"
"    shieldNet\n"
"    The new shield one net value for this net.\n"
"    oacShieldNetNotInSameBlock\n"
;

static PyObject*
oaBitNet_setShieldNet1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setShieldNet1(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setShieldNet2_doc[] = 
"Class: oaBitNet, Function: setShieldNet2\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void setShieldNet2(oaBitNet* shieldNet)\n"
"    Signature: setShieldNet2|void-void|ptr-oaBitNet,\n"
"    This function sets shield net 2 for this net to the specified net. Setting the shield net to NULL unsets the shield net. A net can have zero, one, or two shield nets.\n"
"    shieldNet\n"
"    The new shield two net value for this net.\n"
"    oacShieldNetNotInSameBlock\n"
;

static PyObject*
oaBitNet_setShieldNet2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setShieldNet2(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_setVoltage_doc[] = 
"Class: oaBitNet, Function: setVoltage\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setVoltage(oaFloat voltage)\n"
"    Signature: setVoltage|void-void|simple-oaFloat,\n"
"    This function sets the voltage for this net to the specified value.\n"
"    voltage\n"
"    The new voltage value for this net.\n"
;

static PyObject*
oaBitNet_setVoltage(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitNetObject* self=(PyoaBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setVoltage(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitNet_isNull_doc[] =
"Class: oaBitNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaBitNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaBitNet data;
    int convert_status=PyoaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaBitNet_assign_doc[] = 
"Class: oaBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBitNet data;
  int convert_status=PyoaBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBitNet_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBitNet_methodlist[] = {
    {"breakEquivalence",(PyCFunction)oaBitNet_breakEquivalence,METH_VARARGS,oaBitNet_breakEquivalence_doc},
    {"getConnStatus",(PyCFunction)oaBitNet_getConnStatus,METH_VARARGS,oaBitNet_getConnStatus_doc},
    {"getConnectDef",(PyCFunction)oaBitNet_getConnectDef,METH_VARARGS,oaBitNet_getConnectDef_doc},
    {"getEquivalentNets",(PyCFunction)oaBitNet_getEquivalentNets,METH_VARARGS,oaBitNet_getEquivalentNets_doc},
    {"getEquivalentNetsIter",(PyCFunction)oaBitNet_getEquivalentNetsIter,METH_VARARGS,oaBitNet_getEquivalentNetsIter_doc},
    {"getOriginal",(PyCFunction)oaBitNet_getOriginal,METH_VARARGS,oaBitNet_getOriginal_doc},
    {"getParasiticConfidence",(PyCFunction)oaBitNet_getParasiticConfidence,METH_VARARGS,oaBitNet_getParasiticConfidence_doc},
    {"getPreferredEquivalent",(PyCFunction)oaBitNet_getPreferredEquivalent,METH_VARARGS,oaBitNet_getPreferredEquivalent_doc},
    {"getRoutePattern",(PyCFunction)oaBitNet_getRoutePattern,METH_VARARGS,oaBitNet_getRoutePattern_doc},
    {"getShieldNet1",(PyCFunction)oaBitNet_getShieldNet1,METH_VARARGS,oaBitNet_getShieldNet1_doc},
    {"getShieldNet2",(PyCFunction)oaBitNet_getShieldNet2,METH_VARARGS,oaBitNet_getShieldNet2_doc},
    {"getVoltage",(PyCFunction)oaBitNet_getVoltage,METH_VARARGS,oaBitNet_getVoltage_doc},
    {"isOriginal",(PyCFunction)oaBitNet_isOriginal,METH_VARARGS,oaBitNet_isOriginal_doc},
    {"isPreferredEquivalent",(PyCFunction)oaBitNet_isPreferredEquivalent,METH_VARARGS,oaBitNet_isPreferredEquivalent_doc},
    {"makeEquivalent",(PyCFunction)oaBitNet_makeEquivalent,METH_VARARGS,oaBitNet_makeEquivalent_doc},
    {"setConnStatus",(PyCFunction)oaBitNet_setConnStatus,METH_VARARGS,oaBitNet_setConnStatus_doc},
    {"setOriginal",(PyCFunction)oaBitNet_setOriginal,METH_VARARGS,oaBitNet_setOriginal_doc},
    {"setParasiticConfidence",(PyCFunction)oaBitNet_setParasiticConfidence,METH_VARARGS,oaBitNet_setParasiticConfidence_doc},
    {"setPreferredEquivalent",(PyCFunction)oaBitNet_setPreferredEquivalent,METH_VARARGS,oaBitNet_setPreferredEquivalent_doc},
    {"setRoutePattern",(PyCFunction)oaBitNet_setRoutePattern,METH_VARARGS,oaBitNet_setRoutePattern_doc},
    {"setShieldNet1",(PyCFunction)oaBitNet_setShieldNet1,METH_VARARGS,oaBitNet_setShieldNet1_doc},
    {"setShieldNet2",(PyCFunction)oaBitNet_setShieldNet2,METH_VARARGS,oaBitNet_setShieldNet2_doc},
    {"setVoltage",(PyCFunction)oaBitNet_setVoltage,METH_VARARGS,oaBitNet_setVoltage_doc},
    {"isNull",(PyCFunction)oaBitNet_tp_isNull,METH_VARARGS,oaBitNet_isNull_doc},
    {"assign",(PyCFunction)oaBitNet_tp_assign,METH_VARARGS,oaBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitNet_doc[] = 
"Class: oaBitNet\n"
"  The oaBitNet class is the base class for single-bit nets that are part of the design's physical description.\n"
"  You can have two or more bitNets that are equivalent. Equivalent bitNets are traversed separately or logically as the same net.\n"
"  You can create associate a connection definition, oaNetConnectDef , with a bitNet.\n"
"Constructors:\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: (const oaBitNet&)\n"
"    Signature: oaBitNet||cref-oaBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBitNet",
    sizeof(PyoaBitNetObject),
    0,
    (destructor)oaBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBitNet",
           (PyObject*)(&PyoaBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBitNet\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBitOrder
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBitOrder_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBitOrder_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBitOrderObject* self = (PyoaBitOrderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBitOrderEnum)
    {
        PyParamoaBitOrderEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBitOrderEnum_Convert,&p1)) {
            self->value =  new oaBitOrder(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaBitOrder(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBitOrder)
    {
        PyParamoaBitOrder p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBitOrder_Convert,&p1)) {
            self->value= new oaBitOrder(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBitOrder, Choices are:\n"
        "    (oaBitOrderEnum)\n"
        "    (oaString)\n"
        "    (oaBitOrder)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBitOrder_tp_dealloc(PyoaBitOrderObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBitOrder_tp_repr(PyObject *ob)
{
    PyParamoaBitOrder value;
    int convert_status=PyoaBitOrder_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[32];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaBitOrder::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBitOrder_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBitOrder v1;
    PyParamoaBitOrder v2;
    int convert_status1=PyoaBitOrder_Convert(ob1,&v1);
    int convert_status2=PyoaBitOrder_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBitOrder_Convert(PyObject* ob,PyParamoaBitOrder* result)
{
    if (ob == NULL) return 1;
    if (PyoaBitOrder_Check(ob)) {
        result->SetData(  ((PyoaBitOrderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBitOrder Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBitOrder_FromoaBitOrder(oaBitOrder* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaBitOrder_Type.tp_alloc(&PyoaBitOrder_Type,0);
        if (bself == NULL) return bself;
        PyoaBitOrderObject* self = (PyoaBitOrderObject*)bself;
        self->value =  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitOrder_getName_doc[] = 
"Class: oaBitOrder, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaBitOrderEnum value.\n"
;

static PyObject*
oaBitOrder_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitOrder data;
    int convert_status=PyoaBitOrder_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitOrderObject* self=(PyoaBitOrderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaString result= (data.DataCall()->getName());
        return PyoaString_FromoaString(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitOrder_oaBitOrderEnum_doc[] = 
"Class: oaBitOrder, Function: oaBitOrderEnum\n"
"  Paramegers: ()\n"
"    Calls: oaBitOrderEnum oaBitOrderEnum() const\n"
"    Signature: operator oaBitOrderEnum|simple-oaBitOrderEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaBitOrder into its corresponding #oaBitOrderEnum value.\n"
;

static PyObject*
oaBitOrder_oaBitOrderEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitOrder data;
    int convert_status=PyoaBitOrder_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitOrderObject* self=(PyoaBitOrderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBitOrderEnum result= (data.DataCall()->operator oaBitOrderEnum());
        return PyoaBitOrderEnum_FromoaBitOrderEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaBitOrder_assign_doc[] = 
"Class: oaBitOrder, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBitOrder_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBitOrder data;
  int convert_status=PyoaBitOrder_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBitOrder p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBitOrder_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBitOrder_methodlist[] = {
    {"getName",(PyCFunction)oaBitOrder_getName,METH_VARARGS,oaBitOrder_getName_doc},
    {"oaBitOrderEnum",(PyCFunction)oaBitOrder_oaBitOrderEnum,METH_VARARGS,oaBitOrder_oaBitOrderEnum_doc},
    {"assign",(PyCFunction)oaBitOrder_tp_assign,METH_VARARGS,oaBitOrder_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitOrder_doc[] = 
"Class: oaBitOrder\n"
"  The oaBitOrder class encapsulates the enumerated values that specify the bit order of a busNet definition.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaBitOrderEnum\n"
"Constructors:\n"
"  Paramegers: (oaBitOrderEnum)\n"
"    Calls: oaBitOrder(oaBitOrderEnum valueIn)\n"
"    Signature: oaBitOrder||simple-oaBitOrderEnum,\n"
"    This function constructs an instance of an oaBitOrder object using the specified #oaBitOrderEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaBitOrder(const oaString& name)\n"
"    Signature: oaBitOrder||cref-oaString,\n"
"    This function constructs an instance of an oaBitOrder object using the #oaBitOrderEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaBitOrderEnum.\n"
"    oacInvalidBitOrderName\n"
"  Paramegers: (oaBitOrder)\n"
"    Calls: (const oaBitOrder&)\n"
"    Signature: oaBitOrder||cref-oaBitOrder,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBitOrder_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBitOrder",
    sizeof(PyoaBitOrderObject),
    0,
    (destructor)oaBitOrder_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBitOrder_tp_compare,	/* tp_compare */
    (reprfunc)oaBitOrder_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBitOrder_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBitOrder_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBitOrder_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBitOrder_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBitOrder_Type)<0) {
      printf("** PyType_Ready failed for: oaBitOrder\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBitOrder",
           (PyObject*)(&PyoaBitOrder_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBitOrder\n");
       return -1;
    }
    return 0;
}


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
// Wrapper Implementation for Class: oaBitOrderEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaBitOrderEnum_Convert(PyObject* ob,PyParamoaBitOrderEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNoneBitOrder")==0) { result->SetData(oacNoneBitOrder); return 1;}
        if (strcasecmp(str,"oacAscendingBitOrder")==0) { result->SetData(oacAscendingBitOrder); return 1;}
        if (strcasecmp(str,"oacDescendingBitOrder")==0) { result->SetData(oacDescendingBitOrder); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaBitOrderEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBitOrderEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaBitOrderEnum_FromoaBitOrderEnum(oaBitOrderEnum ob)
{
    if (ob==oacNoneBitOrder) return PyString_FromString("oacNoneBitOrder");
    if (ob==oacAscendingBitOrder) return PyString_FromString("oacAscendingBitOrder");
    if (ob==oacDescendingBitOrder) return PyString_FromString("oacDescendingBitOrder");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaBitOrderEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaBitOrderEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaBitOrderEnum_FromoaBitOrderEnum(oaBitOrderEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaBitOrderEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaBitOrderEnum_doc[] =
"Type convert function for enum: oaBitOrderEnum";
                               
static PyMethodDef PyoaBitOrderEnum_method =
  {"oaBitOrderEnum",(PyCFunction)PyoaBitOrderEnum_TypeFunction,METH_VARARGS,oaBitOrderEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaBitOrderEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNoneBitOrder");
    PyDict_SetItemString(mod_dict,"oacNoneBitOrder",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAscendingBitOrder");
    PyDict_SetItemString(mod_dict,"oacAscendingBitOrder",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDescendingBitOrder");
    PyDict_SetItemString(mod_dict,"oacDescendingBitOrder",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaBitOrderEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaBitOrderEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaBitOrderEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}

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
// Wrapper Implementation for Class: oaBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaBitTermObject* self = (PyoaBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBitTerm)
    {
        PyParamoaBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaBitTerm_Convert,&p1)) {
            self->data=p1.Data();
            self->value=&(self->data);
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,(char*)"")) {
          self->data=NULL;
          self->value=&(self->data);
          return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaBitTerm, Choices are:\n"
        "    (oaBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaBitTerm_tp_dealloc(PyoaBitTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaBitTerm value;
    int convert_status=PyoaBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaBitTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[31];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaBitTerm::");
        buffer+=oaString(addr);
        buffer+=oaString("::");
        buffer+=oaString(sresult);
        buffer+=oaString(">");
        result=PyString_FromString((char*)(const char*)buffer);
    
    }
    return result;
}
        
// ------------------------------------------------------------------
static int
oaBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaBitTerm v1;
    PyParamoaBitTerm v2;
    int convert_status1=PyoaBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaBitTerm_Convert(PyObject* ob,PyParamoaBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaBitTerm_Check(ob)) {
        result->SetData( (oaBitTerm**) ((PyoaBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaBitTerm_FromoaBitTerm(oaBitTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaBitTerm* data=*value;
        if (data->getType()==oacScalarTermType) return PyoaScalarTerm_FromoaScalarTerm((oaScalarTerm**)value,borrow,lock);
        if (data->getType()==oacBusTermBitType) return PyoaBusTermBit_FromoaBusTermBit((oaBusTermBit**)value,borrow,lock);
        PyObject* bself = PyoaBitTerm_Type.tp_alloc(&PyoaBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaBitTermObject* self = (PyoaBitTermObject*)bself;
        self->value = (oaObject**) value;
        self->data = NULL;
        self->locks = NULL;
        self->borrow = 0; // Ignore borrow flag, since we copied
       if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}
// ------------------------------------------------------------------
PyObject* PyoaBitTerm_FromoaBitTerm(oaBitTerm* data)
{
    if (data) {
        if (data->getType()==oacScalarTermType) return PyoaScalarTerm_FromoaScalarTerm((oaScalarTerm*)data);
        if (data->getType()==oacBusTermBitType) return PyoaBusTermBit_FromoaBusTermBit((oaBusTermBit*)data);
       PyObject* bself = PyoaBitTerm_Type.tp_alloc(&PyoaBitTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaBitTermObject* self = (PyoaBitTermObject*)bself;
       self->data = (oaObject*) data;
       self->value = &(self->data);
       self->borrow = 0; 
       self->locks = NULL;
       return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitTerm_getAntennaData_doc[] = 
"Class: oaBitTerm, Function: getAntennaData\n"
"  Paramegers: (oaAntennaData)\n"
"    Calls: void getAntennaData(oaAntennaData& data) const\n"
"    Signature: getAntennaData|void-void|ref-oaAntennaData,simple-oaAntennaModel,\n"
"    BrowseData: 0,oaAntennaData\n"
"    This function retrieves the antennaData associated with this terminal for the specified antennaModel. The given data is filled in if the terminal has the specified antennaData. If the terminal has no corresponding antennaData, data is set to have zero values.\n"
"    data\n"
"    Returns the antenna data associated with this terminal\n"
"    model\n"
"    Specifies which antenna data model to retrieve\n"
"  Paramegers: (oaAntennaData,oaAntennaModel)\n"
"    Calls: void getAntennaData(oaAntennaData& data,oaAntennaModel model) const\n"
"    Signature: getAntennaData|void-void|ref-oaAntennaData,simple-oaAntennaModel,\n"
"    This function retrieves the antennaData associated with this terminal for the specified antennaModel. The given data is filled in if the terminal has the specified antennaData. If the terminal has no corresponding antennaData, data is set to have zero values.\n"
"    data\n"
"    Returns the antenna data associated with this terminal\n"
"    model\n"
"    Specifies which antenna data model to retrieve\n"
;

static PyObject*
oaBitTerm_getAntennaData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaAntennaData)
    {
        PyParamoaAntennaData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAntennaData_Convert,&p1)) {
            data.DataCall()->getAntennaData(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaAntennaData,oaAntennaModel)
    {
        PyParamoaAntennaData p1;
        PyParamoaAntennaModel p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaAntennaData_Convert,&p1,
              &PyoaAntennaModel_Convert,&p2)) {
            data.DataCall()->getAntennaData(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaBitTerm, function: getAntennaData, Choices are:\n"
        "    (oaAntennaData)\n"
        "    (oaAntennaData,oaAntennaModel)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getConnectDef_doc[] = 
"Class: oaBitTerm, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaTermConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaTermConnectDef|\n"
"    BrowseData: 1\n"
"    This function returns the connection definition associated with this terminal, if a connection definition exists. If the terminal does not have a connection definition, NULL is returned.\n"
"    A pointer to an oaTermConnectDef if it exists, otherwise NULL\n"
;

static PyObject*
oaBitTerm_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaTermConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaTermConnectDef_FromoaTermConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getGroundSensitivity_doc[] = 
"Class: oaBitTerm, Function: getGroundSensitivity\n"
"  Paramegers: ()\n"
"    Calls: oaBitTerm* getGroundSensitivity() const\n"
"    Signature: getGroundSensitivity|ptr-oaBitTerm|\n"
"    BrowseData: 1\n"
"    This function returns the ground terminal to which this terminal is sensitized. If no ground sensitivity is set on this terminal, NULL is returned.\n"
"    A pointer to an oaBitTerm\n"
;

static PyObject*
oaBitTerm_getGroundSensitivity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitTermp result= (data.DataCall()->getGroundSensitivity());
        return PyoaBitTerm_FromoaBitTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getMustJoinTerms_doc[] = 
"Class: oaBitTerm, Function: getMustJoinTerms\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBitTerm_oaBitTerm getMustJoinTerms() const\n"
"    Signature: getMustJoinTerms|simple-oaCollection_oaBitTerm_oaBitTerm|\n"
"    BrowseData: 1\n"
"    This function returns the collection of terminals on this block that must be connected at a higher level of hierarchy to this terminal. The collection does not include this terminal, and will be empty if this terminal does not belong to a set of must-join terminals. See setMustJoin() for more information about MustJoin terminals.\n"
;

static PyObject*
oaBitTerm_getMustJoinTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBitTerm_oaBitTerm* result= new oaCollection_oaBitTerm_oaBitTerm(data.DataCall()->getMustJoinTerms());
        return PyoaCollection_oaBitTerm_oaBitTerm_FromoaCollection_oaBitTerm_oaBitTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getMustJoinTermsIter_doc[] = 
"Class: oaBitTerm, Function: getMustJoinTermsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaBitTerm getMustJoinTermsIter() const\n"
"    Signature: getMustJoinTermsIter|simple-oaIter_oaBitTerm|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of terminals on this block that must be connected at a higher level of hierarchy to this terminal. The collection does not include this terminal, and will be empty if this terminal does not belong to a set of must-join terminals. See setMustJoin() for more information about MustJoin terminals.\n"
;

static PyObject*
oaBitTerm_getMustJoinTermsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaBitTerm* result= new oaIter_oaBitTerm(data.DataCall()->getMustJoinTerms());
        return PyoaIter_oaBitTerm_FromoaIter_oaBitTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getPinConnectMethod_doc[] = 
"Class: oaBitTerm, Function: getPinConnectMethod\n"
"  Paramegers: ()\n"
"    Calls: oaPinConnectMethod getPinConnectMethod() const\n"
"    Signature: getPinConnectMethod|simple-oaPinConnectMethod|\n"
"    BrowseData: 1\n"
"    This function returns the pin connection method for this terminal.\n"
;

static PyObject*
oaBitTerm_getPinConnectMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPinConnectMethod* result= new oaPinConnectMethod(data.DataCall()->getPinConnectMethod());
        return PyoaPinConnectMethod_FromoaPinConnectMethod(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getRouteMethod_doc[] = 
"Class: oaBitTerm, Function: getRouteMethod\n"
"  Paramegers: ()\n"
"    Calls: oaRouteMethod getRouteMethod() const\n"
"    Signature: getRouteMethod|simple-oaRouteMethod|\n"
"    BrowseData: 1\n"
"    This function returns the route method of this terminal.\n"
;

static PyObject*
oaBitTerm_getRouteMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteMethod* result= new oaRouteMethod(data.DataCall()->getRouteMethod());
        return PyoaRouteMethod_FromoaRouteMethod(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_getSupplySensitivity_doc[] = 
"Class: oaBitTerm, Function: getSupplySensitivity\n"
"  Paramegers: ()\n"
"    Calls: oaBitTerm* getSupplySensitivity() const\n"
"    Signature: getSupplySensitivity|ptr-oaBitTerm|\n"
"    BrowseData: 1\n"
"    This function returns the supply terminal to which this terminal is sensitized. If no ground sensitivity is set on this terminal, NULL is returned.\n"
"    A pointer to an oaBitTerm\n"
;

static PyObject*
oaBitTerm_getSupplySensitivity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitTermp result= (data.DataCall()->getSupplySensitivity());
        return PyoaBitTerm_FromoaBitTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_isAntennaDataSet_doc[] = 
"Class: oaBitTerm, Function: isAntennaDataSet\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isAntennaDataSet() const\n"
"    Signature: isAntennaDataSet|simple-oaBoolean|simple-oaAntennaModel,\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating if this terminal has any antennaData associated with it for the specified oaAntennaModel .\n"
"    model\n"
"    Specifies the antenna model to query data for.\n"
"  Paramegers: (oaAntennaModel)\n"
"    Calls: oaBoolean isAntennaDataSet(oaAntennaModel model) const\n"
"    Signature: isAntennaDataSet|simple-oaBoolean|simple-oaAntennaModel,\n"
"    This function returns a boolean indicating if this terminal has any antennaData associated with it for the specified oaAntennaModel .\n"
"    model\n"
"    Specifies the antenna model to query data for.\n"
;

static PyObject*
oaBitTerm_isAntennaDataSet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaBoolean result= (data.DataCall()->isAntennaDataSet());
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaAntennaModel)
    {
        PyParamoaAntennaModel p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAntennaModel_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->isAntennaDataSet(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaBitTerm, function: isAntennaDataSet, Choices are:\n"
        "    ()\n"
        "    (oaAntennaModel)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setAntennaData_doc[] = 
"Class: oaBitTerm, Function: setAntennaData\n"
"  Paramegers: (oaAntennaData)\n"
"    Calls: void setAntennaData(const oaAntennaData& data)\n"
"    Signature: setAntennaData|void-void|cref-oaAntennaData,\n"
"    This function adds the given antennaData to this terminal. If this terminal already has corresponding antennaData, it is replaced. An exception is thrown if the terminal is implicit.\n"
"    data\n"
"    antenna data object to set on this terminal\n"
"    oacCannotSetAntennaDataOnImplicitTerm\n"
;

static PyObject*
oaBitTerm_setAntennaData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAntennaData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAntennaData_Convert,&p1)) {
        data.DataCall()->setAntennaData(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setGroundSensitivity_doc[] = 
"Class: oaBitTerm, Function: setGroundSensitivity\n"
"  Paramegers: (oaBitTerm)\n"
"    Calls: void setGroundSensitivity(const oaBitTerm* term)\n"
"    Signature: setGroundSensitivity|void-void|cptr-oaBitTerm,\n"
"    This function set the ground terminal to which this terminal is sensitized. A hierarchy of sensitivity terminals is not allowed.\n"
"    term\n"
"    The terminal to sensitize this terminal to.\n"
"    oacTermSensitivityTermNotInSameBlock\n"
;

static PyObject*
oaBitTerm_setGroundSensitivity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setGroundSensitivity(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setMustJoin_doc[] = 
"Class: oaBitTerm, Function: setMustJoin\n"
"  Paramegers: (oaBitTerm)\n"
"    Calls: void setMustJoin(const oaBitTerm* term)\n"
"    Signature: setMustJoin|void-void|cptr-oaBitTerm,\n"
"    This function specifies that this terminal needs to be connected at a higher level of hierarchy to the specified bit terminal. It adds this bit terminal to a set of MustJoin terminals where every terminal in the set can be accessed by oaTerm::getMustJoinTerms from every other terminal in the set.\n"
"    For example, take 3 terminals on distinct nets: termA , termB , and termC . If a caller calls setMustJoin from termA with termB as an argument, and calls it from termC with termB as an argument, then all 3 of these terminals are in the MustJoin set. The collection returned by getMustJoinTerms() from termA includes termB and termC . The collection from termB includes termA and termC and the collection from termC includes termA and termB .\n"
"    No two MustJoin terminals in a set can be on the same net or on two equivalent nets. In other words, all the nets with terminals in a MustJoin set must be disjoint. This also implies, though OpenAccess does not check this specific situation, that there should not be 2 different MustJoin sets that touch any given pair of nets. (It would require two nets that both have multiple terminals to create this illegal situation).\n"
"    MustJoins are used in standard cells where there is not enough room to make the desired connection in the design layers that are used for the standard cell design. The connection must be made by a router that will use other layers - usually a higher metal layer - for that purpose.\n"
"    In the case of MustJoins on terminals of nets with multiple terminals, the MustJoin indicates the specific terminals that are intended to be connected. The router that satisfies the MustJoin should not use a different terminal on the net unless it is capable of determining that its choice will be electrically correct.\n"
"    term\n"
"    The terminal to establish a must-join relationship with.\n"
"    oacTermMustJoinTermNotInSameBlock\n"
"    oacTermMustJoinCannotBeImplicit\n"
"    oacTermMustJoinSameNet\n"
;

static PyObject*
oaBitTerm_setMustJoin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setMustJoin(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setPinConnectMethod_doc[] = 
"Class: oaBitTerm, Function: setPinConnectMethod\n"
"  Paramegers: (oaPinConnectMethod)\n"
"    Calls: void setPinConnectMethod(oaPinConnectMethod method)\n"
"    Signature: setPinConnectMethod|void-void|simple-oaPinConnectMethod,\n"
"    This function sets the pin connection method for this terminal.\n"
"    method\n"
"    The new oaPinConnectMethod for this terminal.\n"
;

static PyObject*
oaBitTerm_setPinConnectMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPinConnectMethod p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPinConnectMethod_Convert,&p1)) {
        data.DataCall()->setPinConnectMethod(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setRouteMethod_doc[] = 
"Class: oaBitTerm, Function: setRouteMethod\n"
"  Paramegers: (oaRouteMethod)\n"
"    Calls: void setRouteMethod(oaRouteMethod routeMethod)\n"
"    Signature: setRouteMethod|void-void|simple-oaRouteMethod,\n"
"    This function changes the route method for this terminal.\n"
"    routeMethod\n"
"    The new oaRouteMethod value for this terminal.\n"
"    oacCannotSetRouteMethodOnImplicitTerm\n"
;

static PyObject*
oaBitTerm_setRouteMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteMethod p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteMethod_Convert,&p1)) {
        data.DataCall()->setRouteMethod(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_setSupplySensitivity_doc[] = 
"Class: oaBitTerm, Function: setSupplySensitivity\n"
"  Paramegers: (oaBitTerm)\n"
"    Calls: void setSupplySensitivity(const oaBitTerm* term)\n"
"    Signature: setSupplySensitivity|void-void|cptr-oaBitTerm,\n"
"    This function set the supply terminal to which this terminal is sensitized. A hierarchy of sensitivity terminals is not allowed.\n"
"    term\n"
"    The terminal to sensitize this terminal to.\n"
"    oacTermSensitivityTermNotInSameBlock\n"
;

static PyObject*
oaBitTerm_setSupplySensitivity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setSupplySensitivity(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_unsetAntennaData_doc[] = 
"Class: oaBitTerm, Function: unsetAntennaData\n"
"  Paramegers: ()\n"
"    Calls: void unsetAntennaData()\n"
"    Signature: unsetAntennaData|void-void|simple-oaAntennaModel,\n"
"    BrowseData: 0\n"
"    This function removes the antennaData associated with this terminal that corresponds to the specified antennaModel. If this terminal has no antennaData corresponding to the specified model, this function does nothing.\n"
"    model\n"
"    antenna model whose data, if any, will be removed from this term\n"
"  Paramegers: (oaAntennaModel)\n"
"    Calls: void unsetAntennaData(oaAntennaModel model)\n"
"    Signature: unsetAntennaData|void-void|simple-oaAntennaModel,\n"
"    This function removes the antennaData associated with this terminal that corresponds to the specified antennaModel. If this terminal has no antennaData corresponding to the specified model, this function does nothing.\n"
"    model\n"
"    antenna model whose data, if any, will be removed from this term\n"
;

static PyObject*
oaBitTerm_unsetAntennaData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            data.DataCall()->unsetAntennaData();
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaAntennaModel)
    {
        PyParamoaAntennaModel p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAntennaModel_Convert,&p1)) {
            data.DataCall()->unsetAntennaData(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaBitTerm, function: unsetAntennaData, Choices are:\n"
        "    ()\n"
        "    (oaAntennaModel)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_unsetMustJoin_doc[] = 
"Class: oaBitTerm, Function: unsetMustJoin\n"
"  Paramegers: ()\n"
"    Calls: void unsetMustJoin()\n"
"    Signature: unsetMustJoin|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this terminal from the set of terminals that must be externally connected. If this terminal is not part of such a set of terminals an exception is thrown.\n"
"    oacTermHasNoMustJoinTerm\n"
;

static PyObject*
oaBitTerm_unsetMustJoin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaBitTermObject* self=(PyoaBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->unsetMustJoin();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaBitTerm_isNull_doc[] =
"Class: oaBitTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaBitTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaBitTerm data;
    int convert_status=PyoaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaBitTerm_assign_doc[] = 
"Class: oaBitTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaBitTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaBitTerm data;
  int convert_status=PyoaBitTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaBitTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaBitTerm_Convert,&p1)) {
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
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaBitTerm_methodlist[] = {
    {"getAntennaData",(PyCFunction)oaBitTerm_getAntennaData,METH_VARARGS,oaBitTerm_getAntennaData_doc},
    {"getConnectDef",(PyCFunction)oaBitTerm_getConnectDef,METH_VARARGS,oaBitTerm_getConnectDef_doc},
    {"getGroundSensitivity",(PyCFunction)oaBitTerm_getGroundSensitivity,METH_VARARGS,oaBitTerm_getGroundSensitivity_doc},
    {"getMustJoinTerms",(PyCFunction)oaBitTerm_getMustJoinTerms,METH_VARARGS,oaBitTerm_getMustJoinTerms_doc},
    {"getMustJoinTermsIter",(PyCFunction)oaBitTerm_getMustJoinTermsIter,METH_VARARGS,oaBitTerm_getMustJoinTermsIter_doc},
    {"getPinConnectMethod",(PyCFunction)oaBitTerm_getPinConnectMethod,METH_VARARGS,oaBitTerm_getPinConnectMethod_doc},
    {"getRouteMethod",(PyCFunction)oaBitTerm_getRouteMethod,METH_VARARGS,oaBitTerm_getRouteMethod_doc},
    {"getSupplySensitivity",(PyCFunction)oaBitTerm_getSupplySensitivity,METH_VARARGS,oaBitTerm_getSupplySensitivity_doc},
    {"isAntennaDataSet",(PyCFunction)oaBitTerm_isAntennaDataSet,METH_VARARGS,oaBitTerm_isAntennaDataSet_doc},
    {"setAntennaData",(PyCFunction)oaBitTerm_setAntennaData,METH_VARARGS,oaBitTerm_setAntennaData_doc},
    {"setGroundSensitivity",(PyCFunction)oaBitTerm_setGroundSensitivity,METH_VARARGS,oaBitTerm_setGroundSensitivity_doc},
    {"setMustJoin",(PyCFunction)oaBitTerm_setMustJoin,METH_VARARGS,oaBitTerm_setMustJoin_doc},
    {"setPinConnectMethod",(PyCFunction)oaBitTerm_setPinConnectMethod,METH_VARARGS,oaBitTerm_setPinConnectMethod_doc},
    {"setRouteMethod",(PyCFunction)oaBitTerm_setRouteMethod,METH_VARARGS,oaBitTerm_setRouteMethod_doc},
    {"setSupplySensitivity",(PyCFunction)oaBitTerm_setSupplySensitivity,METH_VARARGS,oaBitTerm_setSupplySensitivity_doc},
    {"unsetAntennaData",(PyCFunction)oaBitTerm_unsetAntennaData,METH_VARARGS,oaBitTerm_unsetAntennaData_doc},
    {"unsetMustJoin",(PyCFunction)oaBitTerm_unsetMustJoin,METH_VARARGS,oaBitTerm_unsetMustJoin_doc},
    {"isNull",(PyCFunction)oaBitTerm_tp_isNull,METH_VARARGS,oaBitTerm_isNull_doc},
    {"assign",(PyCFunction)oaBitTerm_tp_assign,METH_VARARGS,oaBitTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaBitTerm_doc[] = 
"Class: oaBitTerm\n"
"  The oaBitTerm class is the base class for single-bit terminals that are part of the design's physical description.\n"
"  You can create associate a connection definition, oaTermConnectDef , with a bitTerm.\n"
"Constructors:\n"
"  Paramegers: (oaBitTerm)\n"
"    Calls: (const oaBitTerm&)\n"
"    Signature: oaBitTerm||cref-oaBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaBitTerm",
    sizeof(PyoaBitTermObject),
    0,
    (destructor)oaBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaBitTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaBitTerm",
           (PyObject*)(&PyoaBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaBitTerm\n");
       return -1;
    }
    return 0;
}

