
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaImage_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaImage_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaImage_oaWaferObject* self = (PyoaCollection_oaImage_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaImage_oaWafer)
    {
        PyParamoaCollection_oaImage_oaWafer p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaImage_oaWafer_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaImage_oaWafer(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaImage_oaWafer, Choices are:\n"
        "    (oaCollection_oaImage_oaWafer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaImage_oaWafer_tp_dealloc(PyoaCollection_oaImage_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaImage_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaImage_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaImage_oaWafer value;
    int convert_status=PyoaCollection_oaImage_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaImage_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaImage_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaImage_oaWafer v1;
    PyParamoaCollection_oaImage_oaWafer v2;
    int convert_status1=PyoaCollection_oaImage_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaImage_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaImage_oaWafer_Convert(PyObject* ob,PyParamoaCollection_oaImage_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaImage_oaWafer_Check(ob)) {
        result->SetData( (oaCollection_oaImage_oaWafer*) ((PyoaCollection_oaImage_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaImage_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaImage_oaWafer_FromoaCollection_oaImage_oaWafer(oaCollection_oaImage_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaImage_oaWafer_Type.tp_alloc(&PyoaCollection_oaImage_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaImage_oaWaferObject* self = (PyoaCollection_oaImage_oaWaferObject*)bself;
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
static char oaCollection_oaImage_oaWafer_includes_doc[] = 
"Class: oaCollection_oaImage_oaWafer, Function: includes\n"
"  Paramegers: (oaImage)\n"
"    Calls: oaBoolean includes(const oaImage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaImage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaImage_oaWafer_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaImage_oaWafer data;
    int convert_status=PyoaCollection_oaImage_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaImage_oaWaferObject* self=(PyoaCollection_oaImage_oaWaferObject*)ob;

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

static char oaCollection_oaImage_oaWafer_assign_doc[] = 
"Class: oaCollection_oaImage_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaImage_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaImage_oaWafer data;
  int convert_status=PyoaCollection_oaImage_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaImage_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaImage_oaWafer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaImage_oaWafer_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaImage_oaWafer_includes,METH_VARARGS,oaCollection_oaImage_oaWafer_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaImage_oaWafer_tp_assign,METH_VARARGS,oaCollection_oaImage_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaImage_oaWafer_doc[] = 
"Class: oaCollection_oaImage_oaWafer\n"
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
"  Paramegers: (oaCollection_oaImage_oaWafer)\n"
"    Calls: oaCollection_oaImage_oaWafer(const oaCollection_oaImage_oaWafer& coll)\n"
"    Signature: oaCollection_oaImage_oaWafer||cref-oaCollection_oaImage_oaWafer,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaImage_oaWafer)\n"
"    Calls: (const oaCollection_oaImage_oaWafer&)\n"
"    Signature: oaCollection_oaImage_oaWafer||cref-oaCollection_oaImage_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaImage_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaImage_oaWafer",
    sizeof(PyoaCollection_oaImage_oaWaferObject),
    0,
    (destructor)oaCollection_oaImage_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaImage_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaImage_oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaImage_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaImage_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaImage_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaImage_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaImage_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaImage_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaImage_oaWafer",
           (PyObject*)(&PyoaCollection_oaImage_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaImage_oaWafer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstHeader_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstHeader_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstHeader_oaBlockObject* self = (PyoaCollection_oaInstHeader_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstHeader_oaBlock)
    {
        PyParamoaCollection_oaInstHeader_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstHeader_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstHeader_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstHeader_oaBlock, Choices are:\n"
        "    (oaCollection_oaInstHeader_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstHeader_oaBlock_tp_dealloc(PyoaCollection_oaInstHeader_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstHeader_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstHeader_oaBlock value;
    int convert_status=PyoaCollection_oaInstHeader_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaInstHeader_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstHeader_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstHeader_oaBlock v1;
    PyParamoaCollection_oaInstHeader_oaBlock v2;
    int convert_status1=PyoaCollection_oaInstHeader_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstHeader_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstHeader_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaInstHeader_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstHeader_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaInstHeader_oaBlock*) ((PyoaCollection_oaInstHeader_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstHeader_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstHeader_oaBlock_FromoaCollection_oaInstHeader_oaBlock(oaCollection_oaInstHeader_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstHeader_oaBlock_Type.tp_alloc(&PyoaCollection_oaInstHeader_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstHeader_oaBlockObject* self = (PyoaCollection_oaInstHeader_oaBlockObject*)bself;
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
static char oaCollection_oaInstHeader_oaBlock_includes_doc[] = 
"Class: oaCollection_oaInstHeader_oaBlock, Function: includes\n"
"  Paramegers: (oaInstHeader)\n"
"    Calls: oaBoolean includes(const oaInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstHeader_oaBlock data;
    int convert_status=PyoaCollection_oaInstHeader_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstHeader_oaBlockObject* self=(PyoaCollection_oaInstHeader_oaBlockObject*)ob;

    PyParamoaInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstHeader_Convert,&p1)) {
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

static char oaCollection_oaInstHeader_oaBlock_assign_doc[] = 
"Class: oaCollection_oaInstHeader_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstHeader_oaBlock data;
  int convert_status=PyoaCollection_oaInstHeader_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstHeader_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstHeader_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstHeader_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstHeader_oaBlock_includes,METH_VARARGS,oaCollection_oaInstHeader_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstHeader_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaInstHeader_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstHeader_oaBlock_doc[] = 
"Class: oaCollection_oaInstHeader_oaBlock\n"
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
"  Paramegers: (oaCollection_oaInstHeader_oaBlock)\n"
"    Calls: oaCollection_oaInstHeader_oaBlock(const oaCollection_oaInstHeader_oaBlock& coll)\n"
"    Signature: oaCollection_oaInstHeader_oaBlock||cref-oaCollection_oaInstHeader_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstHeader_oaBlock)\n"
"    Calls: (const oaCollection_oaInstHeader_oaBlock&)\n"
"    Signature: oaCollection_oaInstHeader_oaBlock||cref-oaCollection_oaInstHeader_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstHeader_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstHeader_oaBlock",
    sizeof(PyoaCollection_oaInstHeader_oaBlockObject),
    0,
    (destructor)oaCollection_oaInstHeader_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstHeader_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstHeader_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstHeader_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstHeader_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstHeader_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstHeader_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstHeader_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstHeader_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstHeader_oaBlock",
           (PyObject*)(&PyoaCollection_oaInstHeader_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstHeader_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstHeader_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstHeader_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstHeader_oaDesignObject* self = (PyoaCollection_oaInstHeader_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstHeader_oaDesign)
    {
        PyParamoaCollection_oaInstHeader_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstHeader_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstHeader_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstHeader_oaDesign, Choices are:\n"
        "    (oaCollection_oaInstHeader_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstHeader_oaDesign_tp_dealloc(PyoaCollection_oaInstHeader_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstHeader_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstHeader_oaDesign value;
    int convert_status=PyoaCollection_oaInstHeader_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaInstHeader_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstHeader_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstHeader_oaDesign v1;
    PyParamoaCollection_oaInstHeader_oaDesign v2;
    int convert_status1=PyoaCollection_oaInstHeader_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstHeader_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstHeader_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaInstHeader_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstHeader_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaInstHeader_oaDesign*) ((PyoaCollection_oaInstHeader_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstHeader_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstHeader_oaDesign_FromoaCollection_oaInstHeader_oaDesign(oaCollection_oaInstHeader_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstHeader_oaDesign_Type.tp_alloc(&PyoaCollection_oaInstHeader_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstHeader_oaDesignObject* self = (PyoaCollection_oaInstHeader_oaDesignObject*)bself;
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
static char oaCollection_oaInstHeader_oaDesign_includes_doc[] = 
"Class: oaCollection_oaInstHeader_oaDesign, Function: includes\n"
"  Paramegers: (oaInstHeader)\n"
"    Calls: oaBoolean includes(const oaInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstHeader_oaDesign data;
    int convert_status=PyoaCollection_oaInstHeader_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstHeader_oaDesignObject* self=(PyoaCollection_oaInstHeader_oaDesignObject*)ob;

    PyParamoaInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstHeader_Convert,&p1)) {
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

static char oaCollection_oaInstHeader_oaDesign_assign_doc[] = 
"Class: oaCollection_oaInstHeader_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstHeader_oaDesign data;
  int convert_status=PyoaCollection_oaInstHeader_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstHeader_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstHeader_oaDesign_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstHeader_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstHeader_oaDesign_includes,METH_VARARGS,oaCollection_oaInstHeader_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstHeader_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaInstHeader_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstHeader_oaDesign_doc[] = 
"Class: oaCollection_oaInstHeader_oaDesign\n"
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
"  Paramegers: (oaCollection_oaInstHeader_oaDesign)\n"
"    Calls: oaCollection_oaInstHeader_oaDesign(const oaCollection_oaInstHeader_oaDesign& coll)\n"
"    Signature: oaCollection_oaInstHeader_oaDesign||cref-oaCollection_oaInstHeader_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstHeader_oaDesign)\n"
"    Calls: (const oaCollection_oaInstHeader_oaDesign&)\n"
"    Signature: oaCollection_oaInstHeader_oaDesign||cref-oaCollection_oaInstHeader_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstHeader_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstHeader_oaDesign",
    sizeof(PyoaCollection_oaInstHeader_oaDesignObject),
    0,
    (destructor)oaCollection_oaInstHeader_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstHeader_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstHeader_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstHeader_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstHeader_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstHeader_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstHeader_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstHeader_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstHeader_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstHeader_oaDesign",
           (PyObject*)(&PyoaCollection_oaInstHeader_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstHeader_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstHeader_oaInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstHeader_oaInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstHeader_oaInstHeaderObject* self = (PyoaCollection_oaInstHeader_oaInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstHeader_oaInstHeader)
    {
        PyParamoaCollection_oaInstHeader_oaInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstHeader_oaInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstHeader_oaInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstHeader_oaInstHeader, Choices are:\n"
        "    (oaCollection_oaInstHeader_oaInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstHeader_oaInstHeader_tp_dealloc(PyoaCollection_oaInstHeader_oaInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstHeader_oaInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstHeader_oaInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstHeader_oaInstHeader value;
    int convert_status=PyoaCollection_oaInstHeader_oaInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaInstHeader_oaInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstHeader_oaInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstHeader_oaInstHeader v1;
    PyParamoaCollection_oaInstHeader_oaInstHeader v2;
    int convert_status1=PyoaCollection_oaInstHeader_oaInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstHeader_oaInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstHeader_oaInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaInstHeader_oaInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstHeader_oaInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaInstHeader_oaInstHeader*) ((PyoaCollection_oaInstHeader_oaInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstHeader_oaInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstHeader_oaInstHeader_FromoaCollection_oaInstHeader_oaInstHeader(oaCollection_oaInstHeader_oaInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstHeader_oaInstHeader_Type.tp_alloc(&PyoaCollection_oaInstHeader_oaInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstHeader_oaInstHeaderObject* self = (PyoaCollection_oaInstHeader_oaInstHeaderObject*)bself;
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
static char oaCollection_oaInstHeader_oaInstHeader_includes_doc[] = 
"Class: oaCollection_oaInstHeader_oaInstHeader, Function: includes\n"
"  Paramegers: (oaInstHeader)\n"
"    Calls: oaBoolean includes(const oaInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstHeader_oaInstHeader data;
    int convert_status=PyoaCollection_oaInstHeader_oaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstHeader_oaInstHeaderObject* self=(PyoaCollection_oaInstHeader_oaInstHeaderObject*)ob;

    PyParamoaInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstHeader_Convert,&p1)) {
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

static char oaCollection_oaInstHeader_oaInstHeader_assign_doc[] = 
"Class: oaCollection_oaInstHeader_oaInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstHeader_oaInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstHeader_oaInstHeader data;
  int convert_status=PyoaCollection_oaInstHeader_oaInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstHeader_oaInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstHeader_oaInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstHeader_oaInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstHeader_oaInstHeader_includes,METH_VARARGS,oaCollection_oaInstHeader_oaInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstHeader_oaInstHeader_tp_assign,METH_VARARGS,oaCollection_oaInstHeader_oaInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstHeader_oaInstHeader_doc[] = 
"Class: oaCollection_oaInstHeader_oaInstHeader\n"
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
"  Paramegers: (oaCollection_oaInstHeader_oaInstHeader)\n"
"    Calls: oaCollection_oaInstHeader_oaInstHeader(const oaCollection_oaInstHeader_oaInstHeader& coll)\n"
"    Signature: oaCollection_oaInstHeader_oaInstHeader||cref-oaCollection_oaInstHeader_oaInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstHeader_oaInstHeader)\n"
"    Calls: (const oaCollection_oaInstHeader_oaInstHeader&)\n"
"    Signature: oaCollection_oaInstHeader_oaInstHeader||cref-oaCollection_oaInstHeader_oaInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstHeader_oaInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstHeader_oaInstHeader",
    sizeof(PyoaCollection_oaInstHeader_oaInstHeaderObject),
    0,
    (destructor)oaCollection_oaInstHeader_oaInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstHeader_oaInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstHeader_oaInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstHeader_oaInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstHeader_oaInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstHeader_oaInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstHeader_oaInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstHeader_oaInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstHeader_oaInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstHeader_oaInstHeader",
           (PyObject*)(&PyoaCollection_oaInstHeader_oaInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstHeader_oaInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstTerm_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstTerm_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstTerm_oaBlockObject* self = (PyoaCollection_oaInstTerm_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstTerm_oaBlock)
    {
        PyParamoaCollection_oaInstTerm_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstTerm_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstTerm_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstTerm_oaBlock, Choices are:\n"
        "    (oaCollection_oaInstTerm_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstTerm_oaBlock_tp_dealloc(PyoaCollection_oaInstTerm_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstTerm_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstTerm_oaBlock value;
    int convert_status=PyoaCollection_oaInstTerm_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaInstTerm_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstTerm_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstTerm_oaBlock v1;
    PyParamoaCollection_oaInstTerm_oaBlock v2;
    int convert_status1=PyoaCollection_oaInstTerm_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstTerm_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstTerm_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaInstTerm_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstTerm_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaInstTerm_oaBlock*) ((PyoaCollection_oaInstTerm_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstTerm_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstTerm_oaBlock_FromoaCollection_oaInstTerm_oaBlock(oaCollection_oaInstTerm_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstTerm_oaBlock_Type.tp_alloc(&PyoaCollection_oaInstTerm_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstTerm_oaBlockObject* self = (PyoaCollection_oaInstTerm_oaBlockObject*)bself;
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
static char oaCollection_oaInstTerm_oaBlock_includes_doc[] = 
"Class: oaCollection_oaInstTerm_oaBlock, Function: includes\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: oaBoolean includes(const oaInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstTerm_oaBlock data;
    int convert_status=PyoaCollection_oaInstTerm_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstTerm_oaBlockObject* self=(PyoaCollection_oaInstTerm_oaBlockObject*)ob;

    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstTerm_Convert,&p1)) {
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

static char oaCollection_oaInstTerm_oaBlock_assign_doc[] = 
"Class: oaCollection_oaInstTerm_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstTerm_oaBlock data;
  int convert_status=PyoaCollection_oaInstTerm_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstTerm_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstTerm_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstTerm_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstTerm_oaBlock_includes,METH_VARARGS,oaCollection_oaInstTerm_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstTerm_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaInstTerm_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstTerm_oaBlock_doc[] = 
"Class: oaCollection_oaInstTerm_oaBlock\n"
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
"  Paramegers: (oaCollection_oaInstTerm_oaBlock)\n"
"    Calls: oaCollection_oaInstTerm_oaBlock(const oaCollection_oaInstTerm_oaBlock& coll)\n"
"    Signature: oaCollection_oaInstTerm_oaBlock||cref-oaCollection_oaInstTerm_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstTerm_oaBlock)\n"
"    Calls: (const oaCollection_oaInstTerm_oaBlock&)\n"
"    Signature: oaCollection_oaInstTerm_oaBlock||cref-oaCollection_oaInstTerm_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstTerm_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstTerm_oaBlock",
    sizeof(PyoaCollection_oaInstTerm_oaBlockObject),
    0,
    (destructor)oaCollection_oaInstTerm_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstTerm_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstTerm_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstTerm_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstTerm_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstTerm_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstTerm_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstTerm_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstTerm_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstTerm_oaBlock",
           (PyObject*)(&PyoaCollection_oaInstTerm_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstTerm_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstTerm_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstTerm_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstTerm_oaInstObject* self = (PyoaCollection_oaInstTerm_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstTerm_oaInst)
    {
        PyParamoaCollection_oaInstTerm_oaInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstTerm_oaInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstTerm_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstTerm_oaInst, Choices are:\n"
        "    (oaCollection_oaInstTerm_oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstTerm_oaInst_tp_dealloc(PyoaCollection_oaInstTerm_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstTerm_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstTerm_oaInst value;
    int convert_status=PyoaCollection_oaInstTerm_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaInstTerm_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstTerm_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstTerm_oaInst v1;
    PyParamoaCollection_oaInstTerm_oaInst v2;
    int convert_status1=PyoaCollection_oaInstTerm_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstTerm_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstTerm_oaInst_Convert(PyObject* ob,PyParamoaCollection_oaInstTerm_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstTerm_oaInst_Check(ob)) {
        result->SetData( (oaCollection_oaInstTerm_oaInst*) ((PyoaCollection_oaInstTerm_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstTerm_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstTerm_oaInst_FromoaCollection_oaInstTerm_oaInst(oaCollection_oaInstTerm_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstTerm_oaInst_Type.tp_alloc(&PyoaCollection_oaInstTerm_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstTerm_oaInstObject* self = (PyoaCollection_oaInstTerm_oaInstObject*)bself;
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
static char oaCollection_oaInstTerm_oaInst_includes_doc[] = 
"Class: oaCollection_oaInstTerm_oaInst, Function: includes\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: oaBoolean includes(const oaInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstTerm_oaInst data;
    int convert_status=PyoaCollection_oaInstTerm_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstTerm_oaInstObject* self=(PyoaCollection_oaInstTerm_oaInstObject*)ob;

    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstTerm_Convert,&p1)) {
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

static char oaCollection_oaInstTerm_oaInst_assign_doc[] = 
"Class: oaCollection_oaInstTerm_oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstTerm_oaInst data;
  int convert_status=PyoaCollection_oaInstTerm_oaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstTerm_oaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstTerm_oaInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstTerm_oaInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstTerm_oaInst_includes,METH_VARARGS,oaCollection_oaInstTerm_oaInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstTerm_oaInst_tp_assign,METH_VARARGS,oaCollection_oaInstTerm_oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstTerm_oaInst_doc[] = 
"Class: oaCollection_oaInstTerm_oaInst\n"
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
"  Paramegers: (oaCollection_oaInstTerm_oaInst)\n"
"    Calls: oaCollection_oaInstTerm_oaInst(const oaCollection_oaInstTerm_oaInst& coll)\n"
"    Signature: oaCollection_oaInstTerm_oaInst||cref-oaCollection_oaInstTerm_oaInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstTerm_oaInst)\n"
"    Calls: (const oaCollection_oaInstTerm_oaInst&)\n"
"    Signature: oaCollection_oaInstTerm_oaInst||cref-oaCollection_oaInstTerm_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstTerm_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstTerm_oaInst",
    sizeof(PyoaCollection_oaInstTerm_oaInstObject),
    0,
    (destructor)oaCollection_oaInstTerm_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstTerm_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstTerm_oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstTerm_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstTerm_oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstTerm_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstTerm_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstTerm_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstTerm_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstTerm_oaInst",
           (PyObject*)(&PyoaCollection_oaInstTerm_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstTerm_oaInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInstTerm_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInstTerm_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInstTerm_oaNetObject* self = (PyoaCollection_oaInstTerm_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInstTerm_oaNet)
    {
        PyParamoaCollection_oaInstTerm_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInstTerm_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInstTerm_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInstTerm_oaNet, Choices are:\n"
        "    (oaCollection_oaInstTerm_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInstTerm_oaNet_tp_dealloc(PyoaCollection_oaInstTerm_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInstTerm_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInstTerm_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInstTerm_oaNet value;
    int convert_status=PyoaCollection_oaInstTerm_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaInstTerm_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInstTerm_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInstTerm_oaNet v1;
    PyParamoaCollection_oaInstTerm_oaNet v2;
    int convert_status1=PyoaCollection_oaInstTerm_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInstTerm_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInstTerm_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaInstTerm_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInstTerm_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaInstTerm_oaNet*) ((PyoaCollection_oaInstTerm_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInstTerm_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInstTerm_oaNet_FromoaCollection_oaInstTerm_oaNet(oaCollection_oaInstTerm_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInstTerm_oaNet_Type.tp_alloc(&PyoaCollection_oaInstTerm_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInstTerm_oaNetObject* self = (PyoaCollection_oaInstTerm_oaNetObject*)bself;
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
static char oaCollection_oaInstTerm_oaNet_includes_doc[] = 
"Class: oaCollection_oaInstTerm_oaNet, Function: includes\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: oaBoolean includes(const oaInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInstTerm_oaNet data;
    int convert_status=PyoaCollection_oaInstTerm_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInstTerm_oaNetObject* self=(PyoaCollection_oaInstTerm_oaNetObject*)ob;

    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstTerm_Convert,&p1)) {
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

static char oaCollection_oaInstTerm_oaNet_assign_doc[] = 
"Class: oaCollection_oaInstTerm_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInstTerm_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInstTerm_oaNet data;
  int convert_status=PyoaCollection_oaInstTerm_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInstTerm_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInstTerm_oaNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInstTerm_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInstTerm_oaNet_includes,METH_VARARGS,oaCollection_oaInstTerm_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInstTerm_oaNet_tp_assign,METH_VARARGS,oaCollection_oaInstTerm_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInstTerm_oaNet_doc[] = 
"Class: oaCollection_oaInstTerm_oaNet\n"
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
"  Paramegers: (oaCollection_oaInstTerm_oaNet)\n"
"    Calls: oaCollection_oaInstTerm_oaNet(const oaCollection_oaInstTerm_oaNet& coll)\n"
"    Signature: oaCollection_oaInstTerm_oaNet||cref-oaCollection_oaInstTerm_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInstTerm_oaNet)\n"
"    Calls: (const oaCollection_oaInstTerm_oaNet&)\n"
"    Signature: oaCollection_oaInstTerm_oaNet||cref-oaCollection_oaInstTerm_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInstTerm_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInstTerm_oaNet",
    sizeof(PyoaCollection_oaInstTerm_oaNetObject),
    0,
    (destructor)oaCollection_oaInstTerm_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInstTerm_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInstTerm_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInstTerm_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInstTerm_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInstTerm_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInstTerm_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInstTerm_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInstTerm_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInstTerm_oaNet",
           (PyObject*)(&PyoaCollection_oaInstTerm_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInstTerm_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInst_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInst_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInst_oaBlockObject* self = (PyoaCollection_oaInst_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInst_oaBlock)
    {
        PyParamoaCollection_oaInst_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInst_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInst_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInst_oaBlock, Choices are:\n"
        "    (oaCollection_oaInst_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInst_oaBlock_tp_dealloc(PyoaCollection_oaInst_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInst_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInst_oaBlock value;
    int convert_status=PyoaCollection_oaInst_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaInst_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInst_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInst_oaBlock v1;
    PyParamoaCollection_oaInst_oaBlock v2;
    int convert_status1=PyoaCollection_oaInst_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInst_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInst_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaInst_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInst_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaInst_oaBlock*) ((PyoaCollection_oaInst_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInst_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInst_oaBlock_FromoaCollection_oaInst_oaBlock(oaCollection_oaInst_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInst_oaBlock_Type.tp_alloc(&PyoaCollection_oaInst_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInst_oaBlockObject* self = (PyoaCollection_oaInst_oaBlockObject*)bself;
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
static char oaCollection_oaInst_oaBlock_includes_doc[] = 
"Class: oaCollection_oaInst_oaBlock, Function: includes\n"
"  Paramegers: (oaInst)\n"
"    Calls: oaBoolean includes(const oaInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInst_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInst_oaBlock data;
    int convert_status=PyoaCollection_oaInst_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInst_oaBlockObject* self=(PyoaCollection_oaInst_oaBlockObject*)ob;

    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInst_Convert,&p1)) {
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

static char oaCollection_oaInst_oaBlock_assign_doc[] = 
"Class: oaCollection_oaInst_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInst_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInst_oaBlock data;
  int convert_status=PyoaCollection_oaInst_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInst_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInst_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInst_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInst_oaBlock_includes,METH_VARARGS,oaCollection_oaInst_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInst_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaInst_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInst_oaBlock_doc[] = 
"Class: oaCollection_oaInst_oaBlock\n"
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
"  Paramegers: (oaCollection_oaInst_oaBlock)\n"
"    Calls: oaCollection_oaInst_oaBlock(const oaCollection_oaInst_oaBlock& coll)\n"
"    Signature: oaCollection_oaInst_oaBlock||cref-oaCollection_oaInst_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInst_oaBlock)\n"
"    Calls: (const oaCollection_oaInst_oaBlock&)\n"
"    Signature: oaCollection_oaInst_oaBlock||cref-oaCollection_oaInst_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInst_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInst_oaBlock",
    sizeof(PyoaCollection_oaInst_oaBlockObject),
    0,
    (destructor)oaCollection_oaInst_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInst_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInst_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInst_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInst_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInst_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInst_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInst_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInst_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInst_oaBlock",
           (PyObject*)(&PyoaCollection_oaInst_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInst_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInst_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInst_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInst_oaClusterObject* self = (PyoaCollection_oaInst_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInst_oaCluster)
    {
        PyParamoaCollection_oaInst_oaCluster p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInst_oaCluster_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInst_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInst_oaCluster, Choices are:\n"
        "    (oaCollection_oaInst_oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInst_oaCluster_tp_dealloc(PyoaCollection_oaInst_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInst_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInst_oaCluster value;
    int convert_status=PyoaCollection_oaInst_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaInst_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInst_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInst_oaCluster v1;
    PyParamoaCollection_oaInst_oaCluster v2;
    int convert_status1=PyoaCollection_oaInst_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInst_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInst_oaCluster_Convert(PyObject* ob,PyParamoaCollection_oaInst_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInst_oaCluster_Check(ob)) {
        result->SetData( (oaCollection_oaInst_oaCluster*) ((PyoaCollection_oaInst_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInst_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInst_oaCluster_FromoaCollection_oaInst_oaCluster(oaCollection_oaInst_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInst_oaCluster_Type.tp_alloc(&PyoaCollection_oaInst_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInst_oaClusterObject* self = (PyoaCollection_oaInst_oaClusterObject*)bself;
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
static char oaCollection_oaInst_oaCluster_includes_doc[] = 
"Class: oaCollection_oaInst_oaCluster, Function: includes\n"
"  Paramegers: (oaInst)\n"
"    Calls: oaBoolean includes(const oaInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInst_oaCluster_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInst_oaCluster data;
    int convert_status=PyoaCollection_oaInst_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInst_oaClusterObject* self=(PyoaCollection_oaInst_oaClusterObject*)ob;

    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInst_Convert,&p1)) {
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

static char oaCollection_oaInst_oaCluster_assign_doc[] = 
"Class: oaCollection_oaInst_oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInst_oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInst_oaCluster data;
  int convert_status=PyoaCollection_oaInst_oaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInst_oaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInst_oaCluster_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInst_oaCluster_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInst_oaCluster_includes,METH_VARARGS,oaCollection_oaInst_oaCluster_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInst_oaCluster_tp_assign,METH_VARARGS,oaCollection_oaInst_oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInst_oaCluster_doc[] = 
"Class: oaCollection_oaInst_oaCluster\n"
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
"  Paramegers: (oaCollection_oaInst_oaCluster)\n"
"    Calls: oaCollection_oaInst_oaCluster(const oaCollection_oaInst_oaCluster& coll)\n"
"    Signature: oaCollection_oaInst_oaCluster||cref-oaCollection_oaInst_oaCluster,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInst_oaCluster)\n"
"    Calls: (const oaCollection_oaInst_oaCluster&)\n"
"    Signature: oaCollection_oaInst_oaCluster||cref-oaCollection_oaInst_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInst_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInst_oaCluster",
    sizeof(PyoaCollection_oaInst_oaClusterObject),
    0,
    (destructor)oaCollection_oaInst_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInst_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInst_oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInst_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInst_oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInst_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInst_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInst_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInst_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInst_oaCluster",
           (PyObject*)(&PyoaCollection_oaInst_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInst_oaCluster\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaInst_oaInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaInst_oaInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaInst_oaInstHeaderObject* self = (PyoaCollection_oaInst_oaInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaInst_oaInstHeader)
    {
        PyParamoaCollection_oaInst_oaInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaInst_oaInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaInst_oaInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaInst_oaInstHeader, Choices are:\n"
        "    (oaCollection_oaInst_oaInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaInst_oaInstHeader_tp_dealloc(PyoaCollection_oaInst_oaInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaInst_oaInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaInst_oaInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaInst_oaInstHeader value;
    int convert_status=PyoaCollection_oaInst_oaInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaInst_oaInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaInst_oaInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaInst_oaInstHeader v1;
    PyParamoaCollection_oaInst_oaInstHeader v2;
    int convert_status1=PyoaCollection_oaInst_oaInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaInst_oaInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaInst_oaInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaInst_oaInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaInst_oaInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaInst_oaInstHeader*) ((PyoaCollection_oaInst_oaInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaInst_oaInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaInst_oaInstHeader_FromoaCollection_oaInst_oaInstHeader(oaCollection_oaInst_oaInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaInst_oaInstHeader_Type.tp_alloc(&PyoaCollection_oaInst_oaInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaInst_oaInstHeaderObject* self = (PyoaCollection_oaInst_oaInstHeaderObject*)bself;
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
static char oaCollection_oaInst_oaInstHeader_includes_doc[] = 
"Class: oaCollection_oaInst_oaInstHeader, Function: includes\n"
"  Paramegers: (oaInst)\n"
"    Calls: oaBoolean includes(const oaInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaInst_oaInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaInst_oaInstHeader data;
    int convert_status=PyoaCollection_oaInst_oaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaInst_oaInstHeaderObject* self=(PyoaCollection_oaInst_oaInstHeaderObject*)ob;

    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInst_Convert,&p1)) {
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

static char oaCollection_oaInst_oaInstHeader_assign_doc[] = 
"Class: oaCollection_oaInst_oaInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaInst_oaInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaInst_oaInstHeader data;
  int convert_status=PyoaCollection_oaInst_oaInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaInst_oaInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaInst_oaInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaInst_oaInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaInst_oaInstHeader_includes,METH_VARARGS,oaCollection_oaInst_oaInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaInst_oaInstHeader_tp_assign,METH_VARARGS,oaCollection_oaInst_oaInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaInst_oaInstHeader_doc[] = 
"Class: oaCollection_oaInst_oaInstHeader\n"
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
"  Paramegers: (oaCollection_oaInst_oaInstHeader)\n"
"    Calls: oaCollection_oaInst_oaInstHeader(const oaCollection_oaInst_oaInstHeader& coll)\n"
"    Signature: oaCollection_oaInst_oaInstHeader||cref-oaCollection_oaInst_oaInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaInst_oaInstHeader)\n"
"    Calls: (const oaCollection_oaInst_oaInstHeader&)\n"
"    Signature: oaCollection_oaInst_oaInstHeader||cref-oaCollection_oaInst_oaInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaInst_oaInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaInst_oaInstHeader",
    sizeof(PyoaCollection_oaInst_oaInstHeaderObject),
    0,
    (destructor)oaCollection_oaInst_oaInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaInst_oaInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaInst_oaInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaInst_oaInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaInst_oaInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaInst_oaInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaInst_oaInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaInst_oaInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaInst_oaInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaInst_oaInstHeader",
           (PyObject*)(&PyoaCollection_oaInst_oaInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaInst_oaInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLPPHeader_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLPPHeader_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLPPHeader_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLPPHeader_oaBlockObject* self = (PyoaCollection_oaLPPHeader_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLPPHeader_oaBlock)
    {
        PyParamoaCollection_oaLPPHeader_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLPPHeader_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLPPHeader_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLPPHeader_oaBlock, Choices are:\n"
        "    (oaCollection_oaLPPHeader_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLPPHeader_oaBlock_tp_dealloc(PyoaCollection_oaLPPHeader_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLPPHeader_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLPPHeader_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLPPHeader_oaBlock value;
    int convert_status=PyoaCollection_oaLPPHeader_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaLPPHeader_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLPPHeader_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLPPHeader_oaBlock v1;
    PyParamoaCollection_oaLPPHeader_oaBlock v2;
    int convert_status1=PyoaCollection_oaLPPHeader_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLPPHeader_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLPPHeader_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaLPPHeader_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLPPHeader_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaLPPHeader_oaBlock*) ((PyoaCollection_oaLPPHeader_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLPPHeader_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLPPHeader_oaBlock_FromoaCollection_oaLPPHeader_oaBlock(oaCollection_oaLPPHeader_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLPPHeader_oaBlock_Type.tp_alloc(&PyoaCollection_oaLPPHeader_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLPPHeader_oaBlockObject* self = (PyoaCollection_oaLPPHeader_oaBlockObject*)bself;
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
static char oaCollection_oaLPPHeader_oaBlock_includes_doc[] = 
"Class: oaCollection_oaLPPHeader_oaBlock, Function: includes\n"
"  Paramegers: (oaLPPHeader)\n"
"    Calls: oaBoolean includes(const oaLPPHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLPPHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLPPHeader_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLPPHeader_oaBlock data;
    int convert_status=PyoaCollection_oaLPPHeader_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLPPHeader_oaBlockObject* self=(PyoaCollection_oaLPPHeader_oaBlockObject*)ob;

    PyParamoaLPPHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLPPHeader_Convert,&p1)) {
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

static char oaCollection_oaLPPHeader_oaBlock_assign_doc[] = 
"Class: oaCollection_oaLPPHeader_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLPPHeader_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLPPHeader_oaBlock data;
  int convert_status=PyoaCollection_oaLPPHeader_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLPPHeader_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLPPHeader_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLPPHeader_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLPPHeader_oaBlock_includes,METH_VARARGS,oaCollection_oaLPPHeader_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLPPHeader_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaLPPHeader_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLPPHeader_oaBlock_doc[] = 
"Class: oaCollection_oaLPPHeader_oaBlock\n"
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
"  Paramegers: (oaCollection_oaLPPHeader_oaBlock)\n"
"    Calls: oaCollection_oaLPPHeader_oaBlock(const oaCollection_oaLPPHeader_oaBlock& coll)\n"
"    Signature: oaCollection_oaLPPHeader_oaBlock||cref-oaCollection_oaLPPHeader_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLPPHeader_oaBlock)\n"
"    Calls: (const oaCollection_oaLPPHeader_oaBlock&)\n"
"    Signature: oaCollection_oaLPPHeader_oaBlock||cref-oaCollection_oaLPPHeader_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLPPHeader_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLPPHeader_oaBlock",
    sizeof(PyoaCollection_oaLPPHeader_oaBlockObject),
    0,
    (destructor)oaCollection_oaLPPHeader_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLPPHeader_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLPPHeader_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLPPHeader_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLPPHeader_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLPPHeader_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLPPHeader_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLPPHeader_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLPPHeader_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLPPHeader_oaBlock",
           (PyObject*)(&PyoaCollection_oaLPPHeader_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLPPHeader_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLPPHeader_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLPPHeader_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLPPHeader_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLPPHeader_oaLayerHeaderObject* self = (PyoaCollection_oaLPPHeader_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLPPHeader_oaLayerHeader)
    {
        PyParamoaCollection_oaLPPHeader_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLPPHeader_oaLayerHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLPPHeader_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLPPHeader_oaLayerHeader, Choices are:\n"
        "    (oaCollection_oaLPPHeader_oaLayerHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLPPHeader_oaLayerHeader_tp_dealloc(PyoaCollection_oaLPPHeader_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLPPHeader_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLPPHeader_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLPPHeader_oaLayerHeader value;
    int convert_status=PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaLPPHeader_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLPPHeader_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLPPHeader_oaLayerHeader v1;
    PyParamoaCollection_oaLPPHeader_oaLayerHeader v2;
    int convert_status1=PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(PyObject* ob,PyParamoaCollection_oaLPPHeader_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLPPHeader_oaLayerHeader_Check(ob)) {
        result->SetData( (oaCollection_oaLPPHeader_oaLayerHeader*) ((PyoaCollection_oaLPPHeader_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLPPHeader_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLPPHeader_oaLayerHeader_FromoaCollection_oaLPPHeader_oaLayerHeader(oaCollection_oaLPPHeader_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLPPHeader_oaLayerHeader_Type.tp_alloc(&PyoaCollection_oaLPPHeader_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLPPHeader_oaLayerHeaderObject* self = (PyoaCollection_oaLPPHeader_oaLayerHeaderObject*)bself;
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
static char oaCollection_oaLPPHeader_oaLayerHeader_includes_doc[] = 
"Class: oaCollection_oaLPPHeader_oaLayerHeader, Function: includes\n"
"  Paramegers: (oaLPPHeader)\n"
"    Calls: oaBoolean includes(const oaLPPHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLPPHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLPPHeader_oaLayerHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLPPHeader_oaLayerHeader data;
    int convert_status=PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLPPHeader_oaLayerHeaderObject* self=(PyoaCollection_oaLPPHeader_oaLayerHeaderObject*)ob;

    PyParamoaLPPHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLPPHeader_Convert,&p1)) {
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

static char oaCollection_oaLPPHeader_oaLayerHeader_assign_doc[] = 
"Class: oaCollection_oaLPPHeader_oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLPPHeader_oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLPPHeader_oaLayerHeader data;
  int convert_status=PyoaCollection_oaLPPHeader_oaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLPPHeader_oaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLPPHeader_oaLayerHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLPPHeader_oaLayerHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLPPHeader_oaLayerHeader_includes,METH_VARARGS,oaCollection_oaLPPHeader_oaLayerHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLPPHeader_oaLayerHeader_tp_assign,METH_VARARGS,oaCollection_oaLPPHeader_oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLPPHeader_oaLayerHeader_doc[] = 
"Class: oaCollection_oaLPPHeader_oaLayerHeader\n"
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
"  Paramegers: (oaCollection_oaLPPHeader_oaLayerHeader)\n"
"    Calls: oaCollection_oaLPPHeader_oaLayerHeader(const oaCollection_oaLPPHeader_oaLayerHeader& coll)\n"
"    Signature: oaCollection_oaLPPHeader_oaLayerHeader||cref-oaCollection_oaLPPHeader_oaLayerHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLPPHeader_oaLayerHeader)\n"
"    Calls: (const oaCollection_oaLPPHeader_oaLayerHeader&)\n"
"    Signature: oaCollection_oaLPPHeader_oaLayerHeader||cref-oaCollection_oaLPPHeader_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLPPHeader_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLPPHeader_oaLayerHeader",
    sizeof(PyoaCollection_oaLPPHeader_oaLayerHeaderObject),
    0,
    (destructor)oaCollection_oaLPPHeader_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLPPHeader_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLPPHeader_oaLayerHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLPPHeader_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLPPHeader_oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLPPHeader_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLPPHeader_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLPPHeader_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLPPHeader_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLPPHeader_oaLayerHeader",
           (PyObject*)(&PyoaCollection_oaLPPHeader_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLPPHeader_oaLayerHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLayerArrayConstraint_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerArrayConstraint_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupCollection*)  new oaCollection_oaLayerArrayConstraint_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLayerArrayConstraint_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_dealloc(PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLayerArrayConstraint_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[75];
    sprintf(buffer,"<oaCollection_oaLayerArrayConstraint_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup v1;
    PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaLayerArrayConstraint_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaLayerArrayConstraint_oaConstraintGroup*) ((PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLayerArrayConstraint_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_FromoaCollection_oaLayerArrayConstraint_oaConstraintGroup(oaCollection_oaLayerArrayConstraint_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject*)bself;
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
static char oaCollection_oaLayerArrayConstraint_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaLayerArrayConstraint_oaConstraintGroup\n"
"  Class type oaCollection_oaLayerArrayConstraint_oaConstraintGroup\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)\n"
"    Calls: oaCollection_oaLayerArrayConstraint_oaConstraintGroup(const oaCollection_oaLayerArrayConstraint_oaConstraintGroup& c)\n"
"    Signature: oaCollection_oaLayerArrayConstraint_oaConstraintGroup||cref-oaCollection_oaLayerArrayConstraint_oaConstraintGroup,\n"
"    Constructor oaCollection_oaLayerArrayConstraint_oaConstraintGroup\n"
"  Paramegers: (oaCollection_oaLayerArrayConstraint_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaLayerArrayConstraint_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaLayerArrayConstraint_oaConstraintGroup||cref-oaCollection_oaLayerArrayConstraint_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLayerArrayConstraint_oaConstraintGroup",
    sizeof(PyoaCollection_oaLayerArrayConstraint_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLayerArrayConstraint_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLayerArrayConstraint_oaConstraintGroup_doc,	/* tp_doc */
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
    oaCollection_oaLayerArrayConstraint_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLayerArrayConstraint_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLayerArrayConstraint_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaLayerArrayConstraint_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLayerArrayConstraint_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLayerConstraint_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerConstraint_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLayerConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerConstraint_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupCollection*)  new oaCollection_oaLayerConstraint_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLayerConstraint_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaLayerConstraint_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLayerConstraint_oaConstraintGroup_tp_dealloc(PyoaCollection_oaLayerConstraint_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLayerConstraint_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerConstraint_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLayerConstraint_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[70];
    sprintf(buffer,"<oaCollection_oaLayerConstraint_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLayerConstraint_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLayerConstraint_oaConstraintGroup v1;
    PyParamoaCollection_oaLayerConstraint_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLayerConstraint_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaLayerConstraint_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLayerConstraint_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaLayerConstraint_oaConstraintGroup*) ((PyoaCollection_oaLayerConstraint_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLayerConstraint_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLayerConstraint_oaConstraintGroup_FromoaCollection_oaLayerConstraint_oaConstraintGroup(oaCollection_oaLayerConstraint_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLayerConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerConstraint_oaConstraintGroupObject*)bself;
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
static char oaCollection_oaLayerConstraint_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaLayerConstraint_oaConstraintGroup\n"
"  Class type oaCollection_oaLayerConstraint_oaConstraintGroup\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerConstraint_oaConstraintGroup)\n"
"    Calls: oaCollection_oaLayerConstraint_oaConstraintGroup(const oaCollection_oaLayerConstraint_oaConstraintGroup& c)\n"
"    Signature: oaCollection_oaLayerConstraint_oaConstraintGroup||cref-oaCollection_oaLayerConstraint_oaConstraintGroup,\n"
"    Constructor oaCollection_oaLayerConstraint_oaConstraintGroup\n"
"  Paramegers: (oaCollection_oaLayerConstraint_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaLayerConstraint_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaLayerConstraint_oaConstraintGroup||cref-oaCollection_oaLayerConstraint_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLayerConstraint_oaConstraintGroup",
    sizeof(PyoaCollection_oaLayerConstraint_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaLayerConstraint_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLayerConstraint_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLayerConstraint_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLayerConstraint_oaConstraintGroup_doc,	/* tp_doc */
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
    oaCollection_oaLayerConstraint_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLayerConstraint_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLayerConstraint_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLayerConstraint_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaLayerConstraint_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLayerConstraint_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLayerHeader_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerHeader_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLayerHeader_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLayerHeader_oaBlockObject* self = (PyoaCollection_oaLayerHeader_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerHeader_oaBlock)
    {
        PyParamoaCollection_oaLayerHeader_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerHeader_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLayerHeader_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLayerHeader_oaBlock, Choices are:\n"
        "    (oaCollection_oaLayerHeader_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLayerHeader_oaBlock_tp_dealloc(PyoaCollection_oaLayerHeader_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLayerHeader_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerHeader_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLayerHeader_oaBlock value;
    int convert_status=PyoaCollection_oaLayerHeader_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaLayerHeader_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLayerHeader_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLayerHeader_oaBlock v1;
    PyParamoaCollection_oaLayerHeader_oaBlock v2;
    int convert_status1=PyoaCollection_oaLayerHeader_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLayerHeader_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLayerHeader_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaLayerHeader_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLayerHeader_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaLayerHeader_oaBlock*) ((PyoaCollection_oaLayerHeader_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLayerHeader_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLayerHeader_oaBlock_FromoaCollection_oaLayerHeader_oaBlock(oaCollection_oaLayerHeader_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLayerHeader_oaBlock_Type.tp_alloc(&PyoaCollection_oaLayerHeader_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLayerHeader_oaBlockObject* self = (PyoaCollection_oaLayerHeader_oaBlockObject*)bself;
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
static char oaCollection_oaLayerHeader_oaBlock_includes_doc[] = 
"Class: oaCollection_oaLayerHeader_oaBlock, Function: includes\n"
"  Paramegers: (oaLayerHeader)\n"
"    Calls: oaBoolean includes(const oaLayerHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLayerHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLayerHeader_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLayerHeader_oaBlock data;
    int convert_status=PyoaCollection_oaLayerHeader_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLayerHeader_oaBlockObject* self=(PyoaCollection_oaLayerHeader_oaBlockObject*)ob;

    PyParamoaLayerHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerHeader_Convert,&p1)) {
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

static char oaCollection_oaLayerHeader_oaBlock_assign_doc[] = 
"Class: oaCollection_oaLayerHeader_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLayerHeader_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLayerHeader_oaBlock data;
  int convert_status=PyoaCollection_oaLayerHeader_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLayerHeader_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLayerHeader_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLayerHeader_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLayerHeader_oaBlock_includes,METH_VARARGS,oaCollection_oaLayerHeader_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLayerHeader_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaLayerHeader_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLayerHeader_oaBlock_doc[] = 
"Class: oaCollection_oaLayerHeader_oaBlock\n"
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
"  Paramegers: (oaCollection_oaLayerHeader_oaBlock)\n"
"    Calls: oaCollection_oaLayerHeader_oaBlock(const oaCollection_oaLayerHeader_oaBlock& coll)\n"
"    Signature: oaCollection_oaLayerHeader_oaBlock||cref-oaCollection_oaLayerHeader_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLayerHeader_oaBlock)\n"
"    Calls: (const oaCollection_oaLayerHeader_oaBlock&)\n"
"    Signature: oaCollection_oaLayerHeader_oaBlock||cref-oaCollection_oaLayerHeader_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLayerHeader_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLayerHeader_oaBlock",
    sizeof(PyoaCollection_oaLayerHeader_oaBlockObject),
    0,
    (destructor)oaCollection_oaLayerHeader_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLayerHeader_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLayerHeader_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLayerHeader_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLayerHeader_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLayerHeader_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLayerHeader_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLayerHeader_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLayerHeader_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLayerHeader_oaBlock",
           (PyObject*)(&PyoaCollection_oaLayerHeader_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLayerHeader_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLayerPairConstraint_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerPairConstraint_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayerPairConstraint_oaConstraintGroup)
    {
        PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert,&p1)) {
            self->value = (oaConstraintInGroupCollection*)  new oaCollection_oaLayerPairConstraint_oaConstraintGroup(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLayerPairConstraint_oaConstraintGroup, Choices are:\n"
        "    (oaCollection_oaLayerPairConstraint_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_dealloc(PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLayerPairConstraint_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup value;
    int convert_status=PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[74];
    sprintf(buffer,"<oaCollection_oaLayerPairConstraint_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup v1;
    PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup v2;
    int convert_status1=PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Convert(PyObject* ob,PyParamoaCollection_oaLayerPairConstraint_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaCollection_oaLayerPairConstraint_oaConstraintGroup*) ((PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLayerPairConstraint_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_FromoaCollection_oaLayerPairConstraint_oaConstraintGroup(oaCollection_oaLayerPairConstraint_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type.tp_alloc(&PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject* self = (PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject*)bself;
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
static char oaCollection_oaLayerPairConstraint_oaConstraintGroup_doc[] = 
"Class: oaCollection_oaLayerPairConstraint_oaConstraintGroup\n"
"  Class type oaCollection_oaLayerPairConstraint_oaConstraintGroup\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaLayerPairConstraint_oaConstraintGroup)\n"
"    Calls: oaCollection_oaLayerPairConstraint_oaConstraintGroup(const oaCollection_oaLayerPairConstraint_oaConstraintGroup& c)\n"
"    Signature: oaCollection_oaLayerPairConstraint_oaConstraintGroup||cref-oaCollection_oaLayerPairConstraint_oaConstraintGroup,\n"
"    Constructor oaCollection_oaLayerPairConstraint_oaConstraintGroup\n"
"  Paramegers: (oaCollection_oaLayerPairConstraint_oaConstraintGroup)\n"
"    Calls: (const oaCollection_oaLayerPairConstraint_oaConstraintGroup&)\n"
"    Signature: oaCollection_oaLayerPairConstraint_oaConstraintGroup||cref-oaCollection_oaLayerPairConstraint_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLayerPairConstraint_oaConstraintGroup",
    sizeof(PyoaCollection_oaLayerPairConstraint_oaConstraintGroupObject),
    0,
    (destructor)oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLayerPairConstraint_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLayerPairConstraint_oaConstraintGroup_doc,	/* tp_doc */
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
    oaCollection_oaLayerPairConstraint_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLayerPairConstraint_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLayerPairConstraint_oaConstraintGroup",
           (PyObject*)(&PyoaCollection_oaLayerPairConstraint_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLayerPairConstraint_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLayer_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayer_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLayer_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLayer_oaTechObject* self = (PyoaCollection_oaLayer_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLayer_oaTech)
    {
        PyParamoaCollection_oaLayer_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLayer_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLayer_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLayer_oaTech, Choices are:\n"
        "    (oaCollection_oaLayer_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLayer_oaTech_tp_dealloc(PyoaCollection_oaLayer_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLayer_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLayer_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLayer_oaTech value;
    int convert_status=PyoaCollection_oaLayer_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaLayer_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLayer_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLayer_oaTech v1;
    PyParamoaCollection_oaLayer_oaTech v2;
    int convert_status1=PyoaCollection_oaLayer_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLayer_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLayer_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaLayer_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLayer_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaLayer_oaTech*) ((PyoaCollection_oaLayer_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLayer_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLayer_oaTech_FromoaCollection_oaLayer_oaTech(oaCollection_oaLayer_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLayer_oaTech_Type.tp_alloc(&PyoaCollection_oaLayer_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLayer_oaTechObject* self = (PyoaCollection_oaLayer_oaTechObject*)bself;
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
static char oaCollection_oaLayer_oaTech_includes_doc[] = 
"Class: oaCollection_oaLayer_oaTech, Function: includes\n"
"  Paramegers: (oaLayer)\n"
"    Calls: oaBoolean includes(const oaLayer* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLayer,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLayer_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLayer_oaTech data;
    int convert_status=PyoaCollection_oaLayer_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLayer_oaTechObject* self=(PyoaCollection_oaLayer_oaTechObject*)ob;

    PyParamoaLayer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayer_Convert,&p1)) {
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

static char oaCollection_oaLayer_oaTech_assign_doc[] = 
"Class: oaCollection_oaLayer_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLayer_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLayer_oaTech data;
  int convert_status=PyoaCollection_oaLayer_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLayer_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLayer_oaTech_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLayer_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLayer_oaTech_includes,METH_VARARGS,oaCollection_oaLayer_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLayer_oaTech_tp_assign,METH_VARARGS,oaCollection_oaLayer_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLayer_oaTech_doc[] = 
"Class: oaCollection_oaLayer_oaTech\n"
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
"  Paramegers: (oaCollection_oaLayer_oaTech)\n"
"    Calls: oaCollection_oaLayer_oaTech(const oaCollection_oaLayer_oaTech& coll)\n"
"    Signature: oaCollection_oaLayer_oaTech||cref-oaCollection_oaLayer_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLayer_oaTech)\n"
"    Calls: (const oaCollection_oaLayer_oaTech&)\n"
"    Signature: oaCollection_oaLayer_oaTech||cref-oaCollection_oaLayer_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLayer_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLayer_oaTech",
    sizeof(PyoaCollection_oaLayer_oaTechObject),
    0,
    (destructor)oaCollection_oaLayer_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLayer_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLayer_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLayer_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLayer_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLayer_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLayer_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLayer_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLayer_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLayer_oaTech",
           (PyObject*)(&PyoaCollection_oaLayer_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLayer_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLibDefListMem_oaLibDefList
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLibDefListMem_oaLibDefList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLibDefListMem_oaLibDefList_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLibDefListMem_oaLibDefListObject* self = (PyoaCollection_oaLibDefListMem_oaLibDefListObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLibDefListMem_oaLibDefList)
    {
        PyParamoaCollection_oaLibDefListMem_oaLibDefList p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLibDefListMem_oaLibDefList_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLibDefListMem_oaLibDefList(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLibDefListMem_oaLibDefList, Choices are:\n"
        "    (oaCollection_oaLibDefListMem_oaLibDefList)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLibDefListMem_oaLibDefList_tp_dealloc(PyoaCollection_oaLibDefListMem_oaLibDefListObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLibDefListMem_oaLibDefList*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLibDefListMem_oaLibDefList_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLibDefListMem_oaLibDefList value;
    int convert_status=PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaLibDefListMem_oaLibDefList::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLibDefListMem_oaLibDefList_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLibDefListMem_oaLibDefList v1;
    PyParamoaCollection_oaLibDefListMem_oaLibDefList v2;
    int convert_status1=PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(PyObject* ob,PyParamoaCollection_oaLibDefListMem_oaLibDefList* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLibDefListMem_oaLibDefList_Check(ob)) {
        result->SetData( (oaCollection_oaLibDefListMem_oaLibDefList*) ((PyoaCollection_oaLibDefListMem_oaLibDefListObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLibDefListMem_oaLibDefList Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLibDefListMem_oaLibDefList_FromoaCollection_oaLibDefListMem_oaLibDefList(oaCollection_oaLibDefListMem_oaLibDefList* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLibDefListMem_oaLibDefList_Type.tp_alloc(&PyoaCollection_oaLibDefListMem_oaLibDefList_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLibDefListMem_oaLibDefListObject* self = (PyoaCollection_oaLibDefListMem_oaLibDefListObject*)bself;
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
static char oaCollection_oaLibDefListMem_oaLibDefList_includes_doc[] = 
"Class: oaCollection_oaLibDefListMem_oaLibDefList, Function: includes\n"
"  Paramegers: (oaLibDefListMem)\n"
"    Calls: oaBoolean includes(const oaLibDefListMem* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLibDefListMem,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLibDefListMem_oaLibDefList_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLibDefListMem_oaLibDefList data;
    int convert_status=PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLibDefListMem_oaLibDefListObject* self=(PyoaCollection_oaLibDefListMem_oaLibDefListObject*)ob;

    PyParamoaLibDefListMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefListMem_Convert,&p1)) {
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

static char oaCollection_oaLibDefListMem_oaLibDefList_assign_doc[] = 
"Class: oaCollection_oaLibDefListMem_oaLibDefList, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLibDefListMem_oaLibDefList_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLibDefListMem_oaLibDefList data;
  int convert_status=PyoaCollection_oaLibDefListMem_oaLibDefList_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLibDefListMem_oaLibDefList p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLibDefListMem_oaLibDefList_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLibDefListMem_oaLibDefList_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLibDefListMem_oaLibDefList_includes,METH_VARARGS,oaCollection_oaLibDefListMem_oaLibDefList_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLibDefListMem_oaLibDefList_tp_assign,METH_VARARGS,oaCollection_oaLibDefListMem_oaLibDefList_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLibDefListMem_oaLibDefList_doc[] = 
"Class: oaCollection_oaLibDefListMem_oaLibDefList\n"
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
"  Paramegers: (oaCollection_oaLibDefListMem_oaLibDefList)\n"
"    Calls: oaCollection_oaLibDefListMem_oaLibDefList(const oaCollection_oaLibDefListMem_oaLibDefList& coll)\n"
"    Signature: oaCollection_oaLibDefListMem_oaLibDefList||cref-oaCollection_oaLibDefListMem_oaLibDefList,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLibDefListMem_oaLibDefList)\n"
"    Calls: (const oaCollection_oaLibDefListMem_oaLibDefList&)\n"
"    Signature: oaCollection_oaLibDefListMem_oaLibDefList||cref-oaCollection_oaLibDefListMem_oaLibDefList,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLibDefListMem_oaLibDefList_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLibDefListMem_oaLibDefList",
    sizeof(PyoaCollection_oaLibDefListMem_oaLibDefListObject),
    0,
    (destructor)oaCollection_oaLibDefListMem_oaLibDefList_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLibDefListMem_oaLibDefList_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLibDefListMem_oaLibDefList_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLibDefListMem_oaLibDefList_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLibDefListMem_oaLibDefList_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLibDefListMem_oaLibDefList_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLibDefListMem_oaLibDefList_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLibDefListMem_oaLibDefList_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLibDefListMem_oaLibDefList\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLibDefListMem_oaLibDefList",
           (PyObject*)(&PyoaCollection_oaLibDefListMem_oaLibDefList_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLibDefListMem_oaLibDefList\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLibDefList_oaLibDefList
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLibDefList_oaLibDefList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLibDefList_oaLibDefList_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLibDefList_oaLibDefListObject* self = (PyoaCollection_oaLibDefList_oaLibDefListObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaLibDefList_oaLibDefList)
    {
        PyParamoaCollection_oaLibDefList_oaLibDefList p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLibDefList_oaLibDefList_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaLibDefList_oaLibDefList(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLibDefList_oaLibDefList, Choices are:\n"
        "    (oaCollection_oaLibDefList_oaLibDefList)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLibDefList_oaLibDefList_tp_dealloc(PyoaCollection_oaLibDefList_oaLibDefListObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLibDefList_oaLibDefList*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLibDefList_oaLibDefList_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLibDefList_oaLibDefList value;
    int convert_status=PyoaCollection_oaLibDefList_oaLibDefList_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaLibDefList_oaLibDefList::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLibDefList_oaLibDefList_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLibDefList_oaLibDefList v1;
    PyParamoaCollection_oaLibDefList_oaLibDefList v2;
    int convert_status1=PyoaCollection_oaLibDefList_oaLibDefList_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLibDefList_oaLibDefList_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLibDefList_oaLibDefList_Convert(PyObject* ob,PyParamoaCollection_oaLibDefList_oaLibDefList* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLibDefList_oaLibDefList_Check(ob)) {
        result->SetData( (oaCollection_oaLibDefList_oaLibDefList*) ((PyoaCollection_oaLibDefList_oaLibDefListObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLibDefList_oaLibDefList Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLibDefList_oaLibDefList_FromoaCollection_oaLibDefList_oaLibDefList(oaCollection_oaLibDefList_oaLibDefList* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLibDefList_oaLibDefList_Type.tp_alloc(&PyoaCollection_oaLibDefList_oaLibDefList_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLibDefList_oaLibDefListObject* self = (PyoaCollection_oaLibDefList_oaLibDefListObject*)bself;
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
static char oaCollection_oaLibDefList_oaLibDefList_includes_doc[] = 
"Class: oaCollection_oaLibDefList_oaLibDefList, Function: includes\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: oaBoolean includes(const oaLibDefList* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLibDefList,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaLibDefList_oaLibDefList_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLibDefList_oaLibDefList data;
    int convert_status=PyoaCollection_oaLibDefList_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLibDefList_oaLibDefListObject* self=(PyoaCollection_oaLibDefList_oaLibDefListObject*)ob;

    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefList_Convert,&p1)) {
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

static char oaCollection_oaLibDefList_oaLibDefList_assign_doc[] = 
"Class: oaCollection_oaLibDefList_oaLibDefList, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLibDefList_oaLibDefList_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLibDefList_oaLibDefList data;
  int convert_status=PyoaCollection_oaLibDefList_oaLibDefList_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLibDefList_oaLibDefList p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLibDefList_oaLibDefList_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLibDefList_oaLibDefList_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLibDefList_oaLibDefList_includes,METH_VARARGS,oaCollection_oaLibDefList_oaLibDefList_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLibDefList_oaLibDefList_tp_assign,METH_VARARGS,oaCollection_oaLibDefList_oaLibDefList_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLibDefList_oaLibDefList_doc[] = 
"Class: oaCollection_oaLibDefList_oaLibDefList\n"
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
"  Paramegers: (oaCollection_oaLibDefList_oaLibDefList)\n"
"    Calls: oaCollection_oaLibDefList_oaLibDefList(const oaCollection_oaLibDefList_oaLibDefList& coll)\n"
"    Signature: oaCollection_oaLibDefList_oaLibDefList||cref-oaCollection_oaLibDefList_oaLibDefList,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaLibDefList_oaLibDefList)\n"
"    Calls: (const oaCollection_oaLibDefList_oaLibDefList&)\n"
"    Signature: oaCollection_oaLibDefList_oaLibDefList||cref-oaCollection_oaLibDefList_oaLibDefList,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLibDefList_oaLibDefList_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLibDefList_oaLibDefList",
    sizeof(PyoaCollection_oaLibDefList_oaLibDefListObject),
    0,
    (destructor)oaCollection_oaLibDefList_oaLibDefList_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLibDefList_oaLibDefList_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLibDefList_oaLibDefList_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLibDefList_oaLibDefList_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLibDefList_oaLibDefList_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLibDefList_oaLibDefList_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLibDefList_oaLibDefList_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLibDefList_oaLibDefList_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLibDefList_oaLibDefList\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLibDefList_oaLibDefList",
           (PyObject*)(&PyoaCollection_oaLibDefList_oaLibDefList_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLibDefList_oaLibDefList\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaLib_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLib_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaLib_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaLib_oaLibObject* self = (PyoaCollection_oaLib_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaLib_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCollection_oaLib_oaLib)
    {
        PyParamoaCollection_oaLib_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaLib_oaLib_Convert,&p1)) {
            self->value = (oaDatabaseCollection*)  new oaCollection_oaLib_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaLib_oaLib, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaCollection_oaLib_oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaLib_oaLib_tp_dealloc(PyoaCollection_oaLib_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaLib_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaLib_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaLib_oaLib value;
    int convert_status=PyoaCollection_oaLib_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaCollection_oaLib_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaLib_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaLib_oaLib v1;
    PyParamoaCollection_oaLib_oaLib v2;
    int convert_status1=PyoaCollection_oaLib_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaLib_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaLib_oaLib_Convert(PyObject* ob,PyParamoaCollection_oaLib_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaLib_oaLib_Check(ob)) {
        result->SetData( (oaCollection_oaLib_oaLib*) ((PyoaCollection_oaLib_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaLib_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaLib_oaLib_FromoaCollection_oaLib_oaLib(oaCollection_oaLib_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaLib_oaLib_Type.tp_alloc(&PyoaCollection_oaLib_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaLib_oaLibObject* self = (PyoaCollection_oaLib_oaLibObject*)bself;
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
static char oaCollection_oaLib_oaLib_includes_doc[] = 
"Class: oaCollection_oaLib_oaLib, Function: includes\n"
"  Paramegers: (oaLib)\n"
"    Calls: oaBoolean includes(const oaLib* db) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaLib,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaLib_oaLib_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaLib_oaLib data;
    int convert_status=PyoaCollection_oaLib_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaLib_oaLibObject* self=(PyoaCollection_oaLib_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
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

static char oaCollection_oaLib_oaLib_assign_doc[] = 
"Class: oaCollection_oaLib_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaLib_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaLib_oaLib data;
  int convert_status=PyoaCollection_oaLib_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaLib_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaLib_oaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaLib_oaLib_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaLib_oaLib_includes,METH_VARARGS,oaCollection_oaLib_oaLib_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaLib_oaLib_tp_assign,METH_VARARGS,oaCollection_oaLib_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaLib_oaLib_doc[] = 
"Class: oaCollection_oaLib_oaLib\n"
"  Class type oaCollection_oaLib_oaLib\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaLib_oaLib(oaUInt4 dbIDIn)\n"
"    Signature: oaCollection_oaLib_oaLib||simple-oaUInt4,\n"
"    Constructor oaCollection_oaLib_oaLib\n"
"  Paramegers: (oaCollection_oaLib_oaLib)\n"
"    Calls: oaCollection_oaLib_oaLib(const oaCollection_oaLib_oaLib& c)\n"
"    Signature: oaCollection_oaLib_oaLib||cref-oaCollection_oaLib_oaLib,\n"
"    Constructor oaCollection_oaLib_oaLib\n"
"  Paramegers: (oaCollection_oaLib_oaLib)\n"
"    Calls: (const oaCollection_oaLib_oaLib&)\n"
"    Signature: oaCollection_oaLib_oaLib||cref-oaCollection_oaLib_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaLib_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaLib_oaLib",
    sizeof(PyoaCollection_oaLib_oaLibObject),
    0,
    (destructor)oaCollection_oaLib_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaLib_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaLib_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaLib_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaLib_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDatabaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaLib_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaLib_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaLib_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaLib_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaLib_oaLib",
           (PyObject*)(&PyoaCollection_oaLib_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaLib_oaLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaMarker_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMarker_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaMarker_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaMarker_oaBlockObject* self = (PyoaCollection_oaMarker_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaMarker_oaBlock)
    {
        PyParamoaCollection_oaMarker_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaMarker_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaMarker_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaMarker_oaBlock, Choices are:\n"
        "    (oaCollection_oaMarker_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaMarker_oaBlock_tp_dealloc(PyoaCollection_oaMarker_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaMarker_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMarker_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaMarker_oaBlock value;
    int convert_status=PyoaCollection_oaMarker_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaMarker_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaMarker_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaMarker_oaBlock v1;
    PyParamoaCollection_oaMarker_oaBlock v2;
    int convert_status1=PyoaCollection_oaMarker_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaMarker_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaMarker_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaMarker_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaMarker_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaMarker_oaBlock*) ((PyoaCollection_oaMarker_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaMarker_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaMarker_oaBlock_FromoaCollection_oaMarker_oaBlock(oaCollection_oaMarker_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaMarker_oaBlock_Type.tp_alloc(&PyoaCollection_oaMarker_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaMarker_oaBlockObject* self = (PyoaCollection_oaMarker_oaBlockObject*)bself;
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
static char oaCollection_oaMarker_oaBlock_includes_doc[] = 
"Class: oaCollection_oaMarker_oaBlock, Function: includes\n"
"  Paramegers: (oaMarker)\n"
"    Calls: oaBoolean includes(const oaMarker* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaMarker,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaMarker_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaMarker_oaBlock data;
    int convert_status=PyoaCollection_oaMarker_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaMarker_oaBlockObject* self=(PyoaCollection_oaMarker_oaBlockObject*)ob;

    PyParamoaMarker p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMarker_Convert,&p1)) {
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

static char oaCollection_oaMarker_oaBlock_assign_doc[] = 
"Class: oaCollection_oaMarker_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaMarker_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaMarker_oaBlock data;
  int convert_status=PyoaCollection_oaMarker_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaMarker_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaMarker_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaMarker_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaMarker_oaBlock_includes,METH_VARARGS,oaCollection_oaMarker_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaMarker_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaMarker_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaMarker_oaBlock_doc[] = 
"Class: oaCollection_oaMarker_oaBlock\n"
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
"  Paramegers: (oaCollection_oaMarker_oaBlock)\n"
"    Calls: oaCollection_oaMarker_oaBlock(const oaCollection_oaMarker_oaBlock& coll)\n"
"    Signature: oaCollection_oaMarker_oaBlock||cref-oaCollection_oaMarker_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaMarker_oaBlock)\n"
"    Calls: (const oaCollection_oaMarker_oaBlock&)\n"
"    Signature: oaCollection_oaMarker_oaBlock||cref-oaCollection_oaMarker_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaMarker_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaMarker_oaBlock",
    sizeof(PyoaCollection_oaMarker_oaBlockObject),
    0,
    (destructor)oaCollection_oaMarker_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaMarker_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaMarker_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaMarker_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaMarker_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaMarker_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaMarker_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaMarker_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaMarker_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaMarker_oaBlock",
           (PyObject*)(&PyoaCollection_oaMarker_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaMarker_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaMarker_oaBlockObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMarker_oaBlockObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaMarker_oaBlockObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaMarker_oaBlockObjectObject* self = (PyoaCollection_oaMarker_oaBlockObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaMarker_oaBlockObject)
    {
        PyParamoaCollection_oaMarker_oaBlockObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaMarker_oaBlockObject_Convert,&p1)) {
            self->value =  new oaCollection_oaMarker_oaBlockObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaMarker_oaBlockObject, Choices are:\n"
        "    (oaCollection_oaMarker_oaBlockObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaMarker_oaBlockObject_tp_dealloc(PyoaCollection_oaMarker_oaBlockObjectObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaMarker_oaBlockObject_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaMarker_oaBlockObject value;
    int convert_status=PyoaCollection_oaMarker_oaBlockObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaMarker_oaBlockObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaMarker_oaBlockObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaMarker_oaBlockObject v1;
    PyParamoaCollection_oaMarker_oaBlockObject v2;
    int convert_status1=PyoaCollection_oaMarker_oaBlockObject_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaMarker_oaBlockObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaMarker_oaBlockObject_Convert(PyObject* ob,PyParamoaCollection_oaMarker_oaBlockObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaMarker_oaBlockObject_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaMarker_oaBlockObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaMarker_oaBlockObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaMarker_oaBlockObject_FromoaCollection_oaMarker_oaBlockObject(oaCollection_oaMarker_oaBlockObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaMarker_oaBlockObject_Type.tp_alloc(&PyoaCollection_oaMarker_oaBlockObject_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaMarker_oaBlockObjectObject* self = (PyoaCollection_oaMarker_oaBlockObjectObject*)bself;
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
static char oaCollection_oaMarker_oaBlockObject_getCount_doc[] = 
"Class: oaCollection_oaMarker_oaBlockObject, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaMarker_oaBlockObject_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaMarker_oaBlockObject data;
    int convert_status=PyoaCollection_oaMarker_oaBlockObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaMarker_oaBlockObjectObject* self=(PyoaCollection_oaMarker_oaBlockObjectObject*)ob;

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
static char oaCollection_oaMarker_oaBlockObject_includes_doc[] = 
"Class: oaCollection_oaMarker_oaBlockObject, Function: includes\n"
"  Paramegers: (oaMarker)\n"
"    Calls: oaBoolean includes(const oaMarker* marker) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaMarker,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaMarker_oaBlockObject_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaMarker_oaBlockObject data;
    int convert_status=PyoaCollection_oaMarker_oaBlockObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaMarker_oaBlockObjectObject* self=(PyoaCollection_oaMarker_oaBlockObjectObject*)ob;

    PyParamoaMarker p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMarker_Convert,&p1)) {
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
static char oaCollection_oaMarker_oaBlockObject_isEmpty_doc[] = 
"Class: oaCollection_oaMarker_oaBlockObject, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaMarker_oaBlockObject_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaMarker_oaBlockObject data;
    int convert_status=PyoaCollection_oaMarker_oaBlockObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaMarker_oaBlockObjectObject* self=(PyoaCollection_oaMarker_oaBlockObjectObject*)ob;

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

static char oaCollection_oaMarker_oaBlockObject_assign_doc[] = 
"Class: oaCollection_oaMarker_oaBlockObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaMarker_oaBlockObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaMarker_oaBlockObject data;
  int convert_status=PyoaCollection_oaMarker_oaBlockObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaMarker_oaBlockObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaMarker_oaBlockObject_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaMarker_oaBlockObject_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaMarker_oaBlockObject_getCount,METH_VARARGS,oaCollection_oaMarker_oaBlockObject_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaMarker_oaBlockObject_includes,METH_VARARGS,oaCollection_oaMarker_oaBlockObject_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaMarker_oaBlockObject_isEmpty,METH_VARARGS,oaCollection_oaMarker_oaBlockObject_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaMarker_oaBlockObject_tp_assign,METH_VARARGS,oaCollection_oaMarker_oaBlockObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaMarker_oaBlockObject_doc[] = 
"Class: oaCollection_oaMarker_oaBlockObject\n"
"  Class type oaCollection_oaMarker_oaBlockObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaMarker_oaBlockObject)\n"
"    Calls: oaCollection_oaMarker_oaBlockObject(const oaCollection_oaMarker_oaBlockObject& c)\n"
"    Signature: oaCollection_oaMarker_oaBlockObject||cref-oaCollection_oaMarker_oaBlockObject,\n"
"    Constructor oaCollection_oaMarker_oaBlockObject\n"
"  Paramegers: (oaCollection_oaMarker_oaBlockObject)\n"
"    Calls: (const oaCollection_oaMarker_oaBlockObject&)\n"
"    Signature: oaCollection_oaMarker_oaBlockObject||cref-oaCollection_oaMarker_oaBlockObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaMarker_oaBlockObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaMarker_oaBlockObject",
    sizeof(PyoaCollection_oaMarker_oaBlockObjectObject),
    0,
    (destructor)oaCollection_oaMarker_oaBlockObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaMarker_oaBlockObject_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaMarker_oaBlockObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaMarker_oaBlockObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaMarker_oaBlockObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaMarker_oaBlockObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaMarker_oaBlockObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaMarker_oaBlockObject_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaMarker_oaBlockObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaMarker_oaBlockObject",
           (PyObject*)(&PyoaCollection_oaMarker_oaBlockObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaMarker_oaBlockObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModAssignment_oaModInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModAssignment_oaModInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModAssignment_oaModInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModAssignment_oaModInstObject* self = (PyoaCollection_oaModAssignment_oaModInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModAssignment_oaModInst)
    {
        PyParamoaCollection_oaModAssignment_oaModInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModAssignment_oaModInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModAssignment_oaModInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModAssignment_oaModInst, Choices are:\n"
        "    (oaCollection_oaModAssignment_oaModInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModAssignment_oaModInst_tp_dealloc(PyoaCollection_oaModAssignment_oaModInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModAssignment_oaModInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModAssignment_oaModInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModAssignment_oaModInst value;
    int convert_status=PyoaCollection_oaModAssignment_oaModInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaModAssignment_oaModInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModAssignment_oaModInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModAssignment_oaModInst v1;
    PyParamoaCollection_oaModAssignment_oaModInst v2;
    int convert_status1=PyoaCollection_oaModAssignment_oaModInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModAssignment_oaModInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModAssignment_oaModInst_Convert(PyObject* ob,PyParamoaCollection_oaModAssignment_oaModInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModAssignment_oaModInst_Check(ob)) {
        result->SetData( (oaCollection_oaModAssignment_oaModInst*) ((PyoaCollection_oaModAssignment_oaModInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModAssignment_oaModInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModAssignment_oaModInst_FromoaCollection_oaModAssignment_oaModInst(oaCollection_oaModAssignment_oaModInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModAssignment_oaModInst_Type.tp_alloc(&PyoaCollection_oaModAssignment_oaModInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModAssignment_oaModInstObject* self = (PyoaCollection_oaModAssignment_oaModInstObject*)bself;
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
static char oaCollection_oaModAssignment_oaModInst_includes_doc[] = 
"Class: oaCollection_oaModAssignment_oaModInst, Function: includes\n"
"  Paramegers: (oaModAssignment)\n"
"    Calls: oaBoolean includes(const oaModAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModAssignment_oaModInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModAssignment_oaModInst data;
    int convert_status=PyoaCollection_oaModAssignment_oaModInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModAssignment_oaModInstObject* self=(PyoaCollection_oaModAssignment_oaModInstObject*)ob;

    PyParamoaModAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModAssignment_Convert,&p1)) {
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

static char oaCollection_oaModAssignment_oaModInst_assign_doc[] = 
"Class: oaCollection_oaModAssignment_oaModInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModAssignment_oaModInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModAssignment_oaModInst data;
  int convert_status=PyoaCollection_oaModAssignment_oaModInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModAssignment_oaModInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModAssignment_oaModInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModAssignment_oaModInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModAssignment_oaModInst_includes,METH_VARARGS,oaCollection_oaModAssignment_oaModInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModAssignment_oaModInst_tp_assign,METH_VARARGS,oaCollection_oaModAssignment_oaModInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModAssignment_oaModInst_doc[] = 
"Class: oaCollection_oaModAssignment_oaModInst\n"
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
"  Paramegers: (oaCollection_oaModAssignment_oaModInst)\n"
"    Calls: oaCollection_oaModAssignment_oaModInst(const oaCollection_oaModAssignment_oaModInst& coll)\n"
"    Signature: oaCollection_oaModAssignment_oaModInst||cref-oaCollection_oaModAssignment_oaModInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModAssignment_oaModInst)\n"
"    Calls: (const oaCollection_oaModAssignment_oaModInst&)\n"
"    Signature: oaCollection_oaModAssignment_oaModInst||cref-oaCollection_oaModAssignment_oaModInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModAssignment_oaModInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModAssignment_oaModInst",
    sizeof(PyoaCollection_oaModAssignment_oaModInstObject),
    0,
    (destructor)oaCollection_oaModAssignment_oaModInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModAssignment_oaModInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModAssignment_oaModInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModAssignment_oaModInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModAssignment_oaModInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModAssignment_oaModInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModAssignment_oaModInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModAssignment_oaModInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModAssignment_oaModInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModAssignment_oaModInst",
           (PyObject*)(&PyoaCollection_oaModAssignment_oaModInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModAssignment_oaModInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModAssignment_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModAssignment_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModAssignment_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModAssignment_oaModuleObject* self = (PyoaCollection_oaModAssignment_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModAssignment_oaModule)
    {
        PyParamoaCollection_oaModAssignment_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModAssignment_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModAssignment_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModAssignment_oaModule, Choices are:\n"
        "    (oaCollection_oaModAssignment_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModAssignment_oaModule_tp_dealloc(PyoaCollection_oaModAssignment_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModAssignment_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModAssignment_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModAssignment_oaModule value;
    int convert_status=PyoaCollection_oaModAssignment_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaModAssignment_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModAssignment_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModAssignment_oaModule v1;
    PyParamoaCollection_oaModAssignment_oaModule v2;
    int convert_status1=PyoaCollection_oaModAssignment_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModAssignment_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModAssignment_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModAssignment_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModAssignment_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModAssignment_oaModule*) ((PyoaCollection_oaModAssignment_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModAssignment_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModAssignment_oaModule_FromoaCollection_oaModAssignment_oaModule(oaCollection_oaModAssignment_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModAssignment_oaModule_Type.tp_alloc(&PyoaCollection_oaModAssignment_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModAssignment_oaModuleObject* self = (PyoaCollection_oaModAssignment_oaModuleObject*)bself;
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
static char oaCollection_oaModAssignment_oaModule_includes_doc[] = 
"Class: oaCollection_oaModAssignment_oaModule, Function: includes\n"
"  Paramegers: (oaModAssignment)\n"
"    Calls: oaBoolean includes(const oaModAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModAssignment_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModAssignment_oaModule data;
    int convert_status=PyoaCollection_oaModAssignment_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModAssignment_oaModuleObject* self=(PyoaCollection_oaModAssignment_oaModuleObject*)ob;

    PyParamoaModAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModAssignment_Convert,&p1)) {
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

static char oaCollection_oaModAssignment_oaModule_assign_doc[] = 
"Class: oaCollection_oaModAssignment_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModAssignment_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModAssignment_oaModule data;
  int convert_status=PyoaCollection_oaModAssignment_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModAssignment_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModAssignment_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModAssignment_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModAssignment_oaModule_includes,METH_VARARGS,oaCollection_oaModAssignment_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModAssignment_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModAssignment_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModAssignment_oaModule_doc[] = 
"Class: oaCollection_oaModAssignment_oaModule\n"
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
"  Paramegers: (oaCollection_oaModAssignment_oaModule)\n"
"    Calls: oaCollection_oaModAssignment_oaModule(const oaCollection_oaModAssignment_oaModule& coll)\n"
"    Signature: oaCollection_oaModAssignment_oaModule||cref-oaCollection_oaModAssignment_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModAssignment_oaModule)\n"
"    Calls: (const oaCollection_oaModAssignment_oaModule&)\n"
"    Signature: oaCollection_oaModAssignment_oaModule||cref-oaCollection_oaModAssignment_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModAssignment_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModAssignment_oaModule",
    sizeof(PyoaCollection_oaModAssignment_oaModuleObject),
    0,
    (destructor)oaCollection_oaModAssignment_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModAssignment_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModAssignment_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModAssignment_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModAssignment_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModAssignment_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModAssignment_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModAssignment_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModAssignment_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModAssignment_oaModule",
           (PyObject*)(&PyoaCollection_oaModAssignment_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModAssignment_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBitNet_oaModBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBitNet_oaModBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBitNet_oaModBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBitNet_oaModBitNetObject* self = (PyoaCollection_oaModBitNet_oaModBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBitNet_oaModBitNet)
    {
        PyParamoaCollection_oaModBitNet_oaModBitNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBitNet_oaModBitNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBitNet_oaModBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBitNet_oaModBitNet, Choices are:\n"
        "    (oaCollection_oaModBitNet_oaModBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBitNet_oaModBitNet_tp_dealloc(PyoaCollection_oaModBitNet_oaModBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBitNet_oaModBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBitNet_oaModBitNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBitNet_oaModBitNet value;
    int convert_status=PyoaCollection_oaModBitNet_oaModBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaModBitNet_oaModBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBitNet_oaModBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBitNet_oaModBitNet v1;
    PyParamoaCollection_oaModBitNet_oaModBitNet v2;
    int convert_status1=PyoaCollection_oaModBitNet_oaModBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBitNet_oaModBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBitNet_oaModBitNet_Convert(PyObject* ob,PyParamoaCollection_oaModBitNet_oaModBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBitNet_oaModBitNet_Check(ob)) {
        result->SetData( (oaCollection_oaModBitNet_oaModBitNet*) ((PyoaCollection_oaModBitNet_oaModBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBitNet_oaModBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBitNet_oaModBitNet_FromoaCollection_oaModBitNet_oaModBitNet(oaCollection_oaModBitNet_oaModBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBitNet_oaModBitNet_Type.tp_alloc(&PyoaCollection_oaModBitNet_oaModBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBitNet_oaModBitNetObject* self = (PyoaCollection_oaModBitNet_oaModBitNetObject*)bself;
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
static char oaCollection_oaModBitNet_oaModBitNet_includes_doc[] = 
"Class: oaCollection_oaModBitNet_oaModBitNet, Function: includes\n"
"  Paramegers: (oaModBitNet)\n"
"    Calls: oaBoolean includes(const oaModBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBitNet_oaModBitNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBitNet_oaModBitNet data;
    int convert_status=PyoaCollection_oaModBitNet_oaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBitNet_oaModBitNetObject* self=(PyoaCollection_oaModBitNet_oaModBitNetObject*)ob;

    PyParamoaModBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBitNet_Convert,&p1)) {
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

static char oaCollection_oaModBitNet_oaModBitNet_assign_doc[] = 
"Class: oaCollection_oaModBitNet_oaModBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBitNet_oaModBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBitNet_oaModBitNet data;
  int convert_status=PyoaCollection_oaModBitNet_oaModBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBitNet_oaModBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBitNet_oaModBitNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBitNet_oaModBitNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBitNet_oaModBitNet_includes,METH_VARARGS,oaCollection_oaModBitNet_oaModBitNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBitNet_oaModBitNet_tp_assign,METH_VARARGS,oaCollection_oaModBitNet_oaModBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBitNet_oaModBitNet_doc[] = 
"Class: oaCollection_oaModBitNet_oaModBitNet\n"
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
"  Paramegers: (oaCollection_oaModBitNet_oaModBitNet)\n"
"    Calls: oaCollection_oaModBitNet_oaModBitNet(const oaCollection_oaModBitNet_oaModBitNet& coll)\n"
"    Signature: oaCollection_oaModBitNet_oaModBitNet||cref-oaCollection_oaModBitNet_oaModBitNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBitNet_oaModBitNet)\n"
"    Calls: (const oaCollection_oaModBitNet_oaModBitNet&)\n"
"    Signature: oaCollection_oaModBitNet_oaModBitNet||cref-oaCollection_oaModBitNet_oaModBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBitNet_oaModBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBitNet_oaModBitNet",
    sizeof(PyoaCollection_oaModBitNet_oaModBitNetObject),
    0,
    (destructor)oaCollection_oaModBitNet_oaModBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBitNet_oaModBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBitNet_oaModBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBitNet_oaModBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBitNet_oaModBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBitNet_oaModBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBitNet_oaModBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBitNet_oaModBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBitNet_oaModBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBitNet_oaModBitNet",
           (PyObject*)(&PyoaCollection_oaModBitNet_oaModBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBitNet_oaModBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBitNet_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBitNet_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBitNet_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBitNet_oaModNetObject* self = (PyoaCollection_oaModBitNet_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBitNet_oaModNet)
    {
        PyParamoaCollection_oaModBitNet_oaModNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBitNet_oaModNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBitNet_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBitNet_oaModNet, Choices are:\n"
        "    (oaCollection_oaModBitNet_oaModNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBitNet_oaModNet_tp_dealloc(PyoaCollection_oaModBitNet_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBitNet_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBitNet_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBitNet_oaModNet value;
    int convert_status=PyoaCollection_oaModBitNet_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaModBitNet_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBitNet_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBitNet_oaModNet v1;
    PyParamoaCollection_oaModBitNet_oaModNet v2;
    int convert_status1=PyoaCollection_oaModBitNet_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBitNet_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBitNet_oaModNet_Convert(PyObject* ob,PyParamoaCollection_oaModBitNet_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBitNet_oaModNet_Check(ob)) {
        result->SetData( (oaCollection_oaModBitNet_oaModNet*) ((PyoaCollection_oaModBitNet_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBitNet_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBitNet_oaModNet_FromoaCollection_oaModBitNet_oaModNet(oaCollection_oaModBitNet_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBitNet_oaModNet_Type.tp_alloc(&PyoaCollection_oaModBitNet_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBitNet_oaModNetObject* self = (PyoaCollection_oaModBitNet_oaModNetObject*)bself;
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
static char oaCollection_oaModBitNet_oaModNet_includes_doc[] = 
"Class: oaCollection_oaModBitNet_oaModNet, Function: includes\n"
"  Paramegers: (oaModBitNet)\n"
"    Calls: oaBoolean includes(const oaModBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBitNet_oaModNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBitNet_oaModNet data;
    int convert_status=PyoaCollection_oaModBitNet_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBitNet_oaModNetObject* self=(PyoaCollection_oaModBitNet_oaModNetObject*)ob;

    PyParamoaModBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBitNet_Convert,&p1)) {
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

static char oaCollection_oaModBitNet_oaModNet_assign_doc[] = 
"Class: oaCollection_oaModBitNet_oaModNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBitNet_oaModNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBitNet_oaModNet data;
  int convert_status=PyoaCollection_oaModBitNet_oaModNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBitNet_oaModNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBitNet_oaModNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBitNet_oaModNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBitNet_oaModNet_includes,METH_VARARGS,oaCollection_oaModBitNet_oaModNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBitNet_oaModNet_tp_assign,METH_VARARGS,oaCollection_oaModBitNet_oaModNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBitNet_oaModNet_doc[] = 
"Class: oaCollection_oaModBitNet_oaModNet\n"
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
"  Paramegers: (oaCollection_oaModBitNet_oaModNet)\n"
"    Calls: oaCollection_oaModBitNet_oaModNet(const oaCollection_oaModBitNet_oaModNet& coll)\n"
"    Signature: oaCollection_oaModBitNet_oaModNet||cref-oaCollection_oaModBitNet_oaModNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBitNet_oaModNet)\n"
"    Calls: (const oaCollection_oaModBitNet_oaModNet&)\n"
"    Signature: oaCollection_oaModBitNet_oaModNet||cref-oaCollection_oaModBitNet_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBitNet_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBitNet_oaModNet",
    sizeof(PyoaCollection_oaModBitNet_oaModNetObject),
    0,
    (destructor)oaCollection_oaModBitNet_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBitNet_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBitNet_oaModNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBitNet_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBitNet_oaModNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBitNet_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBitNet_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBitNet_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBitNet_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBitNet_oaModNet",
           (PyObject*)(&PyoaCollection_oaModBitNet_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBitNet_oaModNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusNetBit_oaModBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNetBit_oaModBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusNetBit_oaModBusNetDefObject* self = (PyoaCollection_oaModBusNetBit_oaModBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusNetBit_oaModBusNetDef)
    {
        PyParamoaCollection_oaModBusNetBit_oaModBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusNetBit_oaModBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusNetBit_oaModBusNetDef, Choices are:\n"
        "    (oaCollection_oaModBusNetBit_oaModBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusNetBit_oaModBusNetDef_tp_dealloc(PyoaCollection_oaModBusNetBit_oaModBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusNetBit_oaModBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNetBit_oaModBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusNetBit_oaModBusNetDef value;
    int convert_status=PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[64];
    sprintf(buffer,"<oaCollection_oaModBusNetBit_oaModBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusNetBit_oaModBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusNetBit_oaModBusNetDef v1;
    PyParamoaCollection_oaModBusNetBit_oaModBusNetDef v2;
    int convert_status1=PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaModBusNetBit_oaModBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusNetBit_oaModBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaModBusNetBit_oaModBusNetDef*) ((PyoaCollection_oaModBusNetBit_oaModBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusNetBit_oaModBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusNetBit_oaModBusNetDef_FromoaCollection_oaModBusNetBit_oaModBusNetDef(oaCollection_oaModBusNetBit_oaModBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type.tp_alloc(&PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusNetBit_oaModBusNetDefObject* self = (PyoaCollection_oaModBusNetBit_oaModBusNetDefObject*)bself;
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
static char oaCollection_oaModBusNetBit_oaModBusNetDef_includes_doc[] = 
"Class: oaCollection_oaModBusNetBit_oaModBusNetDef, Function: includes\n"
"  Paramegers: (oaModBusNetBit)\n"
"    Calls: oaBoolean includes(const oaModBusNetBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusNetBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusNetBit_oaModBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusNetBit_oaModBusNetDef data;
    int convert_status=PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusNetBit_oaModBusNetDefObject* self=(PyoaCollection_oaModBusNetBit_oaModBusNetDefObject*)ob;

    PyParamoaModBusNetBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusNetBit_Convert,&p1)) {
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

static char oaCollection_oaModBusNetBit_oaModBusNetDef_assign_doc[] = 
"Class: oaCollection_oaModBusNetBit_oaModBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusNetBit_oaModBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusNetBit_oaModBusNetDef data;
  int convert_status=PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusNetBit_oaModBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusNetBit_oaModBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusNetBit_oaModBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusNetBit_oaModBusNetDef_includes,METH_VARARGS,oaCollection_oaModBusNetBit_oaModBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusNetBit_oaModBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaModBusNetBit_oaModBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusNetBit_oaModBusNetDef_doc[] = 
"Class: oaCollection_oaModBusNetBit_oaModBusNetDef\n"
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
"  Paramegers: (oaCollection_oaModBusNetBit_oaModBusNetDef)\n"
"    Calls: oaCollection_oaModBusNetBit_oaModBusNetDef(const oaCollection_oaModBusNetBit_oaModBusNetDef& coll)\n"
"    Signature: oaCollection_oaModBusNetBit_oaModBusNetDef||cref-oaCollection_oaModBusNetBit_oaModBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusNetBit_oaModBusNetDef)\n"
"    Calls: (const oaCollection_oaModBusNetBit_oaModBusNetDef&)\n"
"    Signature: oaCollection_oaModBusNetBit_oaModBusNetDef||cref-oaCollection_oaModBusNetBit_oaModBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusNetBit_oaModBusNetDef",
    sizeof(PyoaCollection_oaModBusNetBit_oaModBusNetDefObject),
    0,
    (destructor)oaCollection_oaModBusNetBit_oaModBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusNetBit_oaModBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusNetBit_oaModBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusNetBit_oaModBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusNetBit_oaModBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusNetBit_oaModBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusNetBit_oaModBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusNetBit_oaModBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusNetBit_oaModBusNetDef",
           (PyObject*)(&PyoaCollection_oaModBusNetBit_oaModBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusNetBit_oaModBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusNetDef_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNetDef_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusNetDef_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusNetDef_oaModuleObject* self = (PyoaCollection_oaModBusNetDef_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusNetDef_oaModule)
    {
        PyParamoaCollection_oaModBusNetDef_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusNetDef_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusNetDef_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusNetDef_oaModule, Choices are:\n"
        "    (oaCollection_oaModBusNetDef_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusNetDef_oaModule_tp_dealloc(PyoaCollection_oaModBusNetDef_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusNetDef_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNetDef_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusNetDef_oaModule value;
    int convert_status=PyoaCollection_oaModBusNetDef_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaModBusNetDef_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusNetDef_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusNetDef_oaModule v1;
    PyParamoaCollection_oaModBusNetDef_oaModule v2;
    int convert_status1=PyoaCollection_oaModBusNetDef_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusNetDef_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusNetDef_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModBusNetDef_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusNetDef_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModBusNetDef_oaModule*) ((PyoaCollection_oaModBusNetDef_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusNetDef_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusNetDef_oaModule_FromoaCollection_oaModBusNetDef_oaModule(oaCollection_oaModBusNetDef_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusNetDef_oaModule_Type.tp_alloc(&PyoaCollection_oaModBusNetDef_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusNetDef_oaModuleObject* self = (PyoaCollection_oaModBusNetDef_oaModuleObject*)bself;
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
static char oaCollection_oaModBusNetDef_oaModule_includes_doc[] = 
"Class: oaCollection_oaModBusNetDef_oaModule, Function: includes\n"
"  Paramegers: (oaModBusNetDef)\n"
"    Calls: oaBoolean includes(const oaModBusNetDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusNetDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusNetDef_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusNetDef_oaModule data;
    int convert_status=PyoaCollection_oaModBusNetDef_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusNetDef_oaModuleObject* self=(PyoaCollection_oaModBusNetDef_oaModuleObject*)ob;

    PyParamoaModBusNetDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusNetDef_Convert,&p1)) {
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

static char oaCollection_oaModBusNetDef_oaModule_assign_doc[] = 
"Class: oaCollection_oaModBusNetDef_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusNetDef_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusNetDef_oaModule data;
  int convert_status=PyoaCollection_oaModBusNetDef_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusNetDef_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusNetDef_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusNetDef_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusNetDef_oaModule_includes,METH_VARARGS,oaCollection_oaModBusNetDef_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusNetDef_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModBusNetDef_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusNetDef_oaModule_doc[] = 
"Class: oaCollection_oaModBusNetDef_oaModule\n"
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
"  Paramegers: (oaCollection_oaModBusNetDef_oaModule)\n"
"    Calls: oaCollection_oaModBusNetDef_oaModule(const oaCollection_oaModBusNetDef_oaModule& coll)\n"
"    Signature: oaCollection_oaModBusNetDef_oaModule||cref-oaCollection_oaModBusNetDef_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusNetDef_oaModule)\n"
"    Calls: (const oaCollection_oaModBusNetDef_oaModule&)\n"
"    Signature: oaCollection_oaModBusNetDef_oaModule||cref-oaCollection_oaModBusNetDef_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusNetDef_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusNetDef_oaModule",
    sizeof(PyoaCollection_oaModBusNetDef_oaModuleObject),
    0,
    (destructor)oaCollection_oaModBusNetDef_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusNetDef_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusNetDef_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusNetDef_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusNetDef_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusNetDef_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusNetDef_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusNetDef_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusNetDef_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusNetDef_oaModule",
           (PyObject*)(&PyoaCollection_oaModBusNetDef_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusNetDef_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusNet_oaModBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNet_oaModBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusNet_oaModBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusNet_oaModBusNetDefObject* self = (PyoaCollection_oaModBusNet_oaModBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusNet_oaModBusNetDef)
    {
        PyParamoaCollection_oaModBusNet_oaModBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusNet_oaModBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusNet_oaModBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusNet_oaModBusNetDef, Choices are:\n"
        "    (oaCollection_oaModBusNet_oaModBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusNet_oaModBusNetDef_tp_dealloc(PyoaCollection_oaModBusNet_oaModBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusNet_oaModBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusNet_oaModBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusNet_oaModBusNetDef value;
    int convert_status=PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[61];
    sprintf(buffer,"<oaCollection_oaModBusNet_oaModBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusNet_oaModBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusNet_oaModBusNetDef v1;
    PyParamoaCollection_oaModBusNet_oaModBusNetDef v2;
    int convert_status1=PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaModBusNet_oaModBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusNet_oaModBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaModBusNet_oaModBusNetDef*) ((PyoaCollection_oaModBusNet_oaModBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusNet_oaModBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusNet_oaModBusNetDef_FromoaCollection_oaModBusNet_oaModBusNetDef(oaCollection_oaModBusNet_oaModBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusNet_oaModBusNetDef_Type.tp_alloc(&PyoaCollection_oaModBusNet_oaModBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusNet_oaModBusNetDefObject* self = (PyoaCollection_oaModBusNet_oaModBusNetDefObject*)bself;
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
static char oaCollection_oaModBusNet_oaModBusNetDef_includes_doc[] = 
"Class: oaCollection_oaModBusNet_oaModBusNetDef, Function: includes\n"
"  Paramegers: (oaModBusNet)\n"
"    Calls: oaBoolean includes(const oaModBusNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusNet_oaModBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusNet_oaModBusNetDef data;
    int convert_status=PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusNet_oaModBusNetDefObject* self=(PyoaCollection_oaModBusNet_oaModBusNetDefObject*)ob;

    PyParamoaModBusNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusNet_Convert,&p1)) {
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

static char oaCollection_oaModBusNet_oaModBusNetDef_assign_doc[] = 
"Class: oaCollection_oaModBusNet_oaModBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusNet_oaModBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusNet_oaModBusNetDef data;
  int convert_status=PyoaCollection_oaModBusNet_oaModBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusNet_oaModBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusNet_oaModBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusNet_oaModBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusNet_oaModBusNetDef_includes,METH_VARARGS,oaCollection_oaModBusNet_oaModBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusNet_oaModBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaModBusNet_oaModBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusNet_oaModBusNetDef_doc[] = 
"Class: oaCollection_oaModBusNet_oaModBusNetDef\n"
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
"  Paramegers: (oaCollection_oaModBusNet_oaModBusNetDef)\n"
"    Calls: oaCollection_oaModBusNet_oaModBusNetDef(const oaCollection_oaModBusNet_oaModBusNetDef& coll)\n"
"    Signature: oaCollection_oaModBusNet_oaModBusNetDef||cref-oaCollection_oaModBusNet_oaModBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusNet_oaModBusNetDef)\n"
"    Calls: (const oaCollection_oaModBusNet_oaModBusNetDef&)\n"
"    Signature: oaCollection_oaModBusNet_oaModBusNetDef||cref-oaCollection_oaModBusNet_oaModBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusNet_oaModBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusNet_oaModBusNetDef",
    sizeof(PyoaCollection_oaModBusNet_oaModBusNetDefObject),
    0,
    (destructor)oaCollection_oaModBusNet_oaModBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusNet_oaModBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusNet_oaModBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusNet_oaModBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusNet_oaModBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusNet_oaModBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusNet_oaModBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusNet_oaModBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusNet_oaModBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusNet_oaModBusNetDef",
           (PyObject*)(&PyoaCollection_oaModBusNet_oaModBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusNet_oaModBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusTermBit_oaModBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTermBit_oaModBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusTermBit_oaModBusTermDefObject* self = (PyoaCollection_oaModBusTermBit_oaModBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusTermBit_oaModBusTermDef)
    {
        PyParamoaCollection_oaModBusTermBit_oaModBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusTermBit_oaModBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusTermBit_oaModBusTermDef, Choices are:\n"
        "    (oaCollection_oaModBusTermBit_oaModBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusTermBit_oaModBusTermDef_tp_dealloc(PyoaCollection_oaModBusTermBit_oaModBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusTermBit_oaModBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTermBit_oaModBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusTermBit_oaModBusTermDef value;
    int convert_status=PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaModBusTermBit_oaModBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusTermBit_oaModBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusTermBit_oaModBusTermDef v1;
    PyParamoaCollection_oaModBusTermBit_oaModBusTermDef v2;
    int convert_status1=PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaModBusTermBit_oaModBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusTermBit_oaModBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaModBusTermBit_oaModBusTermDef*) ((PyoaCollection_oaModBusTermBit_oaModBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusTermBit_oaModBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusTermBit_oaModBusTermDef_FromoaCollection_oaModBusTermBit_oaModBusTermDef(oaCollection_oaModBusTermBit_oaModBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type.tp_alloc(&PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusTermBit_oaModBusTermDefObject* self = (PyoaCollection_oaModBusTermBit_oaModBusTermDefObject*)bself;
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
static char oaCollection_oaModBusTermBit_oaModBusTermDef_includes_doc[] = 
"Class: oaCollection_oaModBusTermBit_oaModBusTermDef, Function: includes\n"
"  Paramegers: (oaModBusTermBit)\n"
"    Calls: oaBoolean includes(const oaModBusTermBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusTermBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusTermBit_oaModBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusTermBit_oaModBusTermDef data;
    int convert_status=PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusTermBit_oaModBusTermDefObject* self=(PyoaCollection_oaModBusTermBit_oaModBusTermDefObject*)ob;

    PyParamoaModBusTermBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusTermBit_Convert,&p1)) {
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

static char oaCollection_oaModBusTermBit_oaModBusTermDef_assign_doc[] = 
"Class: oaCollection_oaModBusTermBit_oaModBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusTermBit_oaModBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusTermBit_oaModBusTermDef data;
  int convert_status=PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusTermBit_oaModBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusTermBit_oaModBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusTermBit_oaModBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusTermBit_oaModBusTermDef_includes,METH_VARARGS,oaCollection_oaModBusTermBit_oaModBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusTermBit_oaModBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaModBusTermBit_oaModBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusTermBit_oaModBusTermDef_doc[] = 
"Class: oaCollection_oaModBusTermBit_oaModBusTermDef\n"
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
"  Paramegers: (oaCollection_oaModBusTermBit_oaModBusTermDef)\n"
"    Calls: oaCollection_oaModBusTermBit_oaModBusTermDef(const oaCollection_oaModBusTermBit_oaModBusTermDef& coll)\n"
"    Signature: oaCollection_oaModBusTermBit_oaModBusTermDef||cref-oaCollection_oaModBusTermBit_oaModBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusTermBit_oaModBusTermDef)\n"
"    Calls: (const oaCollection_oaModBusTermBit_oaModBusTermDef&)\n"
"    Signature: oaCollection_oaModBusTermBit_oaModBusTermDef||cref-oaCollection_oaModBusTermBit_oaModBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusTermBit_oaModBusTermDef",
    sizeof(PyoaCollection_oaModBusTermBit_oaModBusTermDefObject),
    0,
    (destructor)oaCollection_oaModBusTermBit_oaModBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusTermBit_oaModBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusTermBit_oaModBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusTermBit_oaModBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusTermBit_oaModBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusTermBit_oaModBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusTermBit_oaModBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusTermBit_oaModBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusTermBit_oaModBusTermDef",
           (PyObject*)(&PyoaCollection_oaModBusTermBit_oaModBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusTermBit_oaModBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusTermDef_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTermDef_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusTermDef_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusTermDef_oaModuleObject* self = (PyoaCollection_oaModBusTermDef_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusTermDef_oaModule)
    {
        PyParamoaCollection_oaModBusTermDef_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusTermDef_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusTermDef_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusTermDef_oaModule, Choices are:\n"
        "    (oaCollection_oaModBusTermDef_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusTermDef_oaModule_tp_dealloc(PyoaCollection_oaModBusTermDef_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusTermDef_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTermDef_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusTermDef_oaModule value;
    int convert_status=PyoaCollection_oaModBusTermDef_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaModBusTermDef_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusTermDef_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusTermDef_oaModule v1;
    PyParamoaCollection_oaModBusTermDef_oaModule v2;
    int convert_status1=PyoaCollection_oaModBusTermDef_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusTermDef_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusTermDef_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModBusTermDef_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusTermDef_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModBusTermDef_oaModule*) ((PyoaCollection_oaModBusTermDef_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusTermDef_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusTermDef_oaModule_FromoaCollection_oaModBusTermDef_oaModule(oaCollection_oaModBusTermDef_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusTermDef_oaModule_Type.tp_alloc(&PyoaCollection_oaModBusTermDef_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusTermDef_oaModuleObject* self = (PyoaCollection_oaModBusTermDef_oaModuleObject*)bself;
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
static char oaCollection_oaModBusTermDef_oaModule_includes_doc[] = 
"Class: oaCollection_oaModBusTermDef_oaModule, Function: includes\n"
"  Paramegers: (oaModBusTermDef)\n"
"    Calls: oaBoolean includes(const oaModBusTermDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusTermDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusTermDef_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusTermDef_oaModule data;
    int convert_status=PyoaCollection_oaModBusTermDef_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusTermDef_oaModuleObject* self=(PyoaCollection_oaModBusTermDef_oaModuleObject*)ob;

    PyParamoaModBusTermDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusTermDef_Convert,&p1)) {
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

static char oaCollection_oaModBusTermDef_oaModule_assign_doc[] = 
"Class: oaCollection_oaModBusTermDef_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusTermDef_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusTermDef_oaModule data;
  int convert_status=PyoaCollection_oaModBusTermDef_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusTermDef_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusTermDef_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusTermDef_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusTermDef_oaModule_includes,METH_VARARGS,oaCollection_oaModBusTermDef_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusTermDef_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModBusTermDef_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusTermDef_oaModule_doc[] = 
"Class: oaCollection_oaModBusTermDef_oaModule\n"
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
"  Paramegers: (oaCollection_oaModBusTermDef_oaModule)\n"
"    Calls: oaCollection_oaModBusTermDef_oaModule(const oaCollection_oaModBusTermDef_oaModule& coll)\n"
"    Signature: oaCollection_oaModBusTermDef_oaModule||cref-oaCollection_oaModBusTermDef_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusTermDef_oaModule)\n"
"    Calls: (const oaCollection_oaModBusTermDef_oaModule&)\n"
"    Signature: oaCollection_oaModBusTermDef_oaModule||cref-oaCollection_oaModBusTermDef_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusTermDef_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusTermDef_oaModule",
    sizeof(PyoaCollection_oaModBusTermDef_oaModuleObject),
    0,
    (destructor)oaCollection_oaModBusTermDef_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusTermDef_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusTermDef_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusTermDef_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusTermDef_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusTermDef_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusTermDef_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusTermDef_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusTermDef_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusTermDef_oaModule",
           (PyObject*)(&PyoaCollection_oaModBusTermDef_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusTermDef_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModBusTerm_oaModBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTerm_oaModBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModBusTerm_oaModBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModBusTerm_oaModBusTermDefObject* self = (PyoaCollection_oaModBusTerm_oaModBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModBusTerm_oaModBusTermDef)
    {
        PyParamoaCollection_oaModBusTerm_oaModBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModBusTerm_oaModBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModBusTerm_oaModBusTermDef, Choices are:\n"
        "    (oaCollection_oaModBusTerm_oaModBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModBusTerm_oaModBusTermDef_tp_dealloc(PyoaCollection_oaModBusTerm_oaModBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModBusTerm_oaModBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModBusTerm_oaModBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModBusTerm_oaModBusTermDef value;
    int convert_status=PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaModBusTerm_oaModBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModBusTerm_oaModBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModBusTerm_oaModBusTermDef v1;
    PyParamoaCollection_oaModBusTerm_oaModBusTermDef v2;
    int convert_status1=PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaModBusTerm_oaModBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModBusTerm_oaModBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaModBusTerm_oaModBusTermDef*) ((PyoaCollection_oaModBusTerm_oaModBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModBusTerm_oaModBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModBusTerm_oaModBusTermDef_FromoaCollection_oaModBusTerm_oaModBusTermDef(oaCollection_oaModBusTerm_oaModBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModBusTerm_oaModBusTermDef_Type.tp_alloc(&PyoaCollection_oaModBusTerm_oaModBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModBusTerm_oaModBusTermDefObject* self = (PyoaCollection_oaModBusTerm_oaModBusTermDefObject*)bself;
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
static char oaCollection_oaModBusTerm_oaModBusTermDef_includes_doc[] = 
"Class: oaCollection_oaModBusTerm_oaModBusTermDef, Function: includes\n"
"  Paramegers: (oaModBusTerm)\n"
"    Calls: oaBoolean includes(const oaModBusTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModBusTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModBusTerm_oaModBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModBusTerm_oaModBusTermDef data;
    int convert_status=PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModBusTerm_oaModBusTermDefObject* self=(PyoaCollection_oaModBusTerm_oaModBusTermDefObject*)ob;

    PyParamoaModBusTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBusTerm_Convert,&p1)) {
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

static char oaCollection_oaModBusTerm_oaModBusTermDef_assign_doc[] = 
"Class: oaCollection_oaModBusTerm_oaModBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModBusTerm_oaModBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModBusTerm_oaModBusTermDef data;
  int convert_status=PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModBusTerm_oaModBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModBusTerm_oaModBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModBusTerm_oaModBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModBusTerm_oaModBusTermDef_includes,METH_VARARGS,oaCollection_oaModBusTerm_oaModBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModBusTerm_oaModBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaModBusTerm_oaModBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModBusTerm_oaModBusTermDef_doc[] = 
"Class: oaCollection_oaModBusTerm_oaModBusTermDef\n"
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
"  Paramegers: (oaCollection_oaModBusTerm_oaModBusTermDef)\n"
"    Calls: oaCollection_oaModBusTerm_oaModBusTermDef(const oaCollection_oaModBusTerm_oaModBusTermDef& coll)\n"
"    Signature: oaCollection_oaModBusTerm_oaModBusTermDef||cref-oaCollection_oaModBusTerm_oaModBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModBusTerm_oaModBusTermDef)\n"
"    Calls: (const oaCollection_oaModBusTerm_oaModBusTermDef&)\n"
"    Signature: oaCollection_oaModBusTerm_oaModBusTermDef||cref-oaCollection_oaModBusTerm_oaModBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModBusTerm_oaModBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModBusTerm_oaModBusTermDef",
    sizeof(PyoaCollection_oaModBusTerm_oaModBusTermDefObject),
    0,
    (destructor)oaCollection_oaModBusTerm_oaModBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModBusTerm_oaModBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModBusTerm_oaModBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModBusTerm_oaModBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModBusTerm_oaModBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModBusTerm_oaModBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModBusTerm_oaModBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModBusTerm_oaModBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModBusTerm_oaModBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModBusTerm_oaModBusTermDef",
           (PyObject*)(&PyoaCollection_oaModBusTerm_oaModBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModBusTerm_oaModBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModConnectDef_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModConnectDef_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModConnectDef_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModConnectDef_oaModuleObject* self = (PyoaCollection_oaModConnectDef_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModConnectDef_oaModule)
    {
        PyParamoaCollection_oaModConnectDef_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModConnectDef_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModConnectDef_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModConnectDef_oaModule, Choices are:\n"
        "    (oaCollection_oaModConnectDef_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModConnectDef_oaModule_tp_dealloc(PyoaCollection_oaModConnectDef_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModConnectDef_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModConnectDef_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModConnectDef_oaModule value;
    int convert_status=PyoaCollection_oaModConnectDef_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaModConnectDef_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModConnectDef_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModConnectDef_oaModule v1;
    PyParamoaCollection_oaModConnectDef_oaModule v2;
    int convert_status1=PyoaCollection_oaModConnectDef_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModConnectDef_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModConnectDef_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModConnectDef_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModConnectDef_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModConnectDef_oaModule*) ((PyoaCollection_oaModConnectDef_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModConnectDef_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModConnectDef_oaModule_FromoaCollection_oaModConnectDef_oaModule(oaCollection_oaModConnectDef_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModConnectDef_oaModule_Type.tp_alloc(&PyoaCollection_oaModConnectDef_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModConnectDef_oaModuleObject* self = (PyoaCollection_oaModConnectDef_oaModuleObject*)bself;
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
static char oaCollection_oaModConnectDef_oaModule_includes_doc[] = 
"Class: oaCollection_oaModConnectDef_oaModule, Function: includes\n"
"  Paramegers: (oaModConnectDef)\n"
"    Calls: oaBoolean includes(const oaModConnectDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModConnectDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModConnectDef_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModConnectDef_oaModule data;
    int convert_status=PyoaCollection_oaModConnectDef_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModConnectDef_oaModuleObject* self=(PyoaCollection_oaModConnectDef_oaModuleObject*)ob;

    PyParamoaModConnectDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModConnectDef_Convert,&p1)) {
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

static char oaCollection_oaModConnectDef_oaModule_assign_doc[] = 
"Class: oaCollection_oaModConnectDef_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModConnectDef_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModConnectDef_oaModule data;
  int convert_status=PyoaCollection_oaModConnectDef_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModConnectDef_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModConnectDef_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModConnectDef_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModConnectDef_oaModule_includes,METH_VARARGS,oaCollection_oaModConnectDef_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModConnectDef_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModConnectDef_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModConnectDef_oaModule_doc[] = 
"Class: oaCollection_oaModConnectDef_oaModule\n"
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
"  Paramegers: (oaCollection_oaModConnectDef_oaModule)\n"
"    Calls: oaCollection_oaModConnectDef_oaModule(const oaCollection_oaModConnectDef_oaModule& coll)\n"
"    Signature: oaCollection_oaModConnectDef_oaModule||cref-oaCollection_oaModConnectDef_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModConnectDef_oaModule)\n"
"    Calls: (const oaCollection_oaModConnectDef_oaModule&)\n"
"    Signature: oaCollection_oaModConnectDef_oaModule||cref-oaCollection_oaModConnectDef_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModConnectDef_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModConnectDef_oaModule",
    sizeof(PyoaCollection_oaModConnectDef_oaModuleObject),
    0,
    (destructor)oaCollection_oaModConnectDef_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModConnectDef_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModConnectDef_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModConnectDef_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModConnectDef_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModConnectDef_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModConnectDef_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModConnectDef_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModConnectDef_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModConnectDef_oaModule",
           (PyObject*)(&PyoaCollection_oaModConnectDef_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModConnectDef_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModDesignInst_oaModInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModDesignInst_oaModInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModDesignInst_oaModInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModDesignInst_oaModInstHeaderObject* self = (PyoaCollection_oaModDesignInst_oaModInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModDesignInst_oaModInstHeader)
    {
        PyParamoaCollection_oaModDesignInst_oaModInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModDesignInst_oaModInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModDesignInst_oaModInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModDesignInst_oaModInstHeader, Choices are:\n"
        "    (oaCollection_oaModDesignInst_oaModInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModDesignInst_oaModInstHeader_tp_dealloc(PyoaCollection_oaModDesignInst_oaModInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModDesignInst_oaModInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModDesignInst_oaModInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModDesignInst_oaModInstHeader value;
    int convert_status=PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaModDesignInst_oaModInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModDesignInst_oaModInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModDesignInst_oaModInstHeader v1;
    PyParamoaCollection_oaModDesignInst_oaModInstHeader v2;
    int convert_status1=PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaModDesignInst_oaModInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModDesignInst_oaModInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaModDesignInst_oaModInstHeader*) ((PyoaCollection_oaModDesignInst_oaModInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModDesignInst_oaModInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModDesignInst_oaModInstHeader_FromoaCollection_oaModDesignInst_oaModInstHeader(oaCollection_oaModDesignInst_oaModInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModDesignInst_oaModInstHeader_Type.tp_alloc(&PyoaCollection_oaModDesignInst_oaModInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModDesignInst_oaModInstHeaderObject* self = (PyoaCollection_oaModDesignInst_oaModInstHeaderObject*)bself;
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
static char oaCollection_oaModDesignInst_oaModInstHeader_includes_doc[] = 
"Class: oaCollection_oaModDesignInst_oaModInstHeader, Function: includes\n"
"  Paramegers: (oaModDesignInst)\n"
"    Calls: oaBoolean includes(const oaModDesignInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModDesignInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModDesignInst_oaModInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModDesignInst_oaModInstHeader data;
    int convert_status=PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModDesignInst_oaModInstHeaderObject* self=(PyoaCollection_oaModDesignInst_oaModInstHeaderObject*)ob;

    PyParamoaModDesignInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModDesignInst_Convert,&p1)) {
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

static char oaCollection_oaModDesignInst_oaModInstHeader_assign_doc[] = 
"Class: oaCollection_oaModDesignInst_oaModInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModDesignInst_oaModInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModDesignInst_oaModInstHeader data;
  int convert_status=PyoaCollection_oaModDesignInst_oaModInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModDesignInst_oaModInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModDesignInst_oaModInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModDesignInst_oaModInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModDesignInst_oaModInstHeader_includes,METH_VARARGS,oaCollection_oaModDesignInst_oaModInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModDesignInst_oaModInstHeader_tp_assign,METH_VARARGS,oaCollection_oaModDesignInst_oaModInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModDesignInst_oaModInstHeader_doc[] = 
"Class: oaCollection_oaModDesignInst_oaModInstHeader\n"
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
"  Paramegers: (oaCollection_oaModDesignInst_oaModInstHeader)\n"
"    Calls: oaCollection_oaModDesignInst_oaModInstHeader(const oaCollection_oaModDesignInst_oaModInstHeader& coll)\n"
"    Signature: oaCollection_oaModDesignInst_oaModInstHeader||cref-oaCollection_oaModDesignInst_oaModInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModDesignInst_oaModInstHeader)\n"
"    Calls: (const oaCollection_oaModDesignInst_oaModInstHeader&)\n"
"    Signature: oaCollection_oaModDesignInst_oaModInstHeader||cref-oaCollection_oaModDesignInst_oaModInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModDesignInst_oaModInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModDesignInst_oaModInstHeader",
    sizeof(PyoaCollection_oaModDesignInst_oaModInstHeaderObject),
    0,
    (destructor)oaCollection_oaModDesignInst_oaModInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModDesignInst_oaModInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModDesignInst_oaModInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModDesignInst_oaModInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModDesignInst_oaModInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModDesignInst_oaModInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModDesignInst_oaModInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModDesignInst_oaModInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModDesignInst_oaModInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModDesignInst_oaModInstHeader",
           (PyObject*)(&PyoaCollection_oaModDesignInst_oaModInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModDesignInst_oaModInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInstHeader_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstHeader_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInstHeader_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInstHeader_oaDesignObject* self = (PyoaCollection_oaModInstHeader_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInstHeader_oaDesign)
    {
        PyParamoaCollection_oaModInstHeader_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInstHeader_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInstHeader_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInstHeader_oaDesign, Choices are:\n"
        "    (oaCollection_oaModInstHeader_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInstHeader_oaDesign_tp_dealloc(PyoaCollection_oaModInstHeader_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInstHeader_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstHeader_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInstHeader_oaDesign value;
    int convert_status=PyoaCollection_oaModInstHeader_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaModInstHeader_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInstHeader_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInstHeader_oaDesign v1;
    PyParamoaCollection_oaModInstHeader_oaDesign v2;
    int convert_status1=PyoaCollection_oaModInstHeader_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInstHeader_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInstHeader_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaModInstHeader_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInstHeader_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaModInstHeader_oaDesign*) ((PyoaCollection_oaModInstHeader_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInstHeader_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInstHeader_oaDesign_FromoaCollection_oaModInstHeader_oaDesign(oaCollection_oaModInstHeader_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInstHeader_oaDesign_Type.tp_alloc(&PyoaCollection_oaModInstHeader_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInstHeader_oaDesignObject* self = (PyoaCollection_oaModInstHeader_oaDesignObject*)bself;
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
static char oaCollection_oaModInstHeader_oaDesign_includes_doc[] = 
"Class: oaCollection_oaModInstHeader_oaDesign, Function: includes\n"
"  Paramegers: (oaModInstHeader)\n"
"    Calls: oaBoolean includes(const oaModInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInstHeader_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInstHeader_oaDesign data;
    int convert_status=PyoaCollection_oaModInstHeader_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInstHeader_oaDesignObject* self=(PyoaCollection_oaModInstHeader_oaDesignObject*)ob;

    PyParamoaModInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInstHeader_Convert,&p1)) {
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

static char oaCollection_oaModInstHeader_oaDesign_assign_doc[] = 
"Class: oaCollection_oaModInstHeader_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInstHeader_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInstHeader_oaDesign data;
  int convert_status=PyoaCollection_oaModInstHeader_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInstHeader_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInstHeader_oaDesign_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInstHeader_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInstHeader_oaDesign_includes,METH_VARARGS,oaCollection_oaModInstHeader_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInstHeader_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaModInstHeader_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInstHeader_oaDesign_doc[] = 
"Class: oaCollection_oaModInstHeader_oaDesign\n"
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
"  Paramegers: (oaCollection_oaModInstHeader_oaDesign)\n"
"    Calls: oaCollection_oaModInstHeader_oaDesign(const oaCollection_oaModInstHeader_oaDesign& coll)\n"
"    Signature: oaCollection_oaModInstHeader_oaDesign||cref-oaCollection_oaModInstHeader_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInstHeader_oaDesign)\n"
"    Calls: (const oaCollection_oaModInstHeader_oaDesign&)\n"
"    Signature: oaCollection_oaModInstHeader_oaDesign||cref-oaCollection_oaModInstHeader_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInstHeader_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInstHeader_oaDesign",
    sizeof(PyoaCollection_oaModInstHeader_oaDesignObject),
    0,
    (destructor)oaCollection_oaModInstHeader_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInstHeader_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInstHeader_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInstHeader_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInstHeader_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInstHeader_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInstHeader_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInstHeader_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInstHeader_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInstHeader_oaDesign",
           (PyObject*)(&PyoaCollection_oaModInstHeader_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInstHeader_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInstHeader_oaModInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstHeader_oaModInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInstHeader_oaModInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInstHeader_oaModInstHeaderObject* self = (PyoaCollection_oaModInstHeader_oaModInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInstHeader_oaModInstHeader)
    {
        PyParamoaCollection_oaModInstHeader_oaModInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInstHeader_oaModInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInstHeader_oaModInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInstHeader_oaModInstHeader, Choices are:\n"
        "    (oaCollection_oaModInstHeader_oaModInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInstHeader_oaModInstHeader_tp_dealloc(PyoaCollection_oaModInstHeader_oaModInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInstHeader_oaModInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstHeader_oaModInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInstHeader_oaModInstHeader value;
    int convert_status=PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[66];
    sprintf(buffer,"<oaCollection_oaModInstHeader_oaModInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInstHeader_oaModInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInstHeader_oaModInstHeader v1;
    PyParamoaCollection_oaModInstHeader_oaModInstHeader v2;
    int convert_status1=PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaModInstHeader_oaModInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInstHeader_oaModInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaModInstHeader_oaModInstHeader*) ((PyoaCollection_oaModInstHeader_oaModInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInstHeader_oaModInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInstHeader_oaModInstHeader_FromoaCollection_oaModInstHeader_oaModInstHeader(oaCollection_oaModInstHeader_oaModInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInstHeader_oaModInstHeader_Type.tp_alloc(&PyoaCollection_oaModInstHeader_oaModInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInstHeader_oaModInstHeaderObject* self = (PyoaCollection_oaModInstHeader_oaModInstHeaderObject*)bself;
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
static char oaCollection_oaModInstHeader_oaModInstHeader_includes_doc[] = 
"Class: oaCollection_oaModInstHeader_oaModInstHeader, Function: includes\n"
"  Paramegers: (oaModInstHeader)\n"
"    Calls: oaBoolean includes(const oaModInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInstHeader_oaModInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInstHeader_oaModInstHeader data;
    int convert_status=PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInstHeader_oaModInstHeaderObject* self=(PyoaCollection_oaModInstHeader_oaModInstHeaderObject*)ob;

    PyParamoaModInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInstHeader_Convert,&p1)) {
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

static char oaCollection_oaModInstHeader_oaModInstHeader_assign_doc[] = 
"Class: oaCollection_oaModInstHeader_oaModInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInstHeader_oaModInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInstHeader_oaModInstHeader data;
  int convert_status=PyoaCollection_oaModInstHeader_oaModInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInstHeader_oaModInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInstHeader_oaModInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInstHeader_oaModInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInstHeader_oaModInstHeader_includes,METH_VARARGS,oaCollection_oaModInstHeader_oaModInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInstHeader_oaModInstHeader_tp_assign,METH_VARARGS,oaCollection_oaModInstHeader_oaModInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInstHeader_oaModInstHeader_doc[] = 
"Class: oaCollection_oaModInstHeader_oaModInstHeader\n"
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
"  Paramegers: (oaCollection_oaModInstHeader_oaModInstHeader)\n"
"    Calls: oaCollection_oaModInstHeader_oaModInstHeader(const oaCollection_oaModInstHeader_oaModInstHeader& coll)\n"
"    Signature: oaCollection_oaModInstHeader_oaModInstHeader||cref-oaCollection_oaModInstHeader_oaModInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInstHeader_oaModInstHeader)\n"
"    Calls: (const oaCollection_oaModInstHeader_oaModInstHeader&)\n"
"    Signature: oaCollection_oaModInstHeader_oaModInstHeader||cref-oaCollection_oaModInstHeader_oaModInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInstHeader_oaModInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInstHeader_oaModInstHeader",
    sizeof(PyoaCollection_oaModInstHeader_oaModInstHeaderObject),
    0,
    (destructor)oaCollection_oaModInstHeader_oaModInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInstHeader_oaModInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInstHeader_oaModInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInstHeader_oaModInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInstHeader_oaModInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInstHeader_oaModInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInstHeader_oaModInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInstHeader_oaModInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInstHeader_oaModInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInstHeader_oaModInstHeader",
           (PyObject*)(&PyoaCollection_oaModInstHeader_oaModInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInstHeader_oaModInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInstTerm_oaModInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInstTerm_oaModInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInstTerm_oaModInstObject* self = (PyoaCollection_oaModInstTerm_oaModInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInstTerm_oaModInst)
    {
        PyParamoaCollection_oaModInstTerm_oaModInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInstTerm_oaModInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInstTerm_oaModInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInstTerm_oaModInst, Choices are:\n"
        "    (oaCollection_oaModInstTerm_oaModInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInstTerm_oaModInst_tp_dealloc(PyoaCollection_oaModInstTerm_oaModInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInstTerm_oaModInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInstTerm_oaModInst value;
    int convert_status=PyoaCollection_oaModInstTerm_oaModInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaModInstTerm_oaModInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInstTerm_oaModInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInstTerm_oaModInst v1;
    PyParamoaCollection_oaModInstTerm_oaModInst v2;
    int convert_status1=PyoaCollection_oaModInstTerm_oaModInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInstTerm_oaModInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInstTerm_oaModInst_Convert(PyObject* ob,PyParamoaCollection_oaModInstTerm_oaModInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInstTerm_oaModInst_Check(ob)) {
        result->SetData( (oaCollection_oaModInstTerm_oaModInst*) ((PyoaCollection_oaModInstTerm_oaModInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInstTerm_oaModInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInstTerm_oaModInst_FromoaCollection_oaModInstTerm_oaModInst(oaCollection_oaModInstTerm_oaModInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInstTerm_oaModInst_Type.tp_alloc(&PyoaCollection_oaModInstTerm_oaModInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInstTerm_oaModInstObject* self = (PyoaCollection_oaModInstTerm_oaModInstObject*)bself;
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
static char oaCollection_oaModInstTerm_oaModInst_includes_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModInst, Function: includes\n"
"  Paramegers: (oaModInstTerm)\n"
"    Calls: oaBoolean includes(const oaModInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInstTerm_oaModInst data;
    int convert_status=PyoaCollection_oaModInstTerm_oaModInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInstTerm_oaModInstObject* self=(PyoaCollection_oaModInstTerm_oaModInstObject*)ob;

    PyParamoaModInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInstTerm_Convert,&p1)) {
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

static char oaCollection_oaModInstTerm_oaModInst_assign_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInstTerm_oaModInst data;
  int convert_status=PyoaCollection_oaModInstTerm_oaModInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInstTerm_oaModInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInstTerm_oaModInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInstTerm_oaModInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInstTerm_oaModInst_includes,METH_VARARGS,oaCollection_oaModInstTerm_oaModInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInstTerm_oaModInst_tp_assign,METH_VARARGS,oaCollection_oaModInstTerm_oaModInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInstTerm_oaModInst_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModInst\n"
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
"  Paramegers: (oaCollection_oaModInstTerm_oaModInst)\n"
"    Calls: oaCollection_oaModInstTerm_oaModInst(const oaCollection_oaModInstTerm_oaModInst& coll)\n"
"    Signature: oaCollection_oaModInstTerm_oaModInst||cref-oaCollection_oaModInstTerm_oaModInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInstTerm_oaModInst)\n"
"    Calls: (const oaCollection_oaModInstTerm_oaModInst&)\n"
"    Signature: oaCollection_oaModInstTerm_oaModInst||cref-oaCollection_oaModInstTerm_oaModInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInstTerm_oaModInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInstTerm_oaModInst",
    sizeof(PyoaCollection_oaModInstTerm_oaModInstObject),
    0,
    (destructor)oaCollection_oaModInstTerm_oaModInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInstTerm_oaModInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInstTerm_oaModInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInstTerm_oaModInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInstTerm_oaModInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInstTerm_oaModInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInstTerm_oaModInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInstTerm_oaModInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInstTerm_oaModInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInstTerm_oaModInst",
           (PyObject*)(&PyoaCollection_oaModInstTerm_oaModInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInstTerm_oaModInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInstTerm_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInstTerm_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInstTerm_oaModNetObject* self = (PyoaCollection_oaModInstTerm_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInstTerm_oaModNet)
    {
        PyParamoaCollection_oaModInstTerm_oaModNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInstTerm_oaModNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInstTerm_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInstTerm_oaModNet, Choices are:\n"
        "    (oaCollection_oaModInstTerm_oaModNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInstTerm_oaModNet_tp_dealloc(PyoaCollection_oaModInstTerm_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInstTerm_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInstTerm_oaModNet value;
    int convert_status=PyoaCollection_oaModInstTerm_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaModInstTerm_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInstTerm_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInstTerm_oaModNet v1;
    PyParamoaCollection_oaModInstTerm_oaModNet v2;
    int convert_status1=PyoaCollection_oaModInstTerm_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInstTerm_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInstTerm_oaModNet_Convert(PyObject* ob,PyParamoaCollection_oaModInstTerm_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInstTerm_oaModNet_Check(ob)) {
        result->SetData( (oaCollection_oaModInstTerm_oaModNet*) ((PyoaCollection_oaModInstTerm_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInstTerm_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInstTerm_oaModNet_FromoaCollection_oaModInstTerm_oaModNet(oaCollection_oaModInstTerm_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInstTerm_oaModNet_Type.tp_alloc(&PyoaCollection_oaModInstTerm_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInstTerm_oaModNetObject* self = (PyoaCollection_oaModInstTerm_oaModNetObject*)bself;
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
static char oaCollection_oaModInstTerm_oaModNet_includes_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModNet, Function: includes\n"
"  Paramegers: (oaModInstTerm)\n"
"    Calls: oaBoolean includes(const oaModInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInstTerm_oaModNet data;
    int convert_status=PyoaCollection_oaModInstTerm_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInstTerm_oaModNetObject* self=(PyoaCollection_oaModInstTerm_oaModNetObject*)ob;

    PyParamoaModInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInstTerm_Convert,&p1)) {
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

static char oaCollection_oaModInstTerm_oaModNet_assign_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInstTerm_oaModNet data;
  int convert_status=PyoaCollection_oaModInstTerm_oaModNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInstTerm_oaModNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInstTerm_oaModNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInstTerm_oaModNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInstTerm_oaModNet_includes,METH_VARARGS,oaCollection_oaModInstTerm_oaModNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInstTerm_oaModNet_tp_assign,METH_VARARGS,oaCollection_oaModInstTerm_oaModNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInstTerm_oaModNet_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModNet\n"
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
"  Paramegers: (oaCollection_oaModInstTerm_oaModNet)\n"
"    Calls: oaCollection_oaModInstTerm_oaModNet(const oaCollection_oaModInstTerm_oaModNet& coll)\n"
"    Signature: oaCollection_oaModInstTerm_oaModNet||cref-oaCollection_oaModInstTerm_oaModNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInstTerm_oaModNet)\n"
"    Calls: (const oaCollection_oaModInstTerm_oaModNet&)\n"
"    Signature: oaCollection_oaModInstTerm_oaModNet||cref-oaCollection_oaModInstTerm_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInstTerm_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInstTerm_oaModNet",
    sizeof(PyoaCollection_oaModInstTerm_oaModNetObject),
    0,
    (destructor)oaCollection_oaModInstTerm_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInstTerm_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInstTerm_oaModNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInstTerm_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInstTerm_oaModNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInstTerm_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInstTerm_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInstTerm_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInstTerm_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInstTerm_oaModNet",
           (PyObject*)(&PyoaCollection_oaModInstTerm_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInstTerm_oaModNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInstTerm_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInstTerm_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInstTerm_oaModuleObject* self = (PyoaCollection_oaModInstTerm_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInstTerm_oaModule)
    {
        PyParamoaCollection_oaModInstTerm_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInstTerm_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInstTerm_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInstTerm_oaModule, Choices are:\n"
        "    (oaCollection_oaModInstTerm_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInstTerm_oaModule_tp_dealloc(PyoaCollection_oaModInstTerm_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInstTerm_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInstTerm_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInstTerm_oaModule value;
    int convert_status=PyoaCollection_oaModInstTerm_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaModInstTerm_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInstTerm_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInstTerm_oaModule v1;
    PyParamoaCollection_oaModInstTerm_oaModule v2;
    int convert_status1=PyoaCollection_oaModInstTerm_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInstTerm_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInstTerm_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModInstTerm_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInstTerm_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModInstTerm_oaModule*) ((PyoaCollection_oaModInstTerm_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInstTerm_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInstTerm_oaModule_FromoaCollection_oaModInstTerm_oaModule(oaCollection_oaModInstTerm_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInstTerm_oaModule_Type.tp_alloc(&PyoaCollection_oaModInstTerm_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInstTerm_oaModuleObject* self = (PyoaCollection_oaModInstTerm_oaModuleObject*)bself;
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
static char oaCollection_oaModInstTerm_oaModule_includes_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModule, Function: includes\n"
"  Paramegers: (oaModInstTerm)\n"
"    Calls: oaBoolean includes(const oaModInstTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInstTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInstTerm_oaModule data;
    int convert_status=PyoaCollection_oaModInstTerm_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInstTerm_oaModuleObject* self=(PyoaCollection_oaModInstTerm_oaModuleObject*)ob;

    PyParamoaModInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInstTerm_Convert,&p1)) {
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

static char oaCollection_oaModInstTerm_oaModule_assign_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInstTerm_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInstTerm_oaModule data;
  int convert_status=PyoaCollection_oaModInstTerm_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInstTerm_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInstTerm_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInstTerm_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInstTerm_oaModule_includes,METH_VARARGS,oaCollection_oaModInstTerm_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInstTerm_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModInstTerm_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInstTerm_oaModule_doc[] = 
"Class: oaCollection_oaModInstTerm_oaModule\n"
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
"  Paramegers: (oaCollection_oaModInstTerm_oaModule)\n"
"    Calls: oaCollection_oaModInstTerm_oaModule(const oaCollection_oaModInstTerm_oaModule& coll)\n"
"    Signature: oaCollection_oaModInstTerm_oaModule||cref-oaCollection_oaModInstTerm_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInstTerm_oaModule)\n"
"    Calls: (const oaCollection_oaModInstTerm_oaModule&)\n"
"    Signature: oaCollection_oaModInstTerm_oaModule||cref-oaCollection_oaModInstTerm_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInstTerm_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInstTerm_oaModule",
    sizeof(PyoaCollection_oaModInstTerm_oaModuleObject),
    0,
    (destructor)oaCollection_oaModInstTerm_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInstTerm_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInstTerm_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInstTerm_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInstTerm_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInstTerm_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInstTerm_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInstTerm_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInstTerm_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInstTerm_oaModule",
           (PyObject*)(&PyoaCollection_oaModInstTerm_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInstTerm_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInst_oaModVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInst_oaModVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInst_oaModVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInst_oaModVectorInstDefObject* self = (PyoaCollection_oaModInst_oaModVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInst_oaModVectorInstDef)
    {
        PyParamoaCollection_oaModInst_oaModVectorInstDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInst_oaModVectorInstDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInst_oaModVectorInstDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInst_oaModVectorInstDef, Choices are:\n"
        "    (oaCollection_oaModInst_oaModVectorInstDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInst_oaModVectorInstDef_tp_dealloc(PyoaCollection_oaModInst_oaModVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInst_oaModVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInst_oaModVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInst_oaModVectorInstDef value;
    int convert_status=PyoaCollection_oaModInst_oaModVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[63];
    sprintf(buffer,"<oaCollection_oaModInst_oaModVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInst_oaModVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInst_oaModVectorInstDef v1;
    PyParamoaCollection_oaModInst_oaModVectorInstDef v2;
    int convert_status1=PyoaCollection_oaModInst_oaModVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInst_oaModVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInst_oaModVectorInstDef_Convert(PyObject* ob,PyParamoaCollection_oaModInst_oaModVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInst_oaModVectorInstDef_Check(ob)) {
        result->SetData( (oaCollection_oaModInst_oaModVectorInstDef*) ((PyoaCollection_oaModInst_oaModVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInst_oaModVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInst_oaModVectorInstDef_FromoaCollection_oaModInst_oaModVectorInstDef(oaCollection_oaModInst_oaModVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInst_oaModVectorInstDef_Type.tp_alloc(&PyoaCollection_oaModInst_oaModVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInst_oaModVectorInstDefObject* self = (PyoaCollection_oaModInst_oaModVectorInstDefObject*)bself;
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
static char oaCollection_oaModInst_oaModVectorInstDef_includes_doc[] = 
"Class: oaCollection_oaModInst_oaModVectorInstDef, Function: includes\n"
"  Paramegers: (oaModInst)\n"
"    Calls: oaBoolean includes(const oaModInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInst_oaModVectorInstDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInst_oaModVectorInstDef data;
    int convert_status=PyoaCollection_oaModInst_oaModVectorInstDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInst_oaModVectorInstDefObject* self=(PyoaCollection_oaModInst_oaModVectorInstDefObject*)ob;

    PyParamoaModInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInst_Convert,&p1)) {
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

static char oaCollection_oaModInst_oaModVectorInstDef_assign_doc[] = 
"Class: oaCollection_oaModInst_oaModVectorInstDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInst_oaModVectorInstDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInst_oaModVectorInstDef data;
  int convert_status=PyoaCollection_oaModInst_oaModVectorInstDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInst_oaModVectorInstDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInst_oaModVectorInstDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInst_oaModVectorInstDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInst_oaModVectorInstDef_includes,METH_VARARGS,oaCollection_oaModInst_oaModVectorInstDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInst_oaModVectorInstDef_tp_assign,METH_VARARGS,oaCollection_oaModInst_oaModVectorInstDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInst_oaModVectorInstDef_doc[] = 
"Class: oaCollection_oaModInst_oaModVectorInstDef\n"
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
"  Paramegers: (oaCollection_oaModInst_oaModVectorInstDef)\n"
"    Calls: oaCollection_oaModInst_oaModVectorInstDef(const oaCollection_oaModInst_oaModVectorInstDef& coll)\n"
"    Signature: oaCollection_oaModInst_oaModVectorInstDef||cref-oaCollection_oaModInst_oaModVectorInstDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInst_oaModVectorInstDef)\n"
"    Calls: (const oaCollection_oaModInst_oaModVectorInstDef&)\n"
"    Signature: oaCollection_oaModInst_oaModVectorInstDef||cref-oaCollection_oaModInst_oaModVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInst_oaModVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInst_oaModVectorInstDef",
    sizeof(PyoaCollection_oaModInst_oaModVectorInstDefObject),
    0,
    (destructor)oaCollection_oaModInst_oaModVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInst_oaModVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInst_oaModVectorInstDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInst_oaModVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInst_oaModVectorInstDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInst_oaModVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInst_oaModVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInst_oaModVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInst_oaModVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInst_oaModVectorInstDef",
           (PyObject*)(&PyoaCollection_oaModInst_oaModVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInst_oaModVectorInstDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModInst_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInst_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModInst_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModInst_oaModuleObject* self = (PyoaCollection_oaModInst_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModInst_oaModule)
    {
        PyParamoaCollection_oaModInst_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModInst_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModInst_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModInst_oaModule, Choices are:\n"
        "    (oaCollection_oaModInst_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModInst_oaModule_tp_dealloc(PyoaCollection_oaModInst_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModInst_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModInst_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModInst_oaModule value;
    int convert_status=PyoaCollection_oaModInst_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaModInst_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModInst_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModInst_oaModule v1;
    PyParamoaCollection_oaModInst_oaModule v2;
    int convert_status1=PyoaCollection_oaModInst_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModInst_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModInst_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModInst_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModInst_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModInst_oaModule*) ((PyoaCollection_oaModInst_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModInst_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModInst_oaModule_FromoaCollection_oaModInst_oaModule(oaCollection_oaModInst_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModInst_oaModule_Type.tp_alloc(&PyoaCollection_oaModInst_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModInst_oaModuleObject* self = (PyoaCollection_oaModInst_oaModuleObject*)bself;
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
static char oaCollection_oaModInst_oaModule_includes_doc[] = 
"Class: oaCollection_oaModInst_oaModule, Function: includes\n"
"  Paramegers: (oaModInst)\n"
"    Calls: oaBoolean includes(const oaModInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModInst_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModInst_oaModule data;
    int convert_status=PyoaCollection_oaModInst_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModInst_oaModuleObject* self=(PyoaCollection_oaModInst_oaModuleObject*)ob;

    PyParamoaModInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInst_Convert,&p1)) {
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

static char oaCollection_oaModInst_oaModule_assign_doc[] = 
"Class: oaCollection_oaModInst_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModInst_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModInst_oaModule data;
  int convert_status=PyoaCollection_oaModInst_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModInst_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModInst_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModInst_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModInst_oaModule_includes,METH_VARARGS,oaCollection_oaModInst_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModInst_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModInst_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModInst_oaModule_doc[] = 
"Class: oaCollection_oaModInst_oaModule\n"
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
"  Paramegers: (oaCollection_oaModInst_oaModule)\n"
"    Calls: oaCollection_oaModInst_oaModule(const oaCollection_oaModInst_oaModule& coll)\n"
"    Signature: oaCollection_oaModInst_oaModule||cref-oaCollection_oaModInst_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModInst_oaModule)\n"
"    Calls: (const oaCollection_oaModInst_oaModule&)\n"
"    Signature: oaCollection_oaModInst_oaModule||cref-oaCollection_oaModInst_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModInst_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModInst_oaModule",
    sizeof(PyoaCollection_oaModInst_oaModuleObject),
    0,
    (destructor)oaCollection_oaModInst_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModInst_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModInst_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModInst_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModInst_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModInst_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModInst_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModInst_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModInst_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModInst_oaModule",
           (PyObject*)(&PyoaCollection_oaModInst_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModInst_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModModuleInstHeader_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModModuleInstHeader_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModModuleInstHeader_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModModuleInstHeader_oaModuleObject* self = (PyoaCollection_oaModModuleInstHeader_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModModuleInstHeader_oaModule)
    {
        PyParamoaCollection_oaModModuleInstHeader_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModModuleInstHeader_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModModuleInstHeader_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModModuleInstHeader_oaModule, Choices are:\n"
        "    (oaCollection_oaModModuleInstHeader_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModModuleInstHeader_oaModule_tp_dealloc(PyoaCollection_oaModModuleInstHeader_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModModuleInstHeader_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModModuleInstHeader_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModModuleInstHeader_oaModule value;
    int convert_status=PyoaCollection_oaModModuleInstHeader_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[65];
    sprintf(buffer,"<oaCollection_oaModModuleInstHeader_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModModuleInstHeader_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModModuleInstHeader_oaModule v1;
    PyParamoaCollection_oaModModuleInstHeader_oaModule v2;
    int convert_status1=PyoaCollection_oaModModuleInstHeader_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModModuleInstHeader_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModModuleInstHeader_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModModuleInstHeader_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModModuleInstHeader_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModModuleInstHeader_oaModule*) ((PyoaCollection_oaModModuleInstHeader_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModModuleInstHeader_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModModuleInstHeader_oaModule_FromoaCollection_oaModModuleInstHeader_oaModule(oaCollection_oaModModuleInstHeader_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModModuleInstHeader_oaModule_Type.tp_alloc(&PyoaCollection_oaModModuleInstHeader_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModModuleInstHeader_oaModuleObject* self = (PyoaCollection_oaModModuleInstHeader_oaModuleObject*)bself;
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
static char oaCollection_oaModModuleInstHeader_oaModule_includes_doc[] = 
"Class: oaCollection_oaModModuleInstHeader_oaModule, Function: includes\n"
"  Paramegers: (oaModModuleInstHeader)\n"
"    Calls: oaBoolean includes(const oaModModuleInstHeader* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModModuleInstHeader,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModModuleInstHeader_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModModuleInstHeader_oaModule data;
    int convert_status=PyoaCollection_oaModModuleInstHeader_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModModuleInstHeader_oaModuleObject* self=(PyoaCollection_oaModModuleInstHeader_oaModuleObject*)ob;

    PyParamoaModModuleInstHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModModuleInstHeader_Convert,&p1)) {
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

static char oaCollection_oaModModuleInstHeader_oaModule_assign_doc[] = 
"Class: oaCollection_oaModModuleInstHeader_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModModuleInstHeader_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModModuleInstHeader_oaModule data;
  int convert_status=PyoaCollection_oaModModuleInstHeader_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModModuleInstHeader_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModModuleInstHeader_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModModuleInstHeader_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModModuleInstHeader_oaModule_includes,METH_VARARGS,oaCollection_oaModModuleInstHeader_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModModuleInstHeader_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModModuleInstHeader_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModModuleInstHeader_oaModule_doc[] = 
"Class: oaCollection_oaModModuleInstHeader_oaModule\n"
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
"  Paramegers: (oaCollection_oaModModuleInstHeader_oaModule)\n"
"    Calls: oaCollection_oaModModuleInstHeader_oaModule(const oaCollection_oaModModuleInstHeader_oaModule& coll)\n"
"    Signature: oaCollection_oaModModuleInstHeader_oaModule||cref-oaCollection_oaModModuleInstHeader_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModModuleInstHeader_oaModule)\n"
"    Calls: (const oaCollection_oaModModuleInstHeader_oaModule&)\n"
"    Signature: oaCollection_oaModModuleInstHeader_oaModule||cref-oaCollection_oaModModuleInstHeader_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModModuleInstHeader_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModModuleInstHeader_oaModule",
    sizeof(PyoaCollection_oaModModuleInstHeader_oaModuleObject),
    0,
    (destructor)oaCollection_oaModModuleInstHeader_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModModuleInstHeader_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModModuleInstHeader_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModModuleInstHeader_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModModuleInstHeader_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModModuleInstHeader_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModModuleInstHeader_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModModuleInstHeader_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModModuleInstHeader_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModModuleInstHeader_oaModule",
           (PyObject*)(&PyoaCollection_oaModModuleInstHeader_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModModuleInstHeader_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModModuleInst_oaModModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModModuleInst_oaModModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject* self = (PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModModuleInst_oaModModuleInstHeader)
    {
        PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModModuleInst_oaModModuleInstHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModModuleInst_oaModModuleInstHeader, Choices are:\n"
        "    (oaCollection_oaModModuleInst_oaModModuleInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_dealloc(PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModModuleInst_oaModModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader value;
    int convert_status=PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[72];
    sprintf(buffer,"<oaCollection_oaModModuleInst_oaModModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader v1;
    PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader v2;
    int convert_status1=PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(PyObject* ob,PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Check(ob)) {
        result->SetData( (oaCollection_oaModModuleInst_oaModModuleInstHeader*) ((PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModModuleInst_oaModModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModModuleInst_oaModModuleInstHeader_FromoaCollection_oaModModuleInst_oaModModuleInstHeader(oaCollection_oaModModuleInst_oaModModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type.tp_alloc(&PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject* self = (PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject*)bself;
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
static char oaCollection_oaModModuleInst_oaModModuleInstHeader_includes_doc[] = 
"Class: oaCollection_oaModModuleInst_oaModModuleInstHeader, Function: includes\n"
"  Paramegers: (oaModModuleInst)\n"
"    Calls: oaBoolean includes(const oaModModuleInst* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModModuleInst,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModModuleInst_oaModModuleInstHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader data;
    int convert_status=PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject* self=(PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject*)ob;

    PyParamoaModModuleInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModModuleInst_Convert,&p1)) {
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

static char oaCollection_oaModModuleInst_oaModModuleInstHeader_assign_doc[] = 
"Class: oaCollection_oaModModuleInst_oaModModuleInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader data;
  int convert_status=PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModModuleInst_oaModModuleInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModModuleInst_oaModModuleInstHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModModuleInst_oaModModuleInstHeader_includes,METH_VARARGS,oaCollection_oaModModuleInst_oaModModuleInstHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_assign,METH_VARARGS,oaCollection_oaModModuleInst_oaModModuleInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModModuleInst_oaModModuleInstHeader_doc[] = 
"Class: oaCollection_oaModModuleInst_oaModModuleInstHeader\n"
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
"  Paramegers: (oaCollection_oaModModuleInst_oaModModuleInstHeader)\n"
"    Calls: oaCollection_oaModModuleInst_oaModModuleInstHeader(const oaCollection_oaModModuleInst_oaModModuleInstHeader& coll)\n"
"    Signature: oaCollection_oaModModuleInst_oaModModuleInstHeader||cref-oaCollection_oaModModuleInst_oaModModuleInstHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModModuleInst_oaModModuleInstHeader)\n"
"    Calls: (const oaCollection_oaModModuleInst_oaModModuleInstHeader&)\n"
"    Signature: oaCollection_oaModModuleInst_oaModModuleInstHeader||cref-oaCollection_oaModModuleInst_oaModModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModModuleInst_oaModModuleInstHeader",
    sizeof(PyoaCollection_oaModModuleInst_oaModModuleInstHeaderObject),
    0,
    (destructor)oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModModuleInst_oaModModuleInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModModuleInst_oaModModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModModuleInst_oaModModuleInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModModuleInst_oaModModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModModuleInst_oaModModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModModuleInst_oaModModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModModuleInst_oaModModuleInstHeader",
           (PyObject*)(&PyoaCollection_oaModModuleInst_oaModModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModModuleInst_oaModModuleInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModNet_oaModBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModNet_oaModBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModNet_oaModBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModNet_oaModBundleNetObject* self = (PyoaCollection_oaModNet_oaModBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModNet_oaModBundleNet)
    {
        PyParamoaCollection_oaModNet_oaModBundleNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModNet_oaModBundleNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModNet_oaModBundleNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModNet_oaModBundleNet, Choices are:\n"
        "    (oaCollection_oaModNet_oaModBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModNet_oaModBundleNet_tp_dealloc(PyoaCollection_oaModNet_oaModBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModNet_oaModBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModNet_oaModBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModNet_oaModBundleNet value;
    int convert_status=PyoaCollection_oaModNet_oaModBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaModNet_oaModBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModNet_oaModBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModNet_oaModBundleNet v1;
    PyParamoaCollection_oaModNet_oaModBundleNet v2;
    int convert_status1=PyoaCollection_oaModNet_oaModBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModNet_oaModBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModNet_oaModBundleNet_Convert(PyObject* ob,PyParamoaCollection_oaModNet_oaModBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModNet_oaModBundleNet_Check(ob)) {
        result->SetData( (oaCollection_oaModNet_oaModBundleNet*) ((PyoaCollection_oaModNet_oaModBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModNet_oaModBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModNet_oaModBundleNet_FromoaCollection_oaModNet_oaModBundleNet(oaCollection_oaModNet_oaModBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModNet_oaModBundleNet_Type.tp_alloc(&PyoaCollection_oaModNet_oaModBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModNet_oaModBundleNetObject* self = (PyoaCollection_oaModNet_oaModBundleNetObject*)bself;
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
static char oaCollection_oaModNet_oaModBundleNet_includes_doc[] = 
"Class: oaCollection_oaModNet_oaModBundleNet, Function: includes\n"
"  Paramegers: (oaModNet)\n"
"    Calls: oaBoolean includes(const oaModNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModNet_oaModBundleNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModNet_oaModBundleNet data;
    int convert_status=PyoaCollection_oaModNet_oaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModNet_oaModBundleNetObject* self=(PyoaCollection_oaModNet_oaModBundleNetObject*)ob;

    PyParamoaModNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModNet_Convert,&p1)) {
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

static char oaCollection_oaModNet_oaModBundleNet_assign_doc[] = 
"Class: oaCollection_oaModNet_oaModBundleNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModNet_oaModBundleNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModNet_oaModBundleNet data;
  int convert_status=PyoaCollection_oaModNet_oaModBundleNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModNet_oaModBundleNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModNet_oaModBundleNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModNet_oaModBundleNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModNet_oaModBundleNet_includes,METH_VARARGS,oaCollection_oaModNet_oaModBundleNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModNet_oaModBundleNet_tp_assign,METH_VARARGS,oaCollection_oaModNet_oaModBundleNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModNet_oaModBundleNet_doc[] = 
"Class: oaCollection_oaModNet_oaModBundleNet\n"
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
"  Paramegers: (oaCollection_oaModNet_oaModBundleNet)\n"
"    Calls: oaCollection_oaModNet_oaModBundleNet(const oaCollection_oaModNet_oaModBundleNet& coll)\n"
"    Signature: oaCollection_oaModNet_oaModBundleNet||cref-oaCollection_oaModNet_oaModBundleNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModNet_oaModBundleNet)\n"
"    Calls: (const oaCollection_oaModNet_oaModBundleNet&)\n"
"    Signature: oaCollection_oaModNet_oaModBundleNet||cref-oaCollection_oaModNet_oaModBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModNet_oaModBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModNet_oaModBundleNet",
    sizeof(PyoaCollection_oaModNet_oaModBundleNetObject),
    0,
    (destructor)oaCollection_oaModNet_oaModBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModNet_oaModBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModNet_oaModBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModNet_oaModBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModNet_oaModBundleNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModNet_oaModBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModNet_oaModBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModNet_oaModBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModNet_oaModBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModNet_oaModBundleNet",
           (PyObject*)(&PyoaCollection_oaModNet_oaModBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModNet_oaModBundleNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModNet_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModNet_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModNet_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModNet_oaModuleObject* self = (PyoaCollection_oaModNet_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModNet_oaModule)
    {
        PyParamoaCollection_oaModNet_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModNet_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModNet_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModNet_oaModule, Choices are:\n"
        "    (oaCollection_oaModNet_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModNet_oaModule_tp_dealloc(PyoaCollection_oaModNet_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModNet_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModNet_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModNet_oaModule value;
    int convert_status=PyoaCollection_oaModNet_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaModNet_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModNet_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModNet_oaModule v1;
    PyParamoaCollection_oaModNet_oaModule v2;
    int convert_status1=PyoaCollection_oaModNet_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModNet_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModNet_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModNet_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModNet_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModNet_oaModule*) ((PyoaCollection_oaModNet_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModNet_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModNet_oaModule_FromoaCollection_oaModNet_oaModule(oaCollection_oaModNet_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModNet_oaModule_Type.tp_alloc(&PyoaCollection_oaModNet_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModNet_oaModuleObject* self = (PyoaCollection_oaModNet_oaModuleObject*)bself;
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
static char oaCollection_oaModNet_oaModule_includes_doc[] = 
"Class: oaCollection_oaModNet_oaModule, Function: includes\n"
"  Paramegers: (oaModNet)\n"
"    Calls: oaBoolean includes(const oaModNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModNet_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModNet_oaModule data;
    int convert_status=PyoaCollection_oaModNet_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModNet_oaModuleObject* self=(PyoaCollection_oaModNet_oaModuleObject*)ob;

    PyParamoaModNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModNet_Convert,&p1)) {
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

static char oaCollection_oaModNet_oaModule_assign_doc[] = 
"Class: oaCollection_oaModNet_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModNet_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModNet_oaModule data;
  int convert_status=PyoaCollection_oaModNet_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModNet_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModNet_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModNet_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModNet_oaModule_includes,METH_VARARGS,oaCollection_oaModNet_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModNet_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModNet_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModNet_oaModule_doc[] = 
"Class: oaCollection_oaModNet_oaModule\n"
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
"  Paramegers: (oaCollection_oaModNet_oaModule)\n"
"    Calls: oaCollection_oaModNet_oaModule(const oaCollection_oaModNet_oaModule& coll)\n"
"    Signature: oaCollection_oaModNet_oaModule||cref-oaCollection_oaModNet_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModNet_oaModule)\n"
"    Calls: (const oaCollection_oaModNet_oaModule&)\n"
"    Signature: oaCollection_oaModNet_oaModule||cref-oaCollection_oaModNet_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModNet_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModNet_oaModule",
    sizeof(PyoaCollection_oaModNet_oaModuleObject),
    0,
    (destructor)oaCollection_oaModNet_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModNet_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModNet_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModNet_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModNet_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModNet_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModNet_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModNet_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModNet_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModNet_oaModule",
           (PyObject*)(&PyoaCollection_oaModNet_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModNet_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModTerm_oaModBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModTerm_oaModBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModTerm_oaModBundleTermObject* self = (PyoaCollection_oaModTerm_oaModBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModTerm_oaModBundleTerm)
    {
        PyParamoaCollection_oaModTerm_oaModBundleTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModTerm_oaModBundleTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModTerm_oaModBundleTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModTerm_oaModBundleTerm, Choices are:\n"
        "    (oaCollection_oaModTerm_oaModBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModTerm_oaModBundleTerm_tp_dealloc(PyoaCollection_oaModTerm_oaModBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModTerm_oaModBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModTerm_oaModBundleTerm value;
    int convert_status=PyoaCollection_oaModTerm_oaModBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaModTerm_oaModBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModTerm_oaModBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModTerm_oaModBundleTerm v1;
    PyParamoaCollection_oaModTerm_oaModBundleTerm v2;
    int convert_status1=PyoaCollection_oaModTerm_oaModBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModTerm_oaModBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModTerm_oaModBundleTerm_Convert(PyObject* ob,PyParamoaCollection_oaModTerm_oaModBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModTerm_oaModBundleTerm_Check(ob)) {
        result->SetData( (oaCollection_oaModTerm_oaModBundleTerm*) ((PyoaCollection_oaModTerm_oaModBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModTerm_oaModBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModTerm_oaModBundleTerm_FromoaCollection_oaModTerm_oaModBundleTerm(oaCollection_oaModTerm_oaModBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModTerm_oaModBundleTerm_Type.tp_alloc(&PyoaCollection_oaModTerm_oaModBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModTerm_oaModBundleTermObject* self = (PyoaCollection_oaModTerm_oaModBundleTermObject*)bself;
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
static char oaCollection_oaModTerm_oaModBundleTerm_includes_doc[] = 
"Class: oaCollection_oaModTerm_oaModBundleTerm, Function: includes\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: oaBoolean includes(const oaModTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModBundleTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModTerm_oaModBundleTerm data;
    int convert_status=PyoaCollection_oaModTerm_oaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModTerm_oaModBundleTermObject* self=(PyoaCollection_oaModTerm_oaModBundleTermObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
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

static char oaCollection_oaModTerm_oaModBundleTerm_assign_doc[] = 
"Class: oaCollection_oaModTerm_oaModBundleTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModBundleTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModTerm_oaModBundleTerm data;
  int convert_status=PyoaCollection_oaModTerm_oaModBundleTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModTerm_oaModBundleTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModTerm_oaModBundleTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModTerm_oaModBundleTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModTerm_oaModBundleTerm_includes,METH_VARARGS,oaCollection_oaModTerm_oaModBundleTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModTerm_oaModBundleTerm_tp_assign,METH_VARARGS,oaCollection_oaModTerm_oaModBundleTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModTerm_oaModBundleTerm_doc[] = 
"Class: oaCollection_oaModTerm_oaModBundleTerm\n"
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
"  Paramegers: (oaCollection_oaModTerm_oaModBundleTerm)\n"
"    Calls: oaCollection_oaModTerm_oaModBundleTerm(const oaCollection_oaModTerm_oaModBundleTerm& coll)\n"
"    Signature: oaCollection_oaModTerm_oaModBundleTerm||cref-oaCollection_oaModTerm_oaModBundleTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModTerm_oaModBundleTerm)\n"
"    Calls: (const oaCollection_oaModTerm_oaModBundleTerm&)\n"
"    Signature: oaCollection_oaModTerm_oaModBundleTerm||cref-oaCollection_oaModTerm_oaModBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModTerm_oaModBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModTerm_oaModBundleTerm",
    sizeof(PyoaCollection_oaModTerm_oaModBundleTermObject),
    0,
    (destructor)oaCollection_oaModTerm_oaModBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModTerm_oaModBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModTerm_oaModBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModTerm_oaModBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModTerm_oaModBundleTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModTerm_oaModBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModTerm_oaModBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModTerm_oaModBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModTerm_oaModBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModTerm_oaModBundleTerm",
           (PyObject*)(&PyoaCollection_oaModTerm_oaModBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModTerm_oaModBundleTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModTerm_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModTerm_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModTerm_oaModNetObject* self = (PyoaCollection_oaModTerm_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModTerm_oaModNet)
    {
        PyParamoaCollection_oaModTerm_oaModNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModTerm_oaModNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModTerm_oaModNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModTerm_oaModNet, Choices are:\n"
        "    (oaCollection_oaModTerm_oaModNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModTerm_oaModNet_tp_dealloc(PyoaCollection_oaModTerm_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModTerm_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModTerm_oaModNet value;
    int convert_status=PyoaCollection_oaModTerm_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaModTerm_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModTerm_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModTerm_oaModNet v1;
    PyParamoaCollection_oaModTerm_oaModNet v2;
    int convert_status1=PyoaCollection_oaModTerm_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModTerm_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModTerm_oaModNet_Convert(PyObject* ob,PyParamoaCollection_oaModTerm_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModTerm_oaModNet_Check(ob)) {
        result->SetData( (oaCollection_oaModTerm_oaModNet*) ((PyoaCollection_oaModTerm_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModTerm_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModTerm_oaModNet_FromoaCollection_oaModTerm_oaModNet(oaCollection_oaModTerm_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModTerm_oaModNet_Type.tp_alloc(&PyoaCollection_oaModTerm_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModTerm_oaModNetObject* self = (PyoaCollection_oaModTerm_oaModNetObject*)bself;
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
static char oaCollection_oaModTerm_oaModNet_includes_doc[] = 
"Class: oaCollection_oaModTerm_oaModNet, Function: includes\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: oaBoolean includes(const oaModTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModTerm_oaModNet data;
    int convert_status=PyoaCollection_oaModTerm_oaModNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModTerm_oaModNetObject* self=(PyoaCollection_oaModTerm_oaModNetObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
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

static char oaCollection_oaModTerm_oaModNet_assign_doc[] = 
"Class: oaCollection_oaModTerm_oaModNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModTerm_oaModNet data;
  int convert_status=PyoaCollection_oaModTerm_oaModNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModTerm_oaModNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModTerm_oaModNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModTerm_oaModNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModTerm_oaModNet_includes,METH_VARARGS,oaCollection_oaModTerm_oaModNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModTerm_oaModNet_tp_assign,METH_VARARGS,oaCollection_oaModTerm_oaModNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModTerm_oaModNet_doc[] = 
"Class: oaCollection_oaModTerm_oaModNet\n"
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
"  Paramegers: (oaCollection_oaModTerm_oaModNet)\n"
"    Calls: oaCollection_oaModTerm_oaModNet(const oaCollection_oaModTerm_oaModNet& coll)\n"
"    Signature: oaCollection_oaModTerm_oaModNet||cref-oaCollection_oaModTerm_oaModNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModTerm_oaModNet)\n"
"    Calls: (const oaCollection_oaModTerm_oaModNet&)\n"
"    Signature: oaCollection_oaModTerm_oaModNet||cref-oaCollection_oaModTerm_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModTerm_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModTerm_oaModNet",
    sizeof(PyoaCollection_oaModTerm_oaModNetObject),
    0,
    (destructor)oaCollection_oaModTerm_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModTerm_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModTerm_oaModNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModTerm_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModTerm_oaModNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModTerm_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModTerm_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModTerm_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModTerm_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModTerm_oaModNet",
           (PyObject*)(&PyoaCollection_oaModTerm_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModTerm_oaModNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModTerm_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModTerm_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModTerm_oaModuleObject* self = (PyoaCollection_oaModTerm_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModTerm_oaModule)
    {
        PyParamoaCollection_oaModTerm_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModTerm_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModTerm_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModTerm_oaModule, Choices are:\n"
        "    (oaCollection_oaModTerm_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModTerm_oaModule_tp_dealloc(PyoaCollection_oaModTerm_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModTerm_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModTerm_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModTerm_oaModule value;
    int convert_status=PyoaCollection_oaModTerm_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaModTerm_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModTerm_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModTerm_oaModule v1;
    PyParamoaCollection_oaModTerm_oaModule v2;
    int convert_status1=PyoaCollection_oaModTerm_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModTerm_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModTerm_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModTerm_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModTerm_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModTerm_oaModule*) ((PyoaCollection_oaModTerm_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModTerm_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModTerm_oaModule_FromoaCollection_oaModTerm_oaModule(oaCollection_oaModTerm_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModTerm_oaModule_Type.tp_alloc(&PyoaCollection_oaModTerm_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModTerm_oaModuleObject* self = (PyoaCollection_oaModTerm_oaModuleObject*)bself;
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
static char oaCollection_oaModTerm_oaModule_includes_doc[] = 
"Class: oaCollection_oaModTerm_oaModule, Function: includes\n"
"  Paramegers: (oaModTerm)\n"
"    Calls: oaBoolean includes(const oaModTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModTerm_oaModule data;
    int convert_status=PyoaCollection_oaModTerm_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModTerm_oaModuleObject* self=(PyoaCollection_oaModTerm_oaModuleObject*)ob;

    PyParamoaModTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModTerm_Convert,&p1)) {
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

static char oaCollection_oaModTerm_oaModule_assign_doc[] = 
"Class: oaCollection_oaModTerm_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModTerm_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModTerm_oaModule data;
  int convert_status=PyoaCollection_oaModTerm_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModTerm_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModTerm_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModTerm_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModTerm_oaModule_includes,METH_VARARGS,oaCollection_oaModTerm_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModTerm_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModTerm_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModTerm_oaModule_doc[] = 
"Class: oaCollection_oaModTerm_oaModule\n"
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
"  Paramegers: (oaCollection_oaModTerm_oaModule)\n"
"    Calls: oaCollection_oaModTerm_oaModule(const oaCollection_oaModTerm_oaModule& coll)\n"
"    Signature: oaCollection_oaModTerm_oaModule||cref-oaCollection_oaModTerm_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModTerm_oaModule)\n"
"    Calls: (const oaCollection_oaModTerm_oaModule&)\n"
"    Signature: oaCollection_oaModTerm_oaModule||cref-oaCollection_oaModTerm_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModTerm_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModTerm_oaModule",
    sizeof(PyoaCollection_oaModTerm_oaModuleObject),
    0,
    (destructor)oaCollection_oaModTerm_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModTerm_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModTerm_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModTerm_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModTerm_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModTerm_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModTerm_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModTerm_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModTerm_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModTerm_oaModule",
           (PyObject*)(&PyoaCollection_oaModTerm_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModTerm_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModVectorInstDef_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModVectorInstDef_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModVectorInstDef_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModVectorInstDef_oaModuleObject* self = (PyoaCollection_oaModVectorInstDef_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModVectorInstDef_oaModule)
    {
        PyParamoaCollection_oaModVectorInstDef_oaModule p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModVectorInstDef_oaModule_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModVectorInstDef_oaModule(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModVectorInstDef_oaModule, Choices are:\n"
        "    (oaCollection_oaModVectorInstDef_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModVectorInstDef_oaModule_tp_dealloc(PyoaCollection_oaModVectorInstDef_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModVectorInstDef_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModVectorInstDef_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModVectorInstDef_oaModule value;
    int convert_status=PyoaCollection_oaModVectorInstDef_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaModVectorInstDef_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModVectorInstDef_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModVectorInstDef_oaModule v1;
    PyParamoaCollection_oaModVectorInstDef_oaModule v2;
    int convert_status1=PyoaCollection_oaModVectorInstDef_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModVectorInstDef_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModVectorInstDef_oaModule_Convert(PyObject* ob,PyParamoaCollection_oaModVectorInstDef_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModVectorInstDef_oaModule_Check(ob)) {
        result->SetData( (oaCollection_oaModVectorInstDef_oaModule*) ((PyoaCollection_oaModVectorInstDef_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModVectorInstDef_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModVectorInstDef_oaModule_FromoaCollection_oaModVectorInstDef_oaModule(oaCollection_oaModVectorInstDef_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModVectorInstDef_oaModule_Type.tp_alloc(&PyoaCollection_oaModVectorInstDef_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModVectorInstDef_oaModuleObject* self = (PyoaCollection_oaModVectorInstDef_oaModuleObject*)bself;
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
static char oaCollection_oaModVectorInstDef_oaModule_includes_doc[] = 
"Class: oaCollection_oaModVectorInstDef_oaModule, Function: includes\n"
"  Paramegers: (oaModVectorInstDef)\n"
"    Calls: oaBoolean includes(const oaModVectorInstDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModVectorInstDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModVectorInstDef_oaModule_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModVectorInstDef_oaModule data;
    int convert_status=PyoaCollection_oaModVectorInstDef_oaModule_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModVectorInstDef_oaModuleObject* self=(PyoaCollection_oaModVectorInstDef_oaModuleObject*)ob;

    PyParamoaModVectorInstDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModVectorInstDef_Convert,&p1)) {
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

static char oaCollection_oaModVectorInstDef_oaModule_assign_doc[] = 
"Class: oaCollection_oaModVectorInstDef_oaModule, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModVectorInstDef_oaModule_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModVectorInstDef_oaModule data;
  int convert_status=PyoaCollection_oaModVectorInstDef_oaModule_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModVectorInstDef_oaModule p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModVectorInstDef_oaModule_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModVectorInstDef_oaModule_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModVectorInstDef_oaModule_includes,METH_VARARGS,oaCollection_oaModVectorInstDef_oaModule_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModVectorInstDef_oaModule_tp_assign,METH_VARARGS,oaCollection_oaModVectorInstDef_oaModule_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModVectorInstDef_oaModule_doc[] = 
"Class: oaCollection_oaModVectorInstDef_oaModule\n"
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
"  Paramegers: (oaCollection_oaModVectorInstDef_oaModule)\n"
"    Calls: oaCollection_oaModVectorInstDef_oaModule(const oaCollection_oaModVectorInstDef_oaModule& coll)\n"
"    Signature: oaCollection_oaModVectorInstDef_oaModule||cref-oaCollection_oaModVectorInstDef_oaModule,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModVectorInstDef_oaModule)\n"
"    Calls: (const oaCollection_oaModVectorInstDef_oaModule&)\n"
"    Signature: oaCollection_oaModVectorInstDef_oaModule||cref-oaCollection_oaModVectorInstDef_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModVectorInstDef_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModVectorInstDef_oaModule",
    sizeof(PyoaCollection_oaModVectorInstDef_oaModuleObject),
    0,
    (destructor)oaCollection_oaModVectorInstDef_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModVectorInstDef_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModVectorInstDef_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModVectorInstDef_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModVectorInstDef_oaModule_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModVectorInstDef_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModVectorInstDef_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModVectorInstDef_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModVectorInstDef_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModVectorInstDef_oaModule",
           (PyObject*)(&PyoaCollection_oaModVectorInstDef_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModVectorInstDef_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaModule_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModule_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaModule_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaModule_oaDesignObject* self = (PyoaCollection_oaModule_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaModule_oaDesign)
    {
        PyParamoaCollection_oaModule_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaModule_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaModule_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaModule_oaDesign, Choices are:\n"
        "    (oaCollection_oaModule_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaModule_oaDesign_tp_dealloc(PyoaCollection_oaModule_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaModule_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaModule_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaModule_oaDesign value;
    int convert_status=PyoaCollection_oaModule_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaModule_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaModule_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaModule_oaDesign v1;
    PyParamoaCollection_oaModule_oaDesign v2;
    int convert_status1=PyoaCollection_oaModule_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaModule_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaModule_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaModule_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaModule_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaModule_oaDesign*) ((PyoaCollection_oaModule_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaModule_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaModule_oaDesign_FromoaCollection_oaModule_oaDesign(oaCollection_oaModule_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaModule_oaDesign_Type.tp_alloc(&PyoaCollection_oaModule_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaModule_oaDesignObject* self = (PyoaCollection_oaModule_oaDesignObject*)bself;
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
static char oaCollection_oaModule_oaDesign_includes_doc[] = 
"Class: oaCollection_oaModule_oaDesign, Function: includes\n"
"  Paramegers: (oaModule)\n"
"    Calls: oaBoolean includes(const oaModule* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaModule,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaModule_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaModule_oaDesign data;
    int convert_status=PyoaCollection_oaModule_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaModule_oaDesignObject* self=(PyoaCollection_oaModule_oaDesignObject*)ob;

    PyParamoaModule p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModule_Convert,&p1)) {
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

static char oaCollection_oaModule_oaDesign_assign_doc[] = 
"Class: oaCollection_oaModule_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaModule_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaModule_oaDesign data;
  int convert_status=PyoaCollection_oaModule_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaModule_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaModule_oaDesign_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaModule_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaModule_oaDesign_includes,METH_VARARGS,oaCollection_oaModule_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaModule_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaModule_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaModule_oaDesign_doc[] = 
"Class: oaCollection_oaModule_oaDesign\n"
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
"  Paramegers: (oaCollection_oaModule_oaDesign)\n"
"    Calls: oaCollection_oaModule_oaDesign(const oaCollection_oaModule_oaDesign& coll)\n"
"    Signature: oaCollection_oaModule_oaDesign||cref-oaCollection_oaModule_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaModule_oaDesign)\n"
"    Calls: (const oaCollection_oaModule_oaDesign&)\n"
"    Signature: oaCollection_oaModule_oaDesign||cref-oaCollection_oaModule_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaModule_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaModule_oaDesign",
    sizeof(PyoaCollection_oaModule_oaDesignObject),
    0,
    (destructor)oaCollection_oaModule_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaModule_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaModule_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaModule_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaModule_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaModule_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaModule_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaModule_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaModule_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaModule_oaDesign",
           (PyObject*)(&PyoaCollection_oaModule_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaModule_oaDesign\n");
       return -1;
    }
    return 0;
}

