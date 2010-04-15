
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaViewModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaViewModTypeEnum_Convert(PyObject* ob,PyParamoaViewModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaViewModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaViewModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaViewModTypeEnum_FromoaViewModTypeEnum(oaViewModTypeEnum ob)
{

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaViewModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaViewModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaViewModTypeEnum_FromoaViewModTypeEnum(oaViewModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaViewModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaViewModTypeEnum_doc[] =
"Type convert function for enum: oaViewModTypeEnum";
                               
static PyMethodDef PyoaViewModTypeEnum_method =
  {"oaViewModTypeEnum",(PyCFunction)PyoaViewModTypeEnum_TypeFunction,METH_VARARGS,oaViewModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaViewModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaViewModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaViewModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaViewModTypeEnum\n");
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
// Wrapper Implementation for Class: oaViewType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaViewType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaViewType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaViewTypeObject* self = (PyoaViewTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaViewType)
    {
        PyParamoaViewType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaViewType_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaViewType, Choices are:\n"
        "    (oaViewType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaViewType_tp_dealloc(PyoaViewTypeObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaViewType_tp_repr(PyObject *ob)
{
    PyParamoaViewType value;
    int convert_status=PyoaViewType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaViewType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaViewType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaViewType v1;
    PyParamoaViewType v2;
    int convert_status1=PyoaViewType_Convert(ob1,&v1);
    int convert_status2=PyoaViewType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaViewType_Convert(PyObject* ob,PyParamoaViewType* result)
{
    if (ob == NULL) return 1;
    if (PyoaViewType_Check(ob)) {
        result->SetData( (oaViewType**) ((PyoaViewTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaViewType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaViewType_FromoaViewType(oaViewType** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaViewType* data=*value;
        PyObject* bself = PyoaViewType_Type.tp_alloc(&PyoaViewType_Type,0);
        if (bself == NULL) return bself;
        PyoaViewTypeObject* self = (PyoaViewTypeObject*)bself;
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
PyObject* PyoaViewType_FromoaViewType(oaViewType* data)
{
    if (data) {
       PyObject* bself = PyoaViewType_Type.tp_alloc(&PyoaViewType_Type,0);
       if (bself == NULL) return bself;
       PyoaViewTypeObject* self = (PyoaViewTypeObject*)bself;
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
static char oaViewType_getName_doc[] = 
"Class: oaViewType, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the string name of this viewType.\n"
"    name\n"
"    returned name of this viewType\n"
;

static PyObject*
oaViewType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaViewType data;
    int convert_status=PyoaViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaViewTypeObject* self=(PyoaViewTypeObject*)ob;
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
static char oaViewType_isNull_doc[] =
"Class: oaViewType, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaViewType_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaViewType data;
    int convert_status=PyoaViewType_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaViewType_assign_doc[] = 
"Class: oaViewType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaViewType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaViewType data;
  int convert_status=PyoaViewType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaViewType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaViewType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaViewType_methodlist[] = {
    {"getName",(PyCFunction)oaViewType_getName,METH_VARARGS,oaViewType_getName_doc},
    {"isNull",(PyCFunction)oaViewType_tp_isNull,METH_VARARGS,oaViewType_isNull_doc},
    {"assign",(PyCFunction)oaViewType_tp_assign,METH_VARARGS,oaViewType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaViewType_doc[] = 
"Class: oaViewType\n"
"  This session object represents the type of a view. See oaReservedViewType for predefined OpenAccess viewTypes.\n"
"  The oaViewType class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaViewType)\n"
"    Calls: (const oaViewType&)\n"
"    Signature: oaViewType||cref-oaViewType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaViewType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaViewType",
    sizeof(PyoaViewTypeObject),
    0,
    (destructor)oaViewType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaViewType_tp_compare,	/* tp_compare */
    (reprfunc)oaViewType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaViewType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaViewType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaViewType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaViewType_static_create_doc[] = 
"Class: oaViewType, Function: create\n"
"  Paramegers: (oaString)\n"
"    Calls: oaViewType* create(const oaString& name)\n"
"    Signature: create|ptr-oaViewType|cref-oaString,\n"
"    This function creates a viewType with the specified name . An exception is thrown if the viewType already exists.\n"
"    name\n"
"    the name of the viewType to create\n"
"    oacViewTypeExists\n"
;

static PyObject*
oaViewType_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaViewTypep result= (oaViewType::create(p1.Data()));
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
static char oaViewType_static_find_doc[] = 
"Class: oaViewType, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaViewType* find(const oaString& name)\n"
"    Signature: find|ptr-oaViewType|cref-oaString,\n"
"    This function attempts to find the viewType with the specified name . If not found, NULL is returned.\n"
"    name\n"
"    the name of the viewType to find\n"
;

static PyObject*
oaViewType_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaViewTypep result= (oaViewType::find(p1.Data()));
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
static char oaViewType_static_get_doc[] = 
"Class: oaViewType, Function: get\n"
"  Paramegers: (oaReservedViewType)\n"
"    Calls: oaViewType* get(oaReservedViewType type)\n"
"    Signature: get|ptr-oaViewType|simple-oaReservedViewType,\n"
"    oaViewType::get This function gets a pointer to a viewType that corresponds to the specified type oaReservedViewType .\n"
"    type\n"
"    an oaReservedViewType wrapper object\n"
;

static PyObject*
oaViewType_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReservedViewType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaReservedViewType_Convert,&p1)) {
        oaViewTypep result= (oaViewType::get(p1.Data()));
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
static char oaViewType_static_getViewTypes_doc[] = 
"Class: oaViewType, Function: getViewTypes\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaViewType_oaSession getViewTypes()\n"
"    Signature: getViewTypes|simple-oaCollection_oaViewType_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns a collection of viewTypes in this session.\n"
;

static PyObject*
oaViewType_static_getViewTypes(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaViewType_oaSession* result= new oaCollection_oaViewType_oaSession(oaViewType::getViewTypes());
        return PyoaCollection_oaViewType_oaSession_FromoaCollection_oaViewType_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaViewType_static_getViewTypesIter_doc[] = 
"Class: oaViewType, Function: getViewTypesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaViewType getViewTypesIter()\n"
"    Signature: getViewTypesIter|simple-oaIter_oaViewType|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of viewTypes in this session.\n"
;

static PyObject*
oaViewType_static_getViewTypesIter(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaViewType* result= new oaIter_oaViewType(oaViewType::getViewTypes());
        return PyoaIter_oaViewType_FromoaIter_oaViewType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaViewType_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaViewType_static_create,METH_VARARGS,oaViewType_static_create_doc},
    {"static_find",(PyCFunction)oaViewType_static_find,METH_VARARGS,oaViewType_static_find_doc},
    {"static_get",(PyCFunction)oaViewType_static_get,METH_VARARGS,oaViewType_static_get_doc},
    {"static_getViewTypes",(PyCFunction)oaViewType_static_getViewTypes,METH_VARARGS,oaViewType_static_getViewTypes_doc},
    {"static_getViewTypesIter",(PyCFunction)oaViewType_static_getViewTypesIter,METH_VARARGS,oaViewType_static_getViewTypesIter_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaViewType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaViewType_Type)<0) {
      printf("** PyType_Ready failed for: oaViewType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaViewType",
           (PyObject*)(&PyoaViewType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaViewType\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaViewType_Type.tp_dict;
    for(method=oaViewType_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferObject* self = (PyoaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWafer)
    {
        PyParamoaWafer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWafer_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaWafer, Choices are:\n"
        "    (oaWafer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWafer_tp_dealloc(PyoaWaferObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaWafer value;
    int convert_status=PyoaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWafer v1;
    PyParamoaWafer v2;
    int convert_status1=PyoaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWafer_Convert(PyObject* ob,PyParamoaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaWafer_Check(ob)) {
        result->SetData( (oaWafer**) ((PyoaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWafer_FromoaWafer(oaWafer** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaWafer* data=*value;
        PyObject* bself = PyoaWafer_Type.tp_alloc(&PyoaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferObject* self = (PyoaWaferObject*)bself;
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
PyObject* PyoaWafer_FromoaWafer(oaWafer* data)
{
    if (data) {
       PyObject* bself = PyoaWafer_Type.tp_alloc(&PyoaWafer_Type,0);
       if (bself == NULL) return bself;
       PyoaWaferObject* self = (PyoaWaferObject*)bself;
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
static char oaWafer_calcVMSize_doc[] = 
"Class: oaWafer, Function: calcVMSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 calcVMSize() const\n"
"    Signature: calcVMSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function calculates and returns the amount of virtual memory this wafer is currently using.\n"
;

static PyObject*
oaWafer_calcVMSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->calcVMSize());
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
static char oaWafer_close_doc[] = 
"Class: oaWafer, Function: close\n"
"  Paramegers: ()\n"
"    Calls: void close()\n"
"    Signature: close|void-void|\n"
"    BrowseData: 0\n"
"    This function decrements the reference count of this wafer by one. If the count goes to zero, the wafer is purged from memory. If the wafer has never been saved, the last close that purges the wafer will also remove the database file, view directory, and cell directory if that cell was empty.\n"
;

static PyObject*
oaWafer_close(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_enableUndo_doc[] = 
"Class: oaWafer, Function: enableUndo\n"
"  Paramegers: ()\n"
"    Calls: void enableUndo()\n"
"    Signature: enableUndo|void-void|simple-oaBoolean,\n"
"    BrowseData: 0\n"
"    This function enables or disables undo functionality for this wafer. If enabled, all changes made to this wafer are logged so that undo() can restore the wafer to earlier states. If disabled, all undo information is discarded and changes are not logged.\n"
"    value\n"
"    Specifies whether to enable or disable undo\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void enableUndo(oaBoolean value)\n"
"    Signature: enableUndo|void-void|simple-oaBoolean,\n"
"    This function enables or disables undo functionality for this wafer. If enabled, all changes made to this wafer are logged so that undo() can restore the wafer to earlier states. If disabled, all undo information is discarded and changes are not logged.\n"
"    value\n"
"    Specifies whether to enable or disable undo\n"
;

static PyObject*
oaWafer_enableUndo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            data.DataCall()->enableUndo();
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            data.DataCall()->enableUndo(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaWafer, function: enableUndo, Choices are:\n"
        "    ()\n"
        "    (oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getCellName_doc[] = 
"Class: oaWafer, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of the cell associated with this wafer in the form of an oaScalarName .\n"
"    cellName\n"
"    The name of the cell is returned in cellName\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellStr) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of the cell associated with this wafer in the nameSpace specified.\n"
"    ns\n"
"    The nameSpace used to get the cell name string\n"
"    cellStr\n"
"    The name string of the cell is returned in cellStr\n"
;

static PyObject*
oaWafer_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
        "No Arg-Matching Function found for class: oaWafer, function: getCellName, Choices are:\n"
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
static char oaWafer_getCreateTime_doc[] = 
"Class: oaWafer, Function: getCreateTime\n"
"  Paramegers: ()\n"
"    Calls: oaTime getCreateTime() const\n"
"    Signature: getCreateTime|simple-oaTime|\n"
"    BrowseData: 1\n"
"    This function returns the time at which this wafer database was created.\n"
;

static PyObject*
oaWafer_getCreateTime(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaTime result= (data.DataCall()->getCreateTime());
        return PyoaTime_FromoaTime(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getDBUPerWU_doc[] = 
"Class: oaWafer, Function: getDBUPerWU\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getDBUPerWU() const\n"
"    Signature: getDBUPerWU|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of database units per waferUnit currently set for this wafer.\n"
;

static PyObject*
oaWafer_getDBUPerWU(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getDBUPerWU());
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
static char oaWafer_getFrames_doc[] = 
"Class: oaWafer, Function: getFrames\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaFrame_oaWafer getFrames() const\n"
"    Signature: getFrames|simple-oaCollection_oaFrame_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns the collection of frames in this wafer.\n"
;

static PyObject*
oaWafer_getFrames(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaFrame_oaWafer* result= new oaCollection_oaFrame_oaWafer(data.DataCall()->getFrames());
        return PyoaCollection_oaFrame_oaWafer_FromoaCollection_oaFrame_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getFramesIter_doc[] = 
"Class: oaWafer, Function: getFramesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaFrame getFramesIter() const\n"
"    Signature: getFramesIter|simple-oaIter_oaFrame|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of frames in this wafer.\n"
;

static PyObject*
oaWafer_getFramesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaFrame* result= new oaIter_oaFrame(data.DataCall()->getFrames());
        return PyoaIter_oaFrame_FromoaIter_oaFrame(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getImages_doc[] = 
"Class: oaWafer, Function: getImages\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaImage_oaWafer getImages() const\n"
"    Signature: getImages|simple-oaCollection_oaImage_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns the collection of images in this wafer.\n"
;

static PyObject*
oaWafer_getImages(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaImage_oaWafer* result= new oaCollection_oaImage_oaWafer(data.DataCall()->getImages());
        return PyoaCollection_oaImage_oaWafer_FromoaCollection_oaImage_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getImagesIter_doc[] = 
"Class: oaWafer, Function: getImagesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaImage getImagesIter() const\n"
"    Signature: getImagesIter|simple-oaIter_oaImage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of images in this wafer.\n"
;

static PyObject*
oaWafer_getImagesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaImage* result= new oaIter_oaImage(data.DataCall()->getImages());
        return PyoaIter_oaImage_FromoaIter_oaImage(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getLastSavedTime_doc[] = 
"Class: oaWafer, Function: getLastSavedTime\n"
"  Paramegers: ()\n"
"    Calls: oaTime getLastSavedTime() const\n"
"    Signature: getLastSavedTime|simple-oaTime|\n"
"    BrowseData: 1\n"
"    This function returns the time at which this wafer was last saved.\n"
;

static PyObject*
oaWafer_getLastSavedTime(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaTime result= (data.DataCall()->getLastSavedTime());
        return PyoaTime_FromoaTime(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getLibName_doc[] = 
"Class: oaWafer, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of the library associated with this wafer in the form of an oaScalarName .\n"
"    libName\n"
"    The name of the library is returned in libName\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libStr) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of the library associated with this wafer in the nameSpace specified.\n"
"    ns\n"
"    The nameSpace used to get the library name string\n"
"    libStr\n"
"    The name string of the library is returned in libStr\n"
;

static PyObject*
oaWafer_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
        "No Arg-Matching Function found for class: oaWafer, function: getLibName, Choices are:\n"
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
static char oaWafer_getMode_doc[] = 
"Class: oaWafer, Function: getMode\n"
"  Paramegers: ()\n"
"    Calls: oaChar getMode() const\n"
"    Signature: getMode|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the mode in which this wafer is currently opened.\n"
;

static PyObject*
oaWafer_getMode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_getReadInTime_doc[] = 
"Class: oaWafer, Function: getReadInTime\n"
"  Paramegers: ()\n"
"    Calls: oaTime getReadInTime() const\n"
"    Signature: getReadInTime|simple-oaTime|\n"
"    BrowseData: 1\n"
"    This function returns the time at which this wafer was read in from disk.\n"
;

static PyObject*
oaWafer_getReadInTime(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaTime result= (data.DataCall()->getReadInTime());
        return PyoaTime_FromoaTime(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getRefCount_doc[] = 
"Class: oaWafer, Function: getRefCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRefCount() const\n"
"    Signature: getRefCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of times this wafer is opened without being closed. This includes both internal and external opens.\n"
;

static PyObject*
oaWafer_getRefCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_getReticleRefs_doc[] = 
"Class: oaWafer, Function: getReticleRefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaReticleRef_oaWafer getReticleRefs() const\n"
"    Signature: getReticleRefs|simple-oaCollection_oaReticleRef_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns a collection of reticle references in this wafer.\n"
;

static PyObject*
oaWafer_getReticleRefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaReticleRef_oaWafer* result= new oaCollection_oaReticleRef_oaWafer(data.DataCall()->getReticleRefs());
        return PyoaCollection_oaReticleRef_oaWafer_FromoaCollection_oaReticleRef_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getReticleRefsIter_doc[] = 
"Class: oaWafer, Function: getReticleRefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaReticleRef getReticleRefsIter() const\n"
"    Signature: getReticleRefsIter|simple-oaIter_oaReticleRef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of reticle references in this wafer.\n"
;

static PyObject*
oaWafer_getReticleRefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaReticleRef* result= new oaIter_oaReticleRef(data.DataCall()->getReticleRefs());
        return PyoaIter_oaReticleRef_FromoaIter_oaReticleRef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getReticles_doc[] = 
"Class: oaWafer, Function: getReticles\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaReticle_oaWafer getReticles() const\n"
"    Signature: getReticles|simple-oaCollection_oaReticle_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns a collection of reticles in this wafer.\n"
;

static PyObject*
oaWafer_getReticles(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaReticle_oaWafer* result= new oaCollection_oaReticle_oaWafer(data.DataCall()->getReticles());
        return PyoaCollection_oaReticle_oaWafer_FromoaCollection_oaReticle_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getReticlesIter_doc[] = 
"Class: oaWafer, Function: getReticlesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaReticle getReticlesIter() const\n"
"    Signature: getReticlesIter|simple-oaIter_oaReticle|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of reticles in this wafer.\n"
;

static PyObject*
oaWafer_getReticlesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaReticle* result= new oaIter_oaReticle(data.DataCall()->getReticles());
        return PyoaIter_oaReticle_FromoaIter_oaReticle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getTimeStamp_doc[] = 
"Class: oaWafer, Function: getTimeStamp\n"
"  Paramegers: (oaWaferDataType)\n"
"    Calls: oaTimeStamp getTimeStamp(oaWaferDataType type) const\n"
"    Signature: getTimeStamp|simple-oaTimeStamp|simple-oaWaferDataType,\n"
"    This function returns the timeStamp value for the specified wafer datatype.\n"
"    type\n"
"    The wafer datatype to check\n"
"  Paramegers: (oaAppObjectDef)\n"
"    Calls: oaTimeStamp getTimeStamp(oaAppObjectDef* def) const\n"
"    Signature: getTimeStamp|simple-oaTimeStamp|ptr-oaAppObjectDef,\n"
"    This function returns the timeStamp value for the specified application object.\n"
"    def\n"
"    The application object to check\n"
;

static PyObject*
oaWafer_getTimeStamp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaWaferDataType)
    {
        PyParamoaWaferDataType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWaferDataType_Convert,&p1)) {
            oaTimeStamp* result= new oaTimeStamp(data.DataCall()->getTimeStamp(p1.Data()));
            return PyoaTimeStamp_FromoaTimeStamp(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaAppObjectDef)
    {
        PyParamoaAppObjectDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAppObjectDef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaTimeStamp* result= new oaTimeStamp(data.DataCall()->getTimeStamp(p1.Data()));
            return PyoaTimeStamp_FromoaTimeStamp(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaWafer, function: getTimeStamp, Choices are:\n"
        "    (oaWaferDataType)\n"
        "    (oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getViewName_doc[] = 
"Class: oaWafer, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of the view associated with this wafer in the form of an oaScalarName .\n"
"    viewName\n"
"    The name of the view is returned in viewName\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewStr) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of the view associated with this wafer in the nameSpace specified.\n"
"    ns\n"
"    The nameSpace used to get the view name string\n"
"    viewStr\n"
"    The name string of the view is returned in viewStr\n"
;

static PyObject*
oaWafer_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
        "No Arg-Matching Function found for class: oaWafer, function: getViewName, Choices are:\n"
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
static char oaWafer_getWaferDesc_doc[] = 
"Class: oaWafer, Function: getWaferDesc\n"
"  Paramegers: ()\n"
"    Calls: oaWaferDesc* getWaferDesc() const\n"
"    Signature: getWaferDesc|ptr-oaWaferDesc|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the wafer description associated with this wafer. NULL is returned if no wafer description has been created yet.\n"
;

static PyObject*
oaWafer_getWaferDesc(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferDescp result= (data.DataCall()->getWaferDesc());
        return PyoaWaferDesc_FromoaWaferDesc(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_getWaferUnits_doc[] = 
"Class: oaWafer, Function: getWaferUnits\n"
"  Paramegers: ()\n"
"    Calls: oaWaferUnitsType getWaferUnits() const\n"
"    Signature: getWaferUnits|simple-oaWaferUnitsType|\n"
"    BrowseData: 1\n"
"    This function returns the wafer-unit information for this wafer.\n"
;

static PyObject*
oaWafer_getWaferUnits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferUnitsType* result= new oaWaferUnitsType(data.DataCall()->getWaferUnits());
        return PyoaWaferUnitsType_FromoaWaferUnitsType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_isModified_doc[] = 
"Class: oaWafer, Function: isModified\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isModified() const\n"
"    Signature: isModified|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this wafer has been modified but not saved.\n"
;

static PyObject*
oaWafer_isModified(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_isUndoEnabled_doc[] = 
"Class: oaWafer, Function: isUndoEnabled\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isUndoEnabled() const\n"
"    Signature: isUndoEnabled|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether undo is enabled for this wafer.\n"
;

static PyObject*
oaWafer_isUndoEnabled(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isUndoEnabled());
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
static char oaWafer_purge_doc[] = 
"Class: oaWafer, Function: purge\n"
"  Paramegers: ()\n"
"    Calls: void purge()\n"
"    Signature: purge|void-void|\n"
"    BrowseData: 0\n"
"    This function closes and removes this wafer from memory, regardless of its reference count.\n"
;

static PyObject*
oaWafer_purge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_redo_doc[] = 
"Class: oaWafer, Function: redo\n"
"  Paramegers: ()\n"
"    Calls: void redo()\n"
"    Signature: redo|void-void|\n"
"    BrowseData: 0\n"
"    This function redoes the changes that were most recently undone. This call has an affect only if undo is enabled, undo() is called for this wafer, and there are no changes since the last undo() was performed.\n"
;

static PyObject*
oaWafer_redo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->redo();
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
static char oaWafer_reopen_doc[] = 
"Class: oaWafer, Function: reopen\n"
"  Paramegers: (oaChar)\n"
"    Calls: void reopen(oaChar mode)\n"
"    Signature: reopen|void-void|simple-oaChar,\n"
"    This function attempts to reopen this wafer using the specified access mode. The contents of the wafer may be reset or even truncated depending upon the new access mode. The open mode of this wafer is changed to mode .\n"
"    Note: The refCount of the wafer is not affected.\n"
"    mode\n"
"    The mode to reopen the wafer in\n"
"    'r' for read\n"
"    'w' for write\n"
"    'a' for append\n"
"    'A' for append in override mode, which is not typically used. Refer to Compatibility for OpenAccess Applications and Data in the Programmers Guide for more information.\n"
"    oacInvalidAccessMode\n"
"    oacWaferCannotChangeScratchMode\n"
"    oacWaferBeingPurged\n"
"    oacDataNotCompatibleOnOpenInAppendMode\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened in append mode\n"
"    oacDataNotCompatibleOnOpenInEditableMode\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened in 'a'ppend or 'A'ppend mode\n"
"    oacCannotDowngradeDatabase\n"
"    The database was opened in  A  mode and cannot be reopened in 'a' mode\n"
;

static PyObject*
oaWafer_reopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_revert_doc[] = 
"Class: oaWafer, Function: revert\n"
"  Paramegers: ()\n"
"    Calls: void revert()\n"
"    Signature: revert|void-void|\n"
"    BrowseData: 0\n"
"    This function reloads the contents of this wafer from disk. If the wafer is opened in write mode, it will simply be truncated. Note that the wafer's access mode is not affected.\n"
;

static PyObject*
oaWafer_revert(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_save_doc[] = 
"Class: oaWafer, Function: save\n"
"  Paramegers: ()\n"
"    Calls: void save()\n"
"    Signature: save|void-void|\n"
"    BrowseData: 0\n"
"    This function saves this wafer to disk. The wafer remains open and all of its in-memory data remains valid including its undo data.\n"
"    oacDataNotCompatibleOnSave\n"
"    Design contains incompatible data and cannot be saved\n"
;

static PyObject*
oaWafer_save(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
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
static char oaWafer_saveAs_doc[] = 
"Class: oaWafer, Function: saveAs\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void saveAs(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: saveAs|void-void|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function saves this wafer to disk using the specified library, cell, and view names. The wafer remains open and all of its in-memory data remains valid including its undo data.\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of a cell\n"
"    viewName\n"
"    The name of a view\n"
"    oacWaferLibNotFound\n"
"    oacDataNotCompatibleOnSave\n"
"    Design contains incompatible data and cannot be saved\n"
;

static PyObject*
oaWafer_saveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        data.DataCall()->saveAs(p1.Data(),p2.Data(),p3.Data());
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
static char oaWafer_setCp_doc[] = 
"Class: oaWafer, Function: setCp\n"
"  Paramegers: ()\n"
"    Calls: void setCp()\n"
"    Signature: setCp|void-void|\n"
"    BrowseData: 0\n"
"    This function sets an undo checkpoint for this wafer. Each call to undo() restores the contents of the wafer to its state when undo is enabled or when a call to setCp() is made.\n"
;

static PyObject*
oaWafer_setCp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->setCp();
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
static char oaWafer_setDBUPerWU_doc[] = 
"Class: oaWafer, Function: setDBUPerWU\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setDBUPerWU(oaUInt4 value)\n"
"    Signature: setDBUPerWU|void-void|simple-oaUInt4,\n"
"    This function changes the database units per wafer units for this wafer.\n"
"    value\n"
"    Specifies the number of database units corresponds to one wafer unit.\n"
;

static PyObject*
oaWafer_setDBUPerWU(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setDBUPerWU(p1.Data());
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
static char oaWafer_setWaferUnits_doc[] = 
"Class: oaWafer, Function: setWaferUnits\n"
"  Paramegers: (oaWaferUnitsType)\n"
"    Calls: void setWaferUnits(oaWaferUnitsType value)\n"
"    Signature: setWaferUnits|void-void|simple-oaWaferUnitsType,\n"
"    This function changes the wafer units used for this wafer.\n"
"    value\n"
"    The wafer-unit value to set\n"
;

static PyObject*
oaWafer_setWaferUnits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferUnitsType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWaferUnitsType_Convert,&p1)) {
        data.DataCall()->setWaferUnits(p1.Data());
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
static char oaWafer_undo_doc[] = 
"Class: oaWafer, Function: undo\n"
"  Paramegers: ()\n"
"    Calls: void undo()\n"
"    Signature: undo|void-void|\n"
"    BrowseData: 0\n"
"    This function undoes all changes made to this wafer since the last undo checkpoint was set.\n"
"    Note that only changes to managed objects in the oaWafer are undone. Utility objects that contain pointers to a managed object are not affected.\n"
;

static PyObject*
oaWafer_undo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObject* self=(PyoaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->undo();
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
static char oaWafer_isNull_doc[] =
"Class: oaWafer, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaWafer_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaWafer data;
    int convert_status=PyoaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaWafer_assign_doc[] = 
"Class: oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWafer data;
  int convert_status=PyoaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWafer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWafer_methodlist[] = {
    {"calcVMSize",(PyCFunction)oaWafer_calcVMSize,METH_VARARGS,oaWafer_calcVMSize_doc},
    {"close",(PyCFunction)oaWafer_close,METH_VARARGS,oaWafer_close_doc},
    {"enableUndo",(PyCFunction)oaWafer_enableUndo,METH_VARARGS,oaWafer_enableUndo_doc},
    {"getCellName",(PyCFunction)oaWafer_getCellName,METH_VARARGS,oaWafer_getCellName_doc},
    {"getCreateTime",(PyCFunction)oaWafer_getCreateTime,METH_VARARGS,oaWafer_getCreateTime_doc},
    {"getDBUPerWU",(PyCFunction)oaWafer_getDBUPerWU,METH_VARARGS,oaWafer_getDBUPerWU_doc},
    {"getFrames",(PyCFunction)oaWafer_getFrames,METH_VARARGS,oaWafer_getFrames_doc},
    {"getFramesIter",(PyCFunction)oaWafer_getFramesIter,METH_VARARGS,oaWafer_getFramesIter_doc},
    {"getImages",(PyCFunction)oaWafer_getImages,METH_VARARGS,oaWafer_getImages_doc},
    {"getImagesIter",(PyCFunction)oaWafer_getImagesIter,METH_VARARGS,oaWafer_getImagesIter_doc},
    {"getLastSavedTime",(PyCFunction)oaWafer_getLastSavedTime,METH_VARARGS,oaWafer_getLastSavedTime_doc},
    {"getLibName",(PyCFunction)oaWafer_getLibName,METH_VARARGS,oaWafer_getLibName_doc},
    {"getMode",(PyCFunction)oaWafer_getMode,METH_VARARGS,oaWafer_getMode_doc},
    {"getReadInTime",(PyCFunction)oaWafer_getReadInTime,METH_VARARGS,oaWafer_getReadInTime_doc},
    {"getRefCount",(PyCFunction)oaWafer_getRefCount,METH_VARARGS,oaWafer_getRefCount_doc},
    {"getReticleRefs",(PyCFunction)oaWafer_getReticleRefs,METH_VARARGS,oaWafer_getReticleRefs_doc},
    {"getReticleRefsIter",(PyCFunction)oaWafer_getReticleRefsIter,METH_VARARGS,oaWafer_getReticleRefsIter_doc},
    {"getReticles",(PyCFunction)oaWafer_getReticles,METH_VARARGS,oaWafer_getReticles_doc},
    {"getReticlesIter",(PyCFunction)oaWafer_getReticlesIter,METH_VARARGS,oaWafer_getReticlesIter_doc},
    {"getTimeStamp",(PyCFunction)oaWafer_getTimeStamp,METH_VARARGS,oaWafer_getTimeStamp_doc},
    {"getViewName",(PyCFunction)oaWafer_getViewName,METH_VARARGS,oaWafer_getViewName_doc},
    {"getWaferDesc",(PyCFunction)oaWafer_getWaferDesc,METH_VARARGS,oaWafer_getWaferDesc_doc},
    {"getWaferUnits",(PyCFunction)oaWafer_getWaferUnits,METH_VARARGS,oaWafer_getWaferUnits_doc},
    {"isModified",(PyCFunction)oaWafer_isModified,METH_VARARGS,oaWafer_isModified_doc},
    {"isUndoEnabled",(PyCFunction)oaWafer_isUndoEnabled,METH_VARARGS,oaWafer_isUndoEnabled_doc},
    {"purge",(PyCFunction)oaWafer_purge,METH_VARARGS,oaWafer_purge_doc},
    {"redo",(PyCFunction)oaWafer_redo,METH_VARARGS,oaWafer_redo_doc},
    {"reopen",(PyCFunction)oaWafer_reopen,METH_VARARGS,oaWafer_reopen_doc},
    {"revert",(PyCFunction)oaWafer_revert,METH_VARARGS,oaWafer_revert_doc},
    {"save",(PyCFunction)oaWafer_save,METH_VARARGS,oaWafer_save_doc},
    {"saveAs",(PyCFunction)oaWafer_saveAs,METH_VARARGS,oaWafer_saveAs_doc},
    {"setCp",(PyCFunction)oaWafer_setCp,METH_VARARGS,oaWafer_setCp_doc},
    {"setDBUPerWU",(PyCFunction)oaWafer_setDBUPerWU,METH_VARARGS,oaWafer_setDBUPerWU_doc},
    {"setWaferUnits",(PyCFunction)oaWafer_setWaferUnits,METH_VARARGS,oaWafer_setWaferUnits_doc},
    {"undo",(PyCFunction)oaWafer_undo,METH_VARARGS,oaWafer_undo_doc},
    {"isNull",(PyCFunction)oaWafer_tp_isNull,METH_VARARGS,oaWafer_isNull_doc},
    {"assign",(PyCFunction)oaWafer_tp_assign,METH_VARARGS,oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWafer_doc[] = 
"Class: oaWafer\n"
"  The oaWafer class implements a wafer database which is a specific view of a cell. This class is the main object for storing the description of a wafer and the reticles frames, and images to associate with the wafer.\n"
"  All oaWafers are implemented as a file in an oaView . They are all associated with a triplet of library, cell, and view names, and this set of names is used to identify them.\n"
"  The oaWafer class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaWafer)\n"
"    Calls: (const oaWafer&)\n"
"    Signature: oaWafer||cref-oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWafer",
    sizeof(PyoaWaferObject),
    0,
    (destructor)oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWafer_static_destroy_doc[] = 
"Class: oaWafer, Function: destroy\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void destroy(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: destroy|void-void|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function attempts to remove the wafer from disk. An exception is thrown if the wafer is currently opened or if the wafer cannot be found on disk.\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of an existing cell\n"
"    viewName\n"
"    The name of an existing view\n"
;

static PyObject*
oaWafer_static_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaWafer::destroy(p1.Data(),p2.Data(),p3.Data());
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
static char oaWafer_static_exists_doc[] = 
"Class: oaWafer, Function: exists\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaBoolean exists(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: exists|simple-oaBoolean|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function returns a boolean indicating whether a wafer is currently open with the specified library, cell, and view names, or whether the wafer is found on disk. If the wafer is found on disk, it database file must have a non-zero size in order to be recognized.\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of a cell\n"
"    viewName\n"
"    The name of a view\n"
;

static PyObject*
oaWafer_static_exists(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaBoolean result= (oaWafer::exists(p1.Data(),p2.Data(),p3.Data()));
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
static char oaWafer_static_find_doc[] = 
"Class: oaWafer, Function: find\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaWafer* find(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: find|ptr-oaWafer|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function attempts to find a wafer with the specified library, cell, and view names. If the specified view is open, it is returned, otherwise NULL is returned.\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of a cell\n"
"    viewName\n"
"    The name of a view\n"
;

static PyObject*
oaWafer_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaWaferp result= (oaWafer::find(p1.Data(),p2.Data(),p3.Data()));
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
static char oaWafer_static_getOpenWafers_doc[] = 
"Class: oaWafer, Function: getOpenWafers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaWafer_oaWafer getOpenWafers()\n"
"    Signature: getOpenWafers|simple-oaCollection_oaWafer_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns a collection of open wafers.\n"
;

static PyObject*
oaWafer_static_getOpenWafers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaWafer_oaWafer* result= new oaCollection_oaWafer_oaWafer(oaWafer::getOpenWafers());
        return PyoaCollection_oaWafer_oaWafer_FromoaCollection_oaWafer_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_static_getOpenWafersIter_doc[] = 
"Class: oaWafer, Function: getOpenWafersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaWafer getOpenWafersIter()\n"
"    Signature: getOpenWafersIter|simple-oaIter_oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of open wafers.\n"
;

static PyObject*
oaWafer_static_getOpenWafersIter(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaWafer* result= new oaIter_oaWafer(oaWafer::getOpenWafers());
        return PyoaIter_oaWafer_FromoaIter_oaWafer(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWafer_static_getRevNumber_doc[] = 
"Class: oaWafer, Function: getRevNumber\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRevNumber()\n"
"    Signature: getRevNumber|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the revision number of the internal format for the wafer database.\n"
;

static PyObject*
oaWafer_static_getRevNumber(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (oaWafer::getRevNumber());
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
static char oaWafer_static_open_doc[] = 
"Class: oaWafer, Function: open\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaWafer* open(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: open|ptr-oaWafer|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaChar,\n"
"    This function attempts to open the wafer with the specified library, cell, and view names with the specified access mode. If successful, the wafer is returned. The reference count of the wafer is incremented once for each successful open call, so it is important each call to open() is matched by a call to close() .\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of a cell\n"
"    viewName\n"
"    The name of a view\n"
"    mode\n"
"    The mode in which to open the wafer\n"
"    'r' for read\n"
"    'w' for write\n"
"    'a' for append to modify an existing wafer\n"
"    'A' for append in override mode, which is not typically used. Refer to Compatibility for OpenAccess Applications and Data in the Programmers Guide for more information.\n"
"    oacWaferLibNotFound\n"
"    oacDataNotCompatibleOnOpen\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened\n"
"    oacDataNotCompatibleOnOpenInAppendMode\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened in append mode\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName,oaChar)\n"
"    Calls: oaWafer* open(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaChar mode)\n"
"    Signature: open|ptr-oaWafer|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaChar,\n"
"    This function attempts to open the wafer with the specified library, cell, and view names with the specified access mode. If successful, the wafer is returned. The reference count of the wafer is incremented once for each successful open call, so it is important each call to open() is matched by a call to close() .\n"
"    libName\n"
"    The name of an existing library\n"
"    cellName\n"
"    The name of a cell\n"
"    viewName\n"
"    The name of a view\n"
"    mode\n"
"    The mode in which to open the wafer\n"
"    'r' for read\n"
"    'w' for write\n"
"    'a' for append to modify an existing wafer\n"
"    'A' for append in override mode, which is not typically used. Refer to Compatibility for OpenAccess Applications and Data in the Programmers Guide for more information.\n"
"    oacWaferLibNotFound\n"
"    oacDataNotCompatibleOnOpen\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened\n"
"    oacDataNotCompatibleOnOpenInAppendMode\n"
"    The design contains new features that are not understood by this version of OpenAccess and cannot be opened in append mode\n"
;

static PyObject*
oaWafer_static_open(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaScalarName,oaScalarName,oaScalarName)
    {
        PyParamoaScalarName p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3)) {
            oaWaferp result= (oaWafer::open(p1.Data(),p2.Data(),p3.Data()));
            return PyoaWafer_FromoaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaScalarName,oaScalarName,oaChar)
    {
        PyParamoaScalarName p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaChar p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaChar_Convert,&p4)) {
            oaWaferp result= (oaWafer::open(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaWafer_FromoaWafer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaWafer, function: open, Choices are:\n"
        "    (oaScalarName,oaScalarName,oaScalarName)\n"
        "    (oaScalarName,oaScalarName,oaScalarName,oaChar)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaWafer_staticmethodlist[] = {
    {"static_destroy",(PyCFunction)oaWafer_static_destroy,METH_VARARGS,oaWafer_static_destroy_doc},
    {"static_exists",(PyCFunction)oaWafer_static_exists,METH_VARARGS,oaWafer_static_exists_doc},
    {"static_find",(PyCFunction)oaWafer_static_find,METH_VARARGS,oaWafer_static_find_doc},
    {"static_getOpenWafers",(PyCFunction)oaWafer_static_getOpenWafers,METH_VARARGS,oaWafer_static_getOpenWafers_doc},
    {"static_getOpenWafersIter",(PyCFunction)oaWafer_static_getOpenWafersIter,METH_VARARGS,oaWafer_static_getOpenWafersIter_doc},
    {"static_getRevNumber",(PyCFunction)oaWafer_static_getRevNumber,METH_VARARGS,oaWafer_static_getRevNumber_doc},
    {"static_open",(PyCFunction)oaWafer_static_open,METH_VARARGS,oaWafer_static_open_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWafer",
           (PyObject*)(&PyoaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWafer\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaWafer_Type.tp_dict;
    for(method=oaWafer_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaWaferDataType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferDataType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferDataType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferDataTypeObject* self = (PyoaWaferDataTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferDataTypeEnum)
    {
        PyParamoaWaferDataTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWaferDataTypeEnum_Convert,&p1)) {
            self->value =  new oaWaferDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaWaferDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaWaferDataType)
    {
        PyParamoaWaferDataType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferDataType_Convert,&p1)) {
            self->value= new oaWaferDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaWaferDataType, Choices are:\n"
        "    (oaWaferDataTypeEnum)\n"
        "    (oaString)\n"
        "    (oaWaferDataType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferDataType_tp_dealloc(PyoaWaferDataTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferDataType_tp_repr(PyObject *ob)
{
    PyParamoaWaferDataType value;
    int convert_status=PyoaWaferDataType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[37];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaWaferDataType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferDataType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferDataType v1;
    PyParamoaWaferDataType v2;
    int convert_status1=PyoaWaferDataType_Convert(ob1,&v1);
    int convert_status2=PyoaWaferDataType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferDataType_Convert(PyObject* ob,PyParamoaWaferDataType* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferDataType_Check(ob)) {
        result->SetData(  ((PyoaWaferDataTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferDataType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferDataType_FromoaWaferDataType(oaWaferDataType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaWaferDataType_Type.tp_alloc(&PyoaWaferDataType_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferDataTypeObject* self = (PyoaWaferDataTypeObject*)bself;
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
static char oaWaferDataType_getName_doc[] = 
"Class: oaWaferDataType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaWaferDataTypeEnum object.\n"
;

static PyObject*
oaWaferDataType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDataType data;
    int convert_status=PyoaWaferDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDataTypeObject* self=(PyoaWaferDataTypeObject*)ob;

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
static char oaWaferDataType_oaWaferDataTypeEnum_doc[] = 
"Class: oaWaferDataType, Function: oaWaferDataTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaWaferDataTypeEnum oaWaferDataTypeEnum() const\n"
"    Signature: operator oaWaferDataTypeEnum|simple-oaWaferDataTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaWaferDataType object into the corresponding #oaWaferDataTypeEnum value.\n"
;

static PyObject*
oaWaferDataType_oaWaferDataTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDataType data;
    int convert_status=PyoaWaferDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDataTypeObject* self=(PyoaWaferDataTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferDataTypeEnum result= (data.DataCall()->operator oaWaferDataTypeEnum());
        return PyoaWaferDataTypeEnum_FromoaWaferDataTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaWaferDataType_assign_doc[] = 
"Class: oaWaferDataType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferDataType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferDataType data;
  int convert_status=PyoaWaferDataType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferDataType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferDataType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferDataType_methodlist[] = {
    {"getName",(PyCFunction)oaWaferDataType_getName,METH_VARARGS,oaWaferDataType_getName_doc},
    {"oaWaferDataTypeEnum",(PyCFunction)oaWaferDataType_oaWaferDataTypeEnum,METH_VARARGS,oaWaferDataType_oaWaferDataTypeEnum_doc},
    {"assign",(PyCFunction)oaWaferDataType_tp_assign,METH_VARARGS,oaWaferDataType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferDataType_doc[] = 
"Class: oaWaferDataType\n"
"  The oaWaferDataType class encapsulates the enumerated values that describe the different types of data contained within a wafer database object.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaWaferDataTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaWaferDataTypeEnum)\n"
"    Calls: oaWaferDataType(oaWaferDataTypeEnum valueIn)\n"
"    Signature: oaWaferDataType||simple-oaWaferDataTypeEnum,\n"
"    This function constructs an instance of an oaWaferDataType class using the specified #oaWaferDataTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaWaferDataType(const oaString& name)\n"
"    Signature: oaWaferDataType||cref-oaString,\n"
"    This function constructs an instance of an oaWaferDataType class using the #oaWaferDataTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaWaferDataTypeEnum.\n"
"    oacInvalidWaferDataTypeName\n"
"  Paramegers: (oaWaferDataType)\n"
"    Calls: (const oaWaferDataType&)\n"
"    Signature: oaWaferDataType||cref-oaWaferDataType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferDataType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferDataType",
    sizeof(PyoaWaferDataTypeObject),
    0,
    (destructor)oaWaferDataType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferDataType_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferDataType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferDataType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferDataType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferDataType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferDataType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferDataType_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferDataType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferDataType",
           (PyObject*)(&PyoaWaferDataType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferDataType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaWaferDataTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferDataTypeEnum_Convert(PyObject* ob,PyParamoaWaferDataTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacWaferWaferDataType")==0) { result->SetData(oacWaferWaferDataType); return 1;}
        if (strcasecmp(str,"oacAppObjectWaferDataType")==0) { result->SetData(oacAppObjectWaferDataType); return 1;}
        if (strcasecmp(str,"oacPropWaferDataType")==0) { result->SetData(oacPropWaferDataType); return 1;}
        if (strcasecmp(str,"oacGroupWaferDataType")==0) { result->SetData(oacGroupWaferDataType); return 1;}
        if (strcasecmp(str,"oacGroupMemWaferDataType")==0) { result->SetData(oacGroupMemWaferDataType); return 1;}
        if (strcasecmp(str,"oacAvatarWaferDataType")==0) { result->SetData(oacAvatarWaferDataType); return 1;}
        if (strcasecmp(str,"oacValueWaferDataType")==0) { result->SetData(oacValueWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintParamDefWaferDataType")==0) { result->SetData(oacConstraintParamDefWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintParamWaferDataType")==0) { result->SetData(oacConstraintParamWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintDefWaferDataType")==0) { result->SetData(oacConstraintDefWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintWaferDataType")==0) { result->SetData(oacConstraintWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintGroupWaferDataType")==0) { result->SetData(oacConstraintGroupWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintGroupMemWaferDataType")==0) { result->SetData(oacConstraintGroupMemWaferDataType); return 1;}
        if (strcasecmp(str,"oacConstraintGroupHeaderWaferDataType")==0) { result->SetData(oacConstraintGroupHeaderWaferDataType); return 1;}
        if (strcasecmp(str,"oacWaferDescWaferDataType")==0) { result->SetData(oacWaferDescWaferDataType); return 1;}
        if (strcasecmp(str,"oacFrameWaferDataType")==0) { result->SetData(oacFrameWaferDataType); return 1;}
        if (strcasecmp(str,"oacReticleWaferDataType")==0) { result->SetData(oacReticleWaferDataType); return 1;}
        if (strcasecmp(str,"oacReticleRefWaferDataType")==0) { result->SetData(oacReticleRefWaferDataType); return 1;}
        if (strcasecmp(str,"oacStepperMapWaferDataType")==0) { result->SetData(oacStepperMapWaferDataType); return 1;}
        if (strcasecmp(str,"oacImageWaferDataType")==0) { result->SetData(oacImageWaferDataType); return 1;}
        if (strcasecmp(str,"oacFrameInstWaferDataType")==0) { result->SetData(oacFrameInstWaferDataType); return 1;}
        if (strcasecmp(str,"oacDesignInstWaferDataType")==0) { result->SetData(oacDesignInstWaferDataType); return 1;}
        if (strcasecmp(str,"oacWaferFeatureWaferDataType")==0) { result->SetData(oacWaferFeatureWaferDataType); return 1;}
        if (strcasecmp(str,"oacFeatureWaferDataType")==0) { result->SetData(oacFeatureWaferDataType); return 1;}
        if (strcasecmp(str,"oacFeaturePolicyWaferDataType")==0) { result->SetData(oacFeaturePolicyWaferDataType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferDataTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferDataTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferDataTypeEnum_FromoaWaferDataTypeEnum(oaWaferDataTypeEnum ob)
{
    if (ob==oacWaferWaferDataType) return PyString_FromString("oacWaferWaferDataType");
    if (ob==oacAppObjectWaferDataType) return PyString_FromString("oacAppObjectWaferDataType");
    if (ob==oacPropWaferDataType) return PyString_FromString("oacPropWaferDataType");
    if (ob==oacGroupWaferDataType) return PyString_FromString("oacGroupWaferDataType");
    if (ob==oacGroupMemWaferDataType) return PyString_FromString("oacGroupMemWaferDataType");
    if (ob==oacAvatarWaferDataType) return PyString_FromString("oacAvatarWaferDataType");
    if (ob==oacValueWaferDataType) return PyString_FromString("oacValueWaferDataType");
    if (ob==oacConstraintParamDefWaferDataType) return PyString_FromString("oacConstraintParamDefWaferDataType");
    if (ob==oacConstraintParamWaferDataType) return PyString_FromString("oacConstraintParamWaferDataType");
    if (ob==oacConstraintDefWaferDataType) return PyString_FromString("oacConstraintDefWaferDataType");
    if (ob==oacConstraintWaferDataType) return PyString_FromString("oacConstraintWaferDataType");
    if (ob==oacConstraintGroupWaferDataType) return PyString_FromString("oacConstraintGroupWaferDataType");
    if (ob==oacConstraintGroupMemWaferDataType) return PyString_FromString("oacConstraintGroupMemWaferDataType");
    if (ob==oacConstraintGroupHeaderWaferDataType) return PyString_FromString("oacConstraintGroupHeaderWaferDataType");
    if (ob==oacWaferDescWaferDataType) return PyString_FromString("oacWaferDescWaferDataType");
    if (ob==oacFrameWaferDataType) return PyString_FromString("oacFrameWaferDataType");
    if (ob==oacReticleWaferDataType) return PyString_FromString("oacReticleWaferDataType");
    if (ob==oacReticleRefWaferDataType) return PyString_FromString("oacReticleRefWaferDataType");
    if (ob==oacStepperMapWaferDataType) return PyString_FromString("oacStepperMapWaferDataType");
    if (ob==oacImageWaferDataType) return PyString_FromString("oacImageWaferDataType");
    if (ob==oacFrameInstWaferDataType) return PyString_FromString("oacFrameInstWaferDataType");
    if (ob==oacDesignInstWaferDataType) return PyString_FromString("oacDesignInstWaferDataType");
    if (ob==oacWaferFeatureWaferDataType) return PyString_FromString("oacWaferFeatureWaferDataType");
    if (ob==oacFeatureWaferDataType) return PyString_FromString("oacFeatureWaferDataType");
    if (ob==oacFeaturePolicyWaferDataType) return PyString_FromString("oacFeaturePolicyWaferDataType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferDataTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferDataTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferDataTypeEnum_FromoaWaferDataTypeEnum(oaWaferDataTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferDataTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferDataTypeEnum_doc[] =
"Type convert function for enum: oaWaferDataTypeEnum";
                               
static PyMethodDef PyoaWaferDataTypeEnum_method =
  {"oaWaferDataTypeEnum",(PyCFunction)PyoaWaferDataTypeEnum_TypeFunction,METH_VARARGS,oaWaferDataTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferDataTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacWaferWaferDataType");
    PyDict_SetItemString(mod_dict,"oacWaferWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAppObjectWaferDataType");
    PyDict_SetItemString(mod_dict,"oacAppObjectWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPropWaferDataType");
    PyDict_SetItemString(mod_dict,"oacPropWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGroupWaferDataType");
    PyDict_SetItemString(mod_dict,"oacGroupWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGroupMemWaferDataType");
    PyDict_SetItemString(mod_dict,"oacGroupMemWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAvatarWaferDataType");
    PyDict_SetItemString(mod_dict,"oacAvatarWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacValueWaferDataType");
    PyDict_SetItemString(mod_dict,"oacValueWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamDefWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintParamDefWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintParamWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintParamWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintDefWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintDefWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupMemWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupMemWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConstraintGroupHeaderWaferDataType");
    PyDict_SetItemString(mod_dict,"oacConstraintGroupHeaderWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferDescWaferDataType");
    PyDict_SetItemString(mod_dict,"oacWaferDescWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameWaferDataType");
    PyDict_SetItemString(mod_dict,"oacFrameWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleWaferDataType");
    PyDict_SetItemString(mod_dict,"oacReticleWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleRefWaferDataType");
    PyDict_SetItemString(mod_dict,"oacReticleRefWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStepperMapWaferDataType");
    PyDict_SetItemString(mod_dict,"oacStepperMapWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacImageWaferDataType");
    PyDict_SetItemString(mod_dict,"oacImageWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameInstWaferDataType");
    PyDict_SetItemString(mod_dict,"oacFrameInstWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDesignInstWaferDataType");
    PyDict_SetItemString(mod_dict,"oacDesignInstWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferFeatureWaferDataType");
    PyDict_SetItemString(mod_dict,"oacWaferFeatureWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFeatureWaferDataType");
    PyDict_SetItemString(mod_dict,"oacFeatureWaferDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFeaturePolicyWaferDataType");
    PyDict_SetItemString(mod_dict,"oacFeaturePolicyWaferDataType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferDataTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferDataTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferDataTypeEnum\n");
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
// Wrapper Implementation for Class: oaWaferDesc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferDesc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferDesc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferDescObject* self = (PyoaWaferDescObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferDesc)
    {
        PyParamoaWaferDesc p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferDesc_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaWaferDesc, Choices are:\n"
        "    (oaWaferDesc)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferDesc_tp_dealloc(PyoaWaferDescObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferDesc_tp_repr(PyObject *ob)
{
    PyParamoaWaferDesc value;
    int convert_status=PyoaWaferDesc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaWaferDesc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferDesc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferDesc v1;
    PyParamoaWaferDesc v2;
    int convert_status1=PyoaWaferDesc_Convert(ob1,&v1);
    int convert_status2=PyoaWaferDesc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferDesc_Convert(PyObject* ob,PyParamoaWaferDesc* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferDesc_Check(ob)) {
        result->SetData( (oaWaferDesc**) ((PyoaWaferDescObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferDesc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferDesc_FromoaWaferDesc(oaWaferDesc** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaWaferDesc* data=*value;
        PyObject* bself = PyoaWaferDesc_Type.tp_alloc(&PyoaWaferDesc_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferDescObject* self = (PyoaWaferDescObject*)bself;
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
PyObject* PyoaWaferDesc_FromoaWaferDesc(oaWaferDesc* data)
{
    if (data) {
       PyObject* bself = PyoaWaferDesc_Type.tp_alloc(&PyoaWaferDesc_Type,0);
       if (bself == NULL) return bself;
       PyoaWaferDescObject* self = (PyoaWaferDescObject*)bself;
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
static char oaWaferDesc_destroy_doc[] = 
"Class: oaWaferDesc, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this wafer description, removing it from the database.\n"
;

static PyObject*
oaWaferDesc_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
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
static char oaWaferDesc_getName_doc[] = 
"Class: oaWaferDesc, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this wafer description.\n"
"    name\n"
"    Filled out with the name of this wafer description\n"
;

static PyObject*
oaWaferDesc_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
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
static char oaWaferDesc_getStepperMaps_doc[] = 
"Class: oaWaferDesc, Function: getStepperMaps\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaStepperMap_oaWaferDesc getStepperMaps() const\n"
"    Signature: getStepperMaps|simple-oaCollection_oaStepperMap_oaWaferDesc|\n"
"    BrowseData: 1\n"
"    This function returns the collection of stepperMaps associated with this wafer description.\n"
;

static PyObject*
oaWaferDesc_getStepperMaps(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaStepperMap_oaWaferDesc* result= new oaCollection_oaStepperMap_oaWaferDesc(data.DataCall()->getStepperMaps());
        return PyoaCollection_oaStepperMap_oaWaferDesc_FromoaCollection_oaStepperMap_oaWaferDesc(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWaferDesc_getStepperMapsIter_doc[] = 
"Class: oaWaferDesc, Function: getStepperMapsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaStepperMap getStepperMapsIter() const\n"
"    Signature: getStepperMapsIter|simple-oaIter_oaStepperMap|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of stepperMaps associated with this wafer description.\n"
;

static PyObject*
oaWaferDesc_getStepperMapsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaStepperMap* result= new oaIter_oaStepperMap(data.DataCall()->getStepperMaps());
        return PyoaIter_oaStepperMap_FromoaIter_oaStepperMap(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWaferDesc_getTotalDiameter_doc[] = 
"Class: oaWaferDesc, Function: getTotalDiameter\n"
"  Paramegers: ()\n"
"    Calls: oaDist getTotalDiameter() const\n"
"    Signature: getTotalDiameter|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the total diameter value associated with this wafer description.\n"
;

static PyObject*
oaWaferDesc_getTotalDiameter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getTotalDiameter());
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
static char oaWaferDesc_getUsableDiameter_doc[] = 
"Class: oaWaferDesc, Function: getUsableDiameter\n"
"  Paramegers: ()\n"
"    Calls: oaDist getUsableDiameter() const\n"
"    Signature: getUsableDiameter|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the usable diameter value associated with this wafer description.\n"
;

static PyObject*
oaWaferDesc_getUsableDiameter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getUsableDiameter());
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
static char oaWaferDesc_getWaferFeatures_doc[] = 
"Class: oaWaferDesc, Function: getWaferFeatures\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaWaferFeature_oaWaferDesc getWaferFeatures() const\n"
"    Signature: getWaferFeatures|simple-oaCollection_oaWaferFeature_oaWaferDesc|\n"
"    BrowseData: 1\n"
"    This function returns the collection of waferFeatures associated with this wafer description object.\n"
;

static PyObject*
oaWaferDesc_getWaferFeatures(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaWaferFeature_oaWaferDesc* result= new oaCollection_oaWaferFeature_oaWaferDesc(data.DataCall()->getWaferFeatures());
        return PyoaCollection_oaWaferFeature_oaWaferDesc_FromoaCollection_oaWaferFeature_oaWaferDesc(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWaferDesc_getWaferFeaturesIter_doc[] = 
"Class: oaWaferDesc, Function: getWaferFeaturesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaWaferFeature getWaferFeaturesIter() const\n"
"    Signature: getWaferFeaturesIter|simple-oaIter_oaWaferFeature|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of waferFeatures associated with this wafer description object.\n"
;

static PyObject*
oaWaferDesc_getWaferFeaturesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaWaferFeature* result= new oaIter_oaWaferFeature(data.DataCall()->getWaferFeatures());
        return PyoaIter_oaWaferFeature_FromoaIter_oaWaferFeature(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWaferDesc_setName_doc[] = 
"Class: oaWaferDesc, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the name of this wafer description.\n"
"    name\n"
"    Specifies the new name for this wafer description\n"
;

static PyObject*
oaWaferDesc_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
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
static char oaWaferDesc_setTotalDiameter_doc[] = 
"Class: oaWaferDesc, Function: setTotalDiameter\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setTotalDiameter(oaDist value)\n"
"    Signature: setTotalDiameter|void-void|simple-oaDist,\n"
"    This function changes the total diameter value of this wafer description. An exception is thrown if the value is less than the current usable diameter value.\n"
"    value\n"
"    Specifies the new total diameter value\n"
"    oacInvalidTotalDiamValue\n"
;

static PyObject*
oaWaferDesc_setTotalDiameter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setTotalDiameter(p1.Data());
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
static char oaWaferDesc_setUsableDiameter_doc[] = 
"Class: oaWaferDesc, Function: setUsableDiameter\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setUsableDiameter(oaDist value)\n"
"    Signature: setUsableDiameter|void-void|simple-oaDist,\n"
"    This function changes the usable diameter value of this wafer description. An exception is thrown if the value is greater than the current total diameter value.\n"
"    value\n"
"    Specifies the new usable diameter value\n"
"    oacInvalidUsableDiamValue\n"
;

static PyObject*
oaWaferDesc_setUsableDiameter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferDescObject* self=(PyoaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setUsableDiameter(p1.Data());
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
static char oaWaferDesc_isNull_doc[] =
"Class: oaWaferDesc, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaWaferDesc_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaWaferDesc data;
    int convert_status=PyoaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaWaferDesc_assign_doc[] = 
"Class: oaWaferDesc, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferDesc_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferDesc data;
  int convert_status=PyoaWaferDesc_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferDesc p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferDesc_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferDesc_methodlist[] = {
    {"destroy",(PyCFunction)oaWaferDesc_destroy,METH_VARARGS,oaWaferDesc_destroy_doc},
    {"getName",(PyCFunction)oaWaferDesc_getName,METH_VARARGS,oaWaferDesc_getName_doc},
    {"getStepperMaps",(PyCFunction)oaWaferDesc_getStepperMaps,METH_VARARGS,oaWaferDesc_getStepperMaps_doc},
    {"getStepperMapsIter",(PyCFunction)oaWaferDesc_getStepperMapsIter,METH_VARARGS,oaWaferDesc_getStepperMapsIter_doc},
    {"getTotalDiameter",(PyCFunction)oaWaferDesc_getTotalDiameter,METH_VARARGS,oaWaferDesc_getTotalDiameter_doc},
    {"getUsableDiameter",(PyCFunction)oaWaferDesc_getUsableDiameter,METH_VARARGS,oaWaferDesc_getUsableDiameter_doc},
    {"getWaferFeatures",(PyCFunction)oaWaferDesc_getWaferFeatures,METH_VARARGS,oaWaferDesc_getWaferFeatures_doc},
    {"getWaferFeaturesIter",(PyCFunction)oaWaferDesc_getWaferFeaturesIter,METH_VARARGS,oaWaferDesc_getWaferFeaturesIter_doc},
    {"setName",(PyCFunction)oaWaferDesc_setName,METH_VARARGS,oaWaferDesc_setName_doc},
    {"setTotalDiameter",(PyCFunction)oaWaferDesc_setTotalDiameter,METH_VARARGS,oaWaferDesc_setTotalDiameter_doc},
    {"setUsableDiameter",(PyCFunction)oaWaferDesc_setUsableDiameter,METH_VARARGS,oaWaferDesc_setUsableDiameter_doc},
    {"isNull",(PyCFunction)oaWaferDesc_tp_isNull,METH_VARARGS,oaWaferDesc_isNull_doc},
    {"assign",(PyCFunction)oaWaferDesc_tp_assign,METH_VARARGS,oaWaferDesc_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferDesc_doc[] = 
"Class: oaWaferDesc\n"
"  The oaWaferDesc class specifies all of the information for exposing its associated reticles on a physical silicon wafer.\n"
"  The oaWaferDesc class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaWaferDesc)\n"
"    Calls: (const oaWaferDesc&)\n"
"    Signature: oaWaferDesc||cref-oaWaferDesc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferDesc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferDesc",
    sizeof(PyoaWaferDescObject),
    0,
    (destructor)oaWaferDesc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferDesc_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferDesc_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferDesc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferDesc_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferDesc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferDesc_static_create_doc[] = 
"Class: oaWaferDesc, Function: create\n"
"  Paramegers: (oaWafer,oaString,oaDist,oaDist)\n"
"    Calls: oaWaferDesc* create(oaWafer* wafer,const oaString& name,oaDist totalDiameter,oaDist usableDiameter)\n"
"    Signature: create|ptr-oaWaferDesc|ptr-oaWafer,cref-oaString,simple-oaDist,simple-oaDist,\n"
"    This function creates a wafer description in the specified wafer with the given name and attributes. Exceptions are thrown if the wafer already has a wafer description associated with it or if the usable diameter value is greater than the total diameter value specified.\n"
"    wafer\n"
"    Specifies the wafer to create the wafer description in\n"
"    name\n"
"    Specifies the name of the wafer description\n"
"    totalDiameter\n"
"    Specifies the total diameter of the wafer\n"
"    usableDiameter\n"
"    Specifies the usable diameter of the wafer\n"
"    oacWaferAlreadyHasWaferDesc\n"
"    oacInvalidUsableDiamValue\n"
;

static PyObject*
oaWaferDesc_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    PyParamoaDist p3;
    PyParamoaDist p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaDist_Convert,&p3,
          &PyoaDist_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaWaferDescp result= (oaWaferDesc::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaWaferDesc_FromoaWaferDesc(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaWaferDesc_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaWaferDesc_static_create,METH_VARARGS,oaWaferDesc_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferDesc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferDesc_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferDesc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferDesc",
           (PyObject*)(&PyoaWaferDesc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferDesc\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaWaferDesc_Type.tp_dict;
    for(method=oaWaferDesc_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaWaferDescModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferDescModTypeEnum_Convert(PyObject* ob,PyParamoaWaferDescModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameWaferDescModType")==0) { result->SetData(oacSetNameWaferDescModType); return 1;}
        if (strcasecmp(str,"oacSetTotalDiamWaferDescModType")==0) { result->SetData(oacSetTotalDiamWaferDescModType); return 1;}
        if (strcasecmp(str,"oacSetUsableDiamWaferDescModType")==0) { result->SetData(oacSetUsableDiamWaferDescModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferDescModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferDescModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferDescModTypeEnum_FromoaWaferDescModTypeEnum(oaWaferDescModTypeEnum ob)
{
    if (ob==oacSetNameWaferDescModType) return PyString_FromString("oacSetNameWaferDescModType");
    if (ob==oacSetTotalDiamWaferDescModType) return PyString_FromString("oacSetTotalDiamWaferDescModType");
    if (ob==oacSetUsableDiamWaferDescModType) return PyString_FromString("oacSetUsableDiamWaferDescModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferDescModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferDescModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferDescModTypeEnum_FromoaWaferDescModTypeEnum(oaWaferDescModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferDescModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferDescModTypeEnum_doc[] =
"Type convert function for enum: oaWaferDescModTypeEnum";
                               
static PyMethodDef PyoaWaferDescModTypeEnum_method =
  {"oaWaferDescModTypeEnum",(PyCFunction)PyoaWaferDescModTypeEnum_TypeFunction,METH_VARARGS,oaWaferDescModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferDescModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameWaferDescModType");
    PyDict_SetItemString(mod_dict,"oacSetNameWaferDescModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetTotalDiamWaferDescModType");
    PyDict_SetItemString(mod_dict,"oacSetTotalDiamWaferDescModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetUsableDiamWaferDescModType");
    PyDict_SetItemString(mod_dict,"oacSetUsableDiamWaferDescModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferDescModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferDescModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferDescModTypeEnum\n");
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
// Wrapper Implementation for Class: oaWaferFeature
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferFeature_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferFeature_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferFeatureObject* self = (PyoaWaferFeatureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferFeature)
    {
        PyParamoaWaferFeature p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferFeature_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaWaferFeature, Choices are:\n"
        "    (oaWaferFeature)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferFeature_tp_dealloc(PyoaWaferFeatureObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferFeature_tp_repr(PyObject *ob)
{
    PyParamoaWaferFeature value;
    int convert_status=PyoaWaferFeature_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaWaferFeature::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferFeature_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferFeature v1;
    PyParamoaWaferFeature v2;
    int convert_status1=PyoaWaferFeature_Convert(ob1,&v1);
    int convert_status2=PyoaWaferFeature_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferFeature_Convert(PyObject* ob,PyParamoaWaferFeature* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferFeature_Check(ob)) {
        result->SetData( (oaWaferFeature**) ((PyoaWaferFeatureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferFeature Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferFeature_FromoaWaferFeature(oaWaferFeature** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaWaferFeature* data=*value;
        PyObject* bself = PyoaWaferFeature_Type.tp_alloc(&PyoaWaferFeature_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferFeatureObject* self = (PyoaWaferFeatureObject*)bself;
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
PyObject* PyoaWaferFeature_FromoaWaferFeature(oaWaferFeature* data)
{
    if (data) {
       PyObject* bself = PyoaWaferFeature_Type.tp_alloc(&PyoaWaferFeature_Type,0);
       if (bself == NULL) return bself;
       PyoaWaferFeatureObject* self = (PyoaWaferFeatureObject*)bself;
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
static char oaWaferFeature_destroy_doc[] = 
"Class: oaWaferFeature, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this wafer feature, removing it from the database.\n"
;

static PyObject*
oaWaferFeature_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
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
static char oaWaferFeature_getBoundary_doc[] = 
"Class: oaWaferFeature, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& points) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function returns the boundary of this wafer feature in the given pointArray.\n"
"    points\n"
"    The boundary is returned in this array of points\n"
;

static PyObject*
oaWaferFeature_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.DataCall()->getBoundary(p1.Data());
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
static char oaWaferFeature_getName_doc[] = 
"Class: oaWaferFeature, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this wafer feature.\n"
"    name\n"
"    The string to return the feature name in\n"
;

static PyObject*
oaWaferFeature_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
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
static char oaWaferFeature_getWaferFeatureType_doc[] = 
"Class: oaWaferFeature, Function: getWaferFeatureType\n"
"  Paramegers: ()\n"
"    Calls: oaWaferFeatureType getWaferFeatureType() const\n"
"    Signature: getWaferFeatureType|simple-oaWaferFeatureType|\n"
"    BrowseData: 1\n"
"    This function returns the type of this wafer feature.\n"
;

static PyObject*
oaWaferFeature_getWaferFeatureType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferFeatureType* result= new oaWaferFeatureType(data.DataCall()->getWaferFeatureType());
        return PyoaWaferFeatureType_FromoaWaferFeatureType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWaferFeature_setBoundary_doc[] = 
"Class: oaWaferFeature, Function: setBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setBoundary(const oaPointArray& points)\n"
"    Signature: setBoundary|void-void|cref-oaPointArray,\n"
"    This function changes the boundary of this waferFeature to have the new set of points specified in the given pointArray. Exceptions are thrown if the specified points have coincident or collinear lines or if the number of new points is less than three.\n"
"    points\n"
"    The new boundary to give this wafer feature\n"
"    oacWaferFeatureHasExtraPoints\n"
"    oacWaferFeatureTooFewPoints\n"
;

static PyObject*
oaWaferFeature_setBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.DataCall()->setBoundary(p1.Data());
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
static char oaWaferFeature_setName_doc[] = 
"Class: oaWaferFeature, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the name of this waferFeature.\n"
"    name\n"
"    The new name to give this wafer feature\n"
"    oacWaferFeatureAlreadyExists\n"
;

static PyObject*
oaWaferFeature_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
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
static char oaWaferFeature_setWaferFeatureType_doc[] = 
"Class: oaWaferFeature, Function: setWaferFeatureType\n"
"  Paramegers: (oaWaferFeatureType)\n"
"    Calls: void setWaferFeatureType(oaWaferFeatureType feature)\n"
"    Signature: setWaferFeatureType|void-void|simple-oaWaferFeatureType,\n"
"    This function changes the feature type of this waferFeature.\n"
"    feature\n"
"    The new type to give this wafer feature.\n"
;

static PyObject*
oaWaferFeature_setWaferFeatureType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureObject* self=(PyoaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferFeatureType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWaferFeatureType_Convert,&p1)) {
        data.DataCall()->setWaferFeatureType(p1.Data());
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
static char oaWaferFeature_isNull_doc[] =
"Class: oaWaferFeature, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaWaferFeature_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaWaferFeature data;
    int convert_status=PyoaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaWaferFeature_assign_doc[] = 
"Class: oaWaferFeature, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferFeature_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferFeature data;
  int convert_status=PyoaWaferFeature_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferFeature p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferFeature_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferFeature_methodlist[] = {
    {"destroy",(PyCFunction)oaWaferFeature_destroy,METH_VARARGS,oaWaferFeature_destroy_doc},
    {"getBoundary",(PyCFunction)oaWaferFeature_getBoundary,METH_VARARGS,oaWaferFeature_getBoundary_doc},
    {"getName",(PyCFunction)oaWaferFeature_getName,METH_VARARGS,oaWaferFeature_getName_doc},
    {"getWaferFeatureType",(PyCFunction)oaWaferFeature_getWaferFeatureType,METH_VARARGS,oaWaferFeature_getWaferFeatureType_doc},
    {"setBoundary",(PyCFunction)oaWaferFeature_setBoundary,METH_VARARGS,oaWaferFeature_setBoundary_doc},
    {"setName",(PyCFunction)oaWaferFeature_setName,METH_VARARGS,oaWaferFeature_setName_doc},
    {"setWaferFeatureType",(PyCFunction)oaWaferFeature_setWaferFeatureType,METH_VARARGS,oaWaferFeature_setWaferFeatureType_doc},
    {"isNull",(PyCFunction)oaWaferFeature_tp_isNull,METH_VARARGS,oaWaferFeature_isNull_doc},
    {"assign",(PyCFunction)oaWaferFeature_tp_assign,METH_VARARGS,oaWaferFeature_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferFeature_doc[] = 
"Class: oaWaferFeature\n"
"  The oaWaferFeature class implements an object representing an area that prevents printing on a silicon wafer.\n"
"  The oaWaferFeature class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaWaferFeature)\n"
"    Calls: (const oaWaferFeature&)\n"
"    Signature: oaWaferFeature||cref-oaWaferFeature,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferFeature_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferFeature",
    sizeof(PyoaWaferFeatureObject),
    0,
    (destructor)oaWaferFeature_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferFeature_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferFeature_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferFeature_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferFeature_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferFeature_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferFeature_static_create_doc[] = 
"Class: oaWaferFeature, Function: create\n"
"  Paramegers: (oaWaferDesc,oaString,oaWaferFeatureType,oaPointArray)\n"
"    Calls: oaWaferFeature* create(oaWaferDesc* waferDesc,const oaString& name,oaWaferFeatureType feature,const oaPointArray& boundary)\n"
"    Signature: create|ptr-oaWaferFeature|ptr-oaWaferDesc,cref-oaString,simple-oaWaferFeatureType,cref-oaPointArray,\n"
"    This function creates a waferFeature of the specified type with the given boundary.\n"
"    waferDesc\n"
"    The wafer description to associate this wafer feature with\n"
"    name\n"
"    The name to give the wafer feature\n"
"    feature\n"
"    The wafer feature type\n"
"    boundary\n"
"    The boundary of the feature specified as an array of points\n"
"    oacWaferFeatureHasExtraPoints\n"
"    oacWaferFeatureTooFewPoints\n"
"    oacWaferFeatureAlreadyExists\n"
;

static PyObject*
oaWaferFeature_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc p1;
    PyParamoaString p2;
    PyParamoaWaferFeatureType p3;
    PyParamoaPointArray p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaWaferDesc_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaWaferFeatureType_Convert,&p3,
          &PyoaPointArray_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaWaferFeaturep result= (oaWaferFeature::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
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
static char oaWaferFeature_static_find_doc[] = 
"Class: oaWaferFeature, Function: find\n"
"  Paramegers: (oaWaferDesc,oaString)\n"
"    Calls: oaWaferFeature* find(const oaWaferDesc* waferDesc,const oaString& name)\n"
"    Signature: find|ptr-oaWaferFeature|cptr-oaWaferDesc,cref-oaString,\n"
"    This function searches the wafer description for a stepper map with the given name. A pointer to the stepper map is returned if found. Otherwise, NULL is returned.\n"
"    waferDesc\n"
"    The wafer description to search\n"
"    name\n"
"    The name of the feature to search for\n"
;

static PyObject*
oaWaferFeature_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferDesc p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWaferDesc_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaWaferFeaturep result= (oaWaferFeature::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaWaferFeature_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaWaferFeature_static_create,METH_VARARGS,oaWaferFeature_static_create_doc},
    {"static_find",(PyCFunction)oaWaferFeature_static_find,METH_VARARGS,oaWaferFeature_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferFeature_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferFeature_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferFeature\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferFeature",
           (PyObject*)(&PyoaWaferFeature_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferFeature\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaWaferFeature_Type.tp_dict;
    for(method=oaWaferFeature_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaWaferFeatureEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferFeatureEnum_Convert(PyObject* ob,PyParamoaWaferFeatureEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacFlatWaferFeature")==0) { result->SetData(oacFlatWaferFeature); return 1;}
        if (strcasecmp(str,"oacNotchWaferFeature")==0) { result->SetData(oacNotchWaferFeature); return 1;}
        if (strcasecmp(str,"oacBlockageWaferFeature")==0) { result->SetData(oacBlockageWaferFeature); return 1;}
        if (strcasecmp(str,"oacClampWaferFeature")==0) { result->SetData(oacClampWaferFeature); return 1;}
        if (strcasecmp(str,"oacLaserWaferFeature")==0) { result->SetData(oacLaserWaferFeature); return 1;}
        if (strcasecmp(str,"oacOtherWaferFeature")==0) { result->SetData(oacOtherWaferFeature); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferFeatureEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferFeatureEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferFeatureEnum_FromoaWaferFeatureEnum(oaWaferFeatureEnum ob)
{
    if (ob==oacFlatWaferFeature) return PyString_FromString("oacFlatWaferFeature");
    if (ob==oacNotchWaferFeature) return PyString_FromString("oacNotchWaferFeature");
    if (ob==oacBlockageWaferFeature) return PyString_FromString("oacBlockageWaferFeature");
    if (ob==oacClampWaferFeature) return PyString_FromString("oacClampWaferFeature");
    if (ob==oacLaserWaferFeature) return PyString_FromString("oacLaserWaferFeature");
    if (ob==oacOtherWaferFeature) return PyString_FromString("oacOtherWaferFeature");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferFeatureEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferFeatureEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferFeatureEnum_FromoaWaferFeatureEnum(oaWaferFeatureEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferFeatureEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferFeatureEnum_doc[] =
"Type convert function for enum: oaWaferFeatureEnum";
                               
static PyMethodDef PyoaWaferFeatureEnum_method =
  {"oaWaferFeatureEnum",(PyCFunction)PyoaWaferFeatureEnum_TypeFunction,METH_VARARGS,oaWaferFeatureEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferFeatureEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacFlatWaferFeature");
    PyDict_SetItemString(mod_dict,"oacFlatWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNotchWaferFeature");
    PyDict_SetItemString(mod_dict,"oacNotchWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBlockageWaferFeature");
    PyDict_SetItemString(mod_dict,"oacBlockageWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacClampWaferFeature");
    PyDict_SetItemString(mod_dict,"oacClampWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLaserWaferFeature");
    PyDict_SetItemString(mod_dict,"oacLaserWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOtherWaferFeature");
    PyDict_SetItemString(mod_dict,"oacOtherWaferFeature",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferFeatureEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferFeatureEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferFeatureEnum\n");
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
// Wrapper Implementation for Class: oaWaferFeatureModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferFeatureModTypeEnum_Convert(PyObject* ob,PyParamoaWaferFeatureModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameWaferFeatureModType")==0) { result->SetData(oacSetNameWaferFeatureModType); return 1;}
        if (strcasecmp(str,"oacSetBoundaryWaferFeatureModType")==0) { result->SetData(oacSetBoundaryWaferFeatureModType); return 1;}
        if (strcasecmp(str,"oacSetFeatureTypeWaferFeatureModType")==0) { result->SetData(oacSetFeatureTypeWaferFeatureModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferFeatureModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferFeatureModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferFeatureModTypeEnum_FromoaWaferFeatureModTypeEnum(oaWaferFeatureModTypeEnum ob)
{
    if (ob==oacSetNameWaferFeatureModType) return PyString_FromString("oacSetNameWaferFeatureModType");
    if (ob==oacSetBoundaryWaferFeatureModType) return PyString_FromString("oacSetBoundaryWaferFeatureModType");
    if (ob==oacSetFeatureTypeWaferFeatureModType) return PyString_FromString("oacSetFeatureTypeWaferFeatureModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferFeatureModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferFeatureModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferFeatureModTypeEnum_FromoaWaferFeatureModTypeEnum(oaWaferFeatureModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferFeatureModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferFeatureModTypeEnum_doc[] =
"Type convert function for enum: oaWaferFeatureModTypeEnum";
                               
static PyMethodDef PyoaWaferFeatureModTypeEnum_method =
  {"oaWaferFeatureModTypeEnum",(PyCFunction)PyoaWaferFeatureModTypeEnum_TypeFunction,METH_VARARGS,oaWaferFeatureModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferFeatureModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameWaferFeatureModType");
    PyDict_SetItemString(mod_dict,"oacSetNameWaferFeatureModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBoundaryWaferFeatureModType");
    PyDict_SetItemString(mod_dict,"oacSetBoundaryWaferFeatureModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetFeatureTypeWaferFeatureModType");
    PyDict_SetItemString(mod_dict,"oacSetFeatureTypeWaferFeatureModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferFeatureModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferFeatureModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferFeatureModTypeEnum\n");
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
// Wrapper Implementation for Class: oaWaferFeatureType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferFeatureType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferFeatureType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferFeatureTypeObject* self = (PyoaWaferFeatureTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferFeatureEnum)
    {
        PyParamoaWaferFeatureEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWaferFeatureEnum_Convert,&p1)) {
            self->value =  new oaWaferFeatureType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaWaferFeatureType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaWaferFeatureType)
    {
        PyParamoaWaferFeatureType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferFeatureType_Convert,&p1)) {
            self->value= new oaWaferFeatureType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaWaferFeatureType, Choices are:\n"
        "    (oaWaferFeatureEnum)\n"
        "    (oaString)\n"
        "    (oaWaferFeatureType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferFeatureType_tp_dealloc(PyoaWaferFeatureTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferFeatureType_tp_repr(PyObject *ob)
{
    PyParamoaWaferFeatureType value;
    int convert_status=PyoaWaferFeatureType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaWaferFeatureType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferFeatureType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferFeatureType v1;
    PyParamoaWaferFeatureType v2;
    int convert_status1=PyoaWaferFeatureType_Convert(ob1,&v1);
    int convert_status2=PyoaWaferFeatureType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferFeatureType_Convert(PyObject* ob,PyParamoaWaferFeatureType* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferFeatureType_Check(ob)) {
        result->SetData(  ((PyoaWaferFeatureTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferFeatureType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferFeatureType_FromoaWaferFeatureType(oaWaferFeatureType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaWaferFeatureType_Type.tp_alloc(&PyoaWaferFeatureType_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferFeatureTypeObject* self = (PyoaWaferFeatureTypeObject*)bself;
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
static char oaWaferFeatureType_getName_doc[] = 
"Class: oaWaferFeatureType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaWaferFeatureEnum value.\n"
;

static PyObject*
oaWaferFeatureType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeatureType data;
    int convert_status=PyoaWaferFeatureType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureTypeObject* self=(PyoaWaferFeatureTypeObject*)ob;

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
static char oaWaferFeatureType_oaWaferFeatureEnum_doc[] = 
"Class: oaWaferFeatureType, Function: oaWaferFeatureEnum\n"
"  Paramegers: ()\n"
"    Calls: oaWaferFeatureEnum oaWaferFeatureEnum() const\n"
"    Signature: operator oaWaferFeatureEnum|simple-oaWaferFeatureEnum|\n"
"    BrowseData: 1\n"
"    This function casts this oaWaferFeatureType into its corresponding #oaWaferFeatureEnum value.\n"
;

static PyObject*
oaWaferFeatureType_oaWaferFeatureEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferFeatureType data;
    int convert_status=PyoaWaferFeatureType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferFeatureTypeObject* self=(PyoaWaferFeatureTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferFeatureEnum result= (data.DataCall()->operator oaWaferFeatureEnum());
        return PyoaWaferFeatureEnum_FromoaWaferFeatureEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaWaferFeatureType_assign_doc[] = 
"Class: oaWaferFeatureType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferFeatureType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferFeatureType data;
  int convert_status=PyoaWaferFeatureType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferFeatureType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferFeatureType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferFeatureType_methodlist[] = {
    {"getName",(PyCFunction)oaWaferFeatureType_getName,METH_VARARGS,oaWaferFeatureType_getName_doc},
    {"oaWaferFeatureEnum",(PyCFunction)oaWaferFeatureType_oaWaferFeatureEnum,METH_VARARGS,oaWaferFeatureType_oaWaferFeatureEnum_doc},
    {"assign",(PyCFunction)oaWaferFeatureType_tp_assign,METH_VARARGS,oaWaferFeatureType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferFeatureType_doc[] = 
"Class: oaWaferFeatureType\n"
"  The oaWaferFeatureType class encapsulates the enumerated values that describe different wafer feature types.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaWaferFeatureEnum\n"
"Constructors:\n"
"  Paramegers: (oaWaferFeatureEnum)\n"
"    Calls: oaWaferFeatureType(oaWaferFeatureEnum valueIn)\n"
"    Signature: oaWaferFeatureType||simple-oaWaferFeatureEnum,\n"
"    This function constructs an instance of an oaWaferFeatureType using the specified #oaWaferFeatureEnum value.\n"
"    valueIn\n"
"    Specifies the wafer feature type value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaWaferFeatureType(const oaString& name)\n"
"    Signature: oaWaferFeatureType||cref-oaString,\n"
"    This function constructs an instance of an oaWaferFeatureType class using the #oaWaferFeatureEnum value associated with the specified name . This name must be defined in the legal set of names associated with #oaWaferFeatureEnum.\n"
"    name\n"
"    The string corresponding to an #oaWaferFeatureEnum\n"
"    oacInvalidWaferFeatureName\n"
"  Paramegers: (oaWaferFeatureType)\n"
"    Calls: (const oaWaferFeatureType&)\n"
"    Signature: oaWaferFeatureType||cref-oaWaferFeatureType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferFeatureType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferFeatureType",
    sizeof(PyoaWaferFeatureTypeObject),
    0,
    (destructor)oaWaferFeatureType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferFeatureType_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferFeatureType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferFeatureType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferFeatureType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferFeatureType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferFeatureType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferFeatureType_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferFeatureType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferFeatureType",
           (PyObject*)(&PyoaWaferFeatureType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferFeatureType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaWaferModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferModTypeEnum_Convert(PyObject* ob,PyParamoaWaferModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetDBUPerWUWaferModType")==0) { result->SetData(oacSetDBUPerWUWaferModType); return 1;}
        if (strcasecmp(str,"oacSetWaferUnitsWaferModType")==0) { result->SetData(oacSetWaferUnitsWaferModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferModTypeEnum_FromoaWaferModTypeEnum(oaWaferModTypeEnum ob)
{
    if (ob==oacSetDBUPerWUWaferModType) return PyString_FromString("oacSetDBUPerWUWaferModType");
    if (ob==oacSetWaferUnitsWaferModType) return PyString_FromString("oacSetWaferUnitsWaferModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferModTypeEnum_FromoaWaferModTypeEnum(oaWaferModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferModTypeEnum_doc[] =
"Type convert function for enum: oaWaferModTypeEnum";
                               
static PyMethodDef PyoaWaferModTypeEnum_method =
  {"oaWaferModTypeEnum",(PyCFunction)PyoaWaferModTypeEnum_TypeFunction,METH_VARARGS,oaWaferModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetDBUPerWUWaferModType");
    PyDict_SetItemString(mod_dict,"oacSetDBUPerWUWaferModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetWaferUnitsWaferModType");
    PyDict_SetItemString(mod_dict,"oacSetWaferUnitsWaferModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferModTypeEnum\n");
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
// Wrapper Implementation for Class: oaWaferMsgIds
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferMsgIds_Convert(PyObject* ob,PyParamoaWaferMsgIds* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacInvalidWafer")==0) { result->SetData(oacInvalidWafer); return 1;}
        if (strcasecmp(str,"oacInvalidWaferDataTypeName")==0) { result->SetData(oacInvalidWaferDataTypeName); return 1;}
        if (strcasecmp(str,"oacNotAWafer")==0) { result->SetData(oacNotAWafer); return 1;}
        if (strcasecmp(str,"oacSaveReadOnlyWafer")==0) { result->SetData(oacSaveReadOnlyWafer); return 1;}
        if (strcasecmp(str,"oacWaferLibNotFound")==0) { result->SetData(oacWaferLibNotFound); return 1;}
        if (strcasecmp(str,"oacInvalidAccessMode")==0) { result->SetData(oacInvalidAccessMode); return 1;}
        if (strcasecmp(str,"oacWaferCannotChangeScratchMode")==0) { result->SetData(oacWaferCannotChangeScratchMode); return 1;}
        if (strcasecmp(str,"oacWaferBeingPurged")==0) { result->SetData(oacWaferBeingPurged); return 1;}
        if (strcasecmp(str,"oacCannotDestroyOpenWafer")==0) { result->SetData(oacCannotDestroyOpenWafer); return 1;}
        if (strcasecmp(str,"oacDestroyCannotFindWafer")==0) { result->SetData(oacDestroyCannotFindWafer); return 1;}
        if (strcasecmp(str,"oacCannotFindWafer")==0) { result->SetData(oacCannotFindWafer); return 1;}
        if (strcasecmp(str,"oacWaferPrimaryFileDoesNotExist")==0) { result->SetData(oacWaferPrimaryFileDoesNotExist); return 1;}
        if (strcasecmp(str,"oacViewNotWafer")==0) { result->SetData(oacViewNotWafer); return 1;}
        if (strcasecmp(str,"oacCannotLockWafer")==0) { result->SetData(oacCannotLockWafer); return 1;}
        if (strcasecmp(str,"oacInvalidWaferUnitsTypeName")==0) { result->SetData(oacInvalidWaferUnitsTypeName); return 1;}
        if (strcasecmp(str,"oacInvalidWaferFeatureName")==0) { result->SetData(oacInvalidWaferFeatureName); return 1;}
        if (strcasecmp(str,"oacInvalidWaferDesc")==0) { result->SetData(oacInvalidWaferDesc); return 1;}
        if (strcasecmp(str,"oacWaferAlreadyHasWaferDesc")==0) { result->SetData(oacWaferAlreadyHasWaferDesc); return 1;}
        if (strcasecmp(str,"oacInvalidUsableDiamValue")==0) { result->SetData(oacInvalidUsableDiamValue); return 1;}
        if (strcasecmp(str,"oacInvalidTotalDiamValue")==0) { result->SetData(oacInvalidTotalDiamValue); return 1;}
        if (strcasecmp(str,"oacInvalidFrame")==0) { result->SetData(oacInvalidFrame); return 1;}
        if (strcasecmp(str,"oacFrameAlreadyExists")==0) { result->SetData(oacFrameAlreadyExists); return 1;}
        if (strcasecmp(str,"oacInvalidStepperMap")==0) { result->SetData(oacInvalidStepperMap); return 1;}
        if (strcasecmp(str,"oacStepperMapAlreadyExists")==0) { result->SetData(oacStepperMapAlreadyExists); return 1;}
        if (strcasecmp(str,"oacImageStepperMapNotInSameWafer")==0) { result->SetData(oacImageStepperMapNotInSameWafer); return 1;}
        if (strcasecmp(str,"oacInvalidImage")==0) { result->SetData(oacInvalidImage); return 1;}
        if (strcasecmp(str,"oacImageAlreadyExists")==0) { result->SetData(oacImageAlreadyExists); return 1;}
        if (strcasecmp(str,"oacImageHasExtraPoints")==0) { result->SetData(oacImageHasExtraPoints); return 1;}
        if (strcasecmp(str,"oacImageTooFewPoints")==0) { result->SetData(oacImageTooFewPoints); return 1;}
        if (strcasecmp(str,"oacInvalidReticle")==0) { result->SetData(oacInvalidReticle); return 1;}
        if (strcasecmp(str,"oacReticleHasExtraPoints")==0) { result->SetData(oacReticleHasExtraPoints); return 1;}
        if (strcasecmp(str,"oacReticleTooFewPoints")==0) { result->SetData(oacReticleTooFewPoints); return 1;}
        if (strcasecmp(str,"oacReticleAlreadyExists")==0) { result->SetData(oacReticleAlreadyExists); return 1;}
        if (strcasecmp(str,"oacInvalidWaferFeature")==0) { result->SetData(oacInvalidWaferFeature); return 1;}
        if (strcasecmp(str,"oacWaferFeatureAlreadyExists")==0) { result->SetData(oacWaferFeatureAlreadyExists); return 1;}
        if (strcasecmp(str,"oacWaferFeatureHasExtraPoints")==0) { result->SetData(oacWaferFeatureHasExtraPoints); return 1;}
        if (strcasecmp(str,"oacWaferFeatureTooFewPoints")==0) { result->SetData(oacWaferFeatureTooFewPoints); return 1;}
        if (strcasecmp(str,"oacInvalidDesignInst")==0) { result->SetData(oacInvalidDesignInst); return 1;}
        if (strcasecmp(str,"oacDesignInstAlreadyExists")==0) { result->SetData(oacDesignInstAlreadyExists); return 1;}
        if (strcasecmp(str,"oacDesignInstInvalidMapLayer")==0) { result->SetData(oacDesignInstInvalidMapLayer); return 1;}
        if (strcasecmp(str,"oacInvalidReticleUsageName")==0) { result->SetData(oacInvalidReticleUsageName); return 1;}
        if (strcasecmp(str,"oacInvalidFrameInst")==0) { result->SetData(oacInvalidFrameInst); return 1;}
        if (strcasecmp(str,"oacFrameInstAlreadyExists")==0) { result->SetData(oacFrameInstAlreadyExists); return 1;}
        if (strcasecmp(str,"oacFrameInstOwnerAndMasterAreSame")==0) { result->SetData(oacFrameInstOwnerAndMasterAreSame); return 1;}
        if (strcasecmp(str,"oacFrameInstOwnerAndMasterDiffWafer")==0) { result->SetData(oacFrameInstOwnerAndMasterDiffWafer); return 1;}
        if (strcasecmp(str,"oacInvalidReticleRef")==0) { result->SetData(oacInvalidReticleRef); return 1;}
        if (strcasecmp(str,"oacReticleRefAlreadyExists")==0) { result->SetData(oacReticleRefAlreadyExists); return 1;}
        if (strcasecmp(str,"oacReticleRefAndRefInSameWafer")==0) { result->SetData(oacReticleRefAndRefInSameWafer); return 1;}
        if (strcasecmp(str,"oacWaferCannotGetReadAccess")==0) { result->SetData(oacWaferCannotGetReadAccess); return 1;}
        if (strcasecmp(str,"oacWaferCannotGetWriteAccess")==0) { result->SetData(oacWaferCannotGetWriteAccess); return 1;}
        if (strcasecmp(str,"oacWaferHasReadNeedWriteAccess")==0) { result->SetData(oacWaferHasReadNeedWriteAccess); return 1;}
        if (strcasecmp(str,"oacInvalidWaferObject")==0) { result->SetData(oacInvalidWaferObject); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferMsgIds)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferMsgIds Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferMsgIds_FromoaWaferMsgIds(oaWaferMsgIds ob)
{
    if (ob==oacInvalidWafer) return PyString_FromString("oacInvalidWafer");
    if (ob==oacInvalidWaferDataTypeName) return PyString_FromString("oacInvalidWaferDataTypeName");
    if (ob==oacNotAWafer) return PyString_FromString("oacNotAWafer");
    if (ob==oacSaveReadOnlyWafer) return PyString_FromString("oacSaveReadOnlyWafer");
    if (ob==oacWaferLibNotFound) return PyString_FromString("oacWaferLibNotFound");
    if (ob==oacInvalidAccessMode) return PyString_FromString("oacInvalidAccessMode");
    if (ob==oacWaferCannotChangeScratchMode) return PyString_FromString("oacWaferCannotChangeScratchMode");
    if (ob==oacWaferBeingPurged) return PyString_FromString("oacWaferBeingPurged");
    if (ob==oacCannotDestroyOpenWafer) return PyString_FromString("oacCannotDestroyOpenWafer");
    if (ob==oacDestroyCannotFindWafer) return PyString_FromString("oacDestroyCannotFindWafer");
    if (ob==oacCannotFindWafer) return PyString_FromString("oacCannotFindWafer");
    if (ob==oacWaferPrimaryFileDoesNotExist) return PyString_FromString("oacWaferPrimaryFileDoesNotExist");
    if (ob==oacViewNotWafer) return PyString_FromString("oacViewNotWafer");
    if (ob==oacCannotLockWafer) return PyString_FromString("oacCannotLockWafer");
    if (ob==oacInvalidWaferUnitsTypeName) return PyString_FromString("oacInvalidWaferUnitsTypeName");
    if (ob==oacInvalidWaferFeatureName) return PyString_FromString("oacInvalidWaferFeatureName");
    if (ob==oacInvalidWaferDesc) return PyString_FromString("oacInvalidWaferDesc");
    if (ob==oacWaferAlreadyHasWaferDesc) return PyString_FromString("oacWaferAlreadyHasWaferDesc");
    if (ob==oacInvalidUsableDiamValue) return PyString_FromString("oacInvalidUsableDiamValue");
    if (ob==oacInvalidTotalDiamValue) return PyString_FromString("oacInvalidTotalDiamValue");
    if (ob==oacInvalidFrame) return PyString_FromString("oacInvalidFrame");
    if (ob==oacFrameAlreadyExists) return PyString_FromString("oacFrameAlreadyExists");
    if (ob==oacInvalidStepperMap) return PyString_FromString("oacInvalidStepperMap");
    if (ob==oacStepperMapAlreadyExists) return PyString_FromString("oacStepperMapAlreadyExists");
    if (ob==oacImageStepperMapNotInSameWafer) return PyString_FromString("oacImageStepperMapNotInSameWafer");
    if (ob==oacInvalidImage) return PyString_FromString("oacInvalidImage");
    if (ob==oacImageAlreadyExists) return PyString_FromString("oacImageAlreadyExists");
    if (ob==oacImageHasExtraPoints) return PyString_FromString("oacImageHasExtraPoints");
    if (ob==oacImageTooFewPoints) return PyString_FromString("oacImageTooFewPoints");
    if (ob==oacInvalidReticle) return PyString_FromString("oacInvalidReticle");
    if (ob==oacReticleHasExtraPoints) return PyString_FromString("oacReticleHasExtraPoints");
    if (ob==oacReticleTooFewPoints) return PyString_FromString("oacReticleTooFewPoints");
    if (ob==oacReticleAlreadyExists) return PyString_FromString("oacReticleAlreadyExists");
    if (ob==oacInvalidWaferFeature) return PyString_FromString("oacInvalidWaferFeature");
    if (ob==oacWaferFeatureAlreadyExists) return PyString_FromString("oacWaferFeatureAlreadyExists");
    if (ob==oacWaferFeatureHasExtraPoints) return PyString_FromString("oacWaferFeatureHasExtraPoints");
    if (ob==oacWaferFeatureTooFewPoints) return PyString_FromString("oacWaferFeatureTooFewPoints");
    if (ob==oacInvalidDesignInst) return PyString_FromString("oacInvalidDesignInst");
    if (ob==oacDesignInstAlreadyExists) return PyString_FromString("oacDesignInstAlreadyExists");
    if (ob==oacDesignInstInvalidMapLayer) return PyString_FromString("oacDesignInstInvalidMapLayer");
    if (ob==oacInvalidReticleUsageName) return PyString_FromString("oacInvalidReticleUsageName");
    if (ob==oacInvalidFrameInst) return PyString_FromString("oacInvalidFrameInst");
    if (ob==oacFrameInstAlreadyExists) return PyString_FromString("oacFrameInstAlreadyExists");
    if (ob==oacFrameInstOwnerAndMasterAreSame) return PyString_FromString("oacFrameInstOwnerAndMasterAreSame");
    if (ob==oacFrameInstOwnerAndMasterDiffWafer) return PyString_FromString("oacFrameInstOwnerAndMasterDiffWafer");
    if (ob==oacInvalidReticleRef) return PyString_FromString("oacInvalidReticleRef");
    if (ob==oacReticleRefAlreadyExists) return PyString_FromString("oacReticleRefAlreadyExists");
    if (ob==oacReticleRefAndRefInSameWafer) return PyString_FromString("oacReticleRefAndRefInSameWafer");
    if (ob==oacWaferCannotGetReadAccess) return PyString_FromString("oacWaferCannotGetReadAccess");
    if (ob==oacWaferCannotGetWriteAccess) return PyString_FromString("oacWaferCannotGetWriteAccess");
    if (ob==oacWaferHasReadNeedWriteAccess) return PyString_FromString("oacWaferHasReadNeedWriteAccess");
    if (ob==oacInvalidWaferObject) return PyString_FromString("oacInvalidWaferObject");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferMsgIds_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferMsgIds e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferMsgIds_FromoaWaferMsgIds(oaWaferMsgIds(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferMsgIds_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferMsgIds_doc[] =
"Type convert function for enum: oaWaferMsgIds";
                               
static PyMethodDef PyoaWaferMsgIds_method =
  {"oaWaferMsgIds",(PyCFunction)PyoaWaferMsgIds_TypeFunction,METH_VARARGS,oaWaferMsgIds_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferMsgIds_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacInvalidWafer");
    PyDict_SetItemString(mod_dict,"oacInvalidWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferDataTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferDataTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNotAWafer");
    PyDict_SetItemString(mod_dict,"oacNotAWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSaveReadOnlyWafer");
    PyDict_SetItemString(mod_dict,"oacSaveReadOnlyWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferLibNotFound");
    PyDict_SetItemString(mod_dict,"oacWaferLibNotFound",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidAccessMode");
    PyDict_SetItemString(mod_dict,"oacInvalidAccessMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferCannotChangeScratchMode");
    PyDict_SetItemString(mod_dict,"oacWaferCannotChangeScratchMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferBeingPurged");
    PyDict_SetItemString(mod_dict,"oacWaferBeingPurged",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotDestroyOpenWafer");
    PyDict_SetItemString(mod_dict,"oacCannotDestroyOpenWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDestroyCannotFindWafer");
    PyDict_SetItemString(mod_dict,"oacDestroyCannotFindWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotFindWafer");
    PyDict_SetItemString(mod_dict,"oacCannotFindWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferPrimaryFileDoesNotExist");
    PyDict_SetItemString(mod_dict,"oacWaferPrimaryFileDoesNotExist",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViewNotWafer");
    PyDict_SetItemString(mod_dict,"oacViewNotWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotLockWafer");
    PyDict_SetItemString(mod_dict,"oacCannotLockWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferUnitsTypeName");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferUnitsTypeName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferFeatureName");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferFeatureName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferDesc");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferDesc",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferAlreadyHasWaferDesc");
    PyDict_SetItemString(mod_dict,"oacWaferAlreadyHasWaferDesc",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidUsableDiamValue");
    PyDict_SetItemString(mod_dict,"oacInvalidUsableDiamValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidTotalDiamValue");
    PyDict_SetItemString(mod_dict,"oacInvalidTotalDiamValue",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidFrame");
    PyDict_SetItemString(mod_dict,"oacInvalidFrame",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacFrameAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidStepperMap");
    PyDict_SetItemString(mod_dict,"oacInvalidStepperMap",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStepperMapAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacStepperMapAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacImageStepperMapNotInSameWafer");
    PyDict_SetItemString(mod_dict,"oacImageStepperMapNotInSameWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidImage");
    PyDict_SetItemString(mod_dict,"oacInvalidImage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacImageAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacImageAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacImageHasExtraPoints");
    PyDict_SetItemString(mod_dict,"oacImageHasExtraPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacImageTooFewPoints");
    PyDict_SetItemString(mod_dict,"oacImageTooFewPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidReticle");
    PyDict_SetItemString(mod_dict,"oacInvalidReticle",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleHasExtraPoints");
    PyDict_SetItemString(mod_dict,"oacReticleHasExtraPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleTooFewPoints");
    PyDict_SetItemString(mod_dict,"oacReticleTooFewPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacReticleAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferFeature");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferFeature",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferFeatureAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacWaferFeatureAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferFeatureHasExtraPoints");
    PyDict_SetItemString(mod_dict,"oacWaferFeatureHasExtraPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferFeatureTooFewPoints");
    PyDict_SetItemString(mod_dict,"oacWaferFeatureTooFewPoints",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidDesignInst");
    PyDict_SetItemString(mod_dict,"oacInvalidDesignInst",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDesignInstAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacDesignInstAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDesignInstInvalidMapLayer");
    PyDict_SetItemString(mod_dict,"oacDesignInstInvalidMapLayer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidReticleUsageName");
    PyDict_SetItemString(mod_dict,"oacInvalidReticleUsageName",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidFrameInst");
    PyDict_SetItemString(mod_dict,"oacInvalidFrameInst",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameInstAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacFrameInstAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameInstOwnerAndMasterAreSame");
    PyDict_SetItemString(mod_dict,"oacFrameInstOwnerAndMasterAreSame",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFrameInstOwnerAndMasterDiffWafer");
    PyDict_SetItemString(mod_dict,"oacFrameInstOwnerAndMasterDiffWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidReticleRef");
    PyDict_SetItemString(mod_dict,"oacInvalidReticleRef",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleRefAlreadyExists");
    PyDict_SetItemString(mod_dict,"oacReticleRefAlreadyExists",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReticleRefAndRefInSameWafer");
    PyDict_SetItemString(mod_dict,"oacReticleRefAndRefInSameWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferCannotGetReadAccess");
    PyDict_SetItemString(mod_dict,"oacWaferCannotGetReadAccess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferCannotGetWriteAccess");
    PyDict_SetItemString(mod_dict,"oacWaferCannotGetWriteAccess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWaferHasReadNeedWriteAccess");
    PyDict_SetItemString(mod_dict,"oacWaferHasReadNeedWriteAccess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInvalidWaferObject");
    PyDict_SetItemString(mod_dict,"oacInvalidWaferObject",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferMsgIds_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferMsgIds",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferMsgIds\n");
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
// Wrapper Implementation for Class: oaWaferObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferObjectObject* self = (PyoaWaferObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferObject)
    {
        PyParamoaWaferObject p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferObject_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaWaferObject, Choices are:\n"
        "    (oaWaferObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferObject_tp_dealloc(PyoaWaferObjectObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferObject_tp_repr(PyObject *ob)
{
    PyParamoaWaferObject value;
    int convert_status=PyoaWaferObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaWaferObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferObject v1;
    PyParamoaWaferObject v2;
    int convert_status1=PyoaWaferObject_Convert(ob1,&v1);
    int convert_status2=PyoaWaferObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferObject_Convert(PyObject* ob,PyParamoaWaferObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferObject_Check(ob)) {
        result->SetData( (oaWaferObject**) ((PyoaWaferObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferObject_FromoaWaferObject(oaWaferObject** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaWaferObject* data=*value;
        if (data->getType()==oacWaferDescType) return PyoaWaferDesc_FromoaWaferDesc((oaWaferDesc**)value,borrow,lock);
        if (data->getType()==oacReticleRefType) return PyoaReticleRef_FromoaReticleRef((oaReticleRef**)value,borrow,lock);
        if (data->getType()==oacImageType) return PyoaImage_FromoaImage((oaImage**)value,borrow,lock);
        if (data->getType()==oacFrameInstType) return PyoaFrameInst_FromoaFrameInst((oaFrameInst**)value,borrow,lock);
        if (data->getType()==oacStepperMapType) return PyoaStepperMap_FromoaStepperMap((oaStepperMap**)value,borrow,lock);
        if (data->getType()==oacWaferType) return PyoaWafer_FromoaWafer((oaWafer**)value,borrow,lock);
        if (data->getType()==oacWaferFeatureType) return PyoaWaferFeature_FromoaWaferFeature((oaWaferFeature**)value,borrow,lock);
        if (data->getType()==oacDesignInstType) return PyoaDesignInst_FromoaDesignInst((oaDesignInst**)value,borrow,lock);
        if (data->getType()==oacReticleType) return PyoaReticle_FromoaReticle((oaReticle**)value,borrow,lock);
        if (data->getType()==oacFrameType) return PyoaFrame_FromoaFrame((oaFrame**)value,borrow,lock);
        PyObject* bself = PyoaWaferObject_Type.tp_alloc(&PyoaWaferObject_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferObjectObject* self = (PyoaWaferObjectObject*)bself;
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
PyObject* PyoaWaferObject_FromoaWaferObject(oaWaferObject* data)
{
    if (data) {
        if (data->getType()==oacWaferDescType) return PyoaWaferDesc_FromoaWaferDesc((oaWaferDesc*)data);
        if (data->getType()==oacReticleRefType) return PyoaReticleRef_FromoaReticleRef((oaReticleRef*)data);
        if (data->getType()==oacImageType) return PyoaImage_FromoaImage((oaImage*)data);
        if (data->getType()==oacFrameInstType) return PyoaFrameInst_FromoaFrameInst((oaFrameInst*)data);
        if (data->getType()==oacStepperMapType) return PyoaStepperMap_FromoaStepperMap((oaStepperMap*)data);
        if (data->getType()==oacWaferType) return PyoaWafer_FromoaWafer((oaWafer*)data);
        if (data->getType()==oacWaferFeatureType) return PyoaWaferFeature_FromoaWaferFeature((oaWaferFeature*)data);
        if (data->getType()==oacDesignInstType) return PyoaDesignInst_FromoaDesignInst((oaDesignInst*)data);
        if (data->getType()==oacReticleType) return PyoaReticle_FromoaReticle((oaReticle*)data);
        if (data->getType()==oacFrameType) return PyoaFrame_FromoaFrame((oaFrame*)data);
       PyObject* bself = PyoaWaferObject_Type.tp_alloc(&PyoaWaferObject_Type,0);
       if (bself == NULL) return bself;
       PyoaWaferObjectObject* self = (PyoaWaferObjectObject*)bself;
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
static char oaWaferObject_getWafer_doc[] = 
"Class: oaWaferObject, Function: getWafer\n"
"  Paramegers: ()\n"
"    Calls: oaWafer* getWafer() const\n"
"    Signature: getWafer|ptr-oaWafer|\n"
"    BrowseData: 1\n"
"    This function returns the wafer that contains the oaWaferObject.\n"
"    This returns the same value as oaObject::getDatabase , but this is more convenient where the object is known to be an oaWaferObject.\n"
;

static PyObject*
oaWaferObject_getWafer(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferObject data;
    int convert_status=PyoaWaferObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferObjectObject* self=(PyoaWaferObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferp result= (data.DataCall()->getWafer());
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
static char oaWaferObject_isNull_doc[] =
"Class: oaWaferObject, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaWaferObject_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaWaferObject data;
    int convert_status=PyoaWaferObject_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaWaferObject_assign_doc[] = 
"Class: oaWaferObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferObject data;
  int convert_status=PyoaWaferObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferObject_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferObject_methodlist[] = {
    {"getWafer",(PyCFunction)oaWaferObject_getWafer,METH_VARARGS,oaWaferObject_getWafer_doc},
    {"isNull",(PyCFunction)oaWaferObject_tp_isNull,METH_VARARGS,oaWaferObject_isNull_doc},
    {"assign",(PyCFunction)oaWaferObject_tp_assign,METH_VARARGS,oaWaferObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferObject_doc[] = 
"Class: oaWaferObject\n"
"  This is the abstract base class for all managed objects that are specific to oaWafer databases.\n"
"  There is a tree of classes derived from oaWaferObject. For most of these classes, an oaWaferObject can be classified using its oaType value. See oaObject::getType for more information.\n"
"  Note that oaProp , oaGroup , and oaAppObject instances can be stored in an oaWafer even though they are not oaWaferObjects. These classes may appear in every database, so they are classified only as oaObjects.\n"
"Constructors:\n"
"  Paramegers: (oaWaferObject)\n"
"    Calls: (const oaWaferObject&)\n"
"    Signature: oaWaferObject||cref-oaWaferObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferObject",
    sizeof(PyoaWaferObjectObject),
    0,
    (destructor)oaWaferObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferObject_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferObject_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferObject",
           (PyObject*)(&PyoaWaferObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaWaferUnitsEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWaferUnitsEnum_Convert(PyObject* ob,PyParamoaWaferUnitsEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMicronWaferUnits")==0) { result->SetData(oacMicronWaferUnits); return 1;}
        if (strcasecmp(str,"oacMilWaferUnits")==0) { result->SetData(oacMilWaferUnits); return 1;}
        if (strcasecmp(str,"oacMillimeterWaferUnits")==0) { result->SetData(oacMillimeterWaferUnits); return 1;}
        if (strcasecmp(str,"oacNanometerWaferUnits")==0) { result->SetData(oacNanometerWaferUnits); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWaferUnitsEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferUnitsEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWaferUnitsEnum_FromoaWaferUnitsEnum(oaWaferUnitsEnum ob)
{
    if (ob==oacMicronWaferUnits) return PyString_FromString("oacMicronWaferUnits");
    if (ob==oacMilWaferUnits) return PyString_FromString("oacMilWaferUnits");
    if (ob==oacMillimeterWaferUnits) return PyString_FromString("oacMillimeterWaferUnits");
    if (ob==oacNanometerWaferUnits) return PyString_FromString("oacNanometerWaferUnits");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWaferUnitsEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWaferUnitsEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWaferUnitsEnum_FromoaWaferUnitsEnum(oaWaferUnitsEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWaferUnitsEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWaferUnitsEnum_doc[] =
"Type convert function for enum: oaWaferUnitsEnum";
                               
static PyMethodDef PyoaWaferUnitsEnum_method =
  {"oaWaferUnitsEnum",(PyCFunction)PyoaWaferUnitsEnum_TypeFunction,METH_VARARGS,oaWaferUnitsEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWaferUnitsEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMicronWaferUnits");
    PyDict_SetItemString(mod_dict,"oacMicronWaferUnits",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMilWaferUnits");
    PyDict_SetItemString(mod_dict,"oacMilWaferUnits",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMillimeterWaferUnits");
    PyDict_SetItemString(mod_dict,"oacMillimeterWaferUnits",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNanometerWaferUnits");
    PyDict_SetItemString(mod_dict,"oacNanometerWaferUnits",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWaferUnitsEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWaferUnitsEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWaferUnitsEnum\n");
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
// Wrapper Implementation for Class: oaWaferUnitsType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWaferUnitsType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWaferUnitsType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWaferUnitsTypeObject* self = (PyoaWaferUnitsTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWaferUnitsEnum)
    {
        PyParamoaWaferUnitsEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWaferUnitsEnum_Convert,&p1)) {
            self->value =  new oaWaferUnitsType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaWaferUnitsType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaWaferUnitsType)
    {
        PyParamoaWaferUnitsType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWaferUnitsType_Convert,&p1)) {
            self->value= new oaWaferUnitsType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaWaferUnitsType, Choices are:\n"
        "    (oaWaferUnitsEnum)\n"
        "    (oaString)\n"
        "    (oaWaferUnitsType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWaferUnitsType_tp_dealloc(PyoaWaferUnitsTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWaferUnitsType_tp_repr(PyObject *ob)
{
    PyParamoaWaferUnitsType value;
    int convert_status=PyoaWaferUnitsType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[38];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaWaferUnitsType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWaferUnitsType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWaferUnitsType v1;
    PyParamoaWaferUnitsType v2;
    int convert_status1=PyoaWaferUnitsType_Convert(ob1,&v1);
    int convert_status2=PyoaWaferUnitsType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWaferUnitsType_Convert(PyObject* ob,PyParamoaWaferUnitsType* result)
{
    if (ob == NULL) return 1;
    if (PyoaWaferUnitsType_Check(ob)) {
        result->SetData(  ((PyoaWaferUnitsTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWaferUnitsType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWaferUnitsType_FromoaWaferUnitsType(oaWaferUnitsType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaWaferUnitsType_Type.tp_alloc(&PyoaWaferUnitsType_Type,0);
        if (bself == NULL) return bself;
        PyoaWaferUnitsTypeObject* self = (PyoaWaferUnitsTypeObject*)bself;
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
static char oaWaferUnitsType_getName_doc[] = 
"Class: oaWaferUnitsType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaWaferUnitsTypeEnum object.\n"
;

static PyObject*
oaWaferUnitsType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferUnitsType data;
    int convert_status=PyoaWaferUnitsType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferUnitsTypeObject* self=(PyoaWaferUnitsTypeObject*)ob;

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
static char oaWaferUnitsType_oaWaferUnitsEnum_doc[] = 
"Class: oaWaferUnitsType, Function: oaWaferUnitsEnum\n"
"  Paramegers: ()\n"
"    Calls: oaWaferUnitsEnum oaWaferUnitsEnum() const\n"
"    Signature: operator oaWaferUnitsEnum|simple-oaWaferUnitsEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaWaferUnitsType object into its corresponding #oaWaferUnitsTypeEnum value.\n"
;

static PyObject*
oaWaferUnitsType_oaWaferUnitsEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWaferUnitsType data;
    int convert_status=PyoaWaferUnitsType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWaferUnitsTypeObject* self=(PyoaWaferUnitsTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferUnitsEnum result= (data.DataCall()->operator oaWaferUnitsEnum());
        return PyoaWaferUnitsEnum_FromoaWaferUnitsEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaWaferUnitsType_assign_doc[] = 
"Class: oaWaferUnitsType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWaferUnitsType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWaferUnitsType data;
  int convert_status=PyoaWaferUnitsType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWaferUnitsType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWaferUnitsType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWaferUnitsType_methodlist[] = {
    {"getName",(PyCFunction)oaWaferUnitsType_getName,METH_VARARGS,oaWaferUnitsType_getName_doc},
    {"oaWaferUnitsEnum",(PyCFunction)oaWaferUnitsType_oaWaferUnitsEnum,METH_VARARGS,oaWaferUnitsType_oaWaferUnitsEnum_doc},
    {"assign",(PyCFunction)oaWaferUnitsType_tp_assign,METH_VARARGS,oaWaferUnitsType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWaferUnitsType_doc[] = 
"Class: oaWaferUnitsType\n"
"  The oaWaferUnitsType class encapsulates the enumerated values that describe the different types of wafer units.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaWaferUnitsEnum\n"
"Constructors:\n"
"  Paramegers: (oaWaferUnitsEnum)\n"
"    Calls: oaWaferUnitsType(oaWaferUnitsEnum valueIn)\n"
"    Signature: oaWaferUnitsType||simple-oaWaferUnitsEnum,\n"
"    This function constructs an instance of an oaWaferUnitsType class using the specified #oaWaferUnitsTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaWaferUnitsType(const oaString& name)\n"
"    Signature: oaWaferUnitsType||cref-oaString,\n"
"    This function constructs an instance of an oaWaferUnitsType class using the #oaWaferUnitsTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaWaferUnitsTypeEnum.\n"
"    oacInvalidWaferUnitsTypeName\n"
"  Paramegers: (oaWaferUnitsType)\n"
"    Calls: (const oaWaferUnitsType&)\n"
"    Signature: oaWaferUnitsType||cref-oaWaferUnitsType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWaferUnitsType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWaferUnitsType",
    sizeof(PyoaWaferUnitsTypeObject),
    0,
    (destructor)oaWaferUnitsType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWaferUnitsType_tp_compare,	/* tp_compare */
    (reprfunc)oaWaferUnitsType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWaferUnitsType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWaferUnitsType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWaferUnitsType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWaferUnitsType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWaferUnitsType_Type)<0) {
      printf("** PyType_Ready failed for: oaWaferUnitsType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWaferUnitsType",
           (PyObject*)(&PyoaWaferUnitsType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWaferUnitsType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaWidthLengthTableType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWidthLengthTableType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWidthLengthTableType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWidthLengthTableTypeObject* self = (PyoaWidthLengthTableTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaWidthLengthTableTypeEnum)
    {
        PyParamoaWidthLengthTableTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWidthLengthTableTypeEnum_Convert,&p1)) {
            self->value =  new oaWidthLengthTableType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaWidthLengthTableType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaWidthLengthTableType)
    {
        PyParamoaWidthLengthTableType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaWidthLengthTableType_Convert,&p1)) {
            self->value= new oaWidthLengthTableType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaWidthLengthTableType, Choices are:\n"
        "    (oaWidthLengthTableTypeEnum)\n"
        "    (oaString)\n"
        "    (oaWidthLengthTableType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWidthLengthTableType_tp_dealloc(PyoaWidthLengthTableTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWidthLengthTableType_tp_repr(PyObject *ob)
{
    PyParamoaWidthLengthTableType value;
    int convert_status=PyoaWidthLengthTableType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[44];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaWidthLengthTableType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWidthLengthTableType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWidthLengthTableType v1;
    PyParamoaWidthLengthTableType v2;
    int convert_status1=PyoaWidthLengthTableType_Convert(ob1,&v1);
    int convert_status2=PyoaWidthLengthTableType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWidthLengthTableType_Convert(PyObject* ob,PyParamoaWidthLengthTableType* result)
{
    if (ob == NULL) return 1;
    if (PyoaWidthLengthTableType_Check(ob)) {
        result->SetData(  ((PyoaWidthLengthTableTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWidthLengthTableType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWidthLengthTableType_FromoaWidthLengthTableType(oaWidthLengthTableType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaWidthLengthTableType_Type.tp_alloc(&PyoaWidthLengthTableType_Type,0);
        if (bself == NULL) return bself;
        PyoaWidthLengthTableTypeObject* self = (PyoaWidthLengthTableTypeObject*)bself;
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
static char oaWidthLengthTableType_getName_doc[] = 
"Class: oaWidthLengthTableType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name that corresponds to an oaWidthLengthTableTypeEnum value.\n"
"    Todo\n"
"    Check description of member function.\n"
;

static PyObject*
oaWidthLengthTableType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWidthLengthTableType data;
    int convert_status=PyoaWidthLengthTableType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWidthLengthTableTypeObject* self=(PyoaWidthLengthTableTypeObject*)ob;

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
static char oaWidthLengthTableType_oaWidthLengthTableTypeEnum_doc[] = 
"Class: oaWidthLengthTableType, Function: oaWidthLengthTableTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaWidthLengthTableTypeEnum oaWidthLengthTableTypeEnum() const\n"
"    Signature: operator oaWidthLengthTableTypeEnum|simple-oaWidthLengthTableTypeEnum|\n"
"    BrowseData: 1\n"
"    This returns the enum value of the enum wrapper class object.\n"
"    Todo\n"
"    Add description of member function.\n"
;

static PyObject*
oaWidthLengthTableType_oaWidthLengthTableTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWidthLengthTableType data;
    int convert_status=PyoaWidthLengthTableType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWidthLengthTableTypeObject* self=(PyoaWidthLengthTableTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaWidthLengthTableTypeEnum result= (data.DataCall()->operator oaWidthLengthTableTypeEnum());
        return PyoaWidthLengthTableTypeEnum_FromoaWidthLengthTableTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaWidthLengthTableType_assign_doc[] = 
"Class: oaWidthLengthTableType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWidthLengthTableType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWidthLengthTableType data;
  int convert_status=PyoaWidthLengthTableType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWidthLengthTableType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWidthLengthTableType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWidthLengthTableType_methodlist[] = {
    {"getName",(PyCFunction)oaWidthLengthTableType_getName,METH_VARARGS,oaWidthLengthTableType_getName_doc},
    {"oaWidthLengthTableTypeEnum",(PyCFunction)oaWidthLengthTableType_oaWidthLengthTableTypeEnum,METH_VARARGS,oaWidthLengthTableType_oaWidthLengthTableTypeEnum_doc},
    {"assign",(PyCFunction)oaWidthLengthTableType_tp_assign,METH_VARARGS,oaWidthLengthTableType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWidthLengthTableType_doc[] = 
"Class: oaWidthLengthTableType\n"
"  oaWidthLengthTableTypeEnum\n"
"  The oaWidthLengthTableType class is an enum wrapper class for oaWidthLengthTableTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  Todo\n"
"  Check detailed description of class. Make sure @wrapper tag is correct and check @enum list that follows this class description.\n"
"Constructors:\n"
"  Paramegers: (oaWidthLengthTableTypeEnum)\n"
"    Calls: oaWidthLengthTableType(oaWidthLengthTableTypeEnum valueIn)\n"
"    Signature: oaWidthLengthTableType||simple-oaWidthLengthTableTypeEnum,\n"
"    This is the constructor for the enum wrapper class that takes an enum value as input.\n"
"    valueIn\n"
"    Todo\n"
"    Complete description of member function. Add description of each parameter.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaWidthLengthTableType(const oaString& name)\n"
"    Signature: oaWidthLengthTableType||cref-oaString,\n"
"    This constructor for oaWidthLengthTableType wrapper class takes the string value of an oaWidthLengthTableTypeEnum.\n"
"    name\n"
"    The string value of an oaWidthLengthTableTypeEnum.\n"
"    oacInvalidWidthLengthTableTypeName\n"
"    Todo\n"
"    Complete description of member function. Add description of each parameter.\n"
"  Paramegers: (oaWidthLengthTableType)\n"
"    Calls: (const oaWidthLengthTableType&)\n"
"    Signature: oaWidthLengthTableType||cref-oaWidthLengthTableType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWidthLengthTableType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWidthLengthTableType",
    sizeof(PyoaWidthLengthTableTypeObject),
    0,
    (destructor)oaWidthLengthTableType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWidthLengthTableType_tp_compare,	/* tp_compare */
    (reprfunc)oaWidthLengthTableType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWidthLengthTableType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWidthLengthTableType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWidthLengthTableType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWidthLengthTableType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWidthLengthTableType_Type)<0) {
      printf("** PyType_Ready failed for: oaWidthLengthTableType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWidthLengthTableType",
           (PyObject*)(&PyoaWidthLengthTableType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWidthLengthTableType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaWidthLengthTableTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaWidthLengthTableTypeEnum_Convert(PyObject* ob,PyParamoaWidthLengthTableTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacWidthParallelRunLengthTableType")==0) { result->SetData(oacWidthParallelRunLengthTableType); return 1;}
        if (strcasecmp(str,"oacWidthWidthTableType")==0) { result->SetData(oacWidthWidthTableType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaWidthLengthTableTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWidthLengthTableTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaWidthLengthTableTypeEnum_FromoaWidthLengthTableTypeEnum(oaWidthLengthTableTypeEnum ob)
{
    if (ob==oacWidthParallelRunLengthTableType) return PyString_FromString("oacWidthParallelRunLengthTableType");
    if (ob==oacWidthWidthTableType) return PyString_FromString("oacWidthWidthTableType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaWidthLengthTableTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaWidthLengthTableTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaWidthLengthTableTypeEnum_FromoaWidthLengthTableTypeEnum(oaWidthLengthTableTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaWidthLengthTableTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaWidthLengthTableTypeEnum_doc[] =
"Type convert function for enum: oaWidthLengthTableTypeEnum";
                               
static PyMethodDef PyoaWidthLengthTableTypeEnum_method =
  {"oaWidthLengthTableTypeEnum",(PyCFunction)PyoaWidthLengthTableTypeEnum_TypeFunction,METH_VARARGS,oaWidthLengthTableTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaWidthLengthTableTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacWidthParallelRunLengthTableType");
    PyDict_SetItemString(mod_dict,"oacWidthParallelRunLengthTableType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWidthWidthTableType");
    PyDict_SetItemString(mod_dict,"oacWidthWidthTableType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaWidthLengthTableTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaWidthLengthTableTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaWidthLengthTableTypeEnum\n");
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
// Wrapper Implementation for Class: oaWinNS
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaWinNS_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaWinNS_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaWinNSObject* self = (PyoaWinNSObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaNameSpace*)  new oaWinNS();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaWinNS)
    {
        PyParamoaWinNS p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaWinNS_Convert,&p1)) {
            self->value = (oaNameSpace*)  new oaWinNS(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaWinNS, Choices are:\n"
        "    ()\n"
        "    (oaWinNS)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaWinNS_tp_dealloc(PyoaWinNSObject* self)
{
    if (!self->borrow) {
        delete (oaWinNS*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaWinNS_tp_repr(PyObject *ob)
{
    PyParamoaWinNS value;
    int convert_status=PyoaWinNS_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaWinNS::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaWinNS_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaWinNS v1;
    PyParamoaWinNS v2;
    int convert_status1=PyoaWinNS_Convert(ob1,&v1);
    int convert_status2=PyoaWinNS_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaWinNS_Convert(PyObject* ob,PyParamoaWinNS* result)
{
    if (ob == NULL) return 1;
    if (PyoaWinNS_Check(ob)) {
        result->SetData( (oaWinNS*) ((PyoaWinNSObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaWinNS Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaWinNS_FromoaWinNS(oaWinNS* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaWinNS_Type.tp_alloc(&PyoaWinNS_Type,0);
        if (bself == NULL) return bself;
        PyoaWinNSObject* self = (PyoaWinNSObject*)bself;
        self->value = (oaNameSpace*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWinNS_getType_doc[] = 
"Class: oaWinNS, Function: getType\n"
"  Paramegers: ([oaChar])\n"
"    Calls: oaNameType getType(const oaChar* in) const\n"
"    Signature: getType|simple-oaNameType|cptr-oaChar,\n"
"    Function getType\n"
;

static PyObject*
oaWinNS_getType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWinNS data;
    int convert_status=PyoaWinNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWinNSObject* self=(PyoaWinNSObject*)ob;

    PyParamoaChar_Array p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaChar_Array_Convert,&p1)) {
        oaNameType* result= new oaNameType(data.DataCall()->getType(p1.Data()));
        return PyoaNameType_FromoaNameType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaWinNS_isEqual_doc[] = 
"Class: oaWinNS, Function: isEqual\n"
"  Paramegers: (oaScalarName,oaScalarName)\n"
"    Calls: oaBoolean isEqual(const oaScalarName& n1,const oaScalarName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaScalarName,cref-oaScalarName,\n"
"    Function isEqual\n"
"  Paramegers: (oaVectorName,oaVectorName)\n"
"    Calls: oaBoolean isEqual(const oaVectorName& n1,const oaVectorName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaVectorName,cref-oaVectorName,\n"
"    Function isEqual\n"
"  Paramegers: (oaVectorBitName,oaVectorBitName)\n"
"    Calls: oaBoolean isEqual(const oaVectorBitName& n1,const oaVectorBitName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaVectorBitName,cref-oaVectorBitName,\n"
"    Function isEqual\n"
"  Paramegers: (oaBundleName,oaBundleName)\n"
"    Calls: oaBoolean isEqual(const oaBundleName& n1,const oaBundleName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaBundleName,cref-oaBundleName,\n"
"    Function isEqual\n"
"  Paramegers: (oaSimpleName,oaSimpleName)\n"
"    Calls: oaBoolean isEqual(const oaSimpleName& n1,const oaSimpleName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaSimpleName,cref-oaSimpleName,\n"
"    Function isEqual\n"
"  Paramegers: (oaName,oaName)\n"
"    Calls: oaBoolean isEqual(const oaName& n1,const oaName& n2) const\n"
"    Signature: isEqual|simple-oaBoolean|cref-oaName,cref-oaName,\n"
"    Function isEqual\n"
;

static PyObject*
oaWinNS_isEqual(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWinNS data;
    int convert_status=PyoaWinNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaWinNSObject* self=(PyoaWinNSObject*)ob;

    // Case: (oaScalarName,oaScalarName)
    {
        PyParamoaScalarName p1;
        PyParamoaScalarName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaScalarName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaVectorName,oaVectorName)
    {
        PyParamoaVectorName p1;
        PyParamoaVectorName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVectorName_Convert,&p1,
              &PyoaVectorName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaVectorBitName,oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVectorBitName_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBundleName,oaBundleName)
    {
        PyParamoaBundleName p1;
        PyParamoaBundleName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBundleName_Convert,&p1,
              &PyoaBundleName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleName,oaSimpleName)
    {
        PyParamoaSimpleName p1;
        PyParamoaSimpleName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaSimpleName_Convert,&p1,
              &PyoaSimpleName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaName,oaName)
    {
        PyParamoaName p1;
        PyParamoaName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaName_Convert,&p1,
              &PyoaName_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->isEqual(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaWinNS, function: isEqual, Choices are:\n"
        "    (oaScalarName,oaScalarName)\n"
        "    (oaVectorName,oaVectorName)\n"
        "    (oaVectorBitName,oaVectorBitName)\n"
        "    (oaBundleName,oaBundleName)\n"
        "    (oaSimpleName,oaSimpleName)\n"
        "    (oaName,oaName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaWinNS_assign_doc[] = 
"Class: oaWinNS, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaWinNS_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaWinNS data;
  int convert_status=PyoaWinNS_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaWinNS p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaWinNS_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaWinNS_methodlist[] = {
    {"getType",(PyCFunction)oaWinNS_getType,METH_VARARGS,oaWinNS_getType_doc},
    {"isEqual",(PyCFunction)oaWinNS_isEqual,METH_VARARGS,oaWinNS_isEqual_doc},
    {"assign",(PyCFunction)oaWinNS_tp_assign,METH_VARARGS,oaWinNS_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaWinNS_doc[] = 
"Class: oaWinNS\n"
"  The oaWinNS class implements the Windows name space used in name mapping. In conjunction with oaName objects, this class provides mapping between names in the Windows name space and the internal format of an oaName . See the Name Mapping Section of the Programmers for more information.\n"
"  The Windows namespace reflects the rules for creating directory names on Windows filesystems. It is used internally by OpenAccess to create cell and view directory names in libraries that are stored on such filesystems. This does not mean that applications must use this name space directly. The name mapping provided by the oaScalarNames used in the API allows the application to create the names with any name space they prefer.\n"
"  The Windows name space supports only scalar names. It does not support indexed, vectored, bundled, or hierarchical names. The Windows name space is case-insensitive and has reserved keywords. See the Windows Name Space Section of the Programmers Guide for a more detailed description of the characteristics of the Windows name space.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaWinNS()\n"
"    Signature: oaWinNS||\n"
"    This function constructs the oaWinNS instance.\n"
"  Paramegers: (oaWinNS)\n"
"    Calls: oaWinNS(const oaWinNS& ns)\n"
"    Signature: oaWinNS||cref-oaWinNS,\n"
"    This function creates a copy of the specified oaWinNS object.\n"
"  Paramegers: (oaWinNS)\n"
"    Calls: (const oaWinNS&)\n"
"    Signature: oaWinNS||cref-oaWinNS,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaWinNS_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaWinNS",
    sizeof(PyoaWinNSObject),
    0,
    (destructor)oaWinNS_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaWinNS_tp_compare,	/* tp_compare */
    (reprfunc)oaWinNS_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaWinNS_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaWinNS_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNameSpace_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaWinNS_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaWinNS_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaWinNS_Type)<0) {
      printf("** PyType_Ready failed for: oaWinNS\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaWinNS",
           (PyObject*)(&PyoaWinNS_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaWinNS\n");
       return -1;
    }
    return 0;
}

