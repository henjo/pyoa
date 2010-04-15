
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
// Wrapper Implementation for Class: oaCollection_oaPoleResidue_oaPiPoleResidue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPoleResidue_oaPiPoleResidue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPoleResidue_oaPiPoleResidueObject* self = (PyoaCollection_oaPoleResidue_oaPiPoleResidueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPoleResidue_oaPiPoleResidue)
    {
        PyParamoaCollection_oaPoleResidue_oaPiPoleResidue p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaPoleResidue_oaPiPoleResidue(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPoleResidue_oaPiPoleResidue, Choices are:\n"
        "    (oaCollection_oaPoleResidue_oaPiPoleResidue)\n"
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
oaCollection_oaPoleResidue_oaPiPoleResidue_tp_dealloc(PyoaCollection_oaPoleResidue_oaPiPoleResidueObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaPoleResidue_oaPiPoleResidue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPoleResidue_oaPiPoleResidue_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPoleResidue_oaPiPoleResidue value;
    int convert_status=PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[64];
    sprintf(buffer,"<oaCollection_oaPoleResidue_oaPiPoleResidue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPoleResidue_oaPiPoleResidue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPoleResidue_oaPiPoleResidue v1;
    PyParamoaCollection_oaPoleResidue_oaPiPoleResidue v2;
    int convert_status1=PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(PyObject* ob,PyParamoaCollection_oaPoleResidue_oaPiPoleResidue* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPoleResidue_oaPiPoleResidue_Check(ob)) {
        result->SetData( (oaCollection_oaPoleResidue_oaPiPoleResidue*) ((PyoaCollection_oaPoleResidue_oaPiPoleResidueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPoleResidue_oaPiPoleResidue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPoleResidue_oaPiPoleResidue_FromoaCollection_oaPoleResidue_oaPiPoleResidue(oaCollection_oaPoleResidue_oaPiPoleResidue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type.tp_alloc(&PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPoleResidue_oaPiPoleResidueObject* self = (PyoaCollection_oaPoleResidue_oaPiPoleResidueObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaPoleResidue_oaPiPoleResidue_includes_doc[] = 
"Class: oaCollection_oaPoleResidue_oaPiPoleResidue, Function: includes\n"
"  Paramegers: (oaPoleResidue)\n"
"    Calls: oaBoolean includes(const oaPoleResidue* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaPoleResidue,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaPoleResidue_oaPiPoleResidue_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPoleResidue_oaPiPoleResidue data;
    int convert_status=PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPoleResidue_oaPiPoleResidueObject* self=(PyoaCollection_oaPoleResidue_oaPiPoleResidueObject*)ob;

    PyParamoaPoleResidue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoleResidue_Convert,&p1)) {
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

static char oaCollection_oaPoleResidue_oaPiPoleResidue_assign_doc[] = 
"Class: oaCollection_oaPoleResidue_oaPiPoleResidue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPoleResidue_oaPiPoleResidue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPoleResidue_oaPiPoleResidue data;
  int convert_status=PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPoleResidue_oaPiPoleResidue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPoleResidue_oaPiPoleResidue_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaPoleResidue_oaPiPoleResidue_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaPoleResidue_oaPiPoleResidue_includes,METH_VARARGS,oaCollection_oaPoleResidue_oaPiPoleResidue_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaPoleResidue_oaPiPoleResidue_tp_assign,METH_VARARGS,oaCollection_oaPoleResidue_oaPiPoleResidue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPoleResidue_oaPiPoleResidue_doc[] = 
"Class: oaCollection_oaPoleResidue_oaPiPoleResidue\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaPoleResidue_oaPiPoleResidue)\n"
"    Calls: oaCollection_oaPoleResidue_oaPiPoleResidue(const oaCollection_oaPoleResidue_oaPiPoleResidue& coll)\n"
"    Signature: oaCollection_oaPoleResidue_oaPiPoleResidue||cref-oaCollection_oaPoleResidue_oaPiPoleResidue,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaPoleResidue_oaPiPoleResidue)\n"
"    Calls: (const oaCollection_oaPoleResidue_oaPiPoleResidue&)\n"
"    Signature: oaCollection_oaPoleResidue_oaPiPoleResidue||cref-oaCollection_oaPoleResidue_oaPiPoleResidue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPoleResidue_oaPiPoleResidue",
    sizeof(PyoaCollection_oaPoleResidue_oaPiPoleResidueObject),
    0,
    (destructor)oaCollection_oaPoleResidue_oaPiPoleResidue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPoleResidue_oaPiPoleResidue_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPoleResidue_oaPiPoleResidue_tp_repr,	/* tp_repr */
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
    oaCollection_oaPoleResidue_oaPiPoleResidue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPoleResidue_oaPiPoleResidue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPoleResidue_oaPiPoleResidue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPoleResidue_oaPiPoleResidue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPoleResidue_oaPiPoleResidue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPoleResidue_oaPiPoleResidue",
           (PyObject*)(&PyoaCollection_oaPoleResidue_oaPiPoleResidue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPoleResidue_oaPiPoleResidue\n");
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
// Wrapper Implementation for Class: oaCollection_oaProp_oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaProp_oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaProp_oaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaProp_oaObjectObject* self = (PyoaCollection_oaProp_oaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaProp_oaObject)
    {
        PyParamoaCollection_oaProp_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaProp_oaObject_Convert,&p1)) {
            self->value =  new oaCollection_oaProp_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaProp_oaObject, Choices are:\n"
        "    (oaCollection_oaProp_oaObject)\n"
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
oaCollection_oaProp_oaObject_tp_dealloc(PyoaCollection_oaProp_oaObjectObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaProp_oaObject_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaProp_oaObject value;
    int convert_status=PyoaCollection_oaProp_oaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaProp_oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaProp_oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaProp_oaObject v1;
    PyParamoaCollection_oaProp_oaObject v2;
    int convert_status1=PyoaCollection_oaProp_oaObject_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaProp_oaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaProp_oaObject_Convert(PyObject* ob,PyParamoaCollection_oaProp_oaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaProp_oaObject_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaProp_oaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaProp_oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaProp_oaObject_FromoaCollection_oaProp_oaObject(oaCollection_oaProp_oaObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaProp_oaObject_Type.tp_alloc(&PyoaCollection_oaProp_oaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaProp_oaObjectObject* self = (PyoaCollection_oaProp_oaObjectObject*)bself;
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
static char oaCollection_oaProp_oaObject_getCount_doc[] = 
"Class: oaCollection_oaProp_oaObject, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaProp_oaObject_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaProp_oaObject data;
    int convert_status=PyoaCollection_oaProp_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaProp_oaObjectObject* self=(PyoaCollection_oaProp_oaObjectObject*)ob;

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
static char oaCollection_oaProp_oaObject_includes_doc[] = 
"Class: oaCollection_oaProp_oaObject, Function: includes\n"
"  Paramegers: (oaProp)\n"
"    Calls: oaBoolean includes(const oaProp* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaProp,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaProp_oaObject_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaProp_oaObject data;
    int convert_status=PyoaCollection_oaProp_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaProp_oaObjectObject* self=(PyoaCollection_oaProp_oaObjectObject*)ob;

    PyParamoaProp p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaProp_Convert,&p1)) {
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
static char oaCollection_oaProp_oaObject_isEmpty_doc[] = 
"Class: oaCollection_oaProp_oaObject, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaProp_oaObject_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaProp_oaObject data;
    int convert_status=PyoaCollection_oaProp_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaProp_oaObjectObject* self=(PyoaCollection_oaProp_oaObjectObject*)ob;

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

static char oaCollection_oaProp_oaObject_assign_doc[] = 
"Class: oaCollection_oaProp_oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaProp_oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaProp_oaObject data;
  int convert_status=PyoaCollection_oaProp_oaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaProp_oaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaProp_oaObject_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaProp_oaObject_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaProp_oaObject_getCount,METH_VARARGS,oaCollection_oaProp_oaObject_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaProp_oaObject_includes,METH_VARARGS,oaCollection_oaProp_oaObject_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaProp_oaObject_isEmpty,METH_VARARGS,oaCollection_oaProp_oaObject_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaProp_oaObject_tp_assign,METH_VARARGS,oaCollection_oaProp_oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaProp_oaObject_doc[] = 
"Class: oaCollection_oaProp_oaObject\n"
"  Class type oaCollection_oaProp_oaObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaProp_oaObject)\n"
"    Calls: oaCollection_oaProp_oaObject(const oaCollection_oaProp_oaObject& c)\n"
"    Signature: oaCollection_oaProp_oaObject||cref-oaCollection_oaProp_oaObject,\n"
"    Constructor oaCollection_oaProp_oaObject\n"
"  Paramegers: (oaCollection_oaProp_oaObject)\n"
"    Calls: (const oaCollection_oaProp_oaObject&)\n"
"    Signature: oaCollection_oaProp_oaObject||cref-oaCollection_oaProp_oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaProp_oaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaProp_oaObject",
    sizeof(PyoaCollection_oaProp_oaObjectObject),
    0,
    (destructor)oaCollection_oaProp_oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaProp_oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaProp_oaObject_tp_repr,	/* tp_repr */
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
    oaCollection_oaProp_oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaProp_oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaProp_oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaProp_oaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaProp_oaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaProp_oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaProp_oaObject",
           (PyObject*)(&PyoaCollection_oaProp_oaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaProp_oaObject\n");
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
// Wrapper Implementation for Class: oaCollection_oaPurpose_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPurpose_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPurpose_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPurpose_oaTechObject* self = (PyoaCollection_oaPurpose_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPurpose_oaTech)
    {
        PyParamoaCollection_oaPurpose_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPurpose_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaPurpose_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPurpose_oaTech, Choices are:\n"
        "    (oaCollection_oaPurpose_oaTech)\n"
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
oaCollection_oaPurpose_oaTech_tp_dealloc(PyoaCollection_oaPurpose_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaPurpose_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPurpose_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPurpose_oaTech value;
    int convert_status=PyoaCollection_oaPurpose_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaPurpose_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPurpose_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPurpose_oaTech v1;
    PyParamoaCollection_oaPurpose_oaTech v2;
    int convert_status1=PyoaCollection_oaPurpose_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPurpose_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPurpose_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaPurpose_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPurpose_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaPurpose_oaTech*) ((PyoaCollection_oaPurpose_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPurpose_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPurpose_oaTech_FromoaCollection_oaPurpose_oaTech(oaCollection_oaPurpose_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPurpose_oaTech_Type.tp_alloc(&PyoaCollection_oaPurpose_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPurpose_oaTechObject* self = (PyoaCollection_oaPurpose_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaPurpose_oaTech_includes_doc[] = 
"Class: oaCollection_oaPurpose_oaTech, Function: includes\n"
"  Paramegers: (oaPurpose)\n"
"    Calls: oaBoolean includes(const oaPurpose* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaPurpose,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaPurpose_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPurpose_oaTech data;
    int convert_status=PyoaCollection_oaPurpose_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPurpose_oaTechObject* self=(PyoaCollection_oaPurpose_oaTechObject*)ob;

    PyParamoaPurpose p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPurpose_Convert,&p1)) {
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

static char oaCollection_oaPurpose_oaTech_assign_doc[] = 
"Class: oaCollection_oaPurpose_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPurpose_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPurpose_oaTech data;
  int convert_status=PyoaCollection_oaPurpose_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPurpose_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPurpose_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaPurpose_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaPurpose_oaTech_includes,METH_VARARGS,oaCollection_oaPurpose_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaPurpose_oaTech_tp_assign,METH_VARARGS,oaCollection_oaPurpose_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPurpose_oaTech_doc[] = 
"Class: oaCollection_oaPurpose_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaPurpose_oaTech)\n"
"    Calls: oaCollection_oaPurpose_oaTech(const oaCollection_oaPurpose_oaTech& coll)\n"
"    Signature: oaCollection_oaPurpose_oaTech||cref-oaCollection_oaPurpose_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaPurpose_oaTech)\n"
"    Calls: (const oaCollection_oaPurpose_oaTech&)\n"
"    Signature: oaCollection_oaPurpose_oaTech||cref-oaCollection_oaPurpose_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPurpose_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPurpose_oaTech",
    sizeof(PyoaCollection_oaPurpose_oaTechObject),
    0,
    (destructor)oaCollection_oaPurpose_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPurpose_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPurpose_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaPurpose_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPurpose_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPurpose_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPurpose_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPurpose_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPurpose_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPurpose_oaTech",
           (PyObject*)(&PyoaCollection_oaPurpose_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPurpose_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaReticleRef_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaReticleRef_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaReticleRef_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaReticleRef_oaWaferObject* self = (PyoaCollection_oaReticleRef_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaReticleRef_oaWafer)
    {
        PyParamoaCollection_oaReticleRef_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaReticleRef_oaWafer_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaReticleRef_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaReticleRef_oaWafer, Choices are:\n"
        "    (oaCollection_oaReticleRef_oaWafer)\n"
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
oaCollection_oaReticleRef_oaWafer_tp_dealloc(PyoaCollection_oaReticleRef_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaReticleRef_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaReticleRef_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaReticleRef_oaWafer value;
    int convert_status=PyoaCollection_oaReticleRef_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaReticleRef_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaReticleRef_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaReticleRef_oaWafer v1;
    PyParamoaCollection_oaReticleRef_oaWafer v2;
    int convert_status1=PyoaCollection_oaReticleRef_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaReticleRef_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaReticleRef_oaWafer_Convert(PyObject* ob,PyParamoaCollection_oaReticleRef_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaReticleRef_oaWafer_Check(ob)) {
        result->SetData( (oaCollection_oaReticleRef_oaWafer*) ((PyoaCollection_oaReticleRef_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaReticleRef_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaReticleRef_oaWafer_FromoaCollection_oaReticleRef_oaWafer(oaCollection_oaReticleRef_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaReticleRef_oaWafer_Type.tp_alloc(&PyoaCollection_oaReticleRef_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaReticleRef_oaWaferObject* self = (PyoaCollection_oaReticleRef_oaWaferObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaReticleRef_oaWafer_includes_doc[] = 
"Class: oaCollection_oaReticleRef_oaWafer, Function: includes\n"
"  Paramegers: (oaReticleRef)\n"
"    Calls: oaBoolean includes(const oaReticleRef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaReticleRef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaReticleRef_oaWafer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaReticleRef_oaWafer data;
    int convert_status=PyoaCollection_oaReticleRef_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaReticleRef_oaWaferObject* self=(PyoaCollection_oaReticleRef_oaWaferObject*)ob;

    PyParamoaReticleRef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaReticleRef_Convert,&p1)) {
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

static char oaCollection_oaReticleRef_oaWafer_assign_doc[] = 
"Class: oaCollection_oaReticleRef_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaReticleRef_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaReticleRef_oaWafer data;
  int convert_status=PyoaCollection_oaReticleRef_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaReticleRef_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaReticleRef_oaWafer_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaReticleRef_oaWafer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaReticleRef_oaWafer_includes,METH_VARARGS,oaCollection_oaReticleRef_oaWafer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaReticleRef_oaWafer_tp_assign,METH_VARARGS,oaCollection_oaReticleRef_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaReticleRef_oaWafer_doc[] = 
"Class: oaCollection_oaReticleRef_oaWafer\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaReticleRef_oaWafer)\n"
"    Calls: oaCollection_oaReticleRef_oaWafer(const oaCollection_oaReticleRef_oaWafer& coll)\n"
"    Signature: oaCollection_oaReticleRef_oaWafer||cref-oaCollection_oaReticleRef_oaWafer,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaReticleRef_oaWafer)\n"
"    Calls: (const oaCollection_oaReticleRef_oaWafer&)\n"
"    Signature: oaCollection_oaReticleRef_oaWafer||cref-oaCollection_oaReticleRef_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaReticleRef_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaReticleRef_oaWafer",
    sizeof(PyoaCollection_oaReticleRef_oaWaferObject),
    0,
    (destructor)oaCollection_oaReticleRef_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaReticleRef_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaReticleRef_oaWafer_tp_repr,	/* tp_repr */
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
    oaCollection_oaReticleRef_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaReticleRef_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaReticleRef_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaReticleRef_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaReticleRef_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaReticleRef_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaReticleRef_oaWafer",
           (PyObject*)(&PyoaCollection_oaReticleRef_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaReticleRef_oaWafer\n");
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
// Wrapper Implementation for Class: oaCollection_oaReticle_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaReticle_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaReticle_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaReticle_oaWaferObject* self = (PyoaCollection_oaReticle_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaReticle_oaWafer)
    {
        PyParamoaCollection_oaReticle_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaReticle_oaWafer_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaReticle_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaReticle_oaWafer, Choices are:\n"
        "    (oaCollection_oaReticle_oaWafer)\n"
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
oaCollection_oaReticle_oaWafer_tp_dealloc(PyoaCollection_oaReticle_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaReticle_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaReticle_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaReticle_oaWafer value;
    int convert_status=PyoaCollection_oaReticle_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaReticle_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaReticle_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaReticle_oaWafer v1;
    PyParamoaCollection_oaReticle_oaWafer v2;
    int convert_status1=PyoaCollection_oaReticle_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaReticle_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaReticle_oaWafer_Convert(PyObject* ob,PyParamoaCollection_oaReticle_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaReticle_oaWafer_Check(ob)) {
        result->SetData( (oaCollection_oaReticle_oaWafer*) ((PyoaCollection_oaReticle_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaReticle_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaReticle_oaWafer_FromoaCollection_oaReticle_oaWafer(oaCollection_oaReticle_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaReticle_oaWafer_Type.tp_alloc(&PyoaCollection_oaReticle_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaReticle_oaWaferObject* self = (PyoaCollection_oaReticle_oaWaferObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaReticle_oaWafer_includes_doc[] = 
"Class: oaCollection_oaReticle_oaWafer, Function: includes\n"
"  Paramegers: (oaReticle)\n"
"    Calls: oaBoolean includes(const oaReticle* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaReticle,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaReticle_oaWafer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaReticle_oaWafer data;
    int convert_status=PyoaCollection_oaReticle_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaReticle_oaWaferObject* self=(PyoaCollection_oaReticle_oaWaferObject*)ob;

    PyParamoaReticle p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaReticle_Convert,&p1)) {
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

static char oaCollection_oaReticle_oaWafer_assign_doc[] = 
"Class: oaCollection_oaReticle_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaReticle_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaReticle_oaWafer data;
  int convert_status=PyoaCollection_oaReticle_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaReticle_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaReticle_oaWafer_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaReticle_oaWafer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaReticle_oaWafer_includes,METH_VARARGS,oaCollection_oaReticle_oaWafer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaReticle_oaWafer_tp_assign,METH_VARARGS,oaCollection_oaReticle_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaReticle_oaWafer_doc[] = 
"Class: oaCollection_oaReticle_oaWafer\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaReticle_oaWafer)\n"
"    Calls: oaCollection_oaReticle_oaWafer(const oaCollection_oaReticle_oaWafer& coll)\n"
"    Signature: oaCollection_oaReticle_oaWafer||cref-oaCollection_oaReticle_oaWafer,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaReticle_oaWafer)\n"
"    Calls: (const oaCollection_oaReticle_oaWafer&)\n"
"    Signature: oaCollection_oaReticle_oaWafer||cref-oaCollection_oaReticle_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaReticle_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaReticle_oaWafer",
    sizeof(PyoaCollection_oaReticle_oaWaferObject),
    0,
    (destructor)oaCollection_oaReticle_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaReticle_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaReticle_oaWafer_tp_repr,	/* tp_repr */
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
    oaCollection_oaReticle_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaReticle_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaReticle_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaReticle_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaReticle_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaReticle_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaReticle_oaWafer",
           (PyObject*)(&PyoaCollection_oaReticle_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaReticle_oaWafer\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaBlockObject* self = (PyoaCollection_oaRoute_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaBlock)
    {
        PyParamoaCollection_oaRoute_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaBlock, Choices are:\n"
        "    (oaCollection_oaRoute_oaBlock)\n"
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
oaCollection_oaRoute_oaBlock_tp_dealloc(PyoaCollection_oaRoute_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaBlock value;
    int convert_status=PyoaCollection_oaRoute_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaRoute_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaBlock v1;
    PyParamoaCollection_oaRoute_oaBlock v2;
    int convert_status1=PyoaCollection_oaRoute_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaBlock*) ((PyoaCollection_oaRoute_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaBlock_FromoaCollection_oaRoute_oaBlock(oaCollection_oaRoute_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaBlock_Type.tp_alloc(&PyoaCollection_oaRoute_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaBlockObject* self = (PyoaCollection_oaRoute_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaBlock_includes_doc[] = 
"Class: oaCollection_oaRoute_oaBlock, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaBlock data;
    int convert_status=PyoaCollection_oaRoute_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaBlockObject* self=(PyoaCollection_oaRoute_oaBlockObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaBlock_assign_doc[] = 
"Class: oaCollection_oaRoute_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaBlock data;
  int convert_status=PyoaCollection_oaRoute_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaBlock_includes,METH_VARARGS,oaCollection_oaRoute_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaBlock_doc[] = 
"Class: oaCollection_oaRoute_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaBlock)\n"
"    Calls: oaCollection_oaRoute_oaBlock(const oaCollection_oaRoute_oaBlock& coll)\n"
"    Signature: oaCollection_oaRoute_oaBlock||cref-oaCollection_oaRoute_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaBlock)\n"
"    Calls: (const oaCollection_oaRoute_oaBlock&)\n"
"    Signature: oaCollection_oaRoute_oaBlock||cref-oaCollection_oaRoute_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaBlock",
    sizeof(PyoaCollection_oaRoute_oaBlockObject),
    0,
    (destructor)oaCollection_oaRoute_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaBlock",
           (PyObject*)(&PyoaCollection_oaRoute_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaInstTermObject* self = (PyoaCollection_oaRoute_oaInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaInstTerm)
    {
        PyParamoaCollection_oaRoute_oaInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaInstTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaInstTerm, Choices are:\n"
        "    (oaCollection_oaRoute_oaInstTerm)\n"
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
oaCollection_oaRoute_oaInstTerm_tp_dealloc(PyoaCollection_oaRoute_oaInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaInstTerm value;
    int convert_status=PyoaCollection_oaRoute_oaInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaRoute_oaInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaInstTerm v1;
    PyParamoaCollection_oaRoute_oaInstTerm v2;
    int convert_status1=PyoaCollection_oaRoute_oaInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaInstTerm_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaInstTerm_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaInstTerm*) ((PyoaCollection_oaRoute_oaInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaInstTerm_FromoaCollection_oaRoute_oaInstTerm(oaCollection_oaRoute_oaInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaInstTerm_Type.tp_alloc(&PyoaCollection_oaRoute_oaInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaInstTermObject* self = (PyoaCollection_oaRoute_oaInstTermObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaInstTerm_includes_doc[] = 
"Class: oaCollection_oaRoute_oaInstTerm, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaInstTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaInstTerm data;
    int convert_status=PyoaCollection_oaRoute_oaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaInstTermObject* self=(PyoaCollection_oaRoute_oaInstTermObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaInstTerm_assign_doc[] = 
"Class: oaCollection_oaRoute_oaInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaInstTerm data;
  int convert_status=PyoaCollection_oaRoute_oaInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaInstTerm_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaInstTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaInstTerm_includes,METH_VARARGS,oaCollection_oaRoute_oaInstTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaInstTerm_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaInstTerm_doc[] = 
"Class: oaCollection_oaRoute_oaInstTerm\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaInstTerm)\n"
"    Calls: oaCollection_oaRoute_oaInstTerm(const oaCollection_oaRoute_oaInstTerm& coll)\n"
"    Signature: oaCollection_oaRoute_oaInstTerm||cref-oaCollection_oaRoute_oaInstTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaInstTerm)\n"
"    Calls: (const oaCollection_oaRoute_oaInstTerm&)\n"
"    Signature: oaCollection_oaRoute_oaInstTerm||cref-oaCollection_oaRoute_oaInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaInstTerm",
    sizeof(PyoaCollection_oaRoute_oaInstTermObject),
    0,
    (destructor)oaCollection_oaRoute_oaInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaInstTerm_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaInstTerm",
           (PyObject*)(&PyoaCollection_oaRoute_oaInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaInstTerm\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaNetObject* self = (PyoaCollection_oaRoute_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaNet)
    {
        PyParamoaCollection_oaRoute_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaNet, Choices are:\n"
        "    (oaCollection_oaRoute_oaNet)\n"
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
oaCollection_oaRoute_oaNet_tp_dealloc(PyoaCollection_oaRoute_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaNet value;
    int convert_status=PyoaCollection_oaRoute_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaRoute_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaNet v1;
    PyParamoaCollection_oaRoute_oaNet v2;
    int convert_status1=PyoaCollection_oaRoute_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaNet*) ((PyoaCollection_oaRoute_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaNet_FromoaCollection_oaRoute_oaNet(oaCollection_oaRoute_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaNet_Type.tp_alloc(&PyoaCollection_oaRoute_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaNetObject* self = (PyoaCollection_oaRoute_oaNetObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaNet_includes_doc[] = 
"Class: oaCollection_oaRoute_oaNet, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaNet data;
    int convert_status=PyoaCollection_oaRoute_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaNetObject* self=(PyoaCollection_oaRoute_oaNetObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaNet_assign_doc[] = 
"Class: oaCollection_oaRoute_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaNet data;
  int convert_status=PyoaCollection_oaRoute_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaNet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaNet_includes,METH_VARARGS,oaCollection_oaRoute_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaNet_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaNet_doc[] = 
"Class: oaCollection_oaRoute_oaNet\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaNet)\n"
"    Calls: oaCollection_oaRoute_oaNet(const oaCollection_oaRoute_oaNet& coll)\n"
"    Signature: oaCollection_oaRoute_oaNet||cref-oaCollection_oaRoute_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaNet)\n"
"    Calls: (const oaCollection_oaRoute_oaNet&)\n"
"    Signature: oaCollection_oaRoute_oaNet||cref-oaCollection_oaRoute_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaNet",
    sizeof(PyoaCollection_oaRoute_oaNetObject),
    0,
    (destructor)oaCollection_oaRoute_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaNet_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaNet",
           (PyObject*)(&PyoaCollection_oaRoute_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaNet\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaPin
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaPin_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaPin_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaPinObject* self = (PyoaCollection_oaRoute_oaPinObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaPin)
    {
        PyParamoaCollection_oaRoute_oaPin p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaPin_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaPin(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaPin, Choices are:\n"
        "    (oaCollection_oaRoute_oaPin)\n"
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
oaCollection_oaRoute_oaPin_tp_dealloc(PyoaCollection_oaRoute_oaPinObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaPin*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaPin_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaPin value;
    int convert_status=PyoaCollection_oaRoute_oaPin_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaRoute_oaPin::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaPin_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaPin v1;
    PyParamoaCollection_oaRoute_oaPin v2;
    int convert_status1=PyoaCollection_oaRoute_oaPin_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaPin_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaPin_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaPin* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaPin_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaPin*) ((PyoaCollection_oaRoute_oaPinObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaPin Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaPin_FromoaCollection_oaRoute_oaPin(oaCollection_oaRoute_oaPin* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaPin_Type.tp_alloc(&PyoaCollection_oaRoute_oaPin_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaPinObject* self = (PyoaCollection_oaRoute_oaPinObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaPin_includes_doc[] = 
"Class: oaCollection_oaRoute_oaPin, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaPin_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaPin data;
    int convert_status=PyoaCollection_oaRoute_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaPinObject* self=(PyoaCollection_oaRoute_oaPinObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaPin_assign_doc[] = 
"Class: oaCollection_oaRoute_oaPin, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaPin_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaPin data;
  int convert_status=PyoaCollection_oaRoute_oaPin_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaPin p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaPin_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaPin_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaPin_includes,METH_VARARGS,oaCollection_oaRoute_oaPin_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaPin_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaPin_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaPin_doc[] = 
"Class: oaCollection_oaRoute_oaPin\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaPin)\n"
"    Calls: oaCollection_oaRoute_oaPin(const oaCollection_oaRoute_oaPin& coll)\n"
"    Signature: oaCollection_oaRoute_oaPin||cref-oaCollection_oaRoute_oaPin,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaPin)\n"
"    Calls: (const oaCollection_oaRoute_oaPin&)\n"
"    Signature: oaCollection_oaRoute_oaPin||cref-oaCollection_oaRoute_oaPin,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaPin_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaPin",
    sizeof(PyoaCollection_oaRoute_oaPinObject),
    0,
    (destructor)oaCollection_oaRoute_oaPin_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaPin_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaPin_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaPin_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaPin_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaPin_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaPin_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaPin_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaPin\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaPin",
           (PyObject*)(&PyoaCollection_oaRoute_oaPin_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaPin\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaShape
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaShape_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaShape_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaShapeObject* self = (PyoaCollection_oaRoute_oaShapeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaShape)
    {
        PyParamoaCollection_oaRoute_oaShape p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaShape_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaShape(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaShape, Choices are:\n"
        "    (oaCollection_oaRoute_oaShape)\n"
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
oaCollection_oaRoute_oaShape_tp_dealloc(PyoaCollection_oaRoute_oaShapeObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaShape*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaShape_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaShape value;
    int convert_status=PyoaCollection_oaRoute_oaShape_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaRoute_oaShape::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaShape_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaShape v1;
    PyParamoaCollection_oaRoute_oaShape v2;
    int convert_status1=PyoaCollection_oaRoute_oaShape_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaShape_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaShape_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaShape* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaShape_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaShape*) ((PyoaCollection_oaRoute_oaShapeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaShape Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaShape_FromoaCollection_oaRoute_oaShape(oaCollection_oaRoute_oaShape* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaShape_Type.tp_alloc(&PyoaCollection_oaRoute_oaShape_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaShapeObject* self = (PyoaCollection_oaRoute_oaShapeObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaShape_includes_doc[] = 
"Class: oaCollection_oaRoute_oaShape, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaShape_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaShape data;
    int convert_status=PyoaCollection_oaRoute_oaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaShapeObject* self=(PyoaCollection_oaRoute_oaShapeObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaShape_assign_doc[] = 
"Class: oaCollection_oaRoute_oaShape, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaShape_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaShape data;
  int convert_status=PyoaCollection_oaRoute_oaShape_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaShape p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaShape_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaShape_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaShape_includes,METH_VARARGS,oaCollection_oaRoute_oaShape_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaShape_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaShape_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaShape_doc[] = 
"Class: oaCollection_oaRoute_oaShape\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaShape)\n"
"    Calls: oaCollection_oaRoute_oaShape(const oaCollection_oaRoute_oaShape& coll)\n"
"    Signature: oaCollection_oaRoute_oaShape||cref-oaCollection_oaRoute_oaShape,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaShape)\n"
"    Calls: (const oaCollection_oaRoute_oaShape&)\n"
"    Signature: oaCollection_oaRoute_oaShape||cref-oaCollection_oaRoute_oaShape,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaShape_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaShape",
    sizeof(PyoaCollection_oaRoute_oaShapeObject),
    0,
    (destructor)oaCollection_oaRoute_oaShape_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaShape_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaShape_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaShape_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaShape_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaShape_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaShape_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaShape_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaShape\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaShape",
           (PyObject*)(&PyoaCollection_oaRoute_oaShape_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaShape\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaSteiner
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaSteiner_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaSteiner_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaSteinerObject* self = (PyoaCollection_oaRoute_oaSteinerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaSteiner)
    {
        PyParamoaCollection_oaRoute_oaSteiner p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaSteiner_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaSteiner(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaSteiner, Choices are:\n"
        "    (oaCollection_oaRoute_oaSteiner)\n"
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
oaCollection_oaRoute_oaSteiner_tp_dealloc(PyoaCollection_oaRoute_oaSteinerObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaSteiner*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaSteiner_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaSteiner value;
    int convert_status=PyoaCollection_oaRoute_oaSteiner_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaRoute_oaSteiner::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaSteiner_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaSteiner v1;
    PyParamoaCollection_oaRoute_oaSteiner v2;
    int convert_status1=PyoaCollection_oaRoute_oaSteiner_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaSteiner_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaSteiner_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaSteiner* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaSteiner_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaSteiner*) ((PyoaCollection_oaRoute_oaSteinerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaSteiner Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaSteiner_FromoaCollection_oaRoute_oaSteiner(oaCollection_oaRoute_oaSteiner* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaSteiner_Type.tp_alloc(&PyoaCollection_oaRoute_oaSteiner_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaSteinerObject* self = (PyoaCollection_oaRoute_oaSteinerObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaSteiner_includes_doc[] = 
"Class: oaCollection_oaRoute_oaSteiner, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaSteiner_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaSteiner data;
    int convert_status=PyoaCollection_oaRoute_oaSteiner_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaSteinerObject* self=(PyoaCollection_oaRoute_oaSteinerObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaSteiner_assign_doc[] = 
"Class: oaCollection_oaRoute_oaSteiner, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaSteiner_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaSteiner data;
  int convert_status=PyoaCollection_oaRoute_oaSteiner_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaSteiner p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaSteiner_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaSteiner_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaSteiner_includes,METH_VARARGS,oaCollection_oaRoute_oaSteiner_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaSteiner_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaSteiner_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaSteiner_doc[] = 
"Class: oaCollection_oaRoute_oaSteiner\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaSteiner)\n"
"    Calls: oaCollection_oaRoute_oaSteiner(const oaCollection_oaRoute_oaSteiner& coll)\n"
"    Signature: oaCollection_oaRoute_oaSteiner||cref-oaCollection_oaRoute_oaSteiner,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaSteiner)\n"
"    Calls: (const oaCollection_oaRoute_oaSteiner&)\n"
"    Signature: oaCollection_oaRoute_oaSteiner||cref-oaCollection_oaRoute_oaSteiner,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaSteiner_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaSteiner",
    sizeof(PyoaCollection_oaRoute_oaSteinerObject),
    0,
    (destructor)oaCollection_oaRoute_oaSteiner_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaSteiner_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaSteiner_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaSteiner_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaSteiner_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaSteiner_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaSteiner_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaSteiner_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaSteiner\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaSteiner",
           (PyObject*)(&PyoaCollection_oaRoute_oaSteiner_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaSteiner\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaTermObject* self = (PyoaCollection_oaRoute_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaTerm)
    {
        PyParamoaCollection_oaRoute_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaTerm, Choices are:\n"
        "    (oaCollection_oaRoute_oaTerm)\n"
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
oaCollection_oaRoute_oaTerm_tp_dealloc(PyoaCollection_oaRoute_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaTerm value;
    int convert_status=PyoaCollection_oaRoute_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaRoute_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaTerm v1;
    PyParamoaCollection_oaRoute_oaTerm v2;
    int convert_status1=PyoaCollection_oaRoute_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaTerm_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaTerm_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaTerm*) ((PyoaCollection_oaRoute_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaTerm_FromoaCollection_oaRoute_oaTerm(oaCollection_oaRoute_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaTerm_Type.tp_alloc(&PyoaCollection_oaRoute_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaTermObject* self = (PyoaCollection_oaRoute_oaTermObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaTerm_includes_doc[] = 
"Class: oaCollection_oaRoute_oaTerm, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaTerm data;
    int convert_status=PyoaCollection_oaRoute_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaTermObject* self=(PyoaCollection_oaRoute_oaTermObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaTerm_assign_doc[] = 
"Class: oaCollection_oaRoute_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaTerm data;
  int convert_status=PyoaCollection_oaRoute_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaTerm_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaTerm_includes,METH_VARARGS,oaCollection_oaRoute_oaTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaTerm_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaTerm_doc[] = 
"Class: oaCollection_oaRoute_oaTerm\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaTerm)\n"
"    Calls: oaCollection_oaRoute_oaTerm(const oaCollection_oaRoute_oaTerm& coll)\n"
"    Signature: oaCollection_oaRoute_oaTerm||cref-oaCollection_oaRoute_oaTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaTerm)\n"
"    Calls: (const oaCollection_oaRoute_oaTerm&)\n"
"    Signature: oaCollection_oaRoute_oaTerm||cref-oaCollection_oaRoute_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaTerm",
    sizeof(PyoaCollection_oaRoute_oaTermObject),
    0,
    (destructor)oaCollection_oaRoute_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaTerm_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaTerm",
           (PyObject*)(&PyoaCollection_oaRoute_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaTerm\n");
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
// Wrapper Implementation for Class: oaCollection_oaRoute_oaVia
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaVia_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRoute_oaVia_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRoute_oaViaObject* self = (PyoaCollection_oaRoute_oaViaObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRoute_oaVia)
    {
        PyParamoaCollection_oaRoute_oaVia p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRoute_oaVia_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRoute_oaVia(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRoute_oaVia, Choices are:\n"
        "    (oaCollection_oaRoute_oaVia)\n"
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
oaCollection_oaRoute_oaVia_tp_dealloc(PyoaCollection_oaRoute_oaViaObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRoute_oaVia*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRoute_oaVia_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRoute_oaVia value;
    int convert_status=PyoaCollection_oaRoute_oaVia_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaRoute_oaVia::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRoute_oaVia_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRoute_oaVia v1;
    PyParamoaCollection_oaRoute_oaVia v2;
    int convert_status1=PyoaCollection_oaRoute_oaVia_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRoute_oaVia_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRoute_oaVia_Convert(PyObject* ob,PyParamoaCollection_oaRoute_oaVia* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRoute_oaVia_Check(ob)) {
        result->SetData( (oaCollection_oaRoute_oaVia*) ((PyoaCollection_oaRoute_oaViaObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRoute_oaVia Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRoute_oaVia_FromoaCollection_oaRoute_oaVia(oaCollection_oaRoute_oaVia* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRoute_oaVia_Type.tp_alloc(&PyoaCollection_oaRoute_oaVia_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRoute_oaViaObject* self = (PyoaCollection_oaRoute_oaViaObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRoute_oaVia_includes_doc[] = 
"Class: oaCollection_oaRoute_oaVia, Function: includes\n"
"  Paramegers: (oaRoute)\n"
"    Calls: oaBoolean includes(const oaRoute* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRoute,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRoute_oaVia_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRoute_oaVia data;
    int convert_status=PyoaCollection_oaRoute_oaVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRoute_oaViaObject* self=(PyoaCollection_oaRoute_oaViaObject*)ob;

    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRoute_Convert,&p1)) {
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

static char oaCollection_oaRoute_oaVia_assign_doc[] = 
"Class: oaCollection_oaRoute_oaVia, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRoute_oaVia_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRoute_oaVia data;
  int convert_status=PyoaCollection_oaRoute_oaVia_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRoute_oaVia p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRoute_oaVia_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRoute_oaVia_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRoute_oaVia_includes,METH_VARARGS,oaCollection_oaRoute_oaVia_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRoute_oaVia_tp_assign,METH_VARARGS,oaCollection_oaRoute_oaVia_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRoute_oaVia_doc[] = 
"Class: oaCollection_oaRoute_oaVia\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRoute_oaVia)\n"
"    Calls: oaCollection_oaRoute_oaVia(const oaCollection_oaRoute_oaVia& coll)\n"
"    Signature: oaCollection_oaRoute_oaVia||cref-oaCollection_oaRoute_oaVia,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRoute_oaVia)\n"
"    Calls: (const oaCollection_oaRoute_oaVia&)\n"
"    Signature: oaCollection_oaRoute_oaVia||cref-oaCollection_oaRoute_oaVia,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRoute_oaVia_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRoute_oaVia",
    sizeof(PyoaCollection_oaRoute_oaViaObject),
    0,
    (destructor)oaCollection_oaRoute_oaVia_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRoute_oaVia_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRoute_oaVia_tp_repr,	/* tp_repr */
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
    oaCollection_oaRoute_oaVia_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRoute_oaVia_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRoute_oaVia_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRoute_oaVia_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRoute_oaVia_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRoute_oaVia\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRoute_oaVia",
           (PyObject*)(&PyoaCollection_oaRoute_oaVia_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRoute_oaVia\n");
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
// Wrapper Implementation for Class: oaCollection_oaRowHeader_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRowHeader_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRowHeader_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRowHeader_oaBlockObject* self = (PyoaCollection_oaRowHeader_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRowHeader_oaBlock)
    {
        PyParamoaCollection_oaRowHeader_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRowHeader_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRowHeader_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRowHeader_oaBlock, Choices are:\n"
        "    (oaCollection_oaRowHeader_oaBlock)\n"
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
oaCollection_oaRowHeader_oaBlock_tp_dealloc(PyoaCollection_oaRowHeader_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRowHeader_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRowHeader_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRowHeader_oaBlock value;
    int convert_status=PyoaCollection_oaRowHeader_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaRowHeader_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRowHeader_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRowHeader_oaBlock v1;
    PyParamoaCollection_oaRowHeader_oaBlock v2;
    int convert_status1=PyoaCollection_oaRowHeader_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRowHeader_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRowHeader_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaRowHeader_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRowHeader_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaRowHeader_oaBlock*) ((PyoaCollection_oaRowHeader_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRowHeader_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRowHeader_oaBlock_FromoaCollection_oaRowHeader_oaBlock(oaCollection_oaRowHeader_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRowHeader_oaBlock_Type.tp_alloc(&PyoaCollection_oaRowHeader_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRowHeader_oaBlockObject* self = (PyoaCollection_oaRowHeader_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRowHeader_oaBlock_includes_doc[] = 
"Class: oaCollection_oaRowHeader_oaBlock, Function: includes\n"
"  Paramegers: (oaRowHeader)\n"
"    Calls: oaBoolean includes(const oaRowHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRowHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRowHeader_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRowHeader_oaBlock data;
    int convert_status=PyoaCollection_oaRowHeader_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRowHeader_oaBlockObject* self=(PyoaCollection_oaRowHeader_oaBlockObject*)ob;

    PyParamoaRowHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRowHeader_Convert,&p1)) {
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

static char oaCollection_oaRowHeader_oaBlock_assign_doc[] = 
"Class: oaCollection_oaRowHeader_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRowHeader_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRowHeader_oaBlock data;
  int convert_status=PyoaCollection_oaRowHeader_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRowHeader_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRowHeader_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRowHeader_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRowHeader_oaBlock_includes,METH_VARARGS,oaCollection_oaRowHeader_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRowHeader_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaRowHeader_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRowHeader_oaBlock_doc[] = 
"Class: oaCollection_oaRowHeader_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRowHeader_oaBlock)\n"
"    Calls: oaCollection_oaRowHeader_oaBlock(const oaCollection_oaRowHeader_oaBlock& coll)\n"
"    Signature: oaCollection_oaRowHeader_oaBlock||cref-oaCollection_oaRowHeader_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRowHeader_oaBlock)\n"
"    Calls: (const oaCollection_oaRowHeader_oaBlock&)\n"
"    Signature: oaCollection_oaRowHeader_oaBlock||cref-oaCollection_oaRowHeader_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRowHeader_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRowHeader_oaBlock",
    sizeof(PyoaCollection_oaRowHeader_oaBlockObject),
    0,
    (destructor)oaCollection_oaRowHeader_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRowHeader_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRowHeader_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaRowHeader_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRowHeader_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRowHeader_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRowHeader_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRowHeader_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRowHeader_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRowHeader_oaBlock",
           (PyObject*)(&PyoaCollection_oaRowHeader_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRowHeader_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaRowHeader_oaSiteDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRowHeader_oaSiteDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRowHeader_oaSiteDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRowHeader_oaSiteDefObject* self = (PyoaCollection_oaRowHeader_oaSiteDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRowHeader_oaSiteDef)
    {
        PyParamoaCollection_oaRowHeader_oaSiteDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRowHeader_oaSiteDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRowHeader_oaSiteDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRowHeader_oaSiteDef, Choices are:\n"
        "    (oaCollection_oaRowHeader_oaSiteDef)\n"
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
oaCollection_oaRowHeader_oaSiteDef_tp_dealloc(PyoaCollection_oaRowHeader_oaSiteDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRowHeader_oaSiteDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRowHeader_oaSiteDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRowHeader_oaSiteDef value;
    int convert_status=PyoaCollection_oaRowHeader_oaSiteDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaRowHeader_oaSiteDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRowHeader_oaSiteDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRowHeader_oaSiteDef v1;
    PyParamoaCollection_oaRowHeader_oaSiteDef v2;
    int convert_status1=PyoaCollection_oaRowHeader_oaSiteDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRowHeader_oaSiteDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRowHeader_oaSiteDef_Convert(PyObject* ob,PyParamoaCollection_oaRowHeader_oaSiteDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRowHeader_oaSiteDef_Check(ob)) {
        result->SetData( (oaCollection_oaRowHeader_oaSiteDef*) ((PyoaCollection_oaRowHeader_oaSiteDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRowHeader_oaSiteDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRowHeader_oaSiteDef_FromoaCollection_oaRowHeader_oaSiteDef(oaCollection_oaRowHeader_oaSiteDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRowHeader_oaSiteDef_Type.tp_alloc(&PyoaCollection_oaRowHeader_oaSiteDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRowHeader_oaSiteDefObject* self = (PyoaCollection_oaRowHeader_oaSiteDefObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRowHeader_oaSiteDef_includes_doc[] = 
"Class: oaCollection_oaRowHeader_oaSiteDef, Function: includes\n"
"  Paramegers: (oaRowHeader)\n"
"    Calls: oaBoolean includes(const oaRowHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRowHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRowHeader_oaSiteDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRowHeader_oaSiteDef data;
    int convert_status=PyoaCollection_oaRowHeader_oaSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRowHeader_oaSiteDefObject* self=(PyoaCollection_oaRowHeader_oaSiteDefObject*)ob;

    PyParamoaRowHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRowHeader_Convert,&p1)) {
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

static char oaCollection_oaRowHeader_oaSiteDef_assign_doc[] = 
"Class: oaCollection_oaRowHeader_oaSiteDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRowHeader_oaSiteDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRowHeader_oaSiteDef data;
  int convert_status=PyoaCollection_oaRowHeader_oaSiteDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRowHeader_oaSiteDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRowHeader_oaSiteDef_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRowHeader_oaSiteDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRowHeader_oaSiteDef_includes,METH_VARARGS,oaCollection_oaRowHeader_oaSiteDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRowHeader_oaSiteDef_tp_assign,METH_VARARGS,oaCollection_oaRowHeader_oaSiteDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRowHeader_oaSiteDef_doc[] = 
"Class: oaCollection_oaRowHeader_oaSiteDef\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRowHeader_oaSiteDef)\n"
"    Calls: oaCollection_oaRowHeader_oaSiteDef(const oaCollection_oaRowHeader_oaSiteDef& coll)\n"
"    Signature: oaCollection_oaRowHeader_oaSiteDef||cref-oaCollection_oaRowHeader_oaSiteDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRowHeader_oaSiteDef)\n"
"    Calls: (const oaCollection_oaRowHeader_oaSiteDef&)\n"
"    Signature: oaCollection_oaRowHeader_oaSiteDef||cref-oaCollection_oaRowHeader_oaSiteDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRowHeader_oaSiteDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRowHeader_oaSiteDef",
    sizeof(PyoaCollection_oaRowHeader_oaSiteDefObject),
    0,
    (destructor)oaCollection_oaRowHeader_oaSiteDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRowHeader_oaSiteDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRowHeader_oaSiteDef_tp_repr,	/* tp_repr */
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
    oaCollection_oaRowHeader_oaSiteDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRowHeader_oaSiteDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRowHeader_oaSiteDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRowHeader_oaSiteDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRowHeader_oaSiteDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRowHeader_oaSiteDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRowHeader_oaSiteDef",
           (PyObject*)(&PyoaCollection_oaRowHeader_oaSiteDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRowHeader_oaSiteDef\n");
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
// Wrapper Implementation for Class: oaCollection_oaRow_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRow_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRow_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRow_oaBlockObject* self = (PyoaCollection_oaRow_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRow_oaBlock)
    {
        PyParamoaCollection_oaRow_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRow_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRow_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRow_oaBlock, Choices are:\n"
        "    (oaCollection_oaRow_oaBlock)\n"
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
oaCollection_oaRow_oaBlock_tp_dealloc(PyoaCollection_oaRow_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRow_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRow_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRow_oaBlock value;
    int convert_status=PyoaCollection_oaRow_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaRow_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRow_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRow_oaBlock v1;
    PyParamoaCollection_oaRow_oaBlock v2;
    int convert_status1=PyoaCollection_oaRow_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRow_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRow_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaRow_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRow_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaRow_oaBlock*) ((PyoaCollection_oaRow_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRow_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRow_oaBlock_FromoaCollection_oaRow_oaBlock(oaCollection_oaRow_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRow_oaBlock_Type.tp_alloc(&PyoaCollection_oaRow_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRow_oaBlockObject* self = (PyoaCollection_oaRow_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRow_oaBlock_includes_doc[] = 
"Class: oaCollection_oaRow_oaBlock, Function: includes\n"
"  Paramegers: (oaRow)\n"
"    Calls: oaBoolean includes(const oaRow* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRow,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRow_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRow_oaBlock data;
    int convert_status=PyoaCollection_oaRow_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRow_oaBlockObject* self=(PyoaCollection_oaRow_oaBlockObject*)ob;

    PyParamoaRow p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRow_Convert,&p1)) {
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

static char oaCollection_oaRow_oaBlock_assign_doc[] = 
"Class: oaCollection_oaRow_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRow_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRow_oaBlock data;
  int convert_status=PyoaCollection_oaRow_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRow_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRow_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRow_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRow_oaBlock_includes,METH_VARARGS,oaCollection_oaRow_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRow_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaRow_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRow_oaBlock_doc[] = 
"Class: oaCollection_oaRow_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRow_oaBlock)\n"
"    Calls: oaCollection_oaRow_oaBlock(const oaCollection_oaRow_oaBlock& coll)\n"
"    Signature: oaCollection_oaRow_oaBlock||cref-oaCollection_oaRow_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRow_oaBlock)\n"
"    Calls: (const oaCollection_oaRow_oaBlock&)\n"
"    Signature: oaCollection_oaRow_oaBlock||cref-oaCollection_oaRow_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRow_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRow_oaBlock",
    sizeof(PyoaCollection_oaRow_oaBlockObject),
    0,
    (destructor)oaCollection_oaRow_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRow_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRow_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaRow_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRow_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRow_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRow_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRow_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRow_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRow_oaBlock",
           (PyObject*)(&PyoaCollection_oaRow_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRow_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaRow_oaRowHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRow_oaRowHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaRow_oaRowHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaRow_oaRowHeaderObject* self = (PyoaCollection_oaRow_oaRowHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaRow_oaRowHeader)
    {
        PyParamoaCollection_oaRow_oaRowHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaRow_oaRowHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaRow_oaRowHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaRow_oaRowHeader, Choices are:\n"
        "    (oaCollection_oaRow_oaRowHeader)\n"
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
oaCollection_oaRow_oaRowHeader_tp_dealloc(PyoaCollection_oaRow_oaRowHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaRow_oaRowHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaRow_oaRowHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaRow_oaRowHeader value;
    int convert_status=PyoaCollection_oaRow_oaRowHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaRow_oaRowHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaRow_oaRowHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaRow_oaRowHeader v1;
    PyParamoaCollection_oaRow_oaRowHeader v2;
    int convert_status1=PyoaCollection_oaRow_oaRowHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaRow_oaRowHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaRow_oaRowHeader_Convert(PyObject* ob,PyParamoaCollection_oaRow_oaRowHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaRow_oaRowHeader_Check(ob)) {
        result->SetData( (oaCollection_oaRow_oaRowHeader*) ((PyoaCollection_oaRow_oaRowHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaRow_oaRowHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaRow_oaRowHeader_FromoaCollection_oaRow_oaRowHeader(oaCollection_oaRow_oaRowHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaRow_oaRowHeader_Type.tp_alloc(&PyoaCollection_oaRow_oaRowHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaRow_oaRowHeaderObject* self = (PyoaCollection_oaRow_oaRowHeaderObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaRow_oaRowHeader_includes_doc[] = 
"Class: oaCollection_oaRow_oaRowHeader, Function: includes\n"
"  Paramegers: (oaRow)\n"
"    Calls: oaBoolean includes(const oaRow* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaRow,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaRow_oaRowHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaRow_oaRowHeader data;
    int convert_status=PyoaCollection_oaRow_oaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaRow_oaRowHeaderObject* self=(PyoaCollection_oaRow_oaRowHeaderObject*)ob;

    PyParamoaRow p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRow_Convert,&p1)) {
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

static char oaCollection_oaRow_oaRowHeader_assign_doc[] = 
"Class: oaCollection_oaRow_oaRowHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaRow_oaRowHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaRow_oaRowHeader data;
  int convert_status=PyoaCollection_oaRow_oaRowHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaRow_oaRowHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaRow_oaRowHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaRow_oaRowHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaRow_oaRowHeader_includes,METH_VARARGS,oaCollection_oaRow_oaRowHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaRow_oaRowHeader_tp_assign,METH_VARARGS,oaCollection_oaRow_oaRowHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaRow_oaRowHeader_doc[] = 
"Class: oaCollection_oaRow_oaRowHeader\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaRow_oaRowHeader)\n"
"    Calls: oaCollection_oaRow_oaRowHeader(const oaCollection_oaRow_oaRowHeader& coll)\n"
"    Signature: oaCollection_oaRow_oaRowHeader||cref-oaCollection_oaRow_oaRowHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaRow_oaRowHeader)\n"
"    Calls: (const oaCollection_oaRow_oaRowHeader&)\n"
"    Signature: oaCollection_oaRow_oaRowHeader||cref-oaCollection_oaRow_oaRowHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaRow_oaRowHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaRow_oaRowHeader",
    sizeof(PyoaCollection_oaRow_oaRowHeaderObject),
    0,
    (destructor)oaCollection_oaRow_oaRowHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaRow_oaRowHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaRow_oaRowHeader_tp_repr,	/* tp_repr */
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
    oaCollection_oaRow_oaRowHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaRow_oaRowHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaRow_oaRowHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaRow_oaRowHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaRow_oaRowHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaRow_oaRowHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaRow_oaRowHeader",
           (PyObject*)(&PyoaCollection_oaRow_oaRowHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaRow_oaRowHeader\n");
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
// Wrapper Implementation for Class: oaCollection_oaScanChainInst_oaScanChainSet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChainInst_oaScanChainSet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaScanChainInst_oaScanChainSet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaScanChainInst_oaScanChainSetObject* self = (PyoaCollection_oaScanChainInst_oaScanChainSetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaScanChainInst_oaScanChainSet)
    {
        PyParamoaCollection_oaScanChainInst_oaScanChainSet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaScanChainInst_oaScanChainSet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaScanChainInst_oaScanChainSet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaScanChainInst_oaScanChainSet, Choices are:\n"
        "    (oaCollection_oaScanChainInst_oaScanChainSet)\n"
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
oaCollection_oaScanChainInst_oaScanChainSet_tp_dealloc(PyoaCollection_oaScanChainInst_oaScanChainSetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaScanChainInst_oaScanChainSet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChainInst_oaScanChainSet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaScanChainInst_oaScanChainSet value;
    int convert_status=PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[65];
    sprintf(buffer,"<oaCollection_oaScanChainInst_oaScanChainSet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaScanChainInst_oaScanChainSet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaScanChainInst_oaScanChainSet v1;
    PyParamoaCollection_oaScanChainInst_oaScanChainSet v2;
    int convert_status1=PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(PyObject* ob,PyParamoaCollection_oaScanChainInst_oaScanChainSet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaScanChainInst_oaScanChainSet_Check(ob)) {
        result->SetData( (oaCollection_oaScanChainInst_oaScanChainSet*) ((PyoaCollection_oaScanChainInst_oaScanChainSetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaScanChainInst_oaScanChainSet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaScanChainInst_oaScanChainSet_FromoaCollection_oaScanChainInst_oaScanChainSet(oaCollection_oaScanChainInst_oaScanChainSet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaScanChainInst_oaScanChainSet_Type.tp_alloc(&PyoaCollection_oaScanChainInst_oaScanChainSet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaScanChainInst_oaScanChainSetObject* self = (PyoaCollection_oaScanChainInst_oaScanChainSetObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaScanChainInst_oaScanChainSet_includes_doc[] = 
"Class: oaCollection_oaScanChainInst_oaScanChainSet, Function: includes\n"
"  Paramegers: (oaScanChainInst)\n"
"    Calls: oaBoolean includes(const oaScanChainInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaScanChainInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaScanChainInst_oaScanChainSet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaScanChainInst_oaScanChainSet data;
    int convert_status=PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaScanChainInst_oaScanChainSetObject* self=(PyoaCollection_oaScanChainInst_oaScanChainSetObject*)ob;

    PyParamoaScanChainInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScanChainInst_Convert,&p1)) {
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

static char oaCollection_oaScanChainInst_oaScanChainSet_assign_doc[] = 
"Class: oaCollection_oaScanChainInst_oaScanChainSet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaScanChainInst_oaScanChainSet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaScanChainInst_oaScanChainSet data;
  int convert_status=PyoaCollection_oaScanChainInst_oaScanChainSet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaScanChainInst_oaScanChainSet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaScanChainInst_oaScanChainSet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaScanChainInst_oaScanChainSet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaScanChainInst_oaScanChainSet_includes,METH_VARARGS,oaCollection_oaScanChainInst_oaScanChainSet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaScanChainInst_oaScanChainSet_tp_assign,METH_VARARGS,oaCollection_oaScanChainInst_oaScanChainSet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaScanChainInst_oaScanChainSet_doc[] = 
"Class: oaCollection_oaScanChainInst_oaScanChainSet\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaScanChainInst_oaScanChainSet)\n"
"    Calls: oaCollection_oaScanChainInst_oaScanChainSet(const oaCollection_oaScanChainInst_oaScanChainSet& coll)\n"
"    Signature: oaCollection_oaScanChainInst_oaScanChainSet||cref-oaCollection_oaScanChainInst_oaScanChainSet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaScanChainInst_oaScanChainSet)\n"
"    Calls: (const oaCollection_oaScanChainInst_oaScanChainSet&)\n"
"    Signature: oaCollection_oaScanChainInst_oaScanChainSet||cref-oaCollection_oaScanChainInst_oaScanChainSet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaScanChainInst_oaScanChainSet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaScanChainInst_oaScanChainSet",
    sizeof(PyoaCollection_oaScanChainInst_oaScanChainSetObject),
    0,
    (destructor)oaCollection_oaScanChainInst_oaScanChainSet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaScanChainInst_oaScanChainSet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaScanChainInst_oaScanChainSet_tp_repr,	/* tp_repr */
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
    oaCollection_oaScanChainInst_oaScanChainSet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaScanChainInst_oaScanChainSet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaScanChainInst_oaScanChainSet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaScanChainInst_oaScanChainSet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaScanChainInst_oaScanChainSet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaScanChainInst_oaScanChainSet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaScanChainInst_oaScanChainSet",
           (PyObject*)(&PyoaCollection_oaScanChainInst_oaScanChainSet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaScanChainInst_oaScanChainSet\n");
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
// Wrapper Implementation for Class: oaCollection_oaScanChainSet_oaScanChain
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChainSet_oaScanChain_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaScanChainSet_oaScanChain_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaScanChainSet_oaScanChainObject* self = (PyoaCollection_oaScanChainSet_oaScanChainObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaScanChainSet_oaScanChain)
    {
        PyParamoaCollection_oaScanChainSet_oaScanChain p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaScanChainSet_oaScanChain_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaScanChainSet_oaScanChain(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaScanChainSet_oaScanChain, Choices are:\n"
        "    (oaCollection_oaScanChainSet_oaScanChain)\n"
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
oaCollection_oaScanChainSet_oaScanChain_tp_dealloc(PyoaCollection_oaScanChainSet_oaScanChainObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaScanChainSet_oaScanChain*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChainSet_oaScanChain_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaScanChainSet_oaScanChain value;
    int convert_status=PyoaCollection_oaScanChainSet_oaScanChain_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaScanChainSet_oaScanChain::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaScanChainSet_oaScanChain_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaScanChainSet_oaScanChain v1;
    PyParamoaCollection_oaScanChainSet_oaScanChain v2;
    int convert_status1=PyoaCollection_oaScanChainSet_oaScanChain_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaScanChainSet_oaScanChain_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaScanChainSet_oaScanChain_Convert(PyObject* ob,PyParamoaCollection_oaScanChainSet_oaScanChain* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaScanChainSet_oaScanChain_Check(ob)) {
        result->SetData( (oaCollection_oaScanChainSet_oaScanChain*) ((PyoaCollection_oaScanChainSet_oaScanChainObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaScanChainSet_oaScanChain Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaScanChainSet_oaScanChain_FromoaCollection_oaScanChainSet_oaScanChain(oaCollection_oaScanChainSet_oaScanChain* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaScanChainSet_oaScanChain_Type.tp_alloc(&PyoaCollection_oaScanChainSet_oaScanChain_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaScanChainSet_oaScanChainObject* self = (PyoaCollection_oaScanChainSet_oaScanChainObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaScanChainSet_oaScanChain_includes_doc[] = 
"Class: oaCollection_oaScanChainSet_oaScanChain, Function: includes\n"
"  Paramegers: (oaScanChainSet)\n"
"    Calls: oaBoolean includes(const oaScanChainSet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaScanChainSet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaScanChainSet_oaScanChain_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaScanChainSet_oaScanChain data;
    int convert_status=PyoaCollection_oaScanChainSet_oaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaScanChainSet_oaScanChainObject* self=(PyoaCollection_oaScanChainSet_oaScanChainObject*)ob;

    PyParamoaScanChainSet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScanChainSet_Convert,&p1)) {
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

static char oaCollection_oaScanChainSet_oaScanChain_assign_doc[] = 
"Class: oaCollection_oaScanChainSet_oaScanChain, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaScanChainSet_oaScanChain_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaScanChainSet_oaScanChain data;
  int convert_status=PyoaCollection_oaScanChainSet_oaScanChain_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaScanChainSet_oaScanChain p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaScanChainSet_oaScanChain_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaScanChainSet_oaScanChain_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaScanChainSet_oaScanChain_includes,METH_VARARGS,oaCollection_oaScanChainSet_oaScanChain_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaScanChainSet_oaScanChain_tp_assign,METH_VARARGS,oaCollection_oaScanChainSet_oaScanChain_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaScanChainSet_oaScanChain_doc[] = 
"Class: oaCollection_oaScanChainSet_oaScanChain\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaScanChainSet_oaScanChain)\n"
"    Calls: oaCollection_oaScanChainSet_oaScanChain(const oaCollection_oaScanChainSet_oaScanChain& coll)\n"
"    Signature: oaCollection_oaScanChainSet_oaScanChain||cref-oaCollection_oaScanChainSet_oaScanChain,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaScanChainSet_oaScanChain)\n"
"    Calls: (const oaCollection_oaScanChainSet_oaScanChain&)\n"
"    Signature: oaCollection_oaScanChainSet_oaScanChain||cref-oaCollection_oaScanChainSet_oaScanChain,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaScanChainSet_oaScanChain_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaScanChainSet_oaScanChain",
    sizeof(PyoaCollection_oaScanChainSet_oaScanChainObject),
    0,
    (destructor)oaCollection_oaScanChainSet_oaScanChain_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaScanChainSet_oaScanChain_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaScanChainSet_oaScanChain_tp_repr,	/* tp_repr */
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
    oaCollection_oaScanChainSet_oaScanChain_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaScanChainSet_oaScanChain_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaScanChainSet_oaScanChain_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaScanChainSet_oaScanChain_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaScanChainSet_oaScanChain_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaScanChainSet_oaScanChain\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaScanChainSet_oaScanChain",
           (PyObject*)(&PyoaCollection_oaScanChainSet_oaScanChain_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaScanChainSet_oaScanChain\n");
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
// Wrapper Implementation for Class: oaCollection_oaScanChain_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChain_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaScanChain_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaScanChain_oaBlockObject* self = (PyoaCollection_oaScanChain_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaScanChain_oaBlock)
    {
        PyParamoaCollection_oaScanChain_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaScanChain_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaScanChain_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaScanChain_oaBlock, Choices are:\n"
        "    (oaCollection_oaScanChain_oaBlock)\n"
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
oaCollection_oaScanChain_oaBlock_tp_dealloc(PyoaCollection_oaScanChain_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaScanChain_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaScanChain_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaScanChain_oaBlock value;
    int convert_status=PyoaCollection_oaScanChain_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaScanChain_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaScanChain_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaScanChain_oaBlock v1;
    PyParamoaCollection_oaScanChain_oaBlock v2;
    int convert_status1=PyoaCollection_oaScanChain_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaScanChain_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaScanChain_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaScanChain_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaScanChain_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaScanChain_oaBlock*) ((PyoaCollection_oaScanChain_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaScanChain_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaScanChain_oaBlock_FromoaCollection_oaScanChain_oaBlock(oaCollection_oaScanChain_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaScanChain_oaBlock_Type.tp_alloc(&PyoaCollection_oaScanChain_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaScanChain_oaBlockObject* self = (PyoaCollection_oaScanChain_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaScanChain_oaBlock_includes_doc[] = 
"Class: oaCollection_oaScanChain_oaBlock, Function: includes\n"
"  Paramegers: (oaScanChain)\n"
"    Calls: oaBoolean includes(const oaScanChain* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaScanChain,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaScanChain_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaScanChain_oaBlock data;
    int convert_status=PyoaCollection_oaScanChain_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaScanChain_oaBlockObject* self=(PyoaCollection_oaScanChain_oaBlockObject*)ob;

    PyParamoaScanChain p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScanChain_Convert,&p1)) {
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

static char oaCollection_oaScanChain_oaBlock_assign_doc[] = 
"Class: oaCollection_oaScanChain_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaScanChain_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaScanChain_oaBlock data;
  int convert_status=PyoaCollection_oaScanChain_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaScanChain_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaScanChain_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaScanChain_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaScanChain_oaBlock_includes,METH_VARARGS,oaCollection_oaScanChain_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaScanChain_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaScanChain_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaScanChain_oaBlock_doc[] = 
"Class: oaCollection_oaScanChain_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaScanChain_oaBlock)\n"
"    Calls: oaCollection_oaScanChain_oaBlock(const oaCollection_oaScanChain_oaBlock& coll)\n"
"    Signature: oaCollection_oaScanChain_oaBlock||cref-oaCollection_oaScanChain_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaScanChain_oaBlock)\n"
"    Calls: (const oaCollection_oaScanChain_oaBlock&)\n"
"    Signature: oaCollection_oaScanChain_oaBlock||cref-oaCollection_oaScanChain_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaScanChain_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaScanChain_oaBlock",
    sizeof(PyoaCollection_oaScanChain_oaBlockObject),
    0,
    (destructor)oaCollection_oaScanChain_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaScanChain_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaScanChain_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaScanChain_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaScanChain_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaScanChain_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaScanChain_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaScanChain_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaScanChain_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaScanChain_oaBlock",
           (PyObject*)(&PyoaCollection_oaScanChain_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaScanChain_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaShape_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaShape_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaShape_oaBlockObject* self = (PyoaCollection_oaShape_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaShape_oaBlock)
    {
        PyParamoaCollection_oaShape_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaShape_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaShape_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaShape_oaBlock, Choices are:\n"
        "    (oaCollection_oaShape_oaBlock)\n"
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
oaCollection_oaShape_oaBlock_tp_dealloc(PyoaCollection_oaShape_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaShape_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaShape_oaBlock value;
    int convert_status=PyoaCollection_oaShape_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaShape_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaShape_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaShape_oaBlock v1;
    PyParamoaCollection_oaShape_oaBlock v2;
    int convert_status1=PyoaCollection_oaShape_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaShape_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaShape_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaShape_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaShape_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaShape_oaBlock*) ((PyoaCollection_oaShape_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaShape_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaShape_oaBlock_FromoaCollection_oaShape_oaBlock(oaCollection_oaShape_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaShape_oaBlock_Type.tp_alloc(&PyoaCollection_oaShape_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaShape_oaBlockObject* self = (PyoaCollection_oaShape_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaShape_oaBlock_includes_doc[] = 
"Class: oaCollection_oaShape_oaBlock, Function: includes\n"
"  Paramegers: (oaShape)\n"
"    Calls: oaBoolean includes(const oaShape* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaShape,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaShape_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaShape_oaBlock data;
    int convert_status=PyoaCollection_oaShape_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaShape_oaBlockObject* self=(PyoaCollection_oaShape_oaBlockObject*)ob;

    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaShape_Convert,&p1)) {
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

static char oaCollection_oaShape_oaBlock_assign_doc[] = 
"Class: oaCollection_oaShape_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaShape_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaShape_oaBlock data;
  int convert_status=PyoaCollection_oaShape_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaShape_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaShape_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaShape_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaShape_oaBlock_includes,METH_VARARGS,oaCollection_oaShape_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaShape_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaShape_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaShape_oaBlock_doc[] = 
"Class: oaCollection_oaShape_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaShape_oaBlock)\n"
"    Calls: oaCollection_oaShape_oaBlock(const oaCollection_oaShape_oaBlock& coll)\n"
"    Signature: oaCollection_oaShape_oaBlock||cref-oaCollection_oaShape_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaShape_oaBlock)\n"
"    Calls: (const oaCollection_oaShape_oaBlock&)\n"
"    Signature: oaCollection_oaShape_oaBlock||cref-oaCollection_oaShape_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaShape_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaShape_oaBlock",
    sizeof(PyoaCollection_oaShape_oaBlockObject),
    0,
    (destructor)oaCollection_oaShape_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaShape_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaShape_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaShape_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaShape_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaShape_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaShape_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaShape_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaShape_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaShape_oaBlock",
           (PyObject*)(&PyoaCollection_oaShape_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaShape_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaShape_oaLPPHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaLPPHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaShape_oaLPPHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaShape_oaLPPHeaderObject* self = (PyoaCollection_oaShape_oaLPPHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaShape_oaLPPHeader)
    {
        PyParamoaCollection_oaShape_oaLPPHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaShape_oaLPPHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaShape_oaLPPHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaShape_oaLPPHeader, Choices are:\n"
        "    (oaCollection_oaShape_oaLPPHeader)\n"
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
oaCollection_oaShape_oaLPPHeader_tp_dealloc(PyoaCollection_oaShape_oaLPPHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaShape_oaLPPHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaLPPHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaShape_oaLPPHeader value;
    int convert_status=PyoaCollection_oaShape_oaLPPHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaShape_oaLPPHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaShape_oaLPPHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaShape_oaLPPHeader v1;
    PyParamoaCollection_oaShape_oaLPPHeader v2;
    int convert_status1=PyoaCollection_oaShape_oaLPPHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaShape_oaLPPHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaShape_oaLPPHeader_Convert(PyObject* ob,PyParamoaCollection_oaShape_oaLPPHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaShape_oaLPPHeader_Check(ob)) {
        result->SetData( (oaCollection_oaShape_oaLPPHeader*) ((PyoaCollection_oaShape_oaLPPHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaShape_oaLPPHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaShape_oaLPPHeader_FromoaCollection_oaShape_oaLPPHeader(oaCollection_oaShape_oaLPPHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaShape_oaLPPHeader_Type.tp_alloc(&PyoaCollection_oaShape_oaLPPHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaShape_oaLPPHeaderObject* self = (PyoaCollection_oaShape_oaLPPHeaderObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaShape_oaLPPHeader_includes_doc[] = 
"Class: oaCollection_oaShape_oaLPPHeader, Function: includes\n"
"  Paramegers: (oaShape)\n"
"    Calls: oaBoolean includes(const oaShape* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaShape,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaShape_oaLPPHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaShape_oaLPPHeader data;
    int convert_status=PyoaCollection_oaShape_oaLPPHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaShape_oaLPPHeaderObject* self=(PyoaCollection_oaShape_oaLPPHeaderObject*)ob;

    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaShape_Convert,&p1)) {
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

static char oaCollection_oaShape_oaLPPHeader_assign_doc[] = 
"Class: oaCollection_oaShape_oaLPPHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaShape_oaLPPHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaShape_oaLPPHeader data;
  int convert_status=PyoaCollection_oaShape_oaLPPHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaShape_oaLPPHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaShape_oaLPPHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaShape_oaLPPHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaShape_oaLPPHeader_includes,METH_VARARGS,oaCollection_oaShape_oaLPPHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaShape_oaLPPHeader_tp_assign,METH_VARARGS,oaCollection_oaShape_oaLPPHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaShape_oaLPPHeader_doc[] = 
"Class: oaCollection_oaShape_oaLPPHeader\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaShape_oaLPPHeader)\n"
"    Calls: oaCollection_oaShape_oaLPPHeader(const oaCollection_oaShape_oaLPPHeader& coll)\n"
"    Signature: oaCollection_oaShape_oaLPPHeader||cref-oaCollection_oaShape_oaLPPHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaShape_oaLPPHeader)\n"
"    Calls: (const oaCollection_oaShape_oaLPPHeader&)\n"
"    Signature: oaCollection_oaShape_oaLPPHeader||cref-oaCollection_oaShape_oaLPPHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaShape_oaLPPHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaShape_oaLPPHeader",
    sizeof(PyoaCollection_oaShape_oaLPPHeaderObject),
    0,
    (destructor)oaCollection_oaShape_oaLPPHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaShape_oaLPPHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaShape_oaLPPHeader_tp_repr,	/* tp_repr */
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
    oaCollection_oaShape_oaLPPHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaShape_oaLPPHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaShape_oaLPPHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaShape_oaLPPHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaShape_oaLPPHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaShape_oaLPPHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaShape_oaLPPHeader",
           (PyObject*)(&PyoaCollection_oaShape_oaLPPHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaShape_oaLPPHeader\n");
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
// Wrapper Implementation for Class: oaCollection_oaShape_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaShape_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaShape_oaNetObject* self = (PyoaCollection_oaShape_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaShape_oaNet)
    {
        PyParamoaCollection_oaShape_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaShape_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaShape_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaShape_oaNet, Choices are:\n"
        "    (oaCollection_oaShape_oaNet)\n"
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
oaCollection_oaShape_oaNet_tp_dealloc(PyoaCollection_oaShape_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaShape_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaShape_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaShape_oaNet value;
    int convert_status=PyoaCollection_oaShape_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaShape_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaShape_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaShape_oaNet v1;
    PyParamoaCollection_oaShape_oaNet v2;
    int convert_status1=PyoaCollection_oaShape_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaShape_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaShape_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaShape_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaShape_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaShape_oaNet*) ((PyoaCollection_oaShape_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaShape_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaShape_oaNet_FromoaCollection_oaShape_oaNet(oaCollection_oaShape_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaShape_oaNet_Type.tp_alloc(&PyoaCollection_oaShape_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaShape_oaNetObject* self = (PyoaCollection_oaShape_oaNetObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaShape_oaNet_includes_doc[] = 
"Class: oaCollection_oaShape_oaNet, Function: includes\n"
"  Paramegers: (oaShape)\n"
"    Calls: oaBoolean includes(const oaShape* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaShape,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaShape_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaShape_oaNet data;
    int convert_status=PyoaCollection_oaShape_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaShape_oaNetObject* self=(PyoaCollection_oaShape_oaNetObject*)ob;

    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaShape_Convert,&p1)) {
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

static char oaCollection_oaShape_oaNet_assign_doc[] = 
"Class: oaCollection_oaShape_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaShape_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaShape_oaNet data;
  int convert_status=PyoaCollection_oaShape_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaShape_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaShape_oaNet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaShape_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaShape_oaNet_includes,METH_VARARGS,oaCollection_oaShape_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaShape_oaNet_tp_assign,METH_VARARGS,oaCollection_oaShape_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaShape_oaNet_doc[] = 
"Class: oaCollection_oaShape_oaNet\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaShape_oaNet)\n"
"    Calls: oaCollection_oaShape_oaNet(const oaCollection_oaShape_oaNet& coll)\n"
"    Signature: oaCollection_oaShape_oaNet||cref-oaCollection_oaShape_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaShape_oaNet)\n"
"    Calls: (const oaCollection_oaShape_oaNet&)\n"
"    Signature: oaCollection_oaShape_oaNet||cref-oaCollection_oaShape_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaShape_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaShape_oaNet",
    sizeof(PyoaCollection_oaShape_oaNetObject),
    0,
    (destructor)oaCollection_oaShape_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaShape_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaShape_oaNet_tp_repr,	/* tp_repr */
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
    oaCollection_oaShape_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaShape_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaShape_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaShape_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaShape_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaShape_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaShape_oaNet",
           (PyObject*)(&PyoaCollection_oaShape_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaShape_oaNet\n");
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
// Wrapper Implementation for Class: oaCollection_oaSimpleConstraint_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSimpleConstraint_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSimpleConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupCollection*)  new oaCollection_oaSimpleConstraint_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSimpleConstraint_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaSimpleConstraint_oaConstraintGroup)\n"
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
oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_dealloc(PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSimpleConstraint_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[71];
    sprintf(buffer,"<oaCollection_oaSimpleConstraint_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup v1;
    PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaSimpleConstraint_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaSimpleConstraint_oaConstraintGroup*) ((PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSimpleConstraint_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSimpleConstraint_oaConstraintGroup_FromoaCollection_oaSimpleConstraint_oaConstraintGroup(oaCollection_oaSimpleConstraint_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject*)bself;
        self->value = (oaConstraintInGroupCollection*)  data;
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
static char oaCollection_oaSimpleConstraint_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaSimpleConstraint_oaConstraintGroup\n"
"  Class type oaCollection_oaSimpleConstraint_oaConstraintGroup\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSimpleConstraint_oaConstraintGroup)\n"
"    Calls: oaCollection_oaSimpleConstraint_oaConstraintGroup(const oaCollection_oaSimpleConstraint_oaConstraintGroup& c)\n"
"    Signature: oaCollection_oaSimpleConstraint_oaConstraintGroup||cref-oaCollection_oaSimpleConstraint_oaConstraintGroup,\n"
"    Constructor oaCollection_oaSimpleConstraint_oaConstraintGroup\n"
"  Paramegers: (oaCollection_oaSimpleConstraint_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaSimpleConstraint_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaSimpleConstraint_oaConstraintGroup||cref-oaCollection_oaSimpleConstraint_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSimpleConstraint_oaConstraintGroup",
    sizeof(PyoaCollection_oaSimpleConstraint_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSimpleConstraint_oaConstraintGroup_tp_repr,	/* tp_repr */
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
    oaCollection_oaSimpleConstraint_oaConstraintGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintInGroupCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSimpleConstraint_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSimpleConstraint_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSimpleConstraint_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSimpleConstraint_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaSimpleConstraint_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSimpleConstraint_oaConstraintGroup\n");
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
// Wrapper Implementation for Class: oaCollection_oaSiteDef_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSiteDef_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSiteDef_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSiteDef_oaTechObject* self = (PyoaCollection_oaSiteDef_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSiteDef_oaTech)
    {
        PyParamoaCollection_oaSiteDef_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSiteDef_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSiteDef_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSiteDef_oaTech, Choices are:\n"
        "    (oaCollection_oaSiteDef_oaTech)\n"
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
oaCollection_oaSiteDef_oaTech_tp_dealloc(PyoaCollection_oaSiteDef_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSiteDef_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSiteDef_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSiteDef_oaTech value;
    int convert_status=PyoaCollection_oaSiteDef_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaSiteDef_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSiteDef_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSiteDef_oaTech v1;
    PyParamoaCollection_oaSiteDef_oaTech v2;
    int convert_status1=PyoaCollection_oaSiteDef_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSiteDef_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSiteDef_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaSiteDef_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSiteDef_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaSiteDef_oaTech*) ((PyoaCollection_oaSiteDef_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSiteDef_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSiteDef_oaTech_FromoaCollection_oaSiteDef_oaTech(oaCollection_oaSiteDef_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSiteDef_oaTech_Type.tp_alloc(&PyoaCollection_oaSiteDef_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSiteDef_oaTechObject* self = (PyoaCollection_oaSiteDef_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSiteDef_oaTech_includes_doc[] = 
"Class: oaCollection_oaSiteDef_oaTech, Function: includes\n"
"  Paramegers: (oaSiteDef)\n"
"    Calls: oaBoolean includes(const oaSiteDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSiteDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSiteDef_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSiteDef_oaTech data;
    int convert_status=PyoaCollection_oaSiteDef_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSiteDef_oaTechObject* self=(PyoaCollection_oaSiteDef_oaTechObject*)ob;

    PyParamoaSiteDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSiteDef_Convert,&p1)) {
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

static char oaCollection_oaSiteDef_oaTech_assign_doc[] = 
"Class: oaCollection_oaSiteDef_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSiteDef_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSiteDef_oaTech data;
  int convert_status=PyoaCollection_oaSiteDef_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSiteDef_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSiteDef_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSiteDef_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSiteDef_oaTech_includes,METH_VARARGS,oaCollection_oaSiteDef_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSiteDef_oaTech_tp_assign,METH_VARARGS,oaCollection_oaSiteDef_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSiteDef_oaTech_doc[] = 
"Class: oaCollection_oaSiteDef_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSiteDef_oaTech)\n"
"    Calls: oaCollection_oaSiteDef_oaTech(const oaCollection_oaSiteDef_oaTech& coll)\n"
"    Signature: oaCollection_oaSiteDef_oaTech||cref-oaCollection_oaSiteDef_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSiteDef_oaTech)\n"
"    Calls: (const oaCollection_oaSiteDef_oaTech&)\n"
"    Signature: oaCollection_oaSiteDef_oaTech||cref-oaCollection_oaSiteDef_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSiteDef_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSiteDef_oaTech",
    sizeof(PyoaCollection_oaSiteDef_oaTechObject),
    0,
    (destructor)oaCollection_oaSiteDef_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSiteDef_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSiteDef_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaSiteDef_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSiteDef_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSiteDef_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSiteDef_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSiteDef_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSiteDef_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSiteDef_oaTech",
           (PyObject*)(&PyoaCollection_oaSiteDef_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSiteDef_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaSteiner_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSteiner_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSteiner_oaBlockObject* self = (PyoaCollection_oaSteiner_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSteiner_oaBlock)
    {
        PyParamoaCollection_oaSteiner_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSteiner_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSteiner_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSteiner_oaBlock, Choices are:\n"
        "    (oaCollection_oaSteiner_oaBlock)\n"
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
oaCollection_oaSteiner_oaBlock_tp_dealloc(PyoaCollection_oaSteiner_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSteiner_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSteiner_oaBlock value;
    int convert_status=PyoaCollection_oaSteiner_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaSteiner_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSteiner_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSteiner_oaBlock v1;
    PyParamoaCollection_oaSteiner_oaBlock v2;
    int convert_status1=PyoaCollection_oaSteiner_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSteiner_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSteiner_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaSteiner_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSteiner_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaSteiner_oaBlock*) ((PyoaCollection_oaSteiner_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSteiner_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSteiner_oaBlock_FromoaCollection_oaSteiner_oaBlock(oaCollection_oaSteiner_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSteiner_oaBlock_Type.tp_alloc(&PyoaCollection_oaSteiner_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSteiner_oaBlockObject* self = (PyoaCollection_oaSteiner_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSteiner_oaBlock_includes_doc[] = 
"Class: oaCollection_oaSteiner_oaBlock, Function: includes\n"
"  Paramegers: (oaSteiner)\n"
"    Calls: oaBoolean includes(const oaSteiner* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSteiner,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSteiner_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSteiner_oaBlock data;
    int convert_status=PyoaCollection_oaSteiner_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSteiner_oaBlockObject* self=(PyoaCollection_oaSteiner_oaBlockObject*)ob;

    PyParamoaSteiner p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSteiner_Convert,&p1)) {
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

static char oaCollection_oaSteiner_oaBlock_assign_doc[] = 
"Class: oaCollection_oaSteiner_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSteiner_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSteiner_oaBlock data;
  int convert_status=PyoaCollection_oaSteiner_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSteiner_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSteiner_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSteiner_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSteiner_oaBlock_includes,METH_VARARGS,oaCollection_oaSteiner_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSteiner_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaSteiner_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSteiner_oaBlock_doc[] = 
"Class: oaCollection_oaSteiner_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSteiner_oaBlock)\n"
"    Calls: oaCollection_oaSteiner_oaBlock(const oaCollection_oaSteiner_oaBlock& coll)\n"
"    Signature: oaCollection_oaSteiner_oaBlock||cref-oaCollection_oaSteiner_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSteiner_oaBlock)\n"
"    Calls: (const oaCollection_oaSteiner_oaBlock&)\n"
"    Signature: oaCollection_oaSteiner_oaBlock||cref-oaCollection_oaSteiner_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSteiner_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSteiner_oaBlock",
    sizeof(PyoaCollection_oaSteiner_oaBlockObject),
    0,
    (destructor)oaCollection_oaSteiner_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSteiner_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSteiner_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaSteiner_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSteiner_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSteiner_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSteiner_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSteiner_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSteiner_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSteiner_oaBlock",
           (PyObject*)(&PyoaCollection_oaSteiner_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSteiner_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaSteiner_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSteiner_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSteiner_oaLayerHeaderObject* self = (PyoaCollection_oaSteiner_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSteiner_oaLayerHeader)
    {
        PyParamoaCollection_oaSteiner_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSteiner_oaLayerHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSteiner_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSteiner_oaLayerHeader, Choices are:\n"
        "    (oaCollection_oaSteiner_oaLayerHeader)\n"
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
oaCollection_oaSteiner_oaLayerHeader_tp_dealloc(PyoaCollection_oaSteiner_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSteiner_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSteiner_oaLayerHeader value;
    int convert_status=PyoaCollection_oaSteiner_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaSteiner_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSteiner_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSteiner_oaLayerHeader v1;
    PyParamoaCollection_oaSteiner_oaLayerHeader v2;
    int convert_status1=PyoaCollection_oaSteiner_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSteiner_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSteiner_oaLayerHeader_Convert(PyObject* ob,PyParamoaCollection_oaSteiner_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSteiner_oaLayerHeader_Check(ob)) {
        result->SetData( (oaCollection_oaSteiner_oaLayerHeader*) ((PyoaCollection_oaSteiner_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSteiner_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSteiner_oaLayerHeader_FromoaCollection_oaSteiner_oaLayerHeader(oaCollection_oaSteiner_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSteiner_oaLayerHeader_Type.tp_alloc(&PyoaCollection_oaSteiner_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSteiner_oaLayerHeaderObject* self = (PyoaCollection_oaSteiner_oaLayerHeaderObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSteiner_oaLayerHeader_includes_doc[] = 
"Class: oaCollection_oaSteiner_oaLayerHeader, Function: includes\n"
"  Paramegers: (oaSteiner)\n"
"    Calls: oaBoolean includes(const oaSteiner* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSteiner,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSteiner_oaLayerHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSteiner_oaLayerHeader data;
    int convert_status=PyoaCollection_oaSteiner_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSteiner_oaLayerHeaderObject* self=(PyoaCollection_oaSteiner_oaLayerHeaderObject*)ob;

    PyParamoaSteiner p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSteiner_Convert,&p1)) {
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

static char oaCollection_oaSteiner_oaLayerHeader_assign_doc[] = 
"Class: oaCollection_oaSteiner_oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSteiner_oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSteiner_oaLayerHeader data;
  int convert_status=PyoaCollection_oaSteiner_oaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSteiner_oaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSteiner_oaLayerHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSteiner_oaLayerHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSteiner_oaLayerHeader_includes,METH_VARARGS,oaCollection_oaSteiner_oaLayerHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSteiner_oaLayerHeader_tp_assign,METH_VARARGS,oaCollection_oaSteiner_oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSteiner_oaLayerHeader_doc[] = 
"Class: oaCollection_oaSteiner_oaLayerHeader\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSteiner_oaLayerHeader)\n"
"    Calls: oaCollection_oaSteiner_oaLayerHeader(const oaCollection_oaSteiner_oaLayerHeader& coll)\n"
"    Signature: oaCollection_oaSteiner_oaLayerHeader||cref-oaCollection_oaSteiner_oaLayerHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSteiner_oaLayerHeader)\n"
"    Calls: (const oaCollection_oaSteiner_oaLayerHeader&)\n"
"    Signature: oaCollection_oaSteiner_oaLayerHeader||cref-oaCollection_oaSteiner_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSteiner_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSteiner_oaLayerHeader",
    sizeof(PyoaCollection_oaSteiner_oaLayerHeaderObject),
    0,
    (destructor)oaCollection_oaSteiner_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSteiner_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSteiner_oaLayerHeader_tp_repr,	/* tp_repr */
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
    oaCollection_oaSteiner_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSteiner_oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSteiner_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSteiner_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSteiner_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSteiner_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSteiner_oaLayerHeader",
           (PyObject*)(&PyoaCollection_oaSteiner_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSteiner_oaLayerHeader\n");
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
// Wrapper Implementation for Class: oaCollection_oaSteiner_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSteiner_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSteiner_oaNetObject* self = (PyoaCollection_oaSteiner_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSteiner_oaNet)
    {
        PyParamoaCollection_oaSteiner_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSteiner_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSteiner_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSteiner_oaNet, Choices are:\n"
        "    (oaCollection_oaSteiner_oaNet)\n"
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
oaCollection_oaSteiner_oaNet_tp_dealloc(PyoaCollection_oaSteiner_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSteiner_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSteiner_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSteiner_oaNet value;
    int convert_status=PyoaCollection_oaSteiner_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaSteiner_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSteiner_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSteiner_oaNet v1;
    PyParamoaCollection_oaSteiner_oaNet v2;
    int convert_status1=PyoaCollection_oaSteiner_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSteiner_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSteiner_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaSteiner_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSteiner_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaSteiner_oaNet*) ((PyoaCollection_oaSteiner_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSteiner_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSteiner_oaNet_FromoaCollection_oaSteiner_oaNet(oaCollection_oaSteiner_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSteiner_oaNet_Type.tp_alloc(&PyoaCollection_oaSteiner_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSteiner_oaNetObject* self = (PyoaCollection_oaSteiner_oaNetObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSteiner_oaNet_includes_doc[] = 
"Class: oaCollection_oaSteiner_oaNet, Function: includes\n"
"  Paramegers: (oaSteiner)\n"
"    Calls: oaBoolean includes(const oaSteiner* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSteiner,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSteiner_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSteiner_oaNet data;
    int convert_status=PyoaCollection_oaSteiner_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSteiner_oaNetObject* self=(PyoaCollection_oaSteiner_oaNetObject*)ob;

    PyParamoaSteiner p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSteiner_Convert,&p1)) {
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

static char oaCollection_oaSteiner_oaNet_assign_doc[] = 
"Class: oaCollection_oaSteiner_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSteiner_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSteiner_oaNet data;
  int convert_status=PyoaCollection_oaSteiner_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSteiner_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSteiner_oaNet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSteiner_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSteiner_oaNet_includes,METH_VARARGS,oaCollection_oaSteiner_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSteiner_oaNet_tp_assign,METH_VARARGS,oaCollection_oaSteiner_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSteiner_oaNet_doc[] = 
"Class: oaCollection_oaSteiner_oaNet\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSteiner_oaNet)\n"
"    Calls: oaCollection_oaSteiner_oaNet(const oaCollection_oaSteiner_oaNet& coll)\n"
"    Signature: oaCollection_oaSteiner_oaNet||cref-oaCollection_oaSteiner_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSteiner_oaNet)\n"
"    Calls: (const oaCollection_oaSteiner_oaNet&)\n"
"    Signature: oaCollection_oaSteiner_oaNet||cref-oaCollection_oaSteiner_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSteiner_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSteiner_oaNet",
    sizeof(PyoaCollection_oaSteiner_oaNetObject),
    0,
    (destructor)oaCollection_oaSteiner_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSteiner_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSteiner_oaNet_tp_repr,	/* tp_repr */
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
    oaCollection_oaSteiner_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSteiner_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSteiner_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSteiner_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSteiner_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSteiner_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSteiner_oaNet",
           (PyObject*)(&PyoaCollection_oaSteiner_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSteiner_oaNet\n");
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
// Wrapper Implementation for Class: oaCollection_oaStepperMap_oaWaferDesc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaStepperMap_oaWaferDesc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaStepperMap_oaWaferDesc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaStepperMap_oaWaferDescObject* self = (PyoaCollection_oaStepperMap_oaWaferDescObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaStepperMap_oaWaferDesc)
    {
        PyParamoaCollection_oaStepperMap_oaWaferDesc p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaStepperMap_oaWaferDesc_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaStepperMap_oaWaferDesc(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaStepperMap_oaWaferDesc, Choices are:\n"
        "    (oaCollection_oaStepperMap_oaWaferDesc)\n"
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
oaCollection_oaStepperMap_oaWaferDesc_tp_dealloc(PyoaCollection_oaStepperMap_oaWaferDescObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaStepperMap_oaWaferDesc*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaStepperMap_oaWaferDesc_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaStepperMap_oaWaferDesc value;
    int convert_status=PyoaCollection_oaStepperMap_oaWaferDesc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaStepperMap_oaWaferDesc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaStepperMap_oaWaferDesc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaStepperMap_oaWaferDesc v1;
    PyParamoaCollection_oaStepperMap_oaWaferDesc v2;
    int convert_status1=PyoaCollection_oaStepperMap_oaWaferDesc_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaStepperMap_oaWaferDesc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaStepperMap_oaWaferDesc_Convert(PyObject* ob,PyParamoaCollection_oaStepperMap_oaWaferDesc* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaStepperMap_oaWaferDesc_Check(ob)) {
        result->SetData( (oaCollection_oaStepperMap_oaWaferDesc*) ((PyoaCollection_oaStepperMap_oaWaferDescObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaStepperMap_oaWaferDesc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaStepperMap_oaWaferDesc_FromoaCollection_oaStepperMap_oaWaferDesc(oaCollection_oaStepperMap_oaWaferDesc* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaStepperMap_oaWaferDesc_Type.tp_alloc(&PyoaCollection_oaStepperMap_oaWaferDesc_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaStepperMap_oaWaferDescObject* self = (PyoaCollection_oaStepperMap_oaWaferDescObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaStepperMap_oaWaferDesc_includes_doc[] = 
"Class: oaCollection_oaStepperMap_oaWaferDesc, Function: includes\n"
"  Paramegers: (oaStepperMap)\n"
"    Calls: oaBoolean includes(const oaStepperMap* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaStepperMap,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaStepperMap_oaWaferDesc_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaStepperMap_oaWaferDesc data;
    int convert_status=PyoaCollection_oaStepperMap_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaStepperMap_oaWaferDescObject* self=(PyoaCollection_oaStepperMap_oaWaferDescObject*)ob;

    PyParamoaStepperMap p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaStepperMap_Convert,&p1)) {
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

static char oaCollection_oaStepperMap_oaWaferDesc_assign_doc[] = 
"Class: oaCollection_oaStepperMap_oaWaferDesc, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaStepperMap_oaWaferDesc_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaStepperMap_oaWaferDesc data;
  int convert_status=PyoaCollection_oaStepperMap_oaWaferDesc_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaStepperMap_oaWaferDesc p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaStepperMap_oaWaferDesc_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaStepperMap_oaWaferDesc_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaStepperMap_oaWaferDesc_includes,METH_VARARGS,oaCollection_oaStepperMap_oaWaferDesc_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaStepperMap_oaWaferDesc_tp_assign,METH_VARARGS,oaCollection_oaStepperMap_oaWaferDesc_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaStepperMap_oaWaferDesc_doc[] = 
"Class: oaCollection_oaStepperMap_oaWaferDesc\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaStepperMap_oaWaferDesc)\n"
"    Calls: oaCollection_oaStepperMap_oaWaferDesc(const oaCollection_oaStepperMap_oaWaferDesc& coll)\n"
"    Signature: oaCollection_oaStepperMap_oaWaferDesc||cref-oaCollection_oaStepperMap_oaWaferDesc,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaStepperMap_oaWaferDesc)\n"
"    Calls: (const oaCollection_oaStepperMap_oaWaferDesc&)\n"
"    Signature: oaCollection_oaStepperMap_oaWaferDesc||cref-oaCollection_oaStepperMap_oaWaferDesc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaStepperMap_oaWaferDesc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaStepperMap_oaWaferDesc",
    sizeof(PyoaCollection_oaStepperMap_oaWaferDescObject),
    0,
    (destructor)oaCollection_oaStepperMap_oaWaferDesc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaStepperMap_oaWaferDesc_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaStepperMap_oaWaferDesc_tp_repr,	/* tp_repr */
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
    oaCollection_oaStepperMap_oaWaferDesc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaStepperMap_oaWaferDesc_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaStepperMap_oaWaferDesc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaStepperMap_oaWaferDesc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaStepperMap_oaWaferDesc_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaStepperMap_oaWaferDesc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaStepperMap_oaWaferDesc",
           (PyObject*)(&PyoaCollection_oaStepperMap_oaWaferDesc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaStepperMap_oaWaferDesc\n");
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
// Wrapper Implementation for Class: oaCollection_oaSubNetwork_oaDevice
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSubNetwork_oaDevice_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSubNetwork_oaDeviceObject* self = (PyoaCollection_oaSubNetwork_oaDeviceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSubNetwork_oaDevice)
    {
        PyParamoaCollection_oaSubNetwork_oaDevice p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSubNetwork_oaDevice_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSubNetwork_oaDevice(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSubNetwork_oaDevice, Choices are:\n"
        "    (oaCollection_oaSubNetwork_oaDevice)\n"
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
oaCollection_oaSubNetwork_oaDevice_tp_dealloc(PyoaCollection_oaSubNetwork_oaDeviceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSubNetwork_oaDevice*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaDevice_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSubNetwork_oaDevice value;
    int convert_status=PyoaCollection_oaSubNetwork_oaDevice_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaSubNetwork_oaDevice::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSubNetwork_oaDevice_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSubNetwork_oaDevice v1;
    PyParamoaCollection_oaSubNetwork_oaDevice v2;
    int convert_status1=PyoaCollection_oaSubNetwork_oaDevice_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSubNetwork_oaDevice_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSubNetwork_oaDevice_Convert(PyObject* ob,PyParamoaCollection_oaSubNetwork_oaDevice* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSubNetwork_oaDevice_Check(ob)) {
        result->SetData( (oaCollection_oaSubNetwork_oaDevice*) ((PyoaCollection_oaSubNetwork_oaDeviceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSubNetwork_oaDevice Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSubNetwork_oaDevice_FromoaCollection_oaSubNetwork_oaDevice(oaCollection_oaSubNetwork_oaDevice* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSubNetwork_oaDevice_Type.tp_alloc(&PyoaCollection_oaSubNetwork_oaDevice_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSubNetwork_oaDeviceObject* self = (PyoaCollection_oaSubNetwork_oaDeviceObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSubNetwork_oaDevice_includes_doc[] = 
"Class: oaCollection_oaSubNetwork_oaDevice, Function: includes\n"
"  Paramegers: (oaSubNetwork)\n"
"    Calls: oaBoolean includes(const oaSubNetwork* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSubNetwork,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaDevice_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSubNetwork_oaDevice data;
    int convert_status=PyoaCollection_oaSubNetwork_oaDevice_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSubNetwork_oaDeviceObject* self=(PyoaCollection_oaSubNetwork_oaDeviceObject*)ob;

    PyParamoaSubNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubNetwork_Convert,&p1)) {
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

static char oaCollection_oaSubNetwork_oaDevice_assign_doc[] = 
"Class: oaCollection_oaSubNetwork_oaDevice, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaDevice_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSubNetwork_oaDevice data;
  int convert_status=PyoaCollection_oaSubNetwork_oaDevice_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSubNetwork_oaDevice p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSubNetwork_oaDevice_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSubNetwork_oaDevice_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSubNetwork_oaDevice_includes,METH_VARARGS,oaCollection_oaSubNetwork_oaDevice_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSubNetwork_oaDevice_tp_assign,METH_VARARGS,oaCollection_oaSubNetwork_oaDevice_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSubNetwork_oaDevice_doc[] = 
"Class: oaCollection_oaSubNetwork_oaDevice\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaDevice)\n"
"    Calls: oaCollection_oaSubNetwork_oaDevice(const oaCollection_oaSubNetwork_oaDevice& coll)\n"
"    Signature: oaCollection_oaSubNetwork_oaDevice||cref-oaCollection_oaSubNetwork_oaDevice,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaDevice)\n"
"    Calls: (const oaCollection_oaSubNetwork_oaDevice&)\n"
"    Signature: oaCollection_oaSubNetwork_oaDevice||cref-oaCollection_oaSubNetwork_oaDevice,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSubNetwork_oaDevice_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSubNetwork_oaDevice",
    sizeof(PyoaCollection_oaSubNetwork_oaDeviceObject),
    0,
    (destructor)oaCollection_oaSubNetwork_oaDevice_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSubNetwork_oaDevice_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSubNetwork_oaDevice_tp_repr,	/* tp_repr */
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
    oaCollection_oaSubNetwork_oaDevice_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSubNetwork_oaDevice_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSubNetwork_oaDevice_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSubNetwork_oaDevice_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSubNetwork_oaDevice_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSubNetwork_oaDevice\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSubNetwork_oaDevice",
           (PyObject*)(&PyoaCollection_oaSubNetwork_oaDevice_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSubNetwork_oaDevice\n");
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
// Wrapper Implementation for Class: oaCollection_oaSubNetwork_oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSubNetwork_oaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSubNetwork_oaNodeObject* self = (PyoaCollection_oaSubNetwork_oaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSubNetwork_oaNode)
    {
        PyParamoaCollection_oaSubNetwork_oaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSubNetwork_oaNode_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSubNetwork_oaNode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSubNetwork_oaNode, Choices are:\n"
        "    (oaCollection_oaSubNetwork_oaNode)\n"
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
oaCollection_oaSubNetwork_oaNode_tp_dealloc(PyoaCollection_oaSubNetwork_oaNodeObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSubNetwork_oaNode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaNode_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSubNetwork_oaNode value;
    int convert_status=PyoaCollection_oaSubNetwork_oaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaSubNetwork_oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSubNetwork_oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSubNetwork_oaNode v1;
    PyParamoaCollection_oaSubNetwork_oaNode v2;
    int convert_status1=PyoaCollection_oaSubNetwork_oaNode_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSubNetwork_oaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSubNetwork_oaNode_Convert(PyObject* ob,PyParamoaCollection_oaSubNetwork_oaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSubNetwork_oaNode_Check(ob)) {
        result->SetData( (oaCollection_oaSubNetwork_oaNode*) ((PyoaCollection_oaSubNetwork_oaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSubNetwork_oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSubNetwork_oaNode_FromoaCollection_oaSubNetwork_oaNode(oaCollection_oaSubNetwork_oaNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSubNetwork_oaNode_Type.tp_alloc(&PyoaCollection_oaSubNetwork_oaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSubNetwork_oaNodeObject* self = (PyoaCollection_oaSubNetwork_oaNodeObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSubNetwork_oaNode_includes_doc[] = 
"Class: oaCollection_oaSubNetwork_oaNode, Function: includes\n"
"  Paramegers: (oaSubNetwork)\n"
"    Calls: oaBoolean includes(const oaSubNetwork* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSubNetwork,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaNode_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSubNetwork_oaNode data;
    int convert_status=PyoaCollection_oaSubNetwork_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSubNetwork_oaNodeObject* self=(PyoaCollection_oaSubNetwork_oaNodeObject*)ob;

    PyParamoaSubNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubNetwork_Convert,&p1)) {
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

static char oaCollection_oaSubNetwork_oaNode_assign_doc[] = 
"Class: oaCollection_oaSubNetwork_oaNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSubNetwork_oaNode data;
  int convert_status=PyoaCollection_oaSubNetwork_oaNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSubNetwork_oaNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSubNetwork_oaNode_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSubNetwork_oaNode_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSubNetwork_oaNode_includes,METH_VARARGS,oaCollection_oaSubNetwork_oaNode_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSubNetwork_oaNode_tp_assign,METH_VARARGS,oaCollection_oaSubNetwork_oaNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSubNetwork_oaNode_doc[] = 
"Class: oaCollection_oaSubNetwork_oaNode\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaNode)\n"
"    Calls: oaCollection_oaSubNetwork_oaNode(const oaCollection_oaSubNetwork_oaNode& coll)\n"
"    Signature: oaCollection_oaSubNetwork_oaNode||cref-oaCollection_oaSubNetwork_oaNode,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaNode)\n"
"    Calls: (const oaCollection_oaSubNetwork_oaNode&)\n"
"    Signature: oaCollection_oaSubNetwork_oaNode||cref-oaCollection_oaSubNetwork_oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSubNetwork_oaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSubNetwork_oaNode",
    sizeof(PyoaCollection_oaSubNetwork_oaNodeObject),
    0,
    (destructor)oaCollection_oaSubNetwork_oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSubNetwork_oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSubNetwork_oaNode_tp_repr,	/* tp_repr */
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
    oaCollection_oaSubNetwork_oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSubNetwork_oaNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSubNetwork_oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSubNetwork_oaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSubNetwork_oaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSubNetwork_oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSubNetwork_oaNode",
           (PyObject*)(&PyoaCollection_oaSubNetwork_oaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSubNetwork_oaNode\n");
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
// Wrapper Implementation for Class: oaCollection_oaSubNetwork_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaSubNetwork_oaParasiticNetworkObject* self = (PyoaCollection_oaSubNetwork_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaSubNetwork_oaParasiticNetwork)
    {
        PyParamoaCollection_oaSubNetwork_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaSubNetwork_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaSubNetwork_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaSubNetwork_oaParasiticNetwork)\n"
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
oaCollection_oaSubNetwork_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaSubNetwork_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaSubNetwork_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaSubNetwork_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaSubNetwork_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaSubNetwork_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaSubNetwork_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaSubNetwork_oaParasiticNetwork v1;
    PyParamoaCollection_oaSubNetwork_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaSubNetwork_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaSubNetwork_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaSubNetwork_oaParasiticNetwork*) ((PyoaCollection_oaSubNetwork_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaSubNetwork_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaSubNetwork_oaParasiticNetwork_FromoaCollection_oaSubNetwork_oaParasiticNetwork(oaCollection_oaSubNetwork_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaSubNetwork_oaParasiticNetworkObject* self = (PyoaCollection_oaSubNetwork_oaParasiticNetworkObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaSubNetwork_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaSubNetwork_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaSubNetwork)\n"
"    Calls: oaBoolean includes(const oaSubNetwork* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaSubNetwork,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaSubNetwork_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaSubNetwork_oaParasiticNetworkObject* self=(PyoaCollection_oaSubNetwork_oaParasiticNetworkObject*)ob;

    PyParamoaSubNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubNetwork_Convert,&p1)) {
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

static char oaCollection_oaSubNetwork_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaSubNetwork_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaSubNetwork_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaSubNetwork_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaSubNetwork_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaSubNetwork_oaParasiticNetwork_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaSubNetwork_oaParasiticNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaSubNetwork_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaSubNetwork_oaParasiticNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaSubNetwork_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaSubNetwork_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaSubNetwork_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaSubNetwork_oaParasiticNetwork\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaSubNetwork_oaParasiticNetwork(const oaCollection_oaSubNetwork_oaParasiticNetwork& coll)\n"
"    Signature: oaCollection_oaSubNetwork_oaParasiticNetwork||cref-oaCollection_oaSubNetwork_oaParasiticNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaSubNetwork_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaSubNetwork_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaSubNetwork_oaParasiticNetwork||cref-oaCollection_oaSubNetwork_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaSubNetwork_oaParasiticNetwork",
    sizeof(PyoaCollection_oaSubNetwork_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaSubNetwork_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaSubNetwork_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaSubNetwork_oaParasiticNetwork_tp_repr,	/* tp_repr */
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
    oaCollection_oaSubNetwork_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaSubNetwork_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaSubNetwork_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaSubNetwork_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaSubNetwork_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaSubNetwork_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaSubNetwork_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaSubNetwork_oaParasiticNetwork\n");
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
// Wrapper Implementation for Class: oaCollection_oaTechHeader_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechHeader_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTechHeader_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTechHeader_oaTechObject* self = (PyoaCollection_oaTechHeader_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTechHeader_oaTech)
    {
        PyParamoaCollection_oaTechHeader_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTechHeader_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTechHeader_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTechHeader_oaTech, Choices are:\n"
        "    (oaCollection_oaTechHeader_oaTech)\n"
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
oaCollection_oaTechHeader_oaTech_tp_dealloc(PyoaCollection_oaTechHeader_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTechHeader_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechHeader_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTechHeader_oaTech value;
    int convert_status=PyoaCollection_oaTechHeader_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaTechHeader_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTechHeader_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTechHeader_oaTech v1;
    PyParamoaCollection_oaTechHeader_oaTech v2;
    int convert_status1=PyoaCollection_oaTechHeader_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTechHeader_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTechHeader_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaTechHeader_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTechHeader_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaTechHeader_oaTech*) ((PyoaCollection_oaTechHeader_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTechHeader_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTechHeader_oaTech_FromoaCollection_oaTechHeader_oaTech(oaCollection_oaTechHeader_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTechHeader_oaTech_Type.tp_alloc(&PyoaCollection_oaTechHeader_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTechHeader_oaTechObject* self = (PyoaCollection_oaTechHeader_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTechHeader_oaTech_includes_doc[] = 
"Class: oaCollection_oaTechHeader_oaTech, Function: includes\n"
"  Paramegers: (oaTechHeader)\n"
"    Calls: oaBoolean includes(const oaTechHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTechHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTechHeader_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTechHeader_oaTech data;
    int convert_status=PyoaCollection_oaTechHeader_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTechHeader_oaTechObject* self=(PyoaCollection_oaTechHeader_oaTechObject*)ob;

    PyParamoaTechHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechHeader_Convert,&p1)) {
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

static char oaCollection_oaTechHeader_oaTech_assign_doc[] = 
"Class: oaCollection_oaTechHeader_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTechHeader_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTechHeader_oaTech data;
  int convert_status=PyoaCollection_oaTechHeader_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTechHeader_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTechHeader_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTechHeader_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTechHeader_oaTech_includes,METH_VARARGS,oaCollection_oaTechHeader_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTechHeader_oaTech_tp_assign,METH_VARARGS,oaCollection_oaTechHeader_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTechHeader_oaTech_doc[] = 
"Class: oaCollection_oaTechHeader_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTechHeader_oaTech)\n"
"    Calls: oaCollection_oaTechHeader_oaTech(const oaCollection_oaTechHeader_oaTech& coll)\n"
"    Signature: oaCollection_oaTechHeader_oaTech||cref-oaCollection_oaTechHeader_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTechHeader_oaTech)\n"
"    Calls: (const oaCollection_oaTechHeader_oaTech&)\n"
"    Signature: oaCollection_oaTechHeader_oaTech||cref-oaCollection_oaTechHeader_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTechHeader_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTechHeader_oaTech",
    sizeof(PyoaCollection_oaTechHeader_oaTechObject),
    0,
    (destructor)oaCollection_oaTechHeader_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTechHeader_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTechHeader_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaTechHeader_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTechHeader_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTechHeader_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTechHeader_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTechHeader_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTechHeader_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTechHeader_oaTech",
           (PyObject*)(&PyoaCollection_oaTechHeader_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTechHeader_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaTechLayerHeader_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechLayerHeader_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTechLayerHeader_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTechLayerHeader_oaTechObject* self = (PyoaCollection_oaTechLayerHeader_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTechLayerHeader_oaTech)
    {
        PyParamoaCollection_oaTechLayerHeader_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTechLayerHeader_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTechLayerHeader_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTechLayerHeader_oaTech, Choices are:\n"
        "    (oaCollection_oaTechLayerHeader_oaTech)\n"
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
oaCollection_oaTechLayerHeader_oaTech_tp_dealloc(PyoaCollection_oaTechLayerHeader_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTechLayerHeader_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechLayerHeader_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTechLayerHeader_oaTech value;
    int convert_status=PyoaCollection_oaTechLayerHeader_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaTechLayerHeader_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTechLayerHeader_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTechLayerHeader_oaTech v1;
    PyParamoaCollection_oaTechLayerHeader_oaTech v2;
    int convert_status1=PyoaCollection_oaTechLayerHeader_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTechLayerHeader_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTechLayerHeader_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaTechLayerHeader_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTechLayerHeader_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaTechLayerHeader_oaTech*) ((PyoaCollection_oaTechLayerHeader_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTechLayerHeader_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTechLayerHeader_oaTech_FromoaCollection_oaTechLayerHeader_oaTech(oaCollection_oaTechLayerHeader_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTechLayerHeader_oaTech_Type.tp_alloc(&PyoaCollection_oaTechLayerHeader_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTechLayerHeader_oaTechObject* self = (PyoaCollection_oaTechLayerHeader_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTechLayerHeader_oaTech_includes_doc[] = 
"Class: oaCollection_oaTechLayerHeader_oaTech, Function: includes\n"
"  Paramegers: (oaTechLayerHeader)\n"
"    Calls: oaBoolean includes(const oaTechLayerHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTechLayerHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTechLayerHeader_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTechLayerHeader_oaTech data;
    int convert_status=PyoaCollection_oaTechLayerHeader_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTechLayerHeader_oaTechObject* self=(PyoaCollection_oaTechLayerHeader_oaTechObject*)ob;

    PyParamoaTechLayerHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechLayerHeader_Convert,&p1)) {
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

static char oaCollection_oaTechLayerHeader_oaTech_assign_doc[] = 
"Class: oaCollection_oaTechLayerHeader_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTechLayerHeader_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTechLayerHeader_oaTech data;
  int convert_status=PyoaCollection_oaTechLayerHeader_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTechLayerHeader_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTechLayerHeader_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTechLayerHeader_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTechLayerHeader_oaTech_includes,METH_VARARGS,oaCollection_oaTechLayerHeader_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTechLayerHeader_oaTech_tp_assign,METH_VARARGS,oaCollection_oaTechLayerHeader_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTechLayerHeader_oaTech_doc[] = 
"Class: oaCollection_oaTechLayerHeader_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTechLayerHeader_oaTech)\n"
"    Calls: oaCollection_oaTechLayerHeader_oaTech(const oaCollection_oaTechLayerHeader_oaTech& coll)\n"
"    Signature: oaCollection_oaTechLayerHeader_oaTech||cref-oaCollection_oaTechLayerHeader_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTechLayerHeader_oaTech)\n"
"    Calls: (const oaCollection_oaTechLayerHeader_oaTech&)\n"
"    Signature: oaCollection_oaTechLayerHeader_oaTech||cref-oaCollection_oaTechLayerHeader_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTechLayerHeader_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTechLayerHeader_oaTech",
    sizeof(PyoaCollection_oaTechLayerHeader_oaTechObject),
    0,
    (destructor)oaCollection_oaTechLayerHeader_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTechLayerHeader_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTechLayerHeader_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaTechLayerHeader_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTechLayerHeader_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTechLayerHeader_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTechLayerHeader_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTechLayerHeader_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTechLayerHeader_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTechLayerHeader_oaTech",
           (PyObject*)(&PyoaCollection_oaTechLayerHeader_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTechLayerHeader_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaTechViaDefHeader_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechViaDefHeader_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTechViaDefHeader_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTechViaDefHeader_oaTechObject* self = (PyoaCollection_oaTechViaDefHeader_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTechViaDefHeader_oaTech)
    {
        PyParamoaCollection_oaTechViaDefHeader_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTechViaDefHeader_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTechViaDefHeader_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTechViaDefHeader_oaTech, Choices are:\n"
        "    (oaCollection_oaTechViaDefHeader_oaTech)\n"
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
oaCollection_oaTechViaDefHeader_oaTech_tp_dealloc(PyoaCollection_oaTechViaDefHeader_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTechViaDefHeader_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTechViaDefHeader_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTechViaDefHeader_oaTech value;
    int convert_status=PyoaCollection_oaTechViaDefHeader_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaTechViaDefHeader_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTechViaDefHeader_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTechViaDefHeader_oaTech v1;
    PyParamoaCollection_oaTechViaDefHeader_oaTech v2;
    int convert_status1=PyoaCollection_oaTechViaDefHeader_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTechViaDefHeader_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTechViaDefHeader_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaTechViaDefHeader_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTechViaDefHeader_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaTechViaDefHeader_oaTech*) ((PyoaCollection_oaTechViaDefHeader_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTechViaDefHeader_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTechViaDefHeader_oaTech_FromoaCollection_oaTechViaDefHeader_oaTech(oaCollection_oaTechViaDefHeader_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTechViaDefHeader_oaTech_Type.tp_alloc(&PyoaCollection_oaTechViaDefHeader_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTechViaDefHeader_oaTechObject* self = (PyoaCollection_oaTechViaDefHeader_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTechViaDefHeader_oaTech_includes_doc[] = 
"Class: oaCollection_oaTechViaDefHeader_oaTech, Function: includes\n"
"  Paramegers: (oaTechViaDefHeader)\n"
"    Calls: oaBoolean includes(const oaTechViaDefHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTechViaDefHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTechViaDefHeader_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTechViaDefHeader_oaTech data;
    int convert_status=PyoaCollection_oaTechViaDefHeader_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTechViaDefHeader_oaTechObject* self=(PyoaCollection_oaTechViaDefHeader_oaTechObject*)ob;

    PyParamoaTechViaDefHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechViaDefHeader_Convert,&p1)) {
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

static char oaCollection_oaTechViaDefHeader_oaTech_assign_doc[] = 
"Class: oaCollection_oaTechViaDefHeader_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTechViaDefHeader_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTechViaDefHeader_oaTech data;
  int convert_status=PyoaCollection_oaTechViaDefHeader_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTechViaDefHeader_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTechViaDefHeader_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTechViaDefHeader_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTechViaDefHeader_oaTech_includes,METH_VARARGS,oaCollection_oaTechViaDefHeader_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTechViaDefHeader_oaTech_tp_assign,METH_VARARGS,oaCollection_oaTechViaDefHeader_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTechViaDefHeader_oaTech_doc[] = 
"Class: oaCollection_oaTechViaDefHeader_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTechViaDefHeader_oaTech)\n"
"    Calls: oaCollection_oaTechViaDefHeader_oaTech(const oaCollection_oaTechViaDefHeader_oaTech& coll)\n"
"    Signature: oaCollection_oaTechViaDefHeader_oaTech||cref-oaCollection_oaTechViaDefHeader_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTechViaDefHeader_oaTech)\n"
"    Calls: (const oaCollection_oaTechViaDefHeader_oaTech&)\n"
"    Signature: oaCollection_oaTechViaDefHeader_oaTech||cref-oaCollection_oaTechViaDefHeader_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTechViaDefHeader_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTechViaDefHeader_oaTech",
    sizeof(PyoaCollection_oaTechViaDefHeader_oaTechObject),
    0,
    (destructor)oaCollection_oaTechViaDefHeader_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTechViaDefHeader_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTechViaDefHeader_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaTechViaDefHeader_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTechViaDefHeader_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTechViaDefHeader_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTechViaDefHeader_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTechViaDefHeader_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTechViaDefHeader_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTechViaDefHeader_oaTech",
           (PyObject*)(&PyoaCollection_oaTechViaDefHeader_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTechViaDefHeader_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaTech_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTech_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTech_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTech_oaTechObject* self = (PyoaCollection_oaTech_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaTech_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaTech_oaTech)
    {
        PyParamoaCollection_oaTech_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTech_oaTech_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaTech_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTech_oaTech, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaCollection_oaTech_oaTech)\n"
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
oaCollection_oaTech_oaTech_tp_dealloc(PyoaCollection_oaTech_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTech_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTech_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTech_oaTech value;
    int convert_status=PyoaCollection_oaTech_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaTech_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTech_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTech_oaTech v1;
    PyParamoaCollection_oaTech_oaTech v2;
    int convert_status1=PyoaCollection_oaTech_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTech_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTech_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaTech_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTech_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaTech_oaTech*) ((PyoaCollection_oaTech_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTech_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTech_oaTech_FromoaCollection_oaTech_oaTech(oaCollection_oaTech_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTech_oaTech_Type.tp_alloc(&PyoaCollection_oaTech_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTech_oaTechObject* self = (PyoaCollection_oaTech_oaTechObject*)bself;
        self->value = (oaDatabaseCollection*)  data;
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
static char oaCollection_oaTech_oaTech_includes_doc[] = 
"Class: oaCollection_oaTech_oaTech, Function: includes\n"
"  Paramegers: (oaTech)\n"
"    Calls: oaBoolean includes(const oaTech* db) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTech,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaTech_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTech_oaTech data;
    int convert_status=PyoaCollection_oaTech_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTech_oaTechObject* self=(PyoaCollection_oaTech_oaTechObject*)ob;

    PyParamoaTech p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTech_Convert,&p1)) {
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

static char oaCollection_oaTech_oaTech_assign_doc[] = 
"Class: oaCollection_oaTech_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTech_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTech_oaTech data;
  int convert_status=PyoaCollection_oaTech_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTech_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTech_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTech_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTech_oaTech_includes,METH_VARARGS,oaCollection_oaTech_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTech_oaTech_tp_assign,METH_VARARGS,oaCollection_oaTech_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTech_oaTech_doc[] = 
"Class: oaCollection_oaTech_oaTech\n"
"  Class type oaCollection_oaTech_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaTech_oaTech(oaUInt4 dbIDIn)\n"
"    Signature: oaCollection_oaTech_oaTech||simple-oaUInt4,\n"
"    Constructor oaCollection_oaTech_oaTech\n"
"  Paramegers: (oaCollection_oaTech_oaTech)\n"
"    Calls: oaCollection_oaTech_oaTech(const oaCollection_oaTech_oaTech& c)\n"
"    Signature: oaCollection_oaTech_oaTech||cref-oaCollection_oaTech_oaTech,\n"
"    Constructor oaCollection_oaTech_oaTech\n"
"  Paramegers: (oaCollection_oaTech_oaTech)\n"
"    Calls: (const oaCollection_oaTech_oaTech&)\n"
"    Signature: oaCollection_oaTech_oaTech||cref-oaCollection_oaTech_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTech_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTech_oaTech",
    sizeof(PyoaCollection_oaTech_oaTechObject),
    0,
    (destructor)oaCollection_oaTech_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTech_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTech_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaTech_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTech_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTech_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTech_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTech_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTech_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTech_oaTech",
           (PyObject*)(&PyoaCollection_oaTech_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTech_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaTerm_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTerm_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTerm_oaBlockObject* self = (PyoaCollection_oaTerm_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTerm_oaBlock)
    {
        PyParamoaCollection_oaTerm_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTerm_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTerm_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTerm_oaBlock, Choices are:\n"
        "    (oaCollection_oaTerm_oaBlock)\n"
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
oaCollection_oaTerm_oaBlock_tp_dealloc(PyoaCollection_oaTerm_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTerm_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTerm_oaBlock value;
    int convert_status=PyoaCollection_oaTerm_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaTerm_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTerm_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTerm_oaBlock v1;
    PyParamoaCollection_oaTerm_oaBlock v2;
    int convert_status1=PyoaCollection_oaTerm_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTerm_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTerm_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaTerm_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTerm_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaTerm_oaBlock*) ((PyoaCollection_oaTerm_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTerm_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTerm_oaBlock_FromoaCollection_oaTerm_oaBlock(oaCollection_oaTerm_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTerm_oaBlock_Type.tp_alloc(&PyoaCollection_oaTerm_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTerm_oaBlockObject* self = (PyoaCollection_oaTerm_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTerm_oaBlock_includes_doc[] = 
"Class: oaCollection_oaTerm_oaBlock, Function: includes\n"
"  Paramegers: (oaTerm)\n"
"    Calls: oaBoolean includes(const oaTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTerm_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTerm_oaBlock data;
    int convert_status=PyoaCollection_oaTerm_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTerm_oaBlockObject* self=(PyoaCollection_oaTerm_oaBlockObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
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

static char oaCollection_oaTerm_oaBlock_assign_doc[] = 
"Class: oaCollection_oaTerm_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTerm_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTerm_oaBlock data;
  int convert_status=PyoaCollection_oaTerm_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTerm_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTerm_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTerm_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTerm_oaBlock_includes,METH_VARARGS,oaCollection_oaTerm_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTerm_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaTerm_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTerm_oaBlock_doc[] = 
"Class: oaCollection_oaTerm_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTerm_oaBlock)\n"
"    Calls: oaCollection_oaTerm_oaBlock(const oaCollection_oaTerm_oaBlock& coll)\n"
"    Signature: oaCollection_oaTerm_oaBlock||cref-oaCollection_oaTerm_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTerm_oaBlock)\n"
"    Calls: (const oaCollection_oaTerm_oaBlock&)\n"
"    Signature: oaCollection_oaTerm_oaBlock||cref-oaCollection_oaTerm_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTerm_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTerm_oaBlock",
    sizeof(PyoaCollection_oaTerm_oaBlockObject),
    0,
    (destructor)oaCollection_oaTerm_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTerm_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTerm_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaTerm_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTerm_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTerm_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTerm_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTerm_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTerm_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTerm_oaBlock",
           (PyObject*)(&PyoaCollection_oaTerm_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTerm_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaTerm_oaBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTerm_oaBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTerm_oaBundleTermObject* self = (PyoaCollection_oaTerm_oaBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTerm_oaBundleTerm)
    {
        PyParamoaCollection_oaTerm_oaBundleTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTerm_oaBundleTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTerm_oaBundleTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTerm_oaBundleTerm, Choices are:\n"
        "    (oaCollection_oaTerm_oaBundleTerm)\n"
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
oaCollection_oaTerm_oaBundleTerm_tp_dealloc(PyoaCollection_oaTerm_oaBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTerm_oaBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTerm_oaBundleTerm value;
    int convert_status=PyoaCollection_oaTerm_oaBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaTerm_oaBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTerm_oaBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTerm_oaBundleTerm v1;
    PyParamoaCollection_oaTerm_oaBundleTerm v2;
    int convert_status1=PyoaCollection_oaTerm_oaBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTerm_oaBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTerm_oaBundleTerm_Convert(PyObject* ob,PyParamoaCollection_oaTerm_oaBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTerm_oaBundleTerm_Check(ob)) {
        result->SetData( (oaCollection_oaTerm_oaBundleTerm*) ((PyoaCollection_oaTerm_oaBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTerm_oaBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTerm_oaBundleTerm_FromoaCollection_oaTerm_oaBundleTerm(oaCollection_oaTerm_oaBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTerm_oaBundleTerm_Type.tp_alloc(&PyoaCollection_oaTerm_oaBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTerm_oaBundleTermObject* self = (PyoaCollection_oaTerm_oaBundleTermObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTerm_oaBundleTerm_includes_doc[] = 
"Class: oaCollection_oaTerm_oaBundleTerm, Function: includes\n"
"  Paramegers: (oaTerm)\n"
"    Calls: oaBoolean includes(const oaTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTerm_oaBundleTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTerm_oaBundleTerm data;
    int convert_status=PyoaCollection_oaTerm_oaBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTerm_oaBundleTermObject* self=(PyoaCollection_oaTerm_oaBundleTermObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
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

static char oaCollection_oaTerm_oaBundleTerm_assign_doc[] = 
"Class: oaCollection_oaTerm_oaBundleTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTerm_oaBundleTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTerm_oaBundleTerm data;
  int convert_status=PyoaCollection_oaTerm_oaBundleTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTerm_oaBundleTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTerm_oaBundleTerm_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTerm_oaBundleTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTerm_oaBundleTerm_includes,METH_VARARGS,oaCollection_oaTerm_oaBundleTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTerm_oaBundleTerm_tp_assign,METH_VARARGS,oaCollection_oaTerm_oaBundleTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTerm_oaBundleTerm_doc[] = 
"Class: oaCollection_oaTerm_oaBundleTerm\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTerm_oaBundleTerm)\n"
"    Calls: oaCollection_oaTerm_oaBundleTerm(const oaCollection_oaTerm_oaBundleTerm& coll)\n"
"    Signature: oaCollection_oaTerm_oaBundleTerm||cref-oaCollection_oaTerm_oaBundleTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTerm_oaBundleTerm)\n"
"    Calls: (const oaCollection_oaTerm_oaBundleTerm&)\n"
"    Signature: oaCollection_oaTerm_oaBundleTerm||cref-oaCollection_oaTerm_oaBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTerm_oaBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTerm_oaBundleTerm",
    sizeof(PyoaCollection_oaTerm_oaBundleTermObject),
    0,
    (destructor)oaCollection_oaTerm_oaBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTerm_oaBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTerm_oaBundleTerm_tp_repr,	/* tp_repr */
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
    oaCollection_oaTerm_oaBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTerm_oaBundleTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTerm_oaBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTerm_oaBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTerm_oaBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTerm_oaBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTerm_oaBundleTerm",
           (PyObject*)(&PyoaCollection_oaTerm_oaBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTerm_oaBundleTerm\n");
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
// Wrapper Implementation for Class: oaCollection_oaTerm_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTerm_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTerm_oaNetObject* self = (PyoaCollection_oaTerm_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTerm_oaNet)
    {
        PyParamoaCollection_oaTerm_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTerm_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTerm_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTerm_oaNet, Choices are:\n"
        "    (oaCollection_oaTerm_oaNet)\n"
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
oaCollection_oaTerm_oaNet_tp_dealloc(PyoaCollection_oaTerm_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTerm_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTerm_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTerm_oaNet value;
    int convert_status=PyoaCollection_oaTerm_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaCollection_oaTerm_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTerm_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTerm_oaNet v1;
    PyParamoaCollection_oaTerm_oaNet v2;
    int convert_status1=PyoaCollection_oaTerm_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTerm_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTerm_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaTerm_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTerm_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaTerm_oaNet*) ((PyoaCollection_oaTerm_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTerm_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTerm_oaNet_FromoaCollection_oaTerm_oaNet(oaCollection_oaTerm_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTerm_oaNet_Type.tp_alloc(&PyoaCollection_oaTerm_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTerm_oaNetObject* self = (PyoaCollection_oaTerm_oaNetObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTerm_oaNet_includes_doc[] = 
"Class: oaCollection_oaTerm_oaNet, Function: includes\n"
"  Paramegers: (oaTerm)\n"
"    Calls: oaBoolean includes(const oaTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTerm_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTerm_oaNet data;
    int convert_status=PyoaCollection_oaTerm_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTerm_oaNetObject* self=(PyoaCollection_oaTerm_oaNetObject*)ob;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
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

static char oaCollection_oaTerm_oaNet_assign_doc[] = 
"Class: oaCollection_oaTerm_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTerm_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTerm_oaNet data;
  int convert_status=PyoaCollection_oaTerm_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTerm_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTerm_oaNet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTerm_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTerm_oaNet_includes,METH_VARARGS,oaCollection_oaTerm_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTerm_oaNet_tp_assign,METH_VARARGS,oaCollection_oaTerm_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTerm_oaNet_doc[] = 
"Class: oaCollection_oaTerm_oaNet\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTerm_oaNet)\n"
"    Calls: oaCollection_oaTerm_oaNet(const oaCollection_oaTerm_oaNet& coll)\n"
"    Signature: oaCollection_oaTerm_oaNet||cref-oaCollection_oaTerm_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTerm_oaNet)\n"
"    Calls: (const oaCollection_oaTerm_oaNet&)\n"
"    Signature: oaCollection_oaTerm_oaNet||cref-oaCollection_oaTerm_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTerm_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTerm_oaNet",
    sizeof(PyoaCollection_oaTerm_oaNetObject),
    0,
    (destructor)oaCollection_oaTerm_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTerm_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTerm_oaNet_tp_repr,	/* tp_repr */
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
    oaCollection_oaTerm_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTerm_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTerm_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTerm_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTerm_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTerm_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTerm_oaNet",
           (PyObject*)(&PyoaCollection_oaTerm_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTerm_oaNet\n");
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
// Wrapper Implementation for Class: oaCollection_oaTrackPattern_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTrackPattern_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaTrackPattern_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaTrackPattern_oaBlockObject* self = (PyoaCollection_oaTrackPattern_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaTrackPattern_oaBlock)
    {
        PyParamoaCollection_oaTrackPattern_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaTrackPattern_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaTrackPattern_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaTrackPattern_oaBlock, Choices are:\n"
        "    (oaCollection_oaTrackPattern_oaBlock)\n"
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
oaCollection_oaTrackPattern_oaBlock_tp_dealloc(PyoaCollection_oaTrackPattern_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaTrackPattern_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaTrackPattern_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaTrackPattern_oaBlock value;
    int convert_status=PyoaCollection_oaTrackPattern_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaTrackPattern_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaTrackPattern_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaTrackPattern_oaBlock v1;
    PyParamoaCollection_oaTrackPattern_oaBlock v2;
    int convert_status1=PyoaCollection_oaTrackPattern_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaTrackPattern_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaTrackPattern_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaTrackPattern_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaTrackPattern_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaTrackPattern_oaBlock*) ((PyoaCollection_oaTrackPattern_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaTrackPattern_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaTrackPattern_oaBlock_FromoaCollection_oaTrackPattern_oaBlock(oaCollection_oaTrackPattern_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaTrackPattern_oaBlock_Type.tp_alloc(&PyoaCollection_oaTrackPattern_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaTrackPattern_oaBlockObject* self = (PyoaCollection_oaTrackPattern_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaTrackPattern_oaBlock_includes_doc[] = 
"Class: oaCollection_oaTrackPattern_oaBlock, Function: includes\n"
"  Paramegers: (oaTrackPattern)\n"
"    Calls: oaBoolean includes(const oaTrackPattern* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaTrackPattern,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaTrackPattern_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaTrackPattern_oaBlock data;
    int convert_status=PyoaCollection_oaTrackPattern_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaTrackPattern_oaBlockObject* self=(PyoaCollection_oaTrackPattern_oaBlockObject*)ob;

    PyParamoaTrackPattern p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTrackPattern_Convert,&p1)) {
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

static char oaCollection_oaTrackPattern_oaBlock_assign_doc[] = 
"Class: oaCollection_oaTrackPattern_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaTrackPattern_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaTrackPattern_oaBlock data;
  int convert_status=PyoaCollection_oaTrackPattern_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaTrackPattern_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaTrackPattern_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaTrackPattern_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaTrackPattern_oaBlock_includes,METH_VARARGS,oaCollection_oaTrackPattern_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaTrackPattern_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaTrackPattern_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaTrackPattern_oaBlock_doc[] = 
"Class: oaCollection_oaTrackPattern_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaTrackPattern_oaBlock)\n"
"    Calls: oaCollection_oaTrackPattern_oaBlock(const oaCollection_oaTrackPattern_oaBlock& coll)\n"
"    Signature: oaCollection_oaTrackPattern_oaBlock||cref-oaCollection_oaTrackPattern_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaTrackPattern_oaBlock)\n"
"    Calls: (const oaCollection_oaTrackPattern_oaBlock&)\n"
"    Signature: oaCollection_oaTrackPattern_oaBlock||cref-oaCollection_oaTrackPattern_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaTrackPattern_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaTrackPattern_oaBlock",
    sizeof(PyoaCollection_oaTrackPattern_oaBlockObject),
    0,
    (destructor)oaCollection_oaTrackPattern_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaTrackPattern_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaTrackPattern_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaTrackPattern_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaTrackPattern_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaTrackPattern_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaTrackPattern_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaTrackPattern_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaTrackPattern_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaTrackPattern_oaBlock",
           (PyObject*)(&PyoaCollection_oaTrackPattern_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaTrackPattern_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaValue_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaValue_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaValue_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaValue_oaDesignObject* self = (PyoaCollection_oaValue_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaValue_oaDesign)
    {
        PyParamoaCollection_oaValue_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaValue_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaValue_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaValue_oaDesign, Choices are:\n"
        "    (oaCollection_oaValue_oaDesign)\n"
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
oaCollection_oaValue_oaDesign_tp_dealloc(PyoaCollection_oaValue_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaValue_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaValue_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaValue_oaDesign value;
    int convert_status=PyoaCollection_oaValue_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaValue_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaValue_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaValue_oaDesign v1;
    PyParamoaCollection_oaValue_oaDesign v2;
    int convert_status1=PyoaCollection_oaValue_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaValue_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaValue_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaValue_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaValue_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaValue_oaDesign*) ((PyoaCollection_oaValue_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaValue_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaValue_oaDesign_FromoaCollection_oaValue_oaDesign(oaCollection_oaValue_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaValue_oaDesign_Type.tp_alloc(&PyoaCollection_oaValue_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaValue_oaDesignObject* self = (PyoaCollection_oaValue_oaDesignObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaValue_oaDesign_includes_doc[] = 
"Class: oaCollection_oaValue_oaDesign, Function: includes\n"
"  Paramegers: (oaValue)\n"
"    Calls: oaBoolean includes(const oaValue* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaValue,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaValue_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaValue_oaDesign data;
    int convert_status=PyoaCollection_oaValue_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaValue_oaDesignObject* self=(PyoaCollection_oaValue_oaDesignObject*)ob;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
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

static char oaCollection_oaValue_oaDesign_assign_doc[] = 
"Class: oaCollection_oaValue_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaValue_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaValue_oaDesign data;
  int convert_status=PyoaCollection_oaValue_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaValue_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaValue_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaValue_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaValue_oaDesign_includes,METH_VARARGS,oaCollection_oaValue_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaValue_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaValue_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaValue_oaDesign_doc[] = 
"Class: oaCollection_oaValue_oaDesign\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaValue_oaDesign)\n"
"    Calls: oaCollection_oaValue_oaDesign(const oaCollection_oaValue_oaDesign& coll)\n"
"    Signature: oaCollection_oaValue_oaDesign||cref-oaCollection_oaValue_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaValue_oaDesign)\n"
"    Calls: (const oaCollection_oaValue_oaDesign&)\n"
"    Signature: oaCollection_oaValue_oaDesign||cref-oaCollection_oaValue_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaValue_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaValue_oaDesign",
    sizeof(PyoaCollection_oaValue_oaDesignObject),
    0,
    (destructor)oaCollection_oaValue_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaValue_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaValue_oaDesign_tp_repr,	/* tp_repr */
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
    oaCollection_oaValue_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaValue_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaValue_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaValue_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaValue_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaValue_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaValue_oaDesign",
           (PyObject*)(&PyoaCollection_oaValue_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaValue_oaDesign\n");
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
// Wrapper Implementation for Class: oaCollection_oaValue_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaValue_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaValue_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaValue_oaTechObject* self = (PyoaCollection_oaValue_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaValue_oaTech)
    {
        PyParamoaCollection_oaValue_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaValue_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaValue_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaValue_oaTech, Choices are:\n"
        "    (oaCollection_oaValue_oaTech)\n"
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
oaCollection_oaValue_oaTech_tp_dealloc(PyoaCollection_oaValue_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaValue_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaValue_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaValue_oaTech value;
    int convert_status=PyoaCollection_oaValue_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaValue_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaValue_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaValue_oaTech v1;
    PyParamoaCollection_oaValue_oaTech v2;
    int convert_status1=PyoaCollection_oaValue_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaValue_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaValue_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaValue_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaValue_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaValue_oaTech*) ((PyoaCollection_oaValue_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaValue_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaValue_oaTech_FromoaCollection_oaValue_oaTech(oaCollection_oaValue_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaValue_oaTech_Type.tp_alloc(&PyoaCollection_oaValue_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaValue_oaTechObject* self = (PyoaCollection_oaValue_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaValue_oaTech_includes_doc[] = 
"Class: oaCollection_oaValue_oaTech, Function: includes\n"
"  Paramegers: (oaValue)\n"
"    Calls: oaBoolean includes(const oaValue* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaValue,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaValue_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaValue_oaTech data;
    int convert_status=PyoaCollection_oaValue_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaValue_oaTechObject* self=(PyoaCollection_oaValue_oaTechObject*)ob;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
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

static char oaCollection_oaValue_oaTech_assign_doc[] = 
"Class: oaCollection_oaValue_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaValue_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaValue_oaTech data;
  int convert_status=PyoaCollection_oaValue_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaValue_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaValue_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaValue_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaValue_oaTech_includes,METH_VARARGS,oaCollection_oaValue_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaValue_oaTech_tp_assign,METH_VARARGS,oaCollection_oaValue_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaValue_oaTech_doc[] = 
"Class: oaCollection_oaValue_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaValue_oaTech)\n"
"    Calls: oaCollection_oaValue_oaTech(const oaCollection_oaValue_oaTech& coll)\n"
"    Signature: oaCollection_oaValue_oaTech||cref-oaCollection_oaValue_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaValue_oaTech)\n"
"    Calls: (const oaCollection_oaValue_oaTech&)\n"
"    Signature: oaCollection_oaValue_oaTech||cref-oaCollection_oaValue_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaValue_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaValue_oaTech",
    sizeof(PyoaCollection_oaValue_oaTechObject),
    0,
    (destructor)oaCollection_oaValue_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaValue_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaValue_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaValue_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaValue_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaValue_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaValue_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaValue_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaValue_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaValue_oaTech",
           (PyObject*)(&PyoaCollection_oaValue_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaValue_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaVectorInstBit_oaVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInstBit_oaVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVectorInstBit_oaVectorInstDefObject* self = (PyoaCollection_oaVectorInstBit_oaVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVectorInstBit_oaVectorInstDef)
    {
        PyParamoaCollection_oaVectorInstBit_oaVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVectorInstBit_oaVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVectorInstBit_oaVectorInstDef, Choices are:\n"
        "    (oaCollection_oaVectorInstBit_oaVectorInstDef)\n"
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
oaCollection_oaVectorInstBit_oaVectorInstDef_tp_dealloc(PyoaCollection_oaVectorInstBit_oaVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVectorInstBit_oaVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInstBit_oaVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVectorInstBit_oaVectorInstDef value;
    int convert_status=PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaVectorInstBit_oaVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVectorInstBit_oaVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVectorInstBit_oaVectorInstDef v1;
    PyParamoaCollection_oaVectorInstBit_oaVectorInstDef v2;
    int convert_status1=PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(PyObject* ob,PyParamoaCollection_oaVectorInstBit_oaVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVectorInstBit_oaVectorInstDef_Check(ob)) {
        result->SetData( (oaCollection_oaVectorInstBit_oaVectorInstDef*) ((PyoaCollection_oaVectorInstBit_oaVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVectorInstBit_oaVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVectorInstBit_oaVectorInstDef_FromoaCollection_oaVectorInstBit_oaVectorInstDef(oaCollection_oaVectorInstBit_oaVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type.tp_alloc(&PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVectorInstBit_oaVectorInstDefObject* self = (PyoaCollection_oaVectorInstBit_oaVectorInstDefObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaVectorInstBit_oaVectorInstDef_includes_doc[] = 
"Class: oaCollection_oaVectorInstBit_oaVectorInstDef, Function: includes\n"
"  Paramegers: (oaVectorInstBit)\n"
"    Calls: oaBoolean includes(const oaVectorInstBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVectorInstBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVectorInstBit_oaVectorInstDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVectorInstBit_oaVectorInstDef data;
    int convert_status=PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVectorInstBit_oaVectorInstDefObject* self=(PyoaCollection_oaVectorInstBit_oaVectorInstDefObject*)ob;

    PyParamoaVectorInstBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVectorInstBit_Convert,&p1)) {
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

static char oaCollection_oaVectorInstBit_oaVectorInstDef_assign_doc[] = 
"Class: oaCollection_oaVectorInstBit_oaVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVectorInstBit_oaVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVectorInstBit_oaVectorInstDef data;
  int convert_status=PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVectorInstBit_oaVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVectorInstBit_oaVectorInstDef_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaVectorInstBit_oaVectorInstDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVectorInstBit_oaVectorInstDef_includes,METH_VARARGS,oaCollection_oaVectorInstBit_oaVectorInstDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVectorInstBit_oaVectorInstDef_tp_assign,METH_VARARGS,oaCollection_oaVectorInstBit_oaVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVectorInstBit_oaVectorInstDef_doc[] = 
"Class: oaCollection_oaVectorInstBit_oaVectorInstDef\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaVectorInstBit_oaVectorInstDef)\n"
"    Calls: oaCollection_oaVectorInstBit_oaVectorInstDef(const oaCollection_oaVectorInstBit_oaVectorInstDef& coll)\n"
"    Signature: oaCollection_oaVectorInstBit_oaVectorInstDef||cref-oaCollection_oaVectorInstBit_oaVectorInstDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVectorInstBit_oaVectorInstDef)\n"
"    Calls: (const oaCollection_oaVectorInstBit_oaVectorInstDef&)\n"
"    Signature: oaCollection_oaVectorInstBit_oaVectorInstDef||cref-oaCollection_oaVectorInstBit_oaVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVectorInstBit_oaVectorInstDef",
    sizeof(PyoaCollection_oaVectorInstBit_oaVectorInstDefObject),
    0,
    (destructor)oaCollection_oaVectorInstBit_oaVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVectorInstBit_oaVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVectorInstBit_oaVectorInstDef_tp_repr,	/* tp_repr */
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
    oaCollection_oaVectorInstBit_oaVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVectorInstBit_oaVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVectorInstBit_oaVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVectorInstBit_oaVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVectorInstBit_oaVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVectorInstBit_oaVectorInstDef",
           (PyObject*)(&PyoaCollection_oaVectorInstBit_oaVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVectorInstBit_oaVectorInstDef\n");
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
// Wrapper Implementation for Class: oaCollection_oaVectorInstDef_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInstDef_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVectorInstDef_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVectorInstDef_oaBlockObject* self = (PyoaCollection_oaVectorInstDef_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVectorInstDef_oaBlock)
    {
        PyParamoaCollection_oaVectorInstDef_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVectorInstDef_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVectorInstDef_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVectorInstDef_oaBlock, Choices are:\n"
        "    (oaCollection_oaVectorInstDef_oaBlock)\n"
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
oaCollection_oaVectorInstDef_oaBlock_tp_dealloc(PyoaCollection_oaVectorInstDef_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVectorInstDef_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInstDef_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVectorInstDef_oaBlock value;
    int convert_status=PyoaCollection_oaVectorInstDef_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaVectorInstDef_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVectorInstDef_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVectorInstDef_oaBlock v1;
    PyParamoaCollection_oaVectorInstDef_oaBlock v2;
    int convert_status1=PyoaCollection_oaVectorInstDef_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVectorInstDef_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVectorInstDef_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaVectorInstDef_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVectorInstDef_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaVectorInstDef_oaBlock*) ((PyoaCollection_oaVectorInstDef_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVectorInstDef_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVectorInstDef_oaBlock_FromoaCollection_oaVectorInstDef_oaBlock(oaCollection_oaVectorInstDef_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVectorInstDef_oaBlock_Type.tp_alloc(&PyoaCollection_oaVectorInstDef_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVectorInstDef_oaBlockObject* self = (PyoaCollection_oaVectorInstDef_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaVectorInstDef_oaBlock_includes_doc[] = 
"Class: oaCollection_oaVectorInstDef_oaBlock, Function: includes\n"
"  Paramegers: (oaVectorInstDef)\n"
"    Calls: oaBoolean includes(const oaVectorInstDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVectorInstDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVectorInstDef_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVectorInstDef_oaBlock data;
    int convert_status=PyoaCollection_oaVectorInstDef_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVectorInstDef_oaBlockObject* self=(PyoaCollection_oaVectorInstDef_oaBlockObject*)ob;

    PyParamoaVectorInstDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVectorInstDef_Convert,&p1)) {
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

static char oaCollection_oaVectorInstDef_oaBlock_assign_doc[] = 
"Class: oaCollection_oaVectorInstDef_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVectorInstDef_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVectorInstDef_oaBlock data;
  int convert_status=PyoaCollection_oaVectorInstDef_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVectorInstDef_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVectorInstDef_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaVectorInstDef_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVectorInstDef_oaBlock_includes,METH_VARARGS,oaCollection_oaVectorInstDef_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVectorInstDef_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaVectorInstDef_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVectorInstDef_oaBlock_doc[] = 
"Class: oaCollection_oaVectorInstDef_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaVectorInstDef_oaBlock)\n"
"    Calls: oaCollection_oaVectorInstDef_oaBlock(const oaCollection_oaVectorInstDef_oaBlock& coll)\n"
"    Signature: oaCollection_oaVectorInstDef_oaBlock||cref-oaCollection_oaVectorInstDef_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVectorInstDef_oaBlock)\n"
"    Calls: (const oaCollection_oaVectorInstDef_oaBlock&)\n"
"    Signature: oaCollection_oaVectorInstDef_oaBlock||cref-oaCollection_oaVectorInstDef_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVectorInstDef_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVectorInstDef_oaBlock",
    sizeof(PyoaCollection_oaVectorInstDef_oaBlockObject),
    0,
    (destructor)oaCollection_oaVectorInstDef_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVectorInstDef_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVectorInstDef_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaVectorInstDef_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVectorInstDef_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVectorInstDef_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVectorInstDef_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVectorInstDef_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVectorInstDef_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVectorInstDef_oaBlock",
           (PyObject*)(&PyoaCollection_oaVectorInstDef_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVectorInstDef_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaVectorInst_oaVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInst_oaVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVectorInst_oaVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVectorInst_oaVectorInstDefObject* self = (PyoaCollection_oaVectorInst_oaVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVectorInst_oaVectorInstDef)
    {
        PyParamoaCollection_oaVectorInst_oaVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVectorInst_oaVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVectorInst_oaVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVectorInst_oaVectorInstDef, Choices are:\n"
        "    (oaCollection_oaVectorInst_oaVectorInstDef)\n"
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
oaCollection_oaVectorInst_oaVectorInstDef_tp_dealloc(PyoaCollection_oaVectorInst_oaVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVectorInst_oaVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVectorInst_oaVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVectorInst_oaVectorInstDef value;
    int convert_status=PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaVectorInst_oaVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVectorInst_oaVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVectorInst_oaVectorInstDef v1;
    PyParamoaCollection_oaVectorInst_oaVectorInstDef v2;
    int convert_status1=PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(PyObject* ob,PyParamoaCollection_oaVectorInst_oaVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVectorInst_oaVectorInstDef_Check(ob)) {
        result->SetData( (oaCollection_oaVectorInst_oaVectorInstDef*) ((PyoaCollection_oaVectorInst_oaVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVectorInst_oaVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVectorInst_oaVectorInstDef_FromoaCollection_oaVectorInst_oaVectorInstDef(oaCollection_oaVectorInst_oaVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVectorInst_oaVectorInstDef_Type.tp_alloc(&PyoaCollection_oaVectorInst_oaVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVectorInst_oaVectorInstDefObject* self = (PyoaCollection_oaVectorInst_oaVectorInstDefObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaVectorInst_oaVectorInstDef_includes_doc[] = 
"Class: oaCollection_oaVectorInst_oaVectorInstDef, Function: includes\n"
"  Paramegers: (oaVectorInst)\n"
"    Calls: oaBoolean includes(const oaVectorInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVectorInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVectorInst_oaVectorInstDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVectorInst_oaVectorInstDef data;
    int convert_status=PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVectorInst_oaVectorInstDefObject* self=(PyoaCollection_oaVectorInst_oaVectorInstDefObject*)ob;

    PyParamoaVectorInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVectorInst_Convert,&p1)) {
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

static char oaCollection_oaVectorInst_oaVectorInstDef_assign_doc[] = 
"Class: oaCollection_oaVectorInst_oaVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVectorInst_oaVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVectorInst_oaVectorInstDef data;
  int convert_status=PyoaCollection_oaVectorInst_oaVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVectorInst_oaVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVectorInst_oaVectorInstDef_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaVectorInst_oaVectorInstDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVectorInst_oaVectorInstDef_includes,METH_VARARGS,oaCollection_oaVectorInst_oaVectorInstDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVectorInst_oaVectorInstDef_tp_assign,METH_VARARGS,oaCollection_oaVectorInst_oaVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVectorInst_oaVectorInstDef_doc[] = 
"Class: oaCollection_oaVectorInst_oaVectorInstDef\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaVectorInst_oaVectorInstDef)\n"
"    Calls: oaCollection_oaVectorInst_oaVectorInstDef(const oaCollection_oaVectorInst_oaVectorInstDef& coll)\n"
"    Signature: oaCollection_oaVectorInst_oaVectorInstDef||cref-oaCollection_oaVectorInst_oaVectorInstDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVectorInst_oaVectorInstDef)\n"
"    Calls: (const oaCollection_oaVectorInst_oaVectorInstDef&)\n"
"    Signature: oaCollection_oaVectorInst_oaVectorInstDef||cref-oaCollection_oaVectorInst_oaVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVectorInst_oaVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVectorInst_oaVectorInstDef",
    sizeof(PyoaCollection_oaVectorInst_oaVectorInstDefObject),
    0,
    (destructor)oaCollection_oaVectorInst_oaVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVectorInst_oaVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVectorInst_oaVectorInstDef_tp_repr,	/* tp_repr */
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
    oaCollection_oaVectorInst_oaVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVectorInst_oaVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVectorInst_oaVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVectorInst_oaVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVectorInst_oaVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVectorInst_oaVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVectorInst_oaVectorInstDef",
           (PyObject*)(&PyoaCollection_oaVectorInst_oaVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVectorInst_oaVectorInstDef\n");
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
// Wrapper Implementation for Class: oaCollection_oaViaDef_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaDef_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaDef_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaDef_oaTechObject* self = (PyoaCollection_oaViaDef_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaDef_oaTech)
    {
        PyParamoaCollection_oaViaDef_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaDef_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaDef_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaDef_oaTech, Choices are:\n"
        "    (oaCollection_oaViaDef_oaTech)\n"
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
oaCollection_oaViaDef_oaTech_tp_dealloc(PyoaCollection_oaViaDef_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaDef_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaDef_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaDef_oaTech value;
    int convert_status=PyoaCollection_oaViaDef_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaViaDef_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaDef_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaDef_oaTech v1;
    PyParamoaCollection_oaViaDef_oaTech v2;
    int convert_status1=PyoaCollection_oaViaDef_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaDef_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaDef_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaViaDef_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaDef_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaViaDef_oaTech*) ((PyoaCollection_oaViaDef_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaDef_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaDef_oaTech_FromoaCollection_oaViaDef_oaTech(oaCollection_oaViaDef_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaDef_oaTech_Type.tp_alloc(&PyoaCollection_oaViaDef_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaDef_oaTechObject* self = (PyoaCollection_oaViaDef_oaTechObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaViaDef_oaTech_includes_doc[] = 
"Class: oaCollection_oaViaDef_oaTech, Function: includes\n"
"  Paramegers: (oaViaDef)\n"
"    Calls: oaBoolean includes(const oaViaDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaDef_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaDef_oaTech data;
    int convert_status=PyoaCollection_oaViaDef_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaDef_oaTechObject* self=(PyoaCollection_oaViaDef_oaTechObject*)ob;

    PyParamoaViaDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaDef_Convert,&p1)) {
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

static char oaCollection_oaViaDef_oaTech_assign_doc[] = 
"Class: oaCollection_oaViaDef_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaDef_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaDef_oaTech data;
  int convert_status=PyoaCollection_oaViaDef_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaDef_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaDef_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaViaDef_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaDef_oaTech_includes,METH_VARARGS,oaCollection_oaViaDef_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaDef_oaTech_tp_assign,METH_VARARGS,oaCollection_oaViaDef_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaDef_oaTech_doc[] = 
"Class: oaCollection_oaViaDef_oaTech\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaViaDef_oaTech)\n"
"    Calls: oaCollection_oaViaDef_oaTech(const oaCollection_oaViaDef_oaTech& coll)\n"
"    Signature: oaCollection_oaViaDef_oaTech||cref-oaCollection_oaViaDef_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaDef_oaTech)\n"
"    Calls: (const oaCollection_oaViaDef_oaTech&)\n"
"    Signature: oaCollection_oaViaDef_oaTech||cref-oaCollection_oaViaDef_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaDef_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaDef_oaTech",
    sizeof(PyoaCollection_oaViaDef_oaTechObject),
    0,
    (destructor)oaCollection_oaViaDef_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaDef_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaDef_oaTech_tp_repr,	/* tp_repr */
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
    oaCollection_oaViaDef_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaDef_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaDef_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaDef_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaDef_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaDef_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaDef_oaTech",
           (PyObject*)(&PyoaCollection_oaViaDef_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaDef_oaTech\n");
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
// Wrapper Implementation for Class: oaCollection_oaViaHeader_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaHeader_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaHeader_oaBlockObject* self = (PyoaCollection_oaViaHeader_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaHeader_oaBlock)
    {
        PyParamoaCollection_oaViaHeader_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaHeader_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaHeader_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaHeader_oaBlock, Choices are:\n"
        "    (oaCollection_oaViaHeader_oaBlock)\n"
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
oaCollection_oaViaHeader_oaBlock_tp_dealloc(PyoaCollection_oaViaHeader_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaHeader_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaHeader_oaBlock value;
    int convert_status=PyoaCollection_oaViaHeader_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaViaHeader_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaHeader_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaHeader_oaBlock v1;
    PyParamoaCollection_oaViaHeader_oaBlock v2;
    int convert_status1=PyoaCollection_oaViaHeader_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaHeader_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaHeader_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaViaHeader_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaHeader_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaViaHeader_oaBlock*) ((PyoaCollection_oaViaHeader_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaHeader_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaHeader_oaBlock_FromoaCollection_oaViaHeader_oaBlock(oaCollection_oaViaHeader_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaHeader_oaBlock_Type.tp_alloc(&PyoaCollection_oaViaHeader_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaHeader_oaBlockObject* self = (PyoaCollection_oaViaHeader_oaBlockObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaViaHeader_oaBlock_includes_doc[] = 
"Class: oaCollection_oaViaHeader_oaBlock, Function: includes\n"
"  Paramegers: (oaViaHeader)\n"
"    Calls: oaBoolean includes(const oaViaHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaHeader_oaBlock data;
    int convert_status=PyoaCollection_oaViaHeader_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaHeader_oaBlockObject* self=(PyoaCollection_oaViaHeader_oaBlockObject*)ob;

    PyParamoaViaHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaHeader_Convert,&p1)) {
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

static char oaCollection_oaViaHeader_oaBlock_assign_doc[] = 
"Class: oaCollection_oaViaHeader_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaHeader_oaBlock data;
  int convert_status=PyoaCollection_oaViaHeader_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaHeader_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaHeader_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaViaHeader_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaHeader_oaBlock_includes,METH_VARARGS,oaCollection_oaViaHeader_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaHeader_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaViaHeader_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaHeader_oaBlock_doc[] = 
"Class: oaCollection_oaViaHeader_oaBlock\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaViaHeader_oaBlock)\n"
"    Calls: oaCollection_oaViaHeader_oaBlock(const oaCollection_oaViaHeader_oaBlock& coll)\n"
"    Signature: oaCollection_oaViaHeader_oaBlock||cref-oaCollection_oaViaHeader_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaHeader_oaBlock)\n"
"    Calls: (const oaCollection_oaViaHeader_oaBlock&)\n"
"    Signature: oaCollection_oaViaHeader_oaBlock||cref-oaCollection_oaViaHeader_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaHeader_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaHeader_oaBlock",
    sizeof(PyoaCollection_oaViaHeader_oaBlockObject),
    0,
    (destructor)oaCollection_oaViaHeader_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaHeader_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaHeader_oaBlock_tp_repr,	/* tp_repr */
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
    oaCollection_oaViaHeader_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaHeader_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaHeader_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaHeader_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaHeader_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaHeader_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaHeader_oaBlock",
           (PyObject*)(&PyoaCollection_oaViaHeader_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaHeader_oaBlock\n");
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
// Wrapper Implementation for Class: oaCollection_oaViaHeader_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaHeader_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaHeader_oaDesignObject* self = (PyoaCollection_oaViaHeader_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaHeader_oaDesign)
    {
        PyParamoaCollection_oaViaHeader_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaHeader_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaHeader_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaHeader_oaDesign, Choices are:\n"
        "    (oaCollection_oaViaHeader_oaDesign)\n"
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
oaCollection_oaViaHeader_oaDesign_tp_dealloc(PyoaCollection_oaViaHeader_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaHeader_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaHeader_oaDesign value;
    int convert_status=PyoaCollection_oaViaHeader_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaViaHeader_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaHeader_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaHeader_oaDesign v1;
    PyParamoaCollection_oaViaHeader_oaDesign v2;
    int convert_status1=PyoaCollection_oaViaHeader_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaHeader_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaHeader_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaViaHeader_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaHeader_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaViaHeader_oaDesign*) ((PyoaCollection_oaViaHeader_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaHeader_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaHeader_oaDesign_FromoaCollection_oaViaHeader_oaDesign(oaCollection_oaViaHeader_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaHeader_oaDesign_Type.tp_alloc(&PyoaCollection_oaViaHeader_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaHeader_oaDesignObject* self = (PyoaCollection_oaViaHeader_oaDesignObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaViaHeader_oaDesign_includes_doc[] = 
"Class: oaCollection_oaViaHeader_oaDesign, Function: includes\n"
"  Paramegers: (oaViaHeader)\n"
"    Calls: oaBoolean includes(const oaViaHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaHeader_oaDesign data;
    int convert_status=PyoaCollection_oaViaHeader_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaHeader_oaDesignObject* self=(PyoaCollection_oaViaHeader_oaDesignObject*)ob;

    PyParamoaViaHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaHeader_Convert,&p1)) {
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

static char oaCollection_oaViaHeader_oaDesign_assign_doc[] = 
"Class: oaCollection_oaViaHeader_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaHeader_oaDesign data;
  int convert_status=PyoaCollection_oaViaHeader_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaHeader_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaHeader_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaViaHeader_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaHeader_oaDesign_includes,METH_VARARGS,oaCollection_oaViaHeader_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaHeader_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaViaHeader_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaHeader_oaDesign_doc[] = 
"Class: oaCollection_oaViaHeader_oaDesign\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaViaHeader_oaDesign)\n"
"    Calls: oaCollection_oaViaHeader_oaDesign(const oaCollection_oaViaHeader_oaDesign& coll)\n"
"    Signature: oaCollection_oaViaHeader_oaDesign||cref-oaCollection_oaViaHeader_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaHeader_oaDesign)\n"
"    Calls: (const oaCollection_oaViaHeader_oaDesign&)\n"
"    Signature: oaCollection_oaViaHeader_oaDesign||cref-oaCollection_oaViaHeader_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaHeader_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaHeader_oaDesign",
    sizeof(PyoaCollection_oaViaHeader_oaDesignObject),
    0,
    (destructor)oaCollection_oaViaHeader_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaHeader_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaHeader_oaDesign_tp_repr,	/* tp_repr */
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
    oaCollection_oaViaHeader_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaHeader_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaHeader_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaHeader_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaHeader_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaHeader_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaHeader_oaDesign",
           (PyObject*)(&PyoaCollection_oaViaHeader_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaHeader_oaDesign\n");
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
// Wrapper Implementation for Class: oaCollection_oaViaHeader_oaViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaHeader_oaViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaHeader_oaViaDefObject* self = (PyoaCollection_oaViaHeader_oaViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaHeader_oaViaDef)
    {
        PyParamoaCollection_oaViaHeader_oaViaDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaHeader_oaViaDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaHeader_oaViaDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaHeader_oaViaDef, Choices are:\n"
        "    (oaCollection_oaViaHeader_oaViaDef)\n"
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
oaCollection_oaViaHeader_oaViaDef_tp_dealloc(PyoaCollection_oaViaHeader_oaViaDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaHeader_oaViaDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaViaDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaHeader_oaViaDef value;
    int convert_status=PyoaCollection_oaViaHeader_oaViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaViaHeader_oaViaDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaHeader_oaViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaHeader_oaViaDef v1;
    PyParamoaCollection_oaViaHeader_oaViaDef v2;
    int convert_status1=PyoaCollection_oaViaHeader_oaViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaHeader_oaViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaHeader_oaViaDef_Convert(PyObject* ob,PyParamoaCollection_oaViaHeader_oaViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaHeader_oaViaDef_Check(ob)) {
        result->SetData( (oaCollection_oaViaHeader_oaViaDef*) ((PyoaCollection_oaViaHeader_oaViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaHeader_oaViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaHeader_oaViaDef_FromoaCollection_oaViaHeader_oaViaDef(oaCollection_oaViaHeader_oaViaDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaHeader_oaViaDef_Type.tp_alloc(&PyoaCollection_oaViaHeader_oaViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaHeader_oaViaDefObject* self = (PyoaCollection_oaViaHeader_oaViaDefObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaViaHeader_oaViaDef_includes_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaDef, Function: includes\n"
"  Paramegers: (oaViaHeader)\n"
"    Calls: oaBoolean includes(const oaViaHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaViaDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaHeader_oaViaDef data;
    int convert_status=PyoaCollection_oaViaHeader_oaViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaHeader_oaViaDefObject* self=(PyoaCollection_oaViaHeader_oaViaDefObject*)ob;

    PyParamoaViaHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaHeader_Convert,&p1)) {
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

static char oaCollection_oaViaHeader_oaViaDef_assign_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaViaDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaHeader_oaViaDef data;
  int convert_status=PyoaCollection_oaViaHeader_oaViaDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaHeader_oaViaDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaHeader_oaViaDef_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaViaHeader_oaViaDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaHeader_oaViaDef_includes,METH_VARARGS,oaCollection_oaViaHeader_oaViaDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaHeader_oaViaDef_tp_assign,METH_VARARGS,oaCollection_oaViaHeader_oaViaDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaHeader_oaViaDef_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaDef\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaViaHeader_oaViaDef)\n"
"    Calls: oaCollection_oaViaHeader_oaViaDef(const oaCollection_oaViaHeader_oaViaDef& coll)\n"
"    Signature: oaCollection_oaViaHeader_oaViaDef||cref-oaCollection_oaViaHeader_oaViaDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaHeader_oaViaDef)\n"
"    Calls: (const oaCollection_oaViaHeader_oaViaDef&)\n"
"    Signature: oaCollection_oaViaHeader_oaViaDef||cref-oaCollection_oaViaHeader_oaViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaHeader_oaViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaHeader_oaViaDef",
    sizeof(PyoaCollection_oaViaHeader_oaViaDefObject),
    0,
    (destructor)oaCollection_oaViaHeader_oaViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaHeader_oaViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaHeader_oaViaDef_tp_repr,	/* tp_repr */
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
    oaCollection_oaViaHeader_oaViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaHeader_oaViaDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaHeader_oaViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaHeader_oaViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaHeader_oaViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaHeader_oaViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaHeader_oaViaDef",
           (PyObject*)(&PyoaCollection_oaViaHeader_oaViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaHeader_oaViaDef\n");
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
// Wrapper Implementation for Class: oaCollection_oaViaHeader_oaViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaHeader_oaViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaHeader_oaViaHeaderObject* self = (PyoaCollection_oaViaHeader_oaViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaHeader_oaViaHeader)
    {
        PyParamoaCollection_oaViaHeader_oaViaHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaHeader_oaViaHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaHeader_oaViaHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaHeader_oaViaHeader, Choices are:\n"
        "    (oaCollection_oaViaHeader_oaViaHeader)\n"
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
oaCollection_oaViaHeader_oaViaHeader_tp_dealloc(PyoaCollection_oaViaHeader_oaViaHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaHeader_oaViaHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaHeader_oaViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaHeader_oaViaHeader value;
    int convert_status=PyoaCollection_oaViaHeader_oaViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaViaHeader_oaViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaHeader_oaViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaHeader_oaViaHeader v1;
    PyParamoaCollection_oaViaHeader_oaViaHeader v2;
    int convert_status1=PyoaCollection_oaViaHeader_oaViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaHeader_oaViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaHeader_oaViaHeader_Convert(PyObject* ob,PyParamoaCollection_oaViaHeader_oaViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaHeader_oaViaHeader_Check(ob)) {
        result->SetData( (oaCollection_oaViaHeader_oaViaHeader*) ((PyoaCollection_oaViaHeader_oaViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaHeader_oaViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaHeader_oaViaHeader_FromoaCollection_oaViaHeader_oaViaHeader(oaCollection_oaViaHeader_oaViaHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaHeader_oaViaHeader_Type.tp_alloc(&PyoaCollection_oaViaHeader_oaViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaHeader_oaViaHeaderObject* self = (PyoaCollection_oaViaHeader_oaViaHeaderObject*)bself;
        self->value = (oaBaseCollection*)  data;
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
static char oaCollection_oaViaHeader_oaViaHeader_includes_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaHeader, Function: includes\n"
"  Paramegers: (oaViaHeader)\n"
"    Calls: oaBoolean includes(const oaViaHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaViaHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaHeader_oaViaHeader data;
    int convert_status=PyoaCollection_oaViaHeader_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaHeader_oaViaHeaderObject* self=(PyoaCollection_oaViaHeader_oaViaHeaderObject*)ob;

    PyParamoaViaHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaHeader_Convert,&p1)) {
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

static char oaCollection_oaViaHeader_oaViaHeader_assign_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaHeader_oaViaHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaHeader_oaViaHeader data;
  int convert_status=PyoaCollection_oaViaHeader_oaViaHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaHeader_oaViaHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaHeader_oaViaHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaViaHeader_oaViaHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaHeader_oaViaHeader_includes,METH_VARARGS,oaCollection_oaViaHeader_oaViaHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaHeader_oaViaHeader_tp_assign,METH_VARARGS,oaCollection_oaViaHeader_oaViaHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaHeader_oaViaHeader_doc[] = 
"Class: oaCollection_oaViaHeader_oaViaHeader\n"
"  Collections are template classes that represent sets of database objects. Collections are templatized for both the class of the starting object that the collection comes from, and the class of the objects contained in the collection. Collections are primarily used to initialize an oaIter so the members of the collection can be retrieved.\n"
"  Collections are an effective way to work with one-to-many relationships. Collections allow the caller to traverse the contents of a collection, determine the collection size, and search the contents of the collection.\n"
"  Note that constructing a collection is very quick, because the collection object simply signifies the collection. It does not gather the objects in the collection. Hence it is reasonable to construct a collection just to call isEmpty() on it.\n"
"  All collections support common functions:\n"
"  getCount() returns the number of objects in the collection.\n"
"  isEmpty() returns a boolean value that indicates if there are any objects in the collection.\n"
"  It is often faster to determine if a collection is empty than to determine the exact size of the collection. As a result, always use isEmpty() rather than getCount() == 0. getCount() is not constant time for all collections.\n"
"  The most common way to use an oaCollection is to use it inline in the construction of an oaIter , never explicitly declaring the oaCollection. In the following example, view->getNets() returns an oaCollection.\n"
"  oaIter<oaNet> nIter(view->getNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaViaHeader_oaViaHeader)\n"
"    Calls: oaCollection_oaViaHeader_oaViaHeader(const oaCollection_oaViaHeader_oaViaHeader& coll)\n"
"    Signature: oaCollection_oaViaHeader_oaViaHeader||cref-oaCollection_oaViaHeader_oaViaHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaHeader_oaViaHeader)\n"
"    Calls: (const oaCollection_oaViaHeader_oaViaHeader&)\n"
"    Signature: oaCollection_oaViaHeader_oaViaHeader||cref-oaCollection_oaViaHeader_oaViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaHeader_oaViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaHeader_oaViaHeader",
    sizeof(PyoaCollection_oaViaHeader_oaViaHeaderObject),
    0,
    (destructor)oaCollection_oaViaHeader_oaViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaHeader_oaViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaHeader_oaViaHeader_tp_repr,	/* tp_repr */
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
    oaCollection_oaViaHeader_oaViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaHeader_oaViaHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaHeader_oaViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaHeader_oaViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaHeader_oaViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaHeader_oaViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaHeader_oaViaHeader",
           (PyObject*)(&PyoaCollection_oaViaHeader_oaViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaHeader_oaViaHeader\n");
       return -1;
    }
    return 0;
}

