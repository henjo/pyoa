
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
// Wrapper Implementation for Class: oaIter_oaScanChain
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChain_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaScanChain_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaScanChainObject* self = (PyoaIter_oaScanChainObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChain(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaScanChain)
    {
        PyParamoaIter_oaScanChain p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaScanChain_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChain(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaScanChain, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaScanChain)\n"
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
oaIter_oaScanChain_tp_dealloc(PyoaIter_oaScanChainObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaScanChain*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChain_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaScanChain value;
    int convert_status=PyoaIter_oaScanChain_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaScanChain::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaScanChain_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaScanChain v1;
    PyParamoaIter_oaScanChain v2;
    int convert_status1=PyoaIter_oaScanChain_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaScanChain_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChain_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChain_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaScanChain ob;
    int convert_status=PyoaIter_oaScanChain_Convert(self,&ob);
    assert(convert_status!=0);
    oaScanChain* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaScanChain_FromoaScanChain(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaScanChain_Convert(PyObject* ob,PyParamoaIter_oaScanChain* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaScanChain_Check(ob)) {
        result->SetData( (oaIter_oaScanChain*) ((PyoaIter_oaScanChainObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaScanChain Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaScanChain_FromoaIter_oaScanChain(oaIter_oaScanChain* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaScanChain_Type.tp_alloc(&PyoaIter_oaScanChain_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaScanChainObject* self = (PyoaIter_oaScanChainObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaScanChain_getNext_doc[] = 
"Class: oaIter_oaScanChain, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaScanChain* getNext()\n"
"    Signature: getNext|ptr-oaScanChain|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaScanChain_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChain data;
    int convert_status=PyoaIter_oaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainObject* self=(PyoaIter_oaScanChainObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainp result= (data.DataCall()->getNext());
        return PyoaScanChain_FromoaScanChain(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaScanChain_next_doc[] = 
"Class: oaIter_oaScanChain, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaScanChain* next()\n"
"    Signature: next|ptr-oaScanChain|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaScanChain_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChain data;
    int convert_status=PyoaIter_oaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainObject* self=(PyoaIter_oaScanChainObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaScanChain_FromoaScanChain(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaScanChain_assign_doc[] = 
"Class: oaIter_oaScanChain, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaScanChain_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaScanChain data;
  int convert_status=PyoaIter_oaScanChain_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaScanChain p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaScanChain_Convert,&p1)) {
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

static PyMethodDef oaIter_oaScanChain_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaScanChain_getNext,METH_VARARGS,oaIter_oaScanChain_getNext_doc},
    {"next",(PyCFunction)oaIter_oaScanChain_next,METH_VARARGS,oaIter_oaScanChain_next_doc},
    {"assign",(PyCFunction)oaIter_oaScanChain_tp_assign,METH_VARARGS,oaIter_oaScanChain_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaScanChain_doc[] = 
"Class: oaIter_oaScanChain\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaScanChain(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaScanChain||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaScanChain)\n"
"    Calls: oaIter_oaScanChain(const oaIter_oaScanChain& iterIn)\n"
"    Signature: oaIter_oaScanChain||cref-oaIter_oaScanChain,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaScanChain)\n"
"    Calls: (const oaIter_oaScanChain&)\n"
"    Signature: oaIter_oaScanChain||cref-oaIter_oaScanChain,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaScanChain_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaScanChain",
    sizeof(PyoaIter_oaScanChainObject),
    0,
    (destructor)oaIter_oaScanChain_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaScanChain_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaScanChain_tp_repr,	/* tp_repr */
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
    oaIter_oaScanChain_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaScanChain_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaScanChain_iternext,	/* tp_iternext */
    oaIter_oaScanChain_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaScanChain_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaScanChain_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaScanChain_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaScanChain\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaScanChain",
           (PyObject*)(&PyoaIter_oaScanChain_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaScanChain\n");
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
// Wrapper Implementation for Class: oaIter_oaScanChainInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaScanChainInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaScanChainInstObject* self = (PyoaIter_oaScanChainInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChainInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaScanChainInst)
    {
        PyParamoaIter_oaScanChainInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaScanChainInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChainInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaScanChainInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaScanChainInst)\n"
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
oaIter_oaScanChainInst_tp_dealloc(PyoaIter_oaScanChainInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaScanChainInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaScanChainInst value;
    int convert_status=PyoaIter_oaScanChainInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaScanChainInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaScanChainInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaScanChainInst v1;
    PyParamoaIter_oaScanChainInst v2;
    int convert_status1=PyoaIter_oaScanChainInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaScanChainInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaScanChainInst ob;
    int convert_status=PyoaIter_oaScanChainInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaScanChainInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaScanChainInst_FromoaScanChainInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaScanChainInst_Convert(PyObject* ob,PyParamoaIter_oaScanChainInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaScanChainInst_Check(ob)) {
        result->SetData( (oaIter_oaScanChainInst*) ((PyoaIter_oaScanChainInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaScanChainInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaScanChainInst_FromoaIter_oaScanChainInst(oaIter_oaScanChainInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaScanChainInst_Type.tp_alloc(&PyoaIter_oaScanChainInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaScanChainInstObject* self = (PyoaIter_oaScanChainInstObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaScanChainInst_getNext_doc[] = 
"Class: oaIter_oaScanChainInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaScanChainInst* getNext()\n"
"    Signature: getNext|ptr-oaScanChainInst|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaScanChainInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChainInst data;
    int convert_status=PyoaIter_oaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainInstObject* self=(PyoaIter_oaScanChainInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainInstp result= (data.DataCall()->getNext());
        return PyoaScanChainInst_FromoaScanChainInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaScanChainInst_next_doc[] = 
"Class: oaIter_oaScanChainInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaScanChainInst* next()\n"
"    Signature: next|ptr-oaScanChainInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaScanChainInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChainInst data;
    int convert_status=PyoaIter_oaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainInstObject* self=(PyoaIter_oaScanChainInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaScanChainInst_FromoaScanChainInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaScanChainInst_assign_doc[] = 
"Class: oaIter_oaScanChainInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaScanChainInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaScanChainInst data;
  int convert_status=PyoaIter_oaScanChainInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaScanChainInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaScanChainInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaScanChainInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaScanChainInst_getNext,METH_VARARGS,oaIter_oaScanChainInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaScanChainInst_next,METH_VARARGS,oaIter_oaScanChainInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaScanChainInst_tp_assign,METH_VARARGS,oaIter_oaScanChainInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaScanChainInst_doc[] = 
"Class: oaIter_oaScanChainInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaScanChainInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaScanChainInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaScanChainInst)\n"
"    Calls: oaIter_oaScanChainInst(const oaIter_oaScanChainInst& iterIn)\n"
"    Signature: oaIter_oaScanChainInst||cref-oaIter_oaScanChainInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaScanChainInst)\n"
"    Calls: (const oaIter_oaScanChainInst&)\n"
"    Signature: oaIter_oaScanChainInst||cref-oaIter_oaScanChainInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaScanChainInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaScanChainInst",
    sizeof(PyoaIter_oaScanChainInstObject),
    0,
    (destructor)oaIter_oaScanChainInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaScanChainInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaScanChainInst_tp_repr,	/* tp_repr */
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
    oaIter_oaScanChainInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaScanChainInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaScanChainInst_iternext,	/* tp_iternext */
    oaIter_oaScanChainInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaScanChainInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaScanChainInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaScanChainInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaScanChainInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaScanChainInst",
           (PyObject*)(&PyoaIter_oaScanChainInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaScanChainInst\n");
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
// Wrapper Implementation for Class: oaIter_oaScanChainSet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainSet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaScanChainSet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaScanChainSetObject* self = (PyoaIter_oaScanChainSetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChainSet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaScanChainSet)
    {
        PyParamoaIter_oaScanChainSet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaScanChainSet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaScanChainSet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaScanChainSet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaScanChainSet)\n"
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
oaIter_oaScanChainSet_tp_dealloc(PyoaIter_oaScanChainSetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaScanChainSet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainSet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaScanChainSet value;
    int convert_status=PyoaIter_oaScanChainSet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaScanChainSet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaScanChainSet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaScanChainSet v1;
    PyParamoaIter_oaScanChainSet v2;
    int convert_status1=PyoaIter_oaScanChainSet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaScanChainSet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainSet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaScanChainSet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaScanChainSet ob;
    int convert_status=PyoaIter_oaScanChainSet_Convert(self,&ob);
    assert(convert_status!=0);
    oaScanChainSet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaScanChainSet_FromoaScanChainSet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaScanChainSet_Convert(PyObject* ob,PyParamoaIter_oaScanChainSet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaScanChainSet_Check(ob)) {
        result->SetData( (oaIter_oaScanChainSet*) ((PyoaIter_oaScanChainSetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaScanChainSet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaScanChainSet_FromoaIter_oaScanChainSet(oaIter_oaScanChainSet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaScanChainSet_Type.tp_alloc(&PyoaIter_oaScanChainSet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaScanChainSetObject* self = (PyoaIter_oaScanChainSetObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaScanChainSet_getNext_doc[] = 
"Class: oaIter_oaScanChainSet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaScanChainSet* getNext()\n"
"    Signature: getNext|ptr-oaScanChainSet|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaScanChainSet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChainSet data;
    int convert_status=PyoaIter_oaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainSetObject* self=(PyoaIter_oaScanChainSetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainSetp result= (data.DataCall()->getNext());
        return PyoaScanChainSet_FromoaScanChainSet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaScanChainSet_next_doc[] = 
"Class: oaIter_oaScanChainSet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaScanChainSet* next()\n"
"    Signature: next|ptr-oaScanChainSet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaScanChainSet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaScanChainSet data;
    int convert_status=PyoaIter_oaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaScanChainSetObject* self=(PyoaIter_oaScanChainSetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainSetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaScanChainSet_FromoaScanChainSet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaScanChainSet_assign_doc[] = 
"Class: oaIter_oaScanChainSet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaScanChainSet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaScanChainSet data;
  int convert_status=PyoaIter_oaScanChainSet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaScanChainSet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaScanChainSet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaScanChainSet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaScanChainSet_getNext,METH_VARARGS,oaIter_oaScanChainSet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaScanChainSet_next,METH_VARARGS,oaIter_oaScanChainSet_next_doc},
    {"assign",(PyCFunction)oaIter_oaScanChainSet_tp_assign,METH_VARARGS,oaIter_oaScanChainSet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaScanChainSet_doc[] = 
"Class: oaIter_oaScanChainSet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaScanChainSet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaScanChainSet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaScanChainSet)\n"
"    Calls: oaIter_oaScanChainSet(const oaIter_oaScanChainSet& iterIn)\n"
"    Signature: oaIter_oaScanChainSet||cref-oaIter_oaScanChainSet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaScanChainSet)\n"
"    Calls: (const oaIter_oaScanChainSet&)\n"
"    Signature: oaIter_oaScanChainSet||cref-oaIter_oaScanChainSet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaScanChainSet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaScanChainSet",
    sizeof(PyoaIter_oaScanChainSetObject),
    0,
    (destructor)oaIter_oaScanChainSet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaScanChainSet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaScanChainSet_tp_repr,	/* tp_repr */
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
    oaIter_oaScanChainSet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaScanChainSet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaScanChainSet_iternext,	/* tp_iternext */
    oaIter_oaScanChainSet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaScanChainSet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaScanChainSet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaScanChainSet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaScanChainSet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaScanChainSet",
           (PyObject*)(&PyoaIter_oaScanChainSet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaScanChainSet\n");
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
// Wrapper Implementation for Class: oaIter_oaShape
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaShape_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaShape_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaShapeObject* self = (PyoaIter_oaShapeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaShape(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaShape)
    {
        PyParamoaIter_oaShape p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaShape_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaShape(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaShape, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaShape)\n"
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
oaIter_oaShape_tp_dealloc(PyoaIter_oaShapeObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaShape*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaShape_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaShape value;
    int convert_status=PyoaIter_oaShape_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaShape::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaShape_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaShape v1;
    PyParamoaIter_oaShape v2;
    int convert_status1=PyoaIter_oaShape_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaShape_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaShape_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaShape_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaShape ob;
    int convert_status=PyoaIter_oaShape_Convert(self,&ob);
    assert(convert_status!=0);
    oaShape* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaShape_FromoaShape(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaShape_Convert(PyObject* ob,PyParamoaIter_oaShape* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaShape_Check(ob)) {
        result->SetData( (oaIter_oaShape*) ((PyoaIter_oaShapeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaShape Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaShape_FromoaIter_oaShape(oaIter_oaShape* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaShape_Type.tp_alloc(&PyoaIter_oaShape_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaShapeObject* self = (PyoaIter_oaShapeObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaShape_getNext_doc[] = 
"Class: oaIter_oaShape, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaShape* getNext()\n"
"    Signature: getNext|ptr-oaShape|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaShape_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaShape data;
    int convert_status=PyoaIter_oaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaShapeObject* self=(PyoaIter_oaShapeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaShapep result= (data.DataCall()->getNext());
        return PyoaShape_FromoaShape(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaShape_next_doc[] = 
"Class: oaIter_oaShape, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaShape* next()\n"
"    Signature: next|ptr-oaShape|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaShape_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaShape data;
    int convert_status=PyoaIter_oaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaShapeObject* self=(PyoaIter_oaShapeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaShapep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaShape_FromoaShape(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaShape_assign_doc[] = 
"Class: oaIter_oaShape, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaShape_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaShape data;
  int convert_status=PyoaIter_oaShape_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaShape p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaShape_Convert,&p1)) {
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

static PyMethodDef oaIter_oaShape_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaShape_getNext,METH_VARARGS,oaIter_oaShape_getNext_doc},
    {"next",(PyCFunction)oaIter_oaShape_next,METH_VARARGS,oaIter_oaShape_next_doc},
    {"assign",(PyCFunction)oaIter_oaShape_tp_assign,METH_VARARGS,oaIter_oaShape_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaShape_doc[] = 
"Class: oaIter_oaShape\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaShape(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaShape||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaShape)\n"
"    Calls: oaIter_oaShape(const oaIter_oaShape& iterIn)\n"
"    Signature: oaIter_oaShape||cref-oaIter_oaShape,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaShape)\n"
"    Calls: (const oaIter_oaShape&)\n"
"    Signature: oaIter_oaShape||cref-oaIter_oaShape,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaShape_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaShape",
    sizeof(PyoaIter_oaShapeObject),
    0,
    (destructor)oaIter_oaShape_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaShape_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaShape_tp_repr,	/* tp_repr */
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
    oaIter_oaShape_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaShape_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaShape_iternext,	/* tp_iternext */
    oaIter_oaShape_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaShape_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaShape_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaShape_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaShape\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaShape",
           (PyObject*)(&PyoaIter_oaShape_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaShape\n");
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
// Wrapper Implementation for Class: oaIter_oaSimpleConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSimpleConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaSimpleConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaSimpleConstraintObject* self = (PyoaIter_oaSimpleConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSimpleConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaSimpleConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaSimpleConstraint)
    {
        PyParamoaIter_oaSimpleConstraint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaSimpleConstraint_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaSimpleConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaSimpleConstraint, Choices are:\n"
        "    (oaCollection_oaSimpleConstraint_oaConstraintGroup)\n"
        "    (oaIter_oaSimpleConstraint)\n"
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
oaIter_oaSimpleConstraint_tp_dealloc(PyoaIter_oaSimpleConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaSimpleConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSimpleConstraint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaSimpleConstraint value;
    int convert_status=PyoaIter_oaSimpleConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaIter_oaSimpleConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaSimpleConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaSimpleConstraint v1;
    PyParamoaIter_oaSimpleConstraint v2;
    int convert_status1=PyoaIter_oaSimpleConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaSimpleConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaSimpleConstraint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSimpleConstraint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaSimpleConstraint ob;
    int convert_status=PyoaIter_oaSimpleConstraint_Convert(self,&ob);
    assert(convert_status!=0);
    oaSimpleConstraint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaSimpleConstraint_Convert(PyObject* ob,PyParamoaIter_oaSimpleConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaSimpleConstraint_Check(ob)) {
        result->SetData( (oaIter_oaSimpleConstraint*) ((PyoaIter_oaSimpleConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaSimpleConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaSimpleConstraint_FromoaIter_oaSimpleConstraint(oaIter_oaSimpleConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaSimpleConstraint_Type.tp_alloc(&PyoaIter_oaSimpleConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaSimpleConstraintObject* self = (PyoaIter_oaSimpleConstraintObject*)bself;
        self->value = (oaConstraintInGroupIter*)  data;
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
static char oaIter_oaSimpleConstraint_getNext_doc[] = 
"Class: oaIter_oaSimpleConstraint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaSimpleConstraint* getNext()\n"
"    Signature: getNext|ptr-oaSimpleConstraint|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaSimpleConstraint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSimpleConstraint data;
    int convert_status=PyoaIter_oaSimpleConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSimpleConstraintObject* self=(PyoaIter_oaSimpleConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSimpleConstraintp result= (data.DataCall()->getNext());
        return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaSimpleConstraint_next_doc[] = 
"Class: oaIter_oaSimpleConstraint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaSimpleConstraint* next()\n"
"    Signature: next|ptr-oaSimpleConstraint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaSimpleConstraint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSimpleConstraint data;
    int convert_status=PyoaIter_oaSimpleConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSimpleConstraintObject* self=(PyoaIter_oaSimpleConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSimpleConstraintp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
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

static PyMethodDef oaIter_oaSimpleConstraint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaSimpleConstraint_getNext,METH_VARARGS,oaIter_oaSimpleConstraint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaSimpleConstraint_next,METH_VARARGS,oaIter_oaSimpleConstraint_next_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaSimpleConstraint_doc[] = 
"Class: oaIter_oaSimpleConstraint\n"
"  Class type oaIter_oaSimpleConstraint\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSimpleConstraint_oaConstraintGroup)\n"
"    Calls: oaIter_oaSimpleConstraint(const oaCollection_oaSimpleConstraint_oaConstraintGroup& c)\n"
"    Signature: oaIter_oaSimpleConstraint||cref-oaCollection_oaSimpleConstraint_oaConstraintGroup,\n"
"    Constructor oaIter_oaSimpleConstraint\n"
"  Paramegers: (oaIter_oaSimpleConstraint)\n"
"    Calls: oaIter_oaSimpleConstraint(const oaIter_oaSimpleConstraint& iterIn)\n"
"    Signature: oaIter_oaSimpleConstraint||cref-oaIter_oaSimpleConstraint,\n"
"    Constructor oaIter_oaSimpleConstraint\n"
"  Paramegers: (oaIter_oaSimpleConstraint)\n"
"    Calls: (const oaIter_oaSimpleConstraint&)\n"
"    Signature: oaIter_oaSimpleConstraint||cref-oaIter_oaSimpleConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaSimpleConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaSimpleConstraint",
    sizeof(PyoaIter_oaSimpleConstraintObject),
    0,
    (destructor)oaIter_oaSimpleConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaSimpleConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaSimpleConstraint_tp_repr,	/* tp_repr */
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
    oaIter_oaSimpleConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaSimpleConstraint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaSimpleConstraint_iternext,	/* tp_iternext */
    oaIter_oaSimpleConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaSimpleConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaSimpleConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaSimpleConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaSimpleConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaSimpleConstraint",
           (PyObject*)(&PyoaIter_oaSimpleConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaSimpleConstraint\n");
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
// Wrapper Implementation for Class: oaIter_oaSiteDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSiteDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaSiteDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaSiteDefObject* self = (PyoaIter_oaSiteDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSiteDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaSiteDef)
    {
        PyParamoaIter_oaSiteDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaSiteDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSiteDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaSiteDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaSiteDef)\n"
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
oaIter_oaSiteDef_tp_dealloc(PyoaIter_oaSiteDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaSiteDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSiteDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaSiteDef value;
    int convert_status=PyoaIter_oaSiteDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaSiteDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaSiteDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaSiteDef v1;
    PyParamoaIter_oaSiteDef v2;
    int convert_status1=PyoaIter_oaSiteDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaSiteDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaSiteDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSiteDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaSiteDef ob;
    int convert_status=PyoaIter_oaSiteDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaSiteDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaSiteDef_FromoaSiteDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaSiteDef_Convert(PyObject* ob,PyParamoaIter_oaSiteDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaSiteDef_Check(ob)) {
        result->SetData( (oaIter_oaSiteDef*) ((PyoaIter_oaSiteDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaSiteDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaSiteDef_FromoaIter_oaSiteDef(oaIter_oaSiteDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaSiteDef_Type.tp_alloc(&PyoaIter_oaSiteDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaSiteDefObject* self = (PyoaIter_oaSiteDefObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaSiteDef_getNext_doc[] = 
"Class: oaIter_oaSiteDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaSiteDef* getNext()\n"
"    Signature: getNext|ptr-oaSiteDef|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaSiteDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSiteDef data;
    int convert_status=PyoaIter_oaSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSiteDefObject* self=(PyoaIter_oaSiteDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSiteDefp result= (data.DataCall()->getNext());
        return PyoaSiteDef_FromoaSiteDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaSiteDef_next_doc[] = 
"Class: oaIter_oaSiteDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaSiteDef* next()\n"
"    Signature: next|ptr-oaSiteDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaSiteDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSiteDef data;
    int convert_status=PyoaIter_oaSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSiteDefObject* self=(PyoaIter_oaSiteDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSiteDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaSiteDef_FromoaSiteDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaSiteDef_assign_doc[] = 
"Class: oaIter_oaSiteDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaSiteDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaSiteDef data;
  int convert_status=PyoaIter_oaSiteDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaSiteDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaSiteDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaSiteDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaSiteDef_getNext,METH_VARARGS,oaIter_oaSiteDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaSiteDef_next,METH_VARARGS,oaIter_oaSiteDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaSiteDef_tp_assign,METH_VARARGS,oaIter_oaSiteDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaSiteDef_doc[] = 
"Class: oaIter_oaSiteDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaSiteDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaSiteDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaSiteDef)\n"
"    Calls: oaIter_oaSiteDef(const oaIter_oaSiteDef& iterIn)\n"
"    Signature: oaIter_oaSiteDef||cref-oaIter_oaSiteDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaSiteDef)\n"
"    Calls: (const oaIter_oaSiteDef&)\n"
"    Signature: oaIter_oaSiteDef||cref-oaIter_oaSiteDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaSiteDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaSiteDef",
    sizeof(PyoaIter_oaSiteDefObject),
    0,
    (destructor)oaIter_oaSiteDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaSiteDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaSiteDef_tp_repr,	/* tp_repr */
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
    oaIter_oaSiteDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaSiteDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaSiteDef_iternext,	/* tp_iternext */
    oaIter_oaSiteDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaSiteDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaSiteDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaSiteDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaSiteDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaSiteDef",
           (PyObject*)(&PyoaIter_oaSiteDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaSiteDef\n");
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
// Wrapper Implementation for Class: oaIter_oaSteiner
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSteiner_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaSteiner_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaSteinerObject* self = (PyoaIter_oaSteinerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSteiner(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaSteiner)
    {
        PyParamoaIter_oaSteiner p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaSteiner_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSteiner(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaSteiner, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaSteiner)\n"
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
oaIter_oaSteiner_tp_dealloc(PyoaIter_oaSteinerObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaSteiner*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSteiner_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaSteiner value;
    int convert_status=PyoaIter_oaSteiner_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaSteiner::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaSteiner_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaSteiner v1;
    PyParamoaIter_oaSteiner v2;
    int convert_status1=PyoaIter_oaSteiner_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaSteiner_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaSteiner_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSteiner_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaSteiner ob;
    int convert_status=PyoaIter_oaSteiner_Convert(self,&ob);
    assert(convert_status!=0);
    oaSteiner* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaSteiner_FromoaSteiner(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaSteiner_Convert(PyObject* ob,PyParamoaIter_oaSteiner* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaSteiner_Check(ob)) {
        result->SetData( (oaIter_oaSteiner*) ((PyoaIter_oaSteinerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaSteiner Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaSteiner_FromoaIter_oaSteiner(oaIter_oaSteiner* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaSteiner_Type.tp_alloc(&PyoaIter_oaSteiner_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaSteinerObject* self = (PyoaIter_oaSteinerObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaSteiner_getNext_doc[] = 
"Class: oaIter_oaSteiner, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaSteiner* getNext()\n"
"    Signature: getNext|ptr-oaSteiner|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaSteiner_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSteiner data;
    int convert_status=PyoaIter_oaSteiner_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSteinerObject* self=(PyoaIter_oaSteinerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSteinerp result= (data.DataCall()->getNext());
        return PyoaSteiner_FromoaSteiner(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaSteiner_next_doc[] = 
"Class: oaIter_oaSteiner, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaSteiner* next()\n"
"    Signature: next|ptr-oaSteiner|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaSteiner_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSteiner data;
    int convert_status=PyoaIter_oaSteiner_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSteinerObject* self=(PyoaIter_oaSteinerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSteinerp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaSteiner_FromoaSteiner(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaSteiner_assign_doc[] = 
"Class: oaIter_oaSteiner, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaSteiner_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaSteiner data;
  int convert_status=PyoaIter_oaSteiner_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaSteiner p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaSteiner_Convert,&p1)) {
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

static PyMethodDef oaIter_oaSteiner_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaSteiner_getNext,METH_VARARGS,oaIter_oaSteiner_getNext_doc},
    {"next",(PyCFunction)oaIter_oaSteiner_next,METH_VARARGS,oaIter_oaSteiner_next_doc},
    {"assign",(PyCFunction)oaIter_oaSteiner_tp_assign,METH_VARARGS,oaIter_oaSteiner_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaSteiner_doc[] = 
"Class: oaIter_oaSteiner\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaSteiner(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaSteiner||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaSteiner)\n"
"    Calls: oaIter_oaSteiner(const oaIter_oaSteiner& iterIn)\n"
"    Signature: oaIter_oaSteiner||cref-oaIter_oaSteiner,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaSteiner)\n"
"    Calls: (const oaIter_oaSteiner&)\n"
"    Signature: oaIter_oaSteiner||cref-oaIter_oaSteiner,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaSteiner_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaSteiner",
    sizeof(PyoaIter_oaSteinerObject),
    0,
    (destructor)oaIter_oaSteiner_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaSteiner_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaSteiner_tp_repr,	/* tp_repr */
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
    oaIter_oaSteiner_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaSteiner_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaSteiner_iternext,	/* tp_iternext */
    oaIter_oaSteiner_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaSteiner_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaSteiner_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaSteiner_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaSteiner\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaSteiner",
           (PyObject*)(&PyoaIter_oaSteiner_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaSteiner\n");
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
// Wrapper Implementation for Class: oaIter_oaStepperMap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaStepperMap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaStepperMap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaStepperMapObject* self = (PyoaIter_oaStepperMapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaStepperMap(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaStepperMap)
    {
        PyParamoaIter_oaStepperMap p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaStepperMap_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaStepperMap(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaStepperMap, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaStepperMap)\n"
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
oaIter_oaStepperMap_tp_dealloc(PyoaIter_oaStepperMapObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaStepperMap*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaStepperMap_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaStepperMap value;
    int convert_status=PyoaIter_oaStepperMap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaStepperMap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaStepperMap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaStepperMap v1;
    PyParamoaIter_oaStepperMap v2;
    int convert_status1=PyoaIter_oaStepperMap_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaStepperMap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaStepperMap_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaStepperMap_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaStepperMap ob;
    int convert_status=PyoaIter_oaStepperMap_Convert(self,&ob);
    assert(convert_status!=0);
    oaStepperMap* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaStepperMap_FromoaStepperMap(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaStepperMap_Convert(PyObject* ob,PyParamoaIter_oaStepperMap* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaStepperMap_Check(ob)) {
        result->SetData( (oaIter_oaStepperMap*) ((PyoaIter_oaStepperMapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaStepperMap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaStepperMap_FromoaIter_oaStepperMap(oaIter_oaStepperMap* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaStepperMap_Type.tp_alloc(&PyoaIter_oaStepperMap_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaStepperMapObject* self = (PyoaIter_oaStepperMapObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaStepperMap_getNext_doc[] = 
"Class: oaIter_oaStepperMap, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaStepperMap* getNext()\n"
"    Signature: getNext|ptr-oaStepperMap|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaStepperMap_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaStepperMap data;
    int convert_status=PyoaIter_oaStepperMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaStepperMapObject* self=(PyoaIter_oaStepperMapObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaStepperMapp result= (data.DataCall()->getNext());
        return PyoaStepperMap_FromoaStepperMap(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaStepperMap_next_doc[] = 
"Class: oaIter_oaStepperMap, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaStepperMap* next()\n"
"    Signature: next|ptr-oaStepperMap|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaStepperMap_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaStepperMap data;
    int convert_status=PyoaIter_oaStepperMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaStepperMapObject* self=(PyoaIter_oaStepperMapObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaStepperMapp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaStepperMap_FromoaStepperMap(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaStepperMap_assign_doc[] = 
"Class: oaIter_oaStepperMap, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaStepperMap_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaStepperMap data;
  int convert_status=PyoaIter_oaStepperMap_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaStepperMap p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaStepperMap_Convert,&p1)) {
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

static PyMethodDef oaIter_oaStepperMap_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaStepperMap_getNext,METH_VARARGS,oaIter_oaStepperMap_getNext_doc},
    {"next",(PyCFunction)oaIter_oaStepperMap_next,METH_VARARGS,oaIter_oaStepperMap_next_doc},
    {"assign",(PyCFunction)oaIter_oaStepperMap_tp_assign,METH_VARARGS,oaIter_oaStepperMap_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaStepperMap_doc[] = 
"Class: oaIter_oaStepperMap\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaStepperMap(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaStepperMap||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaStepperMap)\n"
"    Calls: oaIter_oaStepperMap(const oaIter_oaStepperMap& iterIn)\n"
"    Signature: oaIter_oaStepperMap||cref-oaIter_oaStepperMap,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaStepperMap)\n"
"    Calls: (const oaIter_oaStepperMap&)\n"
"    Signature: oaIter_oaStepperMap||cref-oaIter_oaStepperMap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaStepperMap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaStepperMap",
    sizeof(PyoaIter_oaStepperMapObject),
    0,
    (destructor)oaIter_oaStepperMap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaStepperMap_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaStepperMap_tp_repr,	/* tp_repr */
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
    oaIter_oaStepperMap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaStepperMap_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaStepperMap_iternext,	/* tp_iternext */
    oaIter_oaStepperMap_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaStepperMap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaStepperMap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaStepperMap_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaStepperMap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaStepperMap",
           (PyObject*)(&PyoaIter_oaStepperMap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaStepperMap\n");
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
// Wrapper Implementation for Class: oaIter_oaSubNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSubNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaSubNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaSubNetworkObject* self = (PyoaIter_oaSubNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSubNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaSubNetwork)
    {
        PyParamoaIter_oaSubNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaSubNetwork_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaSubNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaSubNetwork, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaSubNetwork)\n"
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
oaIter_oaSubNetwork_tp_dealloc(PyoaIter_oaSubNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaSubNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSubNetwork_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaSubNetwork value;
    int convert_status=PyoaIter_oaSubNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaSubNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaSubNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaSubNetwork v1;
    PyParamoaIter_oaSubNetwork v2;
    int convert_status1=PyoaIter_oaSubNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaSubNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaSubNetwork_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaSubNetwork_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaSubNetwork ob;
    int convert_status=PyoaIter_oaSubNetwork_Convert(self,&ob);
    assert(convert_status!=0);
    oaSubNetwork* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaSubNetwork_FromoaSubNetwork(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaSubNetwork_Convert(PyObject* ob,PyParamoaIter_oaSubNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaSubNetwork_Check(ob)) {
        result->SetData( (oaIter_oaSubNetwork*) ((PyoaIter_oaSubNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaSubNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaSubNetwork_FromoaIter_oaSubNetwork(oaIter_oaSubNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaSubNetwork_Type.tp_alloc(&PyoaIter_oaSubNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaSubNetworkObject* self = (PyoaIter_oaSubNetworkObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaSubNetwork_getNext_doc[] = 
"Class: oaIter_oaSubNetwork, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaSubNetwork* getNext()\n"
"    Signature: getNext|ptr-oaSubNetwork|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaSubNetwork_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSubNetwork data;
    int convert_status=PyoaIter_oaSubNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSubNetworkObject* self=(PyoaIter_oaSubNetworkObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSubNetworkp result= (data.DataCall()->getNext());
        return PyoaSubNetwork_FromoaSubNetwork(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaSubNetwork_next_doc[] = 
"Class: oaIter_oaSubNetwork, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaSubNetwork* next()\n"
"    Signature: next|ptr-oaSubNetwork|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaSubNetwork_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaSubNetwork data;
    int convert_status=PyoaIter_oaSubNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaSubNetworkObject* self=(PyoaIter_oaSubNetworkObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSubNetworkp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaSubNetwork_FromoaSubNetwork(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaSubNetwork_assign_doc[] = 
"Class: oaIter_oaSubNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaSubNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaSubNetwork data;
  int convert_status=PyoaIter_oaSubNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaSubNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaSubNetwork_Convert,&p1)) {
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

static PyMethodDef oaIter_oaSubNetwork_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaSubNetwork_getNext,METH_VARARGS,oaIter_oaSubNetwork_getNext_doc},
    {"next",(PyCFunction)oaIter_oaSubNetwork_next,METH_VARARGS,oaIter_oaSubNetwork_next_doc},
    {"assign",(PyCFunction)oaIter_oaSubNetwork_tp_assign,METH_VARARGS,oaIter_oaSubNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaSubNetwork_doc[] = 
"Class: oaIter_oaSubNetwork\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaSubNetwork(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaSubNetwork||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaSubNetwork)\n"
"    Calls: oaIter_oaSubNetwork(const oaIter_oaSubNetwork& iterIn)\n"
"    Signature: oaIter_oaSubNetwork||cref-oaIter_oaSubNetwork,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaSubNetwork)\n"
"    Calls: (const oaIter_oaSubNetwork&)\n"
"    Signature: oaIter_oaSubNetwork||cref-oaIter_oaSubNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaSubNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaSubNetwork",
    sizeof(PyoaIter_oaSubNetworkObject),
    0,
    (destructor)oaIter_oaSubNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaSubNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaSubNetwork_tp_repr,	/* tp_repr */
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
    oaIter_oaSubNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaSubNetwork_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaSubNetwork_iternext,	/* tp_iternext */
    oaIter_oaSubNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaSubNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaSubNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaSubNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaSubNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaSubNetwork",
           (PyObject*)(&PyoaIter_oaSubNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaSubNetwork\n");
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
// Wrapper Implementation for Class: oaIter_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTechObject* self = (PyoaIter_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTech_oaTech)
    {
        PyParamoaCollection_oaTech_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTech_oaTech_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTech)
    {
        PyParamoaIter_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTech_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTech, Choices are:\n"
        "    (oaCollection_oaTech_oaTech)\n"
        "    (oaIter_oaTech)\n"
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
oaIter_oaTech_tp_dealloc(PyoaIter_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTech value;
    int convert_status=PyoaIter_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTech v1;
    PyParamoaIter_oaTech v2;
    int convert_status1=PyoaIter_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTech_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTech_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTech ob;
    int convert_status=PyoaIter_oaTech_Convert(self,&ob);
    assert(convert_status!=0);
    oaTech* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTech_FromoaTech(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTech_Convert(PyObject* ob,PyParamoaIter_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTech_Check(ob)) {
        result->SetData( (oaIter_oaTech*) ((PyoaIter_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTech_FromoaIter_oaTech(oaIter_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTech_Type.tp_alloc(&PyoaIter_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTechObject* self = (PyoaIter_oaTechObject*)bself;
        self->value = (oaDatabaseIter*)  data;
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
static char oaIter_oaTech_getNext_doc[] = 
"Class: oaIter_oaTech, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTech* getNext()\n"
"    Signature: getNext|ptr-oaTech|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaTech_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTech data;
    int convert_status=PyoaIter_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechObject* self=(PyoaIter_oaTechObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechp result= (data.DataCall()->getNext());
        return PyoaTech_FromoaTech(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTech_next_doc[] = 
"Class: oaIter_oaTech, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTech* next()\n"
"    Signature: next|ptr-oaTech|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTech_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTech data;
    int convert_status=PyoaIter_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechObject* self=(PyoaIter_oaTechObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTech_FromoaTech(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTech_assign_doc[] = 
"Class: oaIter_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTech data;
  int convert_status=PyoaIter_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTech_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTech_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTech_getNext,METH_VARARGS,oaIter_oaTech_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTech_next,METH_VARARGS,oaIter_oaTech_next_doc},
    {"assign",(PyCFunction)oaIter_oaTech_tp_assign,METH_VARARGS,oaIter_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTech_doc[] = 
"Class: oaIter_oaTech\n"
"  Class type oaIter_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTech_oaTech)\n"
"    Calls: oaIter_oaTech(const oaCollection_oaTech_oaTech& c)\n"
"    Signature: oaIter_oaTech||cref-oaCollection_oaTech_oaTech,\n"
"    Constructor oaIter_oaTech\n"
"  Paramegers: (oaIter_oaTech)\n"
"    Calls: oaIter_oaTech(const oaIter_oaTech& iterIn)\n"
"    Signature: oaIter_oaTech||cref-oaIter_oaTech,\n"
"    Constructor oaIter_oaTech\n"
"  Paramegers: (oaIter_oaTech)\n"
"    Calls: (const oaIter_oaTech&)\n"
"    Signature: oaIter_oaTech||cref-oaIter_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTech",
    sizeof(PyoaIter_oaTechObject),
    0,
    (destructor)oaIter_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTech_tp_repr,	/* tp_repr */
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
    oaIter_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTech_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTech_iternext,	/* tp_iternext */
    oaIter_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTech",
           (PyObject*)(&PyoaIter_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTech\n");
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
// Wrapper Implementation for Class: oaIter_oaTechHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTechHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTechHeaderObject* self = (PyoaIter_oaTechHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTechHeader)
    {
        PyParamoaIter_oaTechHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTechHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTechHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaTechHeader)\n"
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
oaIter_oaTechHeader_tp_dealloc(PyoaIter_oaTechHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTechHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTechHeader value;
    int convert_status=PyoaIter_oaTechHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaTechHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTechHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTechHeader v1;
    PyParamoaIter_oaTechHeader v2;
    int convert_status1=PyoaIter_oaTechHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTechHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTechHeader ob;
    int convert_status=PyoaIter_oaTechHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaTechHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTechHeader_FromoaTechHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTechHeader_Convert(PyObject* ob,PyParamoaIter_oaTechHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTechHeader_Check(ob)) {
        result->SetData( (oaIter_oaTechHeader*) ((PyoaIter_oaTechHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTechHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTechHeader_FromoaIter_oaTechHeader(oaIter_oaTechHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTechHeader_Type.tp_alloc(&PyoaIter_oaTechHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTechHeaderObject* self = (PyoaIter_oaTechHeaderObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaTechHeader_getNext_doc[] = 
"Class: oaIter_oaTechHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTechHeader* getNext()\n"
"    Signature: getNext|ptr-oaTechHeader|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaTechHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechHeader data;
    int convert_status=PyoaIter_oaTechHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechHeaderObject* self=(PyoaIter_oaTechHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechHeaderp result= (data.DataCall()->getNext());
        return PyoaTechHeader_FromoaTechHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTechHeader_next_doc[] = 
"Class: oaIter_oaTechHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTechHeader* next()\n"
"    Signature: next|ptr-oaTechHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTechHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechHeader data;
    int convert_status=PyoaIter_oaTechHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechHeaderObject* self=(PyoaIter_oaTechHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTechHeader_FromoaTechHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTechHeader_assign_doc[] = 
"Class: oaIter_oaTechHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTechHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTechHeader data;
  int convert_status=PyoaIter_oaTechHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTechHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTechHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTechHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTechHeader_getNext,METH_VARARGS,oaIter_oaTechHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTechHeader_next,METH_VARARGS,oaIter_oaTechHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaTechHeader_tp_assign,METH_VARARGS,oaIter_oaTechHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTechHeader_doc[] = 
"Class: oaIter_oaTechHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaTechHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaTechHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaTechHeader)\n"
"    Calls: oaIter_oaTechHeader(const oaIter_oaTechHeader& iterIn)\n"
"    Signature: oaIter_oaTechHeader||cref-oaIter_oaTechHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaTechHeader)\n"
"    Calls: (const oaIter_oaTechHeader&)\n"
"    Signature: oaIter_oaTechHeader||cref-oaIter_oaTechHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTechHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTechHeader",
    sizeof(PyoaIter_oaTechHeaderObject),
    0,
    (destructor)oaIter_oaTechHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTechHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTechHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaTechHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTechHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTechHeader_iternext,	/* tp_iternext */
    oaIter_oaTechHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTechHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTechHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTechHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTechHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTechHeader",
           (PyObject*)(&PyoaIter_oaTechHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTechHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaTechLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTechLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTechLayerHeaderObject* self = (PyoaIter_oaTechLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTechLayerHeader)
    {
        PyParamoaIter_oaTechLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTechLayerHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTechLayerHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaTechLayerHeader)\n"
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
oaIter_oaTechLayerHeader_tp_dealloc(PyoaIter_oaTechLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTechLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTechLayerHeader value;
    int convert_status=PyoaIter_oaTechLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaTechLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTechLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTechLayerHeader v1;
    PyParamoaIter_oaTechLayerHeader v2;
    int convert_status1=PyoaIter_oaTechLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTechLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechLayerHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechLayerHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTechLayerHeader ob;
    int convert_status=PyoaIter_oaTechLayerHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaTechLayerHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTechLayerHeader_FromoaTechLayerHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTechLayerHeader_Convert(PyObject* ob,PyParamoaIter_oaTechLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTechLayerHeader_Check(ob)) {
        result->SetData( (oaIter_oaTechLayerHeader*) ((PyoaIter_oaTechLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTechLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTechLayerHeader_FromoaIter_oaTechLayerHeader(oaIter_oaTechLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTechLayerHeader_Type.tp_alloc(&PyoaIter_oaTechLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTechLayerHeaderObject* self = (PyoaIter_oaTechLayerHeaderObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaTechLayerHeader_getNext_doc[] = 
"Class: oaIter_oaTechLayerHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTechLayerHeader* getNext()\n"
"    Signature: getNext|ptr-oaTechLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaTechLayerHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechLayerHeader data;
    int convert_status=PyoaIter_oaTechLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechLayerHeaderObject* self=(PyoaIter_oaTechLayerHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechLayerHeaderp result= (data.DataCall()->getNext());
        return PyoaTechLayerHeader_FromoaTechLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTechLayerHeader_next_doc[] = 
"Class: oaIter_oaTechLayerHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTechLayerHeader* next()\n"
"    Signature: next|ptr-oaTechLayerHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTechLayerHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechLayerHeader data;
    int convert_status=PyoaIter_oaTechLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechLayerHeaderObject* self=(PyoaIter_oaTechLayerHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechLayerHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTechLayerHeader_FromoaTechLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTechLayerHeader_assign_doc[] = 
"Class: oaIter_oaTechLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTechLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTechLayerHeader data;
  int convert_status=PyoaIter_oaTechLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTechLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTechLayerHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTechLayerHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTechLayerHeader_getNext,METH_VARARGS,oaIter_oaTechLayerHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTechLayerHeader_next,METH_VARARGS,oaIter_oaTechLayerHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaTechLayerHeader_tp_assign,METH_VARARGS,oaIter_oaTechLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTechLayerHeader_doc[] = 
"Class: oaIter_oaTechLayerHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaTechLayerHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaTechLayerHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaTechLayerHeader)\n"
"    Calls: oaIter_oaTechLayerHeader(const oaIter_oaTechLayerHeader& iterIn)\n"
"    Signature: oaIter_oaTechLayerHeader||cref-oaIter_oaTechLayerHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaTechLayerHeader)\n"
"    Calls: (const oaIter_oaTechLayerHeader&)\n"
"    Signature: oaIter_oaTechLayerHeader||cref-oaIter_oaTechLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTechLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTechLayerHeader",
    sizeof(PyoaIter_oaTechLayerHeaderObject),
    0,
    (destructor)oaIter_oaTechLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTechLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTechLayerHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaTechLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTechLayerHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTechLayerHeader_iternext,	/* tp_iternext */
    oaIter_oaTechLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTechLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTechLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTechLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTechLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTechLayerHeader",
           (PyObject*)(&PyoaIter_oaTechLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTechLayerHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaTechViaDefHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechViaDefHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTechViaDefHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTechViaDefHeaderObject* self = (PyoaIter_oaTechViaDefHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechViaDefHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTechViaDefHeader)
    {
        PyParamoaIter_oaTechViaDefHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTechViaDefHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTechViaDefHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTechViaDefHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaTechViaDefHeader)\n"
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
oaIter_oaTechViaDefHeader_tp_dealloc(PyoaIter_oaTechViaDefHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTechViaDefHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechViaDefHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTechViaDefHeader value;
    int convert_status=PyoaIter_oaTechViaDefHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaIter_oaTechViaDefHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTechViaDefHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTechViaDefHeader v1;
    PyParamoaIter_oaTechViaDefHeader v2;
    int convert_status1=PyoaIter_oaTechViaDefHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTechViaDefHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechViaDefHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTechViaDefHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTechViaDefHeader ob;
    int convert_status=PyoaIter_oaTechViaDefHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaTechViaDefHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTechViaDefHeader_FromoaTechViaDefHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTechViaDefHeader_Convert(PyObject* ob,PyParamoaIter_oaTechViaDefHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTechViaDefHeader_Check(ob)) {
        result->SetData( (oaIter_oaTechViaDefHeader*) ((PyoaIter_oaTechViaDefHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTechViaDefHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTechViaDefHeader_FromoaIter_oaTechViaDefHeader(oaIter_oaTechViaDefHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTechViaDefHeader_Type.tp_alloc(&PyoaIter_oaTechViaDefHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTechViaDefHeaderObject* self = (PyoaIter_oaTechViaDefHeaderObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaTechViaDefHeader_getNext_doc[] = 
"Class: oaIter_oaTechViaDefHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTechViaDefHeader* getNext()\n"
"    Signature: getNext|ptr-oaTechViaDefHeader|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaTechViaDefHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechViaDefHeader data;
    int convert_status=PyoaIter_oaTechViaDefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechViaDefHeaderObject* self=(PyoaIter_oaTechViaDefHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechViaDefHeaderp result= (data.DataCall()->getNext());
        return PyoaTechViaDefHeader_FromoaTechViaDefHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTechViaDefHeader_next_doc[] = 
"Class: oaIter_oaTechViaDefHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTechViaDefHeader* next()\n"
"    Signature: next|ptr-oaTechViaDefHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTechViaDefHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTechViaDefHeader data;
    int convert_status=PyoaIter_oaTechViaDefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTechViaDefHeaderObject* self=(PyoaIter_oaTechViaDefHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTechViaDefHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTechViaDefHeader_FromoaTechViaDefHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTechViaDefHeader_assign_doc[] = 
"Class: oaIter_oaTechViaDefHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTechViaDefHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTechViaDefHeader data;
  int convert_status=PyoaIter_oaTechViaDefHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTechViaDefHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTechViaDefHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTechViaDefHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTechViaDefHeader_getNext,METH_VARARGS,oaIter_oaTechViaDefHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTechViaDefHeader_next,METH_VARARGS,oaIter_oaTechViaDefHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaTechViaDefHeader_tp_assign,METH_VARARGS,oaIter_oaTechViaDefHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTechViaDefHeader_doc[] = 
"Class: oaIter_oaTechViaDefHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaTechViaDefHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaTechViaDefHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaTechViaDefHeader)\n"
"    Calls: oaIter_oaTechViaDefHeader(const oaIter_oaTechViaDefHeader& iterIn)\n"
"    Signature: oaIter_oaTechViaDefHeader||cref-oaIter_oaTechViaDefHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaTechViaDefHeader)\n"
"    Calls: (const oaIter_oaTechViaDefHeader&)\n"
"    Signature: oaIter_oaTechViaDefHeader||cref-oaIter_oaTechViaDefHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTechViaDefHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTechViaDefHeader",
    sizeof(PyoaIter_oaTechViaDefHeaderObject),
    0,
    (destructor)oaIter_oaTechViaDefHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTechViaDefHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTechViaDefHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaTechViaDefHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTechViaDefHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTechViaDefHeader_iternext,	/* tp_iternext */
    oaIter_oaTechViaDefHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTechViaDefHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTechViaDefHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTechViaDefHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTechViaDefHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTechViaDefHeader",
           (PyObject*)(&PyoaIter_oaTechViaDefHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTechViaDefHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTermObject* self = (PyoaIter_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTerm)
    {
        PyParamoaIter_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaTerm)\n"
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
oaIter_oaTerm_tp_dealloc(PyoaIter_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTerm value;
    int convert_status=PyoaIter_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTerm v1;
    PyParamoaIter_oaTerm v2;
    int convert_status1=PyoaIter_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTerm ob;
    int convert_status=PyoaIter_oaTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTerm_FromoaTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTerm_Convert(PyObject* ob,PyParamoaIter_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTerm_Check(ob)) {
        result->SetData( (oaIter_oaTerm*) ((PyoaIter_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTerm_FromoaIter_oaTerm(oaIter_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTerm_Type.tp_alloc(&PyoaIter_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTermObject* self = (PyoaIter_oaTermObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaTerm_getNext_doc[] = 
"Class: oaIter_oaTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTerm* getNext()\n"
"    Signature: getNext|ptr-oaTerm|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTerm data;
    int convert_status=PyoaIter_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTermObject* self=(PyoaIter_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTermp result= (data.DataCall()->getNext());
        return PyoaTerm_FromoaTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTerm_next_doc[] = 
"Class: oaIter_oaTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTerm* next()\n"
"    Signature: next|ptr-oaTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTerm data;
    int convert_status=PyoaIter_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTermObject* self=(PyoaIter_oaTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTerm_FromoaTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTerm_assign_doc[] = 
"Class: oaIter_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTerm data;
  int convert_status=PyoaIter_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTerm_getNext,METH_VARARGS,oaIter_oaTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTerm_next,METH_VARARGS,oaIter_oaTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaTerm_tp_assign,METH_VARARGS,oaIter_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTerm_doc[] = 
"Class: oaIter_oaTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaTerm)\n"
"    Calls: oaIter_oaTerm(const oaIter_oaTerm& iterIn)\n"
"    Signature: oaIter_oaTerm||cref-oaIter_oaTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaTerm)\n"
"    Calls: (const oaIter_oaTerm&)\n"
"    Signature: oaIter_oaTerm||cref-oaIter_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTerm",
    sizeof(PyoaIter_oaTermObject),
    0,
    (destructor)oaIter_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTerm_iternext,	/* tp_iternext */
    oaIter_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTerm",
           (PyObject*)(&PyoaIter_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaTrackPattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTrackPattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaTrackPattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaTrackPatternObject* self = (PyoaIter_oaTrackPatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTrackPattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaTrackPattern)
    {
        PyParamoaIter_oaTrackPattern p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaTrackPattern_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaTrackPattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaTrackPattern, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaTrackPattern)\n"
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
oaIter_oaTrackPattern_tp_dealloc(PyoaIter_oaTrackPatternObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaTrackPattern*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTrackPattern_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaTrackPattern value;
    int convert_status=PyoaIter_oaTrackPattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaTrackPattern::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaTrackPattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaTrackPattern v1;
    PyParamoaIter_oaTrackPattern v2;
    int convert_status1=PyoaIter_oaTrackPattern_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaTrackPattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaTrackPattern_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaTrackPattern_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaTrackPattern ob;
    int convert_status=PyoaIter_oaTrackPattern_Convert(self,&ob);
    assert(convert_status!=0);
    oaTrackPattern* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaTrackPattern_FromoaTrackPattern(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaTrackPattern_Convert(PyObject* ob,PyParamoaIter_oaTrackPattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaTrackPattern_Check(ob)) {
        result->SetData( (oaIter_oaTrackPattern*) ((PyoaIter_oaTrackPatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaTrackPattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaTrackPattern_FromoaIter_oaTrackPattern(oaIter_oaTrackPattern* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaTrackPattern_Type.tp_alloc(&PyoaIter_oaTrackPattern_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaTrackPatternObject* self = (PyoaIter_oaTrackPatternObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaTrackPattern_getNext_doc[] = 
"Class: oaIter_oaTrackPattern, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaTrackPattern* getNext()\n"
"    Signature: getNext|ptr-oaTrackPattern|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaTrackPattern_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTrackPattern data;
    int convert_status=PyoaIter_oaTrackPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTrackPatternObject* self=(PyoaIter_oaTrackPatternObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTrackPatternp result= (data.DataCall()->getNext());
        return PyoaTrackPattern_FromoaTrackPattern(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaTrackPattern_next_doc[] = 
"Class: oaIter_oaTrackPattern, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaTrackPattern* next()\n"
"    Signature: next|ptr-oaTrackPattern|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaTrackPattern_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaTrackPattern data;
    int convert_status=PyoaIter_oaTrackPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaTrackPatternObject* self=(PyoaIter_oaTrackPatternObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTrackPatternp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaTrackPattern_FromoaTrackPattern(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaTrackPattern_assign_doc[] = 
"Class: oaIter_oaTrackPattern, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaTrackPattern_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaTrackPattern data;
  int convert_status=PyoaIter_oaTrackPattern_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaTrackPattern p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaTrackPattern_Convert,&p1)) {
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

static PyMethodDef oaIter_oaTrackPattern_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaTrackPattern_getNext,METH_VARARGS,oaIter_oaTrackPattern_getNext_doc},
    {"next",(PyCFunction)oaIter_oaTrackPattern_next,METH_VARARGS,oaIter_oaTrackPattern_next_doc},
    {"assign",(PyCFunction)oaIter_oaTrackPattern_tp_assign,METH_VARARGS,oaIter_oaTrackPattern_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaTrackPattern_doc[] = 
"Class: oaIter_oaTrackPattern\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaTrackPattern(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaTrackPattern||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaTrackPattern)\n"
"    Calls: oaIter_oaTrackPattern(const oaIter_oaTrackPattern& iterIn)\n"
"    Signature: oaIter_oaTrackPattern||cref-oaIter_oaTrackPattern,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaTrackPattern)\n"
"    Calls: (const oaIter_oaTrackPattern&)\n"
"    Signature: oaIter_oaTrackPattern||cref-oaIter_oaTrackPattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaTrackPattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaTrackPattern",
    sizeof(PyoaIter_oaTrackPatternObject),
    0,
    (destructor)oaIter_oaTrackPattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaTrackPattern_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaTrackPattern_tp_repr,	/* tp_repr */
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
    oaIter_oaTrackPattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaTrackPattern_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaTrackPattern_iternext,	/* tp_iternext */
    oaIter_oaTrackPattern_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaTrackPattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaTrackPattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaTrackPattern_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaTrackPattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaTrackPattern",
           (PyObject*)(&PyoaIter_oaTrackPattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaTrackPattern\n");
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
// Wrapper Implementation for Class: oaIter_oaValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaValueObject* self = (PyoaIter_oaValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaValue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaValue)
    {
        PyParamoaIter_oaValue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaValue_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaValue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaValue, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaValue)\n"
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
oaIter_oaValue_tp_dealloc(PyoaIter_oaValueObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaValue_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaValue value;
    int convert_status=PyoaIter_oaValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaValue v1;
    PyParamoaIter_oaValue v2;
    int convert_status1=PyoaIter_oaValue_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaValue_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaValue_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaValue ob;
    int convert_status=PyoaIter_oaValue_Convert(self,&ob);
    assert(convert_status!=0);
    oaValue* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaValue_FromoaValue(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaValue_Convert(PyObject* ob,PyParamoaIter_oaValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaValue_Check(ob)) {
        result->SetData( (oaIter_oaValue*) ((PyoaIter_oaValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaValue_FromoaIter_oaValue(oaIter_oaValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaValue_Type.tp_alloc(&PyoaIter_oaValue_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaValueObject* self = (PyoaIter_oaValueObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaValue_getNext_doc[] = 
"Class: oaIter_oaValue, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getNext()\n"
"    Signature: getNext|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaValue_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaValue data;
    int convert_status=PyoaIter_oaValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaValueObject* self=(PyoaIter_oaValueObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getNext());
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaValue_next_doc[] = 
"Class: oaIter_oaValue, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaValue* next()\n"
"    Signature: next|ptr-oaValue|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaValue_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaValue data;
    int convert_status=PyoaIter_oaValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaValueObject* self=(PyoaIter_oaValueObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaValue_assign_doc[] = 
"Class: oaIter_oaValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaValue data;
  int convert_status=PyoaIter_oaValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaValue_Convert,&p1)) {
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

static PyMethodDef oaIter_oaValue_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaValue_getNext,METH_VARARGS,oaIter_oaValue_getNext_doc},
    {"next",(PyCFunction)oaIter_oaValue_next,METH_VARARGS,oaIter_oaValue_next_doc},
    {"assign",(PyCFunction)oaIter_oaValue_tp_assign,METH_VARARGS,oaIter_oaValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaValue_doc[] = 
"Class: oaIter_oaValue\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaValue(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaValue||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaValue)\n"
"    Calls: oaIter_oaValue(const oaIter_oaValue& iterIn)\n"
"    Signature: oaIter_oaValue||cref-oaIter_oaValue,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaValue)\n"
"    Calls: (const oaIter_oaValue&)\n"
"    Signature: oaIter_oaValue||cref-oaIter_oaValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaValue",
    sizeof(PyoaIter_oaValueObject),
    0,
    (destructor)oaIter_oaValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaValue_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaValue_tp_repr,	/* tp_repr */
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
    oaIter_oaValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaValue_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaValue_iternext,	/* tp_iternext */
    oaIter_oaValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaValue_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaValue",
           (PyObject*)(&PyoaIter_oaValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaValue\n");
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
// Wrapper Implementation for Class: oaIter_oaVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaVectorInstObject* self = (PyoaIter_oaVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaVectorInst)
    {
        PyParamoaIter_oaVectorInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaVectorInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaVectorInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaVectorInst)\n"
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
oaIter_oaVectorInst_tp_dealloc(PyoaIter_oaVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaVectorInst value;
    int convert_status=PyoaIter_oaVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaVectorInst v1;
    PyParamoaIter_oaVectorInst v2;
    int convert_status1=PyoaIter_oaVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaVectorInst ob;
    int convert_status=PyoaIter_oaVectorInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaVectorInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaVectorInst_FromoaVectorInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaVectorInst_Convert(PyObject* ob,PyParamoaIter_oaVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaVectorInst_Check(ob)) {
        result->SetData( (oaIter_oaVectorInst*) ((PyoaIter_oaVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaVectorInst_FromoaIter_oaVectorInst(oaIter_oaVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaVectorInst_Type.tp_alloc(&PyoaIter_oaVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaVectorInstObject* self = (PyoaIter_oaVectorInstObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaVectorInst_getNext_doc[] = 
"Class: oaIter_oaVectorInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInst* getNext()\n"
"    Signature: getNext|ptr-oaVectorInst|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaVectorInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInst data;
    int convert_status=PyoaIter_oaVectorInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstObject* self=(PyoaIter_oaVectorInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstp result= (data.DataCall()->getNext());
        return PyoaVectorInst_FromoaVectorInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaVectorInst_next_doc[] = 
"Class: oaIter_oaVectorInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInst* next()\n"
"    Signature: next|ptr-oaVectorInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaVectorInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInst data;
    int convert_status=PyoaIter_oaVectorInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstObject* self=(PyoaIter_oaVectorInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaVectorInst_FromoaVectorInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaVectorInst_assign_doc[] = 
"Class: oaIter_oaVectorInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaVectorInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaVectorInst data;
  int convert_status=PyoaIter_oaVectorInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaVectorInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaVectorInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaVectorInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaVectorInst_getNext,METH_VARARGS,oaIter_oaVectorInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaVectorInst_next,METH_VARARGS,oaIter_oaVectorInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaVectorInst_tp_assign,METH_VARARGS,oaIter_oaVectorInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaVectorInst_doc[] = 
"Class: oaIter_oaVectorInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaVectorInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaVectorInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaVectorInst)\n"
"    Calls: oaIter_oaVectorInst(const oaIter_oaVectorInst& iterIn)\n"
"    Signature: oaIter_oaVectorInst||cref-oaIter_oaVectorInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaVectorInst)\n"
"    Calls: (const oaIter_oaVectorInst&)\n"
"    Signature: oaIter_oaVectorInst||cref-oaIter_oaVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaVectorInst",
    sizeof(PyoaIter_oaVectorInstObject),
    0,
    (destructor)oaIter_oaVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaVectorInst_tp_repr,	/* tp_repr */
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
    oaIter_oaVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaVectorInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaVectorInst_iternext,	/* tp_iternext */
    oaIter_oaVectorInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaVectorInst",
           (PyObject*)(&PyoaIter_oaVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaVectorInst\n");
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
// Wrapper Implementation for Class: oaIter_oaVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaVectorInstBitObject* self = (PyoaIter_oaVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInstBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaVectorInstBit)
    {
        PyParamoaIter_oaVectorInstBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaVectorInstBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInstBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaVectorInstBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaVectorInstBit)\n"
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
oaIter_oaVectorInstBit_tp_dealloc(PyoaIter_oaVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaVectorInstBit value;
    int convert_status=PyoaIter_oaVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaVectorInstBit v1;
    PyParamoaIter_oaVectorInstBit v2;
    int convert_status1=PyoaIter_oaVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaVectorInstBit ob;
    int convert_status=PyoaIter_oaVectorInstBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaVectorInstBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaVectorInstBit_FromoaVectorInstBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaVectorInstBit_Convert(PyObject* ob,PyParamoaIter_oaVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaVectorInstBit_Check(ob)) {
        result->SetData( (oaIter_oaVectorInstBit*) ((PyoaIter_oaVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaVectorInstBit_FromoaIter_oaVectorInstBit(oaIter_oaVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaVectorInstBit_Type.tp_alloc(&PyoaIter_oaVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaVectorInstBitObject* self = (PyoaIter_oaVectorInstBitObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaVectorInstBit_getNext_doc[] = 
"Class: oaIter_oaVectorInstBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInstBit* getNext()\n"
"    Signature: getNext|ptr-oaVectorInstBit|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaVectorInstBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInstBit data;
    int convert_status=PyoaIter_oaVectorInstBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstBitObject* self=(PyoaIter_oaVectorInstBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstBitp result= (data.DataCall()->getNext());
        return PyoaVectorInstBit_FromoaVectorInstBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaVectorInstBit_next_doc[] = 
"Class: oaIter_oaVectorInstBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInstBit* next()\n"
"    Signature: next|ptr-oaVectorInstBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaVectorInstBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInstBit data;
    int convert_status=PyoaIter_oaVectorInstBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstBitObject* self=(PyoaIter_oaVectorInstBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaVectorInstBit_FromoaVectorInstBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaVectorInstBit_assign_doc[] = 
"Class: oaIter_oaVectorInstBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaVectorInstBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaVectorInstBit data;
  int convert_status=PyoaIter_oaVectorInstBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaVectorInstBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaVectorInstBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaVectorInstBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaVectorInstBit_getNext,METH_VARARGS,oaIter_oaVectorInstBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaVectorInstBit_next,METH_VARARGS,oaIter_oaVectorInstBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaVectorInstBit_tp_assign,METH_VARARGS,oaIter_oaVectorInstBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaVectorInstBit_doc[] = 
"Class: oaIter_oaVectorInstBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaVectorInstBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaVectorInstBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaVectorInstBit)\n"
"    Calls: oaIter_oaVectorInstBit(const oaIter_oaVectorInstBit& iterIn)\n"
"    Signature: oaIter_oaVectorInstBit||cref-oaIter_oaVectorInstBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaVectorInstBit)\n"
"    Calls: (const oaIter_oaVectorInstBit&)\n"
"    Signature: oaIter_oaVectorInstBit||cref-oaIter_oaVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaVectorInstBit",
    sizeof(PyoaIter_oaVectorInstBitObject),
    0,
    (destructor)oaIter_oaVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaVectorInstBit_tp_repr,	/* tp_repr */
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
    oaIter_oaVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaVectorInstBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaVectorInstBit_iternext,	/* tp_iternext */
    oaIter_oaVectorInstBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaVectorInstBit",
           (PyObject*)(&PyoaIter_oaVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaVectorInstBit\n");
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
// Wrapper Implementation for Class: oaIter_oaVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaVectorInstDefObject* self = (PyoaIter_oaVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaVectorInstDef)
    {
        PyParamoaIter_oaVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaVectorInstDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaVectorInstDef)\n"
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
oaIter_oaVectorInstDef_tp_dealloc(PyoaIter_oaVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaVectorInstDef value;
    int convert_status=PyoaIter_oaVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaVectorInstDef v1;
    PyParamoaIter_oaVectorInstDef v2;
    int convert_status1=PyoaIter_oaVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVectorInstDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaVectorInstDef ob;
    int convert_status=PyoaIter_oaVectorInstDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaVectorInstDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaVectorInstDef_FromoaVectorInstDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaVectorInstDef_Convert(PyObject* ob,PyParamoaIter_oaVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaVectorInstDef_Check(ob)) {
        result->SetData( (oaIter_oaVectorInstDef*) ((PyoaIter_oaVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaVectorInstDef_FromoaIter_oaVectorInstDef(oaIter_oaVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaVectorInstDef_Type.tp_alloc(&PyoaIter_oaVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaVectorInstDefObject* self = (PyoaIter_oaVectorInstDefObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaVectorInstDef_getNext_doc[] = 
"Class: oaIter_oaVectorInstDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInstDef* getNext()\n"
"    Signature: getNext|ptr-oaVectorInstDef|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaVectorInstDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInstDef data;
    int convert_status=PyoaIter_oaVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstDefObject* self=(PyoaIter_oaVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstDefp result= (data.DataCall()->getNext());
        return PyoaVectorInstDef_FromoaVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaVectorInstDef_next_doc[] = 
"Class: oaIter_oaVectorInstDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaVectorInstDef* next()\n"
"    Signature: next|ptr-oaVectorInstDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaVectorInstDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVectorInstDef data;
    int convert_status=PyoaIter_oaVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaVectorInstDefObject* self=(PyoaIter_oaVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaVectorInstDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaVectorInstDef_FromoaVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaVectorInstDef_assign_doc[] = 
"Class: oaIter_oaVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaVectorInstDef data;
  int convert_status=PyoaIter_oaVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaVectorInstDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaVectorInstDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaVectorInstDef_getNext,METH_VARARGS,oaIter_oaVectorInstDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaVectorInstDef_next,METH_VARARGS,oaIter_oaVectorInstDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaVectorInstDef_tp_assign,METH_VARARGS,oaIter_oaVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaVectorInstDef_doc[] = 
"Class: oaIter_oaVectorInstDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaVectorInstDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaVectorInstDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaVectorInstDef)\n"
"    Calls: oaIter_oaVectorInstDef(const oaIter_oaVectorInstDef& iterIn)\n"
"    Signature: oaIter_oaVectorInstDef||cref-oaIter_oaVectorInstDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaVectorInstDef)\n"
"    Calls: (const oaIter_oaVectorInstDef&)\n"
"    Signature: oaIter_oaVectorInstDef||cref-oaIter_oaVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaVectorInstDef",
    sizeof(PyoaIter_oaVectorInstDefObject),
    0,
    (destructor)oaIter_oaVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaVectorInstDef_tp_repr,	/* tp_repr */
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
    oaIter_oaVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaVectorInstDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaVectorInstDef_iternext,	/* tp_iternext */
    oaIter_oaVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaVectorInstDef",
           (PyObject*)(&PyoaIter_oaVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaVectorInstDef\n");
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
// Wrapper Implementation for Class: oaIter_oaVia
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVia_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaVia_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViaObject* self = (PyoaIter_oaViaObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVia(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaVia)
    {
        PyParamoaIter_oaVia p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaVia_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaVia(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaVia, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaVia)\n"
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
oaIter_oaVia_tp_dealloc(PyoaIter_oaViaObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaVia*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVia_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaVia value;
    int convert_status=PyoaIter_oaVia_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaIter_oaVia::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaVia_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaVia v1;
    PyParamoaIter_oaVia v2;
    int convert_status1=PyoaIter_oaVia_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaVia_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaVia_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaVia_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaVia ob;
    int convert_status=PyoaIter_oaVia_Convert(self,&ob);
    assert(convert_status!=0);
    oaVia* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaVia_FromoaVia(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaVia_Convert(PyObject* ob,PyParamoaIter_oaVia* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaVia_Check(ob)) {
        result->SetData( (oaIter_oaVia*) ((PyoaIter_oaViaObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaVia Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaVia_FromoaIter_oaVia(oaIter_oaVia* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaVia_Type.tp_alloc(&PyoaIter_oaVia_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViaObject* self = (PyoaIter_oaViaObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaVia_getNext_doc[] = 
"Class: oaIter_oaVia, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaVia* getNext()\n"
"    Signature: getNext|ptr-oaVia|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaVia_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVia data;
    int convert_status=PyoaIter_oaVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaObject* self=(PyoaIter_oaViaObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViap result= (data.DataCall()->getNext());
        return PyoaVia_FromoaVia(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaVia_next_doc[] = 
"Class: oaIter_oaVia, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaVia* next()\n"
"    Signature: next|ptr-oaVia|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaVia_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaVia data;
    int convert_status=PyoaIter_oaVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaObject* self=(PyoaIter_oaViaObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViap result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaVia_FromoaVia(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaVia_assign_doc[] = 
"Class: oaIter_oaVia, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaVia_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaVia data;
  int convert_status=PyoaIter_oaVia_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaVia p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaVia_Convert,&p1)) {
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

static PyMethodDef oaIter_oaVia_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaVia_getNext,METH_VARARGS,oaIter_oaVia_getNext_doc},
    {"next",(PyCFunction)oaIter_oaVia_next,METH_VARARGS,oaIter_oaVia_next_doc},
    {"assign",(PyCFunction)oaIter_oaVia_tp_assign,METH_VARARGS,oaIter_oaVia_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaVia_doc[] = 
"Class: oaIter_oaVia\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaVia(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaVia||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaVia)\n"
"    Calls: oaIter_oaVia(const oaIter_oaVia& iterIn)\n"
"    Signature: oaIter_oaVia||cref-oaIter_oaVia,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaVia)\n"
"    Calls: (const oaIter_oaVia&)\n"
"    Signature: oaIter_oaVia||cref-oaIter_oaVia,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaVia_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaVia",
    sizeof(PyoaIter_oaViaObject),
    0,
    (destructor)oaIter_oaVia_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaVia_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaVia_tp_repr,	/* tp_repr */
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
    oaIter_oaVia_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaVia_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaVia_iternext,	/* tp_iternext */
    oaIter_oaVia_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaVia_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaVia_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaVia_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaVia\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaVia",
           (PyObject*)(&PyoaIter_oaVia_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaVia\n");
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
// Wrapper Implementation for Class: oaIter_oaViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViaDefObject* self = (PyoaIter_oaViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaViaDef)
    {
        PyParamoaIter_oaViaDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaViaDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaViaDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaViaDef)\n"
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
oaIter_oaViaDef_tp_dealloc(PyoaIter_oaViaDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaViaDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaViaDef value;
    int convert_status=PyoaIter_oaViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaViaDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaViaDef v1;
    PyParamoaIter_oaViaDef v2;
    int convert_status1=PyoaIter_oaViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaViaDef ob;
    int convert_status=PyoaIter_oaViaDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaViaDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaViaDef_FromoaViaDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaViaDef_Convert(PyObject* ob,PyParamoaIter_oaViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaViaDef_Check(ob)) {
        result->SetData( (oaIter_oaViaDef*) ((PyoaIter_oaViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaViaDef_FromoaIter_oaViaDef(oaIter_oaViaDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaViaDef_Type.tp_alloc(&PyoaIter_oaViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViaDefObject* self = (PyoaIter_oaViaDefObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaViaDef_getNext_doc[] = 
"Class: oaIter_oaViaDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaViaDef* getNext()\n"
"    Signature: getNext|ptr-oaViaDef|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaViaDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaDef data;
    int convert_status=PyoaIter_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaDefObject* self=(PyoaIter_oaViaDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaDefp result= (data.DataCall()->getNext());
        return PyoaViaDef_FromoaViaDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaViaDef_next_doc[] = 
"Class: oaIter_oaViaDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaViaDef* next()\n"
"    Signature: next|ptr-oaViaDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaViaDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaDef data;
    int convert_status=PyoaIter_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaDefObject* self=(PyoaIter_oaViaDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaViaDef_FromoaViaDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaViaDef_assign_doc[] = 
"Class: oaIter_oaViaDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaViaDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaViaDef data;
  int convert_status=PyoaIter_oaViaDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaViaDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaViaDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaViaDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaViaDef_getNext,METH_VARARGS,oaIter_oaViaDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaViaDef_next,METH_VARARGS,oaIter_oaViaDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaViaDef_tp_assign,METH_VARARGS,oaIter_oaViaDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaViaDef_doc[] = 
"Class: oaIter_oaViaDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaViaDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaViaDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaViaDef)\n"
"    Calls: oaIter_oaViaDef(const oaIter_oaViaDef& iterIn)\n"
"    Signature: oaIter_oaViaDef||cref-oaIter_oaViaDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaViaDef)\n"
"    Calls: (const oaIter_oaViaDef&)\n"
"    Signature: oaIter_oaViaDef||cref-oaIter_oaViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaViaDef",
    sizeof(PyoaIter_oaViaDefObject),
    0,
    (destructor)oaIter_oaViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaViaDef_tp_repr,	/* tp_repr */
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
    oaIter_oaViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaViaDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaViaDef_iternext,	/* tp_iternext */
    oaIter_oaViaDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaViaDef",
           (PyObject*)(&PyoaIter_oaViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaViaDef\n");
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
// Wrapper Implementation for Class: oaIter_oaViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViaHeaderObject* self = (PyoaIter_oaViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaViaHeader)
    {
        PyParamoaIter_oaViaHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaViaHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaViaHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaViaHeader)\n"
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
oaIter_oaViaHeader_tp_dealloc(PyoaIter_oaViaHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaViaHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaViaHeader value;
    int convert_status=PyoaIter_oaViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaViaHeader v1;
    PyParamoaIter_oaViaHeader v2;
    int convert_status1=PyoaIter_oaViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaViaHeader ob;
    int convert_status=PyoaIter_oaViaHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaViaHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaViaHeader_FromoaViaHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaViaHeader_Convert(PyObject* ob,PyParamoaIter_oaViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaViaHeader_Check(ob)) {
        result->SetData( (oaIter_oaViaHeader*) ((PyoaIter_oaViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaViaHeader_FromoaIter_oaViaHeader(oaIter_oaViaHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaViaHeader_Type.tp_alloc(&PyoaIter_oaViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViaHeaderObject* self = (PyoaIter_oaViaHeaderObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaViaHeader_getNext_doc[] = 
"Class: oaIter_oaViaHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaViaHeader* getNext()\n"
"    Signature: getNext|ptr-oaViaHeader|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaViaHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaHeader data;
    int convert_status=PyoaIter_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaHeaderObject* self=(PyoaIter_oaViaHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaHeaderp result= (data.DataCall()->getNext());
        return PyoaViaHeader_FromoaViaHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaViaHeader_next_doc[] = 
"Class: oaIter_oaViaHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaViaHeader* next()\n"
"    Signature: next|ptr-oaViaHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaViaHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaHeader data;
    int convert_status=PyoaIter_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaHeaderObject* self=(PyoaIter_oaViaHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaViaHeader_FromoaViaHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaViaHeader_assign_doc[] = 
"Class: oaIter_oaViaHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaViaHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaViaHeader data;
  int convert_status=PyoaIter_oaViaHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaViaHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaViaHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaViaHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaViaHeader_getNext,METH_VARARGS,oaIter_oaViaHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaViaHeader_next,METH_VARARGS,oaIter_oaViaHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaViaHeader_tp_assign,METH_VARARGS,oaIter_oaViaHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaViaHeader_doc[] = 
"Class: oaIter_oaViaHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaViaHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaViaHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaViaHeader)\n"
"    Calls: oaIter_oaViaHeader(const oaIter_oaViaHeader& iterIn)\n"
"    Signature: oaIter_oaViaHeader||cref-oaIter_oaViaHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaViaHeader)\n"
"    Calls: (const oaIter_oaViaHeader&)\n"
"    Signature: oaIter_oaViaHeader||cref-oaIter_oaViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaViaHeader",
    sizeof(PyoaIter_oaViaHeaderObject),
    0,
    (destructor)oaIter_oaViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaViaHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaViaHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaViaHeader_iternext,	/* tp_iternext */
    oaIter_oaViaHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaViaHeader",
           (PyObject*)(&PyoaIter_oaViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaViaHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaViaSpec
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaSpec_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaViaSpec_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViaSpecObject* self = (PyoaIter_oaViaSpecObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaViaSpec)
    {
        PyParamoaIter_oaViaSpec p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaViaSpec_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViaSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaViaSpec, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaViaSpec)\n"
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
oaIter_oaViaSpec_tp_dealloc(PyoaIter_oaViaSpecObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaViaSpec*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaSpec_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaViaSpec value;
    int convert_status=PyoaIter_oaViaSpec_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaViaSpec::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaViaSpec_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaViaSpec v1;
    PyParamoaIter_oaViaSpec v2;
    int convert_status1=PyoaIter_oaViaSpec_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaViaSpec_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaSpec_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViaSpec_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaViaSpec ob;
    int convert_status=PyoaIter_oaViaSpec_Convert(self,&ob);
    assert(convert_status!=0);
    oaViaSpec* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaViaSpec_FromoaViaSpec(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaViaSpec_Convert(PyObject* ob,PyParamoaIter_oaViaSpec* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaViaSpec_Check(ob)) {
        result->SetData( (oaIter_oaViaSpec*) ((PyoaIter_oaViaSpecObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaViaSpec Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaViaSpec_FromoaIter_oaViaSpec(oaIter_oaViaSpec* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaViaSpec_Type.tp_alloc(&PyoaIter_oaViaSpec_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViaSpecObject* self = (PyoaIter_oaViaSpecObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaViaSpec_getNext_doc[] = 
"Class: oaIter_oaViaSpec, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaViaSpec* getNext()\n"
"    Signature: getNext|ptr-oaViaSpec|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaViaSpec_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaSpec data;
    int convert_status=PyoaIter_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaSpecObject* self=(PyoaIter_oaViaSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaSpecp result= (data.DataCall()->getNext());
        return PyoaViaSpec_FromoaViaSpec(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaViaSpec_next_doc[] = 
"Class: oaIter_oaViaSpec, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaViaSpec* next()\n"
"    Signature: next|ptr-oaViaSpec|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaViaSpec_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViaSpec data;
    int convert_status=PyoaIter_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViaSpecObject* self=(PyoaIter_oaViaSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViaSpecp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaViaSpec_FromoaViaSpec(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaViaSpec_assign_doc[] = 
"Class: oaIter_oaViaSpec, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaViaSpec_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaViaSpec data;
  int convert_status=PyoaIter_oaViaSpec_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaViaSpec p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaViaSpec_Convert,&p1)) {
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

static PyMethodDef oaIter_oaViaSpec_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaViaSpec_getNext,METH_VARARGS,oaIter_oaViaSpec_getNext_doc},
    {"next",(PyCFunction)oaIter_oaViaSpec_next,METH_VARARGS,oaIter_oaViaSpec_next_doc},
    {"assign",(PyCFunction)oaIter_oaViaSpec_tp_assign,METH_VARARGS,oaIter_oaViaSpec_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaViaSpec_doc[] = 
"Class: oaIter_oaViaSpec\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaViaSpec(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaViaSpec||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaViaSpec)\n"
"    Calls: oaIter_oaViaSpec(const oaIter_oaViaSpec& iterIn)\n"
"    Signature: oaIter_oaViaSpec||cref-oaIter_oaViaSpec,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaViaSpec)\n"
"    Calls: (const oaIter_oaViaSpec&)\n"
"    Signature: oaIter_oaViaSpec||cref-oaIter_oaViaSpec,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaViaSpec_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaViaSpec",
    sizeof(PyoaIter_oaViaSpecObject),
    0,
    (destructor)oaIter_oaViaSpec_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaViaSpec_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaViaSpec_tp_repr,	/* tp_repr */
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
    oaIter_oaViaSpec_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaViaSpec_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaViaSpec_iternext,	/* tp_iternext */
    oaIter_oaViaSpec_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaViaSpec_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaViaSpec_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaViaSpec_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaViaSpec\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaViaSpec",
           (PyObject*)(&PyoaIter_oaViaSpec_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaViaSpec\n");
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
// Wrapper Implementation for Class: oaIter_oaView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViewObject* self = (PyoaIter_oaViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaView(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaView)
    {
        PyParamoaIter_oaView p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaView_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaView(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaView, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaView)\n"
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
oaIter_oaView_tp_dealloc(PyoaIter_oaViewObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaView*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaView_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaView value;
    int convert_status=PyoaIter_oaView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaView v1;
    PyParamoaIter_oaView v2;
    int convert_status1=PyoaIter_oaView_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaView_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaView_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaView ob;
    int convert_status=PyoaIter_oaView_Convert(self,&ob);
    assert(convert_status!=0);
    oaView* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaView_FromoaView(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaView_Convert(PyObject* ob,PyParamoaIter_oaView* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaView_Check(ob)) {
        result->SetData( (oaIter_oaView*) ((PyoaIter_oaViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaView_FromoaIter_oaView(oaIter_oaView* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaView_Type.tp_alloc(&PyoaIter_oaView_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViewObject* self = (PyoaIter_oaViewObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaView_getNext_doc[] = 
"Class: oaIter_oaView, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaView* getNext()\n"
"    Signature: getNext|ptr-oaView|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaView_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaView data;
    int convert_status=PyoaIter_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViewObject* self=(PyoaIter_oaViewObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViewp result= (data.DataCall()->getNext());
        return PyoaView_FromoaView(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaView_next_doc[] = 
"Class: oaIter_oaView, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaView* next()\n"
"    Signature: next|ptr-oaView|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaView_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaView data;
    int convert_status=PyoaIter_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViewObject* self=(PyoaIter_oaViewObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViewp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaView_FromoaView(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaView_assign_doc[] = 
"Class: oaIter_oaView, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaView_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaView data;
  int convert_status=PyoaIter_oaView_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaView p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaView_Convert,&p1)) {
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

static PyMethodDef oaIter_oaView_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaView_getNext,METH_VARARGS,oaIter_oaView_getNext_doc},
    {"next",(PyCFunction)oaIter_oaView_next,METH_VARARGS,oaIter_oaView_next_doc},
    {"assign",(PyCFunction)oaIter_oaView_tp_assign,METH_VARARGS,oaIter_oaView_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaView_doc[] = 
"Class: oaIter_oaView\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaView(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaView||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaView)\n"
"    Calls: oaIter_oaView(const oaIter_oaView& iterIn)\n"
"    Signature: oaIter_oaView||cref-oaIter_oaView,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaView)\n"
"    Calls: (const oaIter_oaView&)\n"
"    Signature: oaIter_oaView||cref-oaIter_oaView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaView",
    sizeof(PyoaIter_oaViewObject),
    0,
    (destructor)oaIter_oaView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaView_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaView_tp_repr,	/* tp_repr */
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
    oaIter_oaView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaView_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaView_iternext,	/* tp_iternext */
    oaIter_oaView_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaView_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaView",
           (PyObject*)(&PyoaIter_oaView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaView\n");
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
// Wrapper Implementation for Class: oaIter_oaViewType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViewType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaViewType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaViewTypeObject* self = (PyoaIter_oaViewTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViewType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaViewType)
    {
        PyParamoaIter_oaViewType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaViewType_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaViewType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaViewType, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaViewType)\n"
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
oaIter_oaViewType_tp_dealloc(PyoaIter_oaViewTypeObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaViewType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViewType_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaViewType value;
    int convert_status=PyoaIter_oaViewType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaIter_oaViewType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaViewType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaViewType v1;
    PyParamoaIter_oaViewType v2;
    int convert_status1=PyoaIter_oaViewType_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaViewType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaViewType_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaViewType_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaViewType ob;
    int convert_status=PyoaIter_oaViewType_Convert(self,&ob);
    assert(convert_status!=0);
    oaViewType* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaViewType_FromoaViewType(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaViewType_Convert(PyObject* ob,PyParamoaIter_oaViewType* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaViewType_Check(ob)) {
        result->SetData( (oaIter_oaViewType*) ((PyoaIter_oaViewTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaViewType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaViewType_FromoaIter_oaViewType(oaIter_oaViewType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaViewType_Type.tp_alloc(&PyoaIter_oaViewType_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaViewTypeObject* self = (PyoaIter_oaViewTypeObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaViewType_getNext_doc[] = 
"Class: oaIter_oaViewType, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaViewType* getNext()\n"
"    Signature: getNext|ptr-oaViewType|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaViewType_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViewType data;
    int convert_status=PyoaIter_oaViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViewTypeObject* self=(PyoaIter_oaViewTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViewTypep result= (data.DataCall()->getNext());
        return PyoaViewType_FromoaViewType(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaViewType_next_doc[] = 
"Class: oaIter_oaViewType, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaViewType* next()\n"
"    Signature: next|ptr-oaViewType|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaViewType_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaViewType data;
    int convert_status=PyoaIter_oaViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaViewTypeObject* self=(PyoaIter_oaViewTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaViewTypep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaViewType_FromoaViewType(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaViewType_assign_doc[] = 
"Class: oaIter_oaViewType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaViewType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaViewType data;
  int convert_status=PyoaIter_oaViewType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaViewType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaViewType_Convert,&p1)) {
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

static PyMethodDef oaIter_oaViewType_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaViewType_getNext,METH_VARARGS,oaIter_oaViewType_getNext_doc},
    {"next",(PyCFunction)oaIter_oaViewType_next,METH_VARARGS,oaIter_oaViewType_next_doc},
    {"assign",(PyCFunction)oaIter_oaViewType_tp_assign,METH_VARARGS,oaIter_oaViewType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaViewType_doc[] = 
"Class: oaIter_oaViewType\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaViewType(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaViewType||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaViewType)\n"
"    Calls: oaIter_oaViewType(const oaIter_oaViewType& iterIn)\n"
"    Signature: oaIter_oaViewType||cref-oaIter_oaViewType,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaViewType)\n"
"    Calls: (const oaIter_oaViewType&)\n"
"    Signature: oaIter_oaViewType||cref-oaIter_oaViewType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaViewType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaViewType",
    sizeof(PyoaIter_oaViewTypeObject),
    0,
    (destructor)oaIter_oaViewType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaViewType_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaViewType_tp_repr,	/* tp_repr */
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
    oaIter_oaViewType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaViewType_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaViewType_iternext,	/* tp_iternext */
    oaIter_oaViewType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaViewType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaViewType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaViewType_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaViewType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaViewType",
           (PyObject*)(&PyoaIter_oaViewType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaViewType\n");
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
// Wrapper Implementation for Class: oaIter_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaWaferObject* self = (PyoaIter_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaWafer_oaWafer)
    {
        PyParamoaCollection_oaWafer_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaWafer_oaWafer_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaWafer)
    {
        PyParamoaIter_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaWafer_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaWafer, Choices are:\n"
        "    (oaCollection_oaWafer_oaWafer)\n"
        "    (oaIter_oaWafer)\n"
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
oaIter_oaWafer_tp_dealloc(PyoaIter_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaWafer value;
    int convert_status=PyoaIter_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaWafer v1;
    PyParamoaIter_oaWafer v2;
    int convert_status1=PyoaIter_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaWafer_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWafer_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaWafer ob;
    int convert_status=PyoaIter_oaWafer_Convert(self,&ob);
    assert(convert_status!=0);
    oaWafer* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaWafer_FromoaWafer(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaWafer_Convert(PyObject* ob,PyParamoaIter_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaWafer_Check(ob)) {
        result->SetData( (oaIter_oaWafer*) ((PyoaIter_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaWafer_FromoaIter_oaWafer(oaIter_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaWafer_Type.tp_alloc(&PyoaIter_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaWaferObject* self = (PyoaIter_oaWaferObject*)bself;
        self->value = (oaDatabaseIter*)  data;
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
static char oaIter_oaWafer_getNext_doc[] = 
"Class: oaIter_oaWafer, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaWafer* getNext()\n"
"    Signature: getNext|ptr-oaWafer|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaWafer_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaWafer data;
    int convert_status=PyoaIter_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaWaferObject* self=(PyoaIter_oaWaferObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferp result= (data.DataCall()->getNext());
        return PyoaWafer_FromoaWafer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaWafer_next_doc[] = 
"Class: oaIter_oaWafer, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaWafer* next()\n"
"    Signature: next|ptr-oaWafer|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaWafer_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaWafer data;
    int convert_status=PyoaIter_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaWaferObject* self=(PyoaIter_oaWaferObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaWafer_FromoaWafer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaWafer_assign_doc[] = 
"Class: oaIter_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaWafer data;
  int convert_status=PyoaIter_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaWafer_Convert,&p1)) {
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

static PyMethodDef oaIter_oaWafer_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaWafer_getNext,METH_VARARGS,oaIter_oaWafer_getNext_doc},
    {"next",(PyCFunction)oaIter_oaWafer_next,METH_VARARGS,oaIter_oaWafer_next_doc},
    {"assign",(PyCFunction)oaIter_oaWafer_tp_assign,METH_VARARGS,oaIter_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaWafer_doc[] = 
"Class: oaIter_oaWafer\n"
"  Class type oaIter_oaWafer\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaWafer_oaWafer)\n"
"    Calls: oaIter_oaWafer(const oaCollection_oaWafer_oaWafer& c)\n"
"    Signature: oaIter_oaWafer||cref-oaCollection_oaWafer_oaWafer,\n"
"    Constructor oaIter_oaWafer\n"
"  Paramegers: (oaIter_oaWafer)\n"
"    Calls: oaIter_oaWafer(const oaIter_oaWafer& iterIn)\n"
"    Signature: oaIter_oaWafer||cref-oaIter_oaWafer,\n"
"    Constructor oaIter_oaWafer\n"
"  Paramegers: (oaIter_oaWafer)\n"
"    Calls: (const oaIter_oaWafer&)\n"
"    Signature: oaIter_oaWafer||cref-oaIter_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaWafer",
    sizeof(PyoaIter_oaWaferObject),
    0,
    (destructor)oaIter_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaWafer_tp_repr,	/* tp_repr */
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
    oaIter_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaWafer_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaWafer_iternext,	/* tp_iternext */
    oaIter_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaWafer",
           (PyObject*)(&PyoaIter_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaWafer\n");
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
// Wrapper Implementation for Class: oaIter_oaWaferFeature
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWaferFeature_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaWaferFeature_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaWaferFeatureObject* self = (PyoaIter_oaWaferFeatureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaWaferFeature(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaWaferFeature)
    {
        PyParamoaIter_oaWaferFeature p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaWaferFeature_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaWaferFeature(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaWaferFeature, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaWaferFeature)\n"
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
oaIter_oaWaferFeature_tp_dealloc(PyoaIter_oaWaferFeatureObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaWaferFeature*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWaferFeature_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaWaferFeature value;
    int convert_status=PyoaIter_oaWaferFeature_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaWaferFeature::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaWaferFeature_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaWaferFeature v1;
    PyParamoaIter_oaWaferFeature v2;
    int convert_status1=PyoaIter_oaWaferFeature_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaWaferFeature_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaWaferFeature_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaWaferFeature_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaWaferFeature ob;
    int convert_status=PyoaIter_oaWaferFeature_Convert(self,&ob);
    assert(convert_status!=0);
    oaWaferFeature* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaWaferFeature_FromoaWaferFeature(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaWaferFeature_Convert(PyObject* ob,PyParamoaIter_oaWaferFeature* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaWaferFeature_Check(ob)) {
        result->SetData( (oaIter_oaWaferFeature*) ((PyoaIter_oaWaferFeatureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaWaferFeature Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaWaferFeature_FromoaIter_oaWaferFeature(oaIter_oaWaferFeature* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaWaferFeature_Type.tp_alloc(&PyoaIter_oaWaferFeature_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaWaferFeatureObject* self = (PyoaIter_oaWaferFeatureObject*)bself;
        self->value = (oaBaseIter*)  data;
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
static char oaIter_oaWaferFeature_getNext_doc[] = 
"Class: oaIter_oaWaferFeature, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaWaferFeature* getNext()\n"
"    Signature: getNext|ptr-oaWaferFeature|\n"
"    BrowseData: 1\n"
"    This function returns the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    The order in which objects are returned by oaIter::getNext() is not guaranteed to be the same:\n"
"    between two separate instantiations of an oaIter class over the same set of objects\n"
"    after calling oaIter::reset()\n"
"    When an iterator is active it is safe to delete objects that have already been returned by that iterator, including the most recent getNext() call. Such deletion will not cause the iterator to return invalid objects or to skip other objects in the collection that is being iterated over.\n"
"    It is not safe to delete an object in the collection that has not yet been returned by the iterator. Such deletion will invalidate the iterator and can cause problem results, including returning invalid objects, throwing exceptions, and skipping members of the collection.\n"
"    Further, adding objects to a collection while iterating over the collection is not recommended since subsequent getNext() return results on a collection after the addition of objects to the collection are undefined.\n"
;

static PyObject*
oaIter_oaWaferFeature_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaWaferFeature data;
    int convert_status=PyoaIter_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaWaferFeatureObject* self=(PyoaIter_oaWaferFeatureObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferFeaturep result= (data.DataCall()->getNext());
        return PyoaWaferFeature_FromoaWaferFeature(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaWaferFeature_next_doc[] = 
"Class: oaIter_oaWaferFeature, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaWaferFeature* next()\n"
"    Signature: next|ptr-oaWaferFeature|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaWaferFeature_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaWaferFeature data;
    int convert_status=PyoaIter_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaWaferFeatureObject* self=(PyoaIter_oaWaferFeatureObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferFeaturep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaWaferFeature_FromoaWaferFeature(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaWaferFeature_assign_doc[] = 
"Class: oaIter_oaWaferFeature, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaWaferFeature_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaWaferFeature data;
  int convert_status=PyoaIter_oaWaferFeature_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaWaferFeature p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaWaferFeature_Convert,&p1)) {
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

static PyMethodDef oaIter_oaWaferFeature_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaWaferFeature_getNext,METH_VARARGS,oaIter_oaWaferFeature_getNext_doc},
    {"next",(PyCFunction)oaIter_oaWaferFeature_next,METH_VARARGS,oaIter_oaWaferFeature_next_doc},
    {"assign",(PyCFunction)oaIter_oaWaferFeature_tp_assign,METH_VARARGS,oaIter_oaWaferFeature_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaWaferFeature_doc[] = 
"Class: oaIter_oaWaferFeature\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaWaferFeature(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaWaferFeature||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaWaferFeature)\n"
"    Calls: oaIter_oaWaferFeature(const oaIter_oaWaferFeature& iterIn)\n"
"    Signature: oaIter_oaWaferFeature||cref-oaIter_oaWaferFeature,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaWaferFeature)\n"
"    Calls: (const oaIter_oaWaferFeature&)\n"
"    Signature: oaIter_oaWaferFeature||cref-oaIter_oaWaferFeature,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaWaferFeature_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaWaferFeature",
    sizeof(PyoaIter_oaWaferFeatureObject),
    0,
    (destructor)oaIter_oaWaferFeature_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaWaferFeature_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaWaferFeature_tp_repr,	/* tp_repr */
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
    oaIter_oaWaferFeature_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaWaferFeature_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaWaferFeature_iternext,	/* tp_iternext */
    oaIter_oaWaferFeature_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaWaferFeature_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaWaferFeature_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaWaferFeature_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaWaferFeature\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaWaferFeature",
           (PyObject*)(&PyoaIter_oaWaferFeature_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaWaferFeature\n");
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
// Wrapper Implementation for Class: oaLPPHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLPPHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLPPHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLPPHeaderObject* self = (PyoaLPPHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLPPHeader)
    {
        PyParamoaLPPHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLPPHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLPPHeader, Choices are:\n"
        "    (oaLPPHeader)\n"
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
oaLPPHeader_tp_dealloc(PyoaLPPHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLPPHeader_tp_repr(PyObject *ob)
{
    PyParamoaLPPHeader value;
    int convert_status=PyoaLPPHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaLPPHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLPPHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLPPHeader v1;
    PyParamoaLPPHeader v2;
    int convert_status1=PyoaLPPHeader_Convert(ob1,&v1);
    int convert_status2=PyoaLPPHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLPPHeader_Convert(PyObject* ob,PyParamoaLPPHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaLPPHeader_Check(ob)) {
        result->SetData( (oaLPPHeader**) ((PyoaLPPHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLPPHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLPPHeader_FromoaLPPHeader(oaLPPHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLPPHeader* data=*value;
        PyObject* bself = PyoaLPPHeader_Type.tp_alloc(&PyoaLPPHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaLPPHeaderObject* self = (PyoaLPPHeaderObject*)bself;
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
PyObject* PyoaLPPHeader_FromoaLPPHeader(oaLPPHeader* data)
{
    if (data) {
       PyObject* bself = PyoaLPPHeader_Type.tp_alloc(&PyoaLPPHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaLPPHeaderObject* self = (PyoaLPPHeaderObject*)bself;
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
static char oaLPPHeader_getLayer_doc[] = 
"Class: oaLPPHeader, Function: getLayer\n"
"  Paramegers: ()\n"
"    Calls: oaLayer* getLayer() const\n"
"    Signature: getLayer|ptr-oaLayer|\n"
"    BrowseData: 1\n"
"    This function attempts to return the pointer to the technology oaLayer object that corresponds to the layer that this oaLPPHeader represents. If this lppHeader cannot be bound, a NULL value is returned.\n"
;

static PyObject*
oaLPPHeader_getLayer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerp result= (data.DataCall()->getLayer());
        return PyoaLayer_FromoaLayer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_getLayerHeader_doc[] = 
"Class: oaLPPHeader, Function: getLayerHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getLayerHeader() const\n"
"    Signature: getLayerHeader|ptr-oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layerHeader to which this lppHeader is attached. An oaLPPHeader object is always attached to an oaLayerHeader which has the same layer as the oaLPPHeader object. If an oaLayerHeader object with the same layer does not exist when the oaLPPHeader is creates, one is created and the oaLPPHeader is attached to it.\n"
;

static PyObject*
oaLPPHeader_getLayerHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getLayerHeader());
        return PyoaLayerHeader_FromoaLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_getLayerNum_doc[] = 
"Class: oaLPPHeader, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer associcated with this oaLPPHeader object. This is a cached value that remains valid even if the oaLPPHeader is not bound.\n"
;

static PyObject*
oaLPPHeader_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
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
static char oaLPPHeader_getPurpose_doc[] = 
"Class: oaLPPHeader, Function: getPurpose\n"
"  Paramegers: ()\n"
"    Calls: oaPurpose* getPurpose() const\n"
"    Signature: getPurpose|ptr-oaPurpose|\n"
"    BrowseData: 1\n"
"    This function attempts to return the pointer to the technology oaPurpose object that corresponds to the purpose that this oaLPPHeader represents. If this lppHeader cannot be bound, a NULL value is returned.\n"
;

static PyObject*
oaLPPHeader_getPurpose(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposep result= (data.DataCall()->getPurpose());
        return PyoaPurpose_FromoaPurpose(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_getPurposeNum_doc[] = 
"Class: oaLPPHeader, Function: getPurposeNum\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeNum getPurposeNum() const\n"
"    Signature: getPurposeNum|simple-oaPurposeNum|\n"
"    BrowseData: 1\n"
"    This function returns the purpose associated with this oaLPPHeader object. This is a cached value that remains valid even if the oaLPPHeader is not bound.\n"
;

static PyObject*
oaLPPHeader_getPurposeNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeNum result= (data.DataCall()->getPurposeNum());
        return PyoaPurposeNum_FromoaPurposeNum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_getShapeBBox_doc[] = 
"Class: oaLPPHeader, Function: getShapeBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getShapeBBox(oaBox& bBox) const\n"
"    Signature: getShapeBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the merged bBox of all the oaShape objects that have the same layer and purpose that this oaLPPHeader represents.\n"
"    Note that although lppHeaders will exist in the current open design for all LPPs used in the current design and in any open design in the hierarchy underneath the current design, this function does not take into account shapes inside design instances below the current hierarchy level.\n"
"    Here is an example with three levels of hierarchy:\n"
"      The top design has no shapes in it. The top design contains an instance of a middle design.\n"
"      The middle design has a shape in LPP(1, 1). The middle design contains an instance of a bottom design.\n"
"      The bottom design contains a shape in LPP(2, 2).\n"
"    The top design will have two lppHeaders: one for LPP(1, 1) and the other for LPP(2, 2). However, if the application iterates through the lppHeaders of the top design, lppHeader-> getShapeBBox() will return an inverted bbox for each iteration since there are no shapes in the top design.\n"
"    The middle design also will have two lppHeaders: one for LPP(1, 1) and the other for LPP(2, 2). If the application iterates through the lppHeaders of the middle design, the lppHeader that represents LPP(1, 1) will return a valid bbox when lppHeader-> getShapeBBox() is called on that lppHeader.\n"
"    The bottom design contains one lppHeader for LPP(2,2). When lppHeader-> getShapeBBox() is called on that lppHeader, it will return a valid bbox.\n"
"    bBox\n"
"    A reference to an oaBox object to be populated\n"
;

static PyObject*
oaLPPHeader_getShapeBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getShapeBBox(p1.Data());
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
static char oaLPPHeader_getShapes_doc[] = 
"Class: oaLPPHeader, Function: getShapes\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaShape_oaLPPHeader getShapes() const\n"
"    Signature: getShapes|simple-oaCollection_oaShape_oaLPPHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of shapes in this LPPHeader.\n"
;

static PyObject*
oaLPPHeader_getShapes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaShape_oaLPPHeader* result= new oaCollection_oaShape_oaLPPHeader(data.DataCall()->getShapes());
        return PyoaCollection_oaShape_oaLPPHeader_FromoaCollection_oaShape_oaLPPHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_getShapesIter_doc[] = 
"Class: oaLPPHeader, Function: getShapesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaShape getShapesIter() const\n"
"    Signature: getShapesIter|simple-oaIter_oaShape|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of shapes in this LPPHeader.\n"
;

static PyObject*
oaLPPHeader_getShapesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaShape* result= new oaIter_oaShape(data.DataCall()->getShapes());
        return PyoaIter_oaShape_FromoaIter_oaShape(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLPPHeader_isBound_doc[] = 
"Class: oaLPPHeader, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this lppHeader is bound to its corresponding oaLayer and oaPurpose objects in the technology database. Note that the binding only happens if both the layer and purpose are bound.\n"
;

static PyObject*
oaLPPHeader_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLPPHeaderObject* self=(PyoaLPPHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isBound());
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
static char oaLPPHeader_isNull_doc[] =
"Class: oaLPPHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLPPHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLPPHeader data;
    int convert_status=PyoaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLPPHeader_assign_doc[] = 
"Class: oaLPPHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLPPHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLPPHeader data;
  int convert_status=PyoaLPPHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLPPHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLPPHeader_Convert,&p1)) {
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

static PyMethodDef oaLPPHeader_methodlist[] = {
    {"getLayer",(PyCFunction)oaLPPHeader_getLayer,METH_VARARGS,oaLPPHeader_getLayer_doc},
    {"getLayerHeader",(PyCFunction)oaLPPHeader_getLayerHeader,METH_VARARGS,oaLPPHeader_getLayerHeader_doc},
    {"getLayerNum",(PyCFunction)oaLPPHeader_getLayerNum,METH_VARARGS,oaLPPHeader_getLayerNum_doc},
    {"getPurpose",(PyCFunction)oaLPPHeader_getPurpose,METH_VARARGS,oaLPPHeader_getPurpose_doc},
    {"getPurposeNum",(PyCFunction)oaLPPHeader_getPurposeNum,METH_VARARGS,oaLPPHeader_getPurposeNum_doc},
    {"getShapeBBox",(PyCFunction)oaLPPHeader_getShapeBBox,METH_VARARGS,oaLPPHeader_getShapeBBox_doc},
    {"getShapes",(PyCFunction)oaLPPHeader_getShapes,METH_VARARGS,oaLPPHeader_getShapes_doc},
    {"getShapesIter",(PyCFunction)oaLPPHeader_getShapesIter,METH_VARARGS,oaLPPHeader_getShapesIter_doc},
    {"isBound",(PyCFunction)oaLPPHeader_isBound,METH_VARARGS,oaLPPHeader_isBound_doc},
    {"isNull",(PyCFunction)oaLPPHeader_tp_isNull,METH_VARARGS,oaLPPHeader_isNull_doc},
    {"assign",(PyCFunction)oaLPPHeader_tp_assign,METH_VARARGS,oaLPPHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLPPHeader_doc[] = 
"Class: oaLPPHeader\n"
"  The oaLPPHeader class implements persistent objects that are created and destroyed automatically on an as-needed basis. The existence of an oaLPPHeader object indicates that the layer-purpose pair it represents is currently being used by an oaShape object in the design hierarchy in the block where the oaLPPHeader resides.\n"
"  During binding, LPPHeaders at lower levels of the design hierarchy are promoted up the design hierarchy. As a result, the top block of a given design will have an LPPHeader for every LPPHeader that exists in the top block of every bound, instantiated design. Designs that do not have top blocks also do not have LPPHeaders, and LPPHeader promotion will not occur across such designs.\n"
"  The oaLPPHeader class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaLPPHeader)\n"
"    Calls: (const oaLPPHeader&)\n"
"    Signature: oaLPPHeader||cref-oaLPPHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLPPHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLPPHeader",
    sizeof(PyoaLPPHeaderObject),
    0,
    (destructor)oaLPPHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLPPHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaLPPHeader_tp_repr,	/* tp_repr */
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
    oaLPPHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLPPHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLPPHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLPPHeader_static_find_doc[] = 
"Class: oaLPPHeader, Function: find\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum)\n"
"    Calls: oaLPPHeader* find(const oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum)\n"
"    Signature: find|ptr-oaLPPHeader|cptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,\n"
"    This function searches the specified block looking for an LPPHeader with the specified layer number and purpose number. If the LPPHeader is found, it is returned. Otherwise, a NULL value is returned.\n"
;

static PyObject*
oaLPPHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaLayerNum p2;
    PyParamoaPurposeNum p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaLayerNum_Convert,&p2,
          &PyoaPurposeNum_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLPPHeaderp result= (oaLPPHeader::find(p1.Data(),p2.Data(),p3.Data()));
        return PyoaLPPHeader_FromoaLPPHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLPPHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaLPPHeader_static_find,METH_VARARGS,oaLPPHeader_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLPPHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLPPHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaLPPHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLPPHeader",
           (PyObject*)(&PyoaLPPHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLPPHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLPPHeader_Type.tp_dict;
    for(method=oaLPPHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLPPHeaderModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLPPHeaderModTypeEnum_Convert(PyObject* ob,PyParamoaLPPHeaderModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBindLPPHeaderModType")==0) { result->SetData(oacBindLPPHeaderModType); return 1;}
        if (strcasecmp(str,"oacUnbindLPPHeaderModType")==0) { result->SetData(oacUnbindLPPHeaderModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLPPHeaderModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLPPHeaderModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLPPHeaderModTypeEnum_FromoaLPPHeaderModTypeEnum(oaLPPHeaderModTypeEnum ob)
{
    if (ob==oacBindLPPHeaderModType) return PyString_FromString("oacBindLPPHeaderModType");
    if (ob==oacUnbindLPPHeaderModType) return PyString_FromString("oacUnbindLPPHeaderModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLPPHeaderModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLPPHeaderModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLPPHeaderModTypeEnum_FromoaLPPHeaderModTypeEnum(oaLPPHeaderModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLPPHeaderModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLPPHeaderModTypeEnum_doc[] =
"Type convert function for enum: oaLPPHeaderModTypeEnum";
                               
static PyMethodDef PyoaLPPHeaderModTypeEnum_method =
  {"oaLPPHeaderModTypeEnum",(PyCFunction)PyoaLPPHeaderModTypeEnum_TypeFunction,METH_VARARGS,oaLPPHeaderModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLPPHeaderModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBindLPPHeaderModType");
    PyDict_SetItemString(mod_dict,"oacBindLPPHeaderModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnbindLPPHeaderModType");
    PyDict_SetItemString(mod_dict,"oacUnbindLPPHeaderModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLPPHeaderModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLPPHeaderModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLPPHeaderModTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerObject* self = (PyoaLayerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayer)
    {
        PyParamoaLayer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayer_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayer, Choices are:\n"
        "    (oaLayer)\n"
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
oaLayer_tp_dealloc(PyoaLayerObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayer_tp_repr(PyObject *ob)
{
    PyParamoaLayer value;
    int convert_status=PyoaLayer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaLayer::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[29];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaLayer::");
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
oaLayer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayer v1;
    PyParamoaLayer v2;
    int convert_status1=PyoaLayer_Convert(ob1,&v1);
    int convert_status2=PyoaLayer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayer_Convert(PyObject* ob,PyParamoaLayer* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayer_Check(ob)) {
        result->SetData( (oaLayer**) ((PyoaLayerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayer_FromoaLayer(oaLayer** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayer* data=*value;
        if (data->getType()==oacSizedLayerType) return PyoaSizedLayer_FromoaSizedLayer((oaSizedLayer**)value,borrow,lock);
        if (data->getType()==oacPhysicalLayerType) return PyoaPhysicalLayer_FromoaPhysicalLayer((oaPhysicalLayer**)value,borrow,lock);
        if (data->getType()==oacDerivedLayerType) return PyoaDerivedLayer_FromoaDerivedLayer((oaDerivedLayer**)value,borrow,lock);
        PyObject* bself = PyoaLayer_Type.tp_alloc(&PyoaLayer_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerObject* self = (PyoaLayerObject*)bself;
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
PyObject* PyoaLayer_FromoaLayer(oaLayer* data)
{
    if (data) {
        if (data->getType()==oacSizedLayerType) return PyoaSizedLayer_FromoaSizedLayer((oaSizedLayer*)data);
        if (data->getType()==oacPhysicalLayerType) return PyoaPhysicalLayer_FromoaPhysicalLayer((oaPhysicalLayer*)data);
        if (data->getType()==oacDerivedLayerType) return PyoaDerivedLayer_FromoaDerivedLayer((oaDerivedLayer*)data);
       PyObject* bself = PyoaLayer_Type.tp_alloc(&PyoaLayer_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerObject* self = (PyoaLayerObject*)bself;
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
static char oaLayer_destroy_doc[] = 
"Class: oaLayer, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this layer, removing it from the technology database.\n"
;

static PyObject*
oaLayer_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
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
static char oaLayer_getAvgACCurrentDensity_doc[] = 
"Class: oaLayer, Function: getAvgACCurrentDensity\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getAvgACCurrentDensity() const\n"
"    Signature: getAvgACCurrentDensity|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the avgACCurrentDensity value of this layer.\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Average AC Current Density\n"
;

static PyObject*
oaLayer_getAvgACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getAvgACCurrentDensity());
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayer_getAvgDCCurrentDensity_doc[] = 
"Class: oaLayer, Function: getAvgDCCurrentDensity\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getAvgDCCurrentDensity() const\n"
"    Signature: getAvgDCCurrentDensity|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the avgDCCurrentDensity value of this layer. Valid value types are: oaFltValue and aFlt1DTblValue.\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Average DC Current Density\n"
;

static PyObject*
oaLayer_getAvgDCCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getAvgDCCurrentDensity());
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayer_getName_doc[] = 
"Class: oaLayer, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of the specified layer.\n"
;

static PyObject*
oaLayer_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
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
static char oaLayer_getNumber_doc[] = 
"Class: oaLayer, Function: getNumber\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getNumber() const\n"
"    Signature: getNumber|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the number of the specified layer.\n"
;

static PyObject*
oaLayer_getNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getNumber());
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
static char oaLayer_getPeakACCurrentDensity_doc[] = 
"Class: oaLayer, Function: getPeakACCurrentDensity\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getPeakACCurrentDensity() const\n"
"    Signature: getPeakACCurrentDensity|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the peakACCurrentDensity value of this layer.\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Peak AC Current Density\n"
;

static PyObject*
oaLayer_getPeakACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getPeakACCurrentDensity());
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayer_getRmsACCurrentDensity_doc[] = 
"Class: oaLayer, Function: getRmsACCurrentDensity\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getRmsACCurrentDensity() const\n"
"    Signature: getRmsACCurrentDensity|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the rmsACCurrentDensity value of this layer. Valid value types are: oaFltValue , oaFlt1DTblValue , and oaFltIntFltTblValue .\n"
"    For a more detailed explanation of the usage of oaValues on this function, see RMS AC Current Density\n"
;

static PyObject*
oaLayer_getRmsACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getRmsACCurrentDensity());
        return PyoaValue_FromoaValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayer_setAvgACCurrentDensity_doc[] = 
"Class: oaLayer, Function: setAvgACCurrentDensity\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setAvgACCurrentDensity(oaValue* value)\n"
"    Signature: setAvgACCurrentDensity|void-void|ptr-oaValue,\n"
"    This function sets the avgACCurrentDensity of this layer to the specified value. Valid value types are: oaFltValue , oaFlt1DTblValue , and oaFltIntFltTblValue . A NULL argument can be passed-in for the value parameter for a reset. Note that the previous value, if any, will get destroyed if this function is successful.\n"
"    value\n"
"    The avgACCurrentDensity value to set.\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacInvalidACCurrentDensityValue\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Average AC Current Density\n"
;

static PyObject*
oaLayer_setAvgACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setAvgACCurrentDensity(p1.Data());
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
static char oaLayer_setAvgDCCurrentDensity_doc[] = 
"Class: oaLayer, Function: setAvgDCCurrentDensity\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setAvgDCCurrentDensity(oaValue* value)\n"
"    Signature: setAvgDCCurrentDensity|void-void|ptr-oaValue,\n"
"    This function sets the avgDCCurrentDensity of this layer to the specified value. Valid value types are: oaFltValue , and oaIntFltTblValue . A NULL argument can be passed-in for the value parameter for a reset. Note that the previous value, if any, will get destroyed if this function is successful.\n"
"    value\n"
"    The avgDCCurrentDensity value to set.\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacInvalidDCCurrentDensityValue\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Average DC Current Density\n"
;

static PyObject*
oaLayer_setAvgDCCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setAvgDCCurrentDensity(p1.Data());
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
static char oaLayer_setName_doc[] = 
"Class: oaLayer, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this layer to the specified value.\n"
"    oacLayerNameExists\n"
;

static PyObject*
oaLayer_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
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
static char oaLayer_setNumber_doc[] = 
"Class: oaLayer, Function: setNumber\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setNumber(oaLayerNum number)\n"
"    Signature: setNumber|void-void|simple-oaLayerNum,\n"
"    This function sets the number of this layer to the specified value.\n"
"    oacLayerNumberExists\n"
;

static PyObject*
oaLayer_setNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->setNumber(p1.Data());
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
static char oaLayer_setPeakACCurrentDensity_doc[] = 
"Class: oaLayer, Function: setPeakACCurrentDensity\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setPeakACCurrentDensity(oaValue* value)\n"
"    Signature: setPeakACCurrentDensity|void-void|ptr-oaValue,\n"
"    This function sets the peakACCurrentDensity of this layer to the specified value. Valid value types are: oaFltValue , oaFlt1DTblValue , and oaFltIntFltTblValue . A NULL argument can be passed-in for the value parameter for a reset. Note that the previous value, if any, will get destroyed if this function is successful.\n"
"    value\n"
"    The peakACCurrentDensity value to set.\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacInvalidACCurrentDensityValue\n"
"    For a more detailed explanation of the usage of oaValues on this function, see Peak AC Current Density\n"
;

static PyObject*
oaLayer_setPeakACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setPeakACCurrentDensity(p1.Data());
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
static char oaLayer_setRmsACCurrentDensity_doc[] = 
"Class: oaLayer, Function: setRmsACCurrentDensity\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setRmsACCurrentDensity(oaValue* value)\n"
"    Signature: setRmsACCurrentDensity|void-void|ptr-oaValue,\n"
"    This function sets the rmsACCurrentDensity of this layer to the specified value. Valid value types are: oaFltValue , oaFlt1DTblValue , and oaFltIntFltTblValue . A NULL argument can be passed-in for the value parameter for a reset. Note that the previous value, if any, will get destroyed if this function is successful.\n"
"    value\n"
"    The rmsACCurrentDensity value to set.\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacInvalidACCurrentDensityValue\n"
"    For a more detailed explanation of the usage of oaValues on this function, see RMS AC Current Density\n"
;

static PyObject*
oaLayer_setRmsACCurrentDensity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerObject* self=(PyoaLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setRmsACCurrentDensity(p1.Data());
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
static char oaLayer_isNull_doc[] =
"Class: oaLayer, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayer_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayer data;
    int convert_status=PyoaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayer_assign_doc[] = 
"Class: oaLayer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayer data;
  int convert_status=PyoaLayer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayer_Convert,&p1)) {
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

static PyMethodDef oaLayer_methodlist[] = {
    {"destroy",(PyCFunction)oaLayer_destroy,METH_VARARGS,oaLayer_destroy_doc},
    {"getAvgACCurrentDensity",(PyCFunction)oaLayer_getAvgACCurrentDensity,METH_VARARGS,oaLayer_getAvgACCurrentDensity_doc},
    {"getAvgDCCurrentDensity",(PyCFunction)oaLayer_getAvgDCCurrentDensity,METH_VARARGS,oaLayer_getAvgDCCurrentDensity_doc},
    {"getName",(PyCFunction)oaLayer_getName,METH_VARARGS,oaLayer_getName_doc},
    {"getNumber",(PyCFunction)oaLayer_getNumber,METH_VARARGS,oaLayer_getNumber_doc},
    {"getPeakACCurrentDensity",(PyCFunction)oaLayer_getPeakACCurrentDensity,METH_VARARGS,oaLayer_getPeakACCurrentDensity_doc},
    {"getRmsACCurrentDensity",(PyCFunction)oaLayer_getRmsACCurrentDensity,METH_VARARGS,oaLayer_getRmsACCurrentDensity_doc},
    {"setAvgACCurrentDensity",(PyCFunction)oaLayer_setAvgACCurrentDensity,METH_VARARGS,oaLayer_setAvgACCurrentDensity_doc},
    {"setAvgDCCurrentDensity",(PyCFunction)oaLayer_setAvgDCCurrentDensity,METH_VARARGS,oaLayer_setAvgDCCurrentDensity_doc},
    {"setName",(PyCFunction)oaLayer_setName,METH_VARARGS,oaLayer_setName_doc},
    {"setNumber",(PyCFunction)oaLayer_setNumber,METH_VARARGS,oaLayer_setNumber_doc},
    {"setPeakACCurrentDensity",(PyCFunction)oaLayer_setPeakACCurrentDensity,METH_VARARGS,oaLayer_setPeakACCurrentDensity_doc},
    {"setRmsACCurrentDensity",(PyCFunction)oaLayer_setRmsACCurrentDensity,METH_VARARGS,oaLayer_setRmsACCurrentDensity_doc},
    {"isNull",(PyCFunction)oaLayer_tp_isNull,METH_VARARGS,oaLayer_isNull_doc},
    {"assign",(PyCFunction)oaLayer_tp_assign,METH_VARARGS,oaLayer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayer_doc[] = 
"Class: oaLayer\n"
"  The oaLayer class defines a layer that is later referenced to create a layer that is ultimately referenced when creating physical design data.\n"
"  An oaShape or an oaFig can be placed on a layer. Layers are used for multiple purposes and frequently correspond to the different manufacturing layers that exist on chips. A shape refers to a layer using a layer number -- it is not bound to a layer object.\n"
"  The oaLayer class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaLayer)\n"
"    Calls: (const oaLayer&)\n"
"    Signature: oaLayer||cref-oaLayer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayer",
    sizeof(PyoaLayerObject),
    0,
    (destructor)oaLayer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayer_tp_compare,	/* tp_compare */
    (reprfunc)oaLayer_tp_repr,	/* tp_repr */
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
    oaLayer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTechObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayer_static_find_doc[] = 
"Class: oaLayer, Function: find\n"
"  Paramegers: (oaTech,oaString)\n"
"    Calls: oaLayer* find(const oaTech* tech,const oaString& name)\n"
"    Signature: find|ptr-oaLayer|cptr-oaTech,cref-oaString,\n"
"    This function searches the specified technology database for a layer with the specified name . If the specified technology database references other technology databases, those are searched as well and the first matching layer is returned. To find a layer in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified layer, the function returns a pointer to the oaLayer object. Otherwise, the function returns NULL.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    Technology database to search.\n"
"    name\n"
"    Layer name to find.\n"
"  Paramegers: (oaTech,oaLayerNum)\n"
"    Calls: oaLayer* find(const oaTech* tech,oaLayerNum number)\n"
"    Signature: find|ptr-oaLayer|cptr-oaTech,simple-oaLayerNum,\n"
"    This function searches the specified technology database for a layer with the specified number . If the specified technology database references other technology databases, those are searched as well and the first matching layer is returned. To find a layer in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified layer, the function returns a pointer to the oaLayer object. Otherwise, the function returns NULL.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    Technology database to search.\n"
"    number\n"
"    Layer number to find.\n"
"  Paramegers: (oaTech,oaString,oaBoolean)\n"
"    Calls: oaLayer* find(const oaTech* tech,const oaString& name,oaBoolean local)\n"
"    Signature: find|ptr-oaLayer|cptr-oaTech,cref-oaString,simple-oaBoolean,\n"
"    oaLayer::findName2\n"
"    This function searches the specified technology database looking for a layer with the specified name . The local argument specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases. If the layer is found, a pointer to the layer object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    Technology database to search.\n"
"    name\n"
"    Layer name to find.\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
"    Todo\n"
"    Place this function block in the oaLayer class block.\n"
"  Paramegers: (oaTech,oaLayerNum,oaBoolean)\n"
"    Calls: oaLayer* find(const oaTech* tech,oaLayerNum number,oaBoolean local)\n"
"    Signature: find|ptr-oaLayer|cptr-oaTech,simple-oaLayerNum,simple-oaBoolean,\n"
"    oaLayer::findNum2\n"
"    This function searches the specified technology database for a layer with the specified number . The local argument specifies whether (if true) to look only in the specified technology database or (if false) to search the specified technology database and all of its referenced technology databases. If the layer is found, a pointer to the layer object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    Technology database to search.\n"
"    number\n"
"    Layer number to find.\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
"    Todo\n"
"    Place this function block in the oaLayer class block.\n"
;

static PyObject*
oaLayer_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTech,oaString)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerp result= (oaLayer::find(p1.Data(),p2.Data()));
            return PyoaLayer_FromoaLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaLayerNum)
    {
        PyParamoaTech p1;
        PyParamoaLayerNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaLayerNum_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerp result= (oaLayer::find(p1.Data(),p2.Data()));
            return PyoaLayer_FromoaLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerp result= (oaLayer::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayer_FromoaLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaLayerNum,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaLayerNum p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerp result= (oaLayer::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayer_FromoaLayer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayer, function: find, Choices are:\n"
        "    (oaTech,oaString)\n"
        "    (oaTech,oaLayerNum)\n"
        "    (oaTech,oaString,oaBoolean)\n"
        "    (oaTech,oaLayerNum,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayer_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaLayer_static_find,METH_VARARGS,oaLayer_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayer_Type)<0) {
      printf("** PyType_Ready failed for: oaLayer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayer",
           (PyObject*)(&PyoaLayer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayer\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayer_Type.tp_dict;
    for(method=oaLayer_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerArrayObject* self = (PyoaLayerArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaLayerArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaLayerArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray)
    {
        PyParamoaLayerArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerArray_Convert,&p1)) {
            self->value=(oaArrayBase_oaLayerNum*)  new oaLayerArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaLayerArray)\n"
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
oaLayerArray_tp_dealloc(PyoaLayerArrayObject* self)
{
    if (!self->borrow) {
        delete (oaLayerArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerArray_tp_repr(PyObject *ob)
{
    PyParamoaLayerArray value;
    int convert_status=PyoaLayerArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaLayerArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerArray v1;
    PyParamoaLayerArray v2;
    int convert_status1=PyoaLayerArray_Convert(ob1,&v1);
    int convert_status2=PyoaLayerArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerArray_Convert(PyObject* ob,PyParamoaLayerArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerArray_Check(ob)) {
        result->SetData( (oaLayerArray*) ((PyoaLayerArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerArray_FromoaLayerArray(oaLayerArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerArray_Type.tp_alloc(&PyoaLayerArray_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerArrayObject* self = (PyoaLayerArrayObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArray_doc[] = 
"Class: oaLayerArray\n"
"  The oaLayerArray class implements an array of layer numbers.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLayerArray()\n"
"    Signature: oaLayerArray||simple-oaUInt4,\n"
"    This function constructs an oaLayerArray object, allocating storage for the layers numbers.\n"
"    sizeIn\n"
"    An integer value indicating the initial size of the layer array.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaLayerArray(oaUInt4 sizeIn)\n"
"    Signature: oaLayerArray||simple-oaUInt4,\n"
"    This function constructs an oaLayerArray object, allocating storage for the layers numbers.\n"
"    sizeIn\n"
"    An integer value indicating the initial size of the layer array.\n"
"  Paramegers: (oaLayerArray)\n"
"    Calls: (const oaLayerArray&)\n"
"    Signature: oaLayerArray||cref-oaLayerArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerArray",
    sizeof(PyoaLayerArrayObject),
    0,
    (destructor)oaLayerArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerArray_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerArray_tp_repr,	/* tp_repr */
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
    oaLayerArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaLayerNum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerArray_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerArray",
           (PyObject*)(&PyoaLayerArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerArray\n");
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
// Wrapper Implementation for Class: oaLayerArrayConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerArrayConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerArrayConstraintObject* self = (PyoaLayerArrayConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerArrayConstraint)
    {
        PyParamoaLayerArrayConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerArrayConstraint_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerArrayConstraint, Choices are:\n"
        "    (oaLayerArrayConstraint)\n"
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
oaLayerArrayConstraint_tp_dealloc(PyoaLayerArrayConstraintObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraint_tp_repr(PyObject *ob)
{
    PyParamoaLayerArrayConstraint value;
    int convert_status=PyoaLayerArrayConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaLayerArrayConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerArrayConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerArrayConstraint v1;
    PyParamoaLayerArrayConstraint v2;
    int convert_status1=PyoaLayerArrayConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaLayerArrayConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerArrayConstraint_Convert(PyObject* ob,PyParamoaLayerArrayConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerArrayConstraint_Check(ob)) {
        result->SetData( (oaLayerArrayConstraint**) ((PyoaLayerArrayConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArrayConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(oaLayerArrayConstraint** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerArrayConstraint* data=*value;
        PyObject* bself = PyoaLayerArrayConstraint_Type.tp_alloc(&PyoaLayerArrayConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerArrayConstraintObject* self = (PyoaLayerArrayConstraintObject*)bself;
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
PyObject* PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(oaLayerArrayConstraint* data)
{
    if (data) {
       PyObject* bself = PyoaLayerArrayConstraint_Type.tp_alloc(&PyoaLayerArrayConstraint_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerArrayConstraintObject* self = (PyoaLayerArrayConstraintObject*)bself;
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
static char oaLayerArrayConstraint_getLayers_doc[] = 
"Class: oaLayerArrayConstraint, Function: getLayers\n"
"  Paramegers: (oaLayerArray)\n"
"    Calls: void getLayers(oaLayerArray& layerNums) const\n"
"    Signature: getLayers|void-void|ref-oaLayerArray,\n"
"    BrowseData: 0,oaLayerArray\n"
"    This function returns the layer numbers associated with this layer array constraint. The function fills the layer array provided by the caller. All layer numbers that existed in the layer array before the call are removed from the array, so that after the function returns, the layerNums array contains only the layers on which the constraint depends.\n"
"    layerNums\n"
"    The layer numbers of the constraint.\n"
"    Todo\n"
"    Check description of member function. Add description of each parameter.\n"
;

static PyObject*
oaLayerArrayConstraint_getLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayConstraint data;
    int convert_status=PyoaLayerArrayConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayConstraintObject* self=(PyoaLayerArrayConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerArray_Convert,&p1)) {
        data.DataCall()->getLayers(p1.Data());
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
static char oaLayerArrayConstraint_isNull_doc[] =
"Class: oaLayerArrayConstraint, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerArrayConstraint_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerArrayConstraint data;
    int convert_status=PyoaLayerArrayConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerArrayConstraint_assign_doc[] = 
"Class: oaLayerArrayConstraint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerArrayConstraint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerArrayConstraint data;
  int convert_status=PyoaLayerArrayConstraint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerArrayConstraint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerArrayConstraint_Convert,&p1)) {
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

static PyMethodDef oaLayerArrayConstraint_methodlist[] = {
    {"getLayers",(PyCFunction)oaLayerArrayConstraint_getLayers,METH_VARARGS,oaLayerArrayConstraint_getLayers_doc},
    {"isNull",(PyCFunction)oaLayerArrayConstraint_tp_isNull,METH_VARARGS,oaLayerArrayConstraint_isNull_doc},
    {"assign",(PyCFunction)oaLayerArrayConstraint_tp_assign,METH_VARARGS,oaLayerArrayConstraint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayConstraint_doc[] = 
"Class: oaLayerArrayConstraint\n"
"  This class represents a constraint object that constrains interactions between more than two layers. Full description of oaLayerArrayConstraint includes the following:\n"
"  An array of layers ( oaLayerArray )\n"
"  The constraint definition ( oaLayerArrayConstraintDef )\n"
"  The constraint name ( oaString ). When creating an oaLayerArrayConstraint, providing the name is optional. If the name is not specified, the new constraint is auto-named by OpenAccess.\n"
"  The constraint value ( oaValue ). oaLayerArrayConstraint must be created in the same database as that value.\n"
"  A boolean attribute (oaBoolean) indicating whether the constraint is hard, which means it must be met, or soft.\n"
"  An optional list of constraint parameters ( oaConstraintParamArray ).\n"
"  oaLayerArrayConstraints get applied to objects by being placed in an oaConstraintGroup .\n"
"Constructors:\n"
"  Paramegers: (oaLayerArrayConstraint)\n"
"    Calls: (const oaLayerArrayConstraint&)\n"
"    Signature: oaLayerArrayConstraint||cref-oaLayerArrayConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerArrayConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerArrayConstraint",
    sizeof(PyoaLayerArrayConstraintObject),
    0,
    (destructor)oaLayerArrayConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerArrayConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerArrayConstraint_tp_repr,	/* tp_repr */
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
    oaLayerArrayConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerArrayConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerArrayConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayConstraint_static_create_doc[] = 
"Class: oaLayerArrayConstraint, Function: create\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaValue)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,oaValue* value)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new, auto-named layer array constraint in the same database as the specified value.\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new, auto-named layer array constraint in the same database as the specified value.\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new, auto-named layer array constraint in the same database as the specified value.\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,const oaString& name,oaValue* value)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new layer array constraint with the specified name in the same database as the specified value .\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    name\n"
"    The name of this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"    oacConstraintNameExists\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new layer array constraint with the specified name in the same database as the specified value .\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    name\n"
"    The name of this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"    oacConstraintNameExists\n"
"  Paramegers: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerArrayConstraint* create(const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerArrayConstraint|cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates a new layer array constraint with the specified name in the same database as the specified value .\n"
"    layerNums\n"
"    The array of layer numbers that this constraint applies to.\n"
"    def\n"
"    The definition for this constraint.\n"
"    name\n"
"    The name of this constraint.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A boolean indicating whether this constraint must be met.\n"
"    params\n"
"    The parameters associated with this constraint.\n"
"    oacValueAlreadyOwned\n"
"    oacInvalidDatabaseForLayerArrayConstraint\n"
"    oacConstraintNameExists\n"
;

static PyObject*
oaLayerArrayConstraint_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaValue)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaValue p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        PyParamoaConstraintParamArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaConstraintParamArray_ConvertAof,&p5)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerArray p1;
        PyParamoaLayerArrayConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        PyParamoaConstraintParamArray p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaLayerArray_Convert,&p1,
              &PyoaLayerArrayConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaConstraintParamArray_ConvertAof,&p6)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerArrayConstraint, function: create, Choices are:\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaValue)\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean)\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue)\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean)\n"
        "    (oaLayerArray,oaLayerArrayConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerArrayConstraint_static_find_doc[] = 
"Class: oaLayerArrayConstraint, Function: find\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
"    Calls: oaLayerArrayConstraint* find(const oaConstraintGroup* group,const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def)\n"
"    Signature: find|ptr-oaLayerArrayConstraint|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,simple-oaBoolean,\n"
"    This function returns the first constraint in this group that matches the specified definition, layers and isHard attribute. If no such constraint is found, NULL is returned.\n"
"    group\n"
"    The constraint group in which to locate the constraint.\n"
"    layerNums\n"
"    The layer numbers to match.\n"
"    def\n"
"    The layer definition.\n"
"    hardOnly\n"
"    A boolean indicating a hard or soft constraint.\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef,oaBoolean)\n"
"    Calls: oaLayerArrayConstraint* find(const oaConstraintGroup* group,const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def,oaBoolean hardOnly)\n"
"    Signature: find|ptr-oaLayerArrayConstraint|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,simple-oaBoolean,\n"
"    This function returns the first constraint in this group that matches the specified definition, layers and isHard attribute. If no such constraint is found, NULL is returned.\n"
"    group\n"
"    The constraint group in which to locate the constraint.\n"
"    layerNums\n"
"    The layer numbers to match.\n"
"    def\n"
"    The layer definition.\n"
"    hardOnly\n"
"    A boolean indicating a hard or soft constraint.\n"
;

static PyObject*
oaLayerArrayConstraint_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        PyParamoaLayerArrayConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2,
              &PyoaLayerArrayConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        PyParamoaLayerArrayConstraintDef p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2,
              &PyoaLayerArrayConstraintDef_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerArrayConstraintp result= (oaLayerArrayConstraint::find(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerArrayConstraint, function: find, Choices are:\n"
        "    (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
        "    (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerArrayConstraint_static_getConstraints_doc[] = 
"Class: oaLayerArrayConstraint, Function: getConstraints\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray)\n"
"    Calls: oaCollection_oaLayerArrayConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,const oaLayerArray& layerNums)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerArrayConstraint_oaConstraintGroup|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,\n"
"    This function returns a collection of layer array constraints, with the specified definition, and based on the specified layers, in the specified group. If no definition is specified, all layer array constraints on the specified layers in the group are returned.\n"
"    group\n"
"    The constraint group that the collection belongs to.\n"
"    layerNums\n"
"    The layer numbers of the constraint to match.\n"
"    def\n"
"    An optional layer array constraint definition to match.\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
"    Calls: oaCollection_oaLayerArrayConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerArrayConstraint_oaConstraintGroup|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,\n"
"    This function returns a collection of layer array constraints, with the specified definition, and based on the specified layers, in the specified group. If no definition is specified, all layer array constraints on the specified layers in the group are returned.\n"
"    group\n"
"    The constraint group that the collection belongs to.\n"
"    layerNums\n"
"    The layer numbers of the constraint to match.\n"
"    def\n"
"    An optional layer array constraint definition to match.\n"
;

static PyObject*
oaLayerArrayConstraint_static_getConstraints(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerArray)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaCollection_oaLayerArrayConstraint_oaConstraintGroup* result= new oaCollection_oaLayerArrayConstraint_oaConstraintGroup(oaLayerArrayConstraint::getConstraints(p1.Data(),p2.Data()));
            return PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_FromoaCollection_oaLayerArrayConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        PyParamoaLayerArrayConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2,
              &PyoaLayerArrayConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaCollection_oaLayerArrayConstraint_oaConstraintGroup* result= new oaCollection_oaLayerArrayConstraint_oaConstraintGroup(oaLayerArrayConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_FromoaCollection_oaLayerArrayConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerArrayConstraint, function: getConstraints, Choices are:\n"
        "    (oaConstraintGroup,oaLayerArray)\n"
        "    (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerArrayConstraint_static_getConstraintsIter_doc[] = 
"Class: oaLayerArrayConstraint, Function: getConstraintsIter\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray)\n"
"    Calls: oaIter_oaLayerArrayConstraint getConstraintsIter(const oaConstraintGroup* group,const oaLayerArray& layerNums)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerArrayConstraint|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer array constraints, with the specified definition, and based on the specified layers, in the specified group. If no definition is specified, all layer array constraints on the specified layers in the group are returned.\n"
"    group\n"
"    The constraint group that the collection belongs to.\n"
"    layerNums\n"
"    The layer numbers of the constraint to match.\n"
"    def\n"
"    An optional layer array constraint definition to match.\n"
"  Paramegers: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
"    Calls: oaIter_oaLayerArrayConstraint getConstraintsIter(const oaConstraintGroup* group,const oaLayerArray& layerNums,const oaLayerArrayConstraintDef* def)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerArrayConstraint|cptr-oaConstraintGroup,cref-oaLayerArray,cptr-oaLayerArrayConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer array constraints, with the specified definition, and based on the specified layers, in the specified group. If no definition is specified, all layer array constraints on the specified layers in the group are returned.\n"
"    group\n"
"    The constraint group that the collection belongs to.\n"
"    layerNums\n"
"    The layer numbers of the constraint to match.\n"
"    def\n"
"    An optional layer array constraint definition to match.\n"
;

static PyObject*
oaLayerArrayConstraint_static_getConstraintsIter(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerArray)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaIter_oaLayerArrayConstraint* result= new oaIter_oaLayerArrayConstraint(oaLayerArrayConstraint::getConstraints(p1.Data(),p2.Data()));
            return PyoaIter_oaLayerArrayConstraint_FromoaIter_oaLayerArrayConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerArray p2;
        PyParamoaLayerArrayConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerArray_Convert,&p2,
              &PyoaLayerArrayConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaIter_oaLayerArrayConstraint* result= new oaIter_oaLayerArrayConstraint(oaLayerArrayConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaIter_oaLayerArrayConstraint_FromoaIter_oaLayerArrayConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerArrayConstraint, function: getConstraintsIter, Choices are:\n"
        "    (oaConstraintGroup,oaLayerArray)\n"
        "    (oaConstraintGroup,oaLayerArray,oaLayerArrayConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerArrayConstraint_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerArrayConstraint_static_create,METH_VARARGS,oaLayerArrayConstraint_static_create_doc},
    {"static_find",(PyCFunction)oaLayerArrayConstraint_static_find,METH_VARARGS,oaLayerArrayConstraint_static_find_doc},
    {"static_getConstraints",(PyCFunction)oaLayerArrayConstraint_static_getConstraints,METH_VARARGS,oaLayerArrayConstraint_static_getConstraints_doc},
    {"static_getConstraintsIter",(PyCFunction)oaLayerArrayConstraint_static_getConstraintsIter,METH_VARARGS,oaLayerArrayConstraint_static_getConstraintsIter_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerArrayConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerArrayConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerArrayConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerArrayConstraint",
           (PyObject*)(&PyoaLayerArrayConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerArrayConstraint\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerArrayConstraint_Type.tp_dict;
    for(method=oaLayerArrayConstraint_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerArrayConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerArrayConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerArrayConstraintDefObject* self = (PyoaLayerArrayConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerArrayConstraintDef)
    {
        PyParamoaLayerArrayConstraintDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerArrayConstraintDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerArrayConstraintDef, Choices are:\n"
        "    (oaLayerArrayConstraintDef)\n"
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
oaLayerArrayConstraintDef_tp_dealloc(PyoaLayerArrayConstraintDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaLayerArrayConstraintDef value;
    int convert_status=PyoaLayerArrayConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaLayerArrayConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerArrayConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerArrayConstraintDef v1;
    PyParamoaLayerArrayConstraintDef v2;
    int convert_status1=PyoaLayerArrayConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaLayerArrayConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerArrayConstraintDef_Convert(PyObject* ob,PyParamoaLayerArrayConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerArrayConstraintDef_Check(ob)) {
        result->SetData( (oaLayerArrayConstraintDef**) ((PyoaLayerArrayConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArrayConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef(oaLayerArrayConstraintDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerArrayConstraintDef* data=*value;
        PyObject* bself = PyoaLayerArrayConstraintDef_Type.tp_alloc(&PyoaLayerArrayConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerArrayConstraintDefObject* self = (PyoaLayerArrayConstraintDefObject*)bself;
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
PyObject* PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef(oaLayerArrayConstraintDef* data)
{
    if (data) {
       PyObject* bself = PyoaLayerArrayConstraintDef_Type.tp_alloc(&PyoaLayerArrayConstraintDef_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerArrayConstraintDefObject* self = (PyoaLayerArrayConstraintDefObject*)bself;
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
static char oaLayerArrayConstraintDef_getNumLayers_doc[] = 
"Class: oaLayerArrayConstraintDef, Function: getNumLayers\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumLayers() const\n"
"    Signature: getNumLayers|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of layers involved in the constraint definition.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaLayerArrayConstraintDef_getNumLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayConstraintDef data;
    int convert_status=PyoaLayerArrayConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayConstraintDefObject* self=(PyoaLayerArrayConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumLayers());
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
static char oaLayerArrayConstraintDef_isNull_doc[] =
"Class: oaLayerArrayConstraintDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerArrayConstraintDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerArrayConstraintDef data;
    int convert_status=PyoaLayerArrayConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerArrayConstraintDef_assign_doc[] = 
"Class: oaLayerArrayConstraintDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerArrayConstraintDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerArrayConstraintDef data;
  int convert_status=PyoaLayerArrayConstraintDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerArrayConstraintDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerArrayConstraintDef_Convert,&p1)) {
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

static PyMethodDef oaLayerArrayConstraintDef_methodlist[] = {
    {"getNumLayers",(PyCFunction)oaLayerArrayConstraintDef_getNumLayers,METH_VARARGS,oaLayerArrayConstraintDef_getNumLayers_doc},
    {"isNull",(PyCFunction)oaLayerArrayConstraintDef_tp_isNull,METH_VARARGS,oaLayerArrayConstraintDef_isNull_doc},
    {"assign",(PyCFunction)oaLayerArrayConstraintDef_tp_assign,METH_VARARGS,oaLayerArrayConstraintDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayConstraintDef_doc[] = 
"Class: oaLayerArrayConstraintDef\n"
"  An oaLayerArrayConstraintDef object specifies a definition for a constraint between three or more layers. The definition contains a name, a list of databases that the constraint can be created in, a list of types of oaValues that are allowed for the constraint, a list of objects to which a constraint based on this definition can be applied, and the number of layers for a constraint based on this definition. The names for constraint definitions must be unique.\n"
"Constructors:\n"
"  Paramegers: (oaLayerArrayConstraintDef)\n"
"    Calls: (const oaLayerArrayConstraintDef&)\n"
"    Signature: oaLayerArrayConstraintDef||cref-oaLayerArrayConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerArrayConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerArrayConstraintDef",
    sizeof(PyoaLayerArrayConstraintDefObject),
    0,
    (destructor)oaLayerArrayConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerArrayConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerArrayConstraintDef_tp_repr,	/* tp_repr */
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
    oaLayerArrayConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerArrayConstraintDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerArrayConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayConstraintDef_static_create_doc[] = 
"Class: oaLayerArrayConstraintDef, Function: create\n"
"  Paramegers: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType,oaUInt4)\n"
"    Calls: oaLayerArrayConstraintDef* create(const oaString& name,const oaSubset_oaType& allowedValues,const oaSubset_oaType& allowedObjects,const oaSubset_oaDBType& allowedDB,oaUInt4 numLayers)\n"
"    Signature: create|ptr-oaLayerArrayConstraintDef|cref-oaString,cref-oaSubset_oaType,cref-oaSubset_oaType,cref-oaSubset_oaDBType,simple-oaUInt4,\n"
"    This function creates a new layer array constraint definition with the attributes specified.\n"
"    name\n"
"    The name of the layer array definition.\n"
"    allowedValues\n"
"    The allowed types of oaValue sub classes.\n"
"    allowedObjects\n"
"    The allowed objects a constraint of this def can be applied to.\n"
"    allowedDB\n"
"    The types of databases a constraint based on this def can be created in.\n"
"    numLayers\n"
"    The number of layers for a constraint of this def.\n"
"    Todo\n"
"    Check description of member function. Add description of each parameter.\n"
;

static PyObject*
oaLayerArrayConstraintDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaSubset_oaType p2;
    PyParamoaSubset_oaType p3;
    PyParamoaSubset_oaDBType p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaString_Convert,&p1,
          &PyoaSubset_oaType_Convert,&p2,
          &PyoaSubset_oaType_Convert,&p3,
          &PyoaSubset_oaDBType_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        oaLayerArrayConstraintDefp result= (oaLayerArrayConstraintDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerArrayConstraintDef_static_get_doc[] = 
"Class: oaLayerArrayConstraintDef, Function: get\n"
"  Paramegers: (oaLayerArrayConstraintType)\n"
"    Calls: oaLayerArrayConstraintDef* get(oaLayerArrayConstraintType type)\n"
"    Signature: get|ptr-oaLayerArrayConstraintDef|simple-oaLayerArrayConstraintType,\n"
"    This function returns the built-in constraint definition of the type specified.\n"
"    type\n"
"    An enum value that represents a built-in definition.\n"
;

static PyObject*
oaLayerArrayConstraintDef_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayConstraintType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerArrayConstraintType_Convert,&p1)) {
        oaLayerArrayConstraintDefp result= (oaLayerArrayConstraintDef::get(p1.Data()));
        return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerArrayConstraintDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerArrayConstraintDef_static_create,METH_VARARGS,oaLayerArrayConstraintDef_static_create_doc},
    {"static_get",(PyCFunction)oaLayerArrayConstraintDef_static_get,METH_VARARGS,oaLayerArrayConstraintDef_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerArrayConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerArrayConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerArrayConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerArrayConstraintDef",
           (PyObject*)(&PyoaLayerArrayConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerArrayConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerArrayConstraintDef_Type.tp_dict;
    for(method=oaLayerArrayConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerArrayConstraintType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraintType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerArrayConstraintType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerArrayConstraintTypeObject* self = (PyoaLayerArrayConstraintTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerArrayConstraintTypeEnum)
    {
        PyParamoaLayerArrayConstraintTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerArrayConstraintTypeEnum_Convert,&p1)) {
            self->value =  new oaLayerArrayConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLayerArrayConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerArrayConstraintType)
    {
        PyParamoaLayerArrayConstraintType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerArrayConstraintType_Convert,&p1)) {
            self->value= new oaLayerArrayConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerArrayConstraintType, Choices are:\n"
        "    (oaLayerArrayConstraintTypeEnum)\n"
        "    (oaString)\n"
        "    (oaLayerArrayConstraintType)\n"
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
oaLayerArrayConstraintType_tp_dealloc(PyoaLayerArrayConstraintTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayConstraintType_tp_repr(PyObject *ob)
{
    PyParamoaLayerArrayConstraintType value;
    int convert_status=PyoaLayerArrayConstraintType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[48];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLayerArrayConstraintType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerArrayConstraintType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerArrayConstraintType v1;
    PyParamoaLayerArrayConstraintType v2;
    int convert_status1=PyoaLayerArrayConstraintType_Convert(ob1,&v1);
    int convert_status2=PyoaLayerArrayConstraintType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerArrayConstraintType_Convert(PyObject* ob,PyParamoaLayerArrayConstraintType* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerArrayConstraintType_Check(ob)) {
        result->SetData(  ((PyoaLayerArrayConstraintTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArrayConstraintType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerArrayConstraintType_FromoaLayerArrayConstraintType(oaLayerArrayConstraintType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerArrayConstraintType_Type.tp_alloc(&PyoaLayerArrayConstraintType_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerArrayConstraintTypeObject* self = (PyoaLayerArrayConstraintTypeObject*)bself;
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
static char oaLayerArrayConstraintType_getName_doc[] = 
"Class: oaLayerArrayConstraintType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name of the enum value represented by this oaLayerArrayConstraintType.\n"
;

static PyObject*
oaLayerArrayConstraintType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayConstraintType data;
    int convert_status=PyoaLayerArrayConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayConstraintTypeObject* self=(PyoaLayerArrayConstraintTypeObject*)ob;

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
static char oaLayerArrayConstraintType_oaLayerArrayConstraintTypeEnum_doc[] = 
"Class: oaLayerArrayConstraintType, Function: oaLayerArrayConstraintTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerArrayConstraintTypeEnum oaLayerArrayConstraintTypeEnum() const\n"
"    Signature: operator oaLayerArrayConstraintTypeEnum|simple-oaLayerArrayConstraintTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator recasts this oaLayerArrayConstraintType object to the oaLayerArrayConstraintTypeEnum value it represents.\n"
;

static PyObject*
oaLayerArrayConstraintType_oaLayerArrayConstraintTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayConstraintType data;
    int convert_status=PyoaLayerArrayConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayConstraintTypeObject* self=(PyoaLayerArrayConstraintTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerArrayConstraintTypeEnum result= (data.DataCall()->operator oaLayerArrayConstraintTypeEnum());
        return PyoaLayerArrayConstraintTypeEnum_FromoaLayerArrayConstraintTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLayerArrayConstraintType_assign_doc[] = 
"Class: oaLayerArrayConstraintType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerArrayConstraintType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerArrayConstraintType data;
  int convert_status=PyoaLayerArrayConstraintType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerArrayConstraintType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerArrayConstraintType_Convert,&p1)) {
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

static PyMethodDef oaLayerArrayConstraintType_methodlist[] = {
    {"getName",(PyCFunction)oaLayerArrayConstraintType_getName,METH_VARARGS,oaLayerArrayConstraintType_getName_doc},
    {"oaLayerArrayConstraintTypeEnum",(PyCFunction)oaLayerArrayConstraintType_oaLayerArrayConstraintTypeEnum,METH_VARARGS,oaLayerArrayConstraintType_oaLayerArrayConstraintTypeEnum_doc},
    {"assign",(PyCFunction)oaLayerArrayConstraintType_tp_assign,METH_VARARGS,oaLayerArrayConstraintType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayConstraintType_doc[] = 
"Class: oaLayerArrayConstraintType\n"
"  oaLayerArrayConstraintTypeEnum\n"
"  The oaLayerArrayConstraintType class is an enum wrapper class for oaLayerArrayConstraintTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaLayerArrayConstraintTypeEnum)\n"
"    Calls: oaLayerArrayConstraintType(oaLayerArrayConstraintTypeEnum typeIn)\n"
"    Signature: oaLayerArrayConstraintType||simple-oaLayerArrayConstraintTypeEnum,\n"
"    This constructor for the oaLayerArrayConstraintType class enum wrapper takes an oaLayerArrayConstraintTypeEnum value.\n"
"    typeIn\n"
"    An oaLayerArrayConstraintType value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLayerArrayConstraintType(const oaString& name)\n"
"    Signature: oaLayerArrayConstraintType||cref-oaString,\n"
"    This constructor for the oaLayerArrayConstraintType class enum wrapper takes the name of an oaLayerArrayConstraintTypeEnum value as input.\n"
"    name\n"
"    The name associated with an oaLayerArrayConstraintTypeEnum value.\n"
"    oacInvalidLayerArrayConstraintTypeName\n"
"  Paramegers: (oaLayerArrayConstraintType)\n"
"    Calls: (const oaLayerArrayConstraintType&)\n"
"    Signature: oaLayerArrayConstraintType||cref-oaLayerArrayConstraintType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerArrayConstraintType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerArrayConstraintType",
    sizeof(PyoaLayerArrayConstraintTypeObject),
    0,
    (destructor)oaLayerArrayConstraintType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerArrayConstraintType_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerArrayConstraintType_tp_repr,	/* tp_repr */
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
    oaLayerArrayConstraintType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerArrayConstraintType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerArrayConstraintType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerArrayConstraintType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerArrayConstraintType_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerArrayConstraintType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerArrayConstraintType",
           (PyObject*)(&PyoaLayerArrayConstraintType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerArrayConstraintType\n");
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
// Wrapper Implementation for Class: oaLayerArrayConstraintTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerArrayConstraintTypeEnum_Convert(PyObject* ob,PyParamoaLayerArrayConstraintTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMinTouchingDirectionExtension")==0) { result->SetData(oacMinTouchingDirectionExtension); return 1;}
        if (strcasecmp(str,"oacMinTouchingDirectionClearance")==0) { result->SetData(oacMinTouchingDirectionClearance); return 1;}
        if (strcasecmp(str,"oacMinClearanceOverLayer")==0) { result->SetData(oacMinClearanceOverLayer); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerArrayConstraintTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArrayConstraintTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerArrayConstraintTypeEnum_FromoaLayerArrayConstraintTypeEnum(oaLayerArrayConstraintTypeEnum ob)
{
    if (ob==oacMinTouchingDirectionExtension) return PyString_FromString("oacMinTouchingDirectionExtension");
    if (ob==oacMinTouchingDirectionClearance) return PyString_FromString("oacMinTouchingDirectionClearance");
    if (ob==oacMinClearanceOverLayer) return PyString_FromString("oacMinClearanceOverLayer");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerArrayConstraintTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerArrayConstraintTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerArrayConstraintTypeEnum_FromoaLayerArrayConstraintTypeEnum(oaLayerArrayConstraintTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerArrayConstraintTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerArrayConstraintTypeEnum_doc[] =
"Type convert function for enum: oaLayerArrayConstraintTypeEnum";
                               
static PyMethodDef PyoaLayerArrayConstraintTypeEnum_method =
  {"oaLayerArrayConstraintTypeEnum",(PyCFunction)PyoaLayerArrayConstraintTypeEnum_TypeFunction,METH_VARARGS,oaLayerArrayConstraintTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerArrayConstraintTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMinTouchingDirectionExtension");
    PyDict_SetItemString(mod_dict,"oacMinTouchingDirectionExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinTouchingDirectionClearance");
    PyDict_SetItemString(mod_dict,"oacMinTouchingDirectionClearance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinClearanceOverLayer");
    PyDict_SetItemString(mod_dict,"oacMinClearanceOverLayer",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerArrayConstraintTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerArrayConstraintTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerArrayConstraintTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayerArrayValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerArrayValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerArrayValueObject* self = (PyoaLayerArrayValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerArrayValue)
    {
        PyParamoaLayerArrayValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerArrayValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerArrayValue, Choices are:\n"
        "    (oaLayerArrayValue)\n"
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
oaLayerArrayValue_tp_dealloc(PyoaLayerArrayValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerArrayValue_tp_repr(PyObject *ob)
{
    PyParamoaLayerArrayValue value;
    int convert_status=PyoaLayerArrayValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaLayerArrayValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerArrayValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerArrayValue v1;
    PyParamoaLayerArrayValue v2;
    int convert_status1=PyoaLayerArrayValue_Convert(ob1,&v1);
    int convert_status2=PyoaLayerArrayValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerArrayValue_Convert(PyObject* ob,PyParamoaLayerArrayValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerArrayValue_Check(ob)) {
        result->SetData( (oaLayerArrayValue**) ((PyoaLayerArrayValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerArrayValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerArrayValue_FromoaLayerArrayValue(oaLayerArrayValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerArrayValue* data=*value;
        PyObject* bself = PyoaLayerArrayValue_Type.tp_alloc(&PyoaLayerArrayValue_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerArrayValueObject* self = (PyoaLayerArrayValueObject*)bself;
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
PyObject* PyoaLayerArrayValue_FromoaLayerArrayValue(oaLayerArrayValue* data)
{
    if (data) {
       PyObject* bself = PyoaLayerArrayValue_Type.tp_alloc(&PyoaLayerArrayValue_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerArrayValueObject* self = (PyoaLayerArrayValueObject*)bself;
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
static char oaLayerArrayValue_get_doc[] = 
"Class: oaLayerArrayValue, Function: get\n"
"  Paramegers: (oaLayerArray)\n"
"    Calls: void get(oaLayerArray& value) const\n"
"    Signature: get|void-void|ref-oaLayerArray,\n"
"    BrowseData: 0,oaLayerArray\n"
"    This function returns the oaLayerArray for this value.\n"
"    value\n"
"    The returned value\n"
;

static PyObject*
oaLayerArrayValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayValue data;
    int convert_status=PyoaLayerArrayValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayValueObject* self=(PyoaLayerArrayValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerArray_Convert,&p1)) {
        data.DataCall()->get(p1.Data());
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
static char oaLayerArrayValue_set_doc[] = 
"Class: oaLayerArrayValue, Function: set\n"
"  Paramegers: (oaLayerArray)\n"
"    Calls: void set(const oaLayerArray& value)\n"
"    Signature: set|void-void|cref-oaLayerArray,\n"
"    This function sets the value to the specified oaLayerArray\n"
"    value\n"
"    The layer array to set.\n"
;

static PyObject*
oaLayerArrayValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerArrayValue data;
    int convert_status=PyoaLayerArrayValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerArrayValueObject* self=(PyoaLayerArrayValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerArray_Convert,&p1)) {
        data.DataCall()->set(p1.Data());
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
static char oaLayerArrayValue_isNull_doc[] =
"Class: oaLayerArrayValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerArrayValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerArrayValue data;
    int convert_status=PyoaLayerArrayValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerArrayValue_assign_doc[] = 
"Class: oaLayerArrayValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerArrayValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerArrayValue data;
  int convert_status=PyoaLayerArrayValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerArrayValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerArrayValue_Convert,&p1)) {
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

static PyMethodDef oaLayerArrayValue_methodlist[] = {
    {"get",(PyCFunction)oaLayerArrayValue_get,METH_VARARGS,oaLayerArrayValue_get_doc},
    {"set",(PyCFunction)oaLayerArrayValue_set,METH_VARARGS,oaLayerArrayValue_set_doc},
    {"isNull",(PyCFunction)oaLayerArrayValue_tp_isNull,METH_VARARGS,oaLayerArrayValue_isNull_doc},
    {"assign",(PyCFunction)oaLayerArrayValue_tp_assign,METH_VARARGS,oaLayerArrayValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayValue_doc[] = 
"Class: oaLayerArrayValue\n"
"  The oaLayerArrayValue represents a value that contains an array of oaLayerNums.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaLayerArrayValue)\n"
"    Calls: (const oaLayerArrayValue&)\n"
"    Signature: oaLayerArrayValue||cref-oaLayerArrayValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerArrayValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerArrayValue",
    sizeof(PyoaLayerArrayValueObject),
    0,
    (destructor)oaLayerArrayValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerArrayValue_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerArrayValue_tp_repr,	/* tp_repr */
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
    oaLayerArrayValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerArrayValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerArrayValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerArrayValue_static_create_doc[] = 
"Class: oaLayerArrayValue, Function: create\n"
"  Paramegers: (oaObject,oaLayerArray)\n"
"    Calls: oaLayerArrayValue* create(oaObject* database,const oaLayerArray& value)\n"
"    Signature: create|ptr-oaLayerArrayValue|ptr-oaObject,cref-oaLayerArray,\n"
"    This function creates a layer array value in the specified database.\n"
"    database\n"
"    The database in which to create the value\n"
"    value\n"
"    The layer array\n"
"    oacInvalidDatabase\n"
"    oacInvalidDatabaseForValue\n"
"  Paramegers: (oaObject,oaLayerArray)\n"
"    Calls: oaLayerArrayValue* create(oaObject* database,oaLayerArray& value)\n"
"    Signature: create|ptr-oaLayerArrayValue|ptr-oaObject,ref-oaLayerArray,\n"
"    This function is deprecated and is retained to ensure compatibility with previous versions of OpenAccess. Use the create function overload that takes a const oaLayerArray reference instead.\n"
"    This function creates a layer array value in the specified database.\n"
"    database\n"
"    The database in which to create the value\n"
"    value\n"
"    The layer array value\n"
"    oacInvalidDatabase\n"
"    oacInvalidDatabaseForValue\n"
;

static PyObject*
oaLayerArrayValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaObject,oaLayerArray)
    {
        PyParamoaObject p1;
        PyParamoaLayerArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaLayerArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerArrayValuep result= (oaLayerArrayValue::create(p1.Data(),p2.Data()));
            return PyoaLayerArrayValue_FromoaLayerArrayValue(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaLayerArray)
    {
        PyParamoaObject p1;
        PyParamoaLayerArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaLayerArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerArrayValuep result= (oaLayerArrayValue::create(p1.Data(),p2.Data()));
            return PyoaLayerArrayValue_FromoaLayerArrayValue(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerArrayValue, function: create, Choices are:\n"
        "    (oaObject,oaLayerArray)\n"
        "    (oaObject,oaLayerArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerArrayValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerArrayValue_static_create,METH_VARARGS,oaLayerArrayValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerArrayValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerArrayValue_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerArrayValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerArrayValue",
           (PyObject*)(&PyoaLayerArrayValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerArrayValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerArrayValue_Type.tp_dict;
    for(method=oaLayerArrayValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerBlockage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerBlockage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerBlockage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerBlockageObject* self = (PyoaLayerBlockageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerBlockage)
    {
        PyParamoaLayerBlockage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerBlockage_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerBlockage, Choices are:\n"
        "    (oaLayerBlockage)\n"
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
oaLayerBlockage_tp_dealloc(PyoaLayerBlockageObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerBlockage_tp_repr(PyObject *ob)
{
    PyParamoaLayerBlockage value;
    int convert_status=PyoaLayerBlockage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaLayerBlockage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerBlockage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerBlockage v1;
    PyParamoaLayerBlockage v2;
    int convert_status1=PyoaLayerBlockage_Convert(ob1,&v1);
    int convert_status2=PyoaLayerBlockage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerBlockage_Convert(PyObject* ob,PyParamoaLayerBlockage* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerBlockage_Check(ob)) {
        result->SetData( (oaLayerBlockage**) ((PyoaLayerBlockageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerBlockage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerBlockage_FromoaLayerBlockage(oaLayerBlockage** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerBlockage* data=*value;
        PyObject* bself = PyoaLayerBlockage_Type.tp_alloc(&PyoaLayerBlockage_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerBlockageObject* self = (PyoaLayerBlockageObject*)bself;
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
PyObject* PyoaLayerBlockage_FromoaLayerBlockage(oaLayerBlockage* data)
{
    if (data) {
       PyObject* bself = PyoaLayerBlockage_Type.tp_alloc(&PyoaLayerBlockage_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerBlockageObject* self = (PyoaLayerBlockageObject*)bself;
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
static char oaLayerBlockage_getEffectiveWidth_doc[] = 
"Class: oaLayerBlockage, Function: getEffectiveWidth\n"
"  Paramegers: ()\n"
"    Calls: oaDist getEffectiveWidth() const\n"
"    Signature: getEffectiveWidth|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the effective width of with this blockage.\n"
;

static PyObject*
oaLayerBlockage_getEffectiveWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getEffectiveWidth());
        return PyoaDist_FromoaDist(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerBlockage_getLayerHeader_doc[] = 
"Class: oaLayerBlockage, Function: getLayerHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getLayerHeader() const\n"
"    Signature: getLayerHeader|ptr-oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layerHeader for the layer of this blockage.\n"
;

static PyObject*
oaLayerBlockage_getLayerHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getLayerHeader());
        return PyoaLayerHeader_FromoaLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerBlockage_getLayerNum_doc[] = 
"Class: oaLayerBlockage, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number associated with this blockage.\n"
;

static PyObject*
oaLayerBlockage_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
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
static char oaLayerBlockage_hasEffectiveWidth_doc[] = 
"Class: oaLayerBlockage, Function: hasEffectiveWidth\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasEffectiveWidth() const\n"
"    Signature: hasEffectiveWidth|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not an effective width has been set for this blockage.\n"
;

static PyObject*
oaLayerBlockage_hasEffectiveWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasEffectiveWidth());
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
static char oaLayerBlockage_setEffectiveWidth_doc[] = 
"Class: oaLayerBlockage, Function: setEffectiveWidth\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setEffectiveWidth(oaDist width)\n"
"    Signature: setEffectiveWidth|void-void|simple-oaDist,\n"
"    This function sets the effective width of this blockage. The effective width value allows you to specify what width should be used when looking up the minimum spacing value in the technology database.\n"
"    Usage is as follows:\n"
"    no Width: Use the actual blockage size to look up min spacing.\n"
"    Width > 0: Use the given width to look up minimum spacing.\n"
"    Width = 0: No spacing required.\n"
"    width\n"
"    effective width value\n"
;

static PyObject*
oaLayerBlockage_setEffectiveWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setEffectiveWidth(p1.Data());
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
static char oaLayerBlockage_setLayerNum_doc[] = 
"Class: oaLayerBlockage, Function: setLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setLayerNum(oaLayerNum layerNum)\n"
"    Signature: setLayerNum|void-void|simple-oaLayerNum,\n"
"    This function moves this blockage to the specified layer. The new layer is created if it does not exist. The old layer is deleted if it becomes empty. A layer may not be set on placement blockages.\n"
"    layerNum\n"
"    The layer number\n"
"    oacInvalidLayerForLayerBlockage\n"
;

static PyObject*
oaLayerBlockage_setLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
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
static char oaLayerBlockage_setPoints_doc[] = 
"Class: oaLayerBlockage, Function: setPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setPoints(const oaPointArray& points)\n"
"    Signature: setPoints|void-void|cref-oaPointArray,\n"
"    This function updates the shape of the blockages to the shape specified by the pointArray\n"
"    points\n"
"    The pointArray describing the new shape of the blockage\n"
"    oacBlockageHasExtraPoints\n"
"    oacBlockageTooFewPoints\n"
;

static PyObject*
oaLayerBlockage_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.DataCall()->setPoints(p1.Data());
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
static char oaLayerBlockage_transform_doc[] = 
"Class: oaLayerBlockage, Function: transform\n"
"  Paramegers: (oaDouble,oaDouble)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle)\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,\n"
"    This function transforms this blockage by the specified scale factor and rotation angle. If this blockage is a leader in a group, every object in the group is moved with the specified transform.\n"
"    scale\n"
"    The scale for the transformation.\n"
"    angle\n"
"    The angle of the transformation.\n"
;

static PyObject*
oaLayerBlockage_transform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDouble p1;
    PyParamoaDouble p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDouble_Convert,&p1,
          &PyoaDouble_Convert,&p2)) {
        data.DataCall()->transform(p1.Data(),p2.Data());
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
static char oaLayerBlockage_unsetEffectiveWidth_doc[] = 
"Class: oaLayerBlockage, Function: unsetEffectiveWidth\n"
"  Paramegers: ()\n"
"    Calls: void unsetEffectiveWidth()\n"
"    Signature: unsetEffectiveWidth|void-void|\n"
"    BrowseData: 0\n"
"    This function removes the effective width value for this blockage.\n"
;

static PyObject*
oaLayerBlockage_unsetEffectiveWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerBlockageObject* self=(PyoaLayerBlockageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->unsetEffectiveWidth();
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
static char oaLayerBlockage_isNull_doc[] =
"Class: oaLayerBlockage, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerBlockage_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerBlockage data;
    int convert_status=PyoaLayerBlockage_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerBlockage_assign_doc[] = 
"Class: oaLayerBlockage, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerBlockage_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerBlockage data;
  int convert_status=PyoaLayerBlockage_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerBlockage p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerBlockage_Convert,&p1)) {
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

static PyMethodDef oaLayerBlockage_methodlist[] = {
    {"getEffectiveWidth",(PyCFunction)oaLayerBlockage_getEffectiveWidth,METH_VARARGS,oaLayerBlockage_getEffectiveWidth_doc},
    {"getLayerHeader",(PyCFunction)oaLayerBlockage_getLayerHeader,METH_VARARGS,oaLayerBlockage_getLayerHeader_doc},
    {"getLayerNum",(PyCFunction)oaLayerBlockage_getLayerNum,METH_VARARGS,oaLayerBlockage_getLayerNum_doc},
    {"hasEffectiveWidth",(PyCFunction)oaLayerBlockage_hasEffectiveWidth,METH_VARARGS,oaLayerBlockage_hasEffectiveWidth_doc},
    {"setEffectiveWidth",(PyCFunction)oaLayerBlockage_setEffectiveWidth,METH_VARARGS,oaLayerBlockage_setEffectiveWidth_doc},
    {"setLayerNum",(PyCFunction)oaLayerBlockage_setLayerNum,METH_VARARGS,oaLayerBlockage_setLayerNum_doc},
    {"setPoints",(PyCFunction)oaLayerBlockage_setPoints,METH_VARARGS,oaLayerBlockage_setPoints_doc},
    {"transform",(PyCFunction)oaLayerBlockage_transform,METH_VARARGS,oaLayerBlockage_transform_doc},
    {"unsetEffectiveWidth",(PyCFunction)oaLayerBlockage_unsetEffectiveWidth,METH_VARARGS,oaLayerBlockage_unsetEffectiveWidth_doc},
    {"isNull",(PyCFunction)oaLayerBlockage_tp_isNull,METH_VARARGS,oaLayerBlockage_isNull_doc},
    {"assign",(PyCFunction)oaLayerBlockage_tp_assign,METH_VARARGS,oaLayerBlockage_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerBlockage_doc[] = 
"Class: oaLayerBlockage\n"
"  A layer blockage is a type of blockage representing an area on a given layer. The shape of a blockage is described using an oaPointArray . Coincident and collinear points are illegal in the point array for a layer blockage.\n"
"  oaLayerBlockages may have an effective width. This is the value that is used by routing tools to determine the minimum spacing constraint for other geometry placed near the blockage. Typically, if a blockage has no effective width ( hasEffectiveWidth() is false), the blockage should be treated as \"real geometry\" by tools, and its width is the width of the blockage plus any other adjacent geometry.\n"
"Constructors:\n"
"  Paramegers: (oaLayerBlockage)\n"
"    Calls: (const oaLayerBlockage&)\n"
"    Signature: oaLayerBlockage||cref-oaLayerBlockage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerBlockage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerBlockage",
    sizeof(PyoaLayerBlockageObject),
    0,
    (destructor)oaLayerBlockage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerBlockage_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerBlockage_tp_repr,	/* tp_repr */
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
    oaLayerBlockage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerBlockage_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockage_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerBlockage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerBlockage_static_create_doc[] = 
"Class: oaLayerBlockage, Function: create\n"
"  Paramegers: (oaBlock,oaBlockageType,oaLayerNum,oaPointArray)\n"
"    Calls: oaLayerBlockage* create(oaBlock* block,oaBlockageType type,oaLayerNum layer,const oaPointArray& points)\n"
"    Signature: create|ptr-oaLayerBlockage|ptr-oaBlock,simple-oaBlockageType,simple-oaLayerNum,cref-oaPointArray,ptr-oaBlockObject,\n"
"    This is the constructor for a layer blockage.\n"
"    block\n"
"    The block in which to create the area blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerBlockage should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    points\n"
"    The pointArray describing the shape of the blockage\n"
"    owner\n"
"    The optional cluster or boundary owner of the blockage\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacBlockageHasExtraPoints\n"
"    oacBlockageTooFewPoints\n"
"    oacInvalidBlockageOwner\n"
"  Paramegers: (oaBlock,oaBlockageType,oaLayerNum,oaPointArray,oaBlockObject)\n"
"    Calls: oaLayerBlockage* create(oaBlock* block,oaBlockageType type,oaLayerNum layer,const oaPointArray& points,oaBlockObject* owner)\n"
"    Signature: create|ptr-oaLayerBlockage|ptr-oaBlock,simple-oaBlockageType,simple-oaLayerNum,cref-oaPointArray,ptr-oaBlockObject,\n"
"    This is the constructor for a layer blockage.\n"
"    block\n"
"    The block in which to create the area blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerBlockage should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    points\n"
"    The pointArray describing the shape of the blockage\n"
"    owner\n"
"    The optional cluster or boundary owner of the blockage\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacBlockageHasExtraPoints\n"
"    oacBlockageTooFewPoints\n"
"    oacInvalidBlockageOwner\n"
;

static PyObject*
oaLayerBlockage_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaBlockageType,oaLayerNum,oaPointArray)
    {
        PyParamoaBlock p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaPointArray p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPointArray_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerBlockagep result= (oaLayerBlockage::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerBlockage_FromoaLayerBlockage(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaBlockageType,oaLayerNum,oaPointArray,oaBlockObject)
    {
        PyParamoaBlock p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaPointArray p4;
        PyParamoaBlockObject p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPointArray_Convert,&p4,
              &PyoaBlockObject_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p5.Data(),5)) return NULL;
            oaLayerBlockagep result= (oaLayerBlockage::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerBlockage_FromoaLayerBlockage(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerBlockage, function: create, Choices are:\n"
        "    (oaBlock,oaBlockageType,oaLayerNum,oaPointArray)\n"
        "    (oaBlock,oaBlockageType,oaLayerNum,oaPointArray,oaBlockObject)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerBlockage_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerBlockage_static_create,METH_VARARGS,oaLayerBlockage_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerBlockage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerBlockage_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerBlockage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerBlockage",
           (PyObject*)(&PyoaLayerBlockage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerBlockage\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerBlockage_Type.tp_dict;
    for(method=oaLayerBlockage_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerConstraintObject* self = (PyoaLayerConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerConstraint)
    {
        PyParamoaLayerConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerConstraint_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerConstraint, Choices are:\n"
        "    (oaLayerConstraint)\n"
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
oaLayerConstraint_tp_dealloc(PyoaLayerConstraintObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraint_tp_repr(PyObject *ob)
{
    PyParamoaLayerConstraint value;
    int convert_status=PyoaLayerConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaLayerConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerConstraint v1;
    PyParamoaLayerConstraint v2;
    int convert_status1=PyoaLayerConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaLayerConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerConstraint_Convert(PyObject* ob,PyParamoaLayerConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerConstraint_Check(ob)) {
        result->SetData( (oaLayerConstraint**) ((PyoaLayerConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerConstraint_FromoaLayerConstraint(oaLayerConstraint** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerConstraint* data=*value;
        PyObject* bself = PyoaLayerConstraint_Type.tp_alloc(&PyoaLayerConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerConstraintObject* self = (PyoaLayerConstraintObject*)bself;
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
PyObject* PyoaLayerConstraint_FromoaLayerConstraint(oaLayerConstraint* data)
{
    if (data) {
       PyObject* bself = PyoaLayerConstraint_Type.tp_alloc(&PyoaLayerConstraint_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerConstraintObject* self = (PyoaLayerConstraintObject*)bself;
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
static char oaLayerConstraint_getLayer_doc[] = 
"Class: oaLayerConstraint, Function: getLayer\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayer() const\n"
"    Signature: getLayer|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns layer number associated with this layer constraint.\n"
;

static PyObject*
oaLayerConstraint_getLayer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerConstraint data;
    int convert_status=PyoaLayerConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerConstraintObject* self=(PyoaLayerConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayer());
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
static char oaLayerConstraint_isNull_doc[] =
"Class: oaLayerConstraint, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerConstraint_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerConstraint data;
    int convert_status=PyoaLayerConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerConstraint_assign_doc[] = 
"Class: oaLayerConstraint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerConstraint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerConstraint data;
  int convert_status=PyoaLayerConstraint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerConstraint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerConstraint_Convert,&p1)) {
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

static PyMethodDef oaLayerConstraint_methodlist[] = {
    {"getLayer",(PyCFunction)oaLayerConstraint_getLayer,METH_VARARGS,oaLayerConstraint_getLayer_doc},
    {"isNull",(PyCFunction)oaLayerConstraint_tp_isNull,METH_VARARGS,oaLayerConstraint_isNull_doc},
    {"assign",(PyCFunction)oaLayerConstraint_tp_assign,METH_VARARGS,oaLayerConstraint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerConstraint_doc[] = 
"Class: oaLayerConstraint\n"
"  The oaLayerConstraint class represents a constraint object that constrains objects on a specific layer. In addition to the layer, the oaLayerConstraint is described by its oaLayerConstraintDef . A layer constraint has a value associated with it and potentially a list of constraint parameters. A layer constraint may or may not be a hard constraint. A hard constraint is a constraint that must be met.\n"
"  oaLayerConstraints always have a value, and are created in the same database as that value. oaLayerConstraints get applied to objects by being placed in an oaConstraintGroup .\n"
"Constructors:\n"
"  Paramegers: (oaLayerConstraint)\n"
"    Calls: (const oaLayerConstraint&)\n"
"    Signature: oaLayerConstraint||cref-oaLayerConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerConstraint",
    sizeof(PyoaLayerConstraintObject),
    0,
    (destructor)oaLayerConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerConstraint_tp_repr,	/* tp_repr */
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
    oaLayerConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerConstraint_static_create_doc[] = 
"Class: oaLayerConstraint, Function: create\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaValue)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,oaValue* value)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,const oaString& name,oaValue* value)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    name\n"
"    The constraint name.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters.\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    name\n"
"    The constraint name.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters.\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerConstraint* create(oaLayerNum layer,const oaLayerConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerConstraint|simple-oaLayerNum,cptr-oaLayerConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer\n"
"    The layer associated with the constraint.\n"
"    def\n"
"    The layer constraint definition.\n"
"    name\n"
"    The constraint name.\n"
"    value\n"
"    The constraint value.\n"
"    isHard\n"
"    A Boolean indicating whether the constraint must be met.\n"
"    params\n"
"    Optional constraint parameters.\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
;

static PyObject*
oaLayerConstraint_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaLayerNum,oaLayerConstraintDef,oaValue)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaValue p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        PyParamoaConstraintParamArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaConstraintParamArray_ConvertAof,&p5)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerConstraintDef p2;
        PyParamoaString p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        PyParamoaConstraintParamArray p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerConstraintDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaConstraintParamArray_ConvertAof,&p6)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerConstraint, function: create, Choices are:\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaValue)\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean)\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaString,oaValue)\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean)\n"
        "    (oaLayerNum,oaLayerConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerConstraint_static_find_doc[] = 
"Class: oaLayerConstraint, Function: find\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
"    Calls: oaLayerConstraint* find(const oaConstraintGroup* group,oaLayerNum layer,const oaLayerConstraintDef* def)\n"
"    Signature: find|ptr-oaLayerConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in this group that matches the definition, and layer specified. If no such constraint is found, NULL is returned.\n"
"    group\n"
"    The group to search.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to search for.\n"
"    hardOnly\n"
"    Boolean\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef,oaBoolean)\n"
"    Calls: oaLayerConstraint* find(const oaConstraintGroup* group,oaLayerNum layer,const oaLayerConstraintDef* def,oaBoolean hardOnly)\n"
"    Signature: find|ptr-oaLayerConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in this group that matches the definition, and layer specified. If no such constraint is found, NULL is returned.\n"
"    group\n"
"    The group to search.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to search for.\n"
"    hardOnly\n"
"    Boolean\n"
;

static PyObject*
oaLayerConstraint_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerConstraintDef p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerConstraintDef_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLayerConstraintp result= (oaLayerConstraint::find(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerConstraint_FromoaLayerConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerConstraint, function: find, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerConstraint_static_getConstraints_doc[] = 
"Class: oaLayerConstraint, Function: getConstraints\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum)\n"
"    Calls: oaCollection_oaLayerConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,oaLayerNum layer)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerConstraint_oaConstraintGroup|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,\n"
"    This function returns a collection of layer constraints in the specified group the definition of which matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    The group to search in.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to filter with.\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
"    Calls: oaCollection_oaLayerConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,oaLayerNum layer,const oaLayerConstraintDef* def)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerConstraint_oaConstraintGroup|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,\n"
"    This function returns a collection of layer constraints in the specified group the definition of which matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    The group to search in.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to filter with.\n"
;

static PyObject*
oaLayerConstraint_static_getConstraints(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaCollection_oaLayerConstraint_oaConstraintGroup* result= new oaCollection_oaLayerConstraint_oaConstraintGroup(oaLayerConstraint::getConstraints(p1.Data(),p2.Data()));
            return PyoaCollection_oaLayerConstraint_oaConstraintGroup_FromoaCollection_oaLayerConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaCollection_oaLayerConstraint_oaConstraintGroup* result= new oaCollection_oaLayerConstraint_oaConstraintGroup(oaLayerConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCollection_oaLayerConstraint_oaConstraintGroup_FromoaCollection_oaLayerConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerConstraint, function: getConstraints, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerConstraint_static_getConstraintsIter_doc[] = 
"Class: oaLayerConstraint, Function: getConstraintsIter\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum)\n"
"    Calls: oaIter_oaLayerConstraint getConstraintsIter(const oaConstraintGroup* group,oaLayerNum layer)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer constraints in the specified group the definition of which matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    The group to search in.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to filter with.\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
"    Calls: oaIter_oaLayerConstraint getConstraintsIter(const oaConstraintGroup* group,oaLayerNum layer,const oaLayerConstraintDef* def)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,cptr-oaLayerConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer constraints in the specified group the definition of which matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    The group to search in.\n"
"    layer\n"
"    The layer to search for.\n"
"    def\n"
"    The layer constraint definition to filter with.\n"
;

static PyObject*
oaLayerConstraint_static_getConstraintsIter(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaIter_oaLayerConstraint* result= new oaIter_oaLayerConstraint(oaLayerConstraint::getConstraints(p1.Data(),p2.Data()));
            return PyoaIter_oaLayerConstraint_FromoaIter_oaLayerConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerConstraintDef p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerConstraintDef_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaIter_oaLayerConstraint* result= new oaIter_oaLayerConstraint(oaLayerConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaIter_oaLayerConstraint_FromoaIter_oaLayerConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerConstraint, function: getConstraintsIter, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerConstraint_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerConstraint_static_create,METH_VARARGS,oaLayerConstraint_static_create_doc},
    {"static_find",(PyCFunction)oaLayerConstraint_static_find,METH_VARARGS,oaLayerConstraint_static_find_doc},
    {"static_getConstraints",(PyCFunction)oaLayerConstraint_static_getConstraints,METH_VARARGS,oaLayerConstraint_static_getConstraints_doc},
    {"static_getConstraintsIter",(PyCFunction)oaLayerConstraint_static_getConstraintsIter,METH_VARARGS,oaLayerConstraint_static_getConstraintsIter_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerConstraint",
           (PyObject*)(&PyoaLayerConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerConstraint\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerConstraint_Type.tp_dict;
    for(method=oaLayerConstraint_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerConstraintDefObject* self = (PyoaLayerConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerConstraintDef)
    {
        PyParamoaLayerConstraintDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerConstraintDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerConstraintDef, Choices are:\n"
        "    (oaLayerConstraintDef)\n"
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
oaLayerConstraintDef_tp_dealloc(PyoaLayerConstraintDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaLayerConstraintDef value;
    int convert_status=PyoaLayerConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaLayerConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerConstraintDef v1;
    PyParamoaLayerConstraintDef v2;
    int convert_status1=PyoaLayerConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaLayerConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerConstraintDef_Convert(PyObject* ob,PyParamoaLayerConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerConstraintDef_Check(ob)) {
        result->SetData( (oaLayerConstraintDef**) ((PyoaLayerConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerConstraintDef_FromoaLayerConstraintDef(oaLayerConstraintDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerConstraintDef* data=*value;
        PyObject* bself = PyoaLayerConstraintDef_Type.tp_alloc(&PyoaLayerConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerConstraintDefObject* self = (PyoaLayerConstraintDefObject*)bself;
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
PyObject* PyoaLayerConstraintDef_FromoaLayerConstraintDef(oaLayerConstraintDef* data)
{
    if (data) {
       PyObject* bself = PyoaLayerConstraintDef_Type.tp_alloc(&PyoaLayerConstraintDef_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerConstraintDefObject* self = (PyoaLayerConstraintDefObject*)bself;
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
static char oaLayerConstraintDef_doc[] = 
"Class: oaLayerConstraintDef\n"
"  A oaLayerConstraintDef object specifies a definition for a layer constraint. The definition contains a name, a list of databases that the constraint can be created in, and a list of types of oaValues that are allowed for the constraint. The names for all constraint definitions must be unique.\n"
"Constructors:\n"
"  Paramegers: (oaLayerConstraintDef)\n"
"    Calls: (const oaLayerConstraintDef&)\n"
"    Signature: oaLayerConstraintDef||cref-oaLayerConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerConstraintDef",
    sizeof(PyoaLayerConstraintDefObject),
    0,
    (destructor)oaLayerConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerConstraintDef_tp_repr,	/* tp_repr */
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
    oaLayerConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerConstraintDef_static_create_doc[] = 
"Class: oaLayerConstraintDef, Function: create\n"
"  Paramegers: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType)\n"
"    Calls: oaLayerConstraintDef* create(const oaString& name,const oaSubset_oaType& allowedValues,const oaSubset_oaType& allowedObjects,const oaSubset_oaDBType& allowedDB)\n"
"    Signature: create|ptr-oaLayerConstraintDef|cref-oaString,cref-oaSubset_oaType,cref-oaSubset_oaType,cref-oaSubset_oaDBType,\n"
"    oaLayerConstraintDef::create\n"
"    This function creates a new layer constraint definition with the specified attributes.\n"
"    name\n"
"    The name of the new definition.\n"
"    allowedValues\n"
"    The value types that constraints with this definition can have.\n"
"    allowedObjects\n"
"    The objects that constraints with this definition can be attached to.\n"
"    allowedDB\n"
"    The databases that constraints with this definition can be created in.\n"
"    oacConstraintDefExists\n"
"    oacInvalidValueType\n"
;

static PyObject*
oaLayerConstraintDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaSubset_oaType p2;
    PyParamoaSubset_oaType p3;
    PyParamoaSubset_oaDBType p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaString_Convert,&p1,
          &PyoaSubset_oaType_Convert,&p2,
          &PyoaSubset_oaType_Convert,&p3,
          &PyoaSubset_oaDBType_Convert,&p4)) {
        oaLayerConstraintDefp result= (oaLayerConstraintDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaLayerConstraintDef_FromoaLayerConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerConstraintDef_static_get_doc[] = 
"Class: oaLayerConstraintDef, Function: get\n"
"  Paramegers: (oaLayerConstraintType)\n"
"    Calls: oaLayerConstraintDef* get(oaLayerConstraintType type)\n"
"    Signature: get|ptr-oaLayerConstraintDef|simple-oaLayerConstraintType,\n"
"    This function returns the built-in layer constraint definition of the type specified.\n"
"    type\n"
"    The built-in layer constraint type to find.\n"
;

static PyObject*
oaLayerConstraintDef_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerConstraintType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerConstraintType_Convert,&p1)) {
        oaLayerConstraintDefp result= (oaLayerConstraintDef::get(p1.Data()));
        return PyoaLayerConstraintDef_FromoaLayerConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerConstraintDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerConstraintDef_static_create,METH_VARARGS,oaLayerConstraintDef_static_create_doc},
    {"static_get",(PyCFunction)oaLayerConstraintDef_static_get,METH_VARARGS,oaLayerConstraintDef_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerConstraintDef",
           (PyObject*)(&PyoaLayerConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerConstraintDef_Type.tp_dict;
    for(method=oaLayerConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerConstraintType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraintType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerConstraintType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerConstraintTypeObject* self = (PyoaLayerConstraintTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerConstraintTypeEnum)
    {
        PyParamoaLayerConstraintTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerConstraintTypeEnum_Convert,&p1)) {
            self->value =  new oaLayerConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLayerConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerConstraintType)
    {
        PyParamoaLayerConstraintType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerConstraintType_Convert,&p1)) {
            self->value= new oaLayerConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerConstraintType, Choices are:\n"
        "    (oaLayerConstraintTypeEnum)\n"
        "    (oaString)\n"
        "    (oaLayerConstraintType)\n"
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
oaLayerConstraintType_tp_dealloc(PyoaLayerConstraintTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerConstraintType_tp_repr(PyObject *ob)
{
    PyParamoaLayerConstraintType value;
    int convert_status=PyoaLayerConstraintType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[43];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLayerConstraintType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerConstraintType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerConstraintType v1;
    PyParamoaLayerConstraintType v2;
    int convert_status1=PyoaLayerConstraintType_Convert(ob1,&v1);
    int convert_status2=PyoaLayerConstraintType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerConstraintType_Convert(PyObject* ob,PyParamoaLayerConstraintType* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerConstraintType_Check(ob)) {
        result->SetData(  ((PyoaLayerConstraintTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerConstraintType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerConstraintType_FromoaLayerConstraintType(oaLayerConstraintType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerConstraintType_Type.tp_alloc(&PyoaLayerConstraintType_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerConstraintTypeObject* self = (PyoaLayerConstraintTypeObject*)bself;
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
static char oaLayerConstraintType_getName_doc[] = 
"Class: oaLayerConstraintType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the encapsulated oaLayerConstraintTypeEnum object.\n"
;

static PyObject*
oaLayerConstraintType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerConstraintType data;
    int convert_status=PyoaLayerConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerConstraintTypeObject* self=(PyoaLayerConstraintTypeObject*)ob;

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
static char oaLayerConstraintType_oaLayerConstraintTypeEnum_doc[] = 
"Class: oaLayerConstraintType, Function: oaLayerConstraintTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerConstraintTypeEnum oaLayerConstraintTypeEnum() const\n"
"    Signature: operator oaLayerConstraintTypeEnum|simple-oaLayerConstraintTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaLayerConstraintType object into the corresponding oaLayerConstraintTypeEnum.\n"
;

static PyObject*
oaLayerConstraintType_oaLayerConstraintTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerConstraintType data;
    int convert_status=PyoaLayerConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerConstraintTypeObject* self=(PyoaLayerConstraintTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerConstraintTypeEnum result= (data.DataCall()->operator oaLayerConstraintTypeEnum());
        return PyoaLayerConstraintTypeEnum_FromoaLayerConstraintTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLayerConstraintType_assign_doc[] = 
"Class: oaLayerConstraintType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerConstraintType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerConstraintType data;
  int convert_status=PyoaLayerConstraintType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerConstraintType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerConstraintType_Convert,&p1)) {
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

static PyMethodDef oaLayerConstraintType_methodlist[] = {
    {"getName",(PyCFunction)oaLayerConstraintType_getName,METH_VARARGS,oaLayerConstraintType_getName_doc},
    {"oaLayerConstraintTypeEnum",(PyCFunction)oaLayerConstraintType_oaLayerConstraintTypeEnum,METH_VARARGS,oaLayerConstraintType_oaLayerConstraintTypeEnum_doc},
    {"assign",(PyCFunction)oaLayerConstraintType_tp_assign,METH_VARARGS,oaLayerConstraintType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerConstraintType_doc[] = 
"Class: oaLayerConstraintType\n"
"  The oaLayerConstraintType class is an enum wrapper class for oaLayerConstraintTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaLayerConstraintTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaLayerConstraintTypeEnum)\n"
"    Calls: oaLayerConstraintType(oaLayerConstraintTypeEnum typeIn)\n"
"    Signature: oaLayerConstraintType||simple-oaLayerConstraintTypeEnum,\n"
"    This function constructs an instance of an oaLayerConstraintType class using the specified oaLayerConstraintTypeEnum value.\n"
"    typeIn\n"
"    The layer constraint type.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLayerConstraintType(const oaString& name)\n"
"    Signature: oaLayerConstraintType||cref-oaString,\n"
"    This function creates an instance of an oaLayerConstraintType class using the oaLayerConstraintTypeEnum associated with the specified string name. This name must be defined in the legal set of names associated with oaLayerConstraintTypeEnum.\n"
"    name\n"
"    The name of the layer constraint type.\n"
"    oacInvalidLayerConstraintTypeName\n"
"  Paramegers: (oaLayerConstraintType)\n"
"    Calls: (const oaLayerConstraintType&)\n"
"    Signature: oaLayerConstraintType||cref-oaLayerConstraintType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerConstraintType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerConstraintType",
    sizeof(PyoaLayerConstraintTypeObject),
    0,
    (destructor)oaLayerConstraintType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerConstraintType_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerConstraintType_tp_repr,	/* tp_repr */
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
    oaLayerConstraintType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerConstraintType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerConstraintType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerConstraintType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerConstraintType_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerConstraintType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerConstraintType",
           (PyObject*)(&PyoaLayerConstraintType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerConstraintType\n");
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
// Wrapper Implementation for Class: oaLayerConstraintTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerConstraintTypeEnum_Convert(PyObject* ob,PyParamoaLayerConstraintTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMinArea")==0) { result->SetData(oacMinArea); return 1;}
        if (strcasecmp(str,"oacMinEnclosedArea")==0) { result->SetData(oacMinEnclosedArea); return 1;}
        if (strcasecmp(str,"oacMinDensity")==0) { result->SetData(oacMinDensity); return 1;}
        if (strcasecmp(str,"oacMaxDensity")==0) { result->SetData(oacMaxDensity); return 1;}
        if (strcasecmp(str,"oacMinEdgeLength")==0) { result->SetData(oacMinEdgeLength); return 1;}
        if (strcasecmp(str,"oacMinConcaveEdgeLength")==0) { result->SetData(oacMinConcaveEdgeLength); return 1;}
        if (strcasecmp(str,"oacMinConvexEdgeLength")==0) { result->SetData(oacMinConvexEdgeLength); return 1;}
        if (strcasecmp(str,"oacMinDiagonalEdgeLength")==0) { result->SetData(oacMinDiagonalEdgeLength); return 1;}
        if (strcasecmp(str,"oacMinSpacing")==0) { result->SetData(oacMinSpacing); return 1;}
        if (strcasecmp(str,"oacMinDiagonalSpacing")==0) { result->SetData(oacMinDiagonalSpacing); return 1;}
        if (strcasecmp(str,"oacMinCenterToCenterSpacing")==0) { result->SetData(oacMinCenterToCenterSpacing); return 1;}
        if (strcasecmp(str,"oacMinDiffPotentialSpacing")==0) { result->SetData(oacMinDiffPotentialSpacing); return 1;}
        if (strcasecmp(str,"oacMinEnclosedSpacing")==0) { result->SetData(oacMinEnclosedSpacing); return 1;}
        if (strcasecmp(str,"oacMinFillPatternSpacing")==0) { result->SetData(oacMinFillPatternSpacing); return 1;}
        if (strcasecmp(str,"oacMinProximitySpacing")==0) { result->SetData(oacMinProximitySpacing); return 1;}
        if (strcasecmp(str,"oacMinProtrudedProximitySpacing")==0) { result->SetData(oacMinProtrudedProximitySpacing); return 1;}
        if (strcasecmp(str,"oacMinSameNetSpacing")==0) { result->SetData(oacMinSameNetSpacing); return 1;}
        if (strcasecmp(str,"oacMinAdjacentViaSpacing")==0) { result->SetData(oacMinAdjacentViaSpacing); return 1;}
        if (strcasecmp(str,"oacMergeSpaceAllowed")==0) { result->SetData(oacMergeSpaceAllowed); return 1;}
        if (strcasecmp(str,"oacMinWidth")==0) { result->SetData(oacMinWidth); return 1;}
        if (strcasecmp(str,"oacMinDiagonalWidth")==0) { result->SetData(oacMinDiagonalWidth); return 1;}
        if (strcasecmp(str,"oacMinProtrusionWidth")==0) { result->SetData(oacMinProtrusionWidth); return 1;}
        if (strcasecmp(str,"oacMaxWidth")==0) { result->SetData(oacMaxWidth); return 1;}
        if (strcasecmp(str,"oacMinSize")==0) { result->SetData(oacMinSize); return 1;}
        if (strcasecmp(str,"oacMinNumCut")==0) { result->SetData(oacMinNumCut); return 1;}
        if (strcasecmp(str,"oacMinProtrusionNumCut")==0) { result->SetData(oacMinProtrusionNumCut); return 1;}
        if (strcasecmp(str,"oacHorizontalRouteGridPitch")==0) { result->SetData(oacHorizontalRouteGridPitch); return 1;}
        if (strcasecmp(str,"oacHorizontalRouteGridOffset")==0) { result->SetData(oacHorizontalRouteGridOffset); return 1;}
        if (strcasecmp(str,"oacVerticalRouteGridPitch")==0) { result->SetData(oacVerticalRouteGridPitch); return 1;}
        if (strcasecmp(str,"oacVerticalRouteGridOffset")==0) { result->SetData(oacVerticalRouteGridOffset); return 1;}
        if (strcasecmp(str,"oac135RouteGridPitch")==0) { result->SetData(oac135RouteGridPitch); return 1;}
        if (strcasecmp(str,"oac135RouteGridOffset")==0) { result->SetData(oac135RouteGridOffset); return 1;}
        if (strcasecmp(str,"oac45RouteGridPitch")==0) { result->SetData(oac45RouteGridPitch); return 1;}
        if (strcasecmp(str,"oac45RouteGridOffset")==0) { result->SetData(oac45RouteGridOffset); return 1;}
        if (strcasecmp(str,"oacErrorLayer")==0) { result->SetData(oacErrorLayer); return 1;}
        if (strcasecmp(str,"oacAntenna")==0) { result->SetData(oacAntenna); return 1;}
        if (strcasecmp(str,"oacMinLength")==0) { result->SetData(oacMinLength); return 1;}
        if (strcasecmp(str,"oacMaxLength")==0) { result->SetData(oacMaxLength); return 1;}
        if (strcasecmp(str,"oacDiagonalShapesAllowed")==0) { result->SetData(oacDiagonalShapesAllowed); return 1;}
        if (strcasecmp(str,"oacMaxTapSpacing")==0) { result->SetData(oacMaxTapSpacing); return 1;}
        if (strcasecmp(str,"oacMinBoundaryExtension")==0) { result->SetData(oacMinBoundaryExtension); return 1;}
        if (strcasecmp(str,"oacMinBoundaryInteriorHalo")==0) { result->SetData(oacMinBoundaryInteriorHalo); return 1;}
        if (strcasecmp(str,"oacMinWireExtension")==0) { result->SetData(oacMinWireExtension); return 1;}
        if (strcasecmp(str,"oacMinParallelViaSpacing")==0) { result->SetData(oacMinParallelViaSpacing); return 1;}
        if (strcasecmp(str,"oacMinEndOfLineSpacing")==0) { result->SetData(oacMinEndOfLineSpacing); return 1;}
        if (strcasecmp(str,"oacMinLargeViaArraySpacing")==0) { result->SetData(oacMinLargeViaArraySpacing); return 1;}
        if (strcasecmp(str,"oacMinLargeViaArrayWidth")==0) { result->SetData(oacMinLargeViaArrayWidth); return 1;}
        if (strcasecmp(str,"oacMinLargeViaArrayCutSpacing")==0) { result->SetData(oacMinLargeViaArrayCutSpacing); return 1;}
        if (strcasecmp(str,"oacRectangularLargeViaArraysAllowed")==0) { result->SetData(oacRectangularLargeViaArraysAllowed); return 1;}
        if (strcasecmp(str,"oacMinEdgeMaxCount")==0) { result->SetData(oacMinEdgeMaxCount); return 1;}
        if (strcasecmp(str,"oacMinEdgeAdjacentDistance")==0) { result->SetData(oacMinEdgeAdjacentDistance); return 1;}
        if (strcasecmp(str,"oacMaxDiagonalEdgeLength")==0) { result->SetData(oacMaxDiagonalEdgeLength); return 1;}
        if (strcasecmp(str,"oacMaxRoutingDistance")==0) { result->SetData(oacMaxRoutingDistance); return 1;}
        if (strcasecmp(str,"oacKeepAlignedShapeAndBoundary")==0) { result->SetData(oacKeepAlignedShapeAndBoundary); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerConstraintTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerConstraintTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerConstraintTypeEnum_FromoaLayerConstraintTypeEnum(oaLayerConstraintTypeEnum ob)
{
    if (ob==oacMinArea) return PyString_FromString("oacMinArea");
    if (ob==oacMinEnclosedArea) return PyString_FromString("oacMinEnclosedArea");
    if (ob==oacMinDensity) return PyString_FromString("oacMinDensity");
    if (ob==oacMaxDensity) return PyString_FromString("oacMaxDensity");
    if (ob==oacMinEdgeLength) return PyString_FromString("oacMinEdgeLength");
    if (ob==oacMinConcaveEdgeLength) return PyString_FromString("oacMinConcaveEdgeLength");
    if (ob==oacMinConvexEdgeLength) return PyString_FromString("oacMinConvexEdgeLength");
    if (ob==oacMinDiagonalEdgeLength) return PyString_FromString("oacMinDiagonalEdgeLength");
    if (ob==oacMinSpacing) return PyString_FromString("oacMinSpacing");
    if (ob==oacMinDiagonalSpacing) return PyString_FromString("oacMinDiagonalSpacing");
    if (ob==oacMinCenterToCenterSpacing) return PyString_FromString("oacMinCenterToCenterSpacing");
    if (ob==oacMinDiffPotentialSpacing) return PyString_FromString("oacMinDiffPotentialSpacing");
    if (ob==oacMinEnclosedSpacing) return PyString_FromString("oacMinEnclosedSpacing");
    if (ob==oacMinFillPatternSpacing) return PyString_FromString("oacMinFillPatternSpacing");
    if (ob==oacMinProximitySpacing) return PyString_FromString("oacMinProximitySpacing");
    if (ob==oacMinProtrudedProximitySpacing) return PyString_FromString("oacMinProtrudedProximitySpacing");
    if (ob==oacMinSameNetSpacing) return PyString_FromString("oacMinSameNetSpacing");
    if (ob==oacMinAdjacentViaSpacing) return PyString_FromString("oacMinAdjacentViaSpacing");
    if (ob==oacMergeSpaceAllowed) return PyString_FromString("oacMergeSpaceAllowed");
    if (ob==oacMinWidth) return PyString_FromString("oacMinWidth");
    if (ob==oacMinDiagonalWidth) return PyString_FromString("oacMinDiagonalWidth");
    if (ob==oacMinProtrusionWidth) return PyString_FromString("oacMinProtrusionWidth");
    if (ob==oacMaxWidth) return PyString_FromString("oacMaxWidth");
    if (ob==oacMinSize) return PyString_FromString("oacMinSize");
    if (ob==oacMinNumCut) return PyString_FromString("oacMinNumCut");
    if (ob==oacMinProtrusionNumCut) return PyString_FromString("oacMinProtrusionNumCut");
    if (ob==oacHorizontalRouteGridPitch) return PyString_FromString("oacHorizontalRouteGridPitch");
    if (ob==oacHorizontalRouteGridOffset) return PyString_FromString("oacHorizontalRouteGridOffset");
    if (ob==oacVerticalRouteGridPitch) return PyString_FromString("oacVerticalRouteGridPitch");
    if (ob==oacVerticalRouteGridOffset) return PyString_FromString("oacVerticalRouteGridOffset");
    if (ob==oac135RouteGridPitch) return PyString_FromString("oac135RouteGridPitch");
    if (ob==oac135RouteGridOffset) return PyString_FromString("oac135RouteGridOffset");
    if (ob==oac45RouteGridPitch) return PyString_FromString("oac45RouteGridPitch");
    if (ob==oac45RouteGridOffset) return PyString_FromString("oac45RouteGridOffset");
    if (ob==oacErrorLayer) return PyString_FromString("oacErrorLayer");
    if (ob==oacAntenna) return PyString_FromString("oacAntenna");
    if (ob==oacMinLength) return PyString_FromString("oacMinLength");
    if (ob==oacMaxLength) return PyString_FromString("oacMaxLength");
    if (ob==oacDiagonalShapesAllowed) return PyString_FromString("oacDiagonalShapesAllowed");
    if (ob==oacMaxTapSpacing) return PyString_FromString("oacMaxTapSpacing");
    if (ob==oacMinBoundaryExtension) return PyString_FromString("oacMinBoundaryExtension");
    if (ob==oacMinBoundaryInteriorHalo) return PyString_FromString("oacMinBoundaryInteriorHalo");
    if (ob==oacMinWireExtension) return PyString_FromString("oacMinWireExtension");
    if (ob==oacMinParallelViaSpacing) return PyString_FromString("oacMinParallelViaSpacing");
    if (ob==oacMinEndOfLineSpacing) return PyString_FromString("oacMinEndOfLineSpacing");
    if (ob==oacMinLargeViaArraySpacing) return PyString_FromString("oacMinLargeViaArraySpacing");
    if (ob==oacMinLargeViaArrayWidth) return PyString_FromString("oacMinLargeViaArrayWidth");
    if (ob==oacMinLargeViaArrayCutSpacing) return PyString_FromString("oacMinLargeViaArrayCutSpacing");
    if (ob==oacRectangularLargeViaArraysAllowed) return PyString_FromString("oacRectangularLargeViaArraysAllowed");
    if (ob==oacMinEdgeMaxCount) return PyString_FromString("oacMinEdgeMaxCount");
    if (ob==oacMinEdgeAdjacentDistance) return PyString_FromString("oacMinEdgeAdjacentDistance");
    if (ob==oacMaxDiagonalEdgeLength) return PyString_FromString("oacMaxDiagonalEdgeLength");
    if (ob==oacMaxRoutingDistance) return PyString_FromString("oacMaxRoutingDistance");
    if (ob==oacKeepAlignedShapeAndBoundary) return PyString_FromString("oacKeepAlignedShapeAndBoundary");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerConstraintTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerConstraintTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerConstraintTypeEnum_FromoaLayerConstraintTypeEnum(oaLayerConstraintTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerConstraintTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerConstraintTypeEnum_doc[] =
"Type convert function for enum: oaLayerConstraintTypeEnum";
                               
static PyMethodDef PyoaLayerConstraintTypeEnum_method =
  {"oaLayerConstraintTypeEnum",(PyCFunction)PyoaLayerConstraintTypeEnum_TypeFunction,METH_VARARGS,oaLayerConstraintTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerConstraintTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMinArea");
    PyDict_SetItemString(mod_dict,"oacMinArea",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEnclosedArea");
    PyDict_SetItemString(mod_dict,"oacMinEnclosedArea",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDensity");
    PyDict_SetItemString(mod_dict,"oacMinDensity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxDensity");
    PyDict_SetItemString(mod_dict,"oacMaxDensity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEdgeLength");
    PyDict_SetItemString(mod_dict,"oacMinEdgeLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinConcaveEdgeLength");
    PyDict_SetItemString(mod_dict,"oacMinConcaveEdgeLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinConvexEdgeLength");
    PyDict_SetItemString(mod_dict,"oacMinConvexEdgeLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDiagonalEdgeLength");
    PyDict_SetItemString(mod_dict,"oacMinDiagonalEdgeLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinSpacing");
    PyDict_SetItemString(mod_dict,"oacMinSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDiagonalSpacing");
    PyDict_SetItemString(mod_dict,"oacMinDiagonalSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinCenterToCenterSpacing");
    PyDict_SetItemString(mod_dict,"oacMinCenterToCenterSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDiffPotentialSpacing");
    PyDict_SetItemString(mod_dict,"oacMinDiffPotentialSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEnclosedSpacing");
    PyDict_SetItemString(mod_dict,"oacMinEnclosedSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinFillPatternSpacing");
    PyDict_SetItemString(mod_dict,"oacMinFillPatternSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinProximitySpacing");
    PyDict_SetItemString(mod_dict,"oacMinProximitySpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinProtrudedProximitySpacing");
    PyDict_SetItemString(mod_dict,"oacMinProtrudedProximitySpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinSameNetSpacing");
    PyDict_SetItemString(mod_dict,"oacMinSameNetSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinAdjacentViaSpacing");
    PyDict_SetItemString(mod_dict,"oacMinAdjacentViaSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMergeSpaceAllowed");
    PyDict_SetItemString(mod_dict,"oacMergeSpaceAllowed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinWidth");
    PyDict_SetItemString(mod_dict,"oacMinWidth",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDiagonalWidth");
    PyDict_SetItemString(mod_dict,"oacMinDiagonalWidth",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinProtrusionWidth");
    PyDict_SetItemString(mod_dict,"oacMinProtrusionWidth",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxWidth");
    PyDict_SetItemString(mod_dict,"oacMaxWidth",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinSize");
    PyDict_SetItemString(mod_dict,"oacMinSize",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinNumCut");
    PyDict_SetItemString(mod_dict,"oacMinNumCut",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinProtrusionNumCut");
    PyDict_SetItemString(mod_dict,"oacMinProtrusionNumCut",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHorizontalRouteGridPitch");
    PyDict_SetItemString(mod_dict,"oacHorizontalRouteGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHorizontalRouteGridOffset");
    PyDict_SetItemString(mod_dict,"oacHorizontalRouteGridOffset",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerticalRouteGridPitch");
    PyDict_SetItemString(mod_dict,"oacVerticalRouteGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerticalRouteGridOffset");
    PyDict_SetItemString(mod_dict,"oacVerticalRouteGridOffset",value);
    Py_DECREF(value);
    value=PyString_FromString("oac135RouteGridPitch");
    PyDict_SetItemString(mod_dict,"oac135RouteGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oac135RouteGridOffset");
    PyDict_SetItemString(mod_dict,"oac135RouteGridOffset",value);
    Py_DECREF(value);
    value=PyString_FromString("oac45RouteGridPitch");
    PyDict_SetItemString(mod_dict,"oac45RouteGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oac45RouteGridOffset");
    PyDict_SetItemString(mod_dict,"oac45RouteGridOffset",value);
    Py_DECREF(value);
    value=PyString_FromString("oacErrorLayer");
    PyDict_SetItemString(mod_dict,"oacErrorLayer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntenna");
    PyDict_SetItemString(mod_dict,"oacAntenna",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinLength");
    PyDict_SetItemString(mod_dict,"oacMinLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxLength");
    PyDict_SetItemString(mod_dict,"oacMaxLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDiagonalShapesAllowed");
    PyDict_SetItemString(mod_dict,"oacDiagonalShapesAllowed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxTapSpacing");
    PyDict_SetItemString(mod_dict,"oacMaxTapSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinBoundaryExtension");
    PyDict_SetItemString(mod_dict,"oacMinBoundaryExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinBoundaryInteriorHalo");
    PyDict_SetItemString(mod_dict,"oacMinBoundaryInteriorHalo",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinWireExtension");
    PyDict_SetItemString(mod_dict,"oacMinWireExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinParallelViaSpacing");
    PyDict_SetItemString(mod_dict,"oacMinParallelViaSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEndOfLineSpacing");
    PyDict_SetItemString(mod_dict,"oacMinEndOfLineSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinLargeViaArraySpacing");
    PyDict_SetItemString(mod_dict,"oacMinLargeViaArraySpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinLargeViaArrayWidth");
    PyDict_SetItemString(mod_dict,"oacMinLargeViaArrayWidth",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinLargeViaArrayCutSpacing");
    PyDict_SetItemString(mod_dict,"oacMinLargeViaArrayCutSpacing",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRectangularLargeViaArraysAllowed");
    PyDict_SetItemString(mod_dict,"oacRectangularLargeViaArraysAllowed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEdgeMaxCount");
    PyDict_SetItemString(mod_dict,"oacMinEdgeMaxCount",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEdgeAdjacentDistance");
    PyDict_SetItemString(mod_dict,"oacMinEdgeAdjacentDistance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxDiagonalEdgeLength");
    PyDict_SetItemString(mod_dict,"oacMaxDiagonalEdgeLength",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxRoutingDistance");
    PyDict_SetItemString(mod_dict,"oacMaxRoutingDistance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacKeepAlignedShapeAndBoundary");
    PyDict_SetItemString(mod_dict,"oacKeepAlignedShapeAndBoundary",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerConstraintTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerConstraintTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerConstraintTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayerHalo
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerHalo_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerHalo_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerHaloObject* self = (PyoaLayerHaloObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerHalo)
    {
        PyParamoaLayerHalo p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerHalo_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerHalo, Choices are:\n"
        "    (oaLayerHalo)\n"
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
oaLayerHalo_tp_dealloc(PyoaLayerHaloObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerHalo_tp_repr(PyObject *ob)
{
    PyParamoaLayerHalo value;
    int convert_status=PyoaLayerHalo_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaLayerHalo::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerHalo_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerHalo v1;
    PyParamoaLayerHalo v2;
    int convert_status1=PyoaLayerHalo_Convert(ob1,&v1);
    int convert_status2=PyoaLayerHalo_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerHalo_Convert(PyObject* ob,PyParamoaLayerHalo* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerHalo_Check(ob)) {
        result->SetData( (oaLayerHalo**) ((PyoaLayerHaloObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerHalo Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerHalo_FromoaLayerHalo(oaLayerHalo** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerHalo* data=*value;
        PyObject* bself = PyoaLayerHalo_Type.tp_alloc(&PyoaLayerHalo_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerHaloObject* self = (PyoaLayerHaloObject*)bself;
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
PyObject* PyoaLayerHalo_FromoaLayerHalo(oaLayerHalo* data)
{
    if (data) {
       PyObject* bself = PyoaLayerHalo_Type.tp_alloc(&PyoaLayerHalo_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerHaloObject* self = (PyoaLayerHaloObject*)bself;
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
static char oaLayerHalo_getLayerHeader_doc[] = 
"Class: oaLayerHalo, Function: getLayerHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getLayerHeader() const\n"
"    Signature: getLayerHeader|ptr-oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layerHeader for the layer of this blockage.\n"
;

static PyObject*
oaLayerHalo_getLayerHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHaloObject* self=(PyoaLayerHaloObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getLayerHeader());
        return PyoaLayerHeader_FromoaLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHalo_getLayerNum_doc[] = 
"Class: oaLayerHalo, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number associated with this blockage.\n"
;

static PyObject*
oaLayerHalo_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHaloObject* self=(PyoaLayerHaloObject*)ob;
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
static char oaLayerHalo_getOffsets_doc[] = 
"Class: oaLayerHalo, Function: getOffsets\n"
"  Paramegers: (oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void getOffsets(oaDist& left,oaDist& bottom,oaDist& right,oaDist& top) const\n"
"    Signature: getOffsets|void-void|ref-oaDist,ref-oaDist,ref-oaDist,ref-oaDist,\n"
"    BrowseData: 0,oaDist,oaDist,oaDist,oaDist\n"
"    This function returns the offsets for the halo of the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
;

static PyObject*
oaLayerHalo_getOffsets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHaloObject* self=(PyoaLayerHaloObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    PyParamoaDist p2;
    PyParamoaDist p3;
    PyParamoaDist p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaDist_Convert,&p1,
          &PyoaDist_Convert,&p2,
          &PyoaDist_Convert,&p3,
          &PyoaDist_Convert,&p4)) {
        data.DataCall()->getOffsets(p1.Data(),p2.Data(),p3.Data(),p4.Data());
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
static char oaLayerHalo_setLayerNum_doc[] = 
"Class: oaLayerHalo, Function: setLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setLayerNum(oaLayerNum layerNum)\n"
"    Signature: setLayerNum|void-void|simple-oaLayerNum,\n"
"    This function moves this blockage to the specified layer. The new layer is created if it does not exist. The old layer is deleted if it becomes empty. A layer may not be set on placement blockages.\n"
"    layerNum\n"
"    The layer number\n"
"    oacInvalidLayerForLayerBlockage\n"
;

static PyObject*
oaLayerHalo_setLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHaloObject* self=(PyoaLayerHaloObject*)ob;
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
static char oaLayerHalo_setOffsets_doc[] = 
"Class: oaLayerHalo, Function: setOffsets\n"
"  Paramegers: (oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void setOffsets(oaDist left,oaDist bottom,oaDist right,oaDist top)\n"
"    Signature: setOffsets|void-void|simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This function updates the offsets for the halo of the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
;

static PyObject*
oaLayerHalo_setOffsets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHaloObject* self=(PyoaLayerHaloObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    PyParamoaDist p2;
    PyParamoaDist p3;
    PyParamoaDist p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaDist_Convert,&p1,
          &PyoaDist_Convert,&p2,
          &PyoaDist_Convert,&p3,
          &PyoaDist_Convert,&p4)) {
        data.DataCall()->setOffsets(p1.Data(),p2.Data(),p3.Data(),p4.Data());
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
static char oaLayerHalo_isNull_doc[] =
"Class: oaLayerHalo, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerHalo_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerHalo data;
    int convert_status=PyoaLayerHalo_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerHalo_assign_doc[] = 
"Class: oaLayerHalo, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerHalo_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerHalo data;
  int convert_status=PyoaLayerHalo_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerHalo p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerHalo_Convert,&p1)) {
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

static PyMethodDef oaLayerHalo_methodlist[] = {
    {"getLayerHeader",(PyCFunction)oaLayerHalo_getLayerHeader,METH_VARARGS,oaLayerHalo_getLayerHeader_doc},
    {"getLayerNum",(PyCFunction)oaLayerHalo_getLayerNum,METH_VARARGS,oaLayerHalo_getLayerNum_doc},
    {"getOffsets",(PyCFunction)oaLayerHalo_getOffsets,METH_VARARGS,oaLayerHalo_getOffsets_doc},
    {"setLayerNum",(PyCFunction)oaLayerHalo_setLayerNum,METH_VARARGS,oaLayerHalo_setLayerNum_doc},
    {"setOffsets",(PyCFunction)oaLayerHalo_setOffsets,METH_VARARGS,oaLayerHalo_setOffsets_doc},
    {"isNull",(PyCFunction)oaLayerHalo_tp_isNull,METH_VARARGS,oaLayerHalo_isNull_doc},
    {"assign",(PyCFunction)oaLayerHalo_tp_assign,METH_VARARGS,oaLayerHalo_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerHalo_doc[] = 
"Class: oaLayerHalo\n"
"  A layer halo is a type of blockage associated with an instance or a master, representing an area on a given layer around the master's prBoundary. The shape of the halo is determined from the shape of the prBoundary of the master and the given offsets, and it is automatically updated to reflect changes in the master's prBoundary.\n"
"  Note that the oaLayerHalo object officially supports rectilinear boundaries only i.e. the owner, if it is an oaPRBoundary object should represent a rectilinear figure, or, if it is an explicit instance, the singleton oaPRBoundary for the instance master should be rectilinear. Clients can use an oaLayerBlockage object to describe a halo with a fixed shape which can be rectilinear or non-rectilinear.\n"
"Constructors:\n"
"  Paramegers: (oaLayerHalo)\n"
"    Calls: (const oaLayerHalo&)\n"
"    Signature: oaLayerHalo||cref-oaLayerHalo,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerHalo_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerHalo",
    sizeof(PyoaLayerHaloObject),
    0,
    (destructor)oaLayerHalo_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerHalo_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerHalo_tp_repr,	/* tp_repr */
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
    oaLayerHalo_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerHalo_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockage_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerHalo_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerHalo_static_create_doc[] = 
"Class: oaLayerHalo, Function: create\n"
"  Paramegers: (oaBlockObject,oaBlockageType,oaLayerNum)\n"
"    Calls: oaLayerHalo* create(oaBlockObject* owner,oaBlockageType type,oaLayerNum layer)\n"
"    Signature: create|ptr-oaLayerHalo|ptr-oaBlockObject,simple-oaBlockageType,simple-oaLayerNum,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This is the constructor for a layer halo.\n"
"    owner\n"
"    The instance or prBoundary around which to create the blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerHalo should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacInvalidBlockageOwner\n"
"  Paramegers: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist)\n"
"    Calls: oaLayerHalo* create(oaBlockObject* owner,oaBlockageType type,oaLayerNum layer,oaDist left)\n"
"    Signature: create|ptr-oaLayerHalo|ptr-oaBlockObject,simple-oaBlockageType,simple-oaLayerNum,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This is the constructor for a layer halo.\n"
"    owner\n"
"    The instance or prBoundary around which to create the blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerHalo should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacInvalidBlockageOwner\n"
"  Paramegers: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist)\n"
"    Calls: oaLayerHalo* create(oaBlockObject* owner,oaBlockageType type,oaLayerNum layer,oaDist left,oaDist bottom)\n"
"    Signature: create|ptr-oaLayerHalo|ptr-oaBlockObject,simple-oaBlockageType,simple-oaLayerNum,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This is the constructor for a layer halo.\n"
"    owner\n"
"    The instance or prBoundary around which to create the blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerHalo should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacInvalidBlockageOwner\n"
"  Paramegers: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist)\n"
"    Calls: oaLayerHalo* create(oaBlockObject* owner,oaBlockageType type,oaLayerNum layer,oaDist left,oaDist bottom,oaDist right)\n"
"    Signature: create|ptr-oaLayerHalo|ptr-oaBlockObject,simple-oaBlockageType,simple-oaLayerNum,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This is the constructor for a layer halo.\n"
"    owner\n"
"    The instance or prBoundary around which to create the blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerHalo should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacInvalidBlockageOwner\n"
"  Paramegers: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: oaLayerHalo* create(oaBlockObject* owner,oaBlockageType type,oaLayerNum layer,oaDist left,oaDist bottom,oaDist right,oaDist top)\n"
"    Signature: create|ptr-oaLayerHalo|ptr-oaBlockObject,simple-oaBlockageType,simple-oaLayerNum,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This is the constructor for a layer halo.\n"
"    owner\n"
"    The instance or prBoundary around which to create the blockage\n"
"    type\n"
"    The type of blockage to create. Note: an oaLayerHalo should not have a blockageType of oacPlacementBlockageType.\n"
"    layer\n"
"    The layer on which to create the blockage\n"
"    left\n"
"    The left offset for the halo\n"
"    bottom\n"
"    The bottom offset for the halo\n"
"    right\n"
"    The right offset for the halo\n"
"    top\n"
"    The top offset for the halo\n"
"    oacInvalidLayerForLayerBlockage\n"
"    oacInvalidTypeForLayerBlockage\n"
"    oacInvalidBlockageOwner\n"
;

static PyObject*
oaLayerHalo_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlockObject,oaBlockageType,oaLayerNum)
    {
        PyParamoaBlockObject p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlockObject_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerHalop result= (oaLayerHalo::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLayerHalo_FromoaLayerHalo(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist)
    {
        PyParamoaBlockObject p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlockObject_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerHalop result= (oaLayerHalo::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerHalo_FromoaLayerHalo(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist)
    {
        PyParamoaBlockObject p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlockObject_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerHalop result= (oaLayerHalo::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerHalo_FromoaLayerHalo(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist)
    {
        PyParamoaBlockObject p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaDist p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlockObject_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaDist_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerHalop result= (oaLayerHalo::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaLayerHalo_FromoaLayerHalo(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaBlockObject p1;
        PyParamoaBlockageType p2;
        PyParamoaLayerNum p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaDist p6;
        PyParamoaDist p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlockObject_Convert,&p1,
              &PyoaBlockageType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaDist_Convert,&p6,
              &PyoaDist_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLayerHalop result= (oaLayerHalo::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaLayerHalo_FromoaLayerHalo(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerHalo, function: create, Choices are:\n"
        "    (oaBlockObject,oaBlockageType,oaLayerNum)\n"
        "    (oaBlockObject,oaBlockageType,oaLayerNum,oaDist)\n"
        "    (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist)\n"
        "    (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist)\n"
        "    (oaBlockObject,oaBlockageType,oaLayerNum,oaDist,oaDist,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerHalo_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerHalo_static_create,METH_VARARGS,oaLayerHalo_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerHalo_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerHalo_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerHalo\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerHalo",
           (PyObject*)(&PyoaLayerHalo_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerHalo\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerHalo_Type.tp_dict;
    for(method=oaLayerHalo_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerHeaderObject* self = (PyoaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerHeader)
    {
        PyParamoaLayerHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerHeader, Choices are:\n"
        "    (oaLayerHeader)\n"
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
oaLayerHeader_tp_dealloc(PyoaLayerHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaLayerHeader value;
    int convert_status=PyoaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerHeader v1;
    PyParamoaLayerHeader v2;
    int convert_status1=PyoaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerHeader_Convert(PyObject* ob,PyParamoaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerHeader_Check(ob)) {
        result->SetData( (oaLayerHeader**) ((PyoaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerHeader_FromoaLayerHeader(oaLayerHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerHeader* data=*value;
        PyObject* bself = PyoaLayerHeader_Type.tp_alloc(&PyoaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerHeaderObject* self = (PyoaLayerHeaderObject*)bself;
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
PyObject* PyoaLayerHeader_FromoaLayerHeader(oaLayerHeader* data)
{
    if (data) {
       PyObject* bself = PyoaLayerHeader_Type.tp_alloc(&PyoaLayerHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerHeaderObject* self = (PyoaLayerHeaderObject*)bself;
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
static char oaLayerHeader_getBlockageBBox_doc[] = 
"Class: oaLayerHeader, Function: getBlockageBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getBlockageBBox(oaBox& bBox) const\n"
"    Signature: getBlockageBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the bBox which is the union of all the bBoxes of blockages on the layer represented by this layerHeader.\n"
"    bBox\n"
"    A reference to an oaBox object to be populated\n"
;

static PyObject*
oaLayerHeader_getBlockageBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getBlockageBBox(p1.Data());
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
static char oaLayerHeader_getBlockages_doc[] = 
"Class: oaLayerHeader, Function: getBlockages\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBlockage_oaLayerHeader getBlockages() const\n"
"    Signature: getBlockages|simple-oaCollection_oaBlockage_oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of blockages associated with the layer represented by this layerHeader.\n"
;

static PyObject*
oaLayerHeader_getBlockages(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBlockage_oaLayerHeader* result= new oaCollection_oaBlockage_oaLayerHeader(data.DataCall()->getBlockages());
        return PyoaCollection_oaBlockage_oaLayerHeader_FromoaCollection_oaBlockage_oaLayerHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getBlockagesIter_doc[] = 
"Class: oaLayerHeader, Function: getBlockagesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaBlockage getBlockagesIter() const\n"
"    Signature: getBlockagesIter|simple-oaIter_oaBlockage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of blockages associated with the layer represented by this layerHeader.\n"
;

static PyObject*
oaLayerHeader_getBlockagesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaBlockage* result= new oaIter_oaBlockage(data.DataCall()->getBlockages());
        return PyoaIter_oaBlockage_FromoaIter_oaBlockage(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getGuideBBox_doc[] = 
"Class: oaLayerHeader, Function: getGuideBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getGuideBBox(oaBox& bBox) const\n"
"    Signature: getGuideBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the bBox which is the union of all the bBoxes of guides that either begin or end on the layer represented by this layerHeader.\n"
"    bBox\n"
"    A reference to an oaBox object to be populated\n"
;

static PyObject*
oaLayerHeader_getGuideBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getGuideBBox(p1.Data());
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
static char oaLayerHeader_getGuides_doc[] = 
"Class: oaLayerHeader, Function: getGuides\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGuide_oaLayerHeader getGuides() const\n"
"    Signature: getGuides|simple-oaCollection_oaGuide_oaLayerHeader|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a collection of guides related to this layerHeader.\n"
"    Applications can customize the collection by passing the proper value for the filterFlags parameter. The default value for this parameter is oavGuideIterBeginAndEndLayers , which results in a collection of a unique set of guides that either begin or end on the layer represented by the layerHeader.\n"
"    Applications can also use oavGuideIterBeginLayer , which results in a collection of guides that begin on that layer, or they can use oavGuideIterEndLayer , which results in a collection of guides that only end on that layer.\n"
"    A bit-wise OR of oavGuideIterBeginLayer and oavGuideIterEndLayer results in the same behavior as oavGuideIterBeginAndEndLayers , which is the default value.\n"
"    filterFlags\n"
"    These flags represent the customization required by an application, as explained above.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaGuide_oaLayerHeader getGuides(oaUInt4 filterFlags) const\n"
"    Signature: getGuides|simple-oaCollection_oaGuide_oaLayerHeader|simple-oaUInt4,\n"
"    This function returns a collection of guides related to this layerHeader.\n"
"    Applications can customize the collection by passing the proper value for the filterFlags parameter. The default value for this parameter is oavGuideIterBeginAndEndLayers , which results in a collection of a unique set of guides that either begin or end on the layer represented by the layerHeader.\n"
"    Applications can also use oavGuideIterBeginLayer , which results in a collection of guides that begin on that layer, or they can use oavGuideIterEndLayer , which results in a collection of guides that only end on that layer.\n"
"    A bit-wise OR of oavGuideIterBeginLayer and oavGuideIterEndLayer results in the same behavior as oavGuideIterBeginAndEndLayers , which is the default value.\n"
"    filterFlags\n"
"    These flags represent the customization required by an application, as explained above.\n"
;

static PyObject*
oaLayerHeader_getGuides(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaGuide_oaLayerHeader* result= new oaCollection_oaGuide_oaLayerHeader(data.DataCall()->getGuides());
            return PyoaCollection_oaGuide_oaLayerHeader_FromoaCollection_oaGuide_oaLayerHeader(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaCollection_oaGuide_oaLayerHeader* result= new oaCollection_oaGuide_oaLayerHeader(data.DataCall()->getGuides(p1.Data()));
            return PyoaCollection_oaGuide_oaLayerHeader_FromoaCollection_oaGuide_oaLayerHeader(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerHeader, function: getGuides, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getGuidesIter_doc[] = 
"Class: oaLayerHeader, Function: getGuidesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGuide getGuidesIter() const\n"
"    Signature: getGuidesIter|simple-oaIter_oaGuide|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of guides related to this layerHeader.\n"
"    Applications can customize the collection by passing the proper value for the filterFlags parameter. The default value for this parameter is oavGuideIterBeginAndEndLayers , which results in a collection of a unique set of guides that either begin or end on the layer represented by the layerHeader.\n"
"    Applications can also use oavGuideIterBeginLayer , which results in a collection of guides that begin on that layer, or they can use oavGuideIterEndLayer , which results in a collection of guides that only end on that layer.\n"
"    A bit-wise OR of oavGuideIterBeginLayer and oavGuideIterEndLayer results in the same behavior as oavGuideIterBeginAndEndLayers , which is the default value.\n"
"    filterFlags\n"
"    These flags represent the customization required by an application, as explained above.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaIter_oaGuide getGuidesIter(oaUInt4 filterFlags) const\n"
"    Signature: getGuidesIter|simple-oaIter_oaGuide|simple-oaUInt4,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of guides related to this layerHeader.\n"
"    Applications can customize the collection by passing the proper value for the filterFlags parameter. The default value for this parameter is oavGuideIterBeginAndEndLayers , which results in a collection of a unique set of guides that either begin or end on the layer represented by the layerHeader.\n"
"    Applications can also use oavGuideIterBeginLayer , which results in a collection of guides that begin on that layer, or they can use oavGuideIterEndLayer , which results in a collection of guides that only end on that layer.\n"
"    A bit-wise OR of oavGuideIterBeginLayer and oavGuideIterEndLayer results in the same behavior as oavGuideIterBeginAndEndLayers , which is the default value.\n"
"    filterFlags\n"
"    These flags represent the customization required by an application, as explained above.\n"
;

static PyObject*
oaLayerHeader_getGuidesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaGuide* result= new oaIter_oaGuide(data.DataCall()->getGuides());
            return PyoaIter_oaGuide_FromoaIter_oaGuide(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaIter_oaGuide* result= new oaIter_oaGuide(data.DataCall()->getGuides(p1.Data()));
            return PyoaIter_oaGuide_FromoaIter_oaGuide(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerHeader, function: getGuidesIter, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getLPPHeaders_doc[] = 
"Class: oaLayerHeader, Function: getLPPHeaders\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaLPPHeader_oaLayerHeader getLPPHeaders() const\n"
"    Signature: getLPPHeaders|simple-oaCollection_oaLPPHeader_oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaLPPHeader objects related to this layerHeader. An oaLPPHeader is related to the oaLayerHeader if its layer is the same as the oaLayerHeader object.\n"
;

static PyObject*
oaLayerHeader_getLPPHeaders(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaLPPHeader_oaLayerHeader* result= new oaCollection_oaLPPHeader_oaLayerHeader(data.DataCall()->getLPPHeaders());
        return PyoaCollection_oaLPPHeader_oaLayerHeader_FromoaCollection_oaLPPHeader_oaLayerHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getLPPHeadersIter_doc[] = 
"Class: oaLayerHeader, Function: getLPPHeadersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaLPPHeader getLPPHeadersIter() const\n"
"    Signature: getLPPHeadersIter|simple-oaIter_oaLPPHeader|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaLPPHeader objects related to this layerHeader. An oaLPPHeader is related to the oaLayerHeader if its layer is the same as the oaLayerHeader object.\n"
;

static PyObject*
oaLayerHeader_getLPPHeadersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaLPPHeader* result= new oaIter_oaLPPHeader(data.DataCall()->getLPPHeaders());
        return PyoaIter_oaLPPHeader_FromoaIter_oaLPPHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getLayer_doc[] = 
"Class: oaLayerHeader, Function: getLayer\n"
"  Paramegers: ()\n"
"    Calls: oaLayer* getLayer() const\n"
"    Signature: getLayer|ptr-oaLayer|\n"
"    BrowseData: 1\n"
"    This function attempts to return the layer associated with the specified layerHeader. If the layerHeader cannot be bound, a NULL will be returned.\n"
"    This function returns the layer number associated with this layerHeader.\n"
;

static PyObject*
oaLayerHeader_getLayer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerp result= (data.DataCall()->getLayer());
        return PyoaLayer_FromoaLayer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getLayerNum_doc[] = 
"Class: oaLayerHeader, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number which this layerHeader represents.\n"
;

static PyObject*
oaLayerHeader_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
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
static char oaLayerHeader_getSteinerBBox_doc[] = 
"Class: oaLayerHeader, Function: getSteinerBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getSteinerBBox(oaBox& bBox) const\n"
"    Signature: getSteinerBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the bBox which is the union of all the bBoxes of steiners on the layer represented by this layerHeader.\n"
"    bBox\n"
"    A reference to an oaBox object to be populated\n"
;

static PyObject*
oaLayerHeader_getSteinerBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getSteinerBBox(p1.Data());
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
static char oaLayerHeader_getSteiners_doc[] = 
"Class: oaLayerHeader, Function: getSteiners\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaSteiner_oaLayerHeader getSteiners() const\n"
"    Signature: getSteiners|simple-oaCollection_oaSteiner_oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of steiners associated with the layer represented by this layerHeader.\n"
;

static PyObject*
oaLayerHeader_getSteiners(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaSteiner_oaLayerHeader* result= new oaCollection_oaSteiner_oaLayerHeader(data.DataCall()->getSteiners());
        return PyoaCollection_oaSteiner_oaLayerHeader_FromoaCollection_oaSteiner_oaLayerHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_getSteinersIter_doc[] = 
"Class: oaLayerHeader, Function: getSteinersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaSteiner getSteinersIter() const\n"
"    Signature: getSteinersIter|simple-oaIter_oaSteiner|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of steiners associated with the layer represented by this layerHeader.\n"
;

static PyObject*
oaLayerHeader_getSteinersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaSteiner* result= new oaIter_oaSteiner(data.DataCall()->getSteiners());
        return PyoaIter_oaSteiner_FromoaIter_oaSteiner(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerHeader_isBound_doc[] = 
"Class: oaLayerHeader, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this layerHeader is bound to its technology oaLayer object.\n"
;

static PyObject*
oaLayerHeader_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerHeaderObject* self=(PyoaLayerHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isBound());
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
static char oaLayerHeader_isNull_doc[] =
"Class: oaLayerHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerHeader data;
    int convert_status=PyoaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerHeader_assign_doc[] = 
"Class: oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerHeader data;
  int convert_status=PyoaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerHeader_Convert,&p1)) {
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

static PyMethodDef oaLayerHeader_methodlist[] = {
    {"getBlockageBBox",(PyCFunction)oaLayerHeader_getBlockageBBox,METH_VARARGS,oaLayerHeader_getBlockageBBox_doc},
    {"getBlockages",(PyCFunction)oaLayerHeader_getBlockages,METH_VARARGS,oaLayerHeader_getBlockages_doc},
    {"getBlockagesIter",(PyCFunction)oaLayerHeader_getBlockagesIter,METH_VARARGS,oaLayerHeader_getBlockagesIter_doc},
    {"getGuideBBox",(PyCFunction)oaLayerHeader_getGuideBBox,METH_VARARGS,oaLayerHeader_getGuideBBox_doc},
    {"getGuides",(PyCFunction)oaLayerHeader_getGuides,METH_VARARGS,oaLayerHeader_getGuides_doc},
    {"getGuidesIter",(PyCFunction)oaLayerHeader_getGuidesIter,METH_VARARGS,oaLayerHeader_getGuidesIter_doc},
    {"getLPPHeaders",(PyCFunction)oaLayerHeader_getLPPHeaders,METH_VARARGS,oaLayerHeader_getLPPHeaders_doc},
    {"getLPPHeadersIter",(PyCFunction)oaLayerHeader_getLPPHeadersIter,METH_VARARGS,oaLayerHeader_getLPPHeadersIter_doc},
    {"getLayer",(PyCFunction)oaLayerHeader_getLayer,METH_VARARGS,oaLayerHeader_getLayer_doc},
    {"getLayerNum",(PyCFunction)oaLayerHeader_getLayerNum,METH_VARARGS,oaLayerHeader_getLayerNum_doc},
    {"getSteinerBBox",(PyCFunction)oaLayerHeader_getSteinerBBox,METH_VARARGS,oaLayerHeader_getSteinerBBox_doc},
    {"getSteiners",(PyCFunction)oaLayerHeader_getSteiners,METH_VARARGS,oaLayerHeader_getSteiners_doc},
    {"getSteinersIter",(PyCFunction)oaLayerHeader_getSteinersIter,METH_VARARGS,oaLayerHeader_getSteinersIter_doc},
    {"isBound",(PyCFunction)oaLayerHeader_isBound,METH_VARARGS,oaLayerHeader_isBound_doc},
    {"isNull",(PyCFunction)oaLayerHeader_tp_isNull,METH_VARARGS,oaLayerHeader_isNull_doc},
    {"assign",(PyCFunction)oaLayerHeader_tp_assign,METH_VARARGS,oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerHeader_doc[] = 
"Class: oaLayerHeader\n"
"  The oaLayerHeader class implements persistent objects that are created and destroyed automatically on a need basis. The existence of an oaLayerHeader object indicates that the layer it represents is currently being used by a database object in some way in the design hierarchy. oaLayerHeader objects provide direct access to the collections of steiners, guides and blockages that use the layer they represent and provide indirect access to the collection of shapes that use that layer by providing a collection of oaLPPHeader objects that use the same layer as the oaLayerHeader object.\n"
"  The oaLayerHeader class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaLayerHeader)\n"
"    Calls: (const oaLayerHeader&)\n"
"    Signature: oaLayerHeader||cref-oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerHeader",
    sizeof(PyoaLayerHeaderObject),
    0,
    (destructor)oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerHeader_tp_repr,	/* tp_repr */
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
    oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerHeader_static_find_doc[] = 
"Class: oaLayerHeader, Function: find\n"
"  Paramegers: (oaBlock,oaLayerNum)\n"
"    Calls: oaLayerHeader* find(const oaBlock* block,oaLayerNum layerNum)\n"
"    Signature: find|ptr-oaLayerHeader|cptr-oaBlock,simple-oaLayerNum,\n"
"    This function searches the specified block looking for an layerHeader with the specified layer number. If the layerHeader is found, it is returned, otherwise NULL is returned.\n"
"    block\n"
"    A pointer to the oaBlock object in which to search\n"
"    layerNum\n"
"    The layer number which the layerHeader represents\n"
;

static PyObject*
oaLayerHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaLayerNum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaLayerNum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLayerHeaderp result= (oaLayerHeader::find(p1.Data(),p2.Data()));
        return PyoaLayerHeader_FromoaLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaLayerHeader_static_find,METH_VARARGS,oaLayerHeader_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerHeader",
           (PyObject*)(&PyoaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerHeader_Type.tp_dict;
    for(method=oaLayerHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerHeaderModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerHeaderModTypeEnum_Convert(PyObject* ob,PyParamoaLayerHeaderModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBindLayerHeaderModType")==0) { result->SetData(oacBindLayerHeaderModType); return 1;}
        if (strcasecmp(str,"oacUnbindLayerHeaderModType")==0) { result->SetData(oacUnbindLayerHeaderModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerHeaderModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerHeaderModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerHeaderModTypeEnum_FromoaLayerHeaderModTypeEnum(oaLayerHeaderModTypeEnum ob)
{
    if (ob==oacBindLayerHeaderModType) return PyString_FromString("oacBindLayerHeaderModType");
    if (ob==oacUnbindLayerHeaderModType) return PyString_FromString("oacUnbindLayerHeaderModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerHeaderModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerHeaderModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerHeaderModTypeEnum_FromoaLayerHeaderModTypeEnum(oaLayerHeaderModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerHeaderModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerHeaderModTypeEnum_doc[] =
"Type convert function for enum: oaLayerHeaderModTypeEnum";
                               
static PyMethodDef PyoaLayerHeaderModTypeEnum_method =
  {"oaLayerHeaderModTypeEnum",(PyCFunction)PyoaLayerHeaderModTypeEnum_TypeFunction,METH_VARARGS,oaLayerHeaderModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerHeaderModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBindLayerHeaderModType");
    PyDict_SetItemString(mod_dict,"oacBindLayerHeaderModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnbindLayerHeaderModType");
    PyDict_SetItemString(mod_dict,"oacUnbindLayerHeaderModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerHeaderModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerHeaderModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerHeaderModTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayerMap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerMap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerMapObject* self = (PyoaLayerMapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaLayerMap();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2)) {
            self->value =  new oaLayerMap(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerMap)
    {
        PyParamoaLayerMap p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerMap_Convert,&p1)) {
            self->value =  new oaLayerMap(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerMap, Choices are:\n"
        "    ()\n"
        "    (oaLayerNum,oaLayerNum)\n"
        "    (oaLayerMap)\n"
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
oaLayerMap_tp_dealloc(PyoaLayerMapObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_tp_repr(PyObject *ob)
{
    PyParamoaLayerMap value;
    int convert_status=PyoaLayerMap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaLayerMap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerMap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerMap v1;
    PyParamoaLayerMap v2;
    int convert_status1=PyoaLayerMap_Convert(ob1,&v1);
    int convert_status2=PyoaLayerMap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerMap_Convert(PyObject* ob,PyParamoaLayerMap* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerMap_Check(ob)) {
        result->SetData(  ((PyoaLayerMapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerMap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerMap_FromoaLayerMap(oaLayerMap* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerMap_Type.tp_alloc(&PyoaLayerMap_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerMapObject* self = (PyoaLayerMapObject*)bself;
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
PyObject* PyoaLayerMap_FromoaLayerMap(const oaLayerMap& data)
{
    PyObject* bself = PyoaLayerMap_Type.tp_alloc(&PyoaLayerMap_Type,0);
    if (bself == NULL) return bself;
    PyoaLayerMapObject* self = (PyoaLayerMapObject*)bself;
    self->value =  new oaLayerMap(data);
    self->borrow = 0;
    self->locks = NULL;
    return bself;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerMap_designLayer_doc[] = 
"Class: oaLayerMap, Function: designLayer\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum& designLayer()\n"
"    Signature: designLayer|ref-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the design layer number of this oaLayerMap. The layer number can be modified.\n"
;

static PyObject*
oaLayerMap_designLayer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerMap data;
    int convert_status=PyoaLayerMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerMapObject* self=(PyoaLayerMapObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum* result=&(data.DataCall()->designLayer());
        return PyoaLayerNum_FromoaLayerNum(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerMap_waferLayer_doc[] = 
"Class: oaLayerMap, Function: waferLayer\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum& waferLayer()\n"
"    Signature: waferLayer|ref-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the wafer layer number of this oaLayerMap. The layer number can be modified.\n"
;

static PyObject*
oaLayerMap_waferLayer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerMap data;
    int convert_status=PyoaLayerMap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerMapObject* self=(PyoaLayerMapObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum* result=&(data.DataCall()->waferLayer());
        return PyoaLayerNum_FromoaLayerNum(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLayerMap_assign_doc[] = 
"Class: oaLayerMap, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerMap_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerMap data;
  int convert_status=PyoaLayerMap_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerMap p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerMap_Convert,&p1)) {
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

static PyMethodDef oaLayerMap_methodlist[] = {
    {"designLayer",(PyCFunction)oaLayerMap_designLayer,METH_VARARGS,oaLayerMap_designLayer_doc},
    {"waferLayer",(PyCFunction)oaLayerMap_waferLayer,METH_VARARGS,oaLayerMap_waferLayer_doc},
    {"assign",(PyCFunction)oaLayerMap_tp_assign,METH_VARARGS,oaLayerMap_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerMap_doc[] = 
"Class: oaLayerMap\n"
"  The oaLayerMap is an utility object which is used to map a wafer layer number to the corresponding layer number in the oaDesign associated with the design instance.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLayerMap()\n"
"    Signature: oaLayerMap||\n"
"    This is the default constructor for the oaLayerMap class. It initializes both the wafer layer number and design layer number to be zero\n"
"  Paramegers: (oaLayerNum,oaLayerNum)\n"
"    Calls: oaLayerMap(oaLayerNum waferLayer,oaLayerNum designLayer)\n"
"    Signature: oaLayerMap||simple-oaLayerNum,simple-oaLayerNum,\n"
"    This is the constructor for the oaLayerMap class.\n"
"    waferLayer\n"
"    The wafer layer number\n"
"    designLayer\n"
"    The design layer number\n"
"  Paramegers: (oaLayerMap)\n"
"    Calls: oaLayerMap(const oaLayerMap& layerMap)\n"
"    Signature: oaLayerMap||cref-oaLayerMap,\n"
"    This is the copy constructor for the oaLayerMap class.\n"
"    layerMap\n"
"  Paramegers: (oaLayerMap)\n"
"    Calls: (const oaLayerMap&)\n"
"    Signature: oaLayerMap||cref-oaLayerMap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerMap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerMap",
    sizeof(PyoaLayerMapObject),
    0,
    (destructor)oaLayerMap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerMap_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerMap_tp_repr,	/* tp_repr */
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
    oaLayerMap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerMap_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerMap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerMap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerMap_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerMap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerMap",
           (PyObject*)(&PyoaLayerMap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerMap\n");
       return -1;
    }
    return 0;
}


// ==================================================================
// Array for class: oaLayerMap
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerMap_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaLayerMap_ArrayObject* self = (PyoaLayerMap_ArrayObject*)gself;
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
    /* Case: (oaLayerMap_Array) */
    {
        PyParamoaLayerMap_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerMap_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerMap_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaLayerMap_Array)\n"
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
oaLayerMap_Array_dealloc(PyObject* gself)
{
    PyoaLayerMap_ArrayObject* self = (PyoaLayerMap_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_Array_str(PyObject *ob)
{
    PyParamoaLayerMap_Array value;
    int convert_status=PyoaLayerMap_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaLayerMap_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_Array_repr(PyObject *ob)
{
    PyParamoaLayerMap_Array value;
    int convert_status=PyoaLayerMap_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaLayerMap_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaLayerMap_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerMap_Array p1;
    PyParamoaLayerMap_Array p2;
    int s1=PyoaLayerMap_Array_Convert(ob1,&p1);
    int s2=PyoaLayerMap_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaLayerMap_Array_CreateList(p1);
    PyObject* l2=PyoaLayerMap_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaLayerMap_Array_Convert(PyObject* ob,PyParamoaLayerMap_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaLayerMap_Array_Check(ob)) {
    PyoaLayerMap_ArrayObject* self = (PyoaLayerMap_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaLayerMap data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaLayerMap_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaLayerMap data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaLayerMap_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaLayerMap_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaLayerMap_Array_FromoaLayerMap_Array(const oaLayerMap_Array& value)
{
  PyObject* gself = PyoaLayerMap_Array_Type.tp_alloc(&PyoaLayerMap_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaLayerMap_ArrayObject* self = (PyoaLayerMap_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaLayerMap_Array_FromoaLayerMap_Array(PyTypeoaLayerMap* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaLayerMap_Array_Type.tp_alloc(&PyoaLayerMap_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaLayerMap_ArrayObject* self = (PyoaLayerMap_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaLayerMap_Array_CreateList(PyParamoaLayerMap_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaLayerMap_FromoaLayerMap(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaLayerMap_Array_assign_doc[] = 
"Class: oaLayerMap_Array, Function: assign\n"
"  Paramegers: (oaLayerMap_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaLayerMap_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaLayerMap_ArrayObject* self=(PyoaLayerMap_ArrayObject*)ob;
  try {
    PyParamoaLayerMap_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerMap_Array_Convert,&p1)) {
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
static char oaLayerMap_Array_list_doc[] = 
"Class: oaLayerMap_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaLayerMap_Array_list(PyObject* ob, PyObject *args)
{
  PyoaLayerMap_ArrayObject* self=(PyoaLayerMap_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaLayerMap_Array_CreateList(self->data);
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
static PyMethodDef oaLayerMap_Array_methodlist[] = {
    {"assign",(PyCFunction)oaLayerMap_Array_assign,METH_VARARGS,oaLayerMap_Array_assign_doc},
    {"list",(PyCFunction)oaLayerMap_Array_list,METH_VARARGS,oaLayerMap_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaLayerMap_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaLayerMap_ArrayObject* self=(PyoaLayerMap_ArrayObject*)ob;
  try {
    PyParamoaLayerMap_Array data;
    int convert_status=PyoaLayerMap_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaLayerMap_FromoaLayerMap(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaLayerMap_Array_index_get_length(PyObject* ob)
{
    PyParamoaLayerMap_Array data;
    int convert_status=PyoaLayerMap_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaLayerMap_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaLayerMap_Array data;
    PyParamoaLayerMap dataitem;
    int convert_status=PyoaLayerMap_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaLayerMap_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaLayerMap_Array_doc[] =
"Class: oaLayerMap_Array\n"
"  The oaLayerMap_Array utility class provides an array of oaLayerMap.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLayerMap_Array()\n"
"    Signature: oaLayerMap_Array||\n"
"    This is the default constructor for the oaLayerMap_Array class. This constructor creates an empty oaLayerMap_Array.\n"
"  Paramegers: (oaLayerMap_Array)\n"
"    Calls: (const oaLayerMap_Array&)\n"
"    Signature: oaLayerMap_Array||cref-oaLayerMap_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaLayerMap_Array_as_sequence = {
    (Pyoa_inquiry)oaLayerMap_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaLayerMap_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaLayerMap_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaLayerMap_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerMap_Array",
    sizeof(PyoaLayerMap_ArrayObject),
    0,
    oaLayerMap_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaLayerMap_Array_compare,    /* tp_compare */
    oaLayerMap_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaLayerMap_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaLayerMap_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLayerMap_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaLayerMap_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaLayerMap_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaLayerMap_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerMap_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerMap_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaLayerMap_Array",
           (PyObject*)(&PyoaLayerMap_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerMap_Array\n");
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
// Wrapper Implementation for Class: oaLayerMapArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerMapArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerMapArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerMapArrayObject* self = (PyoaLayerMapArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaLayerMapArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaLayerMapArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerMapArray)
    {
        PyParamoaLayerMapArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerMapArray_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerMap*)  new oaLayerMapArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerMapArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaLayerMapArray)\n"
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
oaLayerMapArray_tp_dealloc(PyoaLayerMapArrayObject* self)
{
    if (!self->borrow) {
        delete (oaLayerMapArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerMapArray_tp_repr(PyObject *ob)
{
    PyParamoaLayerMapArray value;
    int convert_status=PyoaLayerMapArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaLayerMapArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerMapArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerMapArray v1;
    PyParamoaLayerMapArray v2;
    int convert_status1=PyoaLayerMapArray_Convert(ob1,&v1);
    int convert_status2=PyoaLayerMapArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerMapArray_Convert(PyObject* ob,PyParamoaLayerMapArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerMapArray_Check(ob)) {
        result->SetData( (oaLayerMapArray*) ((PyoaLayerMapArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerMapArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerMapArray_FromoaLayerMapArray(oaLayerMapArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerMapArray_Type.tp_alloc(&PyoaLayerMapArray_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerMapArrayObject* self = (PyoaLayerMapArrayObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerMapArray_doc[] = 
"Class: oaLayerMapArray\n"
"  The oaLayerMapArray implements an array of layer mappings. This is an utility class. Its primary usage is to allow user to specify a mapping from the various wafer layer numbers to the corresponding layer number for a design instance.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLayerMapArray()\n"
"    Signature: oaLayerMapArray||simple-oaUInt4,\n"
"    This is the default constructor for the oaLayerMapArray class.\n"
"    size\n"
"    The size of this layerMapArray\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaLayerMapArray(oaUInt4 size)\n"
"    Signature: oaLayerMapArray||simple-oaUInt4,\n"
"    This is the default constructor for the oaLayerMapArray class.\n"
"    size\n"
"    The size of this layerMapArray\n"
"  Paramegers: (oaLayerMapArray)\n"
"    Calls: oaLayerMapArray(const oaLayerMapArray& layers)\n"
"    Signature: oaLayerMapArray||cref-oaLayerMapArray,\n"
"    This is the copy constructor for the oaLayerMapArray class.\n"
"    layers\n"
"  Paramegers: (oaLayerMapArray)\n"
"    Calls: (const oaLayerMapArray&)\n"
"    Signature: oaLayerMapArray||cref-oaLayerMapArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerMapArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerMapArray",
    sizeof(PyoaLayerMapArrayObject),
    0,
    (destructor)oaLayerMapArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerMapArray_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerMapArray_tp_repr,	/* tp_repr */
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
    oaLayerMapArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaLayerMap_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerMapArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerMapArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerMapArray_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerMapArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerMapArray",
           (PyObject*)(&PyoaLayerMapArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerMapArray\n");
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
// Wrapper Implementation for Class: oaLayerModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerModTypeEnum_Convert(PyObject* ob,PyParamoaLayerModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNumberLayerModType")==0) { result->SetData(oacSetNumberLayerModType); return 1;}
        if (strcasecmp(str,"oacSetNameLayerModType")==0) { result->SetData(oacSetNameLayerModType); return 1;}
        if (strcasecmp(str,"oacPhysicalLayerSetMaterialLayerModType")==0) { result->SetData(oacPhysicalLayerSetMaterialLayerModType); return 1;}
        if (strcasecmp(str,"oacPhysicalLayerSetPrefRoutingDirLayerModType")==0) { result->SetData(oacPhysicalLayerSetPrefRoutingDirLayerModType); return 1;}
        if (strcasecmp(str,"oacPhysicalLayerSetMaskNumberLayerModType")==0) { result->SetData(oacPhysicalLayerSetMaskNumberLayerModType); return 1;}
        if (strcasecmp(str,"oacPhysicalLayerSetManufacturingGridLayerModType")==0) { result->SetData(oacPhysicalLayerSetManufacturingGridLayerModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(oaLayerModTypeEnum ob)
{
    if (ob==oacSetNumberLayerModType) return PyString_FromString("oacSetNumberLayerModType");
    if (ob==oacSetNameLayerModType) return PyString_FromString("oacSetNameLayerModType");
    if (ob==oacPhysicalLayerSetMaterialLayerModType) return PyString_FromString("oacPhysicalLayerSetMaterialLayerModType");
    if (ob==oacPhysicalLayerSetPrefRoutingDirLayerModType) return PyString_FromString("oacPhysicalLayerSetPrefRoutingDirLayerModType");
    if (ob==oacPhysicalLayerSetMaskNumberLayerModType) return PyString_FromString("oacPhysicalLayerSetMaskNumberLayerModType");
    if (ob==oacPhysicalLayerSetManufacturingGridLayerModType) return PyString_FromString("oacPhysicalLayerSetManufacturingGridLayerModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(oaLayerModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerModTypeEnum_doc[] =
"Type convert function for enum: oaLayerModTypeEnum";
                               
static PyMethodDef PyoaLayerModTypeEnum_method =
  {"oaLayerModTypeEnum",(PyCFunction)PyoaLayerModTypeEnum_TypeFunction,METH_VARARGS,oaLayerModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNumberLayerModType");
    PyDict_SetItemString(mod_dict,"oacSetNumberLayerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetNameLayerModType");
    PyDict_SetItemString(mod_dict,"oacSetNameLayerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPhysicalLayerSetMaterialLayerModType");
    PyDict_SetItemString(mod_dict,"oacPhysicalLayerSetMaterialLayerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPhysicalLayerSetPrefRoutingDirLayerModType");
    PyDict_SetItemString(mod_dict,"oacPhysicalLayerSetPrefRoutingDirLayerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPhysicalLayerSetMaskNumberLayerModType");
    PyDict_SetItemString(mod_dict,"oacPhysicalLayerSetMaskNumberLayerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPhysicalLayerSetManufacturingGridLayerModType");
    PyDict_SetItemString(mod_dict,"oacPhysicalLayerSetManufacturingGridLayerModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerModTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayerOp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerOp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerOp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerOpObject* self = (PyoaLayerOpObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerOpEnum)
    {
        PyParamoaLayerOpEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerOpEnum_Convert,&p1)) {
            self->value =  new oaLayerOp(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLayerOp(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerOp)
    {
        PyParamoaLayerOp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerOp_Convert,&p1)) {
            self->value= new oaLayerOp(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerOp, Choices are:\n"
        "    (oaLayerOpEnum)\n"
        "    (oaString)\n"
        "    (oaLayerOp)\n"
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
oaLayerOp_tp_dealloc(PyoaLayerOpObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerOp_tp_repr(PyObject *ob)
{
    PyParamoaLayerOp value;
    int convert_status=PyoaLayerOp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[31];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLayerOp::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerOp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerOp v1;
    PyParamoaLayerOp v2;
    int convert_status1=PyoaLayerOp_Convert(ob1,&v1);
    int convert_status2=PyoaLayerOp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerOp_Convert(PyObject* ob,PyParamoaLayerOp* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerOp_Check(ob)) {
        result->SetData(  ((PyoaLayerOpObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerOp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerOp_FromoaLayerOp(oaLayerOp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerOp_Type.tp_alloc(&PyoaLayerOp_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerOpObject* self = (PyoaLayerOpObject*)bself;
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
static char oaLayerOp_getName_doc[] = 
"Class: oaLayerOp, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaLayerOpEnum object.\n"
;

static PyObject*
oaLayerOp_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerOp data;
    int convert_status=PyoaLayerOp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerOpObject* self=(PyoaLayerOpObject*)ob;

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
static char oaLayerOp_oaLayerOpEnum_doc[] = 
"Class: oaLayerOp, Function: oaLayerOpEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerOpEnum oaLayerOpEnum() const\n"
"    Signature: operator oaLayerOpEnum|simple-oaLayerOpEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaLayerOp object into the corresponding #oaLayerOpEnum value.\n"
;

static PyObject*
oaLayerOp_oaLayerOpEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerOp data;
    int convert_status=PyoaLayerOp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerOpObject* self=(PyoaLayerOpObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerOpEnum result= (data.DataCall()->operator oaLayerOpEnum());
        return PyoaLayerOpEnum_FromoaLayerOpEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLayerOp_assign_doc[] = 
"Class: oaLayerOp, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerOp_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerOp data;
  int convert_status=PyoaLayerOp_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerOp p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerOp_Convert,&p1)) {
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

static PyMethodDef oaLayerOp_methodlist[] = {
    {"getName",(PyCFunction)oaLayerOp_getName,METH_VARARGS,oaLayerOp_getName_doc},
    {"oaLayerOpEnum",(PyCFunction)oaLayerOp_oaLayerOpEnum,METH_VARARGS,oaLayerOp_oaLayerOpEnum_doc},
    {"assign",(PyCFunction)oaLayerOp_tp_assign,METH_VARARGS,oaLayerOp_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerOp_doc[] = 
"Class: oaLayerOp\n"
"  The oaLayerOp class encapsulates the enumerated values that describe the different uses of a derived layer object.\n"
"  oaLayerOpEnum\n"
"Constructors:\n"
"  Paramegers: (oaLayerOpEnum)\n"
"    Calls: oaLayerOp(oaLayerOpEnum valueIn)\n"
"    Signature: oaLayerOp||simple-oaLayerOpEnum,\n"
"    This function constructs an instance of an oaLayerOp class using the specified #oaLayerOpEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLayerOp(const oaString& name)\n"
"    Signature: oaLayerOp||cref-oaString,\n"
"    This function constructs an instance of an oaLayerOp class using the #oaLayerOpEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaLayerOpEnum.\n"
"    oacInvalidLayerOpName\n"
"  Paramegers: (oaLayerOp)\n"
"    Calls: (const oaLayerOp&)\n"
"    Signature: oaLayerOp||cref-oaLayerOp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerOp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerOp",
    sizeof(PyoaLayerOpObject),
    0,
    (destructor)oaLayerOp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerOp_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerOp_tp_repr,	/* tp_repr */
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
    oaLayerOp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerOp_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerOp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerOp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerOp_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerOp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerOp",
           (PyObject*)(&PyoaLayerOp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerOp\n");
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
// Wrapper Implementation for Class: oaLayerOpEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerOpEnum_Convert(PyObject* ob,PyParamoaLayerOpEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacAndLayerOp")==0) { result->SetData(oacAndLayerOp); return 1;}
        if (strcasecmp(str,"oacOrLayerOp")==0) { result->SetData(oacOrLayerOp); return 1;}
        if (strcasecmp(str,"oacNotLayerOp")==0) { result->SetData(oacNotLayerOp); return 1;}
        if (strcasecmp(str,"oacXorLayerOp")==0) { result->SetData(oacXorLayerOp); return 1;}
        if (strcasecmp(str,"oacTouchingLayerOp")==0) { result->SetData(oacTouchingLayerOp); return 1;}
        if (strcasecmp(str,"oacButtOnlyLayerOp")==0) { result->SetData(oacButtOnlyLayerOp); return 1;}
        if (strcasecmp(str,"oacUserDefinedLayerOp")==0) { result->SetData(oacUserDefinedLayerOp); return 1;}
        if (strcasecmp(str,"oacInsideLayerOp")==0) { result->SetData(oacInsideLayerOp); return 1;}
        if (strcasecmp(str,"oacOutsideLayerOp")==0) { result->SetData(oacOutsideLayerOp); return 1;}
        if (strcasecmp(str,"oacOverlappingLayerOp")==0) { result->SetData(oacOverlappingLayerOp); return 1;}
        if (strcasecmp(str,"oacStraddlingLayerOp")==0) { result->SetData(oacStraddlingLayerOp); return 1;}
        if (strcasecmp(str,"oacAvoidingLayerOp")==0) { result->SetData(oacAvoidingLayerOp); return 1;}
        if (strcasecmp(str,"oacButtingLayerOp")==0) { result->SetData(oacButtingLayerOp); return 1;}
        if (strcasecmp(str,"oacCoincidentLayerOp")==0) { result->SetData(oacCoincidentLayerOp); return 1;}
        if (strcasecmp(str,"oacCoincidentOnlyLayerOp")==0) { result->SetData(oacCoincidentOnlyLayerOp); return 1;}
        if (strcasecmp(str,"oacEnclosingLayerOp")==0) { result->SetData(oacEnclosingLayerOp); return 1;}
        if (strcasecmp(str,"oacButtingOrCoincidentLayerOp")==0) { result->SetData(oacButtingOrCoincidentLayerOp); return 1;}
        if (strcasecmp(str,"oacButtingOrOverlappingLayerOp")==0) { result->SetData(oacButtingOrOverlappingLayerOp); return 1;}
        if (strcasecmp(str,"oacAreaLayerOp")==0) { result->SetData(oacAreaLayerOp); return 1;}
        if (strcasecmp(str,"oacGrowLayerOp")==0) { result->SetData(oacGrowLayerOp); return 1;}
        if (strcasecmp(str,"oacShrinkLayerOp")==0) { result->SetData(oacShrinkLayerOp); return 1;}
        if (strcasecmp(str,"oacGrowVerticalLayerOp")==0) { result->SetData(oacGrowVerticalLayerOp); return 1;}
        if (strcasecmp(str,"oacGrowHorizontalLayerOp")==0) { result->SetData(oacGrowHorizontalLayerOp); return 1;}
        if (strcasecmp(str,"oacShrinkVerticalLayerOp")==0) { result->SetData(oacShrinkVerticalLayerOp); return 1;}
        if (strcasecmp(str,"oacShrinkHorizontalLayerOp")==0) { result->SetData(oacShrinkHorizontalLayerOp); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerOpEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerOpEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerOpEnum_FromoaLayerOpEnum(oaLayerOpEnum ob)
{
    if (ob==oacAndLayerOp) return PyString_FromString("oacAndLayerOp");
    if (ob==oacOrLayerOp) return PyString_FromString("oacOrLayerOp");
    if (ob==oacNotLayerOp) return PyString_FromString("oacNotLayerOp");
    if (ob==oacXorLayerOp) return PyString_FromString("oacXorLayerOp");
    if (ob==oacTouchingLayerOp) return PyString_FromString("oacTouchingLayerOp");
    if (ob==oacButtOnlyLayerOp) return PyString_FromString("oacButtOnlyLayerOp");
    if (ob==oacUserDefinedLayerOp) return PyString_FromString("oacUserDefinedLayerOp");
    if (ob==oacInsideLayerOp) return PyString_FromString("oacInsideLayerOp");
    if (ob==oacOutsideLayerOp) return PyString_FromString("oacOutsideLayerOp");
    if (ob==oacOverlappingLayerOp) return PyString_FromString("oacOverlappingLayerOp");
    if (ob==oacStraddlingLayerOp) return PyString_FromString("oacStraddlingLayerOp");
    if (ob==oacAvoidingLayerOp) return PyString_FromString("oacAvoidingLayerOp");
    if (ob==oacButtingLayerOp) return PyString_FromString("oacButtingLayerOp");
    if (ob==oacCoincidentLayerOp) return PyString_FromString("oacCoincidentLayerOp");
    if (ob==oacCoincidentOnlyLayerOp) return PyString_FromString("oacCoincidentOnlyLayerOp");
    if (ob==oacEnclosingLayerOp) return PyString_FromString("oacEnclosingLayerOp");
    if (ob==oacButtingOrCoincidentLayerOp) return PyString_FromString("oacButtingOrCoincidentLayerOp");
    if (ob==oacButtingOrOverlappingLayerOp) return PyString_FromString("oacButtingOrOverlappingLayerOp");
    if (ob==oacAreaLayerOp) return PyString_FromString("oacAreaLayerOp");
    if (ob==oacGrowLayerOp) return PyString_FromString("oacGrowLayerOp");
    if (ob==oacShrinkLayerOp) return PyString_FromString("oacShrinkLayerOp");
    if (ob==oacGrowVerticalLayerOp) return PyString_FromString("oacGrowVerticalLayerOp");
    if (ob==oacGrowHorizontalLayerOp) return PyString_FromString("oacGrowHorizontalLayerOp");
    if (ob==oacShrinkVerticalLayerOp) return PyString_FromString("oacShrinkVerticalLayerOp");
    if (ob==oacShrinkHorizontalLayerOp) return PyString_FromString("oacShrinkHorizontalLayerOp");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerOpEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerOpEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerOpEnum_FromoaLayerOpEnum(oaLayerOpEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerOpEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerOpEnum_doc[] =
"Type convert function for enum: oaLayerOpEnum";
                               
static PyMethodDef PyoaLayerOpEnum_method =
  {"oaLayerOpEnum",(PyCFunction)PyoaLayerOpEnum_TypeFunction,METH_VARARGS,oaLayerOpEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerOpEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacAndLayerOp");
    PyDict_SetItemString(mod_dict,"oacAndLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOrLayerOp");
    PyDict_SetItemString(mod_dict,"oacOrLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNotLayerOp");
    PyDict_SetItemString(mod_dict,"oacNotLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacXorLayerOp");
    PyDict_SetItemString(mod_dict,"oacXorLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTouchingLayerOp");
    PyDict_SetItemString(mod_dict,"oacTouchingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacButtOnlyLayerOp");
    PyDict_SetItemString(mod_dict,"oacButtOnlyLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUserDefinedLayerOp");
    PyDict_SetItemString(mod_dict,"oacUserDefinedLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInsideLayerOp");
    PyDict_SetItemString(mod_dict,"oacInsideLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOutsideLayerOp");
    PyDict_SetItemString(mod_dict,"oacOutsideLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOverlappingLayerOp");
    PyDict_SetItemString(mod_dict,"oacOverlappingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStraddlingLayerOp");
    PyDict_SetItemString(mod_dict,"oacStraddlingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAvoidingLayerOp");
    PyDict_SetItemString(mod_dict,"oacAvoidingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacButtingLayerOp");
    PyDict_SetItemString(mod_dict,"oacButtingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCoincidentLayerOp");
    PyDict_SetItemString(mod_dict,"oacCoincidentLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCoincidentOnlyLayerOp");
    PyDict_SetItemString(mod_dict,"oacCoincidentOnlyLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEnclosingLayerOp");
    PyDict_SetItemString(mod_dict,"oacEnclosingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacButtingOrCoincidentLayerOp");
    PyDict_SetItemString(mod_dict,"oacButtingOrCoincidentLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacButtingOrOverlappingLayerOp");
    PyDict_SetItemString(mod_dict,"oacButtingOrOverlappingLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAreaLayerOp");
    PyDict_SetItemString(mod_dict,"oacAreaLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGrowLayerOp");
    PyDict_SetItemString(mod_dict,"oacGrowLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacShrinkLayerOp");
    PyDict_SetItemString(mod_dict,"oacShrinkLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGrowVerticalLayerOp");
    PyDict_SetItemString(mod_dict,"oacGrowVerticalLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGrowHorizontalLayerOp");
    PyDict_SetItemString(mod_dict,"oacGrowHorizontalLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacShrinkVerticalLayerOp");
    PyDict_SetItemString(mod_dict,"oacShrinkVerticalLayerOp",value);
    Py_DECREF(value);
    value=PyString_FromString("oacShrinkHorizontalLayerOp");
    PyDict_SetItemString(mod_dict,"oacShrinkHorizontalLayerOp",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerOpEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerOpEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerOpEnum\n");
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
// Wrapper Implementation for Class: oaLayerPairConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerPairConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerPairConstraintObject* self = (PyoaLayerPairConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerPairConstraint)
    {
        PyParamoaLayerPairConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerPairConstraint_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerPairConstraint, Choices are:\n"
        "    (oaLayerPairConstraint)\n"
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
oaLayerPairConstraint_tp_dealloc(PyoaLayerPairConstraintObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraint_tp_repr(PyObject *ob)
{
    PyParamoaLayerPairConstraint value;
    int convert_status=PyoaLayerPairConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaLayerPairConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerPairConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerPairConstraint v1;
    PyParamoaLayerPairConstraint v2;
    int convert_status1=PyoaLayerPairConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaLayerPairConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerPairConstraint_Convert(PyObject* ob,PyParamoaLayerPairConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerPairConstraint_Check(ob)) {
        result->SetData( (oaLayerPairConstraint**) ((PyoaLayerPairConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerPairConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerPairConstraint_FromoaLayerPairConstraint(oaLayerPairConstraint** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerPairConstraint* data=*value;
        PyObject* bself = PyoaLayerPairConstraint_Type.tp_alloc(&PyoaLayerPairConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerPairConstraintObject* self = (PyoaLayerPairConstraintObject*)bself;
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
PyObject* PyoaLayerPairConstraint_FromoaLayerPairConstraint(oaLayerPairConstraint* data)
{
    if (data) {
       PyObject* bself = PyoaLayerPairConstraint_Type.tp_alloc(&PyoaLayerPairConstraint_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerPairConstraintObject* self = (PyoaLayerPairConstraintObject*)bself;
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
static char oaLayerPairConstraint_getLayer1_doc[] = 
"Class: oaLayerPairConstraint, Function: getLayer1\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayer1() const\n"
"    Signature: getLayer1|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the first layer associated with this constraint.\n"
;

static PyObject*
oaLayerPairConstraint_getLayer1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraint data;
    int convert_status=PyoaLayerPairConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerPairConstraintObject* self=(PyoaLayerPairConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayer1());
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
static char oaLayerPairConstraint_getLayer2_doc[] = 
"Class: oaLayerPairConstraint, Function: getLayer2\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayer2() const\n"
"    Signature: getLayer2|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the second layer associated with this constraint.\n"
;

static PyObject*
oaLayerPairConstraint_getLayer2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraint data;
    int convert_status=PyoaLayerPairConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerPairConstraintObject* self=(PyoaLayerPairConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayer2());
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
static char oaLayerPairConstraint_isNull_doc[] =
"Class: oaLayerPairConstraint, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerPairConstraint_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerPairConstraint data;
    int convert_status=PyoaLayerPairConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerPairConstraint_assign_doc[] = 
"Class: oaLayerPairConstraint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerPairConstraint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerPairConstraint data;
  int convert_status=PyoaLayerPairConstraint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerPairConstraint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerPairConstraint_Convert,&p1)) {
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

static PyMethodDef oaLayerPairConstraint_methodlist[] = {
    {"getLayer1",(PyCFunction)oaLayerPairConstraint_getLayer1,METH_VARARGS,oaLayerPairConstraint_getLayer1_doc},
    {"getLayer2",(PyCFunction)oaLayerPairConstraint_getLayer2,METH_VARARGS,oaLayerPairConstraint_getLayer2_doc},
    {"isNull",(PyCFunction)oaLayerPairConstraint_tp_isNull,METH_VARARGS,oaLayerPairConstraint_isNull_doc},
    {"assign",(PyCFunction)oaLayerPairConstraint_tp_assign,METH_VARARGS,oaLayerPairConstraint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerPairConstraint_doc[] = 
"Class: oaLayerPairConstraint\n"
"  The oaLayerPairConstraint class represents a constraint object that constrains interactions between two ordered layers. In addition to the layers, the oaLayerPairConstraint is described by its oaLayerPairConstraintDef . A layerPair constraint has a value associated with it and potentially a list of constraint parameters. A layerPair constraint may or may not be a hard constraint. A hard constraint is a constraint that must be met.\n"
"  oaLayerPairConstraints always have a value, and are created in the same database as that value. oaLayerPairConstraints get applied to objects by being placed in an oaConstraintGroup .\n"
"Constructors:\n"
"  Paramegers: (oaLayerPairConstraint)\n"
"    Calls: (const oaLayerPairConstraint&)\n"
"    Signature: oaLayerPairConstraint||cref-oaLayerPairConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerPairConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerPairConstraint",
    sizeof(PyoaLayerPairConstraintObject),
    0,
    (destructor)oaLayerPairConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerPairConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerPairConstraint_tp_repr,	/* tp_repr */
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
    oaLayerPairConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerPairConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerPairConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerPairConstraint_static_create_doc[] = 
"Class: oaLayerPairConstraint, Function: create\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,oaValue* value)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,const oaString& name,oaValue* value)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaLayerPairConstraint* create(oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaLayerPairConstraint|simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    layer1\n"
"    Layer associated with constraint.\n"
"    layer2\n"
"    Second layer associated with a constraint.\n"
"    def\n"
"    Layer pair constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
;

static PyObject*
oaLayerPairConstraint_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaValue p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaValue_Convert,&p4)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaValue p4;
        PyParamoaBoolean p5;
        PyParamoaConstraintParamArray p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaValue_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaConstraintParamArray_ConvertAof,&p6)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaString p4;
        PyParamoaValue p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaValue_Convert,&p5)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p5.Data(),5)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaString p4;
        PyParamoaValue p5;
        PyParamoaBoolean p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaValue_Convert,&p5,
              &PyoaBoolean_Convert,&p6)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p5.Data(),5)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaLayerNum p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerPairConstraintDef p3;
        PyParamoaString p4;
        PyParamoaValue p5;
        PyParamoaBoolean p6;
        PyParamoaConstraintParamArray p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaLayerNum_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerPairConstraintDef_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaValue_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaConstraintParamArray_ConvertAof,&p7)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p5.Data(),5)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.DataAof()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerPairConstraint, function: create, Choices are:\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue)\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean)\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue)\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean)\n"
        "    (oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerPairConstraint_static_find_doc[] = 
"Class: oaLayerPairConstraint, Function: find\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
"    Calls: oaLayerPairConstraint* find(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def)\n"
"    Signature: find|ptr-oaLayerPairConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in this group that matches the definition, and layers specified. If no such constraint is found NULL is returned.\n"
"    group\n"
"    Group to search\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to search for\n"
"    hard\n"
"    Boolean indicating whether or not the constraint to be searched for is hard or soft\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaBoolean)\n"
"    Calls: oaLayerPairConstraint* find(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def,oaBoolean hardOnly)\n"
"    Signature: find|ptr-oaLayerPairConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in this group that matches the definition, and layers specified. If no such constraint is found NULL is returned.\n"
"    group\n"
"    Group to search\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to search for\n"
"    hard\n"
"    Boolean indicating whether or not the constraint to be searched for is hard or soft\n"
;

static PyObject*
oaLayerPairConstraint_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        PyParamoaLayerPairConstraintDef p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaLayerPairConstraintDef_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::find(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        PyParamoaLayerPairConstraintDef p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaLayerPairConstraintDef_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaLayerPairConstraintp result= (oaLayerPairConstraint::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerPairConstraint, function: find, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerPairConstraint_static_getConstraints_doc[] = 
"Class: oaLayerPairConstraint, Function: getConstraints\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum)\n"
"    Calls: oaCollection_oaLayerPairConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerPairConstraint_oaConstraintGroup|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,\n"
"    This function returns a collection of layer pair constraints in the specified group whose definition matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    Constraint group to search in\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to filter with\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
"    Calls: oaCollection_oaLayerPairConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def)\n"
"    Signature: getConstraints|simple-oaCollection_oaLayerPairConstraint_oaConstraintGroup|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,\n"
"    This function returns a collection of layer pair constraints in the specified group whose definition matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    Constraint group to search in\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to filter with\n"
;

static PyObject*
oaLayerPairConstraint_static_getConstraints(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaCollection_oaLayerPairConstraint_oaConstraintGroup* result= new oaCollection_oaLayerPairConstraint_oaConstraintGroup(oaLayerPairConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_FromoaCollection_oaLayerPairConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        PyParamoaLayerPairConstraintDef p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaLayerPairConstraintDef_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaCollection_oaLayerPairConstraint_oaConstraintGroup* result= new oaCollection_oaLayerPairConstraint_oaConstraintGroup(oaLayerPairConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_FromoaCollection_oaLayerPairConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerPairConstraint, function: getConstraints, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerPairConstraint_static_getConstraintsIter_doc[] = 
"Class: oaLayerPairConstraint, Function: getConstraintsIter\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum)\n"
"    Calls: oaIter_oaLayerPairConstraint getConstraintsIter(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerPairConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer pair constraints in the specified group whose definition matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    Constraint group to search in\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to filter with\n"
"  Paramegers: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
"    Calls: oaIter_oaLayerPairConstraint getConstraintsIter(const oaConstraintGroup* group,oaLayerNum layer1,oaLayerNum layer2,const oaLayerPairConstraintDef* def)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaLayerPairConstraint|cptr-oaConstraintGroup,simple-oaLayerNum,simple-oaLayerNum,cptr-oaLayerPairConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of layer pair constraints in the specified group whose definition matches the one given. If no definition is specified, all layer constraints on that layer in that group are returned.\n"
"    group\n"
"    Constraint group to search in\n"
"    layer1\n"
"    First layer to search for\n"
"    layer2\n"
"    Second layer to search for\n"
"    def\n"
"    Layer pair constraint definition to filter with\n"
;

static PyObject*
oaLayerPairConstraint_static_getConstraintsIter(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaIter_oaLayerPairConstraint* result= new oaIter_oaLayerPairConstraint(oaLayerPairConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data()));
            return PyoaIter_oaLayerPairConstraint_FromoaIter_oaLayerPairConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaLayerNum p2;
        PyParamoaLayerNum p3;
        PyParamoaLayerPairConstraintDef p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaLayerPairConstraintDef_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaIter_oaLayerPairConstraint* result= new oaIter_oaLayerPairConstraint(oaLayerPairConstraint::getConstraints(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaIter_oaLayerPairConstraint_FromoaIter_oaLayerPairConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerPairConstraint, function: getConstraintsIter, Choices are:\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum)\n"
        "    (oaConstraintGroup,oaLayerNum,oaLayerNum,oaLayerPairConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerPairConstraint_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerPairConstraint_static_create,METH_VARARGS,oaLayerPairConstraint_static_create_doc},
    {"static_find",(PyCFunction)oaLayerPairConstraint_static_find,METH_VARARGS,oaLayerPairConstraint_static_find_doc},
    {"static_getConstraints",(PyCFunction)oaLayerPairConstraint_static_getConstraints,METH_VARARGS,oaLayerPairConstraint_static_getConstraints_doc},
    {"static_getConstraintsIter",(PyCFunction)oaLayerPairConstraint_static_getConstraintsIter,METH_VARARGS,oaLayerPairConstraint_static_getConstraintsIter_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerPairConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerPairConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerPairConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerPairConstraint",
           (PyObject*)(&PyoaLayerPairConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerPairConstraint\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerPairConstraint_Type.tp_dict;
    for(method=oaLayerPairConstraint_staticmethodlist;method->ml_name!=NULL;method++) {
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

