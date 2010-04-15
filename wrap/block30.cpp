
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
// Wrapper Implementation for Class: oaIter_oaModBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusNetDefObject* self = (PyoaIter_oaModBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusNetDef)
    {
        PyParamoaIter_oaModBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusNetDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusNetDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusNetDef)\n"
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
oaIter_oaModBusNetDef_tp_dealloc(PyoaIter_oaModBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusNetDef value;
    int convert_status=PyoaIter_oaModBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaModBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusNetDef v1;
    PyParamoaIter_oaModBusNetDef v2;
    int convert_status1=PyoaIter_oaModBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusNetDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusNetDef ob;
    int convert_status=PyoaIter_oaModBusNetDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusNetDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusNetDef_FromoaModBusNetDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusNetDef_Convert(PyObject* ob,PyParamoaIter_oaModBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusNetDef_Check(ob)) {
        result->SetData( (oaIter_oaModBusNetDef*) ((PyoaIter_oaModBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusNetDef_FromoaIter_oaModBusNetDef(oaIter_oaModBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusNetDef_Type.tp_alloc(&PyoaIter_oaModBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusNetDefObject* self = (PyoaIter_oaModBusNetDefObject*)bself;
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
static char oaIter_oaModBusNetDef_getNext_doc[] = 
"Class: oaIter_oaModBusNetDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetDef* getNext()\n"
"    Signature: getNext|ptr-oaModBusNetDef|\n"
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
oaIter_oaModBusNetDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNetDef data;
    int convert_status=PyoaIter_oaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetDefObject* self=(PyoaIter_oaModBusNetDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetDefp result= (data.DataCall()->getNext());
        return PyoaModBusNetDef_FromoaModBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusNetDef_next_doc[] = 
"Class: oaIter_oaModBusNetDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetDef* next()\n"
"    Signature: next|ptr-oaModBusNetDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusNetDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusNetDef data;
    int convert_status=PyoaIter_oaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusNetDefObject* self=(PyoaIter_oaModBusNetDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusNetDef_FromoaModBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusNetDef_assign_doc[] = 
"Class: oaIter_oaModBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusNetDef data;
  int convert_status=PyoaIter_oaModBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusNetDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusNetDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusNetDef_getNext,METH_VARARGS,oaIter_oaModBusNetDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusNetDef_next,METH_VARARGS,oaIter_oaModBusNetDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusNetDef_tp_assign,METH_VARARGS,oaIter_oaModBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusNetDef_doc[] = 
"Class: oaIter_oaModBusNetDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusNetDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusNetDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusNetDef)\n"
"    Calls: oaIter_oaModBusNetDef(const oaIter_oaModBusNetDef& iterIn)\n"
"    Signature: oaIter_oaModBusNetDef||cref-oaIter_oaModBusNetDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusNetDef)\n"
"    Calls: (const oaIter_oaModBusNetDef&)\n"
"    Signature: oaIter_oaModBusNetDef||cref-oaIter_oaModBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusNetDef",
    sizeof(PyoaIter_oaModBusNetDefObject),
    0,
    (destructor)oaIter_oaModBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusNetDef_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusNetDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusNetDef_iternext,	/* tp_iternext */
    oaIter_oaModBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusNetDef",
           (PyObject*)(&PyoaIter_oaModBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusNetDef\n");
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
// Wrapper Implementation for Class: oaIter_oaModBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusTermObject* self = (PyoaIter_oaModBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusTerm)
    {
        PyParamoaIter_oaModBusTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusTerm)\n"
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
oaIter_oaModBusTerm_tp_dealloc(PyoaIter_oaModBusTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusTerm value;
    int convert_status=PyoaIter_oaModBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaModBusTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusTerm v1;
    PyParamoaIter_oaModBusTerm v2;
    int convert_status1=PyoaIter_oaModBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusTerm ob;
    int convert_status=PyoaIter_oaModBusTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusTerm_FromoaModBusTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusTerm_Convert(PyObject* ob,PyParamoaIter_oaModBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusTerm_Check(ob)) {
        result->SetData( (oaIter_oaModBusTerm*) ((PyoaIter_oaModBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusTerm_FromoaIter_oaModBusTerm(oaIter_oaModBusTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusTerm_Type.tp_alloc(&PyoaIter_oaModBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusTermObject* self = (PyoaIter_oaModBusTermObject*)bself;
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
static char oaIter_oaModBusTerm_getNext_doc[] = 
"Class: oaIter_oaModBusTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTerm* getNext()\n"
"    Signature: getNext|ptr-oaModBusTerm|\n"
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
oaIter_oaModBusTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTerm data;
    int convert_status=PyoaIter_oaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermObject* self=(PyoaIter_oaModBusTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermp result= (data.DataCall()->getNext());
        return PyoaModBusTerm_FromoaModBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusTerm_next_doc[] = 
"Class: oaIter_oaModBusTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTerm* next()\n"
"    Signature: next|ptr-oaModBusTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTerm data;
    int convert_status=PyoaIter_oaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermObject* self=(PyoaIter_oaModBusTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusTerm_FromoaModBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusTerm_assign_doc[] = 
"Class: oaIter_oaModBusTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusTerm data;
  int convert_status=PyoaIter_oaModBusTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusTerm_getNext,METH_VARARGS,oaIter_oaModBusTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusTerm_next,METH_VARARGS,oaIter_oaModBusTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusTerm_tp_assign,METH_VARARGS,oaIter_oaModBusTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusTerm_doc[] = 
"Class: oaIter_oaModBusTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusTerm)\n"
"    Calls: oaIter_oaModBusTerm(const oaIter_oaModBusTerm& iterIn)\n"
"    Signature: oaIter_oaModBusTerm||cref-oaIter_oaModBusTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusTerm)\n"
"    Calls: (const oaIter_oaModBusTerm&)\n"
"    Signature: oaIter_oaModBusTerm||cref-oaIter_oaModBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusTerm",
    sizeof(PyoaIter_oaModBusTermObject),
    0,
    (destructor)oaIter_oaModBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusTerm_iternext,	/* tp_iternext */
    oaIter_oaModBusTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusTerm",
           (PyObject*)(&PyoaIter_oaModBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaModBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusTermBitObject* self = (PyoaIter_oaModBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusTermBit)
    {
        PyParamoaIter_oaModBusTermBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusTermBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusTermBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusTermBit)\n"
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
oaIter_oaModBusTermBit_tp_dealloc(PyoaIter_oaModBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusTermBit value;
    int convert_status=PyoaIter_oaModBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusTermBit v1;
    PyParamoaIter_oaModBusTermBit v2;
    int convert_status1=PyoaIter_oaModBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusTermBit ob;
    int convert_status=PyoaIter_oaModBusTermBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusTermBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusTermBit_FromoaModBusTermBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusTermBit_Convert(PyObject* ob,PyParamoaIter_oaModBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusTermBit_Check(ob)) {
        result->SetData( (oaIter_oaModBusTermBit*) ((PyoaIter_oaModBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusTermBit_FromoaIter_oaModBusTermBit(oaIter_oaModBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusTermBit_Type.tp_alloc(&PyoaIter_oaModBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusTermBitObject* self = (PyoaIter_oaModBusTermBitObject*)bself;
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
static char oaIter_oaModBusTermBit_getNext_doc[] = 
"Class: oaIter_oaModBusTermBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermBit* getNext()\n"
"    Signature: getNext|ptr-oaModBusTermBit|\n"
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
oaIter_oaModBusTermBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTermBit data;
    int convert_status=PyoaIter_oaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermBitObject* self=(PyoaIter_oaModBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermBitp result= (data.DataCall()->getNext());
        return PyoaModBusTermBit_FromoaModBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusTermBit_next_doc[] = 
"Class: oaIter_oaModBusTermBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermBit* next()\n"
"    Signature: next|ptr-oaModBusTermBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusTermBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTermBit data;
    int convert_status=PyoaIter_oaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermBitObject* self=(PyoaIter_oaModBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusTermBit_FromoaModBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusTermBit_assign_doc[] = 
"Class: oaIter_oaModBusTermBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusTermBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusTermBit data;
  int convert_status=PyoaIter_oaModBusTermBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusTermBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusTermBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusTermBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusTermBit_getNext,METH_VARARGS,oaIter_oaModBusTermBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusTermBit_next,METH_VARARGS,oaIter_oaModBusTermBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusTermBit_tp_assign,METH_VARARGS,oaIter_oaModBusTermBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusTermBit_doc[] = 
"Class: oaIter_oaModBusTermBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusTermBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusTermBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusTermBit)\n"
"    Calls: oaIter_oaModBusTermBit(const oaIter_oaModBusTermBit& iterIn)\n"
"    Signature: oaIter_oaModBusTermBit||cref-oaIter_oaModBusTermBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusTermBit)\n"
"    Calls: (const oaIter_oaModBusTermBit&)\n"
"    Signature: oaIter_oaModBusTermBit||cref-oaIter_oaModBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusTermBit",
    sizeof(PyoaIter_oaModBusTermBitObject),
    0,
    (destructor)oaIter_oaModBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusTermBit_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusTermBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusTermBit_iternext,	/* tp_iternext */
    oaIter_oaModBusTermBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusTermBit",
           (PyObject*)(&PyoaIter_oaModBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusTermBit\n");
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
// Wrapper Implementation for Class: oaIter_oaModBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModBusTermDefObject* self = (PyoaIter_oaModBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModBusTermDef)
    {
        PyParamoaIter_oaModBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModBusTermDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModBusTermDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModBusTermDef)\n"
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
oaIter_oaModBusTermDef_tp_dealloc(PyoaIter_oaModBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModBusTermDef value;
    int convert_status=PyoaIter_oaModBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModBusTermDef v1;
    PyParamoaIter_oaModBusTermDef v2;
    int convert_status1=PyoaIter_oaModBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModBusTermDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModBusTermDef ob;
    int convert_status=PyoaIter_oaModBusTermDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaModBusTermDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModBusTermDef_FromoaModBusTermDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModBusTermDef_Convert(PyObject* ob,PyParamoaIter_oaModBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModBusTermDef_Check(ob)) {
        result->SetData( (oaIter_oaModBusTermDef*) ((PyoaIter_oaModBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModBusTermDef_FromoaIter_oaModBusTermDef(oaIter_oaModBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModBusTermDef_Type.tp_alloc(&PyoaIter_oaModBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModBusTermDefObject* self = (PyoaIter_oaModBusTermDefObject*)bself;
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
static char oaIter_oaModBusTermDef_getNext_doc[] = 
"Class: oaIter_oaModBusTermDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermDef* getNext()\n"
"    Signature: getNext|ptr-oaModBusTermDef|\n"
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
oaIter_oaModBusTermDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTermDef data;
    int convert_status=PyoaIter_oaModBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermDefObject* self=(PyoaIter_oaModBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermDefp result= (data.DataCall()->getNext());
        return PyoaModBusTermDef_FromoaModBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModBusTermDef_next_doc[] = 
"Class: oaIter_oaModBusTermDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermDef* next()\n"
"    Signature: next|ptr-oaModBusTermDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModBusTermDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModBusTermDef data;
    int convert_status=PyoaIter_oaModBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModBusTermDefObject* self=(PyoaIter_oaModBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModBusTermDef_FromoaModBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModBusTermDef_assign_doc[] = 
"Class: oaIter_oaModBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModBusTermDef data;
  int convert_status=PyoaIter_oaModBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModBusTermDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModBusTermDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModBusTermDef_getNext,METH_VARARGS,oaIter_oaModBusTermDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModBusTermDef_next,METH_VARARGS,oaIter_oaModBusTermDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaModBusTermDef_tp_assign,METH_VARARGS,oaIter_oaModBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModBusTermDef_doc[] = 
"Class: oaIter_oaModBusTermDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModBusTermDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModBusTermDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModBusTermDef)\n"
"    Calls: oaIter_oaModBusTermDef(const oaIter_oaModBusTermDef& iterIn)\n"
"    Signature: oaIter_oaModBusTermDef||cref-oaIter_oaModBusTermDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModBusTermDef)\n"
"    Calls: (const oaIter_oaModBusTermDef&)\n"
"    Signature: oaIter_oaModBusTermDef||cref-oaIter_oaModBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModBusTermDef",
    sizeof(PyoaIter_oaModBusTermDefObject),
    0,
    (destructor)oaIter_oaModBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModBusTermDef_tp_repr,	/* tp_repr */
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
    oaIter_oaModBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModBusTermDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModBusTermDef_iternext,	/* tp_iternext */
    oaIter_oaModBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModBusTermDef",
           (PyObject*)(&PyoaIter_oaModBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModBusTermDef\n");
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
// Wrapper Implementation for Class: oaIter_oaModConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModConnectDefObject* self = (PyoaIter_oaModConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModConnectDef)
    {
        PyParamoaIter_oaModConnectDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModConnectDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModConnectDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModConnectDef)\n"
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
oaIter_oaModConnectDef_tp_dealloc(PyoaIter_oaModConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModConnectDef value;
    int convert_status=PyoaIter_oaModConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModConnectDef v1;
    PyParamoaIter_oaModConnectDef v2;
    int convert_status1=PyoaIter_oaModConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModConnectDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModConnectDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModConnectDef ob;
    int convert_status=PyoaIter_oaModConnectDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaModConnectDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModConnectDef_FromoaModConnectDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModConnectDef_Convert(PyObject* ob,PyParamoaIter_oaModConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModConnectDef_Check(ob)) {
        result->SetData( (oaIter_oaModConnectDef*) ((PyoaIter_oaModConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModConnectDef_FromoaIter_oaModConnectDef(oaIter_oaModConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModConnectDef_Type.tp_alloc(&PyoaIter_oaModConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModConnectDefObject* self = (PyoaIter_oaModConnectDefObject*)bself;
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
static char oaIter_oaModConnectDef_getNext_doc[] = 
"Class: oaIter_oaModConnectDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModConnectDef* getNext()\n"
"    Signature: getNext|ptr-oaModConnectDef|\n"
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
oaIter_oaModConnectDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModConnectDef data;
    int convert_status=PyoaIter_oaModConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModConnectDefObject* self=(PyoaIter_oaModConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModConnectDefp result= (data.DataCall()->getNext());
        return PyoaModConnectDef_FromoaModConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModConnectDef_next_doc[] = 
"Class: oaIter_oaModConnectDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModConnectDef* next()\n"
"    Signature: next|ptr-oaModConnectDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModConnectDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModConnectDef data;
    int convert_status=PyoaIter_oaModConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModConnectDefObject* self=(PyoaIter_oaModConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModConnectDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModConnectDef_FromoaModConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModConnectDef_assign_doc[] = 
"Class: oaIter_oaModConnectDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModConnectDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModConnectDef data;
  int convert_status=PyoaIter_oaModConnectDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModConnectDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModConnectDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModConnectDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModConnectDef_getNext,METH_VARARGS,oaIter_oaModConnectDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModConnectDef_next,METH_VARARGS,oaIter_oaModConnectDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaModConnectDef_tp_assign,METH_VARARGS,oaIter_oaModConnectDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModConnectDef_doc[] = 
"Class: oaIter_oaModConnectDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModConnectDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModConnectDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModConnectDef)\n"
"    Calls: oaIter_oaModConnectDef(const oaIter_oaModConnectDef& iterIn)\n"
"    Signature: oaIter_oaModConnectDef||cref-oaIter_oaModConnectDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModConnectDef)\n"
"    Calls: (const oaIter_oaModConnectDef&)\n"
"    Signature: oaIter_oaModConnectDef||cref-oaIter_oaModConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModConnectDef",
    sizeof(PyoaIter_oaModConnectDefObject),
    0,
    (destructor)oaIter_oaModConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModConnectDef_tp_repr,	/* tp_repr */
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
    oaIter_oaModConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModConnectDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModConnectDef_iternext,	/* tp_iternext */
    oaIter_oaModConnectDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModConnectDef",
           (PyObject*)(&PyoaIter_oaModConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModConnectDef\n");
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
// Wrapper Implementation for Class: oaIter_oaModDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModDesignInstObject* self = (PyoaIter_oaModDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModDesignInst)
    {
        PyParamoaIter_oaModDesignInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModDesignInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModDesignInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModDesignInst)\n"
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
oaIter_oaModDesignInst_tp_dealloc(PyoaIter_oaModDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModDesignInst value;
    int convert_status=PyoaIter_oaModDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModDesignInst v1;
    PyParamoaIter_oaModDesignInst v2;
    int convert_status1=PyoaIter_oaModDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModDesignInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModDesignInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModDesignInst ob;
    int convert_status=PyoaIter_oaModDesignInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaModDesignInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModDesignInst_FromoaModDesignInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModDesignInst_Convert(PyObject* ob,PyParamoaIter_oaModDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModDesignInst_Check(ob)) {
        result->SetData( (oaIter_oaModDesignInst*) ((PyoaIter_oaModDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModDesignInst_FromoaIter_oaModDesignInst(oaIter_oaModDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModDesignInst_Type.tp_alloc(&PyoaIter_oaModDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModDesignInstObject* self = (PyoaIter_oaModDesignInstObject*)bself;
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
static char oaIter_oaModDesignInst_getNext_doc[] = 
"Class: oaIter_oaModDesignInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModDesignInst* getNext()\n"
"    Signature: getNext|ptr-oaModDesignInst|\n"
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
oaIter_oaModDesignInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModDesignInst data;
    int convert_status=PyoaIter_oaModDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModDesignInstObject* self=(PyoaIter_oaModDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModDesignInstp result= (data.DataCall()->getNext());
        return PyoaModDesignInst_FromoaModDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModDesignInst_next_doc[] = 
"Class: oaIter_oaModDesignInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModDesignInst* next()\n"
"    Signature: next|ptr-oaModDesignInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModDesignInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModDesignInst data;
    int convert_status=PyoaIter_oaModDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModDesignInstObject* self=(PyoaIter_oaModDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModDesignInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModDesignInst_FromoaModDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModDesignInst_assign_doc[] = 
"Class: oaIter_oaModDesignInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModDesignInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModDesignInst data;
  int convert_status=PyoaIter_oaModDesignInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModDesignInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModDesignInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModDesignInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModDesignInst_getNext,METH_VARARGS,oaIter_oaModDesignInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModDesignInst_next,METH_VARARGS,oaIter_oaModDesignInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaModDesignInst_tp_assign,METH_VARARGS,oaIter_oaModDesignInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModDesignInst_doc[] = 
"Class: oaIter_oaModDesignInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModDesignInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModDesignInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModDesignInst)\n"
"    Calls: oaIter_oaModDesignInst(const oaIter_oaModDesignInst& iterIn)\n"
"    Signature: oaIter_oaModDesignInst||cref-oaIter_oaModDesignInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModDesignInst)\n"
"    Calls: (const oaIter_oaModDesignInst&)\n"
"    Signature: oaIter_oaModDesignInst||cref-oaIter_oaModDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModDesignInst",
    sizeof(PyoaIter_oaModDesignInstObject),
    0,
    (destructor)oaIter_oaModDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModDesignInst_tp_repr,	/* tp_repr */
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
    oaIter_oaModDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModDesignInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModDesignInst_iternext,	/* tp_iternext */
    oaIter_oaModDesignInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModDesignInst",
           (PyObject*)(&PyoaIter_oaModDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModDesignInst\n");
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
// Wrapper Implementation for Class: oaIter_oaModInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModInstObject* self = (PyoaIter_oaModInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModInst)
    {
        PyParamoaIter_oaModInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModInst)\n"
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
oaIter_oaModInst_tp_dealloc(PyoaIter_oaModInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModInst value;
    int convert_status=PyoaIter_oaModInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaModInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModInst v1;
    PyParamoaIter_oaModInst v2;
    int convert_status1=PyoaIter_oaModInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModInst ob;
    int convert_status=PyoaIter_oaModInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaModInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModInst_FromoaModInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModInst_Convert(PyObject* ob,PyParamoaIter_oaModInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModInst_Check(ob)) {
        result->SetData( (oaIter_oaModInst*) ((PyoaIter_oaModInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModInst_FromoaIter_oaModInst(oaIter_oaModInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModInst_Type.tp_alloc(&PyoaIter_oaModInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModInstObject* self = (PyoaIter_oaModInstObject*)bself;
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
static char oaIter_oaModInst_getNext_doc[] = 
"Class: oaIter_oaModInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModInst* getNext()\n"
"    Signature: getNext|ptr-oaModInst|\n"
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
oaIter_oaModInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInst data;
    int convert_status=PyoaIter_oaModInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstObject* self=(PyoaIter_oaModInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstp result= (data.DataCall()->getNext());
        return PyoaModInst_FromoaModInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModInst_next_doc[] = 
"Class: oaIter_oaModInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModInst* next()\n"
"    Signature: next|ptr-oaModInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInst data;
    int convert_status=PyoaIter_oaModInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstObject* self=(PyoaIter_oaModInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModInst_FromoaModInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModInst_assign_doc[] = 
"Class: oaIter_oaModInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModInst data;
  int convert_status=PyoaIter_oaModInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModInst_getNext,METH_VARARGS,oaIter_oaModInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModInst_next,METH_VARARGS,oaIter_oaModInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaModInst_tp_assign,METH_VARARGS,oaIter_oaModInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModInst_doc[] = 
"Class: oaIter_oaModInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModInst)\n"
"    Calls: oaIter_oaModInst(const oaIter_oaModInst& iterIn)\n"
"    Signature: oaIter_oaModInst||cref-oaIter_oaModInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModInst)\n"
"    Calls: (const oaIter_oaModInst&)\n"
"    Signature: oaIter_oaModInst||cref-oaIter_oaModInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModInst",
    sizeof(PyoaIter_oaModInstObject),
    0,
    (destructor)oaIter_oaModInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModInst_tp_repr,	/* tp_repr */
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
    oaIter_oaModInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModInst_iternext,	/* tp_iternext */
    oaIter_oaModInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModInst",
           (PyObject*)(&PyoaIter_oaModInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModInst\n");
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
// Wrapper Implementation for Class: oaIter_oaModInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModInstHeaderObject* self = (PyoaIter_oaModInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModInstHeader)
    {
        PyParamoaIter_oaModInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModInstHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModInstHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModInstHeader)\n"
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
oaIter_oaModInstHeader_tp_dealloc(PyoaIter_oaModInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModInstHeader value;
    int convert_status=PyoaIter_oaModInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModInstHeader v1;
    PyParamoaIter_oaModInstHeader v2;
    int convert_status1=PyoaIter_oaModInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModInstHeader ob;
    int convert_status=PyoaIter_oaModInstHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaModInstHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModInstHeader_FromoaModInstHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModInstHeader_Convert(PyObject* ob,PyParamoaIter_oaModInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModInstHeader_Check(ob)) {
        result->SetData( (oaIter_oaModInstHeader*) ((PyoaIter_oaModInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModInstHeader_FromoaIter_oaModInstHeader(oaIter_oaModInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModInstHeader_Type.tp_alloc(&PyoaIter_oaModInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModInstHeaderObject* self = (PyoaIter_oaModInstHeaderObject*)bself;
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
static char oaIter_oaModInstHeader_getNext_doc[] = 
"Class: oaIter_oaModInstHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModInstHeader* getNext()\n"
"    Signature: getNext|ptr-oaModInstHeader|\n"
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
oaIter_oaModInstHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInstHeader data;
    int convert_status=PyoaIter_oaModInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstHeaderObject* self=(PyoaIter_oaModInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstHeaderp result= (data.DataCall()->getNext());
        return PyoaModInstHeader_FromoaModInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModInstHeader_next_doc[] = 
"Class: oaIter_oaModInstHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModInstHeader* next()\n"
"    Signature: next|ptr-oaModInstHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModInstHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInstHeader data;
    int convert_status=PyoaIter_oaModInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstHeaderObject* self=(PyoaIter_oaModInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModInstHeader_FromoaModInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModInstHeader_assign_doc[] = 
"Class: oaIter_oaModInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModInstHeader data;
  int convert_status=PyoaIter_oaModInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModInstHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModInstHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModInstHeader_getNext,METH_VARARGS,oaIter_oaModInstHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModInstHeader_next,METH_VARARGS,oaIter_oaModInstHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaModInstHeader_tp_assign,METH_VARARGS,oaIter_oaModInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModInstHeader_doc[] = 
"Class: oaIter_oaModInstHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModInstHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModInstHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModInstHeader)\n"
"    Calls: oaIter_oaModInstHeader(const oaIter_oaModInstHeader& iterIn)\n"
"    Signature: oaIter_oaModInstHeader||cref-oaIter_oaModInstHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModInstHeader)\n"
"    Calls: (const oaIter_oaModInstHeader&)\n"
"    Signature: oaIter_oaModInstHeader||cref-oaIter_oaModInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModInstHeader",
    sizeof(PyoaIter_oaModInstHeaderObject),
    0,
    (destructor)oaIter_oaModInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModInstHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaModInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModInstHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModInstHeader_iternext,	/* tp_iternext */
    oaIter_oaModInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModInstHeader",
           (PyObject*)(&PyoaIter_oaModInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModInstHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaModInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModInstTermObject* self = (PyoaIter_oaModInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModInstTerm)
    {
        PyParamoaIter_oaModInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModInstTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModInstTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModInstTerm)\n"
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
oaIter_oaModInstTerm_tp_dealloc(PyoaIter_oaModInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModInstTerm value;
    int convert_status=PyoaIter_oaModInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaModInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModInstTerm v1;
    PyParamoaIter_oaModInstTerm v2;
    int convert_status1=PyoaIter_oaModInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModInstTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModInstTerm ob;
    int convert_status=PyoaIter_oaModInstTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaModInstTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModInstTerm_FromoaModInstTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModInstTerm_Convert(PyObject* ob,PyParamoaIter_oaModInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModInstTerm_Check(ob)) {
        result->SetData( (oaIter_oaModInstTerm*) ((PyoaIter_oaModInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModInstTerm_FromoaIter_oaModInstTerm(oaIter_oaModInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModInstTerm_Type.tp_alloc(&PyoaIter_oaModInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModInstTermObject* self = (PyoaIter_oaModInstTermObject*)bself;
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
static char oaIter_oaModInstTerm_getNext_doc[] = 
"Class: oaIter_oaModInstTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModInstTerm* getNext()\n"
"    Signature: getNext|ptr-oaModInstTerm|\n"
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
oaIter_oaModInstTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInstTerm data;
    int convert_status=PyoaIter_oaModInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstTermObject* self=(PyoaIter_oaModInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstTermp result= (data.DataCall()->getNext());
        return PyoaModInstTerm_FromoaModInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModInstTerm_next_doc[] = 
"Class: oaIter_oaModInstTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModInstTerm* next()\n"
"    Signature: next|ptr-oaModInstTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModInstTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModInstTerm data;
    int convert_status=PyoaIter_oaModInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModInstTermObject* self=(PyoaIter_oaModInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModInstTerm_FromoaModInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModInstTerm_assign_doc[] = 
"Class: oaIter_oaModInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModInstTerm data;
  int convert_status=PyoaIter_oaModInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModInstTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModInstTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModInstTerm_getNext,METH_VARARGS,oaIter_oaModInstTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModInstTerm_next,METH_VARARGS,oaIter_oaModInstTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaModInstTerm_tp_assign,METH_VARARGS,oaIter_oaModInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModInstTerm_doc[] = 
"Class: oaIter_oaModInstTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModInstTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModInstTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModInstTerm)\n"
"    Calls: oaIter_oaModInstTerm(const oaIter_oaModInstTerm& iterIn)\n"
"    Signature: oaIter_oaModInstTerm||cref-oaIter_oaModInstTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModInstTerm)\n"
"    Calls: (const oaIter_oaModInstTerm&)\n"
"    Signature: oaIter_oaModInstTerm||cref-oaIter_oaModInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModInstTerm",
    sizeof(PyoaIter_oaModInstTermObject),
    0,
    (destructor)oaIter_oaModInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModInstTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaModInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModInstTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModInstTerm_iternext,	/* tp_iternext */
    oaIter_oaModInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModInstTerm",
           (PyObject*)(&PyoaIter_oaModInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModInstTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaModModuleInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModModuleInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModModuleInstObject* self = (PyoaIter_oaModModuleInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModModuleInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModModuleInst)
    {
        PyParamoaIter_oaModModuleInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModModuleInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModModuleInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModModuleInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModModuleInst)\n"
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
oaIter_oaModModuleInst_tp_dealloc(PyoaIter_oaModModuleInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModModuleInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModModuleInst value;
    int convert_status=PyoaIter_oaModModuleInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaModModuleInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModModuleInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModModuleInst v1;
    PyParamoaIter_oaModModuleInst v2;
    int convert_status1=PyoaIter_oaModModuleInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModModuleInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModModuleInst ob;
    int convert_status=PyoaIter_oaModModuleInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaModModuleInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModModuleInst_FromoaModModuleInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModModuleInst_Convert(PyObject* ob,PyParamoaIter_oaModModuleInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModModuleInst_Check(ob)) {
        result->SetData( (oaIter_oaModModuleInst*) ((PyoaIter_oaModModuleInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModModuleInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModModuleInst_FromoaIter_oaModModuleInst(oaIter_oaModModuleInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModModuleInst_Type.tp_alloc(&PyoaIter_oaModModuleInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModModuleInstObject* self = (PyoaIter_oaModModuleInstObject*)bself;
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
static char oaIter_oaModModuleInst_getNext_doc[] = 
"Class: oaIter_oaModModuleInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModModuleInst* getNext()\n"
"    Signature: getNext|ptr-oaModModuleInst|\n"
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
oaIter_oaModModuleInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModModuleInst data;
    int convert_status=PyoaIter_oaModModuleInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModModuleInstObject* self=(PyoaIter_oaModModuleInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModModuleInstp result= (data.DataCall()->getNext());
        return PyoaModModuleInst_FromoaModModuleInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModModuleInst_next_doc[] = 
"Class: oaIter_oaModModuleInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModModuleInst* next()\n"
"    Signature: next|ptr-oaModModuleInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModModuleInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModModuleInst data;
    int convert_status=PyoaIter_oaModModuleInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModModuleInstObject* self=(PyoaIter_oaModModuleInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModModuleInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModModuleInst_FromoaModModuleInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModModuleInst_assign_doc[] = 
"Class: oaIter_oaModModuleInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModModuleInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModModuleInst data;
  int convert_status=PyoaIter_oaModModuleInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModModuleInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModModuleInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModModuleInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModModuleInst_getNext,METH_VARARGS,oaIter_oaModModuleInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModModuleInst_next,METH_VARARGS,oaIter_oaModModuleInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaModModuleInst_tp_assign,METH_VARARGS,oaIter_oaModModuleInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModModuleInst_doc[] = 
"Class: oaIter_oaModModuleInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModModuleInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModModuleInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModModuleInst)\n"
"    Calls: oaIter_oaModModuleInst(const oaIter_oaModModuleInst& iterIn)\n"
"    Signature: oaIter_oaModModuleInst||cref-oaIter_oaModModuleInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModModuleInst)\n"
"    Calls: (const oaIter_oaModModuleInst&)\n"
"    Signature: oaIter_oaModModuleInst||cref-oaIter_oaModModuleInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModModuleInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModModuleInst",
    sizeof(PyoaIter_oaModModuleInstObject),
    0,
    (destructor)oaIter_oaModModuleInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModModuleInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModModuleInst_tp_repr,	/* tp_repr */
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
    oaIter_oaModModuleInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModModuleInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModModuleInst_iternext,	/* tp_iternext */
    oaIter_oaModModuleInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModModuleInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModModuleInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModModuleInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModModuleInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModModuleInst",
           (PyObject*)(&PyoaIter_oaModModuleInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModModuleInst\n");
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
// Wrapper Implementation for Class: oaIter_oaModModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModModuleInstHeaderObject* self = (PyoaIter_oaModModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModModuleInstHeader)
    {
        PyParamoaIter_oaModModuleInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModModuleInstHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModModuleInstHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModModuleInstHeader)\n"
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
oaIter_oaModModuleInstHeader_tp_dealloc(PyoaIter_oaModModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModModuleInstHeader value;
    int convert_status=PyoaIter_oaModModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaIter_oaModModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModModuleInstHeader v1;
    PyParamoaIter_oaModModuleInstHeader v2;
    int convert_status1=PyoaIter_oaModModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInstHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModModuleInstHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModModuleInstHeader ob;
    int convert_status=PyoaIter_oaModModuleInstHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaModModuleInstHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModModuleInstHeader_FromoaModModuleInstHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModModuleInstHeader_Convert(PyObject* ob,PyParamoaIter_oaModModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModModuleInstHeader_Check(ob)) {
        result->SetData( (oaIter_oaModModuleInstHeader*) ((PyoaIter_oaModModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModModuleInstHeader_FromoaIter_oaModModuleInstHeader(oaIter_oaModModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModModuleInstHeader_Type.tp_alloc(&PyoaIter_oaModModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModModuleInstHeaderObject* self = (PyoaIter_oaModModuleInstHeaderObject*)bself;
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
static char oaIter_oaModModuleInstHeader_getNext_doc[] = 
"Class: oaIter_oaModModuleInstHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModModuleInstHeader* getNext()\n"
"    Signature: getNext|ptr-oaModModuleInstHeader|\n"
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
oaIter_oaModModuleInstHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModModuleInstHeader data;
    int convert_status=PyoaIter_oaModModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModModuleInstHeaderObject* self=(PyoaIter_oaModModuleInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModModuleInstHeaderp result= (data.DataCall()->getNext());
        return PyoaModModuleInstHeader_FromoaModModuleInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModModuleInstHeader_next_doc[] = 
"Class: oaIter_oaModModuleInstHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModModuleInstHeader* next()\n"
"    Signature: next|ptr-oaModModuleInstHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModModuleInstHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModModuleInstHeader data;
    int convert_status=PyoaIter_oaModModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModModuleInstHeaderObject* self=(PyoaIter_oaModModuleInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModModuleInstHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModModuleInstHeader_FromoaModModuleInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModModuleInstHeader_assign_doc[] = 
"Class: oaIter_oaModModuleInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModModuleInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModModuleInstHeader data;
  int convert_status=PyoaIter_oaModModuleInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModModuleInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModModuleInstHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModModuleInstHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModModuleInstHeader_getNext,METH_VARARGS,oaIter_oaModModuleInstHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModModuleInstHeader_next,METH_VARARGS,oaIter_oaModModuleInstHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaModModuleInstHeader_tp_assign,METH_VARARGS,oaIter_oaModModuleInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModModuleInstHeader_doc[] = 
"Class: oaIter_oaModModuleInstHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModModuleInstHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModModuleInstHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModModuleInstHeader)\n"
"    Calls: oaIter_oaModModuleInstHeader(const oaIter_oaModModuleInstHeader& iterIn)\n"
"    Signature: oaIter_oaModModuleInstHeader||cref-oaIter_oaModModuleInstHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModModuleInstHeader)\n"
"    Calls: (const oaIter_oaModModuleInstHeader&)\n"
"    Signature: oaIter_oaModModuleInstHeader||cref-oaIter_oaModModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModModuleInstHeader",
    sizeof(PyoaIter_oaModModuleInstHeaderObject),
    0,
    (destructor)oaIter_oaModModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModModuleInstHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaModModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModModuleInstHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModModuleInstHeader_iternext,	/* tp_iternext */
    oaIter_oaModModuleInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModModuleInstHeader",
           (PyObject*)(&PyoaIter_oaModModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModModuleInstHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModNetObject* self = (PyoaIter_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModNet)
    {
        PyParamoaIter_oaModNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModNet)\n"
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
oaIter_oaModNet_tp_dealloc(PyoaIter_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModNet value;
    int convert_status=PyoaIter_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModNet v1;
    PyParamoaIter_oaModNet v2;
    int convert_status1=PyoaIter_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModNet ob;
    int convert_status=PyoaIter_oaModNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaModNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModNet_FromoaModNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModNet_Convert(PyObject* ob,PyParamoaIter_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModNet_Check(ob)) {
        result->SetData( (oaIter_oaModNet*) ((PyoaIter_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModNet_FromoaIter_oaModNet(oaIter_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModNet_Type.tp_alloc(&PyoaIter_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModNetObject* self = (PyoaIter_oaModNetObject*)bself;
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
static char oaIter_oaModNet_getNext_doc[] = 
"Class: oaIter_oaModNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModNet* getNext()\n"
"    Signature: getNext|ptr-oaModNet|\n"
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
oaIter_oaModNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModNet data;
    int convert_status=PyoaIter_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModNetObject* self=(PyoaIter_oaModNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetp result= (data.DataCall()->getNext());
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
static char oaIter_oaModNet_next_doc[] = 
"Class: oaIter_oaModNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModNet* next()\n"
"    Signature: next|ptr-oaModNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModNet data;
    int convert_status=PyoaIter_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModNetObject* self=(PyoaIter_oaModNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModNet_FromoaModNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModNet_assign_doc[] = 
"Class: oaIter_oaModNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModNet data;
  int convert_status=PyoaIter_oaModNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModNet_getNext,METH_VARARGS,oaIter_oaModNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModNet_next,METH_VARARGS,oaIter_oaModNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaModNet_tp_assign,METH_VARARGS,oaIter_oaModNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModNet_doc[] = 
"Class: oaIter_oaModNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModNet)\n"
"    Calls: oaIter_oaModNet(const oaIter_oaModNet& iterIn)\n"
"    Signature: oaIter_oaModNet||cref-oaIter_oaModNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModNet)\n"
"    Calls: (const oaIter_oaModNet&)\n"
"    Signature: oaIter_oaModNet||cref-oaIter_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModNet",
    sizeof(PyoaIter_oaModNetObject),
    0,
    (destructor)oaIter_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModNet_tp_repr,	/* tp_repr */
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
    oaIter_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModNet_iternext,	/* tp_iternext */
    oaIter_oaModNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModNet",
           (PyObject*)(&PyoaIter_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModNet\n");
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
// Wrapper Implementation for Class: oaIter_oaModTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModTermObject* self = (PyoaIter_oaModTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModTerm)
    {
        PyParamoaIter_oaModTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModTerm)\n"
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
oaIter_oaModTerm_tp_dealloc(PyoaIter_oaModTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModTerm value;
    int convert_status=PyoaIter_oaModTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaModTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModTerm v1;
    PyParamoaIter_oaModTerm v2;
    int convert_status1=PyoaIter_oaModTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModTerm ob;
    int convert_status=PyoaIter_oaModTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaModTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModTerm_FromoaModTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModTerm_Convert(PyObject* ob,PyParamoaIter_oaModTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModTerm_Check(ob)) {
        result->SetData( (oaIter_oaModTerm*) ((PyoaIter_oaModTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModTerm_FromoaIter_oaModTerm(oaIter_oaModTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModTerm_Type.tp_alloc(&PyoaIter_oaModTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModTermObject* self = (PyoaIter_oaModTermObject*)bself;
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
static char oaIter_oaModTerm_getNext_doc[] = 
"Class: oaIter_oaModTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModTerm* getNext()\n"
"    Signature: getNext|ptr-oaModTerm|\n"
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
oaIter_oaModTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModTerm data;
    int convert_status=PyoaIter_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModTermObject* self=(PyoaIter_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModTermp result= (data.DataCall()->getNext());
        return PyoaModTerm_FromoaModTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModTerm_next_doc[] = 
"Class: oaIter_oaModTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModTerm* next()\n"
"    Signature: next|ptr-oaModTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModTerm data;
    int convert_status=PyoaIter_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModTermObject* self=(PyoaIter_oaModTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModTerm_FromoaModTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModTerm_assign_doc[] = 
"Class: oaIter_oaModTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModTerm data;
  int convert_status=PyoaIter_oaModTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModTerm_getNext,METH_VARARGS,oaIter_oaModTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModTerm_next,METH_VARARGS,oaIter_oaModTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaModTerm_tp_assign,METH_VARARGS,oaIter_oaModTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModTerm_doc[] = 
"Class: oaIter_oaModTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModTerm)\n"
"    Calls: oaIter_oaModTerm(const oaIter_oaModTerm& iterIn)\n"
"    Signature: oaIter_oaModTerm||cref-oaIter_oaModTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModTerm)\n"
"    Calls: (const oaIter_oaModTerm&)\n"
"    Signature: oaIter_oaModTerm||cref-oaIter_oaModTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModTerm",
    sizeof(PyoaIter_oaModTermObject),
    0,
    (destructor)oaIter_oaModTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaModTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModTerm_iternext,	/* tp_iternext */
    oaIter_oaModTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModTerm",
           (PyObject*)(&PyoaIter_oaModTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaModVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModVectorInstDefObject* self = (PyoaIter_oaModVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModVectorInstDef)
    {
        PyParamoaIter_oaModVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModVectorInstDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModVectorInstDef)\n"
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
oaIter_oaModVectorInstDef_tp_dealloc(PyoaIter_oaModVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModVectorInstDef value;
    int convert_status=PyoaIter_oaModVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaIter_oaModVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModVectorInstDef v1;
    PyParamoaIter_oaModVectorInstDef v2;
    int convert_status1=PyoaIter_oaModVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModVectorInstDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModVectorInstDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModVectorInstDef ob;
    int convert_status=PyoaIter_oaModVectorInstDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaModVectorInstDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModVectorInstDef_FromoaModVectorInstDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModVectorInstDef_Convert(PyObject* ob,PyParamoaIter_oaModVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModVectorInstDef_Check(ob)) {
        result->SetData( (oaIter_oaModVectorInstDef*) ((PyoaIter_oaModVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModVectorInstDef_FromoaIter_oaModVectorInstDef(oaIter_oaModVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModVectorInstDef_Type.tp_alloc(&PyoaIter_oaModVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModVectorInstDefObject* self = (PyoaIter_oaModVectorInstDefObject*)bself;
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
static char oaIter_oaModVectorInstDef_getNext_doc[] = 
"Class: oaIter_oaModVectorInstDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModVectorInstDef* getNext()\n"
"    Signature: getNext|ptr-oaModVectorInstDef|\n"
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
oaIter_oaModVectorInstDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModVectorInstDef data;
    int convert_status=PyoaIter_oaModVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModVectorInstDefObject* self=(PyoaIter_oaModVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModVectorInstDefp result= (data.DataCall()->getNext());
        return PyoaModVectorInstDef_FromoaModVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModVectorInstDef_next_doc[] = 
"Class: oaIter_oaModVectorInstDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModVectorInstDef* next()\n"
"    Signature: next|ptr-oaModVectorInstDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModVectorInstDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModVectorInstDef data;
    int convert_status=PyoaIter_oaModVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModVectorInstDefObject* self=(PyoaIter_oaModVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModVectorInstDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModVectorInstDef_FromoaModVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModVectorInstDef_assign_doc[] = 
"Class: oaIter_oaModVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModVectorInstDef data;
  int convert_status=PyoaIter_oaModVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModVectorInstDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModVectorInstDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModVectorInstDef_getNext,METH_VARARGS,oaIter_oaModVectorInstDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModVectorInstDef_next,METH_VARARGS,oaIter_oaModVectorInstDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaModVectorInstDef_tp_assign,METH_VARARGS,oaIter_oaModVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModVectorInstDef_doc[] = 
"Class: oaIter_oaModVectorInstDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModVectorInstDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModVectorInstDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModVectorInstDef)\n"
"    Calls: oaIter_oaModVectorInstDef(const oaIter_oaModVectorInstDef& iterIn)\n"
"    Signature: oaIter_oaModVectorInstDef||cref-oaIter_oaModVectorInstDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModVectorInstDef)\n"
"    Calls: (const oaIter_oaModVectorInstDef&)\n"
"    Signature: oaIter_oaModVectorInstDef||cref-oaIter_oaModVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModVectorInstDef",
    sizeof(PyoaIter_oaModVectorInstDefObject),
    0,
    (destructor)oaIter_oaModVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModVectorInstDef_tp_repr,	/* tp_repr */
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
    oaIter_oaModVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModVectorInstDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModVectorInstDef_iternext,	/* tp_iternext */
    oaIter_oaModVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModVectorInstDef",
           (PyObject*)(&PyoaIter_oaModVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModVectorInstDef\n");
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
// Wrapper Implementation for Class: oaIter_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaModuleObject* self = (PyoaIter_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaModule)
    {
        PyParamoaIter_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaModule_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaModule, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaModule)\n"
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
oaIter_oaModule_tp_dealloc(PyoaIter_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaModule value;
    int convert_status=PyoaIter_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaModule v1;
    PyParamoaIter_oaModule v2;
    int convert_status1=PyoaIter_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaModule_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaModule_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaModule ob;
    int convert_status=PyoaIter_oaModule_Convert(self,&ob);
    assert(convert_status!=0);
    oaModule* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaModule_FromoaModule(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaModule_Convert(PyObject* ob,PyParamoaIter_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaModule_Check(ob)) {
        result->SetData( (oaIter_oaModule*) ((PyoaIter_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaModule_FromoaIter_oaModule(oaIter_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaModule_Type.tp_alloc(&PyoaIter_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaModuleObject* self = (PyoaIter_oaModuleObject*)bself;
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
static char oaIter_oaModule_getNext_doc[] = 
"Class: oaIter_oaModule, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaModule* getNext()\n"
"    Signature: getNext|ptr-oaModule|\n"
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
oaIter_oaModule_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModule data;
    int convert_status=PyoaIter_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModuleObject* self=(PyoaIter_oaModuleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModulep result= (data.DataCall()->getNext());
        return PyoaModule_FromoaModule(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaModule_next_doc[] = 
"Class: oaIter_oaModule, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaModule* next()\n"
"    Signature: next|ptr-oaModule|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaModule_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaModule data;
    int convert_status=PyoaIter_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaModuleObject* self=(PyoaIter_oaModuleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaModulep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaModule_FromoaModule(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaModule_assign_doc[] = 
"Class: oaIter_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaModule data;
  int convert_status=PyoaIter_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaModule_Convert,&p1)) {
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

static PyMethodDef oaIter_oaModule_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaModule_getNext,METH_VARARGS,oaIter_oaModule_getNext_doc},
    {"next",(PyCFunction)oaIter_oaModule_next,METH_VARARGS,oaIter_oaModule_next_doc},
    {"assign",(PyCFunction)oaIter_oaModule_tp_assign,METH_VARARGS,oaIter_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaModule_doc[] = 
"Class: oaIter_oaModule\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaModule(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaModule||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaModule)\n"
"    Calls: oaIter_oaModule(const oaIter_oaModule& iterIn)\n"
"    Signature: oaIter_oaModule||cref-oaIter_oaModule,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaModule)\n"
"    Calls: (const oaIter_oaModule&)\n"
"    Signature: oaIter_oaModule||cref-oaIter_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaModule",
    sizeof(PyoaIter_oaModuleObject),
    0,
    (destructor)oaIter_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaModule_tp_repr,	/* tp_repr */
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
    oaIter_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaModule_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaModule_iternext,	/* tp_iternext */
    oaIter_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaModule",
           (PyObject*)(&PyoaIter_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaModule\n");
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
// Wrapper Implementation for Class: oaIter_oaMutualInductor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMutualInductor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaMutualInductor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaMutualInductorObject* self = (PyoaIter_oaMutualInductorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaMutualInductor(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaMutualInductor)
    {
        PyParamoaIter_oaMutualInductor p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaMutualInductor_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaMutualInductor(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaMutualInductor, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaMutualInductor)\n"
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
oaIter_oaMutualInductor_tp_dealloc(PyoaIter_oaMutualInductorObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaMutualInductor*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMutualInductor_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaMutualInductor value;
    int convert_status=PyoaIter_oaMutualInductor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaIter_oaMutualInductor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaMutualInductor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaMutualInductor v1;
    PyParamoaIter_oaMutualInductor v2;
    int convert_status1=PyoaIter_oaMutualInductor_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaMutualInductor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaMutualInductor_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaMutualInductor_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaMutualInductor ob;
    int convert_status=PyoaIter_oaMutualInductor_Convert(self,&ob);
    assert(convert_status!=0);
    oaMutualInductor* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaMutualInductor_FromoaMutualInductor(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaMutualInductor_Convert(PyObject* ob,PyParamoaIter_oaMutualInductor* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaMutualInductor_Check(ob)) {
        result->SetData( (oaIter_oaMutualInductor*) ((PyoaIter_oaMutualInductorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaMutualInductor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaMutualInductor_FromoaIter_oaMutualInductor(oaIter_oaMutualInductor* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaMutualInductor_Type.tp_alloc(&PyoaIter_oaMutualInductor_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaMutualInductorObject* self = (PyoaIter_oaMutualInductorObject*)bself;
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
static char oaIter_oaMutualInductor_getNext_doc[] = 
"Class: oaIter_oaMutualInductor, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaMutualInductor* getNext()\n"
"    Signature: getNext|ptr-oaMutualInductor|\n"
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
oaIter_oaMutualInductor_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaMutualInductor data;
    int convert_status=PyoaIter_oaMutualInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaMutualInductorObject* self=(PyoaIter_oaMutualInductorObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMutualInductorp result= (data.DataCall()->getNext());
        return PyoaMutualInductor_FromoaMutualInductor(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaMutualInductor_next_doc[] = 
"Class: oaIter_oaMutualInductor, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaMutualInductor* next()\n"
"    Signature: next|ptr-oaMutualInductor|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaMutualInductor_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaMutualInductor data;
    int convert_status=PyoaIter_oaMutualInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaMutualInductorObject* self=(PyoaIter_oaMutualInductorObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMutualInductorp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaMutualInductor_FromoaMutualInductor(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaMutualInductor_assign_doc[] = 
"Class: oaIter_oaMutualInductor, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaMutualInductor_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaMutualInductor data;
  int convert_status=PyoaIter_oaMutualInductor_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaMutualInductor p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaMutualInductor_Convert,&p1)) {
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

static PyMethodDef oaIter_oaMutualInductor_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaMutualInductor_getNext,METH_VARARGS,oaIter_oaMutualInductor_getNext_doc},
    {"next",(PyCFunction)oaIter_oaMutualInductor_next,METH_VARARGS,oaIter_oaMutualInductor_next_doc},
    {"assign",(PyCFunction)oaIter_oaMutualInductor_tp_assign,METH_VARARGS,oaIter_oaMutualInductor_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaMutualInductor_doc[] = 
"Class: oaIter_oaMutualInductor\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaMutualInductor(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaMutualInductor||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaMutualInductor)\n"
"    Calls: oaIter_oaMutualInductor(const oaIter_oaMutualInductor& iterIn)\n"
"    Signature: oaIter_oaMutualInductor||cref-oaIter_oaMutualInductor,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaMutualInductor)\n"
"    Calls: (const oaIter_oaMutualInductor&)\n"
"    Signature: oaIter_oaMutualInductor||cref-oaIter_oaMutualInductor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaMutualInductor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaMutualInductor",
    sizeof(PyoaIter_oaMutualInductorObject),
    0,
    (destructor)oaIter_oaMutualInductor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaMutualInductor_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaMutualInductor_tp_repr,	/* tp_repr */
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
    oaIter_oaMutualInductor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaMutualInductor_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaMutualInductor_iternext,	/* tp_iternext */
    oaIter_oaMutualInductor_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaMutualInductor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaMutualInductor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaMutualInductor_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaMutualInductor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaMutualInductor",
           (PyObject*)(&PyoaIter_oaMutualInductor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaMutualInductor\n");
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
// Wrapper Implementation for Class: oaIter_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaNetObject* self = (PyoaIter_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaNet)
    {
        PyParamoaIter_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaNet)\n"
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
oaIter_oaNet_tp_dealloc(PyoaIter_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaNet value;
    int convert_status=PyoaIter_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaIter_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaNet v1;
    PyParamoaIter_oaNet v2;
    int convert_status1=PyoaIter_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaNet ob;
    int convert_status=PyoaIter_oaNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaNet_FromoaNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaNet_Convert(PyObject* ob,PyParamoaIter_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaNet_Check(ob)) {
        result->SetData( (oaIter_oaNet*) ((PyoaIter_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaNet_FromoaIter_oaNet(oaIter_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaNet_Type.tp_alloc(&PyoaIter_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaNetObject* self = (PyoaIter_oaNetObject*)bself;
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
static char oaIter_oaNet_getNext_doc[] = 
"Class: oaIter_oaNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaNet* getNext()\n"
"    Signature: getNext|ptr-oaNet|\n"
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
oaIter_oaNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaNet data;
    int convert_status=PyoaIter_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaNetObject* self=(PyoaIter_oaNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result= (data.DataCall()->getNext());
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
static char oaIter_oaNet_next_doc[] = 
"Class: oaIter_oaNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaNet* next()\n"
"    Signature: next|ptr-oaNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaNet data;
    int convert_status=PyoaIter_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaNetObject* self=(PyoaIter_oaNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaNet_FromoaNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaNet_assign_doc[] = 
"Class: oaIter_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaNet data;
  int convert_status=PyoaIter_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaNet_getNext,METH_VARARGS,oaIter_oaNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaNet_next,METH_VARARGS,oaIter_oaNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaNet_tp_assign,METH_VARARGS,oaIter_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaNet_doc[] = 
"Class: oaIter_oaNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaNet)\n"
"    Calls: oaIter_oaNet(const oaIter_oaNet& iterIn)\n"
"    Signature: oaIter_oaNet||cref-oaIter_oaNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaNet)\n"
"    Calls: (const oaIter_oaNet&)\n"
"    Signature: oaIter_oaNet||cref-oaIter_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaNet",
    sizeof(PyoaIter_oaNetObject),
    0,
    (destructor)oaIter_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaNet_tp_repr,	/* tp_repr */
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
    oaIter_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaNet_iternext,	/* tp_iternext */
    oaIter_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaNet",
           (PyObject*)(&PyoaIter_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaNet\n");
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
// Wrapper Implementation for Class: oaIter_oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaNodeObject* self = (PyoaIter_oaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaNode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaNode)
    {
        PyParamoaIter_oaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaNode_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaNode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaNode, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaNode)\n"
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
oaIter_oaNode_tp_dealloc(PyoaIter_oaNodeObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaNode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNode_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaNode value;
    int convert_status=PyoaIter_oaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaNode v1;
    PyParamoaIter_oaNode v2;
    int convert_status1=PyoaIter_oaNode_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaNode_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaNode_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaNode ob;
    int convert_status=PyoaIter_oaNode_Convert(self,&ob);
    assert(convert_status!=0);
    oaNode* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaNode_FromoaNode(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaNode_Convert(PyObject* ob,PyParamoaIter_oaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaNode_Check(ob)) {
        result->SetData( (oaIter_oaNode*) ((PyoaIter_oaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaNode_FromoaIter_oaNode(oaIter_oaNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaNode_Type.tp_alloc(&PyoaIter_oaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaNodeObject* self = (PyoaIter_oaNodeObject*)bself;
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
static char oaIter_oaNode_getNext_doc[] = 
"Class: oaIter_oaNode, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaNode* getNext()\n"
"    Signature: getNext|ptr-oaNode|\n"
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
oaIter_oaNode_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaNode data;
    int convert_status=PyoaIter_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaNodeObject* self=(PyoaIter_oaNodeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNodep result= (data.DataCall()->getNext());
        return PyoaNode_FromoaNode(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaNode_next_doc[] = 
"Class: oaIter_oaNode, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaNode* next()\n"
"    Signature: next|ptr-oaNode|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaNode_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaNode data;
    int convert_status=PyoaIter_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaNodeObject* self=(PyoaIter_oaNodeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaNodep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaNode_FromoaNode(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaNode_assign_doc[] = 
"Class: oaIter_oaNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaNode data;
  int convert_status=PyoaIter_oaNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaNode_Convert,&p1)) {
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

static PyMethodDef oaIter_oaNode_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaNode_getNext,METH_VARARGS,oaIter_oaNode_getNext_doc},
    {"next",(PyCFunction)oaIter_oaNode_next,METH_VARARGS,oaIter_oaNode_next_doc},
    {"assign",(PyCFunction)oaIter_oaNode_tp_assign,METH_VARARGS,oaIter_oaNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaNode_doc[] = 
"Class: oaIter_oaNode\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaNode(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaNode||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaNode)\n"
"    Calls: oaIter_oaNode(const oaIter_oaNode& iterIn)\n"
"    Signature: oaIter_oaNode||cref-oaIter_oaNode,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaNode)\n"
"    Calls: (const oaIter_oaNode&)\n"
"    Signature: oaIter_oaNode||cref-oaIter_oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaNode",
    sizeof(PyoaIter_oaNodeObject),
    0,
    (destructor)oaIter_oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaNode_tp_repr,	/* tp_repr */
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
    oaIter_oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaNode_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaNode_iternext,	/* tp_iternext */
    oaIter_oaNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaNode",
           (PyObject*)(&PyoaIter_oaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaNode\n");
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
// Wrapper Implementation for Class: oaIter_oaOccAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccAssignmentObject* self = (PyoaIter_oaOccAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccAssignment(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccAssignment)
    {
        PyParamoaIter_oaOccAssignment p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccAssignment_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccAssignment(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccAssignment, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccAssignment)\n"
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
oaIter_oaOccAssignment_tp_dealloc(PyoaIter_oaOccAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccAssignment_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccAssignment value;
    int convert_status=PyoaIter_oaOccAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccAssignment v1;
    PyParamoaIter_oaOccAssignment v2;
    int convert_status1=PyoaIter_oaOccAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccAssignment_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccAssignment_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccAssignment ob;
    int convert_status=PyoaIter_oaOccAssignment_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccAssignment* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccAssignment_FromoaOccAssignment(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccAssignment_Convert(PyObject* ob,PyParamoaIter_oaOccAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccAssignment_Check(ob)) {
        result->SetData( (oaIter_oaOccAssignment*) ((PyoaIter_oaOccAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccAssignment_FromoaIter_oaOccAssignment(oaIter_oaOccAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccAssignment_Type.tp_alloc(&PyoaIter_oaOccAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccAssignmentObject* self = (PyoaIter_oaOccAssignmentObject*)bself;
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
static char oaIter_oaOccAssignment_getNext_doc[] = 
"Class: oaIter_oaOccAssignment, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccAssignment* getNext()\n"
"    Signature: getNext|ptr-oaOccAssignment|\n"
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
oaIter_oaOccAssignment_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccAssignment data;
    int convert_status=PyoaIter_oaOccAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccAssignmentObject* self=(PyoaIter_oaOccAssignmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccAssignmentp result= (data.DataCall()->getNext());
        return PyoaOccAssignment_FromoaOccAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccAssignment_next_doc[] = 
"Class: oaIter_oaOccAssignment, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccAssignment* next()\n"
"    Signature: next|ptr-oaOccAssignment|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccAssignment_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccAssignment data;
    int convert_status=PyoaIter_oaOccAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccAssignmentObject* self=(PyoaIter_oaOccAssignmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccAssignmentp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccAssignment_FromoaOccAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccAssignment_assign_doc[] = 
"Class: oaIter_oaOccAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccAssignment data;
  int convert_status=PyoaIter_oaOccAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccAssignment_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccAssignment_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccAssignment_getNext,METH_VARARGS,oaIter_oaOccAssignment_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccAssignment_next,METH_VARARGS,oaIter_oaOccAssignment_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccAssignment_tp_assign,METH_VARARGS,oaIter_oaOccAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccAssignment_doc[] = 
"Class: oaIter_oaOccAssignment\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccAssignment(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccAssignment||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccAssignment)\n"
"    Calls: oaIter_oaOccAssignment(const oaIter_oaOccAssignment& iterIn)\n"
"    Signature: oaIter_oaOccAssignment||cref-oaIter_oaOccAssignment,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccAssignment)\n"
"    Calls: (const oaIter_oaOccAssignment&)\n"
"    Signature: oaIter_oaOccAssignment||cref-oaIter_oaOccAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccAssignment",
    sizeof(PyoaIter_oaOccAssignmentObject),
    0,
    (destructor)oaIter_oaOccAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccAssignment_tp_repr,	/* tp_repr */
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
    oaIter_oaOccAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccAssignment_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccAssignment_iternext,	/* tp_iternext */
    oaIter_oaOccAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccAssignment",
           (PyObject*)(&PyoaIter_oaOccAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccAssignment\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBitNetObject* self = (PyoaIter_oaOccBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBitNet)
    {
        PyParamoaIter_oaOccBitNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBitNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBitNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBitNet)\n"
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
oaIter_oaOccBitNet_tp_dealloc(PyoaIter_oaOccBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBitNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBitNet value;
    int convert_status=PyoaIter_oaOccBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaOccBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBitNet v1;
    PyParamoaIter_oaOccBitNet v2;
    int convert_status1=PyoaIter_oaOccBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBitNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBitNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBitNet ob;
    int convert_status=PyoaIter_oaOccBitNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBitNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBitNet_FromoaOccBitNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBitNet_Convert(PyObject* ob,PyParamoaIter_oaOccBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBitNet_Check(ob)) {
        result->SetData( (oaIter_oaOccBitNet*) ((PyoaIter_oaOccBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBitNet_FromoaIter_oaOccBitNet(oaIter_oaOccBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBitNet_Type.tp_alloc(&PyoaIter_oaOccBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBitNetObject* self = (PyoaIter_oaOccBitNetObject*)bself;
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
static char oaIter_oaOccBitNet_getNext_doc[] = 
"Class: oaIter_oaOccBitNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBitNet* getNext()\n"
"    Signature: getNext|ptr-oaOccBitNet|\n"
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
oaIter_oaOccBitNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBitNet data;
    int convert_status=PyoaIter_oaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBitNetObject* self=(PyoaIter_oaOccBitNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBitNetp result= (data.DataCall()->getNext());
        return PyoaOccBitNet_FromoaOccBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBitNet_next_doc[] = 
"Class: oaIter_oaOccBitNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBitNet* next()\n"
"    Signature: next|ptr-oaOccBitNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBitNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBitNet data;
    int convert_status=PyoaIter_oaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBitNetObject* self=(PyoaIter_oaOccBitNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBitNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBitNet_FromoaOccBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBitNet_assign_doc[] = 
"Class: oaIter_oaOccBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBitNet data;
  int convert_status=PyoaIter_oaOccBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBitNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBitNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBitNet_getNext,METH_VARARGS,oaIter_oaOccBitNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBitNet_next,METH_VARARGS,oaIter_oaOccBitNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBitNet_tp_assign,METH_VARARGS,oaIter_oaOccBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBitNet_doc[] = 
"Class: oaIter_oaOccBitNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBitNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBitNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBitNet)\n"
"    Calls: oaIter_oaOccBitNet(const oaIter_oaOccBitNet& iterIn)\n"
"    Signature: oaIter_oaOccBitNet||cref-oaIter_oaOccBitNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBitNet)\n"
"    Calls: (const oaIter_oaOccBitNet&)\n"
"    Signature: oaIter_oaOccBitNet||cref-oaIter_oaOccBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBitNet",
    sizeof(PyoaIter_oaOccBitNetObject),
    0,
    (destructor)oaIter_oaOccBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBitNet_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBitNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBitNet_iternext,	/* tp_iternext */
    oaIter_oaOccBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBitNet",
           (PyObject*)(&PyoaIter_oaOccBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBitNet\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusNetObject* self = (PyoaIter_oaOccBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusNet)
    {
        PyParamoaIter_oaOccBusNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusNet)\n"
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
oaIter_oaOccBusNet_tp_dealloc(PyoaIter_oaOccBusNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusNet value;
    int convert_status=PyoaIter_oaOccBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaOccBusNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusNet v1;
    PyParamoaIter_oaOccBusNet v2;
    int convert_status1=PyoaIter_oaOccBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusNet ob;
    int convert_status=PyoaIter_oaOccBusNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusNet_FromoaOccBusNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusNet_Convert(PyObject* ob,PyParamoaIter_oaOccBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusNet_Check(ob)) {
        result->SetData( (oaIter_oaOccBusNet*) ((PyoaIter_oaOccBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusNet_FromoaIter_oaOccBusNet(oaIter_oaOccBusNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusNet_Type.tp_alloc(&PyoaIter_oaOccBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusNetObject* self = (PyoaIter_oaOccBusNetObject*)bself;
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
static char oaIter_oaOccBusNet_getNext_doc[] = 
"Class: oaIter_oaOccBusNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNet* getNext()\n"
"    Signature: getNext|ptr-oaOccBusNet|\n"
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
oaIter_oaOccBusNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNet data;
    int convert_status=PyoaIter_oaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetObject* self=(PyoaIter_oaOccBusNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetp result= (data.DataCall()->getNext());
        return PyoaOccBusNet_FromoaOccBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusNet_next_doc[] = 
"Class: oaIter_oaOccBusNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNet* next()\n"
"    Signature: next|ptr-oaOccBusNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNet data;
    int convert_status=PyoaIter_oaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetObject* self=(PyoaIter_oaOccBusNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusNet_FromoaOccBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusNet_assign_doc[] = 
"Class: oaIter_oaOccBusNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusNet data;
  int convert_status=PyoaIter_oaOccBusNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusNet_getNext,METH_VARARGS,oaIter_oaOccBusNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusNet_next,METH_VARARGS,oaIter_oaOccBusNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusNet_tp_assign,METH_VARARGS,oaIter_oaOccBusNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusNet_doc[] = 
"Class: oaIter_oaOccBusNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusNet)\n"
"    Calls: oaIter_oaOccBusNet(const oaIter_oaOccBusNet& iterIn)\n"
"    Signature: oaIter_oaOccBusNet||cref-oaIter_oaOccBusNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusNet)\n"
"    Calls: (const oaIter_oaOccBusNet&)\n"
"    Signature: oaIter_oaOccBusNet||cref-oaIter_oaOccBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusNet",
    sizeof(PyoaIter_oaOccBusNetObject),
    0,
    (destructor)oaIter_oaOccBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusNet_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusNet_iternext,	/* tp_iternext */
    oaIter_oaOccBusNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusNet",
           (PyObject*)(&PyoaIter_oaOccBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusNet\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusNetBitObject* self = (PyoaIter_oaOccBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNetBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusNetBit)
    {
        PyParamoaIter_oaOccBusNetBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusNetBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNetBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusNetBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusNetBit)\n"
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
oaIter_oaOccBusNetBit_tp_dealloc(PyoaIter_oaOccBusNetBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusNetBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusNetBit value;
    int convert_status=PyoaIter_oaOccBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaOccBusNetBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusNetBit v1;
    PyParamoaIter_oaOccBusNetBit v2;
    int convert_status1=PyoaIter_oaOccBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusNetBit ob;
    int convert_status=PyoaIter_oaOccBusNetBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusNetBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusNetBit_FromoaOccBusNetBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusNetBit_Convert(PyObject* ob,PyParamoaIter_oaOccBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusNetBit_Check(ob)) {
        result->SetData( (oaIter_oaOccBusNetBit*) ((PyoaIter_oaOccBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusNetBit_FromoaIter_oaOccBusNetBit(oaIter_oaOccBusNetBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusNetBit_Type.tp_alloc(&PyoaIter_oaOccBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusNetBitObject* self = (PyoaIter_oaOccBusNetBitObject*)bself;
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
static char oaIter_oaOccBusNetBit_getNext_doc[] = 
"Class: oaIter_oaOccBusNetBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetBit* getNext()\n"
"    Signature: getNext|ptr-oaOccBusNetBit|\n"
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
oaIter_oaOccBusNetBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNetBit data;
    int convert_status=PyoaIter_oaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetBitObject* self=(PyoaIter_oaOccBusNetBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetBitp result= (data.DataCall()->getNext());
        return PyoaOccBusNetBit_FromoaOccBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusNetBit_next_doc[] = 
"Class: oaIter_oaOccBusNetBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetBit* next()\n"
"    Signature: next|ptr-oaOccBusNetBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusNetBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNetBit data;
    int convert_status=PyoaIter_oaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetBitObject* self=(PyoaIter_oaOccBusNetBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusNetBit_FromoaOccBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusNetBit_assign_doc[] = 
"Class: oaIter_oaOccBusNetBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusNetBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusNetBit data;
  int convert_status=PyoaIter_oaOccBusNetBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusNetBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusNetBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusNetBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusNetBit_getNext,METH_VARARGS,oaIter_oaOccBusNetBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusNetBit_next,METH_VARARGS,oaIter_oaOccBusNetBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusNetBit_tp_assign,METH_VARARGS,oaIter_oaOccBusNetBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusNetBit_doc[] = 
"Class: oaIter_oaOccBusNetBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusNetBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusNetBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusNetBit)\n"
"    Calls: oaIter_oaOccBusNetBit(const oaIter_oaOccBusNetBit& iterIn)\n"
"    Signature: oaIter_oaOccBusNetBit||cref-oaIter_oaOccBusNetBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusNetBit)\n"
"    Calls: (const oaIter_oaOccBusNetBit&)\n"
"    Signature: oaIter_oaOccBusNetBit||cref-oaIter_oaOccBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusNetBit",
    sizeof(PyoaIter_oaOccBusNetBitObject),
    0,
    (destructor)oaIter_oaOccBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusNetBit_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusNetBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusNetBit_iternext,	/* tp_iternext */
    oaIter_oaOccBusNetBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusNetBit",
           (PyObject*)(&PyoaIter_oaOccBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusNetBit\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusNetDefObject* self = (PyoaIter_oaOccBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusNetDef)
    {
        PyParamoaIter_oaOccBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusNetDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusNetDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusNetDef)\n"
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
oaIter_oaOccBusNetDef_tp_dealloc(PyoaIter_oaOccBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusNetDef value;
    int convert_status=PyoaIter_oaOccBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaIter_oaOccBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusNetDef v1;
    PyParamoaIter_oaOccBusNetDef v2;
    int convert_status1=PyoaIter_oaOccBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusNetDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusNetDef ob;
    int convert_status=PyoaIter_oaOccBusNetDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusNetDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusNetDef_Convert(PyObject* ob,PyParamoaIter_oaOccBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusNetDef_Check(ob)) {
        result->SetData( (oaIter_oaOccBusNetDef*) ((PyoaIter_oaOccBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusNetDef_FromoaIter_oaOccBusNetDef(oaIter_oaOccBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusNetDef_Type.tp_alloc(&PyoaIter_oaOccBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusNetDefObject* self = (PyoaIter_oaOccBusNetDefObject*)bself;
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
static char oaIter_oaOccBusNetDef_getNext_doc[] = 
"Class: oaIter_oaOccBusNetDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetDef* getNext()\n"
"    Signature: getNext|ptr-oaOccBusNetDef|\n"
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
oaIter_oaOccBusNetDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNetDef data;
    int convert_status=PyoaIter_oaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetDefObject* self=(PyoaIter_oaOccBusNetDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetDefp result= (data.DataCall()->getNext());
        return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusNetDef_next_doc[] = 
"Class: oaIter_oaOccBusNetDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetDef* next()\n"
"    Signature: next|ptr-oaOccBusNetDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusNetDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusNetDef data;
    int convert_status=PyoaIter_oaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusNetDefObject* self=(PyoaIter_oaOccBusNetDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusNetDef_assign_doc[] = 
"Class: oaIter_oaOccBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusNetDef data;
  int convert_status=PyoaIter_oaOccBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusNetDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusNetDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusNetDef_getNext,METH_VARARGS,oaIter_oaOccBusNetDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusNetDef_next,METH_VARARGS,oaIter_oaOccBusNetDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusNetDef_tp_assign,METH_VARARGS,oaIter_oaOccBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusNetDef_doc[] = 
"Class: oaIter_oaOccBusNetDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusNetDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusNetDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusNetDef)\n"
"    Calls: oaIter_oaOccBusNetDef(const oaIter_oaOccBusNetDef& iterIn)\n"
"    Signature: oaIter_oaOccBusNetDef||cref-oaIter_oaOccBusNetDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusNetDef)\n"
"    Calls: (const oaIter_oaOccBusNetDef&)\n"
"    Signature: oaIter_oaOccBusNetDef||cref-oaIter_oaOccBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusNetDef",
    sizeof(PyoaIter_oaOccBusNetDefObject),
    0,
    (destructor)oaIter_oaOccBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusNetDef_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusNetDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusNetDef_iternext,	/* tp_iternext */
    oaIter_oaOccBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusNetDef",
           (PyObject*)(&PyoaIter_oaOccBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusNetDef\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusTermObject* self = (PyoaIter_oaOccBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusTerm)
    {
        PyParamoaIter_oaOccBusTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusTerm)\n"
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
oaIter_oaOccBusTerm_tp_dealloc(PyoaIter_oaOccBusTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusTerm value;
    int convert_status=PyoaIter_oaOccBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaOccBusTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusTerm v1;
    PyParamoaIter_oaOccBusTerm v2;
    int convert_status1=PyoaIter_oaOccBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusTerm ob;
    int convert_status=PyoaIter_oaOccBusTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusTerm_FromoaOccBusTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusTerm_Convert(PyObject* ob,PyParamoaIter_oaOccBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusTerm_Check(ob)) {
        result->SetData( (oaIter_oaOccBusTerm*) ((PyoaIter_oaOccBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusTerm_FromoaIter_oaOccBusTerm(oaIter_oaOccBusTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusTerm_Type.tp_alloc(&PyoaIter_oaOccBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusTermObject* self = (PyoaIter_oaOccBusTermObject*)bself;
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
static char oaIter_oaOccBusTerm_getNext_doc[] = 
"Class: oaIter_oaOccBusTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTerm* getNext()\n"
"    Signature: getNext|ptr-oaOccBusTerm|\n"
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
oaIter_oaOccBusTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTerm data;
    int convert_status=PyoaIter_oaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermObject* self=(PyoaIter_oaOccBusTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermp result= (data.DataCall()->getNext());
        return PyoaOccBusTerm_FromoaOccBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusTerm_next_doc[] = 
"Class: oaIter_oaOccBusTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTerm* next()\n"
"    Signature: next|ptr-oaOccBusTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTerm data;
    int convert_status=PyoaIter_oaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermObject* self=(PyoaIter_oaOccBusTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusTerm_FromoaOccBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusTerm_assign_doc[] = 
"Class: oaIter_oaOccBusTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusTerm data;
  int convert_status=PyoaIter_oaOccBusTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusTerm_getNext,METH_VARARGS,oaIter_oaOccBusTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusTerm_next,METH_VARARGS,oaIter_oaOccBusTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusTerm_tp_assign,METH_VARARGS,oaIter_oaOccBusTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusTerm_doc[] = 
"Class: oaIter_oaOccBusTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusTerm)\n"
"    Calls: oaIter_oaOccBusTerm(const oaIter_oaOccBusTerm& iterIn)\n"
"    Signature: oaIter_oaOccBusTerm||cref-oaIter_oaOccBusTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusTerm)\n"
"    Calls: (const oaIter_oaOccBusTerm&)\n"
"    Signature: oaIter_oaOccBusTerm||cref-oaIter_oaOccBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusTerm",
    sizeof(PyoaIter_oaOccBusTermObject),
    0,
    (destructor)oaIter_oaOccBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusTerm_iternext,	/* tp_iternext */
    oaIter_oaOccBusTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusTerm",
           (PyObject*)(&PyoaIter_oaOccBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusTermBitObject* self = (PyoaIter_oaOccBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusTermBit)
    {
        PyParamoaIter_oaOccBusTermBit p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusTermBit_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTermBit(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusTermBit, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusTermBit)\n"
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
oaIter_oaOccBusTermBit_tp_dealloc(PyoaIter_oaOccBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusTermBit value;
    int convert_status=PyoaIter_oaOccBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusTermBit v1;
    PyParamoaIter_oaOccBusTermBit v2;
    int convert_status1=PyoaIter_oaOccBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermBit_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermBit_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusTermBit ob;
    int convert_status=PyoaIter_oaOccBusTermBit_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusTermBit* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusTermBit_FromoaOccBusTermBit(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusTermBit_Convert(PyObject* ob,PyParamoaIter_oaOccBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusTermBit_Check(ob)) {
        result->SetData( (oaIter_oaOccBusTermBit*) ((PyoaIter_oaOccBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusTermBit_FromoaIter_oaOccBusTermBit(oaIter_oaOccBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusTermBit_Type.tp_alloc(&PyoaIter_oaOccBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusTermBitObject* self = (PyoaIter_oaOccBusTermBitObject*)bself;
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
static char oaIter_oaOccBusTermBit_getNext_doc[] = 
"Class: oaIter_oaOccBusTermBit, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermBit* getNext()\n"
"    Signature: getNext|ptr-oaOccBusTermBit|\n"
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
oaIter_oaOccBusTermBit_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTermBit data;
    int convert_status=PyoaIter_oaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermBitObject* self=(PyoaIter_oaOccBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermBitp result= (data.DataCall()->getNext());
        return PyoaOccBusTermBit_FromoaOccBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusTermBit_next_doc[] = 
"Class: oaIter_oaOccBusTermBit, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermBit* next()\n"
"    Signature: next|ptr-oaOccBusTermBit|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusTermBit_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTermBit data;
    int convert_status=PyoaIter_oaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermBitObject* self=(PyoaIter_oaOccBusTermBitObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermBitp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusTermBit_FromoaOccBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusTermBit_assign_doc[] = 
"Class: oaIter_oaOccBusTermBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusTermBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusTermBit data;
  int convert_status=PyoaIter_oaOccBusTermBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusTermBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusTermBit_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusTermBit_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusTermBit_getNext,METH_VARARGS,oaIter_oaOccBusTermBit_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusTermBit_next,METH_VARARGS,oaIter_oaOccBusTermBit_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusTermBit_tp_assign,METH_VARARGS,oaIter_oaOccBusTermBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusTermBit_doc[] = 
"Class: oaIter_oaOccBusTermBit\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusTermBit(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusTermBit||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusTermBit)\n"
"    Calls: oaIter_oaOccBusTermBit(const oaIter_oaOccBusTermBit& iterIn)\n"
"    Signature: oaIter_oaOccBusTermBit||cref-oaIter_oaOccBusTermBit,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusTermBit)\n"
"    Calls: (const oaIter_oaOccBusTermBit&)\n"
"    Signature: oaIter_oaOccBusTermBit||cref-oaIter_oaOccBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusTermBit",
    sizeof(PyoaIter_oaOccBusTermBitObject),
    0,
    (destructor)oaIter_oaOccBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusTermBit_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusTermBit_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusTermBit_iternext,	/* tp_iternext */
    oaIter_oaOccBusTermBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusTermBit",
           (PyObject*)(&PyoaIter_oaOccBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusTermBit\n");
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
// Wrapper Implementation for Class: oaIter_oaOccBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccBusTermDefObject* self = (PyoaIter_oaOccBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccBusTermDef)
    {
        PyParamoaIter_oaOccBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccBusTermDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccBusTermDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccBusTermDef)\n"
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
oaIter_oaOccBusTermDef_tp_dealloc(PyoaIter_oaOccBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccBusTermDef value;
    int convert_status=PyoaIter_oaOccBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccBusTermDef v1;
    PyParamoaIter_oaOccBusTermDef v2;
    int convert_status1=PyoaIter_oaOccBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccBusTermDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccBusTermDef ob;
    int convert_status=PyoaIter_oaOccBusTermDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccBusTermDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccBusTermDef_Convert(PyObject* ob,PyParamoaIter_oaOccBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccBusTermDef_Check(ob)) {
        result->SetData( (oaIter_oaOccBusTermDef*) ((PyoaIter_oaOccBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccBusTermDef_FromoaIter_oaOccBusTermDef(oaIter_oaOccBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccBusTermDef_Type.tp_alloc(&PyoaIter_oaOccBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccBusTermDefObject* self = (PyoaIter_oaOccBusTermDefObject*)bself;
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
static char oaIter_oaOccBusTermDef_getNext_doc[] = 
"Class: oaIter_oaOccBusTermDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermDef* getNext()\n"
"    Signature: getNext|ptr-oaOccBusTermDef|\n"
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
oaIter_oaOccBusTermDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTermDef data;
    int convert_status=PyoaIter_oaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermDefObject* self=(PyoaIter_oaOccBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermDefp result= (data.DataCall()->getNext());
        return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccBusTermDef_next_doc[] = 
"Class: oaIter_oaOccBusTermDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermDef* next()\n"
"    Signature: next|ptr-oaOccBusTermDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccBusTermDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccBusTermDef data;
    int convert_status=PyoaIter_oaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccBusTermDefObject* self=(PyoaIter_oaOccBusTermDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccBusTermDef_assign_doc[] = 
"Class: oaIter_oaOccBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccBusTermDef data;
  int convert_status=PyoaIter_oaOccBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccBusTermDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccBusTermDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccBusTermDef_getNext,METH_VARARGS,oaIter_oaOccBusTermDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccBusTermDef_next,METH_VARARGS,oaIter_oaOccBusTermDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccBusTermDef_tp_assign,METH_VARARGS,oaIter_oaOccBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccBusTermDef_doc[] = 
"Class: oaIter_oaOccBusTermDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccBusTermDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccBusTermDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccBusTermDef)\n"
"    Calls: oaIter_oaOccBusTermDef(const oaIter_oaOccBusTermDef& iterIn)\n"
"    Signature: oaIter_oaOccBusTermDef||cref-oaIter_oaOccBusTermDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccBusTermDef)\n"
"    Calls: (const oaIter_oaOccBusTermDef&)\n"
"    Signature: oaIter_oaOccBusTermDef||cref-oaIter_oaOccBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccBusTermDef",
    sizeof(PyoaIter_oaOccBusTermDefObject),
    0,
    (destructor)oaIter_oaOccBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccBusTermDef_tp_repr,	/* tp_repr */
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
    oaIter_oaOccBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccBusTermDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccBusTermDef_iternext,	/* tp_iternext */
    oaIter_oaOccBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccBusTermDef",
           (PyObject*)(&PyoaIter_oaOccBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccBusTermDef\n");
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
// Wrapper Implementation for Class: oaIter_oaOccConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccConnectDefObject* self = (PyoaIter_oaOccConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccConnectDef)
    {
        PyParamoaIter_oaOccConnectDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccConnectDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccConnectDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccConnectDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccConnectDef)\n"
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
oaIter_oaOccConnectDef_tp_dealloc(PyoaIter_oaOccConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccConnectDef value;
    int convert_status=PyoaIter_oaOccConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccConnectDef v1;
    PyParamoaIter_oaOccConnectDef v2;
    int convert_status1=PyoaIter_oaOccConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccConnectDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccConnectDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccConnectDef ob;
    int convert_status=PyoaIter_oaOccConnectDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccConnectDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccConnectDef_FromoaOccConnectDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccConnectDef_Convert(PyObject* ob,PyParamoaIter_oaOccConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccConnectDef_Check(ob)) {
        result->SetData( (oaIter_oaOccConnectDef*) ((PyoaIter_oaOccConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccConnectDef_FromoaIter_oaOccConnectDef(oaIter_oaOccConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccConnectDef_Type.tp_alloc(&PyoaIter_oaOccConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccConnectDefObject* self = (PyoaIter_oaOccConnectDefObject*)bself;
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
static char oaIter_oaOccConnectDef_getNext_doc[] = 
"Class: oaIter_oaOccConnectDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccConnectDef* getNext()\n"
"    Signature: getNext|ptr-oaOccConnectDef|\n"
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
oaIter_oaOccConnectDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccConnectDef data;
    int convert_status=PyoaIter_oaOccConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccConnectDefObject* self=(PyoaIter_oaOccConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccConnectDefp result= (data.DataCall()->getNext());
        return PyoaOccConnectDef_FromoaOccConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccConnectDef_next_doc[] = 
"Class: oaIter_oaOccConnectDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccConnectDef* next()\n"
"    Signature: next|ptr-oaOccConnectDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccConnectDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccConnectDef data;
    int convert_status=PyoaIter_oaOccConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccConnectDefObject* self=(PyoaIter_oaOccConnectDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccConnectDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccConnectDef_FromoaOccConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccConnectDef_assign_doc[] = 
"Class: oaIter_oaOccConnectDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccConnectDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccConnectDef data;
  int convert_status=PyoaIter_oaOccConnectDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccConnectDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccConnectDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccConnectDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccConnectDef_getNext,METH_VARARGS,oaIter_oaOccConnectDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccConnectDef_next,METH_VARARGS,oaIter_oaOccConnectDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccConnectDef_tp_assign,METH_VARARGS,oaIter_oaOccConnectDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccConnectDef_doc[] = 
"Class: oaIter_oaOccConnectDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccConnectDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccConnectDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccConnectDef)\n"
"    Calls: oaIter_oaOccConnectDef(const oaIter_oaOccConnectDef& iterIn)\n"
"    Signature: oaIter_oaOccConnectDef||cref-oaIter_oaOccConnectDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccConnectDef)\n"
"    Calls: (const oaIter_oaOccConnectDef&)\n"
"    Signature: oaIter_oaOccConnectDef||cref-oaIter_oaOccConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccConnectDef",
    sizeof(PyoaIter_oaOccConnectDefObject),
    0,
    (destructor)oaIter_oaOccConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccConnectDef_tp_repr,	/* tp_repr */
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
    oaIter_oaOccConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccConnectDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccConnectDef_iternext,	/* tp_iternext */
    oaIter_oaOccConnectDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccConnectDef",
           (PyObject*)(&PyoaIter_oaOccConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccConnectDef\n");
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
// Wrapper Implementation for Class: oaIter_oaOccDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccDesignInstObject* self = (PyoaIter_oaOccDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccDesignInst)
    {
        PyParamoaIter_oaOccDesignInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccDesignInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccDesignInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccDesignInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccDesignInst)\n"
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
oaIter_oaOccDesignInst_tp_dealloc(PyoaIter_oaOccDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccDesignInst value;
    int convert_status=PyoaIter_oaOccDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccDesignInst v1;
    PyParamoaIter_oaOccDesignInst v2;
    int convert_status1=PyoaIter_oaOccDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccDesignInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccDesignInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccDesignInst ob;
    int convert_status=PyoaIter_oaOccDesignInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccDesignInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccDesignInst_FromoaOccDesignInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccDesignInst_Convert(PyObject* ob,PyParamoaIter_oaOccDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccDesignInst_Check(ob)) {
        result->SetData( (oaIter_oaOccDesignInst*) ((PyoaIter_oaOccDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccDesignInst_FromoaIter_oaOccDesignInst(oaIter_oaOccDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccDesignInst_Type.tp_alloc(&PyoaIter_oaOccDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccDesignInstObject* self = (PyoaIter_oaOccDesignInstObject*)bself;
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
static char oaIter_oaOccDesignInst_getNext_doc[] = 
"Class: oaIter_oaOccDesignInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccDesignInst* getNext()\n"
"    Signature: getNext|ptr-oaOccDesignInst|\n"
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
oaIter_oaOccDesignInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccDesignInst data;
    int convert_status=PyoaIter_oaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccDesignInstObject* self=(PyoaIter_oaOccDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccDesignInstp result= (data.DataCall()->getNext());
        return PyoaOccDesignInst_FromoaOccDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccDesignInst_next_doc[] = 
"Class: oaIter_oaOccDesignInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccDesignInst* next()\n"
"    Signature: next|ptr-oaOccDesignInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccDesignInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccDesignInst data;
    int convert_status=PyoaIter_oaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccDesignInstObject* self=(PyoaIter_oaOccDesignInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccDesignInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccDesignInst_FromoaOccDesignInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccDesignInst_assign_doc[] = 
"Class: oaIter_oaOccDesignInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccDesignInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccDesignInst data;
  int convert_status=PyoaIter_oaOccDesignInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccDesignInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccDesignInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccDesignInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccDesignInst_getNext,METH_VARARGS,oaIter_oaOccDesignInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccDesignInst_next,METH_VARARGS,oaIter_oaOccDesignInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccDesignInst_tp_assign,METH_VARARGS,oaIter_oaOccDesignInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccDesignInst_doc[] = 
"Class: oaIter_oaOccDesignInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccDesignInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccDesignInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccDesignInst)\n"
"    Calls: oaIter_oaOccDesignInst(const oaIter_oaOccDesignInst& iterIn)\n"
"    Signature: oaIter_oaOccDesignInst||cref-oaIter_oaOccDesignInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccDesignInst)\n"
"    Calls: (const oaIter_oaOccDesignInst&)\n"
"    Signature: oaIter_oaOccDesignInst||cref-oaIter_oaOccDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccDesignInst",
    sizeof(PyoaIter_oaOccDesignInstObject),
    0,
    (destructor)oaIter_oaOccDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccDesignInst_tp_repr,	/* tp_repr */
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
    oaIter_oaOccDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccDesignInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccDesignInst_iternext,	/* tp_iternext */
    oaIter_oaOccDesignInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccDesignInst",
           (PyObject*)(&PyoaIter_oaOccDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccDesignInst\n");
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
// Wrapper Implementation for Class: oaIter_oaOccInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccInstObject* self = (PyoaIter_oaOccInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccInst)
    {
        PyParamoaIter_oaOccInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccInst)\n"
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
oaIter_oaOccInst_tp_dealloc(PyoaIter_oaOccInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccInst value;
    int convert_status=PyoaIter_oaOccInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaOccInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccInst v1;
    PyParamoaIter_oaOccInst v2;
    int convert_status1=PyoaIter_oaOccInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccInst ob;
    int convert_status=PyoaIter_oaOccInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccInst_FromoaOccInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccInst_Convert(PyObject* ob,PyParamoaIter_oaOccInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccInst_Check(ob)) {
        result->SetData( (oaIter_oaOccInst*) ((PyoaIter_oaOccInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccInst_FromoaIter_oaOccInst(oaIter_oaOccInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccInst_Type.tp_alloc(&PyoaIter_oaOccInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccInstObject* self = (PyoaIter_oaOccInstObject*)bself;
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
static char oaIter_oaOccInst_getNext_doc[] = 
"Class: oaIter_oaOccInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccInst* getNext()\n"
"    Signature: getNext|ptr-oaOccInst|\n"
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
oaIter_oaOccInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInst data;
    int convert_status=PyoaIter_oaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstObject* self=(PyoaIter_oaOccInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstp result= (data.DataCall()->getNext());
        return PyoaOccInst_FromoaOccInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccInst_next_doc[] = 
"Class: oaIter_oaOccInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccInst* next()\n"
"    Signature: next|ptr-oaOccInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInst data;
    int convert_status=PyoaIter_oaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstObject* self=(PyoaIter_oaOccInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccInst_FromoaOccInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccInst_assign_doc[] = 
"Class: oaIter_oaOccInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccInst data;
  int convert_status=PyoaIter_oaOccInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccInst_getNext,METH_VARARGS,oaIter_oaOccInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccInst_next,METH_VARARGS,oaIter_oaOccInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccInst_tp_assign,METH_VARARGS,oaIter_oaOccInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccInst_doc[] = 
"Class: oaIter_oaOccInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccInst)\n"
"    Calls: oaIter_oaOccInst(const oaIter_oaOccInst& iterIn)\n"
"    Signature: oaIter_oaOccInst||cref-oaIter_oaOccInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccInst)\n"
"    Calls: (const oaIter_oaOccInst&)\n"
"    Signature: oaIter_oaOccInst||cref-oaIter_oaOccInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccInst",
    sizeof(PyoaIter_oaOccInstObject),
    0,
    (destructor)oaIter_oaOccInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccInst_tp_repr,	/* tp_repr */
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
    oaIter_oaOccInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccInst_iternext,	/* tp_iternext */
    oaIter_oaOccInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccInst",
           (PyObject*)(&PyoaIter_oaOccInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccInst\n");
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
// Wrapper Implementation for Class: oaIter_oaOccInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccInstHeaderObject* self = (PyoaIter_oaOccInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccInstHeader)
    {
        PyParamoaIter_oaOccInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccInstHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccInstHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccInstHeader)\n"
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
oaIter_oaOccInstHeader_tp_dealloc(PyoaIter_oaOccInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccInstHeader value;
    int convert_status=PyoaIter_oaOccInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccInstHeader v1;
    PyParamoaIter_oaOccInstHeader v2;
    int convert_status1=PyoaIter_oaOccInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccInstHeader ob;
    int convert_status=PyoaIter_oaOccInstHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccInstHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccInstHeader_FromoaOccInstHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccInstHeader_Convert(PyObject* ob,PyParamoaIter_oaOccInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccInstHeader_Check(ob)) {
        result->SetData( (oaIter_oaOccInstHeader*) ((PyoaIter_oaOccInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccInstHeader_FromoaIter_oaOccInstHeader(oaIter_oaOccInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccInstHeader_Type.tp_alloc(&PyoaIter_oaOccInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccInstHeaderObject* self = (PyoaIter_oaOccInstHeaderObject*)bself;
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
static char oaIter_oaOccInstHeader_getNext_doc[] = 
"Class: oaIter_oaOccInstHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstHeader* getNext()\n"
"    Signature: getNext|ptr-oaOccInstHeader|\n"
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
oaIter_oaOccInstHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInstHeader data;
    int convert_status=PyoaIter_oaOccInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstHeaderObject* self=(PyoaIter_oaOccInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstHeaderp result= (data.DataCall()->getNext());
        return PyoaOccInstHeader_FromoaOccInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccInstHeader_next_doc[] = 
"Class: oaIter_oaOccInstHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstHeader* next()\n"
"    Signature: next|ptr-oaOccInstHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccInstHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInstHeader data;
    int convert_status=PyoaIter_oaOccInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstHeaderObject* self=(PyoaIter_oaOccInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccInstHeader_FromoaOccInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccInstHeader_assign_doc[] = 
"Class: oaIter_oaOccInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccInstHeader data;
  int convert_status=PyoaIter_oaOccInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccInstHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccInstHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccInstHeader_getNext,METH_VARARGS,oaIter_oaOccInstHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccInstHeader_next,METH_VARARGS,oaIter_oaOccInstHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccInstHeader_tp_assign,METH_VARARGS,oaIter_oaOccInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccInstHeader_doc[] = 
"Class: oaIter_oaOccInstHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccInstHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccInstHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccInstHeader)\n"
"    Calls: oaIter_oaOccInstHeader(const oaIter_oaOccInstHeader& iterIn)\n"
"    Signature: oaIter_oaOccInstHeader||cref-oaIter_oaOccInstHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccInstHeader)\n"
"    Calls: (const oaIter_oaOccInstHeader&)\n"
"    Signature: oaIter_oaOccInstHeader||cref-oaIter_oaOccInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccInstHeader",
    sizeof(PyoaIter_oaOccInstHeaderObject),
    0,
    (destructor)oaIter_oaOccInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccInstHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaOccInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccInstHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccInstHeader_iternext,	/* tp_iternext */
    oaIter_oaOccInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccInstHeader",
           (PyObject*)(&PyoaIter_oaOccInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccInstHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaOccInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccInstTermObject* self = (PyoaIter_oaOccInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccInstTerm)
    {
        PyParamoaIter_oaOccInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccInstTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccInstTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccInstTerm)\n"
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
oaIter_oaOccInstTerm_tp_dealloc(PyoaIter_oaOccInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccInstTerm value;
    int convert_status=PyoaIter_oaOccInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaOccInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccInstTerm v1;
    PyParamoaIter_oaOccInstTerm v2;
    int convert_status1=PyoaIter_oaOccInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccInstTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccInstTerm ob;
    int convert_status=PyoaIter_oaOccInstTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccInstTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccInstTerm_FromoaOccInstTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccInstTerm_Convert(PyObject* ob,PyParamoaIter_oaOccInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccInstTerm_Check(ob)) {
        result->SetData( (oaIter_oaOccInstTerm*) ((PyoaIter_oaOccInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccInstTerm_FromoaIter_oaOccInstTerm(oaIter_oaOccInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccInstTerm_Type.tp_alloc(&PyoaIter_oaOccInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccInstTermObject* self = (PyoaIter_oaOccInstTermObject*)bself;
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
static char oaIter_oaOccInstTerm_getNext_doc[] = 
"Class: oaIter_oaOccInstTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstTerm* getNext()\n"
"    Signature: getNext|ptr-oaOccInstTerm|\n"
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
oaIter_oaOccInstTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInstTerm data;
    int convert_status=PyoaIter_oaOccInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstTermObject* self=(PyoaIter_oaOccInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstTermp result= (data.DataCall()->getNext());
        return PyoaOccInstTerm_FromoaOccInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccInstTerm_next_doc[] = 
"Class: oaIter_oaOccInstTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstTerm* next()\n"
"    Signature: next|ptr-oaOccInstTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccInstTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccInstTerm data;
    int convert_status=PyoaIter_oaOccInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccInstTermObject* self=(PyoaIter_oaOccInstTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccInstTerm_FromoaOccInstTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccInstTerm_assign_doc[] = 
"Class: oaIter_oaOccInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccInstTerm data;
  int convert_status=PyoaIter_oaOccInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccInstTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccInstTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccInstTerm_getNext,METH_VARARGS,oaIter_oaOccInstTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccInstTerm_next,METH_VARARGS,oaIter_oaOccInstTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccInstTerm_tp_assign,METH_VARARGS,oaIter_oaOccInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccInstTerm_doc[] = 
"Class: oaIter_oaOccInstTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccInstTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccInstTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccInstTerm)\n"
"    Calls: oaIter_oaOccInstTerm(const oaIter_oaOccInstTerm& iterIn)\n"
"    Signature: oaIter_oaOccInstTerm||cref-oaIter_oaOccInstTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccInstTerm)\n"
"    Calls: (const oaIter_oaOccInstTerm&)\n"
"    Signature: oaIter_oaOccInstTerm||cref-oaIter_oaOccInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccInstTerm",
    sizeof(PyoaIter_oaOccInstTermObject),
    0,
    (destructor)oaIter_oaOccInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccInstTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaOccInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccInstTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccInstTerm_iternext,	/* tp_iternext */
    oaIter_oaOccInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccInstTerm",
           (PyObject*)(&PyoaIter_oaOccInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccInstTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaOccModuleInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccModuleInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccModuleInstObject* self = (PyoaIter_oaOccModuleInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccModuleInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccModuleInst)
    {
        PyParamoaIter_oaOccModuleInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccModuleInst_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccModuleInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccModuleInst, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccModuleInst)\n"
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
oaIter_oaOccModuleInst_tp_dealloc(PyoaIter_oaOccModuleInstObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccModuleInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInst_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccModuleInst value;
    int convert_status=PyoaIter_oaOccModuleInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOccModuleInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccModuleInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccModuleInst v1;
    PyParamoaIter_oaOccModuleInst v2;
    int convert_status1=PyoaIter_oaOccModuleInst_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccModuleInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInst_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInst_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccModuleInst ob;
    int convert_status=PyoaIter_oaOccModuleInst_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccModuleInst* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccModuleInst_FromoaOccModuleInst(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccModuleInst_Convert(PyObject* ob,PyParamoaIter_oaOccModuleInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccModuleInst_Check(ob)) {
        result->SetData( (oaIter_oaOccModuleInst*) ((PyoaIter_oaOccModuleInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccModuleInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccModuleInst_FromoaIter_oaOccModuleInst(oaIter_oaOccModuleInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccModuleInst_Type.tp_alloc(&PyoaIter_oaOccModuleInst_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccModuleInstObject* self = (PyoaIter_oaOccModuleInstObject*)bself;
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
static char oaIter_oaOccModuleInst_getNext_doc[] = 
"Class: oaIter_oaOccModuleInst, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccModuleInst* getNext()\n"
"    Signature: getNext|ptr-oaOccModuleInst|\n"
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
oaIter_oaOccModuleInst_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccModuleInst data;
    int convert_status=PyoaIter_oaOccModuleInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccModuleInstObject* self=(PyoaIter_oaOccModuleInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccModuleInstp result= (data.DataCall()->getNext());
        return PyoaOccModuleInst_FromoaOccModuleInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccModuleInst_next_doc[] = 
"Class: oaIter_oaOccModuleInst, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccModuleInst* next()\n"
"    Signature: next|ptr-oaOccModuleInst|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccModuleInst_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccModuleInst data;
    int convert_status=PyoaIter_oaOccModuleInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccModuleInstObject* self=(PyoaIter_oaOccModuleInstObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccModuleInstp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccModuleInst_FromoaOccModuleInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccModuleInst_assign_doc[] = 
"Class: oaIter_oaOccModuleInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccModuleInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccModuleInst data;
  int convert_status=PyoaIter_oaOccModuleInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccModuleInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccModuleInst_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccModuleInst_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccModuleInst_getNext,METH_VARARGS,oaIter_oaOccModuleInst_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccModuleInst_next,METH_VARARGS,oaIter_oaOccModuleInst_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccModuleInst_tp_assign,METH_VARARGS,oaIter_oaOccModuleInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccModuleInst_doc[] = 
"Class: oaIter_oaOccModuleInst\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccModuleInst(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccModuleInst||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccModuleInst)\n"
"    Calls: oaIter_oaOccModuleInst(const oaIter_oaOccModuleInst& iterIn)\n"
"    Signature: oaIter_oaOccModuleInst||cref-oaIter_oaOccModuleInst,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccModuleInst)\n"
"    Calls: (const oaIter_oaOccModuleInst&)\n"
"    Signature: oaIter_oaOccModuleInst||cref-oaIter_oaOccModuleInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccModuleInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccModuleInst",
    sizeof(PyoaIter_oaOccModuleInstObject),
    0,
    (destructor)oaIter_oaOccModuleInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccModuleInst_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccModuleInst_tp_repr,	/* tp_repr */
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
    oaIter_oaOccModuleInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccModuleInst_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccModuleInst_iternext,	/* tp_iternext */
    oaIter_oaOccModuleInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccModuleInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccModuleInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccModuleInst_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccModuleInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccModuleInst",
           (PyObject*)(&PyoaIter_oaOccModuleInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccModuleInst\n");
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
// Wrapper Implementation for Class: oaIter_oaOccModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccModuleInstHeaderObject* self = (PyoaIter_oaOccModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccModuleInstHeader)
    {
        PyParamoaIter_oaOccModuleInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccModuleInstHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccModuleInstHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccModuleInstHeader)\n"
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
oaIter_oaOccModuleInstHeader_tp_dealloc(PyoaIter_oaOccModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccModuleInstHeader value;
    int convert_status=PyoaIter_oaOccModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaIter_oaOccModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccModuleInstHeader v1;
    PyParamoaIter_oaOccModuleInstHeader v2;
    int convert_status1=PyoaIter_oaOccModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInstHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccModuleInstHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccModuleInstHeader ob;
    int convert_status=PyoaIter_oaOccModuleInstHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccModuleInstHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccModuleInstHeader_Convert(PyObject* ob,PyParamoaIter_oaOccModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccModuleInstHeader_Check(ob)) {
        result->SetData( (oaIter_oaOccModuleInstHeader*) ((PyoaIter_oaOccModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccModuleInstHeader_FromoaIter_oaOccModuleInstHeader(oaIter_oaOccModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccModuleInstHeader_Type.tp_alloc(&PyoaIter_oaOccModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccModuleInstHeaderObject* self = (PyoaIter_oaOccModuleInstHeaderObject*)bself;
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
static char oaIter_oaOccModuleInstHeader_getNext_doc[] = 
"Class: oaIter_oaOccModuleInstHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccModuleInstHeader* getNext()\n"
"    Signature: getNext|ptr-oaOccModuleInstHeader|\n"
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
oaIter_oaOccModuleInstHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccModuleInstHeader data;
    int convert_status=PyoaIter_oaOccModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccModuleInstHeaderObject* self=(PyoaIter_oaOccModuleInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccModuleInstHeaderp result= (data.DataCall()->getNext());
        return PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccModuleInstHeader_next_doc[] = 
"Class: oaIter_oaOccModuleInstHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccModuleInstHeader* next()\n"
"    Signature: next|ptr-oaOccModuleInstHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccModuleInstHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccModuleInstHeader data;
    int convert_status=PyoaIter_oaOccModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccModuleInstHeaderObject* self=(PyoaIter_oaOccModuleInstHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccModuleInstHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccModuleInstHeader_assign_doc[] = 
"Class: oaIter_oaOccModuleInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccModuleInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccModuleInstHeader data;
  int convert_status=PyoaIter_oaOccModuleInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccModuleInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccModuleInstHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccModuleInstHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccModuleInstHeader_getNext,METH_VARARGS,oaIter_oaOccModuleInstHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccModuleInstHeader_next,METH_VARARGS,oaIter_oaOccModuleInstHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccModuleInstHeader_tp_assign,METH_VARARGS,oaIter_oaOccModuleInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccModuleInstHeader_doc[] = 
"Class: oaIter_oaOccModuleInstHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccModuleInstHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccModuleInstHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccModuleInstHeader)\n"
"    Calls: oaIter_oaOccModuleInstHeader(const oaIter_oaOccModuleInstHeader& iterIn)\n"
"    Signature: oaIter_oaOccModuleInstHeader||cref-oaIter_oaOccModuleInstHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccModuleInstHeader)\n"
"    Calls: (const oaIter_oaOccModuleInstHeader&)\n"
"    Signature: oaIter_oaOccModuleInstHeader||cref-oaIter_oaOccModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccModuleInstHeader",
    sizeof(PyoaIter_oaOccModuleInstHeaderObject),
    0,
    (destructor)oaIter_oaOccModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccModuleInstHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaOccModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccModuleInstHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccModuleInstHeader_iternext,	/* tp_iternext */
    oaIter_oaOccModuleInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccModuleInstHeader",
           (PyObject*)(&PyoaIter_oaOccModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccModuleInstHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccNetObject* self = (PyoaIter_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccNet)
    {
        PyParamoaIter_oaOccNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccNet_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccNet, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccNet)\n"
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
oaIter_oaOccNet_tp_dealloc(PyoaIter_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccNet value;
    int convert_status=PyoaIter_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccNet v1;
    PyParamoaIter_oaOccNet v2;
    int convert_status1=PyoaIter_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccNet_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccNet_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccNet ob;
    int convert_status=PyoaIter_oaOccNet_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccNet* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccNet_FromoaOccNet(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccNet_Convert(PyObject* ob,PyParamoaIter_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccNet_Check(ob)) {
        result->SetData( (oaIter_oaOccNet*) ((PyoaIter_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccNet_FromoaIter_oaOccNet(oaIter_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccNet_Type.tp_alloc(&PyoaIter_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccNetObject* self = (PyoaIter_oaOccNetObject*)bself;
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
static char oaIter_oaOccNet_getNext_doc[] = 
"Class: oaIter_oaOccNet, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccNet* getNext()\n"
"    Signature: getNext|ptr-oaOccNet|\n"
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
oaIter_oaOccNet_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccNet data;
    int convert_status=PyoaIter_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccNetObject* self=(PyoaIter_oaOccNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccNetp result= (data.DataCall()->getNext());
        return PyoaOccNet_FromoaOccNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccNet_next_doc[] = 
"Class: oaIter_oaOccNet, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccNet* next()\n"
"    Signature: next|ptr-oaOccNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccNet_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccNet data;
    int convert_status=PyoaIter_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccNetObject* self=(PyoaIter_oaOccNetObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccNetp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccNet_FromoaOccNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccNet_assign_doc[] = 
"Class: oaIter_oaOccNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccNet data;
  int convert_status=PyoaIter_oaOccNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccNet_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccNet_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccNet_getNext,METH_VARARGS,oaIter_oaOccNet_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccNet_next,METH_VARARGS,oaIter_oaOccNet_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccNet_tp_assign,METH_VARARGS,oaIter_oaOccNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccNet_doc[] = 
"Class: oaIter_oaOccNet\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccNet(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccNet||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccNet)\n"
"    Calls: oaIter_oaOccNet(const oaIter_oaOccNet& iterIn)\n"
"    Signature: oaIter_oaOccNet||cref-oaIter_oaOccNet,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccNet)\n"
"    Calls: (const oaIter_oaOccNet&)\n"
"    Signature: oaIter_oaOccNet||cref-oaIter_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccNet",
    sizeof(PyoaIter_oaOccNetObject),
    0,
    (destructor)oaIter_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccNet_tp_repr,	/* tp_repr */
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
    oaIter_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccNet_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccNet_iternext,	/* tp_iternext */
    oaIter_oaOccNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccNet",
           (PyObject*)(&PyoaIter_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccNet\n");
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
// Wrapper Implementation for Class: oaIter_oaOccTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccTermObject* self = (PyoaIter_oaOccTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccTerm)
    {
        PyParamoaIter_oaOccTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccTerm_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccTerm, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccTerm)\n"
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
oaIter_oaOccTerm_tp_dealloc(PyoaIter_oaOccTermObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccTerm_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccTerm value;
    int convert_status=PyoaIter_oaOccTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaOccTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccTerm v1;
    PyParamoaIter_oaOccTerm v2;
    int convert_status1=PyoaIter_oaOccTerm_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccTerm_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccTerm_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccTerm ob;
    int convert_status=PyoaIter_oaOccTerm_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccTerm* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccTerm_FromoaOccTerm(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccTerm_Convert(PyObject* ob,PyParamoaIter_oaOccTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccTerm_Check(ob)) {
        result->SetData( (oaIter_oaOccTerm*) ((PyoaIter_oaOccTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccTerm_FromoaIter_oaOccTerm(oaIter_oaOccTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccTerm_Type.tp_alloc(&PyoaIter_oaOccTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccTermObject* self = (PyoaIter_oaOccTermObject*)bself;
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
static char oaIter_oaOccTerm_getNext_doc[] = 
"Class: oaIter_oaOccTerm, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccTerm* getNext()\n"
"    Signature: getNext|ptr-oaOccTerm|\n"
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
oaIter_oaOccTerm_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccTerm data;
    int convert_status=PyoaIter_oaOccTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccTermObject* self=(PyoaIter_oaOccTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccTermp result= (data.DataCall()->getNext());
        return PyoaOccTerm_FromoaOccTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccTerm_next_doc[] = 
"Class: oaIter_oaOccTerm, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccTerm* next()\n"
"    Signature: next|ptr-oaOccTerm|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccTerm_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccTerm data;
    int convert_status=PyoaIter_oaOccTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccTermObject* self=(PyoaIter_oaOccTermObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccTermp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccTerm_FromoaOccTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccTerm_assign_doc[] = 
"Class: oaIter_oaOccTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccTerm data;
  int convert_status=PyoaIter_oaOccTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccTerm_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccTerm_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccTerm_getNext,METH_VARARGS,oaIter_oaOccTerm_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccTerm_next,METH_VARARGS,oaIter_oaOccTerm_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccTerm_tp_assign,METH_VARARGS,oaIter_oaOccTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccTerm_doc[] = 
"Class: oaIter_oaOccTerm\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccTerm(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccTerm||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccTerm)\n"
"    Calls: oaIter_oaOccTerm(const oaIter_oaOccTerm& iterIn)\n"
"    Signature: oaIter_oaOccTerm||cref-oaIter_oaOccTerm,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccTerm)\n"
"    Calls: (const oaIter_oaOccTerm&)\n"
"    Signature: oaIter_oaOccTerm||cref-oaIter_oaOccTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccTerm",
    sizeof(PyoaIter_oaOccTermObject),
    0,
    (destructor)oaIter_oaOccTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccTerm_tp_repr,	/* tp_repr */
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
    oaIter_oaOccTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccTerm_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccTerm_iternext,	/* tp_iternext */
    oaIter_oaOccTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccTerm",
           (PyObject*)(&PyoaIter_oaOccTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccTerm\n");
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
// Wrapper Implementation for Class: oaIter_oaOccVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccVectorInstDefObject* self = (PyoaIter_oaOccVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccVectorInstDef)
    {
        PyParamoaIter_oaOccVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccVectorInstDef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccVectorInstDef)\n"
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
oaIter_oaOccVectorInstDef_tp_dealloc(PyoaIter_oaOccVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccVectorInstDef value;
    int convert_status=PyoaIter_oaOccVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaIter_oaOccVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccVectorInstDef v1;
    PyParamoaIter_oaOccVectorInstDef v2;
    int convert_status1=PyoaIter_oaOccVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccVectorInstDef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccVectorInstDef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccVectorInstDef ob;
    int convert_status=PyoaIter_oaOccVectorInstDef_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccVectorInstDef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccVectorInstDef_FromoaOccVectorInstDef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccVectorInstDef_Convert(PyObject* ob,PyParamoaIter_oaOccVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccVectorInstDef_Check(ob)) {
        result->SetData( (oaIter_oaOccVectorInstDef*) ((PyoaIter_oaOccVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccVectorInstDef_FromoaIter_oaOccVectorInstDef(oaIter_oaOccVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccVectorInstDef_Type.tp_alloc(&PyoaIter_oaOccVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccVectorInstDefObject* self = (PyoaIter_oaOccVectorInstDefObject*)bself;
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
static char oaIter_oaOccVectorInstDef_getNext_doc[] = 
"Class: oaIter_oaOccVectorInstDef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccVectorInstDef* getNext()\n"
"    Signature: getNext|ptr-oaOccVectorInstDef|\n"
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
oaIter_oaOccVectorInstDef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccVectorInstDef data;
    int convert_status=PyoaIter_oaOccVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccVectorInstDefObject* self=(PyoaIter_oaOccVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccVectorInstDefp result= (data.DataCall()->getNext());
        return PyoaOccVectorInstDef_FromoaOccVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccVectorInstDef_next_doc[] = 
"Class: oaIter_oaOccVectorInstDef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccVectorInstDef* next()\n"
"    Signature: next|ptr-oaOccVectorInstDef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccVectorInstDef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccVectorInstDef data;
    int convert_status=PyoaIter_oaOccVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccVectorInstDefObject* self=(PyoaIter_oaOccVectorInstDefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccVectorInstDefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccVectorInstDef_FromoaOccVectorInstDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccVectorInstDef_assign_doc[] = 
"Class: oaIter_oaOccVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccVectorInstDef data;
  int convert_status=PyoaIter_oaOccVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccVectorInstDef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccVectorInstDef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccVectorInstDef_getNext,METH_VARARGS,oaIter_oaOccVectorInstDef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccVectorInstDef_next,METH_VARARGS,oaIter_oaOccVectorInstDef_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccVectorInstDef_tp_assign,METH_VARARGS,oaIter_oaOccVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccVectorInstDef_doc[] = 
"Class: oaIter_oaOccVectorInstDef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccVectorInstDef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccVectorInstDef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccVectorInstDef)\n"
"    Calls: oaIter_oaOccVectorInstDef(const oaIter_oaOccVectorInstDef& iterIn)\n"
"    Signature: oaIter_oaOccVectorInstDef||cref-oaIter_oaOccVectorInstDef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccVectorInstDef)\n"
"    Calls: (const oaIter_oaOccVectorInstDef&)\n"
"    Signature: oaIter_oaOccVectorInstDef||cref-oaIter_oaOccVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccVectorInstDef",
    sizeof(PyoaIter_oaOccVectorInstDefObject),
    0,
    (destructor)oaIter_oaOccVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccVectorInstDef_tp_repr,	/* tp_repr */
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
    oaIter_oaOccVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccVectorInstDef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccVectorInstDef_iternext,	/* tp_iternext */
    oaIter_oaOccVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccVectorInstDef",
           (PyObject*)(&PyoaIter_oaOccVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccVectorInstDef\n");
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
// Wrapper Implementation for Class: oaIter_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOccurrenceObject* self = (PyoaIter_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOccurrence)
    {
        PyParamoaIter_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOccurrence, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOccurrence)\n"
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
oaIter_oaOccurrence_tp_dealloc(PyoaIter_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOccurrence value;
    int convert_status=PyoaIter_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOccurrence v1;
    PyParamoaIter_oaOccurrence v2;
    int convert_status1=PyoaIter_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccurrence_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOccurrence_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOccurrence ob;
    int convert_status=PyoaIter_oaOccurrence_Convert(self,&ob);
    assert(convert_status!=0);
    oaOccurrence* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOccurrence_FromoaOccurrence(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOccurrence_Convert(PyObject* ob,PyParamoaIter_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOccurrence_Check(ob)) {
        result->SetData( (oaIter_oaOccurrence*) ((PyoaIter_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOccurrence_FromoaIter_oaOccurrence(oaIter_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOccurrence_Type.tp_alloc(&PyoaIter_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOccurrenceObject* self = (PyoaIter_oaOccurrenceObject*)bself;
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
static char oaIter_oaOccurrence_getNext_doc[] = 
"Class: oaIter_oaOccurrence, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOccurrence* getNext()\n"
"    Signature: getNext|ptr-oaOccurrence|\n"
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
oaIter_oaOccurrence_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccurrence data;
    int convert_status=PyoaIter_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccurrenceObject* self=(PyoaIter_oaOccurrenceObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccurrencep result= (data.DataCall()->getNext());
        return PyoaOccurrence_FromoaOccurrence(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOccurrence_next_doc[] = 
"Class: oaIter_oaOccurrence, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOccurrence* next()\n"
"    Signature: next|ptr-oaOccurrence|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOccurrence_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOccurrence data;
    int convert_status=PyoaIter_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOccurrenceObject* self=(PyoaIter_oaOccurrenceObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOccurrencep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOccurrence_FromoaOccurrence(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOccurrence_assign_doc[] = 
"Class: oaIter_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOccurrence data;
  int convert_status=PyoaIter_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOccurrence_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOccurrence_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOccurrence_getNext,METH_VARARGS,oaIter_oaOccurrence_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOccurrence_next,METH_VARARGS,oaIter_oaOccurrence_next_doc},
    {"assign",(PyCFunction)oaIter_oaOccurrence_tp_assign,METH_VARARGS,oaIter_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOccurrence_doc[] = 
"Class: oaIter_oaOccurrence\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOccurrence(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOccurrence||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOccurrence)\n"
"    Calls: oaIter_oaOccurrence(const oaIter_oaOccurrence& iterIn)\n"
"    Signature: oaIter_oaOccurrence||cref-oaIter_oaOccurrence,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOccurrence)\n"
"    Calls: (const oaIter_oaOccurrence&)\n"
"    Signature: oaIter_oaOccurrence||cref-oaIter_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOccurrence",
    sizeof(PyoaIter_oaOccurrenceObject),
    0,
    (destructor)oaIter_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOccurrence_tp_repr,	/* tp_repr */
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
    oaIter_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOccurrence_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOccurrence_iternext,	/* tp_iternext */
    oaIter_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOccurrence",
           (PyObject*)(&PyoaIter_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOccurrence\n");
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
// Wrapper Implementation for Class: oaIter_oaOpPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOpPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOpPointObject* self = (PyoaIter_oaOpPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOpPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOpPoint)
    {
        PyParamoaIter_oaOpPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOpPoint_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOpPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOpPoint, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOpPoint)\n"
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
oaIter_oaOpPoint_tp_dealloc(PyoaIter_oaOpPointObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOpPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPoint_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOpPoint value;
    int convert_status=PyoaIter_oaOpPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaOpPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOpPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOpPoint v1;
    PyParamoaIter_oaOpPoint v2;
    int convert_status1=PyoaIter_oaOpPoint_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOpPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPoint_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPoint_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOpPoint ob;
    int convert_status=PyoaIter_oaOpPoint_Convert(self,&ob);
    assert(convert_status!=0);
    oaOpPoint* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOpPoint_FromoaOpPoint(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOpPoint_Convert(PyObject* ob,PyParamoaIter_oaOpPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOpPoint_Check(ob)) {
        result->SetData( (oaIter_oaOpPoint*) ((PyoaIter_oaOpPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOpPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOpPoint_FromoaIter_oaOpPoint(oaIter_oaOpPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOpPoint_Type.tp_alloc(&PyoaIter_oaOpPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOpPointObject* self = (PyoaIter_oaOpPointObject*)bself;
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
static char oaIter_oaOpPoint_getNext_doc[] = 
"Class: oaIter_oaOpPoint, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOpPoint* getNext()\n"
"    Signature: getNext|ptr-oaOpPoint|\n"
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
oaIter_oaOpPoint_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOpPoint data;
    int convert_status=PyoaIter_oaOpPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOpPointObject* self=(PyoaIter_oaOpPointObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOpPointp result= (data.DataCall()->getNext());
        return PyoaOpPoint_FromoaOpPoint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOpPoint_next_doc[] = 
"Class: oaIter_oaOpPoint, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOpPoint* next()\n"
"    Signature: next|ptr-oaOpPoint|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOpPoint_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOpPoint data;
    int convert_status=PyoaIter_oaOpPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOpPointObject* self=(PyoaIter_oaOpPointObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOpPointp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOpPoint_FromoaOpPoint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOpPoint_assign_doc[] = 
"Class: oaIter_oaOpPoint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOpPoint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOpPoint data;
  int convert_status=PyoaIter_oaOpPoint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOpPoint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOpPoint_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOpPoint_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOpPoint_getNext,METH_VARARGS,oaIter_oaOpPoint_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOpPoint_next,METH_VARARGS,oaIter_oaOpPoint_next_doc},
    {"assign",(PyCFunction)oaIter_oaOpPoint_tp_assign,METH_VARARGS,oaIter_oaOpPoint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOpPoint_doc[] = 
"Class: oaIter_oaOpPoint\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOpPoint(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOpPoint||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOpPoint)\n"
"    Calls: oaIter_oaOpPoint(const oaIter_oaOpPoint& iterIn)\n"
"    Signature: oaIter_oaOpPoint||cref-oaIter_oaOpPoint,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOpPoint)\n"
"    Calls: (const oaIter_oaOpPoint&)\n"
"    Signature: oaIter_oaOpPoint||cref-oaIter_oaOpPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOpPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOpPoint",
    sizeof(PyoaIter_oaOpPointObject),
    0,
    (destructor)oaIter_oaOpPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOpPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOpPoint_tp_repr,	/* tp_repr */
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
    oaIter_oaOpPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOpPoint_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOpPoint_iternext,	/* tp_iternext */
    oaIter_oaOpPoint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOpPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOpPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOpPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOpPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOpPoint",
           (PyObject*)(&PyoaIter_oaOpPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOpPoint\n");
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
// Wrapper Implementation for Class: oaIter_oaOpPointHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPointHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaOpPointHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaOpPointHeaderObject* self = (PyoaIter_oaOpPointHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOpPointHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaOpPointHeader)
    {
        PyParamoaIter_oaOpPointHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaOpPointHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaOpPointHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaOpPointHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaOpPointHeader)\n"
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
oaIter_oaOpPointHeader_tp_dealloc(PyoaIter_oaOpPointHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaOpPointHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPointHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaOpPointHeader value;
    int convert_status=PyoaIter_oaOpPointHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaIter_oaOpPointHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaOpPointHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaOpPointHeader v1;
    PyParamoaIter_oaOpPointHeader v2;
    int convert_status1=PyoaIter_oaOpPointHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaOpPointHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPointHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaOpPointHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaOpPointHeader ob;
    int convert_status=PyoaIter_oaOpPointHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaOpPointHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaOpPointHeader_FromoaOpPointHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaOpPointHeader_Convert(PyObject* ob,PyParamoaIter_oaOpPointHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaOpPointHeader_Check(ob)) {
        result->SetData( (oaIter_oaOpPointHeader*) ((PyoaIter_oaOpPointHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaOpPointHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaOpPointHeader_FromoaIter_oaOpPointHeader(oaIter_oaOpPointHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaOpPointHeader_Type.tp_alloc(&PyoaIter_oaOpPointHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaOpPointHeaderObject* self = (PyoaIter_oaOpPointHeaderObject*)bself;
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
static char oaIter_oaOpPointHeader_getNext_doc[] = 
"Class: oaIter_oaOpPointHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaOpPointHeader* getNext()\n"
"    Signature: getNext|ptr-oaOpPointHeader|\n"
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
oaIter_oaOpPointHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOpPointHeader data;
    int convert_status=PyoaIter_oaOpPointHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOpPointHeaderObject* self=(PyoaIter_oaOpPointHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOpPointHeaderp result= (data.DataCall()->getNext());
        return PyoaOpPointHeader_FromoaOpPointHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaOpPointHeader_next_doc[] = 
"Class: oaIter_oaOpPointHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaOpPointHeader* next()\n"
"    Signature: next|ptr-oaOpPointHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaOpPointHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaOpPointHeader data;
    int convert_status=PyoaIter_oaOpPointHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaOpPointHeaderObject* self=(PyoaIter_oaOpPointHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOpPointHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaOpPointHeader_FromoaOpPointHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaOpPointHeader_assign_doc[] = 
"Class: oaIter_oaOpPointHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaOpPointHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaOpPointHeader data;
  int convert_status=PyoaIter_oaOpPointHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaOpPointHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaOpPointHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaOpPointHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaOpPointHeader_getNext,METH_VARARGS,oaIter_oaOpPointHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaOpPointHeader_next,METH_VARARGS,oaIter_oaOpPointHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaOpPointHeader_tp_assign,METH_VARARGS,oaIter_oaOpPointHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaOpPointHeader_doc[] = 
"Class: oaIter_oaOpPointHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaOpPointHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaOpPointHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaOpPointHeader)\n"
"    Calls: oaIter_oaOpPointHeader(const oaIter_oaOpPointHeader& iterIn)\n"
"    Signature: oaIter_oaOpPointHeader||cref-oaIter_oaOpPointHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaOpPointHeader)\n"
"    Calls: (const oaIter_oaOpPointHeader&)\n"
"    Signature: oaIter_oaOpPointHeader||cref-oaIter_oaOpPointHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaOpPointHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaOpPointHeader",
    sizeof(PyoaIter_oaOpPointHeaderObject),
    0,
    (destructor)oaIter_oaOpPointHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaOpPointHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaOpPointHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaOpPointHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaOpPointHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaOpPointHeader_iternext,	/* tp_iternext */
    oaIter_oaOpPointHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaOpPointHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaOpPointHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaOpPointHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaOpPointHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaOpPointHeader",
           (PyObject*)(&PyoaIter_oaOpPointHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaOpPointHeader\n");
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
// Wrapper Implementation for Class: oaIter_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaParasiticNetworkObject* self = (PyoaIter_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaParasiticNetwork)
    {
        PyParamoaIter_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaParasiticNetwork, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaParasiticNetwork)\n"
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
oaIter_oaParasiticNetwork_tp_dealloc(PyoaIter_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaParasiticNetwork value;
    int convert_status=PyoaIter_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaIter_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaParasiticNetwork v1;
    PyParamoaIter_oaParasiticNetwork v2;
    int convert_status1=PyoaIter_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaParasiticNetwork_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaParasiticNetwork_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaParasiticNetwork ob;
    int convert_status=PyoaIter_oaParasiticNetwork_Convert(self,&ob);
    assert(convert_status!=0);
    oaParasiticNetwork* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaParasiticNetwork_FromoaParasiticNetwork(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaIter_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaIter_oaParasiticNetwork*) ((PyoaIter_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaParasiticNetwork_FromoaIter_oaParasiticNetwork(oaIter_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaParasiticNetwork_Type.tp_alloc(&PyoaIter_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaParasiticNetworkObject* self = (PyoaIter_oaParasiticNetworkObject*)bself;
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
static char oaIter_oaParasiticNetwork_getNext_doc[] = 
"Class: oaIter_oaParasiticNetwork, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaParasiticNetwork* getNext()\n"
"    Signature: getNext|ptr-oaParasiticNetwork|\n"
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
oaIter_oaParasiticNetwork_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaParasiticNetwork data;
    int convert_status=PyoaIter_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaParasiticNetworkObject* self=(PyoaIter_oaParasiticNetworkObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaParasiticNetworkp result= (data.DataCall()->getNext());
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
static char oaIter_oaParasiticNetwork_next_doc[] = 
"Class: oaIter_oaParasiticNetwork, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaParasiticNetwork* next()\n"
"    Signature: next|ptr-oaParasiticNetwork|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaParasiticNetwork_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaParasiticNetwork data;
    int convert_status=PyoaIter_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaParasiticNetworkObject* self=(PyoaIter_oaParasiticNetworkObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaParasiticNetworkp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaParasiticNetwork_FromoaParasiticNetwork(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaParasiticNetwork_assign_doc[] = 
"Class: oaIter_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaParasiticNetwork data;
  int convert_status=PyoaIter_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaParasiticNetwork_Convert,&p1)) {
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

static PyMethodDef oaIter_oaParasiticNetwork_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaParasiticNetwork_getNext,METH_VARARGS,oaIter_oaParasiticNetwork_getNext_doc},
    {"next",(PyCFunction)oaIter_oaParasiticNetwork_next,METH_VARARGS,oaIter_oaParasiticNetwork_next_doc},
    {"assign",(PyCFunction)oaIter_oaParasiticNetwork_tp_assign,METH_VARARGS,oaIter_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaParasiticNetwork_doc[] = 
"Class: oaIter_oaParasiticNetwork\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaParasiticNetwork(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaParasiticNetwork||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaParasiticNetwork)\n"
"    Calls: oaIter_oaParasiticNetwork(const oaIter_oaParasiticNetwork& iterIn)\n"
"    Signature: oaIter_oaParasiticNetwork||cref-oaIter_oaParasiticNetwork,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaParasiticNetwork)\n"
"    Calls: (const oaIter_oaParasiticNetwork&)\n"
"    Signature: oaIter_oaParasiticNetwork||cref-oaIter_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaParasiticNetwork",
    sizeof(PyoaIter_oaParasiticNetworkObject),
    0,
    (destructor)oaIter_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaParasiticNetwork_tp_repr,	/* tp_repr */
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
    oaIter_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaParasiticNetwork_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaParasiticNetwork_iternext,	/* tp_iternext */
    oaIter_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaParasiticNetwork",
           (PyObject*)(&PyoaIter_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaParasiticNetwork\n");
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
// Wrapper Implementation for Class: oaIter_oaPin
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPin_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaPin_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaPinObject* self = (PyoaIter_oaPinObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPin(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaPin)
    {
        PyParamoaIter_oaPin p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaPin_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPin(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaPin, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaPin)\n"
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
oaIter_oaPin_tp_dealloc(PyoaIter_oaPinObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaPin*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPin_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaPin value;
    int convert_status=PyoaIter_oaPin_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaIter_oaPin::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaPin_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaPin v1;
    PyParamoaIter_oaPin v2;
    int convert_status1=PyoaIter_oaPin_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaPin_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaPin_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPin_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaPin ob;
    int convert_status=PyoaIter_oaPin_Convert(self,&ob);
    assert(convert_status!=0);
    oaPin* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaPin_FromoaPin(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaPin_Convert(PyObject* ob,PyParamoaIter_oaPin* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaPin_Check(ob)) {
        result->SetData( (oaIter_oaPin*) ((PyoaIter_oaPinObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaPin Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaPin_FromoaIter_oaPin(oaIter_oaPin* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaPin_Type.tp_alloc(&PyoaIter_oaPin_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaPinObject* self = (PyoaIter_oaPinObject*)bself;
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
static char oaIter_oaPin_getNext_doc[] = 
"Class: oaIter_oaPin, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaPin* getNext()\n"
"    Signature: getNext|ptr-oaPin|\n"
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
oaIter_oaPin_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPin data;
    int convert_status=PyoaIter_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPinObject* self=(PyoaIter_oaPinObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPinp result= (data.DataCall()->getNext());
        return PyoaPin_FromoaPin(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaPin_next_doc[] = 
"Class: oaIter_oaPin, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaPin* next()\n"
"    Signature: next|ptr-oaPin|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaPin_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPin data;
    int convert_status=PyoaIter_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPinObject* self=(PyoaIter_oaPinObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPinp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaPin_FromoaPin(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaPin_assign_doc[] = 
"Class: oaIter_oaPin, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaPin_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaPin data;
  int convert_status=PyoaIter_oaPin_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaPin p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaPin_Convert,&p1)) {
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

static PyMethodDef oaIter_oaPin_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaPin_getNext,METH_VARARGS,oaIter_oaPin_getNext_doc},
    {"next",(PyCFunction)oaIter_oaPin_next,METH_VARARGS,oaIter_oaPin_next_doc},
    {"assign",(PyCFunction)oaIter_oaPin_tp_assign,METH_VARARGS,oaIter_oaPin_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaPin_doc[] = 
"Class: oaIter_oaPin\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaPin(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaPin||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaPin)\n"
"    Calls: oaIter_oaPin(const oaIter_oaPin& iterIn)\n"
"    Signature: oaIter_oaPin||cref-oaIter_oaPin,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaPin)\n"
"    Calls: (const oaIter_oaPin&)\n"
"    Signature: oaIter_oaPin||cref-oaIter_oaPin,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaPin_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaPin",
    sizeof(PyoaIter_oaPinObject),
    0,
    (destructor)oaIter_oaPin_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaPin_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaPin_tp_repr,	/* tp_repr */
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
    oaIter_oaPin_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaPin_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaPin_iternext,	/* tp_iternext */
    oaIter_oaPin_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaPin_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaPin_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaPin_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaPin\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaPin",
           (PyObject*)(&PyoaIter_oaPin_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaPin\n");
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
// Wrapper Implementation for Class: oaIter_oaPinFig
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPinFig_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaPinFig_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaPinFigObject* self = (PyoaIter_oaPinFigObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPinFig_oaPin)
    {
        PyParamoaCollection_oaPinFig_oaPin p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPinFig_oaPin_Convert,&p1)) {
            self->value =  new oaIter_oaPinFig(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaPinFig)
    {
        PyParamoaIter_oaPinFig p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaPinFig_Convert,&p1)) {
            self->value =  new oaIter_oaPinFig(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaPinFig, Choices are:\n"
        "    (oaCollection_oaPinFig_oaPin)\n"
        "    (oaIter_oaPinFig)\n"
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
oaIter_oaPinFig_tp_dealloc(PyoaIter_oaPinFigObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPinFig_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaPinFig value;
    int convert_status=PyoaIter_oaPinFig_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaIter_oaPinFig::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaPinFig_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaPinFig v1;
    PyParamoaIter_oaPinFig v2;
    int convert_status1=PyoaIter_oaPinFig_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaPinFig_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaPinFig_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPinFig_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaPinFig ob;
    int convert_status=PyoaIter_oaPinFig_Convert(self,&ob);
    assert(convert_status!=0);
    oaPinFig* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaPinFig_FromoaPinFig(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaPinFig_Convert(PyObject* ob,PyParamoaIter_oaPinFig* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaPinFig_Check(ob)) {
        result->SetData(  ((PyoaIter_oaPinFigObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaPinFig Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaPinFig_FromoaIter_oaPinFig(oaIter_oaPinFig* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaPinFig_Type.tp_alloc(&PyoaIter_oaPinFig_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaPinFigObject* self = (PyoaIter_oaPinFigObject*)bself;
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
static char oaIter_oaPinFig_getNext_doc[] = 
"Class: oaIter_oaPinFig, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaPinFig* getNext()\n"
"    Signature: getNext|ptr-oaPinFig|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaPinFig_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPinFig data;
    int convert_status=PyoaIter_oaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPinFigObject* self=(PyoaIter_oaPinFigObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPinFigp result= (data.DataCall()->getNext());
        return PyoaPinFig_FromoaPinFig(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaPinFig_next_doc[] = 
"Class: oaIter_oaPinFig, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaPinFig* next()\n"
"    Signature: next|ptr-oaPinFig|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaPinFig_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPinFig data;
    int convert_status=PyoaIter_oaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPinFigObject* self=(PyoaIter_oaPinFigObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPinFigp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaPinFig_FromoaPinFig(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaPinFig_reset_doc[] = 
"Class: oaIter_oaPinFig, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaPinFig_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPinFig data;
    int convert_status=PyoaIter_oaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPinFigObject* self=(PyoaIter_oaPinFigObject*)ob;

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

static char oaIter_oaPinFig_assign_doc[] = 
"Class: oaIter_oaPinFig, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaPinFig_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaPinFig data;
  int convert_status=PyoaIter_oaPinFig_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaPinFig p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaPinFig_Convert,&p1)) {
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

static PyMethodDef oaIter_oaPinFig_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaPinFig_getNext,METH_VARARGS,oaIter_oaPinFig_getNext_doc},
    {"next",(PyCFunction)oaIter_oaPinFig_next,METH_VARARGS,oaIter_oaPinFig_next_doc},
    {"reset",(PyCFunction)oaIter_oaPinFig_reset,METH_VARARGS,oaIter_oaPinFig_reset_doc},
    {"assign",(PyCFunction)oaIter_oaPinFig_tp_assign,METH_VARARGS,oaIter_oaPinFig_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaPinFig_doc[] = 
"Class: oaIter_oaPinFig\n"
"  Class type oaIter_oaPinFig\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaPinFig_oaPin)\n"
"    Calls: oaIter_oaPinFig(const oaCollection_oaPinFig_oaPin& cl)\n"
"    Signature: oaIter_oaPinFig||cref-oaCollection_oaPinFig_oaPin,\n"
"    Constructor oaIter_oaPinFig\n"
"  Paramegers: (oaIter_oaPinFig)\n"
"    Calls: oaIter_oaPinFig(const oaIter_oaPinFig& iterIn)\n"
"    Signature: oaIter_oaPinFig||cref-oaIter_oaPinFig,\n"
"    Constructor oaIter_oaPinFig\n"
"  Paramegers: (oaIter_oaPinFig)\n"
"    Calls: (const oaIter_oaPinFig&)\n"
"    Signature: oaIter_oaPinFig||cref-oaIter_oaPinFig,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaPinFig_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaPinFig",
    sizeof(PyoaIter_oaPinFigObject),
    0,
    (destructor)oaIter_oaPinFig_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaPinFig_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaPinFig_tp_repr,	/* tp_repr */
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
    oaIter_oaPinFig_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaPinFig_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaPinFig_iternext,	/* tp_iternext */
    oaIter_oaPinFig_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaPinFig_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaPinFig_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaPinFig_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaPinFig\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaPinFig",
           (PyObject*)(&PyoaIter_oaPinFig_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaPinFig\n");
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
// Wrapper Implementation for Class: oaIter_oaPoleResidue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPoleResidue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaPoleResidue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaPoleResidueObject* self = (PyoaIter_oaPoleResidueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPoleResidue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaPoleResidue)
    {
        PyParamoaIter_oaPoleResidue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaPoleResidue_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPoleResidue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaPoleResidue, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaPoleResidue)\n"
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
oaIter_oaPoleResidue_tp_dealloc(PyoaIter_oaPoleResidueObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaPoleResidue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPoleResidue_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaPoleResidue value;
    int convert_status=PyoaIter_oaPoleResidue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaIter_oaPoleResidue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaPoleResidue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaPoleResidue v1;
    PyParamoaIter_oaPoleResidue v2;
    int convert_status1=PyoaIter_oaPoleResidue_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaPoleResidue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaPoleResidue_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPoleResidue_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaPoleResidue ob;
    int convert_status=PyoaIter_oaPoleResidue_Convert(self,&ob);
    assert(convert_status!=0);
    oaPoleResidue* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaPoleResidue_FromoaPoleResidue(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaPoleResidue_Convert(PyObject* ob,PyParamoaIter_oaPoleResidue* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaPoleResidue_Check(ob)) {
        result->SetData( (oaIter_oaPoleResidue*) ((PyoaIter_oaPoleResidueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaPoleResidue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaPoleResidue_FromoaIter_oaPoleResidue(oaIter_oaPoleResidue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaPoleResidue_Type.tp_alloc(&PyoaIter_oaPoleResidue_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaPoleResidueObject* self = (PyoaIter_oaPoleResidueObject*)bself;
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
static char oaIter_oaPoleResidue_getNext_doc[] = 
"Class: oaIter_oaPoleResidue, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaPoleResidue* getNext()\n"
"    Signature: getNext|ptr-oaPoleResidue|\n"
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
oaIter_oaPoleResidue_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPoleResidue data;
    int convert_status=PyoaIter_oaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPoleResidueObject* self=(PyoaIter_oaPoleResidueObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPoleResiduep result= (data.DataCall()->getNext());
        return PyoaPoleResidue_FromoaPoleResidue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaPoleResidue_next_doc[] = 
"Class: oaIter_oaPoleResidue, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaPoleResidue* next()\n"
"    Signature: next|ptr-oaPoleResidue|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaPoleResidue_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPoleResidue data;
    int convert_status=PyoaIter_oaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPoleResidueObject* self=(PyoaIter_oaPoleResidueObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPoleResiduep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaPoleResidue_FromoaPoleResidue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaPoleResidue_assign_doc[] = 
"Class: oaIter_oaPoleResidue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaPoleResidue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaPoleResidue data;
  int convert_status=PyoaIter_oaPoleResidue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaPoleResidue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaPoleResidue_Convert,&p1)) {
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

static PyMethodDef oaIter_oaPoleResidue_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaPoleResidue_getNext,METH_VARARGS,oaIter_oaPoleResidue_getNext_doc},
    {"next",(PyCFunction)oaIter_oaPoleResidue_next,METH_VARARGS,oaIter_oaPoleResidue_next_doc},
    {"assign",(PyCFunction)oaIter_oaPoleResidue_tp_assign,METH_VARARGS,oaIter_oaPoleResidue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaPoleResidue_doc[] = 
"Class: oaIter_oaPoleResidue\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaPoleResidue(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaPoleResidue||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaPoleResidue)\n"
"    Calls: oaIter_oaPoleResidue(const oaIter_oaPoleResidue& iterIn)\n"
"    Signature: oaIter_oaPoleResidue||cref-oaIter_oaPoleResidue,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaPoleResidue)\n"
"    Calls: (const oaIter_oaPoleResidue&)\n"
"    Signature: oaIter_oaPoleResidue||cref-oaIter_oaPoleResidue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaPoleResidue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaPoleResidue",
    sizeof(PyoaIter_oaPoleResidueObject),
    0,
    (destructor)oaIter_oaPoleResidue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaPoleResidue_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaPoleResidue_tp_repr,	/* tp_repr */
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
    oaIter_oaPoleResidue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaPoleResidue_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaPoleResidue_iternext,	/* tp_iternext */
    oaIter_oaPoleResidue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaPoleResidue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaPoleResidue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaPoleResidue_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaPoleResidue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaPoleResidue",
           (PyObject*)(&PyoaIter_oaPoleResidue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaPoleResidue\n");
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
// Wrapper Implementation for Class: oaIter_oaProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaPropObject* self = (PyoaIter_oaPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaProp_oaObject)
    {
        PyParamoaCollection_oaProp_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaProp_oaObject_Convert,&p1)) {
            self->value =  new oaIter_oaProp(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaProp)
    {
        PyParamoaIter_oaProp p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaProp_Convert,&p1)) {
            self->value =  new oaIter_oaProp(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaProp, Choices are:\n"
        "    (oaCollection_oaProp_oaObject)\n"
        "    (oaIter_oaProp)\n"
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
oaIter_oaProp_tp_dealloc(PyoaIter_oaPropObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaProp_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaProp value;
    int convert_status=PyoaIter_oaProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaIter_oaProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaProp v1;
    PyParamoaIter_oaProp v2;
    int convert_status1=PyoaIter_oaProp_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaProp_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaProp_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaProp ob;
    int convert_status=PyoaIter_oaProp_Convert(self,&ob);
    assert(convert_status!=0);
    oaProp* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaProp_FromoaProp(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaProp_Convert(PyObject* ob,PyParamoaIter_oaProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaProp_Check(ob)) {
        result->SetData(  ((PyoaIter_oaPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaProp_FromoaIter_oaProp(oaIter_oaProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaProp_Type.tp_alloc(&PyoaIter_oaProp_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaPropObject* self = (PyoaIter_oaPropObject*)bself;
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
static char oaIter_oaProp_getNext_doc[] = 
"Class: oaIter_oaProp, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaProp* getNext()\n"
"    Signature: getNext|ptr-oaProp|\n"
"    BrowseData: 1\n"
"    Function getNext\n"
;

static PyObject*
oaIter_oaProp_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaProp data;
    int convert_status=PyoaIter_oaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPropObject* self=(PyoaIter_oaPropObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPropp result= (data.DataCall()->getNext());
        return PyoaProp_FromoaProp(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaProp_next_doc[] = 
"Class: oaIter_oaProp, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaProp* next()\n"
"    Signature: next|ptr-oaProp|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaProp_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaProp data;
    int convert_status=PyoaIter_oaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPropObject* self=(PyoaIter_oaPropObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPropp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaProp_FromoaProp(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaProp_reset_doc[] = 
"Class: oaIter_oaProp, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaIter_oaProp_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaProp data;
    int convert_status=PyoaIter_oaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPropObject* self=(PyoaIter_oaPropObject*)ob;

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

static char oaIter_oaProp_assign_doc[] = 
"Class: oaIter_oaProp, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaProp_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaProp data;
  int convert_status=PyoaIter_oaProp_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaProp p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaProp_Convert,&p1)) {
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

static PyMethodDef oaIter_oaProp_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaProp_getNext,METH_VARARGS,oaIter_oaProp_getNext_doc},
    {"next",(PyCFunction)oaIter_oaProp_next,METH_VARARGS,oaIter_oaProp_next_doc},
    {"reset",(PyCFunction)oaIter_oaProp_reset,METH_VARARGS,oaIter_oaProp_reset_doc},
    {"assign",(PyCFunction)oaIter_oaProp_tp_assign,METH_VARARGS,oaIter_oaProp_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaProp_doc[] = 
"Class: oaIter_oaProp\n"
"  Class type oaIter_oaProp\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaProp_oaObject)\n"
"    Calls: oaIter_oaProp(const oaCollection_oaProp_oaObject& c)\n"
"    Signature: oaIter_oaProp||cref-oaCollection_oaProp_oaObject,\n"
"    Constructor oaIter_oaProp\n"
"  Paramegers: (oaIter_oaProp)\n"
"    Calls: oaIter_oaProp(const oaIter_oaProp& iterIn)\n"
"    Signature: oaIter_oaProp||cref-oaIter_oaProp,\n"
"    Constructor oaIter_oaProp\n"
"  Paramegers: (oaIter_oaProp)\n"
"    Calls: (const oaIter_oaProp&)\n"
"    Signature: oaIter_oaProp||cref-oaIter_oaProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaProp",
    sizeof(PyoaIter_oaPropObject),
    0,
    (destructor)oaIter_oaProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaProp_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaProp_tp_repr,	/* tp_repr */
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
    oaIter_oaProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaProp_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaProp_iternext,	/* tp_iternext */
    oaIter_oaProp_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaProp_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaProp",
           (PyObject*)(&PyoaIter_oaProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaProp\n");
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
// Wrapper Implementation for Class: oaIter_oaPurpose
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPurpose_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaPurpose_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaPurposeObject* self = (PyoaIter_oaPurposeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPurpose(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaPurpose)
    {
        PyParamoaIter_oaPurpose p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaPurpose_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaPurpose(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaPurpose, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaPurpose)\n"
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
oaIter_oaPurpose_tp_dealloc(PyoaIter_oaPurposeObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaPurpose*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPurpose_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaPurpose value;
    int convert_status=PyoaIter_oaPurpose_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaPurpose::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaPurpose_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaPurpose v1;
    PyParamoaIter_oaPurpose v2;
    int convert_status1=PyoaIter_oaPurpose_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaPurpose_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaPurpose_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaPurpose_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaPurpose ob;
    int convert_status=PyoaIter_oaPurpose_Convert(self,&ob);
    assert(convert_status!=0);
    oaPurpose* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaPurpose_FromoaPurpose(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaPurpose_Convert(PyObject* ob,PyParamoaIter_oaPurpose* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaPurpose_Check(ob)) {
        result->SetData( (oaIter_oaPurpose*) ((PyoaIter_oaPurposeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaPurpose Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaPurpose_FromoaIter_oaPurpose(oaIter_oaPurpose* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaPurpose_Type.tp_alloc(&PyoaIter_oaPurpose_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaPurposeObject* self = (PyoaIter_oaPurposeObject*)bself;
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
static char oaIter_oaPurpose_getNext_doc[] = 
"Class: oaIter_oaPurpose, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaPurpose* getNext()\n"
"    Signature: getNext|ptr-oaPurpose|\n"
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
oaIter_oaPurpose_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPurpose data;
    int convert_status=PyoaIter_oaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPurposeObject* self=(PyoaIter_oaPurposeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposep result= (data.DataCall()->getNext());
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
static char oaIter_oaPurpose_next_doc[] = 
"Class: oaIter_oaPurpose, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaPurpose* next()\n"
"    Signature: next|ptr-oaPurpose|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaPurpose_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaPurpose data;
    int convert_status=PyoaIter_oaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaPurposeObject* self=(PyoaIter_oaPurposeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaPurpose_FromoaPurpose(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaPurpose_assign_doc[] = 
"Class: oaIter_oaPurpose, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaPurpose_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaPurpose data;
  int convert_status=PyoaIter_oaPurpose_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaPurpose p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaPurpose_Convert,&p1)) {
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

static PyMethodDef oaIter_oaPurpose_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaPurpose_getNext,METH_VARARGS,oaIter_oaPurpose_getNext_doc},
    {"next",(PyCFunction)oaIter_oaPurpose_next,METH_VARARGS,oaIter_oaPurpose_next_doc},
    {"assign",(PyCFunction)oaIter_oaPurpose_tp_assign,METH_VARARGS,oaIter_oaPurpose_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaPurpose_doc[] = 
"Class: oaIter_oaPurpose\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaPurpose(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaPurpose||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaPurpose)\n"
"    Calls: oaIter_oaPurpose(const oaIter_oaPurpose& iterIn)\n"
"    Signature: oaIter_oaPurpose||cref-oaIter_oaPurpose,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaPurpose)\n"
"    Calls: (const oaIter_oaPurpose&)\n"
"    Signature: oaIter_oaPurpose||cref-oaIter_oaPurpose,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaPurpose_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaPurpose",
    sizeof(PyoaIter_oaPurposeObject),
    0,
    (destructor)oaIter_oaPurpose_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaPurpose_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaPurpose_tp_repr,	/* tp_repr */
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
    oaIter_oaPurpose_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaPurpose_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaPurpose_iternext,	/* tp_iternext */
    oaIter_oaPurpose_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaPurpose_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaPurpose_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaPurpose_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaPurpose\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaPurpose",
           (PyObject*)(&PyoaIter_oaPurpose_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaPurpose\n");
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
// Wrapper Implementation for Class: oaIter_oaReticle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaReticle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaReticleObject* self = (PyoaIter_oaReticleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaReticle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaReticle)
    {
        PyParamoaIter_oaReticle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaReticle_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaReticle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaReticle, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaReticle)\n"
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
oaIter_oaReticle_tp_dealloc(PyoaIter_oaReticleObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaReticle*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticle_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaReticle value;
    int convert_status=PyoaIter_oaReticle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaIter_oaReticle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaReticle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaReticle v1;
    PyParamoaIter_oaReticle v2;
    int convert_status1=PyoaIter_oaReticle_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaReticle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticle_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticle_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaReticle ob;
    int convert_status=PyoaIter_oaReticle_Convert(self,&ob);
    assert(convert_status!=0);
    oaReticle* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaReticle_FromoaReticle(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaReticle_Convert(PyObject* ob,PyParamoaIter_oaReticle* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaReticle_Check(ob)) {
        result->SetData( (oaIter_oaReticle*) ((PyoaIter_oaReticleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaReticle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaReticle_FromoaIter_oaReticle(oaIter_oaReticle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaReticle_Type.tp_alloc(&PyoaIter_oaReticle_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaReticleObject* self = (PyoaIter_oaReticleObject*)bself;
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
static char oaIter_oaReticle_getNext_doc[] = 
"Class: oaIter_oaReticle, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaReticle* getNext()\n"
"    Signature: getNext|ptr-oaReticle|\n"
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
oaIter_oaReticle_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaReticle data;
    int convert_status=PyoaIter_oaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaReticleObject* self=(PyoaIter_oaReticleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReticlep result= (data.DataCall()->getNext());
        return PyoaReticle_FromoaReticle(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaReticle_next_doc[] = 
"Class: oaIter_oaReticle, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaReticle* next()\n"
"    Signature: next|ptr-oaReticle|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaReticle_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaReticle data;
    int convert_status=PyoaIter_oaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaReticleObject* self=(PyoaIter_oaReticleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReticlep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaReticle_FromoaReticle(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaReticle_assign_doc[] = 
"Class: oaIter_oaReticle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaReticle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaReticle data;
  int convert_status=PyoaIter_oaReticle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaReticle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaReticle_Convert,&p1)) {
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

static PyMethodDef oaIter_oaReticle_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaReticle_getNext,METH_VARARGS,oaIter_oaReticle_getNext_doc},
    {"next",(PyCFunction)oaIter_oaReticle_next,METH_VARARGS,oaIter_oaReticle_next_doc},
    {"assign",(PyCFunction)oaIter_oaReticle_tp_assign,METH_VARARGS,oaIter_oaReticle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaReticle_doc[] = 
"Class: oaIter_oaReticle\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaReticle(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaReticle||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaReticle)\n"
"    Calls: oaIter_oaReticle(const oaIter_oaReticle& iterIn)\n"
"    Signature: oaIter_oaReticle||cref-oaIter_oaReticle,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaReticle)\n"
"    Calls: (const oaIter_oaReticle&)\n"
"    Signature: oaIter_oaReticle||cref-oaIter_oaReticle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaReticle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaReticle",
    sizeof(PyoaIter_oaReticleObject),
    0,
    (destructor)oaIter_oaReticle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaReticle_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaReticle_tp_repr,	/* tp_repr */
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
    oaIter_oaReticle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaReticle_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaReticle_iternext,	/* tp_iternext */
    oaIter_oaReticle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaReticle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaReticle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaReticle_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaReticle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaReticle",
           (PyObject*)(&PyoaIter_oaReticle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaReticle\n");
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
// Wrapper Implementation for Class: oaIter_oaReticleRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticleRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaReticleRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaReticleRefObject* self = (PyoaIter_oaReticleRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaReticleRef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaReticleRef)
    {
        PyParamoaIter_oaReticleRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaReticleRef_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaReticleRef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaReticleRef, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaReticleRef)\n"
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
oaIter_oaReticleRef_tp_dealloc(PyoaIter_oaReticleRefObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaReticleRef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticleRef_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaReticleRef value;
    int convert_status=PyoaIter_oaReticleRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaIter_oaReticleRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaReticleRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaReticleRef v1;
    PyParamoaIter_oaReticleRef v2;
    int convert_status1=PyoaIter_oaReticleRef_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaReticleRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticleRef_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaReticleRef_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaReticleRef ob;
    int convert_status=PyoaIter_oaReticleRef_Convert(self,&ob);
    assert(convert_status!=0);
    oaReticleRef* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaReticleRef_FromoaReticleRef(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaReticleRef_Convert(PyObject* ob,PyParamoaIter_oaReticleRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaReticleRef_Check(ob)) {
        result->SetData( (oaIter_oaReticleRef*) ((PyoaIter_oaReticleRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaReticleRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaReticleRef_FromoaIter_oaReticleRef(oaIter_oaReticleRef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaReticleRef_Type.tp_alloc(&PyoaIter_oaReticleRef_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaReticleRefObject* self = (PyoaIter_oaReticleRefObject*)bself;
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
static char oaIter_oaReticleRef_getNext_doc[] = 
"Class: oaIter_oaReticleRef, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaReticleRef* getNext()\n"
"    Signature: getNext|ptr-oaReticleRef|\n"
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
oaIter_oaReticleRef_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaReticleRef data;
    int convert_status=PyoaIter_oaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaReticleRefObject* self=(PyoaIter_oaReticleRefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReticleRefp result= (data.DataCall()->getNext());
        return PyoaReticleRef_FromoaReticleRef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaReticleRef_next_doc[] = 
"Class: oaIter_oaReticleRef, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaReticleRef* next()\n"
"    Signature: next|ptr-oaReticleRef|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaReticleRef_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaReticleRef data;
    int convert_status=PyoaIter_oaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaReticleRefObject* self=(PyoaIter_oaReticleRefObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReticleRefp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaReticleRef_FromoaReticleRef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaReticleRef_assign_doc[] = 
"Class: oaIter_oaReticleRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaReticleRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaReticleRef data;
  int convert_status=PyoaIter_oaReticleRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaReticleRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaReticleRef_Convert,&p1)) {
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

static PyMethodDef oaIter_oaReticleRef_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaReticleRef_getNext,METH_VARARGS,oaIter_oaReticleRef_getNext_doc},
    {"next",(PyCFunction)oaIter_oaReticleRef_next,METH_VARARGS,oaIter_oaReticleRef_next_doc},
    {"assign",(PyCFunction)oaIter_oaReticleRef_tp_assign,METH_VARARGS,oaIter_oaReticleRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaReticleRef_doc[] = 
"Class: oaIter_oaReticleRef\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaReticleRef(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaReticleRef||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaReticleRef)\n"
"    Calls: oaIter_oaReticleRef(const oaIter_oaReticleRef& iterIn)\n"
"    Signature: oaIter_oaReticleRef||cref-oaIter_oaReticleRef,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaReticleRef)\n"
"    Calls: (const oaIter_oaReticleRef&)\n"
"    Signature: oaIter_oaReticleRef||cref-oaIter_oaReticleRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaReticleRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaReticleRef",
    sizeof(PyoaIter_oaReticleRefObject),
    0,
    (destructor)oaIter_oaReticleRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaReticleRef_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaReticleRef_tp_repr,	/* tp_repr */
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
    oaIter_oaReticleRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaReticleRef_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaReticleRef_iternext,	/* tp_iternext */
    oaIter_oaReticleRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaReticleRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaReticleRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaReticleRef_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaReticleRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaReticleRef",
           (PyObject*)(&PyoaIter_oaReticleRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaReticleRef\n");
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
// Wrapper Implementation for Class: oaIter_oaRoute
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRoute_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaRoute_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaRouteObject* self = (PyoaIter_oaRouteObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRoute(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaRoute)
    {
        PyParamoaIter_oaRoute p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaRoute_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRoute(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaRoute, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaRoute)\n"
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
oaIter_oaRoute_tp_dealloc(PyoaIter_oaRouteObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaRoute*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRoute_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaRoute value;
    int convert_status=PyoaIter_oaRoute_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaIter_oaRoute::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaRoute_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaRoute v1;
    PyParamoaIter_oaRoute v2;
    int convert_status1=PyoaIter_oaRoute_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaRoute_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaRoute_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRoute_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaRoute ob;
    int convert_status=PyoaIter_oaRoute_Convert(self,&ob);
    assert(convert_status!=0);
    oaRoute* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaRoute_FromoaRoute(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaRoute_Convert(PyObject* ob,PyParamoaIter_oaRoute* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaRoute_Check(ob)) {
        result->SetData( (oaIter_oaRoute*) ((PyoaIter_oaRouteObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaRoute Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaRoute_FromoaIter_oaRoute(oaIter_oaRoute* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaRoute_Type.tp_alloc(&PyoaIter_oaRoute_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaRouteObject* self = (PyoaIter_oaRouteObject*)bself;
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
static char oaIter_oaRoute_getNext_doc[] = 
"Class: oaIter_oaRoute, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaRoute* getNext()\n"
"    Signature: getNext|ptr-oaRoute|\n"
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
oaIter_oaRoute_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRoute data;
    int convert_status=PyoaIter_oaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRouteObject* self=(PyoaIter_oaRouteObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRoutep result= (data.DataCall()->getNext());
        return PyoaRoute_FromoaRoute(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaRoute_next_doc[] = 
"Class: oaIter_oaRoute, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaRoute* next()\n"
"    Signature: next|ptr-oaRoute|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaRoute_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRoute data;
    int convert_status=PyoaIter_oaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRouteObject* self=(PyoaIter_oaRouteObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRoutep result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaRoute_FromoaRoute(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaRoute_assign_doc[] = 
"Class: oaIter_oaRoute, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaRoute_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaRoute data;
  int convert_status=PyoaIter_oaRoute_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaRoute p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaRoute_Convert,&p1)) {
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

static PyMethodDef oaIter_oaRoute_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaRoute_getNext,METH_VARARGS,oaIter_oaRoute_getNext_doc},
    {"next",(PyCFunction)oaIter_oaRoute_next,METH_VARARGS,oaIter_oaRoute_next_doc},
    {"assign",(PyCFunction)oaIter_oaRoute_tp_assign,METH_VARARGS,oaIter_oaRoute_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaRoute_doc[] = 
"Class: oaIter_oaRoute\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaRoute(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaRoute||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaRoute)\n"
"    Calls: oaIter_oaRoute(const oaIter_oaRoute& iterIn)\n"
"    Signature: oaIter_oaRoute||cref-oaIter_oaRoute,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaRoute)\n"
"    Calls: (const oaIter_oaRoute&)\n"
"    Signature: oaIter_oaRoute||cref-oaIter_oaRoute,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaRoute_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaRoute",
    sizeof(PyoaIter_oaRouteObject),
    0,
    (destructor)oaIter_oaRoute_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaRoute_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaRoute_tp_repr,	/* tp_repr */
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
    oaIter_oaRoute_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaRoute_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaRoute_iternext,	/* tp_iternext */
    oaIter_oaRoute_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaRoute_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaRoute_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaRoute_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaRoute\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaRoute",
           (PyObject*)(&PyoaIter_oaRoute_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaRoute\n");
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
// Wrapper Implementation for Class: oaIter_oaRow
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRow_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaRow_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaRowObject* self = (PyoaIter_oaRowObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRow(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaRow)
    {
        PyParamoaIter_oaRow p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaRow_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRow(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaRow, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaRow)\n"
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
oaIter_oaRow_tp_dealloc(PyoaIter_oaRowObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaRow*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRow_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaRow value;
    int convert_status=PyoaIter_oaRow_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaIter_oaRow::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaRow_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaRow v1;
    PyParamoaIter_oaRow v2;
    int convert_status1=PyoaIter_oaRow_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaRow_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaRow_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRow_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaRow ob;
    int convert_status=PyoaIter_oaRow_Convert(self,&ob);
    assert(convert_status!=0);
    oaRow* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaRow_FromoaRow(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaRow_Convert(PyObject* ob,PyParamoaIter_oaRow* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaRow_Check(ob)) {
        result->SetData( (oaIter_oaRow*) ((PyoaIter_oaRowObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaRow Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaRow_FromoaIter_oaRow(oaIter_oaRow* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaRow_Type.tp_alloc(&PyoaIter_oaRow_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaRowObject* self = (PyoaIter_oaRowObject*)bself;
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
static char oaIter_oaRow_getNext_doc[] = 
"Class: oaIter_oaRow, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaRow* getNext()\n"
"    Signature: getNext|ptr-oaRow|\n"
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
oaIter_oaRow_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRow data;
    int convert_status=PyoaIter_oaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRowObject* self=(PyoaIter_oaRowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowp result= (data.DataCall()->getNext());
        return PyoaRow_FromoaRow(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaRow_next_doc[] = 
"Class: oaIter_oaRow, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaRow* next()\n"
"    Signature: next|ptr-oaRow|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaRow_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRow data;
    int convert_status=PyoaIter_oaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRowObject* self=(PyoaIter_oaRowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaRow_FromoaRow(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaRow_assign_doc[] = 
"Class: oaIter_oaRow, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaRow_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaRow data;
  int convert_status=PyoaIter_oaRow_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaRow p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaRow_Convert,&p1)) {
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

static PyMethodDef oaIter_oaRow_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaRow_getNext,METH_VARARGS,oaIter_oaRow_getNext_doc},
    {"next",(PyCFunction)oaIter_oaRow_next,METH_VARARGS,oaIter_oaRow_next_doc},
    {"assign",(PyCFunction)oaIter_oaRow_tp_assign,METH_VARARGS,oaIter_oaRow_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaRow_doc[] = 
"Class: oaIter_oaRow\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaRow(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaRow||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaRow)\n"
"    Calls: oaIter_oaRow(const oaIter_oaRow& iterIn)\n"
"    Signature: oaIter_oaRow||cref-oaIter_oaRow,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaRow)\n"
"    Calls: (const oaIter_oaRow&)\n"
"    Signature: oaIter_oaRow||cref-oaIter_oaRow,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaRow_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaRow",
    sizeof(PyoaIter_oaRowObject),
    0,
    (destructor)oaIter_oaRow_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaRow_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaRow_tp_repr,	/* tp_repr */
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
    oaIter_oaRow_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaRow_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaRow_iternext,	/* tp_iternext */
    oaIter_oaRow_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaRow_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaRow_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaRow_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaRow\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaRow",
           (PyObject*)(&PyoaIter_oaRow_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaRow\n");
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
// Wrapper Implementation for Class: oaIter_oaRowHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRowHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaIter_oaRowHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaIter_oaRowHeaderObject* self = (PyoaIter_oaRowHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaBaseCollection)
    {
        PyParamoaBaseCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBaseCollection_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRowHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaIter_oaRowHeader)
    {
        PyParamoaIter_oaRowHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaIter_oaRowHeader_Convert,&p1)) {
            self->value = (oaBaseIter*)  new oaIter_oaRowHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaIter_oaRowHeader, Choices are:\n"
        "    (oaBaseCollection)\n"
        "    (oaIter_oaRowHeader)\n"
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
oaIter_oaRowHeader_tp_dealloc(PyoaIter_oaRowHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaIter_oaRowHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRowHeader_tp_repr(PyObject *ob)
{
    PyParamoaIter_oaRowHeader value;
    int convert_status=PyoaIter_oaRowHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaIter_oaRowHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaIter_oaRowHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaIter_oaRowHeader v1;
    PyParamoaIter_oaRowHeader v2;
    int convert_status1=PyoaIter_oaRowHeader_Convert(ob1,&v1);
    int convert_status2=PyoaIter_oaRowHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaIter_oaRowHeader_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
static PyObject*
oaIter_oaRowHeader_iternext(PyObject *self)
{
  try {
    PyParamoaIter_oaRowHeader ob;
    int convert_status=PyoaIter_oaRowHeader_Convert(self,&ob);
    assert(convert_status!=0);
    oaRowHeader* result;
    result=ob.DataCall()->getNext();
    if (result==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaRowHeader_FromoaRowHeader(result);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
int
PyoaIter_oaRowHeader_Convert(PyObject* ob,PyParamoaIter_oaRowHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaIter_oaRowHeader_Check(ob)) {
        result->SetData( (oaIter_oaRowHeader*) ((PyoaIter_oaRowHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaIter_oaRowHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaIter_oaRowHeader_FromoaIter_oaRowHeader(oaIter_oaRowHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaIter_oaRowHeader_Type.tp_alloc(&PyoaIter_oaRowHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaIter_oaRowHeaderObject* self = (PyoaIter_oaRowHeaderObject*)bself;
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
static char oaIter_oaRowHeader_getNext_doc[] = 
"Class: oaIter_oaRowHeader, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaRowHeader* getNext()\n"
"    Signature: getNext|ptr-oaRowHeader|\n"
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
oaIter_oaRowHeader_getNext(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRowHeader data;
    int convert_status=PyoaIter_oaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRowHeaderObject* self=(PyoaIter_oaRowHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowHeaderp result= (data.DataCall()->getNext());
        return PyoaRowHeader_FromoaRowHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaIter_oaRowHeader_next_doc[] = 
"Class: oaIter_oaRowHeader, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaRowHeader* next()\n"
"    Signature: next|ptr-oaRowHeader|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

static PyObject*
oaIter_oaRowHeader_next(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaIter_oaRowHeader data;
    int convert_status=PyoaIter_oaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaIter_oaRowHeaderObject* self=(PyoaIter_oaRowHeaderObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowHeaderp result= (data.DataCall()->getNext());
        if (result==NULL) {
            PyErr_SetObject(PyExc_StopIteration,Py_None);
            return NULL;
        }
        return PyoaRowHeader_FromoaRowHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaIter_oaRowHeader_assign_doc[] = 
"Class: oaIter_oaRowHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaIter_oaRowHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaIter_oaRowHeader data;
  int convert_status=PyoaIter_oaRowHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaIter_oaRowHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaIter_oaRowHeader_Convert,&p1)) {
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

static PyMethodDef oaIter_oaRowHeader_methodlist[] = {
    {"getNext",(PyCFunction)oaIter_oaRowHeader_getNext,METH_VARARGS,oaIter_oaRowHeader_getNext_doc},
    {"next",(PyCFunction)oaIter_oaRowHeader_next,METH_VARARGS,oaIter_oaRowHeader_next_doc},
    {"assign",(PyCFunction)oaIter_oaRowHeader_tp_assign,METH_VARARGS,oaIter_oaRowHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaIter_oaRowHeader_doc[] = 
"Class: oaIter_oaRowHeader\n"
"  The oaIter class is used to iterate over the objects in an oaCollection . oaCollections are used wherever the database needs to return multiple objects in some relationship to a single starting object. The oaIter class allows the caller to return one object in the collection at a time and to test when all the objects are returned.\n"
"  The intended usage of the oaIter class is shown in the following example:\n"
"  oaIter<oaShape> sIter(view->getShapes()); oaShape *myshape; while (myshape = sIter.getNext()) { ... }\n"
"  Note that some collections use special case iterators that do not belong to the oaIter class. This happens where the getNext() function has a different signature.\n"
"Constructors:\n"
"  Paramegers: (oaBaseCollection)\n"
"    Calls: oaIter_oaRowHeader(const oaBaseCollection& coll)\n"
"    Signature: oaIter_oaRowHeader||cref-oaBaseCollection,\n"
"    This function constructs an oaIter object that is associated with the specified oaBaseCollection coll .\n"
"  Paramegers: (oaIter_oaRowHeader)\n"
"    Calls: oaIter_oaRowHeader(const oaIter_oaRowHeader& iterIn)\n"
"    Signature: oaIter_oaRowHeader||cref-oaIter_oaRowHeader,\n"
"    This function constructs an oaIter object that iterates over the same set of objects as the specified iterator iterIn .\n"
"    Note: When an iterator is copied, the new copy retains the state of the original. For example, if the original iterator is in the middle of a collection at the time of the copy, the new copy of the iterator will be at middle of the collection. In other words, this copy constructor function does not reset the iterator to point to the beginning of the collection.\n"
"  Paramegers: (oaIter_oaRowHeader)\n"
"    Calls: (const oaIter_oaRowHeader&)\n"
"    Signature: oaIter_oaRowHeader||cref-oaIter_oaRowHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaIter_oaRowHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaIter_oaRowHeader",
    sizeof(PyoaIter_oaRowHeaderObject),
    0,
    (destructor)oaIter_oaRowHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaIter_oaRowHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaIter_oaRowHeader_tp_repr,	/* tp_repr */
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
    oaIter_oaRowHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaIter_oaRowHeader_getiter,	/* tp_iter */
    (iternextfunc)oaIter_oaRowHeader_iternext,	/* tp_iternext */
    oaIter_oaRowHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaIter_oaRowHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaIter_oaRowHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaIter_oaRowHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaIter_oaRowHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaIter_oaRowHeader",
           (PyObject*)(&PyoaIter_oaRowHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaIter_oaRowHeader\n");
       return -1;
    }
    return 0;
}

