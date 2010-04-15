
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
// Wrapper Implementation for Class: oaNetTermArrayBase_oaNet_oaName
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaName_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermArrayBase_oaNet_oaName_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermArrayBase_oaNet_oaNameObject* self = (PyoaNetTermArrayBase_oaNet_oaNameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaNetTermArrayBase_oaNet_oaName(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermArrayBase_oaNet_oaName, Choices are:\n"
        "    (oaUInt4)\n"
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
oaNetTermArrayBase_oaNet_oaName_tp_dealloc(PyoaNetTermArrayBase_oaNet_oaNameObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaName_tp_repr(PyObject *ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaName value;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaNetTermArrayBase_oaNet_oaName::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermArrayBase_oaNet_oaName_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermArrayBase_oaNet_oaName v1;
    PyParamoaNetTermArrayBase_oaNet_oaName v2;
    int convert_status1=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermArrayBase_oaNet_oaName_Convert(PyObject* ob,PyParamoaNetTermArrayBase_oaNet_oaName* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermArrayBase_oaNet_oaName_Check(ob)) {
        result->SetData(  ((PyoaNetTermArrayBase_oaNet_oaNameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermArrayBase_oaNet_oaName Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermArrayBase_oaNet_oaName_FromoaNetTermArrayBase_oaNet_oaName(oaNetTermArrayBase_oaNet_oaName* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermArrayBase_oaNet_oaName_Type.tp_alloc(&PyoaNetTermArrayBase_oaNet_oaName_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermArrayBase_oaNet_oaNameObject* self = (PyoaNetTermArrayBase_oaNet_oaNameObject*)bself;
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
// IndexGetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaName_index_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: index_get\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    oaNetTermPair_oaNet_oaName* result=&(data.Data()[index]);
    return PyoaNetTermPair_oaNet_oaName_FromoaNetTermPair_oaNet_oaName(result,1,ob);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static Pyoa_ssize_t
oaNetTermArrayBase_oaNet_oaName_index_get_length(PyObject* ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    return data.Data().getNumElements();
}


// ------------------------------------------------------------------
// IndexSetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaName_index_set_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: index_set\n"
;

static int
oaNetTermArrayBase_oaNet_oaName_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    PyParamoaNetTermPair_oaNet_oaName result;
    if (PyoaNetTermPair_oaNet_oaName_Convert(value,&result)==0) return -1;
    data.Data()[index]=result.Data();
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return -1;
  }
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaName_append_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: append\n"
"  Paramegers: (oaNet,oaName)\n"
"    Calls: void append( net,const oaName& term)\n"
"    Signature: append|void-void|cptrref-oaNet,cref-oaName,\n"
"    This function appends the given net and term pair to the end of the array.\n"
"    net\n"
"    The net to append to the array.\n"
"    term\n"
"    The term to append to the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    PyParamoaNet p1;
    PyParamoaName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNet_Convert,&p1,
          &PyoaName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->append(p1.Data(),p2.Data());
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
static char oaNetTermArrayBase_oaNet_oaName_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: get\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermPair_oaNet_oaName& get(oaUInt4 index)\n"
"    Signature: get|ref-oaNetTermPair_oaNet_oaName|simple-oaUInt4,\n"
"    This function returns the element at the given index of the array.\n"
"    index\n"
"    The index value of the element to return.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaNetTermPair_oaNet_oaName* result=&(data.DataCall()->get(p1.Data()));
        return PyoaNetTermPair_oaNet_oaName_FromoaNetTermPair_oaNet_oaName(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaName_getNumBits_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the total number of bits in the elements of the array.\n"
"    Todo\n"
"    Add description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermArrayBase_oaNet_oaName_getNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: getNumElements\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumElements() const\n"
"    Signature: getNumElements|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of elements in the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_getNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumElements());
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
static char oaNetTermArrayBase_oaNet_oaName_getNumMultiBit_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: getNumMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMultiBit() const\n"
"    Signature: getNumMultiBit|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of multi-bit terms in the elements array.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_getNumMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumMultiBit());
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
static char oaNetTermArrayBase_oaNet_oaName_getSize_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: getSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSize() const\n"
"    Signature: getSize|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the size of the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_getSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSize());
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
static char oaNetTermArrayBase_oaNet_oaName_setNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: setNumElements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setNumElements(oaUInt4 numElements)\n"
"    Signature: setNumElements|void-void|simple-oaUInt4,\n"
"    This function sets the number of elements in the array.\n"
"    numElements\n"
"    The number of array elements.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_setNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaNameObject* self=(PyoaNetTermArrayBase_oaNet_oaNameObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setNumElements(p1.Data());
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

static char oaNetTermArrayBase_oaNet_oaName_assign_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaName_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermArrayBase_oaNet_oaName data;
  int convert_status=PyoaNetTermArrayBase_oaNet_oaName_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermArrayBase_oaNet_oaName p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermArrayBase_oaNet_oaName_Convert,&p1)) {
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

static PyMethodDef oaNetTermArrayBase_oaNet_oaName_methodlist[] = {
    {"append",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_append,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_append_doc},
    {"get",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_get,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_get_doc},
    {"getNumBits",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_getNumBits,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_getNumBits_doc},
    {"getNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_getNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_getNumElements_doc},
    {"getNumMultiBit",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_getNumMultiBit,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_getNumMultiBit_doc},
    {"getSize",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_getSize,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_getSize_doc},
    {"setNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_setNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_setNumElements_doc},
    {"assign",(PyCFunction)oaNetTermArrayBase_oaNet_oaName_tp_assign,METH_VARARGS,oaNetTermArrayBase_oaNet_oaName_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------

static PySequenceMethods oaNetTermArrayBase_oaNet_oaName_as_sequence = {
    (Pyoa_inquiry)oaNetTermArrayBase_oaNet_oaName_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,		/* sq_concat */
    (Pyoa_intargfunc)0,		/* sq_repeat */
    (Pyoa_intargfunc)oaNetTermArrayBase_oaNet_oaName_index_get,	/* sq_item */
    (Pyoa_intintargfunc)0,		/* sq_slice */
    (Pyoa_intobjargproc)oaNetTermArrayBase_oaNet_oaName_index_set,	/* sq_ass_item */
};
// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaName_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaName\n"
"  This class implements a template for an array of elements. The size of the array can be different than the number of elements actually stored. This is useful in situations where the array is used as a buffer because the need to re-allocate the array is reduced.\n"
"  Todo\n"
"  Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermArrayBase_oaNet_oaName(oaUInt4 size)\n"
"    Signature: oaNetTermArrayBase_oaNet_oaName||simple-oaUInt4,\n"
"    This is the constructor for the oaNetTermArrayBase class.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermArrayBase_oaNet_oaName_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermArrayBase_oaNet_oaName",
    sizeof(PyoaNetTermArrayBase_oaNet_oaNameObject),
    0,
    (destructor)oaNetTermArrayBase_oaNet_oaName_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermArrayBase_oaNet_oaName_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermArrayBase_oaNet_oaName_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    &oaNetTermArrayBase_oaNet_oaName_as_sequence,	/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaNetTermArrayBase_oaNet_oaName_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermArrayBase_oaNet_oaName_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermArrayBase_oaNet_oaName_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermArrayBase_oaNet_oaName_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermArrayBase_oaNet_oaName_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermArrayBase_oaNet_oaName\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermArrayBase_oaNet_oaName",
           (PyObject*)(&PyoaNetTermArrayBase_oaNet_oaName_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermArrayBase_oaNet_oaName\n");
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
// Wrapper Implementation for Class: oaNetTermArrayBase_oaNet_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermArrayBase_oaNet_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermArrayBase_oaNet_oaTermObject* self = (PyoaNetTermArrayBase_oaNet_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaNetTermArrayBase_oaNet_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermArrayBase_oaNet_oaTerm, Choices are:\n"
        "    (oaUInt4)\n"
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
oaNetTermArrayBase_oaNet_oaTerm_tp_dealloc(PyoaNetTermArrayBase_oaNet_oaTermObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaTerm value;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaNetTermArrayBase_oaNet_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermArrayBase_oaNet_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermArrayBase_oaNet_oaTerm v1;
    PyParamoaNetTermArrayBase_oaNet_oaTerm v2;
    int convert_status1=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermArrayBase_oaNet_oaTerm_Convert(PyObject* ob,PyParamoaNetTermArrayBase_oaNet_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermArrayBase_oaNet_oaTerm_Check(ob)) {
        result->SetData(  ((PyoaNetTermArrayBase_oaNet_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermArrayBase_oaNet_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermArrayBase_oaNet_oaTerm_FromoaNetTermArrayBase_oaNet_oaTerm(oaNetTermArrayBase_oaNet_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermArrayBase_oaNet_oaTerm_Type.tp_alloc(&PyoaNetTermArrayBase_oaNet_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermArrayBase_oaNet_oaTermObject* self = (PyoaNetTermArrayBase_oaNet_oaTermObject*)bself;
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
// IndexGetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaTerm_index_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: index_get\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    oaNetTermPair_oaNet_oaTerm* result=&(data.Data()[index]);
    return PyoaNetTermPair_oaNet_oaTerm_FromoaNetTermPair_oaNet_oaTerm(result,1,ob);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static Pyoa_ssize_t
oaNetTermArrayBase_oaNet_oaTerm_index_get_length(PyObject* ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    return data.Data().getNumElements();
}


// ------------------------------------------------------------------
// IndexSetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaTerm_index_set_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: index_set\n"
;

static int
oaNetTermArrayBase_oaNet_oaTerm_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    PyParamoaNetTermPair_oaNet_oaTerm result;
    if (PyoaNetTermPair_oaNet_oaTerm_Convert(value,&result)==0) return -1;
    data.Data()[index]=result.Data();
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return -1;
  }
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaTerm_append_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: append\n"
"  Paramegers: (oaNet,oaTerm)\n"
"    Calls: void append( net, term)\n"
"    Signature: append|void-void|cptrref-oaNet,cptrref-oaTerm,\n"
"    This function appends the given net and term pair to the end of the array.\n"
"    net\n"
"    The net to append to the array.\n"
"    term\n"
"    The term to append to the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    PyParamoaNet p1;
    PyParamoaTerm p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNet_Convert,&p1,
          &PyoaTerm_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        data.DataCall()->append(p1.Data(),p2.Data());
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
static char oaNetTermArrayBase_oaNet_oaTerm_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: get\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermPair_oaNet_oaTerm& get(oaUInt4 index)\n"
"    Signature: get|ref-oaNetTermPair_oaNet_oaTerm|simple-oaUInt4,\n"
"    This function returns the element at the given index of the array.\n"
"    index\n"
"    The index value of the element to return.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaNetTermPair_oaNet_oaTerm* result=&(data.DataCall()->get(p1.Data()));
        return PyoaNetTermPair_oaNet_oaTerm_FromoaNetTermPair_oaNet_oaTerm(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaTerm_getNumBits_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the total number of bits in the elements of the array.\n"
"    Todo\n"
"    Add description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermArrayBase_oaNet_oaTerm_getNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: getNumElements\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumElements() const\n"
"    Signature: getNumElements|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of elements in the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_getNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumElements());
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
static char oaNetTermArrayBase_oaNet_oaTerm_getNumMultiBit_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: getNumMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMultiBit() const\n"
"    Signature: getNumMultiBit|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of multi-bit terms in the elements array.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_getNumMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumMultiBit());
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
static char oaNetTermArrayBase_oaNet_oaTerm_getSize_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: getSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSize() const\n"
"    Signature: getSize|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the size of the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_getSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSize());
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
static char oaNetTermArrayBase_oaNet_oaTerm_setNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: setNumElements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setNumElements(oaUInt4 numElements)\n"
"    Signature: setNumElements|void-void|simple-oaUInt4,\n"
"    This function sets the number of elements in the array.\n"
"    numElements\n"
"    The number of array elements.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_setNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaTermObject* self=(PyoaNetTermArrayBase_oaNet_oaTermObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setNumElements(p1.Data());
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

static char oaNetTermArrayBase_oaNet_oaTerm_assign_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermArrayBase_oaNet_oaTerm data;
  int convert_status=PyoaNetTermArrayBase_oaNet_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermArrayBase_oaNet_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermArrayBase_oaNet_oaTerm_Convert,&p1)) {
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

static PyMethodDef oaNetTermArrayBase_oaNet_oaTerm_methodlist[] = {
    {"append",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_append,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_append_doc},
    {"get",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_get,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_get_doc},
    {"getNumBits",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_getNumBits,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_getNumBits_doc},
    {"getNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_getNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_getNumElements_doc},
    {"getNumMultiBit",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_getNumMultiBit,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_getNumMultiBit_doc},
    {"getSize",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_getSize,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_getSize_doc},
    {"setNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_setNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_setNumElements_doc},
    {"assign",(PyCFunction)oaNetTermArrayBase_oaNet_oaTerm_tp_assign,METH_VARARGS,oaNetTermArrayBase_oaNet_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------

static PySequenceMethods oaNetTermArrayBase_oaNet_oaTerm_as_sequence = {
    (Pyoa_inquiry)oaNetTermArrayBase_oaNet_oaTerm_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,		/* sq_concat */
    (Pyoa_intargfunc)0,		/* sq_repeat */
    (Pyoa_intargfunc)oaNetTermArrayBase_oaNet_oaTerm_index_get,	/* sq_item */
    (Pyoa_intintargfunc)0,		/* sq_slice */
    (Pyoa_intobjargproc)oaNetTermArrayBase_oaNet_oaTerm_index_set,	/* sq_ass_item */
};
// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaTerm_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaTerm\n"
"  This class implements a template for an array of elements. The size of the array can be different than the number of elements actually stored. This is useful in situations where the array is used as a buffer because the need to re-allocate the array is reduced.\n"
"  Todo\n"
"  Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermArrayBase_oaNet_oaTerm(oaUInt4 size)\n"
"    Signature: oaNetTermArrayBase_oaNet_oaTerm||simple-oaUInt4,\n"
"    This is the constructor for the oaNetTermArrayBase class.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermArrayBase_oaNet_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermArrayBase_oaNet_oaTerm",
    sizeof(PyoaNetTermArrayBase_oaNet_oaTermObject),
    0,
    (destructor)oaNetTermArrayBase_oaNet_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermArrayBase_oaNet_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermArrayBase_oaNet_oaTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    &oaNetTermArrayBase_oaNet_oaTerm_as_sequence,	/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaNetTermArrayBase_oaNet_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermArrayBase_oaNet_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermArrayBase_oaNet_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermArrayBase_oaNet_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermArrayBase_oaNet_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermArrayBase_oaNet_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermArrayBase_oaNet_oaTerm",
           (PyObject*)(&PyoaNetTermArrayBase_oaNet_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermArrayBase_oaNet_oaTerm\n");
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
// Wrapper Implementation for Class: oaNetTermArrayBase_oaNet_oaUInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermArrayBase_oaNet_oaUInt4_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self = (PyoaNetTermArrayBase_oaNet_oaUInt4Object*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaNetTermArrayBase_oaNet_oaUInt4(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermArrayBase_oaNet_oaUInt4, Choices are:\n"
        "    (oaUInt4)\n"
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
oaNetTermArrayBase_oaNet_oaUInt4_tp_dealloc(PyoaNetTermArrayBase_oaNet_oaUInt4Object* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_tp_repr(PyObject *ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 value;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaNetTermArrayBase_oaNet_oaUInt4::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermArrayBase_oaNet_oaUInt4_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 v1;
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 v2;
    int convert_status1=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(PyObject* ob,PyParamoaNetTermArrayBase_oaNet_oaUInt4* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermArrayBase_oaNet_oaUInt4_Check(ob)) {
        result->SetData(  ((PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermArrayBase_oaNet_oaUInt4 Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermArrayBase_oaNet_oaUInt4_FromoaNetTermArrayBase_oaNet_oaUInt4(oaNetTermArrayBase_oaNet_oaUInt4* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermArrayBase_oaNet_oaUInt4_Type.tp_alloc(&PyoaNetTermArrayBase_oaNet_oaUInt4_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermArrayBase_oaNet_oaUInt4Object* self = (PyoaNetTermArrayBase_oaNet_oaUInt4Object*)bself;
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
// IndexGetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaUInt4_index_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: index_get\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    oaNetTermPair_oaNet_oaUInt4* result=&(data.Data()[index]);
    return PyoaNetTermPair_oaNet_oaUInt4_FromoaNetTermPair_oaNet_oaUInt4(result,1,ob);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static Pyoa_ssize_t
oaNetTermArrayBase_oaNet_oaUInt4_index_get_length(PyObject* ob)
{
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    return data.Data().getNumElements();
}


// ------------------------------------------------------------------
// IndexSetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaUInt4_index_set_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: index_set\n"
;

static int
oaNetTermArrayBase_oaNet_oaUInt4_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getNumElements()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    PyParamoaNetTermPair_oaNet_oaUInt4 result;
    if (PyoaNetTermPair_oaNet_oaUInt4_Convert(value,&result)==0) return -1;
    data.Data()[index]=result.Data();
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return -1;
  }
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaUInt4_append_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: append\n"
"  Paramegers: (oaNet,oaUInt4)\n"
"    Calls: void append( net,const oaUInt4& term)\n"
"    Signature: append|void-void|cptrref-oaNet,cref-oaUInt4,\n"
"    This function appends the given net and term pair to the end of the array.\n"
"    net\n"
"    The net to append to the array.\n"
"    term\n"
"    The term to append to the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    PyParamoaNet p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNet_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->append(p1.Data(),p2.Data());
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
static char oaNetTermArrayBase_oaNet_oaUInt4_get_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: get\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermPair_oaNet_oaUInt4& get(oaUInt4 index)\n"
"    Signature: get|ref-oaNetTermPair_oaNet_oaUInt4|simple-oaUInt4,\n"
"    This function returns the element at the given index of the array.\n"
"    index\n"
"    The index value of the element to return.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaNetTermPair_oaNet_oaUInt4* result=&(data.DataCall()->get(p1.Data()));
        return PyoaNetTermPair_oaNet_oaUInt4_FromoaNetTermPair_oaNet_oaUInt4(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaUInt4_getNumBits_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the total number of bits in the elements of the array.\n"
"    Todo\n"
"    Add description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermArrayBase_oaNet_oaUInt4_getNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: getNumElements\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumElements() const\n"
"    Signature: getNumElements|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of elements in the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_getNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumElements());
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
static char oaNetTermArrayBase_oaNet_oaUInt4_getNumMultiBit_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: getNumMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMultiBit() const\n"
"    Signature: getNumMultiBit|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of multi-bit terms in the elements array.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_getNumMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumMultiBit());
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
static char oaNetTermArrayBase_oaNet_oaUInt4_getSize_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: getSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSize() const\n"
"    Signature: getSize|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the size of the array.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_getSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSize());
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
static char oaNetTermArrayBase_oaNet_oaUInt4_setNumElements_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: setNumElements\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setNumElements(oaUInt4 numElements)\n"
"    Signature: setNumElements|void-void|simple-oaUInt4,\n"
"    This function sets the number of elements in the array.\n"
"    numElements\n"
"    The number of array elements.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_setNumElements(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermArrayBase_oaNet_oaUInt4Object* self=(PyoaNetTermArrayBase_oaNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setNumElements(p1.Data());
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

static char oaNetTermArrayBase_oaNet_oaUInt4_assign_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermArrayBase_oaNet_oaUInt4_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermArrayBase_oaNet_oaUInt4 data;
  int convert_status=PyoaNetTermArrayBase_oaNet_oaUInt4_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermArrayBase_oaNet_oaUInt4 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermArrayBase_oaNet_oaUInt4_Convert,&p1)) {
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

static PyMethodDef oaNetTermArrayBase_oaNet_oaUInt4_methodlist[] = {
    {"append",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_append,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_append_doc},
    {"get",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_get,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_get_doc},
    {"getNumBits",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_getNumBits,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_getNumBits_doc},
    {"getNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_getNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_getNumElements_doc},
    {"getNumMultiBit",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_getNumMultiBit,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_getNumMultiBit_doc},
    {"getSize",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_getSize,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_getSize_doc},
    {"setNumElements",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_setNumElements,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_setNumElements_doc},
    {"assign",(PyCFunction)oaNetTermArrayBase_oaNet_oaUInt4_tp_assign,METH_VARARGS,oaNetTermArrayBase_oaNet_oaUInt4_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------

static PySequenceMethods oaNetTermArrayBase_oaNet_oaUInt4_as_sequence = {
    (Pyoa_inquiry)oaNetTermArrayBase_oaNet_oaUInt4_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,		/* sq_concat */
    (Pyoa_intargfunc)0,		/* sq_repeat */
    (Pyoa_intargfunc)oaNetTermArrayBase_oaNet_oaUInt4_index_get,	/* sq_item */
    (Pyoa_intintargfunc)0,		/* sq_slice */
    (Pyoa_intobjargproc)oaNetTermArrayBase_oaNet_oaUInt4_index_set,	/* sq_ass_item */
};
// ------------------------------------------------------------------
static char oaNetTermArrayBase_oaNet_oaUInt4_doc[] = 
"Class: oaNetTermArrayBase_oaNet_oaUInt4\n"
"  This class implements a template for an array of elements. The size of the array can be different than the number of elements actually stored. This is useful in situations where the array is used as a buffer because the need to re-allocate the array is reduced.\n"
"  Todo\n"
"  Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermArrayBase_oaNet_oaUInt4(oaUInt4 size)\n"
"    Signature: oaNetTermArrayBase_oaNet_oaUInt4||simple-oaUInt4,\n"
"    This is the constructor for the oaNetTermArrayBase class.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermArrayBase_oaNet_oaUInt4_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermArrayBase_oaNet_oaUInt4",
    sizeof(PyoaNetTermArrayBase_oaNet_oaUInt4Object),
    0,
    (destructor)oaNetTermArrayBase_oaNet_oaUInt4_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermArrayBase_oaNet_oaUInt4_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermArrayBase_oaNet_oaUInt4_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    &oaNetTermArrayBase_oaNet_oaUInt4_as_sequence,	/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaNetTermArrayBase_oaNet_oaUInt4_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermArrayBase_oaNet_oaUInt4_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermArrayBase_oaNet_oaUInt4_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermArrayBase_oaNet_oaUInt4_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermArrayBase_oaNet_oaUInt4_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermArrayBase_oaNet_oaUInt4\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermArrayBase_oaNet_oaUInt4",
           (PyObject*)(&PyoaNetTermArrayBase_oaNet_oaUInt4_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermArrayBase_oaNet_oaUInt4\n");
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
// Wrapper Implementation for Class: oaNetTermNameArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermNameArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermNameArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermNameArrayObject* self = (PyoaNetTermNameArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaNetTermArrayBase_oaNet_oaName*)  new oaNetTermNameArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaNetTermArrayBase_oaNet_oaName*)  new oaNetTermNameArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermNameArray)
    {
        PyParamoaNetTermNameArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermNameArray_Convert,&p1)) {
            self->value=(oaNetTermArrayBase_oaNet_oaName*)  new oaNetTermNameArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermNameArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaNetTermNameArray)\n"
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
oaNetTermNameArray_tp_dealloc(PyoaNetTermNameArrayObject* self)
{
    if (!self->borrow) {
        delete (oaNetTermNameArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermNameArray_tp_repr(PyObject *ob)
{
    PyParamoaNetTermNameArray value;
    int convert_status=PyoaNetTermNameArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaNetTermNameArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermNameArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermNameArray v1;
    PyParamoaNetTermNameArray v2;
    int convert_status1=PyoaNetTermNameArray_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermNameArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermNameArray_Convert(PyObject* ob,PyParamoaNetTermNameArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermNameArray_Check(ob)) {
        result->SetData( (oaNetTermNameArray*) ((PyoaNetTermNameArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermNameArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermNameArray_FromoaNetTermNameArray(oaNetTermNameArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermNameArray_Type.tp_alloc(&PyoaNetTermNameArray_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermNameArrayObject* self = (PyoaNetTermNameArrayObject*)bself;
        self->value = (oaNetTermArrayBase_oaNet_oaName*)  data;
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
static char oaNetTermNameArray_doc[] = 
"Class: oaNetTermNameArray\n"
"  This class associates oaNet pointers with the names of terms.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermNameArray()\n"
"    Signature: oaNetTermNameArray||simple-oaUInt4,\n"
"    This function constructs an array of oaNet pointers and associated term names.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermNameArray(oaUInt4 size)\n"
"    Signature: oaNetTermNameArray||simple-oaUInt4,\n"
"    This function constructs an array of oaNet pointers and associated term names.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
"  Paramegers: (oaNetTermNameArray)\n"
"    Calls: (const oaNetTermNameArray&)\n"
"    Signature: oaNetTermNameArray||cref-oaNetTermNameArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermNameArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermNameArray",
    sizeof(PyoaNetTermNameArrayObject),
    0,
    (destructor)oaNetTermNameArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermNameArray_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermNameArray_tp_repr,	/* tp_repr */
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
    oaNetTermNameArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNetTermArrayBase_oaNet_oaName_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermNameArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermNameArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermNameArray_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermNameArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermNameArray",
           (PyObject*)(&PyoaNetTermNameArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermNameArray\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaModNet_oaModTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaModTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaModNet_oaModTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaModNet_oaModTermObject* self = (PyoaNetTermPair_oaModNet_oaModTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaModNet_oaModTerm();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaModNet_oaModTerm)
    {
        PyParamoaNetTermPair_oaModNet_oaModTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaModNet_oaModTerm_Convert,&p1)) {
            self->value= new oaNetTermPair_oaModNet_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaModNet_oaModTerm, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaModNet_oaModTerm)\n"
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
oaNetTermPair_oaModNet_oaModTerm_tp_dealloc(PyoaNetTermPair_oaModNet_oaModTermObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaModTerm_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaModNet_oaModTerm value;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaNetTermPair_oaModNet_oaModTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaModNet_oaModTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaModNet_oaModTerm v1;
    PyParamoaNetTermPair_oaModNet_oaModTerm v2;
    int convert_status1=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaModNet_oaModTerm_Convert(PyObject* ob,PyParamoaNetTermPair_oaModNet_oaModTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaModNet_oaModTerm_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaModNet_oaModTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaModNet_oaModTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaModNet_oaModTerm_FromoaNetTermPair_oaModNet_oaModTerm(oaNetTermPair_oaModNet_oaModTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaModNet_oaModTerm_Type.tp_alloc(&PyoaNetTermPair_oaModNet_oaModTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaModNet_oaModTermObject* self = (PyoaNetTermPair_oaModNet_oaModTermObject*)bself;
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
static char oaNetTermPair_oaModNet_oaModTerm_getNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaModNet* getNet() const\n"
"    Signature: getNet|cptr-oaModNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetp result=(oaModNetp)(data.DataCall()->getNet());
        return PyoaModNet_FromoaModNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaModTerm_getNumBits_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaModNet_oaModTerm_getTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaModTerm*& getTerm()\n"
"    Signature: getTerm|ptrref-oaModTerm|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModTermp* result=&(data.DataCall()->getTerm());
        return PyoaModTerm_FromoaModTerm(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaModTerm_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaModNet_oaModTerm_setNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: setNet\n"
"  Paramegers: (oaModNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaModNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    PyParamoaModNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaModNet_oaModTerm_setTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: setTerm\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: void setTerm( termIn)\n"
"    Signature: setTerm|void-void|cptrref-oaModTerm,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm data;
    int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaModTermObject* self=(PyoaNetTermPair_oaModNet_oaModTermObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaModNet_oaModTerm_assign_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaModTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaModNet_oaModTerm data;
  int convert_status=PyoaNetTermPair_oaModNet_oaModTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaModNet_oaModTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaModNet_oaModTerm_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaModNet_oaModTerm_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_getNet,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_getNumBits,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_getTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_isMultiBit,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_setNet,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_setTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaModNet_oaModTerm_tp_assign,METH_VARARGS,oaNetTermPair_oaModNet_oaModTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaModTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaModTerm\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaModNet_oaModTerm()\n"
"    Signature: oaNetTermPair_oaModNet_oaModTerm||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaModNet_oaModTerm)\n"
"    Calls: (const oaNetTermPair_oaModNet_oaModTerm&)\n"
"    Signature: oaNetTermPair_oaModNet_oaModTerm||cref-oaNetTermPair_oaModNet_oaModTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaModNet_oaModTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaModNet_oaModTerm",
    sizeof(PyoaNetTermPair_oaModNet_oaModTermObject),
    0,
    (destructor)oaNetTermPair_oaModNet_oaModTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaModNet_oaModTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaModNet_oaModTerm_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaModNet_oaModTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaModNet_oaModTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaModNet_oaModTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaModNet_oaModTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaModNet_oaModTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaModNet_oaModTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaModNet_oaModTerm",
           (PyObject*)(&PyoaNetTermPair_oaModNet_oaModTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaModNet_oaModTerm\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaModNet_oaName
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaName_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaModNet_oaName_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaModNet_oaNameObject* self = (PyoaNetTermPair_oaModNet_oaNameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaModNet_oaName();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaModNet_oaName)
    {
        PyParamoaNetTermPair_oaModNet_oaName p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaModNet_oaName_Convert,&p1)) {
            self->value= new oaNetTermPair_oaModNet_oaName(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaModNet_oaName, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaModNet_oaName)\n"
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
oaNetTermPair_oaModNet_oaName_tp_dealloc(PyoaNetTermPair_oaModNet_oaNameObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaName_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaModNet_oaName value;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaNetTermPair_oaModNet_oaName::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaModNet_oaName_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaModNet_oaName v1;
    PyParamoaNetTermPair_oaModNet_oaName v2;
    int convert_status1=PyoaNetTermPair_oaModNet_oaName_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaModNet_oaName_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaModNet_oaName_Convert(PyObject* ob,PyParamoaNetTermPair_oaModNet_oaName* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaModNet_oaName_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaModNet_oaNameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaModNet_oaName Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaModNet_oaName_FromoaNetTermPair_oaModNet_oaName(oaNetTermPair_oaModNet_oaName* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaModNet_oaName_Type.tp_alloc(&PyoaNetTermPair_oaModNet_oaName_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaModNet_oaNameObject* self = (PyoaNetTermPair_oaModNet_oaNameObject*)bself;
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
static char oaNetTermPair_oaModNet_oaName_getNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaModNet* getNet() const\n"
"    Signature: getNet|cptr-oaModNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetp result=(oaModNetp)(data.DataCall()->getNet());
        return PyoaModNet_FromoaModNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaName_getNumBits_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaModNet_oaName_getTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaName& getTerm()\n"
"    Signature: getTerm|ref-oaName|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaName* result=&(data.DataCall()->getTerm());
        return PyoaName_FromoaName(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaName_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaModNet_oaName_setNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: setNet\n"
"  Paramegers: (oaModNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaModNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    PyParamoaModNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaModNet_oaName_setTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: setTerm\n"
"  Paramegers: (oaName)\n"
"    Calls: void setTerm(const oaName& termIn)\n"
"    Signature: setTerm|void-void|cref-oaName,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaName data;
    int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaNameObject* self=(PyoaNetTermPair_oaModNet_oaNameObject*)ob;

    PyParamoaName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaName_Convert,&p1)) {
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaModNet_oaName_assign_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaName_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaModNet_oaName data;
  int convert_status=PyoaNetTermPair_oaModNet_oaName_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaModNet_oaName p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaModNet_oaName_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaModNet_oaName_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaModNet_oaName_getNet,METH_VARARGS,oaNetTermPair_oaModNet_oaName_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaModNet_oaName_getNumBits,METH_VARARGS,oaNetTermPair_oaModNet_oaName_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaModNet_oaName_getTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaName_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaModNet_oaName_isMultiBit,METH_VARARGS,oaNetTermPair_oaModNet_oaName_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaModNet_oaName_setNet,METH_VARARGS,oaNetTermPair_oaModNet_oaName_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaModNet_oaName_setTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaName_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaModNet_oaName_tp_assign,METH_VARARGS,oaNetTermPair_oaModNet_oaName_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaName_doc[] = 
"Class: oaNetTermPair_oaModNet_oaName\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaModNet_oaName()\n"
"    Signature: oaNetTermPair_oaModNet_oaName||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaModNet_oaName)\n"
"    Calls: (const oaNetTermPair_oaModNet_oaName&)\n"
"    Signature: oaNetTermPair_oaModNet_oaName||cref-oaNetTermPair_oaModNet_oaName,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaModNet_oaName_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaModNet_oaName",
    sizeof(PyoaNetTermPair_oaModNet_oaNameObject),
    0,
    (destructor)oaNetTermPair_oaModNet_oaName_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaModNet_oaName_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaModNet_oaName_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaModNet_oaName_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaModNet_oaName_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaModNet_oaName_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaModNet_oaName_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaModNet_oaName_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaModNet_oaName\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaModNet_oaName",
           (PyObject*)(&PyoaNetTermPair_oaModNet_oaName_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaModNet_oaName\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaModNet_oaUInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaUInt4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaModNet_oaUInt4_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaModNet_oaUInt4Object* self = (PyoaNetTermPair_oaModNet_oaUInt4Object*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaModNet_oaUInt4();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaModNet_oaUInt4)
    {
        PyParamoaNetTermPair_oaModNet_oaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaModNet_oaUInt4_Convert,&p1)) {
            self->value= new oaNetTermPair_oaModNet_oaUInt4(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaModNet_oaUInt4, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaModNet_oaUInt4)\n"
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
oaNetTermPair_oaModNet_oaUInt4_tp_dealloc(PyoaNetTermPair_oaModNet_oaUInt4Object* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaModNet_oaUInt4_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaModNet_oaUInt4 value;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaNetTermPair_oaModNet_oaUInt4::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaModNet_oaUInt4_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaModNet_oaUInt4 v1;
    PyParamoaNetTermPair_oaModNet_oaUInt4 v2;
    int convert_status1=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaModNet_oaUInt4_Convert(PyObject* ob,PyParamoaNetTermPair_oaModNet_oaUInt4* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaModNet_oaUInt4_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaModNet_oaUInt4Object*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaModNet_oaUInt4 Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaModNet_oaUInt4_FromoaNetTermPair_oaModNet_oaUInt4(oaNetTermPair_oaModNet_oaUInt4* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaModNet_oaUInt4_Type.tp_alloc(&PyoaNetTermPair_oaModNet_oaUInt4_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaModNet_oaUInt4Object* self = (PyoaNetTermPair_oaModNet_oaUInt4Object*)bself;
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
static char oaNetTermPair_oaModNet_oaUInt4_getNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaModNet* getNet() const\n"
"    Signature: getNet|cptr-oaModNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetp result=(oaModNetp)(data.DataCall()->getNet());
        return PyoaModNet_FromoaModNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaUInt4_getNumBits_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaModNet_oaUInt4_getTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4& getTerm()\n"
"    Signature: getTerm|ref-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4* result=&(data.DataCall()->getTerm());
        return PyoaUInt4_FromoaUInt4(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaUInt4_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaModNet_oaUInt4_setNet_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: setNet\n"
"  Paramegers: (oaModNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaModNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    PyParamoaModNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaModNet_oaUInt4_setTerm_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: setTerm\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setTerm(const oaUInt4& termIn)\n"
"    Signature: setTerm|void-void|cref-oaUInt4,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaModNet_oaUInt4Object* self=(PyoaNetTermPair_oaModNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaModNet_oaUInt4_assign_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaModNet_oaUInt4_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaModNet_oaUInt4 data;
  int convert_status=PyoaNetTermPair_oaModNet_oaUInt4_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaModNet_oaUInt4 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaModNet_oaUInt4_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaModNet_oaUInt4_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_getNet,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_getNumBits,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_getTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_isMultiBit,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_setNet,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_setTerm,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaModNet_oaUInt4_tp_assign,METH_VARARGS,oaNetTermPair_oaModNet_oaUInt4_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaModNet_oaUInt4_doc[] = 
"Class: oaNetTermPair_oaModNet_oaUInt4\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaModNet_oaUInt4()\n"
"    Signature: oaNetTermPair_oaModNet_oaUInt4||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaModNet_oaUInt4)\n"
"    Calls: (const oaNetTermPair_oaModNet_oaUInt4&)\n"
"    Signature: oaNetTermPair_oaModNet_oaUInt4||cref-oaNetTermPair_oaModNet_oaUInt4,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaModNet_oaUInt4_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaModNet_oaUInt4",
    sizeof(PyoaNetTermPair_oaModNet_oaUInt4Object),
    0,
    (destructor)oaNetTermPair_oaModNet_oaUInt4_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaModNet_oaUInt4_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaModNet_oaUInt4_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaModNet_oaUInt4_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaModNet_oaUInt4_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaModNet_oaUInt4_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaModNet_oaUInt4_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaModNet_oaUInt4_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaModNet_oaUInt4\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaModNet_oaUInt4",
           (PyObject*)(&PyoaNetTermPair_oaModNet_oaUInt4_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaModNet_oaUInt4\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaNet_oaName
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaName_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaNet_oaName_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaNet_oaNameObject* self = (PyoaNetTermPair_oaNet_oaNameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaNet_oaName();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaNet_oaName)
    {
        PyParamoaNetTermPair_oaNet_oaName p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaNet_oaName_Convert,&p1)) {
            self->value= new oaNetTermPair_oaNet_oaName(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaNet_oaName, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaNet_oaName)\n"
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
oaNetTermPair_oaNet_oaName_tp_dealloc(PyoaNetTermPair_oaNet_oaNameObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaName_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaNet_oaName value;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaNetTermPair_oaNet_oaName::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaNet_oaName_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaNet_oaName v1;
    PyParamoaNetTermPair_oaNet_oaName v2;
    int convert_status1=PyoaNetTermPair_oaNet_oaName_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaNet_oaName_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaNet_oaName_Convert(PyObject* ob,PyParamoaNetTermPair_oaNet_oaName* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaNet_oaName_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaNet_oaNameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaNet_oaName Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaNet_oaName_FromoaNetTermPair_oaNet_oaName(oaNetTermPair_oaNet_oaName* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaNet_oaName_Type.tp_alloc(&PyoaNetTermPair_oaNet_oaName_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaNet_oaNameObject* self = (PyoaNetTermPair_oaNet_oaNameObject*)bself;
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
static char oaNetTermPair_oaNet_oaName_getNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaNet* getNet() const\n"
"    Signature: getNet|cptr-oaNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result=(oaNetp)(data.DataCall()->getNet());
        return PyoaNet_FromoaNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaName_getNumBits_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaNet_oaName_getTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaName& getTerm()\n"
"    Signature: getTerm|ref-oaName|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaName* result=&(data.DataCall()->getTerm());
        return PyoaName_FromoaName(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaName_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaNet_oaName_setNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: setNet\n"
"  Paramegers: (oaNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaNet_oaName_setTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: setTerm\n"
"  Paramegers: (oaName)\n"
"    Calls: void setTerm(const oaName& termIn)\n"
"    Signature: setTerm|void-void|cref-oaName,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaName data;
    int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaNameObject* self=(PyoaNetTermPair_oaNet_oaNameObject*)ob;

    PyParamoaName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaName_Convert,&p1)) {
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaNet_oaName_assign_doc[] = 
"Class: oaNetTermPair_oaNet_oaName, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaName_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaNet_oaName data;
  int convert_status=PyoaNetTermPair_oaNet_oaName_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaNet_oaName p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaNet_oaName_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaNet_oaName_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaNet_oaName_getNet,METH_VARARGS,oaNetTermPair_oaNet_oaName_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaNet_oaName_getNumBits,METH_VARARGS,oaNetTermPair_oaNet_oaName_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaNet_oaName_getTerm,METH_VARARGS,oaNetTermPair_oaNet_oaName_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaNet_oaName_isMultiBit,METH_VARARGS,oaNetTermPair_oaNet_oaName_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaNet_oaName_setNet,METH_VARARGS,oaNetTermPair_oaNet_oaName_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaNet_oaName_setTerm,METH_VARARGS,oaNetTermPair_oaNet_oaName_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaNet_oaName_tp_assign,METH_VARARGS,oaNetTermPair_oaNet_oaName_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaName_doc[] = 
"Class: oaNetTermPair_oaNet_oaName\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaNet_oaName()\n"
"    Signature: oaNetTermPair_oaNet_oaName||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaNet_oaName)\n"
"    Calls: (const oaNetTermPair_oaNet_oaName&)\n"
"    Signature: oaNetTermPair_oaNet_oaName||cref-oaNetTermPair_oaNet_oaName,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaNet_oaName_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaNet_oaName",
    sizeof(PyoaNetTermPair_oaNet_oaNameObject),
    0,
    (destructor)oaNetTermPair_oaNet_oaName_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaNet_oaName_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaNet_oaName_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaNet_oaName_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaNet_oaName_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaNet_oaName_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaNet_oaName_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaNet_oaName_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaNet_oaName\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaNet_oaName",
           (PyObject*)(&PyoaNetTermPair_oaNet_oaName_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaNet_oaName\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaNet_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaNet_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaNet_oaTermObject* self = (PyoaNetTermPair_oaNet_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaNet_oaTerm();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaNet_oaTerm)
    {
        PyParamoaNetTermPair_oaNet_oaTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaNet_oaTerm_Convert,&p1)) {
            self->value= new oaNetTermPair_oaNet_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaNet_oaTerm, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaNet_oaTerm)\n"
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
oaNetTermPair_oaNet_oaTerm_tp_dealloc(PyoaNetTermPair_oaNet_oaTermObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaNet_oaTerm value;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaNetTermPair_oaNet_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaNet_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaNet_oaTerm v1;
    PyParamoaNetTermPair_oaNet_oaTerm v2;
    int convert_status1=PyoaNetTermPair_oaNet_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaNet_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaNet_oaTerm_Convert(PyObject* ob,PyParamoaNetTermPair_oaNet_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaNet_oaTerm_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaNet_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaNet_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaNet_oaTerm_FromoaNetTermPair_oaNet_oaTerm(oaNetTermPair_oaNet_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaNet_oaTerm_Type.tp_alloc(&PyoaNetTermPair_oaNet_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaNet_oaTermObject* self = (PyoaNetTermPair_oaNet_oaTermObject*)bself;
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
static char oaNetTermPair_oaNet_oaTerm_getNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaNet* getNet() const\n"
"    Signature: getNet|cptr-oaNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result=(oaNetp)(data.DataCall()->getNet());
        return PyoaNet_FromoaNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaTerm_getNumBits_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaNet_oaTerm_getTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaTerm*& getTerm()\n"
"    Signature: getTerm|ptrref-oaTerm|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTermp* result=&(data.DataCall()->getTerm());
        return PyoaTerm_FromoaTerm(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaTerm_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaNet_oaTerm_setNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: setNet\n"
"  Paramegers: (oaNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaNet_oaTerm_setTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: setTerm\n"
"  Paramegers: (oaTerm)\n"
"    Calls: void setTerm( termIn)\n"
"    Signature: setTerm|void-void|cptrref-oaTerm,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaTerm data;
    int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaTermObject* self=(PyoaNetTermPair_oaNet_oaTermObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaNet_oaTerm_assign_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaNet_oaTerm data;
  int convert_status=PyoaNetTermPair_oaNet_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaNet_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaNet_oaTerm_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaNet_oaTerm_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaNet_oaTerm_getNet,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaNet_oaTerm_getNumBits,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaNet_oaTerm_getTerm,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaNet_oaTerm_isMultiBit,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaNet_oaTerm_setNet,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaNet_oaTerm_setTerm,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaNet_oaTerm_tp_assign,METH_VARARGS,oaNetTermPair_oaNet_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaTerm\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaNet_oaTerm()\n"
"    Signature: oaNetTermPair_oaNet_oaTerm||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaNet_oaTerm)\n"
"    Calls: (const oaNetTermPair_oaNet_oaTerm&)\n"
"    Signature: oaNetTermPair_oaNet_oaTerm||cref-oaNetTermPair_oaNet_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaNet_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaNet_oaTerm",
    sizeof(PyoaNetTermPair_oaNet_oaTermObject),
    0,
    (destructor)oaNetTermPair_oaNet_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaNet_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaNet_oaTerm_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaNet_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaNet_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaNet_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaNet_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaNet_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaNet_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaNet_oaTerm",
           (PyObject*)(&PyoaNetTermPair_oaNet_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaNet_oaTerm\n");
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
// Wrapper Implementation for Class: oaNetTermPair_oaNet_oaUInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaUInt4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPair_oaNet_oaUInt4_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPair_oaNet_oaUInt4Object* self = (PyoaNetTermPair_oaNet_oaUInt4Object*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaNetTermPair_oaNet_oaUInt4();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPair_oaNet_oaUInt4)
    {
        PyParamoaNetTermPair_oaNet_oaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPair_oaNet_oaUInt4_Convert,&p1)) {
            self->value= new oaNetTermPair_oaNet_oaUInt4(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPair_oaNet_oaUInt4, Choices are:\n"
        "    ()\n"
        "    (oaNetTermPair_oaNet_oaUInt4)\n"
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
oaNetTermPair_oaNet_oaUInt4_tp_dealloc(PyoaNetTermPair_oaNet_oaUInt4Object* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPair_oaNet_oaUInt4_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPair_oaNet_oaUInt4 value;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaNetTermPair_oaNet_oaUInt4::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPair_oaNet_oaUInt4_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPair_oaNet_oaUInt4 v1;
    PyParamoaNetTermPair_oaNet_oaUInt4 v2;
    int convert_status1=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPair_oaNet_oaUInt4_Convert(PyObject* ob,PyParamoaNetTermPair_oaNet_oaUInt4* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPair_oaNet_oaUInt4_Check(ob)) {
        result->SetData(  ((PyoaNetTermPair_oaNet_oaUInt4Object*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPair_oaNet_oaUInt4 Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPair_oaNet_oaUInt4_FromoaNetTermPair_oaNet_oaUInt4(oaNetTermPair_oaNet_oaUInt4* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPair_oaNet_oaUInt4_Type.tp_alloc(&PyoaNetTermPair_oaNet_oaUInt4_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPair_oaNet_oaUInt4Object* self = (PyoaNetTermPair_oaNet_oaUInt4Object*)bself;
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
static char oaNetTermPair_oaNet_oaUInt4_getNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: const oaNet* getNet() const\n"
"    Signature: getNet|cptr-oaNet|\n"
"    BrowseData: 1\n"
"    This function returns the net data members as a constant.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result=(oaNetp)(data.DataCall()->getNet());
        return PyoaNet_FromoaNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaUInt4_getNumBits_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits in the connection specification.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumBits());
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
static char oaNetTermPair_oaNet_oaUInt4_getTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4& getTerm()\n"
"    Signature: getTerm|ref-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the term data members.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4* result=&(data.DataCall()->getTerm());
        return PyoaUInt4_FromoaUInt4(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaUInt4_isMultiBit_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: isMultiBit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMultiBit() const\n"
"    Signature: isMultiBit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the term specification is multi-bit.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_isMultiBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMultiBit());
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
static char oaNetTermPair_oaNet_oaUInt4_setNet_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: setNet\n"
"  Paramegers: (oaNet)\n"
"    Calls: void setNet( netIn)\n"
"    Signature: setNet|void-void|cptrref-oaNet,\n"
"    This function sets a net data member.\n"
"    netIn\n"
"    A reference to the net data member to set.\n"
"    Todo\n"
"    Check description of member function. Check description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_setNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setNet(p1.Data());
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
static char oaNetTermPair_oaNet_oaUInt4_setTerm_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: setTerm\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setTerm(const oaUInt4& termIn)\n"
"    Signature: setTerm|void-void|cref-oaUInt4,\n"
"    This function sets a term data member.\n"
"    termIn\n"
"    A reference to the term data member to set.\n"
"    Todo\n"
"    Add description of each parameter.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 data;
    int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNetTermPair_oaNet_oaUInt4Object* self=(PyoaNetTermPair_oaNet_oaUInt4Object*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setTerm(p1.Data());
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

static char oaNetTermPair_oaNet_oaUInt4_assign_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNetTermPair_oaNet_oaUInt4_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNetTermPair_oaNet_oaUInt4 data;
  int convert_status=PyoaNetTermPair_oaNet_oaUInt4_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNetTermPair_oaNet_oaUInt4 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNetTermPair_oaNet_oaUInt4_Convert,&p1)) {
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

static PyMethodDef oaNetTermPair_oaNet_oaUInt4_methodlist[] = {
    {"getNet",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_getNet,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_getNet_doc},
    {"getNumBits",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_getNumBits,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_getNumBits_doc},
    {"getTerm",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_getTerm,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_getTerm_doc},
    {"isMultiBit",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_isMultiBit,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_isMultiBit_doc},
    {"setNet",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_setNet,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_setNet_doc},
    {"setTerm",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_setTerm,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_setTerm_doc},
    {"assign",(PyCFunction)oaNetTermPair_oaNet_oaUInt4_tp_assign,METH_VARARGS,oaNetTermPair_oaNet_oaUInt4_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNetTermPair_oaNet_oaUInt4_doc[] = 
"Class: oaNetTermPair_oaNet_oaUInt4\n"
"  The oaNetTermPair template class is only intended for use in the context of an oaNetTermArray .\n"
"  Todo\n"
"  Check detailed description of class. Add <> template identifiers to appropriate functions.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPair_oaNet_oaUInt4()\n"
"    Signature: oaNetTermPair_oaNet_oaUInt4||\n"
"    Todo\n"
"    Add description of member function.\n"
"  Paramegers: (oaNetTermPair_oaNet_oaUInt4)\n"
"    Calls: (const oaNetTermPair_oaNet_oaUInt4&)\n"
"    Signature: oaNetTermPair_oaNet_oaUInt4||cref-oaNetTermPair_oaNet_oaUInt4,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPair_oaNet_oaUInt4_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPair_oaNet_oaUInt4",
    sizeof(PyoaNetTermPair_oaNet_oaUInt4Object),
    0,
    (destructor)oaNetTermPair_oaNet_oaUInt4_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPair_oaNet_oaUInt4_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPair_oaNet_oaUInt4_tp_repr,	/* tp_repr */
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
    oaNetTermPair_oaNet_oaUInt4_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNetTermPair_oaNet_oaUInt4_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPair_oaNet_oaUInt4_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPair_oaNet_oaUInt4_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPair_oaNet_oaUInt4_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPair_oaNet_oaUInt4\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPair_oaNet_oaUInt4",
           (PyObject*)(&PyoaNetTermPair_oaNet_oaUInt4_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPair_oaNet_oaUInt4\n");
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
// Wrapper Implementation for Class: oaNetTermPosArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNetTermPosArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNetTermPosArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNetTermPosArrayObject* self = (PyoaNetTermPosArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaNetTermArrayBase_oaNet_oaUInt4*)  new oaNetTermPosArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaNetTermArrayBase_oaNet_oaUInt4*)  new oaNetTermPosArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNetTermPosArray)
    {
        PyParamoaNetTermPosArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNetTermPosArray_Convert,&p1)) {
            self->value=(oaNetTermArrayBase_oaNet_oaUInt4*)  new oaNetTermPosArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaNetTermPosArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaNetTermPosArray)\n"
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
oaNetTermPosArray_tp_dealloc(PyoaNetTermPosArrayObject* self)
{
    if (!self->borrow) {
        delete (oaNetTermPosArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNetTermPosArray_tp_repr(PyObject *ob)
{
    PyParamoaNetTermPosArray value;
    int convert_status=PyoaNetTermPosArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaNetTermPosArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNetTermPosArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNetTermPosArray v1;
    PyParamoaNetTermPosArray v2;
    int convert_status1=PyoaNetTermPosArray_Convert(ob1,&v1);
    int convert_status2=PyoaNetTermPosArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNetTermPosArray_Convert(PyObject* ob,PyParamoaNetTermPosArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaNetTermPosArray_Check(ob)) {
        result->SetData( (oaNetTermPosArray*) ((PyoaNetTermPosArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNetTermPosArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNetTermPosArray_FromoaNetTermPosArray(oaNetTermPosArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaNetTermPosArray_Type.tp_alloc(&PyoaNetTermPosArray_Type,0);
        if (bself == NULL) return bself;
        PyoaNetTermPosArrayObject* self = (PyoaNetTermPosArrayObject*)bself;
        self->value = (oaNetTermArrayBase_oaNet_oaUInt4*)  data;
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
static char oaNetTermPosArray_doc[] = 
"Class: oaNetTermPosArray\n"
"  This class associates oaNet pointers with positions of terms.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaNetTermPosArray()\n"
"    Signature: oaNetTermPosArray||simple-oaUInt4,\n"
"    This function constructs an array of oaNet pointers and associated term positions.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaNetTermPosArray(oaUInt4 size)\n"
"    Signature: oaNetTermPosArray||simple-oaUInt4,\n"
"    This function constructs an array of oaNet pointers and associated term positions.\n"
"    size\n"
"    An integer value indicating the initial size of the array.\n"
"  Paramegers: (oaNetTermPosArray)\n"
"    Calls: (const oaNetTermPosArray&)\n"
"    Signature: oaNetTermPosArray||cref-oaNetTermPosArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNetTermPosArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNetTermPosArray",
    sizeof(PyoaNetTermPosArrayObject),
    0,
    (destructor)oaNetTermPosArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNetTermPosArray_tp_compare,	/* tp_compare */
    (reprfunc)oaNetTermPosArray_tp_repr,	/* tp_repr */
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
    oaNetTermPosArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNetTermArrayBase_oaNet_oaUInt4_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNetTermPosArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNetTermPosArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNetTermPosArray_Type)<0) {
      printf("** PyType_Ready failed for: oaNetTermPosArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNetTermPosArray",
           (PyObject*)(&PyoaNetTermPosArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNetTermPosArray\n");
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
// Wrapper Implementation for Class: oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaNodeObject* self = (PyoaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaNode)
    {
        PyParamoaNode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaNode_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaNode, Choices are:\n"
        "    (oaNode)\n"
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
oaNode_tp_dealloc(PyoaNodeObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaNode_tp_repr(PyObject *ob)
{
    PyParamoaNode value;
    int convert_status=PyoaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[28];
    sprintf(buffer,"<oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaNode v1;
    PyParamoaNode v2;
    int convert_status1=PyoaNode_Convert(ob1,&v1);
    int convert_status2=PyoaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaNode_Convert(PyObject* ob,PyParamoaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaNode_Check(ob)) {
        result->SetData( (oaNode**) ((PyoaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaNode_FromoaNode(oaNode** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaNode* data=*value;
        if (data->getType()==oacGroundedNodeType) return PyoaGroundedNode_FromoaGroundedNode((oaGroundedNode**)value,borrow,lock);
        PyObject* bself = PyoaNode_Type.tp_alloc(&PyoaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaNodeObject* self = (PyoaNodeObject*)bself;
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
PyObject* PyoaNode_FromoaNode(oaNode* data)
{
    if (data) {
        if (data->getType()==oacGroundedNodeType) return PyoaGroundedNode_FromoaGroundedNode((oaGroundedNode*)data);
       PyObject* bself = PyoaNode_Type.tp_alloc(&PyoaNode_Type,0);
       if (bself == NULL) return bself;
       PyoaNodeObject* self = (PyoaNodeObject*)bself;
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
static char oaNode_addConn_doc[] = 
"Class: oaNode, Function: addConn\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void addConn(oaDesignObject* conn)\n"
"    Signature: addConn|void-void|ptr-oaDesignObject,\n"
"    This function adds a connection to this node. The conn object must be a bitTerm or an instTerm. For a ParasiticNetwork that is on an oaNet the object must be an oaBitTerm or oaInstTerm . For a parasiticNetwork on an occNet, the object must be an oaOccBitTerm or oaOccInstTerm .\n"
"    When a terminal is represented by more than one node, it is particularly important for the node to have a layer and location. This enables applications that stitch parasitics across hierarchical boundaries to properly match the node for the terminal with the node for the instTerm.\n"
"    Note: This function throws an oacInvalidNodeConnNet exception if the node and the conn are not on the same or equivalent nets in the block domain. A similar check is not performed in the occurrence domain.\n"
"    conn\n"
"    The connection to be added to this node\n"
"    oacInvalidNodeConnType\n"
"    oacInvalidNodeConnNet\n"
;

static PyObject*
oaNode_addConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addConn(p1.Data());
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
static char oaNode_addToSubNetwork_doc[] = 
"Class: oaNode, Function: addToSubNetwork\n"
"  Paramegers: (oaSubNetwork)\n"
"    Calls: void addToSubNetwork(oaSubNetwork* subNetwork)\n"
"    Signature: addToSubNetwork|void-void|ptr-oaSubNetwork,\n"
"    This function adds this node to the specified subNetwork .\n"
"    subNetwork\n"
"    The sub-network to which the node will be added\n"
"    oacSubNetworkNodeNotSameDesign\n"
"    oacSubNetworkNodeNotSameNetwork\n"
;

static PyObject*
oaNode_addToSubNetwork(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSubNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubNetwork_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addToSubNetwork(p1.Data());
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
static char oaNode_destroy_doc[] = 
"Class: oaNode, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this node, removing it from the database.\n"
;

static PyObject*
oaNode_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
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
static char oaNode_getConns_doc[] = 
"Class: oaNode, Function: getConns\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDesignObject_oaNode getConns() const\n"
"    Signature: getConns|simple-oaCollection_oaDesignObject_oaNode|\n"
"    BrowseData: 1\n"
"    This function returns a collection containing the connections to this node.\n"
;

static PyObject*
oaNode_getConns(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDesignObject_oaNode* result= new oaCollection_oaDesignObject_oaNode(data.DataCall()->getConns());
        return PyoaCollection_oaDesignObject_oaNode_FromoaCollection_oaDesignObject_oaNode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getConnsIter_doc[] = 
"Class: oaNode, Function: getConnsIter\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObjectIter getConnsIter() const\n"
"    Signature: getConnsIter|simple-oaDesignObjectIter|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection containing the connections to this node.\n"
;

static PyObject*
oaNode_getConnsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectIter* result= new oaDesignObjectIter(data.DataCall()->getConns());
        return PyoaDesignObjectIter_FromoaDesignObjectIter(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getFromDevices_doc[] = 
"Class: oaNode, Function: getFromDevices\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDevice_oaNode getFromDevices() const\n"
"    Signature: getFromDevices|simple-oaCollection_oaDevice_oaNode|\n"
"    BrowseData: 1\n"
"    This function returns a collection containing the devices whose from endpoint is connected to this node.\n"
;

static PyObject*
oaNode_getFromDevices(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDevice_oaNode* result= new oaCollection_oaDevice_oaNode(data.DataCall()->getFromDevices());
        return PyoaCollection_oaDevice_oaNode_FromoaCollection_oaDevice_oaNode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getFromDevicesIter_doc[] = 
"Class: oaNode, Function: getFromDevicesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDevice getFromDevicesIter() const\n"
"    Signature: getFromDevicesIter|simple-oaIter_oaDevice|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection containing the devices whose from endpoint is connected to this node.\n"
;

static PyObject*
oaNode_getFromDevicesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDevice* result= new oaIter_oaDevice(data.DataCall()->getFromDevices());
        return PyoaIter_oaDevice_FromoaIter_oaDevice(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getId_doc[] = 
"Class: oaNode, Function: getId\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getId() const\n"
"    Signature: getId|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the optional ID if one was assigned to the node when it was created.\n"
;

static PyObject*
oaNode_getId(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getId());
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
static char oaNode_getLayerNum_doc[] = 
"Class: oaNode, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number for this node. If the layer number has never been set (the hasLayerNum() function returns false), the value returned by this function is undefined.\n"
;

static PyObject*
oaNode_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayerNum());
        return PyoaLayerNum_FromoaLayerNum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getLocation_doc[] = 
"Class: oaNode, Function: getLocation\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getLocation(oaPoint& location) const\n"
"    Signature: getLocation|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function returns the location of this node. If no location has been set, the returned point is at (0, 0).\n"
"    location\n"
"    A reference to an oaPoint object to be populated with the node's location\n"
;

static PyObject*
oaNode_getLocation(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->getLocation(p1.Data());
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
static char oaNode_getName_doc[] = 
"Class: oaNode, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this node. If no name has been set, the returned string is empty.\n"
"    name\n"
"    A reference to an oaString object to be populated with the node's name\n"
;

static PyObject*
oaNode_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
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
static char oaNode_getParasiticNetwork_doc[] = 
"Class: oaNode, Function: getParasiticNetwork\n"
"  Paramegers: ()\n"
"    Calls: oaParasiticNetwork* getParasiticNetwork() const\n"
"    Signature: getParasiticNetwork|ptr-oaParasiticNetwork|\n"
"    BrowseData: 1\n"
"    This function returns the parasiticNetwork to which this node belongs.\n"
;

static PyObject*
oaNode_getParasiticNetwork(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaParasiticNetworkp result= (data.DataCall()->getParasiticNetwork());
        return PyoaParasiticNetwork_FromoaParasiticNetwork(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getSubNetworks_doc[] = 
"Class: oaNode, Function: getSubNetworks\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaSubNetwork_oaNode getSubNetworks() const\n"
"    Signature: getSubNetworks|simple-oaCollection_oaSubNetwork_oaNode|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the subNetworks to which this node belongs.\n"
;

static PyObject*
oaNode_getSubNetworks(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaSubNetwork_oaNode* result= new oaCollection_oaSubNetwork_oaNode(data.DataCall()->getSubNetworks());
        return PyoaCollection_oaSubNetwork_oaNode_FromoaCollection_oaSubNetwork_oaNode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getSubNetworksIter_doc[] = 
"Class: oaNode, Function: getSubNetworksIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaSubNetwork getSubNetworksIter() const\n"
"    Signature: getSubNetworksIter|simple-oaIter_oaSubNetwork|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the subNetworks to which this node belongs.\n"
;

static PyObject*
oaNode_getSubNetworksIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaSubNetwork* result= new oaIter_oaSubNetwork(data.DataCall()->getSubNetworks());
        return PyoaIter_oaSubNetwork_FromoaIter_oaSubNetwork(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getToDevices_doc[] = 
"Class: oaNode, Function: getToDevices\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDevice_oaNode getToDevices() const\n"
"    Signature: getToDevices|simple-oaCollection_oaDevice_oaNode|\n"
"    BrowseData: 1\n"
"    This function returns a collection containing the devices whose to endpoint is connected to this node.\n"
;

static PyObject*
oaNode_getToDevices(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDevice_oaNode* result= new oaCollection_oaDevice_oaNode(data.DataCall()->getToDevices());
        return PyoaCollection_oaDevice_oaNode_FromoaCollection_oaDevice_oaNode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_getToDevicesIter_doc[] = 
"Class: oaNode, Function: getToDevicesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDevice getToDevicesIter() const\n"
"    Signature: getToDevicesIter|simple-oaIter_oaDevice|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection containing the devices whose to endpoint is connected to this node.\n"
;

static PyObject*
oaNode_getToDevicesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDevice* result= new oaIter_oaDevice(data.DataCall()->getToDevices());
        return PyoaIter_oaDevice_FromoaIter_oaDevice(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_hasId_doc[] = 
"Class: oaNode, Function: hasId\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasId() const\n"
"    Signature: hasId|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this node has a user-specified ID associated with it.\n"
;

static PyObject*
oaNode_hasId(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasId());
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
static char oaNode_hasLayerNum_doc[] = 
"Class: oaNode, Function: hasLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasLayerNum() const\n"
"    Signature: hasLayerNum|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if a layer number has been set for this node.\n"
;

static PyObject*
oaNode_hasLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasLayerNum());
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
static char oaNode_hasLocation_doc[] = 
"Class: oaNode, Function: hasLocation\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasLocation() const\n"
"    Signature: hasLocation|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if a location has been set for this node.\n"
;

static PyObject*
oaNode_hasLocation(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasLocation());
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
static char oaNode_removeConn_doc[] = 
"Class: oaNode, Function: removeConn\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void removeConn(oaDesignObject* conn)\n"
"    Signature: removeConn|void-void|ptr-oaDesignObject,\n"
"    This function removes a connection from this node. The conn object must be a terminal or instTerm ( oaTerm , oaInstTerm , oaOccTerm or oaOccInstTerm ) that was previously connected to the node.\n"
"    conn\n"
"    The connection to be removed from the node\n"
"    oacInvalidNodeConnType\n"
;

static PyObject*
oaNode_removeConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->removeConn(p1.Data());
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
static char oaNode_removeFromSubNetwork_doc[] = 
"Class: oaNode, Function: removeFromSubNetwork\n"
"  Paramegers: (oaSubNetwork)\n"
"    Calls: void removeFromSubNetwork(oaSubNetwork* subNetwork)\n"
"    Signature: removeFromSubNetwork|void-void|ptr-oaSubNetwork,\n"
"    This function removes this node from the specified subNetwork .\n"
"    subNetwork\n"
"    The sub-network from which this node is to be removed\n"
;

static PyObject*
oaNode_removeFromSubNetwork(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSubNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubNetwork_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->removeFromSubNetwork(p1.Data());
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
static char oaNode_setLayerNum_doc[] = 
"Class: oaNode, Function: setLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setLayerNum(oaLayerNum layer)\n"
"    Signature: setLayerNum|void-void|simple-oaLayerNum,\n"
"    This function sets the layer number of this node.\n"
"    layer\n"
"    The layer number to be associated with this node\n"
;

static PyObject*
oaNode_setLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->setLayerNum(p1.Data());
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
static char oaNode_setLocation_doc[] = 
"Class: oaNode, Function: setLocation\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void setLocation(const oaPoint& location)\n"
"    Signature: setLocation|void-void|cref-oaPoint,\n"
"    This function sets the location of this node.\n"
"    location\n"
"    A reference to an oaPoint object that holds the new location for this node\n"
;

static PyObject*
oaNode_setLocation(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->setLocation(p1.Data());
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
static char oaNode_setName_doc[] = 
"Class: oaNode, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this node.\n"
"    name\n"
"    A reference to an oaString object that holds the new name for this node\n"
"    oacNodeNameExists\n"
;

static PyObject*
oaNode_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaNodeObject* self=(PyoaNodeObject*)ob;
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
static char oaNode_isNull_doc[] =
"Class: oaNode, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaNode_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaNode data;
    int convert_status=PyoaNode_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaNode_assign_doc[] = 
"Class: oaNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaNode data;
  int convert_status=PyoaNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaNode_Convert,&p1)) {
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

static PyMethodDef oaNode_methodlist[] = {
    {"addConn",(PyCFunction)oaNode_addConn,METH_VARARGS,oaNode_addConn_doc},
    {"addToSubNetwork",(PyCFunction)oaNode_addToSubNetwork,METH_VARARGS,oaNode_addToSubNetwork_doc},
    {"destroy",(PyCFunction)oaNode_destroy,METH_VARARGS,oaNode_destroy_doc},
    {"getConns",(PyCFunction)oaNode_getConns,METH_VARARGS,oaNode_getConns_doc},
    {"getConnsIter",(PyCFunction)oaNode_getConnsIter,METH_VARARGS,oaNode_getConnsIter_doc},
    {"getFromDevices",(PyCFunction)oaNode_getFromDevices,METH_VARARGS,oaNode_getFromDevices_doc},
    {"getFromDevicesIter",(PyCFunction)oaNode_getFromDevicesIter,METH_VARARGS,oaNode_getFromDevicesIter_doc},
    {"getId",(PyCFunction)oaNode_getId,METH_VARARGS,oaNode_getId_doc},
    {"getLayerNum",(PyCFunction)oaNode_getLayerNum,METH_VARARGS,oaNode_getLayerNum_doc},
    {"getLocation",(PyCFunction)oaNode_getLocation,METH_VARARGS,oaNode_getLocation_doc},
    {"getName",(PyCFunction)oaNode_getName,METH_VARARGS,oaNode_getName_doc},
    {"getParasiticNetwork",(PyCFunction)oaNode_getParasiticNetwork,METH_VARARGS,oaNode_getParasiticNetwork_doc},
    {"getSubNetworks",(PyCFunction)oaNode_getSubNetworks,METH_VARARGS,oaNode_getSubNetworks_doc},
    {"getSubNetworksIter",(PyCFunction)oaNode_getSubNetworksIter,METH_VARARGS,oaNode_getSubNetworksIter_doc},
    {"getToDevices",(PyCFunction)oaNode_getToDevices,METH_VARARGS,oaNode_getToDevices_doc},
    {"getToDevicesIter",(PyCFunction)oaNode_getToDevicesIter,METH_VARARGS,oaNode_getToDevicesIter_doc},
    {"hasId",(PyCFunction)oaNode_hasId,METH_VARARGS,oaNode_hasId_doc},
    {"hasLayerNum",(PyCFunction)oaNode_hasLayerNum,METH_VARARGS,oaNode_hasLayerNum_doc},
    {"hasLocation",(PyCFunction)oaNode_hasLocation,METH_VARARGS,oaNode_hasLocation_doc},
    {"removeConn",(PyCFunction)oaNode_removeConn,METH_VARARGS,oaNode_removeConn_doc},
    {"removeFromSubNetwork",(PyCFunction)oaNode_removeFromSubNetwork,METH_VARARGS,oaNode_removeFromSubNetwork_doc},
    {"setLayerNum",(PyCFunction)oaNode_setLayerNum,METH_VARARGS,oaNode_setLayerNum_doc},
    {"setLocation",(PyCFunction)oaNode_setLocation,METH_VARARGS,oaNode_setLocation_doc},
    {"setName",(PyCFunction)oaNode_setName,METH_VARARGS,oaNode_setName_doc},
    {"isNull",(PyCFunction)oaNode_tp_isNull,METH_VARARGS,oaNode_isNull_doc},
    {"assign",(PyCFunction)oaNode_tp_assign,METH_VARARGS,oaNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNode_doc[] = 
"Class: oaNode\n"
"  The oaNode class represents nodes contained within an oaParasiticNetwork . Nodes connect devices, terms and instTerms. They can also describe the physical location of a point within the routing topology, which is useful when a long wire is broken into a series of distributed parasitic elements. In that case, the layer and origin represent the position of the node along the wire. Capacitance between a node and an implicit ground can be represented using the oaGroundedNode derived class.\n"
"  Nodes are managed objects, but they can be loaded from disk into memory (and unloaded from memory back to disk) on request as part of the parasitic network to which they belong. A pointer to a node becomes invalid after the parasitic network to which it belongs has been unloaded.\n"
"  Nodes can have an integer ID that is chosen by the client that creates them. The ID is usually optional, but IDs are required for nodes that are to be connected to a coupling capacitor between two different networks. IDs are also required for nodes that are the endpoint of a device in a lower-level parasitic network partition. When specified, IDs must be unique across all of the nodes within the same parasitic network. The getUniqueId() function can be used to obtain consecutive unique IDs.\n"
"  Nodes can also have an optional name string chosen by the client that creates them. This is primarily useful for small custom designs, as assigning a separate name to every node in large digital designs is prohibitively expensive. Node names must be unique within the same parasitic network.\n"
"  Undo, properties, and groups are not supported for oaNode. Extensions on oaNode (and interPointer extensions that refer to an oaNode) are only accessible while the oaNode is loaded.\n"
"  The oaNode class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaNode)\n"
"    Calls: (const oaNode&)\n"
"    Signature: oaNode||cref-oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaNode",
    sizeof(PyoaNodeObject),
    0,
    (destructor)oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaNode_tp_repr,	/* tp_repr */
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
    oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaNode_static_create_doc[] = 
"Class: oaNode, Function: create\n"
"  Paramegers: (oaParasiticNetwork)\n"
"    Calls: oaNode* create(oaParasiticNetwork* network)\n"
"    Signature: create|ptr-oaNode|ptr-oaParasiticNetwork,\n"
"    This function creates a node belonging to the specified parasitic network. The node created does not have an ID associated with it. The hasId() function will return false for these nodes and the getId() function will return an oacInvalidNodeID value.\n"
"    network\n"
"    The parasitic network to which the created node will belong\n"
"  Paramegers: (oaParasiticNetwork,oaUInt4)\n"
"    Calls: oaNode* create(oaParasiticNetwork* network,oaUInt4 id)\n"
"    Signature: create|ptr-oaNode|ptr-oaParasiticNetwork,simple-oaUInt4,\n"
"    This function creates a node belonging to the specified parasitic network. An explicit unique node ID 'id' is required to be specified. An exception will be thrown if the 'id' is the reserved oacInvalidNodeID value or if a node with the specified 'id' value already exists. The hasId() function will return true for nodes created with these functions and the getId() function will return the user-specified node id.\n"
"    network\n"
"    The parasitic network to which the created node will belong\n"
"    id\n"
"    A unique ID to be associated with the node\n"
"    oacNodeIdExists\n"
"    oacInvalidNodeIdSpecified\n"
;

static PyObject*
oaNode_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaParasiticNetwork)
    {
        PyParamoaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaParasiticNetwork_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaNodep result= (oaNode::create(p1.Data()));
            return PyoaNode_FromoaNode(result);
        }
    }
    PyErr_Clear();
    // Case: (oaParasiticNetwork,oaUInt4)
    {
        PyParamoaParasiticNetwork p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaParasiticNetwork_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaNodep result= (oaNode::create(p1.Data(),p2.Data()));
            return PyoaNode_FromoaNode(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaNode, function: create, Choices are:\n"
        "    (oaParasiticNetwork)\n"
        "    (oaParasiticNetwork,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_static_find_doc[] = 
"Class: oaNode, Function: find\n"
"  Paramegers: (oaParasiticNetwork,oaUInt4)\n"
"    Calls: oaNode* find(const oaParasiticNetwork* network,oaUInt4 id)\n"
"    Signature: find|ptr-oaNode|cptr-oaParasiticNetwork,simple-oaUInt4,\n"
"    This function finds and returns the node with the specified id within network .\n"
"    network\n"
"    The parasitic network to search for the node\n"
"    id\n"
"    The unique ID of the node to look for\n"
"  Paramegers: (oaParasiticNetwork,oaString)\n"
"    Calls: oaNode* find(const oaParasiticNetwork* network,const oaString& name)\n"
"    Signature: find|ptr-oaNode|cptr-oaParasiticNetwork,cref-oaString,\n"
"    This function finds and returns the node with the specified name within network .\n"
"    network\n"
"    The parasitic network to search for the node\n"
"    name\n"
"    The name of the node to look for\n"
;

static PyObject*
oaNode_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaParasiticNetwork,oaUInt4)
    {
        PyParamoaParasiticNetwork p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaParasiticNetwork_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaNodep result= (oaNode::find(p1.Data(),p2.Data()));
            return PyoaNode_FromoaNode(result);
        }
    }
    PyErr_Clear();
    // Case: (oaParasiticNetwork,oaString)
    {
        PyParamoaParasiticNetwork p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaParasiticNetwork_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaNodep result= (oaNode::find(p1.Data(),p2.Data()));
            return PyoaNode_FromoaNode(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaNode, function: find, Choices are:\n"
        "    (oaParasiticNetwork,oaUInt4)\n"
        "    (oaParasiticNetwork,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaNode_static_getUniqueId_doc[] = 
"Class: oaNode, Function: getUniqueId\n"
"  Paramegers: (oaParasiticNetwork)\n"
"    Calls: oaUInt4 getUniqueId(oaParasiticNetwork* network)\n"
"    Signature: getUniqueId|simple-oaUInt4|ptr-oaParasiticNetwork,\n"
"    This function returns a unique ID for a node in network .\n"
"    network\n"
"    The parasitic network to determine the potential unique ID for this node\n"
;

static PyObject*
oaNode_static_getUniqueId(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParasiticNetwork_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaUInt4 result= (oaNode::getUniqueId(p1.Data()));
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
static char oaNode_static_isValidName_doc[] = 
"Class: oaNode, Function: isValidName\n"
"  Paramegers: (oaParasiticNetwork,oaString)\n"
"    Calls: oaBoolean isValidName(const oaParasiticNetwork* network,const oaString& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaParasiticNetwork,cref-oaString,\n"
"    This function returns a boolean value that indicates if the specified name is valid for a new oaNode object within the specified parasitic network .\n"
"    network\n"
"    The parasitic network in whose domain the name is to be validated\n"
"    name\n"
"    A reference to an oaString object holding the name to be validated\n"
;

static PyObject*
oaNode_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaParasiticNetwork p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaParasiticNetwork_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaNode::isValidName(p1.Data(),p2.Data()));
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
static PyMethodDef oaNode_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaNode_static_create,METH_VARARGS,oaNode_static_create_doc},
    {"static_find",(PyCFunction)oaNode_static_find,METH_VARARGS,oaNode_static_find_doc},
    {"static_getUniqueId",(PyCFunction)oaNode_static_getUniqueId,METH_VARARGS,oaNode_static_getUniqueId_doc},
    {"static_isValidName",(PyCFunction)oaNode_static_isValidName,METH_VARARGS,oaNode_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaNode",
           (PyObject*)(&PyoaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaNode\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaNode_Type.tp_dict;
    for(method=oaNode_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaNodeModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaNodeModTypeEnum_Convert(PyObject* ob,PyParamoaNodeModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameNodeModType")==0) { result->SetData(oacSetNameNodeModType); return 1;}
        if (strcasecmp(str,"oacSetLayerNodeModType")==0) { result->SetData(oacSetLayerNodeModType); return 1;}
        if (strcasecmp(str,"oacSetLocationNodeModType")==0) { result->SetData(oacSetLocationNodeModType); return 1;}
        if (strcasecmp(str,"oacSetValueNodeModType")==0) { result->SetData(oacSetValueNodeModType); return 1;}
        if (strcasecmp(str,"oacAddConnNodeModType")==0) { result->SetData(oacAddConnNodeModType); return 1;}
        if (strcasecmp(str,"oacRemoveConnNodeModType")==0) { result->SetData(oacRemoveConnNodeModType); return 1;}
        if (strcasecmp(str,"oacAddToSubNetworkNodeModType")==0) { result->SetData(oacAddToSubNetworkNodeModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromSubNetworkNodeModType")==0) { result->SetData(oacRemoveFromSubNetworkNodeModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaNodeModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaNodeModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(oaNodeModTypeEnum ob)
{
    if (ob==oacSetNameNodeModType) return PyString_FromString("oacSetNameNodeModType");
    if (ob==oacSetLayerNodeModType) return PyString_FromString("oacSetLayerNodeModType");
    if (ob==oacSetLocationNodeModType) return PyString_FromString("oacSetLocationNodeModType");
    if (ob==oacSetValueNodeModType) return PyString_FromString("oacSetValueNodeModType");
    if (ob==oacAddConnNodeModType) return PyString_FromString("oacAddConnNodeModType");
    if (ob==oacRemoveConnNodeModType) return PyString_FromString("oacRemoveConnNodeModType");
    if (ob==oacAddToSubNetworkNodeModType) return PyString_FromString("oacAddToSubNetworkNodeModType");
    if (ob==oacRemoveFromSubNetworkNodeModType) return PyString_FromString("oacRemoveFromSubNetworkNodeModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaNodeModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaNodeModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(oaNodeModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaNodeModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaNodeModTypeEnum_doc[] =
"Type convert function for enum: oaNodeModTypeEnum";
                               
static PyMethodDef PyoaNodeModTypeEnum_method =
  {"oaNodeModTypeEnum",(PyCFunction)PyoaNodeModTypeEnum_TypeFunction,METH_VARARGS,oaNodeModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaNodeModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameNodeModType");
    PyDict_SetItemString(mod_dict,"oacSetNameNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetLayerNodeModType");
    PyDict_SetItemString(mod_dict,"oacSetLayerNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetLocationNodeModType");
    PyDict_SetItemString(mod_dict,"oacSetLocationNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetValueNodeModType");
    PyDict_SetItemString(mod_dict,"oacSetValueNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddConnNodeModType");
    PyDict_SetItemString(mod_dict,"oacAddConnNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveConnNodeModType");
    PyDict_SetItemString(mod_dict,"oacRemoveConnNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToSubNetworkNodeModType");
    PyDict_SetItemString(mod_dict,"oacAddToSubNetworkNodeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromSubNetworkNodeModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromSubNetworkNodeModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaNodeModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaNodeModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaNodeModTypeEnum\n");
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
// Wrapper Implementation for Class: oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObjectObject* self = (PyoaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaObject)
    {
        PyParamoaObject p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObject_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaObject, Choices are:\n"
        "    (oaObject)\n"
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
oaObject_tp_dealloc(PyoaObjectObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObject_tp_repr(PyObject *ob)
{
    PyParamoaObject value;
    int convert_status=PyoaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObject v1;
    PyParamoaObject v2;
    int convert_status1=PyoaObject_Convert(ob1,&v1);
    int convert_status2=PyoaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObject_Convert(PyObject* ob,PyParamoaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaObject_Check(ob)) {
        result->SetData(  ((PyoaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObject_FromoaObject(oaObject** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaObject* data=*value;
        if (data->getType()==oacLayerArrayValueType) return PyoaLayerArrayValue_FromoaLayerArrayValue((oaLayerArrayValue**)value,borrow,lock);
        if (data->getType()==oacUInt8RangeValueType) return PyoaUInt8RangeValue_FromoaUInt8RangeValue((oaUInt8RangeValue**)value,borrow,lock);
        if (data->isDM()) return PyoaDMObject_FromoaDMObject((oaDMObject**)value,borrow,lock);
        if (data->isConstraintGroupHeader()) return PyoaConstraintGroupHeader_FromoaConstraintGroupHeader((oaConstraintGroupHeader**)value,borrow,lock);
        if (data->getType()==oacBoxArrayValueType) return PyoaBoxArrayValue_FromoaBoxArrayValue((oaBoxArrayValue**)value,borrow,lock);
        if (data->getType()==oacUInt8ValueType) return PyoaUInt8Value_FromoaUInt8Value((oaUInt8Value**)value,borrow,lock);
        if (data->getType()==oacInt1DTblValueType) return PyoaInt1DTblValue_FromoaInt1DTblValue((oaInt1DTblValue**)value,borrow,lock);
        if (data->isConstraintGroupMem()) return PyoaConstraintGroupMem_FromoaConstraintGroupMem((oaConstraintGroupMem**)value,borrow,lock);
        if (data->getType()==oacViaDef2DTblValueType) return PyoaViaDef2DTblValue_FromoaViaDef2DTblValue((oaViaDef2DTblValue**)value,borrow,lock);
        if (data->isTech()) return PyoaTechObject_FromoaTechObject((oaTechObject**)value,borrow,lock);
        if (data->getType()==oacBooleanValueType) return PyoaBooleanValue_FromoaBooleanValue((oaBooleanValue**)value,borrow,lock);
        if (data->isWafer()) return PyoaWaferObject_FromoaWaferObject((oaWaferObject**)value,borrow,lock);
        if (data->getType()==oacAntennaRatioArrayValueType) return PyoaAntennaRatioArrayValue_FromoaAntennaRatioArrayValue((oaAntennaRatioArrayValue**)value,borrow,lock);
        if (data->getType()==oacViaDefArrayValueType) return PyoaViaDefArrayValue_FromoaViaDefArrayValue((oaViaDefArrayValue**)value,borrow,lock);
        if (data->getType()==oacFltIntFltTblValueType) return PyoaFltIntFltTblValue_FromoaFltIntFltTblValue((oaFltIntFltTblValue**)value,borrow,lock);
        if (data->isDMData()) return PyoaDMData_FromoaDMData((oaDMData**)value,borrow,lock);
        if (data->isSession()) return PyoaSessionObject_FromoaSessionObject((oaSessionObject**)value,borrow,lock);
        if (data->isProp()) return PyoaProp_FromoaProp((oaProp**)value,borrow,lock);
        if (data->isGroup()) return PyoaGroup_FromoaGroup((oaGroup**)value,borrow,lock);
        if (data->isConstraint()) return PyoaConstraint_FromoaConstraint((oaConstraint**)value,borrow,lock);
        if (data->isConstraintParam()) return PyoaConstraintParam_FromoaConstraintParam((oaConstraintParam**)value,borrow,lock);
        if (data->getType()==oacIntFltTblValueType) return PyoaIntFltTblValue_FromoaIntFltTblValue((oaIntFltTblValue**)value,borrow,lock);
        if (data->isDesign()) return PyoaDesignObject_FromoaDesignObject((oaDesignObject**)value,borrow,lock);
        if (data->getType()==oacFlt2DTblValueType) return PyoaFlt2DTblValue_FromoaFlt2DTblValue((oaFlt2DTblValue**)value,borrow,lock);
        if (data->isConstraintGroup()) return PyoaConstraintGroup_FromoaConstraintGroup((oaConstraintGroup**)value,borrow,lock);
        if (data->getType()==oacFltValueType) return PyoaFltValue_FromoaFltValue((oaFltValue**)value,borrow,lock);
        if (data->getType()==oacValueArrayValueType) return PyoaValueArrayValue_FromoaValueArrayValue((oaValueArrayValue**)value,borrow,lock);
        if (data->getType()==oacLayerValueType) return PyoaLayerValue_FromoaLayerValue((oaLayerValue**)value,borrow,lock);
        if (data->isAppObject()) return PyoaAppObject_FromoaAppObject((oaAppObject**)value,borrow,lock);
        if (data->isGroupMember()) return PyoaGroupMember_FromoaGroupMember((oaGroupMember**)value,borrow,lock);
        if (data->getType()==oacIntDualIntArrayTblValueType) return PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue((oaIntDualIntArrayTblValue**)value,borrow,lock);
        if (data->getType()==oacAntennaRatioValueType) return PyoaAntennaRatioValue_FromoaAntennaRatioValue((oaAntennaRatioValue**)value,borrow,lock);
        if (data->getType()==oacIntValueType) return PyoaIntValue_FromoaIntValue((oaIntValue**)value,borrow,lock);
        if (data->getType()==oacFlt1DTblValueType) return PyoaFlt1DTblValue_FromoaFlt1DTblValue((oaFlt1DTblValue**)value,borrow,lock);
        if (data->getType()==oacDualInt1DTblValueType) return PyoaDualInt1DTblValue_FromoaDualInt1DTblValue((oaDualInt1DTblValue**)value,borrow,lock);
        if (data->getType()==oacDualIntValueType) return PyoaDualIntValue_FromoaDualIntValue((oaDualIntValue**)value,borrow,lock);
        if (data->getType()==oacIntRangeValueType) return PyoaIntRangeValue_FromoaIntRangeValue((oaIntRangeValue**)value,borrow,lock);
        if (data->getType()==oacInt2DTblValueType) return PyoaInt2DTblValue_FromoaInt2DTblValue((oaInt2DTblValue**)value,borrow,lock);
        PyObject* bself = PyoaObject_Type.tp_alloc(&PyoaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaObjectObject* self = (PyoaObjectObject*)bself;
        self->value = value;
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
PyObject* PyoaObject_FromoaObject(oaObject* data)
{
    if (data) {
        if (data->getType()==oacLayerArrayValueType) return PyoaLayerArrayValue_FromoaLayerArrayValue((oaLayerArrayValue*)data);
        if (data->getType()==oacUInt8RangeValueType) return PyoaUInt8RangeValue_FromoaUInt8RangeValue((oaUInt8RangeValue*)data);
        if (data->isDM()) return PyoaDMObject_FromoaDMObject((oaDMObject*)data);
        if (data->isConstraintGroupHeader()) return PyoaConstraintGroupHeader_FromoaConstraintGroupHeader((oaConstraintGroupHeader*)data);
        if (data->getType()==oacBoxArrayValueType) return PyoaBoxArrayValue_FromoaBoxArrayValue((oaBoxArrayValue*)data);
        if (data->getType()==oacUInt8ValueType) return PyoaUInt8Value_FromoaUInt8Value((oaUInt8Value*)data);
        if (data->getType()==oacInt1DTblValueType) return PyoaInt1DTblValue_FromoaInt1DTblValue((oaInt1DTblValue*)data);
        if (data->isConstraintGroupMem()) return PyoaConstraintGroupMem_FromoaConstraintGroupMem((oaConstraintGroupMem*)data);
        if (data->getType()==oacViaDef2DTblValueType) return PyoaViaDef2DTblValue_FromoaViaDef2DTblValue((oaViaDef2DTblValue*)data);
        if (data->isTech()) return PyoaTechObject_FromoaTechObject((oaTechObject*)data);
        if (data->getType()==oacBooleanValueType) return PyoaBooleanValue_FromoaBooleanValue((oaBooleanValue*)data);
        if (data->isWafer()) return PyoaWaferObject_FromoaWaferObject((oaWaferObject*)data);
        if (data->getType()==oacAntennaRatioArrayValueType) return PyoaAntennaRatioArrayValue_FromoaAntennaRatioArrayValue((oaAntennaRatioArrayValue*)data);
        if (data->getType()==oacViaDefArrayValueType) return PyoaViaDefArrayValue_FromoaViaDefArrayValue((oaViaDefArrayValue*)data);
        if (data->getType()==oacFltIntFltTblValueType) return PyoaFltIntFltTblValue_FromoaFltIntFltTblValue((oaFltIntFltTblValue*)data);
        if (data->isDMData()) return PyoaDMData_FromoaDMData((oaDMData*)data);
        if (data->isSession()) return PyoaSessionObject_FromoaSessionObject((oaSessionObject*)data);
        if (data->isProp()) return PyoaProp_FromoaProp((oaProp*)data);
        if (data->isGroup()) return PyoaGroup_FromoaGroup((oaGroup*)data);
        if (data->isConstraint()) return PyoaConstraint_FromoaConstraint((oaConstraint*)data);
        if (data->isConstraintParam()) return PyoaConstraintParam_FromoaConstraintParam((oaConstraintParam*)data);
        if (data->getType()==oacIntFltTblValueType) return PyoaIntFltTblValue_FromoaIntFltTblValue((oaIntFltTblValue*)data);
        if (data->isDesign()) return PyoaDesignObject_FromoaDesignObject((oaDesignObject*)data);
        if (data->getType()==oacFlt2DTblValueType) return PyoaFlt2DTblValue_FromoaFlt2DTblValue((oaFlt2DTblValue*)data);
        if (data->isConstraintGroup()) return PyoaConstraintGroup_FromoaConstraintGroup((oaConstraintGroup*)data);
        if (data->getType()==oacFltValueType) return PyoaFltValue_FromoaFltValue((oaFltValue*)data);
        if (data->getType()==oacValueArrayValueType) return PyoaValueArrayValue_FromoaValueArrayValue((oaValueArrayValue*)data);
        if (data->getType()==oacLayerValueType) return PyoaLayerValue_FromoaLayerValue((oaLayerValue*)data);
        if (data->isAppObject()) return PyoaAppObject_FromoaAppObject((oaAppObject*)data);
        if (data->isGroupMember()) return PyoaGroupMember_FromoaGroupMember((oaGroupMember*)data);
        if (data->getType()==oacIntDualIntArrayTblValueType) return PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue((oaIntDualIntArrayTblValue*)data);
        if (data->getType()==oacAntennaRatioValueType) return PyoaAntennaRatioValue_FromoaAntennaRatioValue((oaAntennaRatioValue*)data);
        if (data->getType()==oacIntValueType) return PyoaIntValue_FromoaIntValue((oaIntValue*)data);
        if (data->getType()==oacFlt1DTblValueType) return PyoaFlt1DTblValue_FromoaFlt1DTblValue((oaFlt1DTblValue*)data);
        if (data->getType()==oacDualInt1DTblValueType) return PyoaDualInt1DTblValue_FromoaDualInt1DTblValue((oaDualInt1DTblValue*)data);
        if (data->getType()==oacDualIntValueType) return PyoaDualIntValue_FromoaDualIntValue((oaDualIntValue*)data);
        if (data->getType()==oacIntRangeValueType) return PyoaIntRangeValue_FromoaIntRangeValue((oaIntRangeValue*)data);
        if (data->getType()==oacInt2DTblValueType) return PyoaInt2DTblValue_FromoaInt2DTblValue((oaInt2DTblValue*)data);
       PyObject* bself = PyoaObject_Type.tp_alloc(&PyoaObject_Type,0);
       if (bself == NULL) return bself;
       PyoaObjectObject* self = (PyoaObjectObject*)bself;
       self->data = data;
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
static char oaObject_getAppDefs_doc[] = 
"Class: oaObject, Function: getAppDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaAppDef_oaObject getAppDefs() const\n"
"    Signature: getAppDefs|simple-oaCollection_oaAppDef_oaObject|\n"
"    BrowseData: 1\n"
"    This function returns the collection of oaAppDef extensions defined on this object.\n"
;

static PyObject*
oaObject_getAppDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaAppDef_oaObject* result= new oaCollection_oaAppDef_oaObject(data.DataCall()->getAppDefs());
        return PyoaCollection_oaAppDef_oaObject_FromoaCollection_oaAppDef_oaObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getAppDefsIter_doc[] = 
"Class: oaObject, Function: getAppDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaAppDef getAppDefsIter() const\n"
"    Signature: getAppDefsIter|simple-oaIter_oaAppDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of oaAppDef extensions defined on this object.\n"
;

static PyObject*
oaObject_getAppDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaAppDef* result= new oaIter_oaAppDef(data.DataCall()->getAppDefs());
        return PyoaIter_oaAppDef_FromoaIter_oaAppDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getConstraintGroup_doc[] = 
"Class: oaObject, Function: getConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getConstraintGroup() const\n"
"    Signature: getConstraintGroup|ptr-oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    oaObject::getConstraintGroup\n"
"    This function returns the built-in constraint group for this object. If no constraint group previously existed, one will be created by this call. If the application is only reading existing constraints, it is more efficient to call hasConstraintGroup() first to determine whether a group exists before making this call.\n"
"    This constraint group is used to hold constraints that are applied directly to the given object. Constraints are applied by putting them in this group with oaConstraintGroupMem::create() . Both individual constraints and constraint groups may be placed in this constraint group.\n"
"    Objects in design, tech, and wafer databases have built-in constraint groups except that parasitic objects do not support them. DM and Session objects cannot have them.\n"
;

static PyObject*
oaObject_getConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupp result= (data.DataCall()->getConstraintGroup());
        return PyoaConstraintGroup_FromoaConstraintGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getDatabase_doc[] = 
"Class: oaObject, Function: getDatabase\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getDatabase() const\n"
"    Signature: getDatabase|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the database containing this object. The returned object will belong to one of the following classes: oaDesign , oaTech , oaWafer , oaLib or oaSession . When called on one of these database classes, getDatabase() will return a pointer to the object it is called on.\n"
"    oacNoObjectDB\n"
;

static PyObject*
oaObject_getDatabase(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaObjectp result= (data.DataCall()->getDatabase());
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
static char oaObject_getDomain_doc[] = 
"Class: oaObject, Function: getDomain\n"
"  Paramegers: ()\n"
"    Calls: oaDomain getDomain() const\n"
"    Signature: getDomain|simple-oaDomain|\n"
"    BrowseData: 1\n"
"    This function returns the domain of the object. For objects in Designs the domain specifies if it is part of the block, module, or occurrence hierarchies. Other design objects and all objects in other databases return oacNoDomain. See oaDomain for more information.\n"
;

static PyObject*
oaObject_getDomain(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDomain* result= new oaDomain(data.DataCall()->getDomain());
        return PyoaDomain_FromoaDomain(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupLeaders_doc[] = 
"Class: oaObject, Function: getGroupLeaders\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroupMember_oaObject getGroupLeaders() const\n"
"    Signature: getGroupLeaders|simple-oaCollection_oaGroupMember_oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaGroupMember objects that represent the relationship between this object and each of the groups of which this object is a leader.\n"
;

static PyObject*
oaObject_getGroupLeaders(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroupMember_oaObject* result= new oaCollection_oaGroupMember_oaObject(data.DataCall()->getGroupLeaders());
        return PyoaCollection_oaGroupMember_oaObject_FromoaCollection_oaGroupMember_oaObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupLeadersIter_doc[] = 
"Class: oaObject, Function: getGroupLeadersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroupMember getGroupLeadersIter() const\n"
"    Signature: getGroupLeadersIter|simple-oaIter_oaGroupMember|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaGroupMember objects that represent the relationship between this object and each of the groups of which this object is a leader.\n"
;

static PyObject*
oaObject_getGroupLeadersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaGroupMember* result= new oaIter_oaGroupMember(data.DataCall()->getGroupLeaders());
        return PyoaIter_oaGroupMember_FromoaIter_oaGroupMember(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupMems_doc[] = 
"Class: oaObject, Function: getGroupMems\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroupMember_oaObject getGroupMems() const\n"
"    Signature: getGroupMems|simple-oaCollection_oaGroupMember_oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the oaGroupMember objects that represent the relationship between this object and each of the groups to which this object belongs.\n"
"    oacInvalidGroupObject\n"
"    If called for an oaObject that is a database class, because a database cannot belong to a group\n"
;

static PyObject*
oaObject_getGroupMems(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroupMember_oaObject* result= new oaCollection_oaGroupMember_oaObject(data.DataCall()->getGroupMems());
        return PyoaCollection_oaGroupMember_oaObject_FromoaCollection_oaGroupMember_oaObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupMemsIter_doc[] = 
"Class: oaObject, Function: getGroupMemsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroupMember getGroupMemsIter() const\n"
"    Signature: getGroupMemsIter|simple-oaIter_oaGroupMember|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the oaGroupMember objects that represent the relationship between this object and each of the groups to which this object belongs.\n"
"    oacInvalidGroupObject\n"
"    If called for an oaObject that is a database class, because a database cannot belong to a group\n"
;

static PyObject*
oaObject_getGroupMemsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaGroupMember* result= new oaIter_oaGroupMember(data.DataCall()->getGroupMems());
        return PyoaIter_oaGroupMember_FromoaIter_oaGroupMember(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupsOwnedBy_doc[] = 
"Class: oaObject, Function: getGroupsOwnedBy\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroup_oaObject getGroupsOwnedBy() const\n"
"    Signature: getGroupsOwnedBy|simple-oaCollection_oaGroup_oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the oaGroups to which this object belongs. In other words, it may be helpful to think of the name of this function as \"get the Groups this object \\em is Owned By.\"\n"
"    Since the database classes cannot belong to groups, it is illegal to call this on an oaDesign , oaTech , oaWafer or oaLib .\n"
"    oacInvalidGroupObject\n"
"    If called for an oaObject that is a database class, because a database cannot belong to a group\n"
;

static PyObject*
oaObject_getGroupsOwnedBy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroup_oaObject* result= new oaCollection_oaGroup_oaObject(data.DataCall()->getGroupsOwnedBy());
        return PyoaCollection_oaGroup_oaObject_FromoaCollection_oaGroup_oaObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getGroupsOwnedByIter_doc[] = 
"Class: oaObject, Function: getGroupsOwnedByIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroup getGroupsOwnedByIter() const\n"
"    Signature: getGroupsOwnedByIter|simple-oaIter_oaGroup|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the oaGroups to which this object belongs. In other words, it may be helpful to think of the name of this function as \"get the Groups this object \\em is Owned By.\"\n"
"    Since the database classes cannot belong to groups, it is illegal to call this on an oaDesign , oaTech , oaWafer or oaLib .\n"
"    oacInvalidGroupObject\n"
"    If called for an oaObject that is a database class, because a database cannot belong to a group\n"
;

static PyObject*
oaObject_getGroupsOwnedByIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaGroup* result= new oaIter_oaGroup(data.DataCall()->getGroupsOwnedBy());
        return PyoaIter_oaGroup_FromoaIter_oaGroup(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getProps_doc[] = 
"Class: oaObject, Function: getProps\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaProp_oaObject getProps() const\n"
"    Signature: getProps|simple-oaCollection_oaProp_oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a collection of properties on this object.\n"
;

static PyObject*
oaObject_getProps(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaProp_oaObject* result= new oaCollection_oaProp_oaObject(data.DataCall()->getProps());
        return PyoaCollection_oaProp_oaObject_FromoaCollection_oaProp_oaObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getPropsIter_doc[] = 
"Class: oaObject, Function: getPropsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaProp getPropsIter() const\n"
"    Signature: getPropsIter|simple-oaIter_oaProp|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of properties on this object.\n"
;

static PyObject*
oaObject_getPropsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaProp* result= new oaIter_oaProp(data.DataCall()->getProps());
        return PyoaIter_oaProp_FromoaIter_oaProp(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_getType_doc[] = 
"Class: oaObject, Function: getType\n"
"  Paramegers: ()\n"
"    Calls: oaType getType() const\n"
"    Signature: getType|simple-oaType|\n"
"    BrowseData: 1\n"
"    This function returns the detailed type of the object as an #oaTypeEnum value.\n"
;

static PyObject*
oaObject_getType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaType* result= new oaType(data.DataCall()->getType());
        return PyoaType_FromoaType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObject_hasAppDef_doc[] = 
"Class: oaObject, Function: hasAppDef\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasAppDef() const\n"
"    Signature: hasAppDef|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a Boolean indicating whether or not this object has any appDef values associated with it.\n"
;

static PyObject*
oaObject_hasAppDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasAppDef());
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
static char oaObject_hasAssociate_doc[] = 
"Class: oaObject, Function: hasAssociate\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasAssociate() const\n"
"    Signature: hasAssociate|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is associated with a textDisplay object.\n"
;

static PyObject*
oaObject_hasAssociate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasAssociate());
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
static char oaObject_hasConstraintGroup_doc[] = 
"Class: oaObject, Function: hasConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasConstraintGroup() const\n"
"    Signature: hasConstraintGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaObject::hasConstraintGroup\n"
"    This function returns a boolean indicating whether or not there are constraints associated with this object.\n"
;

static PyObject*
oaObject_hasConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasConstraintGroup());
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
static char oaObject_hasProp_doc[] = 
"Class: oaObject, Function: hasProp\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasProp() const\n"
"    Signature: hasProp|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a Boolean indicating whether or not this object has any properties attached to it.\n"
;

static PyObject*
oaObject_hasProp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasProp());
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
static char oaObject_inGroup_doc[] = 
"Class: oaObject, Function: inGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean inGroup() const\n"
"    Signature: inGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is in any group.\n"
;

static PyObject*
oaObject_inGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->inGroup());
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
static char oaObject_isAppObject_doc[] = 
"Class: oaObject, Function: isAppObject\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isAppObject() const\n"
"    Signature: isAppObject|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is an extension object.\n"
;

static PyObject*
oaObject_isAppObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isAppObject());
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
static char oaObject_isConstraint_doc[] = 
"Class: oaObject, Function: isConstraint\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isConstraint() const\n"
"    Signature: isConstraint|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a constraint.\n"
;

static PyObject*
oaObject_isConstraint(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isConstraint());
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
static char oaObject_isConstraintGroup_doc[] = 
"Class: oaObject, Function: isConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isConstraintGroup() const\n"
"    Signature: isConstraintGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a constraint group.\n"
;

static PyObject*
oaObject_isConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isConstraintGroup());
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
static char oaObject_isConstraintGroupHeader_doc[] = 
"Class: oaObject, Function: isConstraintGroupHeader\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isConstraintGroupHeader() const\n"
"    Signature: isConstraintGroupHeader|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a constraint group header.\n"
;

static PyObject*
oaObject_isConstraintGroupHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isConstraintGroupHeader());
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
static char oaObject_isConstraintGroupMem_doc[] = 
"Class: oaObject, Function: isConstraintGroupMem\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isConstraintGroupMem() const\n"
"    Signature: isConstraintGroupMem|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a constraint group member.\n"
;

static PyObject*
oaObject_isConstraintGroupMem(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isConstraintGroupMem());
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
static char oaObject_isConstraintParam_doc[] = 
"Class: oaObject, Function: isConstraintParam\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isConstraintParam() const\n"
"    Signature: isConstraintParam|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a constraint parameter.\n"
;

static PyObject*
oaObject_isConstraintParam(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isConstraintParam());
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
static char oaObject_isDM_doc[] = 
"Class: oaObject, Function: isDM\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isDM() const\n"
"    Signature: isDM|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this object represents a design management object, false if not.\n"
;

static PyObject*
oaObject_isDM(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isDM());
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
static char oaObject_isDMData_doc[] = 
"Class: oaObject, Function: isDMData\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isDMData() const\n"
"    Signature: isDMData|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this object is a dmData object.\n"
;

static PyObject*
oaObject_isDMData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isDMData());
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
static char oaObject_isDesign_doc[] = 
"Class: oaObject, Function: isDesign\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isDesign() const\n"
"    Signature: isDesign|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is contained in a design database (design).\n"
;

static PyObject*
oaObject_isDesign(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isDesign());
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
static char oaObject_isGroup_doc[] = 
"Class: oaObject, Function: isGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isGroup() const\n"
"    Signature: isGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is a group object.\n"
;

static PyObject*
oaObject_isGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isGroup());
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
static char oaObject_isGroupMember_doc[] = 
"Class: oaObject, Function: isGroupMember\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isGroupMember() const\n"
"    Signature: isGroupMember|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is a group member object.\n"
;

static PyObject*
oaObject_isGroupMember(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isGroupMember());
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
static char oaObject_isProp_doc[] = 
"Class: oaObject, Function: isProp\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isProp() const\n"
"    Signature: isProp|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this object is a property object.\n"
;

static PyObject*
oaObject_isProp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isProp());
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
static char oaObject_isSession_doc[] = 
"Class: oaObject, Function: isSession\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isSession() const\n"
"    Signature: isSession|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this object represents an object that belongs to the session database, otherwise it returns false.\n"
;

static PyObject*
oaObject_isSession(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isSession());
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
static char oaObject_isTech_doc[] = 
"Class: oaObject, Function: isTech\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isTech() const\n"
"    Signature: isTech|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this object represents a technology database object, false if not.\n"
;

static PyObject*
oaObject_isTech(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isTech());
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
static char oaObject_isValid_doc[] = 
"Class: oaObject, Function: isValid\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isValid() const\n"
"    Signature: isValid|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function verifies that a pointer is a valid database object and that it is safe to use this pointer with other database object member functions. NULL values and pointers that are outside of the memory used by OpenAccess return false. Misaligned pointers return false. A pointer to an object that is deleted might or might not return false. If the location is re-used for another OpenAccess object, the function returns true. If the space is still unused, this function returns false.\n"
"    The isValid() function performs a hash table lookup as part of the validation process. Although the performance is as fast as possible, applications should not call this function more than necessary.\n"
;

static PyObject*
oaObject_isValid(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isValid());
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
static char oaObject_isWafer_doc[] = 
"Class: oaObject, Function: isWafer\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isWafer() const\n"
"    Signature: isWafer|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this object represents an object that belongs to the wafer database, otherwise it returns false.\n"
;

static PyObject*
oaObject_isWafer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObjectObject* self=(PyoaObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isWafer());
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
static char oaObject_isNull_doc[] =
"Class: oaObject, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaObject_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaObject data;
    int convert_status=PyoaObject_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaObject_assign_doc[] = 
"Class: oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObject data;
  int convert_status=PyoaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObject_Convert,&p1)) {
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

static PyMethodDef oaObject_methodlist[] = {
    {"getAppDefs",(PyCFunction)oaObject_getAppDefs,METH_VARARGS,oaObject_getAppDefs_doc},
    {"getAppDefsIter",(PyCFunction)oaObject_getAppDefsIter,METH_VARARGS,oaObject_getAppDefsIter_doc},
    {"getConstraintGroup",(PyCFunction)oaObject_getConstraintGroup,METH_VARARGS,oaObject_getConstraintGroup_doc},
    {"getDatabase",(PyCFunction)oaObject_getDatabase,METH_VARARGS,oaObject_getDatabase_doc},
    {"getDomain",(PyCFunction)oaObject_getDomain,METH_VARARGS,oaObject_getDomain_doc},
    {"getGroupLeaders",(PyCFunction)oaObject_getGroupLeaders,METH_VARARGS,oaObject_getGroupLeaders_doc},
    {"getGroupLeadersIter",(PyCFunction)oaObject_getGroupLeadersIter,METH_VARARGS,oaObject_getGroupLeadersIter_doc},
    {"getGroupMems",(PyCFunction)oaObject_getGroupMems,METH_VARARGS,oaObject_getGroupMems_doc},
    {"getGroupMemsIter",(PyCFunction)oaObject_getGroupMemsIter,METH_VARARGS,oaObject_getGroupMemsIter_doc},
    {"getGroupsOwnedBy",(PyCFunction)oaObject_getGroupsOwnedBy,METH_VARARGS,oaObject_getGroupsOwnedBy_doc},
    {"getGroupsOwnedByIter",(PyCFunction)oaObject_getGroupsOwnedByIter,METH_VARARGS,oaObject_getGroupsOwnedByIter_doc},
    {"getProps",(PyCFunction)oaObject_getProps,METH_VARARGS,oaObject_getProps_doc},
    {"getPropsIter",(PyCFunction)oaObject_getPropsIter,METH_VARARGS,oaObject_getPropsIter_doc},
    {"getType",(PyCFunction)oaObject_getType,METH_VARARGS,oaObject_getType_doc},
    {"hasAppDef",(PyCFunction)oaObject_hasAppDef,METH_VARARGS,oaObject_hasAppDef_doc},
    {"hasAssociate",(PyCFunction)oaObject_hasAssociate,METH_VARARGS,oaObject_hasAssociate_doc},
    {"hasConstraintGroup",(PyCFunction)oaObject_hasConstraintGroup,METH_VARARGS,oaObject_hasConstraintGroup_doc},
    {"hasProp",(PyCFunction)oaObject_hasProp,METH_VARARGS,oaObject_hasProp_doc},
    {"inGroup",(PyCFunction)oaObject_inGroup,METH_VARARGS,oaObject_inGroup_doc},
    {"isAppObject",(PyCFunction)oaObject_isAppObject,METH_VARARGS,oaObject_isAppObject_doc},
    {"isConstraint",(PyCFunction)oaObject_isConstraint,METH_VARARGS,oaObject_isConstraint_doc},
    {"isConstraintGroup",(PyCFunction)oaObject_isConstraintGroup,METH_VARARGS,oaObject_isConstraintGroup_doc},
    {"isConstraintGroupHeader",(PyCFunction)oaObject_isConstraintGroupHeader,METH_VARARGS,oaObject_isConstraintGroupHeader_doc},
    {"isConstraintGroupMem",(PyCFunction)oaObject_isConstraintGroupMem,METH_VARARGS,oaObject_isConstraintGroupMem_doc},
    {"isConstraintParam",(PyCFunction)oaObject_isConstraintParam,METH_VARARGS,oaObject_isConstraintParam_doc},
    {"isDM",(PyCFunction)oaObject_isDM,METH_VARARGS,oaObject_isDM_doc},
    {"isDMData",(PyCFunction)oaObject_isDMData,METH_VARARGS,oaObject_isDMData_doc},
    {"isDesign",(PyCFunction)oaObject_isDesign,METH_VARARGS,oaObject_isDesign_doc},
    {"isGroup",(PyCFunction)oaObject_isGroup,METH_VARARGS,oaObject_isGroup_doc},
    {"isGroupMember",(PyCFunction)oaObject_isGroupMember,METH_VARARGS,oaObject_isGroupMember_doc},
    {"isProp",(PyCFunction)oaObject_isProp,METH_VARARGS,oaObject_isProp_doc},
    {"isSession",(PyCFunction)oaObject_isSession,METH_VARARGS,oaObject_isSession_doc},
    {"isTech",(PyCFunction)oaObject_isTech,METH_VARARGS,oaObject_isTech_doc},
    {"isValid",(PyCFunction)oaObject_isValid,METH_VARARGS,oaObject_isValid_doc},
    {"isWafer",(PyCFunction)oaObject_isWafer,METH_VARARGS,oaObject_isWafer_doc},
    {"isNull",(PyCFunction)oaObject_tp_isNull,METH_VARARGS,oaObject_isNull_doc},
    {"assign",(PyCFunction)oaObject_tp_assign,METH_VARARGS,oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObject_doc[] = 
"Class: oaObject\n"
"  The oaObject class is an abstract class that is the base class for all persistent objects managed by the OpenAccess code. All managed objects in design databases, technology databases, and library databases are derived from oaObject. The oaObject class implements utility functions that apply generically to managed objects. See the Managed Classes section in the Programmers Guide for more discussion.\n"
"Constructors:\n"
"  Paramegers: (oaObject)\n"
"    Calls: (const oaObject&)\n"
"    Signature: oaObject||cref-oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObject",
    sizeof(PyoaObjectObject),
    0,
    (destructor)oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaObject_tp_repr,	/* tp_repr */
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
    oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObject",
           (PyObject*)(&PyoaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObject\n");
       return -1;
    }
    return 0;
}


// ==================================================================
// Array for class: oaObject
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObject_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObject_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaObject_ArrayObject* self = (PyoaObject_ArrayObject*)gself;
    self->borrow = 0;
    self->locks=NULL;
    static char *kwlist [] = { NULL } ;
    /* Case: () */ 
    {
        if (PyArg_ParseTuple(args,"")) {
            return gself;
        }
    }
    PyErr_Clear();
    /* Case: (int) */
    {
        int p1;
        if (PyArg_ParseTuple(args,(char*)"i",&p1)) {
            self->data.SetLen(p1);
            return gself;
        }
    }
    PyErr_Clear();
    /* Case: (oaObject_Array) */
    {
        PyParamoaObject_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObject_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObject_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaObject_Array)\n"
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
oaObject_Array_dealloc(PyObject* gself)
{
    PyoaObject_ArrayObject* self = (PyoaObject_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaObject_Array_str(PyObject *ob)
{
    PyParamoaObject_Array value;
    int convert_status=PyoaObject_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaObject_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaObject_Array_repr(PyObject *ob)
{
    PyParamoaObject_Array value;
    int convert_status=PyoaObject_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaObject_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaObject_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObject_Array p1;
    PyParamoaObject_Array p2;
    int s1=PyoaObject_Array_Convert(ob1,&p1);
    int s2=PyoaObject_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaObject_Array_CreateList(p1);
    PyObject* l2=PyoaObject_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaObject_Array_Convert(PyObject* ob,PyParamoaObject_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaObject_Array_Check(ob)) {
    PyoaObject_ArrayObject* self = (PyoaObject_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaObject data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaObject_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaObject data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaObject_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaObject_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaObject_Array_FromoaObject_Array(const oaObject_Array& value)
{
  PyObject* gself = PyoaObject_Array_Type.tp_alloc(&PyoaObject_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaObject_ArrayObject* self = (PyoaObject_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaObject_Array_FromoaObject_Array(PyTypeoaObject* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaObject_Array_Type.tp_alloc(&PyoaObject_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaObject_ArrayObject* self = (PyoaObject_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaObject_Array_CreateList(PyParamoaObject_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaObject_FromoaObject(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaObject_Array_assign_doc[] = 
"Class: oaObject_Array, Function: assign\n"
"  Paramegers: (oaObject_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaObject_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaObject_ArrayObject* self=(PyoaObject_ArrayObject*)ob;
  try {
    PyParamoaObject_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObject_Array_Convert,&p1)) {
        self->data=p1;
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
static char oaObject_Array_list_doc[] = 
"Class: oaObject_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaObject_Array_list(PyObject* ob, PyObject *args)
{
  PyoaObject_ArrayObject* self=(PyoaObject_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaObject_Array_CreateList(self->data);
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
static PyMethodDef oaObject_Array_methodlist[] = {
    {"assign",(PyCFunction)oaObject_Array_assign,METH_VARARGS,oaObject_Array_assign_doc},
    {"list",(PyCFunction)oaObject_Array_list,METH_VARARGS,oaObject_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaObject_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaObject_ArrayObject* self=(PyoaObject_ArrayObject*)ob;
  try {
    PyParamoaObject_Array data;
    int convert_status=PyoaObject_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaObject_FromoaObject(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaObject_Array_index_get_length(PyObject* ob)
{
    PyParamoaObject_Array data;
    int convert_status=PyoaObject_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaObject_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaObject_Array data;
    PyParamoaObject dataitem;
    int convert_status=PyoaObject_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaObject_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaObject_Array_doc[] =
"Class: oaObject_Array\n"
"  The oaObject_Array utility class provides an array of oaObject.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaObject_Array()\n"
"    Signature: oaObject_Array||\n"
"    This is the default constructor for the oaObject_Array class. This constructor creates an empty oaObject_Array.\n"
"  Paramegers: (oaObject_Array)\n"
"    Calls: (const oaObject_Array&)\n"
"    Signature: oaObject_Array||cref-oaObject_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaObject_Array_as_sequence = {
    (Pyoa_inquiry)oaObject_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaObject_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaObject_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaObject_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObject_Array",
    sizeof(PyoaObject_ArrayObject),
    0,
    oaObject_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaObject_Array_compare,    /* tp_compare */
    oaObject_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaObject_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaObject_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObject_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaObject_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaObject_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaObject_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObject_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaObject_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaObject_Array",
           (PyObject*)(&PyoaObject_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObject_Array\n");
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
// Wrapper Implementation for Class: oaObjectArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObjectArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObjectArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObjectArrayObject* self = (PyoaObjectArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaObject*)  new oaObjectArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaObject*)  new oaObjectArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObjectArray)
    {
        PyParamoaObjectArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaObjectArray_Convert,&p1)) {
            self->value = (oaArrayBase_oaObject*)  new oaObjectArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObjectArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaObjectArray)\n"
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
oaObjectArray_tp_dealloc(PyoaObjectArrayObject* self)
{
    if (!self->borrow) {
        delete (oaObjectArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObjectArray_tp_repr(PyObject *ob)
{
    PyParamoaObjectArray value;
    int convert_status=PyoaObjectArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaObjectArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObjectArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObjectArray v1;
    PyParamoaObjectArray v2;
    int convert_status1=PyoaObjectArray_Convert(ob1,&v1);
    int convert_status2=PyoaObjectArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObjectArray_Convert(PyObject* ob,PyParamoaObjectArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaObjectArray_Check(ob)) {
        result->SetData( (oaObjectArray*) ((PyoaObjectArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObjectArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObjectArray_FromoaObjectArray(oaObjectArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObjectArray_Type.tp_alloc(&PyoaObjectArray_Type,0);
        if (bself == NULL) return bself;
        PyoaObjectArrayObject* self = (PyoaObjectArrayObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObjectArray_doc[] = 
"Class: oaObjectArray\n"
"  The oaObjectArray class implements an array of oaObjects.\n"
"  Todo\n"
"  Check description of class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaObjectArray()\n"
"    Signature: oaObjectArray||simple-oaUInt4,\n"
"    This oaObjectArray constructor sets the number of values and allocates storage for them.\n"
"    sizeIn\n"
"    Number of values for the array\n"
"    Todo\n"
"    Check description of member function. Add description of each parameter.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObjectArray(oaUInt4 sizeIn)\n"
"    Signature: oaObjectArray||simple-oaUInt4,\n"
"    This oaObjectArray constructor sets the number of values and allocates storage for them.\n"
"    sizeIn\n"
"    Number of values for the array\n"
"    Todo\n"
"    Check description of member function. Add description of each parameter.\n"
"  Paramegers: (oaObjectArray)\n"
"    Calls: oaObjectArray(const oaObjectArray& arrayIn)\n"
"    Signature: oaObjectArray||cref-oaObjectArray,\n"
"    This oaObjectArray constructor sets the number of values and creates a copy of the specified oaObjectArray.\n"
"    arrayIn\n"
"    Array to be copied\n"
"    Todo\n"
"    Check description of member function. Add description of each parameter.\n"
"  Paramegers: (oaObjectArray)\n"
"    Calls: (const oaObjectArray&)\n"
"    Signature: oaObjectArray||cref-oaObjectArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObjectArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObjectArray",
    sizeof(PyoaObjectArrayObject),
    0,
    (destructor)oaObjectArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObjectArray_tp_compare,	/* tp_compare */
    (reprfunc)oaObjectArray_tp_repr,	/* tp_repr */
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
    oaObjectArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObjectArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObjectArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObjectArray_Type)<0) {
      printf("** PyType_Ready failed for: oaObjectArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObjectArray",
           (PyObject*)(&PyoaObjectArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObjectArray\n");
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
// Wrapper Implementation for Class: oaObserver_oaAnalysisLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAnalysisLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAnalysisLibObject* self = (PyoaObserver_oaAnalysisLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisLib(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisLib* p=new pyv_oaObserver_oaAnalysisLib(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisLib(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisLib* p=new pyv_oaObserver_oaAnalysisLib(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAnalysisLib)
    {
        PyParamoaObserver_oaAnalysisLib p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAnalysisLib_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAnalysisLib(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisLib* p=new pyv_oaObserver_oaAnalysisLib(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAnalysisLib, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAnalysisLib)\n"
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
oaObserver_oaAnalysisLib_tp_dealloc(PyoaObserver_oaAnalysisLibObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAnalysisLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisLib_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAnalysisLib value;
    int convert_status=PyoaObserver_oaAnalysisLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaAnalysisLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAnalysisLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAnalysisLib v1;
    PyParamoaObserver_oaAnalysisLib v2;
    int convert_status1=PyoaObserver_oaAnalysisLib_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAnalysisLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAnalysisLib_Convert(PyObject* ob,PyParamoaObserver_oaAnalysisLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAnalysisLib_Check(ob)) {
        result->SetData( (oaObserver_oaAnalysisLib*) ((PyoaObserver_oaAnalysisLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAnalysisLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAnalysisLib_FromoaObserver_oaAnalysisLib(oaObserver_oaAnalysisLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAnalysisLib_Type.tp_alloc(&PyoaObserver_oaAnalysisLib_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAnalysisLibObject* self = (PyoaObserver_oaAnalysisLibObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAnalysisLib::pyv_oaObserver_oaAnalysisLib(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAnalysisLib(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisLib::pyv_oaObserver_oaAnalysisLib(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAnalysisLib(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisLib::pyv_oaObserver_oaAnalysisLib(const oaObserver_oaAnalysisLib& p)
 : pyob(NULL),
   oaObserver_oaAnalysisLib(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisLib::onPostCreate(oaAnalysisLib* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisLib_FromoaAnalysisLib(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisLib::onPostModify(oaAnalysisLib* p1,oaAnalysisLibModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisLib_FromoaAnalysisLib(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisLibModTypeEnum_FromoaAnalysisLibModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisLib::onPreDestroy(oaAnalysisLib* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisLib_FromoaAnalysisLib(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisLib::onPreModify(oaAnalysisLib* p1,oaAnalysisLibModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisLib_FromoaAnalysisLib(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisLibModTypeEnum_FromoaAnalysisLibModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisLib::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAnalysisLib_doc[] = 
"Class: oaObserver_oaAnalysisLib\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAnalysisLib(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAnalysisLib||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisLib\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAnalysisLib(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAnalysisLib||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisLib\n"
"  Paramegers: (oaObserver_oaAnalysisLib)\n"
"    Calls: (const oaObserver_oaAnalysisLib&)\n"
"    Signature: oaObserver_oaAnalysisLib||cref-oaObserver_oaAnalysisLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAnalysisLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAnalysisLib",
    sizeof(PyoaObserver_oaAnalysisLibObject),
    0,
    (destructor)oaObserver_oaAnalysisLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAnalysisLib_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAnalysisLib_tp_repr,	/* tp_repr */
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
    oaObserver_oaAnalysisLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAnalysisLib_oaAnalysisLibModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAnalysisLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAnalysisLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAnalysisLib_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAnalysisLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAnalysisLib",
           (PyObject*)(&PyoaObserver_oaAnalysisLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAnalysisLib\n");
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
// Wrapper Implementation for Class: oaObserver_oaAnalysisOpPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisOpPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAnalysisOpPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAnalysisOpPointObject* self = (PyoaObserver_oaAnalysisOpPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisOpPoint(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisOpPoint* p=new pyv_oaObserver_oaAnalysisOpPoint(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisOpPoint(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisOpPoint* p=new pyv_oaObserver_oaAnalysisOpPoint(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAnalysisOpPoint)
    {
        PyParamoaObserver_oaAnalysisOpPoint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAnalysisOpPoint_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAnalysisOpPoint(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisOpPoint* p=new pyv_oaObserver_oaAnalysisOpPoint(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAnalysisOpPoint, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAnalysisOpPoint)\n"
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
oaObserver_oaAnalysisOpPoint_tp_dealloc(PyoaObserver_oaAnalysisOpPointObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAnalysisOpPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisOpPoint_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAnalysisOpPoint value;
    int convert_status=PyoaObserver_oaAnalysisOpPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaAnalysisOpPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAnalysisOpPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAnalysisOpPoint v1;
    PyParamoaObserver_oaAnalysisOpPoint v2;
    int convert_status1=PyoaObserver_oaAnalysisOpPoint_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAnalysisOpPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAnalysisOpPoint_Convert(PyObject* ob,PyParamoaObserver_oaAnalysisOpPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAnalysisOpPoint_Check(ob)) {
        result->SetData( (oaObserver_oaAnalysisOpPoint*) ((PyoaObserver_oaAnalysisOpPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAnalysisOpPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAnalysisOpPoint_FromoaObserver_oaAnalysisOpPoint(oaObserver_oaAnalysisOpPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAnalysisOpPoint_Type.tp_alloc(&PyoaObserver_oaAnalysisOpPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAnalysisOpPointObject* self = (PyoaObserver_oaAnalysisOpPointObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAnalysisOpPoint::pyv_oaObserver_oaAnalysisOpPoint(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAnalysisOpPoint(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisOpPoint::pyv_oaObserver_oaAnalysisOpPoint(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAnalysisOpPoint(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisOpPoint::pyv_oaObserver_oaAnalysisOpPoint(const oaObserver_oaAnalysisOpPoint& p)
 : pyob(NULL),
   oaObserver_oaAnalysisOpPoint(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisOpPoint::onPostCreate(oaAnalysisOpPoint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisOpPoint_FromoaAnalysisOpPoint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisOpPoint::onPostModify(oaAnalysisOpPoint* p1,oaAnalysisOpPointModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisOpPoint_FromoaAnalysisOpPoint(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisOpPointModTypeEnum_FromoaAnalysisOpPointModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisOpPoint::onPreDestroy(oaAnalysisOpPoint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisOpPoint_FromoaAnalysisOpPoint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisOpPoint::onPreModify(oaAnalysisOpPoint* p1,oaAnalysisOpPointModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisOpPoint_FromoaAnalysisOpPoint(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisOpPointModTypeEnum_FromoaAnalysisOpPointModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisOpPoint::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAnalysisOpPoint_doc[] = 
"Class: oaObserver_oaAnalysisOpPoint\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAnalysisOpPoint(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAnalysisOpPoint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisOpPoint\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAnalysisOpPoint(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAnalysisOpPoint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisOpPoint\n"
"  Paramegers: (oaObserver_oaAnalysisOpPoint)\n"
"    Calls: (const oaObserver_oaAnalysisOpPoint&)\n"
"    Signature: oaObserver_oaAnalysisOpPoint||cref-oaObserver_oaAnalysisOpPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAnalysisOpPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAnalysisOpPoint",
    sizeof(PyoaObserver_oaAnalysisOpPointObject),
    0,
    (destructor)oaObserver_oaAnalysisOpPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAnalysisOpPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAnalysisOpPoint_tp_repr,	/* tp_repr */
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
    oaObserver_oaAnalysisOpPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAnalysisOpPoint_oaAnalysisOpPointModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAnalysisOpPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAnalysisOpPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAnalysisOpPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAnalysisOpPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAnalysisOpPoint",
           (PyObject*)(&PyoaObserver_oaAnalysisOpPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAnalysisOpPoint\n");
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
// Wrapper Implementation for Class: oaObserver_oaAnalysisPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAnalysisPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAnalysisPointObject* self = (PyoaObserver_oaAnalysisPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisPoint(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisPoint* p=new pyv_oaObserver_oaAnalysisPoint(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAnalysisPoint(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisPoint* p=new pyv_oaObserver_oaAnalysisPoint(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAnalysisPoint)
    {
        PyParamoaObserver_oaAnalysisPoint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAnalysisPoint_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAnalysisPoint(p1.Data());
            }
            else {
                pyv_oaObserver_oaAnalysisPoint* p=new pyv_oaObserver_oaAnalysisPoint(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAnalysisPoint, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAnalysisPoint)\n"
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
oaObserver_oaAnalysisPoint_tp_dealloc(PyoaObserver_oaAnalysisPointObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAnalysisPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAnalysisPoint_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAnalysisPoint value;
    int convert_status=PyoaObserver_oaAnalysisPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaAnalysisPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAnalysisPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAnalysisPoint v1;
    PyParamoaObserver_oaAnalysisPoint v2;
    int convert_status1=PyoaObserver_oaAnalysisPoint_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAnalysisPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAnalysisPoint_Convert(PyObject* ob,PyParamoaObserver_oaAnalysisPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAnalysisPoint_Check(ob)) {
        result->SetData( (oaObserver_oaAnalysisPoint*) ((PyoaObserver_oaAnalysisPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAnalysisPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAnalysisPoint_FromoaObserver_oaAnalysisPoint(oaObserver_oaAnalysisPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAnalysisPoint_Type.tp_alloc(&PyoaObserver_oaAnalysisPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAnalysisPointObject* self = (PyoaObserver_oaAnalysisPointObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAnalysisPoint::pyv_oaObserver_oaAnalysisPoint(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAnalysisPoint(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisPoint::pyv_oaObserver_oaAnalysisPoint(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAnalysisPoint(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAnalysisPoint::pyv_oaObserver_oaAnalysisPoint(const oaObserver_oaAnalysisPoint& p)
 : pyob(NULL),
   oaObserver_oaAnalysisPoint(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisPoint::onPostCreate(oaAnalysisPoint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisPoint_FromoaAnalysisPoint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisPoint::onPostModify(oaAnalysisPoint* p1,oaAnalysisPointModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisPoint_FromoaAnalysisPoint(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisPointModTypeEnum_FromoaAnalysisPointModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisPoint::onPreDestroy(oaAnalysisPoint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAnalysisPoint_FromoaAnalysisPoint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAnalysisPoint::onPreModify(oaAnalysisPoint* p1,oaAnalysisPointModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAnalysisPoint_FromoaAnalysisPoint(p1));
    PyTuple_SetItem(args,1,PyoaAnalysisPointModTypeEnum_FromoaAnalysisPointModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAnalysisPoint::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAnalysisPoint_doc[] = 
"Class: oaObserver_oaAnalysisPoint\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAnalysisPoint(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAnalysisPoint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisPoint\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAnalysisPoint(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAnalysisPoint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAnalysisPoint\n"
"  Paramegers: (oaObserver_oaAnalysisPoint)\n"
"    Calls: (const oaObserver_oaAnalysisPoint&)\n"
"    Signature: oaObserver_oaAnalysisPoint||cref-oaObserver_oaAnalysisPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAnalysisPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAnalysisPoint",
    sizeof(PyoaObserver_oaAnalysisPointObject),
    0,
    (destructor)oaObserver_oaAnalysisPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAnalysisPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAnalysisPoint_tp_repr,	/* tp_repr */
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
    oaObserver_oaAnalysisPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAnalysisPoint_oaAnalysisPointModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAnalysisPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAnalysisPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAnalysisPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAnalysisPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAnalysisPoint",
           (PyObject*)(&PyoaObserver_oaAnalysisPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAnalysisPoint\n");
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
// Wrapper Implementation for Class: oaObserver_oaAppDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAppDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAppDefObject* self = (PyoaObserver_oaAppDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAppDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaAppDef* p=new pyv_oaObserver_oaAppDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAppDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAppDef* p=new pyv_oaObserver_oaAppDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAppDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
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
oaObserver_oaAppDef_tp_dealloc(PyoaObserver_oaAppDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAppDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAppDef value;
    int convert_status=PyoaObserver_oaAppDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaAppDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAppDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAppDef v1;
    PyParamoaObserver_oaAppDef v2;
    int convert_status1=PyoaObserver_oaAppDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAppDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAppDef_Convert(PyObject* ob,PyParamoaObserver_oaAppDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAppDef_Check(ob)) {
        result->SetData( (oaObserver_oaAppDef*) ((PyoaObserver_oaAppDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAppDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAppDef_FromoaObserver_oaAppDef(oaObserver_oaAppDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAppDef_Type.tp_alloc(&PyoaObserver_oaAppDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAppDefObject* self = (PyoaObserver_oaAppDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAppDef::pyv_oaObserver_oaAppDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAppDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAppDef::pyv_oaObserver_oaAppDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAppDef(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppDef::onConflict(const oaString& p1,oaType p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onConflict");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onConflict was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaString_FromoaString(p1));
    PyTuple_SetItem(args,1,PyoaType_FromoaType(&p2,1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onConflict had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppDef::onPostModify(oaObject* p1,oaAppDef* p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaObject_FromoaObject(p1));
    PyTuple_SetItem(args,1,PyoaAppDef_FromoaAppDef(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppDef::onPreModify(oaObject* p1,oaAppDef* p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaObject_FromoaObject(p1));
    PyTuple_SetItem(args,1,PyoaAppDef_FromoaAppDef(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAppDef_onConflict_doc[] = 
"Class: oaObserver_oaAppDef, Function: onConflict\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: virtual void onConflict(const oaString& name,oaType type)\n"
"    Signature: onConflict|void-void|cref-oaString,simple-oaType,\n"
"    This function is called if there is a conflict between an application data definition ( oaAppDef ) and an exisiting application data definition.\n"
"    The application's derived class should implement this function to receive this notification.\n"
"    name\n"
"    name of the conflicting oaAppDef extension\n"
"    type\n"
"    type of the conflicting oaAppdef extension\n"
;

static PyObject*
oaObserver_oaAppDef_onConflict(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaAppDef data;
    int convert_status=PyoaObserver_oaAppDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaAppDefObject* self=(PyoaObserver_oaAppDefObject*)ob;

    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        data.DataCall()->oaObserver_oaAppDef::onConflict(p1.Data(),p2.Data());
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
static char oaObserver_oaAppDef_onPostModify_doc[] = 
"Class: oaObserver_oaAppDef, Function: onPostModify\n"
"  Paramegers: (oaObject,oaAppDef)\n"
"    Calls: virtual void onPostModify(oaObject* object,oaAppDef* appDef)\n"
"    Signature: onPostModify|void-void|ptr-oaObject,ptr-oaAppDef,\n"
"    This function is called after the extension defined by an oaAppDef has been set on some oaObject . The application's derived class should implement this function to receive notification after the extension value on an object has been set or modified.\n"
"    object\n"
"    A pointer to the object that has the modified extension\n"
"    appDef\n"
"    A pointer to the oaAppDef that defines the extension that was modified.\n"
;

static PyObject*
oaObserver_oaAppDef_onPostModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaAppDef data;
    int convert_status=PyoaObserver_oaAppDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaAppDefObject* self=(PyoaObserver_oaAppDefObject*)ob;

    PyParamoaObject p1;
    PyParamoaAppDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaAppDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        data.DataCall()->oaObserver_oaAppDef::onPostModify(p1.Data(),p2.Data());
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
static char oaObserver_oaAppDef_onPreModify_doc[] = 
"Class: oaObserver_oaAppDef, Function: onPreModify\n"
"  Paramegers: (oaObject,oaAppDef)\n"
"    Calls: virtual void onPreModify(oaObject* object,oaAppDef* appDef)\n"
"    Signature: onPreModify|void-void|ptr-oaObject,ptr-oaAppDef,\n"
"    This function is called before the extension defined by an oaAppDef is set on some oaObject . The application's derived class should implement this function to receive notification before the extension value on an object is set or modified.\n"
"    object\n"
"    A pointer to the object that will have the modified extension\n"
"    appDef\n"
"    A pointer to the oaAppDef that defines the extension to be modified.\n"
;

static PyObject*
oaObserver_oaAppDef_onPreModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaAppDef data;
    int convert_status=PyoaObserver_oaAppDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaAppDefObject* self=(PyoaObserver_oaAppDefObject*)ob;

    PyParamoaObject p1;
    PyParamoaAppDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaAppDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        data.DataCall()->oaObserver_oaAppDef::onPreModify(p1.Data(),p2.Data());
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

static char oaObserver_oaAppDef_assign_doc[] = 
"Class: oaObserver_oaAppDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaAppDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaAppDef data;
  int convert_status=PyoaObserver_oaAppDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaAppDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaAppDef_Convert,&p1)) {
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

static PyMethodDef oaObserver_oaAppDef_methodlist[] = {
    {"onConflict",(PyCFunction)oaObserver_oaAppDef_onConflict,METH_VARARGS,oaObserver_oaAppDef_onConflict_doc},
    {"onPostModify",(PyCFunction)oaObserver_oaAppDef_onPostModify,METH_VARARGS,oaObserver_oaAppDef_onPostModify_doc},
    {"onPreModify",(PyCFunction)oaObserver_oaAppDef_onPreModify,METH_VARARGS,oaObserver_oaAppDef_onPreModify_doc},
    {"assign",(PyCFunction)oaObserver_oaAppDef_tp_assign,METH_VARARGS,oaObserver_oaAppDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAppDef_doc[] = 
"Class: oaObserver_oaAppDef\n"
"  This base template class can be used to derive observers for extension objects. It supports preModify, postModify, and onConflict event notifications.\n"
"  See oaObserver for information on using OpenAccess observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAppDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAppDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAppDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAppDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppDef\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAppDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAppDef",
    sizeof(PyoaObserver_oaAppDefObject),
    0,
    (destructor)oaObserver_oaAppDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAppDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAppDef_tp_repr,	/* tp_repr */
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
    oaObserver_oaAppDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaAppDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAppDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAppDef_static_hasObservers_doc[] = 
"Class: oaObserver_oaAppDef, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaAppDef_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaAppDef::hasObservers());
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
static char oaObserver_oaAppDef_static_notifyOnConflictObservers_doc[] = 
"Class: oaObserver_oaAppDef, Function: notifyOnConflictObservers\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: void notifyOnConflictObservers(const oaString& name,oaType type)\n"
"    Signature: notifyOnConflictObservers|void-void|cref-oaString,simple-oaType,\n"
"    Function notifyOnConflictObservers\n"
;

static PyObject*
oaObserver_oaAppDef_static_notifyOnConflictObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        oaObserver_oaAppDef::notifyOnConflictObservers(p1.Data(),p2.Data());
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
static char oaObserver_oaAppDef_static_notifyPostModifyObservers_doc[] = 
"Class: oaObserver_oaAppDef, Function: notifyPostModifyObservers\n"
"  Paramegers: (oaObject,oaAppDef)\n"
"    Calls: void notifyPostModifyObservers(oaObject* object,oaAppDef* appDef)\n"
"    Signature: notifyPostModifyObservers|void-void|ptr-oaObject,ptr-oaAppDef,\n"
"    Function notifyPostModifyObservers\n"
;

static PyObject*
oaObserver_oaAppDef_static_notifyPostModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaAppDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaAppDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaObserver_oaAppDef::notifyPostModifyObservers(p1.Data(),p2.Data());
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
static char oaObserver_oaAppDef_static_notifyPreModifyObservers_doc[] = 
"Class: oaObserver_oaAppDef, Function: notifyPreModifyObservers\n"
"  Paramegers: (oaObject,oaAppDef)\n"
"    Calls: void notifyPreModifyObservers(oaObject* object,oaAppDef* appDef)\n"
"    Signature: notifyPreModifyObservers|void-void|ptr-oaObject,ptr-oaAppDef,\n"
"    Function notifyPreModifyObservers\n"
;

static PyObject*
oaObserver_oaAppDef_static_notifyPreModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaAppDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaAppDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaObserver_oaAppDef::notifyPreModifyObservers(p1.Data(),p2.Data());
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
static PyMethodDef oaObserver_oaAppDef_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaAppDef_static_hasObservers,METH_VARARGS,oaObserver_oaAppDef_static_hasObservers_doc},
    {"static_notifyOnConflictObservers",(PyCFunction)oaObserver_oaAppDef_static_notifyOnConflictObservers,METH_VARARGS,oaObserver_oaAppDef_static_notifyOnConflictObservers_doc},
    {"static_notifyPostModifyObservers",(PyCFunction)oaObserver_oaAppDef_static_notifyPostModifyObservers,METH_VARARGS,oaObserver_oaAppDef_static_notifyPostModifyObservers_doc},
    {"static_notifyPreModifyObservers",(PyCFunction)oaObserver_oaAppDef_static_notifyPreModifyObservers,METH_VARARGS,oaObserver_oaAppDef_static_notifyPreModifyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAppDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAppDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAppDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAppDef",
           (PyObject*)(&PyoaObserver_oaAppDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAppDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaAppDef_Type.tp_dict;
    for(method=oaObserver_oaAppDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaAppObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAppObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAppObjectObject* self = (PyoaObserver_oaAppObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAppObject(p1.Data());
            }
            else {
                pyv_oaObserver_oaAppObject* p=new pyv_oaObserver_oaAppObject(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAppObject(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAppObject* p=new pyv_oaObserver_oaAppObject(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAppObject)
    {
        PyParamoaObserver_oaAppObject p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAppObject_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAppObject(p1.Data());
            }
            else {
                pyv_oaObserver_oaAppObject* p=new pyv_oaObserver_oaAppObject(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAppObject, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAppObject)\n"
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
oaObserver_oaAppObject_tp_dealloc(PyoaObserver_oaAppObjectObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAppObject*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppObject_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAppObject value;
    int convert_status=PyoaObserver_oaAppObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaAppObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAppObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAppObject v1;
    PyParamoaObserver_oaAppObject v2;
    int convert_status1=PyoaObserver_oaAppObject_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAppObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAppObject_Convert(PyObject* ob,PyParamoaObserver_oaAppObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAppObject_Check(ob)) {
        result->SetData( (oaObserver_oaAppObject*) ((PyoaObserver_oaAppObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAppObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAppObject_FromoaObserver_oaAppObject(oaObserver_oaAppObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAppObject_Type.tp_alloc(&PyoaObserver_oaAppObject_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAppObjectObject* self = (PyoaObserver_oaAppObjectObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAppObject::pyv_oaObserver_oaAppObject(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAppObject(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAppObject::pyv_oaObserver_oaAppObject(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAppObject(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAppObject::pyv_oaObserver_oaAppObject(const oaObserver_oaAppObject& p)
 : pyob(NULL),
   oaObserver_oaAppObject(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppObject::onPostCreate(oaAppObject* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAppObject_FromoaAppObject(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppObject::onPostModify(oaAppObject* p1,oaAppObjectModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAppObject_FromoaAppObject(p1));
    PyTuple_SetItem(args,1,PyoaAppObjectModTypeEnum_FromoaAppObjectModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppObject::onPreDestroy(oaAppObject* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAppObject_FromoaAppObject(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppObject::onPreModify(oaAppObject* p1,oaAppObjectModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAppObject_FromoaAppObject(p1));
    PyTuple_SetItem(args,1,PyoaAppObjectModTypeEnum_FromoaAppObjectModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppObject::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAppObject_doc[] = 
"Class: oaObserver_oaAppObject\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAppObject(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAppObject||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppObject\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAppObject(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAppObject||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppObject\n"
"  Paramegers: (oaObserver_oaAppObject)\n"
"    Calls: (const oaObserver_oaAppObject&)\n"
"    Signature: oaObserver_oaAppObject||cref-oaObserver_oaAppObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAppObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAppObject",
    sizeof(PyoaObserver_oaAppObjectObject),
    0,
    (destructor)oaObserver_oaAppObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAppObject_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAppObject_tp_repr,	/* tp_repr */
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
    oaObserver_oaAppObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAppObject_oaAppObjectModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAppObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAppObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAppObject_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAppObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAppObject",
           (PyObject*)(&PyoaObserver_oaAppObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAppObject\n");
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
// Wrapper Implementation for Class: oaObserver_oaAppProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAppProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAppPropObject* self = (PyoaObserver_oaAppPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAppProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaAppProp* p=new pyv_oaObserver_oaAppProp(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAppProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAppProp* p=new pyv_oaObserver_oaAppProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAppProp)
    {
        PyParamoaObserver_oaAppProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAppProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAppProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaAppProp* p=new pyv_oaObserver_oaAppProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAppProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAppProp)\n"
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
oaObserver_oaAppProp_tp_dealloc(PyoaObserver_oaAppPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAppProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAppProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAppProp value;
    int convert_status=PyoaObserver_oaAppProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaAppProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAppProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAppProp v1;
    PyParamoaObserver_oaAppProp v2;
    int convert_status1=PyoaObserver_oaAppProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAppProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAppProp_Convert(PyObject* ob,PyParamoaObserver_oaAppProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAppProp_Check(ob)) {
        result->SetData( (oaObserver_oaAppProp*) ((PyoaObserver_oaAppPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAppProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAppProp_FromoaObserver_oaAppProp(oaObserver_oaAppProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAppProp_Type.tp_alloc(&PyoaObserver_oaAppProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAppPropObject* self = (PyoaObserver_oaAppPropObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAppProp::pyv_oaObserver_oaAppProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAppProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAppProp::pyv_oaObserver_oaAppProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAppProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAppProp::pyv_oaObserver_oaAppProp(const oaObserver_oaAppProp& p)
 : pyob(NULL),
   oaObserver_oaAppProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppProp::onPostCreate(oaAppProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAppProp_FromoaAppProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppProp::onPostModify(oaAppProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAppProp_FromoaAppProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppProp::onPreDestroy(oaAppProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAppProp_FromoaAppProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAppProp::onPreModify(oaAppProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAppProp_FromoaAppProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAppProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAppProp_doc[] = 
"Class: oaObserver_oaAppProp\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAppProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAppProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAppProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAppProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAppProp\n"
"  Paramegers: (oaObserver_oaAppProp)\n"
"    Calls: (const oaObserver_oaAppProp&)\n"
"    Signature: oaObserver_oaAppProp||cref-oaObserver_oaAppProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAppProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAppProp",
    sizeof(PyoaObserver_oaAppPropObject),
    0,
    (destructor)oaObserver_oaAppProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAppProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAppProp_tp_repr,	/* tp_repr */
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
    oaObserver_oaAppProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAppProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAppProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAppProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAppProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAppProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAppProp",
           (PyObject*)(&PyoaObserver_oaAppProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAppProp\n");
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
// Wrapper Implementation for Class: oaObserver_oaArc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaArc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaArcObject* self = (PyoaObserver_oaArcObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaArc(p1.Data());
            }
            else {
                pyv_oaObserver_oaArc* p=new pyv_oaObserver_oaArc(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaArc(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaArc* p=new pyv_oaObserver_oaArc(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaArc)
    {
        PyParamoaObserver_oaArc p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaArc_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaArc(p1.Data());
            }
            else {
                pyv_oaObserver_oaArc* p=new pyv_oaObserver_oaArc(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaArc, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaArc)\n"
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
oaObserver_oaArc_tp_dealloc(PyoaObserver_oaArcObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaArc*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArc_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaArc value;
    int convert_status=PyoaObserver_oaArc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaObserver_oaArc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaArc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaArc v1;
    PyParamoaObserver_oaArc v2;
    int convert_status1=PyoaObserver_oaArc_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaArc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaArc_Convert(PyObject* ob,PyParamoaObserver_oaArc* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaArc_Check(ob)) {
        result->SetData( (oaObserver_oaArc*) ((PyoaObserver_oaArcObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaArc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaArc_FromoaObserver_oaArc(oaObserver_oaArc* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaArc_Type.tp_alloc(&PyoaObserver_oaArc_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaArcObject* self = (PyoaObserver_oaArcObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaArc::pyv_oaObserver_oaArc(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaArc(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArc::pyv_oaObserver_oaArc(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaArc(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArc::pyv_oaObserver_oaArc(const oaObserver_oaArc& p)
 : pyob(NULL),
   oaObserver_oaArc(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArc::onPostCreate(oaArc* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArc_FromoaArc(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArc::onPostModify(oaArc* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArc_FromoaArc(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArc::onPreDestroy(oaArc* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArc_FromoaArc(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArc::onPreModify(oaArc* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArc_FromoaArc(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArc::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaArc_doc[] = 
"Class: oaObserver_oaArc\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaArc(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaArc||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArc\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaArc(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaArc||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArc\n"
"  Paramegers: (oaObserver_oaArc)\n"
"    Calls: (const oaObserver_oaArc&)\n"
"    Signature: oaObserver_oaArc||cref-oaObserver_oaArc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaArc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaArc",
    sizeof(PyoaObserver_oaArcObject),
    0,
    (destructor)oaObserver_oaArc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaArc_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaArc_tp_repr,	/* tp_repr */
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
    oaObserver_oaArc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaArc_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaArc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaArc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaArc_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaArc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaArc",
           (PyObject*)(&PyoaObserver_oaArc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaArc\n");
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
// Wrapper Implementation for Class: oaObserver_oaAreaBlockage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaBlockage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAreaBlockage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAreaBlockageObject* self = (PyoaObserver_oaAreaBlockageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaBlockage* p=new pyv_oaObserver_oaAreaBlockage(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaBlockage(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAreaBlockage* p=new pyv_oaObserver_oaAreaBlockage(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAreaBlockage)
    {
        PyParamoaObserver_oaAreaBlockage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAreaBlockage_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAreaBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaBlockage* p=new pyv_oaObserver_oaAreaBlockage(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAreaBlockage, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAreaBlockage)\n"
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
oaObserver_oaAreaBlockage_tp_dealloc(PyoaObserver_oaAreaBlockageObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAreaBlockage*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaBlockage_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAreaBlockage value;
    int convert_status=PyoaObserver_oaAreaBlockage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaAreaBlockage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAreaBlockage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAreaBlockage v1;
    PyParamoaObserver_oaAreaBlockage v2;
    int convert_status1=PyoaObserver_oaAreaBlockage_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAreaBlockage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAreaBlockage_Convert(PyObject* ob,PyParamoaObserver_oaAreaBlockage* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAreaBlockage_Check(ob)) {
        result->SetData( (oaObserver_oaAreaBlockage*) ((PyoaObserver_oaAreaBlockageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAreaBlockage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAreaBlockage_FromoaObserver_oaAreaBlockage(oaObserver_oaAreaBlockage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAreaBlockage_Type.tp_alloc(&PyoaObserver_oaAreaBlockage_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAreaBlockageObject* self = (PyoaObserver_oaAreaBlockageObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAreaBlockage::pyv_oaObserver_oaAreaBlockage(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAreaBlockage(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaBlockage::pyv_oaObserver_oaAreaBlockage(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAreaBlockage(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaBlockage::pyv_oaObserver_oaAreaBlockage(const oaObserver_oaAreaBlockage& p)
 : pyob(NULL),
   oaObserver_oaAreaBlockage(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBlockage::onPostCreate(oaAreaBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaBlockage_FromoaAreaBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBlockage::onPostModify(oaAreaBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaBlockage_FromoaAreaBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBlockage::onPreDestroy(oaAreaBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaBlockage_FromoaAreaBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBlockage::onPreModify(oaAreaBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaBlockage_FromoaAreaBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBlockage::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAreaBlockage_doc[] = 
"Class: oaObserver_oaAreaBlockage\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAreaBlockage(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAreaBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaBlockage\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAreaBlockage(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAreaBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaBlockage\n"
"  Paramegers: (oaObserver_oaAreaBlockage)\n"
"    Calls: (const oaObserver_oaAreaBlockage&)\n"
"    Signature: oaObserver_oaAreaBlockage||cref-oaObserver_oaAreaBlockage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAreaBlockage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAreaBlockage",
    sizeof(PyoaObserver_oaAreaBlockageObject),
    0,
    (destructor)oaObserver_oaAreaBlockage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAreaBlockage_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAreaBlockage_tp_repr,	/* tp_repr */
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
    oaObserver_oaAreaBlockage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAreaBlockage_oaBlockageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAreaBlockage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAreaBlockage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAreaBlockage_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAreaBlockage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAreaBlockage",
           (PyObject*)(&PyoaObserver_oaAreaBlockage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAreaBlockage\n");
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
// Wrapper Implementation for Class: oaObserver_oaAreaBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAreaBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAreaBoundaryObject* self = (PyoaObserver_oaAreaBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaBoundary* p=new pyv_oaObserver_oaAreaBoundary(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaBoundary(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAreaBoundary* p=new pyv_oaObserver_oaAreaBoundary(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAreaBoundary)
    {
        PyParamoaObserver_oaAreaBoundary p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAreaBoundary_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAreaBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaBoundary* p=new pyv_oaObserver_oaAreaBoundary(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAreaBoundary, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAreaBoundary)\n"
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
oaObserver_oaAreaBoundary_tp_dealloc(PyoaObserver_oaAreaBoundaryObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAreaBoundary*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaBoundary_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAreaBoundary value;
    int convert_status=PyoaObserver_oaAreaBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaAreaBoundary::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAreaBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAreaBoundary v1;
    PyParamoaObserver_oaAreaBoundary v2;
    int convert_status1=PyoaObserver_oaAreaBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAreaBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAreaBoundary_Convert(PyObject* ob,PyParamoaObserver_oaAreaBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAreaBoundary_Check(ob)) {
        result->SetData( (oaObserver_oaAreaBoundary*) ((PyoaObserver_oaAreaBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAreaBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAreaBoundary_FromoaObserver_oaAreaBoundary(oaObserver_oaAreaBoundary* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAreaBoundary_Type.tp_alloc(&PyoaObserver_oaAreaBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAreaBoundaryObject* self = (PyoaObserver_oaAreaBoundaryObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAreaBoundary::pyv_oaObserver_oaAreaBoundary(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAreaBoundary(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaBoundary::pyv_oaObserver_oaAreaBoundary(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAreaBoundary(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaBoundary::pyv_oaObserver_oaAreaBoundary(const oaObserver_oaAreaBoundary& p)
 : pyob(NULL),
   oaObserver_oaAreaBoundary(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBoundary::onPostCreate(oaAreaBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaBoundary_FromoaAreaBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBoundary::onPostModify(oaAreaBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaBoundary_FromoaAreaBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBoundary::onPreDestroy(oaAreaBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaBoundary_FromoaAreaBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaBoundary::onPreModify(oaAreaBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaBoundary_FromoaAreaBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaBoundary::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAreaBoundary_doc[] = 
"Class: oaObserver_oaAreaBoundary\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAreaBoundary(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAreaBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaBoundary\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAreaBoundary(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAreaBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaBoundary\n"
"  Paramegers: (oaObserver_oaAreaBoundary)\n"
"    Calls: (const oaObserver_oaAreaBoundary&)\n"
"    Signature: oaObserver_oaAreaBoundary||cref-oaObserver_oaAreaBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAreaBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAreaBoundary",
    sizeof(PyoaObserver_oaAreaBoundaryObject),
    0,
    (destructor)oaObserver_oaAreaBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAreaBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAreaBoundary_tp_repr,	/* tp_repr */
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
    oaObserver_oaAreaBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAreaBoundary_oaBoundaryModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAreaBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAreaBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAreaBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAreaBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAreaBoundary",
           (PyObject*)(&PyoaObserver_oaAreaBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAreaBoundary\n");
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
// Wrapper Implementation for Class: oaObserver_oaAreaHalo
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaHalo_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAreaHalo_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAreaHaloObject* self = (PyoaObserver_oaAreaHaloObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaHalo(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaHalo* p=new pyv_oaObserver_oaAreaHalo(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAreaHalo(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAreaHalo* p=new pyv_oaObserver_oaAreaHalo(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAreaHalo)
    {
        PyParamoaObserver_oaAreaHalo p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAreaHalo_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAreaHalo(p1.Data());
            }
            else {
                pyv_oaObserver_oaAreaHalo* p=new pyv_oaObserver_oaAreaHalo(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAreaHalo, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAreaHalo)\n"
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
oaObserver_oaAreaHalo_tp_dealloc(PyoaObserver_oaAreaHaloObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAreaHalo*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAreaHalo_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAreaHalo value;
    int convert_status=PyoaObserver_oaAreaHalo_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaAreaHalo::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAreaHalo_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAreaHalo v1;
    PyParamoaObserver_oaAreaHalo v2;
    int convert_status1=PyoaObserver_oaAreaHalo_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAreaHalo_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAreaHalo_Convert(PyObject* ob,PyParamoaObserver_oaAreaHalo* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAreaHalo_Check(ob)) {
        result->SetData( (oaObserver_oaAreaHalo*) ((PyoaObserver_oaAreaHaloObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAreaHalo Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAreaHalo_FromoaObserver_oaAreaHalo(oaObserver_oaAreaHalo* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAreaHalo_Type.tp_alloc(&PyoaObserver_oaAreaHalo_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAreaHaloObject* self = (PyoaObserver_oaAreaHaloObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAreaHalo::pyv_oaObserver_oaAreaHalo(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAreaHalo(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaHalo::pyv_oaObserver_oaAreaHalo(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAreaHalo(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAreaHalo::pyv_oaObserver_oaAreaHalo(const oaObserver_oaAreaHalo& p)
 : pyob(NULL),
   oaObserver_oaAreaHalo(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaHalo::onPostCreate(oaAreaHalo* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaHalo_FromoaAreaHalo(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaHalo::onPostModify(oaAreaHalo* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaHalo_FromoaAreaHalo(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaHalo::onPreDestroy(oaAreaHalo* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAreaHalo_FromoaAreaHalo(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAreaHalo::onPreModify(oaAreaHalo* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAreaHalo_FromoaAreaHalo(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAreaHalo::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAreaHalo_doc[] = 
"Class: oaObserver_oaAreaHalo\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAreaHalo(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAreaHalo||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaHalo\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAreaHalo(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAreaHalo||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAreaHalo\n"
"  Paramegers: (oaObserver_oaAreaHalo)\n"
"    Calls: (const oaObserver_oaAreaHalo&)\n"
"    Signature: oaObserver_oaAreaHalo||cref-oaObserver_oaAreaHalo,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAreaHalo_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAreaHalo",
    sizeof(PyoaObserver_oaAreaHaloObject),
    0,
    (destructor)oaObserver_oaAreaHalo_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAreaHalo_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAreaHalo_tp_repr,	/* tp_repr */
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
    oaObserver_oaAreaHalo_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAreaHalo_oaBlockageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAreaHalo_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAreaHalo_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAreaHalo_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAreaHalo\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAreaHalo",
           (PyObject*)(&PyoaObserver_oaAreaHalo_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAreaHalo\n");
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
// Wrapper Implementation for Class: oaObserver_oaArrayInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArrayInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaArrayInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaArrayInstObject* self = (PyoaObserver_oaArrayInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaArrayInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaArrayInst* p=new pyv_oaObserver_oaArrayInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaArrayInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaArrayInst* p=new pyv_oaObserver_oaArrayInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaArrayInst)
    {
        PyParamoaObserver_oaArrayInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaArrayInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaArrayInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaArrayInst* p=new pyv_oaObserver_oaArrayInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaArrayInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaArrayInst)\n"
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
oaObserver_oaArrayInst_tp_dealloc(PyoaObserver_oaArrayInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaArrayInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArrayInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaArrayInst value;
    int convert_status=PyoaObserver_oaArrayInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaArrayInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaArrayInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaArrayInst v1;
    PyParamoaObserver_oaArrayInst v2;
    int convert_status1=PyoaObserver_oaArrayInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaArrayInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaArrayInst_Convert(PyObject* ob,PyParamoaObserver_oaArrayInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaArrayInst_Check(ob)) {
        result->SetData( (oaObserver_oaArrayInst*) ((PyoaObserver_oaArrayInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaArrayInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaArrayInst_FromoaObserver_oaArrayInst(oaObserver_oaArrayInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaArrayInst_Type.tp_alloc(&PyoaObserver_oaArrayInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaArrayInstObject* self = (PyoaObserver_oaArrayInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaArrayInst::pyv_oaObserver_oaArrayInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaArrayInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArrayInst::pyv_oaObserver_oaArrayInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaArrayInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArrayInst::pyv_oaObserver_oaArrayInst(const oaObserver_oaArrayInst& p)
 : pyob(NULL),
   oaObserver_oaArrayInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArrayInst::onPostCreate(oaArrayInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArrayInst_FromoaArrayInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArrayInst::onPostModify(oaArrayInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArrayInst_FromoaArrayInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArrayInst::onPreDestroy(oaArrayInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArrayInst_FromoaArrayInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArrayInst::onPreModify(oaArrayInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArrayInst_FromoaArrayInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArrayInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaArrayInst_doc[] = 
"Class: oaObserver_oaArrayInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaArrayInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaArrayInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArrayInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaArrayInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaArrayInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArrayInst\n"
"  Paramegers: (oaObserver_oaArrayInst)\n"
"    Calls: (const oaObserver_oaArrayInst&)\n"
"    Signature: oaObserver_oaArrayInst||cref-oaObserver_oaArrayInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaArrayInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaArrayInst",
    sizeof(PyoaObserver_oaArrayInstObject),
    0,
    (destructor)oaObserver_oaArrayInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaArrayInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaArrayInst_tp_repr,	/* tp_repr */
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
    oaObserver_oaArrayInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaArrayInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaArrayInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaArrayInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaArrayInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaArrayInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaArrayInst",
           (PyObject*)(&PyoaObserver_oaArrayInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaArrayInst\n");
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
// Wrapper Implementation for Class: oaObserver_oaArraySiteDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArraySiteDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaArraySiteDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaArraySiteDefObject* self = (PyoaObserver_oaArraySiteDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaArraySiteDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaArraySiteDef* p=new pyv_oaObserver_oaArraySiteDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaArraySiteDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaArraySiteDef* p=new pyv_oaObserver_oaArraySiteDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaArraySiteDef)
    {
        PyParamoaObserver_oaArraySiteDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaArraySiteDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaArraySiteDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaArraySiteDef* p=new pyv_oaObserver_oaArraySiteDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaArraySiteDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaArraySiteDef)\n"
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
oaObserver_oaArraySiteDef_tp_dealloc(PyoaObserver_oaArraySiteDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaArraySiteDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaArraySiteDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaArraySiteDef value;
    int convert_status=PyoaObserver_oaArraySiteDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaArraySiteDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaArraySiteDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaArraySiteDef v1;
    PyParamoaObserver_oaArraySiteDef v2;
    int convert_status1=PyoaObserver_oaArraySiteDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaArraySiteDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaArraySiteDef_Convert(PyObject* ob,PyParamoaObserver_oaArraySiteDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaArraySiteDef_Check(ob)) {
        result->SetData( (oaObserver_oaArraySiteDef*) ((PyoaObserver_oaArraySiteDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaArraySiteDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaArraySiteDef_FromoaObserver_oaArraySiteDef(oaObserver_oaArraySiteDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaArraySiteDef_Type.tp_alloc(&PyoaObserver_oaArraySiteDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaArraySiteDefObject* self = (PyoaObserver_oaArraySiteDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaArraySiteDef::pyv_oaObserver_oaArraySiteDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaArraySiteDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArraySiteDef::pyv_oaObserver_oaArraySiteDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaArraySiteDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaArraySiteDef::pyv_oaObserver_oaArraySiteDef(const oaObserver_oaArraySiteDef& p)
 : pyob(NULL),
   oaObserver_oaArraySiteDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArraySiteDef::onPostCreate(oaArraySiteDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArraySiteDef_FromoaArraySiteDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArraySiteDef::onPostModify(oaArraySiteDef* p1,oaSiteDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArraySiteDef_FromoaArraySiteDef(p1));
    PyTuple_SetItem(args,1,PyoaSiteDefModTypeEnum_FromoaSiteDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArraySiteDef::onPreDestroy(oaArraySiteDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaArraySiteDef_FromoaArraySiteDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaArraySiteDef::onPreModify(oaArraySiteDef* p1,oaSiteDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaArraySiteDef_FromoaArraySiteDef(p1));
    PyTuple_SetItem(args,1,PyoaSiteDefModTypeEnum_FromoaSiteDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaArraySiteDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaArraySiteDef_doc[] = 
"Class: oaObserver_oaArraySiteDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaArraySiteDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaArraySiteDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArraySiteDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaArraySiteDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaArraySiteDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaArraySiteDef\n"
"  Paramegers: (oaObserver_oaArraySiteDef)\n"
"    Calls: (const oaObserver_oaArraySiteDef&)\n"
"    Signature: oaObserver_oaArraySiteDef||cref-oaObserver_oaArraySiteDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaArraySiteDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaArraySiteDef",
    sizeof(PyoaObserver_oaArraySiteDefObject),
    0,
    (destructor)oaObserver_oaArraySiteDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaArraySiteDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaArraySiteDef_tp_repr,	/* tp_repr */
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
    oaObserver_oaArraySiteDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaArraySiteDef_oaSiteDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaArraySiteDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaArraySiteDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaArraySiteDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaArraySiteDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaArraySiteDef",
           (PyObject*)(&PyoaObserver_oaArraySiteDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaArraySiteDef\n");
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
// Wrapper Implementation for Class: oaObserver_oaAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAssignAssignmentObject* self = (PyoaObserver_oaAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignAssignment* p=new pyv_oaObserver_oaAssignAssignment(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAssignAssignment* p=new pyv_oaObserver_oaAssignAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAssignAssignment)
    {
        PyParamoaObserver_oaAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAssignAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignAssignment* p=new pyv_oaObserver_oaAssignAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAssignAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAssignAssignment)\n"
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
oaObserver_oaAssignAssignment_tp_dealloc(PyoaObserver_oaAssignAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAssignAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAssignAssignment value;
    int convert_status=PyoaObserver_oaAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaAssignAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAssignAssignment v1;
    PyParamoaObserver_oaAssignAssignment v2;
    int convert_status1=PyoaObserver_oaAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAssignAssignment_Convert(PyObject* ob,PyParamoaObserver_oaAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAssignAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaAssignAssignment*) ((PyoaObserver_oaAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAssignAssignment_FromoaObserver_oaAssignAssignment(oaObserver_oaAssignAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAssignAssignment_Type.tp_alloc(&PyoaObserver_oaAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAssignAssignmentObject* self = (PyoaObserver_oaAssignAssignmentObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAssignAssignment::pyv_oaObserver_oaAssignAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAssignAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignAssignment::pyv_oaObserver_oaAssignAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAssignAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignAssignment::pyv_oaObserver_oaAssignAssignment(const oaObserver_oaAssignAssignment& p)
 : pyob(NULL),
   oaObserver_oaAssignAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignAssignment::onPostCreate(oaAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignAssignment_FromoaAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignAssignment::onPostModify(oaAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignAssignment_FromoaAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignAssignment::onPreDestroy(oaAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignAssignment_FromoaAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignAssignment::onPreModify(oaAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignAssignment_FromoaAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAssignAssignment_doc[] = 
"Class: oaObserver_oaAssignAssignment\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAssignAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAssignAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignAssignment\n"
"  Paramegers: (oaObserver_oaAssignAssignment)\n"
"    Calls: (const oaObserver_oaAssignAssignment&)\n"
"    Signature: oaObserver_oaAssignAssignment||cref-oaObserver_oaAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAssignAssignment",
    sizeof(PyoaObserver_oaAssignAssignmentObject),
    0,
    (destructor)oaObserver_oaAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAssignAssignment_tp_repr,	/* tp_repr */
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
    oaObserver_oaAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAssignAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAssignAssignment",
           (PyObject*)(&PyoaObserver_oaAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAssignAssignment\n");
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
// Wrapper Implementation for Class: oaObserver_oaAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAssignValueObject* self = (PyoaObserver_oaAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignValue* p=new pyv_oaObserver_oaAssignValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAssignValue* p=new pyv_oaObserver_oaAssignValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAssignValue)
    {
        PyParamoaObserver_oaAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAssignValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignValue* p=new pyv_oaObserver_oaAssignValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAssignValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAssignValue)\n"
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
oaObserver_oaAssignValue_tp_dealloc(PyoaObserver_oaAssignValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAssignValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAssignValue value;
    int convert_status=PyoaObserver_oaAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaAssignValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAssignValue v1;
    PyParamoaObserver_oaAssignValue v2;
    int convert_status1=PyoaObserver_oaAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAssignValue_Convert(PyObject* ob,PyParamoaObserver_oaAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAssignValue_Check(ob)) {
        result->SetData( (oaObserver_oaAssignValue*) ((PyoaObserver_oaAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAssignValue_FromoaObserver_oaAssignValue(oaObserver_oaAssignValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAssignValue_Type.tp_alloc(&PyoaObserver_oaAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAssignValueObject* self = (PyoaObserver_oaAssignValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAssignValue::pyv_oaObserver_oaAssignValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAssignValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignValue::pyv_oaObserver_oaAssignValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAssignValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignValue::pyv_oaObserver_oaAssignValue(const oaObserver_oaAssignValue& p)
 : pyob(NULL),
   oaObserver_oaAssignValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignValue::onPostCreate(oaAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignValue_FromoaAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignValue::onPostModify(oaAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignValue_FromoaAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignValue::onPreDestroy(oaAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignValue_FromoaAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignValue::onPreModify(oaAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignValue_FromoaAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAssignValue_doc[] = 
"Class: oaObserver_oaAssignValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAssignValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAssignValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignValue\n"
"  Paramegers: (oaObserver_oaAssignValue)\n"
"    Calls: (const oaObserver_oaAssignValue&)\n"
"    Signature: oaObserver_oaAssignValue||cref-oaObserver_oaAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAssignValue",
    sizeof(PyoaObserver_oaAssignValueObject),
    0,
    (destructor)oaObserver_oaAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAssignValue_tp_repr,	/* tp_repr */
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
    oaObserver_oaAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAssignValue_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAssignValue",
           (PyObject*)(&PyoaObserver_oaAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAssignValue\n");
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
// Wrapper Implementation for Class: oaObserver_oaAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAssignmentObject* self = (PyoaObserver_oaAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignment* p=new pyv_oaObserver_oaAssignment(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAssignment* p=new pyv_oaObserver_oaAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAssignment)
    {
        PyParamoaObserver_oaAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaAssignment* p=new pyv_oaObserver_oaAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAssignment)\n"
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
oaObserver_oaAssignment_tp_dealloc(PyoaObserver_oaAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAssignment value;
    int convert_status=PyoaObserver_oaAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAssignment v1;
    PyParamoaObserver_oaAssignment v2;
    int convert_status1=PyoaObserver_oaAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAssignment_Convert(PyObject* ob,PyParamoaObserver_oaAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaAssignment*) ((PyoaObserver_oaAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAssignment_FromoaObserver_oaAssignment(oaObserver_oaAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAssignment_Type.tp_alloc(&PyoaObserver_oaAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAssignmentObject* self = (PyoaObserver_oaAssignmentObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAssignment::pyv_oaObserver_oaAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignment::pyv_oaObserver_oaAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAssignment::pyv_oaObserver_oaAssignment(const oaObserver_oaAssignment& p)
 : pyob(NULL),
   oaObserver_oaAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignment::onPostCreate(oaAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignment_FromoaAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignment::onPostModify(oaAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignment_FromoaAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignment::onPreDestroy(oaAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAssignment_FromoaAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAssignment::onPreModify(oaAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAssignment_FromoaAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAssignment_doc[] = 
"Class: oaObserver_oaAssignment\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAssignment\n"
"  Paramegers: (oaObserver_oaAssignment)\n"
"    Calls: (const oaObserver_oaAssignment&)\n"
"    Signature: oaObserver_oaAssignment||cref-oaObserver_oaAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAssignment",
    sizeof(PyoaObserver_oaAssignmentObject),
    0,
    (destructor)oaObserver_oaAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAssignment_tp_repr,	/* tp_repr */
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
    oaObserver_oaAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAssignment",
           (PyObject*)(&PyoaObserver_oaAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAssignment\n");
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
// Wrapper Implementation for Class: oaObserver_oaAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaAttrDisplayObject* self = (PyoaObserver_oaAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaAttrDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaAttrDisplay* p=new pyv_oaObserver_oaAttrDisplay(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaAttrDisplay(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaAttrDisplay* p=new pyv_oaObserver_oaAttrDisplay(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaAttrDisplay)
    {
        PyParamoaObserver_oaAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaAttrDisplay_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaAttrDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaAttrDisplay* p=new pyv_oaObserver_oaAttrDisplay(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaAttrDisplay, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaAttrDisplay)\n"
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
oaObserver_oaAttrDisplay_tp_dealloc(PyoaObserver_oaAttrDisplayObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaAttrDisplay*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaAttrDisplay value;
    int convert_status=PyoaObserver_oaAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaAttrDisplay v1;
    PyParamoaObserver_oaAttrDisplay v2;
    int convert_status1=PyoaObserver_oaAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaAttrDisplay_Convert(PyObject* ob,PyParamoaObserver_oaAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaAttrDisplay_Check(ob)) {
        result->SetData( (oaObserver_oaAttrDisplay*) ((PyoaObserver_oaAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaAttrDisplay_FromoaObserver_oaAttrDisplay(oaObserver_oaAttrDisplay* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaAttrDisplay_Type.tp_alloc(&PyoaObserver_oaAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaAttrDisplayObject* self = (PyoaObserver_oaAttrDisplayObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaAttrDisplay::pyv_oaObserver_oaAttrDisplay(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaAttrDisplay(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAttrDisplay::pyv_oaObserver_oaAttrDisplay(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaAttrDisplay(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaAttrDisplay::pyv_oaObserver_oaAttrDisplay(const oaObserver_oaAttrDisplay& p)
 : pyob(NULL),
   oaObserver_oaAttrDisplay(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAttrDisplay::onPostCreate(oaAttrDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAttrDisplay_FromoaAttrDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAttrDisplay::onPostModify(oaAttrDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAttrDisplay_FromoaAttrDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAttrDisplay::onPreDestroy(oaAttrDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaAttrDisplay_FromoaAttrDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaAttrDisplay::onPreModify(oaAttrDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaAttrDisplay_FromoaAttrDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaAttrDisplay::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaAttrDisplay_doc[] = 
"Class: oaObserver_oaAttrDisplay\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaAttrDisplay(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaAttrDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAttrDisplay\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaAttrDisplay(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaAttrDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaAttrDisplay\n"
"  Paramegers: (oaObserver_oaAttrDisplay)\n"
"    Calls: (const oaObserver_oaAttrDisplay&)\n"
"    Signature: oaObserver_oaAttrDisplay||cref-oaObserver_oaAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaAttrDisplay",
    sizeof(PyoaObserver_oaAttrDisplayObject),
    0,
    (destructor)oaObserver_oaAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaAttrDisplay_tp_repr,	/* tp_repr */
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
    oaObserver_oaAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaAttrDisplay_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaAttrDisplay",
           (PyObject*)(&PyoaObserver_oaAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaAttrDisplay\n");
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
// Wrapper Implementation for Class: oaObserver_oaBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBitInstObject* self = (PyoaObserver_oaBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitInst* p=new pyv_oaObserver_oaBitInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBitInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBitInst* p=new pyv_oaObserver_oaBitInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBitInst)
    {
        PyParamoaObserver_oaBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBitInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitInst* p=new pyv_oaObserver_oaBitInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBitInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBitInst)\n"
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
oaObserver_oaBitInst_tp_dealloc(PyoaObserver_oaBitInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBitInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBitInst value;
    int convert_status=PyoaObserver_oaBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaBitInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBitInst v1;
    PyParamoaObserver_oaBitInst v2;
    int convert_status1=PyoaObserver_oaBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBitInst_Convert(PyObject* ob,PyParamoaObserver_oaBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBitInst_Check(ob)) {
        result->SetData( (oaObserver_oaBitInst*) ((PyoaObserver_oaBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBitInst_FromoaObserver_oaBitInst(oaObserver_oaBitInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBitInst_Type.tp_alloc(&PyoaObserver_oaBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBitInstObject* self = (PyoaObserver_oaBitInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBitInst::pyv_oaObserver_oaBitInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBitInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitInst::pyv_oaObserver_oaBitInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBitInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitInst::pyv_oaObserver_oaBitInst(const oaObserver_oaBitInst& p)
 : pyob(NULL),
   oaObserver_oaBitInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitInst::onPostCreate(oaBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitInst_FromoaBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitInst::onPostModify(oaBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitInst_FromoaBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitInst::onPreDestroy(oaBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitInst_FromoaBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitInst::onPreModify(oaBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitInst_FromoaBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBitInst_doc[] = 
"Class: oaObserver_oaBitInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBitInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBitInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitInst\n"
"  Paramegers: (oaObserver_oaBitInst)\n"
"    Calls: (const oaObserver_oaBitInst&)\n"
"    Signature: oaObserver_oaBitInst||cref-oaObserver_oaBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBitInst",
    sizeof(PyoaObserver_oaBitInstObject),
    0,
    (destructor)oaObserver_oaBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBitInst_tp_repr,	/* tp_repr */
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
    oaObserver_oaBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBitInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBitInst",
           (PyObject*)(&PyoaObserver_oaBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBitInst\n");
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
// Wrapper Implementation for Class: oaObserver_oaBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBitNetObject* self = (PyoaObserver_oaBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitNet* p=new pyv_oaObserver_oaBitNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBitNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBitNet* p=new pyv_oaObserver_oaBitNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBitNet)
    {
        PyParamoaObserver_oaBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBitNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitNet* p=new pyv_oaObserver_oaBitNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBitNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBitNet)\n"
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
oaObserver_oaBitNet_tp_dealloc(PyoaObserver_oaBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBitNet value;
    int convert_status=PyoaObserver_oaBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBitNet v1;
    PyParamoaObserver_oaBitNet v2;
    int convert_status1=PyoaObserver_oaBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBitNet_Convert(PyObject* ob,PyParamoaObserver_oaBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBitNet_Check(ob)) {
        result->SetData( (oaObserver_oaBitNet*) ((PyoaObserver_oaBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBitNet_FromoaObserver_oaBitNet(oaObserver_oaBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBitNet_Type.tp_alloc(&PyoaObserver_oaBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBitNetObject* self = (PyoaObserver_oaBitNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBitNet::pyv_oaObserver_oaBitNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBitNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitNet::pyv_oaObserver_oaBitNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBitNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitNet::pyv_oaObserver_oaBitNet(const oaObserver_oaBitNet& p)
 : pyob(NULL),
   oaObserver_oaBitNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitNet::onPostCreate(oaBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitNet_FromoaBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitNet::onPostModify(oaBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitNet_FromoaBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitNet::onPreDestroy(oaBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitNet_FromoaBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitNet::onPreModify(oaBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitNet_FromoaBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBitNet_doc[] = 
"Class: oaObserver_oaBitNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBitNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBitNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitNet\n"
"  Paramegers: (oaObserver_oaBitNet)\n"
"    Calls: (const oaObserver_oaBitNet&)\n"
"    Signature: oaObserver_oaBitNet||cref-oaObserver_oaBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBitNet",
    sizeof(PyoaObserver_oaBitNetObject),
    0,
    (destructor)oaObserver_oaBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBitNet_tp_repr,	/* tp_repr */
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
    oaObserver_oaBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBitNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBitNet",
           (PyObject*)(&PyoaObserver_oaBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBitNet\n");
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
// Wrapper Implementation for Class: oaObserver_oaBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBitTermObject* self = (PyoaObserver_oaBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitTerm* p=new pyv_oaObserver_oaBitTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBitTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBitTerm* p=new pyv_oaObserver_oaBitTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBitTerm)
    {
        PyParamoaObserver_oaBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBitTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBitTerm* p=new pyv_oaObserver_oaBitTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBitTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBitTerm)\n"
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
oaObserver_oaBitTerm_tp_dealloc(PyoaObserver_oaBitTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBitTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBitTerm value;
    int convert_status=PyoaObserver_oaBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaBitTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBitTerm v1;
    PyParamoaObserver_oaBitTerm v2;
    int convert_status1=PyoaObserver_oaBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBitTerm_Convert(PyObject* ob,PyParamoaObserver_oaBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBitTerm_Check(ob)) {
        result->SetData( (oaObserver_oaBitTerm*) ((PyoaObserver_oaBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBitTerm_FromoaObserver_oaBitTerm(oaObserver_oaBitTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBitTerm_Type.tp_alloc(&PyoaObserver_oaBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBitTermObject* self = (PyoaObserver_oaBitTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBitTerm::pyv_oaObserver_oaBitTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBitTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitTerm::pyv_oaObserver_oaBitTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBitTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBitTerm::pyv_oaObserver_oaBitTerm(const oaObserver_oaBitTerm& p)
 : pyob(NULL),
   oaObserver_oaBitTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitTerm::onPostCreate(oaBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitTerm_FromoaBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitTerm::onPostModify(oaBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitTerm_FromoaBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitTerm::onPreDestroy(oaBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBitTerm_FromoaBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBitTerm::onPreModify(oaBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBitTerm_FromoaBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBitTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBitTerm_doc[] = 
"Class: oaObserver_oaBitTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBitTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBitTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBitTerm\n"
"  Paramegers: (oaObserver_oaBitTerm)\n"
"    Calls: (const oaObserver_oaBitTerm&)\n"
"    Signature: oaObserver_oaBitTerm||cref-oaObserver_oaBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBitTerm",
    sizeof(PyoaObserver_oaBitTermObject),
    0,
    (destructor)oaObserver_oaBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBitTerm_tp_repr,	/* tp_repr */
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
    oaObserver_oaBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBitTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBitTerm",
           (PyObject*)(&PyoaObserver_oaBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBitTerm\n");
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
// Wrapper Implementation for Class: oaObserver_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBlockObject* self = (PyoaObserver_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBlock(p1.Data());
            }
            else {
                pyv_oaObserver_oaBlock* p=new pyv_oaObserver_oaBlock(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBlock(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBlock* p=new pyv_oaObserver_oaBlock(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBlock)
    {
        PyParamoaObserver_oaBlock p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBlock_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBlock(p1.Data());
            }
            else {
                pyv_oaObserver_oaBlock* p=new pyv_oaObserver_oaBlock(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBlock, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBlock)\n"
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
oaObserver_oaBlock_tp_dealloc(PyoaObserver_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBlock value;
    int convert_status=PyoaObserver_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBlock v1;
    PyParamoaObserver_oaBlock v2;
    int convert_status1=PyoaObserver_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBlock_Convert(PyObject* ob,PyParamoaObserver_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBlock_Check(ob)) {
        result->SetData( (oaObserver_oaBlock*) ((PyoaObserver_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBlock_FromoaObserver_oaBlock(oaObserver_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBlock_Type.tp_alloc(&PyoaObserver_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBlockObject* self = (PyoaObserver_oaBlockObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBlock::pyv_oaObserver_oaBlock(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBlock(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBlock::pyv_oaObserver_oaBlock(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBlock(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBlock::pyv_oaObserver_oaBlock(const oaObserver_oaBlock& p)
 : pyob(NULL),
   oaObserver_oaBlock(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlock::onPostCreate(oaBlock* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBlock_FromoaBlock(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlock::onPostModify(oaBlock* p1,oaBlockModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBlock_FromoaBlock(p1));
    PyTuple_SetItem(args,1,PyoaBlockModTypeEnum_FromoaBlockModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlock::onPreDestroy(oaBlock* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBlock_FromoaBlock(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlock::onPreModify(oaBlock* p1,oaBlockModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBlock_FromoaBlock(p1));
    PyTuple_SetItem(args,1,PyoaBlockModTypeEnum_FromoaBlockModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlock::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBlock_doc[] = 
"Class: oaObserver_oaBlock\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBlock(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBlock||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBlock\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBlock(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBlock||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBlock\n"
"  Paramegers: (oaObserver_oaBlock)\n"
"    Calls: (const oaObserver_oaBlock&)\n"
"    Signature: oaObserver_oaBlock||cref-oaObserver_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBlock",
    sizeof(PyoaObserver_oaBlockObject),
    0,
    (destructor)oaObserver_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBlock_tp_repr,	/* tp_repr */
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
    oaObserver_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBlock_oaBlockModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBlock",
           (PyObject*)(&PyoaObserver_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBlock\n");
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
// Wrapper Implementation for Class: oaObserver_oaBlockage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBlockage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBlockage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBlockageObject* self = (PyoaObserver_oaBlockageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaBlockage* p=new pyv_oaObserver_oaBlockage(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBlockage(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBlockage* p=new pyv_oaObserver_oaBlockage(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBlockage)
    {
        PyParamoaObserver_oaBlockage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBlockage_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaBlockage* p=new pyv_oaObserver_oaBlockage(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBlockage, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBlockage)\n"
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
oaObserver_oaBlockage_tp_dealloc(PyoaObserver_oaBlockageObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBlockage*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBlockage_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBlockage value;
    int convert_status=PyoaObserver_oaBlockage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaBlockage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBlockage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBlockage v1;
    PyParamoaObserver_oaBlockage v2;
    int convert_status1=PyoaObserver_oaBlockage_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBlockage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBlockage_Convert(PyObject* ob,PyParamoaObserver_oaBlockage* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBlockage_Check(ob)) {
        result->SetData( (oaObserver_oaBlockage*) ((PyoaObserver_oaBlockageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBlockage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBlockage_FromoaObserver_oaBlockage(oaObserver_oaBlockage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBlockage_Type.tp_alloc(&PyoaObserver_oaBlockage_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBlockageObject* self = (PyoaObserver_oaBlockageObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBlockage::pyv_oaObserver_oaBlockage(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBlockage(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBlockage::pyv_oaObserver_oaBlockage(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBlockage(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBlockage::pyv_oaObserver_oaBlockage(const oaObserver_oaBlockage& p)
 : pyob(NULL),
   oaObserver_oaBlockage(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlockage::onPostCreate(oaBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBlockage_FromoaBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlockage::onPostModify(oaBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBlockage_FromoaBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlockage::onPreDestroy(oaBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBlockage_FromoaBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBlockage::onPreModify(oaBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBlockage_FromoaBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBlockage::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBlockage_doc[] = 
"Class: oaObserver_oaBlockage\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBlockage(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBlockage\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBlockage(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBlockage\n"
"  Paramegers: (oaObserver_oaBlockage)\n"
"    Calls: (const oaObserver_oaBlockage&)\n"
"    Signature: oaObserver_oaBlockage||cref-oaObserver_oaBlockage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBlockage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBlockage",
    sizeof(PyoaObserver_oaBlockageObject),
    0,
    (destructor)oaObserver_oaBlockage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBlockage_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBlockage_tp_repr,	/* tp_repr */
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
    oaObserver_oaBlockage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBlockage_oaBlockageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBlockage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBlockage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBlockage_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBlockage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBlockage",
           (PyObject*)(&PyoaObserver_oaBlockage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBlockage\n");
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
// Wrapper Implementation for Class: oaObserver_oaBooleanProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBooleanProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBooleanProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBooleanPropObject* self = (PyoaObserver_oaBooleanPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBooleanProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaBooleanProp* p=new pyv_oaObserver_oaBooleanProp(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBooleanProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBooleanProp* p=new pyv_oaObserver_oaBooleanProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBooleanProp)
    {
        PyParamoaObserver_oaBooleanProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBooleanProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBooleanProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaBooleanProp* p=new pyv_oaObserver_oaBooleanProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBooleanProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBooleanProp)\n"
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
oaObserver_oaBooleanProp_tp_dealloc(PyoaObserver_oaBooleanPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBooleanProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBooleanProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBooleanProp value;
    int convert_status=PyoaObserver_oaBooleanProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaBooleanProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBooleanProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBooleanProp v1;
    PyParamoaObserver_oaBooleanProp v2;
    int convert_status1=PyoaObserver_oaBooleanProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBooleanProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBooleanProp_Convert(PyObject* ob,PyParamoaObserver_oaBooleanProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBooleanProp_Check(ob)) {
        result->SetData( (oaObserver_oaBooleanProp*) ((PyoaObserver_oaBooleanPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBooleanProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBooleanProp_FromoaObserver_oaBooleanProp(oaObserver_oaBooleanProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBooleanProp_Type.tp_alloc(&PyoaObserver_oaBooleanProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBooleanPropObject* self = (PyoaObserver_oaBooleanPropObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBooleanProp::pyv_oaObserver_oaBooleanProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBooleanProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBooleanProp::pyv_oaObserver_oaBooleanProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBooleanProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBooleanProp::pyv_oaObserver_oaBooleanProp(const oaObserver_oaBooleanProp& p)
 : pyob(NULL),
   oaObserver_oaBooleanProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanProp::onPostCreate(oaBooleanProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBooleanProp_FromoaBooleanProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanProp::onPostModify(oaBooleanProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBooleanProp_FromoaBooleanProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanProp::onPreDestroy(oaBooleanProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBooleanProp_FromoaBooleanProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanProp::onPreModify(oaBooleanProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBooleanProp_FromoaBooleanProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBooleanProp_doc[] = 
"Class: oaObserver_oaBooleanProp\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBooleanProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBooleanProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBooleanProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBooleanProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBooleanProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBooleanProp\n"
"  Paramegers: (oaObserver_oaBooleanProp)\n"
"    Calls: (const oaObserver_oaBooleanProp&)\n"
"    Signature: oaObserver_oaBooleanProp||cref-oaObserver_oaBooleanProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBooleanProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBooleanProp",
    sizeof(PyoaObserver_oaBooleanPropObject),
    0,
    (destructor)oaObserver_oaBooleanProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBooleanProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBooleanProp_tp_repr,	/* tp_repr */
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
    oaObserver_oaBooleanProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBooleanProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBooleanProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBooleanProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBooleanProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBooleanProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBooleanProp",
           (PyObject*)(&PyoaObserver_oaBooleanProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBooleanProp\n");
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
// Wrapper Implementation for Class: oaObserver_oaBooleanValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBooleanValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBooleanValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBooleanValueObject* self = (PyoaObserver_oaBooleanValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBooleanValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaBooleanValue* p=new pyv_oaObserver_oaBooleanValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBooleanValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBooleanValue* p=new pyv_oaObserver_oaBooleanValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBooleanValue)
    {
        PyParamoaObserver_oaBooleanValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBooleanValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBooleanValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaBooleanValue* p=new pyv_oaObserver_oaBooleanValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBooleanValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBooleanValue)\n"
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
oaObserver_oaBooleanValue_tp_dealloc(PyoaObserver_oaBooleanValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBooleanValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBooleanValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBooleanValue value;
    int convert_status=PyoaObserver_oaBooleanValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaBooleanValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBooleanValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBooleanValue v1;
    PyParamoaObserver_oaBooleanValue v2;
    int convert_status1=PyoaObserver_oaBooleanValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBooleanValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBooleanValue_Convert(PyObject* ob,PyParamoaObserver_oaBooleanValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBooleanValue_Check(ob)) {
        result->SetData( (oaObserver_oaBooleanValue*) ((PyoaObserver_oaBooleanValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBooleanValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBooleanValue_FromoaObserver_oaBooleanValue(oaObserver_oaBooleanValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBooleanValue_Type.tp_alloc(&PyoaObserver_oaBooleanValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBooleanValueObject* self = (PyoaObserver_oaBooleanValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBooleanValue::pyv_oaObserver_oaBooleanValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBooleanValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBooleanValue::pyv_oaObserver_oaBooleanValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBooleanValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBooleanValue::pyv_oaObserver_oaBooleanValue(const oaObserver_oaBooleanValue& p)
 : pyob(NULL),
   oaObserver_oaBooleanValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanValue::onPostCreate(oaBooleanValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBooleanValue_FromoaBooleanValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanValue::onPostModify(oaBooleanValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBooleanValue_FromoaBooleanValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanValue::onPreDestroy(oaBooleanValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBooleanValue_FromoaBooleanValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBooleanValue::onPreModify(oaBooleanValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBooleanValue_FromoaBooleanValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBooleanValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBooleanValue_doc[] = 
"Class: oaObserver_oaBooleanValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBooleanValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBooleanValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBooleanValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBooleanValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBooleanValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBooleanValue\n"
"  Paramegers: (oaObserver_oaBooleanValue)\n"
"    Calls: (const oaObserver_oaBooleanValue&)\n"
"    Signature: oaObserver_oaBooleanValue||cref-oaObserver_oaBooleanValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBooleanValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBooleanValue",
    sizeof(PyoaObserver_oaBooleanValueObject),
    0,
    (destructor)oaObserver_oaBooleanValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBooleanValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBooleanValue_tp_repr,	/* tp_repr */
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
    oaObserver_oaBooleanValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBooleanValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBooleanValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBooleanValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBooleanValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBooleanValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBooleanValue",
           (PyObject*)(&PyoaObserver_oaBooleanValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBooleanValue\n");
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
// Wrapper Implementation for Class: oaObserver_oaBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBoundaryObject* self = (PyoaObserver_oaBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaBoundary* p=new pyv_oaObserver_oaBoundary(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBoundary(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBoundary* p=new pyv_oaObserver_oaBoundary(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBoundary)
    {
        PyParamoaObserver_oaBoundary p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBoundary_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaBoundary* p=new pyv_oaObserver_oaBoundary(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBoundary, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBoundary)\n"
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
oaObserver_oaBoundary_tp_dealloc(PyoaObserver_oaBoundaryObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBoundary*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBoundary_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBoundary value;
    int convert_status=PyoaObserver_oaBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaBoundary::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBoundary v1;
    PyParamoaObserver_oaBoundary v2;
    int convert_status1=PyoaObserver_oaBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBoundary_Convert(PyObject* ob,PyParamoaObserver_oaBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBoundary_Check(ob)) {
        result->SetData( (oaObserver_oaBoundary*) ((PyoaObserver_oaBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBoundary_FromoaObserver_oaBoundary(oaObserver_oaBoundary* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBoundary_Type.tp_alloc(&PyoaObserver_oaBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBoundaryObject* self = (PyoaObserver_oaBoundaryObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBoundary::pyv_oaObserver_oaBoundary(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBoundary(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBoundary::pyv_oaObserver_oaBoundary(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBoundary(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBoundary::pyv_oaObserver_oaBoundary(const oaObserver_oaBoundary& p)
 : pyob(NULL),
   oaObserver_oaBoundary(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoundary::onPostCreate(oaBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBoundary_FromoaBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoundary::onPostModify(oaBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBoundary_FromoaBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoundary::onPreDestroy(oaBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBoundary_FromoaBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoundary::onPreModify(oaBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBoundary_FromoaBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoundary::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBoundary_doc[] = 
"Class: oaObserver_oaBoundary\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBoundary(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBoundary\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBoundary(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBoundary\n"
"  Paramegers: (oaObserver_oaBoundary)\n"
"    Calls: (const oaObserver_oaBoundary&)\n"
"    Signature: oaObserver_oaBoundary||cref-oaObserver_oaBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBoundary",
    sizeof(PyoaObserver_oaBoundaryObject),
    0,
    (destructor)oaObserver_oaBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBoundary_tp_repr,	/* tp_repr */
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
    oaObserver_oaBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBoundary_oaBoundaryModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBoundary",
           (PyObject*)(&PyoaObserver_oaBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBoundary\n");
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
// Wrapper Implementation for Class: oaObserver_oaBoxArrayValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBoxArrayValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBoxArrayValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBoxArrayValueObject* self = (PyoaObserver_oaBoxArrayValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBoxArrayValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaBoxArrayValue* p=new pyv_oaObserver_oaBoxArrayValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBoxArrayValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBoxArrayValue* p=new pyv_oaObserver_oaBoxArrayValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBoxArrayValue)
    {
        PyParamoaObserver_oaBoxArrayValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBoxArrayValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBoxArrayValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaBoxArrayValue* p=new pyv_oaObserver_oaBoxArrayValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBoxArrayValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBoxArrayValue)\n"
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
oaObserver_oaBoxArrayValue_tp_dealloc(PyoaObserver_oaBoxArrayValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBoxArrayValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBoxArrayValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBoxArrayValue value;
    int convert_status=PyoaObserver_oaBoxArrayValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaBoxArrayValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBoxArrayValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBoxArrayValue v1;
    PyParamoaObserver_oaBoxArrayValue v2;
    int convert_status1=PyoaObserver_oaBoxArrayValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBoxArrayValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBoxArrayValue_Convert(PyObject* ob,PyParamoaObserver_oaBoxArrayValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBoxArrayValue_Check(ob)) {
        result->SetData( (oaObserver_oaBoxArrayValue*) ((PyoaObserver_oaBoxArrayValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBoxArrayValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBoxArrayValue_FromoaObserver_oaBoxArrayValue(oaObserver_oaBoxArrayValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBoxArrayValue_Type.tp_alloc(&PyoaObserver_oaBoxArrayValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBoxArrayValueObject* self = (PyoaObserver_oaBoxArrayValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBoxArrayValue::pyv_oaObserver_oaBoxArrayValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBoxArrayValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBoxArrayValue::pyv_oaObserver_oaBoxArrayValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBoxArrayValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBoxArrayValue::pyv_oaObserver_oaBoxArrayValue(const oaObserver_oaBoxArrayValue& p)
 : pyob(NULL),
   oaObserver_oaBoxArrayValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoxArrayValue::onPostCreate(oaBoxArrayValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBoxArrayValue_FromoaBoxArrayValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoxArrayValue::onPostModify(oaBoxArrayValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBoxArrayValue_FromoaBoxArrayValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoxArrayValue::onPreDestroy(oaBoxArrayValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBoxArrayValue_FromoaBoxArrayValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBoxArrayValue::onPreModify(oaBoxArrayValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBoxArrayValue_FromoaBoxArrayValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBoxArrayValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBoxArrayValue_doc[] = 
"Class: oaObserver_oaBoxArrayValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBoxArrayValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBoxArrayValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBoxArrayValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBoxArrayValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBoxArrayValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBoxArrayValue\n"
"  Paramegers: (oaObserver_oaBoxArrayValue)\n"
"    Calls: (const oaObserver_oaBoxArrayValue&)\n"
"    Signature: oaObserver_oaBoxArrayValue||cref-oaObserver_oaBoxArrayValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBoxArrayValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBoxArrayValue",
    sizeof(PyoaObserver_oaBoxArrayValueObject),
    0,
    (destructor)oaObserver_oaBoxArrayValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBoxArrayValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBoxArrayValue_tp_repr,	/* tp_repr */
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
    oaObserver_oaBoxArrayValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBoxArrayValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBoxArrayValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBoxArrayValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBoxArrayValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBoxArrayValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBoxArrayValue",
           (PyObject*)(&PyoaObserver_oaBoxArrayValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBoxArrayValue\n");
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
// Wrapper Implementation for Class: oaObserver_oaBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBundleNetObject* self = (PyoaObserver_oaBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBundleNet* p=new pyv_oaObserver_oaBundleNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBundleNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBundleNet* p=new pyv_oaObserver_oaBundleNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBundleNet)
    {
        PyParamoaObserver_oaBundleNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBundleNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBundleNet* p=new pyv_oaObserver_oaBundleNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBundleNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBundleNet)\n"
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
oaObserver_oaBundleNet_tp_dealloc(PyoaObserver_oaBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBundleNet value;
    int convert_status=PyoaObserver_oaBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBundleNet v1;
    PyParamoaObserver_oaBundleNet v2;
    int convert_status1=PyoaObserver_oaBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBundleNet_Convert(PyObject* ob,PyParamoaObserver_oaBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBundleNet_Check(ob)) {
        result->SetData( (oaObserver_oaBundleNet*) ((PyoaObserver_oaBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBundleNet_FromoaObserver_oaBundleNet(oaObserver_oaBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBundleNet_Type.tp_alloc(&PyoaObserver_oaBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBundleNetObject* self = (PyoaObserver_oaBundleNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBundleNet::pyv_oaObserver_oaBundleNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBundleNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBundleNet::pyv_oaObserver_oaBundleNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBundleNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBundleNet::pyv_oaObserver_oaBundleNet(const oaObserver_oaBundleNet& p)
 : pyob(NULL),
   oaObserver_oaBundleNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleNet::onPostCreate(oaBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBundleNet_FromoaBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleNet::onPostModify(oaBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBundleNet_FromoaBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleNet::onPreDestroy(oaBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBundleNet_FromoaBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleNet::onPreModify(oaBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBundleNet_FromoaBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBundleNet_doc[] = 
"Class: oaObserver_oaBundleNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBundleNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBundleNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBundleNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBundleNet\n"
"  Paramegers: (oaObserver_oaBundleNet)\n"
"    Calls: (const oaObserver_oaBundleNet&)\n"
"    Signature: oaObserver_oaBundleNet||cref-oaObserver_oaBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBundleNet",
    sizeof(PyoaObserver_oaBundleNetObject),
    0,
    (destructor)oaObserver_oaBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBundleNet_tp_repr,	/* tp_repr */
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
    oaObserver_oaBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBundleNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBundleNet",
           (PyObject*)(&PyoaObserver_oaBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBundleNet\n");
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
// Wrapper Implementation for Class: oaObserver_oaBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBundleTermObject* self = (PyoaObserver_oaBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBundleTerm* p=new pyv_oaObserver_oaBundleTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBundleTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBundleTerm* p=new pyv_oaObserver_oaBundleTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBundleTerm)
    {
        PyParamoaObserver_oaBundleTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBundleTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBundleTerm* p=new pyv_oaObserver_oaBundleTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBundleTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBundleTerm)\n"
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
oaObserver_oaBundleTerm_tp_dealloc(PyoaObserver_oaBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBundleTerm value;
    int convert_status=PyoaObserver_oaBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBundleTerm v1;
    PyParamoaObserver_oaBundleTerm v2;
    int convert_status1=PyoaObserver_oaBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBundleTerm_Convert(PyObject* ob,PyParamoaObserver_oaBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBundleTerm_Check(ob)) {
        result->SetData( (oaObserver_oaBundleTerm*) ((PyoaObserver_oaBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBundleTerm_FromoaObserver_oaBundleTerm(oaObserver_oaBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBundleTerm_Type.tp_alloc(&PyoaObserver_oaBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBundleTermObject* self = (PyoaObserver_oaBundleTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBundleTerm::pyv_oaObserver_oaBundleTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBundleTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBundleTerm::pyv_oaObserver_oaBundleTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBundleTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBundleTerm::pyv_oaObserver_oaBundleTerm(const oaObserver_oaBundleTerm& p)
 : pyob(NULL),
   oaObserver_oaBundleTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleTerm::onPostCreate(oaBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBundleTerm_FromoaBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleTerm::onPostModify(oaBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBundleTerm_FromoaBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleTerm::onPreDestroy(oaBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBundleTerm_FromoaBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBundleTerm::onPreModify(oaBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBundleTerm_FromoaBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBundleTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBundleTerm_doc[] = 
"Class: oaObserver_oaBundleTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBundleTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBundleTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBundleTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBundleTerm\n"
"  Paramegers: (oaObserver_oaBundleTerm)\n"
"    Calls: (const oaObserver_oaBundleTerm&)\n"
"    Signature: oaObserver_oaBundleTerm||cref-oaObserver_oaBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBundleTerm",
    sizeof(PyoaObserver_oaBundleTermObject),
    0,
    (destructor)oaObserver_oaBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBundleTerm_tp_repr,	/* tp_repr */
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
    oaObserver_oaBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBundleTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBundleTerm",
           (PyObject*)(&PyoaObserver_oaBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBundleTerm\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusNetObject* self = (PyoaObserver_oaBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNet* p=new pyv_oaObserver_oaBusNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusNet* p=new pyv_oaObserver_oaBusNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusNet)
    {
        PyParamoaObserver_oaBusNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNet* p=new pyv_oaObserver_oaBusNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusNet)\n"
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
oaObserver_oaBusNet_tp_dealloc(PyoaObserver_oaBusNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusNet value;
    int convert_status=PyoaObserver_oaBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaBusNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusNet v1;
    PyParamoaObserver_oaBusNet v2;
    int convert_status1=PyoaObserver_oaBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusNet_Convert(PyObject* ob,PyParamoaObserver_oaBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusNet_Check(ob)) {
        result->SetData( (oaObserver_oaBusNet*) ((PyoaObserver_oaBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusNet_FromoaObserver_oaBusNet(oaObserver_oaBusNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusNet_Type.tp_alloc(&PyoaObserver_oaBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusNetObject* self = (PyoaObserver_oaBusNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusNet::pyv_oaObserver_oaBusNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNet::pyv_oaObserver_oaBusNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNet::pyv_oaObserver_oaBusNet(const oaObserver_oaBusNet& p)
 : pyob(NULL),
   oaObserver_oaBusNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNet::onPostCreate(oaBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNet_FromoaBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNet::onPostModify(oaBusNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNet_FromoaBusNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNet::onPreDestroy(oaBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNet_FromoaBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNet::onPreModify(oaBusNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNet_FromoaBusNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusNet_doc[] = 
"Class: oaObserver_oaBusNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNet\n"
"  Paramegers: (oaObserver_oaBusNet)\n"
"    Calls: (const oaObserver_oaBusNet&)\n"
"    Signature: oaObserver_oaBusNet||cref-oaObserver_oaBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusNet",
    sizeof(PyoaObserver_oaBusNetObject),
    0,
    (destructor)oaObserver_oaBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusNet_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusNet",
           (PyObject*)(&PyoaObserver_oaBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusNet\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusNetBitObject* self = (PyoaObserver_oaBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNetBit* p=new pyv_oaObserver_oaBusNetBit(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNetBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusNetBit* p=new pyv_oaObserver_oaBusNetBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusNetBit)
    {
        PyParamoaObserver_oaBusNetBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusNetBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNetBit* p=new pyv_oaObserver_oaBusNetBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusNetBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusNetBit)\n"
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
oaObserver_oaBusNetBit_tp_dealloc(PyoaObserver_oaBusNetBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusNetBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusNetBit value;
    int convert_status=PyoaObserver_oaBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaBusNetBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusNetBit v1;
    PyParamoaObserver_oaBusNetBit v2;
    int convert_status1=PyoaObserver_oaBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusNetBit_Convert(PyObject* ob,PyParamoaObserver_oaBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusNetBit_Check(ob)) {
        result->SetData( (oaObserver_oaBusNetBit*) ((PyoaObserver_oaBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusNetBit_FromoaObserver_oaBusNetBit(oaObserver_oaBusNetBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusNetBit_Type.tp_alloc(&PyoaObserver_oaBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusNetBitObject* self = (PyoaObserver_oaBusNetBitObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusNetBit::pyv_oaObserver_oaBusNetBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusNetBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNetBit::pyv_oaObserver_oaBusNetBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusNetBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNetBit::pyv_oaObserver_oaBusNetBit(const oaObserver_oaBusNetBit& p)
 : pyob(NULL),
   oaObserver_oaBusNetBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetBit::onPostCreate(oaBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNetBit_FromoaBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetBit::onPostModify(oaBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNetBit_FromoaBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetBit::onPreDestroy(oaBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNetBit_FromoaBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetBit::onPreModify(oaBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNetBit_FromoaBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusNetBit_doc[] = 
"Class: oaObserver_oaBusNetBit\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusNetBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNetBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusNetBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNetBit\n"
"  Paramegers: (oaObserver_oaBusNetBit)\n"
"    Calls: (const oaObserver_oaBusNetBit&)\n"
"    Signature: oaObserver_oaBusNetBit||cref-oaObserver_oaBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusNetBit",
    sizeof(PyoaObserver_oaBusNetBitObject),
    0,
    (destructor)oaObserver_oaBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusNetBit_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusNetBit_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusNetBit",
           (PyObject*)(&PyoaObserver_oaBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusNetBit\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusNetDefObject* self = (PyoaObserver_oaBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNetDef* p=new pyv_oaObserver_oaBusNetDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusNetDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusNetDef* p=new pyv_oaObserver_oaBusNetDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusNetDef)
    {
        PyParamoaObserver_oaBusNetDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusNetDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusNetDef* p=new pyv_oaObserver_oaBusNetDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusNetDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusNetDef)\n"
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
oaObserver_oaBusNetDef_tp_dealloc(PyoaObserver_oaBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusNetDef value;
    int convert_status=PyoaObserver_oaBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusNetDef v1;
    PyParamoaObserver_oaBusNetDef v2;
    int convert_status1=PyoaObserver_oaBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusNetDef_Convert(PyObject* ob,PyParamoaObserver_oaBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusNetDef_Check(ob)) {
        result->SetData( (oaObserver_oaBusNetDef*) ((PyoaObserver_oaBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusNetDef_FromoaObserver_oaBusNetDef(oaObserver_oaBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusNetDef_Type.tp_alloc(&PyoaObserver_oaBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusNetDefObject* self = (PyoaObserver_oaBusNetDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusNetDef::pyv_oaObserver_oaBusNetDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusNetDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNetDef::pyv_oaObserver_oaBusNetDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusNetDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusNetDef::pyv_oaObserver_oaBusNetDef(const oaObserver_oaBusNetDef& p)
 : pyob(NULL),
   oaObserver_oaBusNetDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetDef::onPostCreate(oaBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNetDef_FromoaBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetDef::onPostModify(oaBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNetDef_FromoaBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetDef::onPreDestroy(oaBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusNetDef_FromoaBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusNetDef::onPreModify(oaBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusNetDef_FromoaBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusNetDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusNetDef_doc[] = 
"Class: oaObserver_oaBusNetDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusNetDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNetDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusNetDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusNetDef\n"
"  Paramegers: (oaObserver_oaBusNetDef)\n"
"    Calls: (const oaObserver_oaBusNetDef&)\n"
"    Signature: oaObserver_oaBusNetDef||cref-oaObserver_oaBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusNetDef",
    sizeof(PyoaObserver_oaBusNetDefObject),
    0,
    (destructor)oaObserver_oaBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusNetDef_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusNetDef_oaBusNetDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusNetDef",
           (PyObject*)(&PyoaObserver_oaBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusNetDef\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusTermObject* self = (PyoaObserver_oaBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTerm* p=new pyv_oaObserver_oaBusTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusTerm* p=new pyv_oaObserver_oaBusTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusTerm)
    {
        PyParamoaObserver_oaBusTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTerm* p=new pyv_oaObserver_oaBusTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusTerm)\n"
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
oaObserver_oaBusTerm_tp_dealloc(PyoaObserver_oaBusTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusTerm value;
    int convert_status=PyoaObserver_oaBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaBusTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusTerm v1;
    PyParamoaObserver_oaBusTerm v2;
    int convert_status1=PyoaObserver_oaBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusTerm_Convert(PyObject* ob,PyParamoaObserver_oaBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusTerm_Check(ob)) {
        result->SetData( (oaObserver_oaBusTerm*) ((PyoaObserver_oaBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusTerm_FromoaObserver_oaBusTerm(oaObserver_oaBusTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusTerm_Type.tp_alloc(&PyoaObserver_oaBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusTermObject* self = (PyoaObserver_oaBusTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusTerm::pyv_oaObserver_oaBusTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTerm::pyv_oaObserver_oaBusTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTerm::pyv_oaObserver_oaBusTerm(const oaObserver_oaBusTerm& p)
 : pyob(NULL),
   oaObserver_oaBusTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTerm::onPostCreate(oaBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTerm_FromoaBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTerm::onPostModify(oaBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTerm_FromoaBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTerm::onPreDestroy(oaBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTerm_FromoaBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTerm::onPreModify(oaBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTerm_FromoaBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusTerm_doc[] = 
"Class: oaObserver_oaBusTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTerm\n"
"  Paramegers: (oaObserver_oaBusTerm)\n"
"    Calls: (const oaObserver_oaBusTerm&)\n"
"    Signature: oaObserver_oaBusTerm||cref-oaObserver_oaBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusTerm",
    sizeof(PyoaObserver_oaBusTermObject),
    0,
    (destructor)oaObserver_oaBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusTerm_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusTerm",
           (PyObject*)(&PyoaObserver_oaBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusTerm\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusTermBitObject* self = (PyoaObserver_oaBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTermBit* p=new pyv_oaObserver_oaBusTermBit(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTermBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusTermBit* p=new pyv_oaObserver_oaBusTermBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusTermBit)
    {
        PyParamoaObserver_oaBusTermBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusTermBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTermBit* p=new pyv_oaObserver_oaBusTermBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusTermBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusTermBit)\n"
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
oaObserver_oaBusTermBit_tp_dealloc(PyoaObserver_oaBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusTermBit value;
    int convert_status=PyoaObserver_oaBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusTermBit v1;
    PyParamoaObserver_oaBusTermBit v2;
    int convert_status1=PyoaObserver_oaBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusTermBit_Convert(PyObject* ob,PyParamoaObserver_oaBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusTermBit_Check(ob)) {
        result->SetData( (oaObserver_oaBusTermBit*) ((PyoaObserver_oaBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusTermBit_FromoaObserver_oaBusTermBit(oaObserver_oaBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusTermBit_Type.tp_alloc(&PyoaObserver_oaBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusTermBitObject* self = (PyoaObserver_oaBusTermBitObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusTermBit::pyv_oaObserver_oaBusTermBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusTermBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTermBit::pyv_oaObserver_oaBusTermBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusTermBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTermBit::pyv_oaObserver_oaBusTermBit(const oaObserver_oaBusTermBit& p)
 : pyob(NULL),
   oaObserver_oaBusTermBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermBit::onPostCreate(oaBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTermBit_FromoaBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermBit::onPostModify(oaBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTermBit_FromoaBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermBit::onPreDestroy(oaBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTermBit_FromoaBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermBit::onPreModify(oaBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTermBit_FromoaBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusTermBit_doc[] = 
"Class: oaObserver_oaBusTermBit\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusTermBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTermBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusTermBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTermBit\n"
"  Paramegers: (oaObserver_oaBusTermBit)\n"
"    Calls: (const oaObserver_oaBusTermBit&)\n"
"    Signature: oaObserver_oaBusTermBit||cref-oaObserver_oaBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusTermBit",
    sizeof(PyoaObserver_oaBusTermBitObject),
    0,
    (destructor)oaObserver_oaBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusTermBit_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusTermBit_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusTermBit",
           (PyObject*)(&PyoaObserver_oaBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusTermBit\n");
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
// Wrapper Implementation for Class: oaObserver_oaBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaBusTermDefObject* self = (PyoaObserver_oaBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTermDef* p=new pyv_oaObserver_oaBusTermDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaBusTermDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaBusTermDef* p=new pyv_oaObserver_oaBusTermDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaBusTermDef)
    {
        PyParamoaObserver_oaBusTermDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaBusTermDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaBusTermDef* p=new pyv_oaObserver_oaBusTermDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaBusTermDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaBusTermDef)\n"
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
oaObserver_oaBusTermDef_tp_dealloc(PyoaObserver_oaBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaBusTermDef value;
    int convert_status=PyoaObserver_oaBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaBusTermDef v1;
    PyParamoaObserver_oaBusTermDef v2;
    int convert_status1=PyoaObserver_oaBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaBusTermDef_Convert(PyObject* ob,PyParamoaObserver_oaBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaBusTermDef_Check(ob)) {
        result->SetData( (oaObserver_oaBusTermDef*) ((PyoaObserver_oaBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaBusTermDef_FromoaObserver_oaBusTermDef(oaObserver_oaBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaBusTermDef_Type.tp_alloc(&PyoaObserver_oaBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaBusTermDefObject* self = (PyoaObserver_oaBusTermDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaBusTermDef::pyv_oaObserver_oaBusTermDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaBusTermDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTermDef::pyv_oaObserver_oaBusTermDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaBusTermDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaBusTermDef::pyv_oaObserver_oaBusTermDef(const oaObserver_oaBusTermDef& p)
 : pyob(NULL),
   oaObserver_oaBusTermDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermDef::onPostCreate(oaBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTermDef_FromoaBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermDef::onPostModify(oaBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTermDef_FromoaBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermDef::onPreDestroy(oaBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaBusTermDef_FromoaBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaBusTermDef::onPreModify(oaBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaBusTermDef_FromoaBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaBusTermDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaBusTermDef_doc[] = 
"Class: oaObserver_oaBusTermDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaBusTermDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTermDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaBusTermDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaBusTermDef\n"
"  Paramegers: (oaObserver_oaBusTermDef)\n"
"    Calls: (const oaObserver_oaBusTermDef&)\n"
"    Signature: oaObserver_oaBusTermDef||cref-oaObserver_oaBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaBusTermDef",
    sizeof(PyoaObserver_oaBusTermDefObject),
    0,
    (destructor)oaObserver_oaBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaBusTermDef_tp_repr,	/* tp_repr */
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
    oaObserver_oaBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaBusTermDef_oaBusTermDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaBusTermDef",
           (PyObject*)(&PyoaObserver_oaBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaBusTermDef\n");
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
// Wrapper Implementation for Class: oaObserver_oaCMap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCMap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCMap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCMapObject* self = (PyoaObserver_oaCMapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCMap(p1.Data());
            }
            else {
                pyv_oaObserver_oaCMap* p=new pyv_oaObserver_oaCMap(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCMap(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCMap* p=new pyv_oaObserver_oaCMap(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCMap)
    {
        PyParamoaObserver_oaCMap p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCMap_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCMap(p1.Data());
            }
            else {
                pyv_oaObserver_oaCMap* p=new pyv_oaObserver_oaCMap(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCMap, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCMap)\n"
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
oaObserver_oaCMap_tp_dealloc(PyoaObserver_oaCMapObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCMap*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCMap_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCMap value;
    int convert_status=PyoaObserver_oaCMap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaCMap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCMap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCMap v1;
    PyParamoaObserver_oaCMap v2;
    int convert_status1=PyoaObserver_oaCMap_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCMap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCMap_Convert(PyObject* ob,PyParamoaObserver_oaCMap* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCMap_Check(ob)) {
        result->SetData( (oaObserver_oaCMap*) ((PyoaObserver_oaCMapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCMap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCMap_FromoaObserver_oaCMap(oaObserver_oaCMap* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCMap_Type.tp_alloc(&PyoaObserver_oaCMap_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCMapObject* self = (PyoaObserver_oaCMapObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaCMap::pyv_oaObserver_oaCMap(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCMap(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCMap::pyv_oaObserver_oaCMap(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCMap(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCMap::pyv_oaObserver_oaCMap(const oaObserver_oaCMap& p)
 : pyob(NULL),
   oaObserver_oaCMap(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCMap::onPostCreate(oaCMap* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCMap_FromoaCMap(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCMap::onPostModify(oaCMap* p1,oaCMapModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCMap_FromoaCMap(p1));
    PyTuple_SetItem(args,1,PyoaCMapModTypeEnum_FromoaCMapModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCMap::onPreDestroy(oaCMap* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCMap_FromoaCMap(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCMap::onPreModify(oaCMap* p1,oaCMapModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCMap_FromoaCMap(p1));
    PyTuple_SetItem(args,1,PyoaCMapModTypeEnum_FromoaCMapModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCMap::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCMap_doc[] = 
"Class: oaObserver_oaCMap\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaCMap(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCMap||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCMap\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCMap(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCMap||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCMap\n"
"  Paramegers: (oaObserver_oaCMap)\n"
"    Calls: (const oaObserver_oaCMap&)\n"
"    Signature: oaObserver_oaCMap||cref-oaObserver_oaCMap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCMap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCMap",
    sizeof(PyoaObserver_oaCMapObject),
    0,
    (destructor)oaObserver_oaCMap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCMap_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCMap_tp_repr,	/* tp_repr */
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
    oaObserver_oaCMap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCMap_oaCMapModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCMap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCMap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCMap_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCMap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCMap",
           (PyObject*)(&PyoaObserver_oaCMap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCMap\n");
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
// Wrapper Implementation for Class: oaObserver_oaCell
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCell_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCell_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCellObject* self = (PyoaObserver_oaCellObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCell(p1.Data());
            }
            else {
                pyv_oaObserver_oaCell* p=new pyv_oaObserver_oaCell(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCell(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCell* p=new pyv_oaObserver_oaCell(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCell)
    {
        PyParamoaObserver_oaCell p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCell_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCell(p1.Data());
            }
            else {
                pyv_oaObserver_oaCell* p=new pyv_oaObserver_oaCell(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCell, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCell)\n"
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
oaObserver_oaCell_tp_dealloc(PyoaObserver_oaCellObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCell*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCell_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCell value;
    int convert_status=PyoaObserver_oaCell_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaCell::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCell_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCell v1;
    PyParamoaObserver_oaCell v2;
    int convert_status1=PyoaObserver_oaCell_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCell_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCell_Convert(PyObject* ob,PyParamoaObserver_oaCell* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCell_Check(ob)) {
        result->SetData( (oaObserver_oaCell*) ((PyoaObserver_oaCellObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCell Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCell_FromoaObserver_oaCell(oaObserver_oaCell* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCell_Type.tp_alloc(&PyoaObserver_oaCell_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCellObject* self = (PyoaObserver_oaCellObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaCell::pyv_oaObserver_oaCell(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCell(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCell::pyv_oaObserver_oaCell(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCell(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCell::pyv_oaObserver_oaCell(const oaObserver_oaCell& p)
 : pyob(NULL),
   oaObserver_oaCell(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCell::onPostCreate(oaCell* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCell_FromoaCell(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCell::onPostModify(oaCell* p1,oaCellModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCell_FromoaCell(p1));
    PyTuple_SetItem(args,1,PyoaCellModTypeEnum_FromoaCellModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCell::onPreDestroy(oaCell* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCell_FromoaCell(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCell::onPreModify(oaCell* p1,oaCellModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCell_FromoaCell(p1));
    PyTuple_SetItem(args,1,PyoaCellModTypeEnum_FromoaCellModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCell::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCell_doc[] = 
"Class: oaObserver_oaCell\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaCell(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCell||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCell\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCell(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCell||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCell\n"
"  Paramegers: (oaObserver_oaCell)\n"
"    Calls: (const oaObserver_oaCell&)\n"
"    Signature: oaObserver_oaCell||cref-oaObserver_oaCell,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCell_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCell",
    sizeof(PyoaObserver_oaCellObject),
    0,
    (destructor)oaObserver_oaCell_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCell_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCell_tp_repr,	/* tp_repr */
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
    oaObserver_oaCell_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCell_oaCellModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCell_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCell_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCell_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCell\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCell",
           (PyObject*)(&PyoaObserver_oaCell_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCell\n");
       return -1;
    }
    return 0;
}

