
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCluster_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCluster_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCluster_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCluster_oaBlockObject* self = (PyoaCollection_oaCluster_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCluster_oaBlock)
    {
        PyParamoaCollection_oaCluster_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCluster_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCluster_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCluster_oaBlock, Choices are:\n"
        "    (oaCollection_oaCluster_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCluster_oaBlock_tp_dealloc(PyoaCollection_oaCluster_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCluster_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCluster_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCluster_oaBlock value;
    int convert_status=PyoaCollection_oaCluster_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaCluster_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCluster_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCluster_oaBlock v1;
    PyParamoaCollection_oaCluster_oaBlock v2;
    int convert_status1=PyoaCollection_oaCluster_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCluster_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCluster_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaCluster_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCluster_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaCluster_oaBlock*) ((PyoaCollection_oaCluster_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCluster_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCluster_oaBlock_FromoaCollection_oaCluster_oaBlock(oaCollection_oaCluster_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCluster_oaBlock_Type.tp_alloc(&PyoaCollection_oaCluster_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCluster_oaBlockObject* self = (PyoaCollection_oaCluster_oaBlockObject*)bself;
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
static char oaCollection_oaCluster_oaBlock_includes_doc[] = 
"Class: oaCollection_oaCluster_oaBlock, Function: includes\n"
"  Paramegers: (oaCluster)\n"
"    Calls: oaBoolean includes(const oaCluster* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCluster,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCluster_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCluster_oaBlock data;
    int convert_status=PyoaCollection_oaCluster_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCluster_oaBlockObject* self=(PyoaCollection_oaCluster_oaBlockObject*)ob;

    PyParamoaCluster p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCluster_Convert,&p1)) {
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

static char oaCollection_oaCluster_oaBlock_assign_doc[] = 
"Class: oaCollection_oaCluster_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCluster_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCluster_oaBlock data;
  int convert_status=PyoaCollection_oaCluster_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCluster_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCluster_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaCluster_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCluster_oaBlock_includes,METH_VARARGS,oaCollection_oaCluster_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCluster_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaCluster_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCluster_oaBlock_doc[] = 
"Class: oaCollection_oaCluster_oaBlock\n"
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
"  Paramegers: (oaCollection_oaCluster_oaBlock)\n"
"    Calls: oaCollection_oaCluster_oaBlock(const oaCollection_oaCluster_oaBlock& coll)\n"
"    Signature: oaCollection_oaCluster_oaBlock||cref-oaCollection_oaCluster_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCluster_oaBlock)\n"
"    Calls: (const oaCollection_oaCluster_oaBlock&)\n"
"    Signature: oaCollection_oaCluster_oaBlock||cref-oaCollection_oaCluster_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCluster_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCluster_oaBlock",
    sizeof(PyoaCollection_oaCluster_oaBlockObject),
    0,
    (destructor)oaCollection_oaCluster_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCluster_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCluster_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCluster_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCluster_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCluster_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCluster_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCluster_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCluster_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCluster_oaBlock",
           (PyObject*)(&PyoaCollection_oaCluster_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCluster_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCluster_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCluster_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCluster_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCluster_oaClusterObject* self = (PyoaCollection_oaCluster_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCluster_oaCluster)
    {
        PyParamoaCollection_oaCluster_oaCluster p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCluster_oaCluster_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCluster_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCluster_oaCluster, Choices are:\n"
        "    (oaCollection_oaCluster_oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCluster_oaCluster_tp_dealloc(PyoaCollection_oaCluster_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCluster_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCluster_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCluster_oaCluster value;
    int convert_status=PyoaCollection_oaCluster_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaCluster_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCluster_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCluster_oaCluster v1;
    PyParamoaCollection_oaCluster_oaCluster v2;
    int convert_status1=PyoaCollection_oaCluster_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCluster_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCluster_oaCluster_Convert(PyObject* ob,PyParamoaCollection_oaCluster_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCluster_oaCluster_Check(ob)) {
        result->SetData( (oaCollection_oaCluster_oaCluster*) ((PyoaCollection_oaCluster_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCluster_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCluster_oaCluster_FromoaCollection_oaCluster_oaCluster(oaCollection_oaCluster_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCluster_oaCluster_Type.tp_alloc(&PyoaCollection_oaCluster_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCluster_oaClusterObject* self = (PyoaCollection_oaCluster_oaClusterObject*)bself;
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
static char oaCollection_oaCluster_oaCluster_includes_doc[] = 
"Class: oaCollection_oaCluster_oaCluster, Function: includes\n"
"  Paramegers: (oaCluster)\n"
"    Calls: oaBoolean includes(const oaCluster* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCluster,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCluster_oaCluster_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCluster_oaCluster data;
    int convert_status=PyoaCollection_oaCluster_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCluster_oaClusterObject* self=(PyoaCollection_oaCluster_oaClusterObject*)ob;

    PyParamoaCluster p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCluster_Convert,&p1)) {
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

static char oaCollection_oaCluster_oaCluster_assign_doc[] = 
"Class: oaCollection_oaCluster_oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCluster_oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCluster_oaCluster data;
  int convert_status=PyoaCollection_oaCluster_oaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCluster_oaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCluster_oaCluster_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaCluster_oaCluster_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCluster_oaCluster_includes,METH_VARARGS,oaCollection_oaCluster_oaCluster_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCluster_oaCluster_tp_assign,METH_VARARGS,oaCollection_oaCluster_oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCluster_oaCluster_doc[] = 
"Class: oaCollection_oaCluster_oaCluster\n"
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
"  Paramegers: (oaCollection_oaCluster_oaCluster)\n"
"    Calls: oaCollection_oaCluster_oaCluster(const oaCollection_oaCluster_oaCluster& coll)\n"
"    Signature: oaCollection_oaCluster_oaCluster||cref-oaCollection_oaCluster_oaCluster,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCluster_oaCluster)\n"
"    Calls: (const oaCollection_oaCluster_oaCluster&)\n"
"    Signature: oaCollection_oaCluster_oaCluster||cref-oaCollection_oaCluster_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCluster_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCluster_oaCluster",
    sizeof(PyoaCollection_oaCluster_oaClusterObject),
    0,
    (destructor)oaCollection_oaCluster_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCluster_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCluster_oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCluster_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCluster_oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCluster_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCluster_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCluster_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCluster_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCluster_oaCluster",
           (PyObject*)(&PyoaCollection_oaCluster_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCluster_oaCluster\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConnectDef_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConnectDef_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConnectDef_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConnectDef_oaBlockObject* self = (PyoaCollection_oaConnectDef_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConnectDef_oaBlock)
    {
        PyParamoaCollection_oaConnectDef_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConnectDef_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConnectDef_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConnectDef_oaBlock, Choices are:\n"
        "    (oaCollection_oaConnectDef_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConnectDef_oaBlock_tp_dealloc(PyoaCollection_oaConnectDef_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConnectDef_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConnectDef_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConnectDef_oaBlock value;
    int convert_status=PyoaCollection_oaConnectDef_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaConnectDef_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConnectDef_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConnectDef_oaBlock v1;
    PyParamoaCollection_oaConnectDef_oaBlock v2;
    int convert_status1=PyoaCollection_oaConnectDef_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConnectDef_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConnectDef_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaConnectDef_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConnectDef_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaConnectDef_oaBlock*) ((PyoaCollection_oaConnectDef_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConnectDef_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConnectDef_oaBlock_FromoaCollection_oaConnectDef_oaBlock(oaCollection_oaConnectDef_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConnectDef_oaBlock_Type.tp_alloc(&PyoaCollection_oaConnectDef_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConnectDef_oaBlockObject* self = (PyoaCollection_oaConnectDef_oaBlockObject*)bself;
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
static char oaCollection_oaConnectDef_oaBlock_includes_doc[] = 
"Class: oaCollection_oaConnectDef_oaBlock, Function: includes\n"
"  Paramegers: (oaConnectDef)\n"
"    Calls: oaBoolean includes(const oaConnectDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConnectDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConnectDef_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConnectDef_oaBlock data;
    int convert_status=PyoaCollection_oaConnectDef_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConnectDef_oaBlockObject* self=(PyoaCollection_oaConnectDef_oaBlockObject*)ob;

    PyParamoaConnectDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConnectDef_Convert,&p1)) {
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

static char oaCollection_oaConnectDef_oaBlock_assign_doc[] = 
"Class: oaCollection_oaConnectDef_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConnectDef_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConnectDef_oaBlock data;
  int convert_status=PyoaCollection_oaConnectDef_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConnectDef_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConnectDef_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConnectDef_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConnectDef_oaBlock_includes,METH_VARARGS,oaCollection_oaConnectDef_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConnectDef_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaConnectDef_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConnectDef_oaBlock_doc[] = 
"Class: oaCollection_oaConnectDef_oaBlock\n"
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
"  Paramegers: (oaCollection_oaConnectDef_oaBlock)\n"
"    Calls: oaCollection_oaConnectDef_oaBlock(const oaCollection_oaConnectDef_oaBlock& coll)\n"
"    Signature: oaCollection_oaConnectDef_oaBlock||cref-oaCollection_oaConnectDef_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConnectDef_oaBlock)\n"
"    Calls: (const oaCollection_oaConnectDef_oaBlock&)\n"
"    Signature: oaCollection_oaConnectDef_oaBlock||cref-oaCollection_oaConnectDef_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConnectDef_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConnectDef_oaBlock",
    sizeof(PyoaCollection_oaConnectDef_oaBlockObject),
    0,
    (destructor)oaCollection_oaConnectDef_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConnectDef_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConnectDef_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConnectDef_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConnectDef_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConnectDef_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConnectDef_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConnectDef_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConnectDef_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConnectDef_oaBlock",
           (PyObject*)(&PyoaCollection_oaConnectDef_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConnectDef_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintDef_oaSessionObject* self = (PyoaCollection_oaConstraintDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintDef_oaSession)
    {
        PyParamoaCollection_oaConstraintDef_oaSession p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintDef_oaSession_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintDef_oaSession(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintDef_oaSession, Choices are:\n"
        "    (oaCollection_oaConstraintDef_oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintDef_oaSession_tp_dealloc(PyoaCollection_oaConstraintDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintDef_oaSession*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintDef_oaSession value;
    int convert_status=PyoaCollection_oaConstraintDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaConstraintDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintDef_oaSession v1;
    PyParamoaCollection_oaConstraintDef_oaSession v2;
    int convert_status1=PyoaCollection_oaConstraintDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaConstraintDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintDef_oaSession_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintDef_oaSession*) ((PyoaCollection_oaConstraintDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintDef_oaSession_FromoaCollection_oaConstraintDef_oaSession(oaCollection_oaConstraintDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintDef_oaSession_Type.tp_alloc(&PyoaCollection_oaConstraintDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintDef_oaSessionObject* self = (PyoaCollection_oaConstraintDef_oaSessionObject*)bself;
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
static char oaCollection_oaConstraintDef_oaSession_includes_doc[] = 
"Class: oaCollection_oaConstraintDef_oaSession, Function: includes\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: oaBoolean includes(const oaConstraintDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintDef_oaSession_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintDef_oaSession data;
    int convert_status=PyoaCollection_oaConstraintDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintDef_oaSessionObject* self=(PyoaCollection_oaConstraintDef_oaSessionObject*)ob;

    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintDef_Convert,&p1)) {
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

static char oaCollection_oaConstraintDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaConstraintDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintDef_oaSession data;
  int convert_status=PyoaCollection_oaConstraintDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintDef_oaSession_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintDef_oaSession_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintDef_oaSession_includes,METH_VARARGS,oaCollection_oaConstraintDef_oaSession_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaConstraintDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintDef_oaSession_doc[] = 
"Class: oaCollection_oaConstraintDef_oaSession\n"
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
"  Paramegers: (oaCollection_oaConstraintDef_oaSession)\n"
"    Calls: oaCollection_oaConstraintDef_oaSession(const oaCollection_oaConstraintDef_oaSession& coll)\n"
"    Signature: oaCollection_oaConstraintDef_oaSession||cref-oaCollection_oaConstraintDef_oaSession,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintDef_oaSession)\n"
"    Calls: (const oaCollection_oaConstraintDef_oaSession&)\n"
"    Signature: oaCollection_oaConstraintDef_oaSession||cref-oaCollection_oaConstraintDef_oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintDef_oaSession",
    sizeof(PyoaCollection_oaConstraintDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaConstraintDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintDef_oaSession",
           (PyObject*)(&PyoaCollection_oaConstraintDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroupHeader_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupHeader_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroupHeader_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroupHeader_oaDesignObject* self = (PyoaCollection_oaConstraintGroupHeader_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroupHeader_oaDesign)
    {
        PyParamoaCollection_oaConstraintGroupHeader_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroupHeader_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroupHeader_oaDesign, Choices are:\n"
        "    (oaCollection_oaConstraintGroupHeader_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroupHeader_oaDesign_tp_dealloc(PyoaCollection_oaConstraintGroupHeader_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroupHeader_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupHeader_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroupHeader_oaDesign value;
    int convert_status=PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[67];
    sprintf(buffer,"<oaCollection_oaConstraintGroupHeader_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroupHeader_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroupHeader_oaDesign v1;
    PyParamoaCollection_oaConstraintGroupHeader_oaDesign v2;
    int convert_status1=PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroupHeader_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroupHeader_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroupHeader_oaDesign*) ((PyoaCollection_oaConstraintGroupHeader_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroupHeader_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroupHeader_oaDesign_FromoaCollection_oaConstraintGroupHeader_oaDesign(oaCollection_oaConstraintGroupHeader_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroupHeader_oaDesign_Type.tp_alloc(&PyoaCollection_oaConstraintGroupHeader_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroupHeader_oaDesignObject* self = (PyoaCollection_oaConstraintGroupHeader_oaDesignObject*)bself;
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
static char oaCollection_oaConstraintGroupHeader_oaDesign_includes_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaDesign, Function: includes\n"
"  Paramegers: (oaConstraintGroupHeader)\n"
"    Calls: oaBoolean includes(const oaConstraintGroupHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroupHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroupHeader_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroupHeader_oaDesign data;
    int convert_status=PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroupHeader_oaDesignObject* self=(PyoaCollection_oaConstraintGroupHeader_oaDesignObject*)ob;

    PyParamoaConstraintGroupHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroupHeader_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroupHeader_oaDesign_assign_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroupHeader_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroupHeader_oaDesign data;
  int convert_status=PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroupHeader_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroupHeader_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroupHeader_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroupHeader_oaDesign_includes,METH_VARARGS,oaCollection_oaConstraintGroupHeader_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroupHeader_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroupHeader_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroupHeader_oaDesign_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaDesign\n"
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
"  Paramegers: (oaCollection_oaConstraintGroupHeader_oaDesign)\n"
"    Calls: oaCollection_oaConstraintGroupHeader_oaDesign(const oaCollection_oaConstraintGroupHeader_oaDesign& coll)\n"
"    Signature: oaCollection_oaConstraintGroupHeader_oaDesign||cref-oaCollection_oaConstraintGroupHeader_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroupHeader_oaDesign)\n"
"    Calls: (const oaCollection_oaConstraintGroupHeader_oaDesign&)\n"
"    Signature: oaCollection_oaConstraintGroupHeader_oaDesign||cref-oaCollection_oaConstraintGroupHeader_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroupHeader_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroupHeader_oaDesign",
    sizeof(PyoaCollection_oaConstraintGroupHeader_oaDesignObject),
    0,
    (destructor)oaCollection_oaConstraintGroupHeader_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroupHeader_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroupHeader_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroupHeader_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroupHeader_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroupHeader_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroupHeader_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroupHeader_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroupHeader_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroupHeader_oaDesign",
           (PyObject*)(&PyoaCollection_oaConstraintGroupHeader_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroupHeader_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroupHeader_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupHeader_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroupHeader_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroupHeader_oaTechObject* self = (PyoaCollection_oaConstraintGroupHeader_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroupHeader_oaTech)
    {
        PyParamoaCollection_oaConstraintGroupHeader_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroupHeader_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroupHeader_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroupHeader_oaTech, Choices are:\n"
        "    (oaCollection_oaConstraintGroupHeader_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroupHeader_oaTech_tp_dealloc(PyoaCollection_oaConstraintGroupHeader_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroupHeader_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupHeader_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroupHeader_oaTech value;
    int convert_status=PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[65];
    sprintf(buffer,"<oaCollection_oaConstraintGroupHeader_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroupHeader_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroupHeader_oaTech v1;
    PyParamoaCollection_oaConstraintGroupHeader_oaTech v2;
    int convert_status1=PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroupHeader_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroupHeader_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroupHeader_oaTech*) ((PyoaCollection_oaConstraintGroupHeader_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroupHeader_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroupHeader_oaTech_FromoaCollection_oaConstraintGroupHeader_oaTech(oaCollection_oaConstraintGroupHeader_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroupHeader_oaTech_Type.tp_alloc(&PyoaCollection_oaConstraintGroupHeader_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroupHeader_oaTechObject* self = (PyoaCollection_oaConstraintGroupHeader_oaTechObject*)bself;
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
static char oaCollection_oaConstraintGroupHeader_oaTech_includes_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaTech, Function: includes\n"
"  Paramegers: (oaConstraintGroupHeader)\n"
"    Calls: oaBoolean includes(const oaConstraintGroupHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroupHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroupHeader_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroupHeader_oaTech data;
    int convert_status=PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroupHeader_oaTechObject* self=(PyoaCollection_oaConstraintGroupHeader_oaTechObject*)ob;

    PyParamoaConstraintGroupHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroupHeader_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroupHeader_oaTech_assign_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroupHeader_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroupHeader_oaTech data;
  int convert_status=PyoaCollection_oaConstraintGroupHeader_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroupHeader_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroupHeader_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroupHeader_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroupHeader_oaTech_includes,METH_VARARGS,oaCollection_oaConstraintGroupHeader_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroupHeader_oaTech_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroupHeader_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroupHeader_oaTech_doc[] = 
"Class: oaCollection_oaConstraintGroupHeader_oaTech\n"
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
"  Paramegers: (oaCollection_oaConstraintGroupHeader_oaTech)\n"
"    Calls: oaCollection_oaConstraintGroupHeader_oaTech(const oaCollection_oaConstraintGroupHeader_oaTech& coll)\n"
"    Signature: oaCollection_oaConstraintGroupHeader_oaTech||cref-oaCollection_oaConstraintGroupHeader_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroupHeader_oaTech)\n"
"    Calls: (const oaCollection_oaConstraintGroupHeader_oaTech&)\n"
"    Signature: oaCollection_oaConstraintGroupHeader_oaTech||cref-oaCollection_oaConstraintGroupHeader_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroupHeader_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroupHeader_oaTech",
    sizeof(PyoaCollection_oaConstraintGroupHeader_oaTechObject),
    0,
    (destructor)oaCollection_oaConstraintGroupHeader_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroupHeader_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroupHeader_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroupHeader_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroupHeader_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroupHeader_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroupHeader_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroupHeader_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroupHeader_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroupHeader_oaTech",
           (PyObject*)(&PyoaCollection_oaConstraintGroupHeader_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroupHeader_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroupMem_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject* self = (PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroupMem_oaConstraintGroup)
    {
        PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroupMem_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroupMem_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaConstraintGroupMem_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_dealloc(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroupMem_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[73];
    sprintf(buffer,"<oaCollection_oaConstraintGroupMem_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup v1;
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroupMem_oaConstraintGroup*) ((PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroupMem_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_FromoaCollection_oaConstraintGroupMem_oaConstraintGroup(oaCollection_oaConstraintGroupMem_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject* self = (PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject*)bself;
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
static char oaCollection_oaConstraintGroupMem_oaConstraintGroup_includes_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroup, Function: includes\n"
"  Paramegers: (oaConstraintGroupMem)\n"
"    Calls: oaBoolean includes(const oaConstraintGroupMem* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroupMem,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroup_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup data;
    int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject* self=(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject*)ob;

    PyParamoaConstraintGroupMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroupMem_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroupMem_oaConstraintGroup_assign_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup data;
  int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroupMem_oaConstraintGroup_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroupMem_oaConstraintGroup_includes,METH_VARARGS,oaCollection_oaConstraintGroupMem_oaConstraintGroup_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroupMem_oaConstraintGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroupMem_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroup\n"
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
"  Paramegers: (oaCollection_oaConstraintGroupMem_oaConstraintGroup)\n"
"    Calls: oaCollection_oaConstraintGroupMem_oaConstraintGroup(const oaCollection_oaConstraintGroupMem_oaConstraintGroup& coll)\n"
"    Signature: oaCollection_oaConstraintGroupMem_oaConstraintGroup||cref-oaCollection_oaConstraintGroupMem_oaConstraintGroup,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroupMem_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaConstraintGroupMem_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaConstraintGroupMem_oaConstraintGroup||cref-oaCollection_oaConstraintGroupMem_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroupMem_oaConstraintGroup",
    sizeof(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroupMem_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroupMem_oaConstraintGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroupMem_oaConstraintGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroupMem_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroupMem_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroupMem_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroupMem_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject* self = (PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader)
    {
        PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader, Choices are:\n"
        "    (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_dealloc(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader value;
    int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[79];
    sprintf(buffer,"<oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader v1;
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader v2;
    int convert_status1=PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader*) ((PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_FromoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader(oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type.tp_alloc(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject* self = (PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject*)bself;
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
static char oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_includes_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader, Function: includes\n"
"  Paramegers: (oaConstraintGroupMem)\n"
"    Calls: oaBoolean includes(const oaConstraintGroupMem* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroupMem,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader data;
    int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject* self=(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject*)ob;

    PyParamoaConstraintGroupMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroupMem_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_assign_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader data;
  int convert_status=PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_includes,METH_VARARGS,oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_doc[] = 
"Class: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader\n"
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
"  Paramegers: (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader)\n"
"    Calls: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader(const oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader& coll)\n"
"    Signature: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader||cref-oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader)\n"
"    Calls: (const oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader&)\n"
"    Signature: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader||cref-oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader",
    sizeof(PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeaderObject),
    0,
    (destructor)oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader",
           (PyObject*)(&PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroup_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroup_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroup_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroup_oaDesignObject* self = (PyoaCollection_oaConstraintGroup_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroup_oaDesign)
    {
        PyParamoaCollection_oaConstraintGroup_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroup_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroup_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroup_oaDesign, Choices are:\n"
        "    (oaCollection_oaConstraintGroup_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroup_oaDesign_tp_dealloc(PyoaCollection_oaConstraintGroup_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroup_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroup_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroup_oaDesign value;
    int convert_status=PyoaCollection_oaConstraintGroup_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaConstraintGroup_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroup_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroup_oaDesign v1;
    PyParamoaCollection_oaConstraintGroup_oaDesign v2;
    int convert_status1=PyoaCollection_oaConstraintGroup_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroup_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroup_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroup_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroup_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroup_oaDesign*) ((PyoaCollection_oaConstraintGroup_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroup_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroup_oaDesign_FromoaCollection_oaConstraintGroup_oaDesign(oaCollection_oaConstraintGroup_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroup_oaDesign_Type.tp_alloc(&PyoaCollection_oaConstraintGroup_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroup_oaDesignObject* self = (PyoaCollection_oaConstraintGroup_oaDesignObject*)bself;
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
static char oaCollection_oaConstraintGroup_oaDesign_includes_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaDesign, Function: includes\n"
"  Paramegers: (oaConstraintGroup)\n"
"    Calls: oaBoolean includes(const oaConstraintGroup* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroup,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroup_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroup_oaDesign data;
    int convert_status=PyoaCollection_oaConstraintGroup_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroup_oaDesignObject* self=(PyoaCollection_oaConstraintGroup_oaDesignObject*)ob;

    PyParamoaConstraintGroup p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroup_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroup_oaDesign_assign_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroup_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroup_oaDesign data;
  int convert_status=PyoaCollection_oaConstraintGroup_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroup_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroup_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroup_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroup_oaDesign_includes,METH_VARARGS,oaCollection_oaConstraintGroup_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroup_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroup_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroup_oaDesign_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaDesign\n"
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
"  Paramegers: (oaCollection_oaConstraintGroup_oaDesign)\n"
"    Calls: oaCollection_oaConstraintGroup_oaDesign(const oaCollection_oaConstraintGroup_oaDesign& coll)\n"
"    Signature: oaCollection_oaConstraintGroup_oaDesign||cref-oaCollection_oaConstraintGroup_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroup_oaDesign)\n"
"    Calls: (const oaCollection_oaConstraintGroup_oaDesign&)\n"
"    Signature: oaCollection_oaConstraintGroup_oaDesign||cref-oaCollection_oaConstraintGroup_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroup_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroup_oaDesign",
    sizeof(PyoaCollection_oaConstraintGroup_oaDesignObject),
    0,
    (destructor)oaCollection_oaConstraintGroup_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroup_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroup_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroup_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroup_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroup_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroup_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroup_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroup_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroup_oaDesign",
           (PyObject*)(&PyoaCollection_oaConstraintGroup_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroup_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintGroup_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroup_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintGroup_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintGroup_oaTechObject* self = (PyoaCollection_oaConstraintGroup_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintGroup_oaTech)
    {
        PyParamoaCollection_oaConstraintGroup_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintGroup_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintGroup_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintGroup_oaTech, Choices are:\n"
        "    (oaCollection_oaConstraintGroup_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintGroup_oaTech_tp_dealloc(PyoaCollection_oaConstraintGroup_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintGroup_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintGroup_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintGroup_oaTech value;
    int convert_status=PyoaCollection_oaConstraintGroup_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaConstraintGroup_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintGroup_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintGroup_oaTech v1;
    PyParamoaCollection_oaConstraintGroup_oaTech v2;
    int convert_status1=PyoaCollection_oaConstraintGroup_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintGroup_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintGroup_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaConstraintGroup_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintGroup_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintGroup_oaTech*) ((PyoaCollection_oaConstraintGroup_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintGroup_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintGroup_oaTech_FromoaCollection_oaConstraintGroup_oaTech(oaCollection_oaConstraintGroup_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintGroup_oaTech_Type.tp_alloc(&PyoaCollection_oaConstraintGroup_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintGroup_oaTechObject* self = (PyoaCollection_oaConstraintGroup_oaTechObject*)bself;
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
static char oaCollection_oaConstraintGroup_oaTech_includes_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaTech, Function: includes\n"
"  Paramegers: (oaConstraintGroup)\n"
"    Calls: oaBoolean includes(const oaConstraintGroup* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintGroup,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintGroup_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintGroup_oaTech data;
    int convert_status=PyoaCollection_oaConstraintGroup_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintGroup_oaTechObject* self=(PyoaCollection_oaConstraintGroup_oaTechObject*)ob;

    PyParamoaConstraintGroup p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroup_Convert,&p1)) {
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

static char oaCollection_oaConstraintGroup_oaTech_assign_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintGroup_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintGroup_oaTech data;
  int convert_status=PyoaCollection_oaConstraintGroup_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintGroup_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintGroup_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintGroup_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintGroup_oaTech_includes,METH_VARARGS,oaCollection_oaConstraintGroup_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintGroup_oaTech_tp_assign,METH_VARARGS,oaCollection_oaConstraintGroup_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintGroup_oaTech_doc[] = 
"Class: oaCollection_oaConstraintGroup_oaTech\n"
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
"  Paramegers: (oaCollection_oaConstraintGroup_oaTech)\n"
"    Calls: oaCollection_oaConstraintGroup_oaTech(const oaCollection_oaConstraintGroup_oaTech& coll)\n"
"    Signature: oaCollection_oaConstraintGroup_oaTech||cref-oaCollection_oaConstraintGroup_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintGroup_oaTech)\n"
"    Calls: (const oaCollection_oaConstraintGroup_oaTech&)\n"
"    Signature: oaCollection_oaConstraintGroup_oaTech||cref-oaCollection_oaConstraintGroup_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintGroup_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintGroup_oaTech",
    sizeof(PyoaCollection_oaConstraintGroup_oaTechObject),
    0,
    (destructor)oaCollection_oaConstraintGroup_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintGroup_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintGroup_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintGroup_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintGroup_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintGroup_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintGroup_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintGroup_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintGroup_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintGroup_oaTech",
           (PyObject*)(&PyoaCollection_oaConstraintGroup_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintGroup_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintParamDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParamDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintParamDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintParamDef_oaSessionObject* self = (PyoaCollection_oaConstraintParamDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintParamDef_oaSession)
    {
        PyParamoaCollection_oaConstraintParamDef_oaSession p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintParamDef_oaSession_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintParamDef_oaSession(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintParamDef_oaSession, Choices are:\n"
        "    (oaCollection_oaConstraintParamDef_oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintParamDef_oaSession_tp_dealloc(PyoaCollection_oaConstraintParamDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintParamDef_oaSession*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParamDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintParamDef_oaSession value;
    int convert_status=PyoaCollection_oaConstraintParamDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[65];
    sprintf(buffer,"<oaCollection_oaConstraintParamDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintParamDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintParamDef_oaSession v1;
    PyParamoaCollection_oaConstraintParamDef_oaSession v2;
    int convert_status1=PyoaCollection_oaConstraintParamDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintParamDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintParamDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaConstraintParamDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintParamDef_oaSession_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintParamDef_oaSession*) ((PyoaCollection_oaConstraintParamDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintParamDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintParamDef_oaSession_FromoaCollection_oaConstraintParamDef_oaSession(oaCollection_oaConstraintParamDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintParamDef_oaSession_Type.tp_alloc(&PyoaCollection_oaConstraintParamDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintParamDef_oaSessionObject* self = (PyoaCollection_oaConstraintParamDef_oaSessionObject*)bself;
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
static char oaCollection_oaConstraintParamDef_oaSession_includes_doc[] = 
"Class: oaCollection_oaConstraintParamDef_oaSession, Function: includes\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: oaBoolean includes(const oaConstraintParamDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintParamDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintParamDef_oaSession_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintParamDef_oaSession data;
    int convert_status=PyoaCollection_oaConstraintParamDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintParamDef_oaSessionObject* self=(PyoaCollection_oaConstraintParamDef_oaSessionObject*)ob;

    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
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

static char oaCollection_oaConstraintParamDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaConstraintParamDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintParamDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintParamDef_oaSession data;
  int convert_status=PyoaCollection_oaConstraintParamDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintParamDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintParamDef_oaSession_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintParamDef_oaSession_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintParamDef_oaSession_includes,METH_VARARGS,oaCollection_oaConstraintParamDef_oaSession_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintParamDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaConstraintParamDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintParamDef_oaSession_doc[] = 
"Class: oaCollection_oaConstraintParamDef_oaSession\n"
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
"  Paramegers: (oaCollection_oaConstraintParamDef_oaSession)\n"
"    Calls: oaCollection_oaConstraintParamDef_oaSession(const oaCollection_oaConstraintParamDef_oaSession& coll)\n"
"    Signature: oaCollection_oaConstraintParamDef_oaSession||cref-oaCollection_oaConstraintParamDef_oaSession,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintParamDef_oaSession)\n"
"    Calls: (const oaCollection_oaConstraintParamDef_oaSession&)\n"
"    Signature: oaCollection_oaConstraintParamDef_oaSession||cref-oaCollection_oaConstraintParamDef_oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintParamDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintParamDef_oaSession",
    sizeof(PyoaCollection_oaConstraintParamDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaConstraintParamDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintParamDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintParamDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintParamDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintParamDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintParamDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintParamDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintParamDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintParamDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintParamDef_oaSession",
           (PyObject*)(&PyoaCollection_oaConstraintParamDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintParamDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintParam_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParam_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintParam_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintParam_oaDesignObject* self = (PyoaCollection_oaConstraintParam_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintParam_oaDesign)
    {
        PyParamoaCollection_oaConstraintParam_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintParam_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintParam_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintParam_oaDesign, Choices are:\n"
        "    (oaCollection_oaConstraintParam_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintParam_oaDesign_tp_dealloc(PyoaCollection_oaConstraintParam_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintParam_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParam_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintParam_oaDesign value;
    int convert_status=PyoaCollection_oaConstraintParam_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaConstraintParam_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintParam_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintParam_oaDesign v1;
    PyParamoaCollection_oaConstraintParam_oaDesign v2;
    int convert_status1=PyoaCollection_oaConstraintParam_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintParam_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintParam_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaConstraintParam_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintParam_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintParam_oaDesign*) ((PyoaCollection_oaConstraintParam_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintParam_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintParam_oaDesign_FromoaCollection_oaConstraintParam_oaDesign(oaCollection_oaConstraintParam_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintParam_oaDesign_Type.tp_alloc(&PyoaCollection_oaConstraintParam_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintParam_oaDesignObject* self = (PyoaCollection_oaConstraintParam_oaDesignObject*)bself;
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
static char oaCollection_oaConstraintParam_oaDesign_includes_doc[] = 
"Class: oaCollection_oaConstraintParam_oaDesign, Function: includes\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: oaBoolean includes(const oaConstraintParam* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintParam,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintParam_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintParam_oaDesign data;
    int convert_status=PyoaCollection_oaConstraintParam_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintParam_oaDesignObject* self=(PyoaCollection_oaConstraintParam_oaDesignObject*)ob;

    PyParamoaConstraintParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParam_Convert,&p1)) {
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

static char oaCollection_oaConstraintParam_oaDesign_assign_doc[] = 
"Class: oaCollection_oaConstraintParam_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintParam_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintParam_oaDesign data;
  int convert_status=PyoaCollection_oaConstraintParam_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintParam_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintParam_oaDesign_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintParam_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintParam_oaDesign_includes,METH_VARARGS,oaCollection_oaConstraintParam_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintParam_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaConstraintParam_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintParam_oaDesign_doc[] = 
"Class: oaCollection_oaConstraintParam_oaDesign\n"
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
"  Paramegers: (oaCollection_oaConstraintParam_oaDesign)\n"
"    Calls: oaCollection_oaConstraintParam_oaDesign(const oaCollection_oaConstraintParam_oaDesign& coll)\n"
"    Signature: oaCollection_oaConstraintParam_oaDesign||cref-oaCollection_oaConstraintParam_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintParam_oaDesign)\n"
"    Calls: (const oaCollection_oaConstraintParam_oaDesign&)\n"
"    Signature: oaCollection_oaConstraintParam_oaDesign||cref-oaCollection_oaConstraintParam_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintParam_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintParam_oaDesign",
    sizeof(PyoaCollection_oaConstraintParam_oaDesignObject),
    0,
    (destructor)oaCollection_oaConstraintParam_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintParam_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintParam_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintParam_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintParam_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintParam_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintParam_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintParam_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintParam_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintParam_oaDesign",
           (PyObject*)(&PyoaCollection_oaConstraintParam_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintParam_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraintParam_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParam_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraintParam_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraintParam_oaTechObject* self = (PyoaCollection_oaConstraintParam_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraintParam_oaTech)
    {
        PyParamoaCollection_oaConstraintParam_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraintParam_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaConstraintParam_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraintParam_oaTech, Choices are:\n"
        "    (oaCollection_oaConstraintParam_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraintParam_oaTech_tp_dealloc(PyoaCollection_oaConstraintParam_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraintParam_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraintParam_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraintParam_oaTech value;
    int convert_status=PyoaCollection_oaConstraintParam_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaConstraintParam_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraintParam_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraintParam_oaTech v1;
    PyParamoaCollection_oaConstraintParam_oaTech v2;
    int convert_status1=PyoaCollection_oaConstraintParam_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraintParam_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraintParam_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaConstraintParam_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraintParam_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaConstraintParam_oaTech*) ((PyoaCollection_oaConstraintParam_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraintParam_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraintParam_oaTech_FromoaCollection_oaConstraintParam_oaTech(oaCollection_oaConstraintParam_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraintParam_oaTech_Type.tp_alloc(&PyoaCollection_oaConstraintParam_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraintParam_oaTechObject* self = (PyoaCollection_oaConstraintParam_oaTechObject*)bself;
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
static char oaCollection_oaConstraintParam_oaTech_includes_doc[] = 
"Class: oaCollection_oaConstraintParam_oaTech, Function: includes\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: oaBoolean includes(const oaConstraintParam* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraintParam,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaConstraintParam_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaConstraintParam_oaTech data;
    int convert_status=PyoaCollection_oaConstraintParam_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaConstraintParam_oaTechObject* self=(PyoaCollection_oaConstraintParam_oaTechObject*)ob;

    PyParamoaConstraintParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParam_Convert,&p1)) {
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

static char oaCollection_oaConstraintParam_oaTech_assign_doc[] = 
"Class: oaCollection_oaConstraintParam_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaConstraintParam_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaConstraintParam_oaTech data;
  int convert_status=PyoaCollection_oaConstraintParam_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaConstraintParam_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaConstraintParam_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaConstraintParam_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaConstraintParam_oaTech_includes,METH_VARARGS,oaCollection_oaConstraintParam_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaConstraintParam_oaTech_tp_assign,METH_VARARGS,oaCollection_oaConstraintParam_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaConstraintParam_oaTech_doc[] = 
"Class: oaCollection_oaConstraintParam_oaTech\n"
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
"  Paramegers: (oaCollection_oaConstraintParam_oaTech)\n"
"    Calls: oaCollection_oaConstraintParam_oaTech(const oaCollection_oaConstraintParam_oaTech& coll)\n"
"    Signature: oaCollection_oaConstraintParam_oaTech||cref-oaCollection_oaConstraintParam_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaConstraintParam_oaTech)\n"
"    Calls: (const oaCollection_oaConstraintParam_oaTech&)\n"
"    Signature: oaCollection_oaConstraintParam_oaTech||cref-oaCollection_oaConstraintParam_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraintParam_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraintParam_oaTech",
    sizeof(PyoaCollection_oaConstraintParam_oaTechObject),
    0,
    (destructor)oaCollection_oaConstraintParam_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraintParam_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraintParam_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraintParam_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaConstraintParam_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraintParam_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraintParam_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraintParam_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraintParam_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraintParam_oaTech",
           (PyObject*)(&PyoaCollection_oaConstraintParam_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraintParam_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraint_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraint_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaConstraint_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupCollection*)  new oaCollection_oaConstraint_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraint_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaConstraint_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraint_oaConstraintGroup_tp_dealloc(PyoaCollection_oaConstraint_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraint_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraint_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaConstraint_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[65];
    sprintf(buffer,"<oaCollection_oaConstraint_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraint_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraint_oaConstraintGroup v1;
    PyParamoaCollection_oaConstraint_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaConstraint_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraint_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraint_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaConstraint_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraint_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaConstraint_oaConstraintGroup*) ((PyoaCollection_oaConstraint_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraint_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraint_oaConstraintGroup_FromoaCollection_oaConstraint_oaConstraintGroup(oaCollection_oaConstraint_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraint_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaConstraint_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaConstraint_oaConstraintGroupObject*)bself;
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
static char oaCollection_oaConstraint_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaConstraint_oaConstraintGroup\n"
"  Class type oaCollection_oaConstraint_oaConstraintGroup\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaConstraint_oaConstraintGroup)\n"
"    Calls: oaCollection_oaConstraint_oaConstraintGroup(const oaCollection_oaConstraint_oaConstraintGroup& c)\n"
"    Signature: oaCollection_oaConstraint_oaConstraintGroup||cref-oaCollection_oaConstraint_oaConstraintGroup,\n"
"    Constructor oaCollection_oaConstraint_oaConstraintGroup\n"
"  Paramegers: (oaCollection_oaConstraint_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaConstraint_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaConstraint_oaConstraintGroup||cref-oaCollection_oaConstraint_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraint_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraint_oaConstraintGroup",
    sizeof(PyoaCollection_oaConstraint_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaConstraint_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraint_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraint_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraint_oaConstraintGroup_doc,	/* tp_doc */
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
    oaCollection_oaConstraint_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraint_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraint_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraint_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraint_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaConstraint_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraint_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraint_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraint_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraint_oaDesignObject* self = (PyoaCollection_oaConstraint_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraint_oaDesign)
    {
        PyParamoaCollection_oaConstraint_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraint_oaDesign_Convert,&p1)) {
            self->value = (oaConstraintCollection*)  new oaCollection_oaConstraint_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraint_oaDesign, Choices are:\n"
        "    (oaCollection_oaConstraint_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraint_oaDesign_tp_dealloc(PyoaCollection_oaConstraint_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraint_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraint_oaDesign value;
    int convert_status=PyoaCollection_oaConstraint_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaConstraint_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraint_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraint_oaDesign v1;
    PyParamoaCollection_oaConstraint_oaDesign v2;
    int convert_status1=PyoaCollection_oaConstraint_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraint_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraint_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaConstraint_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraint_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaConstraint_oaDesign*) ((PyoaCollection_oaConstraint_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraint_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraint_oaDesign_FromoaCollection_oaConstraint_oaDesign(oaCollection_oaConstraint_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraint_oaDesign_Type.tp_alloc(&PyoaCollection_oaConstraint_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraint_oaDesignObject* self = (PyoaCollection_oaConstraint_oaDesignObject*)bself;
        self->value = (oaConstraintCollection*)  data;
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
static char oaCollection_oaConstraint_oaDesign_doc[] = 
"Class: oaCollection_oaConstraint_oaDesign\n"
"  Class type oaCollection_oaConstraint_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaConstraint_oaDesign)\n"
"    Calls: oaCollection_oaConstraint_oaDesign(const oaCollection_oaConstraint_oaDesign& c)\n"
"    Signature: oaCollection_oaConstraint_oaDesign||cref-oaCollection_oaConstraint_oaDesign,\n"
"    Constructor oaCollection_oaConstraint_oaDesign\n"
"  Paramegers: (oaCollection_oaConstraint_oaDesign)\n"
"    Calls: (const oaCollection_oaConstraint_oaDesign&)\n"
"    Signature: oaCollection_oaConstraint_oaDesign||cref-oaCollection_oaConstraint_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraint_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraint_oaDesign",
    sizeof(PyoaCollection_oaConstraint_oaDesignObject),
    0,
    (destructor)oaCollection_oaConstraint_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraint_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraint_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraint_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraint_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraint_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraint_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraint_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraint_oaDesign",
           (PyObject*)(&PyoaCollection_oaConstraint_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraint_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaConstraint_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaConstraint_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaConstraint_oaTechObject* self = (PyoaCollection_oaConstraint_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaConstraint_oaTech)
    {
        PyParamoaCollection_oaConstraint_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaConstraint_oaTech_Convert,&p1)) {
            self->value = (oaConstraintCollection*)  new oaCollection_oaConstraint_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaConstraint_oaTech, Choices are:\n"
        "    (oaCollection_oaConstraint_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaConstraint_oaTech_tp_dealloc(PyoaCollection_oaConstraint_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaConstraint_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaConstraint_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaConstraint_oaTech value;
    int convert_status=PyoaCollection_oaConstraint_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaConstraint_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaConstraint_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaConstraint_oaTech v1;
    PyParamoaCollection_oaConstraint_oaTech v2;
    int convert_status1=PyoaCollection_oaConstraint_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaConstraint_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaConstraint_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaConstraint_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaConstraint_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaConstraint_oaTech*) ((PyoaCollection_oaConstraint_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaConstraint_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaConstraint_oaTech_FromoaCollection_oaConstraint_oaTech(oaCollection_oaConstraint_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaConstraint_oaTech_Type.tp_alloc(&PyoaCollection_oaConstraint_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaConstraint_oaTechObject* self = (PyoaCollection_oaConstraint_oaTechObject*)bself;
        self->value = (oaConstraintCollection*)  data;
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
static char oaCollection_oaConstraint_oaTech_doc[] = 
"Class: oaCollection_oaConstraint_oaTech\n"
"  Class type oaCollection_oaConstraint_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaConstraint_oaTech)\n"
"    Calls: oaCollection_oaConstraint_oaTech(const oaCollection_oaConstraint_oaTech& c)\n"
"    Signature: oaCollection_oaConstraint_oaTech||cref-oaCollection_oaConstraint_oaTech,\n"
"    Constructor oaCollection_oaConstraint_oaTech\n"
"  Paramegers: (oaCollection_oaConstraint_oaTech)\n"
"    Calls: (const oaCollection_oaConstraint_oaTech&)\n"
"    Signature: oaCollection_oaConstraint_oaTech||cref-oaCollection_oaConstraint_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaConstraint_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaConstraint_oaTech",
    sizeof(PyoaCollection_oaConstraint_oaTechObject),
    0,
    (destructor)oaCollection_oaConstraint_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaConstraint_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaConstraint_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaConstraint_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaConstraint_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaConstraint_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaConstraint_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaConstraint_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaConstraint_oaTech",
           (PyObject*)(&PyoaCollection_oaConstraint_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaConstraint_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDMData_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMData_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDMData_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDMData_oaDMDataObject* self = (PyoaCollection_oaDMData_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDMData_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaDMData_oaDMData)
    {
        PyParamoaCollection_oaDMData_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDMData_oaDMData_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDMData_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDMData_oaDMData, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaCollection_oaDMData_oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDMData_oaDMData_tp_dealloc(PyoaCollection_oaDMData_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDMData_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMData_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDMData_oaDMData value;
    int convert_status=PyoaCollection_oaDMData_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaDMData_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDMData_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDMData_oaDMData v1;
    PyParamoaCollection_oaDMData_oaDMData v2;
    int convert_status1=PyoaCollection_oaDMData_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDMData_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDMData_oaDMData_Convert(PyObject* ob,PyParamoaCollection_oaDMData_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDMData_oaDMData_Check(ob)) {
        result->SetData( (oaCollection_oaDMData_oaDMData*) ((PyoaCollection_oaDMData_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDMData_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDMData_oaDMData_FromoaCollection_oaDMData_oaDMData(oaCollection_oaDMData_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDMData_oaDMData_Type.tp_alloc(&PyoaCollection_oaDMData_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDMData_oaDMDataObject* self = (PyoaCollection_oaDMData_oaDMDataObject*)bself;
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
static char oaCollection_oaDMData_oaDMData_includes_doc[] = 
"Class: oaCollection_oaDMData_oaDMData, Function: includes\n"
"  Paramegers: (oaDMData)\n"
"    Calls: oaBoolean includes(const oaDMData* db) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDMData,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaDMData_oaDMData_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDMData_oaDMData data;
    int convert_status=PyoaCollection_oaDMData_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDMData_oaDMDataObject* self=(PyoaCollection_oaDMData_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
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

static char oaCollection_oaDMData_oaDMData_assign_doc[] = 
"Class: oaCollection_oaDMData_oaDMData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDMData_oaDMData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDMData_oaDMData data;
  int convert_status=PyoaCollection_oaDMData_oaDMData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDMData_oaDMData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDMData_oaDMData_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDMData_oaDMData_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDMData_oaDMData_includes,METH_VARARGS,oaCollection_oaDMData_oaDMData_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDMData_oaDMData_tp_assign,METH_VARARGS,oaCollection_oaDMData_oaDMData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDMData_oaDMData_doc[] = 
"Class: oaCollection_oaDMData_oaDMData\n"
"  Class type oaCollection_oaDMData_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaDMData_oaDMData(oaUInt4 dbIDIn)\n"
"    Signature: oaCollection_oaDMData_oaDMData||simple-oaUInt4,\n"
"    Constructor oaCollection_oaDMData_oaDMData\n"
"  Paramegers: (oaCollection_oaDMData_oaDMData)\n"
"    Calls: oaCollection_oaDMData_oaDMData(const oaCollection_oaDMData_oaDMData& c)\n"
"    Signature: oaCollection_oaDMData_oaDMData||cref-oaCollection_oaDMData_oaDMData,\n"
"    Constructor oaCollection_oaDMData_oaDMData\n"
"  Paramegers: (oaCollection_oaDMData_oaDMData)\n"
"    Calls: (const oaCollection_oaDMData_oaDMData&)\n"
"    Signature: oaCollection_oaDMData_oaDMData||cref-oaCollection_oaDMData_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDMData_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDMData_oaDMData",
    sizeof(PyoaCollection_oaDMData_oaDMDataObject),
    0,
    (destructor)oaCollection_oaDMData_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDMData_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDMData_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDMData_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDMData_oaDMData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDMData_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDMData_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDMData_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDMData_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDMData_oaDMData",
           (PyObject*)(&PyoaCollection_oaDMData_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDMData_oaDMData\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDMFile_oaDMContainer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMFile_oaDMContainer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDMFile_oaDMContainer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDMFile_oaDMContainerObject* self = (PyoaCollection_oaDMFile_oaDMContainerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDMFile_oaDMContainer)
    {
        PyParamoaCollection_oaDMFile_oaDMContainer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDMFile_oaDMContainer_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDMFile_oaDMContainer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDMFile_oaDMContainer, Choices are:\n"
        "    (oaCollection_oaDMFile_oaDMContainer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDMFile_oaDMContainer_tp_dealloc(PyoaCollection_oaDMFile_oaDMContainerObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDMFile_oaDMContainer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMFile_oaDMContainer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDMFile_oaDMContainer value;
    int convert_status=PyoaCollection_oaDMFile_oaDMContainer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaDMFile_oaDMContainer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDMFile_oaDMContainer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDMFile_oaDMContainer v1;
    PyParamoaCollection_oaDMFile_oaDMContainer v2;
    int convert_status1=PyoaCollection_oaDMFile_oaDMContainer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDMFile_oaDMContainer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDMFile_oaDMContainer_Convert(PyObject* ob,PyParamoaCollection_oaDMFile_oaDMContainer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDMFile_oaDMContainer_Check(ob)) {
        result->SetData( (oaCollection_oaDMFile_oaDMContainer*) ((PyoaCollection_oaDMFile_oaDMContainerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDMFile_oaDMContainer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDMFile_oaDMContainer_FromoaCollection_oaDMFile_oaDMContainer(oaCollection_oaDMFile_oaDMContainer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDMFile_oaDMContainer_Type.tp_alloc(&PyoaCollection_oaDMFile_oaDMContainer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDMFile_oaDMContainerObject* self = (PyoaCollection_oaDMFile_oaDMContainerObject*)bself;
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
static char oaCollection_oaDMFile_oaDMContainer_includes_doc[] = 
"Class: oaCollection_oaDMFile_oaDMContainer, Function: includes\n"
"  Paramegers: (oaDMFile)\n"
"    Calls: oaBoolean includes(const oaDMFile* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDMFile,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDMFile_oaDMContainer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDMFile_oaDMContainer data;
    int convert_status=PyoaCollection_oaDMFile_oaDMContainer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDMFile_oaDMContainerObject* self=(PyoaCollection_oaDMFile_oaDMContainerObject*)ob;

    PyParamoaDMFile p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMFile_Convert,&p1)) {
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

static char oaCollection_oaDMFile_oaDMContainer_assign_doc[] = 
"Class: oaCollection_oaDMFile_oaDMContainer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDMFile_oaDMContainer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDMFile_oaDMContainer data;
  int convert_status=PyoaCollection_oaDMFile_oaDMContainer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDMFile_oaDMContainer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDMFile_oaDMContainer_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDMFile_oaDMContainer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDMFile_oaDMContainer_includes,METH_VARARGS,oaCollection_oaDMFile_oaDMContainer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDMFile_oaDMContainer_tp_assign,METH_VARARGS,oaCollection_oaDMFile_oaDMContainer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDMFile_oaDMContainer_doc[] = 
"Class: oaCollection_oaDMFile_oaDMContainer\n"
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
"  Paramegers: (oaCollection_oaDMFile_oaDMContainer)\n"
"    Calls: oaCollection_oaDMFile_oaDMContainer(const oaCollection_oaDMFile_oaDMContainer& coll)\n"
"    Signature: oaCollection_oaDMFile_oaDMContainer||cref-oaCollection_oaDMFile_oaDMContainer,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDMFile_oaDMContainer)\n"
"    Calls: (const oaCollection_oaDMFile_oaDMContainer&)\n"
"    Signature: oaCollection_oaDMFile_oaDMContainer||cref-oaCollection_oaDMFile_oaDMContainer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDMFile_oaDMContainer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDMFile_oaDMContainer",
    sizeof(PyoaCollection_oaDMFile_oaDMContainerObject),
    0,
    (destructor)oaCollection_oaDMFile_oaDMContainer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDMFile_oaDMContainer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDMFile_oaDMContainer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDMFile_oaDMContainer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDMFile_oaDMContainer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDMFile_oaDMContainer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDMFile_oaDMContainer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDMFile_oaDMContainer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDMFile_oaDMContainer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDMFile_oaDMContainer",
           (PyObject*)(&PyoaCollection_oaDMFile_oaDMContainer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDMFile_oaDMContainer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDMFile_oaDMFile
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMFile_oaDMFile_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDMFile_oaDMFile_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDMFile_oaDMFileObject* self = (PyoaCollection_oaDMFile_oaDMFileObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDMFile_oaDMFile)
    {
        PyParamoaCollection_oaDMFile_oaDMFile p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDMFile_oaDMFile_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDMFile_oaDMFile(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDMFile_oaDMFile, Choices are:\n"
        "    (oaCollection_oaDMFile_oaDMFile)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDMFile_oaDMFile_tp_dealloc(PyoaCollection_oaDMFile_oaDMFileObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDMFile_oaDMFile*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDMFile_oaDMFile_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDMFile_oaDMFile value;
    int convert_status=PyoaCollection_oaDMFile_oaDMFile_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaDMFile_oaDMFile::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDMFile_oaDMFile_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDMFile_oaDMFile v1;
    PyParamoaCollection_oaDMFile_oaDMFile v2;
    int convert_status1=PyoaCollection_oaDMFile_oaDMFile_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDMFile_oaDMFile_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDMFile_oaDMFile_Convert(PyObject* ob,PyParamoaCollection_oaDMFile_oaDMFile* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDMFile_oaDMFile_Check(ob)) {
        result->SetData( (oaCollection_oaDMFile_oaDMFile*) ((PyoaCollection_oaDMFile_oaDMFileObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDMFile_oaDMFile Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDMFile_oaDMFile_FromoaCollection_oaDMFile_oaDMFile(oaCollection_oaDMFile_oaDMFile* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDMFile_oaDMFile_Type.tp_alloc(&PyoaCollection_oaDMFile_oaDMFile_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDMFile_oaDMFileObject* self = (PyoaCollection_oaDMFile_oaDMFileObject*)bself;
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
static char oaCollection_oaDMFile_oaDMFile_includes_doc[] = 
"Class: oaCollection_oaDMFile_oaDMFile, Function: includes\n"
"  Paramegers: (oaDMFile)\n"
"    Calls: oaBoolean includes(const oaDMFile* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDMFile,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDMFile_oaDMFile_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDMFile_oaDMFile data;
    int convert_status=PyoaCollection_oaDMFile_oaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDMFile_oaDMFileObject* self=(PyoaCollection_oaDMFile_oaDMFileObject*)ob;

    PyParamoaDMFile p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMFile_Convert,&p1)) {
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

static char oaCollection_oaDMFile_oaDMFile_assign_doc[] = 
"Class: oaCollection_oaDMFile_oaDMFile, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDMFile_oaDMFile_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDMFile_oaDMFile data;
  int convert_status=PyoaCollection_oaDMFile_oaDMFile_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDMFile_oaDMFile p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDMFile_oaDMFile_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDMFile_oaDMFile_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDMFile_oaDMFile_includes,METH_VARARGS,oaCollection_oaDMFile_oaDMFile_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDMFile_oaDMFile_tp_assign,METH_VARARGS,oaCollection_oaDMFile_oaDMFile_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDMFile_oaDMFile_doc[] = 
"Class: oaCollection_oaDMFile_oaDMFile\n"
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
"  Paramegers: (oaCollection_oaDMFile_oaDMFile)\n"
"    Calls: oaCollection_oaDMFile_oaDMFile(const oaCollection_oaDMFile_oaDMFile& coll)\n"
"    Signature: oaCollection_oaDMFile_oaDMFile||cref-oaCollection_oaDMFile_oaDMFile,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDMFile_oaDMFile)\n"
"    Calls: (const oaCollection_oaDMFile_oaDMFile&)\n"
"    Signature: oaCollection_oaDMFile_oaDMFile||cref-oaCollection_oaDMFile_oaDMFile,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDMFile_oaDMFile_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDMFile_oaDMFile",
    sizeof(PyoaCollection_oaDMFile_oaDMFileObject),
    0,
    (destructor)oaCollection_oaDMFile_oaDMFile_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDMFile_oaDMFile_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDMFile_oaDMFile_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDMFile_oaDMFile_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDMFile_oaDMFile_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDMFile_oaDMFile_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDMFile_oaDMFile_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDMFile_oaDMFile_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDMFile_oaDMFile\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDMFile_oaDMFile",
           (PyObject*)(&PyoaCollection_oaDMFile_oaDMFile_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDMFile_oaDMFile\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDerivedLayerDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDerivedLayerDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDerivedLayerDef_oaSessionObject* self = (PyoaCollection_oaDerivedLayerDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDerivedLayerDef_oaSession)
    {
        PyParamoaCollection_oaDerivedLayerDef_oaSession p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDerivedLayerDef_oaSession_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDerivedLayerDef_oaSession(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDerivedLayerDef_oaSession, Choices are:\n"
        "    (oaCollection_oaDerivedLayerDef_oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDerivedLayerDef_oaSession_tp_dealloc(PyoaCollection_oaDerivedLayerDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDerivedLayerDef_oaSession*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDerivedLayerDef_oaSession value;
    int convert_status=PyoaCollection_oaDerivedLayerDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaDerivedLayerDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDerivedLayerDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDerivedLayerDef_oaSession v1;
    PyParamoaCollection_oaDerivedLayerDef_oaSession v2;
    int convert_status1=PyoaCollection_oaDerivedLayerDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDerivedLayerDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDerivedLayerDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaDerivedLayerDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDerivedLayerDef_oaSession_Check(ob)) {
        result->SetData( (oaCollection_oaDerivedLayerDef_oaSession*) ((PyoaCollection_oaDerivedLayerDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDerivedLayerDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDerivedLayerDef_oaSession_FromoaCollection_oaDerivedLayerDef_oaSession(oaCollection_oaDerivedLayerDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDerivedLayerDef_oaSession_Type.tp_alloc(&PyoaCollection_oaDerivedLayerDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDerivedLayerDef_oaSessionObject* self = (PyoaCollection_oaDerivedLayerDef_oaSessionObject*)bself;
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
static char oaCollection_oaDerivedLayerDef_oaSession_includes_doc[] = 
"Class: oaCollection_oaDerivedLayerDef_oaSession, Function: includes\n"
"  Paramegers: (oaDerivedLayerDef)\n"
"    Calls: oaBoolean includes(const oaDerivedLayerDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDerivedLayerDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDerivedLayerDef_oaSession_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDerivedLayerDef_oaSession data;
    int convert_status=PyoaCollection_oaDerivedLayerDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDerivedLayerDef_oaSessionObject* self=(PyoaCollection_oaDerivedLayerDef_oaSessionObject*)ob;

    PyParamoaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerDef_Convert,&p1)) {
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

static char oaCollection_oaDerivedLayerDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaDerivedLayerDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDerivedLayerDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDerivedLayerDef_oaSession data;
  int convert_status=PyoaCollection_oaDerivedLayerDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDerivedLayerDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDerivedLayerDef_oaSession_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDerivedLayerDef_oaSession_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDerivedLayerDef_oaSession_includes,METH_VARARGS,oaCollection_oaDerivedLayerDef_oaSession_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDerivedLayerDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaDerivedLayerDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDerivedLayerDef_oaSession_doc[] = 
"Class: oaCollection_oaDerivedLayerDef_oaSession\n"
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
"  Paramegers: (oaCollection_oaDerivedLayerDef_oaSession)\n"
"    Calls: oaCollection_oaDerivedLayerDef_oaSession(const oaCollection_oaDerivedLayerDef_oaSession& coll)\n"
"    Signature: oaCollection_oaDerivedLayerDef_oaSession||cref-oaCollection_oaDerivedLayerDef_oaSession,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDerivedLayerDef_oaSession)\n"
"    Calls: (const oaCollection_oaDerivedLayerDef_oaSession&)\n"
"    Signature: oaCollection_oaDerivedLayerDef_oaSession||cref-oaCollection_oaDerivedLayerDef_oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDerivedLayerDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDerivedLayerDef_oaSession",
    sizeof(PyoaCollection_oaDerivedLayerDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaDerivedLayerDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDerivedLayerDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDerivedLayerDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDerivedLayerDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDerivedLayerDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDerivedLayerDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDerivedLayerDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDerivedLayerDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDerivedLayerDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDerivedLayerDef_oaSession",
           (PyObject*)(&PyoaCollection_oaDerivedLayerDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDerivedLayerDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDerivedLayerParamDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerParamDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDerivedLayerParamDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDerivedLayerParamDef_oaSessionObject* self = (PyoaCollection_oaDerivedLayerParamDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDerivedLayerParamDef_oaSession)
    {
        PyParamoaCollection_oaDerivedLayerParamDef_oaSession p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDerivedLayerParamDef_oaSession(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDerivedLayerParamDef_oaSession, Choices are:\n"
        "    (oaCollection_oaDerivedLayerParamDef_oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDerivedLayerParamDef_oaSession_tp_dealloc(PyoaCollection_oaDerivedLayerParamDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDerivedLayerParamDef_oaSession*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerParamDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDerivedLayerParamDef_oaSession value;
    int convert_status=PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[67];
    sprintf(buffer,"<oaCollection_oaDerivedLayerParamDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDerivedLayerParamDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDerivedLayerParamDef_oaSession v1;
    PyParamoaCollection_oaDerivedLayerParamDef_oaSession v2;
    int convert_status1=PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaDerivedLayerParamDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDerivedLayerParamDef_oaSession_Check(ob)) {
        result->SetData( (oaCollection_oaDerivedLayerParamDef_oaSession*) ((PyoaCollection_oaDerivedLayerParamDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDerivedLayerParamDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDerivedLayerParamDef_oaSession_FromoaCollection_oaDerivedLayerParamDef_oaSession(oaCollection_oaDerivedLayerParamDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDerivedLayerParamDef_oaSession_Type.tp_alloc(&PyoaCollection_oaDerivedLayerParamDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDerivedLayerParamDef_oaSessionObject* self = (PyoaCollection_oaDerivedLayerParamDef_oaSessionObject*)bself;
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
static char oaCollection_oaDerivedLayerParamDef_oaSession_includes_doc[] = 
"Class: oaCollection_oaDerivedLayerParamDef_oaSession, Function: includes\n"
"  Paramegers: (oaDerivedLayerParamDef)\n"
"    Calls: oaBoolean includes(const oaDerivedLayerParamDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDerivedLayerParamDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDerivedLayerParamDef_oaSession_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDerivedLayerParamDef_oaSession data;
    int convert_status=PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDerivedLayerParamDef_oaSessionObject* self=(PyoaCollection_oaDerivedLayerParamDef_oaSessionObject*)ob;

    PyParamoaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParamDef_Convert,&p1)) {
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

static char oaCollection_oaDerivedLayerParamDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaDerivedLayerParamDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDerivedLayerParamDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDerivedLayerParamDef_oaSession data;
  int convert_status=PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDerivedLayerParamDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDerivedLayerParamDef_oaSession_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDerivedLayerParamDef_oaSession_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDerivedLayerParamDef_oaSession_includes,METH_VARARGS,oaCollection_oaDerivedLayerParamDef_oaSession_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDerivedLayerParamDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaDerivedLayerParamDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDerivedLayerParamDef_oaSession_doc[] = 
"Class: oaCollection_oaDerivedLayerParamDef_oaSession\n"
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
"  Paramegers: (oaCollection_oaDerivedLayerParamDef_oaSession)\n"
"    Calls: oaCollection_oaDerivedLayerParamDef_oaSession(const oaCollection_oaDerivedLayerParamDef_oaSession& coll)\n"
"    Signature: oaCollection_oaDerivedLayerParamDef_oaSession||cref-oaCollection_oaDerivedLayerParamDef_oaSession,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDerivedLayerParamDef_oaSession)\n"
"    Calls: (const oaCollection_oaDerivedLayerParamDef_oaSession&)\n"
"    Signature: oaCollection_oaDerivedLayerParamDef_oaSession||cref-oaCollection_oaDerivedLayerParamDef_oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDerivedLayerParamDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDerivedLayerParamDef_oaSession",
    sizeof(PyoaCollection_oaDerivedLayerParamDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaDerivedLayerParamDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDerivedLayerParamDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDerivedLayerParamDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDerivedLayerParamDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDerivedLayerParamDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDerivedLayerParamDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDerivedLayerParamDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDerivedLayerParamDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDerivedLayerParamDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDerivedLayerParamDef_oaSession",
           (PyObject*)(&PyoaCollection_oaDerivedLayerParamDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDerivedLayerParamDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDerivedLayerParam_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerParam_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDerivedLayerParam_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDerivedLayerParam_oaTechObject* self = (PyoaCollection_oaDerivedLayerParam_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDerivedLayerParam_oaTech)
    {
        PyParamoaCollection_oaDerivedLayerParam_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDerivedLayerParam_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDerivedLayerParam_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDerivedLayerParam_oaTech, Choices are:\n"
        "    (oaCollection_oaDerivedLayerParam_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDerivedLayerParam_oaTech_tp_dealloc(PyoaCollection_oaDerivedLayerParam_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDerivedLayerParam_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDerivedLayerParam_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDerivedLayerParam_oaTech value;
    int convert_status=PyoaCollection_oaDerivedLayerParam_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaDerivedLayerParam_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDerivedLayerParam_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDerivedLayerParam_oaTech v1;
    PyParamoaCollection_oaDerivedLayerParam_oaTech v2;
    int convert_status1=PyoaCollection_oaDerivedLayerParam_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDerivedLayerParam_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDerivedLayerParam_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaDerivedLayerParam_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDerivedLayerParam_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaDerivedLayerParam_oaTech*) ((PyoaCollection_oaDerivedLayerParam_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDerivedLayerParam_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDerivedLayerParam_oaTech_FromoaCollection_oaDerivedLayerParam_oaTech(oaCollection_oaDerivedLayerParam_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDerivedLayerParam_oaTech_Type.tp_alloc(&PyoaCollection_oaDerivedLayerParam_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDerivedLayerParam_oaTechObject* self = (PyoaCollection_oaDerivedLayerParam_oaTechObject*)bself;
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
static char oaCollection_oaDerivedLayerParam_oaTech_includes_doc[] = 
"Class: oaCollection_oaDerivedLayerParam_oaTech, Function: includes\n"
"  Paramegers: (oaDerivedLayerParam)\n"
"    Calls: oaBoolean includes(const oaDerivedLayerParam* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDerivedLayerParam,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDerivedLayerParam_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDerivedLayerParam_oaTech data;
    int convert_status=PyoaCollection_oaDerivedLayerParam_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDerivedLayerParam_oaTechObject* self=(PyoaCollection_oaDerivedLayerParam_oaTechObject*)ob;

    PyParamoaDerivedLayerParam p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParam_Convert,&p1)) {
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

static char oaCollection_oaDerivedLayerParam_oaTech_assign_doc[] = 
"Class: oaCollection_oaDerivedLayerParam_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDerivedLayerParam_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDerivedLayerParam_oaTech data;
  int convert_status=PyoaCollection_oaDerivedLayerParam_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDerivedLayerParam_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDerivedLayerParam_oaTech_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDerivedLayerParam_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDerivedLayerParam_oaTech_includes,METH_VARARGS,oaCollection_oaDerivedLayerParam_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDerivedLayerParam_oaTech_tp_assign,METH_VARARGS,oaCollection_oaDerivedLayerParam_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDerivedLayerParam_oaTech_doc[] = 
"Class: oaCollection_oaDerivedLayerParam_oaTech\n"
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
"  Paramegers: (oaCollection_oaDerivedLayerParam_oaTech)\n"
"    Calls: oaCollection_oaDerivedLayerParam_oaTech(const oaCollection_oaDerivedLayerParam_oaTech& coll)\n"
"    Signature: oaCollection_oaDerivedLayerParam_oaTech||cref-oaCollection_oaDerivedLayerParam_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDerivedLayerParam_oaTech)\n"
"    Calls: (const oaCollection_oaDerivedLayerParam_oaTech&)\n"
"    Signature: oaCollection_oaDerivedLayerParam_oaTech||cref-oaCollection_oaDerivedLayerParam_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDerivedLayerParam_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDerivedLayerParam_oaTech",
    sizeof(PyoaCollection_oaDerivedLayerParam_oaTechObject),
    0,
    (destructor)oaCollection_oaDerivedLayerParam_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDerivedLayerParam_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDerivedLayerParam_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDerivedLayerParam_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDerivedLayerParam_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDerivedLayerParam_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDerivedLayerParam_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDerivedLayerParam_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDerivedLayerParam_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDerivedLayerParam_oaTech",
           (PyObject*)(&PyoaCollection_oaDerivedLayerParam_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDerivedLayerParam_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDesignInst_oaFrame
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignInst_oaFrame_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDesignInst_oaFrame_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDesignInst_oaFrameObject* self = (PyoaCollection_oaDesignInst_oaFrameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesignInst_oaFrame)
    {
        PyParamoaCollection_oaDesignInst_oaFrame p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignInst_oaFrame_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDesignInst_oaFrame(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDesignInst_oaFrame, Choices are:\n"
        "    (oaCollection_oaDesignInst_oaFrame)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDesignInst_oaFrame_tp_dealloc(PyoaCollection_oaDesignInst_oaFrameObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDesignInst_oaFrame*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignInst_oaFrame_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDesignInst_oaFrame value;
    int convert_status=PyoaCollection_oaDesignInst_oaFrame_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaDesignInst_oaFrame::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDesignInst_oaFrame_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDesignInst_oaFrame v1;
    PyParamoaCollection_oaDesignInst_oaFrame v2;
    int convert_status1=PyoaCollection_oaDesignInst_oaFrame_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDesignInst_oaFrame_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDesignInst_oaFrame_Convert(PyObject* ob,PyParamoaCollection_oaDesignInst_oaFrame* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDesignInst_oaFrame_Check(ob)) {
        result->SetData( (oaCollection_oaDesignInst_oaFrame*) ((PyoaCollection_oaDesignInst_oaFrameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDesignInst_oaFrame Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDesignInst_oaFrame_FromoaCollection_oaDesignInst_oaFrame(oaCollection_oaDesignInst_oaFrame* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDesignInst_oaFrame_Type.tp_alloc(&PyoaCollection_oaDesignInst_oaFrame_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDesignInst_oaFrameObject* self = (PyoaCollection_oaDesignInst_oaFrameObject*)bself;
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
static char oaCollection_oaDesignInst_oaFrame_includes_doc[] = 
"Class: oaCollection_oaDesignInst_oaFrame, Function: includes\n"
"  Paramegers: (oaDesignInst)\n"
"    Calls: oaBoolean includes(const oaDesignInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDesignInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDesignInst_oaFrame_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignInst_oaFrame data;
    int convert_status=PyoaCollection_oaDesignInst_oaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignInst_oaFrameObject* self=(PyoaCollection_oaDesignInst_oaFrameObject*)ob;

    PyParamoaDesignInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignInst_Convert,&p1)) {
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

static char oaCollection_oaDesignInst_oaFrame_assign_doc[] = 
"Class: oaCollection_oaDesignInst_oaFrame, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDesignInst_oaFrame_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDesignInst_oaFrame data;
  int convert_status=PyoaCollection_oaDesignInst_oaFrame_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDesignInst_oaFrame p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDesignInst_oaFrame_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDesignInst_oaFrame_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDesignInst_oaFrame_includes,METH_VARARGS,oaCollection_oaDesignInst_oaFrame_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDesignInst_oaFrame_tp_assign,METH_VARARGS,oaCollection_oaDesignInst_oaFrame_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDesignInst_oaFrame_doc[] = 
"Class: oaCollection_oaDesignInst_oaFrame\n"
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
"  Paramegers: (oaCollection_oaDesignInst_oaFrame)\n"
"    Calls: oaCollection_oaDesignInst_oaFrame(const oaCollection_oaDesignInst_oaFrame& coll)\n"
"    Signature: oaCollection_oaDesignInst_oaFrame||cref-oaCollection_oaDesignInst_oaFrame,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDesignInst_oaFrame)\n"
"    Calls: (const oaCollection_oaDesignInst_oaFrame&)\n"
"    Signature: oaCollection_oaDesignInst_oaFrame||cref-oaCollection_oaDesignInst_oaFrame,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDesignInst_oaFrame_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDesignInst_oaFrame",
    sizeof(PyoaCollection_oaDesignInst_oaFrameObject),
    0,
    (destructor)oaCollection_oaDesignInst_oaFrame_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDesignInst_oaFrame_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDesignInst_oaFrame_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDesignInst_oaFrame_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDesignInst_oaFrame_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDesignInst_oaFrame_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDesignInst_oaFrame_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDesignInst_oaFrame_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDesignInst_oaFrame\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDesignInst_oaFrame",
           (PyObject*)(&PyoaCollection_oaDesignInst_oaFrame_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDesignInst_oaFrame\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDesignInst_oaReticle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignInst_oaReticle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDesignInst_oaReticle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDesignInst_oaReticleObject* self = (PyoaCollection_oaDesignInst_oaReticleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesignInst_oaReticle)
    {
        PyParamoaCollection_oaDesignInst_oaReticle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignInst_oaReticle_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDesignInst_oaReticle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDesignInst_oaReticle, Choices are:\n"
        "    (oaCollection_oaDesignInst_oaReticle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDesignInst_oaReticle_tp_dealloc(PyoaCollection_oaDesignInst_oaReticleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDesignInst_oaReticle*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignInst_oaReticle_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDesignInst_oaReticle value;
    int convert_status=PyoaCollection_oaDesignInst_oaReticle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaDesignInst_oaReticle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDesignInst_oaReticle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDesignInst_oaReticle v1;
    PyParamoaCollection_oaDesignInst_oaReticle v2;
    int convert_status1=PyoaCollection_oaDesignInst_oaReticle_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDesignInst_oaReticle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDesignInst_oaReticle_Convert(PyObject* ob,PyParamoaCollection_oaDesignInst_oaReticle* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDesignInst_oaReticle_Check(ob)) {
        result->SetData( (oaCollection_oaDesignInst_oaReticle*) ((PyoaCollection_oaDesignInst_oaReticleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDesignInst_oaReticle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDesignInst_oaReticle_FromoaCollection_oaDesignInst_oaReticle(oaCollection_oaDesignInst_oaReticle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDesignInst_oaReticle_Type.tp_alloc(&PyoaCollection_oaDesignInst_oaReticle_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDesignInst_oaReticleObject* self = (PyoaCollection_oaDesignInst_oaReticleObject*)bself;
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
static char oaCollection_oaDesignInst_oaReticle_includes_doc[] = 
"Class: oaCollection_oaDesignInst_oaReticle, Function: includes\n"
"  Paramegers: (oaDesignInst)\n"
"    Calls: oaBoolean includes(const oaDesignInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDesignInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDesignInst_oaReticle_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignInst_oaReticle data;
    int convert_status=PyoaCollection_oaDesignInst_oaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignInst_oaReticleObject* self=(PyoaCollection_oaDesignInst_oaReticleObject*)ob;

    PyParamoaDesignInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignInst_Convert,&p1)) {
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

static char oaCollection_oaDesignInst_oaReticle_assign_doc[] = 
"Class: oaCollection_oaDesignInst_oaReticle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDesignInst_oaReticle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDesignInst_oaReticle data;
  int convert_status=PyoaCollection_oaDesignInst_oaReticle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDesignInst_oaReticle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDesignInst_oaReticle_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDesignInst_oaReticle_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDesignInst_oaReticle_includes,METH_VARARGS,oaCollection_oaDesignInst_oaReticle_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDesignInst_oaReticle_tp_assign,METH_VARARGS,oaCollection_oaDesignInst_oaReticle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDesignInst_oaReticle_doc[] = 
"Class: oaCollection_oaDesignInst_oaReticle\n"
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
"  Paramegers: (oaCollection_oaDesignInst_oaReticle)\n"
"    Calls: oaCollection_oaDesignInst_oaReticle(const oaCollection_oaDesignInst_oaReticle& coll)\n"
"    Signature: oaCollection_oaDesignInst_oaReticle||cref-oaCollection_oaDesignInst_oaReticle,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDesignInst_oaReticle)\n"
"    Calls: (const oaCollection_oaDesignInst_oaReticle&)\n"
"    Signature: oaCollection_oaDesignInst_oaReticle||cref-oaCollection_oaDesignInst_oaReticle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDesignInst_oaReticle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDesignInst_oaReticle",
    sizeof(PyoaCollection_oaDesignInst_oaReticleObject),
    0,
    (destructor)oaCollection_oaDesignInst_oaReticle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDesignInst_oaReticle_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDesignInst_oaReticle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDesignInst_oaReticle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDesignInst_oaReticle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDesignInst_oaReticle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDesignInst_oaReticle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDesignInst_oaReticle_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDesignInst_oaReticle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDesignInst_oaReticle",
           (PyObject*)(&PyoaCollection_oaDesignInst_oaReticle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDesignInst_oaReticle\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDesignObject_oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignObject_oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDesignObject_oaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDesignObject_oaNodeObject* self = (PyoaCollection_oaDesignObject_oaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesignObject_oaNode)
    {
        PyParamoaCollection_oaDesignObject_oaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignObject_oaNode_Convert,&p1)) {
            self->value =  new oaCollection_oaDesignObject_oaNode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDesignObject_oaNode, Choices are:\n"
        "    (oaCollection_oaDesignObject_oaNode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDesignObject_oaNode_tp_dealloc(PyoaCollection_oaDesignObject_oaNodeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignObject_oaNode_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDesignObject_oaNode value;
    int convert_status=PyoaCollection_oaDesignObject_oaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaDesignObject_oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDesignObject_oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDesignObject_oaNode v1;
    PyParamoaCollection_oaDesignObject_oaNode v2;
    int convert_status1=PyoaCollection_oaDesignObject_oaNode_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDesignObject_oaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDesignObject_oaNode_Convert(PyObject* ob,PyParamoaCollection_oaDesignObject_oaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDesignObject_oaNode_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaDesignObject_oaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDesignObject_oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDesignObject_oaNode_FromoaCollection_oaDesignObject_oaNode(oaCollection_oaDesignObject_oaNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDesignObject_oaNode_Type.tp_alloc(&PyoaCollection_oaDesignObject_oaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDesignObject_oaNodeObject* self = (PyoaCollection_oaDesignObject_oaNodeObject*)bself;
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
static char oaCollection_oaDesignObject_oaNode_getCount_doc[] = 
"Class: oaCollection_oaDesignObject_oaNode, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaDesignObject_oaNode_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaNode data;
    int convert_status=PyoaCollection_oaDesignObject_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaNodeObject* self=(PyoaCollection_oaDesignObject_oaNodeObject*)ob;

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
static char oaCollection_oaDesignObject_oaNode_includes_doc[] = 
"Class: oaCollection_oaDesignObject_oaNode, Function: includes\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: oaBoolean includes(const oaDesignObject* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDesignObject,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaDesignObject_oaNode_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaNode data;
    int convert_status=PyoaCollection_oaDesignObject_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaNodeObject* self=(PyoaCollection_oaDesignObject_oaNodeObject*)ob;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
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
static char oaCollection_oaDesignObject_oaNode_isEmpty_doc[] = 
"Class: oaCollection_oaDesignObject_oaNode, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaDesignObject_oaNode_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaNode data;
    int convert_status=PyoaCollection_oaDesignObject_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaNodeObject* self=(PyoaCollection_oaDesignObject_oaNodeObject*)ob;

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

static char oaCollection_oaDesignObject_oaNode_assign_doc[] = 
"Class: oaCollection_oaDesignObject_oaNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDesignObject_oaNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDesignObject_oaNode data;
  int convert_status=PyoaCollection_oaDesignObject_oaNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDesignObject_oaNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDesignObject_oaNode_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDesignObject_oaNode_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaDesignObject_oaNode_getCount,METH_VARARGS,oaCollection_oaDesignObject_oaNode_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaDesignObject_oaNode_includes,METH_VARARGS,oaCollection_oaDesignObject_oaNode_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaDesignObject_oaNode_isEmpty,METH_VARARGS,oaCollection_oaDesignObject_oaNode_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaDesignObject_oaNode_tp_assign,METH_VARARGS,oaCollection_oaDesignObject_oaNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDesignObject_oaNode_doc[] = 
"Class: oaCollection_oaDesignObject_oaNode\n"
"  Class type oaCollection_oaDesignObject_oaNode\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaDesignObject_oaNode)\n"
"    Calls: oaCollection_oaDesignObject_oaNode(const oaCollection_oaDesignObject_oaNode& c)\n"
"    Signature: oaCollection_oaDesignObject_oaNode||cref-oaCollection_oaDesignObject_oaNode,\n"
"    Constructor oaCollection_oaDesignObject_oaNode\n"
"  Paramegers: (oaCollection_oaDesignObject_oaNode)\n"
"    Calls: (const oaCollection_oaDesignObject_oaNode&)\n"
"    Signature: oaCollection_oaDesignObject_oaNode||cref-oaCollection_oaDesignObject_oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDesignObject_oaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDesignObject_oaNode",
    sizeof(PyoaCollection_oaDesignObject_oaNodeObject),
    0,
    (destructor)oaCollection_oaDesignObject_oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDesignObject_oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDesignObject_oaNode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDesignObject_oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDesignObject_oaNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDesignObject_oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDesignObject_oaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDesignObject_oaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDesignObject_oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDesignObject_oaNode",
           (PyObject*)(&PyoaCollection_oaDesignObject_oaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDesignObject_oaNode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDesignObject_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDesignObject_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self = (PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDesignObject_oaParasiticNetwork)
    {
        PyParamoaCollection_oaDesignObject_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert,&p1)) {
            self->value =  new oaCollection_oaDesignObject_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDesignObject_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaDesignObject_oaParasiticNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDesignObject_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[68];
    sprintf(buffer,"<oaCollection_oaDesignObject_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDesignObject_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork v1;
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaDesignObject_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDesignObject_oaParasiticNetwork_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDesignObject_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDesignObject_oaParasiticNetwork_FromoaCollection_oaDesignObject_oaParasiticNetwork(oaCollection_oaDesignObject_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDesignObject_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaDesignObject_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self = (PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)bself;
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
static char oaCollection_oaDesignObject_oaParasiticNetwork_getCount_doc[] = 
"Class: oaCollection_oaDesignObject_oaParasiticNetwork, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self=(PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)ob;

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
static char oaCollection_oaDesignObject_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaDesignObject_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: oaBoolean includes(const oaDesignObject* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDesignObject,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self=(PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)ob;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
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
static char oaCollection_oaDesignObject_oaParasiticNetwork_isEmpty_doc[] = 
"Class: oaCollection_oaDesignObject_oaParasiticNetwork, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDesignObject_oaParasiticNetworkObject* self=(PyoaCollection_oaDesignObject_oaParasiticNetworkObject*)ob;

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

static char oaCollection_oaDesignObject_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaDesignObject_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDesignObject_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDesignObject_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDesignObject_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDesignObject_oaParasiticNetwork_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDesignObject_oaParasiticNetwork_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaDesignObject_oaParasiticNetwork_getCount,METH_VARARGS,oaCollection_oaDesignObject_oaParasiticNetwork_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaDesignObject_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaDesignObject_oaParasiticNetwork_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaDesignObject_oaParasiticNetwork_isEmpty,METH_VARARGS,oaCollection_oaDesignObject_oaParasiticNetwork_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaDesignObject_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaDesignObject_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDesignObject_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaDesignObject_oaParasiticNetwork\n"
"  Class type oaCollection_oaDesignObject_oaParasiticNetwork\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaDesignObject_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaDesignObject_oaParasiticNetwork(const oaCollection_oaDesignObject_oaParasiticNetwork& c)\n"
"    Signature: oaCollection_oaDesignObject_oaParasiticNetwork||cref-oaCollection_oaDesignObject_oaParasiticNetwork,\n"
"    Constructor oaCollection_oaDesignObject_oaParasiticNetwork\n"
"  Paramegers: (oaCollection_oaDesignObject_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaDesignObject_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaDesignObject_oaParasiticNetwork||cref-oaCollection_oaDesignObject_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDesignObject_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDesignObject_oaParasiticNetwork",
    sizeof(PyoaCollection_oaDesignObject_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaDesignObject_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDesignObject_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDesignObject_oaParasiticNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDesignObject_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDesignObject_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDesignObject_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDesignObject_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDesignObject_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDesignObject_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDesignObject_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaDesignObject_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDesignObject_oaParasiticNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDesign_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesign_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDesign_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDesign_oaDesignObject* self = (PyoaCollection_oaDesign_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDesign_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaDesignCollTypeEnum)
    {
        PyParamoaUInt4 p1;
        PyParamoaDesignCollTypeEnum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaDesignCollTypeEnum_Convert,&p2)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDesign_oaDesign(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaDesignCollTypeEnum,oaDesign)
    {
        PyParamoaUInt4 p1;
        PyParamoaDesignCollTypeEnum p2;
        PyParamoaDesign p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaDesignCollTypeEnum_Convert,&p2,
              &PyoaDesign_Convert,&p3)) {
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDesign_oaDesign(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaDesign_oaDesign)
    {
        PyParamoaCollection_oaDesign_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDesign_oaDesign_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaDesign_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDesign_oaDesign, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaDesignCollTypeEnum)\n"
        "    (oaUInt4,oaDesignCollTypeEnum,oaDesign)\n"
        "    (oaCollection_oaDesign_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDesign_oaDesign_tp_dealloc(PyoaCollection_oaDesign_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDesign_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDesign_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDesign_oaDesign value;
    int convert_status=PyoaCollection_oaDesign_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaDesign_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDesign_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDesign_oaDesign v1;
    PyParamoaCollection_oaDesign_oaDesign v2;
    int convert_status1=PyoaCollection_oaDesign_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDesign_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDesign_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaDesign_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDesign_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaDesign_oaDesign*) ((PyoaCollection_oaDesign_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDesign_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDesign_oaDesign_FromoaCollection_oaDesign_oaDesign(oaCollection_oaDesign_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDesign_oaDesign_Type.tp_alloc(&PyoaCollection_oaDesign_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDesign_oaDesignObject* self = (PyoaCollection_oaDesign_oaDesignObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDesign_oaDesign_doc[] = 
"Class: oaCollection_oaDesign_oaDesign\n"
"  Class type oaCollection_oaDesign_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaDesign_oaDesign(oaUInt4 dbIDIn)\n"
"    Signature: oaCollection_oaDesign_oaDesign||simple-oaUInt4,simple-oaDesignCollTypeEnum,cptr-oaDesign,\n"
"    Constructor oaCollection_oaDesign_oaDesign\n"
"  Paramegers: (oaUInt4,oaDesignCollTypeEnum)\n"
"    Calls: oaCollection_oaDesign_oaDesign(oaUInt4 dbIDIn,oaDesignCollTypeEnum tIn)\n"
"    Signature: oaCollection_oaDesign_oaDesign||simple-oaUInt4,simple-oaDesignCollTypeEnum,cptr-oaDesign,\n"
"    Constructor oaCollection_oaDesign_oaDesign\n"
"  Paramegers: (oaUInt4,oaDesignCollTypeEnum,oaDesign)\n"
"    Calls: oaCollection_oaDesign_oaDesign(oaUInt4 dbIDIn,oaDesignCollTypeEnum tIn,const oaDesign* design)\n"
"    Signature: oaCollection_oaDesign_oaDesign||simple-oaUInt4,simple-oaDesignCollTypeEnum,cptr-oaDesign,\n"
"    Constructor oaCollection_oaDesign_oaDesign\n"
"  Paramegers: (oaCollection_oaDesign_oaDesign)\n"
"    Calls: oaCollection_oaDesign_oaDesign(const oaCollection_oaDesign_oaDesign& c)\n"
"    Signature: oaCollection_oaDesign_oaDesign||cref-oaCollection_oaDesign_oaDesign,\n"
"    Constructor oaCollection_oaDesign_oaDesign\n"
"  Paramegers: (oaCollection_oaDesign_oaDesign)\n"
"    Calls: (const oaCollection_oaDesign_oaDesign&)\n"
"    Signature: oaCollection_oaDesign_oaDesign||cref-oaCollection_oaDesign_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDesign_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDesign_oaDesign",
    sizeof(PyoaCollection_oaDesign_oaDesignObject),
    0,
    (destructor)oaCollection_oaDesign_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDesign_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDesign_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDesign_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDesign_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDesign_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDesign_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDesign_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDesign_oaDesign",
           (PyObject*)(&PyoaCollection_oaDesign_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDesign_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDevice_oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDevice_oaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDevice_oaNodeObject* self = (PyoaCollection_oaDevice_oaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDevice_oaNode)
    {
        PyParamoaCollection_oaDevice_oaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDevice_oaNode_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDevice_oaNode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDevice_oaNode, Choices are:\n"
        "    (oaCollection_oaDevice_oaNode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDevice_oaNode_tp_dealloc(PyoaCollection_oaDevice_oaNodeObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDevice_oaNode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaNode_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDevice_oaNode value;
    int convert_status=PyoaCollection_oaDevice_oaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaDevice_oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDevice_oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDevice_oaNode v1;
    PyParamoaCollection_oaDevice_oaNode v2;
    int convert_status1=PyoaCollection_oaDevice_oaNode_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDevice_oaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDevice_oaNode_Convert(PyObject* ob,PyParamoaCollection_oaDevice_oaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDevice_oaNode_Check(ob)) {
        result->SetData( (oaCollection_oaDevice_oaNode*) ((PyoaCollection_oaDevice_oaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDevice_oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDevice_oaNode_FromoaCollection_oaDevice_oaNode(oaCollection_oaDevice_oaNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDevice_oaNode_Type.tp_alloc(&PyoaCollection_oaDevice_oaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDevice_oaNodeObject* self = (PyoaCollection_oaDevice_oaNodeObject*)bself;
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
static char oaCollection_oaDevice_oaNode_includes_doc[] = 
"Class: oaCollection_oaDevice_oaNode, Function: includes\n"
"  Paramegers: (oaDevice)\n"
"    Calls: oaBoolean includes(const oaDevice* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDevice,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDevice_oaNode_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDevice_oaNode data;
    int convert_status=PyoaCollection_oaDevice_oaNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDevice_oaNodeObject* self=(PyoaCollection_oaDevice_oaNodeObject*)ob;

    PyParamoaDevice p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDevice_Convert,&p1)) {
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

static char oaCollection_oaDevice_oaNode_assign_doc[] = 
"Class: oaCollection_oaDevice_oaNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDevice_oaNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDevice_oaNode data;
  int convert_status=PyoaCollection_oaDevice_oaNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDevice_oaNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDevice_oaNode_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDevice_oaNode_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDevice_oaNode_includes,METH_VARARGS,oaCollection_oaDevice_oaNode_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDevice_oaNode_tp_assign,METH_VARARGS,oaCollection_oaDevice_oaNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDevice_oaNode_doc[] = 
"Class: oaCollection_oaDevice_oaNode\n"
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
"  Paramegers: (oaCollection_oaDevice_oaNode)\n"
"    Calls: oaCollection_oaDevice_oaNode(const oaCollection_oaDevice_oaNode& coll)\n"
"    Signature: oaCollection_oaDevice_oaNode||cref-oaCollection_oaDevice_oaNode,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDevice_oaNode)\n"
"    Calls: (const oaCollection_oaDevice_oaNode&)\n"
"    Signature: oaCollection_oaDevice_oaNode||cref-oaCollection_oaDevice_oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDevice_oaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDevice_oaNode",
    sizeof(PyoaCollection_oaDevice_oaNodeObject),
    0,
    (destructor)oaCollection_oaDevice_oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDevice_oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDevice_oaNode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDevice_oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDevice_oaNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDevice_oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDevice_oaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDevice_oaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDevice_oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDevice_oaNode",
           (PyObject*)(&PyoaCollection_oaDevice_oaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDevice_oaNode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDevice_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDevice_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDevice_oaParasiticNetworkObject* self = (PyoaCollection_oaDevice_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDevice_oaParasiticNetwork)
    {
        PyParamoaCollection_oaDevice_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDevice_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDevice_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDevice_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaDevice_oaParasiticNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDevice_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaDevice_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDevice_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDevice_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaDevice_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaDevice_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDevice_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDevice_oaParasiticNetwork v1;
    PyParamoaCollection_oaDevice_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaDevice_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDevice_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDevice_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaDevice_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDevice_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaDevice_oaParasiticNetwork*) ((PyoaCollection_oaDevice_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDevice_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDevice_oaParasiticNetwork_FromoaCollection_oaDevice_oaParasiticNetwork(oaCollection_oaDevice_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDevice_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaDevice_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDevice_oaParasiticNetworkObject* self = (PyoaCollection_oaDevice_oaParasiticNetworkObject*)bself;
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
static char oaCollection_oaDevice_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaDevice_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaDevice)\n"
"    Calls: oaBoolean includes(const oaDevice* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDevice,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDevice_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDevice_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaDevice_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDevice_oaParasiticNetworkObject* self=(PyoaCollection_oaDevice_oaParasiticNetworkObject*)ob;

    PyParamoaDevice p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDevice_Convert,&p1)) {
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

static char oaCollection_oaDevice_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaDevice_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDevice_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDevice_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaDevice_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDevice_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDevice_oaParasiticNetwork_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDevice_oaParasiticNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDevice_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaDevice_oaParasiticNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDevice_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaDevice_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDevice_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaDevice_oaParasiticNetwork\n"
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
"  Paramegers: (oaCollection_oaDevice_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaDevice_oaParasiticNetwork(const oaCollection_oaDevice_oaParasiticNetwork& coll)\n"
"    Signature: oaCollection_oaDevice_oaParasiticNetwork||cref-oaCollection_oaDevice_oaParasiticNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDevice_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaDevice_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaDevice_oaParasiticNetwork||cref-oaCollection_oaDevice_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDevice_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDevice_oaParasiticNetwork",
    sizeof(PyoaCollection_oaDevice_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaDevice_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDevice_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDevice_oaParasiticNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDevice_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDevice_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDevice_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDevice_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDevice_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDevice_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDevice_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaDevice_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDevice_oaParasiticNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaDevice_oaSubNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaSubNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaDevice_oaSubNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaDevice_oaSubNetworkObject* self = (PyoaCollection_oaDevice_oaSubNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaDevice_oaSubNetwork)
    {
        PyParamoaCollection_oaDevice_oaSubNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaDevice_oaSubNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaDevice_oaSubNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaDevice_oaSubNetwork, Choices are:\n"
        "    (oaCollection_oaDevice_oaSubNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaDevice_oaSubNetwork_tp_dealloc(PyoaCollection_oaDevice_oaSubNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaDevice_oaSubNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaDevice_oaSubNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaDevice_oaSubNetwork value;
    int convert_status=PyoaCollection_oaDevice_oaSubNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaDevice_oaSubNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaDevice_oaSubNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaDevice_oaSubNetwork v1;
    PyParamoaCollection_oaDevice_oaSubNetwork v2;
    int convert_status1=PyoaCollection_oaDevice_oaSubNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaDevice_oaSubNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaDevice_oaSubNetwork_Convert(PyObject* ob,PyParamoaCollection_oaDevice_oaSubNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaDevice_oaSubNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaDevice_oaSubNetwork*) ((PyoaCollection_oaDevice_oaSubNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaDevice_oaSubNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaDevice_oaSubNetwork_FromoaCollection_oaDevice_oaSubNetwork(oaCollection_oaDevice_oaSubNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaDevice_oaSubNetwork_Type.tp_alloc(&PyoaCollection_oaDevice_oaSubNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaDevice_oaSubNetworkObject* self = (PyoaCollection_oaDevice_oaSubNetworkObject*)bself;
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
static char oaCollection_oaDevice_oaSubNetwork_includes_doc[] = 
"Class: oaCollection_oaDevice_oaSubNetwork, Function: includes\n"
"  Paramegers: (oaDevice)\n"
"    Calls: oaBoolean includes(const oaDevice* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaDevice,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaDevice_oaSubNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaDevice_oaSubNetwork data;
    int convert_status=PyoaCollection_oaDevice_oaSubNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaDevice_oaSubNetworkObject* self=(PyoaCollection_oaDevice_oaSubNetworkObject*)ob;

    PyParamoaDevice p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDevice_Convert,&p1)) {
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

static char oaCollection_oaDevice_oaSubNetwork_assign_doc[] = 
"Class: oaCollection_oaDevice_oaSubNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaDevice_oaSubNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaDevice_oaSubNetwork data;
  int convert_status=PyoaCollection_oaDevice_oaSubNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaDevice_oaSubNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaDevice_oaSubNetwork_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaDevice_oaSubNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaDevice_oaSubNetwork_includes,METH_VARARGS,oaCollection_oaDevice_oaSubNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaDevice_oaSubNetwork_tp_assign,METH_VARARGS,oaCollection_oaDevice_oaSubNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaDevice_oaSubNetwork_doc[] = 
"Class: oaCollection_oaDevice_oaSubNetwork\n"
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
"  Paramegers: (oaCollection_oaDevice_oaSubNetwork)\n"
"    Calls: oaCollection_oaDevice_oaSubNetwork(const oaCollection_oaDevice_oaSubNetwork& coll)\n"
"    Signature: oaCollection_oaDevice_oaSubNetwork||cref-oaCollection_oaDevice_oaSubNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaDevice_oaSubNetwork)\n"
"    Calls: (const oaCollection_oaDevice_oaSubNetwork&)\n"
"    Signature: oaCollection_oaDevice_oaSubNetwork||cref-oaCollection_oaDevice_oaSubNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaDevice_oaSubNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaDevice_oaSubNetwork",
    sizeof(PyoaCollection_oaDevice_oaSubNetworkObject),
    0,
    (destructor)oaCollection_oaDevice_oaSubNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaDevice_oaSubNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaDevice_oaSubNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaDevice_oaSubNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaDevice_oaSubNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaDevice_oaSubNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaDevice_oaSubNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaDevice_oaSubNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaDevice_oaSubNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaDevice_oaSubNetwork",
           (PyObject*)(&PyoaCollection_oaDevice_oaSubNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaDevice_oaSubNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaElmore_oaLumpedElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaElmore_oaLumpedElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaElmore_oaLumpedElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaElmore_oaLumpedElmoreObject* self = (PyoaCollection_oaElmore_oaLumpedElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaElmore_oaLumpedElmore)
    {
        PyParamoaCollection_oaElmore_oaLumpedElmore p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaElmore_oaLumpedElmore_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaElmore_oaLumpedElmore(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaElmore_oaLumpedElmore, Choices are:\n"
        "    (oaCollection_oaElmore_oaLumpedElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaElmore_oaLumpedElmore_tp_dealloc(PyoaCollection_oaElmore_oaLumpedElmoreObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaElmore_oaLumpedElmore*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaElmore_oaLumpedElmore_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaElmore_oaLumpedElmore value;
    int convert_status=PyoaCollection_oaElmore_oaLumpedElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaElmore_oaLumpedElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaElmore_oaLumpedElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaElmore_oaLumpedElmore v1;
    PyParamoaCollection_oaElmore_oaLumpedElmore v2;
    int convert_status1=PyoaCollection_oaElmore_oaLumpedElmore_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaElmore_oaLumpedElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaElmore_oaLumpedElmore_Convert(PyObject* ob,PyParamoaCollection_oaElmore_oaLumpedElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaElmore_oaLumpedElmore_Check(ob)) {
        result->SetData( (oaCollection_oaElmore_oaLumpedElmore*) ((PyoaCollection_oaElmore_oaLumpedElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaElmore_oaLumpedElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaElmore_oaLumpedElmore_FromoaCollection_oaElmore_oaLumpedElmore(oaCollection_oaElmore_oaLumpedElmore* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaElmore_oaLumpedElmore_Type.tp_alloc(&PyoaCollection_oaElmore_oaLumpedElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaElmore_oaLumpedElmoreObject* self = (PyoaCollection_oaElmore_oaLumpedElmoreObject*)bself;
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
static char oaCollection_oaElmore_oaLumpedElmore_includes_doc[] = 
"Class: oaCollection_oaElmore_oaLumpedElmore, Function: includes\n"
"  Paramegers: (oaElmore)\n"
"    Calls: oaBoolean includes(const oaElmore* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaElmore,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaElmore_oaLumpedElmore_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaElmore_oaLumpedElmore data;
    int convert_status=PyoaCollection_oaElmore_oaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaElmore_oaLumpedElmoreObject* self=(PyoaCollection_oaElmore_oaLumpedElmoreObject*)ob;

    PyParamoaElmore p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaElmore_Convert,&p1)) {
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

static char oaCollection_oaElmore_oaLumpedElmore_assign_doc[] = 
"Class: oaCollection_oaElmore_oaLumpedElmore, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaElmore_oaLumpedElmore_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaElmore_oaLumpedElmore data;
  int convert_status=PyoaCollection_oaElmore_oaLumpedElmore_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaElmore_oaLumpedElmore p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaElmore_oaLumpedElmore_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaElmore_oaLumpedElmore_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaElmore_oaLumpedElmore_includes,METH_VARARGS,oaCollection_oaElmore_oaLumpedElmore_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaElmore_oaLumpedElmore_tp_assign,METH_VARARGS,oaCollection_oaElmore_oaLumpedElmore_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaElmore_oaLumpedElmore_doc[] = 
"Class: oaCollection_oaElmore_oaLumpedElmore\n"
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
"  Paramegers: (oaCollection_oaElmore_oaLumpedElmore)\n"
"    Calls: oaCollection_oaElmore_oaLumpedElmore(const oaCollection_oaElmore_oaLumpedElmore& coll)\n"
"    Signature: oaCollection_oaElmore_oaLumpedElmore||cref-oaCollection_oaElmore_oaLumpedElmore,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaElmore_oaLumpedElmore)\n"
"    Calls: (const oaCollection_oaElmore_oaLumpedElmore&)\n"
"    Signature: oaCollection_oaElmore_oaLumpedElmore||cref-oaCollection_oaElmore_oaLumpedElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaElmore_oaLumpedElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaElmore_oaLumpedElmore",
    sizeof(PyoaCollection_oaElmore_oaLumpedElmoreObject),
    0,
    (destructor)oaCollection_oaElmore_oaLumpedElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaElmore_oaLumpedElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaElmore_oaLumpedElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaElmore_oaLumpedElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaElmore_oaLumpedElmore_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaElmore_oaLumpedElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaElmore_oaLumpedElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaElmore_oaLumpedElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaElmore_oaLumpedElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaElmore_oaLumpedElmore",
           (PyObject*)(&PyoaCollection_oaElmore_oaLumpedElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaElmore_oaLumpedElmore\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaElmore_oaPiElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaElmore_oaPiElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaElmore_oaPiElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaElmore_oaPiElmoreObject* self = (PyoaCollection_oaElmore_oaPiElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaElmore_oaPiElmore)
    {
        PyParamoaCollection_oaElmore_oaPiElmore p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaElmore_oaPiElmore_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaElmore_oaPiElmore(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaElmore_oaPiElmore, Choices are:\n"
        "    (oaCollection_oaElmore_oaPiElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaElmore_oaPiElmore_tp_dealloc(PyoaCollection_oaElmore_oaPiElmoreObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaElmore_oaPiElmore*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaElmore_oaPiElmore_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaElmore_oaPiElmore value;
    int convert_status=PyoaCollection_oaElmore_oaPiElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaElmore_oaPiElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaElmore_oaPiElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaElmore_oaPiElmore v1;
    PyParamoaCollection_oaElmore_oaPiElmore v2;
    int convert_status1=PyoaCollection_oaElmore_oaPiElmore_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaElmore_oaPiElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaElmore_oaPiElmore_Convert(PyObject* ob,PyParamoaCollection_oaElmore_oaPiElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaElmore_oaPiElmore_Check(ob)) {
        result->SetData( (oaCollection_oaElmore_oaPiElmore*) ((PyoaCollection_oaElmore_oaPiElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaElmore_oaPiElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaElmore_oaPiElmore_FromoaCollection_oaElmore_oaPiElmore(oaCollection_oaElmore_oaPiElmore* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaElmore_oaPiElmore_Type.tp_alloc(&PyoaCollection_oaElmore_oaPiElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaElmore_oaPiElmoreObject* self = (PyoaCollection_oaElmore_oaPiElmoreObject*)bself;
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
static char oaCollection_oaElmore_oaPiElmore_includes_doc[] = 
"Class: oaCollection_oaElmore_oaPiElmore, Function: includes\n"
"  Paramegers: (oaElmore)\n"
"    Calls: oaBoolean includes(const oaElmore* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaElmore,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaElmore_oaPiElmore_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaElmore_oaPiElmore data;
    int convert_status=PyoaCollection_oaElmore_oaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaElmore_oaPiElmoreObject* self=(PyoaCollection_oaElmore_oaPiElmoreObject*)ob;

    PyParamoaElmore p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaElmore_Convert,&p1)) {
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

static char oaCollection_oaElmore_oaPiElmore_assign_doc[] = 
"Class: oaCollection_oaElmore_oaPiElmore, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaElmore_oaPiElmore_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaElmore_oaPiElmore data;
  int convert_status=PyoaCollection_oaElmore_oaPiElmore_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaElmore_oaPiElmore p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaElmore_oaPiElmore_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaElmore_oaPiElmore_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaElmore_oaPiElmore_includes,METH_VARARGS,oaCollection_oaElmore_oaPiElmore_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaElmore_oaPiElmore_tp_assign,METH_VARARGS,oaCollection_oaElmore_oaPiElmore_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaElmore_oaPiElmore_doc[] = 
"Class: oaCollection_oaElmore_oaPiElmore\n"
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
"  Paramegers: (oaCollection_oaElmore_oaPiElmore)\n"
"    Calls: oaCollection_oaElmore_oaPiElmore(const oaCollection_oaElmore_oaPiElmore& coll)\n"
"    Signature: oaCollection_oaElmore_oaPiElmore||cref-oaCollection_oaElmore_oaPiElmore,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaElmore_oaPiElmore)\n"
"    Calls: (const oaCollection_oaElmore_oaPiElmore&)\n"
"    Signature: oaCollection_oaElmore_oaPiElmore||cref-oaCollection_oaElmore_oaPiElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaElmore_oaPiElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaElmore_oaPiElmore",
    sizeof(PyoaCollection_oaElmore_oaPiElmoreObject),
    0,
    (destructor)oaCollection_oaElmore_oaPiElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaElmore_oaPiElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaElmore_oaPiElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaElmore_oaPiElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaElmore_oaPiElmore_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaElmore_oaPiElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaElmore_oaPiElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaElmore_oaPiElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaElmore_oaPiElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaElmore_oaPiElmore",
           (PyObject*)(&PyoaCollection_oaElmore_oaPiElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaElmore_oaPiElmore\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaFigGroupMem_oaFigGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFigGroupMem_oaFigGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaFigGroupMem_oaFigGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaFigGroupMem_oaFigGroupObject* self = (PyoaCollection_oaFigGroupMem_oaFigGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaFigGroupMem_oaFigGroup)
    {
        PyParamoaCollection_oaFigGroupMem_oaFigGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaFigGroupMem_oaFigGroup_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaFigGroupMem_oaFigGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaFigGroupMem_oaFigGroup, Choices are:\n"
        "    (oaCollection_oaFigGroupMem_oaFigGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaFigGroupMem_oaFigGroup_tp_dealloc(PyoaCollection_oaFigGroupMem_oaFigGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaFigGroupMem_oaFigGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFigGroupMem_oaFigGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaFigGroupMem_oaFigGroup value;
    int convert_status=PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaFigGroupMem_oaFigGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaFigGroupMem_oaFigGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaFigGroupMem_oaFigGroup v1;
    PyParamoaCollection_oaFigGroupMem_oaFigGroup v2;
    int convert_status1=PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(PyObject* ob,PyParamoaCollection_oaFigGroupMem_oaFigGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaFigGroupMem_oaFigGroup_Check(ob)) {
        result->SetData( (oaCollection_oaFigGroupMem_oaFigGroup*) ((PyoaCollection_oaFigGroupMem_oaFigGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaFigGroupMem_oaFigGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaFigGroupMem_oaFigGroup_FromoaCollection_oaFigGroupMem_oaFigGroup(oaCollection_oaFigGroupMem_oaFigGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaFigGroupMem_oaFigGroup_Type.tp_alloc(&PyoaCollection_oaFigGroupMem_oaFigGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaFigGroupMem_oaFigGroupObject* self = (PyoaCollection_oaFigGroupMem_oaFigGroupObject*)bself;
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
static char oaCollection_oaFigGroupMem_oaFigGroup_includes_doc[] = 
"Class: oaCollection_oaFigGroupMem_oaFigGroup, Function: includes\n"
"  Paramegers: (oaFigGroupMem)\n"
"    Calls: oaBoolean includes(const oaFigGroupMem* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFigGroupMem,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaFigGroupMem_oaFigGroup_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaFigGroupMem_oaFigGroup data;
    int convert_status=PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaFigGroupMem_oaFigGroupObject* self=(PyoaCollection_oaFigGroupMem_oaFigGroupObject*)ob;

    PyParamoaFigGroupMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFigGroupMem_Convert,&p1)) {
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

static char oaCollection_oaFigGroupMem_oaFigGroup_assign_doc[] = 
"Class: oaCollection_oaFigGroupMem_oaFigGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaFigGroupMem_oaFigGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaFigGroupMem_oaFigGroup data;
  int convert_status=PyoaCollection_oaFigGroupMem_oaFigGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaFigGroupMem_oaFigGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaFigGroupMem_oaFigGroup_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaFigGroupMem_oaFigGroup_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaFigGroupMem_oaFigGroup_includes,METH_VARARGS,oaCollection_oaFigGroupMem_oaFigGroup_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaFigGroupMem_oaFigGroup_tp_assign,METH_VARARGS,oaCollection_oaFigGroupMem_oaFigGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaFigGroupMem_oaFigGroup_doc[] = 
"Class: oaCollection_oaFigGroupMem_oaFigGroup\n"
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
"  Paramegers: (oaCollection_oaFigGroupMem_oaFigGroup)\n"
"    Calls: oaCollection_oaFigGroupMem_oaFigGroup(const oaCollection_oaFigGroupMem_oaFigGroup& coll)\n"
"    Signature: oaCollection_oaFigGroupMem_oaFigGroup||cref-oaCollection_oaFigGroupMem_oaFigGroup,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaFigGroupMem_oaFigGroup)\n"
"    Calls: (const oaCollection_oaFigGroupMem_oaFigGroup&)\n"
"    Signature: oaCollection_oaFigGroupMem_oaFigGroup||cref-oaCollection_oaFigGroupMem_oaFigGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaFigGroupMem_oaFigGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaFigGroupMem_oaFigGroup",
    sizeof(PyoaCollection_oaFigGroupMem_oaFigGroupObject),
    0,
    (destructor)oaCollection_oaFigGroupMem_oaFigGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaFigGroupMem_oaFigGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaFigGroupMem_oaFigGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaFigGroupMem_oaFigGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaFigGroupMem_oaFigGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaFigGroupMem_oaFigGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaFigGroupMem_oaFigGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaFigGroupMem_oaFigGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaFigGroupMem_oaFigGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaFigGroupMem_oaFigGroup",
           (PyObject*)(&PyoaCollection_oaFigGroupMem_oaFigGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaFigGroupMem_oaFigGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaFigGroup_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFigGroup_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaFigGroup_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaFigGroup_oaBlockObject* self = (PyoaCollection_oaFigGroup_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaFigGroup_oaBlock)
    {
        PyParamoaCollection_oaFigGroup_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaFigGroup_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaFigGroup_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaFigGroup_oaBlock, Choices are:\n"
        "    (oaCollection_oaFigGroup_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaFigGroup_oaBlock_tp_dealloc(PyoaCollection_oaFigGroup_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaFigGroup_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFigGroup_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaFigGroup_oaBlock value;
    int convert_status=PyoaCollection_oaFigGroup_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaFigGroup_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaFigGroup_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaFigGroup_oaBlock v1;
    PyParamoaCollection_oaFigGroup_oaBlock v2;
    int convert_status1=PyoaCollection_oaFigGroup_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaFigGroup_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaFigGroup_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaFigGroup_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaFigGroup_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaFigGroup_oaBlock*) ((PyoaCollection_oaFigGroup_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaFigGroup_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaFigGroup_oaBlock_FromoaCollection_oaFigGroup_oaBlock(oaCollection_oaFigGroup_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaFigGroup_oaBlock_Type.tp_alloc(&PyoaCollection_oaFigGroup_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaFigGroup_oaBlockObject* self = (PyoaCollection_oaFigGroup_oaBlockObject*)bself;
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
static char oaCollection_oaFigGroup_oaBlock_includes_doc[] = 
"Class: oaCollection_oaFigGroup_oaBlock, Function: includes\n"
"  Paramegers: (oaFigGroup)\n"
"    Calls: oaBoolean includes(const oaFigGroup* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFigGroup,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaFigGroup_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaFigGroup_oaBlock data;
    int convert_status=PyoaCollection_oaFigGroup_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaFigGroup_oaBlockObject* self=(PyoaCollection_oaFigGroup_oaBlockObject*)ob;

    PyParamoaFigGroup p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFigGroup_Convert,&p1)) {
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

static char oaCollection_oaFigGroup_oaBlock_assign_doc[] = 
"Class: oaCollection_oaFigGroup_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaFigGroup_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaFigGroup_oaBlock data;
  int convert_status=PyoaCollection_oaFigGroup_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaFigGroup_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaFigGroup_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaFigGroup_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaFigGroup_oaBlock_includes,METH_VARARGS,oaCollection_oaFigGroup_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaFigGroup_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaFigGroup_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaFigGroup_oaBlock_doc[] = 
"Class: oaCollection_oaFigGroup_oaBlock\n"
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
"  Paramegers: (oaCollection_oaFigGroup_oaBlock)\n"
"    Calls: oaCollection_oaFigGroup_oaBlock(const oaCollection_oaFigGroup_oaBlock& coll)\n"
"    Signature: oaCollection_oaFigGroup_oaBlock||cref-oaCollection_oaFigGroup_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaFigGroup_oaBlock)\n"
"    Calls: (const oaCollection_oaFigGroup_oaBlock&)\n"
"    Signature: oaCollection_oaFigGroup_oaBlock||cref-oaCollection_oaFigGroup_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaFigGroup_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaFigGroup_oaBlock",
    sizeof(PyoaCollection_oaFigGroup_oaBlockObject),
    0,
    (destructor)oaCollection_oaFigGroup_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaFigGroup_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaFigGroup_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaFigGroup_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaFigGroup_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaFigGroup_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaFigGroup_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaFigGroup_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaFigGroup_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaFigGroup_oaBlock",
           (PyObject*)(&PyoaCollection_oaFigGroup_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaFigGroup_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaFrameInst_oaFrame
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrameInst_oaFrame_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaFrameInst_oaFrame_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaFrameInst_oaFrameObject* self = (PyoaCollection_oaFrameInst_oaFrameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaFrameInst_oaFrame)
    {
        PyParamoaCollection_oaFrameInst_oaFrame p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaFrameInst_oaFrame_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaFrameInst_oaFrame(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaFrameInst_oaFrame, Choices are:\n"
        "    (oaCollection_oaFrameInst_oaFrame)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaFrameInst_oaFrame_tp_dealloc(PyoaCollection_oaFrameInst_oaFrameObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaFrameInst_oaFrame*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrameInst_oaFrame_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaFrameInst_oaFrame value;
    int convert_status=PyoaCollection_oaFrameInst_oaFrame_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaFrameInst_oaFrame::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaFrameInst_oaFrame_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaFrameInst_oaFrame v1;
    PyParamoaCollection_oaFrameInst_oaFrame v2;
    int convert_status1=PyoaCollection_oaFrameInst_oaFrame_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaFrameInst_oaFrame_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaFrameInst_oaFrame_Convert(PyObject* ob,PyParamoaCollection_oaFrameInst_oaFrame* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaFrameInst_oaFrame_Check(ob)) {
        result->SetData( (oaCollection_oaFrameInst_oaFrame*) ((PyoaCollection_oaFrameInst_oaFrameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaFrameInst_oaFrame Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaFrameInst_oaFrame_FromoaCollection_oaFrameInst_oaFrame(oaCollection_oaFrameInst_oaFrame* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaFrameInst_oaFrame_Type.tp_alloc(&PyoaCollection_oaFrameInst_oaFrame_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaFrameInst_oaFrameObject* self = (PyoaCollection_oaFrameInst_oaFrameObject*)bself;
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
static char oaCollection_oaFrameInst_oaFrame_includes_doc[] = 
"Class: oaCollection_oaFrameInst_oaFrame, Function: includes\n"
"  Paramegers: (oaFrameInst)\n"
"    Calls: oaBoolean includes(const oaFrameInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFrameInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaFrameInst_oaFrame_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaFrameInst_oaFrame data;
    int convert_status=PyoaCollection_oaFrameInst_oaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaFrameInst_oaFrameObject* self=(PyoaCollection_oaFrameInst_oaFrameObject*)ob;

    PyParamoaFrameInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFrameInst_Convert,&p1)) {
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

static char oaCollection_oaFrameInst_oaFrame_assign_doc[] = 
"Class: oaCollection_oaFrameInst_oaFrame, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaFrameInst_oaFrame_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaFrameInst_oaFrame data;
  int convert_status=PyoaCollection_oaFrameInst_oaFrame_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaFrameInst_oaFrame p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaFrameInst_oaFrame_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaFrameInst_oaFrame_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaFrameInst_oaFrame_includes,METH_VARARGS,oaCollection_oaFrameInst_oaFrame_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaFrameInst_oaFrame_tp_assign,METH_VARARGS,oaCollection_oaFrameInst_oaFrame_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaFrameInst_oaFrame_doc[] = 
"Class: oaCollection_oaFrameInst_oaFrame\n"
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
"  Paramegers: (oaCollection_oaFrameInst_oaFrame)\n"
"    Calls: oaCollection_oaFrameInst_oaFrame(const oaCollection_oaFrameInst_oaFrame& coll)\n"
"    Signature: oaCollection_oaFrameInst_oaFrame||cref-oaCollection_oaFrameInst_oaFrame,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaFrameInst_oaFrame)\n"
"    Calls: (const oaCollection_oaFrameInst_oaFrame&)\n"
"    Signature: oaCollection_oaFrameInst_oaFrame||cref-oaCollection_oaFrameInst_oaFrame,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaFrameInst_oaFrame_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaFrameInst_oaFrame",
    sizeof(PyoaCollection_oaFrameInst_oaFrameObject),
    0,
    (destructor)oaCollection_oaFrameInst_oaFrame_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaFrameInst_oaFrame_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaFrameInst_oaFrame_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaFrameInst_oaFrame_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaFrameInst_oaFrame_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaFrameInst_oaFrame_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaFrameInst_oaFrame_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaFrameInst_oaFrame_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaFrameInst_oaFrame\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaFrameInst_oaFrame",
           (PyObject*)(&PyoaCollection_oaFrameInst_oaFrame_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaFrameInst_oaFrame\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaFrameInst_oaReticle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrameInst_oaReticle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaFrameInst_oaReticle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaFrameInst_oaReticleObject* self = (PyoaCollection_oaFrameInst_oaReticleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaFrameInst_oaReticle)
    {
        PyParamoaCollection_oaFrameInst_oaReticle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaFrameInst_oaReticle_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaFrameInst_oaReticle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaFrameInst_oaReticle, Choices are:\n"
        "    (oaCollection_oaFrameInst_oaReticle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaFrameInst_oaReticle_tp_dealloc(PyoaCollection_oaFrameInst_oaReticleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaFrameInst_oaReticle*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrameInst_oaReticle_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaFrameInst_oaReticle value;
    int convert_status=PyoaCollection_oaFrameInst_oaReticle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaFrameInst_oaReticle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaFrameInst_oaReticle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaFrameInst_oaReticle v1;
    PyParamoaCollection_oaFrameInst_oaReticle v2;
    int convert_status1=PyoaCollection_oaFrameInst_oaReticle_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaFrameInst_oaReticle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaFrameInst_oaReticle_Convert(PyObject* ob,PyParamoaCollection_oaFrameInst_oaReticle* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaFrameInst_oaReticle_Check(ob)) {
        result->SetData( (oaCollection_oaFrameInst_oaReticle*) ((PyoaCollection_oaFrameInst_oaReticleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaFrameInst_oaReticle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaFrameInst_oaReticle_FromoaCollection_oaFrameInst_oaReticle(oaCollection_oaFrameInst_oaReticle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaFrameInst_oaReticle_Type.tp_alloc(&PyoaCollection_oaFrameInst_oaReticle_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaFrameInst_oaReticleObject* self = (PyoaCollection_oaFrameInst_oaReticleObject*)bself;
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
static char oaCollection_oaFrameInst_oaReticle_includes_doc[] = 
"Class: oaCollection_oaFrameInst_oaReticle, Function: includes\n"
"  Paramegers: (oaFrameInst)\n"
"    Calls: oaBoolean includes(const oaFrameInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFrameInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaFrameInst_oaReticle_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaFrameInst_oaReticle data;
    int convert_status=PyoaCollection_oaFrameInst_oaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaFrameInst_oaReticleObject* self=(PyoaCollection_oaFrameInst_oaReticleObject*)ob;

    PyParamoaFrameInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFrameInst_Convert,&p1)) {
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

static char oaCollection_oaFrameInst_oaReticle_assign_doc[] = 
"Class: oaCollection_oaFrameInst_oaReticle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaFrameInst_oaReticle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaFrameInst_oaReticle data;
  int convert_status=PyoaCollection_oaFrameInst_oaReticle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaFrameInst_oaReticle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaFrameInst_oaReticle_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaFrameInst_oaReticle_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaFrameInst_oaReticle_includes,METH_VARARGS,oaCollection_oaFrameInst_oaReticle_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaFrameInst_oaReticle_tp_assign,METH_VARARGS,oaCollection_oaFrameInst_oaReticle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaFrameInst_oaReticle_doc[] = 
"Class: oaCollection_oaFrameInst_oaReticle\n"
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
"  Paramegers: (oaCollection_oaFrameInst_oaReticle)\n"
"    Calls: oaCollection_oaFrameInst_oaReticle(const oaCollection_oaFrameInst_oaReticle& coll)\n"
"    Signature: oaCollection_oaFrameInst_oaReticle||cref-oaCollection_oaFrameInst_oaReticle,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaFrameInst_oaReticle)\n"
"    Calls: (const oaCollection_oaFrameInst_oaReticle&)\n"
"    Signature: oaCollection_oaFrameInst_oaReticle||cref-oaCollection_oaFrameInst_oaReticle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaFrameInst_oaReticle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaFrameInst_oaReticle",
    sizeof(PyoaCollection_oaFrameInst_oaReticleObject),
    0,
    (destructor)oaCollection_oaFrameInst_oaReticle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaFrameInst_oaReticle_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaFrameInst_oaReticle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaFrameInst_oaReticle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaFrameInst_oaReticle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaFrameInst_oaReticle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaFrameInst_oaReticle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaFrameInst_oaReticle_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaFrameInst_oaReticle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaFrameInst_oaReticle",
           (PyObject*)(&PyoaCollection_oaFrameInst_oaReticle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaFrameInst_oaReticle\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaFrame_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrame_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaFrame_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaFrame_oaWaferObject* self = (PyoaCollection_oaFrame_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaFrame_oaWafer)
    {
        PyParamoaCollection_oaFrame_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaFrame_oaWafer_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaFrame_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaFrame_oaWafer, Choices are:\n"
        "    (oaCollection_oaFrame_oaWafer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaFrame_oaWafer_tp_dealloc(PyoaCollection_oaFrame_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaFrame_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaFrame_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaFrame_oaWafer value;
    int convert_status=PyoaCollection_oaFrame_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaFrame_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaFrame_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaFrame_oaWafer v1;
    PyParamoaCollection_oaFrame_oaWafer v2;
    int convert_status1=PyoaCollection_oaFrame_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaFrame_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaFrame_oaWafer_Convert(PyObject* ob,PyParamoaCollection_oaFrame_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaFrame_oaWafer_Check(ob)) {
        result->SetData( (oaCollection_oaFrame_oaWafer*) ((PyoaCollection_oaFrame_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaFrame_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaFrame_oaWafer_FromoaCollection_oaFrame_oaWafer(oaCollection_oaFrame_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaFrame_oaWafer_Type.tp_alloc(&PyoaCollection_oaFrame_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaFrame_oaWaferObject* self = (PyoaCollection_oaFrame_oaWaferObject*)bself;
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
static char oaCollection_oaFrame_oaWafer_includes_doc[] = 
"Class: oaCollection_oaFrame_oaWafer, Function: includes\n"
"  Paramegers: (oaFrame)\n"
"    Calls: oaBoolean includes(const oaFrame* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFrame,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaFrame_oaWafer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaFrame_oaWafer data;
    int convert_status=PyoaCollection_oaFrame_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaFrame_oaWaferObject* self=(PyoaCollection_oaFrame_oaWaferObject*)ob;

    PyParamoaFrame p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFrame_Convert,&p1)) {
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

static char oaCollection_oaFrame_oaWafer_assign_doc[] = 
"Class: oaCollection_oaFrame_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaFrame_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaFrame_oaWafer data;
  int convert_status=PyoaCollection_oaFrame_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaFrame_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaFrame_oaWafer_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaFrame_oaWafer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaFrame_oaWafer_includes,METH_VARARGS,oaCollection_oaFrame_oaWafer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaFrame_oaWafer_tp_assign,METH_VARARGS,oaCollection_oaFrame_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaFrame_oaWafer_doc[] = 
"Class: oaCollection_oaFrame_oaWafer\n"
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
"  Paramegers: (oaCollection_oaFrame_oaWafer)\n"
"    Calls: oaCollection_oaFrame_oaWafer(const oaCollection_oaFrame_oaWafer& coll)\n"
"    Signature: oaCollection_oaFrame_oaWafer||cref-oaCollection_oaFrame_oaWafer,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaFrame_oaWafer)\n"
"    Calls: (const oaCollection_oaFrame_oaWafer&)\n"
"    Signature: oaCollection_oaFrame_oaWafer||cref-oaCollection_oaFrame_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaFrame_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaFrame_oaWafer",
    sizeof(PyoaCollection_oaFrame_oaWaferObject),
    0,
    (destructor)oaCollection_oaFrame_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaFrame_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaFrame_oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaFrame_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaFrame_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaFrame_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaFrame_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaFrame_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaFrame_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaFrame_oaWafer",
           (PyObject*)(&PyoaCollection_oaFrame_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaFrame_oaWafer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGCellPattern_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGCellPattern_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGCellPattern_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGCellPattern_oaBlockObject* self = (PyoaCollection_oaGCellPattern_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGCellPattern_oaBlock)
    {
        PyParamoaCollection_oaGCellPattern_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGCellPattern_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaGCellPattern_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGCellPattern_oaBlock, Choices are:\n"
        "    (oaCollection_oaGCellPattern_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGCellPattern_oaBlock_tp_dealloc(PyoaCollection_oaGCellPattern_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGCellPattern_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGCellPattern_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGCellPattern_oaBlock value;
    int convert_status=PyoaCollection_oaGCellPattern_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaGCellPattern_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGCellPattern_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGCellPattern_oaBlock v1;
    PyParamoaCollection_oaGCellPattern_oaBlock v2;
    int convert_status1=PyoaCollection_oaGCellPattern_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGCellPattern_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGCellPattern_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaGCellPattern_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGCellPattern_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaGCellPattern_oaBlock*) ((PyoaCollection_oaGCellPattern_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGCellPattern_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGCellPattern_oaBlock_FromoaCollection_oaGCellPattern_oaBlock(oaCollection_oaGCellPattern_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGCellPattern_oaBlock_Type.tp_alloc(&PyoaCollection_oaGCellPattern_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGCellPattern_oaBlockObject* self = (PyoaCollection_oaGCellPattern_oaBlockObject*)bself;
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
static char oaCollection_oaGCellPattern_oaBlock_includes_doc[] = 
"Class: oaCollection_oaGCellPattern_oaBlock, Function: includes\n"
"  Paramegers: (oaGCellPattern)\n"
"    Calls: oaBoolean includes(const oaGCellPattern* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGCellPattern,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaGCellPattern_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGCellPattern_oaBlock data;
    int convert_status=PyoaCollection_oaGCellPattern_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGCellPattern_oaBlockObject* self=(PyoaCollection_oaGCellPattern_oaBlockObject*)ob;

    PyParamoaGCellPattern p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGCellPattern_Convert,&p1)) {
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

static char oaCollection_oaGCellPattern_oaBlock_assign_doc[] = 
"Class: oaCollection_oaGCellPattern_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGCellPattern_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGCellPattern_oaBlock data;
  int convert_status=PyoaCollection_oaGCellPattern_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGCellPattern_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGCellPattern_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGCellPattern_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaGCellPattern_oaBlock_includes,METH_VARARGS,oaCollection_oaGCellPattern_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaGCellPattern_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaGCellPattern_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGCellPattern_oaBlock_doc[] = 
"Class: oaCollection_oaGCellPattern_oaBlock\n"
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
"  Paramegers: (oaCollection_oaGCellPattern_oaBlock)\n"
"    Calls: oaCollection_oaGCellPattern_oaBlock(const oaCollection_oaGCellPattern_oaBlock& coll)\n"
"    Signature: oaCollection_oaGCellPattern_oaBlock||cref-oaCollection_oaGCellPattern_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaGCellPattern_oaBlock)\n"
"    Calls: (const oaCollection_oaGCellPattern_oaBlock&)\n"
"    Signature: oaCollection_oaGCellPattern_oaBlock||cref-oaCollection_oaGCellPattern_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGCellPattern_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGCellPattern_oaBlock",
    sizeof(PyoaCollection_oaGCellPattern_oaBlockObject),
    0,
    (destructor)oaCollection_oaGCellPattern_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGCellPattern_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGCellPattern_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGCellPattern_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGCellPattern_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGCellPattern_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGCellPattern_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGCellPattern_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGCellPattern_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGCellPattern_oaBlock",
           (PyObject*)(&PyoaCollection_oaGCellPattern_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGCellPattern_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroupMember_oaGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroupMember_oaGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroupMember_oaGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroupMember_oaGroupObject* self = (PyoaCollection_oaGroupMember_oaGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroupMember_oaGroup)
    {
        PyParamoaCollection_oaGroupMember_oaGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroupMember_oaGroup_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaGroupMember_oaGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroupMember_oaGroup, Choices are:\n"
        "    (oaCollection_oaGroupMember_oaGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroupMember_oaGroup_tp_dealloc(PyoaCollection_oaGroupMember_oaGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGroupMember_oaGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroupMember_oaGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroupMember_oaGroup value;
    int convert_status=PyoaCollection_oaGroupMember_oaGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaGroupMember_oaGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroupMember_oaGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroupMember_oaGroup v1;
    PyParamoaCollection_oaGroupMember_oaGroup v2;
    int convert_status1=PyoaCollection_oaGroupMember_oaGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroupMember_oaGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroupMember_oaGroup_Convert(PyObject* ob,PyParamoaCollection_oaGroupMember_oaGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroupMember_oaGroup_Check(ob)) {
        result->SetData( (oaCollection_oaGroupMember_oaGroup*) ((PyoaCollection_oaGroupMember_oaGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroupMember_oaGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroupMember_oaGroup_FromoaCollection_oaGroupMember_oaGroup(oaCollection_oaGroupMember_oaGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroupMember_oaGroup_Type.tp_alloc(&PyoaCollection_oaGroupMember_oaGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroupMember_oaGroupObject* self = (PyoaCollection_oaGroupMember_oaGroupObject*)bself;
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
static char oaCollection_oaGroupMember_oaGroup_includes_doc[] = 
"Class: oaCollection_oaGroupMember_oaGroup, Function: includes\n"
"  Paramegers: (oaGroupMember)\n"
"    Calls: oaBoolean includes(const oaGroupMember* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGroupMember,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaGroupMember_oaGroup_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroupMember_oaGroup data;
    int convert_status=PyoaCollection_oaGroupMember_oaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroupMember_oaGroupObject* self=(PyoaCollection_oaGroupMember_oaGroupObject*)ob;

    PyParamoaGroupMember p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroupMember_Convert,&p1)) {
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

static char oaCollection_oaGroupMember_oaGroup_assign_doc[] = 
"Class: oaCollection_oaGroupMember_oaGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGroupMember_oaGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGroupMember_oaGroup data;
  int convert_status=PyoaCollection_oaGroupMember_oaGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGroupMember_oaGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGroupMember_oaGroup_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGroupMember_oaGroup_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaGroupMember_oaGroup_includes,METH_VARARGS,oaCollection_oaGroupMember_oaGroup_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaGroupMember_oaGroup_tp_assign,METH_VARARGS,oaCollection_oaGroupMember_oaGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGroupMember_oaGroup_doc[] = 
"Class: oaCollection_oaGroupMember_oaGroup\n"
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
"  Paramegers: (oaCollection_oaGroupMember_oaGroup)\n"
"    Calls: oaCollection_oaGroupMember_oaGroup(const oaCollection_oaGroupMember_oaGroup& coll)\n"
"    Signature: oaCollection_oaGroupMember_oaGroup||cref-oaCollection_oaGroupMember_oaGroup,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaGroupMember_oaGroup)\n"
"    Calls: (const oaCollection_oaGroupMember_oaGroup&)\n"
"    Signature: oaCollection_oaGroupMember_oaGroup||cref-oaCollection_oaGroupMember_oaGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroupMember_oaGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroupMember_oaGroup",
    sizeof(PyoaCollection_oaGroupMember_oaGroupObject),
    0,
    (destructor)oaCollection_oaGroupMember_oaGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroupMember_oaGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroupMember_oaGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroupMember_oaGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGroupMember_oaGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroupMember_oaGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroupMember_oaGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroupMember_oaGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroupMember_oaGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroupMember_oaGroup",
           (PyObject*)(&PyoaCollection_oaGroupMember_oaGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroupMember_oaGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroupMember_oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroupMember_oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroupMember_oaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroupMember_oaObjectObject* self = (PyoaCollection_oaGroupMember_oaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroupMember_oaObject)
    {
        PyParamoaCollection_oaGroupMember_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroupMember_oaObject_Convert,&p1)) {
            self->value =  new oaCollection_oaGroupMember_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroupMember_oaObject, Choices are:\n"
        "    (oaCollection_oaGroupMember_oaObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroupMember_oaObject_tp_dealloc(PyoaCollection_oaGroupMember_oaObjectObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroupMember_oaObject_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroupMember_oaObject value;
    int convert_status=PyoaCollection_oaGroupMember_oaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaGroupMember_oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroupMember_oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroupMember_oaObject v1;
    PyParamoaCollection_oaGroupMember_oaObject v2;
    int convert_status1=PyoaCollection_oaGroupMember_oaObject_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroupMember_oaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroupMember_oaObject_Convert(PyObject* ob,PyParamoaCollection_oaGroupMember_oaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroupMember_oaObject_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaGroupMember_oaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroupMember_oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroupMember_oaObject_FromoaCollection_oaGroupMember_oaObject(oaCollection_oaGroupMember_oaObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroupMember_oaObject_Type.tp_alloc(&PyoaCollection_oaGroupMember_oaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroupMember_oaObjectObject* self = (PyoaCollection_oaGroupMember_oaObjectObject*)bself;
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
static char oaCollection_oaGroupMember_oaObject_getCount_doc[] = 
"Class: oaCollection_oaGroupMember_oaObject, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaGroupMember_oaObject_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroupMember_oaObject data;
    int convert_status=PyoaCollection_oaGroupMember_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroupMember_oaObjectObject* self=(PyoaCollection_oaGroupMember_oaObjectObject*)ob;

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
static char oaCollection_oaGroupMember_oaObject_includes_doc[] = 
"Class: oaCollection_oaGroupMember_oaObject, Function: includes\n"
"  Paramegers: (oaGroupMember)\n"
"    Calls: oaBoolean includes(const oaGroupMember* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGroupMember,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaGroupMember_oaObject_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroupMember_oaObject data;
    int convert_status=PyoaCollection_oaGroupMember_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroupMember_oaObjectObject* self=(PyoaCollection_oaGroupMember_oaObjectObject*)ob;

    PyParamoaGroupMember p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroupMember_Convert,&p1)) {
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
static char oaCollection_oaGroupMember_oaObject_isEmpty_doc[] = 
"Class: oaCollection_oaGroupMember_oaObject, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaGroupMember_oaObject_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroupMember_oaObject data;
    int convert_status=PyoaCollection_oaGroupMember_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroupMember_oaObjectObject* self=(PyoaCollection_oaGroupMember_oaObjectObject*)ob;

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

static char oaCollection_oaGroupMember_oaObject_assign_doc[] = 
"Class: oaCollection_oaGroupMember_oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGroupMember_oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGroupMember_oaObject data;
  int convert_status=PyoaCollection_oaGroupMember_oaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGroupMember_oaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGroupMember_oaObject_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGroupMember_oaObject_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaGroupMember_oaObject_getCount,METH_VARARGS,oaCollection_oaGroupMember_oaObject_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaGroupMember_oaObject_includes,METH_VARARGS,oaCollection_oaGroupMember_oaObject_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaGroupMember_oaObject_isEmpty,METH_VARARGS,oaCollection_oaGroupMember_oaObject_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaGroupMember_oaObject_tp_assign,METH_VARARGS,oaCollection_oaGroupMember_oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGroupMember_oaObject_doc[] = 
"Class: oaCollection_oaGroupMember_oaObject\n"
"  Class type oaCollection_oaGroupMember_oaObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroupMember_oaObject)\n"
"    Calls: oaCollection_oaGroupMember_oaObject(const oaCollection_oaGroupMember_oaObject& c)\n"
"    Signature: oaCollection_oaGroupMember_oaObject||cref-oaCollection_oaGroupMember_oaObject,\n"
"    Constructor oaCollection_oaGroupMember_oaObject\n"
"  Paramegers: (oaCollection_oaGroupMember_oaObject)\n"
"    Calls: (const oaCollection_oaGroupMember_oaObject&)\n"
"    Signature: oaCollection_oaGroupMember_oaObject||cref-oaCollection_oaGroupMember_oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroupMember_oaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroupMember_oaObject",
    sizeof(PyoaCollection_oaGroupMember_oaObjectObject),
    0,
    (destructor)oaCollection_oaGroupMember_oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroupMember_oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroupMember_oaObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroupMember_oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGroupMember_oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroupMember_oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroupMember_oaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroupMember_oaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroupMember_oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroupMember_oaObject",
           (PyObject*)(&PyoaCollection_oaGroupMember_oaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroupMember_oaObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroup_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroup_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroup_oaDMDataObject* self = (PyoaCollection_oaGroup_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroup_oaDMData)
    {
        PyParamoaCollection_oaGroup_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaDMData_Convert,&p1)) {
            self->value = (oaGroupCollection*)  new oaCollection_oaGroup_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroup_oaDMData, Choices are:\n"
        "    (oaCollection_oaGroup_oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroup_oaDMData_tp_dealloc(PyoaCollection_oaGroup_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGroup_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroup_oaDMData value;
    int convert_status=PyoaCollection_oaGroup_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaGroup_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroup_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroup_oaDMData v1;
    PyParamoaCollection_oaGroup_oaDMData v2;
    int convert_status1=PyoaCollection_oaGroup_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroup_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroup_oaDMData_Convert(PyObject* ob,PyParamoaCollection_oaGroup_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroup_oaDMData_Check(ob)) {
        result->SetData( (oaCollection_oaGroup_oaDMData*) ((PyoaCollection_oaGroup_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroup_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroup_oaDMData_FromoaCollection_oaGroup_oaDMData(oaCollection_oaGroup_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroup_oaDMData_Type.tp_alloc(&PyoaCollection_oaGroup_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroup_oaDMDataObject* self = (PyoaCollection_oaGroup_oaDMDataObject*)bself;
        self->value = (oaGroupCollection*)  data;
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
static char oaCollection_oaGroup_oaDMData_doc[] = 
"Class: oaCollection_oaGroup_oaDMData\n"
"  Class type oaCollection_oaGroup_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroup_oaDMData)\n"
"    Calls: oaCollection_oaGroup_oaDMData(const oaCollection_oaGroup_oaDMData& col)\n"
"    Signature: oaCollection_oaGroup_oaDMData||cref-oaCollection_oaGroup_oaDMData,\n"
"    Constructor oaCollection_oaGroup_oaDMData\n"
"  Paramegers: (oaCollection_oaGroup_oaDMData)\n"
"    Calls: (const oaCollection_oaGroup_oaDMData&)\n"
"    Signature: oaCollection_oaGroup_oaDMData||cref-oaCollection_oaGroup_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroup_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroup_oaDMData",
    sizeof(PyoaCollection_oaGroup_oaDMDataObject),
    0,
    (destructor)oaCollection_oaGroup_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroup_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroup_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroup_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaGroupCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroup_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroup_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroup_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroup_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroup_oaDMData",
           (PyObject*)(&PyoaCollection_oaGroup_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroup_oaDMData\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroup_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroup_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroup_oaDesignObject* self = (PyoaCollection_oaGroup_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroup_oaDesign)
    {
        PyParamoaCollection_oaGroup_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaDesign_Convert,&p1)) {
            self->value = (oaGroupCollection*)  new oaCollection_oaGroup_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroup_oaDesign, Choices are:\n"
        "    (oaCollection_oaGroup_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroup_oaDesign_tp_dealloc(PyoaCollection_oaGroup_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGroup_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroup_oaDesign value;
    int convert_status=PyoaCollection_oaGroup_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaGroup_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroup_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroup_oaDesign v1;
    PyParamoaCollection_oaGroup_oaDesign v2;
    int convert_status1=PyoaCollection_oaGroup_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroup_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroup_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaGroup_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroup_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaGroup_oaDesign*) ((PyoaCollection_oaGroup_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroup_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroup_oaDesign_FromoaCollection_oaGroup_oaDesign(oaCollection_oaGroup_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroup_oaDesign_Type.tp_alloc(&PyoaCollection_oaGroup_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroup_oaDesignObject* self = (PyoaCollection_oaGroup_oaDesignObject*)bself;
        self->value = (oaGroupCollection*)  data;
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
static char oaCollection_oaGroup_oaDesign_doc[] = 
"Class: oaCollection_oaGroup_oaDesign\n"
"  Class type oaCollection_oaGroup_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroup_oaDesign)\n"
"    Calls: oaCollection_oaGroup_oaDesign(const oaCollection_oaGroup_oaDesign& c)\n"
"    Signature: oaCollection_oaGroup_oaDesign||cref-oaCollection_oaGroup_oaDesign,\n"
"    Constructor oaCollection_oaGroup_oaDesign\n"
"  Paramegers: (oaCollection_oaGroup_oaDesign)\n"
"    Calls: (const oaCollection_oaGroup_oaDesign&)\n"
"    Signature: oaCollection_oaGroup_oaDesign||cref-oaCollection_oaGroup_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroup_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroup_oaDesign",
    sizeof(PyoaCollection_oaGroup_oaDesignObject),
    0,
    (destructor)oaCollection_oaGroup_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroup_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroup_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroup_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaGroupCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroup_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroup_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroup_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroup_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroup_oaDesign",
           (PyObject*)(&PyoaCollection_oaGroup_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroup_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroup_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroup_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroup_oaLibObject* self = (PyoaCollection_oaGroup_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroup_oaLib)
    {
        PyParamoaCollection_oaGroup_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaLib_Convert,&p1)) {
            self->value = (oaGroupCollection*)  new oaCollection_oaGroup_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroup_oaLib, Choices are:\n"
        "    (oaCollection_oaGroup_oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroup_oaLib_tp_dealloc(PyoaCollection_oaGroup_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGroup_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroup_oaLib value;
    int convert_status=PyoaCollection_oaGroup_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaGroup_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroup_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroup_oaLib v1;
    PyParamoaCollection_oaGroup_oaLib v2;
    int convert_status1=PyoaCollection_oaGroup_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroup_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroup_oaLib_Convert(PyObject* ob,PyParamoaCollection_oaGroup_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroup_oaLib_Check(ob)) {
        result->SetData( (oaCollection_oaGroup_oaLib*) ((PyoaCollection_oaGroup_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroup_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroup_oaLib_FromoaCollection_oaGroup_oaLib(oaCollection_oaGroup_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroup_oaLib_Type.tp_alloc(&PyoaCollection_oaGroup_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroup_oaLibObject* self = (PyoaCollection_oaGroup_oaLibObject*)bself;
        self->value = (oaGroupCollection*)  data;
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
static char oaCollection_oaGroup_oaLib_doc[] = 
"Class: oaCollection_oaGroup_oaLib\n"
"  Class type oaCollection_oaGroup_oaLib\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroup_oaLib)\n"
"    Calls: oaCollection_oaGroup_oaLib(const oaCollection_oaGroup_oaLib& col)\n"
"    Signature: oaCollection_oaGroup_oaLib||cref-oaCollection_oaGroup_oaLib,\n"
"    Constructor oaCollection_oaGroup_oaLib\n"
"  Paramegers: (oaCollection_oaGroup_oaLib)\n"
"    Calls: (const oaCollection_oaGroup_oaLib&)\n"
"    Signature: oaCollection_oaGroup_oaLib||cref-oaCollection_oaGroup_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroup_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroup_oaLib",
    sizeof(PyoaCollection_oaGroup_oaLibObject),
    0,
    (destructor)oaCollection_oaGroup_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroup_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroup_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroup_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaGroupCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroup_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroup_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroup_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroup_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroup_oaLib",
           (PyObject*)(&PyoaCollection_oaGroup_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroup_oaLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroup_oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroup_oaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroup_oaObjectObject* self = (PyoaCollection_oaGroup_oaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroup_oaObject)
    {
        PyParamoaCollection_oaGroup_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaObject_Convert,&p1)) {
            self->value =  new oaCollection_oaGroup_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroup_oaObject, Choices are:\n"
        "    (oaCollection_oaGroup_oaObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroup_oaObject_tp_dealloc(PyoaCollection_oaGroup_oaObjectObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaObject_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroup_oaObject value;
    int convert_status=PyoaCollection_oaGroup_oaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaGroup_oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroup_oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroup_oaObject v1;
    PyParamoaCollection_oaGroup_oaObject v2;
    int convert_status1=PyoaCollection_oaGroup_oaObject_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroup_oaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroup_oaObject_Convert(PyObject* ob,PyParamoaCollection_oaGroup_oaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroup_oaObject_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaGroup_oaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroup_oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroup_oaObject_FromoaCollection_oaGroup_oaObject(oaCollection_oaGroup_oaObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroup_oaObject_Type.tp_alloc(&PyoaCollection_oaGroup_oaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroup_oaObjectObject* self = (PyoaCollection_oaGroup_oaObjectObject*)bself;
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
static char oaCollection_oaGroup_oaObject_getCount_doc[] = 
"Class: oaCollection_oaGroup_oaObject, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaGroup_oaObject_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroup_oaObject data;
    int convert_status=PyoaCollection_oaGroup_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroup_oaObjectObject* self=(PyoaCollection_oaGroup_oaObjectObject*)ob;

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
static char oaCollection_oaGroup_oaObject_includes_doc[] = 
"Class: oaCollection_oaGroup_oaObject, Function: includes\n"
"  Paramegers: (oaGroup)\n"
"    Calls: oaBoolean includes(const oaGroup* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGroup,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaGroup_oaObject_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroup_oaObject data;
    int convert_status=PyoaCollection_oaGroup_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroup_oaObjectObject* self=(PyoaCollection_oaGroup_oaObjectObject*)ob;

    PyParamoaGroup p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroup_Convert,&p1)) {
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
static char oaCollection_oaGroup_oaObject_isEmpty_doc[] = 
"Class: oaCollection_oaGroup_oaObject, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaGroup_oaObject_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGroup_oaObject data;
    int convert_status=PyoaCollection_oaGroup_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGroup_oaObjectObject* self=(PyoaCollection_oaGroup_oaObjectObject*)ob;

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

static char oaCollection_oaGroup_oaObject_assign_doc[] = 
"Class: oaCollection_oaGroup_oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGroup_oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGroup_oaObject data;
  int convert_status=PyoaCollection_oaGroup_oaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGroup_oaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGroup_oaObject_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGroup_oaObject_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaGroup_oaObject_getCount,METH_VARARGS,oaCollection_oaGroup_oaObject_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaGroup_oaObject_includes,METH_VARARGS,oaCollection_oaGroup_oaObject_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaGroup_oaObject_isEmpty,METH_VARARGS,oaCollection_oaGroup_oaObject_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaGroup_oaObject_tp_assign,METH_VARARGS,oaCollection_oaGroup_oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGroup_oaObject_doc[] = 
"Class: oaCollection_oaGroup_oaObject\n"
"  Class type oaCollection_oaGroup_oaObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroup_oaObject)\n"
"    Calls: oaCollection_oaGroup_oaObject(const oaCollection_oaGroup_oaObject& c)\n"
"    Signature: oaCollection_oaGroup_oaObject||cref-oaCollection_oaGroup_oaObject,\n"
"    Constructor oaCollection_oaGroup_oaObject\n"
"  Paramegers: (oaCollection_oaGroup_oaObject)\n"
"    Calls: (const oaCollection_oaGroup_oaObject&)\n"
"    Signature: oaCollection_oaGroup_oaObject||cref-oaCollection_oaGroup_oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroup_oaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroup_oaObject",
    sizeof(PyoaCollection_oaGroup_oaObjectObject),
    0,
    (destructor)oaCollection_oaGroup_oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroup_oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroup_oaObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroup_oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGroup_oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroup_oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroup_oaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroup_oaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroup_oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroup_oaObject",
           (PyObject*)(&PyoaCollection_oaGroup_oaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroup_oaObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGroup_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGroup_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGroup_oaTechObject* self = (PyoaCollection_oaGroup_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGroup_oaTech)
    {
        PyParamoaCollection_oaGroup_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGroup_oaTech_Convert,&p1)) {
            self->value = (oaGroupCollection*)  new oaCollection_oaGroup_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGroup_oaTech, Choices are:\n"
        "    (oaCollection_oaGroup_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGroup_oaTech_tp_dealloc(PyoaCollection_oaGroup_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGroup_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGroup_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGroup_oaTech value;
    int convert_status=PyoaCollection_oaGroup_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaGroup_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGroup_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGroup_oaTech v1;
    PyParamoaCollection_oaGroup_oaTech v2;
    int convert_status1=PyoaCollection_oaGroup_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGroup_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGroup_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaGroup_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGroup_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaGroup_oaTech*) ((PyoaCollection_oaGroup_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGroup_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGroup_oaTech_FromoaCollection_oaGroup_oaTech(oaCollection_oaGroup_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGroup_oaTech_Type.tp_alloc(&PyoaCollection_oaGroup_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGroup_oaTechObject* self = (PyoaCollection_oaGroup_oaTechObject*)bself;
        self->value = (oaGroupCollection*)  data;
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
static char oaCollection_oaGroup_oaTech_doc[] = 
"Class: oaCollection_oaGroup_oaTech\n"
"  Class type oaCollection_oaGroup_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaGroup_oaTech)\n"
"    Calls: oaCollection_oaGroup_oaTech(const oaCollection_oaGroup_oaTech& c)\n"
"    Signature: oaCollection_oaGroup_oaTech||cref-oaCollection_oaGroup_oaTech,\n"
"    Constructor oaCollection_oaGroup_oaTech\n"
"  Paramegers: (oaCollection_oaGroup_oaTech)\n"
"    Calls: (const oaCollection_oaGroup_oaTech&)\n"
"    Signature: oaCollection_oaGroup_oaTech||cref-oaCollection_oaGroup_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGroup_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGroup_oaTech",
    sizeof(PyoaCollection_oaGroup_oaTechObject),
    0,
    (destructor)oaCollection_oaGroup_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGroup_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGroup_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGroup_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaGroupCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGroup_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGroup_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGroup_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGroup_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGroup_oaTech",
           (PyObject*)(&PyoaCollection_oaGroup_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGroup_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGuide_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGuide_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGuide_oaBlockObject* self = (PyoaCollection_oaGuide_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGuide_oaBlock)
    {
        PyParamoaCollection_oaGuide_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGuide_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaGuide_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGuide_oaBlock, Choices are:\n"
        "    (oaCollection_oaGuide_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGuide_oaBlock_tp_dealloc(PyoaCollection_oaGuide_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGuide_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGuide_oaBlock value;
    int convert_status=PyoaCollection_oaGuide_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaGuide_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGuide_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGuide_oaBlock v1;
    PyParamoaCollection_oaGuide_oaBlock v2;
    int convert_status1=PyoaCollection_oaGuide_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGuide_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGuide_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaGuide_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGuide_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaGuide_oaBlock*) ((PyoaCollection_oaGuide_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGuide_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGuide_oaBlock_FromoaCollection_oaGuide_oaBlock(oaCollection_oaGuide_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGuide_oaBlock_Type.tp_alloc(&PyoaCollection_oaGuide_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGuide_oaBlockObject* self = (PyoaCollection_oaGuide_oaBlockObject*)bself;
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
static char oaCollection_oaGuide_oaBlock_includes_doc[] = 
"Class: oaCollection_oaGuide_oaBlock, Function: includes\n"
"  Paramegers: (oaGuide)\n"
"    Calls: oaBoolean includes(const oaGuide* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGuide,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaGuide_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGuide_oaBlock data;
    int convert_status=PyoaCollection_oaGuide_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGuide_oaBlockObject* self=(PyoaCollection_oaGuide_oaBlockObject*)ob;

    PyParamoaGuide p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGuide_Convert,&p1)) {
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

static char oaCollection_oaGuide_oaBlock_assign_doc[] = 
"Class: oaCollection_oaGuide_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGuide_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGuide_oaBlock data;
  int convert_status=PyoaCollection_oaGuide_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGuide_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGuide_oaBlock_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGuide_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaGuide_oaBlock_includes,METH_VARARGS,oaCollection_oaGuide_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaGuide_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaGuide_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGuide_oaBlock_doc[] = 
"Class: oaCollection_oaGuide_oaBlock\n"
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
"  Paramegers: (oaCollection_oaGuide_oaBlock)\n"
"    Calls: oaCollection_oaGuide_oaBlock(const oaCollection_oaGuide_oaBlock& coll)\n"
"    Signature: oaCollection_oaGuide_oaBlock||cref-oaCollection_oaGuide_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaGuide_oaBlock)\n"
"    Calls: (const oaCollection_oaGuide_oaBlock&)\n"
"    Signature: oaCollection_oaGuide_oaBlock||cref-oaCollection_oaGuide_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGuide_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGuide_oaBlock",
    sizeof(PyoaCollection_oaGuide_oaBlockObject),
    0,
    (destructor)oaCollection_oaGuide_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGuide_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGuide_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGuide_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGuide_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGuide_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGuide_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGuide_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGuide_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGuide_oaBlock",
           (PyObject*)(&PyoaCollection_oaGuide_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGuide_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGuide_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGuide_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGuide_oaLayerHeaderObject* self = (PyoaCollection_oaGuide_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGuide_oaLayerHeader)
    {
        PyParamoaCollection_oaGuide_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGuide_oaLayerHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaGuide_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGuide_oaLayerHeader, Choices are:\n"
        "    (oaCollection_oaGuide_oaLayerHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGuide_oaLayerHeader_tp_dealloc(PyoaCollection_oaGuide_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGuide_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGuide_oaLayerHeader value;
    int convert_status=PyoaCollection_oaGuide_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaGuide_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGuide_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGuide_oaLayerHeader v1;
    PyParamoaCollection_oaGuide_oaLayerHeader v2;
    int convert_status1=PyoaCollection_oaGuide_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGuide_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGuide_oaLayerHeader_Convert(PyObject* ob,PyParamoaCollection_oaGuide_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGuide_oaLayerHeader_Check(ob)) {
        result->SetData( (oaCollection_oaGuide_oaLayerHeader*) ((PyoaCollection_oaGuide_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGuide_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGuide_oaLayerHeader_FromoaCollection_oaGuide_oaLayerHeader(oaCollection_oaGuide_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGuide_oaLayerHeader_Type.tp_alloc(&PyoaCollection_oaGuide_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGuide_oaLayerHeaderObject* self = (PyoaCollection_oaGuide_oaLayerHeaderObject*)bself;
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
static char oaCollection_oaGuide_oaLayerHeader_includes_doc[] = 
"Class: oaCollection_oaGuide_oaLayerHeader, Function: includes\n"
"  Paramegers: (oaGuide)\n"
"    Calls: oaBoolean includes(const oaGuide* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGuide,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaGuide_oaLayerHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGuide_oaLayerHeader data;
    int convert_status=PyoaCollection_oaGuide_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGuide_oaLayerHeaderObject* self=(PyoaCollection_oaGuide_oaLayerHeaderObject*)ob;

    PyParamoaGuide p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGuide_Convert,&p1)) {
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

static char oaCollection_oaGuide_oaLayerHeader_assign_doc[] = 
"Class: oaCollection_oaGuide_oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGuide_oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGuide_oaLayerHeader data;
  int convert_status=PyoaCollection_oaGuide_oaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGuide_oaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGuide_oaLayerHeader_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGuide_oaLayerHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaGuide_oaLayerHeader_includes,METH_VARARGS,oaCollection_oaGuide_oaLayerHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaGuide_oaLayerHeader_tp_assign,METH_VARARGS,oaCollection_oaGuide_oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGuide_oaLayerHeader_doc[] = 
"Class: oaCollection_oaGuide_oaLayerHeader\n"
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
"  Paramegers: (oaCollection_oaGuide_oaLayerHeader)\n"
"    Calls: oaCollection_oaGuide_oaLayerHeader(const oaCollection_oaGuide_oaLayerHeader& coll)\n"
"    Signature: oaCollection_oaGuide_oaLayerHeader||cref-oaCollection_oaGuide_oaLayerHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaGuide_oaLayerHeader)\n"
"    Calls: (const oaCollection_oaGuide_oaLayerHeader&)\n"
"    Signature: oaCollection_oaGuide_oaLayerHeader||cref-oaCollection_oaGuide_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGuide_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGuide_oaLayerHeader",
    sizeof(PyoaCollection_oaGuide_oaLayerHeaderObject),
    0,
    (destructor)oaCollection_oaGuide_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGuide_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGuide_oaLayerHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGuide_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGuide_oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGuide_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGuide_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGuide_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGuide_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGuide_oaLayerHeader",
           (PyObject*)(&PyoaCollection_oaGuide_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGuide_oaLayerHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaGuide_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaGuide_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaGuide_oaNetObject* self = (PyoaCollection_oaGuide_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaGuide_oaNet)
    {
        PyParamoaCollection_oaGuide_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaGuide_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaGuide_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaGuide_oaNet, Choices are:\n"
        "    (oaCollection_oaGuide_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaGuide_oaNet_tp_dealloc(PyoaCollection_oaGuide_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaGuide_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaGuide_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaGuide_oaNet value;
    int convert_status=PyoaCollection_oaGuide_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaGuide_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaGuide_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaGuide_oaNet v1;
    PyParamoaCollection_oaGuide_oaNet v2;
    int convert_status1=PyoaCollection_oaGuide_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaGuide_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaGuide_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaGuide_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaGuide_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaGuide_oaNet*) ((PyoaCollection_oaGuide_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaGuide_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaGuide_oaNet_FromoaCollection_oaGuide_oaNet(oaCollection_oaGuide_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaGuide_oaNet_Type.tp_alloc(&PyoaCollection_oaGuide_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaGuide_oaNetObject* self = (PyoaCollection_oaGuide_oaNetObject*)bself;
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
static char oaCollection_oaGuide_oaNet_includes_doc[] = 
"Class: oaCollection_oaGuide_oaNet, Function: includes\n"
"  Paramegers: (oaGuide)\n"
"    Calls: oaBoolean includes(const oaGuide* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGuide,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaGuide_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaGuide_oaNet data;
    int convert_status=PyoaCollection_oaGuide_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaGuide_oaNetObject* self=(PyoaCollection_oaGuide_oaNetObject*)ob;

    PyParamoaGuide p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGuide_Convert,&p1)) {
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

static char oaCollection_oaGuide_oaNet_assign_doc[] = 
"Class: oaCollection_oaGuide_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaGuide_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaGuide_oaNet data;
  int convert_status=PyoaCollection_oaGuide_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaGuide_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaGuide_oaNet_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaGuide_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaGuide_oaNet_includes,METH_VARARGS,oaCollection_oaGuide_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaGuide_oaNet_tp_assign,METH_VARARGS,oaCollection_oaGuide_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaGuide_oaNet_doc[] = 
"Class: oaCollection_oaGuide_oaNet\n"
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
"  Paramegers: (oaCollection_oaGuide_oaNet)\n"
"    Calls: oaCollection_oaGuide_oaNet(const oaCollection_oaGuide_oaNet& coll)\n"
"    Signature: oaCollection_oaGuide_oaNet||cref-oaCollection_oaGuide_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaGuide_oaNet)\n"
"    Calls: (const oaCollection_oaGuide_oaNet&)\n"
"    Signature: oaCollection_oaGuide_oaNet||cref-oaCollection_oaGuide_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaGuide_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaGuide_oaNet",
    sizeof(PyoaCollection_oaGuide_oaNetObject),
    0,
    (destructor)oaCollection_oaGuide_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaGuide_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaGuide_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaGuide_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaGuide_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaGuide_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaGuide_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaGuide_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaGuide_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaGuide_oaNet",
           (PyObject*)(&PyoaCollection_oaGuide_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaGuide_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaImage_oaReticle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaReticle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaImage_oaReticle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaImage_oaReticleObject* self = (PyoaCollection_oaImage_oaReticleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaImage_oaReticle)
    {
        PyParamoaCollection_oaImage_oaReticle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaImage_oaReticle_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaImage_oaReticle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaImage_oaReticle, Choices are:\n"
        "    (oaCollection_oaImage_oaReticle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaImage_oaReticle_tp_dealloc(PyoaCollection_oaImage_oaReticleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaImage_oaReticle*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaReticle_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaImage_oaReticle value;
    int convert_status=PyoaCollection_oaImage_oaReticle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaImage_oaReticle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaImage_oaReticle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaImage_oaReticle v1;
    PyParamoaCollection_oaImage_oaReticle v2;
    int convert_status1=PyoaCollection_oaImage_oaReticle_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaImage_oaReticle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaImage_oaReticle_Convert(PyObject* ob,PyParamoaCollection_oaImage_oaReticle* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaImage_oaReticle_Check(ob)) {
        result->SetData( (oaCollection_oaImage_oaReticle*) ((PyoaCollection_oaImage_oaReticleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaImage_oaReticle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaImage_oaReticle_FromoaCollection_oaImage_oaReticle(oaCollection_oaImage_oaReticle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaImage_oaReticle_Type.tp_alloc(&PyoaCollection_oaImage_oaReticle_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaImage_oaReticleObject* self = (PyoaCollection_oaImage_oaReticleObject*)bself;
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
static char oaCollection_oaImage_oaReticle_includes_doc[] = 
"Class: oaCollection_oaImage_oaReticle, Function: includes\n"
"  Paramegers: (oaImage)\n"
"    Calls: oaBoolean includes(const oaImage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaImage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaImage_oaReticle_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaImage_oaReticle data;
    int convert_status=PyoaCollection_oaImage_oaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaImage_oaReticleObject* self=(PyoaCollection_oaImage_oaReticleObject*)ob;

    PyParamoaImage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaImage_Convert,&p1)) {
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

static char oaCollection_oaImage_oaReticle_assign_doc[] = 
"Class: oaCollection_oaImage_oaReticle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaImage_oaReticle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaImage_oaReticle data;
  int convert_status=PyoaCollection_oaImage_oaReticle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaImage_oaReticle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaImage_oaReticle_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaImage_oaReticle_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaImage_oaReticle_includes,METH_VARARGS,oaCollection_oaImage_oaReticle_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaImage_oaReticle_tp_assign,METH_VARARGS,oaCollection_oaImage_oaReticle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaImage_oaReticle_doc[] = 
"Class: oaCollection_oaImage_oaReticle\n"
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
"  Paramegers: (oaCollection_oaImage_oaReticle)\n"
"    Calls: oaCollection_oaImage_oaReticle(const oaCollection_oaImage_oaReticle& coll)\n"
"    Signature: oaCollection_oaImage_oaReticle||cref-oaCollection_oaImage_oaReticle,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaImage_oaReticle)\n"
"    Calls: (const oaCollection_oaImage_oaReticle&)\n"
"    Signature: oaCollection_oaImage_oaReticle||cref-oaCollection_oaImage_oaReticle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaImage_oaReticle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaImage_oaReticle",
    sizeof(PyoaCollection_oaImage_oaReticleObject),
    0,
    (destructor)oaCollection_oaImage_oaReticle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaImage_oaReticle_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaImage_oaReticle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaImage_oaReticle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaImage_oaReticle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaImage_oaReticle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaImage_oaReticle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaImage_oaReticle_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaImage_oaReticle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaImage_oaReticle",
           (PyObject*)(&PyoaCollection_oaImage_oaReticle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaImage_oaReticle\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaImage_oaReticleRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaReticleRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaImage_oaReticleRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaImage_oaReticleRefObject* self = (PyoaCollection_oaImage_oaReticleRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaImage_oaReticleRef)
    {
        PyParamoaCollection_oaImage_oaReticleRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaImage_oaReticleRef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaImage_oaReticleRef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaImage_oaReticleRef, Choices are:\n"
        "    (oaCollection_oaImage_oaReticleRef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaImage_oaReticleRef_tp_dealloc(PyoaCollection_oaImage_oaReticleRefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaImage_oaReticleRef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaReticleRef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaImage_oaReticleRef value;
    int convert_status=PyoaCollection_oaImage_oaReticleRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaImage_oaReticleRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaImage_oaReticleRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaImage_oaReticleRef v1;
    PyParamoaCollection_oaImage_oaReticleRef v2;
    int convert_status1=PyoaCollection_oaImage_oaReticleRef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaImage_oaReticleRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaImage_oaReticleRef_Convert(PyObject* ob,PyParamoaCollection_oaImage_oaReticleRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaImage_oaReticleRef_Check(ob)) {
        result->SetData( (oaCollection_oaImage_oaReticleRef*) ((PyoaCollection_oaImage_oaReticleRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaImage_oaReticleRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaImage_oaReticleRef_FromoaCollection_oaImage_oaReticleRef(oaCollection_oaImage_oaReticleRef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaImage_oaReticleRef_Type.tp_alloc(&PyoaCollection_oaImage_oaReticleRef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaImage_oaReticleRefObject* self = (PyoaCollection_oaImage_oaReticleRefObject*)bself;
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
static char oaCollection_oaImage_oaReticleRef_includes_doc[] = 
"Class: oaCollection_oaImage_oaReticleRef, Function: includes\n"
"  Paramegers: (oaImage)\n"
"    Calls: oaBoolean includes(const oaImage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaImage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaImage_oaReticleRef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaImage_oaReticleRef data;
    int convert_status=PyoaCollection_oaImage_oaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaImage_oaReticleRefObject* self=(PyoaCollection_oaImage_oaReticleRefObject*)ob;

    PyParamoaImage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaImage_Convert,&p1)) {
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

static char oaCollection_oaImage_oaReticleRef_assign_doc[] = 
"Class: oaCollection_oaImage_oaReticleRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaImage_oaReticleRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaImage_oaReticleRef data;
  int convert_status=PyoaCollection_oaImage_oaReticleRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaImage_oaReticleRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaImage_oaReticleRef_Convert,&p1)) {
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

static PyMethodDef oaCollection_oaImage_oaReticleRef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaImage_oaReticleRef_includes,METH_VARARGS,oaCollection_oaImage_oaReticleRef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaImage_oaReticleRef_tp_assign,METH_VARARGS,oaCollection_oaImage_oaReticleRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaImage_oaReticleRef_doc[] = 
"Class: oaCollection_oaImage_oaReticleRef\n"
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
"  Paramegers: (oaCollection_oaImage_oaReticleRef)\n"
"    Calls: oaCollection_oaImage_oaReticleRef(const oaCollection_oaImage_oaReticleRef& coll)\n"
"    Signature: oaCollection_oaImage_oaReticleRef||cref-oaCollection_oaImage_oaReticleRef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaImage_oaReticleRef)\n"
"    Calls: (const oaCollection_oaImage_oaReticleRef&)\n"
"    Signature: oaCollection_oaImage_oaReticleRef||cref-oaCollection_oaImage_oaReticleRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaImage_oaReticleRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaImage_oaReticleRef",
    sizeof(PyoaCollection_oaImage_oaReticleRefObject),
    0,
    (destructor)oaCollection_oaImage_oaReticleRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaImage_oaReticleRef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaImage_oaReticleRef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaImage_oaReticleRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaImage_oaReticleRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaImage_oaReticleRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaImage_oaReticleRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaImage_oaReticleRef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaImage_oaReticleRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaImage_oaReticleRef",
           (PyObject*)(&PyoaCollection_oaImage_oaReticleRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaImage_oaReticleRef\n");
       return -1;
    }
    return 0;
}

