
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaViaSpec_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaSpec_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViaSpec_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViaSpec_oaTechObject* self = (PyoaCollection_oaViaSpec_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViaSpec_oaTech)
    {
        PyParamoaCollection_oaViaSpec_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViaSpec_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViaSpec_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViaSpec_oaTech, Choices are:\n"
        "    (oaCollection_oaViaSpec_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaViaSpec_oaTech_tp_dealloc(PyoaCollection_oaViaSpec_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViaSpec_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViaSpec_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViaSpec_oaTech value;
    int convert_status=PyoaCollection_oaViaSpec_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaViaSpec_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViaSpec_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViaSpec_oaTech v1;
    PyParamoaCollection_oaViaSpec_oaTech v2;
    int convert_status1=PyoaCollection_oaViaSpec_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViaSpec_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViaSpec_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaViaSpec_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViaSpec_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaViaSpec_oaTech*) ((PyoaCollection_oaViaSpec_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViaSpec_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViaSpec_oaTech_FromoaCollection_oaViaSpec_oaTech(oaCollection_oaViaSpec_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViaSpec_oaTech_Type.tp_alloc(&PyoaCollection_oaViaSpec_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViaSpec_oaTechObject* self = (PyoaCollection_oaViaSpec_oaTechObject*)bself;
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
static char oaCollection_oaViaSpec_oaTech_includes_doc[] = 
"Class: oaCollection_oaViaSpec_oaTech, Function: includes\n"
"  Paramegers: (oaViaSpec)\n"
"    Calls: oaBoolean includes(const oaViaSpec* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViaSpec,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViaSpec_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViaSpec_oaTech data;
    int convert_status=PyoaCollection_oaViaSpec_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViaSpec_oaTechObject* self=(PyoaCollection_oaViaSpec_oaTechObject*)ob;

    PyParamoaViaSpec p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaSpec_Convert,&p1)) {
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

static char oaCollection_oaViaSpec_oaTech_assign_doc[] = 
"Class: oaCollection_oaViaSpec_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViaSpec_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViaSpec_oaTech data;
  int convert_status=PyoaCollection_oaViaSpec_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViaSpec_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViaSpec_oaTech_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaViaSpec_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViaSpec_oaTech_includes,METH_VARARGS,oaCollection_oaViaSpec_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViaSpec_oaTech_tp_assign,METH_VARARGS,oaCollection_oaViaSpec_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViaSpec_oaTech_doc[] = 
"Class: oaCollection_oaViaSpec_oaTech\n"
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
"  Paramegers: (oaCollection_oaViaSpec_oaTech)\n"
"    Calls: oaCollection_oaViaSpec_oaTech(const oaCollection_oaViaSpec_oaTech& coll)\n"
"    Signature: oaCollection_oaViaSpec_oaTech||cref-oaCollection_oaViaSpec_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViaSpec_oaTech)\n"
"    Calls: (const oaCollection_oaViaSpec_oaTech&)\n"
"    Signature: oaCollection_oaViaSpec_oaTech||cref-oaCollection_oaViaSpec_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViaSpec_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViaSpec_oaTech",
    sizeof(PyoaCollection_oaViaSpec_oaTechObject),
    0,
    (destructor)oaCollection_oaViaSpec_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViaSpec_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViaSpec_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaViaSpec_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViaSpec_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViaSpec_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViaSpec_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViaSpec_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViaSpec_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViaSpec_oaTech",
           (PyObject*)(&PyoaCollection_oaViaSpec_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViaSpec_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaVia_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVia_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVia_oaBlockObject* self = (PyoaCollection_oaVia_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVia_oaBlock)
    {
        PyParamoaCollection_oaVia_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVia_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVia_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVia_oaBlock, Choices are:\n"
        "    (oaCollection_oaVia_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaVia_oaBlock_tp_dealloc(PyoaCollection_oaVia_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVia_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVia_oaBlock value;
    int convert_status=PyoaCollection_oaVia_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaCollection_oaVia_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVia_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVia_oaBlock v1;
    PyParamoaCollection_oaVia_oaBlock v2;
    int convert_status1=PyoaCollection_oaVia_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVia_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVia_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaVia_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVia_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaVia_oaBlock*) ((PyoaCollection_oaVia_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVia_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVia_oaBlock_FromoaCollection_oaVia_oaBlock(oaCollection_oaVia_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVia_oaBlock_Type.tp_alloc(&PyoaCollection_oaVia_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVia_oaBlockObject* self = (PyoaCollection_oaVia_oaBlockObject*)bself;
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
static char oaCollection_oaVia_oaBlock_includes_doc[] = 
"Class: oaCollection_oaVia_oaBlock, Function: includes\n"
"  Paramegers: (oaVia)\n"
"    Calls: oaBoolean includes(const oaVia* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVia,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVia_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVia_oaBlock data;
    int convert_status=PyoaCollection_oaVia_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVia_oaBlockObject* self=(PyoaCollection_oaVia_oaBlockObject*)ob;

    PyParamoaVia p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVia_Convert,&p1)) {
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

static char oaCollection_oaVia_oaBlock_assign_doc[] = 
"Class: oaCollection_oaVia_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVia_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVia_oaBlock data;
  int convert_status=PyoaCollection_oaVia_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVia_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVia_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaVia_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVia_oaBlock_includes,METH_VARARGS,oaCollection_oaVia_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVia_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaVia_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVia_oaBlock_doc[] = 
"Class: oaCollection_oaVia_oaBlock\n"
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
"  Paramegers: (oaCollection_oaVia_oaBlock)\n"
"    Calls: oaCollection_oaVia_oaBlock(const oaCollection_oaVia_oaBlock& coll)\n"
"    Signature: oaCollection_oaVia_oaBlock||cref-oaCollection_oaVia_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVia_oaBlock)\n"
"    Calls: (const oaCollection_oaVia_oaBlock&)\n"
"    Signature: oaCollection_oaVia_oaBlock||cref-oaCollection_oaVia_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVia_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVia_oaBlock",
    sizeof(PyoaCollection_oaVia_oaBlockObject),
    0,
    (destructor)oaCollection_oaVia_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVia_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVia_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaVia_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVia_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVia_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVia_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVia_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVia_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVia_oaBlock",
           (PyObject*)(&PyoaCollection_oaVia_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVia_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaVia_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVia_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVia_oaNetObject* self = (PyoaCollection_oaVia_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVia_oaNet)
    {
        PyParamoaCollection_oaVia_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVia_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVia_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVia_oaNet, Choices are:\n"
        "    (oaCollection_oaVia_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaVia_oaNet_tp_dealloc(PyoaCollection_oaVia_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVia_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVia_oaNet value;
    int convert_status=PyoaCollection_oaVia_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaCollection_oaVia_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVia_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVia_oaNet v1;
    PyParamoaCollection_oaVia_oaNet v2;
    int convert_status1=PyoaCollection_oaVia_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVia_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVia_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaVia_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVia_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaVia_oaNet*) ((PyoaCollection_oaVia_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVia_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVia_oaNet_FromoaCollection_oaVia_oaNet(oaCollection_oaVia_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVia_oaNet_Type.tp_alloc(&PyoaCollection_oaVia_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVia_oaNetObject* self = (PyoaCollection_oaVia_oaNetObject*)bself;
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
static char oaCollection_oaVia_oaNet_includes_doc[] = 
"Class: oaCollection_oaVia_oaNet, Function: includes\n"
"  Paramegers: (oaVia)\n"
"    Calls: oaBoolean includes(const oaVia* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVia,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVia_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVia_oaNet data;
    int convert_status=PyoaCollection_oaVia_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVia_oaNetObject* self=(PyoaCollection_oaVia_oaNetObject*)ob;

    PyParamoaVia p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVia_Convert,&p1)) {
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

static char oaCollection_oaVia_oaNet_assign_doc[] = 
"Class: oaCollection_oaVia_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVia_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVia_oaNet data;
  int convert_status=PyoaCollection_oaVia_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVia_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVia_oaNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaVia_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVia_oaNet_includes,METH_VARARGS,oaCollection_oaVia_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVia_oaNet_tp_assign,METH_VARARGS,oaCollection_oaVia_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVia_oaNet_doc[] = 
"Class: oaCollection_oaVia_oaNet\n"
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
"  Paramegers: (oaCollection_oaVia_oaNet)\n"
"    Calls: oaCollection_oaVia_oaNet(const oaCollection_oaVia_oaNet& coll)\n"
"    Signature: oaCollection_oaVia_oaNet||cref-oaCollection_oaVia_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVia_oaNet)\n"
"    Calls: (const oaCollection_oaVia_oaNet&)\n"
"    Signature: oaCollection_oaVia_oaNet||cref-oaCollection_oaVia_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVia_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVia_oaNet",
    sizeof(PyoaCollection_oaVia_oaNetObject),
    0,
    (destructor)oaCollection_oaVia_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVia_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVia_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaVia_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVia_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVia_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVia_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVia_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVia_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVia_oaNet",
           (PyObject*)(&PyoaCollection_oaVia_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVia_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaVia_oaViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaVia_oaViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaVia_oaViaHeaderObject* self = (PyoaCollection_oaVia_oaViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaVia_oaViaHeader)
    {
        PyParamoaCollection_oaVia_oaViaHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaVia_oaViaHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaVia_oaViaHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaVia_oaViaHeader, Choices are:\n"
        "    (oaCollection_oaVia_oaViaHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaVia_oaViaHeader_tp_dealloc(PyoaCollection_oaVia_oaViaHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaVia_oaViaHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaVia_oaViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaVia_oaViaHeader value;
    int convert_status=PyoaCollection_oaVia_oaViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaVia_oaViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaVia_oaViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaVia_oaViaHeader v1;
    PyParamoaCollection_oaVia_oaViaHeader v2;
    int convert_status1=PyoaCollection_oaVia_oaViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaVia_oaViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaVia_oaViaHeader_Convert(PyObject* ob,PyParamoaCollection_oaVia_oaViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaVia_oaViaHeader_Check(ob)) {
        result->SetData( (oaCollection_oaVia_oaViaHeader*) ((PyoaCollection_oaVia_oaViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaVia_oaViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaVia_oaViaHeader_FromoaCollection_oaVia_oaViaHeader(oaCollection_oaVia_oaViaHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaVia_oaViaHeader_Type.tp_alloc(&PyoaCollection_oaVia_oaViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaVia_oaViaHeaderObject* self = (PyoaCollection_oaVia_oaViaHeaderObject*)bself;
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
static char oaCollection_oaVia_oaViaHeader_includes_doc[] = 
"Class: oaCollection_oaVia_oaViaHeader, Function: includes\n"
"  Paramegers: (oaVia)\n"
"    Calls: oaBoolean includes(const oaVia* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaVia,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaVia_oaViaHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaVia_oaViaHeader data;
    int convert_status=PyoaCollection_oaVia_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaVia_oaViaHeaderObject* self=(PyoaCollection_oaVia_oaViaHeaderObject*)ob;

    PyParamoaVia p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaVia_Convert,&p1)) {
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

static char oaCollection_oaVia_oaViaHeader_assign_doc[] = 
"Class: oaCollection_oaVia_oaViaHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaVia_oaViaHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaVia_oaViaHeader data;
  int convert_status=PyoaCollection_oaVia_oaViaHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaVia_oaViaHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaVia_oaViaHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaVia_oaViaHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaVia_oaViaHeader_includes,METH_VARARGS,oaCollection_oaVia_oaViaHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaVia_oaViaHeader_tp_assign,METH_VARARGS,oaCollection_oaVia_oaViaHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaVia_oaViaHeader_doc[] = 
"Class: oaCollection_oaVia_oaViaHeader\n"
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
"  Paramegers: (oaCollection_oaVia_oaViaHeader)\n"
"    Calls: oaCollection_oaVia_oaViaHeader(const oaCollection_oaVia_oaViaHeader& coll)\n"
"    Signature: oaCollection_oaVia_oaViaHeader||cref-oaCollection_oaVia_oaViaHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaVia_oaViaHeader)\n"
"    Calls: (const oaCollection_oaVia_oaViaHeader&)\n"
"    Signature: oaCollection_oaVia_oaViaHeader||cref-oaCollection_oaVia_oaViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaVia_oaViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaVia_oaViaHeader",
    sizeof(PyoaCollection_oaVia_oaViaHeaderObject),
    0,
    (destructor)oaCollection_oaVia_oaViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaVia_oaViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaVia_oaViaHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaVia_oaViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaVia_oaViaHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaVia_oaViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaVia_oaViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaVia_oaViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaVia_oaViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaVia_oaViaHeader",
           (PyObject*)(&PyoaCollection_oaVia_oaViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaVia_oaViaHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaViewType_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViewType_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaViewType_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaViewType_oaSessionObject* self = (PyoaCollection_oaViewType_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaViewType_oaSession)
    {
        PyParamoaCollection_oaViewType_oaSession p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaViewType_oaSession_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaViewType_oaSession(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaViewType_oaSession, Choices are:\n"
        "    (oaCollection_oaViewType_oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaViewType_oaSession_tp_dealloc(PyoaCollection_oaViewType_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaViewType_oaSession*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaViewType_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaViewType_oaSession value;
    int convert_status=PyoaCollection_oaViewType_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaViewType_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaViewType_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaViewType_oaSession v1;
    PyParamoaCollection_oaViewType_oaSession v2;
    int convert_status1=PyoaCollection_oaViewType_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaViewType_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaViewType_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaViewType_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaViewType_oaSession_Check(ob)) {
        result->SetData( (oaCollection_oaViewType_oaSession*) ((PyoaCollection_oaViewType_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaViewType_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaViewType_oaSession_FromoaCollection_oaViewType_oaSession(oaCollection_oaViewType_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaViewType_oaSession_Type.tp_alloc(&PyoaCollection_oaViewType_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaViewType_oaSessionObject* self = (PyoaCollection_oaViewType_oaSessionObject*)bself;
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
static char oaCollection_oaViewType_oaSession_includes_doc[] = 
"Class: oaCollection_oaViewType_oaSession, Function: includes\n"
"  Paramegers: (oaViewType)\n"
"    Calls: oaBoolean includes(const oaViewType* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaViewType,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaViewType_oaSession_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaViewType_oaSession data;
    int convert_status=PyoaCollection_oaViewType_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaViewType_oaSessionObject* self=(PyoaCollection_oaViewType_oaSessionObject*)ob;

    PyParamoaViewType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViewType_Convert,&p1)) {
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

static char oaCollection_oaViewType_oaSession_assign_doc[] = 
"Class: oaCollection_oaViewType_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaViewType_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaViewType_oaSession data;
  int convert_status=PyoaCollection_oaViewType_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaViewType_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaViewType_oaSession_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaViewType_oaSession_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaViewType_oaSession_includes,METH_VARARGS,oaCollection_oaViewType_oaSession_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaViewType_oaSession_tp_assign,METH_VARARGS,oaCollection_oaViewType_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaViewType_oaSession_doc[] = 
"Class: oaCollection_oaViewType_oaSession\n"
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
"  Paramegers: (oaCollection_oaViewType_oaSession)\n"
"    Calls: oaCollection_oaViewType_oaSession(const oaCollection_oaViewType_oaSession& coll)\n"
"    Signature: oaCollection_oaViewType_oaSession||cref-oaCollection_oaViewType_oaSession,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaViewType_oaSession)\n"
"    Calls: (const oaCollection_oaViewType_oaSession&)\n"
"    Signature: oaCollection_oaViewType_oaSession||cref-oaCollection_oaViewType_oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaViewType_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaViewType_oaSession",
    sizeof(PyoaCollection_oaViewType_oaSessionObject),
    0,
    (destructor)oaCollection_oaViewType_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaViewType_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaViewType_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaViewType_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaViewType_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaViewType_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaViewType_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaViewType_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaViewType_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaViewType_oaSession",
           (PyObject*)(&PyoaCollection_oaViewType_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaViewType_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaView_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaView_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaView_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaView_oaLibObject* self = (PyoaCollection_oaView_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaView_oaLib)
    {
        PyParamoaCollection_oaView_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaView_oaLib_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaView_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaView_oaLib, Choices are:\n"
        "    (oaCollection_oaView_oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaView_oaLib_tp_dealloc(PyoaCollection_oaView_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaView_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaView_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaView_oaLib value;
    int convert_status=PyoaCollection_oaView_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaCollection_oaView_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaView_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaView_oaLib v1;
    PyParamoaCollection_oaView_oaLib v2;
    int convert_status1=PyoaCollection_oaView_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaView_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaView_oaLib_Convert(PyObject* ob,PyParamoaCollection_oaView_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaView_oaLib_Check(ob)) {
        result->SetData( (oaCollection_oaView_oaLib*) ((PyoaCollection_oaView_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaView_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaView_oaLib_FromoaCollection_oaView_oaLib(oaCollection_oaView_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaView_oaLib_Type.tp_alloc(&PyoaCollection_oaView_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaView_oaLibObject* self = (PyoaCollection_oaView_oaLibObject*)bself;
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
static char oaCollection_oaView_oaLib_includes_doc[] = 
"Class: oaCollection_oaView_oaLib, Function: includes\n"
"  Paramegers: (oaView)\n"
"    Calls: oaBoolean includes(const oaView* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaView,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaView_oaLib_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaView_oaLib data;
    int convert_status=PyoaCollection_oaView_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaView_oaLibObject* self=(PyoaCollection_oaView_oaLibObject*)ob;

    PyParamoaView p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaView_Convert,&p1)) {
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

static char oaCollection_oaView_oaLib_assign_doc[] = 
"Class: oaCollection_oaView_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaView_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaView_oaLib data;
  int convert_status=PyoaCollection_oaView_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaView_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaView_oaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaView_oaLib_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaView_oaLib_includes,METH_VARARGS,oaCollection_oaView_oaLib_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaView_oaLib_tp_assign,METH_VARARGS,oaCollection_oaView_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaView_oaLib_doc[] = 
"Class: oaCollection_oaView_oaLib\n"
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
"  Paramegers: (oaCollection_oaView_oaLib)\n"
"    Calls: oaCollection_oaView_oaLib(const oaCollection_oaView_oaLib& coll)\n"
"    Signature: oaCollection_oaView_oaLib||cref-oaCollection_oaView_oaLib,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaView_oaLib)\n"
"    Calls: (const oaCollection_oaView_oaLib&)\n"
"    Signature: oaCollection_oaView_oaLib||cref-oaCollection_oaView_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaView_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaView_oaLib",
    sizeof(PyoaCollection_oaView_oaLibObject),
    0,
    (destructor)oaCollection_oaView_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaView_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaView_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaView_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaView_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaView_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaView_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaView_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaView_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaView_oaLib",
           (PyObject*)(&PyoaCollection_oaView_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaView_oaLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaWaferFeature_oaWaferDesc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaWaferFeature_oaWaferDesc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaWaferFeature_oaWaferDesc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaWaferFeature_oaWaferDescObject* self = (PyoaCollection_oaWaferFeature_oaWaferDescObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaWaferFeature_oaWaferDesc)
    {
        PyParamoaCollection_oaWaferFeature_oaWaferDesc p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaWaferFeature_oaWaferDesc_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaWaferFeature_oaWaferDesc(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaWaferFeature_oaWaferDesc, Choices are:\n"
        "    (oaCollection_oaWaferFeature_oaWaferDesc)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaWaferFeature_oaWaferDesc_tp_dealloc(PyoaCollection_oaWaferFeature_oaWaferDescObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaWaferFeature_oaWaferDesc*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaWaferFeature_oaWaferDesc_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaWaferFeature_oaWaferDesc value;
    int convert_status=PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaWaferFeature_oaWaferDesc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaWaferFeature_oaWaferDesc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaWaferFeature_oaWaferDesc v1;
    PyParamoaCollection_oaWaferFeature_oaWaferDesc v2;
    int convert_status1=PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(PyObject* ob,PyParamoaCollection_oaWaferFeature_oaWaferDesc* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaWaferFeature_oaWaferDesc_Check(ob)) {
        result->SetData( (oaCollection_oaWaferFeature_oaWaferDesc*) ((PyoaCollection_oaWaferFeature_oaWaferDescObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaWaferFeature_oaWaferDesc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaWaferFeature_oaWaferDesc_FromoaCollection_oaWaferFeature_oaWaferDesc(oaCollection_oaWaferFeature_oaWaferDesc* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaWaferFeature_oaWaferDesc_Type.tp_alloc(&PyoaCollection_oaWaferFeature_oaWaferDesc_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaWaferFeature_oaWaferDescObject* self = (PyoaCollection_oaWaferFeature_oaWaferDescObject*)bself;
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
static char oaCollection_oaWaferFeature_oaWaferDesc_includes_doc[] = 
"Class: oaCollection_oaWaferFeature_oaWaferDesc, Function: includes\n"
"  Paramegers: (oaWaferFeature)\n"
"    Calls: oaBoolean includes(const oaWaferFeature* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaWaferFeature,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaWaferFeature_oaWaferDesc_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaWaferFeature_oaWaferDesc data;
    int convert_status=PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaWaferFeature_oaWaferDescObject* self=(PyoaCollection_oaWaferFeature_oaWaferDescObject*)ob;

    PyParamoaWaferFeature p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWaferFeature_Convert,&p1)) {
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

static char oaCollection_oaWaferFeature_oaWaferDesc_assign_doc[] = 
"Class: oaCollection_oaWaferFeature_oaWaferDesc, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaWaferFeature_oaWaferDesc_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaWaferFeature_oaWaferDesc data;
  int convert_status=PyoaCollection_oaWaferFeature_oaWaferDesc_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaWaferFeature_oaWaferDesc p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaWaferFeature_oaWaferDesc_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaWaferFeature_oaWaferDesc_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaWaferFeature_oaWaferDesc_includes,METH_VARARGS,oaCollection_oaWaferFeature_oaWaferDesc_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaWaferFeature_oaWaferDesc_tp_assign,METH_VARARGS,oaCollection_oaWaferFeature_oaWaferDesc_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaWaferFeature_oaWaferDesc_doc[] = 
"Class: oaCollection_oaWaferFeature_oaWaferDesc\n"
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
"  Paramegers: (oaCollection_oaWaferFeature_oaWaferDesc)\n"
"    Calls: oaCollection_oaWaferFeature_oaWaferDesc(const oaCollection_oaWaferFeature_oaWaferDesc& coll)\n"
"    Signature: oaCollection_oaWaferFeature_oaWaferDesc||cref-oaCollection_oaWaferFeature_oaWaferDesc,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaWaferFeature_oaWaferDesc)\n"
"    Calls: (const oaCollection_oaWaferFeature_oaWaferDesc&)\n"
"    Signature: oaCollection_oaWaferFeature_oaWaferDesc||cref-oaCollection_oaWaferFeature_oaWaferDesc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaWaferFeature_oaWaferDesc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaWaferFeature_oaWaferDesc",
    sizeof(PyoaCollection_oaWaferFeature_oaWaferDescObject),
    0,
    (destructor)oaCollection_oaWaferFeature_oaWaferDesc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaWaferFeature_oaWaferDesc_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaWaferFeature_oaWaferDesc_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaWaferFeature_oaWaferDesc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaWaferFeature_oaWaferDesc_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaWaferFeature_oaWaferDesc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaWaferFeature_oaWaferDesc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaWaferFeature_oaWaferDesc_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaWaferFeature_oaWaferDesc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaWaferFeature_oaWaferDesc",
           (PyObject*)(&PyoaCollection_oaWaferFeature_oaWaferDesc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaWaferFeature_oaWaferDesc\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaWafer_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaWafer_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaWafer_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaWafer_oaWaferObject* self = (PyoaCollection_oaWafer_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaWafer_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaWafer_oaWafer)
    {
        PyParamoaCollection_oaWafer_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaWafer_oaWafer_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaWafer_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaWafer_oaWafer, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaCollection_oaWafer_oaWafer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaWafer_oaWafer_tp_dealloc(PyoaCollection_oaWafer_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaWafer_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaWafer_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaWafer_oaWafer value;
    int convert_status=PyoaCollection_oaWafer_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaWafer_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaWafer_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaWafer_oaWafer v1;
    PyParamoaCollection_oaWafer_oaWafer v2;
    int convert_status1=PyoaCollection_oaWafer_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaWafer_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaWafer_oaWafer_Convert(PyObject* ob,PyParamoaCollection_oaWafer_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaWafer_oaWafer_Check(ob)) {
        result->SetData( (oaCollection_oaWafer_oaWafer*) ((PyoaCollection_oaWafer_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaWafer_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaWafer_oaWafer_FromoaCollection_oaWafer_oaWafer(oaCollection_oaWafer_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaWafer_oaWafer_Type.tp_alloc(&PyoaCollection_oaWafer_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaWafer_oaWaferObject* self = (PyoaCollection_oaWafer_oaWaferObject*)bself;
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
static char oaCollection_oaWafer_oaWafer_includes_doc[] = 
"Class: oaCollection_oaWafer_oaWafer, Function: includes\n"
"  Paramegers: (oaWafer)\n"
"    Calls: oaBoolean includes(const oaWafer* db) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaWafer,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaWafer_oaWafer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaWafer_oaWafer data;
    int convert_status=PyoaCollection_oaWafer_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaWafer_oaWaferObject* self=(PyoaCollection_oaWafer_oaWaferObject*)ob;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
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

static char oaCollection_oaWafer_oaWafer_assign_doc[] = 
"Class: oaCollection_oaWafer_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaWafer_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaWafer_oaWafer data;
  int convert_status=PyoaCollection_oaWafer_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaWafer_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaWafer_oaWafer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaWafer_oaWafer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaWafer_oaWafer_includes,METH_VARARGS,oaCollection_oaWafer_oaWafer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaWafer_oaWafer_tp_assign,METH_VARARGS,oaCollection_oaWafer_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaWafer_oaWafer_doc[] = 
"Class: oaCollection_oaWafer_oaWafer\n"
"  Class type oaCollection_oaWafer_oaWafer\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaWafer_oaWafer(oaUInt4 dbIDIn)\n"
"    Signature: oaCollection_oaWafer_oaWafer||simple-oaUInt4,\n"
"    Constructor oaCollection_oaWafer_oaWafer\n"
"  Paramegers: (oaCollection_oaWafer_oaWafer)\n"
"    Calls: oaCollection_oaWafer_oaWafer(const oaCollection_oaWafer_oaWafer& c)\n"
"    Signature: oaCollection_oaWafer_oaWafer||cref-oaCollection_oaWafer_oaWafer,\n"
"    Constructor oaCollection_oaWafer_oaWafer\n"
"  Paramegers: (oaCollection_oaWafer_oaWafer)\n"
"    Calls: (const oaCollection_oaWafer_oaWafer&)\n"
"    Signature: oaCollection_oaWafer_oaWafer||cref-oaCollection_oaWafer_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaWafer_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaWafer_oaWafer",
    sizeof(PyoaCollection_oaWafer_oaWaferObject),
    0,
    (destructor)oaCollection_oaWafer_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaWafer_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaWafer_oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaWafer_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaWafer_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaWafer_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaWafer_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaWafer_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaWafer_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaWafer_oaWafer",
           (PyObject*)(&PyoaCollection_oaWafer_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaWafer_oaWafer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaComplexArray_oaDouble
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaComplexArray_oaDouble_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaComplexArray_oaDouble_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaComplexArray_oaDoubleObject* self = (PyoaComplexArray_oaDoubleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaComplexArray_oaDouble();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaComplexArray_oaDouble(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaComplexArray_oaDouble)
    {
        PyParamoaComplexArray_oaDouble p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplexArray_oaDouble_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaDouble*)  new oaComplexArray_oaDouble(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaComplexArray_oaDouble, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaComplexArray_oaDouble)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaComplexArray_oaDouble_tp_dealloc(PyoaComplexArray_oaDoubleObject* self)
{
    if (!self->borrow) {
        delete (oaComplexArray_oaDouble*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaComplexArray_oaDouble_tp_repr(PyObject *ob)
{
    PyParamoaComplexArray_oaDouble value;
    int convert_status=PyoaComplexArray_oaDouble_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaComplexArray_oaDouble::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaComplexArray_oaDouble_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaComplexArray_oaDouble v1;
    PyParamoaComplexArray_oaDouble v2;
    int convert_status1=PyoaComplexArray_oaDouble_Convert(ob1,&v1);
    int convert_status2=PyoaComplexArray_oaDouble_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaComplexArray_oaDouble_Convert(PyObject* ob,PyParamoaComplexArray_oaDouble* result)
{
    if (ob == NULL) return 1;
    if (PyoaComplexArray_oaDouble_Check(ob)) {
        result->SetData( (oaComplexArray_oaDouble*) ((PyoaComplexArray_oaDoubleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaComplexArray_oaDouble Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaComplexArray_oaDouble_FromoaComplexArray_oaDouble(oaComplexArray_oaDouble* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaComplexArray_oaDouble_Type.tp_alloc(&PyoaComplexArray_oaDouble_Type,0);
        if (bself == NULL) return bself;
        PyoaComplexArray_oaDoubleObject* self = (PyoaComplexArray_oaDoubleObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaComplexArray_oaDouble_doc[] = 
"Class: oaComplexArray_oaDouble\n"
"  The oaComplexArray template class represents an array of complex numbers, each of which has a real and an imaginary part.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaComplexArray_oaDouble()\n"
"    Signature: oaComplexArray_oaDouble||simple-oaUInt4,\n"
"    This function constructs an oaComplexArray object, setting the number of array elements and allocating storage for the complex numbers.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaComplexArray_oaDouble(oaUInt4 sizeIn)\n"
"    Signature: oaComplexArray_oaDouble||simple-oaUInt4,\n"
"    This function constructs an oaComplexArray object, setting the number of array elements and allocating storage for the complex numbers.\n"
"  Paramegers: (oaComplexArray_oaDouble)\n"
"    Calls: oaComplexArray_oaDouble(const oaComplexArray_oaDouble& array)\n"
"    Signature: oaComplexArray_oaDouble||cref-oaComplexArray_oaDouble,\n"
"    This function constructs a copy of the specified oaComplexArray array .\n"
"  Paramegers: (oaComplexArray_oaDouble)\n"
"    Calls: (const oaComplexArray_oaDouble&)\n"
"    Signature: oaComplexArray_oaDouble||cref-oaComplexArray_oaDouble,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaComplexArray_oaDouble_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaComplexArray_oaDouble",
    sizeof(PyoaComplexArray_oaDoubleObject),
    0,
    (destructor)oaComplexArray_oaDouble_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaComplexArray_oaDouble_tp_compare,	/* tp_compare */
    (reprfunc)oaComplexArray_oaDouble_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaComplexArray_oaDouble_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaComplex_oaDouble_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaComplexArray_oaDouble_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaComplexArray_oaDouble_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaComplexArray_oaDouble_Type)<0) {
      printf("** PyType_Ready failed for: oaComplexArray_oaDouble\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaComplexArray_oaDouble",
           (PyObject*)(&PyoaComplexArray_oaDouble_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaComplexArray_oaDouble\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaComplexArray_oaFloat
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaComplexArray_oaFloat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaComplexArray_oaFloat_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaComplexArray_oaFloatObject* self = (PyoaComplexArray_oaFloatObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaComplexArray_oaFloat();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaComplexArray_oaFloat(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaComplexArray_oaFloat)
    {
        PyParamoaComplexArray_oaFloat p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaComplexArray_oaFloat_Convert,&p1)) {
            self->value = (oaArrayBase_oaComplex_oaFloat*)  new oaComplexArray_oaFloat(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaComplexArray_oaFloat, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaComplexArray_oaFloat)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaComplexArray_oaFloat_tp_dealloc(PyoaComplexArray_oaFloatObject* self)
{
    if (!self->borrow) {
        delete (oaComplexArray_oaFloat*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaComplexArray_oaFloat_tp_repr(PyObject *ob)
{
    PyParamoaComplexArray_oaFloat value;
    int convert_status=PyoaComplexArray_oaFloat_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaComplexArray_oaFloat::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaComplexArray_oaFloat_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaComplexArray_oaFloat v1;
    PyParamoaComplexArray_oaFloat v2;
    int convert_status1=PyoaComplexArray_oaFloat_Convert(ob1,&v1);
    int convert_status2=PyoaComplexArray_oaFloat_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaComplexArray_oaFloat_Convert(PyObject* ob,PyParamoaComplexArray_oaFloat* result)
{
    if (ob == NULL) return 1;
    if (PyoaComplexArray_oaFloat_Check(ob)) {
        result->SetData( (oaComplexArray_oaFloat*) ((PyoaComplexArray_oaFloatObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaComplexArray_oaFloat Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaComplexArray_oaFloat_FromoaComplexArray_oaFloat(oaComplexArray_oaFloat* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaComplexArray_oaFloat_Type.tp_alloc(&PyoaComplexArray_oaFloat_Type,0);
        if (bself == NULL) return bself;
        PyoaComplexArray_oaFloatObject* self = (PyoaComplexArray_oaFloatObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaComplexArray_oaFloat_doc[] = 
"Class: oaComplexArray_oaFloat\n"
"  The oaComplexArray template class represents an array of complex numbers, each of which has a real and an imaginary part.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaComplexArray_oaFloat()\n"
"    Signature: oaComplexArray_oaFloat||simple-oaUInt4,\n"
"    This function constructs an oaComplexArray object, setting the number of array elements and allocating storage for the complex numbers.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaComplexArray_oaFloat(oaUInt4 sizeIn)\n"
"    Signature: oaComplexArray_oaFloat||simple-oaUInt4,\n"
"    This function constructs an oaComplexArray object, setting the number of array elements and allocating storage for the complex numbers.\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: oaComplexArray_oaFloat(const oaComplexArray_oaFloat& array)\n"
"    Signature: oaComplexArray_oaFloat||cref-oaComplexArray_oaFloat,\n"
"    This function constructs a copy of the specified oaComplexArray array .\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: (const oaComplexArray_oaFloat&)\n"
"    Signature: oaComplexArray_oaFloat||cref-oaComplexArray_oaFloat,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaComplexArray_oaFloat_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaComplexArray_oaFloat",
    sizeof(PyoaComplexArray_oaFloatObject),
    0,
    (destructor)oaComplexArray_oaFloat_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaComplexArray_oaFloat_tp_compare,	/* tp_compare */
    (reprfunc)oaComplexArray_oaFloat_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaComplexArray_oaFloat_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaComplex_oaFloat_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaComplexArray_oaFloat_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaComplexArray_oaFloat_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaComplexArray_oaFloat_Type)<0) {
      printf("** PyType_Ready failed for: oaComplexArray_oaFloat\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaComplexArray_oaFloat",
           (PyObject*)(&PyoaComplexArray_oaFloat_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaComplexArray_oaFloat\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConnFig
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConnFig_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConnFig_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConnFigObject* self = (PyoaConnFigObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConnFig)
    {
        PyParamoaConnFig p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConnFig_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConnFig, Choices are:\n"
        "    (oaConnFig)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConnFig_tp_dealloc(PyoaConnFigObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConnFig_tp_repr(PyObject *ob)
{
    PyParamoaConnFig value;
    int convert_status=PyoaConnFig_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaConnFig::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConnFig_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConnFig v1;
    PyParamoaConnFig v2;
    int convert_status1=PyoaConnFig_Convert(ob1,&v1);
    int convert_status2=PyoaConnFig_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConnFig_Convert(PyObject* ob,PyParamoaConnFig* result)
{
    if (ob == NULL) return 1;
    if (PyoaConnFig_Check(ob)) {
        result->SetData( (oaConnFig**) ((PyoaConnFigObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConnFig Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConnFig_FromoaConnFig(oaConnFig** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConnFig* data=*value;
        if (data->getType()==oacSteinerType) return PyoaSteiner_FromoaSteiner((oaSteiner**)value,borrow,lock);
        if (data->getType()==oacRouteType) return PyoaRoute_FromoaRoute((oaRoute**)value,borrow,lock);
        if (data->getType()==oacGuideType) return PyoaGuide_FromoaGuide((oaGuide**)value,borrow,lock);
        if (data->isPinFig()) return PyoaPinFig_FromoaPinFig((oaPinFig**)value,borrow,lock);
        PyObject* bself = PyoaConnFig_Type.tp_alloc(&PyoaConnFig_Type,0);
        if (bself == NULL) return bself;
        PyoaConnFigObject* self = (PyoaConnFigObject*)bself;
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
PyObject* PyoaConnFig_FromoaConnFig(oaConnFig* data)
{
    if (data) {
        if (data->getType()==oacSteinerType) return PyoaSteiner_FromoaSteiner((oaSteiner*)data);
        if (data->getType()==oacRouteType) return PyoaRoute_FromoaRoute((oaRoute*)data);
        if (data->getType()==oacGuideType) return PyoaGuide_FromoaGuide((oaGuide*)data);
        if (data->isPinFig()) return PyoaPinFig_FromoaPinFig((oaPinFig*)data);
       PyObject* bself = PyoaConnFig_Type.tp_alloc(&PyoaConnFig_Type,0);
       if (bself == NULL) return bself;
       PyoaConnFigObject* self = (PyoaConnFigObject*)bself;
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
static char oaConnFig_addToNet_doc[] = 
"Class: oaConnFig, Function: addToNet\n"
"  Paramegers: (oaNet)\n"
"    Calls: void addToNet(oaNet* net)\n"
"    Signature: addToNet|void-void|ptr-oaNet,\n"
"    This function adds this figure to the specified net. If this figure is already connected to another net, it is detached from the other net first.\n"
"    net\n"
"    The net to attach to the figure\n"
"    oacNetFigNotInSameBlock\n"
"    oacCannotAddFigToImplicitNet\n"
"    oacCannotAddPinFigToNet\n"
"    oacCannotAddRouteFigToNet\n"
"    oacCannotAddViaToNonBitNet\n"
"    oacCannotAddSteinerToNonBitNet\n"
;

static PyObject*
oaConnFig_addToNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnFig data;
    int convert_status=PyoaConnFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnFigObject* self=(PyoaConnFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addToNet(p1.Data());
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
static char oaConnFig_getNet_doc[] = 
"Class: oaConnFig, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: oaNet* getNet() const\n"
"    Signature: getNet|ptr-oaNet|\n"
"    BrowseData: 1\n"
"    This function returns the net this figure implements. If this figure does not implement a net, NULL is returned.\n"
"    Note that this function returns a net if the shape is directly assigned to a net or if the shape is in a route that is assigned to a net. If the shape belongs to a pin, it does not return a net but returns NULL .\n"
;

static PyObject*
oaConnFig_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnFig data;
    int convert_status=PyoaConnFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnFigObject* self=(PyoaConnFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaNetp result= (data.DataCall()->getNet());
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
static char oaConnFig_hasNet_doc[] = 
"Class: oaConnFig, Function: hasNet\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasNet() const\n"
"    Signature: hasNet|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates whether this figure implements a net.\n"
;

static PyObject*
oaConnFig_hasNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnFig data;
    int convert_status=PyoaConnFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnFigObject* self=(PyoaConnFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasNet());
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
static char oaConnFig_removeFromNet_doc[] = 
"Class: oaConnFig, Function: removeFromNet\n"
"  Paramegers: ()\n"
"    Calls: void removeFromNet()\n"
"    Signature: removeFromNet|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this figure from the net to which it is attached. If this figure is not attached to a net, this function does nothing.\n"
"    oacCannotRemoveRouteFigFromNet\n"
;

static PyObject*
oaConnFig_removeFromNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnFig data;
    int convert_status=PyoaConnFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnFigObject* self=(PyoaConnFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->removeFromNet();
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
static char oaConnFig_isNull_doc[] =
"Class: oaConnFig, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConnFig_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConnFig data;
    int convert_status=PyoaConnFig_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConnFig_assign_doc[] = 
"Class: oaConnFig, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConnFig_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConnFig data;
  int convert_status=PyoaConnFig_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConnFig p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConnFig_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConnFig_methodlist[] = {
    {"addToNet",(PyCFunction)oaConnFig_addToNet,METH_VARARGS,oaConnFig_addToNet_doc},
    {"getNet",(PyCFunction)oaConnFig_getNet,METH_VARARGS,oaConnFig_getNet_doc},
    {"hasNet",(PyCFunction)oaConnFig_hasNet,METH_VARARGS,oaConnFig_hasNet_doc},
    {"removeFromNet",(PyCFunction)oaConnFig_removeFromNet,METH_VARARGS,oaConnFig_removeFromNet_doc},
    {"isNull",(PyCFunction)oaConnFig_tp_isNull,METH_VARARGS,oaConnFig_isNull_doc},
    {"assign",(PyCFunction)oaConnFig_tp_assign,METH_VARARGS,oaConnFig_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConnFig_doc[] = 
"Class: oaConnFig\n"
"  The oaConnFig class is an abstract class that is the base for all OpenAccess database figures that can represent connectivity, including pinFigs, guides and routes.\n"
"Constructors:\n"
"  Paramegers: (oaConnFig)\n"
"    Calls: (const oaConnFig&)\n"
"    Signature: oaConnFig||cref-oaConnFig,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConnFig_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConnFig",
    sizeof(PyoaConnFigObject),
    0,
    (destructor)oaConnFig_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConnFig_tp_compare,	/* tp_compare */
    (reprfunc)oaConnFig_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConnFig_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConnFig_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConnFig_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConnFig_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConnFig_Type)<0) {
      printf("** PyType_Ready failed for: oaConnFig\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConnFig",
           (PyObject*)(&PyoaConnFig_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConnFig\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConnStatus
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConnStatus_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConnStatus_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConnStatusObject* self = (PyoaConnStatusObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConnStatusEnum)
    {
        PyParamoaConnStatusEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConnStatusEnum_Convert,&p1)) {
            self->value =  new oaConnStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaConnStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaConnStatus)
    {
        PyParamoaConnStatus p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConnStatus_Convert,&p1)) {
            self->value= new oaConnStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConnStatus, Choices are:\n"
        "    (oaConnStatusEnum)\n"
        "    (oaString)\n"
        "    (oaConnStatus)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConnStatus_tp_dealloc(PyoaConnStatusObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConnStatus_tp_repr(PyObject *ob)
{
    PyParamoaConnStatus value;
    int convert_status=PyoaConnStatus_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[34];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaConnStatus::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConnStatus_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConnStatus v1;
    PyParamoaConnStatus v2;
    int convert_status1=PyoaConnStatus_Convert(ob1,&v1);
    int convert_status2=PyoaConnStatus_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConnStatus_Convert(PyObject* ob,PyParamoaConnStatus* result)
{
    if (ob == NULL) return 1;
    if (PyoaConnStatus_Check(ob)) {
        result->SetData(  ((PyoaConnStatusObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConnStatus Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConnStatus_FromoaConnStatus(oaConnStatus* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConnStatus_Type.tp_alloc(&PyoaConnStatus_Type,0);
        if (bself == NULL) return bself;
        PyoaConnStatusObject* self = (PyoaConnStatusObject*)bself;
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
static char oaConnStatus_getName_doc[] = 
"Class: oaConnStatus, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaConnStatusEnum object.\n"
;

static PyObject*
oaConnStatus_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnStatus data;
    int convert_status=PyoaConnStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnStatusObject* self=(PyoaConnStatusObject*)ob;

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
static char oaConnStatus_oaConnStatusEnum_doc[] = 
"Class: oaConnStatus, Function: oaConnStatusEnum\n"
"  Paramegers: ()\n"
"    Calls: oaConnStatusEnum oaConnStatusEnum() const\n"
"    Signature: operator oaConnStatusEnum|simple-oaConnStatusEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaConnStatus object into the corresponding #oaConnStatusEnum value.\n"
;

static PyObject*
oaConnStatus_oaConnStatusEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnStatus data;
    int convert_status=PyoaConnStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnStatusObject* self=(PyoaConnStatusObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConnStatusEnum result= (data.DataCall()->operator oaConnStatusEnum());
        return PyoaConnStatusEnum_FromoaConnStatusEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaConnStatus_assign_doc[] = 
"Class: oaConnStatus, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConnStatus_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConnStatus data;
  int convert_status=PyoaConnStatus_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConnStatus p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConnStatus_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConnStatus_methodlist[] = {
    {"getName",(PyCFunction)oaConnStatus_getName,METH_VARARGS,oaConnStatus_getName_doc},
    {"oaConnStatusEnum",(PyCFunction)oaConnStatus_oaConnStatusEnum,METH_VARARGS,oaConnStatus_oaConnStatusEnum_doc},
    {"assign",(PyCFunction)oaConnStatus_tp_assign,METH_VARARGS,oaConnStatus_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConnStatus_doc[] = 
"Class: oaConnStatus\n"
"  The oaConnStatus class is an enum wrapper for the values that describe whether a net's connectivity may be changed by operations like optimization and buffer insertion. See oaNet::getConnStatus for its usage.\n"
"  OpenAccess does not enforce these settings. Tools that modify the connectivity must enforce them.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaConnStatusEnum\n"
"Constructors:\n"
"  Paramegers: (oaConnStatusEnum)\n"
"    Calls: oaConnStatus(oaConnStatusEnum valueIn)\n"
"    Signature: oaConnStatus||simple-oaConnStatusEnum,\n"
"    This function constructs an instance of an oaConnStatus class using the specified #oaConnStatusEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaConnStatus(const oaString& name)\n"
"    Signature: oaConnStatus||cref-oaString,\n"
"    This function constructs an instance of an oaConnStatus class using the #oaConnStatusEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaConnStatusEnum.\n"
"    oacInvalidConnStatusName\n"
"  Paramegers: (oaConnStatus)\n"
"    Calls: (const oaConnStatus&)\n"
"    Signature: oaConnStatus||cref-oaConnStatus,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConnStatus_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConnStatus",
    sizeof(PyoaConnStatusObject),
    0,
    (destructor)oaConnStatus_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConnStatus_tp_compare,	/* tp_compare */
    (reprfunc)oaConnStatus_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConnStatus_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConnStatus_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConnStatus_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConnStatus_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConnStatus_Type)<0) {
      printf("** PyType_Ready failed for: oaConnStatus\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConnStatus",
           (PyObject*)(&PyoaConnStatus_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConnStatus\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConnStatusEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConnStatusEnum_Convert(PyObject* ob,PyParamoaConnStatusEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNormalConnStatus")==0) { result->SetData(oacNormalConnStatus); return 1;}
        if (strcasecmp(str,"oacFixedConnStatus")==0) { result->SetData(oacFixedConnStatus); return 1;}
        if (strcasecmp(str,"oacLockedConnStatus")==0) { result->SetData(oacLockedConnStatus); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConnStatusEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConnStatusEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConnStatusEnum_FromoaConnStatusEnum(oaConnStatusEnum ob)
{
    if (ob==oacNormalConnStatus) return PyString_FromString("oacNormalConnStatus");
    if (ob==oacFixedConnStatus) return PyString_FromString("oacFixedConnStatus");
    if (ob==oacLockedConnStatus) return PyString_FromString("oacLockedConnStatus");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConnStatusEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConnStatusEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConnStatusEnum_FromoaConnStatusEnum(oaConnStatusEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConnStatusEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConnStatusEnum_doc[] =
"Type convert function for enum: oaConnStatusEnum";
                               
static PyMethodDef PyoaConnStatusEnum_method =
  {"oaConnStatusEnum",(PyCFunction)PyoaConnStatusEnum_TypeFunction,METH_VARARGS,oaConnStatusEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConnStatusEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNormalConnStatus");
    PyDict_SetItemString(mod_dict,"oacNormalConnStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFixedConnStatus");
    PyDict_SetItemString(mod_dict,"oacFixedConnStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLockedConnStatus");
    PyDict_SetItemString(mod_dict,"oacLockedConnStatus",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConnStatusEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConnStatusEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConnStatusEnum\n");
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
// Wrapper Implementation for Class: oaConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConnectDefObject* self = (PyoaConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConnectDef)
    {
        PyParamoaConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConnectDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConnectDef, Choices are:\n"
        "    (oaConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConnectDef_tp_dealloc(PyoaConnectDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaConnectDef value;
    int convert_status=PyoaConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConnectDef v1;
    PyParamoaConnectDef v2;
    int convert_status1=PyoaConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConnectDef_Convert(PyObject* ob,PyParamoaConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaConnectDef_Check(ob)) {
        result->SetData( (oaConnectDef**) ((PyoaConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConnectDef_FromoaConnectDef(oaConnectDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConnectDef* data=*value;
        if (data->getType()==oacTermConnectDefType) return PyoaTermConnectDef_FromoaTermConnectDef((oaTermConnectDef**)value,borrow,lock);
        if (data->getType()==oacNetConnectDefType) return PyoaNetConnectDef_FromoaNetConnectDef((oaNetConnectDef**)value,borrow,lock);
        PyObject* bself = PyoaConnectDef_Type.tp_alloc(&PyoaConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaConnectDefObject* self = (PyoaConnectDefObject*)bself;
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
PyObject* PyoaConnectDef_FromoaConnectDef(oaConnectDef* data)
{
    if (data) {
        if (data->getType()==oacTermConnectDefType) return PyoaTermConnectDef_FromoaTermConnectDef((oaTermConnectDef*)data);
        if (data->getType()==oacNetConnectDefType) return PyoaNetConnectDef_FromoaNetConnectDef((oaNetConnectDef*)data);
       PyObject* bself = PyoaConnectDef_Type.tp_alloc(&PyoaConnectDef_Type,0);
       if (bself == NULL) return bself;
       PyoaConnectDefObject* self = (PyoaConnectDefObject*)bself;
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
static char oaConnectDef_destroy_doc[] = 
"Class: oaConnectDef, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this connection definition.\n"
;

static PyObject*
oaConnectDef_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnectDef data;
    int convert_status=PyoaConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnectDefObject* self=(PyoaConnectDefObject*)ob;
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
static char oaConnectDef_getAssignmentDef_doc[] = 
"Class: oaConnectDef, Function: getAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void getAssignmentDef(oaAssignmentDef& assignmentDef) const\n"
"    Signature: getAssignmentDef|void-void|ref-oaAssignmentDef,\n"
"    BrowseData: 0,oaAssignmentDef\n"
"    This function returns the connection definition of this oaConnectDef in the specified assignmentDef .\n"
;

static PyObject*
oaConnectDef_getAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConnectDef data;
    int convert_status=PyoaConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConnectDefObject* self=(PyoaConnectDefObject*)ob;
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
static char oaConnectDef_isNull_doc[] =
"Class: oaConnectDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConnectDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConnectDef data;
    int convert_status=PyoaConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConnectDef_assign_doc[] = 
"Class: oaConnectDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConnectDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConnectDef data;
  int convert_status=PyoaConnectDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConnectDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConnectDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConnectDef_methodlist[] = {
    {"destroy",(PyCFunction)oaConnectDef_destroy,METH_VARARGS,oaConnectDef_destroy_doc},
    {"getAssignmentDef",(PyCFunction)oaConnectDef_getAssignmentDef,METH_VARARGS,oaConnectDef_getAssignmentDef_doc},
    {"isNull",(PyCFunction)oaConnectDef_tp_isNull,METH_VARARGS,oaConnectDef_isNull_doc},
    {"assign",(PyCFunction)oaConnectDef_tp_assign,METH_VARARGS,oaConnectDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConnectDef_doc[] = 
"Class: oaConnectDef\n"
"  The oaConnectDef class is an abstract base for all types of connection definitions. A connection definition associates an assignment definition (defined by an oaAssignmentDef ) with either a net or a terminal.\n"
"  The oaConnectDef classes allow you to specify that the net name of a connection may be assigned a different name. The new name is specified by a corresponding oaAssignment . If there is no corresponding oaAssignment , the default name specified in the oaConnectDef is used.\n"
"  An oaConnectDef is usually associated with a global net or a terminal representing a global net. This provides you with\n"
"  easier specification of multiple power supplies\n"
"  easier specification of substrate connections\n"
"  the use of parameterized power and ground symbols\n"
"  The oaConnectDef class can be observed by deriving from\n"
"  See oaNetConnectDef and oaTermConnectDef for more information about connection definitions on net and terminal objects. Also see oaAssignment for information regarding how assignments are made and interpreted.\n"
"  This functionality is also known as inherited connections .\n"
"  Note: Not all applications support resolving connectivity specified with connection definitions and assignments. You should verify that downstream consumers of the data are able to resolve such connectivity.\n"
"Constructors:\n"
"  Paramegers: (oaConnectDef)\n"
"    Calls: (const oaConnectDef&)\n"
"    Signature: oaConnectDef||cref-oaConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConnectDef",
    sizeof(PyoaConnectDefObject),
    0,
    (destructor)oaConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConnectDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConnectDef",
           (PyObject*)(&PyoaConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConnectDefModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConnectDefModTypeEnum_Convert(PyObject* ob,PyParamoaConnectDefModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConnectDefModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConnectDefModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(oaConnectDefModTypeEnum ob)
{

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConnectDefModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConnectDefModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(oaConnectDefModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConnectDefModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConnectDefModTypeEnum_doc[] =
"Type convert function for enum: oaConnectDefModTypeEnum";
                               
static PyMethodDef PyoaConnectDefModTypeEnum_method =
  {"oaConnectDefModTypeEnum",(PyCFunction)PyoaConnectDefModTypeEnum_TypeFunction,METH_VARARGS,oaConnectDefModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConnectDefModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConnectDefModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConnectDefModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConnectDefModTypeEnum\n");
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
// Wrapper Implementation for Class: oaConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintObject* self = (PyoaConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraint)
    {
        PyParamoaConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraint_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraint, Choices are:\n"
        "    (oaConstraint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraint_tp_dealloc(PyoaConstraintObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraint_tp_repr(PyObject *ob)
{
    PyParamoaConstraint value;
    int convert_status=PyoaConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraint v1;
    PyParamoaConstraint v2;
    int convert_status1=PyoaConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraint_Convert(PyObject* ob,PyParamoaConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraint_Check(ob)) {
        result->SetData( (oaConstraint**) ((PyoaConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraint_FromoaConstraint(oaConstraint** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraint* data=*value;
        if (data->getType()==oacLayerArrayConstraintType) return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint((oaLayerArrayConstraint**)value,borrow,lock);
        if (data->getType()==oacLayerPairConstraintType) return PyoaLayerPairConstraint_FromoaLayerPairConstraint((oaLayerPairConstraint**)value,borrow,lock);
        if (data->getType()==oacSimpleConstraintType) return PyoaSimpleConstraint_FromoaSimpleConstraint((oaSimpleConstraint**)value,borrow,lock);
        if (data->getType()==oacLayerConstraintType) return PyoaLayerConstraint_FromoaLayerConstraint((oaLayerConstraint**)value,borrow,lock);
        PyObject* bself = PyoaConstraint_Type.tp_alloc(&PyoaConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintObject* self = (PyoaConstraintObject*)bself;
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
PyObject* PyoaConstraint_FromoaConstraint(oaConstraint* data)
{
    if (data) {
        if (data->getType()==oacLayerArrayConstraintType) return PyoaLayerArrayConstraint_FromoaLayerArrayConstraint((oaLayerArrayConstraint*)data);
        if (data->getType()==oacLayerPairConstraintType) return PyoaLayerPairConstraint_FromoaLayerPairConstraint((oaLayerPairConstraint*)data);
        if (data->getType()==oacSimpleConstraintType) return PyoaSimpleConstraint_FromoaSimpleConstraint((oaSimpleConstraint*)data);
        if (data->getType()==oacLayerConstraintType) return PyoaLayerConstraint_FromoaLayerConstraint((oaLayerConstraint*)data);
       PyObject* bself = PyoaConstraint_Type.tp_alloc(&PyoaConstraint_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintObject* self = (PyoaConstraintObject*)bself;
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
static char oaConstraint_destroy_doc[] = 
"Class: oaConstraint, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this constraint removing it from any constraint groups it is a part of.\n"
;

static PyObject*
oaConstraint_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
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
static char oaConstraint_getDef_doc[] = 
"Class: oaConstraint, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintDef* getDef() const\n"
"    Signature: getDef|ptr-oaConstraintDef|\n"
"    BrowseData: 1\n"
"    This function returns the definition for this constraint.\n"
;

static PyObject*
oaConstraint_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintDefp result= (data.DataCall()->getDef());
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
static char oaConstraint_getDescription_doc[] = 
"Class: oaConstraint, Function: getDescription\n"
"  Paramegers: (oaString)\n"
"    Calls: void getDescription(oaString& description) const\n"
"    Signature: getDescription|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the description string of this constraint.\n"
"    descOut\n"
"    The string description of this constraint.\n"
;

static PyObject*
oaConstraint_getDescription(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getDescription(p1.Data());
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
static char oaConstraint_getID_doc[] = 
"Class: oaConstraint, Function: getID\n"
"  Paramegers: (oaString)\n"
"    Calls: void getID(oaString& id) const\n"
"    Signature: getID|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the id string of this constraint.\n"
"    idOut\n"
"    The string id of this constraint\n"
;

static PyObject*
oaConstraint_getID(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getID(p1.Data());
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
static char oaConstraint_getName_doc[] = 
"Class: oaConstraint, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this constraint. If a name wasn't specified on creation one is automatically generated.\n"
"    name\n"
"    The returned name\n"
;

static PyObject*
oaConstraint_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
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
static char oaConstraint_getParams_doc[] = 
"Class: oaConstraint, Function: getParams\n"
"  Paramegers: (oaConstraintParamArray)\n"
"    Calls: void getParams(oaConstraintParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaConstraintParamArray,\n"
"    BrowseData: 0,oaConstraintParamArray\n"
"    This function returns the parameters associated with this constraint\n"
"    params\n"
"    The returned constraint parameters\n"
;

static PyObject*
oaConstraint_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaConstraintParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamArray_Convert,&p1)) {
        data.DataCall()->getParams(p1.Data());
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
static char oaConstraint_getValue_doc[] = 
"Class: oaConstraint, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getValue() const\n"
"    Signature: getValue|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the value for this constraint\n"
;

static PyObject*
oaConstraint_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getValue());
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
static char oaConstraint_hasParams_doc[] = 
"Class: oaConstraint, Function: hasParams\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasParams() const\n"
"    Signature: hasParams|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not the constraint has parameters associated with it.\n"
;

static PyObject*
oaConstraint_hasParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasParams());
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
static char oaConstraint_isHard_doc[] = 
"Class: oaConstraint, Function: isHard\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isHard() const\n"
"    Signature: isHard|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicated whether or not this is a hard constraint.\n"
;

static PyObject*
oaConstraint_isHard(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isHard());
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
static char oaConstraint_setDescription_doc[] = 
"Class: oaConstraint, Function: setDescription\n"
"  Paramegers: (oaString)\n"
"    Calls: void setDescription(const oaString& description)\n"
"    Signature: setDescription|void-void|cref-oaString,\n"
"    This function sets the description string of this constraint.\n"
"    descIn\n"
"    The string description to be set on this constraint.\n"
;

static PyObject*
oaConstraint_setDescription(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setDescription(p1.Data());
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
static char oaConstraint_setHard_doc[] = 
"Class: oaConstraint, Function: setHard\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setHard(oaBoolean isHard)\n"
"    Signature: setHard|void-void|simple-oaBoolean,\n"
"    oaConstraint::setHard\n"
"    This function sets a boolean attribute on the constraint indicating whether or not it is hard.\n"
"    isHard\n"
"    A boolean indicating whether or not the constraint is a hard constraint\n"
;

static PyObject*
oaConstraint_setHard(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setHard(p1.Data());
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
static char oaConstraint_setID_doc[] = 
"Class: oaConstraint, Function: setID\n"
"  Paramegers: (oaString)\n"
"    Calls: void setID(const oaString& id)\n"
"    Signature: setID|void-void|cref-oaString,\n"
"    This function sets the ID string of this constraint.\n"
"    idIn\n"
"    The string id to be set on this constraint.\n"
;

static PyObject*
oaConstraint_setID(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setID(p1.Data());
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
static char oaConstraint_setParams_doc[] = 
"Class: oaConstraint, Function: setParams\n"
"  Paramegers: (oaConstraintParamArray)\n"
"    Calls: void setParams(const oaConstraintParamArray& params)\n"
"    Signature: setParams|void-void|cref-oaConstraintParamArray,\n"
"    This function sets the parameters for this constraint. The old parameters are destroyed.\n"
"    params\n"
"    Constraint parameters to set.\n"
"    oacConstraintParamAlreadyOwned\n"
"    oacConstraintParamNotInSameDB\n"
;

static PyObject*
oaConstraint_setParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaConstraintParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamArray_Convert,&p1)) {
        data.DataCall()->setParams(p1.Data());
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
static char oaConstraint_setValue_doc[] = 
"Class: oaConstraint, Function: setValue\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setValue(oaValue* value)\n"
"    Signature: setValue|void-void|ptr-oaValue,\n"
"    This function sets the value for this constraint. The old value is destroyed.\n"
"    value\n"
"    Value to set\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacInvalidValueForConstraintDef\n"
;

static PyObject*
oaConstraint_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintObject* self=(PyoaConstraintObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setValue(p1.Data());
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
static char oaConstraint_isNull_doc[] =
"Class: oaConstraint, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraint_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraint data;
    int convert_status=PyoaConstraint_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraint_assign_doc[] = 
"Class: oaConstraint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraint data;
  int convert_status=PyoaConstraint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraint_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraint_methodlist[] = {
    {"destroy",(PyCFunction)oaConstraint_destroy,METH_VARARGS,oaConstraint_destroy_doc},
    {"getDef",(PyCFunction)oaConstraint_getDef,METH_VARARGS,oaConstraint_getDef_doc},
    {"getDescription",(PyCFunction)oaConstraint_getDescription,METH_VARARGS,oaConstraint_getDescription_doc},
    {"getID",(PyCFunction)oaConstraint_getID,METH_VARARGS,oaConstraint_getID_doc},
    {"getName",(PyCFunction)oaConstraint_getName,METH_VARARGS,oaConstraint_getName_doc},
    {"getParams",(PyCFunction)oaConstraint_getParams,METH_VARARGS,oaConstraint_getParams_doc},
    {"getValue",(PyCFunction)oaConstraint_getValue,METH_VARARGS,oaConstraint_getValue_doc},
    {"hasParams",(PyCFunction)oaConstraint_hasParams,METH_VARARGS,oaConstraint_hasParams_doc},
    {"isHard",(PyCFunction)oaConstraint_isHard,METH_VARARGS,oaConstraint_isHard_doc},
    {"setDescription",(PyCFunction)oaConstraint_setDescription,METH_VARARGS,oaConstraint_setDescription_doc},
    {"setHard",(PyCFunction)oaConstraint_setHard,METH_VARARGS,oaConstraint_setHard_doc},
    {"setID",(PyCFunction)oaConstraint_setID,METH_VARARGS,oaConstraint_setID_doc},
    {"setParams",(PyCFunction)oaConstraint_setParams,METH_VARARGS,oaConstraint_setParams_doc},
    {"setValue",(PyCFunction)oaConstraint_setValue,METH_VARARGS,oaConstraint_setValue_doc},
    {"isNull",(PyCFunction)oaConstraint_tp_isNull,METH_VARARGS,oaConstraint_isNull_doc},
    {"assign",(PyCFunction)oaConstraint_tp_assign,METH_VARARGS,oaConstraint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraint_doc[] = 
"Class: oaConstraint\n"
"  The oaConstraint class provides a base class for all kinds of constraint representations. All constraint objects are defined by the constraintDef. They have a value associated with them and potentially a list of constraint parameters. A constraint may or may not be a hard constraint. A hard constraint is a constraint that must be met.\n"
"  oaConstraints always have a value, and are created in the same database as that value. oaConstraints get applied to objects by being placed in an oaConstraintGroup .\n"
"  The oaConstraint class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaConstraint)\n"
"    Calls: (const oaConstraint&)\n"
"    Signature: oaConstraint||cref-oaConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraint",
    sizeof(PyoaConstraintObject),
    0,
    (destructor)oaConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraint",
           (PyObject*)(&PyoaConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraint\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintCollectionObject* self = (PyoaConstraintCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaObject)
    {
        PyParamoaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaObject_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaConstraintCollection(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaUInt4)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaConstraintCollection(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintCollection)
    {
        PyParamoaConstraintCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintCollection_Convert,&p1)) {
            self->value =  new oaConstraintCollection(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintCollection, Choices are:\n"
        "    (oaObject)\n"
        "    (oaObject,oaUInt4)\n"
        "    (oaConstraintCollection)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintCollection_tp_dealloc(PyoaConstraintCollectionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintCollection_tp_repr(PyObject *ob)
{
    PyParamoaConstraintCollection value;
    int convert_status=PyoaConstraintCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaConstraintCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintCollection v1;
    PyParamoaConstraintCollection v2;
    int convert_status1=PyoaConstraintCollection_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintCollection_Convert(PyObject* ob,PyParamoaConstraintCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintCollection_Check(ob)) {
        result->SetData(  ((PyoaConstraintCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintCollection_FromoaConstraintCollection(oaConstraintCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConstraintCollection_Type.tp_alloc(&PyoaConstraintCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintCollectionObject* self = (PyoaConstraintCollectionObject*)bself;
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
static char oaConstraintCollection_getCount_doc[] = 
"Class: oaConstraintCollection, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaConstraintCollection_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintCollection data;
    int convert_status=PyoaConstraintCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintCollectionObject* self=(PyoaConstraintCollectionObject*)ob;

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
static char oaConstraintCollection_getDefIndex_doc[] = 
"Class: oaConstraintCollection, Function: getDefIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getDefIndex() const\n"
"    Signature: getDefIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getDefIndex\n"
;

static PyObject*
oaConstraintCollection_getDefIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintCollection data;
    int convert_status=PyoaConstraintCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintCollectionObject* self=(PyoaConstraintCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getDefIndex());
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
static char oaConstraintCollection_getIterAll_doc[] = 
"Class: oaConstraintCollection, Function: getIterAll\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean getIterAll() const\n"
"    Signature: getIterAll|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function getIterAll\n"
;

static PyObject*
oaConstraintCollection_getIterAll(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintCollection data;
    int convert_status=PyoaConstraintCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintCollectionObject* self=(PyoaConstraintCollectionObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->getIterAll());
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
static char oaConstraintCollection_includes_doc[] = 
"Class: oaConstraintCollection, Function: includes\n"
"  Paramegers: (oaConstraint)\n"
"    Calls: oaBoolean includes(const oaConstraint* constraint) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraint,\n"
"    Function includes\n"
;

static PyObject*
oaConstraintCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintCollection data;
    int convert_status=PyoaConstraintCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintCollectionObject* self=(PyoaConstraintCollectionObject*)ob;

    PyParamoaConstraint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraint_Convert,&p1)) {
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
static char oaConstraintCollection_isEmpty_doc[] = 
"Class: oaConstraintCollection, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaConstraintCollection_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintCollection data;
    int convert_status=PyoaConstraintCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintCollectionObject* self=(PyoaConstraintCollectionObject*)ob;

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

static char oaConstraintCollection_assign_doc[] = 
"Class: oaConstraintCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintCollection data;
  int convert_status=PyoaConstraintCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintCollection_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintCollection_methodlist[] = {
    {"getCount",(PyCFunction)oaConstraintCollection_getCount,METH_VARARGS,oaConstraintCollection_getCount_doc},
    {"getDefIndex",(PyCFunction)oaConstraintCollection_getDefIndex,METH_VARARGS,oaConstraintCollection_getDefIndex_doc},
    {"getIterAll",(PyCFunction)oaConstraintCollection_getIterAll,METH_VARARGS,oaConstraintCollection_getIterAll_doc},
    {"includes",(PyCFunction)oaConstraintCollection_includes,METH_VARARGS,oaConstraintCollection_includes_doc},
    {"isEmpty",(PyCFunction)oaConstraintCollection_isEmpty,METH_VARARGS,oaConstraintCollection_isEmpty_doc},
    {"assign",(PyCFunction)oaConstraintCollection_tp_assign,METH_VARARGS,oaConstraintCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintCollection_doc[] = 
"Class: oaConstraintCollection\n"
"  Class type oaConstraintCollection\n"
"Constructors:\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaConstraintCollection(const oaObject* database)\n"
"    Signature: oaConstraintCollection||cptr-oaObject,\n"
"    Constructor oaConstraintCollection\n"
"  Paramegers: (oaObject,oaUInt4)\n"
"    Calls: oaConstraintCollection(const oaObject* database,oaUInt4 defIndex)\n"
"    Signature: oaConstraintCollection||cptr-oaObject,simple-oaUInt4,\n"
"    Constructor oaConstraintCollection\n"
"  Paramegers: (oaConstraintCollection)\n"
"    Calls: oaConstraintCollection(const oaConstraintCollection& c)\n"
"    Signature: oaConstraintCollection||cref-oaConstraintCollection,\n"
"    Constructor oaConstraintCollection\n"
"  Paramegers: (oaConstraintCollection)\n"
"    Calls: (const oaConstraintCollection&)\n"
"    Signature: oaConstraintCollection||cref-oaConstraintCollection,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintCollection",
    sizeof(PyoaConstraintCollectionObject),
    0,
    (destructor)oaConstraintCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintCollection",
           (PyObject*)(&PyoaConstraintCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintCollection\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintDefObject* self = (PyoaConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintDef)
    {
        PyParamoaConstraintDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintDef, Choices are:\n"
        "    (oaConstraintDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintDef_tp_dealloc(PyoaConstraintDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaConstraintDef value;
    int convert_status=PyoaConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintDef v1;
    PyParamoaConstraintDef v2;
    int convert_status1=PyoaConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintDef_Convert(PyObject* ob,PyParamoaConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintDef_Check(ob)) {
        result->SetData( (oaConstraintDef**) ((PyoaConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintDef_FromoaConstraintDef(oaConstraintDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintDef* data=*value;
        if (data->getType()==oacLayerArrayConstraintDefType) return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef((oaLayerArrayConstraintDef**)value,borrow,lock);
        if (data->getType()==oacLayerPairConstraintDefType) return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef((oaLayerPairConstraintDef**)value,borrow,lock);
        if (data->getType()==oacLayerConstraintDefType) return PyoaLayerConstraintDef_FromoaLayerConstraintDef((oaLayerConstraintDef**)value,borrow,lock);
        if (data->getType()==oacSimpleConstraintDefType) return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef((oaSimpleConstraintDef**)value,borrow,lock);
        PyObject* bself = PyoaConstraintDef_Type.tp_alloc(&PyoaConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintDefObject* self = (PyoaConstraintDefObject*)bself;
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
PyObject* PyoaConstraintDef_FromoaConstraintDef(oaConstraintDef* data)
{
    if (data) {
        if (data->getType()==oacLayerArrayConstraintDefType) return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef((oaLayerArrayConstraintDef*)data);
        if (data->getType()==oacLayerPairConstraintDefType) return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef((oaLayerPairConstraintDef*)data);
        if (data->getType()==oacLayerConstraintDefType) return PyoaLayerConstraintDef_FromoaLayerConstraintDef((oaLayerConstraintDef*)data);
        if (data->getType()==oacSimpleConstraintDefType) return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef((oaSimpleConstraintDef*)data);
       PyObject* bself = PyoaConstraintDef_Type.tp_alloc(&PyoaConstraintDef_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintDefObject* self = (PyoaConstraintDefObject*)bself;
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
static char oaConstraintDef_destroy_doc[] = 
"Class: oaConstraintDef, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this constraint definition. If it is a built-in definition, or there are any databases referencing it, an error is thrown.\n"
"    oacUnableToDestroyBuiltInType\n"
"    oacConstraintDefHasReference\n"
;

static PyObject*
oaConstraintDef_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
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
static char oaConstraintDef_getDatabaseTypes_doc[] = 
"Class: oaConstraintDef, Function: getDatabaseTypes\n"
"  Paramegers: (oaSubset_oaDBType)\n"
"    Calls: void getDatabaseTypes(oaSubset_oaDBType& allowedDbs) const\n"
"    Signature: getDatabaseTypes|void-void|ref-oaSubset_oaDBType,\n"
"    BrowseData: 0,oaSubset_oaDBType\n"
"    This function returns the types of databases that a constraint specified with this definition can be created in.\n"
"    allowedDbs\n"
"    The databases allowed.\n"
;

static PyObject*
oaConstraintDef_getDatabaseTypes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSubset_oaDBType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubset_oaDBType_Convert,&p1)) {
        data.DataCall()->getDatabaseTypes(p1.Data());
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
static char oaConstraintDef_getName_doc[] = 
"Class: oaConstraintDef, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this constraint definition.\n"
"    name\n"
"    The returned name.\n"
;

static PyObject*
oaConstraintDef_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
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
static char oaConstraintDef_getObjectTypes_doc[] = 
"Class: oaConstraintDef, Function: getObjectTypes\n"
"  Paramegers: (oaSubset_oaType)\n"
"    Calls: void getObjectTypes(oaSubset_oaType& allowedObjects) const\n"
"    Signature: getObjectTypes|void-void|ref-oaSubset_oaType,\n"
"    BrowseData: 0,oaSubset_oaType\n"
"    This function returns the types of objects that a constraint specified with this definition can be attached to.\n"
"    allowedObjects\n"
"    The objects allowed.\n"
;

static PyObject*
oaConstraintDef_getObjectTypes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSubset_oaType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubset_oaType_Convert,&p1)) {
        data.DataCall()->getObjectTypes(p1.Data());
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
static char oaConstraintDef_getValueTypes_doc[] = 
"Class: oaConstraintDef, Function: getValueTypes\n"
"  Paramegers: (oaSubset_oaType)\n"
"    Calls: void getValueTypes(oaSubset_oaType& allowedValues) const\n"
"    Signature: getValueTypes|void-void|ref-oaSubset_oaType,\n"
"    BrowseData: 0,oaSubset_oaType\n"
"    This function returns the allowed value types for a constraint specified with this definition.\n"
"    allowedValues\n"
"    The returned value types\n"
;

static PyObject*
oaConstraintDef_getValueTypes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSubset_oaType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSubset_oaType_Convert,&p1)) {
        data.DataCall()->getValueTypes(p1.Data());
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
static char oaConstraintDef_remove_doc[] = 
"Class: oaConstraintDef, Function: remove\n"
"  Paramegers: (oaObject)\n"
"    Calls: void remove(oaObject* database)\n"
"    Signature: remove|void-void|ptr-oaObject,\n"
"    This function removes this constraint definition from the specified database. If there are constraints in the specified database that reference this definition, an error is thrown.\n"
"    database\n"
"    The database to remove the constraint definition from.\n"
;

static PyObject*
oaConstraintDef_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintDefObject* self=(PyoaConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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

// ------------------------------------------------------------------
static char oaConstraintDef_isNull_doc[] =
"Class: oaConstraintDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintDef data;
    int convert_status=PyoaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintDef_assign_doc[] = 
"Class: oaConstraintDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintDef data;
  int convert_status=PyoaConstraintDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintDef_methodlist[] = {
    {"destroy",(PyCFunction)oaConstraintDef_destroy,METH_VARARGS,oaConstraintDef_destroy_doc},
    {"getDatabaseTypes",(PyCFunction)oaConstraintDef_getDatabaseTypes,METH_VARARGS,oaConstraintDef_getDatabaseTypes_doc},
    {"getName",(PyCFunction)oaConstraintDef_getName,METH_VARARGS,oaConstraintDef_getName_doc},
    {"getObjectTypes",(PyCFunction)oaConstraintDef_getObjectTypes,METH_VARARGS,oaConstraintDef_getObjectTypes_doc},
    {"getValueTypes",(PyCFunction)oaConstraintDef_getValueTypes,METH_VARARGS,oaConstraintDef_getValueTypes_doc},
    {"remove",(PyCFunction)oaConstraintDef_remove,METH_VARARGS,oaConstraintDef_remove_doc},
    {"isNull",(PyCFunction)oaConstraintDef_tp_isNull,METH_VARARGS,oaConstraintDef_isNull_doc},
    {"assign",(PyCFunction)oaConstraintDef_tp_assign,METH_VARARGS,oaConstraintDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintDef_doc[] = 
"Class: oaConstraintDef\n"
"  The oaConstraintDef object specifies a definition for a particular constraint. The definition contains a name, a list of databases that the constraint can be created in, and a list of types of oaValues that are allowed for the constraint. The names for constraint definitions must be unique.\n"
"  oaConstraintDefs can be built-in or user defined. Built-in oaConstraintDefs can be obtained with an enum, for example, using oaLayerConstraintDef::get() . User- defined oaConstraintDefs can be obtained by name using find() .\n"
"  The oaConstraintDef class can be observed by deriving from\n"
"  See Uniqueness of Session Objects for information about the requirement that session objects be unique.\n"
"Constructors:\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: (const oaConstraintDef&)\n"
"    Signature: oaConstraintDef||cref-oaConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintDef",
    sizeof(PyoaConstraintDefObject),
    0,
    (destructor)oaConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintDef_static_find_doc[] = 
"Class: oaConstraintDef, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaConstraintDef* find(const oaString& name)\n"
"    Signature: find|ptr-oaConstraintDef|cref-oaString,\n"
"    This function returns the constraint definition with the specified name. If no definition by that name is found, NULL is returned.\n"
"    name\n"
"    The name of the constraintDef to search for.\n"
;

static PyObject*
oaConstraintDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaConstraintDefp result= (oaConstraintDef::find(p1.Data()));
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
static PyMethodDef oaConstraintDef_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaConstraintDef_static_find,METH_VARARGS,oaConstraintDef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintDef",
           (PyObject*)(&PyoaConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintDef_Type.tp_dict;
    for(method=oaConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintGroupObject* self = (PyoaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintGroup)
    {
        PyParamoaConstraintGroup p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintGroup_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintGroup, Choices are:\n"
        "    (oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintGroup_tp_dealloc(PyoaConstraintGroupObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaConstraintGroup value;
    int convert_status=PyoaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintGroup v1;
    PyParamoaConstraintGroup v2;
    int convert_status1=PyoaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintGroup_Convert(PyObject* ob,PyParamoaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintGroup_Check(ob)) {
        result->SetData( (oaConstraintGroup**) ((PyoaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintGroup_FromoaConstraintGroup(oaConstraintGroup** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintGroup* data=*value;
        PyObject* bself = PyoaConstraintGroup_Type.tp_alloc(&PyoaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintGroupObject* self = (PyoaConstraintGroupObject*)bself;
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
PyObject* PyoaConstraintGroup_FromoaConstraintGroup(oaConstraintGroup* data)
{
    if (data) {
       PyObject* bself = PyoaConstraintGroup_Type.tp_alloc(&PyoaConstraintGroup_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintGroupObject* self = (PyoaConstraintGroupObject*)bself;
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
static char oaConstraintGroup_destroy_doc[] = 
"Class: oaConstraintGroup, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys the constraint group specified. The constraints in the group are not destroyed, but all of the groups members are.\n"
"    If the constraint group being destroyed is a member or another constraint group, that constraint group member is destroyed as well.\n"
;

static PyObject*
oaConstraintGroup_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
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
static char oaConstraintGroup_getConstraints_doc[] = 
"Class: oaConstraintGroup, Function: getConstraints\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaConstraint_oaConstraintGroup getConstraints() const\n"
"    Signature: getConstraints|simple-oaCollection_oaConstraint_oaConstraintGroup|cptr-oaConstraintDef,\n"
"    BrowseData: 1\n"
"    This function returns a collection of constraints in the this group whose definition matches the specified def . If no definition is specified, all simple constraints in this group are returned.\n"
"    Note that this function only searches this group and its subgroups. Referenced technology databases are not searched.\n"
"    def\n"
"    The constraint definition to search for\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: oaCollection_oaConstraint_oaConstraintGroup getConstraints(const oaConstraintDef* def) const\n"
"    Signature: getConstraints|simple-oaCollection_oaConstraint_oaConstraintGroup|cptr-oaConstraintDef,\n"
"    This function returns a collection of constraints in the this group whose definition matches the specified def . If no definition is specified, all simple constraints in this group are returned.\n"
"    Note that this function only searches this group and its subgroups. Referenced technology databases are not searched.\n"
"    def\n"
"    The constraint definition to search for\n"
;

static PyObject*
oaConstraintGroup_getConstraints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaConstraint_oaConstraintGroup* result= new oaCollection_oaConstraint_oaConstraintGroup(data.DataCall()->getConstraints());
            return PyoaCollection_oaConstraint_oaConstraintGroup_FromoaCollection_oaConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintDef)
    {
        PyParamoaConstraintDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintDef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaCollection_oaConstraint_oaConstraintGroup* result= new oaCollection_oaConstraint_oaConstraintGroup(data.DataCall()->getConstraints(p1.Data()));
            return PyoaCollection_oaConstraint_oaConstraintGroup_FromoaCollection_oaConstraint_oaConstraintGroup(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaConstraintGroup, function: getConstraints, Choices are:\n"
        "    ()\n"
        "    (oaConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroup_getConstraintsIter_doc[] = 
"Class: oaConstraintGroup, Function: getConstraintsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaConstraint getConstraintsIter() const\n"
"    Signature: getConstraintsIter|simple-oaIter_oaConstraint|cptr-oaConstraintDef,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of constraints in the this group whose definition matches the specified def . If no definition is specified, all simple constraints in this group are returned.\n"
"    Note that this function only searches this group and its subgroups. Referenced technology databases are not searched.\n"
"    def\n"
"    The constraint definition to search for\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: oaIter_oaConstraint getConstraintsIter(const oaConstraintDef* def) const\n"
"    Signature: getConstraintsIter|simple-oaIter_oaConstraint|cptr-oaConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of constraints in the this group whose definition matches the specified def . If no definition is specified, all simple constraints in this group are returned.\n"
"    Note that this function only searches this group and its subgroups. Referenced technology databases are not searched.\n"
"    def\n"
"    The constraint definition to search for\n"
;

static PyObject*
oaConstraintGroup_getConstraintsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaConstraint* result= new oaIter_oaConstraint(data.DataCall()->getConstraints());
            return PyoaIter_oaConstraint_FromoaIter_oaConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintDef)
    {
        PyParamoaConstraintDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintDef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaIter_oaConstraint* result= new oaIter_oaConstraint(data.DataCall()->getConstraints(p1.Data()));
            return PyoaIter_oaConstraint_FromoaIter_oaConstraint(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaConstraintGroup, function: getConstraintsIter, Choices are:\n"
        "    ()\n"
        "    (oaConstraintDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroup_getMembers_doc[] = 
"Class: oaConstraintGroup, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaConstraintGroupMem_oaConstraintGroup getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaConstraintGroupMem_oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    This function returns a collection of all of the members in this constraint group.\n"
;

static PyObject*
oaConstraintGroup_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaConstraintGroupMem_oaConstraintGroup* result= new oaCollection_oaConstraintGroupMem_oaConstraintGroup(data.DataCall()->getMembers());
        return PyoaCollection_oaConstraintGroupMem_oaConstraintGroup_FromoaCollection_oaConstraintGroupMem_oaConstraintGroup(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroup_getMembersIter_doc[] = 
"Class: oaConstraintGroup, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaConstraintGroupMem getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaConstraintGroupMem|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of all of the members in this constraint group.\n"
;

static PyObject*
oaConstraintGroup_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaConstraintGroupMem* result= new oaIter_oaConstraintGroupMem(data.DataCall()->getMembers());
        return PyoaIter_oaConstraintGroupMem_FromoaIter_oaConstraintGroupMem(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroup_getName_doc[] = 
"Class: oaConstraintGroup, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this constraint group.\n"
"    name\n"
"    String to return the name in.\n"
;

static PyObject*
oaConstraintGroup_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
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
static char oaConstraintGroup_getOwner_doc[] = 
"Class: oaConstraintGroup, Function: getOwner\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getOwner() const\n"
"    Signature: getOwner|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    For a constraint group associated with a particular owning object, this member function returns a pointer to that owning object. Specifically, constraint groups returned by the following functions will have their containing object returned by getOwner:\n"
"    oaObject::getConstraintGroup\n"
"    getDefaultConstraintGroup of various classes\n"
"    oaTech::getFoundryRules\n"
"    For constraint groups not owned by any object, getOwner returns NULL. Note that constraint groups created with oaConstraintGroup::create will have a NULL owner.\n"
;

static PyObject*
oaConstraintGroup_getOwner(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaObjectp result= (data.DataCall()->getOwner());
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
static char oaConstraintGroup_override_doc[] = 
"Class: oaConstraintGroup, Function: override\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean override() const\n"
"    Signature: override|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaConstraintGroup::override\n"
"    This function returns a boolean indicating whether the constraints in this group should override tighter constraints deeper in the precedence hierarchy.\n"
;

static PyObject*
oaConstraintGroup_override(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupObject* self=(PyoaConstraintGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->override());
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
static char oaConstraintGroup_isNull_doc[] =
"Class: oaConstraintGroup, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintGroup_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintGroup data;
    int convert_status=PyoaConstraintGroup_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintGroup_assign_doc[] = 
"Class: oaConstraintGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintGroup data;
  int convert_status=PyoaConstraintGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintGroup_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintGroup_methodlist[] = {
    {"destroy",(PyCFunction)oaConstraintGroup_destroy,METH_VARARGS,oaConstraintGroup_destroy_doc},
    {"getConstraints",(PyCFunction)oaConstraintGroup_getConstraints,METH_VARARGS,oaConstraintGroup_getConstraints_doc},
    {"getConstraintsIter",(PyCFunction)oaConstraintGroup_getConstraintsIter,METH_VARARGS,oaConstraintGroup_getConstraintsIter_doc},
    {"getMembers",(PyCFunction)oaConstraintGroup_getMembers,METH_VARARGS,oaConstraintGroup_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaConstraintGroup_getMembersIter,METH_VARARGS,oaConstraintGroup_getMembersIter_doc},
    {"getName",(PyCFunction)oaConstraintGroup_getName,METH_VARARGS,oaConstraintGroup_getName_doc},
    {"getOwner",(PyCFunction)oaConstraintGroup_getOwner,METH_VARARGS,oaConstraintGroup_getOwner_doc},
    {"override",(PyCFunction)oaConstraintGroup_override,METH_VARARGS,oaConstraintGroup_override_doc},
    {"isNull",(PyCFunction)oaConstraintGroup_tp_isNull,METH_VARARGS,oaConstraintGroup_isNull_doc},
    {"assign",(PyCFunction)oaConstraintGroup_tp_assign,METH_VARARGS,oaConstraintGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroup_doc[] = 
"Class: oaConstraintGroup\n"
"  The oaConstraintGroup class implements an ordered collection of constraint and constraint group objects.\n"
"  A number of oaConstraintGroups are built into OpenAccess databases. Every object that can have constraints has a built-in constraint group that is returned by oaObject::getConstraintGroup . The classes oaTech , oaRoute , oaNet , oaModule , oaGroup , oaFigGroup , oaDesign , oaBoundary , and oaBlock are container classes that have an additional default constraint group that is returned by getDefaultConstraintGroup on that class. An oaTech also has a foundry constraint group that is returned by oaTech::getFoundryRules .\n"
"  Applications also can explicitly create constraint groups to organize the access to their constraints and to provide a way to reuse a set of constraints. An application creates a constraint group by using the oaConstraintGroup::create function and adds objects to constraint groups by using the oaConstraintGroupMem::create function.\n"
"  The members of a constraint group are ordered and are intended to be searched in a depth-first manner. You can change the order of members in a constraintGroup by using oaConstraintGroupMem::moveToFirst and oaConstraintGroupMem::moveAfter functions.\n"
"  Constraint groups can be constructed in the design, technology and wafer databases. A constraint group can include members that are individual constraints, or that are themselves constraint groups. When talking about constraint groups, it is useful to think in terms of a parent constraint group, which includes individual constraints and other constraint groups as members.\n"
"  An individual constraint must be in the same database as its parent constraint group.\n"
"  A constraint group in a design or technology database may be added to a parent constraint group in a design database.\n"
"  In addition, a constraint group in a design or technology database can have a member that is a user-defined constraint group in a referenced technology database. See Using Technology Databases in the Programmers Guide for information about referenced technology databases.\n"
"  Wafer database constraint groups can only include members in their own database.\n"
"  All constraint groups have a unique name within a database (or across referenced technology databases). The database validates that no other group has the same name. The database also ensures that no other group is ever assigned the same name.\n"
"  The collection of constraint groups in a given database is implemented by the getConstraintGroups function in each database class. See oaDesign::getConstraintGroups , and oaTech::getConstraintGroups .\n"
"  The oaConstraintGroup class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaConstraintGroup)\n"
"    Calls: (const oaConstraintGroup&)\n"
"    Signature: oaConstraintGroup||cref-oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintGroup",
    sizeof(PyoaConstraintGroupObject),
    0,
    (destructor)oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroup_static_create_doc[] = 
"Class: oaConstraintGroup, Function: create\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaConstraintGroup* create(oaObject* database,const oaString& name)\n"
"    Signature: create|ptr-oaConstraintGroup|ptr-oaObject,cref-oaString,simple-oaBoolean,\n"
"    oaConstraintGroup::create\n"
"    This function creates a new constraint group in the specified database. The name of the constraint group is given and a boolean indicating whether the constraints in this group should override potentially tighter constraints deeper in the precedence hierarchy.\n"
"    database\n"
"    Database to create the constraint group in.\n"
"    name\n"
"    The constant oaString name that corresponds to the constraint group.\n"
"    override\n"
"    Boolean flag indicating whether this group overrides other constraints\n"
"    oacConstraintGroupNameExists\n"
"    oacInvalidDatabase\n"
"  Paramegers: (oaObject,oaString,oaBoolean)\n"
"    Calls: oaConstraintGroup* create(oaObject* database,const oaString& name,oaBoolean override)\n"
"    Signature: create|ptr-oaConstraintGroup|ptr-oaObject,cref-oaString,simple-oaBoolean,\n"
"    oaConstraintGroup::create\n"
"    This function creates a new constraint group in the specified database. The name of the constraint group is given and a boolean indicating whether the constraints in this group should override potentially tighter constraints deeper in the precedence hierarchy.\n"
"    database\n"
"    Database to create the constraint group in.\n"
"    name\n"
"    The constant oaString name that corresponds to the constraint group.\n"
"    override\n"
"    Boolean flag indicating whether this group overrides other constraints\n"
"    oacConstraintGroupNameExists\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaConstraintGroup_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaObject,oaString)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaConstraintGroupp result= (oaConstraintGroup::create(p1.Data(),p2.Data()));
            return PyoaConstraintGroup_FromoaConstraintGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaConstraintGroupp result= (oaConstraintGroup::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaConstraintGroup_FromoaConstraintGroup(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaConstraintGroup, function: create, Choices are:\n"
        "    (oaObject,oaString)\n"
        "    (oaObject,oaString,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroup_static_find_doc[] = 
"Class: oaConstraintGroup, Function: find\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaConstraintGroup* find(const oaObject* database,const oaString& name)\n"
"    Signature: find|ptr-oaConstraintGroup|cptr-oaObject,cref-oaString,\n"
"    This function searches the specified database for a constraint group with the specified name . If the specified database supports cross-database references, the referenced databases are searched as well and the first matching constraint group is returned. If no constraint group by that name is found, NULL is returned.\n"
"    To find a constraint group in the current database only, refer to the find function that accepts the local argument.\n"
"    database\n"
"    The database in which to search for this constraint group.\n"
"    name\n"
"    The constant oaString name of the constraint group to search for.\n"
"  Paramegers: (oaObject,oaString,oaBoolean)\n"
"    Calls: oaConstraintGroup* find(const oaObject* database,const oaString& name,oaBoolean local)\n"
"    Signature: find|ptr-oaConstraintGroup|cptr-oaObject,cref-oaString,simple-oaBoolean,\n"
"    oaConstraintGroup::find2\n"
"    This function searches the specified database for a constraint group with the specified name. The local argument specifies whether (if true) to look only in the specified database or (if false) to look in the specified database and all of its referenced databases. If the constraint group is found, a pointer to it is returned, otherwise NULL is returned.\n"
"    See Using Technology Databases in the Programmers Guide for information about referenced technology databases.\n"
"    database\n"
"    Database in which to search for the constraint group\n"
"    name\n"
"    Name of the constraint group to search for\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
"    Todo\n"
"    Place this function block in the oaConstraintGroup class block.\n"
;

static PyObject*
oaConstraintGroup_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaObject,oaString)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaConstraintGroupp result= (oaConstraintGroup::find(p1.Data(),p2.Data()));
            return PyoaConstraintGroup_FromoaConstraintGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaConstraintGroupp result= (oaConstraintGroup::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaConstraintGroup_FromoaConstraintGroup(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaConstraintGroup, function: find, Choices are:\n"
        "    (oaObject,oaString)\n"
        "    (oaObject,oaString,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaConstraintGroup_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaConstraintGroup_static_create,METH_VARARGS,oaConstraintGroup_static_create_doc},
    {"static_find",(PyCFunction)oaConstraintGroup_static_find,METH_VARARGS,oaConstraintGroup_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintGroup",
           (PyObject*)(&PyoaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintGroup\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintGroup_Type.tp_dict;
    for(method=oaConstraintGroup_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaConstraintGroupHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroupHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintGroupHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintGroupHeaderObject* self = (PyoaConstraintGroupHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintGroupHeader)
    {
        PyParamoaConstraintGroupHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintGroupHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintGroupHeader, Choices are:\n"
        "    (oaConstraintGroupHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintGroupHeader_tp_dealloc(PyoaConstraintGroupHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroupHeader_tp_repr(PyObject *ob)
{
    PyParamoaConstraintGroupHeader value;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaConstraintGroupHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintGroupHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintGroupHeader v1;
    PyParamoaConstraintGroupHeader v2;
    int convert_status1=PyoaConstraintGroupHeader_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintGroupHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintGroupHeader_Convert(PyObject* ob,PyParamoaConstraintGroupHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintGroupHeader_Check(ob)) {
        result->SetData( (oaConstraintGroupHeader**) ((PyoaConstraintGroupHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintGroupHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintGroupHeader_FromoaConstraintGroupHeader(oaConstraintGroupHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintGroupHeader* data=*value;
        PyObject* bself = PyoaConstraintGroupHeader_Type.tp_alloc(&PyoaConstraintGroupHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintGroupHeaderObject* self = (PyoaConstraintGroupHeaderObject*)bself;
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
PyObject* PyoaConstraintGroupHeader_FromoaConstraintGroupHeader(oaConstraintGroupHeader* data)
{
    if (data) {
       PyObject* bself = PyoaConstraintGroupHeader_Type.tp_alloc(&PyoaConstraintGroupHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintGroupHeaderObject* self = (PyoaConstraintGroupHeaderObject*)bself;
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
static char oaConstraintGroupHeader_getConstraintGroup_doc[] = 
"Class: oaConstraintGroupHeader, Function: getConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getConstraintGroup() const\n"
"    Signature: getConstraintGroup|ptr-oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    This function attempts to return the constraintGroup associated with the specified ConstraintGroupHeader. If the ConstraintGroupHeader cannot be bound NULL will be returned.\n"
;

static PyObject*
oaConstraintGroupHeader_getConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupHeaderObject* self=(PyoaConstraintGroupHeaderObject*)ob;
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
static char oaConstraintGroupHeader_getConstraintGroupMems_doc[] = 
"Class: oaConstraintGroupHeader, Function: getConstraintGroupMems\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader getConstraintGroupMems() const\n"
"    Signature: getConstraintGroupMems|simple-oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of all of the constraint group members that reference this constraint group header.\n"
;

static PyObject*
oaConstraintGroupHeader_getConstraintGroupMems(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupHeaderObject* self=(PyoaConstraintGroupHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader* result= new oaCollection_oaConstraintGroupMem_oaConstraintGroupHeader(data.DataCall()->getConstraintGroupMems());
        return PyoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader_FromoaCollection_oaConstraintGroupMem_oaConstraintGroupHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroupHeader_getConstraintGroupMemsIter_doc[] = 
"Class: oaConstraintGroupHeader, Function: getConstraintGroupMemsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaConstraintGroupMem getConstraintGroupMemsIter() const\n"
"    Signature: getConstraintGroupMemsIter|simple-oaIter_oaConstraintGroupMem|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of all of the constraint group members that reference this constraint group header.\n"
;

static PyObject*
oaConstraintGroupHeader_getConstraintGroupMemsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupHeaderObject* self=(PyoaConstraintGroupHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaConstraintGroupMem* result= new oaIter_oaConstraintGroupMem(data.DataCall()->getConstraintGroupMems());
        return PyoaIter_oaConstraintGroupMem_FromoaIter_oaConstraintGroupMem(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaConstraintGroupHeader_getName_doc[] = 
"Class: oaConstraintGroupHeader, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name associated with constraint group represented by this ConstraintGroupHeader.\n"
"    name\n"
"    String to return name in\n"
;

static PyObject*
oaConstraintGroupHeader_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupHeaderObject* self=(PyoaConstraintGroupHeaderObject*)ob;
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
static char oaConstraintGroupHeader_isBound_doc[] = 
"Class: oaConstraintGroupHeader, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this ConstraintGroupHeader is bound to its associated constraint group object.\n"
;

static PyObject*
oaConstraintGroupHeader_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupHeaderObject* self=(PyoaConstraintGroupHeaderObject*)ob;
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
static char oaConstraintGroupHeader_isNull_doc[] =
"Class: oaConstraintGroupHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintGroupHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintGroupHeader data;
    int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintGroupHeader_assign_doc[] = 
"Class: oaConstraintGroupHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintGroupHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintGroupHeader data;
  int convert_status=PyoaConstraintGroupHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintGroupHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintGroupHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintGroupHeader_methodlist[] = {
    {"getConstraintGroup",(PyCFunction)oaConstraintGroupHeader_getConstraintGroup,METH_VARARGS,oaConstraintGroupHeader_getConstraintGroup_doc},
    {"getConstraintGroupMems",(PyCFunction)oaConstraintGroupHeader_getConstraintGroupMems,METH_VARARGS,oaConstraintGroupHeader_getConstraintGroupMems_doc},
    {"getConstraintGroupMemsIter",(PyCFunction)oaConstraintGroupHeader_getConstraintGroupMemsIter,METH_VARARGS,oaConstraintGroupHeader_getConstraintGroupMemsIter_doc},
    {"getName",(PyCFunction)oaConstraintGroupHeader_getName,METH_VARARGS,oaConstraintGroupHeader_getName_doc},
    {"isBound",(PyCFunction)oaConstraintGroupHeader_isBound,METH_VARARGS,oaConstraintGroupHeader_isBound_doc},
    {"isNull",(PyCFunction)oaConstraintGroupHeader_tp_isNull,METH_VARARGS,oaConstraintGroupHeader_isNull_doc},
    {"assign",(PyCFunction)oaConstraintGroupHeader_tp_assign,METH_VARARGS,oaConstraintGroupHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroupHeader_doc[] = 
"Class: oaConstraintGroupHeader\n"
"  The oaConstraintGroupHeader class implements persistent objects that are created and destroyed automatically on an as needed basis. The existence of an oaConstraintGroupHeader object indicates that the constraint group it represents is currently being used by a database object in some way in the design hierarchy.\n"
"  oaConstraintGroupHeader objects provide direct access to the collections of constraint group members that use the constraint group they represent.\n"
"Constructors:\n"
"  Paramegers: (oaConstraintGroupHeader)\n"
"    Calls: (const oaConstraintGroupHeader&)\n"
"    Signature: oaConstraintGroupHeader||cref-oaConstraintGroupHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintGroupHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintGroupHeader",
    sizeof(PyoaConstraintGroupHeaderObject),
    0,
    (destructor)oaConstraintGroupHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintGroupHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintGroupHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintGroupHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintGroupHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintGroupHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroupHeader_static_find_doc[] = 
"Class: oaConstraintGroupHeader, Function: find\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaConstraintGroupHeader* find(const oaObject* database,const oaString& name)\n"
"    Signature: find|ptr-oaConstraintGroupHeader|cptr-oaObject,cref-oaString,\n"
"    This function searches the specified database looking for a ConstraintGroupHeader with the specified constraint group name. If the ConstraintGroupHeader is found, it is returned, otherwise NULL is returned. NULL is always returned if the specified constraint group name is default or foundry.\n"
"    database\n"
"    Database to search in\n"
"    name\n"
"    Name of constraint group to search for\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaConstraintGroupHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaConstraintGroupHeaderp result= (oaConstraintGroupHeader::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaConstraintGroupHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaConstraintGroupHeader_static_find,METH_VARARGS,oaConstraintGroupHeader_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintGroupHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintGroupHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintGroupHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintGroupHeader",
           (PyObject*)(&PyoaConstraintGroupHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintGroupHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintGroupHeader_Type.tp_dict;
    for(method=oaConstraintGroupHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaConstraintGroupMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroupMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintGroupMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintGroupMemObject* self = (PyoaConstraintGroupMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintGroupMem)
    {
        PyParamoaConstraintGroupMem p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintGroupMem_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintGroupMem, Choices are:\n"
        "    (oaConstraintGroupMem)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintGroupMem_tp_dealloc(PyoaConstraintGroupMemObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintGroupMem_tp_repr(PyObject *ob)
{
    PyParamoaConstraintGroupMem value;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaConstraintGroupMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintGroupMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintGroupMem v1;
    PyParamoaConstraintGroupMem v2;
    int convert_status1=PyoaConstraintGroupMem_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintGroupMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintGroupMem_Convert(PyObject* ob,PyParamoaConstraintGroupMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintGroupMem_Check(ob)) {
        result->SetData( (oaConstraintGroupMem**) ((PyoaConstraintGroupMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintGroupMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintGroupMem_FromoaConstraintGroupMem(oaConstraintGroupMem** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintGroupMem* data=*value;
        PyObject* bself = PyoaConstraintGroupMem_Type.tp_alloc(&PyoaConstraintGroupMem_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintGroupMemObject* self = (PyoaConstraintGroupMemObject*)bself;
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
PyObject* PyoaConstraintGroupMem_FromoaConstraintGroupMem(oaConstraintGroupMem* data)
{
    if (data) {
       PyObject* bself = PyoaConstraintGroupMem_Type.tp_alloc(&PyoaConstraintGroupMem_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintGroupMemObject* self = (PyoaConstraintGroupMemObject*)bself;
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
static char oaConstraintGroupMem_destroy_doc[] = 
"Class: oaConstraintGroupMem, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    oaConstraintGroupMem::destroy\n"
"    This function destroys the constraint group member specified, removing it from the parent constraint group. The associated object is not destroyed.\n"
;

static PyObject*
oaConstraintGroupMem_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
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
static char oaConstraintGroupMem_getConstraintGroup_doc[] = 
"Class: oaConstraintGroupMem, Function: getConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getConstraintGroup() const\n"
"    Signature: getConstraintGroup|ptr-oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    This function returns the parent constraint group for this group member.\n"
;

static PyObject*
oaConstraintGroupMem_getConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
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
static char oaConstraintGroupMem_getObject_doc[] = 
"Class: oaConstraintGroupMem, Function: getObject\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getObject() const\n"
"    Signature: getObject|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns the object (constraint, constraint group or constraint group header) that is referred by this constraint group member. Objects that refer to constraint groups in a different database will be returned as oaConstraintGroupHeader objects.\n"
;

static PyObject*
oaConstraintGroupMem_getObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
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
static char oaConstraintGroupMem_isImplicit_doc[] = 
"Class: oaConstraintGroupMem, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether the constraint group member was implicitly created by the database. The database creates implicit members for constraint groups such as the foundry constraint group or the default constraint group for incremental technology databases.\n"
"    It is an error to attempt to move or destroy an implicit constraint group member.\n"
"    For more information about incremental technology databases, refer to Using Technology Databases in the Programmers Guide.\n"
;

static PyObject*
oaConstraintGroupMem_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isImplicit());
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
static char oaConstraintGroupMem_moveAfter_doc[] = 
"Class: oaConstraintGroupMem, Function: moveAfter\n"
"  Paramegers: (oaConstraintGroupMem)\n"
"    Calls: void moveAfter(oaConstraintGroupMem* member)\n"
"    Signature: moveAfter|void-void|ptr-oaConstraintGroupMem,\n"
"    oaConstraintGroupMem::moveAfter\n"
"    This function moves this constraint group member to the position after the specified member in the same constraint group.\n"
"    member\n"
"    The constraint group member to move this member after\n"
"    oacInvalidConstraintGroupForMemberMove\n"
;

static PyObject*
oaConstraintGroupMem_moveAfter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaConstraintGroupMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintGroupMem_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->moveAfter(p1.Data());
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
static char oaConstraintGroupMem_moveToFirst_doc[] = 
"Class: oaConstraintGroupMem, Function: moveToFirst\n"
"  Paramegers: ()\n"
"    Calls: void moveToFirst()\n"
"    Signature: moveToFirst|void-void|\n"
"    BrowseData: 0\n"
"    oaConstraintGroupMem::moveToFirst\n"
"    This function attempts to move this constraint group member to the first member in its group. The current first constraint group member is moved to the second, and so on.\n"
;

static PyObject*
oaConstraintGroupMem_moveToFirst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintGroupMemObject* self=(PyoaConstraintGroupMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->moveToFirst();
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
static char oaConstraintGroupMem_isNull_doc[] =
"Class: oaConstraintGroupMem, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintGroupMem_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintGroupMem data;
    int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintGroupMem_assign_doc[] = 
"Class: oaConstraintGroupMem, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintGroupMem_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintGroupMem data;
  int convert_status=PyoaConstraintGroupMem_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintGroupMem p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintGroupMem_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintGroupMem_methodlist[] = {
    {"destroy",(PyCFunction)oaConstraintGroupMem_destroy,METH_VARARGS,oaConstraintGroupMem_destroy_doc},
    {"getConstraintGroup",(PyCFunction)oaConstraintGroupMem_getConstraintGroup,METH_VARARGS,oaConstraintGroupMem_getConstraintGroup_doc},
    {"getObject",(PyCFunction)oaConstraintGroupMem_getObject,METH_VARARGS,oaConstraintGroupMem_getObject_doc},
    {"isImplicit",(PyCFunction)oaConstraintGroupMem_isImplicit,METH_VARARGS,oaConstraintGroupMem_isImplicit_doc},
    {"moveAfter",(PyCFunction)oaConstraintGroupMem_moveAfter,METH_VARARGS,oaConstraintGroupMem_moveAfter_doc},
    {"moveToFirst",(PyCFunction)oaConstraintGroupMem_moveToFirst,METH_VARARGS,oaConstraintGroupMem_moveToFirst_doc},
    {"isNull",(PyCFunction)oaConstraintGroupMem_tp_isNull,METH_VARARGS,oaConstraintGroupMem_isNull_doc},
    {"assign",(PyCFunction)oaConstraintGroupMem_tp_assign,METH_VARARGS,oaConstraintGroupMem_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroupMem_doc[] = 
"Class: oaConstraintGroupMem\n"
"  The oaConstraintGroupMem class implements the members of a constraint group. A constraint group member can be an individual constraint, or another constraint group.\n"
"  A collection of all the oaConstraintGroupMems in a parent constraint group is returned by oaConstraintGroup::getMembers .\n"
"  An instance of oaConstraintGroupMem is automatically destroyed when either the object it references or the parent constraint group is destroyed.\n"
"  The oaConstraintGroupMem class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaConstraintGroupMem)\n"
"    Calls: (const oaConstraintGroupMem&)\n"
"    Signature: oaConstraintGroupMem||cref-oaConstraintGroupMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintGroupMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintGroupMem",
    sizeof(PyoaConstraintGroupMemObject),
    0,
    (destructor)oaConstraintGroupMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintGroupMem_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintGroupMem_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintGroupMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintGroupMem_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintGroupMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintGroupMem_static_create_doc[] = 
"Class: oaConstraintGroupMem, Function: create\n"
"  Paramegers: (oaConstraintGroup,oaConstraint)\n"
"    Calls: oaConstraintGroupMem* create(oaConstraintGroup* group,oaConstraint* constraint)\n"
"    Signature: create|ptr-oaConstraintGroupMem|ptr-oaConstraintGroup,ptr-oaConstraint,simple-oaBoolean,\n"
"    oaConstraintGroupMem::create\n"
"    This function creates a constraint group member that is an individual constraint. The constraint and the parent constraint group must be in the same database. By default constraint group members are appended to the constraint group.\n"
"    group\n"
"    The constraint group to which this member is to be added\n"
"    constraint\n"
"    The constraint to include in the specified group\n"
"    prepend\n"
"    Boolean indicating to add this member as the first member of the constraint group\n"
"    oacConstraintGroupMemberNotInValidDB\n"
"    oacConstraintGroupAlreadyHasObj\n"
"  Paramegers: (oaConstraintGroup,oaConstraint,oaBoolean)\n"
"    Calls: oaConstraintGroupMem* create(oaConstraintGroup* group,oaConstraint* constraint,oaBoolean prepend)\n"
"    Signature: create|ptr-oaConstraintGroupMem|ptr-oaConstraintGroup,ptr-oaConstraint,simple-oaBoolean,\n"
"    oaConstraintGroupMem::create\n"
"    This function creates a constraint group member that is an individual constraint. The constraint and the parent constraint group must be in the same database. By default constraint group members are appended to the constraint group.\n"
"    group\n"
"    The constraint group to which this member is to be added\n"
"    constraint\n"
"    The constraint to include in the specified group\n"
"    prepend\n"
"    Boolean indicating to add this member as the first member of the constraint group\n"
"    oacConstraintGroupMemberNotInValidDB\n"
"    oacConstraintGroupAlreadyHasObj\n"
"  Paramegers: (oaConstraintGroup,oaConstraintGroup)\n"
"    Calls: oaConstraintGroupMem* create(oaConstraintGroup* group,oaConstraintGroup* groupMem)\n"
"    Signature: create|ptr-oaConstraintGroupMem|ptr-oaConstraintGroup,ptr-oaConstraintGroup,simple-oaBoolean,\n"
"    oaConstraintGroupMem::create\n"
"    This function creates a constraint group member that is itself a constraint group.\n"
"    Typically, the constraint group and the parent constraint group are in the same database, or if the parent constraint group is in the design database, then the member may be in the technology database.\n"
"    A parent constraint group can also include a member that is a user-defined constraint group in a referenced technology database. For more information about referenced technology databases, see Using Technology Databases in the Programmers Guide.\n"
"    By default constraint group members are appended to the constraint group.\n"
"    group\n"
"    The constraint group to which this member is to be added\n"
"    groupMem\n"
"    The constraint group to include in the specified group\n"
"    prepend\n"
"    Boolean indicating to add this member as the first member of the constraint group\n"
"    oacConstraintGroupMemberNotInValidDB\n"
"    oacConstraintGroupAlreadyHasObj\n"
"  Paramegers: (oaConstraintGroup,oaConstraintGroup,oaBoolean)\n"
"    Calls: oaConstraintGroupMem* create(oaConstraintGroup* group,oaConstraintGroup* groupMem,oaBoolean prepend)\n"
"    Signature: create|ptr-oaConstraintGroupMem|ptr-oaConstraintGroup,ptr-oaConstraintGroup,simple-oaBoolean,\n"
"    oaConstraintGroupMem::create\n"
"    This function creates a constraint group member that is itself a constraint group.\n"
"    Typically, the constraint group and the parent constraint group are in the same database, or if the parent constraint group is in the design database, then the member may be in the technology database.\n"
"    A parent constraint group can also include a member that is a user-defined constraint group in a referenced technology database. For more information about referenced technology databases, see Using Technology Databases in the Programmers Guide.\n"
"    By default constraint group members are appended to the constraint group.\n"
"    group\n"
"    The constraint group to which this member is to be added\n"
"    groupMem\n"
"    The constraint group to include in the specified group\n"
"    prepend\n"
"    Boolean indicating to add this member as the first member of the constraint group\n"
"    oacConstraintGroupMemberNotInValidDB\n"
"    oacConstraintGroupAlreadyHasObj\n"
;

static PyObject*
oaConstraintGroupMem_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaConstraint)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaConstraint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaConstraint_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaConstraintGroupMemp result= (oaConstraintGroupMem::create(p1.Data(),p2.Data()));
            return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaConstraint,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaConstraint p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaConstraint_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaConstraintGroupMemp result= (oaConstraintGroupMem::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaConstraintGroup)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaConstraintGroup p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaConstraintGroup_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaConstraintGroupMemp result= (oaConstraintGroupMem::create(p1.Data(),p2.Data()));
            return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaConstraintGroup,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaConstraintGroup p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaConstraintGroup_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaConstraintGroupMemp result= (oaConstraintGroupMem::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaConstraintGroupMem_FromoaConstraintGroupMem(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaConstraintGroupMem, function: create, Choices are:\n"
        "    (oaConstraintGroup,oaConstraint)\n"
        "    (oaConstraintGroup,oaConstraint,oaBoolean)\n"
        "    (oaConstraintGroup,oaConstraintGroup)\n"
        "    (oaConstraintGroup,oaConstraintGroup,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaConstraintGroupMem_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaConstraintGroupMem_static_create,METH_VARARGS,oaConstraintGroupMem_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintGroupMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintGroupMem_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintGroupMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintGroupMem",
           (PyObject*)(&PyoaConstraintGroupMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintGroupMem\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintGroupMem_Type.tp_dict;
    for(method=oaConstraintGroupMem_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaConstraintGroupMemModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConstraintGroupMemModTypeEnum_Convert(PyObject* ob,PyParamoaConstraintGroupMemModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMoveConstraintGroupMemModType")==0) { result->SetData(oacMoveConstraintGroupMemModType); return 1;}
        if (strcasecmp(str,"oacMoveFirstConstraintGroupMemModType")==0) { result->SetData(oacMoveFirstConstraintGroupMemModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConstraintGroupMemModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintGroupMemModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConstraintGroupMemModTypeEnum_FromoaConstraintGroupMemModTypeEnum(oaConstraintGroupMemModTypeEnum ob)
{
    if (ob==oacMoveConstraintGroupMemModType) return PyString_FromString("oacMoveConstraintGroupMemModType");
    if (ob==oacMoveFirstConstraintGroupMemModType) return PyString_FromString("oacMoveFirstConstraintGroupMemModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConstraintGroupMemModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConstraintGroupMemModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConstraintGroupMemModTypeEnum_FromoaConstraintGroupMemModTypeEnum(oaConstraintGroupMemModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConstraintGroupMemModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConstraintGroupMemModTypeEnum_doc[] =
"Type convert function for enum: oaConstraintGroupMemModTypeEnum";
                               
static PyMethodDef PyoaConstraintGroupMemModTypeEnum_method =
  {"oaConstraintGroupMemModTypeEnum",(PyCFunction)PyoaConstraintGroupMemModTypeEnum_TypeFunction,METH_VARARGS,oaConstraintGroupMemModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConstraintGroupMemModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMoveConstraintGroupMemModType");
    PyDict_SetItemString(mod_dict,"oacMoveConstraintGroupMemModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMoveFirstConstraintGroupMemModType");
    PyDict_SetItemString(mod_dict,"oacMoveFirstConstraintGroupMemModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConstraintGroupMemModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConstraintGroupMemModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConstraintGroupMemModTypeEnum\n");
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
// Wrapper Implementation for Class: oaConstraintGroupModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConstraintGroupModTypeEnum_Convert(PyObject* ob,PyParamoaConstraintGroupModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConstraintGroupModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintGroupModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConstraintGroupModTypeEnum_FromoaConstraintGroupModTypeEnum(oaConstraintGroupModTypeEnum ob)
{

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConstraintGroupModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConstraintGroupModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConstraintGroupModTypeEnum_FromoaConstraintGroupModTypeEnum(oaConstraintGroupModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConstraintGroupModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConstraintGroupModTypeEnum_doc[] =
"Type convert function for enum: oaConstraintGroupModTypeEnum";
                               
static PyMethodDef PyoaConstraintGroupModTypeEnum_method =
  {"oaConstraintGroupModTypeEnum",(PyCFunction)PyoaConstraintGroupModTypeEnum_TypeFunction,METH_VARARGS,oaConstraintGroupModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConstraintGroupModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConstraintGroupModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConstraintGroupModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConstraintGroupModTypeEnum\n");
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
// Wrapper Implementation for Class: oaConstraintInGroupCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintInGroupCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintInGroupCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintInGroupCollectionObject* self = (PyoaConstraintInGroupCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintGroup,oaConstraintDef,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaConstraintDef p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaConstraintDef_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            self->value =  new oaConstraintInGroupCollection(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintInGroupCollection)
    {
        PyParamoaConstraintInGroupCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintInGroupCollection_Convert,&p1)) {
            self->value =  new oaConstraintInGroupCollection(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintInGroupCollection, Choices are:\n"
        "    (oaConstraintGroup,oaConstraintDef,oaBoolean)\n"
        "    (oaConstraintInGroupCollection)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintInGroupCollection_tp_dealloc(PyoaConstraintInGroupCollectionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintInGroupCollection_tp_repr(PyObject *ob)
{
    PyParamoaConstraintInGroupCollection value;
    int convert_status=PyoaConstraintInGroupCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaConstraintInGroupCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintInGroupCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintInGroupCollection v1;
    PyParamoaConstraintInGroupCollection v2;
    int convert_status1=PyoaConstraintInGroupCollection_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintInGroupCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintInGroupCollection_Convert(PyObject* ob,PyParamoaConstraintInGroupCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintInGroupCollection_Check(ob)) {
        result->SetData(  ((PyoaConstraintInGroupCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintInGroupCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintInGroupCollection_FromoaConstraintInGroupCollection(oaConstraintInGroupCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConstraintInGroupCollection_Type.tp_alloc(&PyoaConstraintInGroupCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintInGroupCollectionObject* self = (PyoaConstraintInGroupCollectionObject*)bself;
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
static char oaConstraintInGroupCollection_getCount_doc[] = 
"Class: oaConstraintInGroupCollection, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaConstraintInGroupCollection_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintInGroupCollection data;
    int convert_status=PyoaConstraintInGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintInGroupCollectionObject* self=(PyoaConstraintInGroupCollectionObject*)ob;

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
static char oaConstraintInGroupCollection_includes_doc[] = 
"Class: oaConstraintInGroupCollection, Function: includes\n"
"  Paramegers: (oaConstraint)\n"
"    Calls: oaBoolean includes(const oaConstraint* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaConstraint,\n"
"    Function includes\n"
;

static PyObject*
oaConstraintInGroupCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintInGroupCollection data;
    int convert_status=PyoaConstraintInGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintInGroupCollectionObject* self=(PyoaConstraintInGroupCollectionObject*)ob;

    PyParamoaConstraint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraint_Convert,&p1)) {
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
static char oaConstraintInGroupCollection_isEmpty_doc[] = 
"Class: oaConstraintInGroupCollection, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaConstraintInGroupCollection_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintInGroupCollection data;
    int convert_status=PyoaConstraintInGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintInGroupCollectionObject* self=(PyoaConstraintInGroupCollectionObject*)ob;

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

static char oaConstraintInGroupCollection_assign_doc[] = 
"Class: oaConstraintInGroupCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintInGroupCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintInGroupCollection data;
  int convert_status=PyoaConstraintInGroupCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintInGroupCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintInGroupCollection_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintInGroupCollection_methodlist[] = {
    {"getCount",(PyCFunction)oaConstraintInGroupCollection_getCount,METH_VARARGS,oaConstraintInGroupCollection_getCount_doc},
    {"includes",(PyCFunction)oaConstraintInGroupCollection_includes,METH_VARARGS,oaConstraintInGroupCollection_includes_doc},
    {"isEmpty",(PyCFunction)oaConstraintInGroupCollection_isEmpty,METH_VARARGS,oaConstraintInGroupCollection_isEmpty_doc},
    {"assign",(PyCFunction)oaConstraintInGroupCollection_tp_assign,METH_VARARGS,oaConstraintInGroupCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintInGroupCollection_doc[] = 
"Class: oaConstraintInGroupCollection\n"
"  Class type oaConstraintInGroupCollection\n"
"Constructors:\n"
"  Paramegers: (oaConstraintGroup,oaConstraintDef,oaBoolean)\n"
"    Calls: oaConstraintInGroupCollection(const oaConstraintGroup* group,const oaConstraintDef* def,oaBoolean hardOnly)\n"
"    Signature: oaConstraintInGroupCollection||cptr-oaConstraintGroup,cptr-oaConstraintDef,simple-oaBoolean,\n"
"    Constructor oaConstraintInGroupCollection\n"
"  Paramegers: (oaConstraintInGroupCollection)\n"
"    Calls: oaConstraintInGroupCollection(const oaConstraintInGroupCollection& c)\n"
"    Signature: oaConstraintInGroupCollection||cref-oaConstraintInGroupCollection,\n"
"    Constructor oaConstraintInGroupCollection\n"
"  Paramegers: (oaConstraintInGroupCollection)\n"
"    Calls: (const oaConstraintInGroupCollection&)\n"
"    Signature: oaConstraintInGroupCollection||cref-oaConstraintInGroupCollection,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintInGroupCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintInGroupCollection",
    sizeof(PyoaConstraintInGroupCollectionObject),
    0,
    (destructor)oaConstraintInGroupCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintInGroupCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintInGroupCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintInGroupCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintInGroupCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintInGroupCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintInGroupCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintInGroupCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintInGroupCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintInGroupCollection",
           (PyObject*)(&PyoaConstraintInGroupCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintInGroupCollection\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintInGroupIter
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintInGroupIter_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintInGroupIter_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintInGroupIterObject* self = (PyoaConstraintInGroupIterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintInGroupIter, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintInGroupIter_tp_dealloc(PyoaConstraintInGroupIterObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintInGroupIter_tp_repr(PyObject *ob)
{
    PyParamoaConstraintInGroupIter value;
    int convert_status=PyoaConstraintInGroupIter_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaConstraintInGroupIter::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintInGroupIter_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintInGroupIter v1;
    PyParamoaConstraintInGroupIter v2;
    int convert_status1=PyoaConstraintInGroupIter_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintInGroupIter_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintInGroupIter_Convert(PyObject* ob,PyParamoaConstraintInGroupIter* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintInGroupIter_Check(ob)) {
        result->SetData(  ((PyoaConstraintInGroupIterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintInGroupIter Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintInGroupIter_FromoaConstraintInGroupIter(oaConstraintInGroupIter* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConstraintInGroupIter_Type.tp_alloc(&PyoaConstraintInGroupIter_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintInGroupIterObject* self = (PyoaConstraintInGroupIterObject*)bself;
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
static char oaConstraintInGroupIter_reset_doc[] = 
"Class: oaConstraintInGroupIter, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaConstraintInGroupIter_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintInGroupIter data;
    int convert_status=PyoaConstraintInGroupIter_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintInGroupIterObject* self=(PyoaConstraintInGroupIterObject*)ob;

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

static PyMethodDef oaConstraintInGroupIter_methodlist[] = {
    {"reset",(PyCFunction)oaConstraintInGroupIter_reset,METH_VARARGS,oaConstraintInGroupIter_reset_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintInGroupIter_doc[] = 
"Class: oaConstraintInGroupIter\n"
"  Class type oaConstraintInGroupIter\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintInGroupIter_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintInGroupIter",
    sizeof(PyoaConstraintInGroupIterObject),
    0,
    (destructor)oaConstraintInGroupIter_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintInGroupIter_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintInGroupIter_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintInGroupIter_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintInGroupIter_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintInGroupIter_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintInGroupIter_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintInGroupIter_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintInGroupIter\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintInGroupIter",
           (PyObject*)(&PyoaConstraintInGroupIter_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintInGroupIter\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConstraintModTypeEnum_Convert(PyObject* ob,PyParamoaConstraintModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetHardConstraintModType")==0) { result->SetData(oacSetHardConstraintModType); return 1;}
        if (strcasecmp(str,"oacSetValueConstraintModType")==0) { result->SetData(oacSetValueConstraintModType); return 1;}
        if (strcasecmp(str,"oacSetParamsConstraintModType")==0) { result->SetData(oacSetParamsConstraintModType); return 1;}
        if (strcasecmp(str,"oacSetIDConstraintModType")==0) { result->SetData(oacSetIDConstraintModType); return 1;}
        if (strcasecmp(str,"oacSetDescriptionConstraintModType")==0) { result->SetData(oacSetDescriptionConstraintModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConstraintModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConstraintModTypeEnum_FromoaConstraintModTypeEnum(oaConstraintModTypeEnum ob)
{
    if (ob==oacSetHardConstraintModType) return PyString_FromString("oacSetHardConstraintModType");
    if (ob==oacSetValueConstraintModType) return PyString_FromString("oacSetValueConstraintModType");
    if (ob==oacSetParamsConstraintModType) return PyString_FromString("oacSetParamsConstraintModType");
    if (ob==oacSetIDConstraintModType) return PyString_FromString("oacSetIDConstraintModType");
    if (ob==oacSetDescriptionConstraintModType) return PyString_FromString("oacSetDescriptionConstraintModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConstraintModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConstraintModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConstraintModTypeEnum_FromoaConstraintModTypeEnum(oaConstraintModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConstraintModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConstraintModTypeEnum_doc[] =
"Type convert function for enum: oaConstraintModTypeEnum";
                               
static PyMethodDef PyoaConstraintModTypeEnum_method =
  {"oaConstraintModTypeEnum",(PyCFunction)PyoaConstraintModTypeEnum_TypeFunction,METH_VARARGS,oaConstraintModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConstraintModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetHardConstraintModType");
    PyDict_SetItemString(mod_dict,"oacSetHardConstraintModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetValueConstraintModType");
    PyDict_SetItemString(mod_dict,"oacSetValueConstraintModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetParamsConstraintModType");
    PyDict_SetItemString(mod_dict,"oacSetParamsConstraintModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetIDConstraintModType");
    PyDict_SetItemString(mod_dict,"oacSetIDConstraintModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetDescriptionConstraintModType");
    PyDict_SetItemString(mod_dict,"oacSetDescriptionConstraintModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConstraintModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConstraintModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConstraintModTypeEnum\n");
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
// Wrapper Implementation for Class: oaConstraintParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintParamObject* self = (PyoaConstraintParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintParam)
    {
        PyParamoaConstraintParam p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintParam_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintParam, Choices are:\n"
        "    (oaConstraintParam)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintParam_tp_dealloc(PyoaConstraintParamObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_tp_repr(PyObject *ob)
{
    PyParamoaConstraintParam value;
    int convert_status=PyoaConstraintParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaConstraintParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintParam v1;
    PyParamoaConstraintParam v2;
    int convert_status1=PyoaConstraintParam_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintParam_Convert(PyObject* ob,PyParamoaConstraintParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintParam_Check(ob)) {
        result->SetData( (oaConstraintParam**) ((PyoaConstraintParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintParam_FromoaConstraintParam(oaConstraintParam** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintParam* data=*value;
        PyObject* bself = PyoaConstraintParam_Type.tp_alloc(&PyoaConstraintParam_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintParamObject* self = (PyoaConstraintParamObject*)bself;
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
PyObject* PyoaConstraintParam_FromoaConstraintParam(oaConstraintParam* data)
{
    if (data) {
       PyObject* bself = PyoaConstraintParam_Type.tp_alloc(&PyoaConstraintParam_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintParamObject* self = (PyoaConstraintParamObject*)bself;
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
static char oaConstraintParam_copy_doc[] = 
"Class: oaConstraintParam, Function: copy\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParam* copy() const\n"
"    Signature: copy|ptr-oaConstraintParam|\n"
"    BrowseData: 1\n"
"    This function copies this parameter and returns a pointer to the copy.\n"
;

static PyObject*
oaConstraintParam_copy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamp result= (data.DataCall()->copy());
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
static char oaConstraintParam_copyTo_doc[] = 
"Class: oaConstraintParam, Function: copyTo\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaConstraintParam* copyTo(oaObject* database) const\n"
"    Signature: copyTo|ptr-oaConstraintParam|ptr-oaObject,\n"
"    This function copies this constraint parameter to the database specified. A pointer to the new constraint parameter is returned.\n"
"    database\n"
"    Database to copy parameter to\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaConstraintParam_copyTo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaConstraintParamp result= (data.DataCall()->copyTo(p1.Data()));
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
static char oaConstraintParam_destroy_doc[] = 
"Class: oaConstraintParam, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this parameter, and all of its associated values. If the parameter is owned by a constraint an error is thrown.\n"
;

static PyObject*
oaConstraintParam_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
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
static char oaConstraintParam_getDef_doc[] = 
"Class: oaConstraintParam, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParamDef* getDef() const\n"
"    Signature: getDef|ptr-oaConstraintParamDef|\n"
"    BrowseData: 1\n"
"    This function returns the definition for this constraint parameter.\n"
;

static PyObject*
oaConstraintParam_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamDefp result= (data.DataCall()->getDef());
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
static char oaConstraintParam_getValue_doc[] = 
"Class: oaConstraintParam, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaValue* getValue() const\n"
"    Signature: getValue|ptr-oaValue|\n"
"    BrowseData: 1\n"
"    This function returns the value for this constraint parameter.\n"
;

static PyObject*
oaConstraintParam_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaValuep result= (data.DataCall()->getValue());
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
static char oaConstraintParam_isOwned_doc[] = 
"Class: oaConstraintParam, Function: isOwned\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOwned() const\n"
"    Signature: isOwned|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns the boolean indicating whether or not this parameter is owned by a constraint.\n"
;

static PyObject*
oaConstraintParam_isOwned(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOwned());
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
static char oaConstraintParam_setValue_doc[] = 
"Class: oaConstraintParam, Function: setValue\n"
"  Paramegers: (oaValue)\n"
"    Calls: void setValue(oaValue* value)\n"
"    Signature: setValue|void-void|ptr-oaValue,\n"
"    This function sets the value for this constraint parameter.\n"
"    value\n"
"    The value to be set on this constraint parameter.\n"
"    oacValueAlreadyOwned\n"
"    oacValueNotInSameDatabase\n"
"    oacValueInvalidForConstraintParamDef\n"
;

static PyObject*
oaConstraintParam_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamObject* self=(PyoaConstraintParamObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaValue p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaValue_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setValue(p1.Data());
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
static char oaConstraintParam_isNull_doc[] =
"Class: oaConstraintParam, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintParam_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintParam data;
    int convert_status=PyoaConstraintParam_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintParam_assign_doc[] = 
"Class: oaConstraintParam, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintParam_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintParam data;
  int convert_status=PyoaConstraintParam_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintParam p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintParam_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintParam_methodlist[] = {
    {"copy",(PyCFunction)oaConstraintParam_copy,METH_VARARGS,oaConstraintParam_copy_doc},
    {"copyTo",(PyCFunction)oaConstraintParam_copyTo,METH_VARARGS,oaConstraintParam_copyTo_doc},
    {"destroy",(PyCFunction)oaConstraintParam_destroy,METH_VARARGS,oaConstraintParam_destroy_doc},
    {"getDef",(PyCFunction)oaConstraintParam_getDef,METH_VARARGS,oaConstraintParam_getDef_doc},
    {"getValue",(PyCFunction)oaConstraintParam_getValue,METH_VARARGS,oaConstraintParam_getValue_doc},
    {"isOwned",(PyCFunction)oaConstraintParam_isOwned,METH_VARARGS,oaConstraintParam_isOwned_doc},
    {"setValue",(PyCFunction)oaConstraintParam_setValue,METH_VARARGS,oaConstraintParam_setValue_doc},
    {"isNull",(PyCFunction)oaConstraintParam_tp_isNull,METH_VARARGS,oaConstraintParam_isNull_doc},
    {"assign",(PyCFunction)oaConstraintParam_tp_assign,METH_VARARGS,oaConstraintParam_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParam_doc[] = 
"Class: oaConstraintParam\n"
"  The oaConstraintParam class represents a parameter used in creating constraint objects. Constraint parameters are defined by the constraintParamDef and have a value associated with them.\n"
"  The oaConstraintParam class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaConstraintParam)\n"
"    Calls: (const oaConstraintParam&)\n"
"    Signature: oaConstraintParam||cref-oaConstraintParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintParam",
    sizeof(PyoaConstraintParamObject),
    0,
    (destructor)oaConstraintParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintParam_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintParam_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParam_static_create_doc[] = 
"Class: oaConstraintParam, Function: create\n"
"  Paramegers: (oaConstraintParamDef,oaValue)\n"
"    Calls: oaConstraintParam* create(const oaConstraintParamDef* def,oaValue* value)\n"
"    Signature: create|ptr-oaConstraintParam|cptr-oaConstraintParamDef,ptr-oaValue,\n"
"    This function creates a constraint parameter in the same database as the value specified.\n"
"    def\n"
"    The definition for the constraint parameter\n"
"    value\n"
"    The value for the parameter\n"
"    oacValueInvalidForConstraintParamDef\n"
;

static PyObject*
oaConstraintParam_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef p1;
    PyParamoaValue p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaConstraintParamDef_Convert,&p1,
          &PyoaValue_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaConstraintParamp result= (oaConstraintParam::create(p1.Data(),p2.Data()));
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
static PyMethodDef oaConstraintParam_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaConstraintParam_static_create,METH_VARARGS,oaConstraintParam_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintParam_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintParam",
           (PyObject*)(&PyoaConstraintParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintParam\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintParam_Type.tp_dict;
    for(method=oaConstraintParam_staticmethodlist;method->ml_name!=NULL;method++) {
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


// ==================================================================
// Array for class: oaConstraintParam
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintParam_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaConstraintParam_ArrayObject* self = (PyoaConstraintParam_ArrayObject*)gself;
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
    /* Case: (oaConstraintParam_Array) */
    {
        PyParamoaConstraintParam_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintParam_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintParam_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaConstraintParam_Array)\n"
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
oaConstraintParam_Array_dealloc(PyObject* gself)
{
    PyoaConstraintParam_ArrayObject* self = (PyoaConstraintParam_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_Array_str(PyObject *ob)
{
    PyParamoaConstraintParam_Array value;
    int convert_status=PyoaConstraintParam_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaConstraintParam_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_Array_repr(PyObject *ob)
{
    PyParamoaConstraintParam_Array value;
    int convert_status=PyoaConstraintParam_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaConstraintParam_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaConstraintParam_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintParam_Array p1;
    PyParamoaConstraintParam_Array p2;
    int s1=PyoaConstraintParam_Array_Convert(ob1,&p1);
    int s2=PyoaConstraintParam_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaConstraintParam_Array_CreateList(p1);
    PyObject* l2=PyoaConstraintParam_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaConstraintParam_Array_Convert(PyObject* ob,PyParamoaConstraintParam_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaConstraintParam_Array_Check(ob)) {
    PyoaConstraintParam_ArrayObject* self = (PyoaConstraintParam_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaConstraintParam data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaConstraintParam_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaConstraintParam data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaConstraintParam_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaConstraintParam_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaConstraintParam_Array_FromoaConstraintParam_Array(const oaConstraintParam_Array& value)
{
  PyObject* gself = PyoaConstraintParam_Array_Type.tp_alloc(&PyoaConstraintParam_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaConstraintParam_ArrayObject* self = (PyoaConstraintParam_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaConstraintParam_Array_FromoaConstraintParam_Array(PyTypeoaConstraintParam* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaConstraintParam_Array_Type.tp_alloc(&PyoaConstraintParam_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaConstraintParam_ArrayObject* self = (PyoaConstraintParam_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaConstraintParam_Array_CreateList(PyParamoaConstraintParam_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaConstraintParam_FromoaConstraintParam(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaConstraintParam_Array_assign_doc[] = 
"Class: oaConstraintParam_Array, Function: assign\n"
"  Paramegers: (oaConstraintParam_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaConstraintParam_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaConstraintParam_ArrayObject* self=(PyoaConstraintParam_ArrayObject*)ob;
  try {
    PyParamoaConstraintParam_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintParam_Array_Convert,&p1)) {
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
static char oaConstraintParam_Array_list_doc[] = 
"Class: oaConstraintParam_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaConstraintParam_Array_list(PyObject* ob, PyObject *args)
{
  PyoaConstraintParam_ArrayObject* self=(PyoaConstraintParam_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaConstraintParam_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaConstraintParam_Array_methodlist[] = {
    {"assign",(PyCFunction)oaConstraintParam_Array_assign,METH_VARARGS,oaConstraintParam_Array_assign_doc},
    {"list",(PyCFunction)oaConstraintParam_Array_list,METH_VARARGS,oaConstraintParam_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaConstraintParam_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaConstraintParam_ArrayObject* self=(PyoaConstraintParam_ArrayObject*)ob;
  try {
    PyParamoaConstraintParam_Array data;
    int convert_status=PyoaConstraintParam_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaConstraintParam_FromoaConstraintParam(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaConstraintParam_Array_index_get_length(PyObject* ob)
{
    PyParamoaConstraintParam_Array data;
    int convert_status=PyoaConstraintParam_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaConstraintParam_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaConstraintParam_Array data;
    PyParamoaConstraintParam dataitem;
    int convert_status=PyoaConstraintParam_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaConstraintParam_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaConstraintParam_Array_doc[] =
"Class: oaConstraintParam_Array\n"
"  The oaConstraintParam_Array utility class provides an array of oaConstraintParam.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParam_Array()\n"
"    Signature: oaConstraintParam_Array||\n"
"    This is the default constructor for the oaConstraintParam_Array class. This constructor creates an empty oaConstraintParam_Array.\n"
"  Paramegers: (oaConstraintParam_Array)\n"
"    Calls: (const oaConstraintParam_Array&)\n"
"    Signature: oaConstraintParam_Array||cref-oaConstraintParam_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaConstraintParam_Array_as_sequence = {
    (Pyoa_inquiry)oaConstraintParam_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaConstraintParam_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaConstraintParam_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintParam_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintParam_Array",
    sizeof(PyoaConstraintParam_ArrayObject),
    0,
    oaConstraintParam_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaConstraintParam_Array_compare,    /* tp_compare */
    oaConstraintParam_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaConstraintParam_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaConstraintParam_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintParam_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaConstraintParam_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaConstraintParam_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaConstraintParam_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintParam_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintParam_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaConstraintParam_Array",
           (PyObject*)(&PyoaConstraintParam_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintParam_Array\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintParamArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintParamArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintParamArrayObject* self = (PyoaConstraintParamArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaConstraintParamArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaConstraintParam*)  new oaConstraintParamArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintParamArray)
    {
        PyParamoaConstraintParamArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintParamArray_Convert,&p1)) {
            self->value=(oaArrayBase_oaConstraintParam*)  new oaConstraintParamArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintParamArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaConstraintParamArray)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintParamArray_tp_dealloc(PyoaConstraintParamArrayObject* self)
{
    if (!self->borrow) {
        delete (oaConstraintParamArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamArray_tp_repr(PyObject *ob)
{
    PyParamoaConstraintParamArray value;
    int convert_status=PyoaConstraintParamArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaConstraintParamArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintParamArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintParamArray v1;
    PyParamoaConstraintParamArray v2;
    int convert_status1=PyoaConstraintParamArray_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintParamArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintParamArray_Convert(PyObject* ob,PyParamoaConstraintParamArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintParamArray_Check(ob)) {
        result->SetData( (oaConstraintParamArray*) ((PyoaConstraintParamArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamArray Failed");
    return 0;
}
int
PyoaConstraintParamArray_ConvertAof(PyObject* ob,PyParamoaConstraintParamArray* result)
{
    if (ob == NULL) return 1;
    if (ob==Py_None) {
        result->SetData(NULL);
        return 1;
    }
    if (PyoaConstraintParamArray_Check(ob)) {
        result->SetData( (oaConstraintParamArray*) ((PyoaConstraintParamArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintParamArray_FromoaConstraintParamArray(oaConstraintParamArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConstraintParamArray_Type.tp_alloc(&PyoaConstraintParamArray_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintParamArrayObject* self = (PyoaConstraintParamArrayObject*)bself;
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
static char oaConstraintParamArray_findParam_doc[] = 
"Class: oaConstraintParamArray, Function: findParam\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: oaConstraintParam* findParam(const oaConstraintParamDef* def) const\n"
"    Signature: findParam|ptr-oaConstraintParam|cptr-oaConstraintParamDef,\n"
"    This function searches the constraint param array for a constraint parameter with the specified definition def . If it is found, the constraint parameter will be returned. If it is not found, NULL is returned.\n"
"    def\n"
"    The oaConstraintParamDef to find.\n"
;

static PyObject*
oaConstraintParamArray_findParam(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamArray data;
    int convert_status=PyoaConstraintParamArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamArrayObject* self=(PyoaConstraintParamArrayObject*)ob;

    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaConstraintParamp result= (data.DataCall()->findParam(p1.Data()));
        return PyoaConstraintParam_FromoaConstraintParam(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaConstraintParamArray_assign_doc[] = 
"Class: oaConstraintParamArray, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintParamArray_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintParamArray data;
  int convert_status=PyoaConstraintParamArray_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintParamArray p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintParamArray_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintParamArray_methodlist[] = {
    {"findParam",(PyCFunction)oaConstraintParamArray_findParam,METH_VARARGS,oaConstraintParamArray_findParam_doc},
    {"assign",(PyCFunction)oaConstraintParamArray_tp_assign,METH_VARARGS,oaConstraintParamArray_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParamArray_doc[] = 
"Class: oaConstraintParamArray\n"
"  The constraintParamArray class implements an array of oaConstraintParam objects. Arrays of constraint parameters are typically used in creating constraint objects.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParamArray()\n"
"    Signature: oaConstraintParamArray||simple-oaUInt4,\n"
"    This function constructs on oaConstraintParamArray object, allocating storage for the parameters.\n"
"    sizeIn\n"
"    An integer value indicating the initial size of the array\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaConstraintParamArray(oaUInt4 sizeIn)\n"
"    Signature: oaConstraintParamArray||simple-oaUInt4,\n"
"    This function constructs on oaConstraintParamArray object, allocating storage for the parameters.\n"
"    sizeIn\n"
"    An integer value indicating the initial size of the array\n"
"  Paramegers: (oaConstraintParamArray)\n"
"    Calls: (const oaConstraintParamArray&)\n"
"    Signature: oaConstraintParamArray||cref-oaConstraintParamArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintParamArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintParamArray",
    sizeof(PyoaConstraintParamArrayObject),
    0,
    (destructor)oaConstraintParamArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintParamArray_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintParamArray_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintParamArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintParamArray_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaConstraintParam_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintParamArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintParamArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintParamArray_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintParamArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintParamArray",
           (PyObject*)(&PyoaConstraintParamArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintParamArray\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintParamDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintParamDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintParamDefObject* self = (PyoaConstraintParamDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintParamDef)
    {
        PyParamoaConstraintParamDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintParamDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaConstraintParamDef, Choices are:\n"
        "    (oaConstraintParamDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintParamDef_tp_dealloc(PyoaConstraintParamDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamDef_tp_repr(PyObject *ob)
{
    PyParamoaConstraintParamDef value;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaConstraintParamDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintParamDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintParamDef v1;
    PyParamoaConstraintParamDef v2;
    int convert_status1=PyoaConstraintParamDef_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintParamDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintParamDef_Convert(PyObject* ob,PyParamoaConstraintParamDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintParamDef_Check(ob)) {
        result->SetData( (oaConstraintParamDef**) ((PyoaConstraintParamDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintParamDef_FromoaConstraintParamDef(oaConstraintParamDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaConstraintParamDef* data=*value;
        PyObject* bself = PyoaConstraintParamDef_Type.tp_alloc(&PyoaConstraintParamDef_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintParamDefObject* self = (PyoaConstraintParamDefObject*)bself;
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
PyObject* PyoaConstraintParamDef_FromoaConstraintParamDef(oaConstraintParamDef* data)
{
    if (data) {
       PyObject* bself = PyoaConstraintParamDef_Type.tp_alloc(&PyoaConstraintParamDef_Type,0);
       if (bself == NULL) return bself;
       PyoaConstraintParamDefObject* self = (PyoaConstraintParamDefObject*)bself;
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
static char oaConstraintParamDef_destroy_doc[] = 
"Class: oaConstraintParamDef, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys the constraintParamDef. If this is a built in type or any databases currently reference this def an error is thrown.\n"
"    oacUnableToDestroyBuiltInType\n"
"    oacConstraintParamDefHasReference\n"
;

static PyObject*
oaConstraintParamDef_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef data;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamDefObject* self=(PyoaConstraintParamDefObject*)ob;
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
static char oaConstraintParamDef_getName_doc[] = 
"Class: oaConstraintParamDef, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of the constraintParamDef.\n"
"    name\n"
"    The returned name.\n"
;

static PyObject*
oaConstraintParamDef_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef data;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamDefObject* self=(PyoaConstraintParamDefObject*)ob;
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
static char oaConstraintParamDef_getValueType_doc[] = 
"Class: oaConstraintParamDef, Function: getValueType\n"
"  Paramegers: ()\n"
"    Calls: oaType getValueType() const\n"
"    Signature: getValueType|simple-oaType|\n"
"    BrowseData: 1\n"
"    This function returns the value type of this constraintParamDef.\n"
;

static PyObject*
oaConstraintParamDef_getValueType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef data;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamDefObject* self=(PyoaConstraintParamDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaType* result= new oaType(data.DataCall()->getValueType());
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
static char oaConstraintParamDef_remove_doc[] = 
"Class: oaConstraintParamDef, Function: remove\n"
"  Paramegers: (oaObject)\n"
"    Calls: void remove(oaObject* database)\n"
"    Signature: remove|void-void|ptr-oaObject,\n"
"    This function removes the constraintParamDef from the database specified. If any constraints in that database currently reference this def an error is thrown.\n"
"    database\n"
"    Database to remove the definition from\n"
"    oacConstraintParamDefHasReference\n"
;

static PyObject*
oaConstraintParamDef_remove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef data;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamDefObject* self=(PyoaConstraintParamDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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

// ------------------------------------------------------------------
static char oaConstraintParamDef_isNull_doc[] =
"Class: oaConstraintParamDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaConstraintParamDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaConstraintParamDef data;
    int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaConstraintParamDef_assign_doc[] = 
"Class: oaConstraintParamDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintParamDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintParamDef data;
  int convert_status=PyoaConstraintParamDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintParamDef_methodlist[] = {
    {"destroy",(PyCFunction)oaConstraintParamDef_destroy,METH_VARARGS,oaConstraintParamDef_destroy_doc},
    {"getName",(PyCFunction)oaConstraintParamDef_getName,METH_VARARGS,oaConstraintParamDef_getName_doc},
    {"getValueType",(PyCFunction)oaConstraintParamDef_getValueType,METH_VARARGS,oaConstraintParamDef_getValueType_doc},
    {"remove",(PyCFunction)oaConstraintParamDef_remove,METH_VARARGS,oaConstraintParamDef_remove_doc},
    {"isNull",(PyCFunction)oaConstraintParamDef_tp_isNull,METH_VARARGS,oaConstraintParamDef_isNull_doc},
    {"assign",(PyCFunction)oaConstraintParamDef_tp_assign,METH_VARARGS,oaConstraintParamDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParamDef_doc[] = 
"Class: oaConstraintParamDef\n"
"  The oaConstraintParamDef object specifies a definition for a particular constraint parameter. The definition contains a name and the valueType that is allowed for the parameter. The names for constraint parameter definitions must be unique.\n"
"  The oaConstraintParamDef class can be observed by deriving from\n"
"  See Uniqueness of Session Objects for information about the requirement that session objects be unique.\n"
"Constructors:\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: (const oaConstraintParamDef&)\n"
"    Signature: oaConstraintParamDef||cref-oaConstraintParamDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintParamDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintParamDef",
    sizeof(PyoaConstraintParamDefObject),
    0,
    (destructor)oaConstraintParamDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintParamDef_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintParamDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintParamDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintParamDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintParamDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParamDef_static_create_doc[] = 
"Class: oaConstraintParamDef, Function: create\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: oaConstraintParamDef* create(const oaString& name,oaType valueType)\n"
"    Signature: create|ptr-oaConstraintParamDef|cref-oaString,simple-oaType,\n"
"    This function creates a new oaConstraintParamDef. It is an error if the name of the constraintParamDef already exists. It is an error if the type specified is not an oaValueType.\n"
"    name\n"
"    The oaString name of the parameter.\n"
"    valueType\n"
"    The value type for the parameter.\n"
"    oacConstraintParamDefExists\n"
"    oacInvalidValueType\n"
;

static PyObject*
oaConstraintParamDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        oaConstraintParamDefp result= (oaConstraintParamDef::create(p1.Data(),p2.Data()));
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
static char oaConstraintParamDef_static_find_doc[] = 
"Class: oaConstraintParamDef, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaConstraintParamDef* find(const oaString& name)\n"
"    Signature: find|ptr-oaConstraintParamDef|cref-oaString,\n"
"    This function finds the constraint parameter by name. If the parameter is not found NULL is returned.\n"
"    name\n"
"    The parameter name to search for.\n"
;

static PyObject*
oaConstraintParamDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaConstraintParamDefp result= (oaConstraintParamDef::find(p1.Data()));
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
static char oaConstraintParamDef_static_get_doc[] = 
"Class: oaConstraintParamDef, Function: get\n"
"  Paramegers: (oaConstraintParamType)\n"
"    Calls: oaConstraintParamDef* get(oaConstraintParamType type)\n"
"    Signature: get|ptr-oaConstraintParamDef|simple-oaConstraintParamType,\n"
"    This function returns the constraintParamDef for the built in type specified.\n"
"    type\n"
"    The built-in type to search for.\n"
;

static PyObject*
oaConstraintParamDef_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamType_Convert,&p1)) {
        oaConstraintParamDefp result= (oaConstraintParamDef::get(p1.Data()));
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
static PyMethodDef oaConstraintParamDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaConstraintParamDef_static_create,METH_VARARGS,oaConstraintParamDef_static_create_doc},
    {"static_find",(PyCFunction)oaConstraintParamDef_static_find,METH_VARARGS,oaConstraintParamDef_static_find_doc},
    {"static_get",(PyCFunction)oaConstraintParamDef_static_get,METH_VARARGS,oaConstraintParamDef_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintParamDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintParamDef_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintParamDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintParamDef",
           (PyObject*)(&PyoaConstraintParamDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintParamDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaConstraintParamDef_Type.tp_dict;
    for(method=oaConstraintParamDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaConstraintParamModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConstraintParamModTypeEnum_Convert(PyObject* ob,PyParamoaConstraintParamModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetValueConstraintParamModType")==0) { result->SetData(oacSetValueConstraintParamModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConstraintParamModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConstraintParamModTypeEnum_FromoaConstraintParamModTypeEnum(oaConstraintParamModTypeEnum ob)
{
    if (ob==oacSetValueConstraintParamModType) return PyString_FromString("oacSetValueConstraintParamModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConstraintParamModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConstraintParamModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConstraintParamModTypeEnum_FromoaConstraintParamModTypeEnum(oaConstraintParamModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConstraintParamModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConstraintParamModTypeEnum_doc[] =
"Type convert function for enum: oaConstraintParamModTypeEnum";
                               
static PyMethodDef PyoaConstraintParamModTypeEnum_method =
  {"oaConstraintParamModTypeEnum",(PyCFunction)PyoaConstraintParamModTypeEnum_TypeFunction,METH_VARARGS,oaConstraintParamModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConstraintParamModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetValueConstraintParamModType");
    PyDict_SetItemString(mod_dict,"oacSetValueConstraintParamModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConstraintParamModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConstraintParamModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConstraintParamModTypeEnum\n");
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
// Wrapper Implementation for Class: oaConstraintParamType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaConstraintParamType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaConstraintParamTypeObject* self = (PyoaConstraintParamTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaConstraintParamTypeEnum)
    {
        PyParamoaConstraintParamTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaConstraintParamTypeEnum_Convert,&p1)) {
            self->value =  new oaConstraintParamType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaConstraintParamType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintParamType)
    {
        PyParamoaConstraintParamType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaConstraintParamType_Convert,&p1)) {
            self->value= new oaConstraintParamType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaConstraintParamType, Choices are:\n"
        "    (oaConstraintParamTypeEnum)\n"
        "    (oaString)\n"
        "    (oaConstraintParamType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaConstraintParamType_tp_dealloc(PyoaConstraintParamTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaConstraintParamType_tp_repr(PyObject *ob)
{
    PyParamoaConstraintParamType value;
    int convert_status=PyoaConstraintParamType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[43];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaConstraintParamType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaConstraintParamType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaConstraintParamType v1;
    PyParamoaConstraintParamType v2;
    int convert_status1=PyoaConstraintParamType_Convert(ob1,&v1);
    int convert_status2=PyoaConstraintParamType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaConstraintParamType_Convert(PyObject* ob,PyParamoaConstraintParamType* result)
{
    if (ob == NULL) return 1;
    if (PyoaConstraintParamType_Check(ob)) {
        result->SetData(  ((PyoaConstraintParamTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaConstraintParamType_FromoaConstraintParamType(oaConstraintParamType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaConstraintParamType_Type.tp_alloc(&PyoaConstraintParamType_Type,0);
        if (bself == NULL) return bself;
        PyoaConstraintParamTypeObject* self = (PyoaConstraintParamTypeObject*)bself;
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
static char oaConstraintParamType_getName_doc[] = 
"Class: oaConstraintParamType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name of this constraint parameter type\n"
;

static PyObject*
oaConstraintParamType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamType data;
    int convert_status=PyoaConstraintParamType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamTypeObject* self=(PyoaConstraintParamTypeObject*)ob;

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
static char oaConstraintParamType_oaConstraintParamTypeEnum_doc[] = 
"Class: oaConstraintParamType, Function: oaConstraintParamTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintParamTypeEnum oaConstraintParamTypeEnum() const\n"
"    Signature: operator oaConstraintParamTypeEnum|simple-oaConstraintParamTypeEnum|\n"
"    BrowseData: 1\n"
"    This function casts this oaConstraintParamType object into the corresponding oaConstraintParamTypeEnum value.\n"
;

static PyObject*
oaConstraintParamType_oaConstraintParamTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamType data;
    int convert_status=PyoaConstraintParamType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaConstraintParamTypeObject* self=(PyoaConstraintParamTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintParamTypeEnum result= (data.DataCall()->operator oaConstraintParamTypeEnum());
        return PyoaConstraintParamTypeEnum_FromoaConstraintParamTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaConstraintParamType_assign_doc[] = 
"Class: oaConstraintParamType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaConstraintParamType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaConstraintParamType data;
  int convert_status=PyoaConstraintParamType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaConstraintParamType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaConstraintParamType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaConstraintParamType_methodlist[] = {
    {"getName",(PyCFunction)oaConstraintParamType_getName,METH_VARARGS,oaConstraintParamType_getName_doc},
    {"oaConstraintParamTypeEnum",(PyCFunction)oaConstraintParamType_oaConstraintParamTypeEnum,METH_VARARGS,oaConstraintParamType_oaConstraintParamTypeEnum_doc},
    {"assign",(PyCFunction)oaConstraintParamType_tp_assign,METH_VARARGS,oaConstraintParamType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaConstraintParamType_doc[] = 
"Class: oaConstraintParamType\n"
"  oaConstraintParamTypeEnum\n"
"  The oaConstraintParamType class is an enum wrapper class for oaConstraintParamTypeEnum values. This class enumerates the list of built in constraint types.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaConstraintParamTypeEnum)\n"
"    Calls: oaConstraintParamType(oaConstraintParamTypeEnum typeIn)\n"
"    Signature: oaConstraintParamType||simple-oaConstraintParamTypeEnum,\n"
"    This function constructs an oaConstraintParamType object taking an oaConstraintParamTypeEnum as input.\n"
"    typeIn\n"
"    Type of constraint parameter\n"
"  Paramegers: (oaString)\n"
"    Calls: oaConstraintParamType(const oaString& name)\n"
"    Signature: oaConstraintParamType||cref-oaString,\n"
"    This function constructs an oaConstraintParamType object taking a name as input. The name must be in the legal set of names associated with oaConstraintParamTypeEnum.\n"
"    name\n"
"    Name of constraint parameter type\n"
"    oacInvalidConstraintParamTypeName\n"
"  Paramegers: (oaConstraintParamType)\n"
"    Calls: (const oaConstraintParamType&)\n"
"    Signature: oaConstraintParamType||cref-oaConstraintParamType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaConstraintParamType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaConstraintParamType",
    sizeof(PyoaConstraintParamTypeObject),
    0,
    (destructor)oaConstraintParamType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaConstraintParamType_tp_compare,	/* tp_compare */
    (reprfunc)oaConstraintParamType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaConstraintParamType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaConstraintParamType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaConstraintParamType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaConstraintParamType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaConstraintParamType_Type)<0) {
      printf("** PyType_Ready failed for: oaConstraintParamType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaConstraintParamType",
           (PyObject*)(&PyoaConstraintParamType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaConstraintParamType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaConstraintParamTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaConstraintParamTypeEnum_Convert(PyObject* ob,PyParamoaConstraintParamTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDistanceConstraintParamType")==0) { result->SetData(oacDistanceConstraintParamType); return 1;}
        if (strcasecmp(str,"oacFrequencyConstraintParamType")==0) { result->SetData(oacFrequencyConstraintParamType); return 1;}
        if (strcasecmp(str,"oacLengthConstraintParamType")==0) { result->SetData(oacLengthConstraintParamType); return 1;}
        if (strcasecmp(str,"oacNumCutsConstraintParamType")==0) { result->SetData(oacNumCutsConstraintParamType); return 1;}
        if (strcasecmp(str,"oacWidthConstraintParamType")==0) { result->SetData(oacWidthConstraintParamType); return 1;}
        if (strcasecmp(str,"oacLengthSumConstraintParamType")==0) { result->SetData(oacLengthSumConstraintParamType); return 1;}
        if (strcasecmp(str,"oacLowerLayerConstraintParamType")==0) { result->SetData(oacLowerLayerConstraintParamType); return 1;}
        if (strcasecmp(str,"oacUpperLayerConstraintParamType")==0) { result->SetData(oacUpperLayerConstraintParamType); return 1;}
        if (strcasecmp(str,"oacCoincidentAllowedParamType")==0) { result->SetData(oacCoincidentAllowedParamType); return 1;}
        if (strcasecmp(str,"oacWidthLengthTableTypeConstraintParamType")==0) { result->SetData(oacWidthLengthTableTypeConstraintParamType); return 1;}
        if (strcasecmp(str,"oacDistanceMeasureTypeConstraintParamType")==0) { result->SetData(oacDistanceMeasureTypeConstraintParamType); return 1;}
        if (strcasecmp(str,"oacCountConstraintParamType")==0) { result->SetData(oacCountConstraintParamType); return 1;}
        if (strcasecmp(str,"oacParallelEdgeSpaceConstraintParamType")==0) { result->SetData(oacParallelEdgeSpaceConstraintParamType); return 1;}
        if (strcasecmp(str,"oacParallelEdgeWithinConstraintParamType")==0) { result->SetData(oacParallelEdgeWithinConstraintParamType); return 1;}
        if (strcasecmp(str,"oacMaxLengthConstraintParamType")==0) { result->SetData(oacMaxLengthConstraintParamType); return 1;}
        if (strcasecmp(str,"oacMaxEdgeCountConstraintParamType")==0) { result->SetData(oacMaxEdgeCountConstraintParamType); return 1;}
        if (strcasecmp(str,"oacMinNumCutsConstraintParamType")==0) { result->SetData(oacMinNumCutsConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAntennaAreaFactorConstraintParamType")==0) { result->SetData(oacAntennaAreaFactorConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAntennaDiffPlusFactorConstraintParamType")==0) { result->SetData(oacAntennaDiffPlusFactorConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAntennaDiffMinusFactorConstraintParamType")==0) { result->SetData(oacAntennaDiffMinusFactorConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAntennaDiffAreaReduceFactorConstraintParamType")==0) { result->SetData(oacAntennaDiffAreaReduceFactorConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAntennaCumRoutingPlusCutConstraintParamType")==0) { result->SetData(oacAntennaCumRoutingPlusCutConstraintParamType); return 1;}
        if (strcasecmp(str,"oacAlignmentTypeConstraintParamType")==0) { result->SetData(oacAlignmentTypeConstraintParamType); return 1;}
        if (strcasecmp(str,"oacEndOfLineSpaceConstraintParamType")==0) { result->SetData(oacEndOfLineSpaceConstraintParamType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaConstraintParamTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaConstraintParamTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaConstraintParamTypeEnum_FromoaConstraintParamTypeEnum(oaConstraintParamTypeEnum ob)
{
    if (ob==oacDistanceConstraintParamType) return PyString_FromString("oacDistanceConstraintParamType");
    if (ob==oacFrequencyConstraintParamType) return PyString_FromString("oacFrequencyConstraintParamType");
    if (ob==oacLengthConstraintParamType) return PyString_FromString("oacLengthConstraintParamType");
    if (ob==oacNumCutsConstraintParamType) return PyString_FromString("oacNumCutsConstraintParamType");
    if (ob==oacWidthConstraintParamType) return PyString_FromString("oacWidthConstraintParamType");
    if (ob==oacLengthSumConstraintParamType) return PyString_FromString("oacLengthSumConstraintParamType");
    if (ob==oacLowerLayerConstraintParamType) return PyString_FromString("oacLowerLayerConstraintParamType");
    if (ob==oacUpperLayerConstraintParamType) return PyString_FromString("oacUpperLayerConstraintParamType");
    if (ob==oacCoincidentAllowedParamType) return PyString_FromString("oacCoincidentAllowedParamType");
    if (ob==oacWidthLengthTableTypeConstraintParamType) return PyString_FromString("oacWidthLengthTableTypeConstraintParamType");
    if (ob==oacDistanceMeasureTypeConstraintParamType) return PyString_FromString("oacDistanceMeasureTypeConstraintParamType");
    if (ob==oacCountConstraintParamType) return PyString_FromString("oacCountConstraintParamType");
    if (ob==oacParallelEdgeSpaceConstraintParamType) return PyString_FromString("oacParallelEdgeSpaceConstraintParamType");
    if (ob==oacParallelEdgeWithinConstraintParamType) return PyString_FromString("oacParallelEdgeWithinConstraintParamType");
    if (ob==oacMaxLengthConstraintParamType) return PyString_FromString("oacMaxLengthConstraintParamType");
    if (ob==oacMaxEdgeCountConstraintParamType) return PyString_FromString("oacMaxEdgeCountConstraintParamType");
    if (ob==oacMinNumCutsConstraintParamType) return PyString_FromString("oacMinNumCutsConstraintParamType");
    if (ob==oacAntennaAreaFactorConstraintParamType) return PyString_FromString("oacAntennaAreaFactorConstraintParamType");
    if (ob==oacAntennaDiffPlusFactorConstraintParamType) return PyString_FromString("oacAntennaDiffPlusFactorConstraintParamType");
    if (ob==oacAntennaDiffMinusFactorConstraintParamType) return PyString_FromString("oacAntennaDiffMinusFactorConstraintParamType");
    if (ob==oacAntennaDiffAreaReduceFactorConstraintParamType) return PyString_FromString("oacAntennaDiffAreaReduceFactorConstraintParamType");
    if (ob==oacAntennaCumRoutingPlusCutConstraintParamType) return PyString_FromString("oacAntennaCumRoutingPlusCutConstraintParamType");
    if (ob==oacAlignmentTypeConstraintParamType) return PyString_FromString("oacAlignmentTypeConstraintParamType");
    if (ob==oacEndOfLineSpaceConstraintParamType) return PyString_FromString("oacEndOfLineSpaceConstraintParamType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaConstraintParamTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaConstraintParamTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaConstraintParamTypeEnum_FromoaConstraintParamTypeEnum(oaConstraintParamTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaConstraintParamTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaConstraintParamTypeEnum_doc[] =
"Type convert function for enum: oaConstraintParamTypeEnum";
                               
static PyMethodDef PyoaConstraintParamTypeEnum_method =
  {"oaConstraintParamTypeEnum",(PyCFunction)PyoaConstraintParamTypeEnum_TypeFunction,METH_VARARGS,oaConstraintParamTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaConstraintParamTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDistanceConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacDistanceConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrequencyConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacFrequencyConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLengthConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacLengthConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNumCutsConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacNumCutsConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWidthConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacWidthConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLengthSumConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacLengthSumConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLowerLayerConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacLowerLayerConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUpperLayerConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacUpperLayerConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCoincidentAllowedParamType");
    PyDict_SetItemString(mod_dict,"oacCoincidentAllowedParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWidthLengthTableTypeConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacWidthLengthTableTypeConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDistanceMeasureTypeConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacDistanceMeasureTypeConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCountConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacCountConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacParallelEdgeSpaceConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacParallelEdgeSpaceConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacParallelEdgeWithinConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacParallelEdgeWithinConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxLengthConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacMaxLengthConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxEdgeCountConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacMaxEdgeCountConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinNumCutsConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacMinNumCutsConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntennaAreaFactorConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAntennaAreaFactorConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntennaDiffPlusFactorConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAntennaDiffPlusFactorConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntennaDiffMinusFactorConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAntennaDiffMinusFactorConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntennaDiffAreaReduceFactorConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAntennaDiffAreaReduceFactorConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAntennaCumRoutingPlusCutConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAntennaCumRoutingPlusCutConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAlignmentTypeConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacAlignmentTypeConstraintParamType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEndOfLineSpaceConstraintParamType");
    PyDict_SetItemString(mod_dict,"oacEndOfLineSpaceConstraintParamType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaConstraintParamTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaConstraintParamTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaConstraintParamTypeEnum\n");
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
// Wrapper Implementation for Class: oaCoreBoxSpec
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCoreBoxSpec_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCoreBoxSpec_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCoreBoxSpecObject* self = (PyoaCoreBoxSpecObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaCoreBoxSpec();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBox)
    {
        PyParamoaBox p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBox_Convert,&p1)) {
            self->value =  new oaCoreBoxSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCoreBoxSpec)
    {
        PyParamoaCoreBoxSpec p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCoreBoxSpec_Convert,&p1)) {
            self->value= new oaCoreBoxSpec(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCoreBoxSpec, Choices are:\n"
        "    ()\n"
        "    (oaBox)\n"
        "    (oaCoreBoxSpec)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCoreBoxSpec_tp_dealloc(PyoaCoreBoxSpecObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCoreBoxSpec_tp_repr(PyObject *ob)
{
    PyParamoaCoreBoxSpec value;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaCoreBoxSpec::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCoreBoxSpec_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCoreBoxSpec v1;
    PyParamoaCoreBoxSpec v2;
    int convert_status1=PyoaCoreBoxSpec_Convert(ob1,&v1);
    int convert_status2=PyoaCoreBoxSpec_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCoreBoxSpec_Convert(PyObject* ob,PyParamoaCoreBoxSpec* result)
{
    if (ob == NULL) return 1;
    if (PyoaCoreBoxSpec_Check(ob)) {
        result->SetData(  ((PyoaCoreBoxSpecObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCoreBoxSpec Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCoreBoxSpec_FromoaCoreBoxSpec(oaCoreBoxSpec* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCoreBoxSpec_Type.tp_alloc(&PyoaCoreBoxSpec_Type,0);
        if (bself == NULL) return bself;
        PyoaCoreBoxSpecObject* self = (PyoaCoreBoxSpecObject*)bself;
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
static char oaCoreBoxSpec_getBBox_doc[] = 
"Class: oaCoreBoxSpec, Function: getBBox\n"
"  Paramegers: ()\n"
"    Calls: oaBox& getBBox()\n"
"    Signature: getBBox|ref-oaBox|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the bounding box of this coreBoxSpec\n"
;

static PyObject*
oaCoreBoxSpec_getBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBox* result=&(data.DataCall()->getBBox());
        return PyoaBox_FromoaBox(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCoreBoxSpec_getNumRows_doc[] = 
"Class: oaCoreBoxSpec, Function: getNumRows\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumRows() const\n"
"    Signature: getNumRows|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of rows completely contained within the core box.\n"
;

static PyObject*
oaCoreBoxSpec_getNumRows(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumRows());
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
static char oaCoreBoxSpec_getRowBBox_doc[] = 
"Class: oaCoreBoxSpec, Function: getRowBBox\n"
"  Paramegers: (oaUInt4,oaBox)\n"
"    Calls: void getRowBBox(oaUInt4 rowNum,oaBox& bBox) const\n"
"    Signature: getRowBBox|void-void|simple-oaUInt4,ref-oaBox,\n"
"    This function fills out the given bBox with the dimension of the given row number. The row number has to be within this core box, or an exception will be thrown. A site definition must exist to obtain the site dimensions\n"
"    rowNum\n"
"    The row number.\n"
"    bBox\n"
"    The bounding box of the specified row\n"
"    oacCoreBoxSpecNoSiteDef\n"
"    oacCoreBoxSpecInvalidRowNumber\n"
;

static PyObject*
oaCoreBoxSpec_getRowBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaUInt4 p1;
    PyParamoaBox p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaBox_Convert,&p2)) {
        data.DataCall()->getRowBBox(p1.Data(),p2.Data());
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
static char oaCoreBoxSpec_getRowFlipType_doc[] = 
"Class: oaCoreBoxSpec, Function: getRowFlipType\n"
"  Paramegers: ()\n"
"    Calls: oaRowFlipType getRowFlipType() const\n"
"    Signature: getRowFlipType|simple-oaRowFlipType|\n"
"    BrowseData: 1\n"
"    This function returns the row flip type\n"
;

static PyObject*
oaCoreBoxSpec_getRowFlipType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowFlipType* result= new oaRowFlipType(data.DataCall()->getRowFlipType());
        return PyoaRowFlipType_FromoaRowFlipType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCoreBoxSpec_getRowSpacing_doc[] = 
"Class: oaCoreBoxSpec, Function: getRowSpacing\n"
"  Paramegers: ()\n"
"    Calls: oaOffset getRowSpacing() const\n"
"    Signature: getRowSpacing|simple-oaOffset|\n"
"    BrowseData: 1\n"
"    This function returns the row spacing.\n"
;

static PyObject*
oaCoreBoxSpec_getRowSpacing(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOffset result= (data.DataCall()->getRowSpacing());
        return PyoaOffset_FromoaOffset(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCoreBoxSpec_getRowSpacingType_doc[] = 
"Class: oaCoreBoxSpec, Function: getRowSpacingType\n"
"  Paramegers: ()\n"
"    Calls: oaRowSpacingType getRowSpacingType() const\n"
"    Signature: getRowSpacingType|simple-oaRowSpacingType|\n"
"    BrowseData: 1\n"
"    This function returns the row spacing type\n"
;

static PyObject*
oaCoreBoxSpec_getRowSpacingType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowSpacingType* result= new oaRowSpacingType(data.DataCall()->getRowSpacingType());
        return PyoaRowSpacingType_FromoaRowSpacingType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCoreBoxSpec_getSiteDef_doc[] = 
"Class: oaCoreBoxSpec, Function: getSiteDef\n"
"  Paramegers: ()\n"
"    Calls: oaSiteDef* getSiteDef() const\n"
"    Signature: getSiteDef|ptr-oaSiteDef|\n"
"    BrowseData: 1\n"
"    This function returns the site definition associated with this core box. If the site definition is not bound, NULL is returned. Binding of a site definition happens at the time when a core box is set on a PR boundary.\n"
;

static PyObject*
oaCoreBoxSpec_getSiteDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSiteDefp result= (data.DataCall()->getSiteDef());
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
static char oaCoreBoxSpec_getSiteDefName_doc[] = 
"Class: oaCoreBoxSpec, Function: getSiteDefName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getSiteDefName(oaString& name)\n"
"    Signature: getSiteDefName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out the site name associated with this core box.\n"
"    name\n"
"    The site name\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getSiteDefName() const\n"
"    Signature: getSiteDefName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns a constant reference to the site name in this core box.\n"
;

static PyObject*
oaCoreBoxSpec_getSiteDefName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            data.DataCall()->getSiteDefName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaString result= (data.DataCall()->getSiteDefName());
            return PyoaString_FromoaString(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCoreBoxSpec, function: getSiteDefName, Choices are:\n"
        "    (oaString)\n"
        "    ()\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCoreBoxSpec_isRowHorizontal_doc[] = 
"Class: oaCoreBoxSpec, Function: isRowHorizontal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isRowHorizontal() const\n"
"    Signature: isRowHorizontal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the row direction is horizontal.\n"
;

static PyObject*
oaCoreBoxSpec_isRowHorizontal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isRowHorizontal());
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
static char oaCoreBoxSpec_setBBox_doc[] = 
"Class: oaCoreBoxSpec, Function: setBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void setBBox(const oaBox& bBox)\n"
"    Signature: setBBox|void-void|cref-oaBox,\n"
"    This function sets the bounding box of this core box within its design. This determines the size of the entire core box array.\n"
;

static PyObject*
oaCoreBoxSpec_setBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->setBBox(p1.Data());
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
static char oaCoreBoxSpec_setRowFlipType_doc[] = 
"Class: oaCoreBoxSpec, Function: setRowFlipType\n"
"  Paramegers: (oaRowFlipType)\n"
"    Calls: void setRowFlipType(oaRowFlipType flip)\n"
"    Signature: setRowFlipType|void-void|simple-oaRowFlipType,\n"
"    This function sets the row flip type for this core box.\n"
"    flip\n"
"    The row flip type\n"
;

static PyObject*
oaCoreBoxSpec_setRowFlipType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaRowFlipType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRowFlipType_Convert,&p1)) {
        data.DataCall()->setRowFlipType(p1.Data());
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
static char oaCoreBoxSpec_setRowHorizontal_doc[] = 
"Class: oaCoreBoxSpec, Function: setRowHorizontal\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setRowHorizontal(oaBoolean isHorizontal)\n"
"    Signature: setRowHorizontal|void-void|simple-oaBoolean,\n"
"    This function sets the row direction for this core box.\n"
"    isHorizontal\n"
"    true if the intended direction is horizontal\n"
;

static PyObject*
oaCoreBoxSpec_setRowHorizontal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setRowHorizontal(p1.Data());
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
static char oaCoreBoxSpec_setRowSpacing_doc[] = 
"Class: oaCoreBoxSpec, Function: setRowSpacing\n"
"  Paramegers: (oaOffset)\n"
"    Calls: void setRowSpacing(oaOffset spacing)\n"
"    Signature: setRowSpacing|void-void|simple-oaOffset,\n"
"    This function sets the row spacing for this core box.\n"
"    spacing\n"
"    The row spacing\n"
;

static PyObject*
oaCoreBoxSpec_setRowSpacing(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaOffset p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOffset_Convert,&p1)) {
        data.DataCall()->setRowSpacing(p1.Data());
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
static char oaCoreBoxSpec_setRowSpacingType_doc[] = 
"Class: oaCoreBoxSpec, Function: setRowSpacingType\n"
"  Paramegers: (oaRowSpacingType)\n"
"    Calls: void setRowSpacingType(oaRowSpacingType type)\n"
"    Signature: setRowSpacingType|void-void|simple-oaRowSpacingType,\n"
"    This function sets the row spacing type for this core box.\n"
"    type\n"
"    The row spacing type\n"
;

static PyObject*
oaCoreBoxSpec_setRowSpacingType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    PyParamoaRowSpacingType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRowSpacingType_Convert,&p1)) {
        data.DataCall()->setRowSpacingType(p1.Data());
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
static char oaCoreBoxSpec_setSiteDef_doc[] = 
"Class: oaCoreBoxSpec, Function: setSiteDef\n"
"  Paramegers: (oaSiteDef)\n"
"    Calls: void setSiteDef(oaSiteDef* siteDef)\n"
"    Signature: setSiteDef|void-void|ptr-oaSiteDef,\n"
"    This function sets the site definition and name for this core box.\n"
"    siteDef\n"
"    The site definition\n"
"  Paramegers: (oaString)\n"
"    Calls: void setSiteDef(const oaString& name)\n"
"    Signature: setSiteDef|void-void|cref-oaString,\n"
"    This function sets the site name for this core box.\n"
"    name\n"
"    The site name\n"
;

static PyObject*
oaCoreBoxSpec_setSiteDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCoreBoxSpec data;
    int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCoreBoxSpecObject* self=(PyoaCoreBoxSpecObject*)ob;

    // Case: (oaSiteDef)
    {
        PyParamoaSiteDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSiteDef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->setSiteDef(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            data.DataCall()->setSiteDef(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCoreBoxSpec, function: setSiteDef, Choices are:\n"
        "    (oaSiteDef)\n"
        "    (oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaCoreBoxSpec_assign_doc[] = 
"Class: oaCoreBoxSpec, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCoreBoxSpec_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCoreBoxSpec data;
  int convert_status=PyoaCoreBoxSpec_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCoreBoxSpec p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCoreBoxSpec_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCoreBoxSpec_methodlist[] = {
    {"getBBox",(PyCFunction)oaCoreBoxSpec_getBBox,METH_VARARGS,oaCoreBoxSpec_getBBox_doc},
    {"getNumRows",(PyCFunction)oaCoreBoxSpec_getNumRows,METH_VARARGS,oaCoreBoxSpec_getNumRows_doc},
    {"getRowBBox",(PyCFunction)oaCoreBoxSpec_getRowBBox,METH_VARARGS,oaCoreBoxSpec_getRowBBox_doc},
    {"getRowFlipType",(PyCFunction)oaCoreBoxSpec_getRowFlipType,METH_VARARGS,oaCoreBoxSpec_getRowFlipType_doc},
    {"getRowSpacing",(PyCFunction)oaCoreBoxSpec_getRowSpacing,METH_VARARGS,oaCoreBoxSpec_getRowSpacing_doc},
    {"getRowSpacingType",(PyCFunction)oaCoreBoxSpec_getRowSpacingType,METH_VARARGS,oaCoreBoxSpec_getRowSpacingType_doc},
    {"getSiteDef",(PyCFunction)oaCoreBoxSpec_getSiteDef,METH_VARARGS,oaCoreBoxSpec_getSiteDef_doc},
    {"getSiteDefName",(PyCFunction)oaCoreBoxSpec_getSiteDefName,METH_VARARGS,oaCoreBoxSpec_getSiteDefName_doc},
    {"isRowHorizontal",(PyCFunction)oaCoreBoxSpec_isRowHorizontal,METH_VARARGS,oaCoreBoxSpec_isRowHorizontal_doc},
    {"setBBox",(PyCFunction)oaCoreBoxSpec_setBBox,METH_VARARGS,oaCoreBoxSpec_setBBox_doc},
    {"setRowFlipType",(PyCFunction)oaCoreBoxSpec_setRowFlipType,METH_VARARGS,oaCoreBoxSpec_setRowFlipType_doc},
    {"setRowHorizontal",(PyCFunction)oaCoreBoxSpec_setRowHorizontal,METH_VARARGS,oaCoreBoxSpec_setRowHorizontal_doc},
    {"setRowSpacing",(PyCFunction)oaCoreBoxSpec_setRowSpacing,METH_VARARGS,oaCoreBoxSpec_setRowSpacing_doc},
    {"setRowSpacingType",(PyCFunction)oaCoreBoxSpec_setRowSpacingType,METH_VARARGS,oaCoreBoxSpec_setRowSpacingType_doc},
    {"setSiteDef",(PyCFunction)oaCoreBoxSpec_setSiteDef,METH_VARARGS,oaCoreBoxSpec_setSiteDef_doc},
    {"assign",(PyCFunction)oaCoreBoxSpec_tp_assign,METH_VARARGS,oaCoreBoxSpec_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCoreBoxSpec_doc[] = 
"Class: oaCoreBoxSpec\n"
"  A core box is a rectangular area within a block that specifies an array of sites where cells may be placed. It provides a similar floorplanning capability to a set of oaRow objects, but oaCoreBoxes define a series of row locations in a single object and provide options for controlling the relative placement and orientation of those rows.\n"
"  The core box represents the limits of the core within the given design. At the full chip level, there will be rows of IO pads and peripheral routing that are outside the core box. For a block, the core box is closer in size to the prboundary for the design.\n"
"  The core box defines a set of virtual rows that run in either a horizontal or vertical direction. The size of each of these rows is determined by the size of the associated site and the bounding box set on the core box. Virtual rows defined by a core box and explicit rows defined by oaRows can coexist, where the explicit rows typically handle special cases like flip chip I/O's, while the virtual rows flood the core area with the regular standard cells. Explicit oaRow objects for regular standard cells should match the virtual row locations defined by the core box, but the database does not require or enforce this.\n"
"  The rows are numbered upwards from 0, with the 0th row being the bottom- or left-most row, depending upon whether the core is horizontal or vertical. The bottom or left edge of the 0th row is aligned to the corresponding edge of the core box. Space can be reserved after every row, after every even (0th, 2nd, ...) after every odd (1st, 3rd, ...) row, or all rows can be abutted. The spacing between virtual rows is given by the core row spacing value. Every even row can be flipped, every odd row can be flipped, or none of the rows can be flipped. In unflipped rows, the site orientation is oacR0 for both horizontal and vertical rows. For flipped horizontal rows, the site orientation is oacMX, while for flipped vertical rows, the site orientation is oacMY.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaCoreBoxSpec()\n"
"    Signature: oaCoreBoxSpec||\n"
"    This function constructs an oaCoreBoxSpec class with the default parameter values. These are: a zero-area bounding box at the origin; horizontal rows; no spacing; no flipping; and no site def.\n"
"  Paramegers: (oaBox)\n"
"    Calls: oaCoreBoxSpec(const oaBox& bBox)\n"
"    Signature: oaCoreBoxSpec||cref-oaBox,\n"
"    This function constructs an oaCoreBoxSpec instance setting its bounding box to the supplied value. All other attributes are set to default values.\n"
"  Paramegers: (oaCoreBoxSpec)\n"
"    Calls: (const oaCoreBoxSpec&)\n"
"    Signature: oaCoreBoxSpec||cref-oaCoreBoxSpec,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCoreBoxSpec_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCoreBoxSpec",
    sizeof(PyoaCoreBoxSpecObject),
    0,
    (destructor)oaCoreBoxSpec_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCoreBoxSpec_tp_compare,	/* tp_compare */
    (reprfunc)oaCoreBoxSpec_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCoreBoxSpec_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCoreBoxSpec_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCoreBoxSpec_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCoreBoxSpec_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCoreBoxSpec_Type)<0) {
      printf("** PyType_Ready failed for: oaCoreBoxSpec\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCoreBoxSpec",
           (PyObject*)(&PyoaCoreBoxSpec_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCoreBoxSpec\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCouplingCap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCouplingCap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCouplingCap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCouplingCapObject* self = (PyoaCouplingCapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCouplingCap)
    {
        PyParamoaCouplingCap p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCouplingCap_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCouplingCap, Choices are:\n"
        "    (oaCouplingCap)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCouplingCap_tp_dealloc(PyoaCouplingCapObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCouplingCap_tp_repr(PyObject *ob)
{
    PyParamoaCouplingCap value;
    int convert_status=PyoaCouplingCap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaCouplingCap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCouplingCap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCouplingCap v1;
    PyParamoaCouplingCap v2;
    int convert_status1=PyoaCouplingCap_Convert(ob1,&v1);
    int convert_status2=PyoaCouplingCap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCouplingCap_Convert(PyObject* ob,PyParamoaCouplingCap* result)
{
    if (ob == NULL) return 1;
    if (PyoaCouplingCap_Check(ob)) {
        result->SetData( (oaCouplingCap**) ((PyoaCouplingCapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCouplingCap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCouplingCap_FromoaCouplingCap(oaCouplingCap** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCouplingCap* data=*value;
        PyObject* bself = PyoaCouplingCap_Type.tp_alloc(&PyoaCouplingCap_Type,0);
        if (bself == NULL) return bself;
        PyoaCouplingCapObject* self = (PyoaCouplingCapObject*)bself;
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
PyObject* PyoaCouplingCap_FromoaCouplingCap(oaCouplingCap* data)
{
    if (data) {
       PyObject* bself = PyoaCouplingCap_Type.tp_alloc(&PyoaCouplingCap_Type,0);
       if (bself == NULL) return bself;
       PyoaCouplingCapObject* self = (PyoaCouplingCapObject*)bself;
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
static char oaCouplingCap_getNode_doc[] = 
"Class: oaCouplingCap, Function: getNode\n"
"  Paramegers: (oaEndpointType)\n"
"    Calls: oaNode* getNode(oaEndpointType endpoint) const\n"
"    Signature: getNode|ptr-oaNode|simple-oaEndpointType,\n"
"    This function returns the node connected to the specified endpoint of this coupling cap. If this coupling capacitor connects to another parasitic network, NULL is returned for the to endpoint.\n"
"    endpoint\n"
"    The endpoint value\n"
;

static PyObject*
oaCouplingCap_getNode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCouplingCapObject* self=(PyoaCouplingCapObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaEndpointType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaEndpointType_Convert,&p1)) {
        oaNodep result= (data.DataCall()->getNode(p1.Data()));
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
static char oaCouplingCap_getOtherConn_doc[] = 
"Class: oaCouplingCap, Function: getOtherConn\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getOtherConn() const\n"
"    Signature: getOtherConn|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the conn (an instTerm or term) for the to endpoint of this device.\n"
"    oacNoConnForLocalCouplingCaps\n"
"    oacCouplingCapHasNoConn\n"
;

static PyObject*
oaCouplingCap_getOtherConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCouplingCapObject* self=(PyoaCouplingCapObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getOtherConn());
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
static char oaCouplingCap_getOtherNode_doc[] = 
"Class: oaCouplingCap, Function: getOtherNode\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaNode* getOtherNode(oaNode* node) const\n"
"    Signature: getOtherNode|ptr-oaNode|ptr-oaNode,\n"
"    This function returns the node connected to the other endpoint of this coupling capacitor (the endpoint that is not connected to node ). When node is the from endpoint of this couplingCap and this coupling capacitor connects to another parasitic network, NULL is returned.\n"
"    node\n"
"    The node connected to the other endpoint of this device\n"
"  Paramegers: (oaDesignObject,oaUInt4)\n"
"    Calls: void getOtherNode(oaDesignObject*& otherNet,oaUInt4& otherNodeId) const\n"
"    Signature: getOtherNode|void-void|ptrref-oaDesignObject,ref-oaUInt4,\n"
"    BrowseData: 0,oaDesignObject,oaUInt4\n"
"    This function returns information about the node connected to the to endpoint of this device. The parasitic network for otherNet does not need to exist or be in memory at the time that this function is called. When this is a local coupling cap, the otherNodeId is set to oacNullIndex if the other node does not have an ID.\n"
"    The other net may either be an oaNet or an oaOccNet . Coupling must either be between 2 occurrence nets or 2 block nets. It may not cross between them.\n"
"    otherNet\n"
"    The other network from which to return information\n"
"    otherNodeId\n"
"    A unique ID for the node in the other parasitic network\n"
;

static PyObject*
oaCouplingCap_getOtherNode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCouplingCapObject* self=(PyoaCouplingCapObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaNode)
    {
        PyParamoaNode p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaNode_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaNodep result= (data.DataCall()->getOtherNode(p1.Data()));
            return PyoaNode_FromoaNode(result);
        }
    }
    PyErr_Clear();
    // Case: (oaDesignObject,oaUInt4)
    {
        PyParamoaDesignObject p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDesignObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            data.DataCall()->getOtherNode(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCouplingCap, function: getOtherNode, Choices are:\n"
        "    (oaNode)\n"
        "    (oaDesignObject,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCouplingCap_isLocal_doc[] = 
"Class: oaCouplingCap, Function: isLocal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isLocal() const\n"
"    Signature: isLocal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this coupling capacitor connects two nodes within the same parasitic network.\n"
;

static PyObject*
oaCouplingCap_isLocal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCouplingCapObject* self=(PyoaCouplingCapObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isLocal());
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
static char oaCouplingCap_isOtherConn_doc[] = 
"Class: oaCouplingCap, Function: isOtherConn\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOtherConn() const\n"
"    Signature: isOtherConn|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this couplingCap connects a node in the local network and a connection (an instTerm or term) in a different parasitic network.\n"
;

static PyObject*
oaCouplingCap_isOtherConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCouplingCapObject* self=(PyoaCouplingCapObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOtherConn());
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
static char oaCouplingCap_isNull_doc[] =
"Class: oaCouplingCap, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCouplingCap_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCouplingCap data;
    int convert_status=PyoaCouplingCap_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCouplingCap_assign_doc[] = 
"Class: oaCouplingCap, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCouplingCap_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCouplingCap data;
  int convert_status=PyoaCouplingCap_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCouplingCap p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCouplingCap_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCouplingCap_methodlist[] = {
    {"getNode",(PyCFunction)oaCouplingCap_getNode,METH_VARARGS,oaCouplingCap_getNode_doc},
    {"getOtherConn",(PyCFunction)oaCouplingCap_getOtherConn,METH_VARARGS,oaCouplingCap_getOtherConn_doc},
    {"getOtherNode",(PyCFunction)oaCouplingCap_getOtherNode,METH_VARARGS,oaCouplingCap_getOtherNode_doc},
    {"isLocal",(PyCFunction)oaCouplingCap_isLocal,METH_VARARGS,oaCouplingCap_isLocal_doc},
    {"isOtherConn",(PyCFunction)oaCouplingCap_isOtherConn,METH_VARARGS,oaCouplingCap_isOtherConn_doc},
    {"isNull",(PyCFunction)oaCouplingCap_tp_isNull,METH_VARARGS,oaCouplingCap_isNull_doc},
    {"assign",(PyCFunction)oaCouplingCap_tp_assign,METH_VARARGS,oaCouplingCap_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCouplingCap_doc[] = 
"Class: oaCouplingCap\n"
"  The oaCouplingCap class represents a coupling capacitor that can couple between two nodes in the same parasitic network, between two nodes in different parasitic networks, or between a node in one parasitic network and an instTerm or term in a different network. Each oaCouplingCap object has one capacitance value for each analysis point that the parasitic network represents.\n"
"  A coupling capacitor between two nodes in the same parasitic network is considered a local coupling cap. Local coupling caps have a single representation in the database. When a coupling capacitor physically connects two different parasitic networks, it is represented in the database as two distinct devices, one within each parasitic network. This allows each parasitic network to be loaded independently and efficiently.\n"
"  The from endpoint of a oaCouplingCap always connects to a node in the same parasitic network as the oaCouplingCap itself. For local coupling caps, the to endpoint also connects to a node in the same parasitic network.\n"
"  For coupling caps that connect nodes in two different networks, the nodes in both networks must be assigned a unique ID when the nodes are created. The net and the node ID are used to specify the node to which the to endpoint of each oaCouplingCap connects.\n"
"  For coupling caps that connect a node in one parasitic network and an instTerm or term in a different network, the node must be assigned a unique ID when it is created. The oaDesignObject for the connection is used to specify the to endpoint of the oaCouplingCap. The isOtherConn() function must be used to distinguish between this type of coupling capacitor and coupling caps between nodes in different networks.\n"
"Constructors:\n"
"  Paramegers: (oaCouplingCap)\n"
"    Calls: (const oaCouplingCap&)\n"
"    Signature: oaCouplingCap||cref-oaCouplingCap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCouplingCap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCouplingCap",
    sizeof(PyoaCouplingCapObject),
    0,
    (destructor)oaCouplingCap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCouplingCap_tp_compare,	/* tp_compare */
    (reprfunc)oaCouplingCap_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCouplingCap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCouplingCap_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdDevice_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCouplingCap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCouplingCap_static_create_doc[] = 
"Class: oaCouplingCap, Function: create\n"
"  Paramegers: (oaNode,oaNode)\n"
"    Calls: oaCouplingCap* create(oaNode* fromNode,oaNode* toNode)\n"
"    Signature: create|ptr-oaCouplingCap|ptr-oaNode,ptr-oaNode,\n"
"    This function creates a local couplingCap between the specified nodes. An exception will be thrown if the two nodes are not in the same parasitic network. The device created will not have an ID associated with it. The hasId() function will return false for these devices and the getId() function will return an oacInvalidDeviceID value.\n"
"    Coupling capacitors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the couplingCap will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The node from which to couple\n"
"    toNode\n"
"    The node to which to couple\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
"  Paramegers: (oaNode,oaNode,oaUInt4)\n"
"    Calls: oaCouplingCap* create(oaNode* fromNode,oaNode* toNode,oaUInt4 id)\n"
"    Signature: create|ptr-oaCouplingCap|ptr-oaNode,ptr-oaNode,simple-oaUInt4,\n"
"    This function creates a local coupling capacitor between the specified nodes. An explicit unique ID id is required to be specified. An exception will be thrown if the id is the reserved oacInvalidDeviceID value or if a device with the specified id value already exists. The hasId() function will return true for devices created with this function and the getId() function will return the user-specified id.\n"
"    Coupling capacitors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the couplingCap will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The node from which to couple\n"
"    toNode\n"
"    The node to which to couple\n"
"    id\n"
"    The unique ID to be assigned to this device\n"
"    oacInvalidDeviceIdSpecified\n"
"    oacLocalDeviceIdExists\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
"  Paramegers: (oaNode,oaDesignObject,oaUInt4,oaUInt4)\n"
"    Calls: oaCouplingCap* create(oaNode* fromNode,oaDesignObject* otherNet,oaUInt4 otherNodeId,oaUInt4 id)\n"
"    Signature: create|ptr-oaCouplingCap|ptr-oaNode,ptr-oaDesignObject,simple-oaUInt4,simple-oaUInt4,\n"
"    This function creates a coupling capacitor in the fromNode parasitic network that couples between fromNode and a node in the parasitic network for another net. The parasitic network for otherNet does not have to exist or be in memory at the time that this function is called. The otherNodeId specifies a unique ID for the node in the otherNet parasitic network, and that ID must be specified when the node is created.\n"
"    The coupled nets must be within a given hierarchy domain, either oaNets or oaOccNets.\n"
"    fromNode\n"
"    The node from which to couple\n"
"    otherNet\n"
"    The other network to which to couple\n"
"    otherNodeId\n"
"    A unique ID for the node in the other parasitic network\n"
"    id\n"
"    The unique ID value\n"
"    oacCoupledNodeWithoutId\n"
"    oacInvalidCouplingCapId\n"
"    oacNodeNetNotInSameDesign\n"
"    oacInvalidNet\n"
"    oacDeviceNetNotInSameDomain\n"
"    oacNonLocalDeviceIdExists\n"
"  Paramegers: (oaNode,oaDesignObject,oaUInt4)\n"
"    Calls: oaCouplingCap* create(oaNode* fromNode,oaDesignObject* otherConn,oaUInt4 id)\n"
"    Signature: create|ptr-oaCouplingCap|ptr-oaNode,ptr-oaDesignObject,simple-oaUInt4,\n"
"    This function creates a coupling capacitor in the fromNode parasitic network that couples between fromNode and an instTerm or term in the parasitic network for another net. The parasitic network for the other net does not have to exist or be in memory at the time that this function is called.\n"
"    fromNode\n"
"    The from which to couple\n"
"    otherConn\n"
"    An instTerm or term to couple to in the parasitic network for another net\n"
"    id\n"
"    The unique ID value\n"
"    oacCoupledNodeWithoutId\n"
"    oacNodeConnNotInSameDesign\n"
"    oacInvalidCouplingCapConnType\n"
"    oacNoConnForLocalCouplingCaps\n"
"    oacInvalidCouplingCapId\n"
"    oacNonLocalDeviceIdExists\n"
;

static PyObject*
oaCouplingCap_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaNode,oaNode)
    {
        PyParamoaNode p1;
        PyParamoaNode p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNode_Convert,&p1,
              &PyoaNode_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCouplingCapp result= (oaCouplingCap::create(p1.Data(),p2.Data()));
            return PyoaCouplingCap_FromoaCouplingCap(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNode,oaNode,oaUInt4)
    {
        PyParamoaNode p1;
        PyParamoaNode p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaNode_Convert,&p1,
              &PyoaNode_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCouplingCapp result= (oaCouplingCap::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCouplingCap_FromoaCouplingCap(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNode,oaDesignObject,oaUInt4,oaUInt4)
    {
        PyParamoaNode p1;
        PyParamoaDesignObject p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaNode_Convert,&p1,
              &PyoaDesignObject_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCouplingCapp result= (oaCouplingCap::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaCouplingCap_FromoaCouplingCap(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNode,oaDesignObject,oaUInt4)
    {
        PyParamoaNode p1;
        PyParamoaDesignObject p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaNode_Convert,&p1,
              &PyoaDesignObject_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCouplingCapp result= (oaCouplingCap::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCouplingCap_FromoaCouplingCap(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCouplingCap, function: create, Choices are:\n"
        "    (oaNode,oaNode)\n"
        "    (oaNode,oaNode,oaUInt4)\n"
        "    (oaNode,oaDesignObject,oaUInt4,oaUInt4)\n"
        "    (oaNode,oaDesignObject,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaCouplingCap_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaCouplingCap_static_create,METH_VARARGS,oaCouplingCap_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCouplingCap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCouplingCap_Type)<0) {
      printf("** PyType_Ready failed for: oaCouplingCap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCouplingCap",
           (PyObject*)(&PyoaCouplingCap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCouplingCap\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaCouplingCap_Type.tp_dict;
    for(method=oaCouplingCap_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaCustomVia
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCustomVia_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCustomVia_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCustomViaObject* self = (PyoaCustomViaObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCustomVia)
    {
        PyParamoaCustomVia p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCustomVia_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCustomVia, Choices are:\n"
        "    (oaCustomVia)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCustomVia_tp_dealloc(PyoaCustomViaObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCustomVia_tp_repr(PyObject *ob)
{
    PyParamoaCustomVia value;
    int convert_status=PyoaCustomVia_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaCustomVia::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCustomVia_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCustomVia v1;
    PyParamoaCustomVia v2;
    int convert_status1=PyoaCustomVia_Convert(ob1,&v1);
    int convert_status2=PyoaCustomVia_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCustomVia_Convert(PyObject* ob,PyParamoaCustomVia* result)
{
    if (ob == NULL) return 1;
    if (PyoaCustomVia_Check(ob)) {
        result->SetData( (oaCustomVia**) ((PyoaCustomViaObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCustomVia Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCustomVia_FromoaCustomVia(oaCustomVia** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCustomVia* data=*value;
        PyObject* bself = PyoaCustomVia_Type.tp_alloc(&PyoaCustomVia_Type,0);
        if (bself == NULL) return bself;
        PyoaCustomViaObject* self = (PyoaCustomViaObject*)bself;
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
PyObject* PyoaCustomVia_FromoaCustomVia(oaCustomVia* data)
{
    if (data) {
       PyObject* bself = PyoaCustomVia_Type.tp_alloc(&PyoaCustomVia_Type,0);
       if (bself == NULL) return bself;
       PyoaCustomViaObject* self = (PyoaCustomViaObject*)bself;
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
static char oaCustomVia_getCellName_doc[] = 
"Class: oaCustomVia, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name for the master design referenced by this custom via.\n"
"    cellName\n"
"    The cell name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name in the given namespace for the master design referenced by this custom via.\n"
"    ns\n"
"    The namespace for the name\n"
"    cellName\n"
"    The cell name for the master design\n"
;

static PyObject*
oaCustomVia_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getCellName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getCellName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomVia, function: getCellName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomVia_getHeader_doc[] = 
"Class: oaCustomVia, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaCustomViaHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaCustomViaHeader|\n"
"    BrowseData: 1\n"
"    This function returns the custom via header associated with this custom via. This call only returns the parameters that is specified during creation or calls to setParams() .\n"
;

static PyObject*
oaCustomVia_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCustomViaHeaderp result= (data.DataCall()->getHeader());
        return PyoaCustomViaHeader_FromoaCustomViaHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomVia_getLibName_doc[] = 
"Class: oaCustomVia, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name for the master design referenced by this custom via.\n"
"    libName\n"
"    The library name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name in the given namespace for the master design referenced by this custom via.\n"
"    ns\n"
"    The namespace for the library name\n"
"    libName\n"
"    The library name for the master design\n"
;

static PyObject*
oaCustomVia_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getLibName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getLibName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomVia, function: getLibName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomVia_getParams_doc[] = 
"Class: oaCustomVia, Function: getParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getParams(oaParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the parameters of this custom via. Only Pcell custom vias have parameters. This call only returns parameters that were specified during creation or through calls setParams() . If invoked on a custom via that is not a Pcell or if no parameter is specified for the custom via, the returned params paramArray will have zero numParams.\n"
;

static PyObject*
oaCustomVia_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParamArray_Convert,&p1)) {
        data.DataCall()->getParams(p1.Data());
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
static char oaCustomVia_getViewName_doc[] = 
"Class: oaCustomVia, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name for the master design referenced by this custom via.\n"
"    viewName\n"
"    The view name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name in the given namespace for the master design referenced by this custom via.\n"
"    ns\n"
"    The namespace for the name\n"
"    viewName\n"
"    The view name for the master design\n"
;

static PyObject*
oaCustomVia_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getViewName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getViewName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomVia, function: getViewName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomVia_setParams_doc[] = 
"Class: oaCustomVia, Function: setParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void setParams(const oaParamArray& params)\n"
"    Signature: setParams|void-void|cref-oaParamArray,\n"
"    This function changes the values of the custom via parameters associated with this custom via.\n"
;

static PyObject*
oaCustomVia_setParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaObject* self=(PyoaCustomViaObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParamArray_Convert,&p1)) {
        data.DataCall()->setParams(p1.Data());
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
static char oaCustomVia_isNull_doc[] =
"Class: oaCustomVia, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCustomVia_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCustomVia data;
    int convert_status=PyoaCustomVia_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCustomVia_assign_doc[] = 
"Class: oaCustomVia, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCustomVia_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCustomVia data;
  int convert_status=PyoaCustomVia_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCustomVia p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCustomVia_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCustomVia_methodlist[] = {
    {"getCellName",(PyCFunction)oaCustomVia_getCellName,METH_VARARGS,oaCustomVia_getCellName_doc},
    {"getHeader",(PyCFunction)oaCustomVia_getHeader,METH_VARARGS,oaCustomVia_getHeader_doc},
    {"getLibName",(PyCFunction)oaCustomVia_getLibName,METH_VARARGS,oaCustomVia_getLibName_doc},
    {"getParams",(PyCFunction)oaCustomVia_getParams,METH_VARARGS,oaCustomVia_getParams_doc},
    {"getViewName",(PyCFunction)oaCustomVia_getViewName,METH_VARARGS,oaCustomVia_getViewName_doc},
    {"setParams",(PyCFunction)oaCustomVia_setParams,METH_VARARGS,oaCustomVia_setParams_doc},
    {"isNull",(PyCFunction)oaCustomVia_tp_isNull,METH_VARARGS,oaCustomVia_isNull_doc},
    {"assign",(PyCFunction)oaCustomVia_tp_assign,METH_VARARGS,oaCustomVia_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCustomVia_doc[] = 
"Class: oaCustomVia\n"
"  The oaCustomVia class implements an object that represents a custom via. A custom via is an instance of a custom via definition which is implemented by the oaCustomViaDef object. A custom via definition is associated with a via master which is another design that defines the custom via. The via master may be parameterized and its parameters are specified through the use of an oaParamArray object.\n"
"  A Pcell custom via can be created with a subset of the parameters defined in the superMaster. Any parameters not specified will become default parameters which will track changes in the superMaster's parameter value. When a parameter is specified during creation or any subsequence calls to setParam(), this parameter will not be classified as a default parameter even though its values equals to the default value in the superMaster.\n"
"  A custom via may be used as an object associated with an oaRoute .\n"
"Constructors:\n"
"  Paramegers: (oaCustomVia)\n"
"    Calls: (const oaCustomVia&)\n"
"    Signature: oaCustomVia||cref-oaCustomVia,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCustomVia_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCustomVia",
    sizeof(PyoaCustomViaObject),
    0,
    (destructor)oaCustomVia_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCustomVia_tp_compare,	/* tp_compare */
    (reprfunc)oaCustomVia_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCustomVia_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCustomVia_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaVia_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCustomVia_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCustomVia_static_create_doc[] = 
"Class: oaCustomVia, Function: create\n"
"  Paramegers: (oaBlock,oaCustomViaDef,oaTransform)\n"
"    Calls: oaCustomVia* create(oaBlock* block,const oaCustomViaDef* viaDef,const oaTransform& xform)\n"
"    Signature: create|ptr-oaCustomVia|ptr-oaBlock,cptr-oaCustomViaDef,cref-oaTransform,cptr-oaParamArray,\n"
"    This function creates a custom via with the specified attributes.\n"
"    An exception is thrown if the via to be created uses a viaDef from a technology database that is not included in the referenced graph of technology databases for the technology database bound to the design containing the via.\n"
"    block\n"
"    The block to create the custom via in\n"
"    viaDef\n"
"    The viaDef to reference; it specifies the default values for the related custom via parameters\n"
"    xform\n"
"    The transform to apply to the standard via\n"
"    params\n"
"    A pointer to the custom via parameters; a NULL value specifies that default parameters are to be used\n"
"    oacViaDefNotInTechAssociatedWithDesign\n"
"    oacParamsSuppliedForNonPCellViaMaster\n"
"  Paramegers: (oaBlock,oaCustomViaDef,oaTransform,oaParamArray)\n"
"    Calls: oaCustomVia* create(oaBlock* block,const oaCustomViaDef* viaDef,const oaTransform& xform,const oaParamArray* params)\n"
"    Signature: create|ptr-oaCustomVia|ptr-oaBlock,cptr-oaCustomViaDef,cref-oaTransform,cptr-oaParamArray,\n"
"    This function creates a custom via with the specified attributes.\n"
"    An exception is thrown if the via to be created uses a viaDef from a technology database that is not included in the referenced graph of technology databases for the technology database bound to the design containing the via.\n"
"    block\n"
"    The block to create the custom via in\n"
"    viaDef\n"
"    The viaDef to reference; it specifies the default values for the related custom via parameters\n"
"    xform\n"
"    The transform to apply to the standard via\n"
"    params\n"
"    A pointer to the custom via parameters; a NULL value specifies that default parameters are to be used\n"
"    oacViaDefNotInTechAssociatedWithDesign\n"
"    oacParamsSuppliedForNonPCellViaMaster\n"
;

static PyObject*
oaCustomVia_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaCustomViaDef,oaTransform)
    {
        PyParamoaBlock p1;
        PyParamoaCustomViaDef p2;
        PyParamoaTransform p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaCustomViaDef_Convert,&p2,
              &PyoaTransform_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCustomViap result= (oaCustomVia::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaCustomVia_FromoaCustomVia(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaCustomViaDef,oaTransform,oaParamArray)
    {
        PyParamoaBlock p1;
        PyParamoaCustomViaDef p2;
        PyParamoaTransform p3;
        PyParamoaParamArray p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaCustomViaDef_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaParamArray_ConvertAof,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaCustomViap result= (oaCustomVia::create(p1.Data(),p2.Data(),p3.Data(),p4.DataAof()));
            return PyoaCustomVia_FromoaCustomVia(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomVia, function: create, Choices are:\n"
        "    (oaBlock,oaCustomViaDef,oaTransform)\n"
        "    (oaBlock,oaCustomViaDef,oaTransform,oaParamArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaCustomVia_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaCustomVia_static_create,METH_VARARGS,oaCustomVia_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCustomVia_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCustomVia_Type)<0) {
      printf("** PyType_Ready failed for: oaCustomVia\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCustomVia",
           (PyObject*)(&PyoaCustomVia_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCustomVia\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaCustomVia_Type.tp_dict;
    for(method=oaCustomVia_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaCustomViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCustomViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCustomViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCustomViaDefObject* self = (PyoaCustomViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCustomViaDef)
    {
        PyParamoaCustomViaDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCustomViaDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCustomViaDef, Choices are:\n"
        "    (oaCustomViaDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCustomViaDef_tp_dealloc(PyoaCustomViaDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCustomViaDef_tp_repr(PyObject *ob)
{
    PyParamoaCustomViaDef value;
    int convert_status=PyoaCustomViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaCustomViaDef::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[36];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaCustomViaDef::");
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
oaCustomViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCustomViaDef v1;
    PyParamoaCustomViaDef v2;
    int convert_status1=PyoaCustomViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaCustomViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCustomViaDef_Convert(PyObject* ob,PyParamoaCustomViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCustomViaDef_Check(ob)) {
        result->SetData( (oaCustomViaDef**) ((PyoaCustomViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCustomViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCustomViaDef_FromoaCustomViaDef(oaCustomViaDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCustomViaDef* data=*value;
        PyObject* bself = PyoaCustomViaDef_Type.tp_alloc(&PyoaCustomViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCustomViaDefObject* self = (PyoaCustomViaDefObject*)bself;
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
PyObject* PyoaCustomViaDef_FromoaCustomViaDef(oaCustomViaDef* data)
{
    if (data) {
       PyObject* bself = PyoaCustomViaDef_Type.tp_alloc(&PyoaCustomViaDef_Type,0);
       if (bself == NULL) return bself;
       PyoaCustomViaDefObject* self = (PyoaCustomViaDefObject*)bself;
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
static char oaCustomViaDef_getCellName_doc[] = 
"Class: oaCustomViaDef, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name of the master design referenced by this oaViaDef object.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& out) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name of the master design referenced by this oaViaDef object in the specified nameSpace.\n"
;

static PyObject*
oaCustomViaDef_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaDef data;
    int convert_status=PyoaCustomViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaDefObject* self=(PyoaCustomViaDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getCellName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getCellName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaDef, function: getCellName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaDef_getLibName_doc[] = 
"Class: oaCustomViaDef, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name of the master design referenced by this oaViaDef object.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& out) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name of the master design referenced by this oaViaDef object in the specified namespace.\n"
;

static PyObject*
oaCustomViaDef_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaDef data;
    int convert_status=PyoaCustomViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaDefObject* self=(PyoaCustomViaDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getLibName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getLibName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaDef, function: getLibName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaDef_getViewName_doc[] = 
"Class: oaCustomViaDef, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name of the master design referenced by this oaViaDef object.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& out) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name of the master design referenced by this oaViaDef object in the specified namespace.\n"
;

static PyObject*
oaCustomViaDef_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaDef data;
    int convert_status=PyoaCustomViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaDefObject* self=(PyoaCustomViaDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getViewName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getViewName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaDef, function: getViewName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaDef_setMaster_doc[] = 
"Class: oaCustomViaDef, Function: setMaster\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void setMaster(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: setMaster|void-void|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function is used to reset the libName, cellName, and viewName of the via master represented by this oaCustomViaDef. After these names are reset, oaCustomViaHeaders and oaCustomVias that refer to this oaCustomViaDef will be rebound to the new design specified by the specified lib, cell and view names.\n"
"    Note: If the specified libName, cellName, and viewName are the same as the current via master names, remastering will not be performed. If remastering is performed, preModify and postModify observer notifications with a oaViaDefModTypeEnum of oacCustomViaDefSetMasterViaDefModType are triggered -- see OpenAccess Observer Table for more information.\n"
"    libName\n"
"    via master library name to set\n"
"    cellName\n"
"    via master cell name to set\n"
"    viewName\n"
"    via master view name to set\n"
;

static PyObject*
oaCustomViaDef_setMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaDef data;
    int convert_status=PyoaCustomViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaDefObject* self=(PyoaCustomViaDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        data.DataCall()->setMaster(p1.Data(),p2.Data(),p3.Data());
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
static char oaCustomViaDef_isNull_doc[] =
"Class: oaCustomViaDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCustomViaDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCustomViaDef data;
    int convert_status=PyoaCustomViaDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCustomViaDef_assign_doc[] = 
"Class: oaCustomViaDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCustomViaDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCustomViaDef data;
  int convert_status=PyoaCustomViaDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCustomViaDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCustomViaDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCustomViaDef_methodlist[] = {
    {"getCellName",(PyCFunction)oaCustomViaDef_getCellName,METH_VARARGS,oaCustomViaDef_getCellName_doc},
    {"getLibName",(PyCFunction)oaCustomViaDef_getLibName,METH_VARARGS,oaCustomViaDef_getLibName_doc},
    {"getViewName",(PyCFunction)oaCustomViaDef_getViewName,METH_VARARGS,oaCustomViaDef_getViewName_doc},
    {"setMaster",(PyCFunction)oaCustomViaDef_setMaster,METH_VARARGS,oaCustomViaDef_setMaster_doc},
    {"isNull",(PyCFunction)oaCustomViaDef_tp_isNull,METH_VARARGS,oaCustomViaDef_isNull_doc},
    {"assign",(PyCFunction)oaCustomViaDef_tp_assign,METH_VARARGS,oaCustomViaDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCustomViaDef_doc[] = 
"Class: oaCustomViaDef\n"
"  The oaCustomViaDef class implements an oaCustomViaDef object in a technology database. The oaCustomViaDef defines a via that has its geometry specified as the contents of a stored design.\n"
"  An oaCustomViaDef object has an unique name and is associated with a master design and two layers. A custom via in a route must point to an oaCustomViaDef object in the technology database associated with the design where the route resides.\n"
"  An oaCustomViaDef is used when an oaCustomVia is created that references it. It is possible for the design that the viaDef points at to be a pcell. In that case the oaCustomVia may have an oaParamArray that provides override values for that pcell.\n"
"  Benefits and Restrictions Associated with OpenAccess oaCustomViaDefs\n"
"  One of the benefits of OpenAccess is that it has a formal definition of a via that is distinct from a generic instance. By definition, a via encapsulates the physical geometry to connect exactly two layers. To allow applications to efficiently analyze routing that contains custom vias, OpenAccess places restrictions on the contents of custom via masters, as follows:\n"
"  custom via masters may not contain any hierarchy. In other words, custom via masters may not contain instances of other vias.\n"
"  custom via masters may contain only shapes. They may not contain blockages, boundaries, rows, guides, routes, or any other type of physical object.\n"
"  custom via masters may not contain markers.\n"
"  custom via masters should not contain any connectivity objects (e.g. nets, terminals) since there is no purpose to provide such connectivity information and the information will be ignored by the rest of OpenAccess and all applications.\n"
"  Note: Unlike its treatment of instances, OpenAccess always attempts to bind vias to their masters implicitly. It is not an error for via masters to be unbound (for example, due to missing data), but OpenAccess will continually attempt to bind the vias when possible. This is done because most applications are unable work with routing that contains unbound vias.\n"
"Constructors:\n"
"  Paramegers: (oaCustomViaDef)\n"
"    Calls: (const oaCustomViaDef&)\n"
"    Signature: oaCustomViaDef||cref-oaCustomViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCustomViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCustomViaDef",
    sizeof(PyoaCustomViaDefObject),
    0,
    (destructor)oaCustomViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCustomViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCustomViaDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCustomViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCustomViaDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaViaDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCustomViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCustomViaDef_static_create_doc[] = 
"Class: oaCustomViaDef, Function: create\n"
"  Paramegers: (oaTech,oaString,oaScalarName,oaScalarName,oaScalarName,oaPhysicalLayer,oaPhysicalLayer)\n"
"    Calls: oaCustomViaDef* create(oaTech* tech,const oaString& name,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaPhysicalLayer* layer1,oaPhysicalLayer* layer2)\n"
"    Signature: create|ptr-oaCustomViaDef|ptr-oaTech,cref-oaString,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,ptr-oaPhysicalLayer,ptr-oaPhysicalLayer,\n"
"    This function creates an oaCustomViaDef object with the specified attributes. With this version of the create() function, you specify the master design by its library, cell, and view names.\n"
"    This function throws an exception if a viaDef with the specified name already exists. An exception is also thrown if layer1 and layer2 are not included in the graph of technology databases rooted at the specified tech .\n"
"    Note: The intended use is for layer1 to be the bottom layer, which should be the layer with the lower manufacturing layer number. Layer2 should be the top layer. The database does not enforce this because some tech databases do not have valid manufacturing layer numbers. Some applications require this layer ordering.\n"
"    tech\n"
"    The technology database to use\n"
"    name\n"
"    The custom viaDef object name\n"
"    libName\n"
"    The libraryName of the master design\n"
"    cellName\n"
"    The cellName of the master design\n"
"    viewName\n"
"    The viewName of the master design\n"
"    layer1\n"
"    A pointer to the first physical layer for the viaDef\n"
"    layer2\n"
"    A pointer to the second physical layer for the viaDef\n"
"    oacLayerNotInReferencedTech\n"
"    oacConflictingLayerNamesInTech\n"
"    oacConflictingLayerNumbersInTech\n"
"    oacViaDefExists\n"
;

static PyObject*
oaCustomViaDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTech p1;
    PyParamoaString p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaScalarName p5;
    PyParamoaPhysicalLayer p6;
    PyParamoaPhysicalLayer p7;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
          &PyoaTech_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaScalarName_Convert,&p5,
          &PyoaPhysicalLayer_Convert,&p6,
          &PyoaPhysicalLayer_Convert,&p7)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p6.Data(),6)) return NULL;
        if (!PyValidateDbObject(p7.Data(),7)) return NULL;
        oaCustomViaDefp result= (oaCustomViaDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
        return PyoaCustomViaDef_FromoaCustomViaDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaCustomViaDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaCustomViaDef_static_create,METH_VARARGS,oaCustomViaDef_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCustomViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCustomViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCustomViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCustomViaDef",
           (PyObject*)(&PyoaCustomViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCustomViaDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaCustomViaDef_Type.tp_dict;
    for(method=oaCustomViaDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaCustomViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCustomViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCustomViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCustomViaHeaderObject* self = (PyoaCustomViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCustomViaHeader)
    {
        PyParamoaCustomViaHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCustomViaHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCustomViaHeader, Choices are:\n"
        "    (oaCustomViaHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCustomViaHeader_tp_dealloc(PyoaCustomViaHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCustomViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaCustomViaHeader value;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaCustomViaHeader::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getViaDefName(sresult);
    
        char addr[39];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaCustomViaHeader::");
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
oaCustomViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCustomViaHeader v1;
    PyParamoaCustomViaHeader v2;
    int convert_status1=PyoaCustomViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCustomViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCustomViaHeader_Convert(PyObject* ob,PyParamoaCustomViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCustomViaHeader_Check(ob)) {
        result->SetData( (oaCustomViaHeader**) ((PyoaCustomViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCustomViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCustomViaHeader_FromoaCustomViaHeader(oaCustomViaHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCustomViaHeader* data=*value;
        PyObject* bself = PyoaCustomViaHeader_Type.tp_alloc(&PyoaCustomViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCustomViaHeaderObject* self = (PyoaCustomViaHeaderObject*)bself;
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
PyObject* PyoaCustomViaHeader_FromoaCustomViaHeader(oaCustomViaHeader* data)
{
    if (data) {
       PyObject* bself = PyoaCustomViaHeader_Type.tp_alloc(&PyoaCustomViaHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaCustomViaHeaderObject* self = (PyoaCustomViaHeaderObject*)bself;
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
static char oaCustomViaHeader_getAllParams_doc[] = 
"Class: oaCustomViaHeader, Function: getAllParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getAllParams(oaParamArray& params) const\n"
"    Signature: getAllParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the complete set of parameters associated with this customViaHeader. The paramArray will contain the params for which this via uses default values and the params for which it uses override values. If this viaHeader is not associated with a Pcell via master, params will have a numParams of zero.\n"
;

static PyObject*
oaCustomViaHeader_getAllParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaHeaderObject* self=(PyoaCustomViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParamArray_Convert,&p1)) {
        data.DataCall()->getAllParams(p1.Data());
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
static char oaCustomViaHeader_getCellName_doc[] = 
"Class: oaCustomViaHeader, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name of the master oaDesign referenced by this customViaHeader.\n"
"    cellName\n"
"    The returned cell name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name of the master oaDesign referenced by this customViaHeader.\n"
"    ns\n"
"    The namespace in which to return the cell name.\n"
"    cellName\n"
"    The returned cell name.\n"
;

static PyObject*
oaCustomViaHeader_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaHeaderObject* self=(PyoaCustomViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getCellName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getCellName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaHeader, function: getCellName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaHeader_getLibName_doc[] = 
"Class: oaCustomViaHeader, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name of the master oaDesign referenced by this customViaHeader.\n"
"    libName\n"
"    The returned library name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name of the master oaDesign referenced by this customViaHeader.\n"
"    ns\n"
"    The namespace in which to return the library name.\n"
"    libName\n"
"    The returned library name.\n"
;

static PyObject*
oaCustomViaHeader_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaHeaderObject* self=(PyoaCustomViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getLibName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getLibName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaHeader, function: getLibName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaHeader_getParams_doc[] = 
"Class: oaCustomViaHeader, Function: getParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getParams(oaParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the parameters associated with this customViaHeader. This call only returns the non-default parameters that were specified during creation or through calls to setParams() on the custom vias. If this viaHeader is not associated with a Pcell via master or uses all default parameters, params will have a numParams of zero.\n"
;

static PyObject*
oaCustomViaHeader_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaHeaderObject* self=(PyoaCustomViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaParamArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaParamArray_Convert,&p1)) {
        data.DataCall()->getParams(p1.Data());
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
static char oaCustomViaHeader_getViewName_doc[] = 
"Class: oaCustomViaHeader, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name of the master oaDesign referenced by this customViaHeader.\n"
"    viewName\n"
"    The returned view name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name of the master oaDesign referenced by this customViaHeader.\n"
"    ns\n"
"    The namespace in which to return the view name.\n"
"    viewName\n"
"    The returned view name.\n"
;

static PyObject*
oaCustomViaHeader_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCustomViaHeaderObject* self=(PyoaCustomViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getViewName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getViewName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCustomViaHeader, function: getViewName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCustomViaHeader_isNull_doc[] =
"Class: oaCustomViaHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCustomViaHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCustomViaHeader data;
    int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCustomViaHeader_assign_doc[] = 
"Class: oaCustomViaHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCustomViaHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCustomViaHeader data;
  int convert_status=PyoaCustomViaHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCustomViaHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCustomViaHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCustomViaHeader_methodlist[] = {
    {"getAllParams",(PyCFunction)oaCustomViaHeader_getAllParams,METH_VARARGS,oaCustomViaHeader_getAllParams_doc},
    {"getCellName",(PyCFunction)oaCustomViaHeader_getCellName,METH_VARARGS,oaCustomViaHeader_getCellName_doc},
    {"getLibName",(PyCFunction)oaCustomViaHeader_getLibName,METH_VARARGS,oaCustomViaHeader_getLibName_doc},
    {"getParams",(PyCFunction)oaCustomViaHeader_getParams,METH_VARARGS,oaCustomViaHeader_getParams_doc},
    {"getViewName",(PyCFunction)oaCustomViaHeader_getViewName,METH_VARARGS,oaCustomViaHeader_getViewName_doc},
    {"isNull",(PyCFunction)oaCustomViaHeader_tp_isNull,METH_VARARGS,oaCustomViaHeader_isNull_doc},
    {"assign",(PyCFunction)oaCustomViaHeader_tp_assign,METH_VARARGS,oaCustomViaHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCustomViaHeader_doc[] = 
"Class: oaCustomViaHeader\n"
"  The oaCustomViaHeader class implements an object that contains information about custom vias of a particular oaCustomViaDef object used in a design. For designs containing custom vias of oaCustomViaDefs that are associated with a parameterized master design, there are two kinds of customViaHeaders:\n"
"  SuperHeaders represent all of the instances of a Pcell master, regardless of parameter settings\n"
"  SubHeaders represent all of the instances that have one specific set of parameter values\n"
"  Every custom via of a Pcell has exactly one subHeader, which, in turn, has exactly one superHeader. CustomViaHeaders for instances that are not Pcells are neither subheaders nor superheaders.\n"
"Constructors:\n"
"  Paramegers: (oaCustomViaHeader)\n"
"    Calls: (const oaCustomViaHeader&)\n"
"    Signature: oaCustomViaHeader||cref-oaCustomViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCustomViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCustomViaHeader",
    sizeof(PyoaCustomViaHeaderObject),
    0,
    (destructor)oaCustomViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCustomViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCustomViaHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCustomViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCustomViaHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaViaHeader_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCustomViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCustomViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCustomViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCustomViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCustomViaHeader",
           (PyObject*)(&PyoaCustomViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCustomViaHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDBType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDBType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDBType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDBTypeObject* self = (PyoaDBTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaDBType();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDBTypeEnum)
    {
        PyParamoaDBTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDBTypeEnum_Convert,&p1)) {
            self->value =  new oaDBType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaDBType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDBType)
    {
        PyParamoaDBType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDBType_Convert,&p1)) {
            self->value= new oaDBType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDBType, Choices are:\n"
        "    ()\n"
        "    (oaDBTypeEnum)\n"
        "    (oaString)\n"
        "    (oaDBType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDBType_tp_dealloc(PyoaDBTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDBType_tp_repr(PyObject *ob)
{
    PyParamoaDBType value;
    int convert_status=PyoaDBType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[30];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaDBType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDBType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDBType v1;
    PyParamoaDBType v2;
    int convert_status1=PyoaDBType_Convert(ob1,&v1);
    int convert_status2=PyoaDBType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDBType_Convert(PyObject* ob,PyParamoaDBType* result)
{
    if (ob == NULL) return 1;
    if (PyoaDBType_Check(ob)) {
        result->SetData(  ((PyoaDBTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDBType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDBType_FromoaDBType(oaDBType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaDBType_Type.tp_alloc(&PyoaDBType_Type,0);
        if (bself == NULL) return bself;
        PyoaDBTypeObject* self = (PyoaDBTypeObject*)bself;
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
PyObject* PyoaDBType_FromoaDBType(const oaDBType& data)
{
    PyObject* bself = PyoaDBType_Type.tp_alloc(&PyoaDBType_Type,0);
    if (bself == NULL) return bself;
    PyoaDBTypeObject* self = (PyoaDBTypeObject*)bself;
    self->value =  new oaDBType(data);
    self->borrow = 0;
    self->locks = NULL;
    return bself;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDBType_getName_doc[] = 
"Class: oaDBType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns a reference to a constant oaString object that represents the name of this database type.\n"
;

static PyObject*
oaDBType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDBType data;
    int convert_status=PyoaDBType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDBTypeObject* self=(PyoaDBTypeObject*)ob;

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
static char oaDBType_oaDBTypeEnum_doc[] = 
"Class: oaDBType, Function: oaDBTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaDBTypeEnum oaDBTypeEnum() const\n"
"    Signature: operator oaDBTypeEnum|simple-oaDBTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator returns the enumerated value that corresponds to the database type that this object represents.\n"
;

static PyObject*
oaDBType_oaDBTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDBType data;
    int convert_status=PyoaDBType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDBTypeObject* self=(PyoaDBTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDBTypeEnum result= (data.DataCall()->operator oaDBTypeEnum());
        return PyoaDBTypeEnum_FromoaDBTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaDBType_assign_doc[] = 
"Class: oaDBType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDBType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDBType data;
  int convert_status=PyoaDBType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDBType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDBType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDBType_methodlist[] = {
    {"getName",(PyCFunction)oaDBType_getName,METH_VARARGS,oaDBType_getName_doc},
    {"oaDBTypeEnum",(PyCFunction)oaDBType_oaDBTypeEnum,METH_VARARGS,oaDBType_oaDBTypeEnum_doc},
    {"assign",(PyCFunction)oaDBType_tp_assign,METH_VARARGS,oaDBType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDBType_doc[] = 
"Class: oaDBType\n"
"  The oaDBType class is an enum wrapper class for oaDBTypeEnum values. It indicates the type of an OpenAccess database.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaDBTypeEnum\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDBType()\n"
"    Signature: oaDBType||\n"
"    Constructor oaDBType\n"
"  Paramegers: (oaDBTypeEnum)\n"
"    Calls: oaDBType(oaDBTypeEnum typeIn)\n"
"    Signature: oaDBType||simple-oaDBTypeEnum,\n"
"    This constructor creates an oaDBType object based on the enumerated value corresponding to the database type.\n"
"    typeIn\n"
"    The enumerated value that represents the database type\n"
"  Paramegers: (oaString)\n"
"    Calls: oaDBType(const oaString& name)\n"
"    Signature: oaDBType||cref-oaString,\n"
"    This constructor creates an oaDBType object based on the constant string value that represents the database type.\n"
"    name\n"
"    A reference to a constant oaString object that holds the database type name\n"
"  Paramegers: (oaDBType)\n"
"    Calls: (const oaDBType&)\n"
"    Signature: oaDBType||cref-oaDBType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDBType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDBType",
    sizeof(PyoaDBTypeObject),
    0,
    (destructor)oaDBType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDBType_tp_compare,	/* tp_compare */
    (reprfunc)oaDBType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDBType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDBType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDBType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDBType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDBType_Type)<0) {
      printf("** PyType_Ready failed for: oaDBType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDBType",
           (PyObject*)(&PyoaDBType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDBType\n");
       return -1;
    }
    return 0;
}


// ==================================================================
// Array for class: oaDBType
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDBType_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDBType_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaDBType_ArrayObject* self = (PyoaDBType_ArrayObject*)gself;
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
    /* Case: (oaDBType_Array) */
    {
        PyParamoaDBType_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDBType_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDBType_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaDBType_Array)\n"
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
oaDBType_Array_dealloc(PyObject* gself)
{
    PyoaDBType_ArrayObject* self = (PyoaDBType_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaDBType_Array_str(PyObject *ob)
{
    PyParamoaDBType_Array value;
    int convert_status=PyoaDBType_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaDBType_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaDBType_Array_repr(PyObject *ob)
{
    PyParamoaDBType_Array value;
    int convert_status=PyoaDBType_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaDBType_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaDBType_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDBType_Array p1;
    PyParamoaDBType_Array p2;
    int s1=PyoaDBType_Array_Convert(ob1,&p1);
    int s2=PyoaDBType_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaDBType_Array_CreateList(p1);
    PyObject* l2=PyoaDBType_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaDBType_Array_Convert(PyObject* ob,PyParamoaDBType_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaDBType_Array_Check(ob)) {
    PyoaDBType_ArrayObject* self = (PyoaDBType_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaDBType data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaDBType_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaDBType data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaDBType_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaDBType_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaDBType_Array_FromoaDBType_Array(const oaDBType_Array& value)
{
  PyObject* gself = PyoaDBType_Array_Type.tp_alloc(&PyoaDBType_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaDBType_ArrayObject* self = (PyoaDBType_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDBType_Array_FromoaDBType_Array(PyTypeoaDBType* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaDBType_Array_Type.tp_alloc(&PyoaDBType_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaDBType_ArrayObject* self = (PyoaDBType_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDBType_Array_CreateList(PyParamoaDBType_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaDBType_FromoaDBType(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaDBType_Array_assign_doc[] = 
"Class: oaDBType_Array, Function: assign\n"
"  Paramegers: (oaDBType_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaDBType_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaDBType_ArrayObject* self=(PyoaDBType_ArrayObject*)ob;
  try {
    PyParamoaDBType_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDBType_Array_Convert,&p1)) {
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
static char oaDBType_Array_list_doc[] = 
"Class: oaDBType_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaDBType_Array_list(PyObject* ob, PyObject *args)
{
  PyoaDBType_ArrayObject* self=(PyoaDBType_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaDBType_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaDBType_Array_methodlist[] = {
    {"assign",(PyCFunction)oaDBType_Array_assign,METH_VARARGS,oaDBType_Array_assign_doc},
    {"list",(PyCFunction)oaDBType_Array_list,METH_VARARGS,oaDBType_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaDBType_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaDBType_ArrayObject* self=(PyoaDBType_ArrayObject*)ob;
  try {
    PyParamoaDBType_Array data;
    int convert_status=PyoaDBType_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaDBType_FromoaDBType(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaDBType_Array_index_get_length(PyObject* ob)
{
    PyParamoaDBType_Array data;
    int convert_status=PyoaDBType_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaDBType_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaDBType_Array data;
    PyParamoaDBType dataitem;
    int convert_status=PyoaDBType_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaDBType_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaDBType_Array_doc[] =
"Class: oaDBType_Array\n"
"  The oaDBType_Array utility class provides an array of oaDBType.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDBType_Array()\n"
"    Signature: oaDBType_Array||\n"
"    This is the default constructor for the oaDBType_Array class. This constructor creates an empty oaDBType_Array.\n"
"  Paramegers: (oaDBType_Array)\n"
"    Calls: (const oaDBType_Array&)\n"
"    Signature: oaDBType_Array||cref-oaDBType_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaDBType_Array_as_sequence = {
    (Pyoa_inquiry)oaDBType_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaDBType_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaDBType_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaDBType_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDBType_Array",
    sizeof(PyoaDBType_ArrayObject),
    0,
    oaDBType_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaDBType_Array_compare,    /* tp_compare */
    oaDBType_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaDBType_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaDBType_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDBType_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaDBType_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaDBType_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaDBType_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDBType_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaDBType_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaDBType_Array",
           (PyObject*)(&PyoaDBType_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDBType_Array\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDBTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaDBTypeEnum_Convert(PyObject* ob,PyParamoaDBTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacFutureDBType")==0) { result->SetData(oacFutureDBType); return 1;}
        if (strcasecmp(str,"oacBaseDBType")==0) { result->SetData(oacBaseDBType); return 1;}
        if (strcasecmp(str,"oacDesignDBType")==0) { result->SetData(oacDesignDBType); return 1;}
        if (strcasecmp(str,"oacTechDBType")==0) { result->SetData(oacTechDBType); return 1;}
        if (strcasecmp(str,"oacLibDBType")==0) { result->SetData(oacLibDBType); return 1;}
        if (strcasecmp(str,"oacWaferDBType")==0) { result->SetData(oacWaferDBType); return 1;}
        if (strcasecmp(str,"oacSessionDBType")==0) { result->SetData(oacSessionDBType); return 1;}
        if (strcasecmp(str,"oacDMDataDBType")==0) { result->SetData(oacDMDataDBType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaDBTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDBTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaDBTypeEnum_FromoaDBTypeEnum(oaDBTypeEnum ob)
{
    if (ob==oacFutureDBType) return PyString_FromString("oacFutureDBType");
    if (ob==oacBaseDBType) return PyString_FromString("oacBaseDBType");
    if (ob==oacDesignDBType) return PyString_FromString("oacDesignDBType");
    if (ob==oacTechDBType) return PyString_FromString("oacTechDBType");
    if (ob==oacLibDBType) return PyString_FromString("oacLibDBType");
    if (ob==oacWaferDBType) return PyString_FromString("oacWaferDBType");
    if (ob==oacSessionDBType) return PyString_FromString("oacSessionDBType");
    if (ob==oacDMDataDBType) return PyString_FromString("oacDMDataDBType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaDBTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaDBTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaDBTypeEnum_FromoaDBTypeEnum(oaDBTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaDBTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaDBTypeEnum_doc[] =
"Type convert function for enum: oaDBTypeEnum";
                               
static PyMethodDef PyoaDBTypeEnum_method =
  {"oaDBTypeEnum",(PyCFunction)PyoaDBTypeEnum_TypeFunction,METH_VARARGS,oaDBTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaDBTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacFutureDBType");
    PyDict_SetItemString(mod_dict,"oacFutureDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBaseDBType");
    PyDict_SetItemString(mod_dict,"oacBaseDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDesignDBType");
    PyDict_SetItemString(mod_dict,"oacDesignDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTechDBType");
    PyDict_SetItemString(mod_dict,"oacTechDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibDBType");
    PyDict_SetItemString(mod_dict,"oacLibDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferDBType");
    PyDict_SetItemString(mod_dict,"oacWaferDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionDBType");
    PyDict_SetItemString(mod_dict,"oacSessionDBType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMDataDBType");
    PyDict_SetItemString(mod_dict,"oacDMDataDBType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaDBTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaDBTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaDBTypeEnum\n");
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
// Wrapper Implementation for Class: oaDMAttr
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMAttr_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMAttrObject* self = (PyoaDMAttrObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaDMAttr();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaString)
    {
        PyParamoaString p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            self->value =  new oaDMAttr(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDMAttr)
    {
        PyParamoaDMAttr p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMAttr_Convert,&p1)) {
            self->value= new oaDMAttr(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDMAttr, Choices are:\n"
        "    ()\n"
        "    (oaString,oaString)\n"
        "    (oaDMAttr)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMAttr_tp_dealloc(PyoaDMAttrObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_tp_repr(PyObject *ob)
{
    PyParamoaDMAttr value;
    int convert_status=PyoaDMAttr_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaDMAttr::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMAttr_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMAttr v1;
    PyParamoaDMAttr v2;
    int convert_status1=PyoaDMAttr_Convert(ob1,&v1);
    int convert_status2=PyoaDMAttr_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMAttr_Convert(PyObject* ob,PyParamoaDMAttr* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMAttr_Check(ob)) {
        result->SetData(  ((PyoaDMAttrObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMAttr Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMAttr_FromoaDMAttr(oaDMAttr* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaDMAttr_Type.tp_alloc(&PyoaDMAttr_Type,0);
        if (bself == NULL) return bself;
        PyoaDMAttrObject* self = (PyoaDMAttrObject*)bself;
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
PyObject* PyoaDMAttr_FromoaDMAttr(const oaDMAttr& data)
{
    PyObject* bself = PyoaDMAttr_Type.tp_alloc(&PyoaDMAttr_Type,0);
    if (bself == NULL) return bself;
    PyoaDMAttrObject* self = (PyoaDMAttrObject*)bself;
    self->value =  new oaDMAttr(data);
    self->borrow = 0;
    self->locks = NULL;
    return bself;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMAttr_getName_doc[] = 
"Class: oaDMAttr, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name of this DMAttribute.\n"
;

static PyObject*
oaDMAttr_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMAttr data;
    int convert_status=PyoaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMAttrObject* self=(PyoaDMAttrObject*)ob;

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
static char oaDMAttr_getValue_doc[] = 
"Class: oaDMAttr, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getValue() const\n"
"    Signature: getValue|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the value of this DMAttribute.\n"
;

static PyObject*
oaDMAttr_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMAttr data;
    int convert_status=PyoaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMAttrObject* self=(PyoaDMAttrObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaString result= (data.DataCall()->getValue());
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
static char oaDMAttr_setName_doc[] = 
"Class: oaDMAttr, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& nameIn)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this dmAttr object.\n"
"    nameIn\n"
"    input name\n"
;

static PyObject*
oaDMAttr_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMAttr data;
    int convert_status=PyoaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMAttrObject* self=(PyoaDMAttrObject*)ob;

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
static char oaDMAttr_setValue_doc[] = 
"Class: oaDMAttr, Function: setValue\n"
"  Paramegers: (oaString)\n"
"    Calls: void setValue(const oaString& valueIn)\n"
"    Signature: setValue|void-void|cref-oaString,\n"
"    This function sets the value of this dmAttr object.\n"
"    valueIn\n"
"    input value\n"
;

static PyObject*
oaDMAttr_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMAttr data;
    int convert_status=PyoaDMAttr_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMAttrObject* self=(PyoaDMAttrObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setValue(p1.Data());
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

static char oaDMAttr_assign_doc[] = 
"Class: oaDMAttr, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMAttr_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMAttr data;
  int convert_status=PyoaDMAttr_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMAttr p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMAttr_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMAttr_methodlist[] = {
    {"getName",(PyCFunction)oaDMAttr_getName,METH_VARARGS,oaDMAttr_getName_doc},
    {"getValue",(PyCFunction)oaDMAttr_getValue,METH_VARARGS,oaDMAttr_getValue_doc},
    {"setName",(PyCFunction)oaDMAttr_setName,METH_VARARGS,oaDMAttr_setName_doc},
    {"setValue",(PyCFunction)oaDMAttr_setValue,METH_VARARGS,oaDMAttr_setValue_doc},
    {"assign",(PyCFunction)oaDMAttr_tp_assign,METH_VARARGS,oaDMAttr_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMAttr_doc[] = 
"Class: oaDMAttr\n"
"  The oaDMAttr and oaDMAttrArray classes hold the definition of attribute, which is a name-value pair, used by DM systems.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDMAttr()\n"
"    Signature: oaDMAttr||\n"
"    This is the default constructor for the oaDMAttr class.\n"
"  Paramegers: (oaString,oaString)\n"
"    Calls: oaDMAttr(const oaString& nameIn,const oaString& value)\n"
"    Signature: oaDMAttr||cref-oaString,cref-oaString,\n"
"    This is a constructor for the oaDMAttr class.\n"
"    nameIn\n"
"    the name of this dmAttribute.\n"
"    value\n"
"    the value of this dmAttribute\n"
"  Paramegers: (oaDMAttr)\n"
"    Calls: (const oaDMAttr&)\n"
"    Signature: oaDMAttr||cref-oaDMAttr,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMAttr_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMAttr",
    sizeof(PyoaDMAttrObject),
    0,
    (destructor)oaDMAttr_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMAttr_tp_compare,	/* tp_compare */
    (reprfunc)oaDMAttr_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMAttr_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMAttr_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMAttr_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMAttr_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMAttr_Type)<0) {
      printf("** PyType_Ready failed for: oaDMAttr\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMAttr",
           (PyObject*)(&PyoaDMAttr_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMAttr\n");
       return -1;
    }
    return 0;
}


// ==================================================================
// Array for class: oaDMAttr
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMAttr_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaDMAttr_ArrayObject* self = (PyoaDMAttr_ArrayObject*)gself;
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
    /* Case: (oaDMAttr_Array) */
    {
        PyParamoaDMAttr_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMAttr_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDMAttr_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaDMAttr_Array)\n"
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
oaDMAttr_Array_dealloc(PyObject* gself)
{
    PyoaDMAttr_ArrayObject* self = (PyoaDMAttr_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_Array_str(PyObject *ob)
{
    PyParamoaDMAttr_Array value;
    int convert_status=PyoaDMAttr_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaDMAttr_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_Array_repr(PyObject *ob)
{
    PyParamoaDMAttr_Array value;
    int convert_status=PyoaDMAttr_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaDMAttr_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaDMAttr_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMAttr_Array p1;
    PyParamoaDMAttr_Array p2;
    int s1=PyoaDMAttr_Array_Convert(ob1,&p1);
    int s2=PyoaDMAttr_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaDMAttr_Array_CreateList(p1);
    PyObject* l2=PyoaDMAttr_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaDMAttr_Array_Convert(PyObject* ob,PyParamoaDMAttr_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaDMAttr_Array_Check(ob)) {
    PyoaDMAttr_ArrayObject* self = (PyoaDMAttr_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaDMAttr data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaDMAttr_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaDMAttr data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaDMAttr_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaDMAttr_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaDMAttr_Array_FromoaDMAttr_Array(const oaDMAttr_Array& value)
{
  PyObject* gself = PyoaDMAttr_Array_Type.tp_alloc(&PyoaDMAttr_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaDMAttr_ArrayObject* self = (PyoaDMAttr_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDMAttr_Array_FromoaDMAttr_Array(PyTypeoaDMAttr* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaDMAttr_Array_Type.tp_alloc(&PyoaDMAttr_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaDMAttr_ArrayObject* self = (PyoaDMAttr_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaDMAttr_Array_CreateList(PyParamoaDMAttr_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaDMAttr_FromoaDMAttr(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaDMAttr_Array_assign_doc[] = 
"Class: oaDMAttr_Array, Function: assign\n"
"  Paramegers: (oaDMAttr_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaDMAttr_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaDMAttr_ArrayObject* self=(PyoaDMAttr_ArrayObject*)ob;
  try {
    PyParamoaDMAttr_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMAttr_Array_Convert,&p1)) {
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
static char oaDMAttr_Array_list_doc[] = 
"Class: oaDMAttr_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaDMAttr_Array_list(PyObject* ob, PyObject *args)
{
  PyoaDMAttr_ArrayObject* self=(PyoaDMAttr_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaDMAttr_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaDMAttr_Array_methodlist[] = {
    {"assign",(PyCFunction)oaDMAttr_Array_assign,METH_VARARGS,oaDMAttr_Array_assign_doc},
    {"list",(PyCFunction)oaDMAttr_Array_list,METH_VARARGS,oaDMAttr_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaDMAttr_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaDMAttr_ArrayObject* self=(PyoaDMAttr_ArrayObject*)ob;
  try {
    PyParamoaDMAttr_Array data;
    int convert_status=PyoaDMAttr_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaDMAttr_FromoaDMAttr(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaDMAttr_Array_index_get_length(PyObject* ob)
{
    PyParamoaDMAttr_Array data;
    int convert_status=PyoaDMAttr_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaDMAttr_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaDMAttr_Array data;
    PyParamoaDMAttr dataitem;
    int convert_status=PyoaDMAttr_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaDMAttr_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaDMAttr_Array_doc[] =
"Class: oaDMAttr_Array\n"
"  The oaDMAttr_Array utility class provides an array of oaDMAttr.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDMAttr_Array()\n"
"    Signature: oaDMAttr_Array||\n"
"    This is the default constructor for the oaDMAttr_Array class. This constructor creates an empty oaDMAttr_Array.\n"
"  Paramegers: (oaDMAttr_Array)\n"
"    Calls: (const oaDMAttr_Array&)\n"
"    Signature: oaDMAttr_Array||cref-oaDMAttr_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaDMAttr_Array_as_sequence = {
    (Pyoa_inquiry)oaDMAttr_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaDMAttr_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaDMAttr_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaDMAttr_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMAttr_Array",
    sizeof(PyoaDMAttr_ArrayObject),
    0,
    oaDMAttr_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaDMAttr_Array_compare,    /* tp_compare */
    oaDMAttr_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaDMAttr_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaDMAttr_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMAttr_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaDMAttr_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaDMAttr_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaDMAttr_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMAttr_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaDMAttr_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaDMAttr_Array",
           (PyObject*)(&PyoaDMAttr_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMAttr_Array\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDMAttrArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMAttrArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMAttrArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMAttrArrayObject* self = (PyoaDMAttrArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaDMAttrArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaDMAttr*)  new oaDMAttrArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDMAttrArray)
    {
        PyParamoaDMAttrArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMAttrArray_Convert,&p1)) {
            self->value=(oaArrayBase_oaDMAttr*)  new oaDMAttrArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDMAttrArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaDMAttrArray)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMAttrArray_tp_dealloc(PyoaDMAttrArrayObject* self)
{
    if (!self->borrow) {
        delete (oaDMAttrArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMAttrArray_tp_repr(PyObject *ob)
{
    PyParamoaDMAttrArray value;
    int convert_status=PyoaDMAttrArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaDMAttrArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMAttrArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMAttrArray v1;
    PyParamoaDMAttrArray v2;
    int convert_status1=PyoaDMAttrArray_Convert(ob1,&v1);
    int convert_status2=PyoaDMAttrArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMAttrArray_Convert(PyObject* ob,PyParamoaDMAttrArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMAttrArray_Check(ob)) {
        result->SetData( (oaDMAttrArray*) ((PyoaDMAttrArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMAttrArray Failed");
    return 0;
}
int
PyoaDMAttrArray_ConvertAof(PyObject* ob,PyParamoaDMAttrArray* result)
{
    if (ob == NULL) return 1;
    if (ob==Py_None) {
        result->SetData(NULL);
        return 1;
    }
    if (PyoaDMAttrArray_Check(ob)) {
        result->SetData( (oaDMAttrArray*) ((PyoaDMAttrArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMAttrArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMAttrArray_FromoaDMAttrArray(oaDMAttrArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaDMAttrArray_Type.tp_alloc(&PyoaDMAttrArray_Type,0);
        if (bself == NULL) return bself;
        PyoaDMAttrArrayObject* self = (PyoaDMAttrArrayObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMAttrArray_doc[] = 
"Class: oaDMAttrArray\n"
"  The oaDMAttr and oaDMAttrArray classes hold the definition of attributes used by DM systems.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaDMAttrArray()\n"
"    Signature: oaDMAttrArray||simple-oaUInt4,\n"
"    This is the constructor for the oaDMAttrArray class.\n"
"    sizeIn\n"
"    the initial size of this attributes array.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaDMAttrArray(oaUInt4 sizeIn)\n"
"    Signature: oaDMAttrArray||simple-oaUInt4,\n"
"    This is the constructor for the oaDMAttrArray class.\n"
"    sizeIn\n"
"    the initial size of this attributes array.\n"
"  Paramegers: (oaDMAttrArray)\n"
"    Calls: (const oaDMAttrArray&)\n"
"    Signature: oaDMAttrArray||cref-oaDMAttrArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMAttrArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMAttrArray",
    sizeof(PyoaDMAttrArrayObject),
    0,
    (destructor)oaDMAttrArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMAttrArray_tp_compare,	/* tp_compare */
    (reprfunc)oaDMAttrArray_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMAttrArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaDMAttr_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMAttrArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMAttrArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMAttrArray_Type)<0) {
      printf("** PyType_Ready failed for: oaDMAttrArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMAttrArray",
           (PyObject*)(&PyoaDMAttrArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMAttrArray\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDMContainer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMContainer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMContainer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMContainerObject* self = (PyoaDMContainerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaDMContainer)
    {
        PyParamoaDMContainer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMContainer_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaDMContainer, Choices are:\n"
        "    (oaDMContainer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMContainer_tp_dealloc(PyoaDMContainerObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMContainer_tp_repr(PyObject *ob)
{
    PyParamoaDMContainer value;
    int convert_status=PyoaDMContainer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaDMContainer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMContainer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMContainer v1;
    PyParamoaDMContainer v2;
    int convert_status1=PyoaDMContainer_Convert(ob1,&v1);
    int convert_status2=PyoaDMContainer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMContainer_Convert(PyObject* ob,PyParamoaDMContainer* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMContainer_Check(ob)) {
        result->SetData( (oaDMContainer**) ((PyoaDMContainerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMContainer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMContainer_FromoaDMContainer(oaDMContainer** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaDMContainer* data=*value;
        if (data->getType()==oacCellViewType) return PyoaCellView_FromoaCellView((oaCellView**)value,borrow,lock);
        if (data->getType()==oacLibType) return PyoaLib_FromoaLib((oaLib**)value,borrow,lock);
        if (data->getType()==oacCellType) return PyoaCell_FromoaCell((oaCell**)value,borrow,lock);
        if (data->getType()==oacViewType) return PyoaView_FromoaView((oaView**)value,borrow,lock);
        PyObject* bself = PyoaDMContainer_Type.tp_alloc(&PyoaDMContainer_Type,0);
        if (bself == NULL) return bself;
        PyoaDMContainerObject* self = (PyoaDMContainerObject*)bself;
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
PyObject* PyoaDMContainer_FromoaDMContainer(oaDMContainer* data)
{
    if (data) {
        if (data->getType()==oacCellViewType) return PyoaCellView_FromoaCellView((oaCellView*)data);
        if (data->getType()==oacLibType) return PyoaLib_FromoaLib((oaLib*)data);
        if (data->getType()==oacCellType) return PyoaCell_FromoaCell((oaCell*)data);
        if (data->getType()==oacViewType) return PyoaView_FromoaView((oaView*)data);
       PyObject* bself = PyoaDMContainer_Type.tp_alloc(&PyoaDMContainer_Type,0);
       if (bself == NULL) return bself;
       PyoaDMContainerObject* self = (PyoaDMContainerObject*)bself;
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
static char oaDMContainer_getDMFiles_doc[] = 
"Class: oaDMContainer, Function: getDMFiles\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDMFile_oaDMContainer getDMFiles() const\n"
"    Signature: getDMFiles|simple-oaCollection_oaDMFile_oaDMContainer|\n"
"    BrowseData: 1\n"
"    This function constructs and returns a collection of files in the container.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacInvalidContainer\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMContainer_getDMFiles(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer data;
    int convert_status=PyoaDMContainer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMContainerObject* self=(PyoaDMContainerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDMFile_oaDMContainer* result= new oaCollection_oaDMFile_oaDMContainer(data.DataCall()->getDMFiles());
        return PyoaCollection_oaDMFile_oaDMContainer_FromoaCollection_oaDMFile_oaDMContainer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMContainer_getDMFilesIter_doc[] = 
"Class: oaDMContainer, Function: getDMFilesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDMFile getDMFilesIter() const\n"
"    Signature: getDMFilesIter|simple-oaIter_oaDMFile|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function constructs and returns a collection of files in the container.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacInvalidContainer\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMContainer_getDMFilesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer data;
    int convert_status=PyoaDMContainer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMContainerObject* self=(PyoaDMContainerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDMFile* result= new oaIter_oaDMFile(data.DataCall()->getDMFiles());
        return PyoaIter_oaDMFile_FromoaIter_oaDMFile(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMContainer_getVCStatus_doc[] = 
"Class: oaDMContainer, Function: getVCStatus\n"
"  Paramegers: (oaVCQueryDepth)\n"
"    Calls: oaDMObjectStatusRefIter getVCStatus(oaVCQueryDepth depth) const\n"
"    Signature: getVCStatus|simple-oaDMObjectStatusRefIter|simple-oaVCQueryDepth,simple-oaUInt4,\n"
"    This function is only active when a Version Control system is in place for the library this object is in. It gets the version control status of the children of this container. Use \"depth\" to control how far down the hierarchy to traverse.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings: oacFileVCQueryDepth: query only the immediate children files of this container oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\" oacViewVCQueryDepth: stop the query at the View level, not including \"view files\" oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    mask\n"
"    this parameter is used to limit the status bits being retrieved. Some types of status are more expensive to discover than others; use this mask to optimize performance\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaVCQueryDepth,oaUInt4)\n"
"    Calls: oaDMObjectStatusRefIter getVCStatus(oaVCQueryDepth depth,oaUInt4 mask) const\n"
"    Signature: getVCStatus|simple-oaDMObjectStatusRefIter|simple-oaVCQueryDepth,simple-oaUInt4,\n"
"    This function is only active when a Version Control system is in place for the library this object is in. It gets the version control status of the children of this container. Use \"depth\" to control how far down the hierarchy to traverse.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings: oacFileVCQueryDepth: query only the immediate children files of this container oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\" oacViewVCQueryDepth: stop the query at the View level, not including \"view files\" oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    mask\n"
"    this parameter is used to limit the status bits being retrieved. Some types of status are more expensive to discover than others; use this mask to optimize performance\n"
"    oacLibAccessDenied\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getVCStatus() const\n"
"    Signature: getVCStatus|simple-oaUInt4|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    oaDMObject::getVCStatus\n"
"    This function is only active when a Version Control system is in place for the library this object is in. It gets the version control status of the object. This status only relates to the given object and is not hierarchical.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    mask\n"
"    this parameter is used to limit the status bits being retrieved. Some types of status are more expensive to discover than others; use this mask to optimize performance\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaUInt4 getVCStatus(oaUInt4 mask) const\n"
"    Signature: getVCStatus|simple-oaUInt4|simple-oaUInt4,\n"
"    oaDMObject::getVCStatus\n"
"    This function is only active when a Version Control system is in place for the library this object is in. It gets the version control status of the object. This status only relates to the given object and is not hierarchical.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    mask\n"
"    this parameter is used to limit the status bits being retrieved. Some types of status are more expensive to discover than others; use this mask to optimize performance\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMContainer_getVCStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer data;
    int convert_status=PyoaDMContainer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMContainerObject* self=(PyoaDMContainerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVCQueryDepth)
    {
        PyParamoaVCQueryDepth p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVCQueryDepth_Convert,&p1)) {
            oaDMObjectStatusRefIter* result= new oaDMObjectStatusRefIter(data.DataCall()->getVCStatus(p1.Data()));
            return PyoaDMObjectStatusRefIter_FromoaDMObjectStatusRefIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaVCQueryDepth,oaUInt4)
    {
        PyParamoaVCQueryDepth p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVCQueryDepth_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            oaDMObjectStatusRefIter* result= new oaDMObjectStatusRefIter(data.DataCall()->getVCStatus(p1.Data(),p2.Data()));
            return PyoaDMObjectStatusRefIter_FromoaDMObjectStatusRefIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaUInt4 result= (data.DataCall()->getVCStatus());
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaUInt4 result= (data.DataCall()->getVCStatus(p1.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaDMContainer, function: getVCStatus, Choices are:\n"
        "    (oaVCQueryDepth)\n"
        "    (oaVCQueryDepth,oaUInt4)\n"
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
static char oaDMContainer_isNull_doc[] =
"Class: oaDMContainer, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaDMContainer_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaDMContainer data;
    int convert_status=PyoaDMContainer_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaDMContainer_assign_doc[] = 
"Class: oaDMContainer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMContainer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMContainer data;
  int convert_status=PyoaDMContainer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMContainer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMContainer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMContainer_methodlist[] = {
    {"getDMFiles",(PyCFunction)oaDMContainer_getDMFiles,METH_VARARGS,oaDMContainer_getDMFiles_doc},
    {"getDMFilesIter",(PyCFunction)oaDMContainer_getDMFilesIter,METH_VARARGS,oaDMContainer_getDMFilesIter_doc},
    {"getVCStatus",(PyCFunction)oaDMContainer_getVCStatus,METH_VARARGS,oaDMContainer_getVCStatus_doc},
    {"isNull",(PyCFunction)oaDMContainer_tp_isNull,METH_VARARGS,oaDMContainer_isNull_doc},
    {"assign",(PyCFunction)oaDMContainer_tp_assign,METH_VARARGS,oaDMContainer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMContainer_doc[] = 
"Class: oaDMContainer\n"
"  The oaDMContainer class is the base for all classes that are file containers.\n"
"Constructors:\n"
"  Paramegers: (oaDMContainer)\n"
"    Calls: (const oaDMContainer&)\n"
"    Signature: oaDMContainer||cref-oaDMContainer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMContainer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMContainer",
    sizeof(PyoaDMContainerObject),
    0,
    (destructor)oaDMContainer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMContainer_tp_compare,	/* tp_compare */
    (reprfunc)oaDMContainer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMContainer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMContainer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDMObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMContainer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMContainer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMContainer_Type)<0) {
      printf("** PyType_Ready failed for: oaDMContainer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMContainer",
           (PyObject*)(&PyoaDMContainer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMContainer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMDataObject* self = (PyoaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaDMData)
    {
        PyParamoaDMData p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMData_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaDMData, Choices are:\n"
        "    (oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMData_tp_dealloc(PyoaDMDataObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaDMData value;
    int convert_status=PyoaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMData v1;
    PyParamoaDMData v2;
    int convert_status1=PyoaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMData_Convert(PyObject* ob,PyParamoaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMData_Check(ob)) {
        result->SetData( (oaDMData**) ((PyoaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMData_FromoaDMData(oaDMData** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaDMData* data=*value;
        if (data->getType()==oacCellViewDMDataType) return PyoaCellViewDMData_FromoaCellViewDMData((oaCellViewDMData**)value,borrow,lock);
        if (data->getType()==oacLibDMDataType) return PyoaLibDMData_FromoaLibDMData((oaLibDMData**)value,borrow,lock);
        if (data->getType()==oacViewDMDataType) return PyoaViewDMData_FromoaViewDMData((oaViewDMData**)value,borrow,lock);
        if (data->getType()==oacCellDMDataType) return PyoaCellDMData_FromoaCellDMData((oaCellDMData**)value,borrow,lock);
        PyObject* bself = PyoaDMData_Type.tp_alloc(&PyoaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaDMDataObject* self = (PyoaDMDataObject*)bself;
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
PyObject* PyoaDMData_FromoaDMData(oaDMData* data)
{
    if (data) {
        if (data->getType()==oacCellViewDMDataType) return PyoaCellViewDMData_FromoaCellViewDMData((oaCellViewDMData*)data);
        if (data->getType()==oacLibDMDataType) return PyoaLibDMData_FromoaLibDMData((oaLibDMData*)data);
        if (data->getType()==oacViewDMDataType) return PyoaViewDMData_FromoaViewDMData((oaViewDMData*)data);
        if (data->getType()==oacCellDMDataType) return PyoaCellDMData_FromoaCellDMData((oaCellDMData*)data);
       PyObject* bself = PyoaDMData_Type.tp_alloc(&PyoaDMData_Type,0);
       if (bself == NULL) return bself;
       PyoaDMDataObject* self = (PyoaDMDataObject*)bself;
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
static char oaDMData_close_doc[] = 
"Class: oaDMData, Function: close\n"
"  Paramegers: ()\n"
"    Calls: void close()\n"
"    Signature: close|void-void|\n"
"    BrowseData: 0\n"
"    This function decrements the reference count of this DMData by one. If the count goes to zero, this database is purged from memory.\n"
"    oacCloseOnDMDataBeingPurged\n"
;

static PyObject*
oaDMData_close(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->close();
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
static char oaDMData_getAppDefsByDataType_doc[] = 
"Class: oaDMData, Function: getAppDefsByDataType\n"
"  Paramegers: (oaDMDataType)\n"
"    Calls: oaCollection_oaAppDef_oaDMData getAppDefsByDataType(oaDMDataType dataType) const\n"
"    Signature: getAppDefsByDataType|simple-oaCollection_oaAppDef_oaDMData|simple-oaDMDataType,\n"
"    This function returns a collection of oaAppDefs of the specified dataType set on oaDMObjects in this oaDMData database.\n"
"    dataType\n"
"    the data type to get\n"
;

static PyObject*
oaDMData_getAppDefsByDataType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMDataType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMDataType_Convert,&p1)) {
        oaCollection_oaAppDef_oaDMData* result= new oaCollection_oaAppDef_oaDMData(data.DataCall()->getAppDefsByDataType(p1.Data()));
        return PyoaCollection_oaAppDef_oaDMData_FromoaCollection_oaAppDef_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getAppDefsByDataTypeIter_doc[] = 
"Class: oaDMData, Function: getAppDefsByDataTypeIter\n"
"  Paramegers: (oaDMDataType)\n"
"    Calls: oaIter_oaAppDef getAppDefsByDataTypeIter(oaDMDataType dataType) const\n"
"    Signature: getAppDefsByDataTypeIter|simple-oaIter_oaAppDef|simple-oaDMDataType,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaAppDefs of the specified dataType set on oaDMObjects in this oaDMData database.\n"
"    dataType\n"
"    the data type to get\n"
;

static PyObject*
oaDMData_getAppDefsByDataTypeIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMDataType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMDataType_Convert,&p1)) {
        oaIter_oaAppDef* result= new oaIter_oaAppDef(data.DataCall()->getAppDefsByDataType(p1.Data()));
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
static char oaDMData_getAppObjectDefs_doc[] = 
"Class: oaDMData, Function: getAppObjectDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaAppObjectDef_oaDMData getAppObjectDefs() const\n"
"    Signature: getAppObjectDefs|simple-oaCollection_oaAppObjectDef_oaDMData|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaAppObjectDefs extension definitions set on oaAppObjects in this oaDMData database.\n"
;

static PyObject*
oaDMData_getAppObjectDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaAppObjectDef_oaDMData* result= new oaCollection_oaAppObjectDef_oaDMData(data.DataCall()->getAppObjectDefs());
        return PyoaCollection_oaAppObjectDef_oaDMData_FromoaCollection_oaAppObjectDef_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getAppObjectDefsIter_doc[] = 
"Class: oaDMData, Function: getAppObjectDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaAppObjectDef getAppObjectDefsIter() const\n"
"    Signature: getAppObjectDefsIter|simple-oaIter_oaAppObjectDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaAppObjectDefs extension definitions set on oaAppObjects in this oaDMData database.\n"
;

static PyObject*
oaDMData_getAppObjectDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaAppObjectDef* result= new oaIter_oaAppObjectDef(data.DataCall()->getAppObjectDefs());
        return PyoaIter_oaAppObjectDef_FromoaIter_oaAppObjectDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getAppObjects_doc[] = 
"Class: oaDMData, Function: getAppObjects\n"
"  Paramegers: (oaAppObjectDef)\n"
"    Calls: oaCollection_oaAppObject_oaDMData getAppObjects(const oaAppObjectDef* def) const\n"
"    Signature: getAppObjects|simple-oaCollection_oaAppObject_oaDMData|cptr-oaAppObjectDef,\n"
"    This function returns a collection of oaAppObjects with the specified def oaAppObjectDef extension definition set on them in this oaDMData database.\n"
"    def\n"
"    the extension type look for\n"
;

static PyObject*
oaDMData_getAppObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAppObjectDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAppObjectDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaCollection_oaAppObject_oaDMData* result= new oaCollection_oaAppObject_oaDMData(data.DataCall()->getAppObjects(p1.Data()));
        return PyoaCollection_oaAppObject_oaDMData_FromoaCollection_oaAppObject_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getAppObjectsIter_doc[] = 
"Class: oaDMData, Function: getAppObjectsIter\n"
"  Paramegers: (oaAppObjectDef)\n"
"    Calls: oaIter_oaAppObject getAppObjectsIter(const oaAppObjectDef* def) const\n"
"    Signature: getAppObjectsIter|simple-oaIter_oaAppObject|cptr-oaAppObjectDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaAppObjects with the specified def oaAppObjectDef extension definition set on them in this oaDMData database.\n"
"    def\n"
"    the extension type look for\n"
;

static PyObject*
oaDMData_getAppObjectsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAppObjectDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAppObjectDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaIter_oaAppObject* result= new oaIter_oaAppObject(data.DataCall()->getAppObjects(p1.Data()));
        return PyoaIter_oaAppObject_FromoaIter_oaAppObject(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getGroups_doc[] = 
"Class: oaDMData, Function: getGroups\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroup_oaDMData getGroups() const\n"
"    Signature: getGroups|simple-oaCollection_oaGroup_oaDMData|\n"
"    BrowseData: 1\n"
"    This function returns the collection of groups in or associated with this oaDMData database.\n"
;

static PyObject*
oaDMData_getGroups(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroup_oaDMData* result= new oaCollection_oaGroup_oaDMData(data.DataCall()->getGroups());
        return PyoaCollection_oaGroup_oaDMData_FromoaCollection_oaGroup_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getGroupsByName_doc[] = 
"Class: oaDMData, Function: getGroupsByName\n"
"  Paramegers: (oaString)\n"
"    Calls: oaCollection_oaGroup_oaDMData getGroupsByName(const oaString& name) const\n"
"    Signature: getGroupsByName|simple-oaCollection_oaGroup_oaDMData|cref-oaString,\n"
"    This function returns a collection of groups in or associated with this oaDMData database with the specified name .\n"
"    name\n"
"    the name of the groups to get\n"
;

static PyObject*
oaDMData_getGroupsByName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaCollection_oaGroup_oaDMData* result= new oaCollection_oaGroup_oaDMData(data.DataCall()->getGroupsByName(p1.Data()));
        return PyoaCollection_oaGroup_oaDMData_FromoaCollection_oaGroup_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getGroupsByNameIter_doc[] = 
"Class: oaDMData, Function: getGroupsByNameIter\n"
"  Paramegers: (oaString)\n"
"    Calls: oaIter_oaGroup getGroupsByNameIter(const oaString& name) const\n"
"    Signature: getGroupsByNameIter|simple-oaIter_oaGroup|cref-oaString,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of groups in or associated with this oaDMData database with the specified name .\n"
"    name\n"
"    the name of the groups to get\n"
;

static PyObject*
oaDMData_getGroupsByNameIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaIter_oaGroup* result= new oaIter_oaGroup(data.DataCall()->getGroupsByName(p1.Data()));
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
static char oaDMData_getGroupsIter_doc[] = 
"Class: oaDMData, Function: getGroupsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroup getGroupsIter() const\n"
"    Signature: getGroupsIter|simple-oaIter_oaGroup|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of groups in or associated with this oaDMData database.\n"
;

static PyObject*
oaDMData_getGroupsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaGroup* result= new oaIter_oaGroup(data.DataCall()->getGroups());
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
static char oaDMData_getLib_doc[] = 
"Class: oaDMData, Function: getLib\n"
"  Paramegers: ()\n"
"    Calls: oaLib* getLib() const\n"
"    Signature: getLib|ptr-oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the lib object that this dmData database is in.\n"
;

static PyObject*
oaDMData_getLib(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLibp result= (data.DataCall()->getLib());
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
static char oaDMData_getLibName_doc[] = 
"Class: oaDMData, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    These functions returns the library name for this DMData object.\n"
"    libName\n"
"    the returned library name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name for this DMData object in the specified ns namespace.\n"
"    ns\n"
"    input parameter - the namespace to use for the returned library name\n"
"    libName\n"
"    the returned library name\n"
;

static PyObject*
oaDMData_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getLibName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->getLibName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaDMData, function: getLibName, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaNameSpace,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getMode_doc[] = 
"Class: oaDMData, Function: getMode\n"
"  Paramegers: ()\n"
"    Calls: oaChar getMode() const\n"
"    Signature: getMode|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the mode ('r'ead-only, 'w'rite, or 'a'ppend) with which this DMData database is currently opened.\n"
;

static PyObject*
oaDMData_getMode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaChar result= (data.DataCall()->getMode());
        return PyoaChar_FromoaChar(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_getRefCount_doc[] = 
"Class: oaDMData, Function: getRefCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRefCount() const\n"
"    Signature: getRefCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of times this DMData has been opened without being closed.\n"
;

static PyObject*
oaDMData_getRefCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getRefCount());
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
static char oaDMData_getTimeStamp_doc[] = 
"Class: oaDMData, Function: getTimeStamp\n"
"  Paramegers: (oaDMDataType)\n"
"    Calls: oaTimeStamp getTimeStamp(oaDMDataType type) const\n"
"    Signature: getTimeStamp|simple-oaTimeStamp|simple-oaDMDataType,\n"
"    This function returns the timeStamp value for the specified DM data dataType.\n"
"    type\n"
"    an oaDMDataType value\n"
"    oacInvalidDMDataTypeForTimeStamp\n"
;

static PyObject*
oaDMData_getTimeStamp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMDataType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMDataType_Convert,&p1)) {
        oaTimeStamp* result= new oaTimeStamp(data.DataCall()->getTimeStamp(p1.Data()));
        return PyoaTimeStamp_FromoaTimeStamp(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_isModified_doc[] = 
"Class: oaDMData, Function: isModified\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isModified() const\n"
"    Signature: isModified|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this oaDMData database has been modified but not saved.\n"
;

static PyObject*
oaDMData_isModified(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isModified());
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
static char oaDMData_purge_doc[] = 
"Class: oaDMData, Function: purge\n"
"  Paramegers: ()\n"
"    Calls: void purge()\n"
"    Signature: purge|void-void|\n"
"    BrowseData: 0\n"
"    This function closes and removes this DMData from memory, regardless of its reference count. Applications sometimes inadvertently attempt to recursively purge databases, so set an exception is thrown to catch this.\n"
"    oacPurgeOnDMDataBeingPurged\n"
;

static PyObject*
oaDMData_purge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->purge();
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
static char oaDMData_reopen_doc[] = 
"Class: oaDMData, Function: reopen\n"
"  Paramegers: (oaChar)\n"
"    Calls: void reopen(oaChar mode)\n"
"    Signature: reopen|void-void|simple-oaChar,\n"
"    This function attempts to reopen this oaDMData using the specified access mode . The contents of the DMData may be reset or even truncated depending on the new access mode.\n"
"    Note that the oaDMData's refCount is not affected.\n"
"    mode\n"
"    mode in which to reopen this DMData database: 'r'ead-only, 'w'rite (truncate) or 'a'ppend.\n"
"    oacOpenUndefinedModeDMData\n"
"    oacOpenOnDMDataBeingPurged\n"
"    oacCannotLockDMData\n"
;

static PyObject*
oaDMData_reopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaChar p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaChar_Convert,&p1)) {
        data.DataCall()->reopen(p1.Data());
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
static char oaDMData_revert_doc[] = 
"Class: oaDMData, Function: revert\n"
"  Paramegers: ()\n"
"    Calls: void revert()\n"
"    Signature: revert|void-void|\n"
"    BrowseData: 0\n"
"    This function reloads the contents of this oaDMData from disk. If the oaDMData is opened in write mode, it will be truncated.\n"
"    Note that the oaDMData's access mode is not affected.\n"
;

static PyObject*
oaDMData_revert(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->revert();
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
static char oaDMData_save_doc[] = 
"Class: oaDMData, Function: save\n"
"  Paramegers: ()\n"
"    Calls: void save()\n"
"    Signature: save|void-void|\n"
"    BrowseData: 0\n"
"    This function attempts to save this oaDMdata database.\n"
"    oacSaveReadOnlyDMData\n"
;

static PyObject*
oaDMData_save(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataObject* self=(PyoaDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->save();
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
static char oaDMData_isNull_doc[] =
"Class: oaDMData, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaDMData_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaDMData data;
    int convert_status=PyoaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaDMData_assign_doc[] = 
"Class: oaDMData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMData data;
  int convert_status=PyoaDMData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMData_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMData_methodlist[] = {
    {"close",(PyCFunction)oaDMData_close,METH_VARARGS,oaDMData_close_doc},
    {"getAppDefsByDataType",(PyCFunction)oaDMData_getAppDefsByDataType,METH_VARARGS,oaDMData_getAppDefsByDataType_doc},
    {"getAppDefsByDataTypeIter",(PyCFunction)oaDMData_getAppDefsByDataTypeIter,METH_VARARGS,oaDMData_getAppDefsByDataTypeIter_doc},
    {"getAppObjectDefs",(PyCFunction)oaDMData_getAppObjectDefs,METH_VARARGS,oaDMData_getAppObjectDefs_doc},
    {"getAppObjectDefsIter",(PyCFunction)oaDMData_getAppObjectDefsIter,METH_VARARGS,oaDMData_getAppObjectDefsIter_doc},
    {"getAppObjects",(PyCFunction)oaDMData_getAppObjects,METH_VARARGS,oaDMData_getAppObjects_doc},
    {"getAppObjectsIter",(PyCFunction)oaDMData_getAppObjectsIter,METH_VARARGS,oaDMData_getAppObjectsIter_doc},
    {"getGroups",(PyCFunction)oaDMData_getGroups,METH_VARARGS,oaDMData_getGroups_doc},
    {"getGroupsByName",(PyCFunction)oaDMData_getGroupsByName,METH_VARARGS,oaDMData_getGroupsByName_doc},
    {"getGroupsByNameIter",(PyCFunction)oaDMData_getGroupsByNameIter,METH_VARARGS,oaDMData_getGroupsByNameIter_doc},
    {"getGroupsIter",(PyCFunction)oaDMData_getGroupsIter,METH_VARARGS,oaDMData_getGroupsIter_doc},
    {"getLib",(PyCFunction)oaDMData_getLib,METH_VARARGS,oaDMData_getLib_doc},
    {"getLibName",(PyCFunction)oaDMData_getLibName,METH_VARARGS,oaDMData_getLibName_doc},
    {"getMode",(PyCFunction)oaDMData_getMode,METH_VARARGS,oaDMData_getMode_doc},
    {"getRefCount",(PyCFunction)oaDMData_getRefCount,METH_VARARGS,oaDMData_getRefCount_doc},
    {"getTimeStamp",(PyCFunction)oaDMData_getTimeStamp,METH_VARARGS,oaDMData_getTimeStamp_doc},
    {"isModified",(PyCFunction)oaDMData_isModified,METH_VARARGS,oaDMData_isModified_doc},
    {"purge",(PyCFunction)oaDMData_purge,METH_VARARGS,oaDMData_purge_doc},
    {"reopen",(PyCFunction)oaDMData_reopen,METH_VARARGS,oaDMData_reopen_doc},
    {"revert",(PyCFunction)oaDMData_revert,METH_VARARGS,oaDMData_revert_doc},
    {"save",(PyCFunction)oaDMData_save,METH_VARARGS,oaDMData_save_doc},
    {"isNull",(PyCFunction)oaDMData_tp_isNull,METH_VARARGS,oaDMData_isNull_doc},
    {"assign",(PyCFunction)oaDMData_tp_assign,METH_VARARGS,oaDMData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMData_doc[] = 
"Class: oaDMData\n"
"  oaDMData objects represent database objects that can be associated with a DM library, cell, view or cellView and can be used to persistently store properties ( oaProp objects), groups ( oaGroup objects), group members ( oaGroupMember objects) and application objects (see oaAppObject ).\n"
"  The oaDMData class provides the behavior that is common to oaLibDMData , oaCellDMData , oaViewDMData and oaCellViewDMData .\n"
"Constructors:\n"
"  Paramegers: (oaDMData)\n"
"    Calls: (const oaDMData&)\n"
"    Signature: oaDMData||cref-oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMData",
    sizeof(PyoaDMDataObject),
    0,
    (destructor)oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMData_static_destroy_doc[] = 
"Class: oaDMData, Function: destroy\n"
"  Paramegers: (oaDMContainer)\n"
"    Calls: void destroy(const oaDMContainer* container)\n"
"    Signature: destroy|void-void|cptr-oaDMContainer,\n"
"    This function attempts to remove this oaDMData database from disk. It throws an exception if the DMData is currently open or if the DMData cannot be found on disk.\n"
"    dmObj\n"
"    pointer to the container for (owner of) the oaDMData database\n"
"    oacInvalidContainer\n"
"    oacDestroyDMDataOpen\n"
"    oacDestroyDMDataDoesNotExist\n"
"    oacDMDataHasReadNeedWriteAccess\n"
"    oacDMDataCannotGetWriteAccess\n"
;

static PyObject*
oaDMData_static_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMContainer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaDMData::destroy(p1.Data());
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
static char oaDMData_static_exists_doc[] = 
"Class: oaDMData, Function: exists\n"
"  Paramegers: (oaDMContainer)\n"
"    Calls: oaBoolean exists(const oaDMContainer* container)\n"
"    Signature: exists|simple-oaBoolean|cptr-oaDMContainer,\n"
"    This function checks whether there is a DMData open that has the specified dmObj container (owner) or whether a DMData file exists on disk with a non-zero size. This function returns if either condition is true; otherwise, it returns false.\n"
"    dmObj\n"
"    pointer to the container for (owner of) the oaDMData database\n"
"    oacInvalidContainer\n"
;

static PyObject*
oaDMData_static_exists(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMContainer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaDMData::exists(p1.Data()));
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
static char oaDMData_static_find_doc[] = 
"Class: oaDMData, Function: find\n"
"  Paramegers: (oaDMContainer)\n"
"    Calls: oaDMData* find(const oaDMContainer* container)\n"
"    Signature: find|ptr-oaDMData|cptr-oaDMContainer,\n"
"    This function attempts to find an open DM data with the specified dmObj container (owner). If successful, a pointer to the DMData database is returned. If unsuccessful, NULL is returned.\n"
"    dmObj\n"
"    pointer to the container for (owner of) the oaDMData database\n"
"    oacInvalidContainer\n"
"    oacDMDataCannotGetReadAccess\n"
;

static PyObject*
oaDMData_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMContainer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaDMDatap result= (oaDMData::find(p1.Data()));
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
static char oaDMData_static_getOpenDMDataObjs_doc[] = 
"Class: oaDMData, Function: getOpenDMDataObjs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDMData_oaDMData getOpenDMDataObjs()\n"
"    Signature: getOpenDMDataObjs|simple-oaCollection_oaDMData_oaDMData|\n"
"    BrowseData: 1\n"
"    This function returns a collection of open DM data databases.\n"
;

static PyObject*
oaDMData_static_getOpenDMDataObjs(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDMData_oaDMData* result= new oaCollection_oaDMData_oaDMData(oaDMData::getOpenDMDataObjs());
        return PyoaCollection_oaDMData_oaDMData_FromoaCollection_oaDMData_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_static_getOpenDMDataObjsIter_doc[] = 
"Class: oaDMData, Function: getOpenDMDataObjsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDMData getOpenDMDataObjsIter()\n"
"    Signature: getOpenDMDataObjsIter|simple-oaIter_oaDMData|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of open DM data databases.\n"
;

static PyObject*
oaDMData_static_getOpenDMDataObjsIter(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDMData* result= new oaIter_oaDMData(oaDMData::getOpenDMDataObjs());
        return PyoaIter_oaDMData_FromoaIter_oaDMData(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMData_static_getRevNumber_doc[] = 
"Class: oaDMData, Function: getRevNumber\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRevNumber()\n"
"    Signature: getRevNumber|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the revision number for this DMData database.\n"
;

static PyObject*
oaDMData_static_getRevNumber(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (oaDMData::getRevNumber());
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
static char oaDMData_static_open_doc[] = 
"Class: oaDMData, Function: open\n"
"  Paramegers: (oaDMContainer,oaChar)\n"
"    Calls: oaDMData* open(const oaDMContainer* container,oaChar mode)\n"
"    Signature: open|ptr-oaDMData|cptr-oaDMContainer,simple-oaChar,\n"
"    This function attempts to open a DM data database with the specified dmObj (container) owner in the given mode. If successful, a pointer to the DM Data is returned.\n"
"    dmObj\n"
"    pointer to the container for (owner of) the oaDMData object\n"
"    mode\n"
"    mode to open this oaDMData object: 'r'ead-only, 'w'rite (truncate) or 'a'ppend\n"
"    oacOpenUndefinedModeDMData\n"
"    oacInvalidContainer\n"
"    oacOpenOnDMDataBeingPurged\n"
"    oacDMDataDoesNotExist\n"
"    oacCannotLockDMData\n"
"    oacDMDataCannotGetReadAccess\n"
"    oacDMDataHasReadNeedWriteAccess\n"
"    oacDMDataCannotGetWriteAccess\n"
;

static PyObject*
oaDMData_static_open(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMContainer_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaDMDatap result= (oaDMData::open(p1.Data(),p2.Data()));
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
static PyMethodDef oaDMData_staticmethodlist[] = {
    {"static_destroy",(PyCFunction)oaDMData_static_destroy,METH_VARARGS,oaDMData_static_destroy_doc},
    {"static_exists",(PyCFunction)oaDMData_static_exists,METH_VARARGS,oaDMData_static_exists_doc},
    {"static_find",(PyCFunction)oaDMData_static_find,METH_VARARGS,oaDMData_static_find_doc},
    {"static_getOpenDMDataObjs",(PyCFunction)oaDMData_static_getOpenDMDataObjs,METH_VARARGS,oaDMData_static_getOpenDMDataObjs_doc},
    {"static_getOpenDMDataObjsIter",(PyCFunction)oaDMData_static_getOpenDMDataObjsIter,METH_VARARGS,oaDMData_static_getOpenDMDataObjsIter_doc},
    {"static_getRevNumber",(PyCFunction)oaDMData_static_getRevNumber,METH_VARARGS,oaDMData_static_getRevNumber_doc},
    {"static_open",(PyCFunction)oaDMData_static_open,METH_VARARGS,oaDMData_static_open_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMData",
           (PyObject*)(&PyoaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMData\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaDMData_Type.tp_dict;
    for(method=oaDMData_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaDMDataType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMDataType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMDataType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMDataTypeObject* self = (PyoaDMDataTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaDMDataTypeEnum)
    {
        PyParamoaDMDataTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDMDataTypeEnum_Convert,&p1)) {
            self->value =  new oaDMDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaDMDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDMDataType)
    {
        PyParamoaDMDataType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMDataType_Convert,&p1)) {
            self->value= new oaDMDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDMDataType, Choices are:\n"
        "    (oaDMDataTypeEnum)\n"
        "    (oaString)\n"
        "    (oaDMDataType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMDataType_tp_dealloc(PyoaDMDataTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMDataType_tp_repr(PyObject *ob)
{
    PyParamoaDMDataType value;
    int convert_status=PyoaDMDataType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[34];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaDMDataType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMDataType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMDataType v1;
    PyParamoaDMDataType v2;
    int convert_status1=PyoaDMDataType_Convert(ob1,&v1);
    int convert_status2=PyoaDMDataType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMDataType_Convert(PyObject* ob,PyParamoaDMDataType* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMDataType_Check(ob)) {
        result->SetData(  ((PyoaDMDataTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMDataType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMDataType_FromoaDMDataType(oaDMDataType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaDMDataType_Type.tp_alloc(&PyoaDMDataType_Type,0);
        if (bself == NULL) return bself;
        PyoaDMDataTypeObject* self = (PyoaDMDataTypeObject*)bself;
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
static char oaDMDataType_getName_doc[] = 
"Class: oaDMDataType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the oaDMDataTypeEnum value encapsulated by this oaDMDataType object.\n"
;

static PyObject*
oaDMDataType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMDataType data;
    int convert_status=PyoaDMDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataTypeObject* self=(PyoaDMDataTypeObject*)ob;

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
static char oaDMDataType_oaDMDataTypeEnum_doc[] = 
"Class: oaDMDataType, Function: oaDMDataTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaDMDataTypeEnum oaDMDataTypeEnum() const\n"
"    Signature: operator oaDMDataTypeEnum|simple-oaDMDataTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaDMDataType object into its corresponding oaDMDataTypeEnum value.\n"
;

static PyObject*
oaDMDataType_oaDMDataTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMDataType data;
    int convert_status=PyoaDMDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMDataTypeObject* self=(PyoaDMDataTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMDataTypeEnum result= (data.DataCall()->operator oaDMDataTypeEnum());
        return PyoaDMDataTypeEnum_FromoaDMDataTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaDMDataType_assign_doc[] = 
"Class: oaDMDataType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMDataType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMDataType data;
  int convert_status=PyoaDMDataType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMDataType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMDataType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMDataType_methodlist[] = {
    {"getName",(PyCFunction)oaDMDataType_getName,METH_VARARGS,oaDMDataType_getName_doc},
    {"oaDMDataTypeEnum",(PyCFunction)oaDMDataType_oaDMDataTypeEnum,METH_VARARGS,oaDMDataType_oaDMDataTypeEnum_doc},
    {"assign",(PyCFunction)oaDMDataType_tp_assign,METH_VARARGS,oaDMDataType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMDataType_doc[] = 
"Class: oaDMDataType\n"
"  oaDMDataTypeEnum\n"
"  The oaDMDataType class is an enum wrapper class for oaDMDataTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaDMDataTypeEnum)\n"
"    Calls: oaDMDataType(oaDMDataTypeEnum valueIn)\n"
"    Signature: oaDMDataType||simple-oaDMDataTypeEnum,\n"
"    This constructor for the oaDMDataType class takes an oaDMDataTypeEnum value.\n"
"    valueIn\n"
"    an oaDMDataTypeEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaDMDataType(const oaString& name)\n"
"    Signature: oaDMDataType||cref-oaString,\n"
"    This constructor for the oaDMDataType class takes the name of an oaDMDataTypeEnum value.\n"
"    name\n"
"    the name of an oaDMDataTypeEnum value\n"
"  Paramegers: (oaDMDataType)\n"
"    Calls: (const oaDMDataType&)\n"
"    Signature: oaDMDataType||cref-oaDMDataType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMDataType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMDataType",
    sizeof(PyoaDMDataTypeObject),
    0,
    (destructor)oaDMDataType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMDataType_tp_compare,	/* tp_compare */
    (reprfunc)oaDMDataType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMDataType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMDataType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMDataType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMDataType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMDataType_Type)<0) {
      printf("** PyType_Ready failed for: oaDMDataType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMDataType",
           (PyObject*)(&PyoaDMDataType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMDataType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDMDataTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaDMDataTypeEnum_Convert(PyObject* ob,PyParamoaDMDataTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDMDataDataType")==0) { result->SetData(oacDMDataDataType); return 1;}
        if (strcasecmp(str,"oacDMAppObjectDataType")==0) { result->SetData(oacDMAppObjectDataType); return 1;}
        if (strcasecmp(str,"oacDMPropDataType")==0) { result->SetData(oacDMPropDataType); return 1;}
        if (strcasecmp(str,"oacDMGroupDataType")==0) { result->SetData(oacDMGroupDataType); return 1;}
        if (strcasecmp(str,"oacDMGroupMemDataType")==0) { result->SetData(oacDMGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacDMAvatarDataType")==0) { result->SetData(oacDMAvatarDataType); return 1;}
        if (strcasecmp(str,"oacDMValueDataType")==0) { result->SetData(oacDMValueDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintParamDefDataType")==0) { result->SetData(oacDMConstraintParamDefDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintParamDataType")==0) { result->SetData(oacDMConstraintParamDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintDefDataType")==0) { result->SetData(oacDMConstraintDefDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintDataType")==0) { result->SetData(oacDMConstraintDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintGroupDataType")==0) { result->SetData(oacDMConstraintGroupDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintGroupMemDataType")==0) { result->SetData(oacDMConstraintGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacDMConstraintGroupHeaderDataType")==0) { result->SetData(oacDMConstraintGroupHeaderDataType); return 1;}
        if (strcasecmp(str,"oacDMFeatureDataType")==0) { result->SetData(oacDMFeatureDataType); return 1;}
        if (strcasecmp(str,"oacDMFeaturePolicyDataType")==0) { result->SetData(oacDMFeaturePolicyDataType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaDMDataTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMDataTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaDMDataTypeEnum_FromoaDMDataTypeEnum(oaDMDataTypeEnum ob)
{
    if (ob==oacDMDataDataType) return PyString_FromString("oacDMDataDataType");
    if (ob==oacDMAppObjectDataType) return PyString_FromString("oacDMAppObjectDataType");
    if (ob==oacDMPropDataType) return PyString_FromString("oacDMPropDataType");
    if (ob==oacDMGroupDataType) return PyString_FromString("oacDMGroupDataType");
    if (ob==oacDMGroupMemDataType) return PyString_FromString("oacDMGroupMemDataType");
    if (ob==oacDMAvatarDataType) return PyString_FromString("oacDMAvatarDataType");
    if (ob==oacDMValueDataType) return PyString_FromString("oacDMValueDataType");
    if (ob==oacDMConstraintParamDefDataType) return PyString_FromString("oacDMConstraintParamDefDataType");
    if (ob==oacDMConstraintParamDataType) return PyString_FromString("oacDMConstraintParamDataType");
    if (ob==oacDMConstraintDefDataType) return PyString_FromString("oacDMConstraintDefDataType");
    if (ob==oacDMConstraintDataType) return PyString_FromString("oacDMConstraintDataType");
    if (ob==oacDMConstraintGroupDataType) return PyString_FromString("oacDMConstraintGroupDataType");
    if (ob==oacDMConstraintGroupMemDataType) return PyString_FromString("oacDMConstraintGroupMemDataType");
    if (ob==oacDMConstraintGroupHeaderDataType) return PyString_FromString("oacDMConstraintGroupHeaderDataType");
    if (ob==oacDMFeatureDataType) return PyString_FromString("oacDMFeatureDataType");
    if (ob==oacDMFeaturePolicyDataType) return PyString_FromString("oacDMFeaturePolicyDataType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaDMDataTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaDMDataTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaDMDataTypeEnum_FromoaDMDataTypeEnum(oaDMDataTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaDMDataTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaDMDataTypeEnum_doc[] =
"Type convert function for enum: oaDMDataTypeEnum";
                               
static PyMethodDef PyoaDMDataTypeEnum_method =
  {"oaDMDataTypeEnum",(PyCFunction)PyoaDMDataTypeEnum_TypeFunction,METH_VARARGS,oaDMDataTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaDMDataTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDMDataDataType");
    PyDict_SetItemString(mod_dict,"oacDMDataDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMAppObjectDataType");
    PyDict_SetItemString(mod_dict,"oacDMAppObjectDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMPropDataType");
    PyDict_SetItemString(mod_dict,"oacDMPropDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMGroupDataType");
    PyDict_SetItemString(mod_dict,"oacDMGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacDMGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMAvatarDataType");
    PyDict_SetItemString(mod_dict,"oacDMAvatarDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMValueDataType");
    PyDict_SetItemString(mod_dict,"oacDMValueDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintParamDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintParamDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintDefDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintGroupDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMConstraintGroupHeaderDataType");
    PyDict_SetItemString(mod_dict,"oacDMConstraintGroupHeaderDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMFeatureDataType");
    PyDict_SetItemString(mod_dict,"oacDMFeatureDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMFeaturePolicyDataType");
    PyDict_SetItemString(mod_dict,"oacDMFeaturePolicyDataType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaDMDataTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaDMDataTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaDMDataTypeEnum\n");
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
// Wrapper Implementation for Class: oaDMFile
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMFile_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMFile_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMFileObject* self = (PyoaDMFileObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaDMFile)
    {
        PyParamoaDMFile p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMFile_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaDMFile, Choices are:\n"
        "    (oaDMFile)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMFile_tp_dealloc(PyoaDMFileObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMFile_tp_repr(PyObject *ob)
{
    PyParamoaDMFile value;
    int convert_status=PyoaDMFile_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaDMFile::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[30];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaDMFile::");
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
oaDMFile_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMFile v1;
    PyParamoaDMFile v2;
    int convert_status1=PyoaDMFile_Convert(ob1,&v1);
    int convert_status2=PyoaDMFile_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMFile_Convert(PyObject* ob,PyParamoaDMFile* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMFile_Check(ob)) {
        result->SetData( (oaDMFile**) ((PyoaDMFileObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMFile Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMFile_FromoaDMFile(oaDMFile** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaDMFile* data=*value;
        PyObject* bself = PyoaDMFile_Type.tp_alloc(&PyoaDMFile_Type,0);
        if (bself == NULL) return bself;
        PyoaDMFileObject* self = (PyoaDMFileObject*)bself;
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
PyObject* PyoaDMFile_FromoaDMFile(oaDMFile* data)
{
    if (data) {
       PyObject* bself = PyoaDMFile_Type.tp_alloc(&PyoaDMFile_Type,0);
       if (bself == NULL) return bself;
       PyoaDMFileObject* self = (PyoaDMFileObject*)bself;
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
static char oaDMFile_destroy_doc[] = 
"Class: oaDMFile, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this oaDMFile.\n"
"    This function requires write access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if write access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
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
static char oaDMFile_existsOnDisk_doc[] = 
"Class: oaDMFile, Function: existsOnDisk\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean existsOnDisk() const\n"
"    Signature: existsOnDisk|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this file exists on disk.\n"
;

static PyObject*
oaDMFile_existsOnDisk(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->existsOnDisk());
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
static char oaDMFile_getFollowers_doc[] = 
"Class: oaDMFile, Function: getFollowers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDMFile_oaDMFile getFollowers() const\n"
"    Signature: getFollowers|simple-oaCollection_oaDMFile_oaDMFile|\n"
"    BrowseData: 1\n"
"    This function is to get a collection of all of the followers of a file. If this file does not have followers, the collection will be empty.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_getFollowers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDMFile_oaDMFile* result= new oaCollection_oaDMFile_oaDMFile(data.DataCall()->getFollowers());
        return PyoaCollection_oaDMFile_oaDMFile_FromoaCollection_oaDMFile_oaDMFile(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_getFollowersIter_doc[] = 
"Class: oaDMFile, Function: getFollowersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDMFile getFollowersIter() const\n"
"    Signature: getFollowersIter|simple-oaIter_oaDMFile|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function is to get a collection of all of the followers of a file. If this file does not have followers, the collection will be empty.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_getFollowersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDMFile* result= new oaIter_oaDMFile(data.DataCall()->getFollowers());
        return PyoaIter_oaDMFile_FromoaIter_oaDMFile(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_getLeader_doc[] = 
"Class: oaDMFile, Function: getLeader\n"
"  Paramegers: ()\n"
"    Calls: oaDMFile* getLeader() const\n"
"    Signature: getLeader|ptr-oaDMFile|\n"
"    BrowseData: 1\n"
"    This function returns the leader of this oaDMFile. If this file is not a follower, NULL will be returned.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_getLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDMFilep result= (data.DataCall()->getLeader());
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
static char oaDMFile_getLock_doc[] = 
"Class: oaDMFile, Function: getLock\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean getLock()\n"
"    Signature: getLock|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaDMFile::getLock\n"
"    This function is used to get a write lock on the specified file. If the lock is successfully obtained, true is returned; otherwise, false is returned.\n"
"    Note: When a file is locked by the current or any other process and a lock is requested, the lock request is denied (this function returns false).\n"
;

static PyObject*
oaDMFile_getLock(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->getLock());
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
static char oaDMFile_getLockStatus_doc[] = 
"Class: oaDMFile, Function: getLockStatus\n"
"  Paramegers: ()\n"
"    Calls: oaDMLockStatus getLockStatus() const\n"
"    Signature: getLockStatus|simple-oaDMLockStatus|\n"
"    BrowseData: 1\n"
"    This function returns the lock status of this file.\n"
;

static PyObject*
oaDMFile_getLockStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDMLockStatus* result= new oaDMLockStatus(data.DataCall()->getLockStatus());
        return PyoaDMLockStatus_FromoaDMLockStatus(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_getName_doc[] = 
"Class: oaDMFile, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this oaDMFile in the user-supplied name parameter.\n"
;

static PyObject*
oaDMFile_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
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
static char oaDMFile_getOnDiskSize_doc[] = 
"Class: oaDMFile, Function: getOnDiskSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 getOnDiskSize() const\n"
"    Signature: getOnDiskSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function returns on disk size of the DM file. If the file does not exist on disk, an error is thrown.\n"
"    oacDMFileDoesNotExistOnDisk\n"
;

static PyObject*
oaDMFile_getOnDiskSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->getOnDiskSize());
        return PyoaUInt8_FromoaUInt8(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_getParent_doc[] = 
"Class: oaDMFile, Function: getParent\n"
"  Paramegers: ()\n"
"    Calls: oaDMContainer* getParent() const\n"
"    Signature: getParent|ptr-oaDMContainer|\n"
"    BrowseData: 1\n"
"    This function returns the parent of this oaDMFile.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_getParent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDMContainerp result= (data.DataCall()->getParent());
        return PyoaDMContainer_FromoaDMContainer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_getPath_doc[] = 
"Class: oaDMFile, Function: getPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getPath(oaString& path) const\n"
"    Signature: getPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the path of this oaDMFile.\n"
;

static PyObject*
oaDMFile_getPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getPath(p1.Data());
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
static char oaDMFile_getVersion_doc[] = 
"Class: oaDMFile, Function: getVersion\n"
"  Paramegers: ()\n"
"    Calls: oaVCVersion getVersion() const\n"
"    Signature: getVersion|simple-oaVCVersion|\n"
"    BrowseData: 1\n"
"    oaDMFile::getVersion\n"
"    This function returns the current version of this file.\n"
;

static PyObject*
oaDMFile_getVersion(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaVCVersion* result= new oaVCVersion(data.DataCall()->getVersion());
        return PyoaVCVersion_FromoaVCVersion(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_isLeader_doc[] = 
"Class: oaDMFile, Function: isLeader\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isLeader() const\n"
"    Signature: isLeader|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this file is a leader file, with other files as its followers.\n"
;

static PyObject*
oaDMFile_isLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isLeader());
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
static char oaDMFile_isPrimary_doc[] = 
"Class: oaDMFile, Function: isPrimary\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isPrimary() const\n"
"    Signature: isPrimary|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this file is a primary file for a cellView.\n"
;

static PyObject*
oaDMFile_isPrimary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isPrimary());
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
static char oaDMFile_releaseLock_doc[] = 
"Class: oaDMFile, Function: releaseLock\n"
"  Paramegers: ()\n"
"    Calls: void releaseLock()\n"
"    Signature: releaseLock|void-void|\n"
"    BrowseData: 0\n"
"    This function is used to release a lock on the current file.\n"
;

static PyObject*
oaDMFile_releaseLock(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->releaseLock();
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
static char oaDMFile_setLeader_doc[] = 
"Class: oaDMFile, Function: setLeader\n"
"  Paramegers: (oaDMFile)\n"
"    Calls: void setLeader(oaDMFile* leader)\n"
"    Signature: setLeader|void-void|ptr-oaDMFile,\n"
"    This function is used to set the specified oaDMFile leader as the leader for this oaDMFile. Leader and follower files must belong to same parent. OA does not support multiple levels of leader-follower relationships, so if the file is a leader, it cannot also be a follower. A primary file can be a leader, but cannot be a follower.\n"
"    Note: This function requires current write access to the library associated with this object (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if write access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib .\n"
"    leader\n"
"    The specified leader file\n"
"    oacCannotHaveMultiLevelFollowers\n"
"    oacPrimaryCannotBeFollower\n"
"    oacLeaderFollowerNotInSameParent\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_setLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMFileObject* self=(PyoaDMFileObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMFile p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMFile_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setLeader(p1.Data());
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
static char oaDMFile_isNull_doc[] =
"Class: oaDMFile, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaDMFile_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaDMFile data;
    int convert_status=PyoaDMFile_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaDMFile_assign_doc[] = 
"Class: oaDMFile, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMFile_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMFile data;
  int convert_status=PyoaDMFile_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMFile p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMFile_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMFile_methodlist[] = {
    {"destroy",(PyCFunction)oaDMFile_destroy,METH_VARARGS,oaDMFile_destroy_doc},
    {"existsOnDisk",(PyCFunction)oaDMFile_existsOnDisk,METH_VARARGS,oaDMFile_existsOnDisk_doc},
    {"getFollowers",(PyCFunction)oaDMFile_getFollowers,METH_VARARGS,oaDMFile_getFollowers_doc},
    {"getFollowersIter",(PyCFunction)oaDMFile_getFollowersIter,METH_VARARGS,oaDMFile_getFollowersIter_doc},
    {"getLeader",(PyCFunction)oaDMFile_getLeader,METH_VARARGS,oaDMFile_getLeader_doc},
    {"getLock",(PyCFunction)oaDMFile_getLock,METH_VARARGS,oaDMFile_getLock_doc},
    {"getLockStatus",(PyCFunction)oaDMFile_getLockStatus,METH_VARARGS,oaDMFile_getLockStatus_doc},
    {"getName",(PyCFunction)oaDMFile_getName,METH_VARARGS,oaDMFile_getName_doc},
    {"getOnDiskSize",(PyCFunction)oaDMFile_getOnDiskSize,METH_VARARGS,oaDMFile_getOnDiskSize_doc},
    {"getParent",(PyCFunction)oaDMFile_getParent,METH_VARARGS,oaDMFile_getParent_doc},
    {"getPath",(PyCFunction)oaDMFile_getPath,METH_VARARGS,oaDMFile_getPath_doc},
    {"getVersion",(PyCFunction)oaDMFile_getVersion,METH_VARARGS,oaDMFile_getVersion_doc},
    {"isLeader",(PyCFunction)oaDMFile_isLeader,METH_VARARGS,oaDMFile_isLeader_doc},
    {"isPrimary",(PyCFunction)oaDMFile_isPrimary,METH_VARARGS,oaDMFile_isPrimary_doc},
    {"releaseLock",(PyCFunction)oaDMFile_releaseLock,METH_VARARGS,oaDMFile_releaseLock_doc},
    {"setLeader",(PyCFunction)oaDMFile_setLeader,METH_VARARGS,oaDMFile_setLeader_doc},
    {"isNull",(PyCFunction)oaDMFile_tp_isNull,METH_VARARGS,oaDMFile_isNull_doc},
    {"assign",(PyCFunction)oaDMFile_tp_assign,METH_VARARGS,oaDMFile_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMFile_doc[] = 
"Class: oaDMFile\n"
"  The oaDMFile class represents a managed file.\n"
"  The oaDMFile class can be observed by deriving from\n"
"  Note: The oaDMFile function descriptions indicate if library access is required for the called function. If write access is necessary, this requirement also is noted.\n"
"  For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"Constructors:\n"
"  Paramegers: (oaDMFile)\n"
"    Calls: (const oaDMFile&)\n"
"    Signature: oaDMFile||cref-oaDMFile,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMFile_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMFile",
    sizeof(PyoaDMFileObject),
    0,
    (destructor)oaDMFile_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMFile_tp_compare,	/* tp_compare */
    (reprfunc)oaDMFile_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMFile_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMFile_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDMObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMFile_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMFile_static_create_doc[] = 
"Class: oaDMFile, Function: create\n"
"  Paramegers: (oaDMContainer,oaString,oaString)\n"
"    Calls: oaDMFile* create(const oaDMContainer* parent,const oaString& name,const oaString& srcPath)\n"
"    Signature: create|ptr-oaDMFile|cptr-oaDMContainer,cref-oaString,cref-oaString,\n"
"    This function copies a file from the specified path into the library directory. An exception is thrown if an oaDMFile already exists with the same name and parent.\n"
"    parent\n"
"    The parent of the file to be created\n"
"    name\n"
"    The name of the file to be created\n"
"    path\n"
"    The path of the file to be copied from\n"
"    oacDMFileExists\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaDMContainer,oaString)\n"
"    Calls: oaDMFile* create(const oaDMContainer* parent,const oaString& name)\n"
"    Signature: create|ptr-oaDMFile|cptr-oaDMContainer,cref-oaString,\n"
"    This function creates a new entry for the file with the specified name and parent. An error is thrown if an oaDMFile already exists with the same name and parent.\n"
"    Note: This function requires write access to the library associated with this object (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if write access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    parent\n"
"    The parent of the file to be created\n"
"    name\n"
"    The name of the file to be created\n"
"    oacDMFileExists\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaDMContainer,oaString,oaString)
    {
        PyParamoaDMContainer p1;
        PyParamoaString p2;
        PyParamoaString p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDMContainer_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaString_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaDMFilep result= (oaDMFile::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaDMFile_FromoaDMFile(result);
        }
    }
    PyErr_Clear();
    // Case: (oaDMContainer,oaString)
    {
        PyParamoaDMContainer p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDMContainer_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaDMFilep result= (oaDMFile::create(p1.Data(),p2.Data()));
            return PyoaDMFile_FromoaDMFile(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaDMFile, function: create, Choices are:\n"
        "    (oaDMContainer,oaString,oaString)\n"
        "    (oaDMContainer,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaDMFile_static_find_doc[] = 
"Class: oaDMFile, Function: find\n"
"  Paramegers: (oaDMContainer,oaString)\n"
"    Calls: oaDMFile* find(const oaDMContainer* parent,const oaString& name)\n"
"    Signature: find|ptr-oaDMFile|cptr-oaDMContainer,cref-oaString,\n"
"    This function finds and returns the file with the specified name and parent if it exists. If not found, NULL is returned.\n"
"    This function requires access to the library associated with this object (through a call to oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib and OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"    parent\n"
"    The parent of the file\n"
"    name\n"
"    The name of the file\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaDMFile_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMContainer p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMContainer_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaDMFilep result= (oaDMFile::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaDMFile_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaDMFile_static_create,METH_VARARGS,oaDMFile_static_create_doc},
    {"static_find",(PyCFunction)oaDMFile_static_find,METH_VARARGS,oaDMFile_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMFile_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMFile_Type)<0) {
      printf("** PyType_Ready failed for: oaDMFile\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMFile",
           (PyObject*)(&PyoaDMFile_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMFile\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaDMFile_Type.tp_dict;
    for(method=oaDMFile_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaDMFileModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaDMFileModTypeEnum_Convert(PyObject* ob,PyParamoaDMFileModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetLeaderDMFileModType")==0) { result->SetData(oacSetLeaderDMFileModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaDMFileModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMFileModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaDMFileModTypeEnum_FromoaDMFileModTypeEnum(oaDMFileModTypeEnum ob)
{
    if (ob==oacSetLeaderDMFileModType) return PyString_FromString("oacSetLeaderDMFileModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaDMFileModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaDMFileModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaDMFileModTypeEnum_FromoaDMFileModTypeEnum(oaDMFileModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaDMFileModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaDMFileModTypeEnum_doc[] =
"Type convert function for enum: oaDMFileModTypeEnum";
                               
static PyMethodDef PyoaDMFileModTypeEnum_method =
  {"oaDMFileModTypeEnum",(PyCFunction)PyoaDMFileModTypeEnum_TypeFunction,METH_VARARGS,oaDMFileModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaDMFileModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetLeaderDMFileModType");
    PyDict_SetItemString(mod_dict,"oacSetLeaderDMFileModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaDMFileModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaDMFileModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaDMFileModTypeEnum\n");
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
// Wrapper Implementation for Class: oaDMLibModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaDMLibModTypeEnum_Convert(PyObject* ob,PyParamoaDMLibModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetAttributesLibModType")==0) { result->SetData(oacSetAttributesLibModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaDMLibModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMLibModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaDMLibModTypeEnum_FromoaDMLibModTypeEnum(oaDMLibModTypeEnum ob)
{
    if (ob==oacSetAttributesLibModType) return PyString_FromString("oacSetAttributesLibModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaDMLibModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaDMLibModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaDMLibModTypeEnum_FromoaDMLibModTypeEnum(oaDMLibModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaDMLibModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaDMLibModTypeEnum_doc[] =
"Type convert function for enum: oaDMLibModTypeEnum";
                               
static PyMethodDef PyoaDMLibModTypeEnum_method =
  {"oaDMLibModTypeEnum",(PyCFunction)PyoaDMLibModTypeEnum_TypeFunction,METH_VARARGS,oaDMLibModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaDMLibModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetAttributesLibModType");
    PyDict_SetItemString(mod_dict,"oacSetAttributesLibModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaDMLibModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaDMLibModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaDMLibModTypeEnum\n");
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
// Wrapper Implementation for Class: oaDMLockStatus
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaDMLockStatus_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaDMLockStatus_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaDMLockStatusObject* self = (PyoaDMLockStatusObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaDMLockStatusEnum)
    {
        PyParamoaDMLockStatusEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDMLockStatusEnum_Convert,&p1)) {
            self->value =  new oaDMLockStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDMLockStatus)
    {
        PyParamoaDMLockStatus p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaDMLockStatus_Convert,&p1)) {
            self->value= new oaDMLockStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaDMLockStatus, Choices are:\n"
        "    (oaDMLockStatusEnum)\n"
        "    (oaDMLockStatus)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaDMLockStatus_tp_dealloc(PyoaDMLockStatusObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaDMLockStatus_tp_repr(PyObject *ob)
{
    PyParamoaDMLockStatus value;
    int convert_status=PyoaDMLockStatus_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[36];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaDMLockStatus::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaDMLockStatus_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaDMLockStatus v1;
    PyParamoaDMLockStatus v2;
    int convert_status1=PyoaDMLockStatus_Convert(ob1,&v1);
    int convert_status2=PyoaDMLockStatus_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaDMLockStatus_Convert(PyObject* ob,PyParamoaDMLockStatus* result)
{
    if (ob == NULL) return 1;
    if (PyoaDMLockStatus_Check(ob)) {
        result->SetData(  ((PyoaDMLockStatusObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMLockStatus Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaDMLockStatus_FromoaDMLockStatus(oaDMLockStatus* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaDMLockStatus_Type.tp_alloc(&PyoaDMLockStatus_Type,0);
        if (bself == NULL) return bself;
        PyoaDMLockStatusObject* self = (PyoaDMLockStatusObject*)bself;
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
static char oaDMLockStatus_getName_doc[] = 
"Class: oaDMLockStatus, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the oaDMLockStatusEnum value set on this oaDMLockStatus object.\n"
;

static PyObject*
oaDMLockStatus_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMLockStatus data;
    int convert_status=PyoaDMLockStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMLockStatusObject* self=(PyoaDMLockStatusObject*)ob;

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
static char oaDMLockStatus_oaDMLockStatusEnum_doc[] = 
"Class: oaDMLockStatus, Function: oaDMLockStatusEnum\n"
"  Paramegers: ()\n"
"    Calls: oaDMLockStatusEnum oaDMLockStatusEnum() const\n"
"    Signature: operator oaDMLockStatusEnum|simple-oaDMLockStatusEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaDMLockStatus object into its corresponding oaDMLockStatusEnum value.\n"
;

static PyObject*
oaDMLockStatus_oaDMLockStatusEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMLockStatus data;
    int convert_status=PyoaDMLockStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaDMLockStatusObject* self=(PyoaDMLockStatusObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDMLockStatusEnum result= (data.DataCall()->operator oaDMLockStatusEnum());
        return PyoaDMLockStatusEnum_FromoaDMLockStatusEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaDMLockStatus_assign_doc[] = 
"Class: oaDMLockStatus, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaDMLockStatus_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaDMLockStatus data;
  int convert_status=PyoaDMLockStatus_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaDMLockStatus p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaDMLockStatus_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaDMLockStatus_methodlist[] = {
    {"getName",(PyCFunction)oaDMLockStatus_getName,METH_VARARGS,oaDMLockStatus_getName_doc},
    {"oaDMLockStatusEnum",(PyCFunction)oaDMLockStatus_oaDMLockStatusEnum,METH_VARARGS,oaDMLockStatus_oaDMLockStatusEnum_doc},
    {"assign",(PyCFunction)oaDMLockStatus_tp_assign,METH_VARARGS,oaDMLockStatus_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaDMLockStatus_doc[] = 
"Class: oaDMLockStatus\n"
"  oaDMLockStatusEnum\n"
"  The oaDMLockStatus class is an enum wrapper class for oaDMLockStatusEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaDMLockStatusEnum)\n"
"    Calls: oaDMLockStatus(oaDMLockStatusEnum valueIn)\n"
"    Signature: oaDMLockStatus||simple-oaDMLockStatusEnum,\n"
"    This oaDMLockStatus constructor takes an oaDMLockStatusEnum value as input.\n"
"    valueIn\n"
"    an oaDMLockStatusEnum value\n"
"  Paramegers: (oaDMLockStatus)\n"
"    Calls: (const oaDMLockStatus&)\n"
"    Signature: oaDMLockStatus||cref-oaDMLockStatus,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaDMLockStatus_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaDMLockStatus",
    sizeof(PyoaDMLockStatusObject),
    0,
    (destructor)oaDMLockStatus_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaDMLockStatus_tp_compare,	/* tp_compare */
    (reprfunc)oaDMLockStatus_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaDMLockStatus_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaDMLockStatus_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaDMLockStatus_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaDMLockStatus_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaDMLockStatus_Type)<0) {
      printf("** PyType_Ready failed for: oaDMLockStatus\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaDMLockStatus",
           (PyObject*)(&PyoaDMLockStatus_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaDMLockStatus\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaDMLockStatusEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaDMLockStatusEnum_Convert(PyObject* ob,PyParamoaDMLockStatusEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNotLocked")==0) { result->SetData(oacNotLocked); return 1;}
        if (strcasecmp(str,"oacLockedByCurrentProcess")==0) { result->SetData(oacLockedByCurrentProcess); return 1;}
        if (strcasecmp(str,"oacLockedByForeignProcess")==0) { result->SetData(oacLockedByForeignProcess); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaDMLockStatusEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaDMLockStatusEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaDMLockStatusEnum_FromoaDMLockStatusEnum(oaDMLockStatusEnum ob)
{
    if (ob==oacNotLocked) return PyString_FromString("oacNotLocked");
    if (ob==oacLockedByCurrentProcess) return PyString_FromString("oacLockedByCurrentProcess");
    if (ob==oacLockedByForeignProcess) return PyString_FromString("oacLockedByForeignProcess");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaDMLockStatusEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaDMLockStatusEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaDMLockStatusEnum_FromoaDMLockStatusEnum(oaDMLockStatusEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaDMLockStatusEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaDMLockStatusEnum_doc[] =
"Type convert function for enum: oaDMLockStatusEnum";
                               
static PyMethodDef PyoaDMLockStatusEnum_method =
  {"oaDMLockStatusEnum",(PyCFunction)PyoaDMLockStatusEnum_TypeFunction,METH_VARARGS,oaDMLockStatusEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaDMLockStatusEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNotLocked");
    PyDict_SetItemString(mod_dict,"oacNotLocked",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLockedByCurrentProcess");
    PyDict_SetItemString(mod_dict,"oacLockedByCurrentProcess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLockedByForeignProcess");
    PyDict_SetItemString(mod_dict,"oacLockedByForeignProcess",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaDMLockStatusEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaDMLockStatusEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaDMLockStatusEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}
