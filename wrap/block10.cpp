
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaMutualInductor_oaInductor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMutualInductor_oaInductor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaMutualInductor_oaInductor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaMutualInductor_oaInductorObject* self = (PyoaCollection_oaMutualInductor_oaInductorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaMutualInductor_oaInductor)
    {
        PyParamoaCollection_oaMutualInductor_oaInductor p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaMutualInductor_oaInductor_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaMutualInductor_oaInductor(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaMutualInductor_oaInductor, Choices are:\n"
        "    (oaCollection_oaMutualInductor_oaInductor)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaMutualInductor_oaInductor_tp_dealloc(PyoaCollection_oaMutualInductor_oaInductorObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaMutualInductor_oaInductor*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMutualInductor_oaInductor_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaMutualInductor_oaInductor value;
    int convert_status=PyoaCollection_oaMutualInductor_oaInductor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaMutualInductor_oaInductor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaMutualInductor_oaInductor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaMutualInductor_oaInductor v1;
    PyParamoaCollection_oaMutualInductor_oaInductor v2;
    int convert_status1=PyoaCollection_oaMutualInductor_oaInductor_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaMutualInductor_oaInductor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaMutualInductor_oaInductor_Convert(PyObject* ob,PyParamoaCollection_oaMutualInductor_oaInductor* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaMutualInductor_oaInductor_Check(ob)) {
        result->SetData( (oaCollection_oaMutualInductor_oaInductor*) ((PyoaCollection_oaMutualInductor_oaInductorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaMutualInductor_oaInductor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaMutualInductor_oaInductor_FromoaCollection_oaMutualInductor_oaInductor(oaCollection_oaMutualInductor_oaInductor* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaMutualInductor_oaInductor_Type.tp_alloc(&PyoaCollection_oaMutualInductor_oaInductor_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaMutualInductor_oaInductorObject* self = (PyoaCollection_oaMutualInductor_oaInductorObject*)bself;
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
static char oaCollection_oaMutualInductor_oaInductor_includes_doc[] = 
"Class: oaCollection_oaMutualInductor_oaInductor, Function: includes\n"
"  Paramegers: (oaMutualInductor)\n"
"    Calls: oaBoolean includes(const oaMutualInductor* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaMutualInductor,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaMutualInductor_oaInductor_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaMutualInductor_oaInductor data;
    int convert_status=PyoaCollection_oaMutualInductor_oaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaMutualInductor_oaInductorObject* self=(PyoaCollection_oaMutualInductor_oaInductorObject*)ob;

    PyParamoaMutualInductor p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMutualInductor_Convert,&p1)) {
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

static char oaCollection_oaMutualInductor_oaInductor_assign_doc[] = 
"Class: oaCollection_oaMutualInductor_oaInductor, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaMutualInductor_oaInductor_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaMutualInductor_oaInductor data;
  int convert_status=PyoaCollection_oaMutualInductor_oaInductor_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaMutualInductor_oaInductor p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaMutualInductor_oaInductor_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaMutualInductor_oaInductor_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaMutualInductor_oaInductor_includes,METH_VARARGS,oaCollection_oaMutualInductor_oaInductor_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaMutualInductor_oaInductor_tp_assign,METH_VARARGS,oaCollection_oaMutualInductor_oaInductor_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaMutualInductor_oaInductor_doc[] = 
"Class: oaCollection_oaMutualInductor_oaInductor\n"
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
"  Paramegers: (oaCollection_oaMutualInductor_oaInductor)\n"
"    Calls: oaCollection_oaMutualInductor_oaInductor(const oaCollection_oaMutualInductor_oaInductor& coll)\n"
"    Signature: oaCollection_oaMutualInductor_oaInductor||cref-oaCollection_oaMutualInductor_oaInductor,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaMutualInductor_oaInductor)\n"
"    Calls: (const oaCollection_oaMutualInductor_oaInductor&)\n"
"    Signature: oaCollection_oaMutualInductor_oaInductor||cref-oaCollection_oaMutualInductor_oaInductor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaMutualInductor_oaInductor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaMutualInductor_oaInductor",
    sizeof(PyoaCollection_oaMutualInductor_oaInductorObject),
    0,
    (destructor)oaCollection_oaMutualInductor_oaInductor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaMutualInductor_oaInductor_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaMutualInductor_oaInductor_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaMutualInductor_oaInductor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaMutualInductor_oaInductor_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaMutualInductor_oaInductor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaMutualInductor_oaInductor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaMutualInductor_oaInductor_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaMutualInductor_oaInductor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaMutualInductor_oaInductor",
           (PyObject*)(&PyoaCollection_oaMutualInductor_oaInductor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaMutualInductor_oaInductor\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaNet_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNet_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaNet_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaNet_oaBlockObject* self = (PyoaCollection_oaNet_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaNet_oaBlock)
    {
        PyParamoaCollection_oaNet_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaNet_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaNet_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaNet_oaBlock, Choices are:\n"
        "    (oaCollection_oaNet_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaNet_oaBlock_tp_dealloc(PyoaCollection_oaNet_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaNet_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNet_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaNet_oaBlock value;
    int convert_status=PyoaCollection_oaNet_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaNet_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaNet_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaNet_oaBlock v1;
    PyParamoaCollection_oaNet_oaBlock v2;
    int convert_status1=PyoaCollection_oaNet_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaNet_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaNet_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaNet_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaNet_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaNet_oaBlock*) ((PyoaCollection_oaNet_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaNet_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaNet_oaBlock_FromoaCollection_oaNet_oaBlock(oaCollection_oaNet_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaNet_oaBlock_Type.tp_alloc(&PyoaCollection_oaNet_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaNet_oaBlockObject* self = (PyoaCollection_oaNet_oaBlockObject*)bself;
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
static char oaCollection_oaNet_oaBlock_includes_doc[] = 
"Class: oaCollection_oaNet_oaBlock, Function: includes\n"
"  Paramegers: (oaNet)\n"
"    Calls: oaBoolean includes(const oaNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaNet_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaNet_oaBlock data;
    int convert_status=PyoaCollection_oaNet_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaNet_oaBlockObject* self=(PyoaCollection_oaNet_oaBlockObject*)ob;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
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

static char oaCollection_oaNet_oaBlock_assign_doc[] = 
"Class: oaCollection_oaNet_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaNet_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaNet_oaBlock data;
  int convert_status=PyoaCollection_oaNet_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaNet_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaNet_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaNet_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaNet_oaBlock_includes,METH_VARARGS,oaCollection_oaNet_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaNet_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaNet_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaNet_oaBlock_doc[] = 
"Class: oaCollection_oaNet_oaBlock\n"
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
"  Paramegers: (oaCollection_oaNet_oaBlock)\n"
"    Calls: oaCollection_oaNet_oaBlock(const oaCollection_oaNet_oaBlock& coll)\n"
"    Signature: oaCollection_oaNet_oaBlock||cref-oaCollection_oaNet_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaNet_oaBlock)\n"
"    Calls: (const oaCollection_oaNet_oaBlock&)\n"
"    Signature: oaCollection_oaNet_oaBlock||cref-oaCollection_oaNet_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaNet_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaNet_oaBlock",
    sizeof(PyoaCollection_oaNet_oaBlockObject),
    0,
    (destructor)oaCollection_oaNet_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaNet_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaNet_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaNet_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaNet_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaNet_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaNet_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaNet_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaNet_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaNet_oaBlock",
           (PyObject*)(&PyoaCollection_oaNet_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaNet_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaNet_oaBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNet_oaBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaNet_oaBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaNet_oaBundleNetObject* self = (PyoaCollection_oaNet_oaBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaNet_oaBundleNet)
    {
        PyParamoaCollection_oaNet_oaBundleNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaNet_oaBundleNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaNet_oaBundleNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaNet_oaBundleNet, Choices are:\n"
        "    (oaCollection_oaNet_oaBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaNet_oaBundleNet_tp_dealloc(PyoaCollection_oaNet_oaBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaNet_oaBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNet_oaBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaNet_oaBundleNet value;
    int convert_status=PyoaCollection_oaNet_oaBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaNet_oaBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaNet_oaBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaNet_oaBundleNet v1;
    PyParamoaCollection_oaNet_oaBundleNet v2;
    int convert_status1=PyoaCollection_oaNet_oaBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaNet_oaBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaNet_oaBundleNet_Convert(PyObject* ob,PyParamoaCollection_oaNet_oaBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaNet_oaBundleNet_Check(ob)) {
        result->SetData( (oaCollection_oaNet_oaBundleNet*) ((PyoaCollection_oaNet_oaBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaNet_oaBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaNet_oaBundleNet_FromoaCollection_oaNet_oaBundleNet(oaCollection_oaNet_oaBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaNet_oaBundleNet_Type.tp_alloc(&PyoaCollection_oaNet_oaBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaNet_oaBundleNetObject* self = (PyoaCollection_oaNet_oaBundleNetObject*)bself;
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
static char oaCollection_oaNet_oaBundleNet_includes_doc[] = 
"Class: oaCollection_oaNet_oaBundleNet, Function: includes\n"
"  Paramegers: (oaNet)\n"
"    Calls: oaBoolean includes(const oaNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaNet_oaBundleNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaNet_oaBundleNet data;
    int convert_status=PyoaCollection_oaNet_oaBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaNet_oaBundleNetObject* self=(PyoaCollection_oaNet_oaBundleNetObject*)ob;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
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

static char oaCollection_oaNet_oaBundleNet_assign_doc[] = 
"Class: oaCollection_oaNet_oaBundleNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaNet_oaBundleNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaNet_oaBundleNet data;
  int convert_status=PyoaCollection_oaNet_oaBundleNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaNet_oaBundleNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaNet_oaBundleNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaNet_oaBundleNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaNet_oaBundleNet_includes,METH_VARARGS,oaCollection_oaNet_oaBundleNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaNet_oaBundleNet_tp_assign,METH_VARARGS,oaCollection_oaNet_oaBundleNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaNet_oaBundleNet_doc[] = 
"Class: oaCollection_oaNet_oaBundleNet\n"
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
"  Paramegers: (oaCollection_oaNet_oaBundleNet)\n"
"    Calls: oaCollection_oaNet_oaBundleNet(const oaCollection_oaNet_oaBundleNet& coll)\n"
"    Signature: oaCollection_oaNet_oaBundleNet||cref-oaCollection_oaNet_oaBundleNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaNet_oaBundleNet)\n"
"    Calls: (const oaCollection_oaNet_oaBundleNet&)\n"
"    Signature: oaCollection_oaNet_oaBundleNet||cref-oaCollection_oaNet_oaBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaNet_oaBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaNet_oaBundleNet",
    sizeof(PyoaCollection_oaNet_oaBundleNetObject),
    0,
    (destructor)oaCollection_oaNet_oaBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaNet_oaBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaNet_oaBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaNet_oaBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaNet_oaBundleNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaNet_oaBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaNet_oaBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaNet_oaBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaNet_oaBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaNet_oaBundleNet",
           (PyObject*)(&PyoaCollection_oaNet_oaBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaNet_oaBundleNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaNode_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaNode_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaNode_oaParasiticNetworkObject* self = (PyoaCollection_oaNode_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaNode_oaParasiticNetwork)
    {
        PyParamoaCollection_oaNode_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaNode_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaNode_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaNode_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaNode_oaParasiticNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaNode_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaNode_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaNode_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaNode_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaNode_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaNode_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaNode_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaNode_oaParasiticNetwork v1;
    PyParamoaCollection_oaNode_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaNode_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaNode_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaNode_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaNode_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaNode_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaNode_oaParasiticNetwork*) ((PyoaCollection_oaNode_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaNode_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaNode_oaParasiticNetwork_FromoaCollection_oaNode_oaParasiticNetwork(oaCollection_oaNode_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaNode_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaNode_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaNode_oaParasiticNetworkObject* self = (PyoaCollection_oaNode_oaParasiticNetworkObject*)bself;
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
static char oaCollection_oaNode_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaNode_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaBoolean includes(const oaNode* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNode,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaNode_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaNode_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaNode_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaNode_oaParasiticNetworkObject* self=(PyoaCollection_oaNode_oaParasiticNetworkObject*)ob;

    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNode_Convert,&p1)) {
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

static char oaCollection_oaNode_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaNode_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaNode_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaNode_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaNode_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaNode_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaNode_oaParasiticNetwork_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaNode_oaParasiticNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaNode_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaNode_oaParasiticNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaNode_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaNode_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaNode_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaNode_oaParasiticNetwork\n"
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
"  Paramegers: (oaCollection_oaNode_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaNode_oaParasiticNetwork(const oaCollection_oaNode_oaParasiticNetwork& coll)\n"
"    Signature: oaCollection_oaNode_oaParasiticNetwork||cref-oaCollection_oaNode_oaParasiticNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaNode_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaNode_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaNode_oaParasiticNetwork||cref-oaCollection_oaNode_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaNode_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaNode_oaParasiticNetwork",
    sizeof(PyoaCollection_oaNode_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaNode_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaNode_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaNode_oaParasiticNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaNode_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaNode_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaNode_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaNode_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaNode_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaNode_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaNode_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaNode_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaNode_oaParasiticNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaNode_oaStdDevice
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaStdDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaNode_oaStdDevice_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaNode_oaStdDeviceObject* self = (PyoaCollection_oaNode_oaStdDeviceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaNode_oaStdDevice)
    {
        PyParamoaCollection_oaNode_oaStdDevice p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaNode_oaStdDevice_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaNode_oaStdDevice(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaNode_oaStdDevice, Choices are:\n"
        "    (oaCollection_oaNode_oaStdDevice)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaNode_oaStdDevice_tp_dealloc(PyoaCollection_oaNode_oaStdDeviceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaNode_oaStdDevice*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaStdDevice_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaNode_oaStdDevice value;
    int convert_status=PyoaCollection_oaNode_oaStdDevice_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaNode_oaStdDevice::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaNode_oaStdDevice_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaNode_oaStdDevice v1;
    PyParamoaCollection_oaNode_oaStdDevice v2;
    int convert_status1=PyoaCollection_oaNode_oaStdDevice_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaNode_oaStdDevice_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaNode_oaStdDevice_Convert(PyObject* ob,PyParamoaCollection_oaNode_oaStdDevice* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaNode_oaStdDevice_Check(ob)) {
        result->SetData( (oaCollection_oaNode_oaStdDevice*) ((PyoaCollection_oaNode_oaStdDeviceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaNode_oaStdDevice Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaNode_oaStdDevice_FromoaCollection_oaNode_oaStdDevice(oaCollection_oaNode_oaStdDevice* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaNode_oaStdDevice_Type.tp_alloc(&PyoaCollection_oaNode_oaStdDevice_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaNode_oaStdDeviceObject* self = (PyoaCollection_oaNode_oaStdDeviceObject*)bself;
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
static char oaCollection_oaNode_oaStdDevice_includes_doc[] = 
"Class: oaCollection_oaNode_oaStdDevice, Function: includes\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaBoolean includes(const oaNode* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNode,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaNode_oaStdDevice_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaNode_oaStdDevice data;
    int convert_status=PyoaCollection_oaNode_oaStdDevice_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaNode_oaStdDeviceObject* self=(PyoaCollection_oaNode_oaStdDeviceObject*)ob;

    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNode_Convert,&p1)) {
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

static char oaCollection_oaNode_oaStdDevice_assign_doc[] = 
"Class: oaCollection_oaNode_oaStdDevice, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaNode_oaStdDevice_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaNode_oaStdDevice data;
  int convert_status=PyoaCollection_oaNode_oaStdDevice_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaNode_oaStdDevice p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaNode_oaStdDevice_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaNode_oaStdDevice_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaNode_oaStdDevice_includes,METH_VARARGS,oaCollection_oaNode_oaStdDevice_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaNode_oaStdDevice_tp_assign,METH_VARARGS,oaCollection_oaNode_oaStdDevice_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaNode_oaStdDevice_doc[] = 
"Class: oaCollection_oaNode_oaStdDevice\n"
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
"  Paramegers: (oaCollection_oaNode_oaStdDevice)\n"
"    Calls: oaCollection_oaNode_oaStdDevice(const oaCollection_oaNode_oaStdDevice& coll)\n"
"    Signature: oaCollection_oaNode_oaStdDevice||cref-oaCollection_oaNode_oaStdDevice,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaNode_oaStdDevice)\n"
"    Calls: (const oaCollection_oaNode_oaStdDevice&)\n"
"    Signature: oaCollection_oaNode_oaStdDevice||cref-oaCollection_oaNode_oaStdDevice,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaNode_oaStdDevice_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaNode_oaStdDevice",
    sizeof(PyoaCollection_oaNode_oaStdDeviceObject),
    0,
    (destructor)oaCollection_oaNode_oaStdDevice_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaNode_oaStdDevice_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaNode_oaStdDevice_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaNode_oaStdDevice_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaNode_oaStdDevice_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaNode_oaStdDevice_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaNode_oaStdDevice_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaNode_oaStdDevice_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaNode_oaStdDevice\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaNode_oaStdDevice",
           (PyObject*)(&PyoaCollection_oaNode_oaStdDevice_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaNode_oaStdDevice\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaNode_oaSubNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaSubNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaNode_oaSubNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaNode_oaSubNetworkObject* self = (PyoaCollection_oaNode_oaSubNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaNode_oaSubNetwork)
    {
        PyParamoaCollection_oaNode_oaSubNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaNode_oaSubNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaNode_oaSubNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaNode_oaSubNetwork, Choices are:\n"
        "    (oaCollection_oaNode_oaSubNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaNode_oaSubNetwork_tp_dealloc(PyoaCollection_oaNode_oaSubNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaNode_oaSubNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaNode_oaSubNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaNode_oaSubNetwork value;
    int convert_status=PyoaCollection_oaNode_oaSubNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaNode_oaSubNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaNode_oaSubNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaNode_oaSubNetwork v1;
    PyParamoaCollection_oaNode_oaSubNetwork v2;
    int convert_status1=PyoaCollection_oaNode_oaSubNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaNode_oaSubNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaNode_oaSubNetwork_Convert(PyObject* ob,PyParamoaCollection_oaNode_oaSubNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaNode_oaSubNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaNode_oaSubNetwork*) ((PyoaCollection_oaNode_oaSubNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaNode_oaSubNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaNode_oaSubNetwork_FromoaCollection_oaNode_oaSubNetwork(oaCollection_oaNode_oaSubNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaNode_oaSubNetwork_Type.tp_alloc(&PyoaCollection_oaNode_oaSubNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaNode_oaSubNetworkObject* self = (PyoaCollection_oaNode_oaSubNetworkObject*)bself;
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
static char oaCollection_oaNode_oaSubNetwork_includes_doc[] = 
"Class: oaCollection_oaNode_oaSubNetwork, Function: includes\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaBoolean includes(const oaNode* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNode,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaNode_oaSubNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaNode_oaSubNetwork data;
    int convert_status=PyoaCollection_oaNode_oaSubNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaNode_oaSubNetworkObject* self=(PyoaCollection_oaNode_oaSubNetworkObject*)ob;

    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNode_Convert,&p1)) {
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

static char oaCollection_oaNode_oaSubNetwork_assign_doc[] = 
"Class: oaCollection_oaNode_oaSubNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaNode_oaSubNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaNode_oaSubNetwork data;
  int convert_status=PyoaCollection_oaNode_oaSubNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaNode_oaSubNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaNode_oaSubNetwork_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaNode_oaSubNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaNode_oaSubNetwork_includes,METH_VARARGS,oaCollection_oaNode_oaSubNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaNode_oaSubNetwork_tp_assign,METH_VARARGS,oaCollection_oaNode_oaSubNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaNode_oaSubNetwork_doc[] = 
"Class: oaCollection_oaNode_oaSubNetwork\n"
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
"  Paramegers: (oaCollection_oaNode_oaSubNetwork)\n"
"    Calls: oaCollection_oaNode_oaSubNetwork(const oaCollection_oaNode_oaSubNetwork& coll)\n"
"    Signature: oaCollection_oaNode_oaSubNetwork||cref-oaCollection_oaNode_oaSubNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaNode_oaSubNetwork)\n"
"    Calls: (const oaCollection_oaNode_oaSubNetwork&)\n"
"    Signature: oaCollection_oaNode_oaSubNetwork||cref-oaCollection_oaNode_oaSubNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaNode_oaSubNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaNode_oaSubNetwork",
    sizeof(PyoaCollection_oaNode_oaSubNetworkObject),
    0,
    (destructor)oaCollection_oaNode_oaSubNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaNode_oaSubNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaNode_oaSubNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaNode_oaSubNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaNode_oaSubNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaNode_oaSubNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaNode_oaSubNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaNode_oaSubNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaNode_oaSubNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaNode_oaSubNetwork",
           (PyObject*)(&PyoaCollection_oaNode_oaSubNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaNode_oaSubNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccAssignment_oaOccInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccAssignment_oaOccInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccAssignment_oaOccInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccAssignment_oaOccInstObject* self = (PyoaCollection_oaOccAssignment_oaOccInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccAssignment_oaOccInst)
    {
        PyParamoaCollection_oaOccAssignment_oaOccInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccAssignment_oaOccInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccAssignment_oaOccInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccAssignment_oaOccInst, Choices are:\n"
        "    (oaCollection_oaOccAssignment_oaOccInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccAssignment_oaOccInst_tp_dealloc(PyoaCollection_oaOccAssignment_oaOccInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccAssignment_oaOccInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccAssignment_oaOccInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccAssignment_oaOccInst value;
    int convert_status=PyoaCollection_oaOccAssignment_oaOccInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaOccAssignment_oaOccInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccAssignment_oaOccInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccAssignment_oaOccInst v1;
    PyParamoaCollection_oaOccAssignment_oaOccInst v2;
    int convert_status1=PyoaCollection_oaOccAssignment_oaOccInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccAssignment_oaOccInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccAssignment_oaOccInst_Convert(PyObject* ob,PyParamoaCollection_oaOccAssignment_oaOccInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccAssignment_oaOccInst_Check(ob)) {
        result->SetData( (oaCollection_oaOccAssignment_oaOccInst*) ((PyoaCollection_oaOccAssignment_oaOccInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccAssignment_oaOccInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccAssignment_oaOccInst_FromoaCollection_oaOccAssignment_oaOccInst(oaCollection_oaOccAssignment_oaOccInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccAssignment_oaOccInst_Type.tp_alloc(&PyoaCollection_oaOccAssignment_oaOccInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccAssignment_oaOccInstObject* self = (PyoaCollection_oaOccAssignment_oaOccInstObject*)bself;
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
static char oaCollection_oaOccAssignment_oaOccInst_includes_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccInst, Function: includes\n"
"  Paramegers: (oaOccAssignment)\n"
"    Calls: oaBoolean includes(const oaOccAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccAssignment_oaOccInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccAssignment_oaOccInst data;
    int convert_status=PyoaCollection_oaOccAssignment_oaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccAssignment_oaOccInstObject* self=(PyoaCollection_oaOccAssignment_oaOccInstObject*)ob;

    PyParamoaOccAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccAssignment_Convert,&p1)) {
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

static char oaCollection_oaOccAssignment_oaOccInst_assign_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccAssignment_oaOccInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccAssignment_oaOccInst data;
  int convert_status=PyoaCollection_oaOccAssignment_oaOccInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccAssignment_oaOccInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccAssignment_oaOccInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccAssignment_oaOccInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccAssignment_oaOccInst_includes,METH_VARARGS,oaCollection_oaOccAssignment_oaOccInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccAssignment_oaOccInst_tp_assign,METH_VARARGS,oaCollection_oaOccAssignment_oaOccInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccAssignment_oaOccInst_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccInst\n"
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
"  Paramegers: (oaCollection_oaOccAssignment_oaOccInst)\n"
"    Calls: oaCollection_oaOccAssignment_oaOccInst(const oaCollection_oaOccAssignment_oaOccInst& coll)\n"
"    Signature: oaCollection_oaOccAssignment_oaOccInst||cref-oaCollection_oaOccAssignment_oaOccInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccAssignment_oaOccInst)\n"
"    Calls: (const oaCollection_oaOccAssignment_oaOccInst&)\n"
"    Signature: oaCollection_oaOccAssignment_oaOccInst||cref-oaCollection_oaOccAssignment_oaOccInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccAssignment_oaOccInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccAssignment_oaOccInst",
    sizeof(PyoaCollection_oaOccAssignment_oaOccInstObject),
    0,
    (destructor)oaCollection_oaOccAssignment_oaOccInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccAssignment_oaOccInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccAssignment_oaOccInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccAssignment_oaOccInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccAssignment_oaOccInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccAssignment_oaOccInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccAssignment_oaOccInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccAssignment_oaOccInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccAssignment_oaOccInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccAssignment_oaOccInst",
           (PyObject*)(&PyoaCollection_oaOccAssignment_oaOccInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccAssignment_oaOccInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccAssignment_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccAssignment_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccAssignment_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccAssignment_oaOccurrenceObject* self = (PyoaCollection_oaOccAssignment_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccAssignment_oaOccurrence)
    {
        PyParamoaCollection_oaOccAssignment_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccAssignment_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccAssignment_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccAssignment_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccAssignment_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccAssignment_oaOccurrence_tp_dealloc(PyoaCollection_oaOccAssignment_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccAssignment_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccAssignment_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccAssignment_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccAssignment_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaOccAssignment_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccAssignment_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccAssignment_oaOccurrence v1;
    PyParamoaCollection_oaOccAssignment_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccAssignment_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccAssignment_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccAssignment_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccAssignment_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccAssignment_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccAssignment_oaOccurrence*) ((PyoaCollection_oaOccAssignment_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccAssignment_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccAssignment_oaOccurrence_FromoaCollection_oaOccAssignment_oaOccurrence(oaCollection_oaOccAssignment_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccAssignment_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccAssignment_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccAssignment_oaOccurrenceObject* self = (PyoaCollection_oaOccAssignment_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccAssignment_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccAssignment)\n"
"    Calls: oaBoolean includes(const oaOccAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccAssignment_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccAssignment_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccAssignment_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccAssignment_oaOccurrenceObject* self=(PyoaCollection_oaOccAssignment_oaOccurrenceObject*)ob;

    PyParamoaOccAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccAssignment_Convert,&p1)) {
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

static char oaCollection_oaOccAssignment_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccAssignment_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccAssignment_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccAssignment_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccAssignment_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccAssignment_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccAssignment_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccAssignment_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccAssignment_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccAssignment_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccAssignment_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccAssignment_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccAssignment_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccAssignment_oaOccurrence)\n"
"    Calls: oaCollection_oaOccAssignment_oaOccurrence(const oaCollection_oaOccAssignment_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccAssignment_oaOccurrence||cref-oaCollection_oaOccAssignment_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccAssignment_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccAssignment_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccAssignment_oaOccurrence||cref-oaCollection_oaOccAssignment_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccAssignment_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccAssignment_oaOccurrence",
    sizeof(PyoaCollection_oaOccAssignment_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccAssignment_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccAssignment_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccAssignment_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccAssignment_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccAssignment_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccAssignment_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccAssignment_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccAssignment_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccAssignment_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccAssignment_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccAssignment_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccAssignment_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBitNet_oaOccBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBitNet_oaOccBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBitNet_oaOccBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBitNet_oaOccBitNetObject* self = (PyoaCollection_oaOccBitNet_oaOccBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBitNet_oaOccBitNet)
    {
        PyParamoaCollection_oaOccBitNet_oaOccBitNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBitNet_oaOccBitNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBitNet_oaOccBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBitNet_oaOccBitNet, Choices are:\n"
        "    (oaCollection_oaOccBitNet_oaOccBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBitNet_oaOccBitNet_tp_dealloc(PyoaCollection_oaOccBitNet_oaOccBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBitNet_oaOccBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBitNet_oaOccBitNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBitNet_oaOccBitNet value;
    int convert_status=PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaOccBitNet_oaOccBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBitNet_oaOccBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBitNet_oaOccBitNet v1;
    PyParamoaCollection_oaOccBitNet_oaOccBitNet v2;
    int convert_status1=PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(PyObject* ob,PyParamoaCollection_oaOccBitNet_oaOccBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBitNet_oaOccBitNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccBitNet_oaOccBitNet*) ((PyoaCollection_oaOccBitNet_oaOccBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBitNet_oaOccBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBitNet_oaOccBitNet_FromoaCollection_oaOccBitNet_oaOccBitNet(oaCollection_oaOccBitNet_oaOccBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBitNet_oaOccBitNet_Type.tp_alloc(&PyoaCollection_oaOccBitNet_oaOccBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBitNet_oaOccBitNetObject* self = (PyoaCollection_oaOccBitNet_oaOccBitNetObject*)bself;
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
static char oaCollection_oaOccBitNet_oaOccBitNet_includes_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccBitNet, Function: includes\n"
"  Paramegers: (oaOccBitNet)\n"
"    Calls: oaBoolean includes(const oaOccBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBitNet_oaOccBitNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBitNet_oaOccBitNet data;
    int convert_status=PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBitNet_oaOccBitNetObject* self=(PyoaCollection_oaOccBitNet_oaOccBitNetObject*)ob;

    PyParamoaOccBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBitNet_Convert,&p1)) {
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

static char oaCollection_oaOccBitNet_oaOccBitNet_assign_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBitNet_oaOccBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBitNet_oaOccBitNet data;
  int convert_status=PyoaCollection_oaOccBitNet_oaOccBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBitNet_oaOccBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBitNet_oaOccBitNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBitNet_oaOccBitNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBitNet_oaOccBitNet_includes,METH_VARARGS,oaCollection_oaOccBitNet_oaOccBitNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBitNet_oaOccBitNet_tp_assign,METH_VARARGS,oaCollection_oaOccBitNet_oaOccBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBitNet_oaOccBitNet_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccBitNet\n"
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
"  Paramegers: (oaCollection_oaOccBitNet_oaOccBitNet)\n"
"    Calls: oaCollection_oaOccBitNet_oaOccBitNet(const oaCollection_oaOccBitNet_oaOccBitNet& coll)\n"
"    Signature: oaCollection_oaOccBitNet_oaOccBitNet||cref-oaCollection_oaOccBitNet_oaOccBitNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBitNet_oaOccBitNet)\n"
"    Calls: (const oaCollection_oaOccBitNet_oaOccBitNet&)\n"
"    Signature: oaCollection_oaOccBitNet_oaOccBitNet||cref-oaCollection_oaOccBitNet_oaOccBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBitNet_oaOccBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBitNet_oaOccBitNet",
    sizeof(PyoaCollection_oaOccBitNet_oaOccBitNetObject),
    0,
    (destructor)oaCollection_oaOccBitNet_oaOccBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBitNet_oaOccBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBitNet_oaOccBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBitNet_oaOccBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBitNet_oaOccBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBitNet_oaOccBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBitNet_oaOccBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBitNet_oaOccBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBitNet_oaOccBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBitNet_oaOccBitNet",
           (PyObject*)(&PyoaCollection_oaOccBitNet_oaOccBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBitNet_oaOccBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBitNet_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBitNet_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBitNet_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBitNet_oaOccNetObject* self = (PyoaCollection_oaOccBitNet_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBitNet_oaOccNet)
    {
        PyParamoaCollection_oaOccBitNet_oaOccNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBitNet_oaOccNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBitNet_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBitNet_oaOccNet, Choices are:\n"
        "    (oaCollection_oaOccBitNet_oaOccNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBitNet_oaOccNet_tp_dealloc(PyoaCollection_oaOccBitNet_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBitNet_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBitNet_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBitNet_oaOccNet value;
    int convert_status=PyoaCollection_oaOccBitNet_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaOccBitNet_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBitNet_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBitNet_oaOccNet v1;
    PyParamoaCollection_oaOccBitNet_oaOccNet v2;
    int convert_status1=PyoaCollection_oaOccBitNet_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBitNet_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBitNet_oaOccNet_Convert(PyObject* ob,PyParamoaCollection_oaOccBitNet_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBitNet_oaOccNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccBitNet_oaOccNet*) ((PyoaCollection_oaOccBitNet_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBitNet_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBitNet_oaOccNet_FromoaCollection_oaOccBitNet_oaOccNet(oaCollection_oaOccBitNet_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBitNet_oaOccNet_Type.tp_alloc(&PyoaCollection_oaOccBitNet_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBitNet_oaOccNetObject* self = (PyoaCollection_oaOccBitNet_oaOccNetObject*)bself;
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
static char oaCollection_oaOccBitNet_oaOccNet_includes_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccNet, Function: includes\n"
"  Paramegers: (oaOccBitNet)\n"
"    Calls: oaBoolean includes(const oaOccBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBitNet_oaOccNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBitNet_oaOccNet data;
    int convert_status=PyoaCollection_oaOccBitNet_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBitNet_oaOccNetObject* self=(PyoaCollection_oaOccBitNet_oaOccNetObject*)ob;

    PyParamoaOccBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBitNet_Convert,&p1)) {
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

static char oaCollection_oaOccBitNet_oaOccNet_assign_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBitNet_oaOccNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBitNet_oaOccNet data;
  int convert_status=PyoaCollection_oaOccBitNet_oaOccNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBitNet_oaOccNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBitNet_oaOccNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBitNet_oaOccNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBitNet_oaOccNet_includes,METH_VARARGS,oaCollection_oaOccBitNet_oaOccNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBitNet_oaOccNet_tp_assign,METH_VARARGS,oaCollection_oaOccBitNet_oaOccNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBitNet_oaOccNet_doc[] = 
"Class: oaCollection_oaOccBitNet_oaOccNet\n"
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
"  Paramegers: (oaCollection_oaOccBitNet_oaOccNet)\n"
"    Calls: oaCollection_oaOccBitNet_oaOccNet(const oaCollection_oaOccBitNet_oaOccNet& coll)\n"
"    Signature: oaCollection_oaOccBitNet_oaOccNet||cref-oaCollection_oaOccBitNet_oaOccNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBitNet_oaOccNet)\n"
"    Calls: (const oaCollection_oaOccBitNet_oaOccNet&)\n"
"    Signature: oaCollection_oaOccBitNet_oaOccNet||cref-oaCollection_oaOccBitNet_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBitNet_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBitNet_oaOccNet",
    sizeof(PyoaCollection_oaOccBitNet_oaOccNetObject),
    0,
    (destructor)oaCollection_oaOccBitNet_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBitNet_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBitNet_oaOccNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBitNet_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBitNet_oaOccNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBitNet_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBitNet_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBitNet_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBitNet_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBitNet_oaOccNet",
           (PyObject*)(&PyoaCollection_oaOccBitNet_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBitNet_oaOccNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusNetBit_oaOccBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNetBit_oaOccBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject* self = (PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusNetBit_oaOccBusNetDef)
    {
        PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusNetBit_oaOccBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusNetBit_oaOccBusNetDef, Choices are:\n"
        "    (oaCollection_oaOccBusNetBit_oaOccBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_dealloc(PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusNetBit_oaOccBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef value;
    int convert_status=PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[64];
    sprintf(buffer,"<oaCollection_oaOccBusNetBit_oaOccBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef v1;
    PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef v2;
    int convert_status1=PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusNetBit_oaOccBusNetDef*) ((PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusNetBit_oaOccBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_FromoaCollection_oaOccBusNetBit_oaOccBusNetDef(oaCollection_oaOccBusNetBit_oaOccBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type.tp_alloc(&PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject* self = (PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject*)bself;
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
static char oaCollection_oaOccBusNetBit_oaOccBusNetDef_includes_doc[] = 
"Class: oaCollection_oaOccBusNetBit_oaOccBusNetDef, Function: includes\n"
"  Paramegers: (oaOccBusNetBit)\n"
"    Calls: oaBoolean includes(const oaOccBusNetBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusNetBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusNetBit_oaOccBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef data;
    int convert_status=PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject* self=(PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject*)ob;

    PyParamoaOccBusNetBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusNetBit_Convert,&p1)) {
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

static char oaCollection_oaOccBusNetBit_oaOccBusNetDef_assign_doc[] = 
"Class: oaCollection_oaOccBusNetBit_oaOccBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef data;
  int convert_status=PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusNetBit_oaOccBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusNetBit_oaOccBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusNetBit_oaOccBusNetDef_includes,METH_VARARGS,oaCollection_oaOccBusNetBit_oaOccBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaOccBusNetBit_oaOccBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusNetBit_oaOccBusNetDef_doc[] = 
"Class: oaCollection_oaOccBusNetBit_oaOccBusNetDef\n"
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
"  Paramegers: (oaCollection_oaOccBusNetBit_oaOccBusNetDef)\n"
"    Calls: oaCollection_oaOccBusNetBit_oaOccBusNetDef(const oaCollection_oaOccBusNetBit_oaOccBusNetDef& coll)\n"
"    Signature: oaCollection_oaOccBusNetBit_oaOccBusNetDef||cref-oaCollection_oaOccBusNetBit_oaOccBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusNetBit_oaOccBusNetDef)\n"
"    Calls: (const oaCollection_oaOccBusNetBit_oaOccBusNetDef&)\n"
"    Signature: oaCollection_oaOccBusNetBit_oaOccBusNetDef||cref-oaCollection_oaOccBusNetBit_oaOccBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusNetBit_oaOccBusNetDef",
    sizeof(PyoaCollection_oaOccBusNetBit_oaOccBusNetDefObject),
    0,
    (destructor)oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusNetBit_oaOccBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusNetBit_oaOccBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusNetBit_oaOccBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusNetBit_oaOccBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusNetBit_oaOccBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusNetBit_oaOccBusNetDef",
           (PyObject*)(&PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusNetBit_oaOccBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusNetDef_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNetDef_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusNetDef_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusNetDef_oaOccurrenceObject* self = (PyoaCollection_oaOccBusNetDef_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusNetDef_oaOccurrence)
    {
        PyParamoaCollection_oaOccBusNetDef_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusNetDef_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusNetDef_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccBusNetDef_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusNetDef_oaOccurrence_tp_dealloc(PyoaCollection_oaOccBusNetDef_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusNetDef_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNetDef_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusNetDef_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaOccBusNetDef_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusNetDef_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusNetDef_oaOccurrence v1;
    PyParamoaCollection_oaOccBusNetDef_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccBusNetDef_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusNetDef_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusNetDef_oaOccurrence*) ((PyoaCollection_oaOccBusNetDef_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusNetDef_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusNetDef_oaOccurrence_FromoaCollection_oaOccBusNetDef_oaOccurrence(oaCollection_oaOccBusNetDef_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusNetDef_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccBusNetDef_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusNetDef_oaOccurrenceObject* self = (PyoaCollection_oaOccBusNetDef_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccBusNetDef_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccBusNetDef_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccBusNetDef)\n"
"    Calls: oaBoolean includes(const oaOccBusNetDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusNetDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusNetDef_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusNetDef_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusNetDef_oaOccurrenceObject* self=(PyoaCollection_oaOccBusNetDef_oaOccurrenceObject*)ob;

    PyParamoaOccBusNetDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusNetDef_Convert,&p1)) {
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

static char oaCollection_oaOccBusNetDef_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccBusNetDef_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusNetDef_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusNetDef_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusNetDef_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusNetDef_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusNetDef_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusNetDef_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccBusNetDef_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusNetDef_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccBusNetDef_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusNetDef_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccBusNetDef_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccBusNetDef_oaOccurrence)\n"
"    Calls: oaCollection_oaOccBusNetDef_oaOccurrence(const oaCollection_oaOccBusNetDef_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccBusNetDef_oaOccurrence||cref-oaCollection_oaOccBusNetDef_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusNetDef_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccBusNetDef_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccBusNetDef_oaOccurrence||cref-oaCollection_oaOccBusNetDef_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusNetDef_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusNetDef_oaOccurrence",
    sizeof(PyoaCollection_oaOccBusNetDef_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccBusNetDef_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusNetDef_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusNetDef_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusNetDef_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusNetDef_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusNetDef_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusNetDef_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusNetDef_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusNetDef_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusNetDef_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccBusNetDef_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusNetDef_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusNet_oaOccBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNet_oaOccBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusNet_oaOccBusNetDefObject* self = (PyoaCollection_oaOccBusNet_oaOccBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusNet_oaOccBusNetDef)
    {
        PyParamoaCollection_oaOccBusNet_oaOccBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusNet_oaOccBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusNet_oaOccBusNetDef, Choices are:\n"
        "    (oaCollection_oaOccBusNet_oaOccBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusNet_oaOccBusNetDef_tp_dealloc(PyoaCollection_oaOccBusNet_oaOccBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusNet_oaOccBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusNet_oaOccBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusNet_oaOccBusNetDef value;
    int convert_status=PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaOccBusNet_oaOccBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusNet_oaOccBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusNet_oaOccBusNetDef v1;
    PyParamoaCollection_oaOccBusNet_oaOccBusNetDef v2;
    int convert_status1=PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaOccBusNet_oaOccBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusNet_oaOccBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusNet_oaOccBusNetDef*) ((PyoaCollection_oaOccBusNet_oaOccBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusNet_oaOccBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusNet_oaOccBusNetDef_FromoaCollection_oaOccBusNet_oaOccBusNetDef(oaCollection_oaOccBusNet_oaOccBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type.tp_alloc(&PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusNet_oaOccBusNetDefObject* self = (PyoaCollection_oaOccBusNet_oaOccBusNetDefObject*)bself;
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
static char oaCollection_oaOccBusNet_oaOccBusNetDef_includes_doc[] = 
"Class: oaCollection_oaOccBusNet_oaOccBusNetDef, Function: includes\n"
"  Paramegers: (oaOccBusNet)\n"
"    Calls: oaBoolean includes(const oaOccBusNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusNet_oaOccBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusNet_oaOccBusNetDef data;
    int convert_status=PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusNet_oaOccBusNetDefObject* self=(PyoaCollection_oaOccBusNet_oaOccBusNetDefObject*)ob;

    PyParamoaOccBusNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusNet_Convert,&p1)) {
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

static char oaCollection_oaOccBusNet_oaOccBusNetDef_assign_doc[] = 
"Class: oaCollection_oaOccBusNet_oaOccBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusNet_oaOccBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusNet_oaOccBusNetDef data;
  int convert_status=PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusNet_oaOccBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusNet_oaOccBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusNet_oaOccBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusNet_oaOccBusNetDef_includes,METH_VARARGS,oaCollection_oaOccBusNet_oaOccBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusNet_oaOccBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaOccBusNet_oaOccBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusNet_oaOccBusNetDef_doc[] = 
"Class: oaCollection_oaOccBusNet_oaOccBusNetDef\n"
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
"  Paramegers: (oaCollection_oaOccBusNet_oaOccBusNetDef)\n"
"    Calls: oaCollection_oaOccBusNet_oaOccBusNetDef(const oaCollection_oaOccBusNet_oaOccBusNetDef& coll)\n"
"    Signature: oaCollection_oaOccBusNet_oaOccBusNetDef||cref-oaCollection_oaOccBusNet_oaOccBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusNet_oaOccBusNetDef)\n"
"    Calls: (const oaCollection_oaOccBusNet_oaOccBusNetDef&)\n"
"    Signature: oaCollection_oaOccBusNet_oaOccBusNetDef||cref-oaCollection_oaOccBusNet_oaOccBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusNet_oaOccBusNetDef",
    sizeof(PyoaCollection_oaOccBusNet_oaOccBusNetDefObject),
    0,
    (destructor)oaCollection_oaOccBusNet_oaOccBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusNet_oaOccBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusNet_oaOccBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusNet_oaOccBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusNet_oaOccBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusNet_oaOccBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusNet_oaOccBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusNet_oaOccBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusNet_oaOccBusNetDef",
           (PyObject*)(&PyoaCollection_oaOccBusNet_oaOccBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusNet_oaOccBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusTermBit_oaOccBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTermBit_oaOccBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject* self = (PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusTermBit_oaOccBusTermDef)
    {
        PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusTermBit_oaOccBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusTermBit_oaOccBusTermDef, Choices are:\n"
        "    (oaCollection_oaOccBusTermBit_oaOccBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_dealloc(PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusTermBit_oaOccBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef value;
    int convert_status=PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaOccBusTermBit_oaOccBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef v1;
    PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef v2;
    int convert_status1=PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusTermBit_oaOccBusTermDef*) ((PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusTermBit_oaOccBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_FromoaCollection_oaOccBusTermBit_oaOccBusTermDef(oaCollection_oaOccBusTermBit_oaOccBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type.tp_alloc(&PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject* self = (PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject*)bself;
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
static char oaCollection_oaOccBusTermBit_oaOccBusTermDef_includes_doc[] = 
"Class: oaCollection_oaOccBusTermBit_oaOccBusTermDef, Function: includes\n"
"  Paramegers: (oaOccBusTermBit)\n"
"    Calls: oaBoolean includes(const oaOccBusTermBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusTermBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusTermBit_oaOccBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef data;
    int convert_status=PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject* self=(PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject*)ob;

    PyParamoaOccBusTermBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusTermBit_Convert,&p1)) {
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

static char oaCollection_oaOccBusTermBit_oaOccBusTermDef_assign_doc[] = 
"Class: oaCollection_oaOccBusTermBit_oaOccBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef data;
  int convert_status=PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusTermBit_oaOccBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusTermBit_oaOccBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusTermBit_oaOccBusTermDef_includes,METH_VARARGS,oaCollection_oaOccBusTermBit_oaOccBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaOccBusTermBit_oaOccBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusTermBit_oaOccBusTermDef_doc[] = 
"Class: oaCollection_oaOccBusTermBit_oaOccBusTermDef\n"
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
"  Paramegers: (oaCollection_oaOccBusTermBit_oaOccBusTermDef)\n"
"    Calls: oaCollection_oaOccBusTermBit_oaOccBusTermDef(const oaCollection_oaOccBusTermBit_oaOccBusTermDef& coll)\n"
"    Signature: oaCollection_oaOccBusTermBit_oaOccBusTermDef||cref-oaCollection_oaOccBusTermBit_oaOccBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusTermBit_oaOccBusTermDef)\n"
"    Calls: (const oaCollection_oaOccBusTermBit_oaOccBusTermDef&)\n"
"    Signature: oaCollection_oaOccBusTermBit_oaOccBusTermDef||cref-oaCollection_oaOccBusTermBit_oaOccBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusTermBit_oaOccBusTermDef",
    sizeof(PyoaCollection_oaOccBusTermBit_oaOccBusTermDefObject),
    0,
    (destructor)oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusTermBit_oaOccBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusTermBit_oaOccBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusTermBit_oaOccBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusTermBit_oaOccBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusTermBit_oaOccBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusTermBit_oaOccBusTermDef",
           (PyObject*)(&PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusTermBit_oaOccBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusTermDef_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTermDef_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusTermDef_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusTermDef_oaOccurrenceObject* self = (PyoaCollection_oaOccBusTermDef_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusTermDef_oaOccurrence)
    {
        PyParamoaCollection_oaOccBusTermDef_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusTermDef_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusTermDef_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccBusTermDef_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusTermDef_oaOccurrence_tp_dealloc(PyoaCollection_oaOccBusTermDef_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusTermDef_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTermDef_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusTermDef_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaOccBusTermDef_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusTermDef_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusTermDef_oaOccurrence v1;
    PyParamoaCollection_oaOccBusTermDef_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccBusTermDef_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusTermDef_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusTermDef_oaOccurrence*) ((PyoaCollection_oaOccBusTermDef_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusTermDef_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusTermDef_oaOccurrence_FromoaCollection_oaOccBusTermDef_oaOccurrence(oaCollection_oaOccBusTermDef_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusTermDef_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccBusTermDef_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusTermDef_oaOccurrenceObject* self = (PyoaCollection_oaOccBusTermDef_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccBusTermDef_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccBusTermDef_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccBusTermDef)\n"
"    Calls: oaBoolean includes(const oaOccBusTermDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusTermDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusTermDef_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusTermDef_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusTermDef_oaOccurrenceObject* self=(PyoaCollection_oaOccBusTermDef_oaOccurrenceObject*)ob;

    PyParamoaOccBusTermDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusTermDef_Convert,&p1)) {
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

static char oaCollection_oaOccBusTermDef_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccBusTermDef_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusTermDef_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusTermDef_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusTermDef_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusTermDef_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusTermDef_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusTermDef_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccBusTermDef_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusTermDef_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccBusTermDef_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusTermDef_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccBusTermDef_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccBusTermDef_oaOccurrence)\n"
"    Calls: oaCollection_oaOccBusTermDef_oaOccurrence(const oaCollection_oaOccBusTermDef_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccBusTermDef_oaOccurrence||cref-oaCollection_oaOccBusTermDef_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusTermDef_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccBusTermDef_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccBusTermDef_oaOccurrence||cref-oaCollection_oaOccBusTermDef_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusTermDef_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusTermDef_oaOccurrence",
    sizeof(PyoaCollection_oaOccBusTermDef_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccBusTermDef_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusTermDef_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusTermDef_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusTermDef_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusTermDef_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusTermDef_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusTermDef_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusTermDef_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusTermDef_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusTermDef_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccBusTermDef_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusTermDef_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccBusTerm_oaOccBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTerm_oaOccBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject* self = (PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccBusTerm_oaOccBusTermDef)
    {
        PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccBusTerm_oaOccBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccBusTerm_oaOccBusTermDef, Choices are:\n"
        "    (oaCollection_oaOccBusTerm_oaOccBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_dealloc(PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccBusTerm_oaOccBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef value;
    int convert_status=PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaOccBusTerm_oaOccBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef v1;
    PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef v2;
    int convert_status1=PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaOccBusTerm_oaOccBusTermDef*) ((PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccBusTerm_oaOccBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccBusTerm_oaOccBusTermDef_FromoaCollection_oaOccBusTerm_oaOccBusTermDef(oaCollection_oaOccBusTerm_oaOccBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type.tp_alloc(&PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject* self = (PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject*)bself;
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
static char oaCollection_oaOccBusTerm_oaOccBusTermDef_includes_doc[] = 
"Class: oaCollection_oaOccBusTerm_oaOccBusTermDef, Function: includes\n"
"  Paramegers: (oaOccBusTerm)\n"
"    Calls: oaBoolean includes(const oaOccBusTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccBusTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccBusTerm_oaOccBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef data;
    int convert_status=PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject* self=(PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject*)ob;

    PyParamoaOccBusTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccBusTerm_Convert,&p1)) {
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

static char oaCollection_oaOccBusTerm_oaOccBusTermDef_assign_doc[] = 
"Class: oaCollection_oaOccBusTerm_oaOccBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef data;
  int convert_status=PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccBusTerm_oaOccBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccBusTerm_oaOccBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccBusTerm_oaOccBusTermDef_includes,METH_VARARGS,oaCollection_oaOccBusTerm_oaOccBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaOccBusTerm_oaOccBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccBusTerm_oaOccBusTermDef_doc[] = 
"Class: oaCollection_oaOccBusTerm_oaOccBusTermDef\n"
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
"  Paramegers: (oaCollection_oaOccBusTerm_oaOccBusTermDef)\n"
"    Calls: oaCollection_oaOccBusTerm_oaOccBusTermDef(const oaCollection_oaOccBusTerm_oaOccBusTermDef& coll)\n"
"    Signature: oaCollection_oaOccBusTerm_oaOccBusTermDef||cref-oaCollection_oaOccBusTerm_oaOccBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccBusTerm_oaOccBusTermDef)\n"
"    Calls: (const oaCollection_oaOccBusTerm_oaOccBusTermDef&)\n"
"    Signature: oaCollection_oaOccBusTerm_oaOccBusTermDef||cref-oaCollection_oaOccBusTerm_oaOccBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccBusTerm_oaOccBusTermDef",
    sizeof(PyoaCollection_oaOccBusTerm_oaOccBusTermDefObject),
    0,
    (destructor)oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccBusTerm_oaOccBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccBusTerm_oaOccBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccBusTerm_oaOccBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccBusTerm_oaOccBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccBusTerm_oaOccBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccBusTerm_oaOccBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccBusTerm_oaOccBusTermDef",
           (PyObject*)(&PyoaCollection_oaOccBusTerm_oaOccBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccBusTerm_oaOccBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccConnectDef_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccConnectDef_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccConnectDef_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccConnectDef_oaOccurrenceObject* self = (PyoaCollection_oaOccConnectDef_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccConnectDef_oaOccurrence)
    {
        PyParamoaCollection_oaOccConnectDef_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccConnectDef_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccConnectDef_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccConnectDef_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccConnectDef_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccConnectDef_oaOccurrence_tp_dealloc(PyoaCollection_oaOccConnectDef_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccConnectDef_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccConnectDef_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccConnectDef_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaOccConnectDef_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccConnectDef_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccConnectDef_oaOccurrence v1;
    PyParamoaCollection_oaOccConnectDef_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccConnectDef_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccConnectDef_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccConnectDef_oaOccurrence*) ((PyoaCollection_oaOccConnectDef_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccConnectDef_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccConnectDef_oaOccurrence_FromoaCollection_oaOccConnectDef_oaOccurrence(oaCollection_oaOccConnectDef_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccConnectDef_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccConnectDef_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccConnectDef_oaOccurrenceObject* self = (PyoaCollection_oaOccConnectDef_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccConnectDef_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccConnectDef_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccConnectDef)\n"
"    Calls: oaBoolean includes(const oaOccConnectDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccConnectDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccConnectDef_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccConnectDef_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccConnectDef_oaOccurrenceObject* self=(PyoaCollection_oaOccConnectDef_oaOccurrenceObject*)ob;

    PyParamoaOccConnectDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccConnectDef_Convert,&p1)) {
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

static char oaCollection_oaOccConnectDef_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccConnectDef_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccConnectDef_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccConnectDef_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccConnectDef_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccConnectDef_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccConnectDef_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccConnectDef_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccConnectDef_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccConnectDef_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccConnectDef_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccConnectDef_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccConnectDef_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccConnectDef_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccConnectDef_oaOccurrence)\n"
"    Calls: oaCollection_oaOccConnectDef_oaOccurrence(const oaCollection_oaOccConnectDef_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccConnectDef_oaOccurrence||cref-oaCollection_oaOccConnectDef_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccConnectDef_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccConnectDef_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccConnectDef_oaOccurrence||cref-oaCollection_oaOccConnectDef_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccConnectDef_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccConnectDef_oaOccurrence",
    sizeof(PyoaCollection_oaOccConnectDef_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccConnectDef_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccConnectDef_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccConnectDef_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccConnectDef_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccConnectDef_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccConnectDef_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccConnectDef_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccConnectDef_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccConnectDef_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccConnectDef_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccConnectDef_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccConnectDef_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccDesignInst_oaOccInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccDesignInst_oaOccInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject* self = (PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccDesignInst_oaOccInstHeader)
    {
        PyParamoaCollection_oaOccDesignInst_oaOccInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccDesignInst_oaOccInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccDesignInst_oaOccInstHeader, Choices are:\n"
        "    (oaCollection_oaOccDesignInst_oaOccInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccDesignInst_oaOccInstHeader_tp_dealloc(PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccDesignInst_oaOccInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccDesignInst_oaOccInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccDesignInst_oaOccInstHeader value;
    int convert_status=PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaOccDesignInst_oaOccInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccDesignInst_oaOccInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccDesignInst_oaOccInstHeader v1;
    PyParamoaCollection_oaOccDesignInst_oaOccInstHeader v2;
    int convert_status1=PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaOccDesignInst_oaOccInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccDesignInst_oaOccInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaOccDesignInst_oaOccInstHeader*) ((PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccDesignInst_oaOccInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccDesignInst_oaOccInstHeader_FromoaCollection_oaOccDesignInst_oaOccInstHeader(oaCollection_oaOccDesignInst_oaOccInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type.tp_alloc(&PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject* self = (PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject*)bself;
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
static char oaCollection_oaOccDesignInst_oaOccInstHeader_includes_doc[] = 
"Class: oaCollection_oaOccDesignInst_oaOccInstHeader, Function: includes\n"
"  Paramegers: (oaOccDesignInst)\n"
"    Calls: oaBoolean includes(const oaOccDesignInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccDesignInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccDesignInst_oaOccInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccDesignInst_oaOccInstHeader data;
    int convert_status=PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject* self=(PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject*)ob;

    PyParamoaOccDesignInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccDesignInst_Convert,&p1)) {
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

static char oaCollection_oaOccDesignInst_oaOccInstHeader_assign_doc[] = 
"Class: oaCollection_oaOccDesignInst_oaOccInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccDesignInst_oaOccInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccDesignInst_oaOccInstHeader data;
  int convert_status=PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccDesignInst_oaOccInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccDesignInst_oaOccInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccDesignInst_oaOccInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccDesignInst_oaOccInstHeader_includes,METH_VARARGS,oaCollection_oaOccDesignInst_oaOccInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccDesignInst_oaOccInstHeader_tp_assign,METH_VARARGS,oaCollection_oaOccDesignInst_oaOccInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccDesignInst_oaOccInstHeader_doc[] = 
"Class: oaCollection_oaOccDesignInst_oaOccInstHeader\n"
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
"  Paramegers: (oaCollection_oaOccDesignInst_oaOccInstHeader)\n"
"    Calls: oaCollection_oaOccDesignInst_oaOccInstHeader(const oaCollection_oaOccDesignInst_oaOccInstHeader& coll)\n"
"    Signature: oaCollection_oaOccDesignInst_oaOccInstHeader||cref-oaCollection_oaOccDesignInst_oaOccInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccDesignInst_oaOccInstHeader)\n"
"    Calls: (const oaCollection_oaOccDesignInst_oaOccInstHeader&)\n"
"    Signature: oaCollection_oaOccDesignInst_oaOccInstHeader||cref-oaCollection_oaOccDesignInst_oaOccInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccDesignInst_oaOccInstHeader",
    sizeof(PyoaCollection_oaOccDesignInst_oaOccInstHeaderObject),
    0,
    (destructor)oaCollection_oaOccDesignInst_oaOccInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccDesignInst_oaOccInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccDesignInst_oaOccInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccDesignInst_oaOccInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccDesignInst_oaOccInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccDesignInst_oaOccInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccDesignInst_oaOccInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccDesignInst_oaOccInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccDesignInst_oaOccInstHeader",
           (PyObject*)(&PyoaCollection_oaOccDesignInst_oaOccInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccDesignInst_oaOccInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstHeader_oaOccInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstHeader_oaOccInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject* self = (PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstHeader_oaOccInstHeader)
    {
        PyParamoaCollection_oaOccInstHeader_oaOccInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstHeader_oaOccInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstHeader_oaOccInstHeader, Choices are:\n"
        "    (oaCollection_oaOccInstHeader_oaOccInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstHeader_oaOccInstHeader_tp_dealloc(PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstHeader_oaOccInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstHeader_oaOccInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstHeader_oaOccInstHeader value;
    int convert_status=PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaOccInstHeader_oaOccInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstHeader_oaOccInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstHeader_oaOccInstHeader v1;
    PyParamoaCollection_oaOccInstHeader_oaOccInstHeader v2;
    int convert_status1=PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaOccInstHeader_oaOccInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstHeader_oaOccInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstHeader_oaOccInstHeader*) ((PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstHeader_oaOccInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstHeader_oaOccInstHeader_FromoaCollection_oaOccInstHeader_oaOccInstHeader(oaCollection_oaOccInstHeader_oaOccInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type.tp_alloc(&PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject* self = (PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject*)bself;
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
static char oaCollection_oaOccInstHeader_oaOccInstHeader_includes_doc[] = 
"Class: oaCollection_oaOccInstHeader_oaOccInstHeader, Function: includes\n"
"  Paramegers: (oaOccInstHeader)\n"
"    Calls: oaBoolean includes(const oaOccInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstHeader_oaOccInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstHeader_oaOccInstHeader data;
    int convert_status=PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject* self=(PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject*)ob;

    PyParamoaOccInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstHeader_Convert,&p1)) {
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

static char oaCollection_oaOccInstHeader_oaOccInstHeader_assign_doc[] = 
"Class: oaCollection_oaOccInstHeader_oaOccInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstHeader_oaOccInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstHeader_oaOccInstHeader data;
  int convert_status=PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstHeader_oaOccInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstHeader_oaOccInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstHeader_oaOccInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstHeader_oaOccInstHeader_includes,METH_VARARGS,oaCollection_oaOccInstHeader_oaOccInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstHeader_oaOccInstHeader_tp_assign,METH_VARARGS,oaCollection_oaOccInstHeader_oaOccInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstHeader_oaOccInstHeader_doc[] = 
"Class: oaCollection_oaOccInstHeader_oaOccInstHeader\n"
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
"  Paramegers: (oaCollection_oaOccInstHeader_oaOccInstHeader)\n"
"    Calls: oaCollection_oaOccInstHeader_oaOccInstHeader(const oaCollection_oaOccInstHeader_oaOccInstHeader& coll)\n"
"    Signature: oaCollection_oaOccInstHeader_oaOccInstHeader||cref-oaCollection_oaOccInstHeader_oaOccInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstHeader_oaOccInstHeader)\n"
"    Calls: (const oaCollection_oaOccInstHeader_oaOccInstHeader&)\n"
"    Signature: oaCollection_oaOccInstHeader_oaOccInstHeader||cref-oaCollection_oaOccInstHeader_oaOccInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstHeader_oaOccInstHeader",
    sizeof(PyoaCollection_oaOccInstHeader_oaOccInstHeaderObject),
    0,
    (destructor)oaCollection_oaOccInstHeader_oaOccInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstHeader_oaOccInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstHeader_oaOccInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstHeader_oaOccInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstHeader_oaOccInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstHeader_oaOccInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstHeader_oaOccInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstHeader_oaOccInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstHeader_oaOccInstHeader",
           (PyObject*)(&PyoaCollection_oaOccInstHeader_oaOccInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstHeader_oaOccInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstTerm_oaInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstTerm_oaInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstTerm_oaInstTermObject* self = (PyoaCollection_oaOccInstTerm_oaInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstTerm_oaInstTerm)
    {
        PyParamoaCollection_oaOccInstTerm_oaInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstTerm_oaInstTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstTerm_oaInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstTerm_oaInstTerm, Choices are:\n"
        "    (oaCollection_oaOccInstTerm_oaInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstTerm_oaInstTerm_tp_dealloc(PyoaCollection_oaOccInstTerm_oaInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstTerm_oaInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstTerm_oaInstTerm value;
    int convert_status=PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaOccInstTerm_oaInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstTerm_oaInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstTerm_oaInstTerm v1;
    PyParamoaCollection_oaOccInstTerm_oaInstTerm v2;
    int convert_status1=PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(PyObject* ob,PyParamoaCollection_oaOccInstTerm_oaInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstTerm_oaInstTerm_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstTerm_oaInstTerm*) ((PyoaCollection_oaOccInstTerm_oaInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstTerm_oaInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstTerm_oaInstTerm_FromoaCollection_oaOccInstTerm_oaInstTerm(oaCollection_oaOccInstTerm_oaInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstTerm_oaInstTerm_Type.tp_alloc(&PyoaCollection_oaOccInstTerm_oaInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstTerm_oaInstTermObject* self = (PyoaCollection_oaOccInstTerm_oaInstTermObject*)bself;
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
static char oaCollection_oaOccInstTerm_oaInstTerm_includes_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaInstTerm, Function: includes\n"
"  Paramegers: (oaOccInstTerm)\n"
"    Calls: oaBoolean includes(const oaOccInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaInstTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstTerm_oaInstTerm data;
    int convert_status=PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstTerm_oaInstTermObject* self=(PyoaCollection_oaOccInstTerm_oaInstTermObject*)ob;

    PyParamoaOccInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstTerm_Convert,&p1)) {
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

static char oaCollection_oaOccInstTerm_oaInstTerm_assign_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstTerm_oaInstTerm data;
  int convert_status=PyoaCollection_oaOccInstTerm_oaInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstTerm_oaInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstTerm_oaInstTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstTerm_oaInstTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstTerm_oaInstTerm_includes,METH_VARARGS,oaCollection_oaOccInstTerm_oaInstTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstTerm_oaInstTerm_tp_assign,METH_VARARGS,oaCollection_oaOccInstTerm_oaInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstTerm_oaInstTerm_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaInstTerm\n"
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
"  Paramegers: (oaCollection_oaOccInstTerm_oaInstTerm)\n"
"    Calls: oaCollection_oaOccInstTerm_oaInstTerm(const oaCollection_oaOccInstTerm_oaInstTerm& coll)\n"
"    Signature: oaCollection_oaOccInstTerm_oaInstTerm||cref-oaCollection_oaOccInstTerm_oaInstTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstTerm_oaInstTerm)\n"
"    Calls: (const oaCollection_oaOccInstTerm_oaInstTerm&)\n"
"    Signature: oaCollection_oaOccInstTerm_oaInstTerm||cref-oaCollection_oaOccInstTerm_oaInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstTerm_oaInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstTerm_oaInstTerm",
    sizeof(PyoaCollection_oaOccInstTerm_oaInstTermObject),
    0,
    (destructor)oaCollection_oaOccInstTerm_oaInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstTerm_oaInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstTerm_oaInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstTerm_oaInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstTerm_oaInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstTerm_oaInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstTerm_oaInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstTerm_oaInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstTerm_oaInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstTerm_oaInstTerm",
           (PyObject*)(&PyoaCollection_oaOccInstTerm_oaInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstTerm_oaInstTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstTerm_oaModInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaModInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstTerm_oaModInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstTerm_oaModInstTermObject* self = (PyoaCollection_oaOccInstTerm_oaModInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstTerm_oaModInstTerm)
    {
        PyParamoaCollection_oaOccInstTerm_oaModInstTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstTerm_oaModInstTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstTerm_oaModInstTerm, Choices are:\n"
        "    (oaCollection_oaOccInstTerm_oaModInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstTerm_oaModInstTerm_tp_dealloc(PyoaCollection_oaOccInstTerm_oaModInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstTerm_oaModInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaModInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstTerm_oaModInstTerm value;
    int convert_status=PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaOccInstTerm_oaModInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstTerm_oaModInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstTerm_oaModInstTerm v1;
    PyParamoaCollection_oaOccInstTerm_oaModInstTerm v2;
    int convert_status1=PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(PyObject* ob,PyParamoaCollection_oaOccInstTerm_oaModInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstTerm_oaModInstTerm_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstTerm_oaModInstTerm*) ((PyoaCollection_oaOccInstTerm_oaModInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstTerm_oaModInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstTerm_oaModInstTerm_FromoaCollection_oaOccInstTerm_oaModInstTerm(oaCollection_oaOccInstTerm_oaModInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstTerm_oaModInstTerm_Type.tp_alloc(&PyoaCollection_oaOccInstTerm_oaModInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstTerm_oaModInstTermObject* self = (PyoaCollection_oaOccInstTerm_oaModInstTermObject*)bself;
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
static char oaCollection_oaOccInstTerm_oaModInstTerm_includes_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaModInstTerm, Function: includes\n"
"  Paramegers: (oaOccInstTerm)\n"
"    Calls: oaBoolean includes(const oaOccInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaModInstTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstTerm_oaModInstTerm data;
    int convert_status=PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstTerm_oaModInstTermObject* self=(PyoaCollection_oaOccInstTerm_oaModInstTermObject*)ob;

    PyParamoaOccInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstTerm_Convert,&p1)) {
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

static char oaCollection_oaOccInstTerm_oaModInstTerm_assign_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaModInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaModInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstTerm_oaModInstTerm data;
  int convert_status=PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstTerm_oaModInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstTerm_oaModInstTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstTerm_oaModInstTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstTerm_oaModInstTerm_includes,METH_VARARGS,oaCollection_oaOccInstTerm_oaModInstTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstTerm_oaModInstTerm_tp_assign,METH_VARARGS,oaCollection_oaOccInstTerm_oaModInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstTerm_oaModInstTerm_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaModInstTerm\n"
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
"  Paramegers: (oaCollection_oaOccInstTerm_oaModInstTerm)\n"
"    Calls: oaCollection_oaOccInstTerm_oaModInstTerm(const oaCollection_oaOccInstTerm_oaModInstTerm& coll)\n"
"    Signature: oaCollection_oaOccInstTerm_oaModInstTerm||cref-oaCollection_oaOccInstTerm_oaModInstTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstTerm_oaModInstTerm)\n"
"    Calls: (const oaCollection_oaOccInstTerm_oaModInstTerm&)\n"
"    Signature: oaCollection_oaOccInstTerm_oaModInstTerm||cref-oaCollection_oaOccInstTerm_oaModInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstTerm_oaModInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstTerm_oaModInstTerm",
    sizeof(PyoaCollection_oaOccInstTerm_oaModInstTermObject),
    0,
    (destructor)oaCollection_oaOccInstTerm_oaModInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstTerm_oaModInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstTerm_oaModInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstTerm_oaModInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstTerm_oaModInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstTerm_oaModInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstTerm_oaModInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstTerm_oaModInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstTerm_oaModInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstTerm_oaModInstTerm",
           (PyObject*)(&PyoaCollection_oaOccInstTerm_oaModInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstTerm_oaModInstTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstTerm_oaOccInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstTerm_oaOccInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstTerm_oaOccInstObject* self = (PyoaCollection_oaOccInstTerm_oaOccInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstTerm_oaOccInst)
    {
        PyParamoaCollection_oaOccInstTerm_oaOccInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstTerm_oaOccInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstTerm_oaOccInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstTerm_oaOccInst, Choices are:\n"
        "    (oaCollection_oaOccInstTerm_oaOccInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstTerm_oaOccInst_tp_dealloc(PyoaCollection_oaOccInstTerm_oaOccInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstTerm_oaOccInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstTerm_oaOccInst value;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaOccInstTerm_oaOccInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstTerm_oaOccInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstTerm_oaOccInst v1;
    PyParamoaCollection_oaOccInstTerm_oaOccInst v2;
    int convert_status1=PyoaCollection_oaOccInstTerm_oaOccInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstTerm_oaOccInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstTerm_oaOccInst_Convert(PyObject* ob,PyParamoaCollection_oaOccInstTerm_oaOccInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstTerm_oaOccInst_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstTerm_oaOccInst*) ((PyoaCollection_oaOccInstTerm_oaOccInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstTerm_oaOccInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstTerm_oaOccInst_FromoaCollection_oaOccInstTerm_oaOccInst(oaCollection_oaOccInstTerm_oaOccInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstTerm_oaOccInst_Type.tp_alloc(&PyoaCollection_oaOccInstTerm_oaOccInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstTerm_oaOccInstObject* self = (PyoaCollection_oaOccInstTerm_oaOccInstObject*)bself;
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
static char oaCollection_oaOccInstTerm_oaOccInst_includes_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccInst, Function: includes\n"
"  Paramegers: (oaOccInstTerm)\n"
"    Calls: oaBoolean includes(const oaOccInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccInst data;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstTerm_oaOccInstObject* self=(PyoaCollection_oaOccInstTerm_oaOccInstObject*)ob;

    PyParamoaOccInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstTerm_Convert,&p1)) {
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

static char oaCollection_oaOccInstTerm_oaOccInst_assign_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstTerm_oaOccInst data;
  int convert_status=PyoaCollection_oaOccInstTerm_oaOccInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstTerm_oaOccInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstTerm_oaOccInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstTerm_oaOccInst_includes,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstTerm_oaOccInst_tp_assign,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstTerm_oaOccInst_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccInst\n"
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
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccInst)\n"
"    Calls: oaCollection_oaOccInstTerm_oaOccInst(const oaCollection_oaOccInstTerm_oaOccInst& coll)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccInst||cref-oaCollection_oaOccInstTerm_oaOccInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccInst)\n"
"    Calls: (const oaCollection_oaOccInstTerm_oaOccInst&)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccInst||cref-oaCollection_oaOccInstTerm_oaOccInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstTerm_oaOccInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstTerm_oaOccInst",
    sizeof(PyoaCollection_oaOccInstTerm_oaOccInstObject),
    0,
    (destructor)oaCollection_oaOccInstTerm_oaOccInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstTerm_oaOccInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstTerm_oaOccInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstTerm_oaOccInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstTerm_oaOccInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstTerm_oaOccInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstTerm_oaOccInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstTerm_oaOccInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstTerm_oaOccInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstTerm_oaOccInst",
           (PyObject*)(&PyoaCollection_oaOccInstTerm_oaOccInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstTerm_oaOccInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstTerm_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstTerm_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstTerm_oaOccNetObject* self = (PyoaCollection_oaOccInstTerm_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstTerm_oaOccNet)
    {
        PyParamoaCollection_oaOccInstTerm_oaOccNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstTerm_oaOccNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstTerm_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstTerm_oaOccNet, Choices are:\n"
        "    (oaCollection_oaOccInstTerm_oaOccNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstTerm_oaOccNet_tp_dealloc(PyoaCollection_oaOccInstTerm_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstTerm_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstTerm_oaOccNet value;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaOccInstTerm_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstTerm_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstTerm_oaOccNet v1;
    PyParamoaCollection_oaOccInstTerm_oaOccNet v2;
    int convert_status1=PyoaCollection_oaOccInstTerm_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstTerm_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstTerm_oaOccNet_Convert(PyObject* ob,PyParamoaCollection_oaOccInstTerm_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstTerm_oaOccNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstTerm_oaOccNet*) ((PyoaCollection_oaOccInstTerm_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstTerm_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstTerm_oaOccNet_FromoaCollection_oaOccInstTerm_oaOccNet(oaCollection_oaOccInstTerm_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstTerm_oaOccNet_Type.tp_alloc(&PyoaCollection_oaOccInstTerm_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstTerm_oaOccNetObject* self = (PyoaCollection_oaOccInstTerm_oaOccNetObject*)bself;
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
static char oaCollection_oaOccInstTerm_oaOccNet_includes_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccNet, Function: includes\n"
"  Paramegers: (oaOccInstTerm)\n"
"    Calls: oaBoolean includes(const oaOccInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccNet data;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstTerm_oaOccNetObject* self=(PyoaCollection_oaOccInstTerm_oaOccNetObject*)ob;

    PyParamoaOccInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstTerm_Convert,&p1)) {
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

static char oaCollection_oaOccInstTerm_oaOccNet_assign_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstTerm_oaOccNet data;
  int convert_status=PyoaCollection_oaOccInstTerm_oaOccNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstTerm_oaOccNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstTerm_oaOccNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstTerm_oaOccNet_includes,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstTerm_oaOccNet_tp_assign,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstTerm_oaOccNet_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccNet\n"
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
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccNet)\n"
"    Calls: oaCollection_oaOccInstTerm_oaOccNet(const oaCollection_oaOccInstTerm_oaOccNet& coll)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccNet||cref-oaCollection_oaOccInstTerm_oaOccNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccNet)\n"
"    Calls: (const oaCollection_oaOccInstTerm_oaOccNet&)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccNet||cref-oaCollection_oaOccInstTerm_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstTerm_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstTerm_oaOccNet",
    sizeof(PyoaCollection_oaOccInstTerm_oaOccNetObject),
    0,
    (destructor)oaCollection_oaOccInstTerm_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstTerm_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstTerm_oaOccNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstTerm_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstTerm_oaOccNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstTerm_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstTerm_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstTerm_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstTerm_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstTerm_oaOccNet",
           (PyObject*)(&PyoaCollection_oaOccInstTerm_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstTerm_oaOccNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInstTerm_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInstTerm_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInstTerm_oaOccurrenceObject* self = (PyoaCollection_oaOccInstTerm_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInstTerm_oaOccurrence)
    {
        PyParamoaCollection_oaOccInstTerm_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInstTerm_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInstTerm_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInstTerm_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccInstTerm_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInstTerm_oaOccurrence_tp_dealloc(PyoaCollection_oaOccInstTerm_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInstTerm_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInstTerm_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInstTerm_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaOccInstTerm_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInstTerm_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInstTerm_oaOccurrence v1;
    PyParamoaCollection_oaOccInstTerm_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccInstTerm_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInstTerm_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccInstTerm_oaOccurrence*) ((PyoaCollection_oaOccInstTerm_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInstTerm_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInstTerm_oaOccurrence_FromoaCollection_oaOccInstTerm_oaOccurrence(oaCollection_oaOccInstTerm_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInstTerm_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccInstTerm_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInstTerm_oaOccurrenceObject* self = (PyoaCollection_oaOccInstTerm_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccInstTerm_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccInstTerm)\n"
"    Calls: oaBoolean includes(const oaOccInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInstTerm_oaOccurrenceObject* self=(PyoaCollection_oaOccInstTerm_oaOccurrenceObject*)ob;

    PyParamoaOccInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInstTerm_Convert,&p1)) {
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

static char oaCollection_oaOccInstTerm_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInstTerm_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInstTerm_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccInstTerm_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInstTerm_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInstTerm_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInstTerm_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInstTerm_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInstTerm_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccInstTerm_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInstTerm_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccInstTerm_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccurrence)\n"
"    Calls: oaCollection_oaOccInstTerm_oaOccurrence(const oaCollection_oaOccInstTerm_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccurrence||cref-oaCollection_oaOccInstTerm_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInstTerm_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccInstTerm_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccInstTerm_oaOccurrence||cref-oaCollection_oaOccInstTerm_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInstTerm_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInstTerm_oaOccurrence",
    sizeof(PyoaCollection_oaOccInstTerm_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccInstTerm_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInstTerm_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInstTerm_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInstTerm_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInstTerm_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInstTerm_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInstTerm_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInstTerm_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInstTerm_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInstTerm_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccInstTerm_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInstTerm_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInst_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInst_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInst_oaInstObject* self = (PyoaCollection_oaOccInst_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInst_oaInst)
    {
        PyParamoaCollection_oaOccInst_oaInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInst_oaInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInst_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInst_oaInst, Choices are:\n"
        "    (oaCollection_oaOccInst_oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInst_oaInst_tp_dealloc(PyoaCollection_oaOccInst_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInst_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInst_oaInst value;
    int convert_status=PyoaCollection_oaOccInst_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaOccInst_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInst_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInst_oaInst v1;
    PyParamoaCollection_oaOccInst_oaInst v2;
    int convert_status1=PyoaCollection_oaOccInst_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInst_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInst_oaInst_Convert(PyObject* ob,PyParamoaCollection_oaOccInst_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInst_oaInst_Check(ob)) {
        result->SetData( (oaCollection_oaOccInst_oaInst*) ((PyoaCollection_oaOccInst_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInst_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInst_oaInst_FromoaCollection_oaOccInst_oaInst(oaCollection_oaOccInst_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInst_oaInst_Type.tp_alloc(&PyoaCollection_oaOccInst_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInst_oaInstObject* self = (PyoaCollection_oaOccInst_oaInstObject*)bself;
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
static char oaCollection_oaOccInst_oaInst_includes_doc[] = 
"Class: oaCollection_oaOccInst_oaInst, Function: includes\n"
"  Paramegers: (oaOccInst)\n"
"    Calls: oaBoolean includes(const oaOccInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInst_oaInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInst_oaInst data;
    int convert_status=PyoaCollection_oaOccInst_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInst_oaInstObject* self=(PyoaCollection_oaOccInst_oaInstObject*)ob;

    PyParamoaOccInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInst_Convert,&p1)) {
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

static char oaCollection_oaOccInst_oaInst_assign_doc[] = 
"Class: oaCollection_oaOccInst_oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInst_oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInst_oaInst data;
  int convert_status=PyoaCollection_oaOccInst_oaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInst_oaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInst_oaInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInst_oaInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInst_oaInst_includes,METH_VARARGS,oaCollection_oaOccInst_oaInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInst_oaInst_tp_assign,METH_VARARGS,oaCollection_oaOccInst_oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInst_oaInst_doc[] = 
"Class: oaCollection_oaOccInst_oaInst\n"
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
"  Paramegers: (oaCollection_oaOccInst_oaInst)\n"
"    Calls: oaCollection_oaOccInst_oaInst(const oaCollection_oaOccInst_oaInst& coll)\n"
"    Signature: oaCollection_oaOccInst_oaInst||cref-oaCollection_oaOccInst_oaInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInst_oaInst)\n"
"    Calls: (const oaCollection_oaOccInst_oaInst&)\n"
"    Signature: oaCollection_oaOccInst_oaInst||cref-oaCollection_oaOccInst_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInst_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInst_oaInst",
    sizeof(PyoaCollection_oaOccInst_oaInstObject),
    0,
    (destructor)oaCollection_oaOccInst_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInst_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInst_oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInst_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInst_oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInst_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInst_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInst_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInst_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInst_oaInst",
           (PyObject*)(&PyoaCollection_oaOccInst_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInst_oaInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInst_oaModInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaModInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInst_oaModInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInst_oaModInstObject* self = (PyoaCollection_oaOccInst_oaModInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInst_oaModInst)
    {
        PyParamoaCollection_oaOccInst_oaModInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInst_oaModInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInst_oaModInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInst_oaModInst, Choices are:\n"
        "    (oaCollection_oaOccInst_oaModInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInst_oaModInst_tp_dealloc(PyoaCollection_oaOccInst_oaModInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInst_oaModInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaModInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInst_oaModInst value;
    int convert_status=PyoaCollection_oaOccInst_oaModInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaOccInst_oaModInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInst_oaModInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInst_oaModInst v1;
    PyParamoaCollection_oaOccInst_oaModInst v2;
    int convert_status1=PyoaCollection_oaOccInst_oaModInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInst_oaModInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInst_oaModInst_Convert(PyObject* ob,PyParamoaCollection_oaOccInst_oaModInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInst_oaModInst_Check(ob)) {
        result->SetData( (oaCollection_oaOccInst_oaModInst*) ((PyoaCollection_oaOccInst_oaModInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInst_oaModInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInst_oaModInst_FromoaCollection_oaOccInst_oaModInst(oaCollection_oaOccInst_oaModInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInst_oaModInst_Type.tp_alloc(&PyoaCollection_oaOccInst_oaModInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInst_oaModInstObject* self = (PyoaCollection_oaOccInst_oaModInstObject*)bself;
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
static char oaCollection_oaOccInst_oaModInst_includes_doc[] = 
"Class: oaCollection_oaOccInst_oaModInst, Function: includes\n"
"  Paramegers: (oaOccInst)\n"
"    Calls: oaBoolean includes(const oaOccInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInst_oaModInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInst_oaModInst data;
    int convert_status=PyoaCollection_oaOccInst_oaModInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInst_oaModInstObject* self=(PyoaCollection_oaOccInst_oaModInstObject*)ob;

    PyParamoaOccInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInst_Convert,&p1)) {
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

static char oaCollection_oaOccInst_oaModInst_assign_doc[] = 
"Class: oaCollection_oaOccInst_oaModInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInst_oaModInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInst_oaModInst data;
  int convert_status=PyoaCollection_oaOccInst_oaModInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInst_oaModInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInst_oaModInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInst_oaModInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInst_oaModInst_includes,METH_VARARGS,oaCollection_oaOccInst_oaModInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInst_oaModInst_tp_assign,METH_VARARGS,oaCollection_oaOccInst_oaModInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInst_oaModInst_doc[] = 
"Class: oaCollection_oaOccInst_oaModInst\n"
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
"  Paramegers: (oaCollection_oaOccInst_oaModInst)\n"
"    Calls: oaCollection_oaOccInst_oaModInst(const oaCollection_oaOccInst_oaModInst& coll)\n"
"    Signature: oaCollection_oaOccInst_oaModInst||cref-oaCollection_oaOccInst_oaModInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInst_oaModInst)\n"
"    Calls: (const oaCollection_oaOccInst_oaModInst&)\n"
"    Signature: oaCollection_oaOccInst_oaModInst||cref-oaCollection_oaOccInst_oaModInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInst_oaModInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInst_oaModInst",
    sizeof(PyoaCollection_oaOccInst_oaModInstObject),
    0,
    (destructor)oaCollection_oaOccInst_oaModInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInst_oaModInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInst_oaModInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInst_oaModInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInst_oaModInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInst_oaModInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInst_oaModInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInst_oaModInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInst_oaModInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInst_oaModInst",
           (PyObject*)(&PyoaCollection_oaOccInst_oaModInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInst_oaModInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInst_oaOccVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaOccVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInst_oaOccVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInst_oaOccVectorInstDefObject* self = (PyoaCollection_oaOccInst_oaOccVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInst_oaOccVectorInstDef)
    {
        PyParamoaCollection_oaOccInst_oaOccVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInst_oaOccVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInst_oaOccVectorInstDef, Choices are:\n"
        "    (oaCollection_oaOccInst_oaOccVectorInstDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInst_oaOccVectorInstDef_tp_dealloc(PyoaCollection_oaOccInst_oaOccVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInst_oaOccVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaOccVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInst_oaOccVectorInstDef value;
    int convert_status=PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaOccInst_oaOccVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInst_oaOccVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInst_oaOccVectorInstDef v1;
    PyParamoaCollection_oaOccInst_oaOccVectorInstDef v2;
    int convert_status1=PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(PyObject* ob,PyParamoaCollection_oaOccInst_oaOccVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInst_oaOccVectorInstDef_Check(ob)) {
        result->SetData( (oaCollection_oaOccInst_oaOccVectorInstDef*) ((PyoaCollection_oaOccInst_oaOccVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInst_oaOccVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInst_oaOccVectorInstDef_FromoaCollection_oaOccInst_oaOccVectorInstDef(oaCollection_oaOccInst_oaOccVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInst_oaOccVectorInstDef_Type.tp_alloc(&PyoaCollection_oaOccInst_oaOccVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInst_oaOccVectorInstDefObject* self = (PyoaCollection_oaOccInst_oaOccVectorInstDefObject*)bself;
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
static char oaCollection_oaOccInst_oaOccVectorInstDef_includes_doc[] = 
"Class: oaCollection_oaOccInst_oaOccVectorInstDef, Function: includes\n"
"  Paramegers: (oaOccInst)\n"
"    Calls: oaBoolean includes(const oaOccInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInst_oaOccVectorInstDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInst_oaOccVectorInstDef data;
    int convert_status=PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInst_oaOccVectorInstDefObject* self=(PyoaCollection_oaOccInst_oaOccVectorInstDefObject*)ob;

    PyParamoaOccInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInst_Convert,&p1)) {
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

static char oaCollection_oaOccInst_oaOccVectorInstDef_assign_doc[] = 
"Class: oaCollection_oaOccInst_oaOccVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInst_oaOccVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInst_oaOccVectorInstDef data;
  int convert_status=PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInst_oaOccVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInst_oaOccVectorInstDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInst_oaOccVectorInstDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInst_oaOccVectorInstDef_includes,METH_VARARGS,oaCollection_oaOccInst_oaOccVectorInstDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInst_oaOccVectorInstDef_tp_assign,METH_VARARGS,oaCollection_oaOccInst_oaOccVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInst_oaOccVectorInstDef_doc[] = 
"Class: oaCollection_oaOccInst_oaOccVectorInstDef\n"
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
"  Paramegers: (oaCollection_oaOccInst_oaOccVectorInstDef)\n"
"    Calls: oaCollection_oaOccInst_oaOccVectorInstDef(const oaCollection_oaOccInst_oaOccVectorInstDef& coll)\n"
"    Signature: oaCollection_oaOccInst_oaOccVectorInstDef||cref-oaCollection_oaOccInst_oaOccVectorInstDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInst_oaOccVectorInstDef)\n"
"    Calls: (const oaCollection_oaOccInst_oaOccVectorInstDef&)\n"
"    Signature: oaCollection_oaOccInst_oaOccVectorInstDef||cref-oaCollection_oaOccInst_oaOccVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInst_oaOccVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInst_oaOccVectorInstDef",
    sizeof(PyoaCollection_oaOccInst_oaOccVectorInstDefObject),
    0,
    (destructor)oaCollection_oaOccInst_oaOccVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInst_oaOccVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInst_oaOccVectorInstDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInst_oaOccVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInst_oaOccVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInst_oaOccVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInst_oaOccVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInst_oaOccVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInst_oaOccVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInst_oaOccVectorInstDef",
           (PyObject*)(&PyoaCollection_oaOccInst_oaOccVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInst_oaOccVectorInstDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccInst_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccInst_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccInst_oaOccurrenceObject* self = (PyoaCollection_oaOccInst_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccInst_oaOccurrence)
    {
        PyParamoaCollection_oaOccInst_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccInst_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccInst_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccInst_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccInst_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccInst_oaOccurrence_tp_dealloc(PyoaCollection_oaOccInst_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccInst_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccInst_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccInst_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccInst_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaOccInst_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccInst_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccInst_oaOccurrence v1;
    PyParamoaCollection_oaOccInst_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccInst_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccInst_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccInst_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccInst_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccInst_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccInst_oaOccurrence*) ((PyoaCollection_oaOccInst_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccInst_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccInst_oaOccurrence_FromoaCollection_oaOccInst_oaOccurrence(oaCollection_oaOccInst_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccInst_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccInst_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccInst_oaOccurrenceObject* self = (PyoaCollection_oaOccInst_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccInst_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccInst_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccInst)\n"
"    Calls: oaBoolean includes(const oaOccInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccInst_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccInst_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccInst_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccInst_oaOccurrenceObject* self=(PyoaCollection_oaOccInst_oaOccurrenceObject*)ob;

    PyParamoaOccInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccInst_Convert,&p1)) {
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

static char oaCollection_oaOccInst_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccInst_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccInst_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccInst_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccInst_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccInst_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccInst_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccInst_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccInst_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccInst_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccInst_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccInst_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccInst_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccInst_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccInst_oaOccurrence)\n"
"    Calls: oaCollection_oaOccInst_oaOccurrence(const oaCollection_oaOccInst_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccInst_oaOccurrence||cref-oaCollection_oaOccInst_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccInst_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccInst_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccInst_oaOccurrence||cref-oaCollection_oaOccInst_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccInst_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccInst_oaOccurrence",
    sizeof(PyoaCollection_oaOccInst_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccInst_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccInst_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccInst_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccInst_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccInst_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccInst_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccInst_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccInst_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccInst_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccInst_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccInst_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccInst_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccModuleInstHeader_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccModuleInstHeader_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject* self = (PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccModuleInstHeader_oaOccurrence)
    {
        PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccModuleInstHeader_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccModuleInstHeader_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccModuleInstHeader_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_dealloc(PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccModuleInstHeader_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[69];
    sprintf(buffer,"<oaCollection_oaOccModuleInstHeader_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence v1;
    PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccModuleInstHeader_oaOccurrence*) ((PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccModuleInstHeader_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccModuleInstHeader_oaOccurrence_FromoaCollection_oaOccModuleInstHeader_oaOccurrence(oaCollection_oaOccModuleInstHeader_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject* self = (PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccModuleInstHeader_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccModuleInstHeader_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccModuleInstHeader)\n"
"    Calls: oaBoolean includes(const oaOccModuleInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccModuleInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccModuleInstHeader_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject* self=(PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject*)ob;

    PyParamoaOccModuleInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccModuleInstHeader_Convert,&p1)) {
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

static char oaCollection_oaOccModuleInstHeader_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccModuleInstHeader_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccModuleInstHeader_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccModuleInstHeader_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccModuleInstHeader_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccModuleInstHeader_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccModuleInstHeader_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccModuleInstHeader_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccModuleInstHeader_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccModuleInstHeader_oaOccurrence)\n"
"    Calls: oaCollection_oaOccModuleInstHeader_oaOccurrence(const oaCollection_oaOccModuleInstHeader_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccModuleInstHeader_oaOccurrence||cref-oaCollection_oaOccModuleInstHeader_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccModuleInstHeader_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccModuleInstHeader_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccModuleInstHeader_oaOccurrence||cref-oaCollection_oaOccModuleInstHeader_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccModuleInstHeader_oaOccurrence",
    sizeof(PyoaCollection_oaOccModuleInstHeader_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccModuleInstHeader_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccModuleInstHeader_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccModuleInstHeader_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccModuleInstHeader_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccModuleInstHeader_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccModuleInstHeader_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccModuleInstHeader_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccModuleInstHeader_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccModuleInstHeader_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject* self = (PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccModuleInst_oaOccModuleInstHeader)
    {
        PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccModuleInst_oaOccModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader, Choices are:\n"
        "    (oaCollection_oaOccModuleInst_oaOccModuleInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_dealloc(PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccModuleInst_oaOccModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader value;
    int convert_status=PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[72];
    sprintf(buffer,"<oaCollection_oaOccModuleInst_oaOccModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader v1;
    PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader v2;
    int convert_status1=PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaOccModuleInst_oaOccModuleInstHeader*) ((PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_FromoaCollection_oaOccModuleInst_oaOccModuleInstHeader(oaCollection_oaOccModuleInst_oaOccModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type.tp_alloc(&PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject* self = (PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject*)bself;
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
static char oaCollection_oaOccModuleInst_oaOccModuleInstHeader_includes_doc[] = 
"Class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader, Function: includes\n"
"  Paramegers: (oaOccModuleInst)\n"
"    Calls: oaBoolean includes(const oaOccModuleInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccModuleInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader data;
    int convert_status=PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject* self=(PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject*)ob;

    PyParamoaOccModuleInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccModuleInst_Convert,&p1)) {
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

static char oaCollection_oaOccModuleInst_oaOccModuleInstHeader_assign_doc[] = 
"Class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader data;
  int convert_status=PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccModuleInst_oaOccModuleInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccModuleInst_oaOccModuleInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccModuleInst_oaOccModuleInstHeader_includes,METH_VARARGS,oaCollection_oaOccModuleInst_oaOccModuleInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_assign,METH_VARARGS,oaCollection_oaOccModuleInst_oaOccModuleInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccModuleInst_oaOccModuleInstHeader_doc[] = 
"Class: oaCollection_oaOccModuleInst_oaOccModuleInstHeader\n"
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
"  Paramegers: (oaCollection_oaOccModuleInst_oaOccModuleInstHeader)\n"
"    Calls: oaCollection_oaOccModuleInst_oaOccModuleInstHeader(const oaCollection_oaOccModuleInst_oaOccModuleInstHeader& coll)\n"
"    Signature: oaCollection_oaOccModuleInst_oaOccModuleInstHeader||cref-oaCollection_oaOccModuleInst_oaOccModuleInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccModuleInst_oaOccModuleInstHeader)\n"
"    Calls: (const oaCollection_oaOccModuleInst_oaOccModuleInstHeader&)\n"
"    Signature: oaCollection_oaOccModuleInst_oaOccModuleInstHeader||cref-oaCollection_oaOccModuleInst_oaOccModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccModuleInst_oaOccModuleInstHeader",
    sizeof(PyoaCollection_oaOccModuleInst_oaOccModuleInstHeaderObject),
    0,
    (destructor)oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccModuleInst_oaOccModuleInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccModuleInst_oaOccModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccModuleInst_oaOccModuleInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccModuleInst_oaOccModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccModuleInst_oaOccModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccModuleInst_oaOccModuleInstHeader",
           (PyObject*)(&PyoaCollection_oaOccModuleInst_oaOccModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccModuleInst_oaOccModuleInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccNet_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccNet_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccNet_oaModNetObject* self = (PyoaCollection_oaOccNet_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccNet_oaModNet)
    {
        PyParamoaCollection_oaOccNet_oaModNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccNet_oaModNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccNet_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccNet_oaModNet, Choices are:\n"
        "    (oaCollection_oaOccNet_oaModNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccNet_oaModNet_tp_dealloc(PyoaCollection_oaOccNet_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccNet_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccNet_oaModNet value;
    int convert_status=PyoaCollection_oaOccNet_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaOccNet_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccNet_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccNet_oaModNet v1;
    PyParamoaCollection_oaOccNet_oaModNet v2;
    int convert_status1=PyoaCollection_oaOccNet_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccNet_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccNet_oaModNet_Convert(PyObject* ob,PyParamoaCollection_oaOccNet_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccNet_oaModNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccNet_oaModNet*) ((PyoaCollection_oaOccNet_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccNet_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccNet_oaModNet_FromoaCollection_oaOccNet_oaModNet(oaCollection_oaOccNet_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccNet_oaModNet_Type.tp_alloc(&PyoaCollection_oaOccNet_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccNet_oaModNetObject* self = (PyoaCollection_oaOccNet_oaModNetObject*)bself;
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
static char oaCollection_oaOccNet_oaModNet_includes_doc[] = 
"Class: oaCollection_oaOccNet_oaModNet, Function: includes\n"
"  Paramegers: (oaOccNet)\n"
"    Calls: oaBoolean includes(const oaOccNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccNet_oaModNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccNet_oaModNet data;
    int convert_status=PyoaCollection_oaOccNet_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccNet_oaModNetObject* self=(PyoaCollection_oaOccNet_oaModNetObject*)ob;

    PyParamoaOccNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccNet_Convert,&p1)) {
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

static char oaCollection_oaOccNet_oaModNet_assign_doc[] = 
"Class: oaCollection_oaOccNet_oaModNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccNet_oaModNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccNet_oaModNet data;
  int convert_status=PyoaCollection_oaOccNet_oaModNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccNet_oaModNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccNet_oaModNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccNet_oaModNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccNet_oaModNet_includes,METH_VARARGS,oaCollection_oaOccNet_oaModNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccNet_oaModNet_tp_assign,METH_VARARGS,oaCollection_oaOccNet_oaModNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccNet_oaModNet_doc[] = 
"Class: oaCollection_oaOccNet_oaModNet\n"
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
"  Paramegers: (oaCollection_oaOccNet_oaModNet)\n"
"    Calls: oaCollection_oaOccNet_oaModNet(const oaCollection_oaOccNet_oaModNet& coll)\n"
"    Signature: oaCollection_oaOccNet_oaModNet||cref-oaCollection_oaOccNet_oaModNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccNet_oaModNet)\n"
"    Calls: (const oaCollection_oaOccNet_oaModNet&)\n"
"    Signature: oaCollection_oaOccNet_oaModNet||cref-oaCollection_oaOccNet_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccNet_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccNet_oaModNet",
    sizeof(PyoaCollection_oaOccNet_oaModNetObject),
    0,
    (destructor)oaCollection_oaOccNet_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccNet_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccNet_oaModNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccNet_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccNet_oaModNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccNet_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccNet_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccNet_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccNet_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccNet_oaModNet",
           (PyObject*)(&PyoaCollection_oaOccNet_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccNet_oaModNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccNet_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccNet_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccNet_oaNetObject* self = (PyoaCollection_oaOccNet_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccNet_oaNet)
    {
        PyParamoaCollection_oaOccNet_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccNet_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccNet_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccNet_oaNet, Choices are:\n"
        "    (oaCollection_oaOccNet_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccNet_oaNet_tp_dealloc(PyoaCollection_oaOccNet_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccNet_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccNet_oaNet value;
    int convert_status=PyoaCollection_oaOccNet_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaOccNet_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccNet_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccNet_oaNet v1;
    PyParamoaCollection_oaOccNet_oaNet v2;
    int convert_status1=PyoaCollection_oaOccNet_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccNet_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccNet_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaOccNet_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccNet_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccNet_oaNet*) ((PyoaCollection_oaOccNet_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccNet_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccNet_oaNet_FromoaCollection_oaOccNet_oaNet(oaCollection_oaOccNet_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccNet_oaNet_Type.tp_alloc(&PyoaCollection_oaOccNet_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccNet_oaNetObject* self = (PyoaCollection_oaOccNet_oaNetObject*)bself;
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
static char oaCollection_oaOccNet_oaNet_includes_doc[] = 
"Class: oaCollection_oaOccNet_oaNet, Function: includes\n"
"  Paramegers: (oaOccNet)\n"
"    Calls: oaBoolean includes(const oaOccNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccNet_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccNet_oaNet data;
    int convert_status=PyoaCollection_oaOccNet_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccNet_oaNetObject* self=(PyoaCollection_oaOccNet_oaNetObject*)ob;

    PyParamoaOccNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccNet_Convert,&p1)) {
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

static char oaCollection_oaOccNet_oaNet_assign_doc[] = 
"Class: oaCollection_oaOccNet_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccNet_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccNet_oaNet data;
  int convert_status=PyoaCollection_oaOccNet_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccNet_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccNet_oaNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccNet_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccNet_oaNet_includes,METH_VARARGS,oaCollection_oaOccNet_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccNet_oaNet_tp_assign,METH_VARARGS,oaCollection_oaOccNet_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccNet_oaNet_doc[] = 
"Class: oaCollection_oaOccNet_oaNet\n"
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
"  Paramegers: (oaCollection_oaOccNet_oaNet)\n"
"    Calls: oaCollection_oaOccNet_oaNet(const oaCollection_oaOccNet_oaNet& coll)\n"
"    Signature: oaCollection_oaOccNet_oaNet||cref-oaCollection_oaOccNet_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccNet_oaNet)\n"
"    Calls: (const oaCollection_oaOccNet_oaNet&)\n"
"    Signature: oaCollection_oaOccNet_oaNet||cref-oaCollection_oaOccNet_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccNet_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccNet_oaNet",
    sizeof(PyoaCollection_oaOccNet_oaNetObject),
    0,
    (destructor)oaCollection_oaOccNet_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccNet_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccNet_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccNet_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccNet_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccNet_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccNet_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccNet_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccNet_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccNet_oaNet",
           (PyObject*)(&PyoaCollection_oaOccNet_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccNet_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccNet_oaOccBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccNet_oaOccBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccNet_oaOccBundleNetObject* self = (PyoaCollection_oaOccNet_oaOccBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccNet_oaOccBundleNet)
    {
        PyParamoaCollection_oaOccNet_oaOccBundleNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccNet_oaOccBundleNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccNet_oaOccBundleNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccNet_oaOccBundleNet, Choices are:\n"
        "    (oaCollection_oaOccNet_oaOccBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccNet_oaOccBundleNet_tp_dealloc(PyoaCollection_oaOccNet_oaOccBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccNet_oaOccBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccNet_oaOccBundleNet value;
    int convert_status=PyoaCollection_oaOccNet_oaOccBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaOccNet_oaOccBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccNet_oaOccBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccNet_oaOccBundleNet v1;
    PyParamoaCollection_oaOccNet_oaOccBundleNet v2;
    int convert_status1=PyoaCollection_oaOccNet_oaOccBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccNet_oaOccBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccNet_oaOccBundleNet_Convert(PyObject* ob,PyParamoaCollection_oaOccNet_oaOccBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccNet_oaOccBundleNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccNet_oaOccBundleNet*) ((PyoaCollection_oaOccNet_oaOccBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccNet_oaOccBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccNet_oaOccBundleNet_FromoaCollection_oaOccNet_oaOccBundleNet(oaCollection_oaOccNet_oaOccBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccNet_oaOccBundleNet_Type.tp_alloc(&PyoaCollection_oaOccNet_oaOccBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccNet_oaOccBundleNetObject* self = (PyoaCollection_oaOccNet_oaOccBundleNetObject*)bself;
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
static char oaCollection_oaOccNet_oaOccBundleNet_includes_doc[] = 
"Class: oaCollection_oaOccNet_oaOccBundleNet, Function: includes\n"
"  Paramegers: (oaOccNet)\n"
"    Calls: oaBoolean includes(const oaOccNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccBundleNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccNet_oaOccBundleNet data;
    int convert_status=PyoaCollection_oaOccNet_oaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccNet_oaOccBundleNetObject* self=(PyoaCollection_oaOccNet_oaOccBundleNetObject*)ob;

    PyParamoaOccNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccNet_Convert,&p1)) {
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

static char oaCollection_oaOccNet_oaOccBundleNet_assign_doc[] = 
"Class: oaCollection_oaOccNet_oaOccBundleNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccBundleNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccNet_oaOccBundleNet data;
  int convert_status=PyoaCollection_oaOccNet_oaOccBundleNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccNet_oaOccBundleNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccNet_oaOccBundleNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccNet_oaOccBundleNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccNet_oaOccBundleNet_includes,METH_VARARGS,oaCollection_oaOccNet_oaOccBundleNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccNet_oaOccBundleNet_tp_assign,METH_VARARGS,oaCollection_oaOccNet_oaOccBundleNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccNet_oaOccBundleNet_doc[] = 
"Class: oaCollection_oaOccNet_oaOccBundleNet\n"
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
"  Paramegers: (oaCollection_oaOccNet_oaOccBundleNet)\n"
"    Calls: oaCollection_oaOccNet_oaOccBundleNet(const oaCollection_oaOccNet_oaOccBundleNet& coll)\n"
"    Signature: oaCollection_oaOccNet_oaOccBundleNet||cref-oaCollection_oaOccNet_oaOccBundleNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccNet_oaOccBundleNet)\n"
"    Calls: (const oaCollection_oaOccNet_oaOccBundleNet&)\n"
"    Signature: oaCollection_oaOccNet_oaOccBundleNet||cref-oaCollection_oaOccNet_oaOccBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccNet_oaOccBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccNet_oaOccBundleNet",
    sizeof(PyoaCollection_oaOccNet_oaOccBundleNetObject),
    0,
    (destructor)oaCollection_oaOccNet_oaOccBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccNet_oaOccBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccNet_oaOccBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccNet_oaOccBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccNet_oaOccBundleNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccNet_oaOccBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccNet_oaOccBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccNet_oaOccBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccNet_oaOccBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccNet_oaOccBundleNet",
           (PyObject*)(&PyoaCollection_oaOccNet_oaOccBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccNet_oaOccBundleNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccNet_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccNet_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccNet_oaOccNetObject* self = (PyoaCollection_oaOccNet_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccNet_oaOccNet)
    {
        PyParamoaCollection_oaOccNet_oaOccNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccNet_oaOccNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccNet_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccNet_oaOccNet, Choices are:\n"
        "    (oaCollection_oaOccNet_oaOccNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccNet_oaOccNet_tp_dealloc(PyoaCollection_oaOccNet_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccNet_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccNet_oaOccNet value;
    int convert_status=PyoaCollection_oaOccNet_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaOccNet_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccNet_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccNet_oaOccNet v1;
    PyParamoaCollection_oaOccNet_oaOccNet v2;
    int convert_status1=PyoaCollection_oaOccNet_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccNet_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccNet_oaOccNet_Convert(PyObject* ob,PyParamoaCollection_oaOccNet_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccNet_oaOccNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccNet_oaOccNet*) ((PyoaCollection_oaOccNet_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccNet_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccNet_oaOccNet_FromoaCollection_oaOccNet_oaOccNet(oaCollection_oaOccNet_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccNet_oaOccNet_Type.tp_alloc(&PyoaCollection_oaOccNet_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccNet_oaOccNetObject* self = (PyoaCollection_oaOccNet_oaOccNetObject*)bself;
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
static char oaCollection_oaOccNet_oaOccNet_includes_doc[] = 
"Class: oaCollection_oaOccNet_oaOccNet, Function: includes\n"
"  Paramegers: (oaOccNet)\n"
"    Calls: oaBoolean includes(const oaOccNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccNet_oaOccNet data;
    int convert_status=PyoaCollection_oaOccNet_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccNet_oaOccNetObject* self=(PyoaCollection_oaOccNet_oaOccNetObject*)ob;

    PyParamoaOccNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccNet_Convert,&p1)) {
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

static char oaCollection_oaOccNet_oaOccNet_assign_doc[] = 
"Class: oaCollection_oaOccNet_oaOccNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccNet_oaOccNet data;
  int convert_status=PyoaCollection_oaOccNet_oaOccNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccNet_oaOccNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccNet_oaOccNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccNet_oaOccNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccNet_oaOccNet_includes,METH_VARARGS,oaCollection_oaOccNet_oaOccNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccNet_oaOccNet_tp_assign,METH_VARARGS,oaCollection_oaOccNet_oaOccNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccNet_oaOccNet_doc[] = 
"Class: oaCollection_oaOccNet_oaOccNet\n"
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
"  Paramegers: (oaCollection_oaOccNet_oaOccNet)\n"
"    Calls: oaCollection_oaOccNet_oaOccNet(const oaCollection_oaOccNet_oaOccNet& coll)\n"
"    Signature: oaCollection_oaOccNet_oaOccNet||cref-oaCollection_oaOccNet_oaOccNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccNet_oaOccNet)\n"
"    Calls: (const oaCollection_oaOccNet_oaOccNet&)\n"
"    Signature: oaCollection_oaOccNet_oaOccNet||cref-oaCollection_oaOccNet_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccNet_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccNet_oaOccNet",
    sizeof(PyoaCollection_oaOccNet_oaOccNetObject),
    0,
    (destructor)oaCollection_oaOccNet_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccNet_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccNet_oaOccNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccNet_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccNet_oaOccNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccNet_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccNet_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccNet_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccNet_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccNet_oaOccNet",
           (PyObject*)(&PyoaCollection_oaOccNet_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccNet_oaOccNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccNet_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccNet_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccNet_oaOccurrenceObject* self = (PyoaCollection_oaOccNet_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccNet_oaOccurrence)
    {
        PyParamoaCollection_oaOccNet_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccNet_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccNet_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccNet_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccNet_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccNet_oaOccurrence_tp_dealloc(PyoaCollection_oaOccNet_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccNet_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccNet_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccNet_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccNet_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaOccNet_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccNet_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccNet_oaOccurrence v1;
    PyParamoaCollection_oaOccNet_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccNet_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccNet_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccNet_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccNet_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccNet_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccNet_oaOccurrence*) ((PyoaCollection_oaOccNet_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccNet_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccNet_oaOccurrence_FromoaCollection_oaOccNet_oaOccurrence(oaCollection_oaOccNet_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccNet_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccNet_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccNet_oaOccurrenceObject* self = (PyoaCollection_oaOccNet_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccNet_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccNet_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccNet)\n"
"    Calls: oaBoolean includes(const oaOccNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccNet_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccNet_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccNet_oaOccurrenceObject* self=(PyoaCollection_oaOccNet_oaOccurrenceObject*)ob;

    PyParamoaOccNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccNet_Convert,&p1)) {
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

static char oaCollection_oaOccNet_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccNet_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccNet_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccNet_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccNet_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccNet_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccNet_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccNet_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccNet_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccNet_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccNet_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccNet_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccNet_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccNet_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccNet_oaOccurrence)\n"
"    Calls: oaCollection_oaOccNet_oaOccurrence(const oaCollection_oaOccNet_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccNet_oaOccurrence||cref-oaCollection_oaOccNet_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccNet_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccNet_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccNet_oaOccurrence||cref-oaCollection_oaOccNet_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccNet_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccNet_oaOccurrence",
    sizeof(PyoaCollection_oaOccNet_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccNet_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccNet_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccNet_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccNet_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccNet_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccNet_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccNet_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccNet_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccNet_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccNet_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccNet_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccNet_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccTerm_oaModTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaModTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccTerm_oaModTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccTerm_oaModTermObject* self = (PyoaCollection_oaOccTerm_oaModTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccTerm_oaModTerm)
    {
        PyParamoaCollection_oaOccTerm_oaModTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccTerm_oaModTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccTerm_oaModTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccTerm_oaModTerm, Choices are:\n"
        "    (oaCollection_oaOccTerm_oaModTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccTerm_oaModTerm_tp_dealloc(PyoaCollection_oaOccTerm_oaModTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccTerm_oaModTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaModTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccTerm_oaModTerm value;
    int convert_status=PyoaCollection_oaOccTerm_oaModTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaOccTerm_oaModTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccTerm_oaModTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccTerm_oaModTerm v1;
    PyParamoaCollection_oaOccTerm_oaModTerm v2;
    int convert_status1=PyoaCollection_oaOccTerm_oaModTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccTerm_oaModTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccTerm_oaModTerm_Convert(PyObject* ob,PyParamoaCollection_oaOccTerm_oaModTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccTerm_oaModTerm_Check(ob)) {
        result->SetData( (oaCollection_oaOccTerm_oaModTerm*) ((PyoaCollection_oaOccTerm_oaModTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccTerm_oaModTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccTerm_oaModTerm_FromoaCollection_oaOccTerm_oaModTerm(oaCollection_oaOccTerm_oaModTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccTerm_oaModTerm_Type.tp_alloc(&PyoaCollection_oaOccTerm_oaModTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccTerm_oaModTermObject* self = (PyoaCollection_oaOccTerm_oaModTermObject*)bself;
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
static char oaCollection_oaOccTerm_oaModTerm_includes_doc[] = 
"Class: oaCollection_oaOccTerm_oaModTerm, Function: includes\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaBoolean includes(const oaOccTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaModTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccTerm_oaModTerm data;
    int convert_status=PyoaCollection_oaOccTerm_oaModTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccTerm_oaModTermObject* self=(PyoaCollection_oaOccTerm_oaModTermObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
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

static char oaCollection_oaOccTerm_oaModTerm_assign_doc[] = 
"Class: oaCollection_oaOccTerm_oaModTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaModTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccTerm_oaModTerm data;
  int convert_status=PyoaCollection_oaOccTerm_oaModTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccTerm_oaModTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccTerm_oaModTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccTerm_oaModTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccTerm_oaModTerm_includes,METH_VARARGS,oaCollection_oaOccTerm_oaModTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccTerm_oaModTerm_tp_assign,METH_VARARGS,oaCollection_oaOccTerm_oaModTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccTerm_oaModTerm_doc[] = 
"Class: oaCollection_oaOccTerm_oaModTerm\n"
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
"  Paramegers: (oaCollection_oaOccTerm_oaModTerm)\n"
"    Calls: oaCollection_oaOccTerm_oaModTerm(const oaCollection_oaOccTerm_oaModTerm& coll)\n"
"    Signature: oaCollection_oaOccTerm_oaModTerm||cref-oaCollection_oaOccTerm_oaModTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccTerm_oaModTerm)\n"
"    Calls: (const oaCollection_oaOccTerm_oaModTerm&)\n"
"    Signature: oaCollection_oaOccTerm_oaModTerm||cref-oaCollection_oaOccTerm_oaModTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccTerm_oaModTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccTerm_oaModTerm",
    sizeof(PyoaCollection_oaOccTerm_oaModTermObject),
    0,
    (destructor)oaCollection_oaOccTerm_oaModTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccTerm_oaModTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccTerm_oaModTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccTerm_oaModTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccTerm_oaModTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccTerm_oaModTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccTerm_oaModTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccTerm_oaModTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccTerm_oaModTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccTerm_oaModTerm",
           (PyObject*)(&PyoaCollection_oaOccTerm_oaModTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccTerm_oaModTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccTerm_oaOccBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccTerm_oaOccBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccTerm_oaOccBundleTermObject* self = (PyoaCollection_oaOccTerm_oaOccBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccTerm_oaOccBundleTerm)
    {
        PyParamoaCollection_oaOccTerm_oaOccBundleTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccTerm_oaOccBundleTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccTerm_oaOccBundleTerm, Choices are:\n"
        "    (oaCollection_oaOccTerm_oaOccBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccTerm_oaOccBundleTerm_tp_dealloc(PyoaCollection_oaOccTerm_oaOccBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccTerm_oaOccBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccTerm_oaOccBundleTerm value;
    int convert_status=PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaOccTerm_oaOccBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccTerm_oaOccBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccTerm_oaOccBundleTerm v1;
    PyParamoaCollection_oaOccTerm_oaOccBundleTerm v2;
    int convert_status1=PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(PyObject* ob,PyParamoaCollection_oaOccTerm_oaOccBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccTerm_oaOccBundleTerm_Check(ob)) {
        result->SetData( (oaCollection_oaOccTerm_oaOccBundleTerm*) ((PyoaCollection_oaOccTerm_oaOccBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccTerm_oaOccBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccTerm_oaOccBundleTerm_FromoaCollection_oaOccTerm_oaOccBundleTerm(oaCollection_oaOccTerm_oaOccBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccTerm_oaOccBundleTerm_Type.tp_alloc(&PyoaCollection_oaOccTerm_oaOccBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccTerm_oaOccBundleTermObject* self = (PyoaCollection_oaOccTerm_oaOccBundleTermObject*)bself;
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
static char oaCollection_oaOccTerm_oaOccBundleTerm_includes_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccBundleTerm, Function: includes\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaBoolean includes(const oaOccTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccBundleTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccTerm_oaOccBundleTerm data;
    int convert_status=PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccTerm_oaOccBundleTermObject* self=(PyoaCollection_oaOccTerm_oaOccBundleTermObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
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

static char oaCollection_oaOccTerm_oaOccBundleTerm_assign_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccBundleTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccBundleTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccTerm_oaOccBundleTerm data;
  int convert_status=PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccTerm_oaOccBundleTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccTerm_oaOccBundleTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccTerm_oaOccBundleTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccTerm_oaOccBundleTerm_includes,METH_VARARGS,oaCollection_oaOccTerm_oaOccBundleTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccTerm_oaOccBundleTerm_tp_assign,METH_VARARGS,oaCollection_oaOccTerm_oaOccBundleTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccTerm_oaOccBundleTerm_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccBundleTerm\n"
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
"  Paramegers: (oaCollection_oaOccTerm_oaOccBundleTerm)\n"
"    Calls: oaCollection_oaOccTerm_oaOccBundleTerm(const oaCollection_oaOccTerm_oaOccBundleTerm& coll)\n"
"    Signature: oaCollection_oaOccTerm_oaOccBundleTerm||cref-oaCollection_oaOccTerm_oaOccBundleTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccTerm_oaOccBundleTerm)\n"
"    Calls: (const oaCollection_oaOccTerm_oaOccBundleTerm&)\n"
"    Signature: oaCollection_oaOccTerm_oaOccBundleTerm||cref-oaCollection_oaOccTerm_oaOccBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccTerm_oaOccBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccTerm_oaOccBundleTerm",
    sizeof(PyoaCollection_oaOccTerm_oaOccBundleTermObject),
    0,
    (destructor)oaCollection_oaOccTerm_oaOccBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccTerm_oaOccBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccTerm_oaOccBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccTerm_oaOccBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccTerm_oaOccBundleTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccTerm_oaOccBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccTerm_oaOccBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccTerm_oaOccBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccTerm_oaOccBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccTerm_oaOccBundleTerm",
           (PyObject*)(&PyoaCollection_oaOccTerm_oaOccBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccTerm_oaOccBundleTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccTerm_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccTerm_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccTerm_oaOccNetObject* self = (PyoaCollection_oaOccTerm_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccTerm_oaOccNet)
    {
        PyParamoaCollection_oaOccTerm_oaOccNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccTerm_oaOccNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccTerm_oaOccNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccTerm_oaOccNet, Choices are:\n"
        "    (oaCollection_oaOccTerm_oaOccNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccTerm_oaOccNet_tp_dealloc(PyoaCollection_oaOccTerm_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccTerm_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccTerm_oaOccNet value;
    int convert_status=PyoaCollection_oaOccTerm_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaOccTerm_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccTerm_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccTerm_oaOccNet v1;
    PyParamoaCollection_oaOccTerm_oaOccNet v2;
    int convert_status1=PyoaCollection_oaOccTerm_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccTerm_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccTerm_oaOccNet_Convert(PyObject* ob,PyParamoaCollection_oaOccTerm_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccTerm_oaOccNet_Check(ob)) {
        result->SetData( (oaCollection_oaOccTerm_oaOccNet*) ((PyoaCollection_oaOccTerm_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccTerm_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccTerm_oaOccNet_FromoaCollection_oaOccTerm_oaOccNet(oaCollection_oaOccTerm_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccTerm_oaOccNet_Type.tp_alloc(&PyoaCollection_oaOccTerm_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccTerm_oaOccNetObject* self = (PyoaCollection_oaOccTerm_oaOccNetObject*)bself;
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
static char oaCollection_oaOccTerm_oaOccNet_includes_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccNet, Function: includes\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaBoolean includes(const oaOccTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccTerm_oaOccNet data;
    int convert_status=PyoaCollection_oaOccTerm_oaOccNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccTerm_oaOccNetObject* self=(PyoaCollection_oaOccTerm_oaOccNetObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
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

static char oaCollection_oaOccTerm_oaOccNet_assign_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccTerm_oaOccNet data;
  int convert_status=PyoaCollection_oaOccTerm_oaOccNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccTerm_oaOccNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccTerm_oaOccNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccTerm_oaOccNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccTerm_oaOccNet_includes,METH_VARARGS,oaCollection_oaOccTerm_oaOccNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccTerm_oaOccNet_tp_assign,METH_VARARGS,oaCollection_oaOccTerm_oaOccNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccTerm_oaOccNet_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccNet\n"
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
"  Paramegers: (oaCollection_oaOccTerm_oaOccNet)\n"
"    Calls: oaCollection_oaOccTerm_oaOccNet(const oaCollection_oaOccTerm_oaOccNet& coll)\n"
"    Signature: oaCollection_oaOccTerm_oaOccNet||cref-oaCollection_oaOccTerm_oaOccNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccTerm_oaOccNet)\n"
"    Calls: (const oaCollection_oaOccTerm_oaOccNet&)\n"
"    Signature: oaCollection_oaOccTerm_oaOccNet||cref-oaCollection_oaOccTerm_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccTerm_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccTerm_oaOccNet",
    sizeof(PyoaCollection_oaOccTerm_oaOccNetObject),
    0,
    (destructor)oaCollection_oaOccTerm_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccTerm_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccTerm_oaOccNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccTerm_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccTerm_oaOccNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccTerm_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccTerm_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccTerm_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccTerm_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccTerm_oaOccNet",
           (PyObject*)(&PyoaCollection_oaOccTerm_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccTerm_oaOccNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccTerm_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccTerm_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccTerm_oaOccurrenceObject* self = (PyoaCollection_oaOccTerm_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccTerm_oaOccurrence)
    {
        PyParamoaCollection_oaOccTerm_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccTerm_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccTerm_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccTerm_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccTerm_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccTerm_oaOccurrence_tp_dealloc(PyoaCollection_oaOccTerm_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccTerm_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccTerm_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccTerm_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaOccTerm_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccTerm_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccTerm_oaOccurrence v1;
    PyParamoaCollection_oaOccTerm_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccTerm_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccTerm_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccTerm_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccTerm_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccTerm_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccTerm_oaOccurrence*) ((PyoaCollection_oaOccTerm_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccTerm_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccTerm_oaOccurrence_FromoaCollection_oaOccTerm_oaOccurrence(oaCollection_oaOccTerm_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccTerm_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccTerm_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccTerm_oaOccurrenceObject* self = (PyoaCollection_oaOccTerm_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccTerm_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaBoolean includes(const oaOccTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccTerm_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccTerm_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccTerm_oaOccurrenceObject* self=(PyoaCollection_oaOccTerm_oaOccurrenceObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
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

static char oaCollection_oaOccTerm_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccTerm_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccTerm_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccTerm_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccTerm_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccTerm_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccTerm_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccTerm_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccTerm_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccTerm_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccTerm_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccTerm_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccTerm_oaOccurrence)\n"
"    Calls: oaCollection_oaOccTerm_oaOccurrence(const oaCollection_oaOccTerm_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccTerm_oaOccurrence||cref-oaCollection_oaOccTerm_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccTerm_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccTerm_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccTerm_oaOccurrence||cref-oaCollection_oaOccTerm_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccTerm_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccTerm_oaOccurrence",
    sizeof(PyoaCollection_oaOccTerm_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccTerm_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccTerm_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccTerm_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccTerm_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccTerm_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccTerm_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccTerm_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccTerm_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccTerm_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccTerm_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccTerm_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccTerm_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccTerm_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccTerm_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccTerm_oaTermObject* self = (PyoaCollection_oaOccTerm_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccTerm_oaTerm)
    {
        PyParamoaCollection_oaOccTerm_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccTerm_oaTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccTerm_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccTerm_oaTerm, Choices are:\n"
        "    (oaCollection_oaOccTerm_oaTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccTerm_oaTerm_tp_dealloc(PyoaCollection_oaOccTerm_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccTerm_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccTerm_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccTerm_oaTerm value;
    int convert_status=PyoaCollection_oaOccTerm_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaOccTerm_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccTerm_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccTerm_oaTerm v1;
    PyParamoaCollection_oaOccTerm_oaTerm v2;
    int convert_status1=PyoaCollection_oaOccTerm_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccTerm_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccTerm_oaTerm_Convert(PyObject* ob,PyParamoaCollection_oaOccTerm_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccTerm_oaTerm_Check(ob)) {
        result->SetData( (oaCollection_oaOccTerm_oaTerm*) ((PyoaCollection_oaOccTerm_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccTerm_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccTerm_oaTerm_FromoaCollection_oaOccTerm_oaTerm(oaCollection_oaOccTerm_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccTerm_oaTerm_Type.tp_alloc(&PyoaCollection_oaOccTerm_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccTerm_oaTermObject* self = (PyoaCollection_oaOccTerm_oaTermObject*)bself;
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
static char oaCollection_oaOccTerm_oaTerm_includes_doc[] = 
"Class: oaCollection_oaOccTerm_oaTerm, Function: includes\n"
"  Paramegers: (oaOccTerm)\n"
"    Calls: oaBoolean includes(const oaOccTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccTerm_oaTerm data;
    int convert_status=PyoaCollection_oaOccTerm_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccTerm_oaTermObject* self=(PyoaCollection_oaOccTerm_oaTermObject*)ob;

    PyParamoaOccTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccTerm_Convert,&p1)) {
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

static char oaCollection_oaOccTerm_oaTerm_assign_doc[] = 
"Class: oaCollection_oaOccTerm_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccTerm_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccTerm_oaTerm data;
  int convert_status=PyoaCollection_oaOccTerm_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccTerm_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccTerm_oaTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccTerm_oaTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccTerm_oaTerm_includes,METH_VARARGS,oaCollection_oaOccTerm_oaTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccTerm_oaTerm_tp_assign,METH_VARARGS,oaCollection_oaOccTerm_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccTerm_oaTerm_doc[] = 
"Class: oaCollection_oaOccTerm_oaTerm\n"
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
"  Paramegers: (oaCollection_oaOccTerm_oaTerm)\n"
"    Calls: oaCollection_oaOccTerm_oaTerm(const oaCollection_oaOccTerm_oaTerm& coll)\n"
"    Signature: oaCollection_oaOccTerm_oaTerm||cref-oaCollection_oaOccTerm_oaTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccTerm_oaTerm)\n"
"    Calls: (const oaCollection_oaOccTerm_oaTerm&)\n"
"    Signature: oaCollection_oaOccTerm_oaTerm||cref-oaCollection_oaOccTerm_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccTerm_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccTerm_oaTerm",
    sizeof(PyoaCollection_oaOccTerm_oaTermObject),
    0,
    (destructor)oaCollection_oaOccTerm_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccTerm_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccTerm_oaTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccTerm_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccTerm_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccTerm_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccTerm_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccTerm_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccTerm_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccTerm_oaTerm",
           (PyObject*)(&PyoaCollection_oaOccTerm_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccTerm_oaTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccVectorInstDef_oaOccurrence
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccVectorInstDef_oaOccurrence_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject* self = (PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccVectorInstDef_oaOccurrence)
    {
        PyParamoaCollection_oaOccVectorInstDef_oaOccurrence p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccVectorInstDef_oaOccurrence(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccVectorInstDef_oaOccurrence, Choices are:\n"
        "    (oaCollection_oaOccVectorInstDef_oaOccurrence)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccVectorInstDef_oaOccurrence_tp_dealloc(PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccVectorInstDef_oaOccurrence*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccVectorInstDef_oaOccurrence_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccVectorInstDef_oaOccurrence value;
    int convert_status=PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaOccVectorInstDef_oaOccurrence::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccVectorInstDef_oaOccurrence_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccVectorInstDef_oaOccurrence v1;
    PyParamoaCollection_oaOccVectorInstDef_oaOccurrence v2;
    int convert_status1=PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(PyObject* ob,PyParamoaCollection_oaOccVectorInstDef_oaOccurrence* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccVectorInstDef_oaOccurrence_Check(ob)) {
        result->SetData( (oaCollection_oaOccVectorInstDef_oaOccurrence*) ((PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccVectorInstDef_oaOccurrence Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccVectorInstDef_oaOccurrence_FromoaCollection_oaOccVectorInstDef_oaOccurrence(oaCollection_oaOccVectorInstDef_oaOccurrence* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type.tp_alloc(&PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject* self = (PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject*)bself;
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
static char oaCollection_oaOccVectorInstDef_oaOccurrence_includes_doc[] = 
"Class: oaCollection_oaOccVectorInstDef_oaOccurrence, Function: includes\n"
"  Paramegers: (oaOccVectorInstDef)\n"
"    Calls: oaBoolean includes(const oaOccVectorInstDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccVectorInstDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccVectorInstDef_oaOccurrence_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccVectorInstDef_oaOccurrence data;
    int convert_status=PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject* self=(PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject*)ob;

    PyParamoaOccVectorInstDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccVectorInstDef_Convert,&p1)) {
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

static char oaCollection_oaOccVectorInstDef_oaOccurrence_assign_doc[] = 
"Class: oaCollection_oaOccVectorInstDef_oaOccurrence, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccVectorInstDef_oaOccurrence_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccVectorInstDef_oaOccurrence data;
  int convert_status=PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccVectorInstDef_oaOccurrence p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccVectorInstDef_oaOccurrence_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccVectorInstDef_oaOccurrence_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccVectorInstDef_oaOccurrence_includes,METH_VARARGS,oaCollection_oaOccVectorInstDef_oaOccurrence_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccVectorInstDef_oaOccurrence_tp_assign,METH_VARARGS,oaCollection_oaOccVectorInstDef_oaOccurrence_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccVectorInstDef_oaOccurrence_doc[] = 
"Class: oaCollection_oaOccVectorInstDef_oaOccurrence\n"
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
"  Paramegers: (oaCollection_oaOccVectorInstDef_oaOccurrence)\n"
"    Calls: oaCollection_oaOccVectorInstDef_oaOccurrence(const oaCollection_oaOccVectorInstDef_oaOccurrence& coll)\n"
"    Signature: oaCollection_oaOccVectorInstDef_oaOccurrence||cref-oaCollection_oaOccVectorInstDef_oaOccurrence,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccVectorInstDef_oaOccurrence)\n"
"    Calls: (const oaCollection_oaOccVectorInstDef_oaOccurrence&)\n"
"    Signature: oaCollection_oaOccVectorInstDef_oaOccurrence||cref-oaCollection_oaOccVectorInstDef_oaOccurrence,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccVectorInstDef_oaOccurrence",
    sizeof(PyoaCollection_oaOccVectorInstDef_oaOccurrenceObject),
    0,
    (destructor)oaCollection_oaOccVectorInstDef_oaOccurrence_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccVectorInstDef_oaOccurrence_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccVectorInstDef_oaOccurrence_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccVectorInstDef_oaOccurrence_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccVectorInstDef_oaOccurrence_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccVectorInstDef_oaOccurrence_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccVectorInstDef_oaOccurrence_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccVectorInstDef_oaOccurrence\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccVectorInstDef_oaOccurrence",
           (PyObject*)(&PyoaCollection_oaOccVectorInstDef_oaOccurrence_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccVectorInstDef_oaOccurrence\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOccurrence_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccurrence_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOccurrence_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOccurrence_oaModuleObject* self = (PyoaCollection_oaOccurrence_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOccurrence_oaModule)
    {
        PyParamoaCollection_oaOccurrence_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOccurrence_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOccurrence_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOccurrence_oaModule, Choices are:\n"
        "    (oaCollection_oaOccurrence_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOccurrence_oaModule_tp_dealloc(PyoaCollection_oaOccurrence_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOccurrence_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOccurrence_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOccurrence_oaModule value;
    int convert_status=PyoaCollection_oaOccurrence_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaOccurrence_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOccurrence_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOccurrence_oaModule v1;
    PyParamoaCollection_oaOccurrence_oaModule v2;
    int convert_status1=PyoaCollection_oaOccurrence_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOccurrence_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOccurrence_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaOccurrence_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOccurrence_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaOccurrence_oaModule*) ((PyoaCollection_oaOccurrence_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOccurrence_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOccurrence_oaModule_FromoaCollection_oaOccurrence_oaModule(oaCollection_oaOccurrence_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOccurrence_oaModule_Type.tp_alloc(&PyoaCollection_oaOccurrence_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOccurrence_oaModuleObject* self = (PyoaCollection_oaOccurrence_oaModuleObject*)bself;
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
static char oaCollection_oaOccurrence_oaModule_includes_doc[] = 
"Class: oaCollection_oaOccurrence_oaModule, Function: includes\n"
"  Paramegers: (oaOccurrence)\n"
"    Calls: oaBoolean includes(const oaOccurrence* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOccurrence,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOccurrence_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOccurrence_oaModule data;
    int convert_status=PyoaCollection_oaOccurrence_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOccurrence_oaModuleObject* self=(PyoaCollection_oaOccurrence_oaModuleObject*)ob;

    PyParamoaOccurrence p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccurrence_Convert,&p1)) {
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

static char oaCollection_oaOccurrence_oaModule_assign_doc[] = 
"Class: oaCollection_oaOccurrence_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOccurrence_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOccurrence_oaModule data;
  int convert_status=PyoaCollection_oaOccurrence_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOccurrence_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOccurrence_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOccurrence_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOccurrence_oaModule_includes,METH_VARARGS,oaCollection_oaOccurrence_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOccurrence_oaModule_tp_assign,METH_VARARGS,oaCollection_oaOccurrence_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOccurrence_oaModule_doc[] = 
"Class: oaCollection_oaOccurrence_oaModule\n"
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
"  Paramegers: (oaCollection_oaOccurrence_oaModule)\n"
"    Calls: oaCollection_oaOccurrence_oaModule(const oaCollection_oaOccurrence_oaModule& coll)\n"
"    Signature: oaCollection_oaOccurrence_oaModule||cref-oaCollection_oaOccurrence_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOccurrence_oaModule)\n"
"    Calls: (const oaCollection_oaOccurrence_oaModule&)\n"
"    Signature: oaCollection_oaOccurrence_oaModule||cref-oaCollection_oaOccurrence_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOccurrence_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOccurrence_oaModule",
    sizeof(PyoaCollection_oaOccurrence_oaModuleObject),
    0,
    (destructor)oaCollection_oaOccurrence_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOccurrence_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOccurrence_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOccurrence_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOccurrence_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOccurrence_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOccurrence_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOccurrence_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOccurrence_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOccurrence_oaModule",
           (PyObject*)(&PyoaCollection_oaOccurrence_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOccurrence_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOpPointHeader_oaOpPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPointHeader_oaOpPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOpPointHeader_oaOpPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOpPointHeader_oaOpPointObject* self = (PyoaCollection_oaOpPointHeader_oaOpPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOpPointHeader_oaOpPoint)
    {
        PyParamoaCollection_oaOpPointHeader_oaOpPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOpPointHeader_oaOpPoint_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOpPointHeader_oaOpPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOpPointHeader_oaOpPoint, Choices are:\n"
        "    (oaCollection_oaOpPointHeader_oaOpPoint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOpPointHeader_oaOpPoint_tp_dealloc(PyoaCollection_oaOpPointHeader_oaOpPointObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOpPointHeader_oaOpPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPointHeader_oaOpPoint_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOpPointHeader_oaOpPoint value;
    int convert_status=PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaOpPointHeader_oaOpPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOpPointHeader_oaOpPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOpPointHeader_oaOpPoint v1;
    PyParamoaCollection_oaOpPointHeader_oaOpPoint v2;
    int convert_status1=PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(PyObject* ob,PyParamoaCollection_oaOpPointHeader_oaOpPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOpPointHeader_oaOpPoint_Check(ob)) {
        result->SetData( (oaCollection_oaOpPointHeader_oaOpPoint*) ((PyoaCollection_oaOpPointHeader_oaOpPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOpPointHeader_oaOpPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOpPointHeader_oaOpPoint_FromoaCollection_oaOpPointHeader_oaOpPoint(oaCollection_oaOpPointHeader_oaOpPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOpPointHeader_oaOpPoint_Type.tp_alloc(&PyoaCollection_oaOpPointHeader_oaOpPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOpPointHeader_oaOpPointObject* self = (PyoaCollection_oaOpPointHeader_oaOpPointObject*)bself;
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
static char oaCollection_oaOpPointHeader_oaOpPoint_includes_doc[] = 
"Class: oaCollection_oaOpPointHeader_oaOpPoint, Function: includes\n"
"  Paramegers: (oaOpPointHeader)\n"
"    Calls: oaBoolean includes(const oaOpPointHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOpPointHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOpPointHeader_oaOpPoint_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOpPointHeader_oaOpPoint data;
    int convert_status=PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOpPointHeader_oaOpPointObject* self=(PyoaCollection_oaOpPointHeader_oaOpPointObject*)ob;

    PyParamoaOpPointHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOpPointHeader_Convert,&p1)) {
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

static char oaCollection_oaOpPointHeader_oaOpPoint_assign_doc[] = 
"Class: oaCollection_oaOpPointHeader_oaOpPoint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOpPointHeader_oaOpPoint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOpPointHeader_oaOpPoint data;
  int convert_status=PyoaCollection_oaOpPointHeader_oaOpPoint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOpPointHeader_oaOpPoint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOpPointHeader_oaOpPoint_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOpPointHeader_oaOpPoint_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOpPointHeader_oaOpPoint_includes,METH_VARARGS,oaCollection_oaOpPointHeader_oaOpPoint_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOpPointHeader_oaOpPoint_tp_assign,METH_VARARGS,oaCollection_oaOpPointHeader_oaOpPoint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOpPointHeader_oaOpPoint_doc[] = 
"Class: oaCollection_oaOpPointHeader_oaOpPoint\n"
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
"  Paramegers: (oaCollection_oaOpPointHeader_oaOpPoint)\n"
"    Calls: oaCollection_oaOpPointHeader_oaOpPoint(const oaCollection_oaOpPointHeader_oaOpPoint& coll)\n"
"    Signature: oaCollection_oaOpPointHeader_oaOpPoint||cref-oaCollection_oaOpPointHeader_oaOpPoint,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOpPointHeader_oaOpPoint)\n"
"    Calls: (const oaCollection_oaOpPointHeader_oaOpPoint&)\n"
"    Signature: oaCollection_oaOpPointHeader_oaOpPoint||cref-oaCollection_oaOpPointHeader_oaOpPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOpPointHeader_oaOpPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOpPointHeader_oaOpPoint",
    sizeof(PyoaCollection_oaOpPointHeader_oaOpPointObject),
    0,
    (destructor)oaCollection_oaOpPointHeader_oaOpPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOpPointHeader_oaOpPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOpPointHeader_oaOpPoint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOpPointHeader_oaOpPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOpPointHeader_oaOpPoint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOpPointHeader_oaOpPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOpPointHeader_oaOpPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOpPointHeader_oaOpPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOpPointHeader_oaOpPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOpPointHeader_oaOpPoint",
           (PyObject*)(&PyoaCollection_oaOpPointHeader_oaOpPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOpPointHeader_oaOpPoint\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOpPoint_oaAnalysisLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPoint_oaAnalysisLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOpPoint_oaAnalysisLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOpPoint_oaAnalysisLibObject* self = (PyoaCollection_oaOpPoint_oaAnalysisLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOpPoint_oaAnalysisLib)
    {
        PyParamoaCollection_oaOpPoint_oaAnalysisLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOpPoint_oaAnalysisLib_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOpPoint_oaAnalysisLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOpPoint_oaAnalysisLib, Choices are:\n"
        "    (oaCollection_oaOpPoint_oaAnalysisLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOpPoint_oaAnalysisLib_tp_dealloc(PyoaCollection_oaOpPoint_oaAnalysisLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOpPoint_oaAnalysisLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPoint_oaAnalysisLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOpPoint_oaAnalysisLib value;
    int convert_status=PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaOpPoint_oaAnalysisLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOpPoint_oaAnalysisLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOpPoint_oaAnalysisLib v1;
    PyParamoaCollection_oaOpPoint_oaAnalysisLib v2;
    int convert_status1=PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(PyObject* ob,PyParamoaCollection_oaOpPoint_oaAnalysisLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOpPoint_oaAnalysisLib_Check(ob)) {
        result->SetData( (oaCollection_oaOpPoint_oaAnalysisLib*) ((PyoaCollection_oaOpPoint_oaAnalysisLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOpPoint_oaAnalysisLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOpPoint_oaAnalysisLib_FromoaCollection_oaOpPoint_oaAnalysisLib(oaCollection_oaOpPoint_oaAnalysisLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOpPoint_oaAnalysisLib_Type.tp_alloc(&PyoaCollection_oaOpPoint_oaAnalysisLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOpPoint_oaAnalysisLibObject* self = (PyoaCollection_oaOpPoint_oaAnalysisLibObject*)bself;
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
static char oaCollection_oaOpPoint_oaAnalysisLib_includes_doc[] = 
"Class: oaCollection_oaOpPoint_oaAnalysisLib, Function: includes\n"
"  Paramegers: (oaOpPoint)\n"
"    Calls: oaBoolean includes(const oaOpPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOpPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOpPoint_oaAnalysisLib_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOpPoint_oaAnalysisLib data;
    int convert_status=PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOpPoint_oaAnalysisLibObject* self=(PyoaCollection_oaOpPoint_oaAnalysisLibObject*)ob;

    PyParamoaOpPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOpPoint_Convert,&p1)) {
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

static char oaCollection_oaOpPoint_oaAnalysisLib_assign_doc[] = 
"Class: oaCollection_oaOpPoint_oaAnalysisLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOpPoint_oaAnalysisLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOpPoint_oaAnalysisLib data;
  int convert_status=PyoaCollection_oaOpPoint_oaAnalysisLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOpPoint_oaAnalysisLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOpPoint_oaAnalysisLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOpPoint_oaAnalysisLib_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOpPoint_oaAnalysisLib_includes,METH_VARARGS,oaCollection_oaOpPoint_oaAnalysisLib_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOpPoint_oaAnalysisLib_tp_assign,METH_VARARGS,oaCollection_oaOpPoint_oaAnalysisLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOpPoint_oaAnalysisLib_doc[] = 
"Class: oaCollection_oaOpPoint_oaAnalysisLib\n"
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
"  Paramegers: (oaCollection_oaOpPoint_oaAnalysisLib)\n"
"    Calls: oaCollection_oaOpPoint_oaAnalysisLib(const oaCollection_oaOpPoint_oaAnalysisLib& coll)\n"
"    Signature: oaCollection_oaOpPoint_oaAnalysisLib||cref-oaCollection_oaOpPoint_oaAnalysisLib,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOpPoint_oaAnalysisLib)\n"
"    Calls: (const oaCollection_oaOpPoint_oaAnalysisLib&)\n"
"    Signature: oaCollection_oaOpPoint_oaAnalysisLib||cref-oaCollection_oaOpPoint_oaAnalysisLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOpPoint_oaAnalysisLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOpPoint_oaAnalysisLib",
    sizeof(PyoaCollection_oaOpPoint_oaAnalysisLibObject),
    0,
    (destructor)oaCollection_oaOpPoint_oaAnalysisLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOpPoint_oaAnalysisLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOpPoint_oaAnalysisLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOpPoint_oaAnalysisLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOpPoint_oaAnalysisLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOpPoint_oaAnalysisLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOpPoint_oaAnalysisLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOpPoint_oaAnalysisLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOpPoint_oaAnalysisLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOpPoint_oaAnalysisLib",
           (PyObject*)(&PyoaCollection_oaOpPoint_oaAnalysisLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOpPoint_oaAnalysisLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaOpPoint_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPoint_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaOpPoint_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaOpPoint_oaTechObject* self = (PyoaCollection_oaOpPoint_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaOpPoint_oaTech)
    {
        PyParamoaCollection_oaOpPoint_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaOpPoint_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaOpPoint_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaOpPoint_oaTech, Choices are:\n"
        "    (oaCollection_oaOpPoint_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaOpPoint_oaTech_tp_dealloc(PyoaCollection_oaOpPoint_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaOpPoint_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaOpPoint_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaOpPoint_oaTech value;
    int convert_status=PyoaCollection_oaOpPoint_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaOpPoint_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaOpPoint_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaOpPoint_oaTech v1;
    PyParamoaCollection_oaOpPoint_oaTech v2;
    int convert_status1=PyoaCollection_oaOpPoint_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaOpPoint_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaOpPoint_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaOpPoint_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaOpPoint_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaOpPoint_oaTech*) ((PyoaCollection_oaOpPoint_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaOpPoint_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaOpPoint_oaTech_FromoaCollection_oaOpPoint_oaTech(oaCollection_oaOpPoint_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaOpPoint_oaTech_Type.tp_alloc(&PyoaCollection_oaOpPoint_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaOpPoint_oaTechObject* self = (PyoaCollection_oaOpPoint_oaTechObject*)bself;
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
static char oaCollection_oaOpPoint_oaTech_includes_doc[] = 
"Class: oaCollection_oaOpPoint_oaTech, Function: includes\n"
"  Paramegers: (oaOpPoint)\n"
"    Calls: oaBoolean includes(const oaOpPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaOpPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaOpPoint_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaOpPoint_oaTech data;
    int convert_status=PyoaCollection_oaOpPoint_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaOpPoint_oaTechObject* self=(PyoaCollection_oaOpPoint_oaTechObject*)ob;

    PyParamoaOpPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOpPoint_Convert,&p1)) {
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

static char oaCollection_oaOpPoint_oaTech_assign_doc[] = 
"Class: oaCollection_oaOpPoint_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaOpPoint_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaOpPoint_oaTech data;
  int convert_status=PyoaCollection_oaOpPoint_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaOpPoint_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaOpPoint_oaTech_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaOpPoint_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaOpPoint_oaTech_includes,METH_VARARGS,oaCollection_oaOpPoint_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaOpPoint_oaTech_tp_assign,METH_VARARGS,oaCollection_oaOpPoint_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaOpPoint_oaTech_doc[] = 
"Class: oaCollection_oaOpPoint_oaTech\n"
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
"  Paramegers: (oaCollection_oaOpPoint_oaTech)\n"
"    Calls: oaCollection_oaOpPoint_oaTech(const oaCollection_oaOpPoint_oaTech& coll)\n"
"    Signature: oaCollection_oaOpPoint_oaTech||cref-oaCollection_oaOpPoint_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaOpPoint_oaTech)\n"
"    Calls: (const oaCollection_oaOpPoint_oaTech&)\n"
"    Signature: oaCollection_oaOpPoint_oaTech||cref-oaCollection_oaOpPoint_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaOpPoint_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaOpPoint_oaTech",
    sizeof(PyoaCollection_oaOpPoint_oaTechObject),
    0,
    (destructor)oaCollection_oaOpPoint_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaOpPoint_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaOpPoint_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaOpPoint_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaOpPoint_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaOpPoint_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaOpPoint_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaOpPoint_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaOpPoint_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaOpPoint_oaTech",
           (PyObject*)(&PyoaCollection_oaOpPoint_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaOpPoint_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaParasiticNetwork_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaParasiticNetwork_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject* self = (PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaParasiticNetwork_oaParasiticNetwork)
    {
        PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaParasiticNetwork_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaParasiticNetwork_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaParasiticNetwork_oaParasiticNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaParasiticNetwork_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[72];
    sprintf(buffer,"<oaCollection_oaParasiticNetwork_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork v1;
    PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaParasiticNetwork_oaParasiticNetwork*) ((PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaParasiticNetwork_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_FromoaCollection_oaParasiticNetwork_oaParasiticNetwork(oaCollection_oaParasiticNetwork_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject* self = (PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject*)bself;
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
static char oaCollection_oaParasiticNetwork_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaParasiticNetwork_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaParasiticNetwork)\n"
"    Calls: oaBoolean includes(const oaParasiticNetwork* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaParasiticNetwork,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaParasiticNetwork_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject* self=(PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject*)ob;

    PyParamoaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParasiticNetwork_Convert,&p1)) {
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

static char oaCollection_oaParasiticNetwork_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaParasiticNetwork_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaParasiticNetwork_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaParasiticNetwork_oaParasiticNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaParasiticNetwork_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaParasiticNetwork_oaParasiticNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaParasiticNetwork_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaParasiticNetwork_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaParasiticNetwork_oaParasiticNetwork\n"
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
"  Paramegers: (oaCollection_oaParasiticNetwork_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaParasiticNetwork_oaParasiticNetwork(const oaCollection_oaParasiticNetwork_oaParasiticNetwork& coll)\n"
"    Signature: oaCollection_oaParasiticNetwork_oaParasiticNetwork||cref-oaCollection_oaParasiticNetwork_oaParasiticNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaParasiticNetwork_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaParasiticNetwork_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaParasiticNetwork_oaParasiticNetwork||cref-oaCollection_oaParasiticNetwork_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaParasiticNetwork_oaParasiticNetwork",
    sizeof(PyoaCollection_oaParasiticNetwork_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaParasiticNetwork_oaParasiticNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaParasiticNetwork_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaParasiticNetwork_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaParasiticNetwork_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaParasiticNetwork_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaParasiticNetwork_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaParasiticNetwork_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaParasiticNetwork_oaParasiticNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaPinFig_oaPin
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPinFig_oaPin_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPinFig_oaPin_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPinFig_oaPinObject* self = (PyoaCollection_oaPinFig_oaPinObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPinFig_oaPin)
    {
        PyParamoaCollection_oaPinFig_oaPin p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPinFig_oaPin_Convert,&p1)) {
            self->value =  new oaCollection_oaPinFig_oaPin(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPinFig_oaPin, Choices are:\n"
        "    (oaCollection_oaPinFig_oaPin)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaPinFig_oaPin_tp_dealloc(PyoaCollection_oaPinFig_oaPinObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPinFig_oaPin_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPinFig_oaPin value;
    int convert_status=PyoaCollection_oaPinFig_oaPin_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaPinFig_oaPin::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPinFig_oaPin_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPinFig_oaPin v1;
    PyParamoaCollection_oaPinFig_oaPin v2;
    int convert_status1=PyoaCollection_oaPinFig_oaPin_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPinFig_oaPin_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPinFig_oaPin_Convert(PyObject* ob,PyParamoaCollection_oaPinFig_oaPin* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPinFig_oaPin_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaPinFig_oaPinObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPinFig_oaPin Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPinFig_oaPin_FromoaCollection_oaPinFig_oaPin(oaCollection_oaPinFig_oaPin* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPinFig_oaPin_Type.tp_alloc(&PyoaCollection_oaPinFig_oaPin_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPinFig_oaPinObject* self = (PyoaCollection_oaPinFig_oaPinObject*)bself;
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
static char oaCollection_oaPinFig_oaPin_getCount_doc[] = 
"Class: oaCollection_oaPinFig_oaPin, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaPinFig_oaPin_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPinFig_oaPin data;
    int convert_status=PyoaCollection_oaPinFig_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPinFig_oaPinObject* self=(PyoaCollection_oaPinFig_oaPinObject*)ob;

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
static char oaCollection_oaPinFig_oaPin_includes_doc[] = 
"Class: oaCollection_oaPinFig_oaPin, Function: includes\n"
"  Paramegers: (oaFig)\n"
"    Calls: oaBoolean includes(const oaFig* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaFig,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaPinFig_oaPin_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPinFig_oaPin data;
    int convert_status=PyoaCollection_oaPinFig_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPinFig_oaPinObject* self=(PyoaCollection_oaPinFig_oaPinObject*)ob;

    PyParamoaFig p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFig_Convert,&p1)) {
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
static char oaCollection_oaPinFig_oaPin_isEmpty_doc[] = 
"Class: oaCollection_oaPinFig_oaPin, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaPinFig_oaPin_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPinFig_oaPin data;
    int convert_status=PyoaCollection_oaPinFig_oaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPinFig_oaPinObject* self=(PyoaCollection_oaPinFig_oaPinObject*)ob;

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

static char oaCollection_oaPinFig_oaPin_assign_doc[] = 
"Class: oaCollection_oaPinFig_oaPin, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPinFig_oaPin_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPinFig_oaPin data;
  int convert_status=PyoaCollection_oaPinFig_oaPin_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPinFig_oaPin p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPinFig_oaPin_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaPinFig_oaPin_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaPinFig_oaPin_getCount,METH_VARARGS,oaCollection_oaPinFig_oaPin_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaPinFig_oaPin_includes,METH_VARARGS,oaCollection_oaPinFig_oaPin_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaPinFig_oaPin_isEmpty,METH_VARARGS,oaCollection_oaPinFig_oaPin_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaPinFig_oaPin_tp_assign,METH_VARARGS,oaCollection_oaPinFig_oaPin_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPinFig_oaPin_doc[] = 
"Class: oaCollection_oaPinFig_oaPin\n"
"  Class type oaCollection_oaPinFig_oaPin\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaPinFig_oaPin)\n"
"    Calls: oaCollection_oaPinFig_oaPin(const oaCollection_oaPinFig_oaPin& c)\n"
"    Signature: oaCollection_oaPinFig_oaPin||cref-oaCollection_oaPinFig_oaPin,\n"
"    Constructor oaCollection_oaPinFig_oaPin\n"
"  Paramegers: (oaCollection_oaPinFig_oaPin)\n"
"    Calls: (const oaCollection_oaPinFig_oaPin&)\n"
"    Signature: oaCollection_oaPinFig_oaPin||cref-oaCollection_oaPinFig_oaPin,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPinFig_oaPin_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPinFig_oaPin",
    sizeof(PyoaCollection_oaPinFig_oaPinObject),
    0,
    (destructor)oaCollection_oaPinFig_oaPin_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPinFig_oaPin_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPinFig_oaPin_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaPinFig_oaPin_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPinFig_oaPin_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPinFig_oaPin_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPinFig_oaPin_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPinFig_oaPin_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPinFig_oaPin\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPinFig_oaPin",
           (PyObject*)(&PyoaCollection_oaPinFig_oaPin_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPinFig_oaPin\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaPin_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPin_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPin_oaBlockObject* self = (PyoaCollection_oaPin_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPin_oaBlock)
    {
        PyParamoaCollection_oaPin_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPin_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaPin_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPin_oaBlock, Choices are:\n"
        "    (oaCollection_oaPin_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaPin_oaBlock_tp_dealloc(PyoaCollection_oaPin_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaPin_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPin_oaBlock value;
    int convert_status=PyoaCollection_oaPin_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaPin_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPin_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPin_oaBlock v1;
    PyParamoaCollection_oaPin_oaBlock v2;
    int convert_status1=PyoaCollection_oaPin_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPin_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPin_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaPin_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPin_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaPin_oaBlock*) ((PyoaCollection_oaPin_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPin_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPin_oaBlock_FromoaCollection_oaPin_oaBlock(oaCollection_oaPin_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPin_oaBlock_Type.tp_alloc(&PyoaCollection_oaPin_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPin_oaBlockObject* self = (PyoaCollection_oaPin_oaBlockObject*)bself;
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
static char oaCollection_oaPin_oaBlock_includes_doc[] = 
"Class: oaCollection_oaPin_oaBlock, Function: includes\n"
"  Paramegers: (oaPin)\n"
"    Calls: oaBoolean includes(const oaPin* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaPin,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaPin_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPin_oaBlock data;
    int convert_status=PyoaCollection_oaPin_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPin_oaBlockObject* self=(PyoaCollection_oaPin_oaBlockObject*)ob;

    PyParamoaPin p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPin_Convert,&p1)) {
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

static char oaCollection_oaPin_oaBlock_assign_doc[] = 
"Class: oaCollection_oaPin_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPin_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPin_oaBlock data;
  int convert_status=PyoaCollection_oaPin_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPin_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPin_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaPin_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaPin_oaBlock_includes,METH_VARARGS,oaCollection_oaPin_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaPin_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaPin_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPin_oaBlock_doc[] = 
"Class: oaCollection_oaPin_oaBlock\n"
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
"  Paramegers: (oaCollection_oaPin_oaBlock)\n"
"    Calls: oaCollection_oaPin_oaBlock(const oaCollection_oaPin_oaBlock& coll)\n"
"    Signature: oaCollection_oaPin_oaBlock||cref-oaCollection_oaPin_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaPin_oaBlock)\n"
"    Calls: (const oaCollection_oaPin_oaBlock&)\n"
"    Signature: oaCollection_oaPin_oaBlock||cref-oaCollection_oaPin_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPin_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPin_oaBlock",
    sizeof(PyoaCollection_oaPin_oaBlockObject),
    0,
    (destructor)oaCollection_oaPin_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPin_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPin_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaPin_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPin_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPin_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPin_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPin_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPin_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPin_oaBlock",
           (PyObject*)(&PyoaCollection_oaPin_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPin_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaPin_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPin_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPin_oaNetObject* self = (PyoaCollection_oaPin_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPin_oaNet)
    {
        PyParamoaCollection_oaPin_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPin_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaPin_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPin_oaNet, Choices are:\n"
        "    (oaCollection_oaPin_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaPin_oaNet_tp_dealloc(PyoaCollection_oaPin_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaPin_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPin_oaNet value;
    int convert_status=PyoaCollection_oaPin_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaCollection_oaPin_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPin_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPin_oaNet v1;
    PyParamoaCollection_oaPin_oaNet v2;
    int convert_status1=PyoaCollection_oaPin_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPin_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPin_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaPin_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPin_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaPin_oaNet*) ((PyoaCollection_oaPin_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPin_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPin_oaNet_FromoaCollection_oaPin_oaNet(oaCollection_oaPin_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPin_oaNet_Type.tp_alloc(&PyoaCollection_oaPin_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPin_oaNetObject* self = (PyoaCollection_oaPin_oaNetObject*)bself;
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
static char oaCollection_oaPin_oaNet_includes_doc[] = 
"Class: oaCollection_oaPin_oaNet, Function: includes\n"
"  Paramegers: (oaPin)\n"
"    Calls: oaBoolean includes(const oaPin* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaPin,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaPin_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPin_oaNet data;
    int convert_status=PyoaCollection_oaPin_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPin_oaNetObject* self=(PyoaCollection_oaPin_oaNetObject*)ob;

    PyParamoaPin p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPin_Convert,&p1)) {
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

static char oaCollection_oaPin_oaNet_assign_doc[] = 
"Class: oaCollection_oaPin_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPin_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPin_oaNet data;
  int convert_status=PyoaCollection_oaPin_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPin_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPin_oaNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaPin_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaPin_oaNet_includes,METH_VARARGS,oaCollection_oaPin_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaPin_oaNet_tp_assign,METH_VARARGS,oaCollection_oaPin_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPin_oaNet_doc[] = 
"Class: oaCollection_oaPin_oaNet\n"
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
"  Paramegers: (oaCollection_oaPin_oaNet)\n"
"    Calls: oaCollection_oaPin_oaNet(const oaCollection_oaPin_oaNet& coll)\n"
"    Signature: oaCollection_oaPin_oaNet||cref-oaCollection_oaPin_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaPin_oaNet)\n"
"    Calls: (const oaCollection_oaPin_oaNet&)\n"
"    Signature: oaCollection_oaPin_oaNet||cref-oaCollection_oaPin_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPin_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPin_oaNet",
    sizeof(PyoaCollection_oaPin_oaNetObject),
    0,
    (destructor)oaCollection_oaPin_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPin_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPin_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaPin_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPin_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPin_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPin_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPin_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPin_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPin_oaNet",
           (PyObject*)(&PyoaCollection_oaPin_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPin_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaPin_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaPin_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaPin_oaTermObject* self = (PyoaCollection_oaPin_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaPin_oaTerm)
    {
        PyParamoaCollection_oaPin_oaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaPin_oaTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaPin_oaTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaPin_oaTerm, Choices are:\n"
        "    (oaCollection_oaPin_oaTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaPin_oaTerm_tp_dealloc(PyoaCollection_oaPin_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaPin_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaPin_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaPin_oaTerm value;
    int convert_status=PyoaCollection_oaPin_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaCollection_oaPin_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaPin_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaPin_oaTerm v1;
    PyParamoaCollection_oaPin_oaTerm v2;
    int convert_status1=PyoaCollection_oaPin_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaPin_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaPin_oaTerm_Convert(PyObject* ob,PyParamoaCollection_oaPin_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaPin_oaTerm_Check(ob)) {
        result->SetData( (oaCollection_oaPin_oaTerm*) ((PyoaCollection_oaPin_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaPin_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaPin_oaTerm_FromoaCollection_oaPin_oaTerm(oaCollection_oaPin_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaPin_oaTerm_Type.tp_alloc(&PyoaCollection_oaPin_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaPin_oaTermObject* self = (PyoaCollection_oaPin_oaTermObject*)bself;
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
static char oaCollection_oaPin_oaTerm_includes_doc[] = 
"Class: oaCollection_oaPin_oaTerm, Function: includes\n"
"  Paramegers: (oaPin)\n"
"    Calls: oaBoolean includes(const oaPin* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaPin,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaPin_oaTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaPin_oaTerm data;
    int convert_status=PyoaCollection_oaPin_oaTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaPin_oaTermObject* self=(PyoaCollection_oaPin_oaTermObject*)ob;

    PyParamoaPin p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPin_Convert,&p1)) {
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

static char oaCollection_oaPin_oaTerm_assign_doc[] = 
"Class: oaCollection_oaPin_oaTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaPin_oaTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaPin_oaTerm data;
  int convert_status=PyoaCollection_oaPin_oaTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaPin_oaTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaPin_oaTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaPin_oaTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaPin_oaTerm_includes,METH_VARARGS,oaCollection_oaPin_oaTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaPin_oaTerm_tp_assign,METH_VARARGS,oaCollection_oaPin_oaTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaPin_oaTerm_doc[] = 
"Class: oaCollection_oaPin_oaTerm\n"
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
"  Paramegers: (oaCollection_oaPin_oaTerm)\n"
"    Calls: oaCollection_oaPin_oaTerm(const oaCollection_oaPin_oaTerm& coll)\n"
"    Signature: oaCollection_oaPin_oaTerm||cref-oaCollection_oaPin_oaTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaPin_oaTerm)\n"
"    Calls: (const oaCollection_oaPin_oaTerm&)\n"
"    Signature: oaCollection_oaPin_oaTerm||cref-oaCollection_oaPin_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaPin_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaPin_oaTerm",
    sizeof(PyoaCollection_oaPin_oaTermObject),
    0,
    (destructor)oaCollection_oaPin_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaPin_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaPin_oaTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaPin_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaPin_oaTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaPin_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaPin_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaPin_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaPin_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaPin_oaTerm",
           (PyObject*)(&PyoaCollection_oaPin_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaPin_oaTerm\n");
       return -1;
    }
    return 0;
}

