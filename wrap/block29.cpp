
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
// Wrapper Implementation for Class: oaIter_oaBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaBusTermBitObject* self = (PyoaIter_oaBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaBusTermBit)
    {
        PyParamoaIter_oaBusTermBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaBusTermBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaBusTermBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaBusTermBit)\n"
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
oaIter_oaBusTermBit_tp_dealloc(PyoaIter_oaBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaBusTermBit value;
    int convert_status=PyoaIter_oaBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaBusTermBit v1;
    PyParamoaIter_oaBusTermBit v2;
    int convert_status1=PyoaIter_oaBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaBusTermBit ob;
    int convert_status=PyoaIter_oaBusTermBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaBusTermBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaBusTermBit_FromoaBusTermBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaBusTermBit_Convert(PyObject* ob,PyParamoaIter_oaBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaBusTermBit_Check(ob)) {
        result->SetData( (oaIter_oaBusTermBit*) ((PyoaIter_oaBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaBusTermBit_FromoaIter_oaBusTermBit(oaIter_oaBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaBusTermBit_Type.tp_alloc(&PyoaIter_oaBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaBusTermBitObject* self = (PyoaIter_oaBusTermBitObject*)bself;
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
static char oaIter_oaBusTermBit_getNext_doc[] = 
"Class: oaIter_oaBusTermBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaBusTermBit* getNext()\n"
"    Signature: getNext|ptr-oaBusTermBit|\n"
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
oaIter_oaBusTermBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaBusTermBit data;
    int convert_status=PyoaIter_oaBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaBusTermBitObject* self=(PyoaIter_oaBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermBitp result= (data.DataCall()->getNext());
        return PyoaBusTermBit_FromoaBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaBusTermBit_next_doc[] = 
"Class: oaIter_oaBusTermBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaBusTermBit* next()\n"
"    Signature: next|ptr-oaBusTermBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaBusTermBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaBusTermBit data;
    int convert_status=PyoaIter_oaBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaBusTermBitObject* self=(PyoaIter_oaBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaBusTermBit_FromoaBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaBusTermBit_assign_doc[] = 
"Class: oaIter_oaBusTermBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaBusTermBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaBusTermBit data;
  int convert_status=PyoaIter_oaBusTermBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaBusTermBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaBusTermBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaBusTermBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaBusTermBit_getNext,METH_VARARGS,oaIter_oaBusTermBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaBusTermBit_next,METH_VARARGS,oaIter_oaBusTermBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaBusTermBit_tp_assign,METH_VARARGS,oaIter_oaBusTermBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaBusTermBit_doc[] = 
"Class: oaIter_oaBusTermBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaBusTermBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaBusTermBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaBusTermBit)\n"
"    Calls: oaIter_oaBusTermBit(const oaIter_oaBusTermBit& iterIn)\n"
"    Signature: oaIter_oaBusTermBit||cref-oaIter_oaBusTermBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaBusTermBit)\n"
"    Calls: (const oaIter_oaBusTermBit&)\n"
"    Signature: oaIter_oaBusTermBit||cref-oaIter_oaBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaBusTermBit",
    sizeof(PyoaIter_oaBusTermBitObject),
    0,
    (destructor)oaIter_oaBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaBusTermBit_tp_repr,	/* tp_repr */
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
    oaIter_oaBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaBusTermBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaBusTermBit_iternext,	/* tp_iternext */
    oaIter_oaBusTermBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaBusTermBit",
           (PyObject*)(&PyoaIter_oaBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaBusTermBit\n");
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
// Wrapper Implementation for Class: oaIter_oaBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaBusTermDefObject* self = (PyoaIter_oaBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaBusTermDef)
    {
        PyParamoaIter_oaBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaBusTermDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaBusTermDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaBusTermDef)\n"
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
oaIter_oaBusTermDef_tp_dealloc(PyoaIter_oaBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaBusTermDef value;
    int convert_status=PyoaIter_oaBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaBusTermDef v1;
    PyParamoaIter_oaBusTermDef v2;
    int convert_status1=PyoaIter_oaBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaBusTermDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaBusTermDef ob;
    int convert_status=PyoaIter_oaBusTermDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaBusTermDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaBusTermDef_FromoaBusTermDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaBusTermDef_Convert(PyObject* ob,PyParamoaIter_oaBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaBusTermDef_Check(ob)) {
        result->SetData( (oaIter_oaBusTermDef*) ((PyoaIter_oaBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaBusTermDef_FromoaIter_oaBusTermDef(oaIter_oaBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaBusTermDef_Type.tp_alloc(&PyoaIter_oaBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaBusTermDefObject* self = (PyoaIter_oaBusTermDefObject*)bself;
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
static char oaIter_oaBusTermDef_getNext_doc[] = 
"Class: oaIter_oaBusTermDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaBusTermDef* getNext()\n"
"    Signature: getNext|ptr-oaBusTermDef|\n"
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
oaIter_oaBusTermDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaBusTermDef data;
    int convert_status=PyoaIter_oaBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaBusTermDefObject* self=(PyoaIter_oaBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermDefp result= (data.DataCall()->getNext());
        return PyoaBusTermDef_FromoaBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaBusTermDef_next_doc[] = 
"Class: oaIter_oaBusTermDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaBusTermDef* next()\n"
"    Signature: next|ptr-oaBusTermDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaBusTermDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaBusTermDef data;
    int convert_status=PyoaIter_oaBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaBusTermDefObject* self=(PyoaIter_oaBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaBusTermDef_FromoaBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaBusTermDef_assign_doc[] = 
"Class: oaIter_oaBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaBusTermDef data;
  int convert_status=PyoaIter_oaBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaBusTermDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaBusTermDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaBusTermDef_getNext,METH_VARARGS,oaIter_oaBusTermDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaBusTermDef_next,METH_VARARGS,oaIter_oaBusTermDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaBusTermDef_tp_assign,METH_VARARGS,oaIter_oaBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaBusTermDef_doc[] = 
"Class: oaIter_oaBusTermDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaBusTermDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaBusTermDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaBusTermDef)\n"
"    Calls: oaIter_oaBusTermDef(const oaIter_oaBusTermDef& iterIn)\n"
"    Signature: oaIter_oaBusTermDef||cref-oaIter_oaBusTermDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaBusTermDef)\n"
"    Calls: (const oaIter_oaBusTermDef&)\n"
"    Signature: oaIter_oaBusTermDef||cref-oaIter_oaBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaBusTermDef",
    sizeof(PyoaIter_oaBusTermDefObject),
    0,
    (destructor)oaIter_oaBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaBusTermDef_tp_repr,	/* tp_repr */
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
    oaIter_oaBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaBusTermDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaBusTermDef_iternext,	/* tp_iternext */
    oaIter_oaBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaBusTermDef",
           (PyObject*)(&PyoaIter_oaBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaBusTermDef\n");
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
// Wrapper Implementation for Class: oaIter_oaCell
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCell_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaCell_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaCellObject* self = (PyoaIter_oaCellObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCell(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaCell)
    {
        PyParamoaIter_oaCell p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaCell_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCell(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaCell, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaCell)\n"
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
oaIter_oaCell_tp_dealloc(PyoaIter_oaCellObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaCell*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCell_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaCell value;
    int convert_status=PyoaIter_oaCell_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaCell::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaCell_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaCell v1;
    PyParamoaIter_oaCell v2;
    int convert_status1=PyoaIter_oaCell_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaCell_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaCell_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCell_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaCell ob;
    int convert_status=PyoaIter_oaCell_Convert(self,&ob);
    assert(convert_status!=0);
    oaCell* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaCell_FromoaCell(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaCell_Convert(PyObject* ob,PyParamoaIter_oaCell* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaCell_Check(ob)) {
        result->SetData( (oaIter_oaCell*) ((PyoaIter_oaCellObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaCell Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaCell_FromoaIter_oaCell(oaIter_oaCell* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaCell_Type.tp_alloc(&PyoaIter_oaCell_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaCellObject* self = (PyoaIter_oaCellObject*)bself;
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
static char oaIter_oaCell_getNext_doc[] = 
"Class: oaIter_oaCell, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaCell* getNext()\n"
"    Signature: getNext|ptr-oaCell|\n"
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
oaIter_oaCell_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCell data;
    int convert_status=PyoaIter_oaCell_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaCellObject* self=(PyoaIter_oaCellObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCellp result= (data.DataCall()->getNext());
        return PyoaCell_FromoaCell(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaCell_next_doc[] = 
"Class: oaIter_oaCell, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaCell* next()\n"
"    Signature: next|ptr-oaCell|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaCell_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCell data;
    int convert_status=PyoaIter_oaCell_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaCellObject* self=(PyoaIter_oaCellObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCellp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaCell_FromoaCell(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaCell_assign_doc[] = 
"Class: oaIter_oaCell, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaCell_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaCell data;
  int convert_status=PyoaIter_oaCell_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaCell p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaCell_Convert,&p1)) {
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

static PyMethodDef oaIter_oaCell_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaCell_getNext,METH_VARARGS,oaIter_oaCell_getNext_doc},
    {"next",(PyCFunction)oaIter_oaCell_next,METH_VARARGS,oaIter_oaCell_next_doc},
    {"assign",(PyCFunction)oaIter_oaCell_tp_assign,METH_VARARGS,oaIter_oaCell_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaCell_doc[] = 
"Class: oaIter_oaCell\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaCell(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaCell||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaCell)\n"
"    Calls: oaIter_oaCell(const oaIter_oaCell& iterIn)\n"
"    Signature: oaIter_oaCell||cref-oaIter_oaCell,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaCell)\n"
"    Calls: (const oaIter_oaCell&)\n"
"    Signature: oaIter_oaCell||cref-oaIter_oaCell,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaCell_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaCell",
    sizeof(PyoaIter_oaCellObject),
    0,
    (destructor)oaIter_oaCell_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaCell_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaCell_tp_repr,	/* tp_repr */
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
    oaIter_oaCell_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaCell_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaCell_iternext,	/* tp_iternext */
    oaIter_oaCell_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaCell_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaCell_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaCell_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaCell\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaCell",
           (PyObject*)(&PyoaIter_oaCell_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaCell\n");
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
// Wrapper Implementation for Class: oaIter_oaCellView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCellView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaCellView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaCellViewObject* self = (PyoaIter_oaCellViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCellView(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaCellView)
    {
        PyParamoaIter_oaCellView p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaCellView_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCellView(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaCellView, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaCellView)\n"
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
oaIter_oaCellView_tp_dealloc(PyoaIter_oaCellViewObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaCellView*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCellView_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaCellView value;
    int convert_status=PyoaIter_oaCellView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaIter_oaCellView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaCellView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaCellView v1;
    PyParamoaIter_oaCellView v2;
    int convert_status1=PyoaIter_oaCellView_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaCellView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaCellView_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCellView_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaCellView ob;
    int convert_status=PyoaIter_oaCellView_Convert(self,&ob);
    assert(convert_status!=0);
    oaCellView* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaCellView_FromoaCellView(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaCellView_Convert(PyObject* ob,PyParamoaIter_oaCellView* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaCellView_Check(ob)) {
        result->SetData( (oaIter_oaCellView*) ((PyoaIter_oaCellViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaCellView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaCellView_FromoaIter_oaCellView(oaIter_oaCellView* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaCellView_Type.tp_alloc(&PyoaIter_oaCellView_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaCellViewObject* self = (PyoaIter_oaCellViewObject*)bself;
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
static char oaIter_oaCellView_getNext_doc[] = 
"Class: oaIter_oaCellView, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaCellView* getNext()\n"
"    Signature: getNext|ptr-oaCellView|\n"
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
oaIter_oaCellView_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCellView data;
    int convert_status=PyoaIter_oaCellView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaCellViewObject* self=(PyoaIter_oaCellViewObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCellViewp result= (data.DataCall()->getNext());
        return PyoaCellView_FromoaCellView(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaCellView_next_doc[] = 
"Class: oaIter_oaCellView, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaCellView* next()\n"
"    Signature: next|ptr-oaCellView|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaCellView_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCellView data;
    int convert_status=PyoaIter_oaCellView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaCellViewObject* self=(PyoaIter_oaCellViewObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCellViewp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaCellView_FromoaCellView(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaCellView_assign_doc[] = 
"Class: oaIter_oaCellView, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaCellView_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaCellView data;
  int convert_status=PyoaIter_oaCellView_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaCellView p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaCellView_Convert,&p1)) {
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

static PyMethodDef oaIter_oaCellView_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaCellView_getNext,METH_VARARGS,oaIter_oaCellView_getNext_doc},
    {"next",(PyCFunction)oaIter_oaCellView_next,METH_VARARGS,oaIter_oaCellView_next_doc},
    {"assign",(PyCFunction)oaIter_oaCellView_tp_assign,METH_VARARGS,oaIter_oaCellView_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaCellView_doc[] = 
"Class: oaIter_oaCellView\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaCellView(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaCellView||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaCellView)\n"
"    Calls: oaIter_oaCellView(const oaIter_oaCellView& iterIn)\n"
"    Signature: oaIter_oaCellView||cref-oaIter_oaCellView,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaCellView)\n"
"    Calls: (const oaIter_oaCellView&)\n"
"    Signature: oaIter_oaCellView||cref-oaIter_oaCellView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaCellView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaCellView",
    sizeof(PyoaIter_oaCellViewObject),
    0,
    (destructor)oaIter_oaCellView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaCellView_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaCellView_tp_repr,	/* tp_repr */
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
    oaIter_oaCellView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaCellView_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaCellView_iternext,	/* tp_iternext */
    oaIter_oaCellView_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaCellView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaCellView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaCellView_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaCellView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaCellView",
           (PyObject*)(&PyoaIter_oaCellView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaCellView\n");
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
// Wrapper Implementation for Class: oaIter_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaClusterObject* self = (PyoaIter_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaCluster)
    {
        PyParamoaIter_oaCluster p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaCluster_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaCluster, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaCluster)\n"
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
oaIter_oaCluster_tp_dealloc(PyoaIter_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaCluster value;
    int convert_status=PyoaIter_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaCluster v1;
    PyParamoaIter_oaCluster v2;
    int convert_status1=PyoaIter_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaCluster_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaCluster_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaCluster ob;
    int convert_status=PyoaIter_oaCluster_Convert(self,&ob);
    assert(convert_status!=0);
    oaCluster* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaCluster_FromoaCluster(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaCluster_Convert(PyObject* ob,PyParamoaIter_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaCluster_Check(ob)) {
        result->SetData( (oaIter_oaCluster*) ((PyoaIter_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaCluster_FromoaIter_oaCluster(oaIter_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaCluster_Type.tp_alloc(&PyoaIter_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaClusterObject* self = (PyoaIter_oaClusterObject*)bself;
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
static char oaIter_oaCluster_getNext_doc[] = 
"Class: oaIter_oaCluster, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaCluster* getNext()\n"
"    Signature: getNext|ptr-oaCluster|\n"
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
oaIter_oaCluster_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCluster data;
    int convert_status=PyoaIter_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaClusterObject* self=(PyoaIter_oaClusterObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterp result= (data.DataCall()->getNext());
        return PyoaCluster_FromoaCluster(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaCluster_next_doc[] = 
"Class: oaIter_oaCluster, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaCluster* next()\n"
"    Signature: next|ptr-oaCluster|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaCluster_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaCluster data;
    int convert_status=PyoaIter_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaClusterObject* self=(PyoaIter_oaClusterObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaCluster_FromoaCluster(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaCluster_assign_doc[] = 
"Class: oaIter_oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaCluster data;
  int convert_status=PyoaIter_oaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaCluster_Convert,&p1)) {
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

static PyMethodDef oaIter_oaCluster_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaCluster_getNext,METH_VARARGS,oaIter_oaCluster_getNext_doc},
    {"next",(PyCFunction)oaIter_oaCluster_next,METH_VARARGS,oaIter_oaCluster_next_doc},
    {"assign",(PyCFunction)oaIter_oaCluster_tp_assign,METH_VARARGS,oaIter_oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaCluster_doc[] = 
"Class: oaIter_oaCluster\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaCluster(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaCluster||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaCluster)\n"
"    Calls: oaIter_oaCluster(const oaIter_oaCluster& iterIn)\n"
"    Signature: oaIter_oaCluster||cref-oaIter_oaCluster,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaCluster)\n"
"    Calls: (const oaIter_oaCluster&)\n"
"    Signature: oaIter_oaCluster||cref-oaIter_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaCluster",
    sizeof(PyoaIter_oaClusterObject),
    0,
    (destructor)oaIter_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaCluster_tp_repr,	/* tp_repr */
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
    oaIter_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaCluster_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaCluster_iternext,	/* tp_iternext */
    oaIter_oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaCluster",
           (PyObject*)(&PyoaIter_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaCluster\n");
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
// Wrapper Implementation for Class: oaIter_oaClusterBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaClusterBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaClusterBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaClusterBoundaryObject* self = (PyoaIter_oaClusterBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaClusterBoundary(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaClusterBoundary)
    {
        PyParamoaIter_oaClusterBoundary p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaClusterBoundary_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaClusterBoundary(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaClusterBoundary, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaClusterBoundary)\n"
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
oaIter_oaClusterBoundary_tp_dealloc(PyoaIter_oaClusterBoundaryObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaClusterBoundary*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaClusterBoundary_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaClusterBoundary value;
    int convert_status=PyoaIter_oaClusterBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaClusterBoundary::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaClusterBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaClusterBoundary v1;
    PyParamoaIter_oaClusterBoundary v2;
    int convert_status1=PyoaIter_oaClusterBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaClusterBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaClusterBoundary_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaClusterBoundary_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaClusterBoundary ob;
    int convert_status=PyoaIter_oaClusterBoundary_Convert(self,&ob);
    assert(convert_status!=0);
    oaClusterBoundary* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaClusterBoundary_FromoaClusterBoundary(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaClusterBoundary_Convert(PyObject* ob,PyParamoaIter_oaClusterBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaClusterBoundary_Check(ob)) {
        result->SetData( (oaIter_oaClusterBoundary*) ((PyoaIter_oaClusterBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaClusterBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaClusterBoundary_FromoaIter_oaClusterBoundary(oaIter_oaClusterBoundary* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaClusterBoundary_Type.tp_alloc(&PyoaIter_oaClusterBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaClusterBoundaryObject* self = (PyoaIter_oaClusterBoundaryObject*)bself;
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
static char oaIter_oaClusterBoundary_getNext_doc[] = 
"Class: oaIter_oaClusterBoundary, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaClusterBoundary* getNext()\n"
"    Signature: getNext|ptr-oaClusterBoundary|\n"
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
oaIter_oaClusterBoundary_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaClusterBoundary data;
    int convert_status=PyoaIter_oaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaClusterBoundaryObject* self=(PyoaIter_oaClusterBoundaryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterBoundaryp result= (data.DataCall()->getNext());
        return PyoaClusterBoundary_FromoaClusterBoundary(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaClusterBoundary_next_doc[] = 
"Class: oaIter_oaClusterBoundary, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaClusterBoundary* next()\n"
"    Signature: next|ptr-oaClusterBoundary|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaClusterBoundary_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaClusterBoundary data;
    int convert_status=PyoaIter_oaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaClusterBoundaryObject* self=(PyoaIter_oaClusterBoundaryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterBoundaryp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaClusterBoundary_FromoaClusterBoundary(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaClusterBoundary_assign_doc[] = 
"Class: oaIter_oaClusterBoundary, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaClusterBoundary_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaClusterBoundary data;
  int convert_status=PyoaIter_oaClusterBoundary_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaClusterBoundary p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaClusterBoundary_Convert,&p1)) {
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

static PyMethodDef oaIter_oaClusterBoundary_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaClusterBoundary_getNext,METH_VARARGS,oaIter_oaClusterBoundary_getNext_doc},
    {"next",(PyCFunction)oaIter_oaClusterBoundary_next,METH_VARARGS,oaIter_oaClusterBoundary_next_doc},
    {"assign",(PyCFunction)oaIter_oaClusterBoundary_tp_assign,METH_VARARGS,oaIter_oaClusterBoundary_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaClusterBoundary_doc[] = 
"Class: oaIter_oaClusterBoundary\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaClusterBoundary(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaClusterBoundary||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaClusterBoundary)\n"
"    Calls: oaIter_oaClusterBoundary(const oaIter_oaClusterBoundary& iterIn)\n"
"    Signature: oaIter_oaClusterBoundary||cref-oaIter_oaClusterBoundary,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaClusterBoundary)\n"
"    Calls: (const oaIter_oaClusterBoundary&)\n"
"    Signature: oaIter_oaClusterBoundary||cref-oaIter_oaClusterBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaClusterBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaClusterBoundary",
    sizeof(PyoaIter_oaClusterBoundaryObject),
    0,
    (destructor)oaIter_oaClusterBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaClusterBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaClusterBoundary_tp_repr,	/* tp_repr */
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
    oaIter_oaClusterBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaClusterBoundary_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaClusterBoundary_iternext,	/* tp_iternext */
    oaIter_oaClusterBoundary_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaClusterBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaClusterBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaClusterBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaClusterBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaClusterBoundary",
           (PyObject*)(&PyoaIter_oaClusterBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaClusterBoundary\n");
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
// Wrapper Implementation for Class: oaIter_oaConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConnectDefObject* self = (PyoaIter_oaConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConnectDef)
    {
        PyParamoaIter_oaConnectDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConnectDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConnectDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConnectDef)\n"
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
oaIter_oaConnectDef_tp_dealloc(PyoaIter_oaConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConnectDef value;
    int convert_status=PyoaIter_oaConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConnectDef v1;
    PyParamoaIter_oaConnectDef v2;
    int convert_status1=PyoaIter_oaConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConnectDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConnectDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConnectDef ob;
    int convert_status=PyoaIter_oaConnectDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaConnectDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConnectDef_FromoaConnectDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConnectDef_Convert(PyObject* ob,PyParamoaIter_oaConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConnectDef_Check(ob)) {
        result->SetData( (oaIter_oaConnectDef*) ((PyoaIter_oaConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConnectDef_FromoaIter_oaConnectDef(oaIter_oaConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConnectDef_Type.tp_alloc(&PyoaIter_oaConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConnectDefObject* self = (PyoaIter_oaConnectDefObject*)bself;
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
static char oaIter_oaConnectDef_getNext_doc[] = 
"Class: oaIter_oaConnectDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConnectDef* getNext()\n"
"    Signature: getNext|ptr-oaConnectDef|\n"
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
oaIter_oaConnectDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConnectDef data;
    int convert_status=PyoaIter_oaConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConnectDefObject* self=(PyoaIter_oaConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConnectDefp result= (data.DataCall()->getNext());
        return PyoaConnectDef_FromoaConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConnectDef_next_doc[] = 
"Class: oaIter_oaConnectDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConnectDef* next()\n"
"    Signature: next|ptr-oaConnectDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConnectDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConnectDef data;
    int convert_status=PyoaIter_oaConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConnectDefObject* self=(PyoaIter_oaConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConnectDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConnectDef_FromoaConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConnectDef_assign_doc[] = 
"Class: oaIter_oaConnectDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConnectDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConnectDef data;
  int convert_status=PyoaIter_oaConnectDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConnectDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConnectDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConnectDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConnectDef_getNext,METH_VARARGS,oaIter_oaConnectDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConnectDef_next,METH_VARARGS,oaIter_oaConnectDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaConnectDef_tp_assign,METH_VARARGS,oaIter_oaConnectDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConnectDef_doc[] = 
"Class: oaIter_oaConnectDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConnectDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConnectDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConnectDef)\n"
"    Calls: oaIter_oaConnectDef(const oaIter_oaConnectDef& iterIn)\n"
"    Signature: oaIter_oaConnectDef||cref-oaIter_oaConnectDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConnectDef)\n"
"    Calls: (const oaIter_oaConnectDef&)\n"
"    Signature: oaIter_oaConnectDef||cref-oaIter_oaConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConnectDef",
    sizeof(PyoaIter_oaConnectDefObject),
    0,
    (destructor)oaIter_oaConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConnectDef_tp_repr,	/* tp_repr */
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
    oaIter_oaConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConnectDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConnectDef_iternext,	/* tp_iternext */
    oaIter_oaConnectDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConnectDef",
           (PyObject*)(&PyoaIter_oaConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConnectDef\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintObject* self = (PyoaIter_oaConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintCollection)
    {
        PyParamoaConstraintCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintCollection_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraint)
    {
        PyParamoaIter_oaConstraint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraint_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraint, Choices are:\n"
        "    (oaConstraintCollection)\n"
        "    (oaCollection_oaConstraint_oaConstraintGroup)\n"
        "    (oaIter_oaConstraint)\n"
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
oaIter_oaConstraint_tp_dealloc(PyoaIter_oaConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraint value;
    int convert_status=PyoaIter_oaConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraint v1;
    PyParamoaIter_oaConstraint v2;
    int convert_status1=PyoaIter_oaConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraint ob;
    int convert_status=PyoaIter_oaConstraint_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraint_FromoaConstraint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraint_Convert(PyObject* ob,PyParamoaIter_oaConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraint_Check(ob)) {
        result->SetData( (oaIter_oaConstraint*) ((PyoaIter_oaConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraint_FromoaIter_oaConstraint(oaIter_oaConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraint_Type.tp_alloc(&PyoaIter_oaConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintObject* self = (PyoaIter_oaConstraintObject*)bself;
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
static char oaIter_oaConstraint_getNext_doc[] = 
"Class: oaIter_oaConstraint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraint* getNext()\n"
"    Signature: getNext|ptr-oaConstraint|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaConstraint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraint data;
    int convert_status=PyoaIter_oaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintObject* self=(PyoaIter_oaConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintp result= (data.DataCall()->getNext());
        return PyoaConstraint_FromoaConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraint_next_doc[] = 
"Class: oaIter_oaConstraint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraint* next()\n"
"    Signature: next|ptr-oaConstraint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraint data;
    int convert_status=PyoaIter_oaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintObject* self=(PyoaIter_oaConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraint_FromoaConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraint_reset_doc[] = 
"Class: oaIter_oaConstraint, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaConstraint_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraint data;
    int convert_status=PyoaIter_oaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintObject* self=(PyoaIter_oaConstraintObject*)ob;

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


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaIter_oaConstraint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraint_getNext,METH_VARARGS,oaIter_oaConstraint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraint_next,METH_VARARGS,oaIter_oaConstraint_next_doc},
    {"reset",(PyCFunction)oaIter_oaConstraint_reset,METH_VARARGS,oaIter_oaConstraint_reset_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraint_doc[] = 
"Class: oaIter_oaConstraint\n"
"  Class type oaIter_oaConstraint\n"
"Constructors:\n"
"  Paramegers: (oaConstraintCollection)\n"
"    Calls: oaIter_oaConstraint(const oaConstraintCollection& c)\n"
"    Signature: oaIter_oaConstraint||cref-oaConstraintCollection,\n"
"    Constructor oaIter_oaConstraint\n"
"  Paramegers: (oaCollection_oaConstraint_oaConstraintGroup)\n"
"    Calls: oaIter_oaConstraint(const oaCollection_oaConstraint_oaConstraintGroup& c)\n"
"    Signature: oaIter_oaConstraint||cref-oaCollection_oaConstraint_oaConstraintGroup,\n"
"    Constructor oaIter_oaConstraint\n"
"  Paramegers: (oaIter_oaConstraint)\n"
"    Calls: oaIter_oaConstraint(const oaIter_oaConstraint& iterIn)\n"
"    Signature: oaIter_oaConstraint||cref-oaIter_oaConstraint,\n"
"    Constructor oaIter_oaConstraint\n"
"  Paramegers: (oaIter_oaConstraint)\n"
"    Calls: (const oaIter_oaConstraint&)\n"
"    Signature: oaIter_oaConstraint||cref-oaIter_oaConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraint",
    sizeof(PyoaIter_oaConstraintObject),
    0,
    (destructor)oaIter_oaConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraint_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraint_iternext,	/* tp_iternext */
    oaIter_oaConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraint",
           (PyObject*)(&PyoaIter_oaConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraint\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintDefObject* self = (PyoaIter_oaConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintDef)
    {
        PyParamoaIter_oaConstraintDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintDef)\n"
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
oaIter_oaConstraintDef_tp_dealloc(PyoaIter_oaConstraintDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintDef value;
    int convert_status=PyoaIter_oaConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintDef v1;
    PyParamoaIter_oaConstraintDef v2;
    int convert_status1=PyoaIter_oaConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintDef ob;
    int convert_status=PyoaIter_oaConstraintDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintDef_FromoaConstraintDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintDef_Convert(PyObject* ob,PyParamoaIter_oaConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintDef_Check(ob)) {
        result->SetData( (oaIter_oaConstraintDef*) ((PyoaIter_oaConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintDef_FromoaIter_oaConstraintDef(oaIter_oaConstraintDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintDef_Type.tp_alloc(&PyoaIter_oaConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintDefObject* self = (PyoaIter_oaConstraintDefObject*)bself;
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
static char oaIter_oaConstraintDef_getNext_doc[] = 
"Class: oaIter_oaConstraintDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintDef* getNext()\n"
"    Signature: getNext|ptr-oaConstraintDef|\n"
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
oaIter_oaConstraintDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintDef data;
    int convert_status=PyoaIter_oaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintDefObject* self=(PyoaIter_oaConstraintDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintDefp result= (data.DataCall()->getNext());
        return PyoaConstraintDef_FromoaConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraintDef_next_doc[] = 
"Class: oaIter_oaConstraintDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintDef* next()\n"
"    Signature: next|ptr-oaConstraintDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintDef data;
    int convert_status=PyoaIter_oaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintDefObject* self=(PyoaIter_oaConstraintDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintDef_FromoaConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintDef_assign_doc[] = 
"Class: oaIter_oaConstraintDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintDef data;
  int convert_status=PyoaIter_oaConstraintDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintDef_getNext,METH_VARARGS,oaIter_oaConstraintDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintDef_next,METH_VARARGS,oaIter_oaConstraintDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintDef_tp_assign,METH_VARARGS,oaIter_oaConstraintDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintDef_doc[] = 
"Class: oaIter_oaConstraintDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintDef)\n"
"    Calls: oaIter_oaConstraintDef(const oaIter_oaConstraintDef& iterIn)\n"
"    Signature: oaIter_oaConstraintDef||cref-oaIter_oaConstraintDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintDef)\n"
"    Calls: (const oaIter_oaConstraintDef&)\n"
"    Signature: oaIter_oaConstraintDef||cref-oaIter_oaConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintDef",
    sizeof(PyoaIter_oaConstraintDefObject),
    0,
    (destructor)oaIter_oaConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintDef_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintDef_iternext,	/* tp_iternext */
    oaIter_oaConstraintDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintDef",
           (PyObject*)(&PyoaIter_oaConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintDef\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintGroupObject* self = (PyoaIter_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintGroup)
    {
        PyParamoaIter_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintGroup, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintGroup)\n"
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
oaIter_oaConstraintGroup_tp_dealloc(PyoaIter_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintGroup value;
    int convert_status=PyoaIter_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintGroup v1;
    PyParamoaIter_oaConstraintGroup v2;
    int convert_status1=PyoaIter_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroup_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroup_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintGroup ob;
    int convert_status=PyoaIter_oaConstraintGroup_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintGroup* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintGroup_FromoaConstraintGroup(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintGroup_Convert(PyObject* ob,PyParamoaIter_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaIter_oaConstraintGroup*) ((PyoaIter_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintGroup_FromoaIter_oaConstraintGroup(oaIter_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintGroup_Type.tp_alloc(&PyoaIter_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintGroupObject* self = (PyoaIter_oaConstraintGroupObject*)bself;
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
static char oaIter_oaConstraintGroup_getNext_doc[] = 
"Class: oaIter_oaConstraintGroup, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getNext()\n"
"    Signature: getNext|ptr-oaConstraintGroup|\n"
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
oaIter_oaConstraintGroup_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroup data;
    int convert_status=PyoaIter_oaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupObject* self=(PyoaIter_oaConstraintGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupp result= (data.DataCall()->getNext());
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
static char oaIter_oaConstraintGroup_next_doc[] = 
"Class: oaIter_oaConstraintGroup, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* next()\n"
"    Signature: next|ptr-oaConstraintGroup|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintGroup_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroup data;
    int convert_status=PyoaIter_oaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupObject* self=(PyoaIter_oaConstraintGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintGroup_FromoaConstraintGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintGroup_assign_doc[] = 
"Class: oaIter_oaConstraintGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintGroup data;
  int convert_status=PyoaIter_oaConstraintGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintGroup_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintGroup_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintGroup_getNext,METH_VARARGS,oaIter_oaConstraintGroup_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintGroup_next,METH_VARARGS,oaIter_oaConstraintGroup_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintGroup_tp_assign,METH_VARARGS,oaIter_oaConstraintGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintGroup_doc[] = 
"Class: oaIter_oaConstraintGroup\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintGroup(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintGroup||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintGroup)\n"
"    Calls: oaIter_oaConstraintGroup(const oaIter_oaConstraintGroup& iterIn)\n"
"    Signature: oaIter_oaConstraintGroup||cref-oaIter_oaConstraintGroup,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintGroup)\n"
"    Calls: (const oaIter_oaConstraintGroup&)\n"
"    Signature: oaIter_oaConstraintGroup||cref-oaIter_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintGroup",
    sizeof(PyoaIter_oaConstraintGroupObject),
    0,
    (destructor)oaIter_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintGroup_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintGroup_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintGroup_iternext,	/* tp_iternext */
    oaIter_oaConstraintGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintGroup",
           (PyObject*)(&PyoaIter_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintGroup\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintGroupHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintGroupHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintGroupHeaderObject* self = (PyoaIter_oaConstraintGroupHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroupHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintGroupHeader)
    {
        PyParamoaIter_oaConstraintGroupHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintGroupHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroupHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintGroupHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintGroupHeader)\n"
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
oaIter_oaConstraintGroupHeader_tp_dealloc(PyoaIter_oaConstraintGroupHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintGroupHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintGroupHeader value;
    int convert_status=PyoaIter_oaConstraintGroupHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaIter_oaConstraintGroupHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintGroupHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintGroupHeader v1;
    PyParamoaIter_oaConstraintGroupHeader v2;
    int convert_status1=PyoaIter_oaConstraintGroupHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintGroupHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintGroupHeader ob;
    int convert_status=PyoaIter_oaConstraintGroupHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintGroupHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintGroupHeader_FromoaConstraintGroupHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintGroupHeader_Convert(PyObject* ob,PyParamoaIter_oaConstraintGroupHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintGroupHeader_Check(ob)) {
        result->SetData( (oaIter_oaConstraintGroupHeader*) ((PyoaIter_oaConstraintGroupHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintGroupHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintGroupHeader_FromoaIter_oaConstraintGroupHeader(oaIter_oaConstraintGroupHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintGroupHeader_Type.tp_alloc(&PyoaIter_oaConstraintGroupHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintGroupHeaderObject* self = (PyoaIter_oaConstraintGroupHeaderObject*)bself;
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
static char oaIter_oaConstraintGroupHeader_getNext_doc[] = 
"Class: oaIter_oaConstraintGroupHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroupHeader* getNext()\n"
"    Signature: getNext|ptr-oaConstraintGroupHeader|\n"
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
oaIter_oaConstraintGroupHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroupHeader data;
    int convert_status=PyoaIter_oaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupHeaderObject* self=(PyoaIter_oaConstraintGroupHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupHeaderp result= (data.DataCall()->getNext());
        return PyoaConstraintGroupHeader_FromoaConstraintGroupHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraintGroupHeader_next_doc[] = 
"Class: oaIter_oaConstraintGroupHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroupHeader* next()\n"
"    Signature: next|ptr-oaConstraintGroupHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintGroupHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroupHeader data;
    int convert_status=PyoaIter_oaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupHeaderObject* self=(PyoaIter_oaConstraintGroupHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintGroupHeader_FromoaConstraintGroupHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintGroupHeader_assign_doc[] = 
"Class: oaIter_oaConstraintGroupHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintGroupHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintGroupHeader data;
  int convert_status=PyoaIter_oaConstraintGroupHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintGroupHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintGroupHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintGroupHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintGroupHeader_getNext,METH_VARARGS,oaIter_oaConstraintGroupHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintGroupHeader_next,METH_VARARGS,oaIter_oaConstraintGroupHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintGroupHeader_tp_assign,METH_VARARGS,oaIter_oaConstraintGroupHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintGroupHeader_doc[] = 
"Class: oaIter_oaConstraintGroupHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintGroupHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintGroupHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintGroupHeader)\n"
"    Calls: oaIter_oaConstraintGroupHeader(const oaIter_oaConstraintGroupHeader& iterIn)\n"
"    Signature: oaIter_oaConstraintGroupHeader||cref-oaIter_oaConstraintGroupHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintGroupHeader)\n"
"    Calls: (const oaIter_oaConstraintGroupHeader&)\n"
"    Signature: oaIter_oaConstraintGroupHeader||cref-oaIter_oaConstraintGroupHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintGroupHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintGroupHeader",
    sizeof(PyoaIter_oaConstraintGroupHeaderObject),
    0,
    (destructor)oaIter_oaConstraintGroupHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintGroupHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintGroupHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintGroupHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintGroupHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintGroupHeader_iternext,	/* tp_iternext */
    oaIter_oaConstraintGroupHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintGroupHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintGroupHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintGroupHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintGroupHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintGroupHeader",
           (PyObject*)(&PyoaIter_oaConstraintGroupHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintGroupHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintGroupMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintGroupMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintGroupMemObject* self = (PyoaIter_oaConstraintGroupMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroupMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintGroupMem)
    {
        PyParamoaIter_oaConstraintGroupMem p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintGroupMem_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintGroupMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintGroupMem, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintGroupMem)\n"
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
oaIter_oaConstraintGroupMem_tp_dealloc(PyoaIter_oaConstraintGroupMemObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintGroupMem*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupMem_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintGroupMem value;
    int convert_status=PyoaIter_oaConstraintGroupMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaIter_oaConstraintGroupMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintGroupMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintGroupMem v1;
    PyParamoaIter_oaConstraintGroupMem v2;
    int convert_status1=PyoaIter_oaConstraintGroupMem_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintGroupMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupMem_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintGroupMem_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintGroupMem ob;
    int convert_status=PyoaIter_oaConstraintGroupMem_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintGroupMem* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintGroupMem_Convert(PyObject* ob,PyParamoaIter_oaConstraintGroupMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintGroupMem_Check(ob)) {
        result->SetData( (oaIter_oaConstraintGroupMem*) ((PyoaIter_oaConstraintGroupMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintGroupMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintGroupMem_FromoaIter_oaConstraintGroupMem(oaIter_oaConstraintGroupMem* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintGroupMem_Type.tp_alloc(&PyoaIter_oaConstraintGroupMem_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintGroupMemObject* self = (PyoaIter_oaConstraintGroupMemObject*)bself;
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
static char oaIter_oaConstraintGroupMem_getNext_doc[] = 
"Class: oaIter_oaConstraintGroupMem, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroupMem* getNext()\n"
"    Signature: getNext|ptr-oaConstraintGroupMem|\n"
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
oaIter_oaConstraintGroupMem_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroupMem data;
    int convert_status=PyoaIter_oaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupMemObject* self=(PyoaIter_oaConstraintGroupMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupMemp result= (data.DataCall()->getNext());
        return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraintGroupMem_next_doc[] = 
"Class: oaIter_oaConstraintGroupMem, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroupMem* next()\n"
"    Signature: next|ptr-oaConstraintGroupMem|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintGroupMem_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintGroupMem data;
    int convert_status=PyoaIter_oaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintGroupMemObject* self=(PyoaIter_oaConstraintGroupMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupMemp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintGroupMem_assign_doc[] = 
"Class: oaIter_oaConstraintGroupMem, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintGroupMem_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintGroupMem data;
  int convert_status=PyoaIter_oaConstraintGroupMem_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintGroupMem p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintGroupMem_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintGroupMem_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintGroupMem_getNext,METH_VARARGS,oaIter_oaConstraintGroupMem_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintGroupMem_next,METH_VARARGS,oaIter_oaConstraintGroupMem_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintGroupMem_tp_assign,METH_VARARGS,oaIter_oaConstraintGroupMem_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintGroupMem_doc[] = 
"Class: oaIter_oaConstraintGroupMem\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintGroupMem(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintGroupMem||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintGroupMem)\n"
"    Calls: oaIter_oaConstraintGroupMem(const oaIter_oaConstraintGroupMem& iterIn)\n"
"    Signature: oaIter_oaConstraintGroupMem||cref-oaIter_oaConstraintGroupMem,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintGroupMem)\n"
"    Calls: (const oaIter_oaConstraintGroupMem&)\n"
"    Signature: oaIter_oaConstraintGroupMem||cref-oaIter_oaConstraintGroupMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintGroupMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintGroupMem",
    sizeof(PyoaIter_oaConstraintGroupMemObject),
    0,
    (destructor)oaIter_oaConstraintGroupMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintGroupMem_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintGroupMem_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintGroupMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintGroupMem_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintGroupMem_iternext,	/* tp_iternext */
    oaIter_oaConstraintGroupMem_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintGroupMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintGroupMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintGroupMem_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintGroupMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintGroupMem",
           (PyObject*)(&PyoaIter_oaConstraintGroupMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintGroupMem\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintParamObject* self = (PyoaIter_oaConstraintParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintParam)
    {
        PyParamoaIter_oaConstraintParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintParam_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintParam, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintParam)\n"
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
oaIter_oaConstraintParam_tp_dealloc(PyoaIter_oaConstraintParamObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParam_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintParam value;
    int convert_status=PyoaIter_oaConstraintParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaConstraintParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintParam v1;
    PyParamoaIter_oaConstraintParam v2;
    int convert_status1=PyoaIter_oaConstraintParam_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParam_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParam_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintParam ob;
    int convert_status=PyoaIter_oaConstraintParam_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintParam* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintParam_FromoaConstraintParam(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintParam_Convert(PyObject* ob,PyParamoaIter_oaConstraintParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintParam_Check(ob)) {
        result->SetData( (oaIter_oaConstraintParam*) ((PyoaIter_oaConstraintParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintParam_FromoaIter_oaConstraintParam(oaIter_oaConstraintParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintParam_Type.tp_alloc(&PyoaIter_oaConstraintParam_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintParamObject* self = (PyoaIter_oaConstraintParamObject*)bself;
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
static char oaIter_oaConstraintParam_getNext_doc[] = 
"Class: oaIter_oaConstraintParam, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParam* getNext()\n"
"    Signature: getNext|ptr-oaConstraintParam|\n"
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
oaIter_oaConstraintParam_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintParam data;
    int convert_status=PyoaIter_oaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintParamObject* self=(PyoaIter_oaConstraintParamObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamp result= (data.DataCall()->getNext());
        return PyoaConstraintParam_FromoaConstraintParam(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraintParam_next_doc[] = 
"Class: oaIter_oaConstraintParam, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParam* next()\n"
"    Signature: next|ptr-oaConstraintParam|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintParam_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintParam data;
    int convert_status=PyoaIter_oaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintParamObject* self=(PyoaIter_oaConstraintParamObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintParam_FromoaConstraintParam(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintParam_assign_doc[] = 
"Class: oaIter_oaConstraintParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintParam data;
  int convert_status=PyoaIter_oaConstraintParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintParam_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintParam_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintParam_getNext,METH_VARARGS,oaIter_oaConstraintParam_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintParam_next,METH_VARARGS,oaIter_oaConstraintParam_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintParam_tp_assign,METH_VARARGS,oaIter_oaConstraintParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintParam_doc[] = 
"Class: oaIter_oaConstraintParam\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintParam(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintParam||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintParam)\n"
"    Calls: oaIter_oaConstraintParam(const oaIter_oaConstraintParam& iterIn)\n"
"    Signature: oaIter_oaConstraintParam||cref-oaIter_oaConstraintParam,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintParam)\n"
"    Calls: (const oaIter_oaConstraintParam&)\n"
"    Signature: oaIter_oaConstraintParam||cref-oaIter_oaConstraintParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintParam",
    sizeof(PyoaIter_oaConstraintParamObject),
    0,
    (destructor)oaIter_oaConstraintParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintParam_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintParam_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintParam_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintParam_iternext,	/* tp_iternext */
    oaIter_oaConstraintParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintParam_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintParam",
           (PyObject*)(&PyoaIter_oaConstraintParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintParam\n");
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
// Wrapper Implementation for Class: oaIter_oaConstraintParamDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParamDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaConstraintParamDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaConstraintParamDefObject* self = (PyoaIter_oaConstraintParamDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintParamDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaConstraintParamDef)
    {
        PyParamoaIter_oaConstraintParamDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaConstraintParamDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaConstraintParamDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaConstraintParamDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaConstraintParamDef)\n"
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
oaIter_oaConstraintParamDef_tp_dealloc(PyoaIter_oaConstraintParamDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaConstraintParamDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParamDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaConstraintParamDef value;
    int convert_status=PyoaIter_oaConstraintParamDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaIter_oaConstraintParamDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaConstraintParamDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaConstraintParamDef v1;
    PyParamoaIter_oaConstraintParamDef v2;
    int convert_status1=PyoaIter_oaConstraintParamDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaConstraintParamDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParamDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaConstraintParamDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaConstraintParamDef ob;
    int convert_status=PyoaIter_oaConstraintParamDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaConstraintParamDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaConstraintParamDef_FromoaConstraintParamDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaConstraintParamDef_Convert(PyObject* ob,PyParamoaIter_oaConstraintParamDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaConstraintParamDef_Check(ob)) {
        result->SetData( (oaIter_oaConstraintParamDef*) ((PyoaIter_oaConstraintParamDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaConstraintParamDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaConstraintParamDef_FromoaIter_oaConstraintParamDef(oaIter_oaConstraintParamDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaConstraintParamDef_Type.tp_alloc(&PyoaIter_oaConstraintParamDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaConstraintParamDefObject* self = (PyoaIter_oaConstraintParamDefObject*)bself;
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
static char oaIter_oaConstraintParamDef_getNext_doc[] = 
"Class: oaIter_oaConstraintParamDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParamDef* getNext()\n"
"    Signature: getNext|ptr-oaConstraintParamDef|\n"
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
oaIter_oaConstraintParamDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintParamDef data;
    int convert_status=PyoaIter_oaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintParamDefObject* self=(PyoaIter_oaConstraintParamDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamDefp result= (data.DataCall()->getNext());
        return PyoaConstraintParamDef_FromoaConstraintParamDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaConstraintParamDef_next_doc[] = 
"Class: oaIter_oaConstraintParamDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParamDef* next()\n"
"    Signature: next|ptr-oaConstraintParamDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaConstraintParamDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaConstraintParamDef data;
    int convert_status=PyoaIter_oaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaConstraintParamDefObject* self=(PyoaIter_oaConstraintParamDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaConstraintParamDef_FromoaConstraintParamDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaConstraintParamDef_assign_doc[] = 
"Class: oaIter_oaConstraintParamDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaConstraintParamDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaConstraintParamDef data;
  int convert_status=PyoaIter_oaConstraintParamDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaConstraintParamDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaConstraintParamDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaConstraintParamDef_getNext,METH_VARARGS,oaIter_oaConstraintParamDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaConstraintParamDef_next,METH_VARARGS,oaIter_oaConstraintParamDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaConstraintParamDef_tp_assign,METH_VARARGS,oaIter_oaConstraintParamDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaConstraintParamDef_doc[] = 
"Class: oaIter_oaConstraintParamDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaConstraintParamDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaConstraintParamDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaConstraintParamDef)\n"
"    Calls: oaIter_oaConstraintParamDef(const oaIter_oaConstraintParamDef& iterIn)\n"
"    Signature: oaIter_oaConstraintParamDef||cref-oaIter_oaConstraintParamDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaConstraintParamDef)\n"
"    Calls: (const oaIter_oaConstraintParamDef&)\n"
"    Signature: oaIter_oaConstraintParamDef||cref-oaIter_oaConstraintParamDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaConstraintParamDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaConstraintParamDef",
    sizeof(PyoaIter_oaConstraintParamDefObject),
    0,
    (destructor)oaIter_oaConstraintParamDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaConstraintParamDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaConstraintParamDef_tp_repr,	/* tp_repr */
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
    oaIter_oaConstraintParamDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaConstraintParamDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaConstraintParamDef_iternext,	/* tp_iternext */
    oaIter_oaConstraintParamDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaConstraintParamDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaConstraintParamDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaConstraintParamDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaConstraintParamDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaConstraintParamDef",
           (PyObject*)(&PyoaIter_oaConstraintParamDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaConstraintParamDef\n");
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
// Wrapper Implementation for Class: oaIter_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDMDataObject* self = (PyoaIter_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDMData_oaDMData)
    {
        PyParamoaCollection_oaDMData_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDMData_oaDMData_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDMData)
    {
        PyParamoaIter_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDMData_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDMData, Choices are:\n"
        "    (oaCollection_oaDMData_oaDMData)\n"
        "    (oaIter_oaDMData)\n"
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
oaIter_oaDMData_tp_dealloc(PyoaIter_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDMData value;
    int convert_status=PyoaIter_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDMData v1;
    PyParamoaIter_oaDMData v2;
    int convert_status1=PyoaIter_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMData_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMData_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDMData ob;
    int convert_status=PyoaIter_oaDMData_Convert(self,&ob);
    assert(convert_status!=0);
    oaDMData* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDMData_FromoaDMData(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDMData_Convert(PyObject* ob,PyParamoaIter_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDMData_Check(ob)) {
        result->SetData( (oaIter_oaDMData*) ((PyoaIter_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDMData_FromoaIter_oaDMData(oaIter_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDMData_Type.tp_alloc(&PyoaIter_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDMDataObject* self = (PyoaIter_oaDMDataObject*)bself;
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
static char oaIter_oaDMData_getNext_doc[] = 
"Class: oaIter_oaDMData, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDMData* getNext()\n"
"    Signature: getNext|ptr-oaDMData|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaDMData_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDMData data;
    int convert_status=PyoaIter_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDMDataObject* self=(PyoaIter_oaDMDataObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMDatap result= (data.DataCall()->getNext());
        return PyoaDMData_FromoaDMData(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDMData_next_doc[] = 
"Class: oaIter_oaDMData, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDMData* next()\n"
"    Signature: next|ptr-oaDMData|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDMData_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDMData data;
    int convert_status=PyoaIter_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDMDataObject* self=(PyoaIter_oaDMDataObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMDatap result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDMData_FromoaDMData(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDMData_assign_doc[] = 
"Class: oaIter_oaDMData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDMData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDMData data;
  int convert_status=PyoaIter_oaDMData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDMData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDMData_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDMData_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDMData_getNext,METH_VARARGS,oaIter_oaDMData_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDMData_next,METH_VARARGS,oaIter_oaDMData_next_doc},
    {"assign",(PyCFunction)oaIter_oaDMData_tp_assign,METH_VARARGS,oaIter_oaDMData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDMData_doc[] = 
"Class: oaIter_oaDMData\n"
"  Class type oaIter_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaDMData_oaDMData)\n"
"    Calls: oaIter_oaDMData(const oaCollection_oaDMData_oaDMData& c)\n"
"    Signature: oaIter_oaDMData||cref-oaCollection_oaDMData_oaDMData,\n"
"    Constructor oaIter_oaDMData\n"
"  Paramegers: (oaIter_oaDMData)\n"
"    Calls: oaIter_oaDMData(const oaIter_oaDMData& iterIn)\n"
"    Signature: oaIter_oaDMData||cref-oaIter_oaDMData,\n"
"    Constructor oaIter_oaDMData\n"
"  Paramegers: (oaIter_oaDMData)\n"
"    Calls: (const oaIter_oaDMData&)\n"
"    Signature: oaIter_oaDMData||cref-oaIter_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDMData",
    sizeof(PyoaIter_oaDMDataObject),
    0,
    (destructor)oaIter_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDMData_tp_repr,	/* tp_repr */
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
    oaIter_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDMData_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDMData_iternext,	/* tp_iternext */
    oaIter_oaDMData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDMData",
           (PyObject*)(&PyoaIter_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDMData\n");
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
// Wrapper Implementation for Class: oaIter_oaDMFile
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMFile_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDMFile_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDMFileObject* self = (PyoaIter_oaDMFileObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDMFile(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDMFile)
    {
        PyParamoaIter_oaDMFile p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDMFile_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDMFile(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDMFile, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDMFile)\n"
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
oaIter_oaDMFile_tp_dealloc(PyoaIter_oaDMFileObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDMFile*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMFile_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDMFile value;
    int convert_status=PyoaIter_oaDMFile_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaDMFile::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDMFile_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDMFile v1;
    PyParamoaIter_oaDMFile v2;
    int convert_status1=PyoaIter_oaDMFile_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDMFile_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMFile_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDMFile_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDMFile ob;
    int convert_status=PyoaIter_oaDMFile_Convert(self,&ob);
    assert(convert_status!=0);
    oaDMFile* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDMFile_FromoaDMFile(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDMFile_Convert(PyObject* ob,PyParamoaIter_oaDMFile* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDMFile_Check(ob)) {
        result->SetData( (oaIter_oaDMFile*) ((PyoaIter_oaDMFileObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDMFile Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDMFile_FromoaIter_oaDMFile(oaIter_oaDMFile* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDMFile_Type.tp_alloc(&PyoaIter_oaDMFile_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDMFileObject* self = (PyoaIter_oaDMFileObject*)bself;
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
static char oaIter_oaDMFile_getNext_doc[] = 
"Class: oaIter_oaDMFile, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDMFile* getNext()\n"
"    Signature: getNext|ptr-oaDMFile|\n"
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
oaIter_oaDMFile_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDMFile data;
    int convert_status=PyoaIter_oaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDMFileObject* self=(PyoaIter_oaDMFileObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMFilep result= (data.DataCall()->getNext());
        return PyoaDMFile_FromoaDMFile(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDMFile_next_doc[] = 
"Class: oaIter_oaDMFile, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDMFile* next()\n"
"    Signature: next|ptr-oaDMFile|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDMFile_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDMFile data;
    int convert_status=PyoaIter_oaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDMFileObject* self=(PyoaIter_oaDMFileObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMFilep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDMFile_FromoaDMFile(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDMFile_assign_doc[] = 
"Class: oaIter_oaDMFile, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDMFile_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDMFile data;
  int convert_status=PyoaIter_oaDMFile_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDMFile p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDMFile_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDMFile_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDMFile_getNext,METH_VARARGS,oaIter_oaDMFile_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDMFile_next,METH_VARARGS,oaIter_oaDMFile_next_doc},
    {"assign",(PyCFunction)oaIter_oaDMFile_tp_assign,METH_VARARGS,oaIter_oaDMFile_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDMFile_doc[] = 
"Class: oaIter_oaDMFile\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDMFile(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDMFile||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDMFile)\n"
"    Calls: oaIter_oaDMFile(const oaIter_oaDMFile& iterIn)\n"
"    Signature: oaIter_oaDMFile||cref-oaIter_oaDMFile,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDMFile)\n"
"    Calls: (const oaIter_oaDMFile&)\n"
"    Signature: oaIter_oaDMFile||cref-oaIter_oaDMFile,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDMFile_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDMFile",
    sizeof(PyoaIter_oaDMFileObject),
    0,
    (destructor)oaIter_oaDMFile_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDMFile_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDMFile_tp_repr,	/* tp_repr */
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
    oaIter_oaDMFile_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDMFile_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDMFile_iternext,	/* tp_iternext */
    oaIter_oaDMFile_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDMFile_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDMFile_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDMFile_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDMFile\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDMFile",
           (PyObject*)(&PyoaIter_oaDMFile_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDMFile\n");
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
// Wrapper Implementation for Class: oaIter_oaDerivedLayerDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDerivedLayerDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDerivedLayerDefObject* self = (PyoaIter_oaDerivedLayerDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDerivedLayerDef)
    {
        PyParamoaIter_oaDerivedLayerDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDerivedLayerDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDerivedLayerDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDerivedLayerDef)\n"
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
oaIter_oaDerivedLayerDef_tp_dealloc(PyoaIter_oaDerivedLayerDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDerivedLayerDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDerivedLayerDef value;
    int convert_status=PyoaIter_oaDerivedLayerDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaDerivedLayerDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDerivedLayerDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDerivedLayerDef v1;
    PyParamoaIter_oaDerivedLayerDef v2;
    int convert_status1=PyoaIter_oaDerivedLayerDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDerivedLayerDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDerivedLayerDef ob;
    int convert_status=PyoaIter_oaDerivedLayerDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaDerivedLayerDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDerivedLayerDef_FromoaDerivedLayerDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDerivedLayerDef_Convert(PyObject* ob,PyParamoaIter_oaDerivedLayerDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDerivedLayerDef_Check(ob)) {
        result->SetData( (oaIter_oaDerivedLayerDef*) ((PyoaIter_oaDerivedLayerDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDerivedLayerDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDerivedLayerDef_FromoaIter_oaDerivedLayerDef(oaIter_oaDerivedLayerDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDerivedLayerDef_Type.tp_alloc(&PyoaIter_oaDerivedLayerDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDerivedLayerDefObject* self = (PyoaIter_oaDerivedLayerDefObject*)bself;
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
static char oaIter_oaDerivedLayerDef_getNext_doc[] = 
"Class: oaIter_oaDerivedLayerDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerDef* getNext()\n"
"    Signature: getNext|ptr-oaDerivedLayerDef|\n"
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
oaIter_oaDerivedLayerDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerDef data;
    int convert_status=PyoaIter_oaDerivedLayerDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerDefObject* self=(PyoaIter_oaDerivedLayerDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerDefp result= (data.DataCall()->getNext());
        return PyoaDerivedLayerDef_FromoaDerivedLayerDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerDef_next_doc[] = 
"Class: oaIter_oaDerivedLayerDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerDef* next()\n"
"    Signature: next|ptr-oaDerivedLayerDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDerivedLayerDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerDef data;
    int convert_status=PyoaIter_oaDerivedLayerDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerDefObject* self=(PyoaIter_oaDerivedLayerDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDerivedLayerDef_FromoaDerivedLayerDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDerivedLayerDef_assign_doc[] = 
"Class: oaIter_oaDerivedLayerDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDerivedLayerDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDerivedLayerDef data;
  int convert_status=PyoaIter_oaDerivedLayerDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDerivedLayerDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDerivedLayerDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDerivedLayerDef_getNext,METH_VARARGS,oaIter_oaDerivedLayerDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDerivedLayerDef_next,METH_VARARGS,oaIter_oaDerivedLayerDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaDerivedLayerDef_tp_assign,METH_VARARGS,oaIter_oaDerivedLayerDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerDef_doc[] = 
"Class: oaIter_oaDerivedLayerDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDerivedLayerDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDerivedLayerDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDerivedLayerDef)\n"
"    Calls: oaIter_oaDerivedLayerDef(const oaIter_oaDerivedLayerDef& iterIn)\n"
"    Signature: oaIter_oaDerivedLayerDef||cref-oaIter_oaDerivedLayerDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDerivedLayerDef)\n"
"    Calls: (const oaIter_oaDerivedLayerDef&)\n"
"    Signature: oaIter_oaDerivedLayerDef||cref-oaIter_oaDerivedLayerDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDerivedLayerDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDerivedLayerDef",
    sizeof(PyoaIter_oaDerivedLayerDefObject),
    0,
    (destructor)oaIter_oaDerivedLayerDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDerivedLayerDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDerivedLayerDef_tp_repr,	/* tp_repr */
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
    oaIter_oaDerivedLayerDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDerivedLayerDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDerivedLayerDef_iternext,	/* tp_iternext */
    oaIter_oaDerivedLayerDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDerivedLayerDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDerivedLayerDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDerivedLayerDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDerivedLayerDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDerivedLayerDef",
           (PyObject*)(&PyoaIter_oaDerivedLayerDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDerivedLayerDef\n");
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
// Wrapper Implementation for Class: oaIter_oaDerivedLayerParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDerivedLayerParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDerivedLayerParamObject* self = (PyoaIter_oaDerivedLayerParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDerivedLayerParam)
    {
        PyParamoaIter_oaDerivedLayerParam p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDerivedLayerParam_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerParam(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDerivedLayerParam, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDerivedLayerParam)\n"
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
oaIter_oaDerivedLayerParam_tp_dealloc(PyoaIter_oaDerivedLayerParamObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDerivedLayerParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParam_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDerivedLayerParam value;
    int convert_status=PyoaIter_oaDerivedLayerParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaIter_oaDerivedLayerParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDerivedLayerParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDerivedLayerParam v1;
    PyParamoaIter_oaDerivedLayerParam v2;
    int convert_status1=PyoaIter_oaDerivedLayerParam_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDerivedLayerParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParam_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParam_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDerivedLayerParam ob;
    int convert_status=PyoaIter_oaDerivedLayerParam_Convert(self,&ob);
    assert(convert_status!=0);
    oaDerivedLayerParam* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDerivedLayerParam_FromoaDerivedLayerParam(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDerivedLayerParam_Convert(PyObject* ob,PyParamoaIter_oaDerivedLayerParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDerivedLayerParam_Check(ob)) {
        result->SetData( (oaIter_oaDerivedLayerParam*) ((PyoaIter_oaDerivedLayerParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDerivedLayerParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDerivedLayerParam_FromoaIter_oaDerivedLayerParam(oaIter_oaDerivedLayerParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDerivedLayerParam_Type.tp_alloc(&PyoaIter_oaDerivedLayerParam_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDerivedLayerParamObject* self = (PyoaIter_oaDerivedLayerParamObject*)bself;
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
static char oaIter_oaDerivedLayerParam_getNext_doc[] = 
"Class: oaIter_oaDerivedLayerParam, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerParam* getNext()\n"
"    Signature: getNext|ptr-oaDerivedLayerParam|\n"
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
oaIter_oaDerivedLayerParam_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerParam data;
    int convert_status=PyoaIter_oaDerivedLayerParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerParamObject* self=(PyoaIter_oaDerivedLayerParamObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerParamp result= (data.DataCall()->getNext());
        return PyoaDerivedLayerParam_FromoaDerivedLayerParam(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerParam_next_doc[] = 
"Class: oaIter_oaDerivedLayerParam, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerParam* next()\n"
"    Signature: next|ptr-oaDerivedLayerParam|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDerivedLayerParam_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerParam data;
    int convert_status=PyoaIter_oaDerivedLayerParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerParamObject* self=(PyoaIter_oaDerivedLayerParamObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerParamp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDerivedLayerParam_FromoaDerivedLayerParam(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDerivedLayerParam_assign_doc[] = 
"Class: oaIter_oaDerivedLayerParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDerivedLayerParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDerivedLayerParam data;
  int convert_status=PyoaIter_oaDerivedLayerParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDerivedLayerParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDerivedLayerParam_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDerivedLayerParam_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDerivedLayerParam_getNext,METH_VARARGS,oaIter_oaDerivedLayerParam_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDerivedLayerParam_next,METH_VARARGS,oaIter_oaDerivedLayerParam_next_doc},
    {"assign",(PyCFunction)oaIter_oaDerivedLayerParam_tp_assign,METH_VARARGS,oaIter_oaDerivedLayerParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerParam_doc[] = 
"Class: oaIter_oaDerivedLayerParam\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDerivedLayerParam(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDerivedLayerParam||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDerivedLayerParam)\n"
"    Calls: oaIter_oaDerivedLayerParam(const oaIter_oaDerivedLayerParam& iterIn)\n"
"    Signature: oaIter_oaDerivedLayerParam||cref-oaIter_oaDerivedLayerParam,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDerivedLayerParam)\n"
"    Calls: (const oaIter_oaDerivedLayerParam&)\n"
"    Signature: oaIter_oaDerivedLayerParam||cref-oaIter_oaDerivedLayerParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDerivedLayerParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDerivedLayerParam",
    sizeof(PyoaIter_oaDerivedLayerParamObject),
    0,
    (destructor)oaIter_oaDerivedLayerParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDerivedLayerParam_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDerivedLayerParam_tp_repr,	/* tp_repr */
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
    oaIter_oaDerivedLayerParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDerivedLayerParam_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDerivedLayerParam_iternext,	/* tp_iternext */
    oaIter_oaDerivedLayerParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDerivedLayerParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDerivedLayerParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDerivedLayerParam_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDerivedLayerParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDerivedLayerParam",
           (PyObject*)(&PyoaIter_oaDerivedLayerParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDerivedLayerParam\n");
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
// Wrapper Implementation for Class: oaIter_oaDerivedLayerParamDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParamDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDerivedLayerParamDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDerivedLayerParamDefObject* self = (PyoaIter_oaDerivedLayerParamDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerParamDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDerivedLayerParamDef)
    {
        PyParamoaIter_oaDerivedLayerParamDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDerivedLayerParamDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDerivedLayerParamDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDerivedLayerParamDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDerivedLayerParamDef)\n"
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
oaIter_oaDerivedLayerParamDef_tp_dealloc(PyoaIter_oaDerivedLayerParamDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDerivedLayerParamDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParamDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDerivedLayerParamDef value;
    int convert_status=PyoaIter_oaDerivedLayerParamDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaIter_oaDerivedLayerParamDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDerivedLayerParamDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDerivedLayerParamDef v1;
    PyParamoaIter_oaDerivedLayerParamDef v2;
    int convert_status1=PyoaIter_oaDerivedLayerParamDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDerivedLayerParamDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParamDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDerivedLayerParamDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDerivedLayerParamDef ob;
    int convert_status=PyoaIter_oaDerivedLayerParamDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaDerivedLayerParamDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDerivedLayerParamDef_Convert(PyObject* ob,PyParamoaIter_oaDerivedLayerParamDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDerivedLayerParamDef_Check(ob)) {
        result->SetData( (oaIter_oaDerivedLayerParamDef*) ((PyoaIter_oaDerivedLayerParamDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDerivedLayerParamDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDerivedLayerParamDef_FromoaIter_oaDerivedLayerParamDef(oaIter_oaDerivedLayerParamDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDerivedLayerParamDef_Type.tp_alloc(&PyoaIter_oaDerivedLayerParamDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDerivedLayerParamDefObject* self = (PyoaIter_oaDerivedLayerParamDefObject*)bself;
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
static char oaIter_oaDerivedLayerParamDef_getNext_doc[] = 
"Class: oaIter_oaDerivedLayerParamDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerParamDef* getNext()\n"
"    Signature: getNext|ptr-oaDerivedLayerParamDef|\n"
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
oaIter_oaDerivedLayerParamDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerParamDef data;
    int convert_status=PyoaIter_oaDerivedLayerParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerParamDefObject* self=(PyoaIter_oaDerivedLayerParamDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerParamDefp result= (data.DataCall()->getNext());
        return PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerParamDef_next_doc[] = 
"Class: oaIter_oaDerivedLayerParamDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDerivedLayerParamDef* next()\n"
"    Signature: next|ptr-oaDerivedLayerParamDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDerivedLayerParamDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDerivedLayerParamDef data;
    int convert_status=PyoaIter_oaDerivedLayerParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDerivedLayerParamDefObject* self=(PyoaIter_oaDerivedLayerParamDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDerivedLayerParamDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDerivedLayerParamDef_assign_doc[] = 
"Class: oaIter_oaDerivedLayerParamDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDerivedLayerParamDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDerivedLayerParamDef data;
  int convert_status=PyoaIter_oaDerivedLayerParamDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDerivedLayerParamDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDerivedLayerParamDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDerivedLayerParamDef_getNext,METH_VARARGS,oaIter_oaDerivedLayerParamDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDerivedLayerParamDef_next,METH_VARARGS,oaIter_oaDerivedLayerParamDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaDerivedLayerParamDef_tp_assign,METH_VARARGS,oaIter_oaDerivedLayerParamDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDerivedLayerParamDef_doc[] = 
"Class: oaIter_oaDerivedLayerParamDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDerivedLayerParamDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDerivedLayerParamDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDerivedLayerParamDef)\n"
"    Calls: oaIter_oaDerivedLayerParamDef(const oaIter_oaDerivedLayerParamDef& iterIn)\n"
"    Signature: oaIter_oaDerivedLayerParamDef||cref-oaIter_oaDerivedLayerParamDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDerivedLayerParamDef)\n"
"    Calls: (const oaIter_oaDerivedLayerParamDef&)\n"
"    Signature: oaIter_oaDerivedLayerParamDef||cref-oaIter_oaDerivedLayerParamDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDerivedLayerParamDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDerivedLayerParamDef",
    sizeof(PyoaIter_oaDerivedLayerParamDefObject),
    0,
    (destructor)oaIter_oaDerivedLayerParamDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDerivedLayerParamDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDerivedLayerParamDef_tp_repr,	/* tp_repr */
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
    oaIter_oaDerivedLayerParamDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDerivedLayerParamDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDerivedLayerParamDef_iternext,	/* tp_iternext */
    oaIter_oaDerivedLayerParamDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDerivedLayerParamDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDerivedLayerParamDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDerivedLayerParamDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDerivedLayerParamDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDerivedLayerParamDef",
           (PyObject*)(&PyoaIter_oaDerivedLayerParamDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDerivedLayerParamDef\n");
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
// Wrapper Implementation for Class: oaIter_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDesignObject* self = (PyoaIter_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesign_oaDesign)
    {
        PyParamoaCollection_oaDesign_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesign_oaDesign_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDesign)
    {
        PyParamoaIter_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDesign_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDesign, Choices are:\n"
        "    (oaCollection_oaDesign_oaDesign)\n"
        "    (oaIter_oaDesign)\n"
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
oaIter_oaDesign_tp_dealloc(PyoaIter_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDesign value;
    int convert_status=PyoaIter_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDesign v1;
    PyParamoaIter_oaDesign v2;
    int convert_status1=PyoaIter_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesign_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesign_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDesign ob;
    int convert_status=PyoaIter_oaDesign_Convert(self,&ob);
    assert(convert_status!=0);
    oaDesign* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDesign_FromoaDesign(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDesign_Convert(PyObject* ob,PyParamoaIter_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDesign_Check(ob)) {
        result->SetData( (oaIter_oaDesign*) ((PyoaIter_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDesign_FromoaIter_oaDesign(oaIter_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDesign_Type.tp_alloc(&PyoaIter_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDesignObject* self = (PyoaIter_oaDesignObject*)bself;
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
static char oaIter_oaDesign_getNext_doc[] = 
"Class: oaIter_oaDesign, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDesign* getNext()\n"
"    Signature: getNext|ptr-oaDesign|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaDesign_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesign data;
    int convert_status=PyoaIter_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignObject* self=(PyoaIter_oaDesignObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignp result= (data.DataCall()->getNext());
        return PyoaDesign_FromoaDesign(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDesign_next_doc[] = 
"Class: oaIter_oaDesign, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDesign* next()\n"
"    Signature: next|ptr-oaDesign|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDesign_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesign data;
    int convert_status=PyoaIter_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignObject* self=(PyoaIter_oaDesignObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDesign_FromoaDesign(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDesign_assign_doc[] = 
"Class: oaIter_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDesign data;
  int convert_status=PyoaIter_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDesign_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDesign_getNext,METH_VARARGS,oaIter_oaDesign_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDesign_next,METH_VARARGS,oaIter_oaDesign_next_doc},
    {"assign",(PyCFunction)oaIter_oaDesign_tp_assign,METH_VARARGS,oaIter_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDesign_doc[] = 
"Class: oaIter_oaDesign\n"
"  Class type oaIter_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaDesign_oaDesign)\n"
"    Calls: oaIter_oaDesign(const oaCollection_oaDesign_oaDesign& c)\n"
"    Signature: oaIter_oaDesign||cref-oaCollection_oaDesign_oaDesign,\n"
"    Constructor oaIter_oaDesign\n"
"  Paramegers: (oaIter_oaDesign)\n"
"    Calls: oaIter_oaDesign(const oaIter_oaDesign& iterIn)\n"
"    Signature: oaIter_oaDesign||cref-oaIter_oaDesign,\n"
"    Constructor oaIter_oaDesign\n"
"  Paramegers: (oaIter_oaDesign)\n"
"    Calls: (const oaIter_oaDesign&)\n"
"    Signature: oaIter_oaDesign||cref-oaIter_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDesign",
    sizeof(PyoaIter_oaDesignObject),
    0,
    (destructor)oaIter_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDesign_tp_repr,	/* tp_repr */
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
    oaIter_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDesign_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDesign_iternext,	/* tp_iternext */
    oaIter_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDesign",
           (PyObject*)(&PyoaIter_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDesign\n");
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
// Wrapper Implementation for Class: oaIter_oaDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDesignInstObject* self = (PyoaIter_oaDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDesignInst)
    {
        PyParamoaIter_oaDesignInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDesignInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDesignInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDesignInst)\n"
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
oaIter_oaDesignInst_tp_dealloc(PyoaIter_oaDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDesignInst value;
    int convert_status=PyoaIter_oaDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDesignInst v1;
    PyParamoaIter_oaDesignInst v2;
    int convert_status1=PyoaIter_oaDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDesignInst ob;
    int convert_status=PyoaIter_oaDesignInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaDesignInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDesignInst_FromoaDesignInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDesignInst_Convert(PyObject* ob,PyParamoaIter_oaDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDesignInst_Check(ob)) {
        result->SetData( (oaIter_oaDesignInst*) ((PyoaIter_oaDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDesignInst_FromoaIter_oaDesignInst(oaIter_oaDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDesignInst_Type.tp_alloc(&PyoaIter_oaDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDesignInstObject* self = (PyoaIter_oaDesignInstObject*)bself;
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
static char oaIter_oaDesignInst_getNext_doc[] = 
"Class: oaIter_oaDesignInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDesignInst* getNext()\n"
"    Signature: getNext|ptr-oaDesignInst|\n"
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
oaIter_oaDesignInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesignInst data;
    int convert_status=PyoaIter_oaDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignInstObject* self=(PyoaIter_oaDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignInstp result= (data.DataCall()->getNext());
        return PyoaDesignInst_FromoaDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDesignInst_next_doc[] = 
"Class: oaIter_oaDesignInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDesignInst* next()\n"
"    Signature: next|ptr-oaDesignInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDesignInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesignInst data;
    int convert_status=PyoaIter_oaDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignInstObject* self=(PyoaIter_oaDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDesignInst_FromoaDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDesignInst_assign_doc[] = 
"Class: oaIter_oaDesignInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDesignInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDesignInst data;
  int convert_status=PyoaIter_oaDesignInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDesignInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDesignInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDesignInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDesignInst_getNext,METH_VARARGS,oaIter_oaDesignInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDesignInst_next,METH_VARARGS,oaIter_oaDesignInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaDesignInst_tp_assign,METH_VARARGS,oaIter_oaDesignInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDesignInst_doc[] = 
"Class: oaIter_oaDesignInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDesignInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDesignInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDesignInst)\n"
"    Calls: oaIter_oaDesignInst(const oaIter_oaDesignInst& iterIn)\n"
"    Signature: oaIter_oaDesignInst||cref-oaIter_oaDesignInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDesignInst)\n"
"    Calls: (const oaIter_oaDesignInst&)\n"
"    Signature: oaIter_oaDesignInst||cref-oaIter_oaDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDesignInst",
    sizeof(PyoaIter_oaDesignInstObject),
    0,
    (destructor)oaIter_oaDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDesignInst_tp_repr,	/* tp_repr */
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
    oaIter_oaDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDesignInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDesignInst_iternext,	/* tp_iternext */
    oaIter_oaDesignInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDesignInst",
           (PyObject*)(&PyoaIter_oaDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDesignInst\n");
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
// Wrapper Implementation for Class: oaIter_oaDesignObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDesignObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDesignObjectObject* self = (PyoaIter_oaDesignObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesignObject_oaNode)
    {
        PyParamoaCollection_oaDesignObject_oaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignObject_oaNode_Convert,&p1)) {
            self->value = (oaDesignObjectIter*)  new oaIter_oaDesignObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaDesignObject_oaParasiticNetwork)
    {
        PyParamoaCollection_oaDesignObject_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaDesignObjectIter*)  new oaIter_oaDesignObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDesignObject)
    {
        PyParamoaIter_oaDesignObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDesignObject_Convert,&p1)) {
            self->value = (oaDesignObjectIter*)  new oaIter_oaDesignObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDesignObject, Choices are:\n"
        "    (oaCollection_oaDesignObject_oaNode)\n"
        "    (oaCollection_oaDesignObject_oaParasiticNetwork)\n"
        "    (oaIter_oaDesignObject)\n"
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
oaIter_oaDesignObject_tp_dealloc(PyoaIter_oaDesignObjectObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDesignObject*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignObject_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDesignObject value;
    int convert_status=PyoaIter_oaDesignObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaDesignObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDesignObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDesignObject v1;
    PyParamoaIter_oaDesignObject v2;
    int convert_status1=PyoaIter_oaDesignObject_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDesignObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignObject_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDesignObject_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDesignObject ob;
    int convert_status=PyoaIter_oaDesignObject_Convert(self,&ob);
    assert(convert_status!=0);
    oaDesignObject* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDesignObject_FromoaDesignObject(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDesignObject_Convert(PyObject* ob,PyParamoaIter_oaDesignObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDesignObject_Check(ob)) {
        result->SetData( (oaIter_oaDesignObject*) ((PyoaIter_oaDesignObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDesignObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDesignObject_FromoaIter_oaDesignObject(oaIter_oaDesignObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDesignObject_Type.tp_alloc(&PyoaIter_oaDesignObject_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDesignObjectObject* self = (PyoaIter_oaDesignObjectObject*)bself;
        self->value = (oaDesignObjectIter*)  data;
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
static char oaIter_oaDesignObject_getNext_doc[] = 
"Class: oaIter_oaDesignObject, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getNext()\n"
"    Signature: getNext|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaDesignObject_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesignObject data;
    int convert_status=PyoaIter_oaDesignObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignObjectObject* self=(PyoaIter_oaDesignObjectObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getNext());
        return PyoaDesignObject_FromoaDesignObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDesignObject_next_doc[] = 
"Class: oaIter_oaDesignObject, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* next()\n"
"    Signature: next|ptr-oaDesignObject|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDesignObject_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDesignObject data;
    int convert_status=PyoaIter_oaDesignObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDesignObjectObject* self=(PyoaIter_oaDesignObjectObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDesignObject_FromoaDesignObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDesignObject_assign_doc[] = 
"Class: oaIter_oaDesignObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDesignObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDesignObject data;
  int convert_status=PyoaIter_oaDesignObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDesignObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDesignObject_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDesignObject_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDesignObject_getNext,METH_VARARGS,oaIter_oaDesignObject_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDesignObject_next,METH_VARARGS,oaIter_oaDesignObject_next_doc},
    {"assign",(PyCFunction)oaIter_oaDesignObject_tp_assign,METH_VARARGS,oaIter_oaDesignObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDesignObject_doc[] = 
"Class: oaIter_oaDesignObject\n"
"  Class type oaIter_oaDesignObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaDesignObject_oaNode)\n"
"    Calls: oaIter_oaDesignObject(const oaCollection_oaDesignObject_oaNode& c)\n"
"    Signature: oaIter_oaDesignObject||cref-oaCollection_oaDesignObject_oaNode,\n"
"    Constructor oaIter_oaDesignObject\n"
"  Paramegers: (oaCollection_oaDesignObject_oaParasiticNetwork)\n"
"    Calls: oaIter_oaDesignObject(const oaCollection_oaDesignObject_oaParasiticNetwork& c)\n"
"    Signature: oaIter_oaDesignObject||cref-oaCollection_oaDesignObject_oaParasiticNetwork,\n"
"    Constructor oaIter_oaDesignObject\n"
"  Paramegers: (oaIter_oaDesignObject)\n"
"    Calls: oaIter_oaDesignObject(const oaIter_oaDesignObject& iter)\n"
"    Signature: oaIter_oaDesignObject||cref-oaIter_oaDesignObject,\n"
"    Constructor oaIter_oaDesignObject\n"
"  Paramegers: (oaIter_oaDesignObject)\n"
"    Calls: (const oaIter_oaDesignObject&)\n"
"    Signature: oaIter_oaDesignObject||cref-oaIter_oaDesignObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDesignObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDesignObject",
    sizeof(PyoaIter_oaDesignObjectObject),
    0,
    (destructor)oaIter_oaDesignObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDesignObject_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDesignObject_tp_repr,	/* tp_repr */
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
    oaIter_oaDesignObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDesignObject_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDesignObject_iternext,	/* tp_iternext */
    oaIter_oaDesignObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignObjectIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDesignObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDesignObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDesignObject_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDesignObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDesignObject",
           (PyObject*)(&PyoaIter_oaDesignObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDesignObject\n");
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
// Wrapper Implementation for Class: oaIter_oaDevice
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaDevice_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaDeviceObject* self = (PyoaIter_oaDeviceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDevice(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaDevice)
    {
        PyParamoaIter_oaDevice p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaDevice_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaDevice(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaDevice, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaDevice)\n"
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
oaIter_oaDevice_tp_dealloc(PyoaIter_oaDeviceObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaDevice*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDevice_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaDevice value;
    int convert_status=PyoaIter_oaDevice_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaDevice::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaDevice_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaDevice v1;
    PyParamoaIter_oaDevice v2;
    int convert_status1=PyoaIter_oaDevice_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaDevice_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaDevice_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaDevice_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaDevice ob;
    int convert_status=PyoaIter_oaDevice_Convert(self,&ob);
    assert(convert_status!=0);
    oaDevice* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDevice_FromoaDevice(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaDevice_Convert(PyObject* ob,PyParamoaIter_oaDevice* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaDevice_Check(ob)) {
        result->SetData( (oaIter_oaDevice*) ((PyoaIter_oaDeviceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaDevice Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaDevice_FromoaIter_oaDevice(oaIter_oaDevice* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaDevice_Type.tp_alloc(&PyoaIter_oaDevice_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaDeviceObject* self = (PyoaIter_oaDeviceObject*)bself;
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
static char oaIter_oaDevice_getNext_doc[] = 
"Class: oaIter_oaDevice, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaDevice* getNext()\n"
"    Signature: getNext|ptr-oaDevice|\n"
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
oaIter_oaDevice_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDevice data;
    int convert_status=PyoaIter_oaDevice_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDeviceObject* self=(PyoaIter_oaDeviceObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDevicep result= (data.DataCall()->getNext());
        return PyoaDevice_FromoaDevice(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaDevice_next_doc[] = 
"Class: oaIter_oaDevice, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaDevice* next()\n"
"    Signature: next|ptr-oaDevice|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaDevice_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaDevice data;
    int convert_status=PyoaIter_oaDevice_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaDeviceObject* self=(PyoaIter_oaDeviceObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDevicep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaDevice_FromoaDevice(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaDevice_assign_doc[] = 
"Class: oaIter_oaDevice, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaDevice_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaDevice data;
  int convert_status=PyoaIter_oaDevice_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaDevice p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaDevice_Convert,&p1)) {
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

static PyMethodDef oaIter_oaDevice_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaDevice_getNext,METH_VARARGS,oaIter_oaDevice_getNext_doc},
    {"next",(PyCFunction)oaIter_oaDevice_next,METH_VARARGS,oaIter_oaDevice_next_doc},
    {"assign",(PyCFunction)oaIter_oaDevice_tp_assign,METH_VARARGS,oaIter_oaDevice_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaDevice_doc[] = 
"Class: oaIter_oaDevice\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaDevice(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaDevice||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaDevice)\n"
"    Calls: oaIter_oaDevice(const oaIter_oaDevice& iterIn)\n"
"    Signature: oaIter_oaDevice||cref-oaIter_oaDevice,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaDevice)\n"
"    Calls: (const oaIter_oaDevice&)\n"
"    Signature: oaIter_oaDevice||cref-oaIter_oaDevice,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaDevice_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaDevice",
    sizeof(PyoaIter_oaDeviceObject),
    0,
    (destructor)oaIter_oaDevice_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaDevice_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaDevice_tp_repr,	/* tp_repr */
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
    oaIter_oaDevice_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaDevice_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaDevice_iternext,	/* tp_iternext */
    oaIter_oaDevice_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaDevice_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaDevice_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaDevice_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaDevice\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaDevice",
           (PyObject*)(&PyoaIter_oaDevice_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaDevice\n");
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
// Wrapper Implementation for Class: oaIter_oaElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaElmoreObject* self = (PyoaIter_oaElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaElmore(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaElmore)
    {
        PyParamoaIter_oaElmore p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaElmore_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaElmore(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaElmore, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaElmore)\n"
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
oaIter_oaElmore_tp_dealloc(PyoaIter_oaElmoreObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaElmore*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaElmore_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaElmore value;
    int convert_status=PyoaIter_oaElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaElmore v1;
    PyParamoaIter_oaElmore v2;
    int convert_status1=PyoaIter_oaElmore_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaElmore_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaElmore_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaElmore ob;
    int convert_status=PyoaIter_oaElmore_Convert(self,&ob);
    assert(convert_status!=0);
    oaElmore* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaElmore_FromoaElmore(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaElmore_Convert(PyObject* ob,PyParamoaIter_oaElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaElmore_Check(ob)) {
        result->SetData( (oaIter_oaElmore*) ((PyoaIter_oaElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaElmore_FromoaIter_oaElmore(oaIter_oaElmore* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaElmore_Type.tp_alloc(&PyoaIter_oaElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaElmoreObject* self = (PyoaIter_oaElmoreObject*)bself;
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
static char oaIter_oaElmore_getNext_doc[] = 
"Class: oaIter_oaElmore, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaElmore* getNext()\n"
"    Signature: getNext|ptr-oaElmore|\n"
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
oaIter_oaElmore_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaElmore data;
    int convert_status=PyoaIter_oaElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaElmoreObject* self=(PyoaIter_oaElmoreObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaElmorep result= (data.DataCall()->getNext());
        return PyoaElmore_FromoaElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaElmore_next_doc[] = 
"Class: oaIter_oaElmore, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaElmore* next()\n"
"    Signature: next|ptr-oaElmore|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaElmore_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaElmore data;
    int convert_status=PyoaIter_oaElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaElmoreObject* self=(PyoaIter_oaElmoreObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaElmorep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaElmore_FromoaElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaElmore_assign_doc[] = 
"Class: oaIter_oaElmore, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaElmore_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaElmore data;
  int convert_status=PyoaIter_oaElmore_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaElmore p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaElmore_Convert,&p1)) {
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

static PyMethodDef oaIter_oaElmore_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaElmore_getNext,METH_VARARGS,oaIter_oaElmore_getNext_doc},
    {"next",(PyCFunction)oaIter_oaElmore_next,METH_VARARGS,oaIter_oaElmore_next_doc},
    {"assign",(PyCFunction)oaIter_oaElmore_tp_assign,METH_VARARGS,oaIter_oaElmore_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaElmore_doc[] = 
"Class: oaIter_oaElmore\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaElmore(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaElmore||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaElmore)\n"
"    Calls: oaIter_oaElmore(const oaIter_oaElmore& iterIn)\n"
"    Signature: oaIter_oaElmore||cref-oaIter_oaElmore,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaElmore)\n"
"    Calls: (const oaIter_oaElmore&)\n"
"    Signature: oaIter_oaElmore||cref-oaIter_oaElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaElmore",
    sizeof(PyoaIter_oaElmoreObject),
    0,
    (destructor)oaIter_oaElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaElmore_tp_repr,	/* tp_repr */
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
    oaIter_oaElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaElmore_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaElmore_iternext,	/* tp_iternext */
    oaIter_oaElmore_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaElmore",
           (PyObject*)(&PyoaIter_oaElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaElmore\n");
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
// Wrapper Implementation for Class: oaIter_oaFigGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaFigGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaFigGroupObject* self = (PyoaIter_oaFigGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFigGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaFigGroup)
    {
        PyParamoaIter_oaFigGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaFigGroup_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFigGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaFigGroup, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaFigGroup)\n"
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
oaIter_oaFigGroup_tp_dealloc(PyoaIter_oaFigGroupObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaFigGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroup_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaFigGroup value;
    int convert_status=PyoaIter_oaFigGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaIter_oaFigGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaFigGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaFigGroup v1;
    PyParamoaIter_oaFigGroup v2;
    int convert_status1=PyoaIter_oaFigGroup_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaFigGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroup_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroup_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaFigGroup ob;
    int convert_status=PyoaIter_oaFigGroup_Convert(self,&ob);
    assert(convert_status!=0);
    oaFigGroup* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaFigGroup_FromoaFigGroup(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaFigGroup_Convert(PyObject* ob,PyParamoaIter_oaFigGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaFigGroup_Check(ob)) {
        result->SetData( (oaIter_oaFigGroup*) ((PyoaIter_oaFigGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaFigGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaFigGroup_FromoaIter_oaFigGroup(oaIter_oaFigGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaFigGroup_Type.tp_alloc(&PyoaIter_oaFigGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaFigGroupObject* self = (PyoaIter_oaFigGroupObject*)bself;
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
static char oaIter_oaFigGroup_getNext_doc[] = 
"Class: oaIter_oaFigGroup, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaFigGroup* getNext()\n"
"    Signature: getNext|ptr-oaFigGroup|\n"
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
oaIter_oaFigGroup_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFigGroup data;
    int convert_status=PyoaIter_oaFigGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFigGroupObject* self=(PyoaIter_oaFigGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFigGroupp result= (data.DataCall()->getNext());
        return PyoaFigGroup_FromoaFigGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaFigGroup_next_doc[] = 
"Class: oaIter_oaFigGroup, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaFigGroup* next()\n"
"    Signature: next|ptr-oaFigGroup|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaFigGroup_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFigGroup data;
    int convert_status=PyoaIter_oaFigGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFigGroupObject* self=(PyoaIter_oaFigGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFigGroupp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaFigGroup_FromoaFigGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaFigGroup_assign_doc[] = 
"Class: oaIter_oaFigGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaFigGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaFigGroup data;
  int convert_status=PyoaIter_oaFigGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaFigGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaFigGroup_Convert,&p1)) {
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

static PyMethodDef oaIter_oaFigGroup_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaFigGroup_getNext,METH_VARARGS,oaIter_oaFigGroup_getNext_doc},
    {"next",(PyCFunction)oaIter_oaFigGroup_next,METH_VARARGS,oaIter_oaFigGroup_next_doc},
    {"assign",(PyCFunction)oaIter_oaFigGroup_tp_assign,METH_VARARGS,oaIter_oaFigGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaFigGroup_doc[] = 
"Class: oaIter_oaFigGroup\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaFigGroup(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaFigGroup||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaFigGroup)\n"
"    Calls: oaIter_oaFigGroup(const oaIter_oaFigGroup& iterIn)\n"
"    Signature: oaIter_oaFigGroup||cref-oaIter_oaFigGroup,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaFigGroup)\n"
"    Calls: (const oaIter_oaFigGroup&)\n"
"    Signature: oaIter_oaFigGroup||cref-oaIter_oaFigGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaFigGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaFigGroup",
    sizeof(PyoaIter_oaFigGroupObject),
    0,
    (destructor)oaIter_oaFigGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaFigGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaFigGroup_tp_repr,	/* tp_repr */
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
    oaIter_oaFigGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaFigGroup_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaFigGroup_iternext,	/* tp_iternext */
    oaIter_oaFigGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaFigGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaFigGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaFigGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaFigGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaFigGroup",
           (PyObject*)(&PyoaIter_oaFigGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaFigGroup\n");
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
// Wrapper Implementation for Class: oaIter_oaFigGroupMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroupMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaFigGroupMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaFigGroupMemObject* self = (PyoaIter_oaFigGroupMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFigGroupMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaFigGroupMem)
    {
        PyParamoaIter_oaFigGroupMem p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaFigGroupMem_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFigGroupMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaFigGroupMem, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaFigGroupMem)\n"
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
oaIter_oaFigGroupMem_tp_dealloc(PyoaIter_oaFigGroupMemObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaFigGroupMem*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroupMem_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaFigGroupMem value;
    int convert_status=PyoaIter_oaFigGroupMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaFigGroupMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaFigGroupMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaFigGroupMem v1;
    PyParamoaIter_oaFigGroupMem v2;
    int convert_status1=PyoaIter_oaFigGroupMem_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaFigGroupMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroupMem_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFigGroupMem_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaFigGroupMem ob;
    int convert_status=PyoaIter_oaFigGroupMem_Convert(self,&ob);
    assert(convert_status!=0);
    oaFigGroupMem* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaFigGroupMem_FromoaFigGroupMem(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaFigGroupMem_Convert(PyObject* ob,PyParamoaIter_oaFigGroupMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaFigGroupMem_Check(ob)) {
        result->SetData( (oaIter_oaFigGroupMem*) ((PyoaIter_oaFigGroupMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaFigGroupMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaFigGroupMem_FromoaIter_oaFigGroupMem(oaIter_oaFigGroupMem* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaFigGroupMem_Type.tp_alloc(&PyoaIter_oaFigGroupMem_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaFigGroupMemObject* self = (PyoaIter_oaFigGroupMemObject*)bself;
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
static char oaIter_oaFigGroupMem_getNext_doc[] = 
"Class: oaIter_oaFigGroupMem, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaFigGroupMem* getNext()\n"
"    Signature: getNext|ptr-oaFigGroupMem|\n"
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
oaIter_oaFigGroupMem_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFigGroupMem data;
    int convert_status=PyoaIter_oaFigGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFigGroupMemObject* self=(PyoaIter_oaFigGroupMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFigGroupMemp result= (data.DataCall()->getNext());
        return PyoaFigGroupMem_FromoaFigGroupMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaFigGroupMem_next_doc[] = 
"Class: oaIter_oaFigGroupMem, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaFigGroupMem* next()\n"
"    Signature: next|ptr-oaFigGroupMem|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaFigGroupMem_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFigGroupMem data;
    int convert_status=PyoaIter_oaFigGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFigGroupMemObject* self=(PyoaIter_oaFigGroupMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFigGroupMemp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaFigGroupMem_FromoaFigGroupMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaFigGroupMem_assign_doc[] = 
"Class: oaIter_oaFigGroupMem, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaFigGroupMem_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaFigGroupMem data;
  int convert_status=PyoaIter_oaFigGroupMem_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaFigGroupMem p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaFigGroupMem_Convert,&p1)) {
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

static PyMethodDef oaIter_oaFigGroupMem_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaFigGroupMem_getNext,METH_VARARGS,oaIter_oaFigGroupMem_getNext_doc},
    {"next",(PyCFunction)oaIter_oaFigGroupMem_next,METH_VARARGS,oaIter_oaFigGroupMem_next_doc},
    {"assign",(PyCFunction)oaIter_oaFigGroupMem_tp_assign,METH_VARARGS,oaIter_oaFigGroupMem_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaFigGroupMem_doc[] = 
"Class: oaIter_oaFigGroupMem\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaFigGroupMem(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaFigGroupMem||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaFigGroupMem)\n"
"    Calls: oaIter_oaFigGroupMem(const oaIter_oaFigGroupMem& iterIn)\n"
"    Signature: oaIter_oaFigGroupMem||cref-oaIter_oaFigGroupMem,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaFigGroupMem)\n"
"    Calls: (const oaIter_oaFigGroupMem&)\n"
"    Signature: oaIter_oaFigGroupMem||cref-oaIter_oaFigGroupMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaFigGroupMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaFigGroupMem",
    sizeof(PyoaIter_oaFigGroupMemObject),
    0,
    (destructor)oaIter_oaFigGroupMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaFigGroupMem_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaFigGroupMem_tp_repr,	/* tp_repr */
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
    oaIter_oaFigGroupMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaFigGroupMem_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaFigGroupMem_iternext,	/* tp_iternext */
    oaIter_oaFigGroupMem_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaFigGroupMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaFigGroupMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaFigGroupMem_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaFigGroupMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaFigGroupMem",
           (PyObject*)(&PyoaIter_oaFigGroupMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaFigGroupMem\n");
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
// Wrapper Implementation for Class: oaIter_oaFrame
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrame_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaFrame_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaFrameObject* self = (PyoaIter_oaFrameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFrame(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaFrame)
    {
        PyParamoaIter_oaFrame p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaFrame_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFrame(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaFrame, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaFrame)\n"
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
oaIter_oaFrame_tp_dealloc(PyoaIter_oaFrameObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaFrame*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrame_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaFrame value;
    int convert_status=PyoaIter_oaFrame_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaFrame::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaFrame_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaFrame v1;
    PyParamoaIter_oaFrame v2;
    int convert_status1=PyoaIter_oaFrame_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaFrame_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrame_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrame_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaFrame ob;
    int convert_status=PyoaIter_oaFrame_Convert(self,&ob);
    assert(convert_status!=0);
    oaFrame* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaFrame_FromoaFrame(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaFrame_Convert(PyObject* ob,PyParamoaIter_oaFrame* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaFrame_Check(ob)) {
        result->SetData( (oaIter_oaFrame*) ((PyoaIter_oaFrameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaFrame Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaFrame_FromoaIter_oaFrame(oaIter_oaFrame* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaFrame_Type.tp_alloc(&PyoaIter_oaFrame_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaFrameObject* self = (PyoaIter_oaFrameObject*)bself;
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
static char oaIter_oaFrame_getNext_doc[] = 
"Class: oaIter_oaFrame, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaFrame* getNext()\n"
"    Signature: getNext|ptr-oaFrame|\n"
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
oaIter_oaFrame_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFrame data;
    int convert_status=PyoaIter_oaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFrameObject* self=(PyoaIter_oaFrameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFramep result= (data.DataCall()->getNext());
        return PyoaFrame_FromoaFrame(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaFrame_next_doc[] = 
"Class: oaIter_oaFrame, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaFrame* next()\n"
"    Signature: next|ptr-oaFrame|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaFrame_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFrame data;
    int convert_status=PyoaIter_oaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFrameObject* self=(PyoaIter_oaFrameObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFramep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaFrame_FromoaFrame(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaFrame_assign_doc[] = 
"Class: oaIter_oaFrame, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaFrame_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaFrame data;
  int convert_status=PyoaIter_oaFrame_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaFrame p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaFrame_Convert,&p1)) {
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

static PyMethodDef oaIter_oaFrame_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaFrame_getNext,METH_VARARGS,oaIter_oaFrame_getNext_doc},
    {"next",(PyCFunction)oaIter_oaFrame_next,METH_VARARGS,oaIter_oaFrame_next_doc},
    {"assign",(PyCFunction)oaIter_oaFrame_tp_assign,METH_VARARGS,oaIter_oaFrame_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaFrame_doc[] = 
"Class: oaIter_oaFrame\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaFrame(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaFrame||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaFrame)\n"
"    Calls: oaIter_oaFrame(const oaIter_oaFrame& iterIn)\n"
"    Signature: oaIter_oaFrame||cref-oaIter_oaFrame,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaFrame)\n"
"    Calls: (const oaIter_oaFrame&)\n"
"    Signature: oaIter_oaFrame||cref-oaIter_oaFrame,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaFrame_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaFrame",
    sizeof(PyoaIter_oaFrameObject),
    0,
    (destructor)oaIter_oaFrame_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaFrame_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaFrame_tp_repr,	/* tp_repr */
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
    oaIter_oaFrame_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaFrame_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaFrame_iternext,	/* tp_iternext */
    oaIter_oaFrame_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaFrame_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaFrame_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaFrame_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaFrame\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaFrame",
           (PyObject*)(&PyoaIter_oaFrame_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaFrame\n");
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
// Wrapper Implementation for Class: oaIter_oaFrameInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrameInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaFrameInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaFrameInstObject* self = (PyoaIter_oaFrameInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFrameInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaFrameInst)
    {
        PyParamoaIter_oaFrameInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaFrameInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaFrameInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaFrameInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaFrameInst)\n"
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
oaIter_oaFrameInst_tp_dealloc(PyoaIter_oaFrameInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaFrameInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrameInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaFrameInst value;
    int convert_status=PyoaIter_oaFrameInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaFrameInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaFrameInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaFrameInst v1;
    PyParamoaIter_oaFrameInst v2;
    int convert_status1=PyoaIter_oaFrameInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaFrameInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrameInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaFrameInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaFrameInst ob;
    int convert_status=PyoaIter_oaFrameInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaFrameInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaFrameInst_FromoaFrameInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaFrameInst_Convert(PyObject* ob,PyParamoaIter_oaFrameInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaFrameInst_Check(ob)) {
        result->SetData( (oaIter_oaFrameInst*) ((PyoaIter_oaFrameInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaFrameInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaFrameInst_FromoaIter_oaFrameInst(oaIter_oaFrameInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaFrameInst_Type.tp_alloc(&PyoaIter_oaFrameInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaFrameInstObject* self = (PyoaIter_oaFrameInstObject*)bself;
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
static char oaIter_oaFrameInst_getNext_doc[] = 
"Class: oaIter_oaFrameInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaFrameInst* getNext()\n"
"    Signature: getNext|ptr-oaFrameInst|\n"
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
oaIter_oaFrameInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFrameInst data;
    int convert_status=PyoaIter_oaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFrameInstObject* self=(PyoaIter_oaFrameInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFrameInstp result= (data.DataCall()->getNext());
        return PyoaFrameInst_FromoaFrameInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaFrameInst_next_doc[] = 
"Class: oaIter_oaFrameInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaFrameInst* next()\n"
"    Signature: next|ptr-oaFrameInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaFrameInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaFrameInst data;
    int convert_status=PyoaIter_oaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaFrameInstObject* self=(PyoaIter_oaFrameInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFrameInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaFrameInst_FromoaFrameInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaFrameInst_assign_doc[] = 
"Class: oaIter_oaFrameInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaFrameInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaFrameInst data;
  int convert_status=PyoaIter_oaFrameInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaFrameInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaFrameInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaFrameInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaFrameInst_getNext,METH_VARARGS,oaIter_oaFrameInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaFrameInst_next,METH_VARARGS,oaIter_oaFrameInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaFrameInst_tp_assign,METH_VARARGS,oaIter_oaFrameInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaFrameInst_doc[] = 
"Class: oaIter_oaFrameInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaFrameInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaFrameInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaFrameInst)\n"
"    Calls: oaIter_oaFrameInst(const oaIter_oaFrameInst& iterIn)\n"
"    Signature: oaIter_oaFrameInst||cref-oaIter_oaFrameInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaFrameInst)\n"
"    Calls: (const oaIter_oaFrameInst&)\n"
"    Signature: oaIter_oaFrameInst||cref-oaIter_oaFrameInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaFrameInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaFrameInst",
    sizeof(PyoaIter_oaFrameInstObject),
    0,
    (destructor)oaIter_oaFrameInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaFrameInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaFrameInst_tp_repr,	/* tp_repr */
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
    oaIter_oaFrameInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaFrameInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaFrameInst_iternext,	/* tp_iternext */
    oaIter_oaFrameInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaFrameInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaFrameInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaFrameInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaFrameInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaFrameInst",
           (PyObject*)(&PyoaIter_oaFrameInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaFrameInst\n");
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
// Wrapper Implementation for Class: oaIter_oaGCellPattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGCellPattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaGCellPattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaGCellPatternObject* self = (PyoaIter_oaGCellPatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaGCellPattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaGCellPattern)
    {
        PyParamoaIter_oaGCellPattern p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaGCellPattern_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaGCellPattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaGCellPattern, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaGCellPattern)\n"
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
oaIter_oaGCellPattern_tp_dealloc(PyoaIter_oaGCellPatternObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaGCellPattern*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGCellPattern_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaGCellPattern value;
    int convert_status=PyoaIter_oaGCellPattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaGCellPattern::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaGCellPattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaGCellPattern v1;
    PyParamoaIter_oaGCellPattern v2;
    int convert_status1=PyoaIter_oaGCellPattern_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaGCellPattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaGCellPattern_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGCellPattern_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaGCellPattern ob;
    int convert_status=PyoaIter_oaGCellPattern_Convert(self,&ob);
    assert(convert_status!=0);
    oaGCellPattern* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaGCellPattern_FromoaGCellPattern(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaGCellPattern_Convert(PyObject* ob,PyParamoaIter_oaGCellPattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaGCellPattern_Check(ob)) {
        result->SetData( (oaIter_oaGCellPattern*) ((PyoaIter_oaGCellPatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaGCellPattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaGCellPattern_FromoaIter_oaGCellPattern(oaIter_oaGCellPattern* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaGCellPattern_Type.tp_alloc(&PyoaIter_oaGCellPattern_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaGCellPatternObject* self = (PyoaIter_oaGCellPatternObject*)bself;
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
static char oaIter_oaGCellPattern_getNext_doc[] = 
"Class: oaIter_oaGCellPattern, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaGCellPattern* getNext()\n"
"    Signature: getNext|ptr-oaGCellPattern|\n"
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
oaIter_oaGCellPattern_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGCellPattern data;
    int convert_status=PyoaIter_oaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGCellPatternObject* self=(PyoaIter_oaGCellPatternObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGCellPatternp result= (data.DataCall()->getNext());
        return PyoaGCellPattern_FromoaGCellPattern(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGCellPattern_next_doc[] = 
"Class: oaIter_oaGCellPattern, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaGCellPattern* next()\n"
"    Signature: next|ptr-oaGCellPattern|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaGCellPattern_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGCellPattern data;
    int convert_status=PyoaIter_oaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGCellPatternObject* self=(PyoaIter_oaGCellPatternObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGCellPatternp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaGCellPattern_FromoaGCellPattern(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaGCellPattern_assign_doc[] = 
"Class: oaIter_oaGCellPattern, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaGCellPattern_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaGCellPattern data;
  int convert_status=PyoaIter_oaGCellPattern_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaGCellPattern p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaGCellPattern_Convert,&p1)) {
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

static PyMethodDef oaIter_oaGCellPattern_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaGCellPattern_getNext,METH_VARARGS,oaIter_oaGCellPattern_getNext_doc},
    {"next",(PyCFunction)oaIter_oaGCellPattern_next,METH_VARARGS,oaIter_oaGCellPattern_next_doc},
    {"assign",(PyCFunction)oaIter_oaGCellPattern_tp_assign,METH_VARARGS,oaIter_oaGCellPattern_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaGCellPattern_doc[] = 
"Class: oaIter_oaGCellPattern\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaGCellPattern(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaGCellPattern||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaGCellPattern)\n"
"    Calls: oaIter_oaGCellPattern(const oaIter_oaGCellPattern& iterIn)\n"
"    Signature: oaIter_oaGCellPattern||cref-oaIter_oaGCellPattern,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaGCellPattern)\n"
"    Calls: (const oaIter_oaGCellPattern&)\n"
"    Signature: oaIter_oaGCellPattern||cref-oaIter_oaGCellPattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaGCellPattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaGCellPattern",
    sizeof(PyoaIter_oaGCellPatternObject),
    0,
    (destructor)oaIter_oaGCellPattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaGCellPattern_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaGCellPattern_tp_repr,	/* tp_repr */
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
    oaIter_oaGCellPattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaGCellPattern_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaGCellPattern_iternext,	/* tp_iternext */
    oaIter_oaGCellPattern_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaGCellPattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaGCellPattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaGCellPattern_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaGCellPattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaGCellPattern",
           (PyObject*)(&PyoaIter_oaGCellPattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaGCellPattern\n");
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
// Wrapper Implementation for Class: oaIter_oaGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaGroupObject* self = (PyoaIter_oaGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroupCollection)
    {
        PyParamoaGroupCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaGroupCollection_Convert,&p1)) {
            self->value =  new oaIter_oaGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaGroup_oaObject)
    {
        PyParamoaCollection_oaGroup_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaObject_Convert,&p1)) {
            self->value =  new oaIter_oaGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaGroup)
    {
        PyParamoaIter_oaGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaGroup_Convert,&p1)) {
            self->value =  new oaIter_oaGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaGroup, Choices are:\n"
        "    (oaGroupCollection)\n"
        "    (oaCollection_oaGroup_oaObject)\n"
        "    (oaIter_oaGroup)\n"
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
oaIter_oaGroup_tp_dealloc(PyoaIter_oaGroupObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroup_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaGroup value;
    int convert_status=PyoaIter_oaGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaGroup v1;
    PyParamoaIter_oaGroup v2;
    int convert_status1=PyoaIter_oaGroup_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroup_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroup_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaGroup ob;
    int convert_status=PyoaIter_oaGroup_Convert(self,&ob);
    assert(convert_status!=0);
    oaGroup* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaGroup_FromoaGroup(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaGroup_Convert(PyObject* ob,PyParamoaIter_oaGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaGroup_Check(ob)) {
        result->SetData(  ((PyoaIter_oaGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaGroup_FromoaIter_oaGroup(oaIter_oaGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaGroup_Type.tp_alloc(&PyoaIter_oaGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaGroupObject* self = (PyoaIter_oaGroupObject*)bself;
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
static char oaIter_oaGroup_getNext_doc[] = 
"Class: oaIter_oaGroup, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaGroup* getNext()\n"
"    Signature: getNext|ptr-oaGroup|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaGroup_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroup data;
    int convert_status=PyoaIter_oaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupObject* self=(PyoaIter_oaGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupp result= (data.DataCall()->getNext());
        return PyoaGroup_FromoaGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGroup_next_doc[] = 
"Class: oaIter_oaGroup, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaGroup* next()\n"
"    Signature: next|ptr-oaGroup|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaGroup_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroup data;
    int convert_status=PyoaIter_oaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupObject* self=(PyoaIter_oaGroupObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaGroup_FromoaGroup(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGroup_reset_doc[] = 
"Class: oaIter_oaGroup, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaGroup_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroup data;
    int convert_status=PyoaIter_oaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupObject* self=(PyoaIter_oaGroupObject*)ob;

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

static char oaIter_oaGroup_assign_doc[] = 
"Class: oaIter_oaGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaGroup data;
  int convert_status=PyoaIter_oaGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaGroup_Convert,&p1)) {
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

static PyMethodDef oaIter_oaGroup_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaGroup_getNext,METH_VARARGS,oaIter_oaGroup_getNext_doc},
    {"next",(PyCFunction)oaIter_oaGroup_next,METH_VARARGS,oaIter_oaGroup_next_doc},
    {"reset",(PyCFunction)oaIter_oaGroup_reset,METH_VARARGS,oaIter_oaGroup_reset_doc},
    {"assign",(PyCFunction)oaIter_oaGroup_tp_assign,METH_VARARGS,oaIter_oaGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaGroup_doc[] = 
"Class: oaIter_oaGroup\n"
"  Class type oaIter_oaGroup\n"
"Constructors:\n"
"  Paramegers: (oaGroupCollection)\n"
"    Calls: oaIter_oaGroup(const oaGroupCollection& c)\n"
"    Signature: oaIter_oaGroup||cref-oaGroupCollection,\n"
"    Constructor oaIter_oaGroup\n"
"  Paramegers: (oaCollection_oaGroup_oaObject)\n"
"    Calls: oaIter_oaGroup(const oaCollection_oaGroup_oaObject& c)\n"
"    Signature: oaIter_oaGroup||cref-oaCollection_oaGroup_oaObject,\n"
"    Constructor oaIter_oaGroup\n"
"  Paramegers: (oaIter_oaGroup)\n"
"    Calls: oaIter_oaGroup(const oaIter_oaGroup& iterIn)\n"
"    Signature: oaIter_oaGroup||cref-oaIter_oaGroup,\n"
"    Constructor oaIter_oaGroup\n"
"  Paramegers: (oaIter_oaGroup)\n"
"    Calls: (const oaIter_oaGroup&)\n"
"    Signature: oaIter_oaGroup||cref-oaIter_oaGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaGroup",
    sizeof(PyoaIter_oaGroupObject),
    0,
    (destructor)oaIter_oaGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaGroup_tp_repr,	/* tp_repr */
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
    oaIter_oaGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaGroup_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaGroup_iternext,	/* tp_iternext */
    oaIter_oaGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaGroup",
           (PyObject*)(&PyoaIter_oaGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaGroup\n");
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
// Wrapper Implementation for Class: oaIter_oaGroupMember
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroupMember_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaGroupMember_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaGroupMemberObject* self = (PyoaIter_oaGroupMemberObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroupMember_oaGroup)
    {
        PyParamoaCollection_oaGroupMember_oaGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroupMember_oaGroup_Convert,&p1)) {
            self->value =  new oaIter_oaGroupMember(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaGroupMember_oaObject)
    {
        PyParamoaCollection_oaGroupMember_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroupMember_oaObject_Convert,&p1)) {
            self->value =  new oaIter_oaGroupMember(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaGroupMember)
    {
        PyParamoaIter_oaGroupMember p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaGroupMember_Convert,&p1)) {
            self->value =  new oaIter_oaGroupMember(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaGroupMember, Choices are:\n"
        "    (oaCollection_oaGroupMember_oaGroup)\n"
        "    (oaCollection_oaGroupMember_oaObject)\n"
        "    (oaIter_oaGroupMember)\n"
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
oaIter_oaGroupMember_tp_dealloc(PyoaIter_oaGroupMemberObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroupMember_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaGroupMember value;
    int convert_status=PyoaIter_oaGroupMember_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaGroupMember::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaGroupMember_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaGroupMember v1;
    PyParamoaIter_oaGroupMember v2;
    int convert_status1=PyoaIter_oaGroupMember_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaGroupMember_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroupMember_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGroupMember_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaGroupMember ob;
    int convert_status=PyoaIter_oaGroupMember_Convert(self,&ob);
    assert(convert_status!=0);
    oaGroupMember* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaGroupMember_FromoaGroupMember(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaGroupMember_Convert(PyObject* ob,PyParamoaIter_oaGroupMember* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaGroupMember_Check(ob)) {
        result->SetData(  ((PyoaIter_oaGroupMemberObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaGroupMember Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaGroupMember_FromoaIter_oaGroupMember(oaIter_oaGroupMember* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaGroupMember_Type.tp_alloc(&PyoaIter_oaGroupMember_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaGroupMemberObject* self = (PyoaIter_oaGroupMemberObject*)bself;
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
static char oaIter_oaGroupMember_getNext_doc[] = 
"Class: oaIter_oaGroupMember, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaGroupMember* getNext()\n"
"    Signature: getNext|ptr-oaGroupMember|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaGroupMember_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroupMember data;
    int convert_status=PyoaIter_oaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupMemberObject* self=(PyoaIter_oaGroupMemberObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupMemberp result= (data.DataCall()->getNext());
        return PyoaGroupMember_FromoaGroupMember(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGroupMember_next_doc[] = 
"Class: oaIter_oaGroupMember, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaGroupMember* next()\n"
"    Signature: next|ptr-oaGroupMember|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaGroupMember_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroupMember data;
    int convert_status=PyoaIter_oaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupMemberObject* self=(PyoaIter_oaGroupMemberObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupMemberp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaGroupMember_FromoaGroupMember(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGroupMember_reset_doc[] = 
"Class: oaIter_oaGroupMember, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaGroupMember_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGroupMember data;
    int convert_status=PyoaIter_oaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGroupMemberObject* self=(PyoaIter_oaGroupMemberObject*)ob;

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

static char oaIter_oaGroupMember_assign_doc[] = 
"Class: oaIter_oaGroupMember, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaGroupMember_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaGroupMember data;
  int convert_status=PyoaIter_oaGroupMember_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaGroupMember p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaGroupMember_Convert,&p1)) {
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

static PyMethodDef oaIter_oaGroupMember_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaGroupMember_getNext,METH_VARARGS,oaIter_oaGroupMember_getNext_doc},
    {"next",(PyCFunction)oaIter_oaGroupMember_next,METH_VARARGS,oaIter_oaGroupMember_next_doc},
    {"reset",(PyCFunction)oaIter_oaGroupMember_reset,METH_VARARGS,oaIter_oaGroupMember_reset_doc},
    {"assign",(PyCFunction)oaIter_oaGroupMember_tp_assign,METH_VARARGS,oaIter_oaGroupMember_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaGroupMember_doc[] = 
"Class: oaIter_oaGroupMember\n"
"  Class type oaIter_oaGroupMember\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroupMember_oaGroup)\n"
"    Calls: oaIter_oaGroupMember(const oaCollection_oaGroupMember_oaGroup& c)\n"
"    Signature: oaIter_oaGroupMember||cref-oaCollection_oaGroupMember_oaGroup,\n"
"    Constructor oaIter_oaGroupMember\n"
"  Paramegers: (oaCollection_oaGroupMember_oaObject)\n"
"    Calls: oaIter_oaGroupMember(const oaCollection_oaGroupMember_oaObject& c)\n"
"    Signature: oaIter_oaGroupMember||cref-oaCollection_oaGroupMember_oaObject,\n"
"    Constructor oaIter_oaGroupMember\n"
"  Paramegers: (oaIter_oaGroupMember)\n"
"    Calls: oaIter_oaGroupMember(const oaIter_oaGroupMember& iterIn)\n"
"    Signature: oaIter_oaGroupMember||cref-oaIter_oaGroupMember,\n"
"    Constructor oaIter_oaGroupMember\n"
"  Paramegers: (oaIter_oaGroupMember)\n"
"    Calls: (const oaIter_oaGroupMember&)\n"
"    Signature: oaIter_oaGroupMember||cref-oaIter_oaGroupMember,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaGroupMember_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaGroupMember",
    sizeof(PyoaIter_oaGroupMemberObject),
    0,
    (destructor)oaIter_oaGroupMember_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaGroupMember_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaGroupMember_tp_repr,	/* tp_repr */
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
    oaIter_oaGroupMember_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaGroupMember_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaGroupMember_iternext,	/* tp_iternext */
    oaIter_oaGroupMember_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaGroupMember_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaGroupMember_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaGroupMember_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaGroupMember\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaGroupMember",
           (PyObject*)(&PyoaIter_oaGroupMember_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaGroupMember\n");
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
// Wrapper Implementation for Class: oaIter_oaGuide
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGuide_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaGuide_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaGuideObject* self = (PyoaIter_oaGuideObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaGuide(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaGuide)
    {
        PyParamoaIter_oaGuide p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaGuide_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaGuide(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaGuide, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaGuide)\n"
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
oaIter_oaGuide_tp_dealloc(PyoaIter_oaGuideObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaGuide*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGuide_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaGuide value;
    int convert_status=PyoaIter_oaGuide_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaGuide::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaGuide_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaGuide v1;
    PyParamoaIter_oaGuide v2;
    int convert_status1=PyoaIter_oaGuide_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaGuide_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaGuide_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaGuide_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaGuide ob;
    int convert_status=PyoaIter_oaGuide_Convert(self,&ob);
    assert(convert_status!=0);
    oaGuide* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaGuide_FromoaGuide(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaGuide_Convert(PyObject* ob,PyParamoaIter_oaGuide* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaGuide_Check(ob)) {
        result->SetData( (oaIter_oaGuide*) ((PyoaIter_oaGuideObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaGuide Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaGuide_FromoaIter_oaGuide(oaIter_oaGuide* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaGuide_Type.tp_alloc(&PyoaIter_oaGuide_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaGuideObject* self = (PyoaIter_oaGuideObject*)bself;
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
static char oaIter_oaGuide_getNext_doc[] = 
"Class: oaIter_oaGuide, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaGuide* getNext()\n"
"    Signature: getNext|ptr-oaGuide|\n"
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
oaIter_oaGuide_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGuide data;
    int convert_status=PyoaIter_oaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGuideObject* self=(PyoaIter_oaGuideObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGuidep result= (data.DataCall()->getNext());
        return PyoaGuide_FromoaGuide(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaGuide_next_doc[] = 
"Class: oaIter_oaGuide, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaGuide* next()\n"
"    Signature: next|ptr-oaGuide|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaGuide_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaGuide data;
    int convert_status=PyoaIter_oaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaGuideObject* self=(PyoaIter_oaGuideObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGuidep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaGuide_FromoaGuide(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaGuide_assign_doc[] = 
"Class: oaIter_oaGuide, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaGuide_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaGuide data;
  int convert_status=PyoaIter_oaGuide_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaGuide p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaGuide_Convert,&p1)) {
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

static PyMethodDef oaIter_oaGuide_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaGuide_getNext,METH_VARARGS,oaIter_oaGuide_getNext_doc},
    {"next",(PyCFunction)oaIter_oaGuide_next,METH_VARARGS,oaIter_oaGuide_next_doc},
    {"assign",(PyCFunction)oaIter_oaGuide_tp_assign,METH_VARARGS,oaIter_oaGuide_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaGuide_doc[] = 
"Class: oaIter_oaGuide\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaGuide(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaGuide||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaGuide)\n"
"    Calls: oaIter_oaGuide(const oaIter_oaGuide& iterIn)\n"
"    Signature: oaIter_oaGuide||cref-oaIter_oaGuide,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaGuide)\n"
"    Calls: (const oaIter_oaGuide&)\n"
"    Signature: oaIter_oaGuide||cref-oaIter_oaGuide,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaGuide_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaGuide",
    sizeof(PyoaIter_oaGuideObject),
    0,
    (destructor)oaIter_oaGuide_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaGuide_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaGuide_tp_repr,	/* tp_repr */
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
    oaIter_oaGuide_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaGuide_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaGuide_iternext,	/* tp_iternext */
    oaIter_oaGuide_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaGuide_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaGuide_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaGuide_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaGuide\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaGuide",
           (PyObject*)(&PyoaIter_oaGuide_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaGuide\n");
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
// Wrapper Implementation for Class: oaIter_oaImage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaImage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaImage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaImageObject* self = (PyoaIter_oaImageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaImage(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaImage)
    {
        PyParamoaIter_oaImage p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaImage_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaImage(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaImage, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaImage)\n"
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
oaIter_oaImage_tp_dealloc(PyoaIter_oaImageObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaImage*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaImage_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaImage value;
    int convert_status=PyoaIter_oaImage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaImage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaImage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaImage v1;
    PyParamoaIter_oaImage v2;
    int convert_status1=PyoaIter_oaImage_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaImage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaImage_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaImage_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaImage ob;
    int convert_status=PyoaIter_oaImage_Convert(self,&ob);
    assert(convert_status!=0);
    oaImage* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaImage_FromoaImage(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaImage_Convert(PyObject* ob,PyParamoaIter_oaImage* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaImage_Check(ob)) {
        result->SetData( (oaIter_oaImage*) ((PyoaIter_oaImageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaImage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaImage_FromoaIter_oaImage(oaIter_oaImage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaImage_Type.tp_alloc(&PyoaIter_oaImage_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaImageObject* self = (PyoaIter_oaImageObject*)bself;
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
static char oaIter_oaImage_getNext_doc[] = 
"Class: oaIter_oaImage, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaImage* getNext()\n"
"    Signature: getNext|ptr-oaImage|\n"
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
oaIter_oaImage_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaImage data;
    int convert_status=PyoaIter_oaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaImageObject* self=(PyoaIter_oaImageObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaImagep result= (data.DataCall()->getNext());
        return PyoaImage_FromoaImage(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaImage_next_doc[] = 
"Class: oaIter_oaImage, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaImage* next()\n"
"    Signature: next|ptr-oaImage|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaImage_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaImage data;
    int convert_status=PyoaIter_oaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaImageObject* self=(PyoaIter_oaImageObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaImagep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaImage_FromoaImage(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaImage_assign_doc[] = 
"Class: oaIter_oaImage, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaImage_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaImage data;
  int convert_status=PyoaIter_oaImage_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaImage p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaImage_Convert,&p1)) {
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

static PyMethodDef oaIter_oaImage_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaImage_getNext,METH_VARARGS,oaIter_oaImage_getNext_doc},
    {"next",(PyCFunction)oaIter_oaImage_next,METH_VARARGS,oaIter_oaImage_next_doc},
    {"assign",(PyCFunction)oaIter_oaImage_tp_assign,METH_VARARGS,oaIter_oaImage_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaImage_doc[] = 
"Class: oaIter_oaImage\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaImage(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaImage||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaImage)\n"
"    Calls: oaIter_oaImage(const oaIter_oaImage& iterIn)\n"
"    Signature: oaIter_oaImage||cref-oaIter_oaImage,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaImage)\n"
"    Calls: (const oaIter_oaImage&)\n"
"    Signature: oaIter_oaImage||cref-oaIter_oaImage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaImage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaImage",
    sizeof(PyoaIter_oaImageObject),
    0,
    (destructor)oaIter_oaImage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaImage_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaImage_tp_repr,	/* tp_repr */
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
    oaIter_oaImage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaImage_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaImage_iternext,	/* tp_iternext */
    oaIter_oaImage_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaImage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaImage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaImage_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaImage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaImage",
           (PyObject*)(&PyoaIter_oaImage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaImage\n");
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
// Wrapper Implementation for Class: oaIter_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaInstObject* self = (PyoaIter_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaInst)
    {
        PyParamoaIter_oaInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaInst)\n"
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
oaIter_oaInst_tp_dealloc(PyoaIter_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaInst value;
    int convert_status=PyoaIter_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaInst v1;
    PyParamoaIter_oaInst v2;
    int convert_status1=PyoaIter_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaInst ob;
    int convert_status=PyoaIter_oaInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaInst_FromoaInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaInst_Convert(PyObject* ob,PyParamoaIter_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaInst_Check(ob)) {
        result->SetData( (oaIter_oaInst*) ((PyoaIter_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaInst_FromoaIter_oaInst(oaIter_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaInst_Type.tp_alloc(&PyoaIter_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaInstObject* self = (PyoaIter_oaInstObject*)bself;
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
static char oaIter_oaInst_getNext_doc[] = 
"Class: oaIter_oaInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getNext()\n"
"    Signature: getNext|ptr-oaInst|\n"
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
oaIter_oaInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInst data;
    int convert_status=PyoaIter_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstObject* self=(PyoaIter_oaInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getNext());
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
static char oaIter_oaInst_next_doc[] = 
"Class: oaIter_oaInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaInst* next()\n"
"    Signature: next|ptr-oaInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInst data;
    int convert_status=PyoaIter_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstObject* self=(PyoaIter_oaInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaInst_FromoaInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaInst_assign_doc[] = 
"Class: oaIter_oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaInst data;
  int convert_status=PyoaIter_oaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaInst_getNext,METH_VARARGS,oaIter_oaInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaInst_next,METH_VARARGS,oaIter_oaInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaInst_tp_assign,METH_VARARGS,oaIter_oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaInst_doc[] = 
"Class: oaIter_oaInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaInst)\n"
"    Calls: oaIter_oaInst(const oaIter_oaInst& iterIn)\n"
"    Signature: oaIter_oaInst||cref-oaIter_oaInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaInst)\n"
"    Calls: (const oaIter_oaInst&)\n"
"    Signature: oaIter_oaInst||cref-oaIter_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaInst",
    sizeof(PyoaIter_oaInstObject),
    0,
    (destructor)oaIter_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaInst_tp_repr,	/* tp_repr */
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
    oaIter_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaInst_iternext,	/* tp_iternext */
    oaIter_oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaInst",
           (PyObject*)(&PyoaIter_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaInst\n");
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
// Wrapper Implementation for Class: oaIter_oaInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaInstHeaderObject* self = (PyoaIter_oaInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaInstHeader)
    {
        PyParamoaIter_oaInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaInstHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaInstHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaInstHeader)\n"
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
oaIter_oaInstHeader_tp_dealloc(PyoaIter_oaInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaInstHeader value;
    int convert_status=PyoaIter_oaInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaInstHeader v1;
    PyParamoaIter_oaInstHeader v2;
    int convert_status1=PyoaIter_oaInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaInstHeader ob;
    int convert_status=PyoaIter_oaInstHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaInstHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaInstHeader_FromoaInstHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaInstHeader_Convert(PyObject* ob,PyParamoaIter_oaInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaInstHeader_Check(ob)) {
        result->SetData( (oaIter_oaInstHeader*) ((PyoaIter_oaInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaInstHeader_FromoaIter_oaInstHeader(oaIter_oaInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaInstHeader_Type.tp_alloc(&PyoaIter_oaInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaInstHeaderObject* self = (PyoaIter_oaInstHeaderObject*)bself;
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
static char oaIter_oaInstHeader_getNext_doc[] = 
"Class: oaIter_oaInstHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaInstHeader* getNext()\n"
"    Signature: getNext|ptr-oaInstHeader|\n"
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
oaIter_oaInstHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInstHeader data;
    int convert_status=PyoaIter_oaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstHeaderObject* self=(PyoaIter_oaInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstHeaderp result= (data.DataCall()->getNext());
        return PyoaInstHeader_FromoaInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaInstHeader_next_doc[] = 
"Class: oaIter_oaInstHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaInstHeader* next()\n"
"    Signature: next|ptr-oaInstHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaInstHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInstHeader data;
    int convert_status=PyoaIter_oaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstHeaderObject* self=(PyoaIter_oaInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaInstHeader_FromoaInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaInstHeader_assign_doc[] = 
"Class: oaIter_oaInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaInstHeader data;
  int convert_status=PyoaIter_oaInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaInstHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaInstHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaInstHeader_getNext,METH_VARARGS,oaIter_oaInstHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaInstHeader_next,METH_VARARGS,oaIter_oaInstHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaInstHeader_tp_assign,METH_VARARGS,oaIter_oaInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaInstHeader_doc[] = 
"Class: oaIter_oaInstHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaInstHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaInstHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaInstHeader)\n"
"    Calls: oaIter_oaInstHeader(const oaIter_oaInstHeader& iterIn)\n"
"    Signature: oaIter_oaInstHeader||cref-oaIter_oaInstHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaInstHeader)\n"
"    Calls: (const oaIter_oaInstHeader&)\n"
"    Signature: oaIter_oaInstHeader||cref-oaIter_oaInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaInstHeader",
    sizeof(PyoaIter_oaInstHeaderObject),
    0,
    (destructor)oaIter_oaInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaInstHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaInstHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaInstHeader_iternext,	/* tp_iternext */
    oaIter_oaInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaInstHeader",
           (PyObject*)(&PyoaIter_oaInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaInstHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaInstTermObject* self = (PyoaIter_oaInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaInstTerm)
    {
        PyParamoaIter_oaInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaInstTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaInstTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaInstTerm)\n"
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
oaIter_oaInstTerm_tp_dealloc(PyoaIter_oaInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaInstTerm value;
    int convert_status=PyoaIter_oaInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaIter_oaInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaInstTerm v1;
    PyParamoaIter_oaInstTerm v2;
    int convert_status1=PyoaIter_oaInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaInstTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaInstTerm ob;
    int convert_status=PyoaIter_oaInstTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaInstTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaInstTerm_FromoaInstTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaInstTerm_Convert(PyObject* ob,PyParamoaIter_oaInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaInstTerm_Check(ob)) {
        result->SetData( (oaIter_oaInstTerm*) ((PyoaIter_oaInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaInstTerm_FromoaIter_oaInstTerm(oaIter_oaInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaInstTerm_Type.tp_alloc(&PyoaIter_oaInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaInstTermObject* self = (PyoaIter_oaInstTermObject*)bself;
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
static char oaIter_oaInstTerm_getNext_doc[] = 
"Class: oaIter_oaInstTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaInstTerm* getNext()\n"
"    Signature: getNext|ptr-oaInstTerm|\n"
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
oaIter_oaInstTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInstTerm data;
    int convert_status=PyoaIter_oaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstTermObject* self=(PyoaIter_oaInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstTermp result= (data.DataCall()->getNext());
        return PyoaInstTerm_FromoaInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaInstTerm_next_doc[] = 
"Class: oaIter_oaInstTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaInstTerm* next()\n"
"    Signature: next|ptr-oaInstTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaInstTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaInstTerm data;
    int convert_status=PyoaIter_oaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaInstTermObject* self=(PyoaIter_oaInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaInstTerm_FromoaInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaInstTerm_assign_doc[] = 
"Class: oaIter_oaInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaInstTerm data;
  int convert_status=PyoaIter_oaInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaInstTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaInstTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaInstTerm_getNext,METH_VARARGS,oaIter_oaInstTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaInstTerm_next,METH_VARARGS,oaIter_oaInstTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaInstTerm_tp_assign,METH_VARARGS,oaIter_oaInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaInstTerm_doc[] = 
"Class: oaIter_oaInstTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaInstTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaInstTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaInstTerm)\n"
"    Calls: oaIter_oaInstTerm(const oaIter_oaInstTerm& iterIn)\n"
"    Signature: oaIter_oaInstTerm||cref-oaIter_oaInstTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaInstTerm)\n"
"    Calls: (const oaIter_oaInstTerm&)\n"
"    Signature: oaIter_oaInstTerm||cref-oaIter_oaInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaInstTerm",
    sizeof(PyoaIter_oaInstTermObject),
    0,
    (destructor)oaIter_oaInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaInstTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaInstTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaInstTerm_iternext,	/* tp_iternext */
    oaIter_oaInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaInstTerm",
           (PyObject*)(&PyoaIter_oaInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaInstTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaLPPHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLPPHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLPPHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLPPHeaderObject* self = (PyoaIter_oaLPPHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLPPHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLPPHeader)
    {
        PyParamoaIter_oaLPPHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLPPHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLPPHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLPPHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaLPPHeader)\n"
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
oaIter_oaLPPHeader_tp_dealloc(PyoaIter_oaLPPHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLPPHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLPPHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLPPHeader value;
    int convert_status=PyoaIter_oaLPPHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaLPPHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLPPHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLPPHeader v1;
    PyParamoaIter_oaLPPHeader v2;
    int convert_status1=PyoaIter_oaLPPHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLPPHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLPPHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLPPHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLPPHeader ob;
    int convert_status=PyoaIter_oaLPPHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaLPPHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLPPHeader_FromoaLPPHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLPPHeader_Convert(PyObject* ob,PyParamoaIter_oaLPPHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLPPHeader_Check(ob)) {
        result->SetData( (oaIter_oaLPPHeader*) ((PyoaIter_oaLPPHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLPPHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLPPHeader_FromoaIter_oaLPPHeader(oaIter_oaLPPHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLPPHeader_Type.tp_alloc(&PyoaIter_oaLPPHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLPPHeaderObject* self = (PyoaIter_oaLPPHeaderObject*)bself;
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
static char oaIter_oaLPPHeader_getNext_doc[] = 
"Class: oaIter_oaLPPHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLPPHeader* getNext()\n"
"    Signature: getNext|ptr-oaLPPHeader|\n"
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
oaIter_oaLPPHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLPPHeader data;
    int convert_status=PyoaIter_oaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLPPHeaderObject* self=(PyoaIter_oaLPPHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLPPHeaderp result= (data.DataCall()->getNext());
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
static char oaIter_oaLPPHeader_next_doc[] = 
"Class: oaIter_oaLPPHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLPPHeader* next()\n"
"    Signature: next|ptr-oaLPPHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLPPHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLPPHeader data;
    int convert_status=PyoaIter_oaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLPPHeaderObject* self=(PyoaIter_oaLPPHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLPPHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLPPHeader_FromoaLPPHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLPPHeader_assign_doc[] = 
"Class: oaIter_oaLPPHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLPPHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLPPHeader data;
  int convert_status=PyoaIter_oaLPPHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLPPHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLPPHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLPPHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLPPHeader_getNext,METH_VARARGS,oaIter_oaLPPHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLPPHeader_next,METH_VARARGS,oaIter_oaLPPHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaLPPHeader_tp_assign,METH_VARARGS,oaIter_oaLPPHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLPPHeader_doc[] = 
"Class: oaIter_oaLPPHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaLPPHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaLPPHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaLPPHeader)\n"
"    Calls: oaIter_oaLPPHeader(const oaIter_oaLPPHeader& iterIn)\n"
"    Signature: oaIter_oaLPPHeader||cref-oaIter_oaLPPHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaLPPHeader)\n"
"    Calls: (const oaIter_oaLPPHeader&)\n"
"    Signature: oaIter_oaLPPHeader||cref-oaIter_oaLPPHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLPPHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLPPHeader",
    sizeof(PyoaIter_oaLPPHeaderObject),
    0,
    (destructor)oaIter_oaLPPHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLPPHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLPPHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaLPPHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLPPHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLPPHeader_iternext,	/* tp_iternext */
    oaIter_oaLPPHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLPPHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLPPHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLPPHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLPPHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLPPHeader",
           (PyObject*)(&PyoaIter_oaLPPHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLPPHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaLayer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLayer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLayerObject* self = (PyoaIter_oaLayerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLayer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLayer)
    {
        PyParamoaIter_oaLayer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLayer_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLayer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLayer, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaLayer)\n"
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
oaIter_oaLayer_tp_dealloc(PyoaIter_oaLayerObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLayer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayer_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLayer value;
    int convert_status=PyoaIter_oaLayer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaLayer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLayer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLayer v1;
    PyParamoaIter_oaLayer v2;
    int convert_status1=PyoaIter_oaLayer_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLayer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayer_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayer_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLayer ob;
    int convert_status=PyoaIter_oaLayer_Convert(self,&ob);
    assert(convert_status!=0);
    oaLayer* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLayer_FromoaLayer(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLayer_Convert(PyObject* ob,PyParamoaIter_oaLayer* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLayer_Check(ob)) {
        result->SetData( (oaIter_oaLayer*) ((PyoaIter_oaLayerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLayer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLayer_FromoaIter_oaLayer(oaIter_oaLayer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLayer_Type.tp_alloc(&PyoaIter_oaLayer_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLayerObject* self = (PyoaIter_oaLayerObject*)bself;
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
static char oaIter_oaLayer_getNext_doc[] = 
"Class: oaIter_oaLayer, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLayer* getNext()\n"
"    Signature: getNext|ptr-oaLayer|\n"
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
oaIter_oaLayer_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayer data;
    int convert_status=PyoaIter_oaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerObject* self=(PyoaIter_oaLayerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerp result= (data.DataCall()->getNext());
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
static char oaIter_oaLayer_next_doc[] = 
"Class: oaIter_oaLayer, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLayer* next()\n"
"    Signature: next|ptr-oaLayer|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLayer_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayer data;
    int convert_status=PyoaIter_oaLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerObject* self=(PyoaIter_oaLayerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLayer_FromoaLayer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLayer_assign_doc[] = 
"Class: oaIter_oaLayer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLayer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLayer data;
  int convert_status=PyoaIter_oaLayer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLayer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLayer_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLayer_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLayer_getNext,METH_VARARGS,oaIter_oaLayer_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLayer_next,METH_VARARGS,oaIter_oaLayer_next_doc},
    {"assign",(PyCFunction)oaIter_oaLayer_tp_assign,METH_VARARGS,oaIter_oaLayer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLayer_doc[] = 
"Class: oaIter_oaLayer\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaLayer(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaLayer||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaLayer)\n"
"    Calls: oaIter_oaLayer(const oaIter_oaLayer& iterIn)\n"
"    Signature: oaIter_oaLayer||cref-oaIter_oaLayer,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaLayer)\n"
"    Calls: (const oaIter_oaLayer&)\n"
"    Signature: oaIter_oaLayer||cref-oaIter_oaLayer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLayer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLayer",
    sizeof(PyoaIter_oaLayerObject),
    0,
    (destructor)oaIter_oaLayer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLayer_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLayer_tp_repr,	/* tp_repr */
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
    oaIter_oaLayer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLayer_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLayer_iternext,	/* tp_iternext */
    oaIter_oaLayer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLayer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLayer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLayer_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLayer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLayer",
           (PyObject*)(&PyoaIter_oaLayer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLayer\n");
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
// Wrapper Implementation for Class: oaIter_oaLayerArrayConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerArrayConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLayerArrayConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLayerArrayConstraintObject* self = (PyoaIter_oaLayerArrayConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerArrayConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLayerArrayConstraint)
    {
        PyParamoaIter_oaLayerArrayConstraint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLayerArrayConstraint_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerArrayConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLayerArrayConstraint, Choices are:\n"
        "    (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)\n"
        "    (oaIter_oaLayerArrayConstraint)\n"
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
oaIter_oaLayerArrayConstraint_tp_dealloc(PyoaIter_oaLayerArrayConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLayerArrayConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerArrayConstraint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLayerArrayConstraint value;
    int convert_status=PyoaIter_oaLayerArrayConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaIter_oaLayerArrayConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLayerArrayConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLayerArrayConstraint v1;
    PyParamoaIter_oaLayerArrayConstraint v2;
    int convert_status1=PyoaIter_oaLayerArrayConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLayerArrayConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerArrayConstraint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerArrayConstraint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLayerArrayConstraint ob;
    int convert_status=PyoaIter_oaLayerArrayConstraint_Convert(self,&ob);
    assert(convert_status!=0);
    oaLayerArrayConstraint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLayerArrayConstraint_Convert(PyObject* ob,PyParamoaIter_oaLayerArrayConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLayerArrayConstraint_Check(ob)) {
        result->SetData( (oaIter_oaLayerArrayConstraint*) ((PyoaIter_oaLayerArrayConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLayerArrayConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLayerArrayConstraint_FromoaIter_oaLayerArrayConstraint(oaIter_oaLayerArrayConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLayerArrayConstraint_Type.tp_alloc(&PyoaIter_oaLayerArrayConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLayerArrayConstraintObject* self = (PyoaIter_oaLayerArrayConstraintObject*)bself;
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
static char oaIter_oaLayerArrayConstraint_getNext_doc[] = 
"Class: oaIter_oaLayerArrayConstraint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLayerArrayConstraint* getNext()\n"
"    Signature: getNext|ptr-oaLayerArrayConstraint|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaLayerArrayConstraint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerArrayConstraint data;
    int convert_status=PyoaIter_oaLayerArrayConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerArrayConstraintObject* self=(PyoaIter_oaLayerArrayConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerArrayConstraintp result= (data.DataCall()->getNext());
        return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLayerArrayConstraint_next_doc[] = 
"Class: oaIter_oaLayerArrayConstraint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLayerArrayConstraint* next()\n"
"    Signature: next|ptr-oaLayerArrayConstraint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLayerArrayConstraint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerArrayConstraint data;
    int convert_status=PyoaIter_oaLayerArrayConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerArrayConstraintObject* self=(PyoaIter_oaLayerArrayConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerArrayConstraintp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint(result);
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

static PyMethodDef oaIter_oaLayerArrayConstraint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLayerArrayConstraint_getNext,METH_VARARGS,oaIter_oaLayerArrayConstraint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLayerArrayConstraint_next,METH_VARARGS,oaIter_oaLayerArrayConstraint_next_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLayerArrayConstraint_doc[] = 
"Class: oaIter_oaLayerArrayConstraint\n"
"  Class type oaIter_oaLayerArrayConstraint\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)\n"
"    Calls: oaIter_oaLayerArrayConstraint(const oaCollection_oaLayerArrayConstraint_oaConstraintGroup& c)\n"
"    Signature: oaIter_oaLayerArrayConstraint||cref-oaCollection_oaLayerArrayConstraint_oaConstraintGroup,\n"
"    Constructor oaIter_oaLayerArrayConstraint\n"
"  Paramegers: (oaIter_oaLayerArrayConstraint)\n"
"    Calls: oaIter_oaLayerArrayConstraint(const oaIter_oaLayerArrayConstraint& iterIn)\n"
"    Signature: oaIter_oaLayerArrayConstraint||cref-oaIter_oaLayerArrayConstraint,\n"
"    Constructor oaIter_oaLayerArrayConstraint\n"
"  Paramegers: (oaIter_oaLayerArrayConstraint)\n"
"    Calls: (const oaIter_oaLayerArrayConstraint&)\n"
"    Signature: oaIter_oaLayerArrayConstraint||cref-oaIter_oaLayerArrayConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLayerArrayConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLayerArrayConstraint",
    sizeof(PyoaIter_oaLayerArrayConstraintObject),
    0,
    (destructor)oaIter_oaLayerArrayConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLayerArrayConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLayerArrayConstraint_tp_repr,	/* tp_repr */
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
    oaIter_oaLayerArrayConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLayerArrayConstraint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLayerArrayConstraint_iternext,	/* tp_iternext */
    oaIter_oaLayerArrayConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLayerArrayConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLayerArrayConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLayerArrayConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLayerArrayConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLayerArrayConstraint",
           (PyObject*)(&PyoaIter_oaLayerArrayConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLayerArrayConstraint\n");
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
// Wrapper Implementation for Class: oaIter_oaLayerConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLayerConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLayerConstraintObject* self = (PyoaIter_oaLayerConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLayerConstraint)
    {
        PyParamoaIter_oaLayerConstraint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLayerConstraint_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLayerConstraint, Choices are:\n"
        "    (oaCollection_oaLayerConstraint_oaConstraintGroup)\n"
        "    (oaIter_oaLayerConstraint)\n"
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
oaIter_oaLayerConstraint_tp_dealloc(PyoaIter_oaLayerConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLayerConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerConstraint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLayerConstraint value;
    int convert_status=PyoaIter_oaLayerConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaIter_oaLayerConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLayerConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLayerConstraint v1;
    PyParamoaIter_oaLayerConstraint v2;
    int convert_status1=PyoaIter_oaLayerConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLayerConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerConstraint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerConstraint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLayerConstraint ob;
    int convert_status=PyoaIter_oaLayerConstraint_Convert(self,&ob);
    assert(convert_status!=0);
    oaLayerConstraint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLayerConstraint_FromoaLayerConstraint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLayerConstraint_Convert(PyObject* ob,PyParamoaIter_oaLayerConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLayerConstraint_Check(ob)) {
        result->SetData( (oaIter_oaLayerConstraint*) ((PyoaIter_oaLayerConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLayerConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLayerConstraint_FromoaIter_oaLayerConstraint(oaIter_oaLayerConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLayerConstraint_Type.tp_alloc(&PyoaIter_oaLayerConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLayerConstraintObject* self = (PyoaIter_oaLayerConstraintObject*)bself;
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
static char oaIter_oaLayerConstraint_getNext_doc[] = 
"Class: oaIter_oaLayerConstraint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLayerConstraint* getNext()\n"
"    Signature: getNext|ptr-oaLayerConstraint|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaLayerConstraint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerConstraint data;
    int convert_status=PyoaIter_oaLayerConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerConstraintObject* self=(PyoaIter_oaLayerConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerConstraintp result= (data.DataCall()->getNext());
        return PyoaLayerConstraint_FromoaLayerConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLayerConstraint_next_doc[] = 
"Class: oaIter_oaLayerConstraint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLayerConstraint* next()\n"
"    Signature: next|ptr-oaLayerConstraint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLayerConstraint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerConstraint data;
    int convert_status=PyoaIter_oaLayerConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerConstraintObject* self=(PyoaIter_oaLayerConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerConstraintp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLayerConstraint_FromoaLayerConstraint(result);
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

static PyMethodDef oaIter_oaLayerConstraint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLayerConstraint_getNext,METH_VARARGS,oaIter_oaLayerConstraint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLayerConstraint_next,METH_VARARGS,oaIter_oaLayerConstraint_next_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLayerConstraint_doc[] = 
"Class: oaIter_oaLayerConstraint\n"
"  Class type oaIter_oaLayerConstraint\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerConstraint_oaConstraintGroup)\n"
"    Calls: oaIter_oaLayerConstraint(const oaCollection_oaLayerConstraint_oaConstraintGroup& c)\n"
"    Signature: oaIter_oaLayerConstraint||cref-oaCollection_oaLayerConstraint_oaConstraintGroup,\n"
"    Constructor oaIter_oaLayerConstraint\n"
"  Paramegers: (oaIter_oaLayerConstraint)\n"
"    Calls: oaIter_oaLayerConstraint(const oaIter_oaLayerConstraint& iterIn)\n"
"    Signature: oaIter_oaLayerConstraint||cref-oaIter_oaLayerConstraint,\n"
"    Constructor oaIter_oaLayerConstraint\n"
"  Paramegers: (oaIter_oaLayerConstraint)\n"
"    Calls: (const oaIter_oaLayerConstraint&)\n"
"    Signature: oaIter_oaLayerConstraint||cref-oaIter_oaLayerConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLayerConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLayerConstraint",
    sizeof(PyoaIter_oaLayerConstraintObject),
    0,
    (destructor)oaIter_oaLayerConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLayerConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLayerConstraint_tp_repr,	/* tp_repr */
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
    oaIter_oaLayerConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLayerConstraint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLayerConstraint_iternext,	/* tp_iternext */
    oaIter_oaLayerConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLayerConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLayerConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLayerConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLayerConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLayerConstraint",
           (PyObject*)(&PyoaIter_oaLayerConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLayerConstraint\n");
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
// Wrapper Implementation for Class: oaIter_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLayerHeaderObject* self = (PyoaIter_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLayerHeader)
    {
        PyParamoaIter_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLayerHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLayerHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaLayerHeader)\n"
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
oaIter_oaLayerHeader_tp_dealloc(PyoaIter_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLayerHeader value;
    int convert_status=PyoaIter_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLayerHeader v1;
    PyParamoaIter_oaLayerHeader v2;
    int convert_status1=PyoaIter_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLayerHeader ob;
    int convert_status=PyoaIter_oaLayerHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaLayerHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLayerHeader_FromoaLayerHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLayerHeader_Convert(PyObject* ob,PyParamoaIter_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLayerHeader_Check(ob)) {
        result->SetData( (oaIter_oaLayerHeader*) ((PyoaIter_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLayerHeader_FromoaIter_oaLayerHeader(oaIter_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLayerHeader_Type.tp_alloc(&PyoaIter_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLayerHeaderObject* self = (PyoaIter_oaLayerHeaderObject*)bself;
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
static char oaIter_oaLayerHeader_getNext_doc[] = 
"Class: oaIter_oaLayerHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getNext()\n"
"    Signature: getNext|ptr-oaLayerHeader|\n"
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
oaIter_oaLayerHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerHeader data;
    int convert_status=PyoaIter_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerHeaderObject* self=(PyoaIter_oaLayerHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getNext());
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
static char oaIter_oaLayerHeader_next_doc[] = 
"Class: oaIter_oaLayerHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* next()\n"
"    Signature: next|ptr-oaLayerHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLayerHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerHeader data;
    int convert_status=PyoaIter_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerHeaderObject* self=(PyoaIter_oaLayerHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLayerHeader_FromoaLayerHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLayerHeader_assign_doc[] = 
"Class: oaIter_oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLayerHeader data;
  int convert_status=PyoaIter_oaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLayerHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLayerHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLayerHeader_getNext,METH_VARARGS,oaIter_oaLayerHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLayerHeader_next,METH_VARARGS,oaIter_oaLayerHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaLayerHeader_tp_assign,METH_VARARGS,oaIter_oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLayerHeader_doc[] = 
"Class: oaIter_oaLayerHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaLayerHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaLayerHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaLayerHeader)\n"
"    Calls: oaIter_oaLayerHeader(const oaIter_oaLayerHeader& iterIn)\n"
"    Signature: oaIter_oaLayerHeader||cref-oaIter_oaLayerHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaLayerHeader)\n"
"    Calls: (const oaIter_oaLayerHeader&)\n"
"    Signature: oaIter_oaLayerHeader||cref-oaIter_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLayerHeader",
    sizeof(PyoaIter_oaLayerHeaderObject),
    0,
    (destructor)oaIter_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLayerHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLayerHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLayerHeader_iternext,	/* tp_iternext */
    oaIter_oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLayerHeader",
           (PyObject*)(&PyoaIter_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLayerHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaLayerPairConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerPairConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLayerPairConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLayerPairConstraintObject* self = (PyoaIter_oaLayerPairConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerPairConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerPairConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLayerPairConstraint)
    {
        PyParamoaIter_oaLayerPairConstraint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLayerPairConstraint_Convert,&p1)) {
            self->value = (oaConstraintInGroupIter*)  new oaIter_oaLayerPairConstraint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLayerPairConstraint, Choices are:\n"
        "    (oaCollection_oaLayerPairConstraint_oaConstraintGroup)\n"
        "    (oaIter_oaLayerPairConstraint)\n"
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
oaIter_oaLayerPairConstraint_tp_dealloc(PyoaIter_oaLayerPairConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLayerPairConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerPairConstraint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLayerPairConstraint value;
    int convert_status=PyoaIter_oaLayerPairConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaIter_oaLayerPairConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLayerPairConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLayerPairConstraint v1;
    PyParamoaIter_oaLayerPairConstraint v2;
    int convert_status1=PyoaIter_oaLayerPairConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLayerPairConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerPairConstraint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLayerPairConstraint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLayerPairConstraint ob;
    int convert_status=PyoaIter_oaLayerPairConstraint_Convert(self,&ob);
    assert(convert_status!=0);
    oaLayerPairConstraint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLayerPairConstraint_Convert(PyObject* ob,PyParamoaIter_oaLayerPairConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLayerPairConstraint_Check(ob)) {
        result->SetData( (oaIter_oaLayerPairConstraint*) ((PyoaIter_oaLayerPairConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLayerPairConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLayerPairConstraint_FromoaIter_oaLayerPairConstraint(oaIter_oaLayerPairConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLayerPairConstraint_Type.tp_alloc(&PyoaIter_oaLayerPairConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLayerPairConstraintObject* self = (PyoaIter_oaLayerPairConstraintObject*)bself;
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
static char oaIter_oaLayerPairConstraint_getNext_doc[] = 
"Class: oaIter_oaLayerPairConstraint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLayerPairConstraint* getNext()\n"
"    Signature: getNext|ptr-oaLayerPairConstraint|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaLayerPairConstraint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerPairConstraint data;
    int convert_status=PyoaIter_oaLayerPairConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerPairConstraintObject* self=(PyoaIter_oaLayerPairConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerPairConstraintp result= (data.DataCall()->getNext());
        return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLayerPairConstraint_next_doc[] = 
"Class: oaIter_oaLayerPairConstraint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLayerPairConstraint* next()\n"
"    Signature: next|ptr-oaLayerPairConstraint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLayerPairConstraint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLayerPairConstraint data;
    int convert_status=PyoaIter_oaLayerPairConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLayerPairConstraintObject* self=(PyoaIter_oaLayerPairConstraintObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerPairConstraintp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLayerPairConstraint_FromoaLayerPairConstraint(result);
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

static PyMethodDef oaIter_oaLayerPairConstraint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLayerPairConstraint_getNext,METH_VARARGS,oaIter_oaLayerPairConstraint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLayerPairConstraint_next,METH_VARARGS,oaIter_oaLayerPairConstraint_next_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLayerPairConstraint_doc[] = 
"Class: oaIter_oaLayerPairConstraint\n"
"  Class type oaIter_oaLayerPairConstraint\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerPairConstraint_oaConstraintGroup)\n"
"    Calls: oaIter_oaLayerPairConstraint(const oaCollection_oaLayerPairConstraint_oaConstraintGroup& c)\n"
"    Signature: oaIter_oaLayerPairConstraint||cref-oaCollection_oaLayerPairConstraint_oaConstraintGroup,\n"
"    Constructor oaIter_oaLayerPairConstraint\n"
"  Paramegers: (oaIter_oaLayerPairConstraint)\n"
"    Calls: oaIter_oaLayerPairConstraint(const oaIter_oaLayerPairConstraint& iterIn)\n"
"    Signature: oaIter_oaLayerPairConstraint||cref-oaIter_oaLayerPairConstraint,\n"
"    Constructor oaIter_oaLayerPairConstraint\n"
"  Paramegers: (oaIter_oaLayerPairConstraint)\n"
"    Calls: (const oaIter_oaLayerPairConstraint&)\n"
"    Signature: oaIter_oaLayerPairConstraint||cref-oaIter_oaLayerPairConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLayerPairConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLayerPairConstraint",
    sizeof(PyoaIter_oaLayerPairConstraintObject),
    0,
    (destructor)oaIter_oaLayerPairConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLayerPairConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLayerPairConstraint_tp_repr,	/* tp_repr */
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
    oaIter_oaLayerPairConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLayerPairConstraint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLayerPairConstraint_iternext,	/* tp_iternext */
    oaIter_oaLayerPairConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLayerPairConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLayerPairConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLayerPairConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLayerPairConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLayerPairConstraint",
           (PyObject*)(&PyoaIter_oaLayerPairConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLayerPairConstraint\n");
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
// Wrapper Implementation for Class: oaIter_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLibObject* self = (PyoaIter_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLib_oaLib)
    {
        PyParamoaCollection_oaLib_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLib_oaLib_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLib)
    {
        PyParamoaIter_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLib_Convert,&p1)) {
            self->value = (oaDatabaseIter*)  new oaIter_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLib, Choices are:\n"
        "    (oaCollection_oaLib_oaLib)\n"
        "    (oaIter_oaLib)\n"
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
oaIter_oaLib_tp_dealloc(PyoaIter_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLib value;
    int convert_status=PyoaIter_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaIter_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLib v1;
    PyParamoaIter_oaLib v2;
    int convert_status1=PyoaIter_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLib_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLib_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLib ob;
    int convert_status=PyoaIter_oaLib_Convert(self,&ob);
    assert(convert_status!=0);
    oaLib* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLib_FromoaLib(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLib_Convert(PyObject* ob,PyParamoaIter_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLib_Check(ob)) {
        result->SetData( (oaIter_oaLib*) ((PyoaIter_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLib_FromoaIter_oaLib(oaIter_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLib_Type.tp_alloc(&PyoaIter_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLibObject* self = (PyoaIter_oaLibObject*)bself;
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
static char oaIter_oaLib_getNext_doc[] = 
"Class: oaIter_oaLib, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLib* getNext()\n"
"    Signature: getNext|ptr-oaLib|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaLib_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLib data;
    int convert_status=PyoaIter_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibObject* self=(PyoaIter_oaLibObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibp result= (data.DataCall()->getNext());
        return PyoaLib_FromoaLib(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLib_next_doc[] = 
"Class: oaIter_oaLib, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLib* next()\n"
"    Signature: next|ptr-oaLib|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLib_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLib data;
    int convert_status=PyoaIter_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibObject* self=(PyoaIter_oaLibObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLib_FromoaLib(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLib_assign_doc[] = 
"Class: oaIter_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLib data;
  int convert_status=PyoaIter_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLib_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLib_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLib_getNext,METH_VARARGS,oaIter_oaLib_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLib_next,METH_VARARGS,oaIter_oaLib_next_doc},
    {"assign",(PyCFunction)oaIter_oaLib_tp_assign,METH_VARARGS,oaIter_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLib_doc[] = 
"Class: oaIter_oaLib\n"
"  Class type oaIter_oaLib\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLib_oaLib)\n"
"    Calls: oaIter_oaLib(const oaCollection_oaLib_oaLib& c)\n"
"    Signature: oaIter_oaLib||cref-oaCollection_oaLib_oaLib,\n"
"    Constructor oaIter_oaLib\n"
"  Paramegers: (oaIter_oaLib)\n"
"    Calls: oaIter_oaLib(const oaIter_oaLib& iterIn)\n"
"    Signature: oaIter_oaLib||cref-oaIter_oaLib,\n"
"    Constructor oaIter_oaLib\n"
"  Paramegers: (oaIter_oaLib)\n"
"    Calls: (const oaIter_oaLib&)\n"
"    Signature: oaIter_oaLib||cref-oaIter_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLib",
    sizeof(PyoaIter_oaLibObject),
    0,
    (destructor)oaIter_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLib_tp_repr,	/* tp_repr */
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
    oaIter_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLib_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLib_iternext,	/* tp_iternext */
    oaIter_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLib",
           (PyObject*)(&PyoaIter_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLib\n");
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
// Wrapper Implementation for Class: oaIter_oaLibDefList
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLibDefList_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLibDefListObject* self = (PyoaIter_oaLibDefListObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLibDefList(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLibDefList)
    {
        PyParamoaIter_oaLibDefList p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLibDefList_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLibDefList(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLibDefList, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaLibDefList)\n"
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
oaIter_oaLibDefList_tp_dealloc(PyoaIter_oaLibDefListObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLibDefList*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefList_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLibDefList value;
    int convert_status=PyoaIter_oaLibDefList_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaLibDefList::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLibDefList_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLibDefList v1;
    PyParamoaIter_oaLibDefList v2;
    int convert_status1=PyoaIter_oaLibDefList_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLibDefList_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefList_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefList_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLibDefList ob;
    int convert_status=PyoaIter_oaLibDefList_Convert(self,&ob);
    assert(convert_status!=0);
    oaLibDefList* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLibDefList_FromoaLibDefList(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLibDefList_Convert(PyObject* ob,PyParamoaIter_oaLibDefList* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLibDefList_Check(ob)) {
        result->SetData( (oaIter_oaLibDefList*) ((PyoaIter_oaLibDefListObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLibDefList Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLibDefList_FromoaIter_oaLibDefList(oaIter_oaLibDefList* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLibDefList_Type.tp_alloc(&PyoaIter_oaLibDefList_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLibDefListObject* self = (PyoaIter_oaLibDefListObject*)bself;
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
static char oaIter_oaLibDefList_getNext_doc[] = 
"Class: oaIter_oaLibDefList, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefList* getNext()\n"
"    Signature: getNext|ptr-oaLibDefList|\n"
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
oaIter_oaLibDefList_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLibDefList data;
    int convert_status=PyoaIter_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibDefListObject* self=(PyoaIter_oaLibDefListObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListp result= (data.DataCall()->getNext());
        return PyoaLibDefList_FromoaLibDefList(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLibDefList_next_doc[] = 
"Class: oaIter_oaLibDefList, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefList* next()\n"
"    Signature: next|ptr-oaLibDefList|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLibDefList_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLibDefList data;
    int convert_status=PyoaIter_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibDefListObject* self=(PyoaIter_oaLibDefListObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLibDefList_FromoaLibDefList(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLibDefList_assign_doc[] = 
"Class: oaIter_oaLibDefList, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLibDefList_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLibDefList data;
  int convert_status=PyoaIter_oaLibDefList_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLibDefList p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLibDefList_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLibDefList_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLibDefList_getNext,METH_VARARGS,oaIter_oaLibDefList_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLibDefList_next,METH_VARARGS,oaIter_oaLibDefList_next_doc},
    {"assign",(PyCFunction)oaIter_oaLibDefList_tp_assign,METH_VARARGS,oaIter_oaLibDefList_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLibDefList_doc[] = 
"Class: oaIter_oaLibDefList\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaLibDefList(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaLibDefList||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaLibDefList)\n"
"    Calls: oaIter_oaLibDefList(const oaIter_oaLibDefList& iterIn)\n"
"    Signature: oaIter_oaLibDefList||cref-oaIter_oaLibDefList,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaLibDefList)\n"
"    Calls: (const oaIter_oaLibDefList&)\n"
"    Signature: oaIter_oaLibDefList||cref-oaIter_oaLibDefList,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLibDefList_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLibDefList",
    sizeof(PyoaIter_oaLibDefListObject),
    0,
    (destructor)oaIter_oaLibDefList_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLibDefList_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLibDefList_tp_repr,	/* tp_repr */
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
    oaIter_oaLibDefList_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLibDefList_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLibDefList_iternext,	/* tp_iternext */
    oaIter_oaLibDefList_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLibDefList_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLibDefList_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLibDefList_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLibDefList\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLibDefList",
           (PyObject*)(&PyoaIter_oaLibDefList_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLibDefList\n");
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
// Wrapper Implementation for Class: oaIter_oaLibDefListMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefListMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaLibDefListMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaLibDefListMemObject* self = (PyoaIter_oaLibDefListMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLibDefListMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaLibDefListMem)
    {
        PyParamoaIter_oaLibDefListMem p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaLibDefListMem_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaLibDefListMem(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaLibDefListMem, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaLibDefListMem)\n"
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
oaIter_oaLibDefListMem_tp_dealloc(PyoaIter_oaLibDefListMemObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaLibDefListMem*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefListMem_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaLibDefListMem value;
    int convert_status=PyoaIter_oaLibDefListMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaLibDefListMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaLibDefListMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaLibDefListMem v1;
    PyParamoaIter_oaLibDefListMem v2;
    int convert_status1=PyoaIter_oaLibDefListMem_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaLibDefListMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefListMem_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaLibDefListMem_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaLibDefListMem ob;
    int convert_status=PyoaIter_oaLibDefListMem_Convert(self,&ob);
    assert(convert_status!=0);
    oaLibDefListMem* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaLibDefListMem_FromoaLibDefListMem(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaLibDefListMem_Convert(PyObject* ob,PyParamoaIter_oaLibDefListMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaLibDefListMem_Check(ob)) {
        result->SetData( (oaIter_oaLibDefListMem*) ((PyoaIter_oaLibDefListMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaLibDefListMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaLibDefListMem_FromoaIter_oaLibDefListMem(oaIter_oaLibDefListMem* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaLibDefListMem_Type.tp_alloc(&PyoaIter_oaLibDefListMem_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaLibDefListMemObject* self = (PyoaIter_oaLibDefListMemObject*)bself;
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
static char oaIter_oaLibDefListMem_getNext_doc[] = 
"Class: oaIter_oaLibDefListMem, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefListMem* getNext()\n"
"    Signature: getNext|ptr-oaLibDefListMem|\n"
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
oaIter_oaLibDefListMem_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLibDefListMem data;
    int convert_status=PyoaIter_oaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibDefListMemObject* self=(PyoaIter_oaLibDefListMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListMemp result= (data.DataCall()->getNext());
        return PyoaLibDefListMem_FromoaLibDefListMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaLibDefListMem_next_doc[] = 
"Class: oaIter_oaLibDefListMem, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefListMem* next()\n"
"    Signature: next|ptr-oaLibDefListMem|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaLibDefListMem_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaLibDefListMem data;
    int convert_status=PyoaIter_oaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaLibDefListMemObject* self=(PyoaIter_oaLibDefListMemObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListMemp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaLibDefListMem_FromoaLibDefListMem(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaLibDefListMem_assign_doc[] = 
"Class: oaIter_oaLibDefListMem, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaLibDefListMem_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaLibDefListMem data;
  int convert_status=PyoaIter_oaLibDefListMem_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaLibDefListMem p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaLibDefListMem_Convert,&p1)) {
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

static PyMethodDef oaIter_oaLibDefListMem_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaLibDefListMem_getNext,METH_VARARGS,oaIter_oaLibDefListMem_getNext_doc},
    {"next",(PyCFunction)oaIter_oaLibDefListMem_next,METH_VARARGS,oaIter_oaLibDefListMem_next_doc},
    {"assign",(PyCFunction)oaIter_oaLibDefListMem_tp_assign,METH_VARARGS,oaIter_oaLibDefListMem_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaLibDefListMem_doc[] = 
"Class: oaIter_oaLibDefListMem\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaLibDefListMem(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaLibDefListMem||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaLibDefListMem)\n"
"    Calls: oaIter_oaLibDefListMem(const oaIter_oaLibDefListMem& iterIn)\n"
"    Signature: oaIter_oaLibDefListMem||cref-oaIter_oaLibDefListMem,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaLibDefListMem)\n"
"    Calls: (const oaIter_oaLibDefListMem&)\n"
"    Signature: oaIter_oaLibDefListMem||cref-oaIter_oaLibDefListMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaLibDefListMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaLibDefListMem",
    sizeof(PyoaIter_oaLibDefListMemObject),
    0,
    (destructor)oaIter_oaLibDefListMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaLibDefListMem_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaLibDefListMem_tp_repr,	/* tp_repr */
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
    oaIter_oaLibDefListMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaLibDefListMem_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaLibDefListMem_iternext,	/* tp_iternext */
    oaIter_oaLibDefListMem_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaLibDefListMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaLibDefListMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaLibDefListMem_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaLibDefListMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaLibDefListMem",
           (PyObject*)(&PyoaIter_oaLibDefListMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaLibDefListMem\n");
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
// Wrapper Implementation for Class: oaIter_oaMarker
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMarker_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaMarker_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaMarkerObject* self = (PyoaIter_oaMarkerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaMarker_oaBlock)
    {
        PyParamoaCollection_oaMarker_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaMarker_oaBlock_Convert,&p1)) {
            self->value =  new oaIter_oaMarker(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaMarker_oaBlockObject)
    {
        PyParamoaCollection_oaMarker_oaBlockObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaMarker_oaBlockObject_Convert,&p1)) {
            self->value =  new oaIter_oaMarker(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaMarker)
    {
        PyParamoaIter_oaMarker p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaMarker_Convert,&p1)) {
            self->value =  new oaIter_oaMarker(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaMarker, Choices are:\n"
        "    (oaCollection_oaMarker_oaBlock)\n"
        "    (oaCollection_oaMarker_oaBlockObject)\n"
        "    (oaIter_oaMarker)\n"
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
oaIter_oaMarker_tp_dealloc(PyoaIter_oaMarkerObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMarker_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaMarker value;
    int convert_status=PyoaIter_oaMarker_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaMarker::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaMarker_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaMarker v1;
    PyParamoaIter_oaMarker v2;
    int convert_status1=PyoaIter_oaMarker_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaMarker_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaMarker_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMarker_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaMarker ob;
    int convert_status=PyoaIter_oaMarker_Convert(self,&ob);
    assert(convert_status!=0);
    oaMarker* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaMarker_FromoaMarker(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaMarker_Convert(PyObject* ob,PyParamoaIter_oaMarker* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaMarker_Check(ob)) {
        result->SetData(  ((PyoaIter_oaMarkerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaMarker Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaMarker_FromoaIter_oaMarker(oaIter_oaMarker* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaMarker_Type.tp_alloc(&PyoaIter_oaMarker_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaMarkerObject* self = (PyoaIter_oaMarkerObject*)bself;
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
static char oaIter_oaMarker_getNext_doc[] = 
"Class: oaIter_oaMarker, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaMarker* getNext()\n"
"    Signature: getNext|ptr-oaMarker|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaMarker_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaMarker data;
    int convert_status=PyoaIter_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaMarkerObject* self=(PyoaIter_oaMarkerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerp result= (data.DataCall()->getNext());
        return PyoaMarker_FromoaMarker(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaMarker_next_doc[] = 
"Class: oaIter_oaMarker, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaMarker* next()\n"
"    Signature: next|ptr-oaMarker|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaMarker_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaMarker data;
    int convert_status=PyoaIter_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaMarkerObject* self=(PyoaIter_oaMarkerObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaMarker_FromoaMarker(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaMarker_reset_doc[] = 
"Class: oaIter_oaMarker, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaMarker_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaMarker data;
    int convert_status=PyoaIter_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaMarkerObject* self=(PyoaIter_oaMarkerObject*)ob;

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

static char oaIter_oaMarker_assign_doc[] = 
"Class: oaIter_oaMarker, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaMarker_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaMarker data;
  int convert_status=PyoaIter_oaMarker_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaMarker p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaMarker_Convert,&p1)) {
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

static PyMethodDef oaIter_oaMarker_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaMarker_getNext,METH_VARARGS,oaIter_oaMarker_getNext_doc},
    {"next",(PyCFunction)oaIter_oaMarker_next,METH_VARARGS,oaIter_oaMarker_next_doc},
    {"reset",(PyCFunction)oaIter_oaMarker_reset,METH_VARARGS,oaIter_oaMarker_reset_doc},
    {"assign",(PyCFunction)oaIter_oaMarker_tp_assign,METH_VARARGS,oaIter_oaMarker_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaMarker_doc[] = 
"Class: oaIter_oaMarker\n"
"  Class type oaIter_oaMarker\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaMarker_oaBlock)\n"
"    Calls: oaIter_oaMarker(const oaCollection_oaMarker_oaBlock& c)\n"
"    Signature: oaIter_oaMarker||cref-oaCollection_oaMarker_oaBlock,\n"
"    Constructor oaIter_oaMarker\n"
"  Paramegers: (oaCollection_oaMarker_oaBlockObject)\n"
"    Calls: oaIter_oaMarker(const oaCollection_oaMarker_oaBlockObject& c)\n"
"    Signature: oaIter_oaMarker||cref-oaCollection_oaMarker_oaBlockObject,\n"
"    Constructor oaIter_oaMarker\n"
"  Paramegers: (oaIter_oaMarker)\n"
"    Calls: oaIter_oaMarker(const oaIter_oaMarker& iterIn)\n"
"    Signature: oaIter_oaMarker||cref-oaIter_oaMarker,\n"
"    Constructor oaIter_oaMarker\n"
"  Paramegers: (oaIter_oaMarker)\n"
"    Calls: (const oaIter_oaMarker&)\n"
"    Signature: oaIter_oaMarker||cref-oaIter_oaMarker,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaMarker_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaMarker",
    sizeof(PyoaIter_oaMarkerObject),
    0,
    (destructor)oaIter_oaMarker_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaMarker_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaMarker_tp_repr,	/* tp_repr */
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
    oaIter_oaMarker_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaMarker_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaMarker_iternext,	/* tp_iternext */
    oaIter_oaMarker_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaMarker_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaMarker_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaMarker_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaMarker\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaMarker",
           (PyObject*)(&PyoaIter_oaMarker_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaMarker\n");
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
// Wrapper Implementation for Class: oaIter_oaModAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModAssignmentObject* self = (PyoaIter_oaModAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModAssignment(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModAssignment)
    {
        PyParamoaIter_oaModAssignment p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModAssignment_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModAssignment(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModAssignment, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModAssignment)\n"
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
oaIter_oaModAssignment_tp_dealloc(PyoaIter_oaModAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModAssignment_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModAssignment value;
    int convert_status=PyoaIter_oaModAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModAssignment v1;
    PyParamoaIter_oaModAssignment v2;
    int convert_status1=PyoaIter_oaModAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModAssignment_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModAssignment_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModAssignment ob;
    int convert_status=PyoaIter_oaModAssignment_Convert(self,&ob);
    assert(convert_status!=0);
    oaModAssignment* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModAssignment_FromoaModAssignment(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModAssignment_Convert(PyObject* ob,PyParamoaIter_oaModAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModAssignment_Check(ob)) {
        result->SetData( (oaIter_oaModAssignment*) ((PyoaIter_oaModAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModAssignment_FromoaIter_oaModAssignment(oaIter_oaModAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModAssignment_Type.tp_alloc(&PyoaIter_oaModAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModAssignmentObject* self = (PyoaIter_oaModAssignmentObject*)bself;
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
static char oaIter_oaModAssignment_getNext_doc[] = 
"Class: oaIter_oaModAssignment, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModAssignment* getNext()\n"
"    Signature: getNext|ptr-oaModAssignment|\n"
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
oaIter_oaModAssignment_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModAssignment data;
    int convert_status=PyoaIter_oaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModAssignmentObject* self=(PyoaIter_oaModAssignmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModAssignmentp result= (data.DataCall()->getNext());
        return PyoaModAssignment_FromoaModAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModAssignment_next_doc[] = 
"Class: oaIter_oaModAssignment, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModAssignment* next()\n"
"    Signature: next|ptr-oaModAssignment|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModAssignment_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModAssignment data;
    int convert_status=PyoaIter_oaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModAssignmentObject* self=(PyoaIter_oaModAssignmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModAssignmentp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModAssignment_FromoaModAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModAssignment_assign_doc[] = 
"Class: oaIter_oaModAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModAssignment data;
  int convert_status=PyoaIter_oaModAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModAssignment_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModAssignment_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModAssignment_getNext,METH_VARARGS,oaIter_oaModAssignment_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModAssignment_next,METH_VARARGS,oaIter_oaModAssignment_next_doc},
    {"assign",(PyCFunction)oaIter_oaModAssignment_tp_assign,METH_VARARGS,oaIter_oaModAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModAssignment_doc[] = 
"Class: oaIter_oaModAssignment\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModAssignment(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModAssignment||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModAssignment)\n"
"    Calls: oaIter_oaModAssignment(const oaIter_oaModAssignment& iterIn)\n"
"    Signature: oaIter_oaModAssignment||cref-oaIter_oaModAssignment,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModAssignment)\n"
"    Calls: (const oaIter_oaModAssignment&)\n"
"    Signature: oaIter_oaModAssignment||cref-oaIter_oaModAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModAssignment",
    sizeof(PyoaIter_oaModAssignmentObject),
    0,
    (destructor)oaIter_oaModAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModAssignment_tp_repr,	/* tp_repr */
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
    oaIter_oaModAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModAssignment_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModAssignment_iternext,	/* tp_iternext */
    oaIter_oaModAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModAssignment",
           (PyObject*)(&PyoaIter_oaModAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModAssignment\n");
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
// Wrapper Implementation for Class: oaIter_oaModBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBitNetObject* self = (PyoaIter_oaModBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBitNet)
    {
        PyParamoaIter_oaModBitNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBitNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBitNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBitNet)\n"
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
oaIter_oaModBitNet_tp_dealloc(PyoaIter_oaModBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBitNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBitNet value;
    int convert_status=PyoaIter_oaModBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaModBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBitNet v1;
    PyParamoaIter_oaModBitNet v2;
    int convert_status1=PyoaIter_oaModBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBitNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBitNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBitNet ob;
    int convert_status=PyoaIter_oaModBitNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBitNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBitNet_FromoaModBitNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBitNet_Convert(PyObject* ob,PyParamoaIter_oaModBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBitNet_Check(ob)) {
        result->SetData( (oaIter_oaModBitNet*) ((PyoaIter_oaModBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBitNet_FromoaIter_oaModBitNet(oaIter_oaModBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBitNet_Type.tp_alloc(&PyoaIter_oaModBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBitNetObject* self = (PyoaIter_oaModBitNetObject*)bself;
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
static char oaIter_oaModBitNet_getNext_doc[] = 
"Class: oaIter_oaModBitNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBitNet* getNext()\n"
"    Signature: getNext|ptr-oaModBitNet|\n"
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
oaIter_oaModBitNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBitNet data;
    int convert_status=PyoaIter_oaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBitNetObject* self=(PyoaIter_oaModBitNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBitNetp result= (data.DataCall()->getNext());
        return PyoaModBitNet_FromoaModBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBitNet_next_doc[] = 
"Class: oaIter_oaModBitNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBitNet* next()\n"
"    Signature: next|ptr-oaModBitNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBitNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBitNet data;
    int convert_status=PyoaIter_oaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBitNetObject* self=(PyoaIter_oaModBitNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBitNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBitNet_FromoaModBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBitNet_assign_doc[] = 
"Class: oaIter_oaModBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBitNet data;
  int convert_status=PyoaIter_oaModBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBitNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBitNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBitNet_getNext,METH_VARARGS,oaIter_oaModBitNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBitNet_next,METH_VARARGS,oaIter_oaModBitNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBitNet_tp_assign,METH_VARARGS,oaIter_oaModBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBitNet_doc[] = 
"Class: oaIter_oaModBitNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBitNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBitNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBitNet)\n"
"    Calls: oaIter_oaModBitNet(const oaIter_oaModBitNet& iterIn)\n"
"    Signature: oaIter_oaModBitNet||cref-oaIter_oaModBitNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBitNet)\n"
"    Calls: (const oaIter_oaModBitNet&)\n"
"    Signature: oaIter_oaModBitNet||cref-oaIter_oaModBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBitNet",
    sizeof(PyoaIter_oaModBitNetObject),
    0,
    (destructor)oaIter_oaModBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBitNet_tp_repr,	/* tp_repr */
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
    oaIter_oaModBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBitNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBitNet_iternext,	/* tp_iternext */
    oaIter_oaModBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBitNet",
           (PyObject*)(&PyoaIter_oaModBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBitNet\n");
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
// Wrapper Implementation for Class: oaIter_oaModBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusNetObject* self = (PyoaIter_oaModBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusNet)
    {
        PyParamoaIter_oaModBusNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusNet)\n"
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
oaIter_oaModBusNet_tp_dealloc(PyoaIter_oaModBusNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusNet value;
    int convert_status=PyoaIter_oaModBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaModBusNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusNet v1;
    PyParamoaIter_oaModBusNet v2;
    int convert_status1=PyoaIter_oaModBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusNet ob;
    int convert_status=PyoaIter_oaModBusNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusNet_FromoaModBusNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusNet_Convert(PyObject* ob,PyParamoaIter_oaModBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusNet_Check(ob)) {
        result->SetData( (oaIter_oaModBusNet*) ((PyoaIter_oaModBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusNet_FromoaIter_oaModBusNet(oaIter_oaModBusNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusNet_Type.tp_alloc(&PyoaIter_oaModBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusNetObject* self = (PyoaIter_oaModBusNetObject*)bself;
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
static char oaIter_oaModBusNet_getNext_doc[] = 
"Class: oaIter_oaModBusNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNet* getNext()\n"
"    Signature: getNext|ptr-oaModBusNet|\n"
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
oaIter_oaModBusNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNet data;
    int convert_status=PyoaIter_oaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetObject* self=(PyoaIter_oaModBusNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetp result= (data.DataCall()->getNext());
        return PyoaModBusNet_FromoaModBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusNet_next_doc[] = 
"Class: oaIter_oaModBusNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNet* next()\n"
"    Signature: next|ptr-oaModBusNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNet data;
    int convert_status=PyoaIter_oaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetObject* self=(PyoaIter_oaModBusNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusNet_FromoaModBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusNet_assign_doc[] = 
"Class: oaIter_oaModBusNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusNet data;
  int convert_status=PyoaIter_oaModBusNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusNet_getNext,METH_VARARGS,oaIter_oaModBusNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusNet_next,METH_VARARGS,oaIter_oaModBusNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusNet_tp_assign,METH_VARARGS,oaIter_oaModBusNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusNet_doc[] = 
"Class: oaIter_oaModBusNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusNet)\n"
"    Calls: oaIter_oaModBusNet(const oaIter_oaModBusNet& iterIn)\n"
"    Signature: oaIter_oaModBusNet||cref-oaIter_oaModBusNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusNet)\n"
"    Calls: (const oaIter_oaModBusNet&)\n"
"    Signature: oaIter_oaModBusNet||cref-oaIter_oaModBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusNet",
    sizeof(PyoaIter_oaModBusNetObject),
    0,
    (destructor)oaIter_oaModBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusNet_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusNet_iternext,	/* tp_iternext */
    oaIter_oaModBusNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusNet",
           (PyObject*)(&PyoaIter_oaModBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusNet\n");
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
// Wrapper Implementation for Class: oaIter_oaModBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusNetBitObject* self = (PyoaIter_oaModBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNetBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusNetBit)
    {
        PyParamoaIter_oaModBusNetBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusNetBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNetBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusNetBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusNetBit)\n"
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
oaIter_oaModBusNetBit_tp_dealloc(PyoaIter_oaModBusNetBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusNetBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusNetBit value;
    int convert_status=PyoaIter_oaModBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaModBusNetBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusNetBit v1;
    PyParamoaIter_oaModBusNetBit v2;
    int convert_status1=PyoaIter_oaModBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusNetBit ob;
    int convert_status=PyoaIter_oaModBusNetBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusNetBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusNetBit_FromoaModBusNetBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusNetBit_Convert(PyObject* ob,PyParamoaIter_oaModBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusNetBit_Check(ob)) {
        result->SetData( (oaIter_oaModBusNetBit*) ((PyoaIter_oaModBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusNetBit_FromoaIter_oaModBusNetBit(oaIter_oaModBusNetBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusNetBit_Type.tp_alloc(&PyoaIter_oaModBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusNetBitObject* self = (PyoaIter_oaModBusNetBitObject*)bself;
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
static char oaIter_oaModBusNetBit_getNext_doc[] = 
"Class: oaIter_oaModBusNetBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetBit* getNext()\n"
"    Signature: getNext|ptr-oaModBusNetBit|\n"
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
oaIter_oaModBusNetBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNetBit data;
    int convert_status=PyoaIter_oaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetBitObject* self=(PyoaIter_oaModBusNetBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetBitp result= (data.DataCall()->getNext());
        return PyoaModBusNetBit_FromoaModBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusNetBit_next_doc[] = 
"Class: oaIter_oaModBusNetBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetBit* next()\n"
"    Signature: next|ptr-oaModBusNetBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusNetBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNetBit data;
    int convert_status=PyoaIter_oaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetBitObject* self=(PyoaIter_oaModBusNetBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusNetBit_FromoaModBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusNetBit_assign_doc[] = 
"Class: oaIter_oaModBusNetBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusNetBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusNetBit data;
  int convert_status=PyoaIter_oaModBusNetBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusNetBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusNetBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusNetBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusNetBit_getNext,METH_VARARGS,oaIter_oaModBusNetBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusNetBit_next,METH_VARARGS,oaIter_oaModBusNetBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusNetBit_tp_assign,METH_VARARGS,oaIter_oaModBusNetBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusNetBit_doc[] = 
"Class: oaIter_oaModBusNetBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusNetBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusNetBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusNetBit)\n"
"    Calls: oaIter_oaModBusNetBit(const oaIter_oaModBusNetBit& iterIn)\n"
"    Signature: oaIter_oaModBusNetBit||cref-oaIter_oaModBusNetBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusNetBit)\n"
"    Calls: (const oaIter_oaModBusNetBit&)\n"
"    Signature: oaIter_oaModBusNetBit||cref-oaIter_oaModBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusNetBit",
    sizeof(PyoaIter_oaModBusNetBitObject),
    0,
    (destructor)oaIter_oaModBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusNetBit_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusNetBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusNetBit_iternext,	/* tp_iternext */
    oaIter_oaModBusNetBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusNetBit",
           (PyObject*)(&PyoaIter_oaModBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusNetBit\n");
       return -1;
    }
    return 0;
}

