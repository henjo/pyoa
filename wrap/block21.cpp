
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaFloatAppDef_oaViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaViaHeaderObject* self = (PyoaFloatAppDef_oaViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaViaHeader)
    {
        PyParamoaFloatAppDef_oaViaHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaViaHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaViaHeader, Choices are:\n"
        "    (oaFloatAppDef_oaViaHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaViaHeader_tp_dealloc(PyoaFloatAppDef_oaViaHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaViaHeader value;
    int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaFloatAppDef_oaViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaViaHeader v1;
    PyParamoaFloatAppDef_oaViaHeader v2;
    int convert_status1=PyoaFloatAppDef_oaViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaViaHeader_Convert(PyObject* ob,PyParamoaFloatAppDef_oaViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaViaHeader_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaViaHeader**) ((PyoaFloatAppDef_oaViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(oaFloatAppDef_oaViaHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaViaHeader* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaViaHeader_Type.tp_alloc(&PyoaFloatAppDef_oaViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaViaHeaderObject* self = (PyoaFloatAppDef_oaViaHeaderObject*)bself;
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
PyObject* PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(oaFloatAppDef_oaViaHeader* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaViaHeader_Type.tp_alloc(&PyoaFloatAppDef_oaViaHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaViaHeaderObject* self = (PyoaFloatAppDef_oaViaHeaderObject*)bself;
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
static char oaFloatAppDef_oaViaHeader_get_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: get\n"
"  Paramegers: (oaViaHeader)\n"
"    Calls: oaFloat get(const oaViaHeader* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaViaHeader,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaHeader data;
    int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaHeaderObject* self=(PyoaFloatAppDef_oaViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaViaHeader p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaHeader_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaHeader_getDefault_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaHeader data;
    int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaHeaderObject* self=(PyoaFloatAppDef_oaViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaHeader_set_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: set\n"
"  Paramegers: (oaViaHeader,oaFloat)\n"
"    Calls: void set(oaViaHeader* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaViaHeader,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaHeader data;
    int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaHeaderObject* self=(PyoaFloatAppDef_oaViaHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaViaHeader p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaViaHeader_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaViaHeader_isNull_doc[] =
"Class: oaFloatAppDef_oaViaHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaViaHeader data;
    int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaViaHeader_assign_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaViaHeader data;
  int convert_status=PyoaFloatAppDef_oaViaHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaViaHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaViaHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaViaHeader_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaViaHeader_get,METH_VARARGS,oaFloatAppDef_oaViaHeader_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaViaHeader_getDefault,METH_VARARGS,oaFloatAppDef_oaViaHeader_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaViaHeader_set,METH_VARARGS,oaFloatAppDef_oaViaHeader_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaViaHeader_tp_isNull,METH_VARARGS,oaFloatAppDef_oaViaHeader_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaViaHeader_tp_assign,METH_VARARGS,oaFloatAppDef_oaViaHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaHeader_doc[] = 
"Class: oaFloatAppDef_oaViaHeader\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaViaHeader)\n"
"    Calls: (const oaFloatAppDef_oaViaHeader&)\n"
"    Signature: oaFloatAppDef_oaViaHeader||cref-oaFloatAppDef_oaViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaViaHeader",
    sizeof(PyoaFloatAppDef_oaViaHeaderObject),
    0,
    (destructor)oaFloatAppDef_oaViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaViaHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaViaHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaHeader_static_find_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaViaHeader* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaViaHeader* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::find(p1.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaViaHeader, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaHeader_static_get_doc[] = 
"Class: oaFloatAppDef_oaViaHeader, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaViaHeader* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaHeader|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaViaHeader_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaHeaderp result= (oaFloatAppDef_oaViaHeader::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaViaHeader_FromoaFloatAppDef_oaViaHeader(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaViaHeader, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaViaHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaViaHeader_static_find,METH_VARARGS,oaFloatAppDef_oaViaHeader_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaViaHeader_static_get,METH_VARARGS,oaFloatAppDef_oaViaHeader_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaViaHeader",
           (PyObject*)(&PyoaFloatAppDef_oaViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaViaHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaViaHeader_Type.tp_dict;
    for(method=oaFloatAppDef_oaViaHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatAppDef_oaViaSpec
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaViaSpec_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaViaSpec_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaViaSpecObject* self = (PyoaFloatAppDef_oaViaSpecObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaViaSpec)
    {
        PyParamoaFloatAppDef_oaViaSpec p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaViaSpec_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaViaSpec, Choices are:\n"
        "    (oaFloatAppDef_oaViaSpec)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaViaSpec_tp_dealloc(PyoaFloatAppDef_oaViaSpecObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaViaSpec_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaViaSpec value;
    int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaFloatAppDef_oaViaSpec::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaViaSpec_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaViaSpec v1;
    PyParamoaFloatAppDef_oaViaSpec v2;
    int convert_status1=PyoaFloatAppDef_oaViaSpec_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaViaSpec_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaViaSpec_Convert(PyObject* ob,PyParamoaFloatAppDef_oaViaSpec* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaViaSpec_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaViaSpec**) ((PyoaFloatAppDef_oaViaSpecObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaViaSpec Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(oaFloatAppDef_oaViaSpec** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaViaSpec* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaViaSpec_Type.tp_alloc(&PyoaFloatAppDef_oaViaSpec_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaViaSpecObject* self = (PyoaFloatAppDef_oaViaSpecObject*)bself;
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
PyObject* PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(oaFloatAppDef_oaViaSpec* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaViaSpec_Type.tp_alloc(&PyoaFloatAppDef_oaViaSpec_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaViaSpecObject* self = (PyoaFloatAppDef_oaViaSpecObject*)bself;
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
static char oaFloatAppDef_oaViaSpec_get_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: get\n"
"  Paramegers: (oaViaSpec)\n"
"    Calls: oaFloat get(const oaViaSpec* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaViaSpec,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaSpec data;
    int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaSpecObject* self=(PyoaFloatAppDef_oaViaSpecObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaViaSpec p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViaSpec_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaSpec_getDefault_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaSpec data;
    int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaSpecObject* self=(PyoaFloatAppDef_oaViaSpecObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaSpec_set_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: set\n"
"  Paramegers: (oaViaSpec,oaFloat)\n"
"    Calls: void set(oaViaSpec* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaViaSpec,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaViaSpec data;
    int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViaSpecObject* self=(PyoaFloatAppDef_oaViaSpecObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaViaSpec p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaViaSpec_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaViaSpec_isNull_doc[] =
"Class: oaFloatAppDef_oaViaSpec, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaViaSpec data;
    int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaViaSpec_assign_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaViaSpec data;
  int convert_status=PyoaFloatAppDef_oaViaSpec_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaViaSpec p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaViaSpec_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaViaSpec_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaViaSpec_get,METH_VARARGS,oaFloatAppDef_oaViaSpec_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaViaSpec_getDefault,METH_VARARGS,oaFloatAppDef_oaViaSpec_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaViaSpec_set,METH_VARARGS,oaFloatAppDef_oaViaSpec_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaViaSpec_tp_isNull,METH_VARARGS,oaFloatAppDef_oaViaSpec_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaViaSpec_tp_assign,METH_VARARGS,oaFloatAppDef_oaViaSpec_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaSpec_doc[] = 
"Class: oaFloatAppDef_oaViaSpec\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaViaSpec)\n"
"    Calls: (const oaFloatAppDef_oaViaSpec&)\n"
"    Signature: oaFloatAppDef_oaViaSpec||cref-oaFloatAppDef_oaViaSpec,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaViaSpec_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaViaSpec",
    sizeof(PyoaFloatAppDef_oaViaSpecObject),
    0,
    (destructor)oaFloatAppDef_oaViaSpec_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaViaSpec_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaViaSpec_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaViaSpec_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaViaSpec_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaViaSpec_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaSpec_static_find_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaViaSpec* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaViaSpec* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::find(p1.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaViaSpec, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaViaSpec_static_get_doc[] = 
"Class: oaFloatAppDef_oaViaSpec, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaViaSpec* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaViaSpec|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaViaSpec_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViaSpecp result= (oaFloatAppDef_oaViaSpec::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaViaSpec_FromoaFloatAppDef_oaViaSpec(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaViaSpec, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaViaSpec_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaViaSpec_static_find,METH_VARARGS,oaFloatAppDef_oaViaSpec_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaViaSpec_static_get,METH_VARARGS,oaFloatAppDef_oaViaSpec_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaViaSpec_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaViaSpec_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaViaSpec\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaViaSpec",
           (PyObject*)(&PyoaFloatAppDef_oaViaSpec_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaViaSpec\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaViaSpec_Type.tp_dict;
    for(method=oaFloatAppDef_oaViaSpec_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatAppDef_oaView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaViewObject* self = (PyoaFloatAppDef_oaViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaView)
    {
        PyParamoaFloatAppDef_oaView p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaView_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaView, Choices are:\n"
        "    (oaFloatAppDef_oaView)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaView_tp_dealloc(PyoaFloatAppDef_oaViewObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaView_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaView value;
    int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaFloatAppDef_oaView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaView v1;
    PyParamoaFloatAppDef_oaView v2;
    int convert_status1=PyoaFloatAppDef_oaView_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaView_Convert(PyObject* ob,PyParamoaFloatAppDef_oaView* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaView_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaView**) ((PyoaFloatAppDef_oaViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(oaFloatAppDef_oaView** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaView* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaView_Type.tp_alloc(&PyoaFloatAppDef_oaView_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaViewObject* self = (PyoaFloatAppDef_oaViewObject*)bself;
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
PyObject* PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(oaFloatAppDef_oaView* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaView_Type.tp_alloc(&PyoaFloatAppDef_oaView_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaViewObject* self = (PyoaFloatAppDef_oaViewObject*)bself;
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
static char oaFloatAppDef_oaView_get_doc[] = 
"Class: oaFloatAppDef_oaView, Function: get\n"
"  Paramegers: (oaView)\n"
"    Calls: oaFloat get(const oaView* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaView,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaView_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaView data;
    int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViewObject* self=(PyoaFloatAppDef_oaViewObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaView p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaView_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaView_getDefault_doc[] = 
"Class: oaFloatAppDef_oaView, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaView_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaView data;
    int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViewObject* self=(PyoaFloatAppDef_oaViewObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaView_set_doc[] = 
"Class: oaFloatAppDef_oaView, Function: set\n"
"  Paramegers: (oaView,oaFloat)\n"
"    Calls: void set(oaView* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaView,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaView_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaView data;
    int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaViewObject* self=(PyoaFloatAppDef_oaViewObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaView p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaView_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaView_isNull_doc[] =
"Class: oaFloatAppDef_oaView, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaView_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaView data;
    int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaView_assign_doc[] = 
"Class: oaFloatAppDef_oaView, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaView_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaView data;
  int convert_status=PyoaFloatAppDef_oaView_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaView p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaView_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaView_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaView_get,METH_VARARGS,oaFloatAppDef_oaView_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaView_getDefault,METH_VARARGS,oaFloatAppDef_oaView_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaView_set,METH_VARARGS,oaFloatAppDef_oaView_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaView_tp_isNull,METH_VARARGS,oaFloatAppDef_oaView_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaView_tp_assign,METH_VARARGS,oaFloatAppDef_oaView_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaView_doc[] = 
"Class: oaFloatAppDef_oaView\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaView)\n"
"    Calls: (const oaFloatAppDef_oaView&)\n"
"    Signature: oaFloatAppDef_oaView||cref-oaFloatAppDef_oaView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaView",
    sizeof(PyoaFloatAppDef_oaViewObject),
    0,
    (destructor)oaFloatAppDef_oaView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaView_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaView_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaView_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaView_static_find_doc[] = 
"Class: oaFloatAppDef_oaView, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaView* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaView|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaView* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaView|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaView_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::find(p1.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaView, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaView_static_get_doc[] = 
"Class: oaFloatAppDef_oaView, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaView* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaView|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaView_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaViewp result= (oaFloatAppDef_oaView::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaView_FromoaFloatAppDef_oaView(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaView, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaView_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaView_static_find,METH_VARARGS,oaFloatAppDef_oaView_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaView_static_get,METH_VARARGS,oaFloatAppDef_oaView_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaView_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaView",
           (PyObject*)(&PyoaFloatAppDef_oaView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaView\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaView_Type.tp_dict;
    for(method=oaFloatAppDef_oaView_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatAppDef_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaWaferObject* self = (PyoaFloatAppDef_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaWafer)
    {
        PyParamoaFloatAppDef_oaWafer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaWafer_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaWafer, Choices are:\n"
        "    (oaFloatAppDef_oaWafer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaWafer_tp_dealloc(PyoaFloatAppDef_oaWaferObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaWafer value;
    int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaFloatAppDef_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaWafer v1;
    PyParamoaFloatAppDef_oaWafer v2;
    int convert_status1=PyoaFloatAppDef_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaWafer_Convert(PyObject* ob,PyParamoaFloatAppDef_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaWafer_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaWafer**) ((PyoaFloatAppDef_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(oaFloatAppDef_oaWafer** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaWafer* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaWafer_Type.tp_alloc(&PyoaFloatAppDef_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaWaferObject* self = (PyoaFloatAppDef_oaWaferObject*)bself;
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
PyObject* PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(oaFloatAppDef_oaWafer* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaWafer_Type.tp_alloc(&PyoaFloatAppDef_oaWafer_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaWaferObject* self = (PyoaFloatAppDef_oaWaferObject*)bself;
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
static char oaFloatAppDef_oaWafer_get_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: get\n"
"  Paramegers: (oaWafer)\n"
"    Calls: oaFloat get(const oaWafer* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaWafer,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWafer_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWafer data;
    int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferObject* self=(PyoaFloatAppDef_oaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWafer_getDefault_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWafer_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWafer data;
    int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferObject* self=(PyoaFloatAppDef_oaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWafer_set_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: set\n"
"  Paramegers: (oaWafer,oaFloat)\n"
"    Calls: void set(oaWafer* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaWafer,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaWafer_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWafer data;
    int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferObject* self=(PyoaFloatAppDef_oaWaferObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWafer p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaWafer_isNull_doc[] =
"Class: oaFloatAppDef_oaWafer, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaWafer_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaWafer data;
    int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaWafer_assign_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaWafer data;
  int convert_status=PyoaFloatAppDef_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaWafer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaWafer_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaWafer_get,METH_VARARGS,oaFloatAppDef_oaWafer_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaWafer_getDefault,METH_VARARGS,oaFloatAppDef_oaWafer_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaWafer_set,METH_VARARGS,oaFloatAppDef_oaWafer_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaWafer_tp_isNull,METH_VARARGS,oaFloatAppDef_oaWafer_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaWafer_tp_assign,METH_VARARGS,oaFloatAppDef_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWafer_doc[] = 
"Class: oaFloatAppDef_oaWafer\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaWafer)\n"
"    Calls: (const oaFloatAppDef_oaWafer&)\n"
"    Signature: oaFloatAppDef_oaWafer||cref-oaFloatAppDef_oaWafer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaWafer",
    sizeof(PyoaFloatAppDef_oaWaferObject),
    0,
    (destructor)oaFloatAppDef_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWafer_static_find_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWafer* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWafer|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWafer* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWafer|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaWafer_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::find(p1.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWafer, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWafer_static_get_doc[] = 
"Class: oaFloatAppDef_oaWafer, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWafer* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWafer|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaWafer_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferp result= (oaFloatAppDef_oaWafer::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaWafer_FromoaFloatAppDef_oaWafer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWafer, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaWafer_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaWafer_static_find,METH_VARARGS,oaFloatAppDef_oaWafer_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaWafer_static_get,METH_VARARGS,oaFloatAppDef_oaWafer_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaWafer",
           (PyObject*)(&PyoaFloatAppDef_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaWafer\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaWafer_Type.tp_dict;
    for(method=oaFloatAppDef_oaWafer_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatAppDef_oaWaferDesc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWaferDesc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaWaferDesc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaWaferDescObject* self = (PyoaFloatAppDef_oaWaferDescObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaWaferDesc)
    {
        PyParamoaFloatAppDef_oaWaferDesc p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaWaferDesc_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaWaferDesc, Choices are:\n"
        "    (oaFloatAppDef_oaWaferDesc)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaWaferDesc_tp_dealloc(PyoaFloatAppDef_oaWaferDescObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWaferDesc_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaWaferDesc value;
    int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaFloatAppDef_oaWaferDesc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaWaferDesc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaWaferDesc v1;
    PyParamoaFloatAppDef_oaWaferDesc v2;
    int convert_status1=PyoaFloatAppDef_oaWaferDesc_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaWaferDesc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaWaferDesc_Convert(PyObject* ob,PyParamoaFloatAppDef_oaWaferDesc* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaWaferDesc_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaWaferDesc**) ((PyoaFloatAppDef_oaWaferDescObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaWaferDesc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(oaFloatAppDef_oaWaferDesc** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaWaferDesc* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaWaferDesc_Type.tp_alloc(&PyoaFloatAppDef_oaWaferDesc_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaWaferDescObject* self = (PyoaFloatAppDef_oaWaferDescObject*)bself;
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
PyObject* PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(oaFloatAppDef_oaWaferDesc* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaWaferDesc_Type.tp_alloc(&PyoaFloatAppDef_oaWaferDesc_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaWaferDescObject* self = (PyoaFloatAppDef_oaWaferDescObject*)bself;
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
static char oaFloatAppDef_oaWaferDesc_get_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: get\n"
"  Paramegers: (oaWaferDesc)\n"
"    Calls: oaFloat get(const oaWaferDesc* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaWaferDesc,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferDesc data;
    int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferDescObject* self=(PyoaFloatAppDef_oaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferDesc p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWaferDesc_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferDesc_getDefault_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferDesc data;
    int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferDescObject* self=(PyoaFloatAppDef_oaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferDesc_set_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: set\n"
"  Paramegers: (oaWaferDesc,oaFloat)\n"
"    Calls: void set(oaWaferDesc* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaWaferDesc,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferDesc data;
    int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferDescObject* self=(PyoaFloatAppDef_oaWaferDescObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferDesc p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWaferDesc_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaWaferDesc_isNull_doc[] =
"Class: oaFloatAppDef_oaWaferDesc, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaWaferDesc data;
    int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaWaferDesc_assign_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaWaferDesc data;
  int convert_status=PyoaFloatAppDef_oaWaferDesc_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaWaferDesc p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaWaferDesc_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaWaferDesc_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaWaferDesc_get,METH_VARARGS,oaFloatAppDef_oaWaferDesc_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaWaferDesc_getDefault,METH_VARARGS,oaFloatAppDef_oaWaferDesc_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaWaferDesc_set,METH_VARARGS,oaFloatAppDef_oaWaferDesc_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaWaferDesc_tp_isNull,METH_VARARGS,oaFloatAppDef_oaWaferDesc_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaWaferDesc_tp_assign,METH_VARARGS,oaFloatAppDef_oaWaferDesc_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferDesc_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaWaferDesc)\n"
"    Calls: (const oaFloatAppDef_oaWaferDesc&)\n"
"    Signature: oaFloatAppDef_oaWaferDesc||cref-oaFloatAppDef_oaWaferDesc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaWaferDesc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaWaferDesc",
    sizeof(PyoaFloatAppDef_oaWaferDescObject),
    0,
    (destructor)oaFloatAppDef_oaWaferDesc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaWaferDesc_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaWaferDesc_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaWaferDesc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaWaferDesc_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaWaferDesc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferDesc_static_find_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::find(p1.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWaferDesc, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferDesc_static_get_doc[] = 
"Class: oaFloatAppDef_oaWaferDesc, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWaferDesc* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferDesc|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaWaferDesc_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferDescp result= (oaFloatAppDef_oaWaferDesc::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaWaferDesc_FromoaFloatAppDef_oaWaferDesc(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWaferDesc, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaWaferDesc_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaWaferDesc_static_find,METH_VARARGS,oaFloatAppDef_oaWaferDesc_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaWaferDesc_static_get,METH_VARARGS,oaFloatAppDef_oaWaferDesc_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaWaferDesc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaWaferDesc_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaWaferDesc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaWaferDesc",
           (PyObject*)(&PyoaFloatAppDef_oaWaferDesc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaWaferDesc\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaWaferDesc_Type.tp_dict;
    for(method=oaFloatAppDef_oaWaferDesc_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatAppDef_oaWaferFeature
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWaferFeature_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatAppDef_oaWaferFeature_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatAppDef_oaWaferFeatureObject* self = (PyoaFloatAppDef_oaWaferFeatureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatAppDef_oaWaferFeature)
    {
        PyParamoaFloatAppDef_oaWaferFeature p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatAppDef_oaWaferFeature_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatAppDef_oaWaferFeature, Choices are:\n"
        "    (oaFloatAppDef_oaWaferFeature)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatAppDef_oaWaferFeature_tp_dealloc(PyoaFloatAppDef_oaWaferFeatureObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatAppDef_oaWaferFeature_tp_repr(PyObject *ob)
{
    PyParamoaFloatAppDef_oaWaferFeature value;
    int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaFloatAppDef_oaWaferFeature::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFloatAppDef_oaWaferFeature_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatAppDef_oaWaferFeature v1;
    PyParamoaFloatAppDef_oaWaferFeature v2;
    int convert_status1=PyoaFloatAppDef_oaWaferFeature_Convert(ob1,&v1);
    int convert_status2=PyoaFloatAppDef_oaWaferFeature_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatAppDef_oaWaferFeature_Convert(PyObject* ob,PyParamoaFloatAppDef_oaWaferFeature* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatAppDef_oaWaferFeature_Check(ob)) {
        result->SetData( (oaFloatAppDef_oaWaferFeature**) ((PyoaFloatAppDef_oaWaferFeatureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatAppDef_oaWaferFeature Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(oaFloatAppDef_oaWaferFeature** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatAppDef_oaWaferFeature* data=*value;
        PyObject* bself = PyoaFloatAppDef_oaWaferFeature_Type.tp_alloc(&PyoaFloatAppDef_oaWaferFeature_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatAppDef_oaWaferFeatureObject* self = (PyoaFloatAppDef_oaWaferFeatureObject*)bself;
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
PyObject* PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(oaFloatAppDef_oaWaferFeature* data)
{
    if (data) {
       PyObject* bself = PyoaFloatAppDef_oaWaferFeature_Type.tp_alloc(&PyoaFloatAppDef_oaWaferFeature_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatAppDef_oaWaferFeatureObject* self = (PyoaFloatAppDef_oaWaferFeatureObject*)bself;
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
static char oaFloatAppDef_oaWaferFeature_get_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: get\n"
"  Paramegers: (oaWaferFeature)\n"
"    Calls: oaFloat get(const oaWaferFeature* object)\n"
"    Signature: get|simple-oaFloat|cptr-oaWaferFeature,\n"
"    This function returns the value of this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferFeature data;
    int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferFeatureObject* self=(PyoaFloatAppDef_oaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferFeature p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWaferFeature_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->get(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferFeature_getDefault_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: getDefault\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDefault() const\n"
"    Signature: getDefault|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the default value for this float extension.\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_getDefault(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferFeature data;
    int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferFeatureObject* self=(PyoaFloatAppDef_oaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDefault());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferFeature_set_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: set\n"
"  Paramegers: (oaWaferFeature,oaFloat)\n"
"    Calls: void set(oaWaferFeature* object,oaFloat value)\n"
"    Signature: set|void-void|ptr-oaWaferFeature,simple-oaFloat,\n"
"    This function sets the value of this string extension.\n"
"    oacInvalidDesignObjectForAppDef\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatAppDef_oaWaferFeature data;
    int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatAppDef_oaWaferFeatureObject* self=(PyoaFloatAppDef_oaWaferFeatureObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaWaferFeature p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWaferFeature_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->set(p1.Data(),p2.Data());
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
static char oaFloatAppDef_oaWaferFeature_isNull_doc[] =
"Class: oaFloatAppDef_oaWaferFeature, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatAppDef_oaWaferFeature data;
    int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatAppDef_oaWaferFeature_assign_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatAppDef_oaWaferFeature data;
  int convert_status=PyoaFloatAppDef_oaWaferFeature_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatAppDef_oaWaferFeature p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatAppDef_oaWaferFeature_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatAppDef_oaWaferFeature_methodlist[] = {
    {"get",(PyCFunction)oaFloatAppDef_oaWaferFeature_get,METH_VARARGS,oaFloatAppDef_oaWaferFeature_get_doc},
    {"getDefault",(PyCFunction)oaFloatAppDef_oaWaferFeature_getDefault,METH_VARARGS,oaFloatAppDef_oaWaferFeature_getDefault_doc},
    {"set",(PyCFunction)oaFloatAppDef_oaWaferFeature_set,METH_VARARGS,oaFloatAppDef_oaWaferFeature_set_doc},
    {"isNull",(PyCFunction)oaFloatAppDef_oaWaferFeature_tp_isNull,METH_VARARGS,oaFloatAppDef_oaWaferFeature_isNull_doc},
    {"assign",(PyCFunction)oaFloatAppDef_oaWaferFeature_tp_assign,METH_VARARGS,oaFloatAppDef_oaWaferFeature_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferFeature_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature\n"
"  The oaFloatAppDef class implements an application-specific extension to a particular type of data in a database.\n"
"  Once created, a float field is added to each object of the specified dataType. The default value for this extension is FLT_MAX. Applications can use the new field for whatever purpose is necessary.\n"
"  For additional information on defining and using AppDefs, see oaAppDef and Extending the Database in the Programmer's Guide.\n"
"Constructors:\n"
"  Paramegers: (oaFloatAppDef_oaWaferFeature)\n"
"    Calls: (const oaFloatAppDef_oaWaferFeature&)\n"
"    Signature: oaFloatAppDef_oaWaferFeature||cref-oaFloatAppDef_oaWaferFeature,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatAppDef_oaWaferFeature_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatAppDef_oaWaferFeature",
    sizeof(PyoaFloatAppDef_oaWaferFeatureObject),
    0,
    (destructor)oaFloatAppDef_oaWaferFeature_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatAppDef_oaWaferFeature_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatAppDef_oaWaferFeature_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatAppDef_oaWaferFeature_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatAppDef_oaWaferFeature_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatAppDef_oaWaferFeature_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferFeature_static_find_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* find(const oaString& name)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' if it exists.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* find(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: find|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,cptr-oaAppObjectDef,\n"
"    This function returns an oaFloatAppDef object with this dataType and the specified 'name' that is associated with the specified object extension 'objDef'.\n"
"    name\n"
"    The name of the oaAppDef object to look for\n"
"    objDef\n"
"    A constant pointer to the object extension\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::find(p1.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::find(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWaferFeature, function: find, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaAppObjectDef)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatAppDef_oaWaferFeature_static_get_doc[] = 
"Class: oaFloatAppDef_oaWaferFeature, Function: get\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name . You can create a float extension on any object except another extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name,const oaAppObjectDef* objDef)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
"  Paramegers: (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
"    Calls: oaFloatAppDef_oaWaferFeature* get(const oaString& name,const oaAppObjectDef* objDef,oaFloat defValue,oaBoolean persist)\n"
"    Signature: get|ptr-oaFloatAppDef_oaWaferFeature|cref-oaString,cptr-oaAppObjectDef,simple-oaFloat,simple-oaBoolean,\n"
"    This function constructs an oaFloatAppDef object, creating a float extension with the specified name for an object extension.\n"
"    name\n"
"    The name given to the oaFloatAppDef object\n"
"    objDef\n"
"    The object extension with which to associate the extension\n"
"    defValue\n"
"    An optional default value\n"
"    persist\n"
"    Saves the oaFloatAppDef data in the database\n"
"    oacAppDefExists\n"
;

static PyObject*
oaFloatAppDef_oaWaferFeature_static_get(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2)) {
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaFloat p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaFloat_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data(),p2.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data(),p2.Data(),p3.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaAppObjectDef,oaFloat,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaAppObjectDef p2;
        PyParamoaFloat p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaAppObjectDef_Convert,&p2,
              &PyoaFloat_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFloatAppDef_oaWaferFeaturep result= (oaFloatAppDef_oaWaferFeature::get(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaFloatAppDef_oaWaferFeature_FromoaFloatAppDef_oaWaferFeature(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFloatAppDef_oaWaferFeature, function: get, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaFloat)\n"
        "    (oaString,oaFloat,oaBoolean)\n"
        "    (oaString,oaAppObjectDef)\n"
        "    (oaString,oaAppObjectDef,oaFloat)\n"
        "    (oaString,oaAppObjectDef,oaFloat,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatAppDef_oaWaferFeature_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaFloatAppDef_oaWaferFeature_static_find,METH_VARARGS,oaFloatAppDef_oaWaferFeature_static_find_doc},
    {"static_get",(PyCFunction)oaFloatAppDef_oaWaferFeature_static_get,METH_VARARGS,oaFloatAppDef_oaWaferFeature_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatAppDef_oaWaferFeature_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatAppDef_oaWaferFeature_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatAppDef_oaWaferFeature\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatAppDef_oaWaferFeature",
           (PyObject*)(&PyoaFloatAppDef_oaWaferFeature_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatAppDef_oaWaferFeature\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatAppDef_oaWaferFeature_Type.tp_dict;
    for(method=oaFloatAppDef_oaWaferFeature_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatPropObject* self = (PyoaFloatPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatProp)
    {
        PyParamoaFloatProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatProp_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatProp, Choices are:\n"
        "    (oaFloatProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatProp_tp_dealloc(PyoaFloatPropObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatProp_tp_repr(PyObject *ob)
{
    PyParamoaFloatProp value;
    int convert_status=PyoaFloatProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaFloatProp::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[33];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaFloatProp::");
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
oaFloatProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatProp v1;
    PyParamoaFloatProp v2;
    int convert_status1=PyoaFloatProp_Convert(ob1,&v1);
    int convert_status2=PyoaFloatProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatProp_Convert(PyObject* ob,PyParamoaFloatProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatProp_Check(ob)) {
        result->SetData( (oaFloatProp**) ((PyoaFloatPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatProp_FromoaFloatProp(oaFloatProp** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatProp* data=*value;
        PyObject* bself = PyoaFloatProp_Type.tp_alloc(&PyoaFloatProp_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatPropObject* self = (PyoaFloatPropObject*)bself;
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
PyObject* PyoaFloatProp_FromoaFloatProp(oaFloatProp* data)
{
    if (data) {
       PyObject* bself = PyoaFloatProp_Type.tp_alloc(&PyoaFloatProp_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatPropObject* self = (PyoaFloatPropObject*)bself;
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
static char oaFloatProp_getValue_doc[] = 
"Class: oaFloatProp, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getValue() const\n"
"    Signature: getValue|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of this property.\n"
;

static PyObject*
oaFloatProp_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatProp data;
    int convert_status=PyoaFloatProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatPropObject* self=(PyoaFloatPropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getValue());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatProp_setValue_doc[] = 
"Class: oaFloatProp, Function: setValue\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setValue(oaFloat value)\n"
"    Signature: setValue|void-void|simple-oaFloat,\n"
"    This function sets this property to the specified value.\n"
"    value\n"
"    The property value to set\n"
;

static PyObject*
oaFloatProp_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatProp data;
    int convert_status=PyoaFloatProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatPropObject* self=(PyoaFloatPropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
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
static char oaFloatProp_isNull_doc[] =
"Class: oaFloatProp, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatProp_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatProp data;
    int convert_status=PyoaFloatProp_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatProp_assign_doc[] = 
"Class: oaFloatProp, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatProp_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatProp data;
  int convert_status=PyoaFloatProp_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatProp p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatProp_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatProp_methodlist[] = {
    {"getValue",(PyCFunction)oaFloatProp_getValue,METH_VARARGS,oaFloatProp_getValue_doc},
    {"setValue",(PyCFunction)oaFloatProp_setValue,METH_VARARGS,oaFloatProp_setValue_doc},
    {"isNull",(PyCFunction)oaFloatProp_tp_isNull,METH_VARARGS,oaFloatProp_isNull_doc},
    {"assign",(PyCFunction)oaFloatProp_tp_assign,METH_VARARGS,oaFloatProp_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatProp_doc[] = 
"Class: oaFloatProp\n"
"  The oaFloatProp is a property that has a 32-bit floating point value.\n"
"  Properties are application-defined values that can be added to any managed object in oaDesign , oaTech , and oaWafer databases except for the following paged objects: oaDevice , oaNode , oaParasiticNetwork , and oaSubNetwork .\n"
"  To create properties on DM Objects, create the corresponding oaDMData object (using oaLibDMData::open , oaCellDMData::open , oaViewDMData::open , or oaCellViewDMData::open ), then create properties on that oaDMData object.\n"
"  See oaProp for a general discussion of properties.\n"
"Constructors:\n"
"  Paramegers: (oaFloatProp)\n"
"    Calls: (const oaFloatProp&)\n"
"    Signature: oaFloatProp||cref-oaFloatProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatProp",
    sizeof(PyoaFloatPropObject),
    0,
    (destructor)oaFloatProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatProp_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatProp_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaProp_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatProp_static_create_doc[] = 
"Class: oaFloatProp, Function: create\n"
"  Paramegers: (oaObject,oaString,oaFloat)\n"
"    Calls: oaFloatProp* create(oaObject* object,const oaString& name,oaFloat value)\n"
"    Signature: create|ptr-oaFloatProp|ptr-oaObject,cref-oaString,simple-oaFloat,\n"
"    This function creates a float property with the specified attributes. The specified name is checked to verify it is unique for properties on the specified object.\n"
"    object\n"
"    The object to which to attach the property\n"
"    name\n"
"    The property name\n"
"    value\n"
"    The property value\n"
"    A pointer to the oaFloatProp\n"
"    oacInvalidObjForProp\n"
"    oacPropNameUsed\n"
;

static PyObject*
oaFloatProp_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaString p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloatPropp result= (oaFloatProp::create(p1.Data(),p2.Data(),p3.Data()));
        return PyoaFloatProp_FromoaFloatProp(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatProp_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFloatProp_static_create,METH_VARARGS,oaFloatProp_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatProp_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatProp",
           (PyObject*)(&PyoaFloatProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatProp\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatProp_Type.tp_dict;
    for(method=oaFloatProp_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFloatRangeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFloatRangeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFloatRangeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFloatRangePropObject* self = (PyoaFloatRangePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFloatRangeProp)
    {
        PyParamoaFloatRangeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFloatRangeProp_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFloatRangeProp, Choices are:\n"
        "    (oaFloatRangeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFloatRangeProp_tp_dealloc(PyoaFloatRangePropObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFloatRangeProp_tp_repr(PyObject *ob)
{
    PyParamoaFloatRangeProp value;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaFloatRangeProp::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[38];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaFloatRangeProp::");
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
oaFloatRangeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFloatRangeProp v1;
    PyParamoaFloatRangeProp v2;
    int convert_status1=PyoaFloatRangeProp_Convert(ob1,&v1);
    int convert_status2=PyoaFloatRangeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFloatRangeProp_Convert(PyObject* ob,PyParamoaFloatRangeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaFloatRangeProp_Check(ob)) {
        result->SetData( (oaFloatRangeProp**) ((PyoaFloatRangePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFloatRangeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFloatRangeProp_FromoaFloatRangeProp(oaFloatRangeProp** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFloatRangeProp* data=*value;
        PyObject* bself = PyoaFloatRangeProp_Type.tp_alloc(&PyoaFloatRangeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaFloatRangePropObject* self = (PyoaFloatRangePropObject*)bself;
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
PyObject* PyoaFloatRangeProp_FromoaFloatRangeProp(oaFloatRangeProp* data)
{
    if (data) {
       PyObject* bself = PyoaFloatRangeProp_Type.tp_alloc(&PyoaFloatRangeProp_Type,0);
       if (bself == NULL) return bself;
       PyoaFloatRangePropObject* self = (PyoaFloatRangePropObject*)bself;
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
static char oaFloatRangeProp_getLowerBound_doc[] = 
"Class: oaFloatRangeProp, Function: getLowerBound\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getLowerBound() const\n"
"    Signature: getLowerBound|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the lower bound of the float range.\n"
;

static PyObject*
oaFloatRangeProp_getLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatRangePropObject* self=(PyoaFloatRangePropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getLowerBound());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatRangeProp_getUpperBound_doc[] = 
"Class: oaFloatRangeProp, Function: getUpperBound\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getUpperBound() const\n"
"    Signature: getUpperBound|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the upper bound of the float range.\n"
;

static PyObject*
oaFloatRangeProp_getUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatRangePropObject* self=(PyoaFloatRangePropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getUpperBound());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatRangeProp_getValue_doc[] = 
"Class: oaFloatRangeProp, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getValue() const\n"
"    Signature: getValue|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of this property.\n"
;

static PyObject*
oaFloatRangeProp_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatRangePropObject* self=(PyoaFloatRangePropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getValue());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFloatRangeProp_set_doc[] = 
"Class: oaFloatRangeProp, Function: set\n"
"  Paramegers: (oaFloat,oaFloat,oaFloat)\n"
"    Calls: void set(oaFloat lowerBound,oaFloat value,oaFloat upperBound)\n"
"    Signature: set|void-void|simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function sets this property attributes.\n"
"    lowerBound\n"
"    The lower bound for the range\n"
"    value\n"
"    The property value\n"
"    upperBound\n"
"    The upper bound for the range\n"
"    oacInvalidValueForFloatRange\n"
;

static PyObject*
oaFloatRangeProp_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatRangePropObject* self=(PyoaFloatRangePropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaFloat_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        data.DataCall()->set(p1.Data(),p2.Data(),p3.Data());
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
static char oaFloatRangeProp_setValue_doc[] = 
"Class: oaFloatRangeProp, Function: setValue\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setValue(oaFloat value)\n"
"    Signature: setValue|void-void|simple-oaFloat,\n"
"    This function sets this property to the specified value.\n"
"    value\n"
"    The property value\n"
"    oacInvalidValueForFloatRange\n"
;

static PyObject*
oaFloatRangeProp_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFloatRangePropObject* self=(PyoaFloatRangePropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
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
static char oaFloatRangeProp_isNull_doc[] =
"Class: oaFloatRangeProp, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFloatRangeProp_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFloatRangeProp data;
    int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFloatRangeProp_assign_doc[] = 
"Class: oaFloatRangeProp, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFloatRangeProp_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFloatRangeProp data;
  int convert_status=PyoaFloatRangeProp_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFloatRangeProp p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFloatRangeProp_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFloatRangeProp_methodlist[] = {
    {"getLowerBound",(PyCFunction)oaFloatRangeProp_getLowerBound,METH_VARARGS,oaFloatRangeProp_getLowerBound_doc},
    {"getUpperBound",(PyCFunction)oaFloatRangeProp_getUpperBound,METH_VARARGS,oaFloatRangeProp_getUpperBound_doc},
    {"getValue",(PyCFunction)oaFloatRangeProp_getValue,METH_VARARGS,oaFloatRangeProp_getValue_doc},
    {"set",(PyCFunction)oaFloatRangeProp_set,METH_VARARGS,oaFloatRangeProp_set_doc},
    {"setValue",(PyCFunction)oaFloatRangeProp_setValue,METH_VARARGS,oaFloatRangeProp_setValue_doc},
    {"isNull",(PyCFunction)oaFloatRangeProp_tp_isNull,METH_VARARGS,oaFloatRangeProp_isNull_doc},
    {"assign",(PyCFunction)oaFloatRangeProp_tp_assign,METH_VARARGS,oaFloatRangeProp_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatRangeProp_doc[] = 
"Class: oaFloatRangeProp\n"
"  The oaFloatRangeProp is a property that has a float-type value as well as a range of valid values that the float is allowed to take on. The range can be used by a generic property editor to assist a user to enter a proper value.\n"
"  Properties are application-defined values that can be added to any managed object in oaDesign , oaTech , and oaWafer databases except for the following paged objects: oaDevice , oaNode , oaParasiticNetwork , and oaSubNetwork .\n"
"  To create properties on DM Objects, create the corresponding oaDMData object (using oaLibDMData::open , oaCellDMData::open , oaViewDMData::open , or oaCellViewDMData::open ), then create properties on that oaDMData object.\n"
"  See oaProp for a general discussion of properties.\n"
"Constructors:\n"
"  Paramegers: (oaFloatRangeProp)\n"
"    Calls: (const oaFloatRangeProp&)\n"
"    Signature: oaFloatRangeProp||cref-oaFloatRangeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFloatRangeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFloatRangeProp",
    sizeof(PyoaFloatRangePropObject),
    0,
    (destructor)oaFloatRangeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFloatRangeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaFloatRangeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFloatRangeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFloatRangeProp_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaProp_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFloatRangeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFloatRangeProp_static_create_doc[] = 
"Class: oaFloatRangeProp, Function: create\n"
"  Paramegers: (oaObject,oaString,oaFloat,oaFloat,oaFloat)\n"
"    Calls: oaFloatRangeProp* create(oaObject* object,const oaString& name,oaFloat lowerBound,oaFloat value,oaFloat upperBound)\n"
"    Signature: create|ptr-oaFloatRangeProp|ptr-oaObject,cref-oaString,simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function creates a float range property with the specified attributes. The specified name is checked to verify the name is unique for properties on the specified object.\n"
"    object\n"
"    The object to which to attach the property\n"
"    name\n"
"    The property name\n"
"    lowerBound\n"
"    The lower bound for the range\n"
"    value\n"
"    The property value\n"
"    upperBound\n"
"    The upper bound for the range\n"
"    A pointer to the oaFloatRangeProp\n"
"    oacPropNameUsed\n"
"    oacInvalidValueForFloatRange\n"
"    oacInvalidObjForProp\n"
;

static PyObject*
oaFloatRangeProp_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaString p2;
    PyParamoaFloat p3;
    PyParamoaFloat p4;
    PyParamoaFloat p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaFloat_Convert,&p3,
          &PyoaFloat_Convert,&p4,
          &PyoaFloat_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloatRangePropp result= (oaFloatRangeProp::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaFloatRangeProp_FromoaFloatRangeProp(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFloatRangeProp_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFloatRangeProp_static_create,METH_VARARGS,oaFloatRangeProp_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFloatRangeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFloatRangeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaFloatRangeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFloatRangeProp",
           (PyObject*)(&PyoaFloatRangeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFloatRangeProp\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFloatRangeProp_Type.tp_dict;
    for(method=oaFloatRangeProp_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFlt1DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFlt1DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFlt1DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFlt1DTblValueObject* self = (PyoaFlt1DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFlt1DTblValue)
    {
        PyParamoaFlt1DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFlt1DTblValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFlt1DTblValue, Choices are:\n"
        "    (oaFlt1DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFlt1DTblValue_tp_dealloc(PyoaFlt1DTblValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFlt1DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaFlt1DTblValue value;
    int convert_status=PyoaFlt1DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaFlt1DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFlt1DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFlt1DTblValue v1;
    PyParamoaFlt1DTblValue v2;
    int convert_status1=PyoaFlt1DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaFlt1DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFlt1DTblValue_Convert(PyObject* ob,PyParamoaFlt1DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaFlt1DTblValue_Check(ob)) {
        result->SetData( (oaFlt1DTblValue**) ((PyoaFlt1DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFlt1DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFlt1DTblValue_FromoaFlt1DTblValue(oaFlt1DTblValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFlt1DTblValue* data=*value;
        PyObject* bself = PyoaFlt1DTblValue_Type.tp_alloc(&PyoaFlt1DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaFlt1DTblValueObject* self = (PyoaFlt1DTblValueObject*)bself;
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
PyObject* PyoaFlt1DTblValue_FromoaFlt1DTblValue(oaFlt1DTblValue* data)
{
    if (data) {
       PyObject* bself = PyoaFlt1DTblValue_Type.tp_alloc(&PyoaFlt1DTblValue_Type,0);
       if (bself == NULL) return bself;
       PyoaFlt1DTblValueObject* self = (PyoaFlt1DTblValueObject*)bself;
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
static char oaFlt1DTblValue_get_doc[] = 
"Class: oaFlt1DTblValue, Function: get\n"
"  Paramegers: (oa1DLookupTbl_oaFloat_oaFloat)\n"
"    Calls: void get(oa1DLookupTbl_oaFloat_oaFloat& tbl) const\n"
"    Signature: get|void-void|ref-oa1DLookupTbl_oaFloat_oaFloat,\n"
"    BrowseData: 0,oa1DLookupTbl_oaFloat_oaFloat\n"
"    This function returns the flt1DTbl for this value.\n"
"    tbl\n"
"    The returned value.\n"
;

static PyObject*
oaFlt1DTblValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFlt1DTblValue data;
    int convert_status=PyoaFlt1DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFlt1DTblValueObject* self=(PyoaFlt1DTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa1DLookupTbl_oaFloat_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa1DLookupTbl_oaFloat_oaFloat_Convert,&p1)) {
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
static char oaFlt1DTblValue_set_doc[] = 
"Class: oaFlt1DTblValue, Function: set\n"
"  Paramegers: (oa1DLookupTbl_oaFloat_oaFloat)\n"
"    Calls: void set(const oa1DLookupTbl_oaFloat_oaFloat& tbl)\n"
"    Signature: set|void-void|cref-oa1DLookupTbl_oaFloat_oaFloat,\n"
"    This function sets this value to the specified flt1DTbl value.\n"
"    tbl\n"
"    The flt1DTbl value to set\n"
;

static PyObject*
oaFlt1DTblValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFlt1DTblValue data;
    int convert_status=PyoaFlt1DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFlt1DTblValueObject* self=(PyoaFlt1DTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa1DLookupTbl_oaFloat_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa1DLookupTbl_oaFloat_oaFloat_Convert,&p1)) {
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
static char oaFlt1DTblValue_isNull_doc[] =
"Class: oaFlt1DTblValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFlt1DTblValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFlt1DTblValue data;
    int convert_status=PyoaFlt1DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFlt1DTblValue_assign_doc[] = 
"Class: oaFlt1DTblValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFlt1DTblValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFlt1DTblValue data;
  int convert_status=PyoaFlt1DTblValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFlt1DTblValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFlt1DTblValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFlt1DTblValue_methodlist[] = {
    {"get",(PyCFunction)oaFlt1DTblValue_get,METH_VARARGS,oaFlt1DTblValue_get_doc},
    {"set",(PyCFunction)oaFlt1DTblValue_set,METH_VARARGS,oaFlt1DTblValue_set_doc},
    {"isNull",(PyCFunction)oaFlt1DTblValue_tp_isNull,METH_VARARGS,oaFlt1DTblValue_isNull_doc},
    {"assign",(PyCFunction)oaFlt1DTblValue_tp_assign,METH_VARARGS,oaFlt1DTblValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFlt1DTblValue_doc[] = 
"Class: oaFlt1DTblValue\n"
"  The oaFlt1DTblValue class represents a 1D float lookup table value.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaFlt1DTblValue)\n"
"    Calls: (const oaFlt1DTblValue&)\n"
"    Signature: oaFlt1DTblValue||cref-oaFlt1DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFlt1DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFlt1DTblValue",
    sizeof(PyoaFlt1DTblValueObject),
    0,
    (destructor)oaFlt1DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFlt1DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaFlt1DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFlt1DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFlt1DTblValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFlt1DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFlt1DTblValue_static_create_doc[] = 
"Class: oaFlt1DTblValue, Function: create\n"
"  Paramegers: (oaObject,oa1DLookupTbl_oaFloat_oaFloat)\n"
"    Calls: oaFlt1DTblValue* create(oaObject* database,const oa1DLookupTbl_oaFloat_oaFloat& value)\n"
"    Signature: create|ptr-oaFlt1DTblValue|ptr-oaObject,cref-oa1DLookupTbl_oaFloat_oaFloat,\n"
"    This function creates a flt1DTbl value in the database specified.\n"
"    database\n"
"    The database in which to create the value.\n"
"    value\n"
"    The flt1DTbl value\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaFlt1DTblValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoa1DLookupTbl_oaFloat_oaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &Pyoa1DLookupTbl_oaFloat_oaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFlt1DTblValuep result= (oaFlt1DTblValue::create(p1.Data(),p2.Data()));
        return PyoaFlt1DTblValue_FromoaFlt1DTblValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFlt1DTblValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFlt1DTblValue_static_create,METH_VARARGS,oaFlt1DTblValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFlt1DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFlt1DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaFlt1DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFlt1DTblValue",
           (PyObject*)(&PyoaFlt1DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFlt1DTblValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFlt1DTblValue_Type.tp_dict;
    for(method=oaFlt1DTblValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFlt2DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFlt2DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFlt2DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFlt2DTblValueObject* self = (PyoaFlt2DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFlt2DTblValue)
    {
        PyParamoaFlt2DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFlt2DTblValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFlt2DTblValue, Choices are:\n"
        "    (oaFlt2DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFlt2DTblValue_tp_dealloc(PyoaFlt2DTblValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFlt2DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaFlt2DTblValue value;
    int convert_status=PyoaFlt2DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaFlt2DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFlt2DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFlt2DTblValue v1;
    PyParamoaFlt2DTblValue v2;
    int convert_status1=PyoaFlt2DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaFlt2DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFlt2DTblValue_Convert(PyObject* ob,PyParamoaFlt2DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaFlt2DTblValue_Check(ob)) {
        result->SetData( (oaFlt2DTblValue**) ((PyoaFlt2DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFlt2DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFlt2DTblValue_FromoaFlt2DTblValue(oaFlt2DTblValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFlt2DTblValue* data=*value;
        PyObject* bself = PyoaFlt2DTblValue_Type.tp_alloc(&PyoaFlt2DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaFlt2DTblValueObject* self = (PyoaFlt2DTblValueObject*)bself;
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
PyObject* PyoaFlt2DTblValue_FromoaFlt2DTblValue(oaFlt2DTblValue* data)
{
    if (data) {
       PyObject* bself = PyoaFlt2DTblValue_Type.tp_alloc(&PyoaFlt2DTblValue_Type,0);
       if (bself == NULL) return bself;
       PyoaFlt2DTblValueObject* self = (PyoaFlt2DTblValueObject*)bself;
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
static char oaFlt2DTblValue_get_doc[] = 
"Class: oaFlt2DTblValue, Function: get\n"
"  Paramegers: (oa2DLookupTbl_oaFloat_oaFloat_oaFloat)\n"
"    Calls: void get(oa2DLookupTbl_oaFloat_oaFloat_oaFloat& tbl) const\n"
"    Signature: get|void-void|ref-oa2DLookupTbl_oaFloat_oaFloat_oaFloat,\n"
"    BrowseData: 0,oa2DLookupTbl_oaFloat_oaFloat_oaFloat\n"
"    This function returns the flt2DTbl for this value.\n"
"    tbl\n"
"    The returned value.\n"
;

static PyObject*
oaFlt2DTblValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFlt2DTblValue data;
    int convert_status=PyoaFlt2DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFlt2DTblValueObject* self=(PyoaFlt2DTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa2DLookupTbl_oaFloat_oaFloat_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa2DLookupTbl_oaFloat_oaFloat_oaFloat_Convert,&p1)) {
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
static char oaFlt2DTblValue_set_doc[] = 
"Class: oaFlt2DTblValue, Function: set\n"
"  Paramegers: (oa2DLookupTbl_oaFloat_oaFloat_oaFloat)\n"
"    Calls: void set(const oa2DLookupTbl_oaFloat_oaFloat_oaFloat& tbl)\n"
"    Signature: set|void-void|cref-oa2DLookupTbl_oaFloat_oaFloat_oaFloat,\n"
"    This function sets this value to the specified flt2DTbl value.\n"
"    tbl\n"
"    The flt2DTbl value to set\n"
;

static PyObject*
oaFlt2DTblValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFlt2DTblValue data;
    int convert_status=PyoaFlt2DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFlt2DTblValueObject* self=(PyoaFlt2DTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa2DLookupTbl_oaFloat_oaFloat_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa2DLookupTbl_oaFloat_oaFloat_oaFloat_Convert,&p1)) {
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
static char oaFlt2DTblValue_isNull_doc[] =
"Class: oaFlt2DTblValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFlt2DTblValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFlt2DTblValue data;
    int convert_status=PyoaFlt2DTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFlt2DTblValue_assign_doc[] = 
"Class: oaFlt2DTblValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFlt2DTblValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFlt2DTblValue data;
  int convert_status=PyoaFlt2DTblValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFlt2DTblValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFlt2DTblValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFlt2DTblValue_methodlist[] = {
    {"get",(PyCFunction)oaFlt2DTblValue_get,METH_VARARGS,oaFlt2DTblValue_get_doc},
    {"set",(PyCFunction)oaFlt2DTblValue_set,METH_VARARGS,oaFlt2DTblValue_set_doc},
    {"isNull",(PyCFunction)oaFlt2DTblValue_tp_isNull,METH_VARARGS,oaFlt2DTblValue_isNull_doc},
    {"assign",(PyCFunction)oaFlt2DTblValue_tp_assign,METH_VARARGS,oaFlt2DTblValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFlt2DTblValue_doc[] = 
"Class: oaFlt2DTblValue\n"
"  The oaFlt2DTblValue class represents a 2D float lookup table value.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaFlt2DTblValue)\n"
"    Calls: (const oaFlt2DTblValue&)\n"
"    Signature: oaFlt2DTblValue||cref-oaFlt2DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFlt2DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFlt2DTblValue",
    sizeof(PyoaFlt2DTblValueObject),
    0,
    (destructor)oaFlt2DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFlt2DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaFlt2DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFlt2DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFlt2DTblValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFlt2DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFlt2DTblValue_static_create_doc[] = 
"Class: oaFlt2DTblValue, Function: create\n"
"  Paramegers: (oaObject,oa2DLookupTbl_oaFloat_oaFloat_oaFloat)\n"
"    Calls: oaFlt2DTblValue* create(oaObject* database,const oa2DLookupTbl_oaFloat_oaFloat_oaFloat& value)\n"
"    Signature: create|ptr-oaFlt2DTblValue|ptr-oaObject,cref-oa2DLookupTbl_oaFloat_oaFloat_oaFloat,\n"
"    This function creates a flt2DTbl value in the database specified.\n"
"    database\n"
"    The database in which to create the value.\n"
"    value\n"
"    The flt2DTbl value\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaFlt2DTblValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoa2DLookupTbl_oaFloat_oaFloat_oaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &Pyoa2DLookupTbl_oaFloat_oaFloat_oaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFlt2DTblValuep result= (oaFlt2DTblValue::create(p1.Data(),p2.Data()));
        return PyoaFlt2DTblValue_FromoaFlt2DTblValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFlt2DTblValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFlt2DTblValue_static_create,METH_VARARGS,oaFlt2DTblValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFlt2DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFlt2DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaFlt2DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFlt2DTblValue",
           (PyObject*)(&PyoaFlt2DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFlt2DTblValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFlt2DTblValue_Type.tp_dict;
    for(method=oaFlt2DTblValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFltIntFltTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFltIntFltTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFltIntFltTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFltIntFltTblValueObject* self = (PyoaFltIntFltTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFltIntFltTblValue)
    {
        PyParamoaFltIntFltTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFltIntFltTblValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFltIntFltTblValue, Choices are:\n"
        "    (oaFltIntFltTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFltIntFltTblValue_tp_dealloc(PyoaFltIntFltTblValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFltIntFltTblValue_tp_repr(PyObject *ob)
{
    PyParamoaFltIntFltTblValue value;
    int convert_status=PyoaFltIntFltTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaFltIntFltTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFltIntFltTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFltIntFltTblValue v1;
    PyParamoaFltIntFltTblValue v2;
    int convert_status1=PyoaFltIntFltTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaFltIntFltTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFltIntFltTblValue_Convert(PyObject* ob,PyParamoaFltIntFltTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaFltIntFltTblValue_Check(ob)) {
        result->SetData( (oaFltIntFltTblValue**) ((PyoaFltIntFltTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFltIntFltTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(oaFltIntFltTblValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFltIntFltTblValue* data=*value;
        PyObject* bself = PyoaFltIntFltTblValue_Type.tp_alloc(&PyoaFltIntFltTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaFltIntFltTblValueObject* self = (PyoaFltIntFltTblValueObject*)bself;
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
PyObject* PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(oaFltIntFltTblValue* data)
{
    if (data) {
       PyObject* bself = PyoaFltIntFltTblValue_Type.tp_alloc(&PyoaFltIntFltTblValue_Type,0);
       if (bself == NULL) return bself;
       PyoaFltIntFltTblValueObject* self = (PyoaFltIntFltTblValueObject*)bself;
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
static char oaFltIntFltTblValue_get_doc[] = 
"Class: oaFltIntFltTblValue, Function: get\n"
"  Paramegers: (oa2DLookupTbl_oaFloat_oaInt4_oaFloat)\n"
"    Calls: void get(oa2DLookupTbl_oaFloat_oaInt4_oaFloat& tbl) const\n"
"    Signature: get|void-void|ref-oa2DLookupTbl_oaFloat_oaInt4_oaFloat,\n"
"    BrowseData: 0,oa2DLookupTbl_oaFloat_oaInt4_oaFloat\n"
"    This function returns the fltIntFltTbl of this value.\n"
"    tbl\n"
"    The fltIntFltTbl of the value to return\n"
;

static PyObject*
oaFltIntFltTblValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFltIntFltTblValue data;
    int convert_status=PyoaFltIntFltTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFltIntFltTblValueObject* self=(PyoaFltIntFltTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa2DLookupTbl_oaFloat_oaInt4_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa2DLookupTbl_oaFloat_oaInt4_oaFloat_Convert,&p1)) {
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
static char oaFltIntFltTblValue_set_doc[] = 
"Class: oaFltIntFltTblValue, Function: set\n"
"  Paramegers: (oa2DLookupTbl_oaFloat_oaInt4_oaFloat)\n"
"    Calls: void set(const oa2DLookupTbl_oaFloat_oaInt4_oaFloat& tbl)\n"
"    Signature: set|void-void|cref-oa2DLookupTbl_oaFloat_oaInt4_oaFloat,\n"
"    This function sets the value of this fltIntFltTbl value to the specified fltIntFltTbl value.\n"
"    tbl\n"
"    The fltIntFltTbl value to set.\n"
;

static PyObject*
oaFltIntFltTblValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFltIntFltTblValue data;
    int convert_status=PyoaFltIntFltTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFltIntFltTblValueObject* self=(PyoaFltIntFltTblValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoa2DLookupTbl_oaFloat_oaInt4_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &Pyoa2DLookupTbl_oaFloat_oaInt4_oaFloat_Convert,&p1)) {
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
static char oaFltIntFltTblValue_isNull_doc[] =
"Class: oaFltIntFltTblValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFltIntFltTblValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFltIntFltTblValue data;
    int convert_status=PyoaFltIntFltTblValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFltIntFltTblValue_assign_doc[] = 
"Class: oaFltIntFltTblValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFltIntFltTblValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFltIntFltTblValue data;
  int convert_status=PyoaFltIntFltTblValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFltIntFltTblValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFltIntFltTblValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFltIntFltTblValue_methodlist[] = {
    {"get",(PyCFunction)oaFltIntFltTblValue_get,METH_VARARGS,oaFltIntFltTblValue_get_doc},
    {"set",(PyCFunction)oaFltIntFltTblValue_set,METH_VARARGS,oaFltIntFltTblValue_set_doc},
    {"isNull",(PyCFunction)oaFltIntFltTblValue_tp_isNull,METH_VARARGS,oaFltIntFltTblValue_isNull_doc},
    {"assign",(PyCFunction)oaFltIntFltTblValue_tp_assign,METH_VARARGS,oaFltIntFltTblValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFltIntFltTblValue_doc[] = 
"Class: oaFltIntFltTblValue\n"
"  The oaFltIntFltTblValue class represents a 2D lookup table value whose first lookup key is a float and second lookup key is an integer and the value is a float.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaFltIntFltTblValue)\n"
"    Calls: (const oaFltIntFltTblValue&)\n"
"    Signature: oaFltIntFltTblValue||cref-oaFltIntFltTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFltIntFltTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFltIntFltTblValue",
    sizeof(PyoaFltIntFltTblValueObject),
    0,
    (destructor)oaFltIntFltTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFltIntFltTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaFltIntFltTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFltIntFltTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFltIntFltTblValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFltIntFltTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFltIntFltTblValue_static_create_doc[] = 
"Class: oaFltIntFltTblValue, Function: create\n"
"  Paramegers: (oaObject,oa2DLookupTbl_oaFloat_oaInt4_oaFloat)\n"
"    Calls: oaFltIntFltTblValue* create(oaObject* database,const oa2DLookupTbl_oaFloat_oaInt4_oaFloat& value)\n"
"    Signature: create|ptr-oaFltIntFltTblValue|ptr-oaObject,cref-oa2DLookupTbl_oaFloat_oaInt4_oaFloat,\n"
"    This function creates fltIntFltTbl value in the database specified.\n"
"    database\n"
"    The database in which to create the value.\n"
"    value\n"
"    The fltIntFltTbl value\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaFltIntFltTblValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoa2DLookupTbl_oaFloat_oaInt4_oaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &Pyoa2DLookupTbl_oaFloat_oaInt4_oaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFltIntFltTblValuep result= (oaFltIntFltTblValue::create(p1.Data(),p2.Data()));
        return PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFltIntFltTblValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFltIntFltTblValue_static_create,METH_VARARGS,oaFltIntFltTblValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFltIntFltTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFltIntFltTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaFltIntFltTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFltIntFltTblValue",
           (PyObject*)(&PyoaFltIntFltTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFltIntFltTblValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFltIntFltTblValue_Type.tp_dict;
    for(method=oaFltIntFltTblValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFltValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFltValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFltValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFltValueObject* self = (PyoaFltValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFltValue)
    {
        PyParamoaFltValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFltValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFltValue, Choices are:\n"
        "    (oaFltValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFltValue_tp_dealloc(PyoaFltValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFltValue_tp_repr(PyObject *ob)
{
    PyParamoaFltValue value;
    int convert_status=PyoaFltValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaFltValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFltValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFltValue v1;
    PyParamoaFltValue v2;
    int convert_status1=PyoaFltValue_Convert(ob1,&v1);
    int convert_status2=PyoaFltValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFltValue_Convert(PyObject* ob,PyParamoaFltValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaFltValue_Check(ob)) {
        result->SetData( (oaFltValue**) ((PyoaFltValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFltValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFltValue_FromoaFltValue(oaFltValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFltValue* data=*value;
        PyObject* bself = PyoaFltValue_Type.tp_alloc(&PyoaFltValue_Type,0);
        if (bself == NULL) return bself;
        PyoaFltValueObject* self = (PyoaFltValueObject*)bself;
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
PyObject* PyoaFltValue_FromoaFltValue(oaFltValue* data)
{
    if (data) {
       PyObject* bself = PyoaFltValue_Type.tp_alloc(&PyoaFltValue_Type,0);
       if (bself == NULL) return bself;
       PyoaFltValueObject* self = (PyoaFltValueObject*)bself;
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
static char oaFltValue_get_doc[] = 
"Class: oaFltValue, Function: get\n"
"  Paramegers: ()\n"
"    Calls: oaFloat get() const\n"
"    Signature: get|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the float for this value.\n"
;

static PyObject*
oaFltValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFltValue data;
    int convert_status=PyoaFltValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFltValueObject* self=(PyoaFltValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->get());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFltValue_set_doc[] = 
"Class: oaFltValue, Function: set\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void set(oaFloat value)\n"
"    Signature: set|void-void|simple-oaFloat,\n"
"    This function sets this value to the specified float value.\n"
"    value\n"
"    The float value to set\n"
;

static PyObject*
oaFltValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFltValue data;
    int convert_status=PyoaFltValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFltValueObject* self=(PyoaFltValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
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
static char oaFltValue_isNull_doc[] =
"Class: oaFltValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFltValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFltValue data;
    int convert_status=PyoaFltValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFltValue_assign_doc[] = 
"Class: oaFltValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFltValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFltValue data;
  int convert_status=PyoaFltValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFltValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFltValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFltValue_methodlist[] = {
    {"get",(PyCFunction)oaFltValue_get,METH_VARARGS,oaFltValue_get_doc},
    {"set",(PyCFunction)oaFltValue_set,METH_VARARGS,oaFltValue_set_doc},
    {"isNull",(PyCFunction)oaFltValue_tp_isNull,METH_VARARGS,oaFltValue_isNull_doc},
    {"assign",(PyCFunction)oaFltValue_tp_assign,METH_VARARGS,oaFltValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFltValue_doc[] = 
"Class: oaFltValue\n"
"  The oaFltValue class represents a float value.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaFltValue)\n"
"    Calls: (const oaFltValue&)\n"
"    Signature: oaFltValue||cref-oaFltValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFltValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFltValue",
    sizeof(PyoaFltValueObject),
    0,
    (destructor)oaFltValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFltValue_tp_compare,	/* tp_compare */
    (reprfunc)oaFltValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFltValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFltValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFltValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFltValue_static_create_doc[] = 
"Class: oaFltValue, Function: create\n"
"  Paramegers: (oaObject,oaFloat)\n"
"    Calls: oaFltValue* create(oaObject* database,oaFloat value)\n"
"    Signature: create|ptr-oaFltValue|ptr-oaObject,simple-oaFloat,\n"
"    This function creates a float value in the database specified.\n"
"    database\n"
"    The database in which to create the value\n"
"    value\n"
"    The float value\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaFltValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFltValuep result= (oaFltValue::create(p1.Data(),p2.Data()));
        return PyoaFltValue_FromoaFltValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaFltValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFltValue_static_create,METH_VARARGS,oaFltValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFltValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFltValue_Type)<0) {
      printf("** PyType_Ready failed for: oaFltValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFltValue",
           (PyObject*)(&PyoaFltValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFltValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFltValue_Type.tp_dict;
    for(method=oaFltValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFont
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFont_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFont_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFontObject* self = (PyoaFontObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaFont();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaFontEnum)
    {
        PyParamoaFontEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaFontEnum_Convert,&p1)) {
            self->value =  new oaFont(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaFont(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaFont)
    {
        PyParamoaFont p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFont_Convert,&p1)) {
            self->value= new oaFont(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaFont, Choices are:\n"
        "    ()\n"
        "    (oaFontEnum)\n"
        "    (oaString)\n"
        "    (oaFont)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFont_tp_dealloc(PyoaFontObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFont_tp_repr(PyObject *ob)
{
    PyParamoaFont value;
    int convert_status=PyoaFont_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[28];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaFont::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFont_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFont v1;
    PyParamoaFont v2;
    int convert_status1=PyoaFont_Convert(ob1,&v1);
    int convert_status2=PyoaFont_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFont_Convert(PyObject* ob,PyParamoaFont* result)
{
    if (ob == NULL) return 1;
    if (PyoaFont_Check(ob)) {
        result->SetData(  ((PyoaFontObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFont Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFont_FromoaFont(oaFont* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaFont_Type.tp_alloc(&PyoaFont_Type,0);
        if (bself == NULL) return bself;
        PyoaFontObject* self = (PyoaFontObject*)bself;
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
static char oaFont_calcBBox_doc[] = 
"Class: oaFont, Function: calcBBox\n"
"  Paramegers: (oaPoint,oaString,oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)\n"
"    Calls: void calcBBox(const oaPoint& origin,const oaString& text,oaDist height,oaTextAlign textAlign,oaOrient orient,oaBoolean hasOverbar,oaBox& bBox)\n"
"    Signature: calcBBox|void-void|cref-oaPoint,cref-oaString,simple-oaDist,simple-oaTextAlign,simple-oaOrient,simple-oaBoolean,ref-oaBox,\n"
"    This function calculates the bounding box for the specified arguments in the current font.\n"
"    origin\n"
"    The origin point of the bounding box\n"
"    text\n"
"    The text for which to calculate the bounding box\n"
"    height\n"
"    The height of the bounding box\n"
"    textAlign\n"
"    The text alignment of the bounding box\n"
"    orient\n"
"    The orientation of the bounding box\n"
"    hasOverbar\n"
"    Determines if the text has a bar over it\n"
"    bBox\n"
"    The bounding box specifications\n"
"  Paramegers: (oaPoint,[oaChar],oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)\n"
"    Calls: void calcBBox(const oaPoint& origin,const oaChar* text,oaDist height,oaTextAlign textAlign,oaOrient orient,oaBoolean hasOverbar,oaBox& bBox)\n"
"    Signature: calcBBox|void-void|cref-oaPoint,cptr-oaChar,simple-oaDist,simple-oaTextAlign,simple-oaOrient,simple-oaBoolean,ref-oaBox,\n"
"    This function calculates the bounding box for the specified arguments in the current font.\n"
"    origin\n"
"    The origin point of the bounding box\n"
"    text\n"
"    The text for which to calculate the bounding box\n"
"    height\n"
"    The height of the bounding box\n"
"    textAlign\n"
"    The text alignment of the bounding box\n"
"    orient\n"
"    The orientation of the bounding box\n"
"    hasOverbar\n"
"    Determines if the text has a bar over it\n"
"    bBox\n"
"    The bounding box specifications\n"
;

static PyObject*
oaFont_calcBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFont data;
    int convert_status=PyoaFont_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFontObject* self=(PyoaFontObject*)ob;

    // Case: (oaPoint,oaString,oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)
    {
        PyParamoaPoint p1;
        PyParamoaString p2;
        PyParamoaDist p3;
        PyParamoaTextAlign p4;
        PyParamoaOrient p5;
        PyParamoaBoolean p6;
        PyParamoaBox p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaTextAlign_Convert,&p4,
              &PyoaOrient_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBox_Convert,&p7)) {
            data.DataCall()->calcBBox(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,[oaChar],oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)
    {
        PyParamoaPoint p1;
        PyParamoaChar_Array p2;
        PyParamoaDist p3;
        PyParamoaTextAlign p4;
        PyParamoaOrient p5;
        PyParamoaBoolean p6;
        PyParamoaBox p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaChar_Array_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaTextAlign_Convert,&p4,
              &PyoaOrient_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBox_Convert,&p7)) {
            data.DataCall()->calcBBox(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFont, function: calcBBox, Choices are:\n"
        "    (oaPoint,oaString,oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)\n"
        "    (oaPoint,[oaChar],oaDist,oaTextAlign,oaOrient,oaBoolean,oaBox)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFont_getName_doc[] = 
"Class: oaFont, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaFontEnum object.\n"
;

static PyObject*
oaFont_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFont data;
    int convert_status=PyoaFont_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFontObject* self=(PyoaFontObject*)ob;

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
static char oaFont_oaFontEnum_doc[] = 
"Class: oaFont, Function: oaFontEnum\n"
"  Paramegers: ()\n"
"    Calls: oaFontEnum oaFontEnum() const\n"
"    Signature: operator oaFontEnum|simple-oaFontEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaFontobject into the corresponding #oaFontEnum value.\n"
;

static PyObject*
oaFont_oaFontEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFont data;
    int convert_status=PyoaFont_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFontObject* self=(PyoaFontObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaFontEnum result= (data.DataCall()->operator oaFontEnum());
        return PyoaFontEnum_FromoaFontEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaFont_assign_doc[] = 
"Class: oaFont, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFont_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFont data;
  int convert_status=PyoaFont_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFont p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFont_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFont_methodlist[] = {
    {"calcBBox",(PyCFunction)oaFont_calcBBox,METH_VARARGS,oaFont_calcBBox_doc},
    {"getName",(PyCFunction)oaFont_getName,METH_VARARGS,oaFont_getName_doc},
    {"oaFontEnum",(PyCFunction)oaFont_oaFontEnum,METH_VARARGS,oaFont_oaFontEnum_doc},
    {"assign",(PyCFunction)oaFont_tp_assign,METH_VARARGS,oaFont_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFont_doc[] = 
"Class: oaFont\n"
"  The oaFont class implements an enumerated font type. This class also implements functions for calculating the bounding box of any text string in a specified font with a specified set of attributes.\n"
"  oaFontEnum\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaFont()\n"
"    Signature: oaFont||\n"
"    This function constructs an oaFont class with the font value initialized to oacStickFont.\n"
"  Paramegers: (oaFontEnum)\n"
"    Calls: oaFont(oaFontEnum valueIn)\n"
"    Signature: oaFont||simple-oaFontEnum,\n"
"    This function constructs an instance of an oaFont class using the specified enum value. The enum values are defined in #oaFontEnum.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaFont(const oaString& name)\n"
"    Signature: oaFont||cref-oaString,\n"
"    This function constructs an instance of an oaFont class using the #oaFontEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaFontEnum.\n"
"    oacInvalidFontName\n"
"  Paramegers: (oaFont)\n"
"    Calls: (const oaFont&)\n"
"    Signature: oaFont||cref-oaFont,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFont_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFont",
    sizeof(PyoaFontObject),
    0,
    (destructor)oaFont_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFont_tp_compare,	/* tp_compare */
    (reprfunc)oaFont_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFont_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFont_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFont_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFont_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFont_Type)<0) {
      printf("** PyType_Ready failed for: oaFont\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFont",
           (PyObject*)(&PyoaFont_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFont\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaFontEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaFontEnum_Convert(PyObject* ob,PyParamoaFontEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacEuroStyleFont")==0) { result->SetData(oacEuroStyleFont); return 1;}
        if (strcasecmp(str,"oacGothicFont")==0) { result->SetData(oacGothicFont); return 1;}
        if (strcasecmp(str,"oacMathFont")==0) { result->SetData(oacMathFont); return 1;}
        if (strcasecmp(str,"oacRomanFont")==0) { result->SetData(oacRomanFont); return 1;}
        if (strcasecmp(str,"oacScriptFont")==0) { result->SetData(oacScriptFont); return 1;}
        if (strcasecmp(str,"oacStickFont")==0) { result->SetData(oacStickFont); return 1;}
        if (strcasecmp(str,"oacFixedFont")==0) { result->SetData(oacFixedFont); return 1;}
        if (strcasecmp(str,"oacSwedishFont")==0) { result->SetData(oacSwedishFont); return 1;}
        if (strcasecmp(str,"oacMilSpecFont")==0) { result->SetData(oacMilSpecFont); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaFontEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFontEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaFontEnum_FromoaFontEnum(oaFontEnum ob)
{
    if (ob==oacEuroStyleFont) return PyString_FromString("oacEuroStyleFont");
    if (ob==oacGothicFont) return PyString_FromString("oacGothicFont");
    if (ob==oacMathFont) return PyString_FromString("oacMathFont");
    if (ob==oacRomanFont) return PyString_FromString("oacRomanFont");
    if (ob==oacScriptFont) return PyString_FromString("oacScriptFont");
    if (ob==oacStickFont) return PyString_FromString("oacStickFont");
    if (ob==oacFixedFont) return PyString_FromString("oacFixedFont");
    if (ob==oacSwedishFont) return PyString_FromString("oacSwedishFont");
    if (ob==oacMilSpecFont) return PyString_FromString("oacMilSpecFont");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaFontEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaFontEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaFontEnum_FromoaFontEnum(oaFontEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaFontEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaFontEnum_doc[] =
"Type convert function for enum: oaFontEnum";
                               
static PyMethodDef PyoaFontEnum_method =
  {"oaFontEnum",(PyCFunction)PyoaFontEnum_TypeFunction,METH_VARARGS,oaFontEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaFontEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacEuroStyleFont");
    PyDict_SetItemString(mod_dict,"oacEuroStyleFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGothicFont");
    PyDict_SetItemString(mod_dict,"oacGothicFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMathFont");
    PyDict_SetItemString(mod_dict,"oacMathFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRomanFont");
    PyDict_SetItemString(mod_dict,"oacRomanFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacScriptFont");
    PyDict_SetItemString(mod_dict,"oacScriptFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStickFont");
    PyDict_SetItemString(mod_dict,"oacStickFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFixedFont");
    PyDict_SetItemString(mod_dict,"oacFixedFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSwedishFont");
    PyDict_SetItemString(mod_dict,"oacSwedishFont",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMilSpecFont");
    PyDict_SetItemString(mod_dict,"oacMilSpecFont",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaFontEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaFontEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaFontEnum\n");
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
// Wrapper Implementation for Class: oaFrame
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFrame_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFrame_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFrameObject* self = (PyoaFrameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFrame)
    {
        PyParamoaFrame p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFrame_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFrame, Choices are:\n"
        "    (oaFrame)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFrame_tp_dealloc(PyoaFrameObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFrame_tp_repr(PyObject *ob)
{
    PyParamoaFrame value;
    int convert_status=PyoaFrame_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaFrame::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFrame_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFrame v1;
    PyParamoaFrame v2;
    int convert_status1=PyoaFrame_Convert(ob1,&v1);
    int convert_status2=PyoaFrame_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFrame_Convert(PyObject* ob,PyParamoaFrame* result)
{
    if (ob == NULL) return 1;
    if (PyoaFrame_Check(ob)) {
        result->SetData( (oaFrame**) ((PyoaFrameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFrame Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFrame_FromoaFrame(oaFrame** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFrame* data=*value;
        PyObject* bself = PyoaFrame_Type.tp_alloc(&PyoaFrame_Type,0);
        if (bself == NULL) return bself;
        PyoaFrameObject* self = (PyoaFrameObject*)bself;
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
PyObject* PyoaFrame_FromoaFrame(oaFrame* data)
{
    if (data) {
       PyObject* bself = PyoaFrame_Type.tp_alloc(&PyoaFrame_Type,0);
       if (bself == NULL) return bself;
       PyoaFrameObject* self = (PyoaFrameObject*)bself;
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
static char oaFrame_destroy_doc[] = 
"Class: oaFrame, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this frame, removing it from the database.\n"
;

static PyObject*
oaFrame_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
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
static char oaFrame_getBoundaryBox_doc[] = 
"Class: oaFrame, Function: getBoundaryBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getBoundaryBox(oaBox& boundaryBox) const\n"
"    Signature: getBoundaryBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function returns the boundary box of this frame in the given boundaryBox argument.\n"
"    boundaryBox\n"
"    The boundary box of the oaFrame to return\n"
;

static PyObject*
oaFrame_getBoundaryBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getBoundaryBox(p1.Data());
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
static char oaFrame_getDesignInsts_doc[] = 
"Class: oaFrame, Function: getDesignInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDesignInst_oaFrame getDesignInsts() const\n"
"    Signature: getDesignInsts|simple-oaCollection_oaDesignInst_oaFrame|\n"
"    BrowseData: 1\n"
"    This function returns the collection of designInsts associated with this frame.\n"
;

static PyObject*
oaFrame_getDesignInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDesignInst_oaFrame* result= new oaCollection_oaDesignInst_oaFrame(data.DataCall()->getDesignInsts());
        return PyoaCollection_oaDesignInst_oaFrame_FromoaCollection_oaDesignInst_oaFrame(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrame_getDesignInstsIter_doc[] = 
"Class: oaFrame, Function: getDesignInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDesignInst getDesignInstsIter() const\n"
"    Signature: getDesignInstsIter|simple-oaIter_oaDesignInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of designInsts associated with this frame.\n"
;

static PyObject*
oaFrame_getDesignInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDesignInst* result= new oaIter_oaDesignInst(data.DataCall()->getDesignInsts());
        return PyoaIter_oaDesignInst_FromoaIter_oaDesignInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrame_getFrameInsts_doc[] = 
"Class: oaFrame, Function: getFrameInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaFrameInst_oaFrame getFrameInsts() const\n"
"    Signature: getFrameInsts|simple-oaCollection_oaFrameInst_oaFrame|\n"
"    BrowseData: 1\n"
"    This function returns the collection of frameInsts associated with this frame.\n"
;

static PyObject*
oaFrame_getFrameInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaFrameInst_oaFrame* result= new oaCollection_oaFrameInst_oaFrame(data.DataCall()->getFrameInsts());
        return PyoaCollection_oaFrameInst_oaFrame_FromoaCollection_oaFrameInst_oaFrame(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrame_getFrameInstsIter_doc[] = 
"Class: oaFrame, Function: getFrameInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaFrameInst getFrameInstsIter() const\n"
"    Signature: getFrameInstsIter|simple-oaIter_oaFrameInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of frameInsts associated with this frame.\n"
;

static PyObject*
oaFrame_getFrameInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaFrameInst* result= new oaIter_oaFrameInst(data.DataCall()->getFrameInsts());
        return PyoaIter_oaFrameInst_FromoaIter_oaFrameInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrame_getName_doc[] = 
"Class: oaFrame, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this frame.\n"
"    name\n"
"    The oaString to return the name in\n"
;

static PyObject*
oaFrame_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
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
static char oaFrame_setBoundaryBox_doc[] = 
"Class: oaFrame, Function: setBoundaryBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void setBoundaryBox(const oaBox& boundaryBox)\n"
"    Signature: setBoundaryBox|void-void|cref-oaBox,\n"
"    This function changes the boundary box of this frame to the specified boundaryBox.\n"
"    boundaryBox\n"
"    The boundary box to set\n"
;

static PyObject*
oaFrame_setBoundaryBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->setBoundaryBox(p1.Data());
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
static char oaFrame_setName_doc[] = 
"Class: oaFrame, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this frame to the specified name . An exception is thrown if another frame has the specified name.\n"
"    name\n"
"    The name to give to this frame\n"
"    oacFrameAlreadyExists\n"
;

static PyObject*
oaFrame_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameObject* self=(PyoaFrameObject*)ob;
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
static char oaFrame_isNull_doc[] =
"Class: oaFrame, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFrame_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFrame data;
    int convert_status=PyoaFrame_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFrame_assign_doc[] = 
"Class: oaFrame, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFrame_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFrame data;
  int convert_status=PyoaFrame_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFrame p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFrame_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFrame_methodlist[] = {
    {"destroy",(PyCFunction)oaFrame_destroy,METH_VARARGS,oaFrame_destroy_doc},
    {"getBoundaryBox",(PyCFunction)oaFrame_getBoundaryBox,METH_VARARGS,oaFrame_getBoundaryBox_doc},
    {"getDesignInsts",(PyCFunction)oaFrame_getDesignInsts,METH_VARARGS,oaFrame_getDesignInsts_doc},
    {"getDesignInstsIter",(PyCFunction)oaFrame_getDesignInstsIter,METH_VARARGS,oaFrame_getDesignInstsIter_doc},
    {"getFrameInsts",(PyCFunction)oaFrame_getFrameInsts,METH_VARARGS,oaFrame_getFrameInsts_doc},
    {"getFrameInstsIter",(PyCFunction)oaFrame_getFrameInstsIter,METH_VARARGS,oaFrame_getFrameInstsIter_doc},
    {"getName",(PyCFunction)oaFrame_getName,METH_VARARGS,oaFrame_getName_doc},
    {"setBoundaryBox",(PyCFunction)oaFrame_setBoundaryBox,METH_VARARGS,oaFrame_setBoundaryBox_doc},
    {"setName",(PyCFunction)oaFrame_setName,METH_VARARGS,oaFrame_setName_doc},
    {"isNull",(PyCFunction)oaFrame_tp_isNull,METH_VARARGS,oaFrame_isNull_doc},
    {"assign",(PyCFunction)oaFrame_tp_assign,METH_VARARGS,oaFrame_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFrame_doc[] = 
"Class: oaFrame\n"
"  The oaFrame class defines a non-printing area into which a series of frame or design instances are placed. Frames are hierarchical so that in a shuttle-style (multi-project chip) reticle, a lower-level frame can be used to organize the number of different die instances into a larger component, and then a top-level frame can be used to organize the shuttle die into the NxN locations on the reticle.\n"
"  An oaFrame defines a polygonal boundary. Two coincident and three collinear points are illegal, and if detected, cause an exception to be thrown. You can use oaPointArray::compress() to remove these combinations.\n"
"  The oaFrame class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaFrame)\n"
"    Calls: (const oaFrame&)\n"
"    Signature: oaFrame||cref-oaFrame,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFrame_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFrame",
    sizeof(PyoaFrameObject),
    0,
    (destructor)oaFrame_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFrame_tp_compare,	/* tp_compare */
    (reprfunc)oaFrame_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFrame_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFrame_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFrame_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFrame_static_create_doc[] = 
"Class: oaFrame, Function: create\n"
"  Paramegers: (oaWafer,oaString,oaBox)\n"
"    Calls: oaFrame* create(oaWafer* wafer,const oaString& name,const oaBox& boundaryBox)\n"
"    Signature: create|ptr-oaFrame|ptr-oaWafer,cref-oaString,cref-oaBox,\n"
"    This function creates a frame in the specified wafer with the given name and boundary. The specified boundary is checked to verify that there are at least three points and no collinear or coincident points. This function throws an exception if a frame with the specified name already exists in the specified wafer.\n"
"    wafer\n"
"    The wafer in which to create the frame\n"
"    name\n"
"    The name of the frame to create\n"
"    boundaryBox\n"
"    The frame boundary box\n"
"    oacFrameAlreadyExists\n"
;

static PyObject*
oaFrame_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    PyParamoaBox p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaBox_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFramep result= (oaFrame::create(p1.Data(),p2.Data(),p3.Data()));
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
static char oaFrame_static_find_doc[] = 
"Class: oaFrame, Function: find\n"
"  Paramegers: (oaWafer,oaString)\n"
"    Calls: oaFrame* find(const oaWafer* wafer,const oaString& name)\n"
"    Signature: find|ptr-oaFrame|cptr-oaWafer,cref-oaString,\n"
"    This function searches the specified wafer for a frame with the specified name. A pointer to the frame is returned if found, otherwise, NULL is returned.\n"
"    wafer\n"
"    The wafer to search\n"
"    name\n"
"    The name of the frame to find\n"
;

static PyObject*
oaFrame_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFramep result= (oaFrame::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaFrame_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFrame_static_create,METH_VARARGS,oaFrame_static_create_doc},
    {"static_find",(PyCFunction)oaFrame_static_find,METH_VARARGS,oaFrame_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFrame_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFrame_Type)<0) {
      printf("** PyType_Ready failed for: oaFrame\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFrame",
           (PyObject*)(&PyoaFrame_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFrame\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFrame_Type.tp_dict;
    for(method=oaFrame_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFrameInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaFrameInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaFrameInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaFrameInstObject* self = (PyoaFrameInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaFrameInst)
    {
        PyParamoaFrameInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaFrameInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaFrameInst, Choices are:\n"
        "    (oaFrameInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaFrameInst_tp_dealloc(PyoaFrameInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaFrameInst_tp_repr(PyObject *ob)
{
    PyParamoaFrameInst value;
    int convert_status=PyoaFrameInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaFrameInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaFrameInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaFrameInst v1;
    PyParamoaFrameInst v2;
    int convert_status1=PyoaFrameInst_Convert(ob1,&v1);
    int convert_status2=PyoaFrameInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaFrameInst_Convert(PyObject* ob,PyParamoaFrameInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaFrameInst_Check(ob)) {
        result->SetData( (oaFrameInst**) ((PyoaFrameInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFrameInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaFrameInst_FromoaFrameInst(oaFrameInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaFrameInst* data=*value;
        PyObject* bself = PyoaFrameInst_Type.tp_alloc(&PyoaFrameInst_Type,0);
        if (bself == NULL) return bself;
        PyoaFrameInstObject* self = (PyoaFrameInstObject*)bself;
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
PyObject* PyoaFrameInst_FromoaFrameInst(oaFrameInst* data)
{
    if (data) {
       PyObject* bself = PyoaFrameInst_Type.tp_alloc(&PyoaFrameInst_Type,0);
       if (bself == NULL) return bself;
       PyoaFrameInstObject* self = (PyoaFrameInstObject*)bself;
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
static char oaFrameInst_destroy_doc[] = 
"Class: oaFrameInst, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this frame instance, removing it from the database.\n"
;

static PyObject*
oaFrameInst_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
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
static char oaFrameInst_getMag_doc[] = 
"Class: oaFrameInst, Function: getMag\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getMag() const\n"
"    Signature: getMag|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the magnification of this frame instance\n"
;

static PyObject*
oaFrameInst_getMag(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getMag());
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrameInst_getMaster_doc[] = 
"Class: oaFrameInst, Function: getMaster\n"
"  Paramegers: ()\n"
"    Calls: oaFrame* getMaster() const\n"
"    Signature: getMaster|ptr-oaFrame|\n"
"    BrowseData: 1\n"
"    This function returns the master frame of this frame instance.\n"
;

static PyObject*
oaFrameInst_getMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFramep result= (data.DataCall()->getMaster());
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
static char oaFrameInst_getName_doc[] = 
"Class: oaFrameInst, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this frame instance in the given name argument.\n"
"    name\n"
"    The name to be filled out with the name of this frame instance\n"
;

static PyObject*
oaFrameInst_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
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
static char oaFrameInst_getOrient_doc[] = 
"Class: oaFrameInst, Function: getOrient\n"
"  Paramegers: ()\n"
"    Calls: oaOrient getOrient() const\n"
"    Signature: getOrient|simple-oaOrient|\n"
"    BrowseData: 1\n"
"    This function returns the orientation of this frame instance.\n"
;

static PyObject*
oaFrameInst_getOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOrient* result= new oaOrient(data.DataCall()->getOrient());
        return PyoaOrient_FromoaOrient(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrameInst_getOrigin_doc[] = 
"Class: oaFrameInst, Function: getOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getOrigin(oaPoint& origin) const\n"
"    Signature: getOrigin|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function fills out 'origin' with the origin of this frame instance.\n"
"    origin\n"
"    The origin to be filled out\n"
;

static PyObject*
oaFrameInst_getOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->getOrigin(p1.Data());
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
static char oaFrameInst_getOwner_doc[] = 
"Class: oaFrameInst, Function: getOwner\n"
"  Paramegers: ()\n"
"    Calls: oaWaferObject* getOwner() const\n"
"    Signature: getOwner|ptr-oaWaferObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to object that owns this frame instance. The owning object can be either an oaReticle or an oaFrame\n"
;

static PyObject*
oaFrameInst_getOwner(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferObjectp result= (data.DataCall()->getOwner());
        return PyoaWaferObject_FromoaWaferObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrameInst_getTransform_doc[] = 
"Class: oaFrameInst, Function: getTransform\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void getTransform(oaTransform& xform) const\n"
"    Signature: getTransform|void-void|ref-oaTransform,\n"
"    BrowseData: 0,oaTransform\n"
"    This function fills out 'xform' with the transform of this frame instance.\n"
"    xform\n"
"    The transform to be filled out\n"
;

static PyObject*
oaFrameInst_getTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaTransform p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTransform_Convert,&p1)) {
        data.DataCall()->getTransform(p1.Data());
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
static char oaFrameInst_setMag_doc[] = 
"Class: oaFrameInst, Function: setMag\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setMag(oaFloat mag)\n"
"    Signature: setMag|void-void|simple-oaFloat,\n"
"    This function sets the magnification of this frame instance to the specified value.\n"
"    mag\n"
"    The new magnification\n"
;

static PyObject*
oaFrameInst_setMag(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setMag(p1.Data());
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
static char oaFrameInst_setName_doc[] = 
"Class: oaFrameInst, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this frame instance to the specified 'name'. An exception is thrown if another frame instance already has the specified name.\n"
"    name\n"
"    The new name of the frame instance\n"
"    oacFrameInstAlreadyExists\n"
;

static PyObject*
oaFrameInst_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
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
static char oaFrameInst_setOrient_doc[] = 
"Class: oaFrameInst, Function: setOrient\n"
"  Paramegers: (oaOrient)\n"
"    Calls: void setOrient(oaOrient orient)\n"
"    Signature: setOrient|void-void|simple-oaOrient,\n"
"    This function sets the orientation for this frame instance.\n"
"    orient\n"
"    The new orientation\n"
;

static PyObject*
oaFrameInst_setOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOrient p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOrient_Convert,&p1)) {
        data.DataCall()->setOrient(p1.Data());
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
static char oaFrameInst_setOrigin_doc[] = 
"Class: oaFrameInst, Function: setOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void setOrigin(const oaPoint& origin)\n"
"    Signature: setOrigin|void-void|cref-oaPoint,\n"
"    This function sets the origin value for this frame instance.\n"
"    origin\n"
"    The new origin\n"
;

static PyObject*
oaFrameInst_setOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->setOrigin(p1.Data());
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
static char oaFrameInst_setTransform_doc[] = 
"Class: oaFrameInst, Function: setTransform\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void setTransform(const oaTransform& xform)\n"
"    Signature: setTransform|void-void|cref-oaTransform,\n"
"    This function sets the transform for this frame instance.\n"
"    xform\n"
"    The new transform\n"
;

static PyObject*
oaFrameInst_setTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaFrameInstObject* self=(PyoaFrameInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaTransform p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTransform_Convert,&p1)) {
        data.DataCall()->setTransform(p1.Data());
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
static char oaFrameInst_isNull_doc[] =
"Class: oaFrameInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaFrameInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaFrameInst data;
    int convert_status=PyoaFrameInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaFrameInst_assign_doc[] = 
"Class: oaFrameInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaFrameInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaFrameInst data;
  int convert_status=PyoaFrameInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaFrameInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaFrameInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaFrameInst_methodlist[] = {
    {"destroy",(PyCFunction)oaFrameInst_destroy,METH_VARARGS,oaFrameInst_destroy_doc},
    {"getMag",(PyCFunction)oaFrameInst_getMag,METH_VARARGS,oaFrameInst_getMag_doc},
    {"getMaster",(PyCFunction)oaFrameInst_getMaster,METH_VARARGS,oaFrameInst_getMaster_doc},
    {"getName",(PyCFunction)oaFrameInst_getName,METH_VARARGS,oaFrameInst_getName_doc},
    {"getOrient",(PyCFunction)oaFrameInst_getOrient,METH_VARARGS,oaFrameInst_getOrient_doc},
    {"getOrigin",(PyCFunction)oaFrameInst_getOrigin,METH_VARARGS,oaFrameInst_getOrigin_doc},
    {"getOwner",(PyCFunction)oaFrameInst_getOwner,METH_VARARGS,oaFrameInst_getOwner_doc},
    {"getTransform",(PyCFunction)oaFrameInst_getTransform,METH_VARARGS,oaFrameInst_getTransform_doc},
    {"setMag",(PyCFunction)oaFrameInst_setMag,METH_VARARGS,oaFrameInst_setMag_doc},
    {"setName",(PyCFunction)oaFrameInst_setName,METH_VARARGS,oaFrameInst_setName_doc},
    {"setOrient",(PyCFunction)oaFrameInst_setOrient,METH_VARARGS,oaFrameInst_setOrient_doc},
    {"setOrigin",(PyCFunction)oaFrameInst_setOrigin,METH_VARARGS,oaFrameInst_setOrigin_doc},
    {"setTransform",(PyCFunction)oaFrameInst_setTransform,METH_VARARGS,oaFrameInst_setTransform_doc},
    {"isNull",(PyCFunction)oaFrameInst_tp_isNull,METH_VARARGS,oaFrameInst_isNull_doc},
    {"assign",(PyCFunction)oaFrameInst_tp_assign,METH_VARARGS,oaFrameInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFrameInst_doc[] = 
"Class: oaFrameInst\n"
"  An oaFrameInst is an instance of an oaFrame in its parent which is either another oaFrame , or an oaReticle . They provide a means where a hierarchy of oaFrames can be used to layout the contents of an oaReticle . At the bottom of this hierarchy will be oaDesignInst objects that refer to oaDesign databases that contain the actual geometry that will be printed on the oaReticle .\n"
"  The oaFrameInst class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaFrameInst)\n"
"    Calls: (const oaFrameInst&)\n"
"    Signature: oaFrameInst||cref-oaFrameInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaFrameInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaFrameInst",
    sizeof(PyoaFrameInstObject),
    0,
    (destructor)oaFrameInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaFrameInst_tp_compare,	/* tp_compare */
    (reprfunc)oaFrameInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaFrameInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaFrameInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaFrameInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaFrameInst_static_create_doc[] = 
"Class: oaFrameInst, Function: create\n"
"  Paramegers: (oaReticle,oaFrame,oaString,oaFloat,oaTransform)\n"
"    Calls: oaFrameInst* create(oaReticle* reticle,oaFrame* master,const oaString& name,oaFloat mag,const oaTransform& xform)\n"
"    Signature: create|ptr-oaFrameInst|ptr-oaReticle,ptr-oaFrame,cref-oaString,simple-oaFloat,cref-oaTransform,\n"
"    This function creates an oaFrameInst object in the specified reticle with the specified attributes.\n"
"    reticle\n"
"    The reticle object from which this frame instance is instantiated\n"
"    master\n"
"    The master frame\n"
"    name\n"
"    The name of the frame instance\n"
"    mag\n"
"    The magnification\n"
"    xform\n"
"    The transformation\n"
"    oacFrameInstAlreadyExists\n"
"    oacFrameInstOwnerAndMasterDiffWafer\n"
"  Paramegers: (oaFrame,oaFrame,oaString,oaFloat,oaTransform)\n"
"    Calls: oaFrameInst* create(oaFrame* frame,oaFrame* master,const oaString& name,oaFloat mag,const oaTransform& xform)\n"
"    Signature: create|ptr-oaFrameInst|ptr-oaFrame,ptr-oaFrame,cref-oaString,simple-oaFloat,cref-oaTransform,\n"
"    This function creates an oaDesignInst object in the specified frame with the specified attributes.\n"
"    frame\n"
"    The frame object from which this frame instance is instantiated\n"
"    master\n"
"    The master frame\n"
"    name\n"
"    The name of the frame instance\n"
"    mag\n"
"    The magnification\n"
"    xform\n"
"    The transformation\n"
"    oacFrameInstAlreadyExists\n"
"    oacFrameInstOwnerAndMasterDiffWafer\n"
"    oacFrameInstOwnerAndMasterAreSame\n"
;

static PyObject*
oaFrameInst_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaReticle,oaFrame,oaString,oaFloat,oaTransform)
    {
        PyParamoaReticle p1;
        PyParamoaFrame p2;
        PyParamoaString p3;
        PyParamoaFloat p4;
        PyParamoaTransform p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaReticle_Convert,&p1,
              &PyoaFrame_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaFloat_Convert,&p4,
              &PyoaTransform_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFrameInstp result= (oaFrameInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaFrameInst_FromoaFrameInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaFrame,oaFrame,oaString,oaFloat,oaTransform)
    {
        PyParamoaFrame p1;
        PyParamoaFrame p2;
        PyParamoaString p3;
        PyParamoaFloat p4;
        PyParamoaTransform p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaFrame_Convert,&p1,
              &PyoaFrame_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaFloat_Convert,&p4,
              &PyoaTransform_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaFrameInstp result= (oaFrameInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaFrameInst_FromoaFrameInst(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaFrameInst, function: create, Choices are:\n"
        "    (oaReticle,oaFrame,oaString,oaFloat,oaTransform)\n"
        "    (oaFrame,oaFrame,oaString,oaFloat,oaTransform)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaFrameInst_static_find_doc[] = 
"Class: oaFrameInst, Function: find\n"
"  Paramegers: (oaWafer,oaString)\n"
"    Calls: oaFrameInst* find(const oaWafer* wafer,const oaString& name)\n"
"    Signature: find|ptr-oaFrameInst|cptr-oaWafer,cref-oaString,\n"
"    This function searches the specified wafer for a frameInst with the given name. A pointer to the frameInst is returned if found, otherwise, NULL is returned.\n"
"    wafer\n"
"    The wafer to search\n"
"    name\n"
"    The frame instance name to find\n"
;

static PyObject*
oaFrameInst_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFrameInstp result= (oaFrameInst::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaFrameInst_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaFrameInst_static_create,METH_VARARGS,oaFrameInst_static_create_doc},
    {"static_find",(PyCFunction)oaFrameInst_static_find,METH_VARARGS,oaFrameInst_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaFrameInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaFrameInst_Type)<0) {
      printf("** PyType_Ready failed for: oaFrameInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaFrameInst",
           (PyObject*)(&PyoaFrameInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaFrameInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaFrameInst_Type.tp_dict;
    for(method=oaFrameInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaFrameInstModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaFrameInstModTypeEnum_Convert(PyObject* ob,PyParamoaFrameInstModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameFrameInstModType")==0) { result->SetData(oacSetNameFrameInstModType); return 1;}
        if (strcasecmp(str,"oacSetMagFrameInstModType")==0) { result->SetData(oacSetMagFrameInstModType); return 1;}
        if (strcasecmp(str,"oacSetTransformFrameInstModType")==0) { result->SetData(oacSetTransformFrameInstModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaFrameInstModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFrameInstModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaFrameInstModTypeEnum_FromoaFrameInstModTypeEnum(oaFrameInstModTypeEnum ob)
{
    if (ob==oacSetNameFrameInstModType) return PyString_FromString("oacSetNameFrameInstModType");
    if (ob==oacSetMagFrameInstModType) return PyString_FromString("oacSetMagFrameInstModType");
    if (ob==oacSetTransformFrameInstModType) return PyString_FromString("oacSetTransformFrameInstModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaFrameInstModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaFrameInstModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaFrameInstModTypeEnum_FromoaFrameInstModTypeEnum(oaFrameInstModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaFrameInstModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaFrameInstModTypeEnum_doc[] =
"Type convert function for enum: oaFrameInstModTypeEnum";
                               
static PyMethodDef PyoaFrameInstModTypeEnum_method =
  {"oaFrameInstModTypeEnum",(PyCFunction)PyoaFrameInstModTypeEnum_TypeFunction,METH_VARARGS,oaFrameInstModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaFrameInstModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameFrameInstModType");
    PyDict_SetItemString(mod_dict,"oacSetNameFrameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetMagFrameInstModType");
    PyDict_SetItemString(mod_dict,"oacSetMagFrameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetTransformFrameInstModType");
    PyDict_SetItemString(mod_dict,"oacSetTransformFrameInstModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaFrameInstModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaFrameInstModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaFrameInstModTypeEnum\n");
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
// Wrapper Implementation for Class: oaFrameModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaFrameModTypeEnum_Convert(PyObject* ob,PyParamoaFrameModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameFrameModType")==0) { result->SetData(oacSetNameFrameModType); return 1;}
        if (strcasecmp(str,"oacSetBoundaryBoxFrameModType")==0) { result->SetData(oacSetBoundaryBoxFrameModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaFrameModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaFrameModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaFrameModTypeEnum_FromoaFrameModTypeEnum(oaFrameModTypeEnum ob)
{
    if (ob==oacSetNameFrameModType) return PyString_FromString("oacSetNameFrameModType");
    if (ob==oacSetBoundaryBoxFrameModType) return PyString_FromString("oacSetBoundaryBoxFrameModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaFrameModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaFrameModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaFrameModTypeEnum_FromoaFrameModTypeEnum(oaFrameModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaFrameModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaFrameModTypeEnum_doc[] =
"Type convert function for enum: oaFrameModTypeEnum";
                               
static PyMethodDef PyoaFrameModTypeEnum_method =
  {"oaFrameModTypeEnum",(PyCFunction)PyoaFrameModTypeEnum_TypeFunction,METH_VARARGS,oaFrameModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaFrameModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameFrameModType");
    PyDict_SetItemString(mod_dict,"oacSetNameFrameModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBoundaryBoxFrameModType");
    PyDict_SetItemString(mod_dict,"oacSetBoundaryBoxFrameModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaFrameModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaFrameModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaFrameModTypeEnum\n");
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
// Wrapper Implementation for Class: oaGCellPattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGCellPattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGCellPattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGCellPatternObject* self = (PyoaGCellPatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGCellPattern)
    {
        PyParamoaGCellPattern p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGCellPattern_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaGCellPattern, Choices are:\n"
        "    (oaGCellPattern)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGCellPattern_tp_dealloc(PyoaGCellPatternObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGCellPattern_tp_repr(PyObject *ob)
{
    PyParamoaGCellPattern value;
    int convert_status=PyoaGCellPattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaGCellPattern::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGCellPattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGCellPattern v1;
    PyParamoaGCellPattern v2;
    int convert_status1=PyoaGCellPattern_Convert(ob1,&v1);
    int convert_status2=PyoaGCellPattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGCellPattern_Convert(PyObject* ob,PyParamoaGCellPattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaGCellPattern_Check(ob)) {
        result->SetData( (oaGCellPattern**) ((PyoaGCellPatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGCellPattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGCellPattern_FromoaGCellPattern(oaGCellPattern** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaGCellPattern* data=*value;
        PyObject* bself = PyoaGCellPattern_Type.tp_alloc(&PyoaGCellPattern_Type,0);
        if (bself == NULL) return bself;
        PyoaGCellPatternObject* self = (PyoaGCellPatternObject*)bself;
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
PyObject* PyoaGCellPattern_FromoaGCellPattern(oaGCellPattern* data)
{
    if (data) {
       PyObject* bself = PyoaGCellPattern_Type.tp_alloc(&PyoaGCellPattern_Type,0);
       if (bself == NULL) return bself;
       PyoaGCellPatternObject* self = (PyoaGCellPatternObject*)bself;
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
static char oaGCellPattern_destroy_doc[] = 
"Class: oaGCellPattern, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this pattern from the design. It will also invalidate any previous oaCMap .\n"
;

static PyObject*
oaGCellPattern_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGCellPatternObject* self=(PyoaGCellPatternObject*)ob;
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
static char oaGCellPattern_getCount_doc[] = 
"Class: oaGCellPattern, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function gets the count value from this pattern.\n"
;

static PyObject*
oaGCellPattern_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGCellPatternObject* self=(PyoaGCellPatternObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaGCellPattern_getSpacing_doc[] = 
"Class: oaGCellPattern, Function: getSpacing\n"
"  Paramegers: ()\n"
"    Calls: oaDist getSpacing() const\n"
"    Signature: getSpacing|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function gets the spacing from this pattern.\n"
;

static PyObject*
oaGCellPattern_getSpacing(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGCellPatternObject* self=(PyoaGCellPatternObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getSpacing());
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
static char oaGCellPattern_getStartCoord_doc[] = 
"Class: oaGCellPattern, Function: getStartCoord\n"
"  Paramegers: ()\n"
"    Calls: oaCoord getStartCoord() const\n"
"    Signature: getStartCoord|simple-oaCoord|\n"
"    BrowseData: 1\n"
"    This function gets the starting coordinate from this pattern.\n"
;

static PyObject*
oaGCellPattern_getStartCoord(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGCellPatternObject* self=(PyoaGCellPatternObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord result= (data.DataCall()->getStartCoord());
        return PyoaCoord_FromoaCoord(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGCellPattern_isHorizontal_doc[] = 
"Class: oaGCellPattern, Function: isHorizontal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isHorizontal() const\n"
"    Signature: isHorizontal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function gets the flag indicating if this pattern is horizontal.\n"
;

static PyObject*
oaGCellPattern_isHorizontal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGCellPatternObject* self=(PyoaGCellPatternObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isHorizontal());
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
static char oaGCellPattern_isNull_doc[] =
"Class: oaGCellPattern, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaGCellPattern_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaGCellPattern data;
    int convert_status=PyoaGCellPattern_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaGCellPattern_assign_doc[] = 
"Class: oaGCellPattern, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGCellPattern_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGCellPattern data;
  int convert_status=PyoaGCellPattern_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGCellPattern p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGCellPattern_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGCellPattern_methodlist[] = {
    {"destroy",(PyCFunction)oaGCellPattern_destroy,METH_VARARGS,oaGCellPattern_destroy_doc},
    {"getCount",(PyCFunction)oaGCellPattern_getCount,METH_VARARGS,oaGCellPattern_getCount_doc},
    {"getSpacing",(PyCFunction)oaGCellPattern_getSpacing,METH_VARARGS,oaGCellPattern_getSpacing_doc},
    {"getStartCoord",(PyCFunction)oaGCellPattern_getStartCoord,METH_VARARGS,oaGCellPattern_getStartCoord_doc},
    {"isHorizontal",(PyCFunction)oaGCellPattern_isHorizontal,METH_VARARGS,oaGCellPattern_isHorizontal_doc},
    {"isNull",(PyCFunction)oaGCellPattern_tp_isNull,METH_VARARGS,oaGCellPattern_isNull_doc},
    {"assign",(PyCFunction)oaGCellPattern_tp_assign,METH_VARARGS,oaGCellPattern_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGCellPattern_doc[] = 
"Class: oaGCellPattern\n"
"  The oaGCellPattern class defines the position and number of GCells in the congestion map. GCells are used by global routers to keep statistics on the level of congestion of each area in the design. GCells are defined as a grid - possibly non uniform - covering the area of the design.\n"
"  GCellPatterns can be horizontal or vertical and at least one of each must exist in a design for it to have a valid congestion map. Each GCellPattern declares a set of uniformly spaced edges that will divide the design area into columns or rows. GCellPatterns with isHorizontal set will define columns, and GCellPatterns with isHorizontal unset will define rows.\n"
"  In the common case where there is a single GCellPattern for each direction, the pattern declares count edges that define count-1 columns or rows. These columns or rows will have indexes from 0 to count-2 in the oaCMap . The startCoord of the GCellPattern with isHorizontal set will be the left X coordinate of the first column and the startCoord of the GCellPattern with isHorizontal unset will define the bottom Y coordinate of the lowest row.\n"
"  Non-uniform grids may be declared by using multiple GCellPatterns for a given direction. In this case OpenAccess will sort and merge the edges defined by all the GCellPatterns for a given direction. Coincident edges will be removed and the remaining edges will define the set of rows or columns that exist. It is allowed (though unusual) to have overlapping GCellPatterns.\n"
"  See oaCMap for a discussion of how to access GCells and the data that is stored in them.\n"
"  The oaGCellPattern class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaGCellPattern)\n"
"    Calls: (const oaGCellPattern&)\n"
"    Signature: oaGCellPattern||cref-oaGCellPattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGCellPattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGCellPattern",
    sizeof(PyoaGCellPatternObject),
    0,
    (destructor)oaGCellPattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGCellPattern_tp_compare,	/* tp_compare */
    (reprfunc)oaGCellPattern_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGCellPattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGCellPattern_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGCellPattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGCellPattern_static_create_doc[] = 
"Class: oaGCellPattern, Function: create\n"
"  Paramegers: (oaBlock,oaBoolean,oaCoord,oaDist,oaUInt4)\n"
"    Calls: oaGCellPattern* create(oaBlock* block,oaBoolean isHorizontal,oaCoord startCoord,oaDist spacing,oaUInt4 count)\n"
"    Signature: create|ptr-oaGCellPattern|ptr-oaBlock,simple-oaBoolean,simple-oaCoord,simple-oaDist,simple-oaUInt4,\n"
"    This function creates a new GCellPattern in the specified design with the specified attributes.\n"
"    block\n"
"    The vlock in which to create the new GCellPattern\n"
"    isHorizontal\n"
"    Determines if the pattern is horizontal\n"
"    startCoord\n"
"    The starting coordinate for the pattern\n"
"    spacing\n"
"    The spacing for the pattern\n"
"    count\n"
"    The number of edges defined by the pattern\n"
"    This will invalidate any previous values stored on the design's oaCMap .\n"
;

static PyObject*
oaGCellPattern_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaBoolean p2;
    PyParamoaCoord p3;
    PyParamoaDist p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaBoolean_Convert,&p2,
          &PyoaCoord_Convert,&p3,
          &PyoaDist_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaGCellPatternp result= (oaGCellPattern::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static PyMethodDef oaGCellPattern_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaGCellPattern_static_create,METH_VARARGS,oaGCellPattern_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGCellPattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGCellPattern_Type)<0) {
      printf("** PyType_Ready failed for: oaGCellPattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGCellPattern",
           (PyObject*)(&PyoaGCellPattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGCellPattern\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaGCellPattern_Type.tp_dict;
    for(method=oaGCellPattern_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaGCellPatternModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGCellPatternModTypeEnum_Convert(PyObject* ob,PyParamoaGCellPatternModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGCellPatternModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGCellPatternModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGCellPatternModTypeEnum_FromoaGCellPatternModTypeEnum(oaGCellPatternModTypeEnum ob)
{

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGCellPatternModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGCellPatternModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGCellPatternModTypeEnum_FromoaGCellPatternModTypeEnum(oaGCellPatternModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGCellPatternModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGCellPatternModTypeEnum_doc[] =
"Type convert function for enum: oaGCellPatternModTypeEnum";
                               
static PyMethodDef PyoaGCellPatternModTypeEnum_method =
  {"oaGCellPatternModTypeEnum",(PyCFunction)PyoaGCellPatternModTypeEnum_TypeFunction,METH_VARARGS,oaGCellPatternModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGCellPatternModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGCellPatternModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGCellPatternModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGCellPatternModTypeEnum\n");
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
// Wrapper Implementation for Class: oaGroundedNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroundedNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroundedNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroundedNodeObject* self = (PyoaGroundedNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroundedNode)
    {
        PyParamoaGroundedNode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGroundedNode_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaGroundedNode, Choices are:\n"
        "    (oaGroundedNode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroundedNode_tp_dealloc(PyoaGroundedNodeObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroundedNode_tp_repr(PyObject *ob)
{
    PyParamoaGroundedNode value;
    int convert_status=PyoaGroundedNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaGroundedNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGroundedNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroundedNode v1;
    PyParamoaGroundedNode v2;
    int convert_status1=PyoaGroundedNode_Convert(ob1,&v1);
    int convert_status2=PyoaGroundedNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroundedNode_Convert(PyObject* ob,PyParamoaGroundedNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroundedNode_Check(ob)) {
        result->SetData( (oaGroundedNode**) ((PyoaGroundedNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroundedNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroundedNode_FromoaGroundedNode(oaGroundedNode** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaGroundedNode* data=*value;
        PyObject* bself = PyoaGroundedNode_Type.tp_alloc(&PyoaGroundedNode_Type,0);
        if (bself == NULL) return bself;
        PyoaGroundedNodeObject* self = (PyoaGroundedNodeObject*)bself;
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
PyObject* PyoaGroundedNode_FromoaGroundedNode(oaGroundedNode* data)
{
    if (data) {
       PyObject* bself = PyoaGroundedNode_Type.tp_alloc(&PyoaGroundedNode_Type,0);
       if (bself == NULL) return bself;
       PyoaGroundedNodeObject* self = (PyoaGroundedNodeObject*)bself;
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
static char oaGroundedNode_getValue_doc[] = 
"Class: oaGroundedNode, Function: getValue\n"
"  Paramegers: (oaAnalysisPoint)\n"
"    Calls: oaFloat getValue(const oaAnalysisPoint* ap) const\n"
"    Signature: getValue|simple-oaFloat|cptr-oaAnalysisPoint,\n"
"    This function gets the capacitance value of this node for a particular analysis point.\n"
"    OpenAccess assumes capacitance data is specified in Farads\n"
"    ap\n"
"    The reference analysis point to use to obtain the capacitance value\n"
;

static PyObject*
oaGroundedNode_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroundedNode data;
    int convert_status=PyoaGroundedNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroundedNodeObject* self=(PyoaGroundedNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAnalysisPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisPoint_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaFloat result= (data.DataCall()->getValue(p1.Data()));
        return PyoaFloat_FromoaFloat(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGroundedNode_setValue_doc[] = 
"Class: oaGroundedNode, Function: setValue\n"
"  Paramegers: (oaAnalysisPoint,oaFloat)\n"
"    Calls: void setValue(const oaAnalysisPoint* ap,oaFloat value)\n"
"    Signature: setValue|void-void|cptr-oaAnalysisPoint,simple-oaFloat,\n"
"    This function sets the capacitance value of this node for a particular analysis point.\n"
"    OpenAccess assumes capacitance data is specified in Farads\n"
"    ap\n"
"    The reference analysis point for which the capacitance value needs to be set\n"
"    value\n"
"    The capacitance value in Farads\n"
;

static PyObject*
oaGroundedNode_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroundedNode data;
    int convert_status=PyoaGroundedNode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroundedNodeObject* self=(PyoaGroundedNodeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAnalysisPoint p1;
    PyParamoaFloat p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaAnalysisPoint_Convert,&p1,
          &PyoaFloat_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setValue(p1.Data(),p2.Data());
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
static char oaGroundedNode_isNull_doc[] =
"Class: oaGroundedNode, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaGroundedNode_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaGroundedNode data;
    int convert_status=PyoaGroundedNode_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaGroundedNode_assign_doc[] = 
"Class: oaGroundedNode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroundedNode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroundedNode data;
  int convert_status=PyoaGroundedNode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroundedNode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroundedNode_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroundedNode_methodlist[] = {
    {"getValue",(PyCFunction)oaGroundedNode_getValue,METH_VARARGS,oaGroundedNode_getValue_doc},
    {"setValue",(PyCFunction)oaGroundedNode_setValue,METH_VARARGS,oaGroundedNode_setValue_doc},
    {"isNull",(PyCFunction)oaGroundedNode_tp_isNull,METH_VARARGS,oaGroundedNode_isNull_doc},
    {"assign",(PyCFunction)oaGroundedNode_tp_assign,METH_VARARGS,oaGroundedNode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroundedNode_doc[] = 
"Class: oaGroundedNode\n"
"  The oaGroundedNode class is used for nodes contained within an oaParasiticNetwork that include capacitance to an implicit ground. Each grounded node has one value for each analysis point that the parasitic network represents. Each value reflects the capacitance value applicable to the operating points associated with the corresponding analysis point.\n"
"Constructors:\n"
"  Paramegers: (oaGroundedNode)\n"
"    Calls: (const oaGroundedNode&)\n"
"    Signature: oaGroundedNode||cref-oaGroundedNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroundedNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroundedNode",
    sizeof(PyoaGroundedNodeObject),
    0,
    (destructor)oaGroundedNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroundedNode_tp_compare,	/* tp_compare */
    (reprfunc)oaGroundedNode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroundedNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroundedNode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNode_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroundedNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroundedNode_static_create_doc[] = 
"Class: oaGroundedNode, Function: create\n"
"  Paramegers: (oaParasiticNetwork)\n"
"    Calls: oaGroundedNode* create(oaParasiticNetwork* network)\n"
"    Signature: create|ptr-oaGroundedNode|ptr-oaParasiticNetwork,\n"
"    This function creates a grounded node belonging to the specified parasitic network. The node created does not have an ID associated with it. The hasId() function will return false for these nodes and the getId() function will return an oacInvalidNodeID value.\n"
"    network\n"
"    The parasitic network to which the created node will belong\n"
"  Paramegers: (oaParasiticNetwork,oaUInt4)\n"
"    Calls: oaGroundedNode* create(oaParasiticNetwork* network,oaUInt4 id)\n"
"    Signature: create|ptr-oaGroundedNode|ptr-oaParasiticNetwork,simple-oaUInt4,\n"
"    This function creates a grounded node belonging to the specified parasitic network. An explicit unique node ID 'id' is required to be specified. An exception will be thrown if the 'id' is the reserved oacInvalidNodeID value or if a node with the specified 'id' value already exists. The hasId() function will return true for nodes created with these functions and the getId() function will return the user-specified node id.\n"
"    network\n"
"    The parasitic network to which the created node will belong\n"
"    id\n"
"    A unique ID to be associated with the node\n"
"    oacNodeIdExists\n"
"    oacInvalidNodeIdSpecified\n"
;

static PyObject*
oaGroundedNode_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaParasiticNetwork)
    {
        PyParamoaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaParasiticNetwork_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroundedNodep result= (oaGroundedNode::create(p1.Data()));
            return PyoaGroundedNode_FromoaGroundedNode(result);
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
            oaGroundedNodep result= (oaGroundedNode::create(p1.Data(),p2.Data()));
            return PyoaGroundedNode_FromoaGroundedNode(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGroundedNode, function: create, Choices are:\n"
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
static PyMethodDef oaGroundedNode_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaGroundedNode_static_create,METH_VARARGS,oaGroundedNode_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroundedNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroundedNode_Type)<0) {
      printf("** PyType_Ready failed for: oaGroundedNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroundedNode",
           (PyObject*)(&PyoaGroundedNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroundedNode\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaGroundedNode_Type.tp_dict;
    for(method=oaGroundedNode_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroupObject* self = (PyoaGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroup)
    {
        PyParamoaGroup p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGroup_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaGroup, Choices are:\n"
        "    (oaGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroup_tp_dealloc(PyoaGroupObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroup_tp_repr(PyObject *ob)
{
    PyParamoaGroup value;
    int convert_status=PyoaGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaGroup::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[29];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaGroup::");
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
oaGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroup v1;
    PyParamoaGroup v2;
    int convert_status1=PyoaGroup_Convert(ob1,&v1);
    int convert_status2=PyoaGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroup_Convert(PyObject* ob,PyParamoaGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroup_Check(ob)) {
        result->SetData( (oaGroup**) ((PyoaGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroup_FromoaGroup(oaGroup** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaGroup* data=*value;
        PyObject* bself = PyoaGroup_Type.tp_alloc(&PyoaGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaGroupObject* self = (PyoaGroupObject*)bself;
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
PyObject* PyoaGroup_FromoaGroup(oaGroup* data)
{
    if (data) {
       PyObject* bself = PyoaGroup_Type.tp_alloc(&PyoaGroup_Type,0);
       if (bself == NULL) return bself;
       PyoaGroupObject* self = (PyoaGroupObject*)bself;
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
static char oaGroup_destroy_doc[] = 
"Class: oaGroup, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this group. All of the oaGroupMember objects in the group are destroyed as well as the group. This doesn't affect the database objects that the oaGroupMembers point to.\n"
;

static PyObject*
oaGroup_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
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
static char oaGroup_getDefaultConstraintGroup_doc[] = 
"Class: oaGroup, Function: getDefaultConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getDefaultConstraintGroup() const\n"
"    Signature: getDefaultConstraintGroup|ptr-oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    This function returns the constraint group for this oaGroup. If no constraints exist on the oaGroup, a new constraint group is created. Constraints in this constraint group apply to the objects which are members of the group.\n"
"    Todo\n"
"    Check function description.\n"
;

static PyObject*
oaGroup_getDefaultConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaConstraintGroupp result= (data.DataCall()->getDefaultConstraintGroup());
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
static char oaGroup_getDeleteWhen_doc[] = 
"Class: oaGroup, Function: getDeleteWhen\n"
"  Paramegers: ()\n"
"    Calls: oaGroupDeleteWhen getDeleteWhen() const\n"
"    Signature: getDeleteWhen|simple-oaGroupDeleteWhen|\n"
"    BrowseData: 1\n"
"    This function returns the deleteWhen attribute of this group. This attribute indicates the event, if any, that causes this group to be destroyed.\n"
;

static PyObject*
oaGroup_getDeleteWhen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupDeleteWhen* result= new oaGroupDeleteWhen(data.DataCall()->getDeleteWhen());
        return PyoaGroupDeleteWhen_FromoaGroupDeleteWhen(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGroup_getGroupDomain_doc[] = 
"Class: oaGroup, Function: getGroupDomain\n"
"  Paramegers: ()\n"
"    Calls: oaDomain getGroupDomain() const\n"
"    Signature: getGroupDomain|simple-oaDomain|\n"
"    BrowseData: 1\n"
"    This function returns the hierarchy domain that this group is restricted to. If no domain has been specified, oacNoDomain is returned.\n"
;

static PyObject*
oaGroup_getGroupDomain(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDomain* result= new oaDomain(data.DataCall()->getGroupDomain());
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
static char oaGroup_getGroupType_doc[] = 
"Class: oaGroup, Function: getGroupType\n"
"  Paramegers: ()\n"
"    Calls: oaGroupType getGroupType() const\n"
"    Signature: getGroupType|simple-oaGroupType|\n"
"    BrowseData: 1\n"
"    This function returns whether this group is a collection or a set (see oaGroupTypeEnum).\n"
;

static PyObject*
oaGroup_getGroupType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupType* result= new oaGroupType(data.DataCall()->getGroupType());
        return PyoaGroupType_FromoaGroupType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGroup_getLeader_doc[] = 
"Class: oaGroup, Function: getLeader\n"
"  Paramegers: ()\n"
"    Calls: oaGroupMember* getLeader()\n"
"    Signature: getLeader|ptr-oaGroupMember|\n"
"    BrowseData: 1\n"
"    This function returns the leader member of this group. If the group doesn't have a leader, NULL is returned.\n"
;

static PyObject*
oaGroup_getLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupMemberp result= (data.DataCall()->getLeader());
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
static char oaGroup_getMembers_doc[] = 
"Class: oaGroup, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroupMember_oaGroup getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaGroupMember_oaGroup|\n"
"    BrowseData: 1\n"
"    This function returns a collection of all the groupMembers in this group.\n"
;

static PyObject*
oaGroup_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroupMember_oaGroup* result= new oaCollection_oaGroupMember_oaGroup(data.DataCall()->getMembers());
        return PyoaCollection_oaGroupMember_oaGroup_FromoaCollection_oaGroupMember_oaGroup(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGroup_getMembersIter_doc[] = 
"Class: oaGroup, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroupMember getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaGroupMember|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of all the groupMembers in this group.\n"
;

static PyObject*
oaGroup_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaGroupMember* result= new oaIter_oaGroupMember(data.DataCall()->getMembers());
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
static char oaGroup_getName_doc[] = 
"Class: oaGroup, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this group in name .\n"
;

static PyObject*
oaGroup_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
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
static char oaGroup_getOwner_doc[] = 
"Class: oaGroup, Function: getOwner\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getOwner()\n"
"    Signature: getOwner|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the database that contains this group.\n"
;

static PyObject*
oaGroup_getOwner(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
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
static char oaGroup_hasDefaultConstraintGroup_doc[] = 
"Class: oaGroup, Function: hasDefaultConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasDefaultConstraintGroup() const\n"
"    Signature: hasDefaultConstraintGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a Boolean indicating whether there are constraints associated with this oaGroup.\n"
"    Todo\n"
"    Check function description.\n"
;

static PyObject*
oaGroup_hasDefaultConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasDefaultConstraintGroup());
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
static char oaGroup_isEmpty_doc[] = 
"Class: oaGroup, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether this group has any group members.\n"
;

static PyObject*
oaGroup_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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

// ------------------------------------------------------------------
static char oaGroup_isOrdered_doc[] = 
"Class: oaGroup, Function: isOrdered\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrdered() const\n"
"    Signature: isOrdered|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether the objects in this group are ordered.\n"
;

static PyObject*
oaGroup_isOrdered(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOrdered());
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
static char oaGroup_isUniqueName_doc[] = 
"Class: oaGroup, Function: isUniqueName\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isUniqueName() const\n"
"    Signature: isUniqueName|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether the name of this group must be unique.\n"
;

static PyObject*
oaGroup_isUniqueName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isUniqueName());
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
static char oaGroup_setDeleteWhen_doc[] = 
"Class: oaGroup, Function: setDeleteWhen\n"
"  Paramegers: (oaGroupDeleteWhen)\n"
"    Calls: void setDeleteWhen(oaGroupDeleteWhen deleteWhen)\n"
"    Signature: setDeleteWhen|void-void|simple-oaGroupDeleteWhen,\n"
"    This function sets the event type that determines when, if ever, this group will be deleted.\n"
;

static PyObject*
oaGroup_setDeleteWhen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaGroupDeleteWhen p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroupDeleteWhen_Convert,&p1)) {
        data.DataCall()->setDeleteWhen(p1.Data());
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
static char oaGroup_setGroupType_doc[] = 
"Class: oaGroup, Function: setGroupType\n"
"  Paramegers: (oaGroupType)\n"
"    Calls: void setGroupType(oaGroupType type)\n"
"    Signature: setGroupType|void-void|simple-oaGroupType,\n"
"    This function sets whether this group is a collection or a set (see oaGroupTypeEnum).\n"
"    oacInvalidGroupForSameObj\n"
;

static PyObject*
oaGroup_setGroupType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaGroupType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroupType_Convert,&p1)) {
        data.DataCall()->setGroupType(p1.Data());
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
static char oaGroup_setLeader_doc[] = 
"Class: oaGroup, Function: setLeader\n"
"  Paramegers: ()\n"
"    Calls: void setLeader()\n"
"    Signature: setLeader|void-void|ptr-oaGroupMember,\n"
"    BrowseData: 0\n"
"    This function sets the specified group member to the leader of this group. If this group already has a leader, the leader is reset. If the specified group member is already the leader of this group, this function does nothing. If NULL is specified and this group has a leader, this group is set to be leaderless.\n"
"    Note that this function moves the leader to the first group position. If you later call oaGroupMember::moveToFirst() on a member of an ordered group to move a different member in front of the leader, an exception will be thrown.\n"
"    oacInvalidGroupLeader\n"
"  Paramegers: (oaGroupMember)\n"
"    Calls: void setLeader(oaGroupMember* leader)\n"
"    Signature: setLeader|void-void|ptr-oaGroupMember,\n"
"    This function sets the specified group member to the leader of this group. If this group already has a leader, the leader is reset. If the specified group member is already the leader of this group, this function does nothing. If NULL is specified and this group has a leader, this group is set to be leaderless.\n"
"    Note that this function moves the leader to the first group position. If you later call oaGroupMember::moveToFirst() on a member of an ordered group to move a different member in front of the leader, an exception will be thrown.\n"
"    oacInvalidGroupLeader\n"
;

static PyObject*
oaGroup_setLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            data.DataCall()->setLeader();
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaGroupMember)
    {
        PyParamoaGroupMember p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaGroupMember_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->setLeader(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGroup, function: setLeader, Choices are:\n"
        "    ()\n"
        "    (oaGroupMember)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGroup_setName_doc[] = 
"Class: oaGroup, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this group to name .\n"
"    oacInvalidUniqueGroupName\n"
;

static PyObject*
oaGroup_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
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
static char oaGroup_setOrdered_doc[] = 
"Class: oaGroup, Function: setOrdered\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setOrdered(oaBoolean value)\n"
"    Signature: setOrdered|void-void|simple-oaBoolean,\n"
"    This function sets the boolean value indicating whether the objects in this group are ordered.\n"
;

static PyObject*
oaGroup_setOrdered(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setOrdered(p1.Data());
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
static char oaGroup_setUniqueName_doc[] = 
"Class: oaGroup, Function: setUniqueName\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setUniqueName(oaBoolean value)\n"
"    Signature: setUniqueName|void-void|simple-oaBoolean,\n"
"    This function sets the boolean value indicating whether the name of this group must be unique in the database that owns the group.\n"
"    oacInvalidUniqueGroupName\n"
;

static PyObject*
oaGroup_setUniqueName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupObject* self=(PyoaGroupObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setUniqueName(p1.Data());
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
static char oaGroup_isNull_doc[] =
"Class: oaGroup, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaGroup_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaGroup data;
    int convert_status=PyoaGroup_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaGroup_assign_doc[] = 
"Class: oaGroup, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroup_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroup data;
  int convert_status=PyoaGroup_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroup p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroup_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroup_methodlist[] = {
    {"destroy",(PyCFunction)oaGroup_destroy,METH_VARARGS,oaGroup_destroy_doc},
    {"getDefaultConstraintGroup",(PyCFunction)oaGroup_getDefaultConstraintGroup,METH_VARARGS,oaGroup_getDefaultConstraintGroup_doc},
    {"getDeleteWhen",(PyCFunction)oaGroup_getDeleteWhen,METH_VARARGS,oaGroup_getDeleteWhen_doc},
    {"getGroupDomain",(PyCFunction)oaGroup_getGroupDomain,METH_VARARGS,oaGroup_getGroupDomain_doc},
    {"getGroupType",(PyCFunction)oaGroup_getGroupType,METH_VARARGS,oaGroup_getGroupType_doc},
    {"getLeader",(PyCFunction)oaGroup_getLeader,METH_VARARGS,oaGroup_getLeader_doc},
    {"getMembers",(PyCFunction)oaGroup_getMembers,METH_VARARGS,oaGroup_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaGroup_getMembersIter,METH_VARARGS,oaGroup_getMembersIter_doc},
    {"getName",(PyCFunction)oaGroup_getName,METH_VARARGS,oaGroup_getName_doc},
    {"getOwner",(PyCFunction)oaGroup_getOwner,METH_VARARGS,oaGroup_getOwner_doc},
    {"hasDefaultConstraintGroup",(PyCFunction)oaGroup_hasDefaultConstraintGroup,METH_VARARGS,oaGroup_hasDefaultConstraintGroup_doc},
    {"isEmpty",(PyCFunction)oaGroup_isEmpty,METH_VARARGS,oaGroup_isEmpty_doc},
    {"isOrdered",(PyCFunction)oaGroup_isOrdered,METH_VARARGS,oaGroup_isOrdered_doc},
    {"isUniqueName",(PyCFunction)oaGroup_isUniqueName,METH_VARARGS,oaGroup_isUniqueName_doc},
    {"setDeleteWhen",(PyCFunction)oaGroup_setDeleteWhen,METH_VARARGS,oaGroup_setDeleteWhen_doc},
    {"setGroupType",(PyCFunction)oaGroup_setGroupType,METH_VARARGS,oaGroup_setGroupType_doc},
    {"setLeader",(PyCFunction)oaGroup_setLeader,METH_VARARGS,oaGroup_setLeader_doc},
    {"setName",(PyCFunction)oaGroup_setName,METH_VARARGS,oaGroup_setName_doc},
    {"setOrdered",(PyCFunction)oaGroup_setOrdered,METH_VARARGS,oaGroup_setOrdered_doc},
    {"setUniqueName",(PyCFunction)oaGroup_setUniqueName,METH_VARARGS,oaGroup_setUniqueName_doc},
    {"isNull",(PyCFunction)oaGroup_tp_isNull,METH_VARARGS,oaGroup_isNull_doc},
    {"assign",(PyCFunction)oaGroup_tp_assign,METH_VARARGS,oaGroup_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroup_doc[] = 
"Class: oaGroup\n"
"  The oaGroup class implements a general collection of database objects. This collection of objects is designated a group. Groups are associated with a specified database, and all added objects must be in the same database.\n"
"  Groups are designed specifically for applications that need to extend the data model by adding new relationships, which are usually specific to the application. An application creates a group by using the oaGroup::create function and adds objects to groups by using the oaGroupMember::create function. You can also set certain attributes to manage a group.\n"
"  An example of using a group is an application that clusters together multiple shapes and stores this relationship persistently. The application creates the group and adds the required shapes.\n"
"  All groups have a name. When you create a group, you can indicate that the group name must be unique within a given database, and you can set or reset the unique name attribute after a group is created by using the oaGroup::setUniqueName function. If a group is marked as requiring a unique name, the database validates that no other group has the same name. The database also ensures that no other group is ever assigned the same name.\n"
"  A group can be restricted to having members of a particular hierarchy domain by specifying this to the create API using the oaDomain argument. If the domain specified is oacNoDomain , then the group is not restricted; this is the same as not specifying a domain. If any other domain type is specified then all of the members of the group must be of the same domain.\n"
"  Groups can either be sets or collections as specified with the oaGroupType enum. A given object may only appear once in a set whereas an object may appear in a collection multiple times. Only sets may have leaders.\n"
"  A group of type set can optionally have a leader . A group leader can be specified when you create a group and set or reset after a group is created using the oaGroup::setLeader function. Specifying a group leader is useful when a group implements a set of objects that must be manipulated together. If an object of a group is designated the leader, other objects of the group are designated as followers . If a destroy , move , or copy operation, or an addition to or removal from an oaFigGroup are applied to an oaGroup leader, the same operation also applies to the followers--for example, if the leader is destroyed, its followers are destroyed.\n"
"  Note: The leader/follower relationship only applies to destroy, move, or copy operations, or to additions or removals from an oaFigGroup . Other operations performed on the leader do not apply to its followers.\n"
"  The members of a group can be ordered by using the oaGroup::setOrdered function. The default order of group members corresponds to the order in which they are added, with the first member added being the first in the order. You can change the order of members in an ordered group by using oaGroupMember::moveToFirst and oaGroupMember::moveAfter functions.\n"
"  Also note that oaGroup::setLeader moves its object to the first group position. If you later call oaGroupMember::moveToFirst() on a member of an ordered group to move a different member in front of the leader, an exception will be thrown.\n"
"  Groups can be constructed in oaDesign , oaTech and oaWafer databases. Any object in a given database may be placed in a group in that database except for the database itself and the following paged parasitic objects: oaDevice , oaNode , oaParasiticNetwork , and oaSubNetwork . All members of a group must be objects in the same database the group was created in.\n"
"  The database can automatically delete a group when a particular event occurs. This is controlled by the oaGroupDeleteWhen enum. You can use it to specify that the group is automatically deleted whenever any member is deleted, or when it becomes empty, or that it is never deleted automatically, only by oaGroup::destroy .\n"
"  The use of groups and other database extensions should be considered carefully. These extensions are not part of the standard OpenAccess data model and can interfere with the interoperability of tools in a flow. See the Extending the Database section of the Programmers Guide for another method of adding extensions that can be more compact and higher performance.\n"
"  The collection of groups in a given database is implemented by the getGroups function in each database class. See oaDesign::getGroups , oaDMData::getGroups , oaLib::getGroups and oaTech::getGroups .\n"
"  The oaGroup class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaGroup)\n"
"    Calls: (const oaGroup&)\n"
"    Signature: oaGroup||cref-oaGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroup",
    sizeof(PyoaGroupObject),
    0,
    (destructor)oaGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroup_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroup_static_create_doc[] = 
"Class: oaGroup, Function: create\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology database, or design library database.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to be deleted, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaGroupType)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaGroupType groupType)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology database, or design library database.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to be deleted, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaGroupType,oaBoolean)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaGroupType groupType,oaBoolean isUniqueName)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology database, or design library database.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to be deleted, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaGroupType groupType,oaBoolean isUniqueName,oaBoolean isOrdered)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology database, or design library database.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to be deleted, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaGroupType groupType,oaBoolean isUniqueName,oaBoolean isOrdered,oaGroupDeleteWhen deleteWhen)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology database, or design library database.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to be deleted, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaDomain)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaDomain domain)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaDomain,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology, or design-data database. This variant allows the specification of a hierarchy domain that the group is restricted to.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    domain\n"
"    The domain of the group. If the domain is oacNoDomain , then the membership is not restricted. Otherwise, each member of the group must be of the specified domain.\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to delete, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaDomain,oaGroupType)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaDomain domain,oaGroupType groupType)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaDomain,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology, or design-data database. This variant allows the specification of a hierarchy domain that the group is restricted to.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    domain\n"
"    The domain of the group. If the domain is oacNoDomain , then the membership is not restricted. Otherwise, each member of the group must be of the specified domain.\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to delete, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaDomain domain,oaGroupType groupType,oaBoolean isUniqueName)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaDomain,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology, or design-data database. This variant allows the specification of a hierarchy domain that the group is restricted to.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    domain\n"
"    The domain of the group. If the domain is oacNoDomain , then the membership is not restricted. Otherwise, each member of the group must be of the specified domain.\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to delete, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaDomain domain,oaGroupType groupType,oaBoolean isUniqueName,oaBoolean isOrdered)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaDomain,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology, or design-data database. This variant allows the specification of a hierarchy domain that the group is restricted to.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    domain\n"
"    The domain of the group. If the domain is oacNoDomain , then the membership is not restricted. Otherwise, each member of the group must be of the specified domain.\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to delete, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
"  Paramegers: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)\n"
"    Calls: oaGroup* create(oaObject* database,const oaString& name,oaDomain domain,oaGroupType groupType,oaBoolean isUniqueName,oaBoolean isOrdered,oaGroupDeleteWhen deleteWhen)\n"
"    Signature: create|ptr-oaGroup|ptr-oaObject,cref-oaString,simple-oaDomain,simple-oaGroupType,simple-oaBoolean,simple-oaBoolean,simple-oaGroupDeleteWhen,\n"
"    This function creates a group in the specified database , which must be a design, technology, or design-data database. This variant allows the specification of a hierarchy domain that the group is restricted to.\n"
"    database\n"
"    The design, technology, or design-data database in which to create the group\n"
"    name\n"
"    The name of the group\n"
"    domain\n"
"    The domain of the group. If the domain is oacNoDomain , then the membership is not restricted. Otherwise, each member of the group must be of the specified domain.\n"
"    groupType\n"
"    Specifies whether objects can appear in this set multiple times (see oaGroupTypeEnum).\n"
"    isUniqueName\n"
"    Specifies if the group name must be unique within the database; the default is true\n"
"    isOrdered\n"
"    Specifies if the order of objects in the group must be maintained; the default is false\n"
"    deleteWhen\n"
"    An enum that indicates the event that causes the group to delete, if ever; the default is oacNeverGroupDeleteWhen\n"
"    oacInvalidDatabase\n"
"    oacInvalidUniqueGroupName\n"
;

static PyObject*
oaGroup_static_create(PyObject* ob, PyObject *args)
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
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaGroupType)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaGroupType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaGroupType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaGroupType,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaGroupType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaGroupType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaGroupType p3;
        PyParamoaBoolean p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaGroupType_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaGroupType p3;
        PyParamoaBoolean p4;
        PyParamoaBoolean p5;
        PyParamoaGroupDeleteWhen p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaGroupType_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaGroupDeleteWhen_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaDomain)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaDomain p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDomain_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaDomain,oaGroupType)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaDomain p3;
        PyParamoaGroupType p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaGroupType_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaDomain p3;
        PyParamoaGroupType p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaGroupType_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaDomain p3;
        PyParamoaGroupType p4;
        PyParamoaBoolean p5;
        PyParamoaBoolean p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaGroupType_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaBoolean_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    // Case: (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)
    {
        PyParamoaObject p1;
        PyParamoaString p2;
        PyParamoaDomain p3;
        PyParamoaGroupType p4;
        PyParamoaBoolean p5;
        PyParamoaBoolean p6;
        PyParamoaGroupDeleteWhen p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaDomain_Convert,&p3,
              &PyoaGroupType_Convert,&p4,
              &PyoaBoolean_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaGroupDeleteWhen_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGroupp result= (oaGroup::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaGroup_FromoaGroup(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGroup, function: create, Choices are:\n"
        "    (oaObject,oaString)\n"
        "    (oaObject,oaString,oaGroupType)\n"
        "    (oaObject,oaString,oaGroupType,oaBoolean)\n"
        "    (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean)\n"
        "    (oaObject,oaString,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)\n"
        "    (oaObject,oaString,oaDomain)\n"
        "    (oaObject,oaString,oaDomain,oaGroupType)\n"
        "    (oaObject,oaString,oaDomain,oaGroupType,oaBoolean)\n"
        "    (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean)\n"
        "    (oaObject,oaString,oaDomain,oaGroupType,oaBoolean,oaBoolean,oaGroupDeleteWhen)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaGroup_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaGroup_static_create,METH_VARARGS,oaGroup_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroup",
           (PyObject*)(&PyoaGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroup\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaGroup_Type.tp_dict;
    for(method=oaGroup_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaGroupCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroupCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroupCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroupCollectionObject* self = (PyoaGroupCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaObject,oaUInt4,oaUInt4)
    {
        PyParamoaObject p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaObject_Convert,&p1,
              &PyoaUInt4_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            self->value =  new oaGroupCollection(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaGroupCollection)
    {
        PyParamoaGroupCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaGroupCollection_Convert,&p1)) {
            self->value =  new oaGroupCollection(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaGroupCollection, Choices are:\n"
        "    (oaObject,oaUInt4,oaUInt4)\n"
        "    (oaGroupCollection)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroupCollection_tp_dealloc(PyoaGroupCollectionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroupCollection_tp_repr(PyObject *ob)
{
    PyParamoaGroupCollection value;
    int convert_status=PyoaGroupCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaGroupCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGroupCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroupCollection v1;
    PyParamoaGroupCollection v2;
    int convert_status1=PyoaGroupCollection_Convert(ob1,&v1);
    int convert_status2=PyoaGroupCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroupCollection_Convert(PyObject* ob,PyParamoaGroupCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroupCollection_Check(ob)) {
        result->SetData(  ((PyoaGroupCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroupCollection_FromoaGroupCollection(oaGroupCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaGroupCollection_Type.tp_alloc(&PyoaGroupCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaGroupCollectionObject* self = (PyoaGroupCollectionObject*)bself;
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
static char oaGroupCollection_getCount_doc[] = 
"Class: oaGroupCollection, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaGroupCollection_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupCollection data;
    int convert_status=PyoaGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupCollectionObject* self=(PyoaGroupCollectionObject*)ob;

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
static char oaGroupCollection_includes_doc[] = 
"Class: oaGroupCollection, Function: includes\n"
"  Paramegers: (oaGroup)\n"
"    Calls: oaBoolean includes(const oaGroup* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaGroup,\n"
"    Function includes\n"
;

static PyObject*
oaGroupCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupCollection data;
    int convert_status=PyoaGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupCollectionObject* self=(PyoaGroupCollectionObject*)ob;

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
static char oaGroupCollection_isEmpty_doc[] = 
"Class: oaGroupCollection, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaGroupCollection_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupCollection data;
    int convert_status=PyoaGroupCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupCollectionObject* self=(PyoaGroupCollectionObject*)ob;

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

static char oaGroupCollection_assign_doc[] = 
"Class: oaGroupCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroupCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroupCollection data;
  int convert_status=PyoaGroupCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroupCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroupCollection_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroupCollection_methodlist[] = {
    {"getCount",(PyCFunction)oaGroupCollection_getCount,METH_VARARGS,oaGroupCollection_getCount_doc},
    {"includes",(PyCFunction)oaGroupCollection_includes,METH_VARARGS,oaGroupCollection_includes_doc},
    {"isEmpty",(PyCFunction)oaGroupCollection_isEmpty,METH_VARARGS,oaGroupCollection_isEmpty_doc},
    {"assign",(PyCFunction)oaGroupCollection_tp_assign,METH_VARARGS,oaGroupCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroupCollection_doc[] = 
"Class: oaGroupCollection\n"
"  Class type oaGroupCollection\n"
"Constructors:\n"
"  Paramegers: (oaObject,oaUInt4,oaUInt4)\n"
"    Calls: oaGroupCollection(const oaObject* database,oaUInt4 domainFlags,oaUInt4 nameIndexIn)\n"
"    Signature: oaGroupCollection||cptr-oaObject,simple-oaUInt4,simple-oaUInt4,\n"
"    Constructor oaGroupCollection\n"
"  Paramegers: (oaGroupCollection)\n"
"    Calls: oaGroupCollection(const oaGroupCollection& c)\n"
"    Signature: oaGroupCollection||cref-oaGroupCollection,\n"
"    Constructor oaGroupCollection\n"
"  Paramegers: (oaGroupCollection)\n"
"    Calls: (const oaGroupCollection&)\n"
"    Signature: oaGroupCollection||cref-oaGroupCollection,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroupCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroupCollection",
    sizeof(PyoaGroupCollectionObject),
    0,
    (destructor)oaGroupCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroupCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaGroupCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroupCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroupCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroupCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroupCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroupCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaGroupCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroupCollection",
           (PyObject*)(&PyoaGroupCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroupCollection\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaGroupDeleteWhen
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroupDeleteWhen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroupDeleteWhen_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroupDeleteWhenObject* self = (PyoaGroupDeleteWhenObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroupDeleteWhenEnum)
    {
        PyParamoaGroupDeleteWhenEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaGroupDeleteWhenEnum_Convert,&p1)) {
            self->value =  new oaGroupDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaGroupDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaGroupDeleteWhen)
    {
        PyParamoaGroupDeleteWhen p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGroupDeleteWhen_Convert,&p1)) {
            self->value= new oaGroupDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaGroupDeleteWhen, Choices are:\n"
        "    (oaGroupDeleteWhenEnum)\n"
        "    (oaString)\n"
        "    (oaGroupDeleteWhen)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroupDeleteWhen_tp_dealloc(PyoaGroupDeleteWhenObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroupDeleteWhen_tp_repr(PyObject *ob)
{
    PyParamoaGroupDeleteWhen value;
    int convert_status=PyoaGroupDeleteWhen_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[39];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaGroupDeleteWhen::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGroupDeleteWhen_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroupDeleteWhen v1;
    PyParamoaGroupDeleteWhen v2;
    int convert_status1=PyoaGroupDeleteWhen_Convert(ob1,&v1);
    int convert_status2=PyoaGroupDeleteWhen_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroupDeleteWhen_Convert(PyObject* ob,PyParamoaGroupDeleteWhen* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroupDeleteWhen_Check(ob)) {
        result->SetData(  ((PyoaGroupDeleteWhenObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupDeleteWhen Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroupDeleteWhen_FromoaGroupDeleteWhen(oaGroupDeleteWhen* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaGroupDeleteWhen_Type.tp_alloc(&PyoaGroupDeleteWhen_Type,0);
        if (bself == NULL) return bself;
        PyoaGroupDeleteWhenObject* self = (PyoaGroupDeleteWhenObject*)bself;
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
static char oaGroupDeleteWhen_getName_doc[] = 
"Class: oaGroupDeleteWhen, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaGroupDeleteWhenEnum object.\n"
;

static PyObject*
oaGroupDeleteWhen_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupDeleteWhen data;
    int convert_status=PyoaGroupDeleteWhen_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupDeleteWhenObject* self=(PyoaGroupDeleteWhenObject*)ob;

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
static char oaGroupDeleteWhen_oaGroupDeleteWhenEnum_doc[] = 
"Class: oaGroupDeleteWhen, Function: oaGroupDeleteWhenEnum\n"
"  Paramegers: ()\n"
"    Calls: oaGroupDeleteWhenEnum oaGroupDeleteWhenEnum() const\n"
"    Signature: operator oaGroupDeleteWhenEnum|simple-oaGroupDeleteWhenEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaGroupDeleteWhen object into the corresponding #oaGroupDeleteWhenEnum value.\n"
;

static PyObject*
oaGroupDeleteWhen_oaGroupDeleteWhenEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupDeleteWhen data;
    int convert_status=PyoaGroupDeleteWhen_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupDeleteWhenObject* self=(PyoaGroupDeleteWhenObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupDeleteWhenEnum result= (data.DataCall()->operator oaGroupDeleteWhenEnum());
        return PyoaGroupDeleteWhenEnum_FromoaGroupDeleteWhenEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaGroupDeleteWhen_assign_doc[] = 
"Class: oaGroupDeleteWhen, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroupDeleteWhen_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroupDeleteWhen data;
  int convert_status=PyoaGroupDeleteWhen_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroupDeleteWhen p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroupDeleteWhen_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroupDeleteWhen_methodlist[] = {
    {"getName",(PyCFunction)oaGroupDeleteWhen_getName,METH_VARARGS,oaGroupDeleteWhen_getName_doc},
    {"oaGroupDeleteWhenEnum",(PyCFunction)oaGroupDeleteWhen_oaGroupDeleteWhenEnum,METH_VARARGS,oaGroupDeleteWhen_oaGroupDeleteWhenEnum_doc},
    {"assign",(PyCFunction)oaGroupDeleteWhen_tp_assign,METH_VARARGS,oaGroupDeleteWhen_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroupDeleteWhen_doc[] = 
"Class: oaGroupDeleteWhen\n"
"  The oaGroupDeleteWhen class is an enum wrapper that indicates the condition on which OpenAccess will automatically delete an oaGroup object. See oaGroup::setDeleteWhen for its usage. See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaGroupDeleteWhenEnum\n"
"Constructors:\n"
"  Paramegers: (oaGroupDeleteWhenEnum)\n"
"    Calls: oaGroupDeleteWhen(oaGroupDeleteWhenEnum valueIn)\n"
"    Signature: oaGroupDeleteWhen||simple-oaGroupDeleteWhenEnum,\n"
"    This function constructs an instance of an oaGroupDeleteWhen class using the specified #oaGroupDeleteWhenEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaGroupDeleteWhen(const oaString& name)\n"
"    Signature: oaGroupDeleteWhen||cref-oaString,\n"
"    This function constructs an instance of an oaGroupDeleteWhen class using the #oaGroupDeleteWhenEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaGroupDeleteWhenEnum.\n"
"    oacInvalidGroupDeleteWhenTypeName\n"
"  Paramegers: (oaGroupDeleteWhen)\n"
"    Calls: (const oaGroupDeleteWhen&)\n"
"    Signature: oaGroupDeleteWhen||cref-oaGroupDeleteWhen,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroupDeleteWhen_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroupDeleteWhen",
    sizeof(PyoaGroupDeleteWhenObject),
    0,
    (destructor)oaGroupDeleteWhen_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroupDeleteWhen_tp_compare,	/* tp_compare */
    (reprfunc)oaGroupDeleteWhen_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroupDeleteWhen_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroupDeleteWhen_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroupDeleteWhen_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroupDeleteWhen_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroupDeleteWhen_Type)<0) {
      printf("** PyType_Ready failed for: oaGroupDeleteWhen\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroupDeleteWhen",
           (PyObject*)(&PyoaGroupDeleteWhen_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroupDeleteWhen\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaGroupDeleteWhenEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGroupDeleteWhenEnum_Convert(PyObject* ob,PyParamoaGroupDeleteWhenEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNeverGroupDeleteWhen")==0) { result->SetData(oacNeverGroupDeleteWhen); return 1;}
        if (strcasecmp(str,"oacOnFirstGroupDeleteWhen")==0) { result->SetData(oacOnFirstGroupDeleteWhen); return 1;}
        if (strcasecmp(str,"oacOnLastGroupDeleteWhen")==0) { result->SetData(oacOnLastGroupDeleteWhen); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGroupDeleteWhenEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupDeleteWhenEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGroupDeleteWhenEnum_FromoaGroupDeleteWhenEnum(oaGroupDeleteWhenEnum ob)
{
    if (ob==oacNeverGroupDeleteWhen) return PyString_FromString("oacNeverGroupDeleteWhen");
    if (ob==oacOnFirstGroupDeleteWhen) return PyString_FromString("oacOnFirstGroupDeleteWhen");
    if (ob==oacOnLastGroupDeleteWhen) return PyString_FromString("oacOnLastGroupDeleteWhen");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGroupDeleteWhenEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGroupDeleteWhenEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGroupDeleteWhenEnum_FromoaGroupDeleteWhenEnum(oaGroupDeleteWhenEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGroupDeleteWhenEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGroupDeleteWhenEnum_doc[] =
"Type convert function for enum: oaGroupDeleteWhenEnum";
                               
static PyMethodDef PyoaGroupDeleteWhenEnum_method =
  {"oaGroupDeleteWhenEnum",(PyCFunction)PyoaGroupDeleteWhenEnum_TypeFunction,METH_VARARGS,oaGroupDeleteWhenEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGroupDeleteWhenEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNeverGroupDeleteWhen");
    PyDict_SetItemString(mod_dict,"oacNeverGroupDeleteWhen",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOnFirstGroupDeleteWhen");
    PyDict_SetItemString(mod_dict,"oacOnFirstGroupDeleteWhen",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOnLastGroupDeleteWhen");
    PyDict_SetItemString(mod_dict,"oacOnLastGroupDeleteWhen",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGroupDeleteWhenEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGroupDeleteWhenEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGroupDeleteWhenEnum\n");
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
// Wrapper Implementation for Class: oaGroupMember
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroupMember_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroupMember_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroupMemberObject* self = (PyoaGroupMemberObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroupMember)
    {
        PyParamoaGroupMember p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGroupMember_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaGroupMember, Choices are:\n"
        "    (oaGroupMember)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroupMember_tp_dealloc(PyoaGroupMemberObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroupMember_tp_repr(PyObject *ob)
{
    PyParamoaGroupMember value;
    int convert_status=PyoaGroupMember_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaGroupMember::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGroupMember_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroupMember v1;
    PyParamoaGroupMember v2;
    int convert_status1=PyoaGroupMember_Convert(ob1,&v1);
    int convert_status2=PyoaGroupMember_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroupMember_Convert(PyObject* ob,PyParamoaGroupMember* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroupMember_Check(ob)) {
        result->SetData( (oaGroupMember**) ((PyoaGroupMemberObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupMember Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroupMember_FromoaGroupMember(oaGroupMember** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaGroupMember* data=*value;
        PyObject* bself = PyoaGroupMember_Type.tp_alloc(&PyoaGroupMember_Type,0);
        if (bself == NULL) return bself;
        PyoaGroupMemberObject* self = (PyoaGroupMemberObject*)bself;
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
PyObject* PyoaGroupMember_FromoaGroupMember(oaGroupMember* data)
{
    if (data) {
       PyObject* bself = PyoaGroupMember_Type.tp_alloc(&PyoaGroupMember_Type,0);
       if (bself == NULL) return bself;
       PyoaGroupMemberObject* self = (PyoaGroupMemberObject*)bself;
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
static char oaGroupMember_destroy_doc[] = 
"Class: oaGroupMember, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this object from the given group and destroys this oaGroupMember object. The deleteWhen property of the related group is also checked to determine if the group itself should also be destroyed. If it is a deleteFirst type group, it is destroyed. If it is a deleteLast type group, it is destroyed only if this group member is the last one in the group.\n"
;

static PyObject*
oaGroupMember_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
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
static char oaGroupMember_getGroup_doc[] = 
"Class: oaGroupMember, Function: getGroup\n"
"  Paramegers: ()\n"
"    Calls: oaGroup* getGroup()\n"
"    Signature: getGroup|ptr-oaGroup|\n"
"    BrowseData: 1\n"
"    This function returns the group of which owns this group member.\n"
;

static PyObject*
oaGroupMember_getGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupp result= (data.DataCall()->getGroup());
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
static char oaGroupMember_getObject_doc[] = 
"Class: oaGroupMember, Function: getObject\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getObject()\n"
"    Signature: getObject|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns the object that is referred by this group member.\n"
;

static PyObject*
oaGroupMember_getObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
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
static char oaGroupMember_isLeader_doc[] = 
"Class: oaGroupMember, Function: isLeader\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isLeader()\n"
"    Signature: isLeader|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether this group member is the leader of the group.\n"
;

static PyObject*
oaGroupMember_isLeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
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
static char oaGroupMember_moveAfter_doc[] = 
"Class: oaGroupMember, Function: moveAfter\n"
"  Paramegers: (oaGroupMember)\n"
"    Calls: void moveAfter(oaGroupMember* member)\n"
"    Signature: moveAfter|void-void|ptr-oaGroupMember,\n"
"    This function moves this group member in an ordered group to the position behind the specified group member in the same group. If these two group members are the same, this function has no effect.\n"
"    If you attempt to move the group leader after another member, an oacInvalidMoveLeader exception will be thrown.\n"
"    If this object and member are not in the same group, an oacInvalidGroupForMemberMove exception will be thrown.\n"
"    if the group to which this object belongs is not an ordered group, an oacInvalidGroupTypeForMemberMove exception will be thrown.\n"
"    member\n"
"    The group member to move this groupMember after\n"
"    oacInvalidMoveLeader\n"
"    oacInvalidGroupForMemberMove\n"
"    oacInvalidGroupTypeForMemberMove\n"
;

static PyObject*
oaGroupMember_moveAfter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaGroupMember p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGroupMember_Convert,&p1)) {
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
static char oaGroupMember_moveToFirst_doc[] = 
"Class: oaGroupMember, Function: moveToFirst\n"
"  Paramegers: ()\n"
"    Calls: void moveToFirst()\n"
"    Signature: moveToFirst|void-void|\n"
"    BrowseData: 0\n"
"    This function attempts to move this group member in an ordered group to the first group member in its group. The current first group member is moved to the second, and so on with the following group members.\n"
"    If you attempt to move a group member in front of the group leader, an oacInvalidMoveLeader exception will be thrown.\n"
"    If the group to which this object belongs is not an ordered group, an oacInvalidGroupTypeForMemberMove exception will be thrown.\n"
"    oacInvalidMoveLeader\n"
"    oacInvalidGroupTypeForMemberMove\n"
;

static PyObject*
oaGroupMember_moveToFirst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupMemberObject* self=(PyoaGroupMemberObject*)ob;
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
static char oaGroupMember_isNull_doc[] =
"Class: oaGroupMember, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaGroupMember_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaGroupMember data;
    int convert_status=PyoaGroupMember_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaGroupMember_assign_doc[] = 
"Class: oaGroupMember, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroupMember_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroupMember data;
  int convert_status=PyoaGroupMember_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroupMember p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroupMember_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroupMember_methodlist[] = {
    {"destroy",(PyCFunction)oaGroupMember_destroy,METH_VARARGS,oaGroupMember_destroy_doc},
    {"getGroup",(PyCFunction)oaGroupMember_getGroup,METH_VARARGS,oaGroupMember_getGroup_doc},
    {"getObject",(PyCFunction)oaGroupMember_getObject,METH_VARARGS,oaGroupMember_getObject_doc},
    {"isLeader",(PyCFunction)oaGroupMember_isLeader,METH_VARARGS,oaGroupMember_isLeader_doc},
    {"moveAfter",(PyCFunction)oaGroupMember_moveAfter,METH_VARARGS,oaGroupMember_moveAfter_doc},
    {"moveToFirst",(PyCFunction)oaGroupMember_moveToFirst,METH_VARARGS,oaGroupMember_moveToFirst_doc},
    {"isNull",(PyCFunction)oaGroupMember_tp_isNull,METH_VARARGS,oaGroupMember_isNull_doc},
    {"assign",(PyCFunction)oaGroupMember_tp_assign,METH_VARARGS,oaGroupMember_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroupMember_doc[] = 
"Class: oaGroupMember\n"
"  The oaGroupMember class implements group member objects. A group member object represents a relationship between a database object and a group.\n"
"  This class represents the membership of a database object in a group. You can place most objects in a group or even another group, as long as they reside in the same database as the containing group. However, database classes ( oaDesign , oaTech , oaDDObjectDB) cannot be group members and the paged parasitic objects cannot be included in a group. See oaGroup for more information.\n"
"  A group can have a hierarchy domain specified when it is created. In this case, each member added to the group must be of the same domain as the group. If the group domain is unspecified, or if it is oacNoDomain , then members of any domain can be added to the group. See oaGroup and oaDomain for more information.\n"
"  A collection of all the oaGroupMembers in a group is returned by oaGroup :getMembers and a collection of all the oaGroupMembers that include a given object is returned by oaObject::getGroupMems .\n"
"  An instance of oaGroupMember is automatically destroyed when either the object it references or the group that owns it is destroyed.\n"
"  The oaGroupMember class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaGroupMember)\n"
"    Calls: (const oaGroupMember&)\n"
"    Signature: oaGroupMember||cref-oaGroupMember,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroupMember_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroupMember",
    sizeof(PyoaGroupMemberObject),
    0,
    (destructor)oaGroupMember_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroupMember_tp_compare,	/* tp_compare */
    (reprfunc)oaGroupMember_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroupMember_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroupMember_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroupMember_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroupMember_static_create_doc[] = 
"Class: oaGroupMember, Function: create\n"
"  Paramegers: (oaGroup,oaObject)\n"
"    Calls: oaGroupMember* create(oaGroup* group,oaObject* object)\n"
"    Signature: create|ptr-oaGroupMember|ptr-oaGroup,ptr-oaObject,simple-oaBoolean,\n"
"    This function creates a group member for the specified object in the specified group. The object and the group must be in the same database. The object must also be in the same domain as the group if the group is restricted by domain. It is possible to specify this group member as the leader of the group if the group was created with the type oacSetGroupType and if it does not currently have a leader.\n"
"    If the created group member is a leader, it becomes the first group member; otherwise, the created member becomes the last group member.\n"
"    You can change the order of members in an ordered group by using oaGroupMember::moveToFirst and oaGroupMember::moveAfter functions. If you later call oaGroupMember::moveToFirst() to move a different member in front of the leader, an exception will be thrown.\n"
"    group\n"
"    The group to which this group member belongs\n"
"    object\n"
"    The object to include in the specified group\n"
"    isLeader\n"
"    Specifies if this group member is set as the leader of the specified group; the default is false\n"
"    oacGroupMemberNotInSameDB\n"
"    oacGroupMemberNotInDomain\n"
"    oacInvalidGroupForSameObj\n"
"    oacInvalidGroupForLeader\n"
"    oacInvalidGroupLeader\n"
"    oacInvalidGroupObject\n"
"    oacInvalidObjForGroup\n"
"    oacMismatchDatabaseID\n"
"    oacMultipleGroupLeader\n"
"  Paramegers: (oaGroup,oaObject,oaBoolean)\n"
"    Calls: oaGroupMember* create(oaGroup* group,oaObject* object,oaBoolean isLeader)\n"
"    Signature: create|ptr-oaGroupMember|ptr-oaGroup,ptr-oaObject,simple-oaBoolean,\n"
"    This function creates a group member for the specified object in the specified group. The object and the group must be in the same database. The object must also be in the same domain as the group if the group is restricted by domain. It is possible to specify this group member as the leader of the group if the group was created with the type oacSetGroupType and if it does not currently have a leader.\n"
"    If the created group member is a leader, it becomes the first group member; otherwise, the created member becomes the last group member.\n"
"    You can change the order of members in an ordered group by using oaGroupMember::moveToFirst and oaGroupMember::moveAfter functions. If you later call oaGroupMember::moveToFirst() to move a different member in front of the leader, an exception will be thrown.\n"
"    group\n"
"    The group to which this group member belongs\n"
"    object\n"
"    The object to include in the specified group\n"
"    isLeader\n"
"    Specifies if this group member is set as the leader of the specified group; the default is false\n"
"    oacGroupMemberNotInSameDB\n"
"    oacGroupMemberNotInDomain\n"
"    oacInvalidGroupForSameObj\n"
"    oacInvalidGroupForLeader\n"
"    oacInvalidGroupLeader\n"
"    oacInvalidGroupObject\n"
"    oacInvalidObjForGroup\n"
"    oacMismatchDatabaseID\n"
"    oacMultipleGroupLeader\n"
;

static PyObject*
oaGroupMember_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaGroup,oaObject)
    {
        PyParamoaGroup p1;
        PyParamoaObject p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaGroup_Convert,&p1,
              &PyoaObject_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaGroupMemberp result= (oaGroupMember::create(p1.Data(),p2.Data()));
            return PyoaGroupMember_FromoaGroupMember(result);
        }
    }
    PyErr_Clear();
    // Case: (oaGroup,oaObject,oaBoolean)
    {
        PyParamoaGroup p1;
        PyParamoaObject p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaGroup_Convert,&p1,
              &PyoaObject_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaGroupMemberp result= (oaGroupMember::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaGroupMember_FromoaGroupMember(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGroupMember, function: create, Choices are:\n"
        "    (oaGroup,oaObject)\n"
        "    (oaGroup,oaObject,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaGroupMember_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaGroupMember_static_create,METH_VARARGS,oaGroupMember_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroupMember_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroupMember_Type)<0) {
      printf("** PyType_Ready failed for: oaGroupMember\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroupMember",
           (PyObject*)(&PyoaGroupMember_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroupMember\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaGroupMember_Type.tp_dict;
    for(method=oaGroupMember_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaGroupMemberModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGroupMemberModTypeEnum_Convert(PyObject* ob,PyParamoaGroupMemberModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetLeaderGroupMemberModType")==0) { result->SetData(oacSetLeaderGroupMemberModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGroupMemberModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupMemberModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGroupMemberModTypeEnum_FromoaGroupMemberModTypeEnum(oaGroupMemberModTypeEnum ob)
{
    if (ob==oacSetLeaderGroupMemberModType) return PyString_FromString("oacSetLeaderGroupMemberModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGroupMemberModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGroupMemberModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGroupMemberModTypeEnum_FromoaGroupMemberModTypeEnum(oaGroupMemberModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGroupMemberModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGroupMemberModTypeEnum_doc[] =
"Type convert function for enum: oaGroupMemberModTypeEnum";
                               
static PyMethodDef PyoaGroupMemberModTypeEnum_method =
  {"oaGroupMemberModTypeEnum",(PyCFunction)PyoaGroupMemberModTypeEnum_TypeFunction,METH_VARARGS,oaGroupMemberModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGroupMemberModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetLeaderGroupMemberModType");
    PyDict_SetItemString(mod_dict,"oacSetLeaderGroupMemberModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGroupMemberModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGroupMemberModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGroupMemberModTypeEnum\n");
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
// Wrapper Implementation for Class: oaGroupModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGroupModTypeEnum_Convert(PyObject* ob,PyParamoaGroupModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameGroupModType")==0) { result->SetData(oacSetNameGroupModType); return 1;}
        if (strcasecmp(str,"oacSetGroupTypeGroupModType")==0) { result->SetData(oacSetGroupTypeGroupModType); return 1;}
        if (strcasecmp(str,"oacSetDeleteWhenGroupModType")==0) { result->SetData(oacSetDeleteWhenGroupModType); return 1;}
        if (strcasecmp(str,"oacSetUniqueNameGroupModType")==0) { result->SetData(oacSetUniqueNameGroupModType); return 1;}
        if (strcasecmp(str,"oacSetOrderedGroupModType")==0) { result->SetData(oacSetOrderedGroupModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGroupModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGroupModTypeEnum_FromoaGroupModTypeEnum(oaGroupModTypeEnum ob)
{
    if (ob==oacSetNameGroupModType) return PyString_FromString("oacSetNameGroupModType");
    if (ob==oacSetGroupTypeGroupModType) return PyString_FromString("oacSetGroupTypeGroupModType");
    if (ob==oacSetDeleteWhenGroupModType) return PyString_FromString("oacSetDeleteWhenGroupModType");
    if (ob==oacSetUniqueNameGroupModType) return PyString_FromString("oacSetUniqueNameGroupModType");
    if (ob==oacSetOrderedGroupModType) return PyString_FromString("oacSetOrderedGroupModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGroupModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGroupModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGroupModTypeEnum_FromoaGroupModTypeEnum(oaGroupModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGroupModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGroupModTypeEnum_doc[] =
"Type convert function for enum: oaGroupModTypeEnum";
                               
static PyMethodDef PyoaGroupModTypeEnum_method =
  {"oaGroupModTypeEnum",(PyCFunction)PyoaGroupModTypeEnum_TypeFunction,METH_VARARGS,oaGroupModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGroupModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameGroupModType");
    PyDict_SetItemString(mod_dict,"oacSetNameGroupModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetGroupTypeGroupModType");
    PyDict_SetItemString(mod_dict,"oacSetGroupTypeGroupModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetDeleteWhenGroupModType");
    PyDict_SetItemString(mod_dict,"oacSetDeleteWhenGroupModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetUniqueNameGroupModType");
    PyDict_SetItemString(mod_dict,"oacSetUniqueNameGroupModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetOrderedGroupModType");
    PyDict_SetItemString(mod_dict,"oacSetOrderedGroupModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGroupModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGroupModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGroupModTypeEnum\n");
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
// Wrapper Implementation for Class: oaGroupType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGroupType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGroupType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGroupTypeObject* self = (PyoaGroupTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGroupTypeEnum)
    {
        PyParamoaGroupTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaGroupTypeEnum_Convert,&p1)) {
            self->value =  new oaGroupType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaGroupType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaGroupType)
    {
        PyParamoaGroupType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGroupType_Convert,&p1)) {
            self->value= new oaGroupType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaGroupType, Choices are:\n"
        "    (oaGroupTypeEnum)\n"
        "    (oaString)\n"
        "    (oaGroupType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGroupType_tp_dealloc(PyoaGroupTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGroupType_tp_repr(PyObject *ob)
{
    PyParamoaGroupType value;
    int convert_status=PyoaGroupType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[33];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaGroupType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGroupType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGroupType v1;
    PyParamoaGroupType v2;
    int convert_status1=PyoaGroupType_Convert(ob1,&v1);
    int convert_status2=PyoaGroupType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGroupType_Convert(PyObject* ob,PyParamoaGroupType* result)
{
    if (ob == NULL) return 1;
    if (PyoaGroupType_Check(ob)) {
        result->SetData(  ((PyoaGroupTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGroupType_FromoaGroupType(oaGroupType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaGroupType_Type.tp_alloc(&PyoaGroupType_Type,0);
        if (bself == NULL) return bself;
        PyoaGroupTypeObject* self = (PyoaGroupTypeObject*)bself;
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
static char oaGroupType_getName_doc[] = 
"Class: oaGroupType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaGroupTypeEnum object.\n"
;

static PyObject*
oaGroupType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupType data;
    int convert_status=PyoaGroupType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupTypeObject* self=(PyoaGroupTypeObject*)ob;

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
static char oaGroupType_oaGroupTypeEnum_doc[] = 
"Class: oaGroupType, Function: oaGroupTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaGroupTypeEnum oaGroupTypeEnum() const\n"
"    Signature: operator oaGroupTypeEnum|simple-oaGroupTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaGroupType into the corresponding #oaGroupTypeEnum value.\n"
;

static PyObject*
oaGroupType_oaGroupTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGroupType data;
    int convert_status=PyoaGroupType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGroupTypeObject* self=(PyoaGroupTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaGroupTypeEnum result= (data.DataCall()->operator oaGroupTypeEnum());
        return PyoaGroupTypeEnum_FromoaGroupTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaGroupType_assign_doc[] = 
"Class: oaGroupType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGroupType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGroupType data;
  int convert_status=PyoaGroupType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGroupType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGroupType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGroupType_methodlist[] = {
    {"getName",(PyCFunction)oaGroupType_getName,METH_VARARGS,oaGroupType_getName_doc},
    {"oaGroupTypeEnum",(PyCFunction)oaGroupType_oaGroupTypeEnum,METH_VARARGS,oaGroupType_oaGroupTypeEnum_doc},
    {"assign",(PyCFunction)oaGroupType_tp_assign,METH_VARARGS,oaGroupType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGroupType_doc[] = 
"Class: oaGroupType\n"
"  The oaGroupType class is an enum wrapper that indicates if an oaGroup object is a collection or a set. An object may occur more than once in a collection, but only once in a set (see oaGroup for additional information).\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaGroupTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaGroupTypeEnum)\n"
"    Calls: oaGroupType(oaGroupTypeEnum valueIn)\n"
"    Signature: oaGroupType||simple-oaGroupTypeEnum,\n"
"    This function constructs an instance of an oaGroupType class using the specified #oaGroupTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaGroupType(const oaString& name)\n"
"    Signature: oaGroupType||cref-oaString,\n"
"    This function constructs an instance of an oaGroupType class using the #oaGroupTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaGroupTypeEnum.\n"
"    oacInvalidGroupTypeName\n"
"  Paramegers: (oaGroupType)\n"
"    Calls: (const oaGroupType&)\n"
"    Signature: oaGroupType||cref-oaGroupType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGroupType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGroupType",
    sizeof(PyoaGroupTypeObject),
    0,
    (destructor)oaGroupType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGroupType_tp_compare,	/* tp_compare */
    (reprfunc)oaGroupType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGroupType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGroupType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGroupType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGroupType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGroupType_Type)<0) {
      printf("** PyType_Ready failed for: oaGroupType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGroupType",
           (PyObject*)(&PyoaGroupType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGroupType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaGroupTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGroupTypeEnum_Convert(PyObject* ob,PyParamoaGroupTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacCollectionGroupType")==0) { result->SetData(oacCollectionGroupType); return 1;}
        if (strcasecmp(str,"oacSetGroupType")==0) { result->SetData(oacSetGroupType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGroupTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGroupTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGroupTypeEnum_FromoaGroupTypeEnum(oaGroupTypeEnum ob)
{
    if (ob==oacCollectionGroupType) return PyString_FromString("oacCollectionGroupType");
    if (ob==oacSetGroupType) return PyString_FromString("oacSetGroupType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGroupTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGroupTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGroupTypeEnum_FromoaGroupTypeEnum(oaGroupTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGroupTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGroupTypeEnum_doc[] =
"Type convert function for enum: oaGroupTypeEnum";
                               
static PyMethodDef PyoaGroupTypeEnum_method =
  {"oaGroupTypeEnum",(PyCFunction)PyoaGroupTypeEnum_TypeFunction,METH_VARARGS,oaGroupTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGroupTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacCollectionGroupType");
    PyDict_SetItemString(mod_dict,"oacCollectionGroupType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetGroupType");
    PyDict_SetItemString(mod_dict,"oacSetGroupType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGroupTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGroupTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGroupTypeEnum\n");
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
// Wrapper Implementation for Class: oaGuide
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGuide_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGuide_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGuideObject* self = (PyoaGuideObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaGuide)
    {
        PyParamoaGuide p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaGuide_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaGuide, Choices are:\n"
        "    (oaGuide)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGuide_tp_dealloc(PyoaGuideObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGuide_tp_repr(PyObject *ob)
{
    PyParamoaGuide value;
    int convert_status=PyoaGuide_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaGuide::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGuide_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGuide v1;
    PyParamoaGuide v2;
    int convert_status1=PyoaGuide_Convert(ob1,&v1);
    int convert_status2=PyoaGuide_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGuide_Convert(PyObject* ob,PyParamoaGuide* result)
{
    if (ob == NULL) return 1;
    if (PyoaGuide_Check(ob)) {
        result->SetData( (oaGuide**) ((PyoaGuideObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGuide Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGuide_FromoaGuide(oaGuide** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaGuide* data=*value;
        PyObject* bself = PyoaGuide_Type.tp_alloc(&PyoaGuide_Type,0);
        if (bself == NULL) return bself;
        PyoaGuideObject* self = (PyoaGuideObject*)bself;
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
PyObject* PyoaGuide_FromoaGuide(oaGuide* data)
{
    if (data) {
       PyObject* bself = PyoaGuide_Type.tp_alloc(&PyoaGuide_Type,0);
       if (bself == NULL) return bself;
       PyoaGuideObject* self = (PyoaGuideObject*)bself;
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
static char oaGuide_followLayers_doc[] = 
"Class: oaGuide, Function: followLayers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean followLayers() const\n"
"    Signature: followLayers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether the layers specified must be followed when attempting to replace this guide with physical routing.\n"
;

static PyObject*
oaGuide_followLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->followLayers());
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
static char oaGuide_getBeginLayerHeader_doc[] = 
"Class: oaGuide, Function: getBeginLayerHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getBeginLayerHeader() const\n"
"    Signature: getBeginLayerHeader|ptr-oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layerHeader for the begin layer of this guide. If there is no specific begin layer associated with this guide, a NULL is returned.\n"
;

static PyObject*
oaGuide_getBeginLayerHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getBeginLayerHeader());
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
static char oaGuide_getBeginLayerNum_doc[] = 
"Class: oaGuide, Function: getBeginLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getBeginLayerNum() const\n"
"    Signature: getBeginLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number where this guide begins. If one hasn't been specified then an oacAnyLayerNum value is returned.\n"
;

static PyObject*
oaGuide_getBeginLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getBeginLayerNum());
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
static char oaGuide_getEndLayerHeader_doc[] = 
"Class: oaGuide, Function: getEndLayerHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLayerHeader* getEndLayerHeader() const\n"
"    Signature: getEndLayerHeader|ptr-oaLayerHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layerHeader for the end layer of this guide. If there is no specific end layer associated with this guide, a NULL is returned.\n"
;

static PyObject*
oaGuide_getEndLayerHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerHeaderp result= (data.DataCall()->getEndLayerHeader());
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
static char oaGuide_getEndLayerNum_doc[] = 
"Class: oaGuide, Function: getEndLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getEndLayerNum() const\n"
"    Signature: getEndLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the end layer number of this guide. If one hasn't been specified then an oacAnyLayerNumValue is returned.\n"
;

static PyObject*
oaGuide_getEndLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getEndLayerNum());
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
static char oaGuide_getPoints_doc[] = 
"Class: oaGuide, Function: getPoints\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: void getPoints(oaPoint& beginPoint,oaPoint& endPoint) const\n"
"    Signature: getPoints|void-void|ref-oaPoint,ref-oaPoint,\n"
"    BrowseData: 0,oaPoint,oaPoint\n"
"    This function returns the begin and end points for this guide in the given oaPoint parameters.\n"
"    beginPoint\n"
"    The begin point is returned in this parameter\n"
"    endPoint\n"
"    The end point is returned in this parameter\n"
;

static PyObject*
oaGuide_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    PyParamoaPoint p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaPoint_Convert,&p1,
          &PyoaPoint_Convert,&p2)) {
        data.DataCall()->getPoints(p1.Data(),p2.Data());
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
static char oaGuide_getRoute_doc[] = 
"Class: oaGuide, Function: getRoute\n"
"  Paramegers: ()\n"
"    Calls: oaRoute* getRoute() const\n"
"    Signature: getRoute|ptr-oaRoute|\n"
"    BrowseData: 1\n"
"    This function returns the route this guide is attached to. If this guide is not attached to a route, NULL is returned.\n"
;

static PyObject*
oaGuide_getRoute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRoutep result= (data.DataCall()->getRoute());
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
static char oaGuide_hasRoute_doc[] = 
"Class: oaGuide, Function: hasRoute\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasRoute() const\n"
"    Signature: hasRoute|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this guide belongs to a route. true is returned if the guide belongs to a route; false otherwise.\n"
;

static PyObject*
oaGuide_hasRoute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasRoute());
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
static char oaGuide_setBeginLayerNum_doc[] = 
"Class: oaGuide, Function: setBeginLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setBeginLayerNum(oaLayerNum layer)\n"
"    Signature: setBeginLayerNum|void-void|simple-oaLayerNum,\n"
"    This function changes the begin layer for this guide.\n"
"    layer\n"
"    The layer number of the new begin layer for this guide.\n"
;

static PyObject*
oaGuide_setBeginLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->setBeginLayerNum(p1.Data());
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
static char oaGuide_setEndLayerNum_doc[] = 
"Class: oaGuide, Function: setEndLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setEndLayerNum(oaLayerNum layer)\n"
"    Signature: setEndLayerNum|void-void|simple-oaLayerNum,\n"
"    This function changes the end layer for this guide.\n"
"    layer\n"
"    The layer number of the new end layer for this guide.\n"
;

static PyObject*
oaGuide_setEndLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->setEndLayerNum(p1.Data());
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
static char oaGuide_setFollowLayers_doc[] = 
"Class: oaGuide, Function: setFollowLayers\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setFollowLayers(oaBoolean value)\n"
"    Signature: setFollowLayers|void-void|simple-oaBoolean,\n"
"    This function changes the follow layers attribute for this guide to the specified value .\n"
;

static PyObject*
oaGuide_setFollowLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setFollowLayers(p1.Data());
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
static char oaGuide_setPoints_doc[] = 
"Class: oaGuide, Function: setPoints\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: void setPoints(const oaPoint& beginPoint,const oaPoint& endPoint)\n"
"    Signature: setPoints|void-void|cref-oaPoint,cref-oaPoint,\n"
"    This function changes the begin and end points for this guide.\n"
"    beginPoint\n"
"    The new begin point for this guide\n"
"    endPoint\n"
"    The new end point for this guide\n"
;

static PyObject*
oaGuide_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideObject* self=(PyoaGuideObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    PyParamoaPoint p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaPoint_Convert,&p1,
          &PyoaPoint_Convert,&p2)) {
        data.DataCall()->setPoints(p1.Data(),p2.Data());
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
static char oaGuide_isNull_doc[] =
"Class: oaGuide, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaGuide_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaGuide data;
    int convert_status=PyoaGuide_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaGuide_assign_doc[] = 
"Class: oaGuide, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGuide_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGuide data;
  int convert_status=PyoaGuide_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGuide p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGuide_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGuide_methodlist[] = {
    {"followLayers",(PyCFunction)oaGuide_followLayers,METH_VARARGS,oaGuide_followLayers_doc},
    {"getBeginLayerHeader",(PyCFunction)oaGuide_getBeginLayerHeader,METH_VARARGS,oaGuide_getBeginLayerHeader_doc},
    {"getBeginLayerNum",(PyCFunction)oaGuide_getBeginLayerNum,METH_VARARGS,oaGuide_getBeginLayerNum_doc},
    {"getEndLayerHeader",(PyCFunction)oaGuide_getEndLayerHeader,METH_VARARGS,oaGuide_getEndLayerHeader_doc},
    {"getEndLayerNum",(PyCFunction)oaGuide_getEndLayerNum,METH_VARARGS,oaGuide_getEndLayerNum_doc},
    {"getPoints",(PyCFunction)oaGuide_getPoints,METH_VARARGS,oaGuide_getPoints_doc},
    {"getRoute",(PyCFunction)oaGuide_getRoute,METH_VARARGS,oaGuide_getRoute_doc},
    {"hasRoute",(PyCFunction)oaGuide_hasRoute,METH_VARARGS,oaGuide_hasRoute_doc},
    {"setBeginLayerNum",(PyCFunction)oaGuide_setBeginLayerNum,METH_VARARGS,oaGuide_setBeginLayerNum_doc},
    {"setEndLayerNum",(PyCFunction)oaGuide_setEndLayerNum,METH_VARARGS,oaGuide_setEndLayerNum_doc},
    {"setFollowLayers",(PyCFunction)oaGuide_setFollowLayers,METH_VARARGS,oaGuide_setFollowLayers_doc},
    {"setPoints",(PyCFunction)oaGuide_setPoints,METH_VARARGS,oaGuide_setPoints_doc},
    {"isNull",(PyCFunction)oaGuide_tp_isNull,METH_VARARGS,oaGuide_isNull_doc},
    {"assign",(PyCFunction)oaGuide_tp_assign,METH_VARARGS,oaGuide_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGuide_doc[] = 
"Class: oaGuide\n"
"  The oaGuide class specifies a connection between two objects that are intended to be wired together. Guides are generally replaced with physical objects when the wiring for the net is completed. Guides can be used before the detailed location of the wiring is known, but after the branching of the wire into segments for each end point is known and/or layer constraints are known. Guides also qualify as route objects and can be added to routes.\n"
"  The oaGuide class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaGuide)\n"
"    Calls: (const oaGuide&)\n"
"    Signature: oaGuide||cref-oaGuide,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGuide_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGuide",
    sizeof(PyoaGuideObject),
    0,
    (destructor)oaGuide_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGuide_tp_compare,	/* tp_compare */
    (reprfunc)oaGuide_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGuide_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGuide_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConnFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGuide_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGuide_static_create_doc[] = 
"Class: oaGuide, Function: create\n"
"  Paramegers: (oaBlock,oaPoint,oaPoint)\n"
"    Calls: oaGuide* create(oaBlock* block,const oaPoint& beginPoint,const oaPoint& endPoint)\n"
"    Signature: create|ptr-oaGuide|ptr-oaBlock,cref-oaPoint,cref-oaPoint,simple-oaLayerNum,simple-oaLayerNum,\n"
"    This function creates a guide object in the specified block with the specified attributes.\n"
"    block\n"
"    The block in which to create this guide\n"
"    beginPoint\n"
"    The begin point for this guide\n"
"    endPoint\n"
"    The end point for this guide. The end point may be the same as the begin point.\n"
"    beginLayer\n"
"    An optional begin layer number for this guide\n"
"    endLayer\n"
"    An optional end layer number for this guide\n"
"  Paramegers: (oaBlock,oaPoint,oaPoint,oaLayerNum)\n"
"    Calls: oaGuide* create(oaBlock* block,const oaPoint& beginPoint,const oaPoint& endPoint,oaLayerNum beginLayer)\n"
"    Signature: create|ptr-oaGuide|ptr-oaBlock,cref-oaPoint,cref-oaPoint,simple-oaLayerNum,simple-oaLayerNum,\n"
"    This function creates a guide object in the specified block with the specified attributes.\n"
"    block\n"
"    The block in which to create this guide\n"
"    beginPoint\n"
"    The begin point for this guide\n"
"    endPoint\n"
"    The end point for this guide. The end point may be the same as the begin point.\n"
"    beginLayer\n"
"    An optional begin layer number for this guide\n"
"    endLayer\n"
"    An optional end layer number for this guide\n"
"  Paramegers: (oaBlock,oaPoint,oaPoint,oaLayerNum,oaLayerNum)\n"
"    Calls: oaGuide* create(oaBlock* block,const oaPoint& beginPoint,const oaPoint& endPoint,oaLayerNum beginLayer,oaLayerNum endLayer)\n"
"    Signature: create|ptr-oaGuide|ptr-oaBlock,cref-oaPoint,cref-oaPoint,simple-oaLayerNum,simple-oaLayerNum,\n"
"    This function creates a guide object in the specified block with the specified attributes.\n"
"    block\n"
"    The block in which to create this guide\n"
"    beginPoint\n"
"    The begin point for this guide\n"
"    endPoint\n"
"    The end point for this guide. The end point may be the same as the begin point.\n"
"    beginLayer\n"
"    An optional begin layer number for this guide\n"
"    endLayer\n"
"    An optional end layer number for this guide\n"
;

static PyObject*
oaGuide_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaPoint,oaPoint)
    {
        PyParamoaBlock p1;
        PyParamoaPoint p2;
        PyParamoaPoint p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaPoint_Convert,&p2,
              &PyoaPoint_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGuidep result= (oaGuide::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaGuide_FromoaGuide(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaPoint,oaPoint,oaLayerNum)
    {
        PyParamoaBlock p1;
        PyParamoaPoint p2;
        PyParamoaPoint p3;
        PyParamoaLayerNum p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaPoint_Convert,&p2,
              &PyoaPoint_Convert,&p3,
              &PyoaLayerNum_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGuidep result= (oaGuide::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaGuide_FromoaGuide(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaPoint,oaPoint,oaLayerNum,oaLayerNum)
    {
        PyParamoaBlock p1;
        PyParamoaPoint p2;
        PyParamoaPoint p3;
        PyParamoaLayerNum p4;
        PyParamoaLayerNum p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaPoint_Convert,&p2,
              &PyoaPoint_Convert,&p3,
              &PyoaLayerNum_Convert,&p4,
              &PyoaLayerNum_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaGuidep result= (oaGuide::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaGuide_FromoaGuide(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGuide, function: create, Choices are:\n"
        "    (oaBlock,oaPoint,oaPoint)\n"
        "    (oaBlock,oaPoint,oaPoint,oaLayerNum)\n"
        "    (oaBlock,oaPoint,oaPoint,oaLayerNum,oaLayerNum)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaGuide_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaGuide_static_create,METH_VARARGS,oaGuide_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGuide_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGuide_Type)<0) {
      printf("** PyType_Ready failed for: oaGuide\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGuide",
           (PyObject*)(&PyoaGuide_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGuide\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaGuide_Type.tp_dict;
    for(method=oaGuide_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaGuideModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaGuideModTypeEnum_Convert(PyObject* ob,PyParamoaGuideModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacAddToNetGuideModType")==0) { result->SetData(oacAddToNetGuideModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromNetGuideModType")==0) { result->SetData(oacRemoveFromNetGuideModType); return 1;}
        if (strcasecmp(str,"oacSetPointsGuideModType")==0) { result->SetData(oacSetPointsGuideModType); return 1;}
        if (strcasecmp(str,"oacSetBeginLayerGuideModType")==0) { result->SetData(oacSetBeginLayerGuideModType); return 1;}
        if (strcasecmp(str,"oacSetEndLayerGuideModType")==0) { result->SetData(oacSetEndLayerGuideModType); return 1;}
        if (strcasecmp(str,"oacSetFollowLayersGuideModType")==0) { result->SetData(oacSetFollowLayersGuideModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupGuideModType")==0) { result->SetData(oacAddToFigGroupGuideModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupGuideModType")==0) { result->SetData(oacRemoveFromFigGroupGuideModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaGuideModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGuideModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaGuideModTypeEnum_FromoaGuideModTypeEnum(oaGuideModTypeEnum ob)
{
    if (ob==oacAddToNetGuideModType) return PyString_FromString("oacAddToNetGuideModType");
    if (ob==oacRemoveFromNetGuideModType) return PyString_FromString("oacRemoveFromNetGuideModType");
    if (ob==oacSetPointsGuideModType) return PyString_FromString("oacSetPointsGuideModType");
    if (ob==oacSetBeginLayerGuideModType) return PyString_FromString("oacSetBeginLayerGuideModType");
    if (ob==oacSetEndLayerGuideModType) return PyString_FromString("oacSetEndLayerGuideModType");
    if (ob==oacSetFollowLayersGuideModType) return PyString_FromString("oacSetFollowLayersGuideModType");
    if (ob==oacAddToFigGroupGuideModType) return PyString_FromString("oacAddToFigGroupGuideModType");
    if (ob==oacRemoveFromFigGroupGuideModType) return PyString_FromString("oacRemoveFromFigGroupGuideModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaGuideModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaGuideModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaGuideModTypeEnum_FromoaGuideModTypeEnum(oaGuideModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaGuideModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaGuideModTypeEnum_doc[] =
"Type convert function for enum: oaGuideModTypeEnum";
                               
static PyMethodDef PyoaGuideModTypeEnum_method =
  {"oaGuideModTypeEnum",(PyCFunction)PyoaGuideModTypeEnum_TypeFunction,METH_VARARGS,oaGuideModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaGuideModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacAddToNetGuideModType");
    PyDict_SetItemString(mod_dict,"oacAddToNetGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromNetGuideModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromNetGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPointsGuideModType");
    PyDict_SetItemString(mod_dict,"oacSetPointsGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBeginLayerGuideModType");
    PyDict_SetItemString(mod_dict,"oacSetBeginLayerGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetEndLayerGuideModType");
    PyDict_SetItemString(mod_dict,"oacSetEndLayerGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetFollowLayersGuideModType");
    PyDict_SetItemString(mod_dict,"oacSetFollowLayersGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupGuideModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupGuideModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupGuideModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupGuideModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaGuideModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaGuideModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaGuideModTypeEnum\n");
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
// Wrapper Implementation for Class: oaGuideQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaGuideQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaGuideQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaGuideQueryObject* self = (PyoaGuideQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: oaGuideQuery");
    }
    else {
        pyv_oaGuideQuery* p = new pyv_oaGuideQuery();
        p->pyob=self;
        self->value= (oaRegionQuery*)  p;
        return bself;
    }
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaGuideQuery_tp_dealloc(PyoaGuideQueryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaGuideQuery_tp_repr(PyObject *ob)
{
    PyParamoaGuideQuery value;
    int convert_status=PyoaGuideQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaGuideQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaGuideQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaGuideQuery v1;
    PyParamoaGuideQuery v2;
    int convert_status1=PyoaGuideQuery_Convert(ob1,&v1);
    int convert_status2=PyoaGuideQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaGuideQuery_Convert(PyObject* ob,PyParamoaGuideQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaGuideQuery_Check(ob)) {
        result->SetData( (oaGuideQuery*) ((PyoaGuideQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaGuideQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaGuideQuery_FromoaGuideQuery(oaGuideQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaGuideQuery_Type.tp_alloc(&PyoaGuideQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaGuideQueryObject* self = (PyoaGuideQueryObject*)bself;
        self->value = (oaRegionQuery*)  data;
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
pyv_oaGuideQuery::pyv_oaGuideQuery()
 : pyob(NULL),
   oaGuideQuery()
{
}

// ------------------------------------------------------------------
pyv_oaGuideQuery::pyv_oaGuideQuery(const oaGuideQuery& p)
 : pyob(NULL),
   oaGuideQuery(p)
{
}

// ------------------------------------------------------------------
void pyv_oaGuideQuery::queryGuide(oaGuide* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"queryGuide");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::queryGuide was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGuide_FromoaGuide(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::queryGuide had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaGuideQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaGuideQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaGuideQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaGuideQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaGuideQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaGuideQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaGuideQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGuideQuery_query_doc[] = 
"Class: oaGuideQuery, Function: query\n"
"  Paramegers: (oaDesign,oaBox)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The current transform that is applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The current transform that is applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The current transform that is applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating guides in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The current transform that is applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
;

static PyObject*
oaGuideQuery_query(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuideQuery data;
    int convert_status=PyoaGuideQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideQueryObject* self=(PyoaGuideQueryObject*)ob;

    // Case: (oaDesign,oaBox)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        PyParamoaUInt4 p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaUInt4_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        PyParamoaUInt4 p5;
        PyParamoaUInt4 p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaUInt4_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaGuideQuery, function: query, Choices are:\n"
        "    (oaDesign,oaBox)\n"
        "    (oaDesign,oaBox,oaDist)\n"
        "    (oaDesign,oaBox,oaDist,oaUInt4)\n"
        "    (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)\n"
        "    (oaDesign,oaBox,oaTransform)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaGuideQuery_queryGuide_doc[] = 
"Class: oaGuideQuery, Function: queryGuide\n"
"  Paramegers: (oaGuide)\n"
"    Calls: virtual void queryGuide(oaGuide* guide)\n"
"    Signature: queryGuide|void-void|ptr-oaGuide,\n"
"    This function processes each result of the guide query.\n"
"    guide\n"
"    Pointer to the oaGuide that is queried.\n"
;

static PyObject*
oaGuideQuery_queryGuide(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaGuideQuery data;
    int convert_status=PyoaGuideQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaGuideQueryObject* self=(PyoaGuideQueryObject*)ob;

    PyParamoaGuide p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaGuide_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        PyErr_SetString(PyExc_TypeError,
            "Call to Pure-Virtual Function class: oaGuideQuery, function: queryGuide");
            return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaGuideQuery_assign_doc[] = 
"Class: oaGuideQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaGuideQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaGuideQuery data;
  int convert_status=PyoaGuideQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaGuideQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaGuideQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaGuideQuery_methodlist[] = {
    {"query",(PyCFunction)oaGuideQuery_query,METH_VARARGS,oaGuideQuery_query_doc},
    {"queryGuide",(PyCFunction)oaGuideQuery_queryGuide,METH_VARARGS,oaGuideQuery_queryGuide_doc},
    {"assign",(PyCFunction)oaGuideQuery_tp_assign,METH_VARARGS,oaGuideQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaGuideQuery_doc[] = 
"Class: oaGuideQuery\n"
"  The oaGuideQuery class implements functionality to query a specified region in a design hierarchy and quickly return all guides that overlap the region.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaGuideQuery()\n"
"    Signature: oaGuideQuery||\n"
"    The constructor for oaGuideQuery.\n"
"  Paramegers: (oaGuideQuery)\n"
"    Calls: (const oaGuideQuery&)\n"
"    Signature: oaGuideQuery||cref-oaGuideQuery,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaGuideQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaGuideQuery",
    sizeof(PyoaGuideQueryObject),
    0,
    (destructor)oaGuideQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaGuideQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaGuideQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaGuideQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaGuideQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRegionQuery_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaGuideQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaGuideQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaGuideQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaGuideQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaGuideQuery",
           (PyObject*)(&PyoaGuideQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaGuideQuery\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaHierPath
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaHierPath_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaHierPath_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaHierPathObject* self = (PyoaHierPathObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaHierPath();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value =  new oaHierPath(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaHierPath)
    {
        PyParamoaHierPath p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaHierPath_Convert,&p1)) {
            self->value =  new oaHierPath(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaHierPath, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaHierPath)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaHierPath_tp_dealloc(PyoaHierPathObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaHierPath_tp_repr(PyObject *ob)
{
    PyParamoaHierPath value;
    int convert_status=PyoaHierPath_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaHierPath::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaHierPath_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaHierPath v1;
    PyParamoaHierPath v2;
    int convert_status1=PyoaHierPath_Convert(ob1,&v1);
    int convert_status2=PyoaHierPath_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaHierPath_Convert(PyObject* ob,PyParamoaHierPath* result)
{
    if (ob == NULL) return 1;
    if (PyoaHierPath_Check(ob)) {
        result->SetData(  ((PyoaHierPathObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaHierPath Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaHierPath_FromoaHierPath(oaHierPath* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaHierPath_Type.tp_alloc(&PyoaHierPath_Type,0);
        if (bself == NULL) return bself;
        PyoaHierPathObject* self = (PyoaHierPathObject*)bself;
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
static char oaHierPath_getDepth_doc[] = 
"Class: oaHierPath, Function: getDepth\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getDepth() const\n"
"    Signature: getDepth|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the depth of this oaHierPath.\n"
;

static PyObject*
oaHierPath_getDepth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getDepth());
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
static char oaHierPath_getLevel_doc[] = 
"Class: oaHierPath, Function: getLevel\n"
"  Paramegers: (oaUInt4,oaRef,oaUInt4,oaUInt4)\n"
"    Calls: void getLevel(oaUInt4 index,oaRef*& ref,oaUInt4& row,oaUInt4& col) const\n"
"    Signature: getLevel|void-void|simple-oaUInt4,ptrref-oaRef,ref-oaUInt4,ref-oaUInt4,\n"
"    This function returns the specified level in this path.\n"
"    level\n"
"    The specified level of interest\n"
"    ref\n"
"    The reference to return\n"
"    row\n"
"    The reference of the row\n"
"    col\n"
"    The reference of the col\n"
;

static PyObject*
oaHierPath_getLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    PyParamoaUInt4 p1;
    PyParamoaRef p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaRef_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4)) {
        data.DataCall()->getLevel(p1.Data(),p2.Data(),p3.Data(),p4.Data());
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
static char oaHierPath_getTransform_doc[] = 
"Class: oaHierPath, Function: getTransform\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void getTransform(oaTransform& result) const\n"
"    Signature: getTransform|void-void|ref-oaTransform,\n"
"    BrowseData: 0,oaTransform\n"
"    This function returns the concatenated transform for the context of this oaHierPath object.\n"
"    result\n"
"    The reference of the transform to return\n"
;

static PyObject*
oaHierPath_getTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    PyParamoaTransform p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTransform_Convert,&p1)) {
        data.DataCall()->getTransform(p1.Data());
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
static char oaHierPath_popLevel_doc[] = 
"Class: oaHierPath, Function: popLevel\n"
"  Paramegers: ()\n"
"    Calls: void popLevel()\n"
"    Signature: popLevel|void-void|\n"
"    BrowseData: 0\n"
"    This function pops the top level off of this oaHierPath.\n"
;

static PyObject*
oaHierPath_popLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->popLevel();
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
static char oaHierPath_pushLevel_doc[] = 
"Class: oaHierPath, Function: pushLevel\n"
"  Paramegers: (oaRef)\n"
"    Calls: void pushLevel(oaRef* ref)\n"
"    Signature: pushLevel|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function pushes a new level onto the top of this oaHierPath object. The oaHierPath object is resized if necessary.\n"
"    ref\n"
"    The reference to push onto the top of this oaHierPath object\n"
"    row\n"
"    The row index; the default value is zero\n"
"    col\n"
"    The column index; the default value is zero\n"
"  Paramegers: (oaRef,oaUInt4)\n"
"    Calls: void pushLevel(oaRef* ref,oaUInt4 row)\n"
"    Signature: pushLevel|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function pushes a new level onto the top of this oaHierPath object. The oaHierPath object is resized if necessary.\n"
"    ref\n"
"    The reference to push onto the top of this oaHierPath object\n"
"    row\n"
"    The row index; the default value is zero\n"
"    col\n"
"    The column index; the default value is zero\n"
"  Paramegers: (oaRef,oaUInt4,oaUInt4)\n"
"    Calls: void pushLevel(oaRef* ref,oaUInt4 row,oaUInt4 col)\n"
"    Signature: pushLevel|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function pushes a new level onto the top of this oaHierPath object. The oaHierPath object is resized if necessary.\n"
"    ref\n"
"    The reference to push onto the top of this oaHierPath object\n"
"    row\n"
"    The row index; the default value is zero\n"
"    col\n"
"    The column index; the default value is zero\n"
;

static PyObject*
oaHierPath_pushLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    // Case: (oaRef)
    {
        PyParamoaRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->pushLevel(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaRef,oaUInt4)
    {
        PyParamoaRef p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaRef_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->pushLevel(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaRef,oaUInt4,oaUInt4)
    {
        PyParamoaRef p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaRef_Convert,&p1,
              &PyoaUInt4_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->pushLevel(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaHierPath, function: pushLevel, Choices are:\n"
        "    (oaRef)\n"
        "    (oaRef,oaUInt4)\n"
        "    (oaRef,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaHierPath_reset_doc[] = 
"Class: oaHierPath, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    This function resets this oaHierPath object to empty.\n"
;

static PyObject*
oaHierPath_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

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
static char oaHierPath_setLevel_doc[] = 
"Class: oaHierPath, Function: setLevel\n"
"  Paramegers: (oaUInt4,oaRef,oaUInt4,oaUInt4)\n"
"    Calls: void setLevel(oaUInt4 level,oaRef* ref,oaUInt4 row,oaUInt4 col)\n"
"    Signature: setLevel|void-void|simple-oaUInt4,ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function sets the element of the specified level. The depth of this hierPath is incremented. It is assumed that the element array has been allocated properly.\n"
"    level\n"
"    The specified level of interest\n"
"    ref\n"
"    The reference\n"
"    row\n"
"    The row number\n"
"    col\n"
"    The column number\n"
;

static PyObject*
oaHierPath_setLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    PyParamoaUInt4 p1;
    PyParamoaRef p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaRef_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4)) {
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        data.DataCall()->setLevel(p1.Data(),p2.Data(),p3.Data(),p4.Data());
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
static char oaHierPath_setSize_doc[] = 
"Class: oaHierPath, Function: setSize\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setSize(oaUInt4 sizeIn)\n"
"    Signature: setSize|void-void|simple-oaUInt4,\n"
"    This function sets the size of this hierPath to the specified size and resets the depth to zero. If the given size is greater than the exiting size, this function allocates new storage and removes the existing data.\n"
"    sizeIn\n"
"    The new size\n"
;

static PyObject*
oaHierPath_setSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaHierPath data;
    int convert_status=PyoaHierPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaHierPathObject* self=(PyoaHierPathObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setSize(p1.Data());
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

static char oaHierPath_assign_doc[] = 
"Class: oaHierPath, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaHierPath_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaHierPath data;
  int convert_status=PyoaHierPath_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaHierPath p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaHierPath_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaHierPath_methodlist[] = {
    {"getDepth",(PyCFunction)oaHierPath_getDepth,METH_VARARGS,oaHierPath_getDepth_doc},
    {"getLevel",(PyCFunction)oaHierPath_getLevel,METH_VARARGS,oaHierPath_getLevel_doc},
    {"getTransform",(PyCFunction)oaHierPath_getTransform,METH_VARARGS,oaHierPath_getTransform_doc},
    {"popLevel",(PyCFunction)oaHierPath_popLevel,METH_VARARGS,oaHierPath_popLevel_doc},
    {"pushLevel",(PyCFunction)oaHierPath_pushLevel,METH_VARARGS,oaHierPath_pushLevel_doc},
    {"reset",(PyCFunction)oaHierPath_reset,METH_VARARGS,oaHierPath_reset_doc},
    {"setLevel",(PyCFunction)oaHierPath_setLevel,METH_VARARGS,oaHierPath_setLevel_doc},
    {"setSize",(PyCFunction)oaHierPath_setSize,METH_VARARGS,oaHierPath_setSize_doc},
    {"assign",(PyCFunction)oaHierPath_tp_assign,METH_VARARGS,oaHierPath_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaHierPath_doc[] = 
"Class: oaHierPath\n"
"  The oaHierPath utility class implements functions for referring to a specific instance of a design hierarchy. A hierarchical path is composed of an array that contains the elements of the path and the depth of the path. Functions are implemented that allow applications to examine the contents of the path.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaHierPath()\n"
"    Signature: oaHierPath||simple-oaUInt4,\n"
"    This function constructs an oaHierPath object, initializing the path so the path is empty.\n"
"    sizeIn\n"
"    The size of this path; the default value is 10\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaHierPath(oaUInt4 sizeIn)\n"
"    Signature: oaHierPath||simple-oaUInt4,\n"
"    This function constructs an oaHierPath object, initializing the path so the path is empty.\n"
"    sizeIn\n"
"    The size of this path; the default value is 10\n"
"  Paramegers: (oaHierPath)\n"
"    Calls: oaHierPath(const oaHierPath& pathIn)\n"
"    Signature: oaHierPath||cref-oaHierPath,\n"
"    This function constructs a new oaHierPath object by copying the specified oaHierPath object.\n"
"    pathIn\n"
"    The oaHierPath object to copy\n"
"  Paramegers: (oaHierPath)\n"
"    Calls: (const oaHierPath&)\n"
"    Signature: oaHierPath||cref-oaHierPath,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaHierPath_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaHierPath",
    sizeof(PyoaHierPathObject),
    0,
    (destructor)oaHierPath_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaHierPath_tp_compare,	/* tp_compare */
    (reprfunc)oaHierPath_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaHierPath_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaHierPath_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaHierPath_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaHierPath_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaHierPath_Type)<0) {
      printf("** PyType_Ready failed for: oaHierPath\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaHierPath",
           (PyObject*)(&PyoaHierPath_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaHierPath\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaHierPathElement
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaHierPathElement_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaHierPathElement_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaHierPathElementObject* self = (PyoaHierPathElementObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaHierPathElement, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaHierPathElement_tp_dealloc(PyoaHierPathElementObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaHierPathElement_tp_repr(PyObject *ob)
{
    PyParamoaHierPathElement value;
    int convert_status=PyoaHierPathElement_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaHierPathElement::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaHierPathElement_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaHierPathElement v1;
    PyParamoaHierPathElement v2;
    int convert_status1=PyoaHierPathElement_Convert(ob1,&v1);
    int convert_status2=PyoaHierPathElement_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaHierPathElement_Convert(PyObject* ob,PyParamoaHierPathElement* result)
{
    if (ob == NULL) return 1;
    if (PyoaHierPathElement_Check(ob)) {
        result->SetData(  ((PyoaHierPathElementObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaHierPathElement Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaHierPathElement_FromoaHierPathElement(oaHierPathElement* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaHierPathElement_Type.tp_alloc(&PyoaHierPathElement_Type,0);
        if (bself == NULL) return bself;
        PyoaHierPathElementObject* self = (PyoaHierPathElementObject*)bself;
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
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaHierPathElement_doc[] = 
"Class: oaHierPathElement\n"
"  Class type oaHierPathElement\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaHierPathElement_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaHierPathElement",
    sizeof(PyoaHierPathElementObject),
    0,
    (destructor)oaHierPathElement_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaHierPathElement_tp_compare,	/* tp_compare */
    (reprfunc)oaHierPathElement_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaHierPathElement_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaHierPathElement_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaHierPathElement_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaHierPathElement_Type)<0) {
      printf("** PyType_Ready failed for: oaHierPathElement\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaHierPathElement",
           (PyObject*)(&PyoaHierPathElement_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaHierPathElement\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaHierProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaHierProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaHierProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaHierPropObject* self = (PyoaHierPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaHierProp)
    {
        PyParamoaHierProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaHierProp_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaHierProp, Choices are:\n"
        "    (oaHierProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaHierProp_tp_dealloc(PyoaHierPropObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaHierProp_tp_repr(PyObject *ob)
{
    PyParamoaHierProp value;
    int convert_status=PyoaHierProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaHierProp::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[32];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaHierProp::");
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
oaHierProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaHierProp v1;
    PyParamoaHierProp v2;
    int convert_status1=PyoaHierProp_Convert(ob1,&v1);
    int convert_status2=PyoaHierProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaHierProp_Convert(PyObject* ob,PyParamoaHierProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaHierProp_Check(ob)) {
        result->SetData( (oaHierProp**) ((PyoaHierPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaHierProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaHierProp_FromoaHierProp(oaHierProp** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaHierProp* data=*value;
        PyObject* bself = PyoaHierProp_Type.tp_alloc(&PyoaHierProp_Type,0);
        if (bself == NULL) return bself;
        PyoaHierPropObject* self = (PyoaHierPropObject*)bself;
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
PyObject* PyoaHierProp_FromoaHierProp(oaHierProp* data)
{
    if (data) {
       PyObject* bself = PyoaHierProp_Type.tp_alloc(&PyoaHierProp_Type,0);
       if (bself == NULL) return bself;
       PyoaHierPropObject* self = (PyoaHierPropObject*)bself;
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
static char oaHierProp_doc[] = 
"Class: oaHierProp\n"
"  The oaHierProp class is a hierarchical property. Hierarchical properties have no direct value but they may have other properties attached to them including oaHierProps. Hence they can create multi-level trees of properties that organize collections of related properties.\n"
"  For example, you could create a hierarchical property on a design called \"constraints\" and add properties representing constraints to that HierProp.\n"
"  Note that calling oaProp::getValue on a hierarchical property will return the constant string \"oaHierProp\".\n"
"  Properties are application-defined values that can be added to any managed object in oaDesign , oaTech , and oaWafer databases except for the following paged objects: oaDevice , oaNode , oaParasiticNetwork , and oaSubNetwork .\n"
"  To create properties on DM Objects, create the corresponding oaDMData object (using oaLibDMData::open , oaCellDMData::open , oaViewDMData::open , or oaCellViewDMData::open ), then create properties on that oaDMData object.\n"
"  See oaProp for a general discussion of properties.\n"
"Constructors:\n"
"  Paramegers: (oaHierProp)\n"
"    Calls: (const oaHierProp&)\n"
"    Signature: oaHierProp||cref-oaHierProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaHierProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaHierProp",
    sizeof(PyoaHierPropObject),
    0,
    (destructor)oaHierProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaHierProp_tp_compare,	/* tp_compare */
    (reprfunc)oaHierProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaHierProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaProp_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaHierProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaHierProp_static_create_doc[] = 
"Class: oaHierProp, Function: create\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaHierProp* create(oaObject* object,const oaString& name)\n"
"    Signature: create|ptr-oaHierProp|ptr-oaObject,cref-oaString,\n"
"    This function creates a hierarchical property with the specified name on the specified object . The specified name is checked to verify it is unique for properties on the specified object .\n"
"    oacInvalidObjForProp\n"
"    oacPropNameUsed\n"
;

static PyObject*
oaHierProp_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaHierPropp result= (oaHierProp::create(p1.Data(),p2.Data()));
        return PyoaHierProp_FromoaHierProp(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaHierProp_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaHierProp_static_create,METH_VARARGS,oaHierProp_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaHierProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaHierProp_Type)<0) {
      printf("** PyType_Ready failed for: oaHierProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaHierProp",
           (PyObject*)(&PyoaHierProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaHierProp\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaHierProp_Type.tp_dict;
    for(method=oaHierProp_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaImage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaImage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaImage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaImageObject* self = (PyoaImageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaImage)
    {
        PyParamoaImage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaImage_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaImage, Choices are:\n"
        "    (oaImage)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaImage_tp_dealloc(PyoaImageObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaImage_tp_repr(PyObject *ob)
{
    PyParamoaImage value;
    int convert_status=PyoaImage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaImage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaImage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaImage v1;
    PyParamoaImage v2;
    int convert_status1=PyoaImage_Convert(ob1,&v1);
    int convert_status2=PyoaImage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaImage_Convert(PyObject* ob,PyParamoaImage* result)
{
    if (ob == NULL) return 1;
    if (PyoaImage_Check(ob)) {
        result->SetData( (oaImage**) ((PyoaImageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaImage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaImage_FromoaImage(oaImage** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaImage* data=*value;
        PyObject* bself = PyoaImage_Type.tp_alloc(&PyoaImage_Type,0);
        if (bself == NULL) return bself;
        PyoaImageObject* self = (PyoaImageObject*)bself;
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
PyObject* PyoaImage_FromoaImage(oaImage* data)
{
    if (data) {
       PyObject* bself = PyoaImage_Type.tp_alloc(&PyoaImage_Type,0);
       if (bself == NULL) return bself;
       PyoaImageObject* self = (PyoaImageObject*)bself;
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
static char oaImage_destroy_doc[] = 
"Class: oaImage, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this image, removing it from the database.\n"
;

static PyObject*
oaImage_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
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
static char oaImage_getBoundary_doc[] = 
"Class: oaImage, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& points) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function returns the boundary of this image in the given pointArray.\n"
"    points\n"
"    Returns the boundary of this image\n"
;

static PyObject*
oaImage_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
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
static char oaImage_getMfgLayers_doc[] = 
"Class: oaImage, Function: getMfgLayers\n"
"  Paramegers: (oaMfgLayerArray)\n"
"    Calls: void getMfgLayers(oaMfgLayerArray& mfgLayers) const\n"
"    Signature: getMfgLayers|void-void|ref-oaMfgLayerArray,\n"
"    BrowseData: 0,oaMfgLayerArray\n"
"    This function retrieves the list of manufacturing layers associated with this image and returns them in the given oaMfgLayerArray .\n"
"    mfgLayers\n"
"    The list of manufacturing layers returned by this function\n"
;

static PyObject*
oaImage_getMfgLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMfgLayerArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMfgLayerArray_Convert,&p1)) {
        data.DataCall()->getMfgLayers(p1.Data());
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
static char oaImage_getName_doc[] = 
"Class: oaImage, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this image in the given string name .\n"
"    name\n"
"    Returns the name of this image.\n"
;

static PyObject*
oaImage_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
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
static char oaImage_getOwner_doc[] = 
"Class: oaImage, Function: getOwner\n"
"  Paramegers: ()\n"
"    Calls: oaWaferObject* getOwner() const\n"
"    Signature: getOwner|ptr-oaWaferObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the owner of this image.\n"
;

static PyObject*
oaImage_getOwner(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaWaferObjectp result= (data.DataCall()->getOwner());
        return PyoaWaferObject_FromoaWaferObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaImage_getStepperMap_doc[] = 
"Class: oaImage, Function: getStepperMap\n"
"  Paramegers: ()\n"
"    Calls: oaStepperMap* getStepperMap() const\n"
"    Signature: getStepperMap|ptr-oaStepperMap|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the stepperMap associated with this image. NULL is returned if there is no associated stepperMap.\n"
;

static PyObject*
oaImage_getStepperMap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaStepperMapp result= (data.DataCall()->getStepperMap());
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
static char oaImage_setBoundary_doc[] = 
"Class: oaImage, Function: setBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setBoundary(const oaPointArray& points)\n"
"    Signature: setBoundary|void-void|cref-oaPointArray,\n"
"    This function changes the boundary of this image to have the new set of points specified in the given pointArray. Exceptions are thrown if the specified points have coincident or collinear lines or if the number of new points is less than three.\n"
"    points\n"
"    The new boundary to give this image\n"
"    oacImageHasExtraPoints\n"
"    oacImageTooFewPoints\n"
;

static PyObject*
oaImage_setBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
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
static char oaImage_setMfgLayers_doc[] = 
"Class: oaImage, Function: setMfgLayers\n"
"  Paramegers: (oaMfgLayerArray)\n"
"    Calls: void setMfgLayers(const oaMfgLayerArray& mfgLayers)\n"
"    Signature: setMfgLayers|void-void|cref-oaMfgLayerArray,\n"
"    This function changes the set of manufacturing layers associated with this image.\n"
"    mfgLayers\n"
"    Specifies the new set of manufacturing layers for this image\n"
;

static PyObject*
oaImage_setMfgLayers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMfgLayerArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMfgLayerArray_Convert,&p1)) {
        data.DataCall()->setMfgLayers(p1.Data());
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
static char oaImage_setName_doc[] = 
"Class: oaImage, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the name of this image.\n"
"    name\n"
"    The new name to give this image\n"
"    oacImageAlreadyExists\n"
;

static PyObject*
oaImage_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaImageObject* self=(PyoaImageObject*)ob;
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
static char oaImage_isNull_doc[] =
"Class: oaImage, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaImage_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaImage data;
    int convert_status=PyoaImage_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaImage_assign_doc[] = 
"Class: oaImage, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaImage_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaImage data;
  int convert_status=PyoaImage_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaImage p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaImage_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaImage_methodlist[] = {
    {"destroy",(PyCFunction)oaImage_destroy,METH_VARARGS,oaImage_destroy_doc},
    {"getBoundary",(PyCFunction)oaImage_getBoundary,METH_VARARGS,oaImage_getBoundary_doc},
    {"getMfgLayers",(PyCFunction)oaImage_getMfgLayers,METH_VARARGS,oaImage_getMfgLayers_doc},
    {"getName",(PyCFunction)oaImage_getName,METH_VARARGS,oaImage_getName_doc},
    {"getOwner",(PyCFunction)oaImage_getOwner,METH_VARARGS,oaImage_getOwner_doc},
    {"getStepperMap",(PyCFunction)oaImage_getStepperMap,METH_VARARGS,oaImage_getStepperMap_doc},
    {"setBoundary",(PyCFunction)oaImage_setBoundary,METH_VARARGS,oaImage_setBoundary_doc},
    {"setMfgLayers",(PyCFunction)oaImage_setMfgLayers,METH_VARARGS,oaImage_setMfgLayers_doc},
    {"setName",(PyCFunction)oaImage_setName,METH_VARARGS,oaImage_setName_doc},
    {"isNull",(PyCFunction)oaImage_tp_isNull,METH_VARARGS,oaImage_isNull_doc},
    {"assign",(PyCFunction)oaImage_tp_assign,METH_VARARGS,oaImage_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaImage_doc[] = 
"Class: oaImage\n"
"  The oaImage class implements an object that represents a region of a reticle that can be stepped across a silicon wafer.\n"
"  The oaImage class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaImage)\n"
"    Calls: (const oaImage&)\n"
"    Signature: oaImage||cref-oaImage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaImage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaImage",
    sizeof(PyoaImageObject),
    0,
    (destructor)oaImage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaImage_tp_compare,	/* tp_compare */
    (reprfunc)oaImage_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaImage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaImage_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaImage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaImage_static_create_doc[] = 
"Class: oaImage, Function: create\n"
"  Paramegers: (oaReticle,oaString,oaPointArray)\n"
"    Calls: oaImage* create(oaReticle* reticle,const oaString& name,const oaPointArray& boundary)\n"
"    Signature: create|ptr-oaImage|ptr-oaReticle,cref-oaString,cref-oaPointArray,\n"
"    This function creates an image with the given name and boundary. The image represents the specified reticle. The given boundary is checked to verify that there are at least three points and no collinear or coincident points.\n"
"    reticle\n"
"    The reticle that this image represents\n"
"    name\n"
"    The name of this image\n"
"    boundary\n"
"    The boundary of the image\n"
"  Paramegers: (oaReticleRef,oaString,oaPointArray)\n"
"    Calls: oaImage* create(oaReticleRef* reticleRef,const oaString& name,const oaPointArray& boundary)\n"
"    Signature: create|ptr-oaImage|ptr-oaReticleRef,cref-oaString,cref-oaPointArray,\n"
"    This function creates an image with the given name and boundary that references the specified reticle reference.\n"
"    reticleRef\n"
"    The referenced reticleRef object\n"
"    name\n"
"    The name of the image\n"
"    boundary\n"
"    The boundary of the image\n"
"    oacImageHasExtraPoints\n"
"    oacImageTooFewPoints\n"
"    oacImageAlreadyExists\n"
;

static PyObject*
oaImage_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaReticle,oaString,oaPointArray)
    {
        PyParamoaReticle p1;
        PyParamoaString p2;
        PyParamoaPointArray p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaReticle_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaPointArray_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaImagep result= (oaImage::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaImage_FromoaImage(result);
        }
    }
    PyErr_Clear();
    // Case: (oaReticleRef,oaString,oaPointArray)
    {
        PyParamoaReticleRef p1;
        PyParamoaString p2;
        PyParamoaPointArray p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaReticleRef_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaPointArray_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaImagep result= (oaImage::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaImage_FromoaImage(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaImage, function: create, Choices are:\n"
        "    (oaReticle,oaString,oaPointArray)\n"
        "    (oaReticleRef,oaString,oaPointArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaImage_static_find_doc[] = 
"Class: oaImage, Function: find\n"
"  Paramegers: (oaWafer,oaString)\n"
"    Calls: oaImage* find(const oaWafer* wafer,const oaString& name)\n"
"    Signature: find|ptr-oaImage|cptr-oaWafer,cref-oaString,\n"
"    This function searches the wafer for an image with the given name. The image is returned if found. Otherwise, NULL is returned.\n"
"    wafer\n"
"    The wafer to search for the named image\n"
"    name\n"
"    The name of the image to look for\n"
;

static PyObject*
oaImage_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaImagep result= (oaImage::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaImage_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaImage_static_create,METH_VARARGS,oaImage_static_create_doc},
    {"static_find",(PyCFunction)oaImage_static_find,METH_VARARGS,oaImage_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaImage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaImage_Type)<0) {
      printf("** PyType_Ready failed for: oaImage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaImage",
           (PyObject*)(&PyoaImage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaImage\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaImage_Type.tp_dict;
    for(method=oaImage_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaImageModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaImageModTypeEnum_Convert(PyObject* ob,PyParamoaImageModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameImageModType")==0) { result->SetData(oacSetNameImageModType); return 1;}
        if (strcasecmp(str,"oacSetBoundaryImageModType")==0) { result->SetData(oacSetBoundaryImageModType); return 1;}
        if (strcasecmp(str,"oacSetMfgLayersImageModType")==0) { result->SetData(oacSetMfgLayersImageModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaImageModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaImageModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaImageModTypeEnum_FromoaImageModTypeEnum(oaImageModTypeEnum ob)
{
    if (ob==oacSetNameImageModType) return PyString_FromString("oacSetNameImageModType");
    if (ob==oacSetBoundaryImageModType) return PyString_FromString("oacSetBoundaryImageModType");
    if (ob==oacSetMfgLayersImageModType) return PyString_FromString("oacSetMfgLayersImageModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaImageModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaImageModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaImageModTypeEnum_FromoaImageModTypeEnum(oaImageModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaImageModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaImageModTypeEnum_doc[] =
"Type convert function for enum: oaImageModTypeEnum";
                               
static PyMethodDef PyoaImageModTypeEnum_method =
  {"oaImageModTypeEnum",(PyCFunction)PyoaImageModTypeEnum_TypeFunction,METH_VARARGS,oaImageModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaImageModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameImageModType");
    PyDict_SetItemString(mod_dict,"oacSetNameImageModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBoundaryImageModType");
    PyDict_SetItemString(mod_dict,"oacSetBoundaryImageModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetMfgLayersImageModType");
    PyDict_SetItemString(mod_dict,"oacSetMfgLayersImageModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaImageModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaImageModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaImageModTypeEnum\n");
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
// Wrapper Implementation for Class: oaInductor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInductor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInductor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInductorObject* self = (PyoaInductorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInductor)
    {
        PyParamoaInductor p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInductor_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInductor, Choices are:\n"
        "    (oaInductor)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInductor_tp_dealloc(PyoaInductorObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInductor_tp_repr(PyObject *ob)
{
    PyParamoaInductor value;
    int convert_status=PyoaInductor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaInductor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInductor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInductor v1;
    PyParamoaInductor v2;
    int convert_status1=PyoaInductor_Convert(ob1,&v1);
    int convert_status2=PyoaInductor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInductor_Convert(PyObject* ob,PyParamoaInductor* result)
{
    if (ob == NULL) return 1;
    if (PyoaInductor_Check(ob)) {
        result->SetData( (oaInductor**) ((PyoaInductorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInductor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInductor_FromoaInductor(oaInductor** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInductor* data=*value;
        PyObject* bself = PyoaInductor_Type.tp_alloc(&PyoaInductor_Type,0);
        if (bself == NULL) return bself;
        PyoaInductorObject* self = (PyoaInductorObject*)bself;
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
PyObject* PyoaInductor_FromoaInductor(oaInductor* data)
{
    if (data) {
       PyObject* bself = PyoaInductor_Type.tp_alloc(&PyoaInductor_Type,0);
       if (bself == NULL) return bself;
       PyoaInductorObject* self = (PyoaInductorObject*)bself;
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
static char oaInductor_getFromMutualInductors_doc[] = 
"Class: oaInductor, Function: getFromMutualInductors\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaMutualInductor_oaInductor getFromMutualInductors() const\n"
"    Signature: getFromMutualInductors|simple-oaCollection_oaMutualInductor_oaInductor|\n"
"    BrowseData: 1\n"
"    This function returns a collection of mutual inductors whose from endpoint connects to this inductor.\n"
;

static PyObject*
oaInductor_getFromMutualInductors(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInductor data;
    int convert_status=PyoaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInductorObject* self=(PyoaInductorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaMutualInductor_oaInductor* result= new oaCollection_oaMutualInductor_oaInductor(data.DataCall()->getFromMutualInductors());
        return PyoaCollection_oaMutualInductor_oaInductor_FromoaCollection_oaMutualInductor_oaInductor(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInductor_getFromMutualInductorsIter_doc[] = 
"Class: oaInductor, Function: getFromMutualInductorsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaMutualInductor getFromMutualInductorsIter() const\n"
"    Signature: getFromMutualInductorsIter|simple-oaIter_oaMutualInductor|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of mutual inductors whose from endpoint connects to this inductor.\n"
;

static PyObject*
oaInductor_getFromMutualInductorsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInductor data;
    int convert_status=PyoaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInductorObject* self=(PyoaInductorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaMutualInductor* result= new oaIter_oaMutualInductor(data.DataCall()->getFromMutualInductors());
        return PyoaIter_oaMutualInductor_FromoaIter_oaMutualInductor(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInductor_getToMutualInductors_doc[] = 
"Class: oaInductor, Function: getToMutualInductors\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaMutualInductor_oaInductor getToMutualInductors() const\n"
"    Signature: getToMutualInductors|simple-oaCollection_oaMutualInductor_oaInductor|\n"
"    BrowseData: 1\n"
"    This function returns a collection of mutual inductors whose to endpoint connects to this inductor.\n"
;

static PyObject*
oaInductor_getToMutualInductors(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInductor data;
    int convert_status=PyoaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInductorObject* self=(PyoaInductorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaMutualInductor_oaInductor* result= new oaCollection_oaMutualInductor_oaInductor(data.DataCall()->getToMutualInductors());
        return PyoaCollection_oaMutualInductor_oaInductor_FromoaCollection_oaMutualInductor_oaInductor(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInductor_getToMutualInductorsIter_doc[] = 
"Class: oaInductor, Function: getToMutualInductorsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaMutualInductor getToMutualInductorsIter() const\n"
"    Signature: getToMutualInductorsIter|simple-oaIter_oaMutualInductor|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of mutual inductors whose to endpoint connects to this inductor.\n"
;

static PyObject*
oaInductor_getToMutualInductorsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInductor data;
    int convert_status=PyoaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInductorObject* self=(PyoaInductorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaMutualInductor* result= new oaIter_oaMutualInductor(data.DataCall()->getToMutualInductors());
        return PyoaIter_oaMutualInductor_FromoaIter_oaMutualInductor(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInductor_isNull_doc[] =
"Class: oaInductor, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInductor_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInductor data;
    int convert_status=PyoaInductor_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInductor_assign_doc[] = 
"Class: oaInductor, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInductor_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInductor data;
  int convert_status=PyoaInductor_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInductor p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInductor_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInductor_methodlist[] = {
    {"getFromMutualInductors",(PyCFunction)oaInductor_getFromMutualInductors,METH_VARARGS,oaInductor_getFromMutualInductors_doc},
    {"getFromMutualInductorsIter",(PyCFunction)oaInductor_getFromMutualInductorsIter,METH_VARARGS,oaInductor_getFromMutualInductorsIter_doc},
    {"getToMutualInductors",(PyCFunction)oaInductor_getToMutualInductors,METH_VARARGS,oaInductor_getToMutualInductors_doc},
    {"getToMutualInductorsIter",(PyCFunction)oaInductor_getToMutualInductorsIter,METH_VARARGS,oaInductor_getToMutualInductorsIter_doc},
    {"isNull",(PyCFunction)oaInductor_tp_isNull,METH_VARARGS,oaInductor_isNull_doc},
    {"assign",(PyCFunction)oaInductor_tp_assign,METH_VARARGS,oaInductor_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInductor_doc[] = 
"Class: oaInductor\n"
"  The oaInductor class represents an inductor in a parasitic network for a net. Each inductor object has one inductance value for each analysis point that the parasitic network represents.\n"
"Constructors:\n"
"  Paramegers: (oaInductor)\n"
"    Calls: (const oaInductor&)\n"
"    Signature: oaInductor||cref-oaInductor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInductor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInductor",
    sizeof(PyoaInductorObject),
    0,
    (destructor)oaInductor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInductor_tp_compare,	/* tp_compare */
    (reprfunc)oaInductor_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInductor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInductor_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdDevice_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInductor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInductor_static_create_doc[] = 
"Class: oaInductor, Function: create\n"
"  Paramegers: (oaNode,oaNode)\n"
"    Calls: oaInductor* create(oaNode* fromNode,oaNode* toNode)\n"
"    Signature: create|ptr-oaInductor|ptr-oaNode,ptr-oaNode,\n"
"    This function creates an inductor belonging to the parasitic network containing fromNode and toNode . An exception will be thrown if fromNode and toNode are specified and do not belong to the same network. The device created will not have an ID associated with it. The hasId() function will return false for these devices and the getId() function will return an oacInvalidDeviceID value.\n"
"    Inductors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the inductor will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The starting node for the inductor\n"
"    toNode\n"
"    The ending node for the inductor\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
"  Paramegers: (oaNode,oaNode,oaUInt4)\n"
"    Calls: oaInductor* create(oaNode* fromNode,oaNode* toNode,oaUInt4 id)\n"
"    Signature: create|ptr-oaInductor|ptr-oaNode,ptr-oaNode,simple-oaUInt4,\n"
"    This function creates an inductor belonging to the parasitic network containing fromNode and toNode . An exception will be thrown if fromNode and toNode do not belong to the same network. An exception will be thrown if the id is the reserved oacInvalidDeviceID value or if a device with the specified id value already exists. The hasId() function will return true for devices created with this function and the getId() function will return the user-specified id.\n"
"    Inductors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the inductor will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The starting node for the inductor\n"
"    toNode\n"
"    The ending node for the inductor\n"
"    id\n"
"    The unique ID to be assigned to the inductor created\n"
"    oacInvalidDeviceIdSpecified\n"
"    oacLocalDeviceIdExists\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
;

static PyObject*
oaInductor_static_create(PyObject* ob, PyObject *args)
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
            oaInductorp result= (oaInductor::create(p1.Data(),p2.Data()));
            return PyoaInductor_FromoaInductor(result);
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
            oaInductorp result= (oaInductor::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaInductor_FromoaInductor(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInductor, function: create, Choices are:\n"
        "    (oaNode,oaNode)\n"
        "    (oaNode,oaNode,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaInductor_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaInductor_static_create,METH_VARARGS,oaInductor_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInductor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInductor_Type)<0) {
      printf("** PyType_Ready failed for: oaInductor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInductor",
           (PyObject*)(&PyoaInductor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInductor\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInductor_Type.tp_dict;
    for(method=oaInductor_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstObject* self = (PyoaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInst)
    {
        PyParamoaInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInst, Choices are:\n"
        "    (oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInst_tp_dealloc(PyoaInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInst_tp_repr(PyObject *ob)
{
    PyParamoaInst value;
    int convert_status=PyoaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[28];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaInst::");
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
oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInst v1;
    PyParamoaInst v2;
    int convert_status1=PyoaInst_Convert(ob1,&v1);
    int convert_status2=PyoaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInst_Convert(PyObject* ob,PyParamoaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaInst_Check(ob)) {
        result->SetData( (oaInst**) ((PyoaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInst_FromoaInst(oaInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInst* data=*value;
        if (data->isBitInst()) return PyoaBitInst_FromoaBitInst((oaBitInst**)value,borrow,lock);
        if (data->getType()==oacVectorInstType) return PyoaVectorInst_FromoaVectorInst((oaVectorInst**)value,borrow,lock);
        PyObject* bself = PyoaInst_Type.tp_alloc(&PyoaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaInstObject* self = (PyoaInstObject*)bself;
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
PyObject* PyoaInst_FromoaInst(oaInst* data)
{
    if (data) {
        if (data->isBitInst()) return PyoaBitInst_FromoaBitInst((oaBitInst*)data);
        if (data->getType()==oacVectorInstType) return PyoaVectorInst_FromoaVectorInst((oaVectorInst*)data);
       PyObject* bself = PyoaInst_Type.tp_alloc(&PyoaInst_Type,0);
       if (bself == NULL) return bself;
       PyoaInstObject* self = (PyoaInstObject*)bself;
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
static char oaInst_addToCluster_doc[] = 
"Class: oaInst, Function: addToCluster\n"
"  Paramegers: (oaCluster)\n"
"    Calls: void addToCluster(oaCluster* cluster)\n"
"    Signature: addToCluster|void-void|ptr-oaCluster,\n"
"    This function adds this instance to the specified cluster.\n"
"    oacClusterAndInstNotSameBlock\n"
"    oacInstAlreadyInCluster\n"
;

static PyObject*
oaInst_addToCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaCluster p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCluster_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addToCluster(p1.Data());
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
static char oaInst_findParam_doc[] = 
"Class: oaInst, Function: findParam\n"
"  Paramegers: (oaString,oaParam)\n"
"    Calls: oaBoolean findParam(const oaString& name,oaParam& param)\n"
"    Signature: findParam|simple-oaBoolean|cref-oaString,ref-oaParam,\n"
"    This function searches the parameter list of this instance for a parameter with the specified name . If found, it fills out param with the appropriate attributes and returns true. Otherwise, the function returns false. Only Pcell instances have parameters.\n"
"    name\n"
"    The parameter name to find\n"
"    param\n"
"    The parameter class to fill out if the parameter is found\n"
;

static PyObject*
oaInst_findParam(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    PyParamoaParam p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaParam_Convert,&p2)) {
        oaBoolean result= (data.DataCall()->findParam(p1.Data(),p2.Data()));
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
static char oaInst_getAssignments_doc[] = 
"Class: oaInst, Function: getAssignments\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaAssignment_oaInst getAssignments() const\n"
"    Signature: getAssignments|simple-oaCollection_oaAssignment_oaInst|\n"
"    BrowseData: 1\n"
"    This function returns a collection of assignments in this instance.\n"
;

static PyObject*
oaInst_getAssignments(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaAssignment_oaInst* result= new oaCollection_oaAssignment_oaInst(data.DataCall()->getAssignments());
        return PyoaCollection_oaAssignment_oaInst_FromoaCollection_oaAssignment_oaInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getAssignmentsIter_doc[] = 
"Class: oaInst, Function: getAssignmentsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaAssignment getAssignmentsIter() const\n"
"    Signature: getAssignmentsIter|simple-oaIter_oaAssignment|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of assignments in this instance.\n"
;

static PyObject*
oaInst_getAssignmentsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaAssignment* result= new oaIter_oaAssignment(data.DataCall()->getAssignments());
        return PyoaIter_oaAssignment_FromoaIter_oaAssignment(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getBlockagesOwnedBy_doc[] = 
"Class: oaInst, Function: getBlockagesOwnedBy\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBlockage_oaInst getBlockagesOwnedBy() const\n"
"    Signature: getBlockagesOwnedBy|simple-oaCollection_oaBlockage_oaInst|\n"
"    BrowseData: 1\n"
"    This function returns a collection of blockages owned by this instance.\n"
;

static PyObject*
oaInst_getBlockagesOwnedBy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBlockage_oaInst* result= new oaCollection_oaBlockage_oaInst(data.DataCall()->getBlockagesOwnedBy());
        return PyoaCollection_oaBlockage_oaInst_FromoaCollection_oaBlockage_oaInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getBlockagesOwnedByIter_doc[] = 
"Class: oaInst, Function: getBlockagesOwnedByIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaBlockage getBlockagesOwnedByIter() const\n"
"    Signature: getBlockagesOwnedByIter|simple-oaIter_oaBlockage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of blockages owned by this instance.\n"
;

static PyObject*
oaInst_getBlockagesOwnedByIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaBlockage* result= new oaIter_oaBlockage(data.DataCall()->getBlockagesOwnedBy());
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
static char oaInst_getCellName_doc[] = 
"Class: oaInst, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name for the master design referenced by this instance.\n"
"    cellName\n"
"    The cell name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name in the given namespace for the master design referenced by this instance.\n"
"    ns\n"
"    The namespace for the name\n"
"    cellName\n"
"    The cell name for the master design\n"
;

static PyObject*
oaInst_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaInst, function: getCellName, Choices are:\n"
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
static char oaInst_getCluster_doc[] = 
"Class: oaInst, Function: getCluster\n"
"  Paramegers: ()\n"
"    Calls: oaCluster* getCluster() const\n"
"    Signature: getCluster|ptr-oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the cluster of which this instance is a member. If the instance is not in a cluster, NULL is returned.\n"
;

static PyObject*
oaInst_getCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterp result= (data.DataCall()->getCluster());
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
static char oaInst_getHeader_doc[] = 
"Class: oaInst, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaInstHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaInstHeader|\n"
"    BrowseData: 1\n"
"    This function returns the instHeader associated with this instance. The instHeader is a collection of the attributes that are common to all instances of a particular master. For Pcell instances, this function returns the subheader.\n"
"    The pointer to the instance header\n"
;

static PyObject*
oaInst_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstHeaderp result= (data.DataCall()->getHeader());
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
static char oaInst_getInstTerms_doc[] = 
"Class: oaInst, Function: getInstTerms\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaInstTerm_oaInst getInstTerms() const\n"
"    Signature: getInstTerms|simple-oaCollection_oaInstTerm_oaInst|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a collection of instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaInstTerm_oaInst getInstTerms(oaUInt4 filterFlags) const\n"
"    Signature: getInstTerms|simple-oaCollection_oaInstTerm_oaInst|simple-oaUInt4,\n"
"    This function returns a collection of instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
;

static PyObject*
oaInst_getInstTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaInstTerm_oaInst* result= new oaCollection_oaInstTerm_oaInst(data.DataCall()->getInstTerms());
            return PyoaCollection_oaInstTerm_oaInst_FromoaCollection_oaInstTerm_oaInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaCollection_oaInstTerm_oaInst* result= new oaCollection_oaInstTerm_oaInst(data.DataCall()->getInstTerms(p1.Data()));
            return PyoaCollection_oaInstTerm_oaInst_FromoaCollection_oaInstTerm_oaInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInst, function: getInstTerms, Choices are:\n"
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
static char oaInst_getInstTermsIter_doc[] = 
"Class: oaInst, Function: getInstTermsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaInstTerm getInstTermsIter() const\n"
"    Signature: getInstTermsIter|simple-oaIter_oaInstTerm|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaIter_oaInstTerm getInstTermsIter(oaUInt4 filterFlags) const\n"
"    Signature: getInstTermsIter|simple-oaIter_oaInstTerm|simple-oaUInt4,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
;

static PyObject*
oaInst_getInstTermsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaInstTerm* result= new oaIter_oaInstTerm(data.DataCall()->getInstTerms());
            return PyoaIter_oaInstTerm_FromoaIter_oaInstTerm(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaIter_oaInstTerm* result= new oaIter_oaInstTerm(data.DataCall()->getInstTerms(p1.Data()));
            return PyoaIter_oaInstTerm_FromoaIter_oaInstTerm(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInst, function: getInstTermsIter, Choices are:\n"
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
static char oaInst_getLibName_doc[] = 
"Class: oaInst, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name for the master design referenced by this instance.\n"
"    libName\n"
"    The library name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name in the given namespace for the master design referenced by this instance.\n"
"    ns\n"
"    The namespace for the library name\n"
"    libName\n"
"    The library name for the master design\n"
;

static PyObject*
oaInst_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaInst, function: getLibName, Choices are:\n"
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
static char oaInst_getName_doc[] = 
"Class: oaInst, Function: getName\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getName(oaSimpleName& name) const\n"
"    Signature: getName|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function fills out name with the name of this instance.\n"
"    name\n"
"    The returned instance name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function fills out name with the name of this instance. The name is mapped according to the specified nameSpace.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    name\n"
"    The returned instance name\n"
;

static PyObject*
oaInst_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaSimpleName)
    {
        PyParamoaSimpleName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSimpleName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
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
            data.DataCall()->getName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInst, function: getName, Choices are:\n"
        "    (oaSimpleName)\n"
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
static char oaInst_getNumBits_doc[] = 
"Class: oaInst, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits of this instance. This function always returns '1' for scalar and array instances. The function can return '1' or more for vector instances.\n"
;

static PyObject*
oaInst_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaInst_getOccInst_doc[] = 
"Class: oaInst, Function: getOccInst\n"
"  Paramegers: ()\n"
"    Calls: oaOccInst* getOccInst() const\n"
"    Signature: getOccInst|ptr-oaOccInst|\n"
"    BrowseData: 1\n"
"    This function returns the occurrence instance that is the reflection of this block instance in the context of the top occurrence of the design that contains the instance.\n"
;

static PyObject*
oaInst_getOccInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstp result= (data.DataCall()->getOccInst());
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
static char oaInst_getOccInsts_doc[] = 
"Class: oaInst, Function: getOccInsts\n"
"  Paramegers: (oaOccurrence)\n"
"    Calls: oaCollection_oaOccInst_oaInst getOccInsts(const oaOccurrence* top) const\n"
"    Signature: getOccInsts|simple-oaCollection_oaOccInst_oaInst|cptr-oaOccurrence,\n"
"    This function returns a collection of the occInsts that are occurrences of this instance in the occurrence hierarchy identified by top . The top occurrence does not have to be in the same design as the given instance.\n"
"    top\n"
"    the top occurrence\n"
;

static PyObject*
oaInst_getOccInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOccurrence p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccurrence_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaCollection_oaOccInst_oaInst* result= new oaCollection_oaOccInst_oaInst(data.DataCall()->getOccInsts(p1.Data()));
        return PyoaCollection_oaOccInst_oaInst_FromoaCollection_oaOccInst_oaInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getOccInstsIter_doc[] = 
"Class: oaInst, Function: getOccInstsIter\n"
"  Paramegers: (oaOccurrence)\n"
"    Calls: oaIter_oaOccInst getOccInstsIter(const oaOccurrence* top) const\n"
"    Signature: getOccInstsIter|simple-oaIter_oaOccInst|cptr-oaOccurrence,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the occInsts that are occurrences of this instance in the occurrence hierarchy identified by top . The top occurrence does not have to be in the same design as the given instance.\n"
"    top\n"
"    the top occurrence\n"
;

static PyObject*
oaInst_getOccInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOccurrence p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccurrence_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaIter_oaOccInst* result= new oaIter_oaOccInst(data.DataCall()->getOccInsts(p1.Data()));
        return PyoaIter_oaOccInst_FromoaIter_oaOccInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getParams_doc[] = 
"Class: oaInst, Function: getParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getParams(oaParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the parameters of this instance. Only Pcell instances have parameters. This call only returns parameters that were specified during creation or through calls to setParams() . If invoked on an inst that is not a Pcell or if no parameter is specified for the instance, the returned params paramArray will have a numParams of zero.\n"
;

static PyObject*
oaInst_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
static char oaInst_getPlacementStatus_doc[] = 
"Class: oaInst, Function: getPlacementStatus\n"
"  Paramegers: ()\n"
"    Calls: oaPlacementStatus getPlacementStatus() const\n"
"    Signature: getPlacementStatus|simple-oaPlacementStatus|\n"
"    BrowseData: 1\n"
"    This function returns the placement status for this instance.\n"
;

static PyObject*
oaInst_getPlacementStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPlacementStatus* result= new oaPlacementStatus(data.DataCall()->getPlacementStatus());
        return PyoaPlacementStatus_FromoaPlacementStatus(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getPriority_doc[] = 
"Class: oaInst, Function: getPriority\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getPriority() const\n"
"    Signature: getPriority|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the placement priority for this instance.\n"
;

static PyObject*
oaInst_getPriority(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getPriority());
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
static char oaInst_getSource_doc[] = 
"Class: oaInst, Function: getSource\n"
"  Paramegers: ()\n"
"    Calls: oaSource getSource() const\n"
"    Signature: getSource|simple-oaSource|\n"
"    BrowseData: 1\n"
"    This function returns the source for this instance. This is used to indicate where the instance was created.\n"
;

static PyObject*
oaInst_getSource(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaSource* result= new oaSource(data.DataCall()->getSource());
        return PyoaSource_FromoaSource(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_getUsage_doc[] = 
"Class: oaInst, Function: getUsage\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getUsage() const\n"
"    Signature: getUsage|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns a bit mask that indicates certain special reasons that instances can be used in a design. The defined bits are:\n"
"    oacInstUsageFeedthru this instance simply connects its inputs to its outputs oacInstUsageSpare this instance is a spare that is not currently used in the design's function oacInstUsageJTag this instance is part of the JTAG test structures added to the design\n"
"    These bits may be or'ed together in the value returned.\n"
;

static PyObject*
oaInst_getUsage(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getUsage());
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
static char oaInst_getViewName_doc[] = 
"Class: oaInst, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name for the master design referenced by this instance.\n"
"    viewName\n"
"    The view name for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name in the given namespace for the master design referenced by this instance.\n"
"    ns\n"
"    The namespace for the name\n"
"    viewName\n"
"    The view name for the master design\n"
;

static PyObject*
oaInst_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaInst, function: getViewName, Choices are:\n"
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
static char oaInst_isImplicit_doc[] = 
"Class: oaInst, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this instance is implicit, having been automatically created as a result of the creation of a vectorInst.\n"
;

static PyObject*
oaInst_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
static char oaInst_removeFromCluster_doc[] = 
"Class: oaInst, Function: removeFromCluster\n"
"  Paramegers: ()\n"
"    Calls: void removeFromCluster()\n"
"    Signature: removeFromCluster|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this instance from the cluster with which it is associated. If this instance is not associated with a cluster, this function does nothing.\n"
;

static PyObject*
oaInst_removeFromCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->removeFromCluster();
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
static char oaInst_scalarize_doc[] = 
"Class: oaInst, Function: scalarize\n"
"  Paramegers: ()\n"
"    Calls: void scalarize()\n"
"    Signature: scalarize|void-void|\n"
"    BrowseData: 0\n"
"    This function insures that the bitInsts associated with this instance have been promoted to the explicit state so that they can support implementation data.\n"
"    If this instance is a multibit instance, this function insures that all constituent bitInsts are promoted to the explicit state. The multibit instance is then demoted to the implicit state so that no implementation data can be associated with it. When an instance is demoted to the implicit state, associated implementation data is removed from it.\n"
"    When an instance is scalarized, all of its connections are also scalarized. Each bit of any multi-bit connection associated with the instance is promoted to the explicit state and is available for editing.\n"
;

static PyObject*
oaInst_scalarize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->scalarize();
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
static char oaInst_setMaster_doc[] = 
"Class: oaInst, Function: setMaster\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void setMaster(const oaDesign* master)\n"
"    Signature: setMaster|void-void|cptr-oaDesign,\n"
"    This function sets the master of this instance. This version sets the master to the specified design.\n"
"    master\n"
"    The pointer to the new instance master\n"
"    oacInvalidSuperMaster\n"
"    oacCannotSetMasterImplicitInst\n"
"    oacInstMustBeInUniqueOccHier\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void setMaster(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: setMaster|void-void|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function sets the master of this instance. This version sets the master to the design specified by the specified library, cell, and view names and does not force the master to open.\n"
"    libName\n"
"    The library name for the new instance master\n"
"    cellName\n"
"    The cell name for the new instance master\n"
"    viewName\n"
"    The view name for the new instance master\n"
"    oacCannotSetMasterImplicitInst\n"
"    oacInstMustBeInUniqueOccHier\n"
;

static PyObject*
oaInst_setMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaDesign)
    {
        PyParamoaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDesign_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->setMaster(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaScalarName,oaScalarName)
    {
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
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInst, function: setMaster, Choices are:\n"
        "    (oaDesign)\n"
        "    (oaScalarName,oaScalarName,oaScalarName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInst_setParams_doc[] = 
"Class: oaInst, Function: setParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void setParams(const oaParamArray& params)\n"
"    Signature: setParams|void-void|cref-oaParamArray,\n"
"    This function sets the parameters of this instance to the specified list. If this instance already has parameters attached to it, the existing parameters are replaced.\n"
"    The oaParamArray is any subset of the master's oaParamArray definition. Any parameter omitted becomes a default parameter and gets its value from the superMaster.\n"
"    Note: Any parameter included in the params array that is not defined in the master's oaParamArray definition (whose name and type is not found in the master's definition) is ignored. Also note that such an unused param will be used later when that param is added to param set defined on the master.\n"
"    params\n"
"    The array of parameters to apply to the instance\n"
"    oacInvalidPcellMaster\n"
"    oacPcellMasterNotBound\n"
"    oacCannotSetParamsImplicitInst\n"
"    oacInstMustBeInUniqueOccHier\n"
;

static PyObject*
oaInst_setParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
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
static char oaInst_setPlacementStatus_doc[] = 
"Class: oaInst, Function: setPlacementStatus\n"
"  Paramegers: (oaPlacementStatus)\n"
"    Calls: void setPlacementStatus(oaPlacementStatus status)\n"
"    Signature: setPlacementStatus|void-void|simple-oaPlacementStatus,\n"
"    This function sets the placement status of this instance to the specified value.\n"
"    status\n"
"    The new placement status for the instance\n"
"    oacCannotSetPlacementStatusImplicitInst\n"
;

static PyObject*
oaInst_setPlacementStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPlacementStatus p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPlacementStatus_Convert,&p1)) {
        data.DataCall()->setPlacementStatus(p1.Data());
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
static char oaInst_setPriority_doc[] = 
"Class: oaInst, Function: setPriority\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setPriority(oaUInt4 priority)\n"
"    Signature: setPriority|void-void|simple-oaUInt4,\n"
"    This function sets the priority for this instance to the specified value. The priority is used during placement.\n"
"    oacCannotSetPriorityImplicitInst\n"
;

static PyObject*
oaInst_setPriority(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setPriority(p1.Data());
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
static char oaInst_setSource_doc[] = 
"Class: oaInst, Function: setSource\n"
"  Paramegers: (oaSource)\n"
"    Calls: void setSource(oaSource source)\n"
"    Signature: setSource|void-void|simple-oaSource,\n"
"    This function sets the source for this instance to the specified value. The source is used to indicate where the instance was created.\n"
"    oacCannotSetSourceImplicitInst\n"
;

static PyObject*
oaInst_setSource(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSource p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSource_Convert,&p1)) {
        data.DataCall()->setSource(p1.Data());
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
static char oaInst_setUsage_doc[] = 
"Class: oaInst, Function: setUsage\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setUsage(oaUInt4 usage)\n"
"    Signature: setUsage|void-void|simple-oaUInt4,\n"
"    This function sets a bit mask that indicates certain special reasons for instances to be created in a design. See oaInst::getUsage for details.\n"
"    oacCannotSetUsageImplicitInst\n"
;

static PyObject*
oaInst_setUsage(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setUsage(p1.Data());
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
static char oaInst_usesTermPositions_doc[] = 
"Class: oaInst, Function: usesTermPositions\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean usesTermPositions() const\n"
"    Signature: usesTermPositions|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating how connections to this instance have been made. If the instTerms associated with this instance connect to terminal positions, this function returns 'true'. Otherwise, this function returns 'false'. Note that if the collection of instTerms for this instance is empty, this function will also return 'false'.\n"
;

static PyObject*
oaInst_usesTermPositions(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstObject* self=(PyoaInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->usesTermPositions());
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
static char oaInst_isNull_doc[] =
"Class: oaInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInst data;
    int convert_status=PyoaInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInst_assign_doc[] = 
"Class: oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInst data;
  int convert_status=PyoaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInst_methodlist[] = {
    {"addToCluster",(PyCFunction)oaInst_addToCluster,METH_VARARGS,oaInst_addToCluster_doc},
    {"findParam",(PyCFunction)oaInst_findParam,METH_VARARGS,oaInst_findParam_doc},
    {"getAssignments",(PyCFunction)oaInst_getAssignments,METH_VARARGS,oaInst_getAssignments_doc},
    {"getAssignmentsIter",(PyCFunction)oaInst_getAssignmentsIter,METH_VARARGS,oaInst_getAssignmentsIter_doc},
    {"getBlockagesOwnedBy",(PyCFunction)oaInst_getBlockagesOwnedBy,METH_VARARGS,oaInst_getBlockagesOwnedBy_doc},
    {"getBlockagesOwnedByIter",(PyCFunction)oaInst_getBlockagesOwnedByIter,METH_VARARGS,oaInst_getBlockagesOwnedByIter_doc},
    {"getCellName",(PyCFunction)oaInst_getCellName,METH_VARARGS,oaInst_getCellName_doc},
    {"getCluster",(PyCFunction)oaInst_getCluster,METH_VARARGS,oaInst_getCluster_doc},
    {"getHeader",(PyCFunction)oaInst_getHeader,METH_VARARGS,oaInst_getHeader_doc},
    {"getInstTerms",(PyCFunction)oaInst_getInstTerms,METH_VARARGS,oaInst_getInstTerms_doc},
    {"getInstTermsIter",(PyCFunction)oaInst_getInstTermsIter,METH_VARARGS,oaInst_getInstTermsIter_doc},
    {"getLibName",(PyCFunction)oaInst_getLibName,METH_VARARGS,oaInst_getLibName_doc},
    {"getName",(PyCFunction)oaInst_getName,METH_VARARGS,oaInst_getName_doc},
    {"getNumBits",(PyCFunction)oaInst_getNumBits,METH_VARARGS,oaInst_getNumBits_doc},
    {"getOccInst",(PyCFunction)oaInst_getOccInst,METH_VARARGS,oaInst_getOccInst_doc},
    {"getOccInsts",(PyCFunction)oaInst_getOccInsts,METH_VARARGS,oaInst_getOccInsts_doc},
    {"getOccInstsIter",(PyCFunction)oaInst_getOccInstsIter,METH_VARARGS,oaInst_getOccInstsIter_doc},
    {"getParams",(PyCFunction)oaInst_getParams,METH_VARARGS,oaInst_getParams_doc},
    {"getPlacementStatus",(PyCFunction)oaInst_getPlacementStatus,METH_VARARGS,oaInst_getPlacementStatus_doc},
    {"getPriority",(PyCFunction)oaInst_getPriority,METH_VARARGS,oaInst_getPriority_doc},
    {"getSource",(PyCFunction)oaInst_getSource,METH_VARARGS,oaInst_getSource_doc},
    {"getUsage",(PyCFunction)oaInst_getUsage,METH_VARARGS,oaInst_getUsage_doc},
    {"getViewName",(PyCFunction)oaInst_getViewName,METH_VARARGS,oaInst_getViewName_doc},
    {"isImplicit",(PyCFunction)oaInst_isImplicit,METH_VARARGS,oaInst_isImplicit_doc},
    {"removeFromCluster",(PyCFunction)oaInst_removeFromCluster,METH_VARARGS,oaInst_removeFromCluster_doc},
    {"scalarize",(PyCFunction)oaInst_scalarize,METH_VARARGS,oaInst_scalarize_doc},
    {"setMaster",(PyCFunction)oaInst_setMaster,METH_VARARGS,oaInst_setMaster_doc},
    {"setParams",(PyCFunction)oaInst_setParams,METH_VARARGS,oaInst_setParams_doc},
    {"setPlacementStatus",(PyCFunction)oaInst_setPlacementStatus,METH_VARARGS,oaInst_setPlacementStatus_doc},
    {"setPriority",(PyCFunction)oaInst_setPriority,METH_VARARGS,oaInst_setPriority_doc},
    {"setSource",(PyCFunction)oaInst_setSource,METH_VARARGS,oaInst_setSource_doc},
    {"setUsage",(PyCFunction)oaInst_setUsage,METH_VARARGS,oaInst_setUsage_doc},
    {"usesTermPositions",(PyCFunction)oaInst_usesTermPositions,METH_VARARGS,oaInst_usesTermPositions_doc},
    {"isNull",(PyCFunction)oaInst_tp_isNull,METH_VARARGS,oaInst_isNull_doc},
    {"assign",(PyCFunction)oaInst_tp_assign,METH_VARARGS,oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInst_doc[] = 
"Class: oaInst\n"
"  The oaInst class is an abstract base class for block domain instances. An instance represents the inclusion of one design as a part of the contents of another. The design containing the instance is the parent design and the design that is included is the master of the instance.\n"
"  oaInst objects are always in the block domain. Thus they are contained in an oaBlock object. An oaInst may have one or more equivalent module instances in the module hierarchy and will have an equivalent oaOccInst in the occurrence hierarchy.\n"
"  You can use instances to create hierarchical designs. The master of an instance can contain instances of other masters. This hierarchy can continue for as many levels as needed to express a complete design.\n"
"  You can use instances to represent complex pin figures. These are often used in schematics where a shape more complicated than a polygon is wanted.\n"
"  All instances have names. These names can be assigned by the creator. For scalar inst, instance names can be automatically assigned by the database.\n"
"  Instances always have an oaInstHeader , which contains the attributes that are constant for all instances of a given master.\n"
"  Instances of Pcells include a set of parameters values used to tailor the Pcell for each specific instance. A Pcell instance can be created with a subset of the parameters defined in the superMaster. Any parameters not specified will become default parameters, which will track changes in the superMaster's parameter value. When a parameter is specified during creation or any subsequence calls to setParam(), this parameter will not be classified as a default parameter even though its value is equal to the default value in the superMaster.\n"
"  The superMaster of pcell Instances will be bound when they are created so that OpenAccess can verify the parameters supplied. If the binding fails, an oacParamsSuppliedForNonPCellInstMaster exception will be thrown.\n"
"  The oaInst class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaInst)\n"
"    Calls: (const oaInst&)\n"
"    Signature: oaInst||cref-oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInst",
    sizeof(PyoaInstObject),
    0,
    (destructor)oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInst_static_find_doc[] = 
"Class: oaInst, Function: find\n"
"  Paramegers: (oaBlock,oaSimpleName)\n"
"    Calls: oaInst* find(const oaBlock* block,const oaSimpleName& name)\n"
"    Signature: find|ptr-oaInst|cptr-oaBlock,cref-oaSimpleName,\n"
"    This function searches the specified block for an instance with the specified name. If found, the instance is returned. Otherwise, NULL is returned.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The instance name to find\n"
"    A pointer to the instance, if found; otherwise, NULL\n"
;

static PyObject*
oaInst_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaSimpleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaSimpleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaInstp result= (oaInst::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaInst_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaInst_static_find,METH_VARARGS,oaInst_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInst",
           (PyObject*)(&PyoaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInst_Type.tp_dict;
    for(method=oaInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInstAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstAttrDisplayObject* self = (PyoaInstAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstAttrDisplay)
    {
        PyParamoaInstAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstAttrDisplay_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInstAttrDisplay, Choices are:\n"
        "    (oaInstAttrDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstAttrDisplay_tp_dealloc(PyoaInstAttrDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaInstAttrDisplay value;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaInstAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInstAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstAttrDisplay v1;
    PyParamoaInstAttrDisplay v2;
    int convert_status1=PyoaInstAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaInstAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstAttrDisplay_Convert(PyObject* ob,PyParamoaInstAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstAttrDisplay_Check(ob)) {
        result->SetData( (oaInstAttrDisplay**) ((PyoaInstAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstAttrDisplay_FromoaInstAttrDisplay(oaInstAttrDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInstAttrDisplay* data=*value;
        PyObject* bself = PyoaInstAttrDisplay_Type.tp_alloc(&PyoaInstAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaInstAttrDisplayObject* self = (PyoaInstAttrDisplayObject*)bself;
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
PyObject* PyoaInstAttrDisplay_FromoaInstAttrDisplay(oaInstAttrDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaInstAttrDisplay_Type.tp_alloc(&PyoaInstAttrDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaInstAttrDisplayObject* self = (PyoaInstAttrDisplayObject*)bself;
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
static char oaInstAttrDisplay_getInst_doc[] = 
"Class: oaInstAttrDisplay, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns the instance associated with this instAttrDisplay object.\n"
;

static PyObject*
oaInstAttrDisplay_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrDisplay data;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrDisplayObject* self=(PyoaInstAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getInst());
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
static char oaInstAttrDisplay_getMasterAttribute_doc[] = 
"Class: oaInstAttrDisplay, Function: getMasterAttribute\n"
"  Paramegers: ()\n"
"    Calls: oaDesignAttrType getMasterAttribute() const\n"
"    Signature: getMasterAttribute|simple-oaDesignAttrType|\n"
"    BrowseData: 1\n"
"    This function returns the attribute referenced by this attrDisplay object.\n"
;

static PyObject*
oaInstAttrDisplay_getMasterAttribute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrDisplay data;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrDisplayObject* self=(PyoaInstAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignAttrType* result= new oaDesignAttrType(data.DataCall()->getMasterAttribute());
        return PyoaDesignAttrType_FromoaDesignAttrType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstAttrDisplay_getText_doc[] = 
"Class: oaInstAttrDisplay, Function: getText\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getText(const oaNameSpace& ns,oaString& text) const\n"
"    Signature: getText|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the value of this attribute display according to the specified nameSpace. The nameSpace is valid only for name type attributes.\n"
;

static PyObject*
oaInstAttrDisplay_getText(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrDisplay data;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrDisplayObject* self=(PyoaInstAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaNameSpace p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNameSpace_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        data.DataCall()->getText(p1.Data(),p2.Data());
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
static char oaInstAttrDisplay_isBound_doc[] = 
"Class: oaInstAttrDisplay, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean that indicates if this attribute display is currently bound.\n"
;

static PyObject*
oaInstAttrDisplay_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrDisplay data;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrDisplayObject* self=(PyoaInstAttrDisplayObject*)ob;
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
static char oaInstAttrDisplay_isNull_doc[] =
"Class: oaInstAttrDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInstAttrDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInstAttrDisplay data;
    int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInstAttrDisplay_assign_doc[] = 
"Class: oaInstAttrDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstAttrDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstAttrDisplay data;
  int convert_status=PyoaInstAttrDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstAttrDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstAttrDisplay_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstAttrDisplay_methodlist[] = {
    {"getInst",(PyCFunction)oaInstAttrDisplay_getInst,METH_VARARGS,oaInstAttrDisplay_getInst_doc},
    {"getMasterAttribute",(PyCFunction)oaInstAttrDisplay_getMasterAttribute,METH_VARARGS,oaInstAttrDisplay_getMasterAttribute_doc},
    {"getText",(PyCFunction)oaInstAttrDisplay_getText,METH_VARARGS,oaInstAttrDisplay_getText_doc},
    {"isBound",(PyCFunction)oaInstAttrDisplay_isBound,METH_VARARGS,oaInstAttrDisplay_isBound_doc},
    {"isNull",(PyCFunction)oaInstAttrDisplay_tp_isNull,METH_VARARGS,oaInstAttrDisplay_isNull_doc},
    {"assign",(PyCFunction)oaInstAttrDisplay_tp_assign,METH_VARARGS,oaInstAttrDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstAttrDisplay_doc[] = 
"Class: oaInstAttrDisplay\n"
"  The oaInstAttrDisplay is a shape similar to an oaText object, except that it presents a string that is the value of the specified attribute of the master of the oaInst to which it is attached. Whenever the value of the master's attribute changes, calling the getText function on this oaInstAttrDisplay object returns the updated text string that represents the new value of the master's attribute.\n"
"  The oaAttrDisplay is contained in the design that contains the attached oaInst object.\n"
"Constructors:\n"
"  Paramegers: (oaInstAttrDisplay)\n"
"    Calls: (const oaInstAttrDisplay&)\n"
"    Signature: oaInstAttrDisplay||cref-oaInstAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstAttrDisplay",
    sizeof(PyoaInstAttrDisplayObject),
    0,
    (destructor)oaInstAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaInstAttrDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstAttrDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstAttrDisplay_static_create_doc[] = 
"Class: oaInstAttrDisplay, Function: create\n"
"  Paramegers: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
"    Calls: oaInstAttrDisplay* create(oaInst* inst,oaDesignAttrType masterAttribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height)\n"
"    Signature: create|ptr-oaInstAttrDisplay|ptr-oaInst,simple-oaDesignAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instAttrDisplay object for the specified attribute that is on the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterAttribute\n"
"    The attribute associated with this attrDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this textDisplay\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: You must be able to open the instance's master for this function to succeed.\n"
"    oacInvalidTextDisplayCopy\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
"    Calls: oaInstAttrDisplay* create(oaInst* inst,oaDesignAttrType masterAttribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format)\n"
"    Signature: create|ptr-oaInstAttrDisplay|ptr-oaInst,simple-oaDesignAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instAttrDisplay object for the specified attribute that is on the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterAttribute\n"
"    The attribute associated with this attrDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this textDisplay\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: You must be able to open the instance's master for this function to succeed.\n"
"    oacInvalidTextDisplayCopy\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
"    Calls: oaInstAttrDisplay* create(oaInst* inst,oaDesignAttrType masterAttribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar)\n"
"    Signature: create|ptr-oaInstAttrDisplay|ptr-oaInst,simple-oaDesignAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instAttrDisplay object for the specified attribute that is on the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterAttribute\n"
"    The attribute associated with this attrDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this textDisplay\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: You must be able to open the instance's master for this function to succeed.\n"
"    oacInvalidTextDisplayCopy\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
"    Calls: oaInstAttrDisplay* create(oaInst* inst,oaDesignAttrType masterAttribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible)\n"
"    Signature: create|ptr-oaInstAttrDisplay|ptr-oaInst,simple-oaDesignAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instAttrDisplay object for the specified attribute that is on the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterAttribute\n"
"    The attribute associated with this attrDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this textDisplay\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: You must be able to open the instance's master for this function to succeed.\n"
"    oacInvalidTextDisplayCopy\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
"    Calls: oaInstAttrDisplay* create(oaInst* inst,oaDesignAttrType masterAttribute,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible,oaBoolean drafting)\n"
"    Signature: create|ptr-oaInstAttrDisplay|ptr-oaInst,simple-oaDesignAttrType,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instAttrDisplay object for the specified attribute that is on the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterAttribute\n"
"    The attribute associated with this attrDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this textDisplay\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: You must be able to open the instance's master for this function to succeed.\n"
"    oacInvalidTextDisplayCopy\n"
"    oacPropNotOnInstanceMaster\n"
;

static PyObject*
oaInstAttrDisplay_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)
    {
        PyParamoaInst p1;
        PyParamoaDesignAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaDesignAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstAttrDisplayp result= (oaInstAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data()));
            return PyoaInstAttrDisplay_FromoaInstAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)
    {
        PyParamoaInst p1;
        PyParamoaDesignAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaDesignAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstAttrDisplayp result= (oaInstAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data()));
            return PyoaInstAttrDisplay_FromoaInstAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaDesignAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaDesignAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstAttrDisplayp result= (oaInstAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data()));
            return PyoaInstAttrDisplay_FromoaInstAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaDesignAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaDesignAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstAttrDisplayp result= (oaInstAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data()));
            return PyoaInstAttrDisplay_FromoaInstAttrDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaDesignAttrType p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        PyParamoaBoolean p13;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaDesignAttrType_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12,
              &PyoaBoolean_Convert,&p13)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstAttrDisplayp result= (oaInstAttrDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data(),p13.Data()));
            return PyoaInstAttrDisplay_FromoaInstAttrDisplay(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstAttrDisplay, function: create, Choices are:\n"
        "    (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
        "    (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
        "    (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
        "    (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
        "    (oaInst,oaDesignAttrType,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaInstAttrDisplay_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaInstAttrDisplay_static_create,METH_VARARGS,oaInstAttrDisplay_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaInstAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstAttrDisplay",
           (PyObject*)(&PyoaInstAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstAttrDisplay\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInstAttrDisplay_Type.tp_dict;
    for(method=oaInstAttrDisplay_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInstAttrType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstAttrType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstAttrType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstAttrTypeObject* self = (PyoaInstAttrTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstAttrTypeEnum)
    {
        PyParamoaInstAttrTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaInstAttrTypeEnum_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAttrType)
    {
        PyParamoaAttrType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAttrType_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaInstAttrType)
    {
        PyParamoaInstAttrType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstAttrType_Convert,&p1)) {
            self->value=(oaAttrType*)  new oaInstAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaInstAttrType, Choices are:\n"
        "    (oaInstAttrTypeEnum)\n"
        "    (oaString)\n"
        "    (oaAttrType)\n"
        "    (oaInstAttrType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstAttrType_tp_dealloc(PyoaInstAttrTypeObject* self)
{
    if (!self->borrow) {
        delete (oaInstAttrType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstAttrType_tp_repr(PyObject *ob)
{
    PyParamoaInstAttrType value;
    int convert_status=PyoaInstAttrType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[36];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaInstAttrType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInstAttrType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstAttrType v1;
    PyParamoaInstAttrType v2;
    int convert_status1=PyoaInstAttrType_Convert(ob1,&v1);
    int convert_status2=PyoaInstAttrType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstAttrType_Convert(PyObject* ob,PyParamoaInstAttrType* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstAttrType_Check(ob)) {
        result->SetData( (oaInstAttrType*) ((PyoaInstAttrTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstAttrType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstAttrType_FromoaInstAttrType(oaInstAttrType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaInstAttrType_Type.tp_alloc(&PyoaInstAttrType_Type,0);
        if (bself == NULL) return bself;
        PyoaInstAttrTypeObject* self = (PyoaInstAttrTypeObject*)bself;
        self->value = (oaAttrType*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstAttrType_getName_doc[] = 
"Class: oaInstAttrType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaInstAttrTypeEnum object.\n"
;

static PyObject*
oaInstAttrType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrType data;
    int convert_status=PyoaInstAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrTypeObject* self=(PyoaInstAttrTypeObject*)ob;

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
static char oaInstAttrType_getValue_doc[] = 
"Class: oaInstAttrType, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaInstAttrTypeEnum getValue() const\n"
"    Signature: getValue|simple-oaInstAttrTypeEnum|\n"
"    BrowseData: 1\n"
"    This function returns the value string of this instance attribute type.\n"
;

static PyObject*
oaInstAttrType_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstAttrType data;
    int convert_status=PyoaInstAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstAttrTypeObject* self=(PyoaInstAttrTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstAttrTypeEnum result= (data.DataCall()->getValue());
        return PyoaInstAttrTypeEnum_FromoaInstAttrTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaInstAttrType_assign_doc[] = 
"Class: oaInstAttrType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstAttrType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstAttrType data;
  int convert_status=PyoaInstAttrType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstAttrType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstAttrType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstAttrType_methodlist[] = {
    {"getName",(PyCFunction)oaInstAttrType_getName,METH_VARARGS,oaInstAttrType_getName_doc},
    {"getValue",(PyCFunction)oaInstAttrType_getValue,METH_VARARGS,oaInstAttrType_getValue_doc},
    {"assign",(PyCFunction)oaInstAttrType_tp_assign,METH_VARARGS,oaInstAttrType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstAttrType_doc[] = 
"Class: oaInstAttrType\n"
"  The oaInstAttrType class is an enum wrapper that specifies the various attributes of an instance that can be displayed by an oaAttrDisplay associated with an instance.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaInstAttrTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaInstAttrTypeEnum)\n"
"    Calls: oaInstAttrType(oaInstAttrTypeEnum valueIn)\n"
"    Signature: oaInstAttrType||simple-oaInstAttrTypeEnum,\n"
"    This function constructs an instance of an oaInstAttrType class using the specified #oaInstAttrTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaInstAttrType(const oaString& name)\n"
"    Signature: oaInstAttrType||cref-oaString,\n"
"    This function constructs an instance of an oaInstAttrType class using the #oaInstAttrTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaInstAttrTypeEnum.\n"
"    oacInvalidInstAttrTypeName\n"
"  Paramegers: (oaAttrType)\n"
"    Calls: oaInstAttrType(oaAttrType attr)\n"
"    Signature: oaInstAttrType||simple-oaAttrType,\n"
"    This function constructs an oaInstAttrType class using the oaAttrType as input to support the class down-cast.\n"
"    attr\n"
"    The attribute type to use\n"
"  Paramegers: (oaInstAttrType)\n"
"    Calls: (const oaInstAttrType&)\n"
"    Signature: oaInstAttrType||cref-oaInstAttrType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstAttrType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstAttrType",
    sizeof(PyoaInstAttrTypeObject),
    0,
    (destructor)oaInstAttrType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstAttrType_tp_compare,	/* tp_compare */
    (reprfunc)oaInstAttrType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstAttrType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstAttrType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAttrType_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstAttrType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstAttrType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstAttrType_Type)<0) {
      printf("** PyType_Ready failed for: oaInstAttrType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstAttrType",
           (PyObject*)(&PyoaInstAttrType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstAttrType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaInstAttrTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaInstAttrTypeEnum_Convert(PyObject* ob,PyParamoaInstAttrTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacLibNameInstAttrType")==0) { result->SetData(oacLibNameInstAttrType); return 1;}
        if (strcasecmp(str,"oacCellNameInstAttrType")==0) { result->SetData(oacCellNameInstAttrType); return 1;}
        if (strcasecmp(str,"oacViewNameInstAttrType")==0) { result->SetData(oacViewNameInstAttrType); return 1;}
        if (strcasecmp(str,"oacNameInstAttrType")==0) { result->SetData(oacNameInstAttrType); return 1;}
        if (strcasecmp(str,"oacNumBitsInstAttrType")==0) { result->SetData(oacNumBitsInstAttrType); return 1;}
        if (strcasecmp(str,"oacIsBoundInstAttrType")==0) { result->SetData(oacIsBoundInstAttrType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaInstAttrTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstAttrTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaInstAttrTypeEnum_FromoaInstAttrTypeEnum(oaInstAttrTypeEnum ob)
{
    if (ob==oacLibNameInstAttrType) return PyString_FromString("oacLibNameInstAttrType");
    if (ob==oacCellNameInstAttrType) return PyString_FromString("oacCellNameInstAttrType");
    if (ob==oacViewNameInstAttrType) return PyString_FromString("oacViewNameInstAttrType");
    if (ob==oacNameInstAttrType) return PyString_FromString("oacNameInstAttrType");
    if (ob==oacNumBitsInstAttrType) return PyString_FromString("oacNumBitsInstAttrType");
    if (ob==oacIsBoundInstAttrType) return PyString_FromString("oacIsBoundInstAttrType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaInstAttrTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaInstAttrTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaInstAttrTypeEnum_FromoaInstAttrTypeEnum(oaInstAttrTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaInstAttrTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaInstAttrTypeEnum_doc[] =
"Type convert function for enum: oaInstAttrTypeEnum";
                               
static PyMethodDef PyoaInstAttrTypeEnum_method =
  {"oaInstAttrTypeEnum",(PyCFunction)PyoaInstAttrTypeEnum_TypeFunction,METH_VARARGS,oaInstAttrTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaInstAttrTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacLibNameInstAttrType");
    PyDict_SetItemString(mod_dict,"oacLibNameInstAttrType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCellNameInstAttrType");
    PyDict_SetItemString(mod_dict,"oacCellNameInstAttrType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViewNameInstAttrType");
    PyDict_SetItemString(mod_dict,"oacViewNameInstAttrType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNameInstAttrType");
    PyDict_SetItemString(mod_dict,"oacNameInstAttrType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNumBitsInstAttrType");
    PyDict_SetItemString(mod_dict,"oacNumBitsInstAttrType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacIsBoundInstAttrType");
    PyDict_SetItemString(mod_dict,"oacIsBoundInstAttrType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaInstAttrTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaInstAttrTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaInstAttrTypeEnum\n");
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
// Wrapper Implementation for Class: oaInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstHeaderObject* self = (PyoaInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstHeader)
    {
        PyParamoaInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInstHeader, Choices are:\n"
        "    (oaInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstHeader_tp_dealloc(PyoaInstHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaInstHeader value;
    int convert_status=PyoaInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaInstHeader::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        oaString sep=" ";
        sep[(oaUInt4)0]=oacInternalHierDelimiter;
        oaScalarName name;
        oaString str;
        value.DataCall()->getLibName(name);
        name.get(str);
        sresult+=oaString(str);
        sresult+=sep;
        value.DataCall()->getCellName(name);
        name.get(str);
        sresult+=oaString(str);
        sresult+=sep;
        value.DataCall()->getViewName(name);
        name.get(str);
        sresult+=oaString(str);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaInstHeader::");
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
oaInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstHeader v1;
    PyParamoaInstHeader v2;
    int convert_status1=PyoaInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstHeader_Convert(PyObject* ob,PyParamoaInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstHeader_Check(ob)) {
        result->SetData( (oaInstHeader**) ((PyoaInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstHeader_FromoaInstHeader(oaInstHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInstHeader* data=*value;
        PyObject* bself = PyoaInstHeader_Type.tp_alloc(&PyoaInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaInstHeaderObject* self = (PyoaInstHeaderObject*)bself;
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
PyObject* PyoaInstHeader_FromoaInstHeader(oaInstHeader* data)
{
    if (data) {
       PyObject* bself = PyoaInstHeader_Type.tp_alloc(&PyoaInstHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaInstHeaderObject* self = (PyoaInstHeaderObject*)bself;
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
static char oaInstHeader_findParam_doc[] = 
"Class: oaInstHeader, Function: findParam\n"
"  Paramegers: (oaString,oaParam)\n"
"    Calls: oaBoolean findParam(const oaString& name,oaParam& param)\n"
"    Signature: findParam|simple-oaBoolean|cref-oaString,ref-oaParam,\n"
"    This function searches the parameter list of this inst header looking for a parameter with the specified 'name'. If found, it fills out 'param' with the appropriate attributes and returns true. Otherwise, it returns false.\n"
"    name\n"
"    The name of the parameter to look for\n"
"    param\n"
"    The parameter object to be populated if parameter is found\n"
;

static PyObject*
oaInstHeader_findParam(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    PyParamoaParam p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaParam_Convert,&p2)) {
        oaBoolean result= (data.DataCall()->findParam(p1.Data(),p2.Data()));
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
static char oaInstHeader_getAllParams_doc[] = 
"Class: oaInstHeader, Function: getAllParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getAllParams(oaParamArray& params) const\n"
"    Signature: getAllParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the complete set of parameters associated with this instHeader. The paramArray will contain the params for which this instHeader uses default values and the params for which it uses override values. If this instHeader is not associated with a Pcell master, params will have a numParams of zero.\n"
;

static PyObject*
oaInstHeader_getAllParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
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
static char oaInstHeader_getCellName_doc[] = 
"Class: oaInstHeader, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name of the master oaDesign referenced by this instHeader.\n"
"    cellName\n"
"    The returned cell name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name of the master oaDesign referenced by this instHeader.\n"
"    ns\n"
"    The namespace in which to return the cell name.\n"
"    cellName\n"
"    The returned cell name.\n"
;

static PyObject*
oaInstHeader_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
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
        "No Arg-Matching Function found for class: oaInstHeader, function: getCellName, Choices are:\n"
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
static char oaInstHeader_getInsts_doc[] = 
"Class: oaInstHeader, Function: getInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaInst_oaInstHeader getInsts() const\n"
"    Signature: getInsts|simple-oaCollection_oaInst_oaInstHeader|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a collection of instances associated with this instHeader. The filter flag bits are defined below and may be logically OR'd together to refine the contents of the collection.\n"
"    Note: For a Pcell superHeader, the getInsts() collection will be empty since there are no instances under a superHeader.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bit flags are defined as follows:\n"
"    oacInstIterSingleBit: the collection contains single-bit instances\n"
"    oacInstIterNotImplicit: the collection will not contain any implicitly created instances\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaInst_oaInstHeader getInsts(oaUInt4 filterFlags) const\n"
"    Signature: getInsts|simple-oaCollection_oaInst_oaInstHeader|simple-oaUInt4,\n"
"    This function returns a collection of instances associated with this instHeader. The filter flag bits are defined below and may be logically OR'd together to refine the contents of the collection.\n"
"    Note: For a Pcell superHeader, the getInsts() collection will be empty since there are no instances under a superHeader.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bit flags are defined as follows:\n"
"    oacInstIterSingleBit: the collection contains single-bit instances\n"
"    oacInstIterNotImplicit: the collection will not contain any implicitly created instances\n"
;

static PyObject*
oaInstHeader_getInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaInst_oaInstHeader* result= new oaCollection_oaInst_oaInstHeader(data.DataCall()->getInsts());
            return PyoaCollection_oaInst_oaInstHeader_FromoaCollection_oaInst_oaInstHeader(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaCollection_oaInst_oaInstHeader* result= new oaCollection_oaInst_oaInstHeader(data.DataCall()->getInsts(p1.Data()));
            return PyoaCollection_oaInst_oaInstHeader_FromoaCollection_oaInst_oaInstHeader(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstHeader, function: getInsts, Choices are:\n"
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
static char oaInstHeader_getInstsIter_doc[] = 
"Class: oaInstHeader, Function: getInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaInst getInstsIter() const\n"
"    Signature: getInstsIter|simple-oaIter_oaInst|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of instances associated with this instHeader. The filter flag bits are defined below and may be logically OR'd together to refine the contents of the collection.\n"
"    Note: For a Pcell superHeader, the getInsts() collection will be empty since there are no instances under a superHeader.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bit flags are defined as follows:\n"
"    oacInstIterSingleBit: the collection contains single-bit instances\n"
"    oacInstIterNotImplicit: the collection will not contain any implicitly created instances\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaIter_oaInst getInstsIter(oaUInt4 filterFlags) const\n"
"    Signature: getInstsIter|simple-oaIter_oaInst|simple-oaUInt4,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of instances associated with this instHeader. The filter flag bits are defined below and may be logically OR'd together to refine the contents of the collection.\n"
"    Note: For a Pcell superHeader, the getInsts() collection will be empty since there are no instances under a superHeader.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bit flags are defined as follows:\n"
"    oacInstIterSingleBit: the collection contains single-bit instances\n"
"    oacInstIterNotImplicit: the collection will not contain any implicitly created instances\n"
;

static PyObject*
oaInstHeader_getInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaInst* result= new oaIter_oaInst(data.DataCall()->getInsts());
            return PyoaIter_oaInst_FromoaIter_oaInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaIter_oaInst* result= new oaIter_oaInst(data.DataCall()->getInsts(p1.Data()));
            return PyoaIter_oaInst_FromoaIter_oaInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstHeader, function: getInstsIter, Choices are:\n"
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
static char oaInstHeader_getLibName_doc[] = 
"Class: oaInstHeader, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name of the master oaDesign referenced by this instHeader.\n"
"    libName\n"
"    The returned library name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name of the master oaDesign referenced by this instHeader.\n"
"    ns\n"
"    The namespace in which to return the library name.\n"
"    libName\n"
"    The returned library name.\n"
;

static PyObject*
oaInstHeader_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
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
        "No Arg-Matching Function found for class: oaInstHeader, function: getLibName, Choices are:\n"
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
static char oaInstHeader_getParams_doc[] = 
"Class: oaInstHeader, Function: getParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getParams(oaParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the parameters associated with this instHeader. This call only returns the non-default parameters that were specified during creation or through calls to setParams() on the instances. If this instHeader is not associated with a Pcell master or uses all default parameters, params will have a numParams of zero.\n"
"    Note that params also will have a numParams of zero if the instHeader is a superHeader.\n"
;

static PyObject*
oaInstHeader_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
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
static char oaInstHeader_getSubHeaders_doc[] = 
"Class: oaInstHeader, Function: getSubHeaders\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaInstHeader_oaInstHeader getSubHeaders() const\n"
"    Signature: getSubHeaders|simple-oaCollection_oaInstHeader_oaInstHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of subHeaders in this superHeader.\n"
;

static PyObject*
oaInstHeader_getSubHeaders(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaInstHeader_oaInstHeader* result= new oaCollection_oaInstHeader_oaInstHeader(data.DataCall()->getSubHeaders());
        return PyoaCollection_oaInstHeader_oaInstHeader_FromoaCollection_oaInstHeader_oaInstHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstHeader_getSubHeadersIter_doc[] = 
"Class: oaInstHeader, Function: getSubHeadersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaInstHeader getSubHeadersIter() const\n"
"    Signature: getSubHeadersIter|simple-oaIter_oaInstHeader|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of subHeaders in this superHeader.\n"
;

static PyObject*
oaInstHeader_getSubHeadersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaInstHeader* result= new oaIter_oaInstHeader(data.DataCall()->getSubHeaders());
        return PyoaIter_oaInstHeader_FromoaIter_oaInstHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstHeader_getViewName_doc[] = 
"Class: oaInstHeader, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name of the master oaDesign referenced by this instHeader.\n"
"    viewName\n"
"    The returned view name.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name of the master oaDesign referenced by this instHeader.\n"
"    ns\n"
"    The namespace in which to return the view name.\n"
"    viewName\n"
"    The returned view name.\n"
;

static PyObject*
oaInstHeader_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
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
        "No Arg-Matching Function found for class: oaInstHeader, function: getViewName, Choices are:\n"
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
static char oaInstHeader_setMasterBBox_doc[] = 
"Class: oaInstHeader, Function: setMasterBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void setMasterBBox(const oaBox& bBox)\n"
"    Signature: setMasterBBox|void-void|cref-oaBox,\n"
"    This function sets the bounding box of the master associated with this instHeader to the specified value. This function is a special purpose utility that should only be called when the master cannot or should not be bound, but the bounding box of the master is known.\n"
;

static PyObject*
oaInstHeader_setMasterBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstHeaderObject* self=(PyoaInstHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->setMasterBBox(p1.Data());
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
static char oaInstHeader_isNull_doc[] =
"Class: oaInstHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInstHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInstHeader data;
    int convert_status=PyoaInstHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInstHeader_assign_doc[] = 
"Class: oaInstHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstHeader data;
  int convert_status=PyoaInstHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstHeader_methodlist[] = {
    {"findParam",(PyCFunction)oaInstHeader_findParam,METH_VARARGS,oaInstHeader_findParam_doc},
    {"getAllParams",(PyCFunction)oaInstHeader_getAllParams,METH_VARARGS,oaInstHeader_getAllParams_doc},
    {"getCellName",(PyCFunction)oaInstHeader_getCellName,METH_VARARGS,oaInstHeader_getCellName_doc},
    {"getInsts",(PyCFunction)oaInstHeader_getInsts,METH_VARARGS,oaInstHeader_getInsts_doc},
    {"getInstsIter",(PyCFunction)oaInstHeader_getInstsIter,METH_VARARGS,oaInstHeader_getInstsIter_doc},
    {"getLibName",(PyCFunction)oaInstHeader_getLibName,METH_VARARGS,oaInstHeader_getLibName_doc},
    {"getParams",(PyCFunction)oaInstHeader_getParams,METH_VARARGS,oaInstHeader_getParams_doc},
    {"getSubHeaders",(PyCFunction)oaInstHeader_getSubHeaders,METH_VARARGS,oaInstHeader_getSubHeaders_doc},
    {"getSubHeadersIter",(PyCFunction)oaInstHeader_getSubHeadersIter,METH_VARARGS,oaInstHeader_getSubHeadersIter_doc},
    {"getViewName",(PyCFunction)oaInstHeader_getViewName,METH_VARARGS,oaInstHeader_getViewName_doc},
    {"setMasterBBox",(PyCFunction)oaInstHeader_setMasterBBox,METH_VARARGS,oaInstHeader_setMasterBBox_doc},
    {"isNull",(PyCFunction)oaInstHeader_tp_isNull,METH_VARARGS,oaInstHeader_isNull_doc},
    {"assign",(PyCFunction)oaInstHeader_tp_assign,METH_VARARGS,oaInstHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstHeader_doc[] = 
"Class: oaInstHeader\n"
"  The oaInstHeader class implements an object that contains information common to all the instances of a particular master design in a given parent design.\n"
"  An oaInstHeader is an automatic object that is created and destroyed by the database. An oaInstHeader is automatically created whenever the first inst is created. An oaInstHeader is destroyed when the last inst of it is destroyed.\n"
"  oaInstHeaders are always in the block domain. An oaInstHeader may have one or more equivalents in the module hierarchy and will have an equivalent oaOccInstHeader in the occurrence hierarchy.\n"
"  For instances of Pcells, there are two kinds of instHeaders:\n"
"  SuperHeaders represent all of the instances of a Pcell master, regardless of parameter settings\n"
"  SubHeaders represent all of the instances that have one specific set of parameter values\n"
"  For more information about Pcells, refer to Support for Pcells in the Programmers Guide.\n"
"  Every instance of a Pcell has exactly one subHeader, which, in turn, has exactly one superHeader. InstHeaders for instances that are not Pcells are neither subheaders nor superheaders.\n"
"  The oaInstHeader class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaInstHeader)\n"
"    Calls: (const oaInstHeader&)\n"
"    Signature: oaInstHeader||cref-oaInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstHeader",
    sizeof(PyoaInstHeaderObject),
    0,
    (destructor)oaInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRefHeader_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstHeader_static_find_doc[] = 
"Class: oaInstHeader, Function: find\n"
"  Paramegers: (oaBlock,oaDesign)\n"
"    Calls: oaInstHeader* find(const oaBlock* block,const oaDesign* master)\n"
"    Signature: find|ptr-oaInstHeader|cptr-oaBlock,cptr-oaDesign,\n"
"    This function searches the specified block for an instHeader with the specified master design. If the specified master is a Pcell, the superHeader is returned.\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaInstHeader* find(const oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: find|ptr-oaInstHeader|cptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function searches the specified block for an instHeader with the specified master design library, cell, and view names. If the specified master is a Pcell, the superHeader is returned.\n"
;

static PyObject*
oaInstHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaDesign)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstHeaderp result= (oaInstHeader::find(p1.Data(),p2.Data()));
            return PyoaInstHeader_FromoaInstHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstHeaderp result= (oaInstHeader::find(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaInstHeader_FromoaInstHeader(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstHeader, function: find, Choices are:\n"
        "    (oaBlock,oaDesign)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaInstHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaInstHeader_static_find,METH_VARARGS,oaInstHeader_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstHeader",
           (PyObject*)(&PyoaInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInstHeader_Type.tp_dict;
    for(method=oaInstHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInstHeaderModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaInstHeaderModTypeEnum_Convert(PyObject* ob,PyParamoaInstHeaderModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBindInstHeaderModType")==0) { result->SetData(oacBindInstHeaderModType); return 1;}
        if (strcasecmp(str,"oacUnbindInstHeaderModType")==0) { result->SetData(oacUnbindInstHeaderModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaInstHeaderModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstHeaderModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(oaInstHeaderModTypeEnum ob)
{
    if (ob==oacBindInstHeaderModType) return PyString_FromString("oacBindInstHeaderModType");
    if (ob==oacUnbindInstHeaderModType) return PyString_FromString("oacUnbindInstHeaderModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaInstHeaderModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaInstHeaderModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(oaInstHeaderModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaInstHeaderModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaInstHeaderModTypeEnum_doc[] =
"Type convert function for enum: oaInstHeaderModTypeEnum";
                               
static PyMethodDef PyoaInstHeaderModTypeEnum_method =
  {"oaInstHeaderModTypeEnum",(PyCFunction)PyoaInstHeaderModTypeEnum_TypeFunction,METH_VARARGS,oaInstHeaderModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaInstHeaderModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBindInstHeaderModType");
    PyDict_SetItemString(mod_dict,"oacBindInstHeaderModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnbindInstHeaderModType");
    PyDict_SetItemString(mod_dict,"oacUnbindInstHeaderModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaInstHeaderModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaInstHeaderModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaInstHeaderModTypeEnum\n");
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
// Wrapper Implementation for Class: oaInstModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaInstModTypeEnum_Convert(PyObject* ob,PyParamoaInstModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetTransformInstModType")==0) { result->SetData(oacSetTransformInstModType); return 1;}
        if (strcasecmp(str,"oacSetInstHeaderInstModType")==0) { result->SetData(oacSetInstHeaderInstModType); return 1;}
        if (strcasecmp(str,"oacSetPlacementStatusInstModType")==0) { result->SetData(oacSetPlacementStatusInstModType); return 1;}
        if (strcasecmp(str,"oacSetPriorityInstModType")==0) { result->SetData(oacSetPriorityInstModType); return 1;}
        if (strcasecmp(str,"oacAddToClusterInstModType")==0) { result->SetData(oacAddToClusterInstModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromClusterInstModType")==0) { result->SetData(oacRemoveFromClusterInstModType); return 1;}
        if (strcasecmp(str,"oacSetSourceInstModType")==0) { result->SetData(oacSetSourceInstModType); return 1;}
        if (strcasecmp(str,"oacSetUsageInstModType")==0) { result->SetData(oacSetUsageInstModType); return 1;}
        if (strcasecmp(str,"oacSetImplicitInstModType")==0) { result->SetData(oacSetImplicitInstModType); return 1;}
        if (strcasecmp(str,"oacArrayInstSetNumRowsInstModType")==0) { result->SetData(oacArrayInstSetNumRowsInstModType); return 1;}
        if (strcasecmp(str,"oacArrayInstSetNumColsInstModType")==0) { result->SetData(oacArrayInstSetNumColsInstModType); return 1;}
        if (strcasecmp(str,"oacArrayInstSetDXInstModType")==0) { result->SetData(oacArrayInstSetDXInstModType); return 1;}
        if (strcasecmp(str,"oacArrayInstSetDYInstModType")==0) { result->SetData(oacArrayInstSetDYInstModType); return 1;}
        if (strcasecmp(str,"oacArrayInstSetNameInstModType")==0) { result->SetData(oacArrayInstSetNameInstModType); return 1;}
        if (strcasecmp(str,"oacScalarInstSetNameInstModType")==0) { result->SetData(oacScalarInstSetNameInstModType); return 1;}
        if (strcasecmp(str,"oacVectorInstSetBaseNameInstModType")==0) { result->SetData(oacVectorInstSetBaseNameInstModType); return 1;}
        if (strcasecmp(str,"oacVectorInstSetRangeInstModType")==0) { result->SetData(oacVectorInstSetRangeInstModType); return 1;}
        if (strcasecmp(str,"oacVectorInstBitSetNameInstModType")==0) { result->SetData(oacVectorInstBitSetNameInstModType); return 1;}
        if (strcasecmp(str,"oacAddToPinInstModType")==0) { result->SetData(oacAddToPinInstModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromPinInstModType")==0) { result->SetData(oacRemoveFromPinInstModType); return 1;}
        if (strcasecmp(str,"oacConvertToModuleInstModType")==0) { result->SetData(oacConvertToModuleInstModType); return 1;}
        if (strcasecmp(str,"oacConvertToDesignInstModType")==0) { result->SetData(oacConvertToDesignInstModType); return 1;}
        if (strcasecmp(str,"oacScalarizeInstModType")==0) { result->SetData(oacScalarizeInstModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupInstModType")==0) { result->SetData(oacAddToFigGroupInstModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupInstModType")==0) { result->SetData(oacRemoveFromFigGroupInstModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaInstModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaInstModTypeEnum_FromoaInstModTypeEnum(oaInstModTypeEnum ob)
{
    if (ob==oacSetTransformInstModType) return PyString_FromString("oacSetTransformInstModType");
    if (ob==oacSetInstHeaderInstModType) return PyString_FromString("oacSetInstHeaderInstModType");
    if (ob==oacSetPlacementStatusInstModType) return PyString_FromString("oacSetPlacementStatusInstModType");
    if (ob==oacSetPriorityInstModType) return PyString_FromString("oacSetPriorityInstModType");
    if (ob==oacAddToClusterInstModType) return PyString_FromString("oacAddToClusterInstModType");
    if (ob==oacRemoveFromClusterInstModType) return PyString_FromString("oacRemoveFromClusterInstModType");
    if (ob==oacSetSourceInstModType) return PyString_FromString("oacSetSourceInstModType");
    if (ob==oacSetUsageInstModType) return PyString_FromString("oacSetUsageInstModType");
    if (ob==oacSetImplicitInstModType) return PyString_FromString("oacSetImplicitInstModType");
    if (ob==oacArrayInstSetNumRowsInstModType) return PyString_FromString("oacArrayInstSetNumRowsInstModType");
    if (ob==oacArrayInstSetNumColsInstModType) return PyString_FromString("oacArrayInstSetNumColsInstModType");
    if (ob==oacArrayInstSetDXInstModType) return PyString_FromString("oacArrayInstSetDXInstModType");
    if (ob==oacArrayInstSetDYInstModType) return PyString_FromString("oacArrayInstSetDYInstModType");
    if (ob==oacArrayInstSetNameInstModType) return PyString_FromString("oacArrayInstSetNameInstModType");
    if (ob==oacScalarInstSetNameInstModType) return PyString_FromString("oacScalarInstSetNameInstModType");
    if (ob==oacVectorInstSetBaseNameInstModType) return PyString_FromString("oacVectorInstSetBaseNameInstModType");
    if (ob==oacVectorInstSetRangeInstModType) return PyString_FromString("oacVectorInstSetRangeInstModType");
    if (ob==oacVectorInstBitSetNameInstModType) return PyString_FromString("oacVectorInstBitSetNameInstModType");
    if (ob==oacAddToPinInstModType) return PyString_FromString("oacAddToPinInstModType");
    if (ob==oacRemoveFromPinInstModType) return PyString_FromString("oacRemoveFromPinInstModType");
    if (ob==oacConvertToModuleInstModType) return PyString_FromString("oacConvertToModuleInstModType");
    if (ob==oacConvertToDesignInstModType) return PyString_FromString("oacConvertToDesignInstModType");
    if (ob==oacScalarizeInstModType) return PyString_FromString("oacScalarizeInstModType");
    if (ob==oacAddToFigGroupInstModType) return PyString_FromString("oacAddToFigGroupInstModType");
    if (ob==oacRemoveFromFigGroupInstModType) return PyString_FromString("oacRemoveFromFigGroupInstModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaInstModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaInstModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaInstModTypeEnum_FromoaInstModTypeEnum(oaInstModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaInstModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaInstModTypeEnum_doc[] =
"Type convert function for enum: oaInstModTypeEnum";
                               
static PyMethodDef PyoaInstModTypeEnum_method =
  {"oaInstModTypeEnum",(PyCFunction)PyoaInstModTypeEnum_TypeFunction,METH_VARARGS,oaInstModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaInstModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetTransformInstModType");
    PyDict_SetItemString(mod_dict,"oacSetTransformInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetInstHeaderInstModType");
    PyDict_SetItemString(mod_dict,"oacSetInstHeaderInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPlacementStatusInstModType");
    PyDict_SetItemString(mod_dict,"oacSetPlacementStatusInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPriorityInstModType");
    PyDict_SetItemString(mod_dict,"oacSetPriorityInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToClusterInstModType");
    PyDict_SetItemString(mod_dict,"oacAddToClusterInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromClusterInstModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromClusterInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetSourceInstModType");
    PyDict_SetItemString(mod_dict,"oacSetSourceInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetUsageInstModType");
    PyDict_SetItemString(mod_dict,"oacSetUsageInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetImplicitInstModType");
    PyDict_SetItemString(mod_dict,"oacSetImplicitInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArrayInstSetNumRowsInstModType");
    PyDict_SetItemString(mod_dict,"oacArrayInstSetNumRowsInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArrayInstSetNumColsInstModType");
    PyDict_SetItemString(mod_dict,"oacArrayInstSetNumColsInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArrayInstSetDXInstModType");
    PyDict_SetItemString(mod_dict,"oacArrayInstSetDXInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArrayInstSetDYInstModType");
    PyDict_SetItemString(mod_dict,"oacArrayInstSetDYInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArrayInstSetNameInstModType");
    PyDict_SetItemString(mod_dict,"oacArrayInstSetNameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacScalarInstSetNameInstModType");
    PyDict_SetItemString(mod_dict,"oacScalarInstSetNameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVectorInstSetBaseNameInstModType");
    PyDict_SetItemString(mod_dict,"oacVectorInstSetBaseNameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVectorInstSetRangeInstModType");
    PyDict_SetItemString(mod_dict,"oacVectorInstSetRangeInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVectorInstBitSetNameInstModType");
    PyDict_SetItemString(mod_dict,"oacVectorInstBitSetNameInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToPinInstModType");
    PyDict_SetItemString(mod_dict,"oacAddToPinInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromPinInstModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromPinInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConvertToModuleInstModType");
    PyDict_SetItemString(mod_dict,"oacConvertToModuleInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacConvertToDesignInstModType");
    PyDict_SetItemString(mod_dict,"oacConvertToDesignInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacScalarizeInstModType");
    PyDict_SetItemString(mod_dict,"oacScalarizeInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupInstModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupInstModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupInstModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaInstModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaInstModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaInstModTypeEnum\n");
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
// Wrapper Implementation for Class: oaInstPropDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstPropDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstPropDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstPropDisplayObject* self = (PyoaInstPropDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstPropDisplay)
    {
        PyParamoaInstPropDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstPropDisplay_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInstPropDisplay, Choices are:\n"
        "    (oaInstPropDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstPropDisplay_tp_dealloc(PyoaInstPropDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstPropDisplay_tp_repr(PyObject *ob)
{
    PyParamoaInstPropDisplay value;
    int convert_status=PyoaInstPropDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaInstPropDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInstPropDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstPropDisplay v1;
    PyParamoaInstPropDisplay v2;
    int convert_status1=PyoaInstPropDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaInstPropDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstPropDisplay_Convert(PyObject* ob,PyParamoaInstPropDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstPropDisplay_Check(ob)) {
        result->SetData( (oaInstPropDisplay**) ((PyoaInstPropDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstPropDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstPropDisplay_FromoaInstPropDisplay(oaInstPropDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInstPropDisplay* data=*value;
        PyObject* bself = PyoaInstPropDisplay_Type.tp_alloc(&PyoaInstPropDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaInstPropDisplayObject* self = (PyoaInstPropDisplayObject*)bself;
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
PyObject* PyoaInstPropDisplay_FromoaInstPropDisplay(oaInstPropDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaInstPropDisplay_Type.tp_alloc(&PyoaInstPropDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaInstPropDisplayObject* self = (PyoaInstPropDisplayObject*)bself;
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
static char oaInstPropDisplay_getInst_doc[] = 
"Class: oaInstPropDisplay, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns the instance associated with this instPropDisplay object.\n"
;

static PyObject*
oaInstPropDisplay_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstPropDisplay data;
    int convert_status=PyoaInstPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstPropDisplayObject* self=(PyoaInstPropDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getInst());
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
static char oaInstPropDisplay_getMasterProp_doc[] = 
"Class: oaInstPropDisplay, Function: getMasterProp\n"
"  Paramegers: ()\n"
"    Calls: oaProp* getMasterProp() const\n"
"    Signature: getMasterProp|ptr-oaProp|\n"
"    BrowseData: 1\n"
"    This function returns the property associated with this instPropDisplay object.\n"
;

static PyObject*
oaInstPropDisplay_getMasterProp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstPropDisplay data;
    int convert_status=PyoaInstPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstPropDisplayObject* self=(PyoaInstPropDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPropp result= (data.DataCall()->getMasterProp());
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
static char oaInstPropDisplay_isBound_doc[] = 
"Class: oaInstPropDisplay, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if instance property display is currently bound.\n"
;

static PyObject*
oaInstPropDisplay_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstPropDisplay data;
    int convert_status=PyoaInstPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstPropDisplayObject* self=(PyoaInstPropDisplayObject*)ob;
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
static char oaInstPropDisplay_isNull_doc[] =
"Class: oaInstPropDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInstPropDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInstPropDisplay data;
    int convert_status=PyoaInstPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInstPropDisplay_assign_doc[] = 
"Class: oaInstPropDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstPropDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstPropDisplay data;
  int convert_status=PyoaInstPropDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstPropDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstPropDisplay_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstPropDisplay_methodlist[] = {
    {"getInst",(PyCFunction)oaInstPropDisplay_getInst,METH_VARARGS,oaInstPropDisplay_getInst_doc},
    {"getMasterProp",(PyCFunction)oaInstPropDisplay_getMasterProp,METH_VARARGS,oaInstPropDisplay_getMasterProp_doc},
    {"isBound",(PyCFunction)oaInstPropDisplay_isBound,METH_VARARGS,oaInstPropDisplay_isBound_doc},
    {"isNull",(PyCFunction)oaInstPropDisplay_tp_isNull,METH_VARARGS,oaInstPropDisplay_isNull_doc},
    {"assign",(PyCFunction)oaInstPropDisplay_tp_assign,METH_VARARGS,oaInstPropDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstPropDisplay_doc[] = 
"Class: oaInstPropDisplay\n"
"  The oaInstPropDisplay is a shape similar to an oaText object, except that it presents a string that is the value of the specified oaProp on the master of the oaInst to which it is attached. Whenever the value of the oaProp changes, calling the getText function on this oaInstPropDisplay object returns the updated text string that represents the master's oaProp value.\n"
"  The oaInstPropDisplay is contained in the design that contains the attached oaInst object.\n"
"Constructors:\n"
"  Paramegers: (oaInstPropDisplay)\n"
"    Calls: (const oaInstPropDisplay&)\n"
"    Signature: oaInstPropDisplay||cref-oaInstPropDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstPropDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstPropDisplay",
    sizeof(PyoaInstPropDisplayObject),
    0,
    (destructor)oaInstPropDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstPropDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaInstPropDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstPropDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstPropDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstPropDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstPropDisplay_static_create_doc[] = 
"Class: oaInstPropDisplay, Function: create\n"
"  Paramegers: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
"    Calls: oaInstPropDisplay* create(oaInst* inst,oaProp* masterProp,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height)\n"
"    Signature: create|ptr-oaInstPropDisplay|ptr-oaInst,ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instPropDisplay object for the specified prop object in the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterProp\n"
"    The property associated with this instPropDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this display\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: The instance's master must be able to open for this function to succeed.\n"
"    oacNoMasterForTextDisplay\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
"    Calls: oaInstPropDisplay* create(oaInst* inst,oaProp* masterProp,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format)\n"
"    Signature: create|ptr-oaInstPropDisplay|ptr-oaInst,ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instPropDisplay object for the specified prop object in the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterProp\n"
"    The property associated with this instPropDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this display\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: The instance's master must be able to open for this function to succeed.\n"
"    oacNoMasterForTextDisplay\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
"    Calls: oaInstPropDisplay* create(oaInst* inst,oaProp* masterProp,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar)\n"
"    Signature: create|ptr-oaInstPropDisplay|ptr-oaInst,ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instPropDisplay object for the specified prop object in the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterProp\n"
"    The property associated with this instPropDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this display\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: The instance's master must be able to open for this function to succeed.\n"
"    oacNoMasterForTextDisplay\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
"    Calls: oaInstPropDisplay* create(oaInst* inst,oaProp* masterProp,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible)\n"
"    Signature: create|ptr-oaInstPropDisplay|ptr-oaInst,ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instPropDisplay object for the specified prop object in the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterProp\n"
"    The property associated with this instPropDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this display\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: The instance's master must be able to open for this function to succeed.\n"
"    oacNoMasterForTextDisplay\n"
"    oacPropNotOnInstanceMaster\n"
"  Paramegers: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
"    Calls: oaInstPropDisplay* create(oaInst* inst,oaProp* masterProp,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible,oaBoolean drafting)\n"
"    Signature: create|ptr-oaInstPropDisplay|ptr-oaInst,ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an instPropDisplay object for the specified prop object in the specified instance's master.\n"
"    inst\n"
"    The oaInst object with which this textDisplay is associated\n"
"    masterProp\n"
"    The property associated with this instPropDisplay object\n"
"    layerNum\n"
"    The layer number for this textDisplay\n"
"    purposeNum\n"
"    The purpose number for this textDisplay\n"
"    origin\n"
"    The origin point of this textDisplay shape\n"
"    alignment\n"
"    The alignment related to the origin\n"
"    orient\n"
"    The orientation of this textDisplay shape\n"
"    font\n"
"    The font used to display textDisplay shape\n"
"    height\n"
"    The height of this display\n"
"    format\n"
"    The format used to create the textDisplay\n"
"    overbar\n"
"    Specifies if this textDisplay has an overbar; the default is false\n"
"    visible\n"
"    Specifies if this textDisplay is actually displayed; the default is true\n"
"    drafting\n"
"    Specifies the drafting of this textDisplay shape; the default is true\n"
"    Note: The instance's master must be able to open for this function to succeed.\n"
"    oacNoMasterForTextDisplay\n"
"    oacPropNotOnInstanceMaster\n"
;

static PyObject*
oaInstPropDisplay_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)
    {
        PyParamoaInst p1;
        PyParamoaProp p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaProp_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstPropDisplayp result= (oaInstPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data()));
            return PyoaInstPropDisplay_FromoaInstPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)
    {
        PyParamoaInst p1;
        PyParamoaProp p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaProp_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstPropDisplayp result= (oaInstPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data()));
            return PyoaInstPropDisplay_FromoaInstPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaProp p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaProp_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstPropDisplayp result= (oaInstPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data()));
            return PyoaInstPropDisplay_FromoaInstPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaProp p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaProp_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstPropDisplayp result= (oaInstPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data()));
            return PyoaInstPropDisplay_FromoaInstPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)
    {
        PyParamoaInst p1;
        PyParamoaProp p2;
        PyParamoaLayerNum p3;
        PyParamoaPurposeNum p4;
        PyParamoaPoint p5;
        PyParamoaTextAlign p6;
        PyParamoaOrient p7;
        PyParamoaFont p8;
        PyParamoaDist p9;
        PyParamoaTextDisplayFormat p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        PyParamoaBoolean p13;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaProp_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaPurposeNum_Convert,&p4,
              &PyoaPoint_Convert,&p5,
              &PyoaTextAlign_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaFont_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaTextDisplayFormat_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12,
              &PyoaBoolean_Convert,&p13)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstPropDisplayp result= (oaInstPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data(),p13.Data()));
            return PyoaInstPropDisplay_FromoaInstPropDisplay(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstPropDisplay, function: create, Choices are:\n"
        "    (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
        "    (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
        "    (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
        "    (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
        "    (oaInst,oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaInstPropDisplay_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaInstPropDisplay_static_create,METH_VARARGS,oaInstPropDisplay_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstPropDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstPropDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaInstPropDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstPropDisplay",
           (PyObject*)(&PyoaInstPropDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstPropDisplay\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInstPropDisplay_Type.tp_dict;
    for(method=oaInstPropDisplay_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInstQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstQueryObject* self = (PyoaInstQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: oaInstQuery");
    }
    else {
        pyv_oaInstQuery* p = new pyv_oaInstQuery();
        p->pyob=self;
        self->value= (oaRegionQuery*)  p;
        return bself;
    }
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstQuery_tp_dealloc(PyoaInstQueryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstQuery_tp_repr(PyObject *ob)
{
    PyParamoaInstQuery value;
    int convert_status=PyoaInstQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaInstQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInstQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstQuery v1;
    PyParamoaInstQuery v2;
    int convert_status1=PyoaInstQuery_Convert(ob1,&v1);
    int convert_status2=PyoaInstQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstQuery_Convert(PyObject* ob,PyParamoaInstQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstQuery_Check(ob)) {
        result->SetData( (oaInstQuery*) ((PyoaInstQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstQuery_FromoaInstQuery(oaInstQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaInstQuery_Type.tp_alloc(&PyoaInstQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaInstQueryObject* self = (PyoaInstQueryObject*)bself;
        self->value = (oaRegionQuery*)  data;
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
pyv_oaInstQuery::pyv_oaInstQuery()
 : pyob(NULL),
   oaInstQuery()
{
}

// ------------------------------------------------------------------
pyv_oaInstQuery::pyv_oaInstQuery(const oaInstQuery& p)
 : pyob(NULL),
   oaInstQuery(p)
{
}

// ------------------------------------------------------------------
void pyv_oaInstQuery::queryInst(oaInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"queryInst");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::queryInst was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInst_FromoaInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::queryInst had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaInstQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaInstQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaInstQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaInstQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaInstQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaInstQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaInstQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstQuery_query_doc[] = 
"Class: oaInstQuery, Function: query\n"
"  Paramegers: (oaDesign,oaBox)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The transform that is currently applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The transform that is currently applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The transform that is currently applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating instances in the specified region of the specified design hierarchy.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    region\n"
"    The region of interest\n"
"    xform\n"
"    The transform that is currently applied to the design\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to end the querying\n"
;

static PyObject*
oaInstQuery_query(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstQuery data;
    int convert_status=PyoaInstQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstQueryObject* self=(PyoaInstQueryObject*)ob;

    // Case: (oaDesign,oaBox)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        PyParamoaUInt4 p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaUInt4_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaDist p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaBox p2;
        PyParamoaTransform p3;
        PyParamoaDist p4;
        PyParamoaUInt4 p5;
        PyParamoaUInt4 p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaBox_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaUInt4_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstQuery, function: query, Choices are:\n"
        "    (oaDesign,oaBox)\n"
        "    (oaDesign,oaBox,oaDist)\n"
        "    (oaDesign,oaBox,oaDist,oaUInt4)\n"
        "    (oaDesign,oaBox,oaDist,oaUInt4,oaUInt4)\n"
        "    (oaDesign,oaBox,oaTransform)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)\n"
        "    (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstQuery_queryInst_doc[] = 
"Class: oaInstQuery, Function: queryInst\n"
"  Paramegers: (oaInst)\n"
"    Calls: virtual void queryInst(oaInst* inst)\n"
"    Signature: queryInst|void-void|ptr-oaInst,\n"
"    This function processes each result of the instance query.\n"
"    inst\n"
"    Pointer to an instance found during querying\n"
;

static PyObject*
oaInstQuery_queryInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstQuery data;
    int convert_status=PyoaInstQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstQueryObject* self=(PyoaInstQueryObject*)ob;

    PyParamoaInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInst_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        PyErr_SetString(PyExc_TypeError,
            "Call to Pure-Virtual Function class: oaInstQuery, function: queryInst");
            return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaInstQuery_assign_doc[] = 
"Class: oaInstQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstQuery data;
  int convert_status=PyoaInstQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstQuery_methodlist[] = {
    {"query",(PyCFunction)oaInstQuery_query,METH_VARARGS,oaInstQuery_query_doc},
    {"queryInst",(PyCFunction)oaInstQuery_queryInst,METH_VARARGS,oaInstQuery_queryInst_doc},
    {"assign",(PyCFunction)oaInstQuery_tp_assign,METH_VARARGS,oaInstQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstQuery_doc[] = 
"Class: oaInstQuery\n"
"  The oaInstQuery class implements functionality to query a specified region in a design hierarchy and quickly return all oaInst that overlap the region.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaInstQuery()\n"
"    Signature: oaInstQuery||\n"
"    This is the constructor for the oaInstQuery class.\n"
"  Paramegers: (oaInstQuery)\n"
"    Calls: (const oaInstQuery&)\n"
"    Signature: oaInstQuery||cref-oaInstQuery,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstQuery",
    sizeof(PyoaInstQueryObject),
    0,
    (destructor)oaInstQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaInstQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRegionQuery_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaInstQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstQuery",
           (PyObject*)(&PyoaInstQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstQuery\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstTermObject* self = (PyoaInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstTerm)
    {
        PyParamoaInstTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaInstTerm, Choices are:\n"
        "    (oaInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstTerm_tp_dealloc(PyoaInstTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaInstTerm value;
    int convert_status=PyoaInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaInstTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        oaString sep=" ";
        sep[(oaUInt4)0]=oacInternalHierDelimiter;
        oaSimpleName sname;
        oaName name;
        oaString str;
        if (value.DataCall()->getInst()->isValid()) {
          value.DataCall()->getInst()->getName(sname);
          sname.get(str);
        }
        else {
          str="-";
        }
        sname.get(str);
        sresult+=oaString(str);
        sresult+=sep;
        value.DataCall()->getTermName(name);
        name.get(str);
        sresult+=oaString(str);
    
        char addr[32];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaInstTerm::");
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
oaInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstTerm v1;
    PyParamoaInstTerm v2;
    int convert_status1=PyoaInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstTerm_Convert(PyObject* ob,PyParamoaInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstTerm_Check(ob)) {
        result->SetData( (oaInstTerm**) ((PyoaInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstTerm_FromoaInstTerm(oaInstTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaInstTerm* data=*value;
        PyObject* bself = PyoaInstTerm_Type.tp_alloc(&PyoaInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaInstTermObject* self = (PyoaInstTermObject*)bself;
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
PyObject* PyoaInstTerm_FromoaInstTerm(oaInstTerm* data)
{
    if (data) {
       PyObject* bself = PyoaInstTerm_Type.tp_alloc(&PyoaInstTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaInstTermObject* self = (PyoaInstTermObject*)bself;
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
static char oaInstTerm_addToNet_doc[] = 
"Class: oaInstTerm, Function: addToNet\n"
"  Paramegers: (oaNet)\n"
"    Calls: void addToNet(oaNet* net)\n"
"    Signature: addToNet|void-void|ptr-oaNet,\n"
"    This function adds this instTerm to the specified net. If this instTerm is already connected to another net, it detaches first.\n"
"    net\n"
"    The new net to which to attach the instTerm\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"    oacCannotModifyImplicitInstTerm\n"
"    oacCannotModifyInstTermInNonUniqueHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
;

static PyObject*
oaInstTerm_addToNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
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
static char oaInstTerm_destroy_doc[] = 
"Class: oaInstTerm, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this instTerm, removing it from the database. The reference for the instTerm is removed from the corresponding net.\n"
"    oacCannotDestroyImplicitInstTerm\n"
"    oacCannotModifyInstTermInNonUniqueHier\n"
;

static PyObject*
oaInstTerm_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
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
static char oaInstTerm_getBit_doc[] = 
"Class: oaInstTerm, Function: getBit\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaInstTerm* getBit(oaUInt4 bitIndex) const\n"
"    Signature: getBit|ptr-oaInstTerm|simple-oaUInt4,\n"
"    This function returns a pointer to the instTerm that corresponds to the specified bitIndex bit of this instTerm. For single-bit instTerms, this function returns this instTerm if the bitIndex value is zero.\n"
"    oacInvalidInstTermBitIndex\n"
;

static PyObject*
oaInstTerm_getBit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaInstTermp result= (data.DataCall()->getBit(p1.Data()));
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
static char oaInstTerm_getConnRoutes_doc[] = 
"Class: oaInstTerm, Function: getConnRoutes\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaRoute_oaInstTerm getConnRoutes() const\n"
"    Signature: getConnRoutes|simple-oaCollection_oaRoute_oaInstTerm|\n"
"    BrowseData: 1\n"
"    This function returns a collection of routes connected to this instTerm. Each route in the collection has this instTerm as either its startConn, endConn, or both.\n"
;

static PyObject*
oaInstTerm_getConnRoutes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaRoute_oaInstTerm* result= new oaCollection_oaRoute_oaInstTerm(data.DataCall()->getConnRoutes());
        return PyoaCollection_oaRoute_oaInstTerm_FromoaCollection_oaRoute_oaInstTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_getConnRoutesIter_doc[] = 
"Class: oaInstTerm, Function: getConnRoutesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaRoute getConnRoutesIter() const\n"
"    Signature: getConnRoutesIter|simple-oaIter_oaRoute|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of routes connected to this instTerm. Each route in the collection has this instTerm as either its startConn, endConn, or both.\n"
;

static PyObject*
oaInstTerm_getConnRoutesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaRoute* result= new oaIter_oaRoute(data.DataCall()->getConnRoutes());
        return PyoaIter_oaRoute_FromoaIter_oaRoute(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_getInst_doc[] = 
"Class: oaInstTerm, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the instance associated with this instTerm.\n"
;

static PyObject*
oaInstTerm_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getInst());
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
static char oaInstTerm_getNet_doc[] = 
"Class: oaInstTerm, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: oaNet* getNet() const\n"
"    Signature: getNet|ptr-oaNet|simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    oaInstTerm::getNet\n"
"    This function returns the net associated with this instTerm. NULL is returned if the instTerm was created with a NULL net or if the instTerm was disconnected from the net. If preferred is true , the preferred equivalent net associated with the net will be returned instead.\n"
"    preferred\n"
"    indicates whether to return the preferred equivalent\n"
"    A pointer to an oaNet\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: oaNet* getNet(oaBoolean preferred) const\n"
"    Signature: getNet|ptr-oaNet|simple-oaBoolean,\n"
"    oaInstTerm::getNet\n"
"    This function returns the net associated with this instTerm. NULL is returned if the instTerm was created with a NULL net or if the instTerm was disconnected from the net. If preferred is true , the preferred equivalent net associated with the net will be returned instead.\n"
"    preferred\n"
"    indicates whether to return the preferred equivalent\n"
"    A pointer to an oaNet\n"
;

static PyObject*
oaInstTerm_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaNetp result= (data.DataCall()->getNet());
            return PyoaNet_FromoaNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            oaNetp result= (data.DataCall()->getNet(p1.Data()));
            return PyoaNet_FromoaNet(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstTerm, function: getNet, Choices are:\n"
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
static char oaInstTerm_getNumBits_doc[] = 
"Class: oaInstTerm, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits for this instTerm. This value is equal to the number of bits in the associated net. If the instTerm has no net, the value is calculated from the number of bits in the corresponding terminal multiplied by the number of bits in the corresponding instance. If the terminal is not bound, the number of bits for the terminal is derived from the terminal name. If the terminal is not bound and the instTerm connects by position, the number of bits cannot be determined if there is no net and a value of zero is returned.\n"
;

static PyObject*
oaInstTerm_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaInstTerm_getOccInstTerm_doc[] = 
"Class: oaInstTerm, Function: getOccInstTerm\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstTerm* getOccInstTerm() const\n"
"    Signature: getOccInstTerm|ptr-oaOccInstTerm|\n"
"    BrowseData: 1\n"
"    This function returns the occurrence instTerm that is the reflection of this block instTerm in the context of the top occurrence of the design that contains the instTerm.\n"
;

static PyObject*
oaInstTerm_getOccInstTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstTermp result= (data.DataCall()->getOccInstTerm());
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
static char oaInstTerm_getOccInstTerms_doc[] = 
"Class: oaInstTerm, Function: getOccInstTerms\n"
"  Paramegers: (oaOccurrence)\n"
"    Calls: oaCollection_oaOccInstTerm_oaInstTerm getOccInstTerms(const oaOccurrence* top) const\n"
"    Signature: getOccInstTerms|simple-oaCollection_oaOccInstTerm_oaInstTerm|cptr-oaOccurrence,\n"
"    This function returns a collection of occInstTerms that represent this instTerm in the occurrence hierarchy specified by top .\n"
"    top\n"
"    The top occurrence\n"
;

static PyObject*
oaInstTerm_getOccInstTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOccurrence p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccurrence_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaCollection_oaOccInstTerm_oaInstTerm* result= new oaCollection_oaOccInstTerm_oaInstTerm(data.DataCall()->getOccInstTerms(p1.Data()));
        return PyoaCollection_oaOccInstTerm_oaInstTerm_FromoaCollection_oaOccInstTerm_oaInstTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_getOccInstTermsIter_doc[] = 
"Class: oaInstTerm, Function: getOccInstTermsIter\n"
"  Paramegers: (oaOccurrence)\n"
"    Calls: oaIter_oaOccInstTerm getOccInstTermsIter(const oaOccurrence* top) const\n"
"    Signature: getOccInstTermsIter|simple-oaIter_oaOccInstTerm|cptr-oaOccurrence,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of occInstTerms that represent this instTerm in the occurrence hierarchy specified by top .\n"
"    top\n"
"    The top occurrence\n"
;

static PyObject*
oaInstTerm_getOccInstTermsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOccurrence p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOccurrence_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaIter_oaOccInstTerm* result= new oaIter_oaOccInstTerm(data.DataCall()->getOccInstTerms(p1.Data()));
        return PyoaIter_oaOccInstTerm_FromoaIter_oaOccInstTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_getRouteMethod_doc[] = 
"Class: oaInstTerm, Function: getRouteMethod\n"
"  Paramegers: ()\n"
"    Calls: oaRouteMethod getRouteMethod() const\n"
"    Signature: getRouteMethod|simple-oaRouteMethod|\n"
"    BrowseData: 1\n"
"    This function returns the route method of this instTerm.\n"
;

static PyObject*
oaInstTerm_getRouteMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteMethod* result= new oaRouteMethod(data.DataCall()->getRouteMethod());
        return PyoaRouteMethod_FromoaRouteMethod(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_getTerm_doc[] = 
"Class: oaInstTerm, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaTerm* getTerm() const\n"
"    Signature: getTerm|ptr-oaTerm|\n"
"    BrowseData: 1\n"
"    oaInstTerm::getTerm\n"
"    This function returns the terminal associated with this instTerm. An attempt is made to bind the master if the instTerm is unbound. NULL is returned if the instance is unbound or the terminal is not found in the master.\n"
;

static PyObject*
oaInstTerm_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaTermp result= (data.DataCall()->getTerm());
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
static char oaInstTerm_getTermName_doc[] = 
"Class: oaInstTerm, Function: getTermName\n"
"  Paramegers: (oaName)\n"
"    Calls: void getTermName(oaName& name) const\n"
"    Signature: getTermName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the name of the terminal associated with this instTerm in the given name argument. A name is returned even if the instTerm is not bound. The existence of a terminal name does not guarantee that the terminal exists in the corresponding instance master.\n"
"    name\n"
"    The name object to return the terminal name in\n"
"    oacInstTermConnectsByPosition\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getTermName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getTermName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of the terminal associated with this instTerm in the nameSpace specified. A name is returned even if the instTerm is not bound. The existence of a terminal name does not necessarily guarantee that the corresponding terminal exists in the instance master.\n"
"    ns\n"
"    The nameSpace for processing the name\n"
"    name\n"
"    The string that the terminal name is returned in\n"
"    oacInstTermConnectsByPosition\n"
;

static PyObject*
oaInstTerm_getTermName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
            data.DataCall()->getTermName(p1.Data());
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
            data.DataCall()->getTermName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstTerm, function: getTermName, Choices are:\n"
        "    (oaName)\n"
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
static char oaInstTerm_getTermPosition_doc[] = 
"Class: oaInstTerm, Function: getTermPosition\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getTermPosition() const\n"
"    Signature: getTermPosition|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the terminal position that this instTerm connects to.\n"
"    oacInstTermConnectsByName\n"
;

static PyObject*
oaInstTerm_getTermPosition(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getTermPosition());
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
static char oaInstTerm_hide_doc[] = 
"Class: oaInstTerm, Function: hide\n"
"  Paramegers: ()\n"
"    Calls: void hide()\n"
"    Signature: hide|void-void|\n"
"    BrowseData: 0\n"
"    oaInstTerm::hide\n"
"    This function removes the instTerm from the block domain. The instTerm will not appear in any block domain collections, and it will not be returned by any find() functions. This is not the same as destroy since the corresponding instTerms in the module domain are unaffected by hide() .\n"
"    An instTerm must be explicit to be hidden, it must correspond to an instTerm in a unique occurrence hierarchy (see oaOccurrence::uniquify() ), and it must have a corresponding instTerm in the module domain. Hiding a multi-bit instTerm also will cause all the member instTerms to be hidden. Hiding an explicit single-bit member of a scalarized multi-bit instTerm will hide all the multi-bit owners of the instTerm as well as all the member bits of those instTerms.\n"
"    oacCannotHideBlockOnlyInstTerm\n"
"    oacCannotHideImplicitInstTerm\n"
"    oacCannotModifyInstTermInNonUniqueHier\n"
;

static PyObject*
oaInstTerm_hide(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->hide();
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
static char oaInstTerm_isBound_doc[] = 
"Class: oaInstTerm, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether the instance associated with this instTerm is bound and if the associated terminal exists in the instance master.\n"
;

static PyObject*
oaInstTerm_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
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
static char oaInstTerm_isImplicit_doc[] = 
"Class: oaInstTerm, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value indicating whether this instTerm is implicit, having been created as a result of the creation of a multi-bit instTerm.\n"
;

static PyObject*
oaInstTerm_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
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
static char oaInstTerm_removeFromNet_doc[] = 
"Class: oaInstTerm, Function: removeFromNet\n"
"  Paramegers: ()\n"
"    Calls: void removeFromNet()\n"
"    Signature: removeFromNet|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this instTerm from the net to which it is attached. If this instTerm is not attached to a net, this function does nothing.\n"
"    oacCannotModifyImplicitInstTerm\n"
"    oacCannotModifyInstTermInNonUniqueHier\n"
;

static PyObject*
oaInstTerm_removeFromNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
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
static char oaInstTerm_scalarize_doc[] = 
"Class: oaInstTerm, Function: scalarize\n"
"  Paramegers: ()\n"
"    Calls: void scalarize()\n"
"    Signature: scalarize|void-void|\n"
"    BrowseData: 0\n"
"    This function insures that the bits associated of the connection formed by this instTerm are explicit and available to support implementation data.\n"
"    If this instTerm represents a multibit connection, this function insures all corresponding single-bit connections are scalarized. That is, for each bit of the connection, the implicit instTerm and its associated bitNet are made explicit. After processing all of the bits in the connection, the instTerm is made implicit. This insures that no implementation data can be added to the instTerm. If the instTerm becomes implicit, any associated impmentation data is removed from it.\n"
"    oacCannotScalarizeImplicitInstTerm\n"
"    oacCannotModifyInstTermInNonUniqueHier\n"
;

static PyObject*
oaInstTerm_scalarize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->scalarize();
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
static char oaInstTerm_setRouteMethod_doc[] = 
"Class: oaInstTerm, Function: setRouteMethod\n"
"  Paramegers: (oaRouteMethod)\n"
"    Calls: void setRouteMethod(oaRouteMethod routeMethod)\n"
"    Signature: setRouteMethod|void-void|simple-oaRouteMethod,\n"
"    This function changes the route method for this instTerm.\n"
"    routeMethod\n"
"    The new routeMethod value for this instTerm\n"
"    oacCannotModifyImplicitInstTerm\n"
;

static PyObject*
oaInstTerm_setRouteMethod(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteMethod p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteMethod_Convert,&p1)) {
        data.DataCall()->setRouteMethod(p1.Data());
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
static char oaInstTerm_usesTermPosition_doc[] = 
"Class: oaInstTerm, Function: usesTermPosition\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean usesTermPosition() const\n"
"    Signature: usesTermPosition|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this instTerm was created to connect to a terminal position. This function returns 'true' if this instTerm binds to a particular terminal position. It returns 'false' if this instTerm binds to a terminal by name.\n"
;

static PyObject*
oaInstTerm_usesTermPosition(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermObject* self=(PyoaInstTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->usesTermPosition());
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
static char oaInstTerm_isNull_doc[] =
"Class: oaInstTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaInstTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaInstTerm data;
    int convert_status=PyoaInstTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaInstTerm_assign_doc[] = 
"Class: oaInstTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstTerm data;
  int convert_status=PyoaInstTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstTerm_methodlist[] = {
    {"addToNet",(PyCFunction)oaInstTerm_addToNet,METH_VARARGS,oaInstTerm_addToNet_doc},
    {"destroy",(PyCFunction)oaInstTerm_destroy,METH_VARARGS,oaInstTerm_destroy_doc},
    {"getBit",(PyCFunction)oaInstTerm_getBit,METH_VARARGS,oaInstTerm_getBit_doc},
    {"getConnRoutes",(PyCFunction)oaInstTerm_getConnRoutes,METH_VARARGS,oaInstTerm_getConnRoutes_doc},
    {"getConnRoutesIter",(PyCFunction)oaInstTerm_getConnRoutesIter,METH_VARARGS,oaInstTerm_getConnRoutesIter_doc},
    {"getInst",(PyCFunction)oaInstTerm_getInst,METH_VARARGS,oaInstTerm_getInst_doc},
    {"getNet",(PyCFunction)oaInstTerm_getNet,METH_VARARGS,oaInstTerm_getNet_doc},
    {"getNumBits",(PyCFunction)oaInstTerm_getNumBits,METH_VARARGS,oaInstTerm_getNumBits_doc},
    {"getOccInstTerm",(PyCFunction)oaInstTerm_getOccInstTerm,METH_VARARGS,oaInstTerm_getOccInstTerm_doc},
    {"getOccInstTerms",(PyCFunction)oaInstTerm_getOccInstTerms,METH_VARARGS,oaInstTerm_getOccInstTerms_doc},
    {"getOccInstTermsIter",(PyCFunction)oaInstTerm_getOccInstTermsIter,METH_VARARGS,oaInstTerm_getOccInstTermsIter_doc},
    {"getRouteMethod",(PyCFunction)oaInstTerm_getRouteMethod,METH_VARARGS,oaInstTerm_getRouteMethod_doc},
    {"getTerm",(PyCFunction)oaInstTerm_getTerm,METH_VARARGS,oaInstTerm_getTerm_doc},
    {"getTermName",(PyCFunction)oaInstTerm_getTermName,METH_VARARGS,oaInstTerm_getTermName_doc},
    {"getTermPosition",(PyCFunction)oaInstTerm_getTermPosition,METH_VARARGS,oaInstTerm_getTermPosition_doc},
    {"hide",(PyCFunction)oaInstTerm_hide,METH_VARARGS,oaInstTerm_hide_doc},
    {"isBound",(PyCFunction)oaInstTerm_isBound,METH_VARARGS,oaInstTerm_isBound_doc},
    {"isImplicit",(PyCFunction)oaInstTerm_isImplicit,METH_VARARGS,oaInstTerm_isImplicit_doc},
    {"removeFromNet",(PyCFunction)oaInstTerm_removeFromNet,METH_VARARGS,oaInstTerm_removeFromNet_doc},
    {"scalarize",(PyCFunction)oaInstTerm_scalarize,METH_VARARGS,oaInstTerm_scalarize_doc},
    {"setRouteMethod",(PyCFunction)oaInstTerm_setRouteMethod,METH_VARARGS,oaInstTerm_setRouteMethod_doc},
    {"usesTermPosition",(PyCFunction)oaInstTerm_usesTermPosition,METH_VARARGS,oaInstTerm_usesTermPosition_doc},
    {"isNull",(PyCFunction)oaInstTerm_tp_isNull,METH_VARARGS,oaInstTerm_isNull_doc},
    {"assign",(PyCFunction)oaInstTerm_tp_assign,METH_VARARGS,oaInstTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstTerm_doc[] = 
"Class: oaInstTerm\n"
"  The oaInstTerm class represents a connection between a net and a terminal in the master of an instance. The connection is proper if the number of bits in the net is equal to the number of bits implied by the instTerm's terminal name. In the case of oaVectorInsts, the net width must be multiplied by the number of bits represented by the instance name.\n"
"  InstTerms can exist that do not have a proper corresponding terminal in the master of the instance. This allows instTerms to be created when the instance master is not read in, and it allows changes to instTerms that happen before the master is updated. The traversal from an instTerm to its corresponding terminal will not succeed unless a terminal with an exactly matching name or position is present in the master.\n"
"  When an instTerm is created by specifying a terminal or terminal name, the instTerm is said to connect by name. Binding is done to the named terminal if it exists in the instance master. The width of the connection must match the width of the associated net. When an instTerm is created by specifying a terminal position, the instTerm is said to connect by position. Binding is to the terminal in the master that is assigned to the position and if the resulting connection width matches the width of the corresponding net. To avoid confusion, the instTerms associated with a particular instance must either all be connected by name or all by connected by position.\n"
"  oaInstTerm objects are always in the block domain. oaInstTerms can be physical-only instTerms that are only in the block hierarchy, or they can be cross-domain instTerms that directly correspond to an oaModInstTerm in the module domain and one or more oaOccInstTerm instances in the occurrence domain.\n"
"  The oaInstTerm class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: (const oaInstTerm&)\n"
"    Signature: oaInstTerm||cref-oaInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstTerm",
    sizeof(PyoaInstTermObject),
    0,
    (destructor)oaInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstTerm_static_create_doc[] = 
"Class: oaInstTerm, Function: create\n"
"  Paramegers: (oaNet,oaInst,oaTerm)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,oaTerm* term)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,ptr-oaTerm,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting the specified terminal in the master of the given instance to the specified net. You may specify a NULL net value.\n"
"    The instTerms associated with the instance must all be connected either by name or by position. An oacInstTermNetMismatchInRepeatedMembers exception is thrown if repeated bundle instTerm bits connect to different nets.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    term\n"
"    The terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    A pointer to the instTerm created.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacTermNotInInstMasterForInstTerm\n"
"    oacInstTermAlreadyExists\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"    oacInstTermMustBeByPosition\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"    oacInstTermNetMismatchInRepeatedMembers\n"
"  Paramegers: (oaNet,oaInst,oaTerm,oaBlockDomainVisibility)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,oaTerm* term,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,ptr-oaTerm,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting the specified terminal in the master of the given instance to the specified net. You may specify a NULL net value.\n"
"    The instTerms associated with the instance must all be connected either by name or by position. An oacInstTermNetMismatchInRepeatedMembers exception is thrown if repeated bundle instTerm bits connect to different nets.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    term\n"
"    The terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    A pointer to the instTerm created.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacTermNotInInstMasterForInstTerm\n"
"    oacInstTermAlreadyExists\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"    oacInstTermMustBeByPosition\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"    oacInstTermNetMismatchInRepeatedMembers\n"
"  Paramegers: (oaNet,oaInst,oaName)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,const oaName& termName)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,cref-oaName,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting the named terminal in the master of the given instance to the specified net. You can specify a NULL net value. InstTerms can be created with names of terminals that do not exist in the instance master; these instTerms are unbound until the named terminal is created in the instance master.\n"
"    The instTerms associated with the instance must all be connected either by name or by position. An oacInstTermNetMismatchInRepeatedMembers exception is thrown if repeated bundle instTerm bits connect to different nets.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    termName\n"
"    The name of the terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacInstTermAlreadyExists\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"    oacInstTermMustBeByPosition\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"    oacInstTermNetMismatchInRepeatedMembers\n"
"  Paramegers: (oaNet,oaInst,oaName,oaBlockDomainVisibility)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,const oaName& termName,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,cref-oaName,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting the named terminal in the master of the given instance to the specified net. You can specify a NULL net value. InstTerms can be created with names of terminals that do not exist in the instance master; these instTerms are unbound until the named terminal is created in the instance master.\n"
"    The instTerms associated with the instance must all be connected either by name or by position. An oacInstTermNetMismatchInRepeatedMembers exception is thrown if repeated bundle instTerm bits connect to different nets.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    termName\n"
"    The name of the terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacInstTermAlreadyExists\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"    oacInstTermMustBeByPosition\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"    oacInstTermNetMismatchInRepeatedMembers\n"
"  Paramegers: (oaNet,oaInst,oaUInt4)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,oaUInt4 termPosition)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,simple-oaUInt4,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting a terminal at the specified position in the master of the given instance to the specified net. You may specify a NULL net value.\n"
"    The instTerms associated with the instance must all be connected either by name or by position.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    termPosition\n"
"    The position of a terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacInstTermAlreadyExists\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"  Paramegers: (oaNet,oaInst,oaUInt4,oaBlockDomainVisibility)\n"
"    Calls: oaInstTerm* create(oaNet* net,oaInst* inst,oaUInt4 termPosition,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaInstTerm|ptr-oaNet,ptr-oaInst,simple-oaUInt4,simple-oaBlockDomainVisibility,\n"
"    This function creates an instTerm connecting a terminal at the specified position in the master of the given instance to the specified net. You may specify a NULL net value.\n"
"    The instTerms associated with the instance must all be connected either by name or by position.\n"
"    net\n"
"    The net to use for the connection; it may be NULL.\n"
"    inst\n"
"    The instance to make the connection to.\n"
"    termPosition\n"
"    The position of a terminal in the instance master to connect to.\n"
"    view\n"
"    Specifies the visibility of the instTerm to the module domain.\n"
"    oacNetAndInstNotInSameDesign\n"
"    oacInstTermAlreadyExists\n"
"    oacInstTermInstMustBeInUniqueOccHier\n"
"    oacInstTermNetMustBeInUniqueOccHier\n"
"  Paramegers: (oaInst,oaNetTermArray)\n"
"    Calls: void create(oaInst* inst,const oaNetTermArray& connData)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermArray,simple-oaBlockDomainVisibility,\n"
"    This function creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermArray that associates net and term pointers.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm pointer is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm pointer was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the number of specified bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where each entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"  Paramegers: (oaInst,oaNetTermArray,oaBlockDomainVisibility)\n"
"    Calls: void create(oaInst* inst,const oaNetTermArray& connData,oaBlockDomainVisibility view)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermArray,simple-oaBlockDomainVisibility,\n"
"    This function creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermArray that associates net and term pointers.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm pointer is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm pointer was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the number of specified bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where each entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"  Paramegers: (oaInst,oaNetTermNameArray)\n"
"    Calls: void create(oaInst* inst,const oaNetTermNameArray& connData)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermNameArray,simple-oaBlockDomainVisibility,\n"
"    This functions creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermNameArray that associates net pointers with term names.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm name is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm name was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the specified number of bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where ach entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"  Paramegers: (oaInst,oaNetTermNameArray,oaBlockDomainVisibility)\n"
"    Calls: void create(oaInst* inst,const oaNetTermNameArray& connData,oaBlockDomainVisibility view)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermNameArray,simple-oaBlockDomainVisibility,\n"
"    This functions creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermNameArray that associates net pointers with term names.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm name is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm name was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the specified number of bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where ach entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"  Paramegers: (oaInst,oaNetTermPosArray)\n"
"    Calls: void create(oaInst* inst,const oaNetTermPosArray& connData)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermPosArray,simple-oaBlockDomainVisibility,\n"
"    This function creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermPosArray that associates net pointers with term positions.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm position is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm position was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the specified number of bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where ach entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
"  Paramegers: (oaInst,oaNetTermPosArray,oaBlockDomainVisibility)\n"
"    Calls: void create(oaInst* inst,const oaNetTermPosArray& connData,oaBlockDomainVisibility view)\n"
"    Signature: create|void-void|ptr-oaInst,cref-oaNetTermPosArray,simple-oaBlockDomainVisibility,\n"
"    This function creates a set of instTerms, connecting the specified instance's terminals to the specified nets. The specifications for which terminals are connected to which nets are stored in an oaNetTermPosArray that associates net pointers with term positions.\n"
"    Important: This function is intended for use by performance-sensitive applications that create connectivity that is \"correct by construction.\" This function can have undesirable side effects if this expectation is violated and the specified connectivity is inconsistent: If a duplicate oaTerm position is encountered in the array during the execution of this function, all the oaInstTerms created before the duplicate oaTerm position was encountered are destroyed, but the design is still tagged as modified and undo records are created. If changes are then rolled back with an undo operation, the application will receive observer notifications for both the creation and the destruction of those oaInstTerms.\n"
"    Exceptions are thrown if:\n"
"    Any net and the given instance are not in the same design\n"
"    Any net is an implicit net\n"
"    Any terminal is not in the instance master design\n"
"    An instance of any terminal already exists where the net is not NULL\n"
"    A connection width does not match the specified number of bits in the net\n"
"    inst\n"
"    The instance on which the instTerms are created\n"
"    connData\n"
"    An array of instTerm specifications; where ach entry in the array describes a specification that is used to create a single instTerm\n"
"    view\n"
"    Specifies the visibility of each instTerm to the module domain\n"
"    oacInstTermBatchCreateHasInstTerms\n"
"    oacNetInstTermWidthMismatchForInstTerm\n"
;

static PyObject*
oaInstTerm_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaNet,oaInst,oaTerm)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaTerm p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaTerm_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaInst,oaTerm,oaBlockDomainVisibility)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaTerm p3;
        PyParamoaBlockDomainVisibility p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaTerm_Convert,&p3,
              &PyoaBlockDomainVisibility_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaInst,oaName)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaName_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaInst,oaName,oaBlockDomainVisibility)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaName p3;
        PyParamoaBlockDomainVisibility p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaName_Convert,&p3,
              &PyoaBlockDomainVisibility_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaInst,oaUInt4)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaInst,oaUInt4,oaBlockDomainVisibility)
    {
        PyParamoaNet p1;
        PyParamoaInst p2;
        PyParamoaUInt4 p3;
        PyParamoaBlockDomainVisibility p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaInst_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaBlockDomainVisibility_Convert,&p4)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstTermp result= (oaInstTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermArray)
    {
        PyParamoaInst p1;
        PyParamoaNetTermArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermArray,oaBlockDomainVisibility)
    {
        PyParamoaInst p1;
        PyParamoaNetTermArray p2;
        PyParamoaBlockDomainVisibility p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermArray_Convert,&p2,
              &PyoaBlockDomainVisibility_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermNameArray)
    {
        PyParamoaInst p1;
        PyParamoaNetTermNameArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermNameArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermNameArray,oaBlockDomainVisibility)
    {
        PyParamoaInst p1;
        PyParamoaNetTermNameArray p2;
        PyParamoaBlockDomainVisibility p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermNameArray_Convert,&p2,
              &PyoaBlockDomainVisibility_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermPosArray)
    {
        PyParamoaInst p1;
        PyParamoaNetTermPosArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermPosArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaNetTermPosArray,oaBlockDomainVisibility)
    {
        PyParamoaInst p1;
        PyParamoaNetTermPosArray p2;
        PyParamoaBlockDomainVisibility p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaNetTermPosArray_Convert,&p2,
              &PyoaBlockDomainVisibility_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTerm::create(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstTerm, function: create, Choices are:\n"
        "    (oaNet,oaInst,oaTerm)\n"
        "    (oaNet,oaInst,oaTerm,oaBlockDomainVisibility)\n"
        "    (oaNet,oaInst,oaName)\n"
        "    (oaNet,oaInst,oaName,oaBlockDomainVisibility)\n"
        "    (oaNet,oaInst,oaUInt4)\n"
        "    (oaNet,oaInst,oaUInt4,oaBlockDomainVisibility)\n"
        "    (oaInst,oaNetTermArray)\n"
        "    (oaInst,oaNetTermArray,oaBlockDomainVisibility)\n"
        "    (oaInst,oaNetTermNameArray)\n"
        "    (oaInst,oaNetTermNameArray,oaBlockDomainVisibility)\n"
        "    (oaInst,oaNetTermPosArray)\n"
        "    (oaInst,oaNetTermPosArray,oaBlockDomainVisibility)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaInstTerm_static_find_doc[] = 
"Class: oaInstTerm, Function: find\n"
"  Paramegers: (oaInst,oaTerm)\n"
"    Calls: oaInstTerm* find(const oaInst* inst,const oaTerm* term)\n"
"    Signature: find|ptr-oaInstTerm|cptr-oaInst,cptr-oaTerm,\n"
"    This function searches all of the instTerms associated with the specified instance and returns the one that is associated with the specified terminal. NULL is returned if no such terminal exists on the instance.\n"
"    inst\n"
"    The instance whose instTerms are searched.\n"
"    term\n"
"    The terminal to use in the search.\n"
"    oacTermNotInInstMasterForInstTerm\n"
"    oacInstTermInstUsesTermPosition\n"
"  Paramegers: (oaInst,oaName)\n"
"    Calls: oaInstTerm* find(const oaInst* inst,const oaName& termName)\n"
"    Signature: find|ptr-oaInstTerm|cptr-oaInst,cref-oaName,\n"
"    This function searches all of the instTerms associated with the specified instance and returns the one that makes a connection to the named terminal. NULL is returned if no such terminal exists on the instance.\n"
"    inst\n"
"    The instance whose instTerms are searched.\n"
"    termName\n"
"    The terminal name to use in the search.\n"
"    oacInstTermInstUsesTermPosition\n"
"  Paramegers: (oaInst,oaUInt4)\n"
"    Calls: oaInstTerm* find(const oaInst* inst,oaUInt4 termPosition)\n"
"    Signature: find|ptr-oaInstTerm|cptr-oaInst,simple-oaUInt4,\n"
"    This function searches all of the instTerms associated with the specified instance and returns the one that makes a connection to the specified terminal position. NULL is returned if no terminal exists in the instance master at the specified position.\n"
"    inst\n"
"    The instance whose instTerms are searched.\n"
"    termPosition\n"
"    The terminal position used in the search.\n"
"    oacInstTermInstUsesTermName\n"
;

static PyObject*
oaInstTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaInst,oaTerm)
    {
        PyParamoaInst p1;
        PyParamoaTerm p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaTerm_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaInstTermp result= (oaInstTerm::find(p1.Data(),p2.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaName)
    {
        PyParamoaInst p1;
        PyParamoaName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTermp result= (oaInstTerm::find(p1.Data(),p2.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaInst,oaUInt4)
    {
        PyParamoaInst p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaInst_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaInstTermp result= (oaInstTerm::find(p1.Data(),p2.Data()));
            return PyoaInstTerm_FromoaInstTerm(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaInstTerm, function: find, Choices are:\n"
        "    (oaInst,oaTerm)\n"
        "    (oaInst,oaName)\n"
        "    (oaInst,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaInstTerm_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaInstTerm_static_create,METH_VARARGS,oaInstTerm_static_create_doc},
    {"static_find",(PyCFunction)oaInstTerm_static_find,METH_VARARGS,oaInstTerm_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstTerm",
           (PyObject*)(&PyoaInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaInstTerm_Type.tp_dict;
    for(method=oaInstTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaInstTermAttrType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaInstTermAttrType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaInstTermAttrType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaInstTermAttrTypeObject* self = (PyoaInstTermAttrTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaInstTermAttrTypeEnum)
    {
        PyParamoaInstTermAttrTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaInstTermAttrTypeEnum_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstTermAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstTermAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaAttrType)
    {
        PyParamoaAttrType p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAttrType_Convert,&p1)) {
            self->value = (oaAttrType*)  new oaInstTermAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaInstTermAttrType)
    {
        PyParamoaInstTermAttrType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaInstTermAttrType_Convert,&p1)) {
            self->value=(oaAttrType*)  new oaInstTermAttrType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaInstTermAttrType, Choices are:\n"
        "    (oaInstTermAttrTypeEnum)\n"
        "    (oaString)\n"
        "    (oaAttrType)\n"
        "    (oaInstTermAttrType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaInstTermAttrType_tp_dealloc(PyoaInstTermAttrTypeObject* self)
{
    if (!self->borrow) {
        delete (oaInstTermAttrType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaInstTermAttrType_tp_repr(PyObject *ob)
{
    PyParamoaInstTermAttrType value;
    int convert_status=PyoaInstTermAttrType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaInstTermAttrType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaInstTermAttrType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaInstTermAttrType v1;
    PyParamoaInstTermAttrType v2;
    int convert_status1=PyoaInstTermAttrType_Convert(ob1,&v1);
    int convert_status2=PyoaInstTermAttrType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaInstTermAttrType_Convert(PyObject* ob,PyParamoaInstTermAttrType* result)
{
    if (ob == NULL) return 1;
    if (PyoaInstTermAttrType_Check(ob)) {
        result->SetData( (oaInstTermAttrType*) ((PyoaInstTermAttrTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaInstTermAttrType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaInstTermAttrType_FromoaInstTermAttrType(oaInstTermAttrType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaInstTermAttrType_Type.tp_alloc(&PyoaInstTermAttrType_Type,0);
        if (bself == NULL) return bself;
        PyoaInstTermAttrTypeObject* self = (PyoaInstTermAttrTypeObject*)bself;
        self->value = (oaAttrType*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstTermAttrType_getName_doc[] = 
"Class: oaInstTermAttrType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaInstTermAttrTypeEnum object.\n"
;

static PyObject*
oaInstTermAttrType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTermAttrType data;
    int convert_status=PyoaInstTermAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermAttrTypeObject* self=(PyoaInstTermAttrTypeObject*)ob;

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
static char oaInstTermAttrType_getValue_doc[] = 
"Class: oaInstTermAttrType, Function: getValue\n"
"  Paramegers: ()\n"
"    Calls: oaInstTermAttrTypeEnum getValue() const\n"
"    Signature: getValue|simple-oaInstTermAttrTypeEnum|\n"
"    BrowseData: 1\n"
"    This function returns the value string of this instTerm attribute type.\n"
;

static PyObject*
oaInstTermAttrType_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaInstTermAttrType data;
    int convert_status=PyoaInstTermAttrType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaInstTermAttrTypeObject* self=(PyoaInstTermAttrTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInstTermAttrTypeEnum result= (data.DataCall()->getValue());
        return PyoaInstTermAttrTypeEnum_FromoaInstTermAttrTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaInstTermAttrType_assign_doc[] = 
"Class: oaInstTermAttrType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaInstTermAttrType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaInstTermAttrType data;
  int convert_status=PyoaInstTermAttrType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaInstTermAttrType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaInstTermAttrType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaInstTermAttrType_methodlist[] = {
    {"getName",(PyCFunction)oaInstTermAttrType_getName,METH_VARARGS,oaInstTermAttrType_getName_doc},
    {"getValue",(PyCFunction)oaInstTermAttrType_getValue,METH_VARARGS,oaInstTermAttrType_getValue_doc},
    {"assign",(PyCFunction)oaInstTermAttrType_tp_assign,METH_VARARGS,oaInstTermAttrType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaInstTermAttrType_doc[] = 
"Class: oaInstTermAttrType\n"
"  The oaInstTermAttrType class is an enum wrapper class for the attributes of an oaInstTerm that can be handled by an oaAttrDisplay object that is attached to an instTerm.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaInstTermAttrTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaInstTermAttrTypeEnum)\n"
"    Calls: oaInstTermAttrType(oaInstTermAttrTypeEnum valueIn)\n"
"    Signature: oaInstTermAttrType||simple-oaInstTermAttrTypeEnum,\n"
"    This function constructs an instance of an oaInstTermAttrType class using the specified #oaInstTermAttrTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaInstTermAttrType(const oaString& name)\n"
"    Signature: oaInstTermAttrType||cref-oaString,\n"
"    This function constructs an instance of an oaInstTermAttrType class using the #oaInstTermAttrTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaInstTermAttrTypeEnum.\n"
"    oacInvalidInstTermAttrTypeName\n"
"  Paramegers: (oaAttrType)\n"
"    Calls: oaInstTermAttrType(oaAttrType attr)\n"
"    Signature: oaInstTermAttrType||simple-oaAttrType,\n"
"    This function constructs an oaInstTermAttrType class using the oaAttrType as input to support the class down-cast.\n"
"  Paramegers: (oaInstTermAttrType)\n"
"    Calls: (const oaInstTermAttrType&)\n"
"    Signature: oaInstTermAttrType||cref-oaInstTermAttrType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaInstTermAttrType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaInstTermAttrType",
    sizeof(PyoaInstTermAttrTypeObject),
    0,
    (destructor)oaInstTermAttrType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaInstTermAttrType_tp_compare,	/* tp_compare */
    (reprfunc)oaInstTermAttrType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaInstTermAttrType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaInstTermAttrType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAttrType_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaInstTermAttrType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaInstTermAttrType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaInstTermAttrType_Type)<0) {
      printf("** PyType_Ready failed for: oaInstTermAttrType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaInstTermAttrType",
           (PyObject*)(&PyoaInstTermAttrType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaInstTermAttrType\n");
       return -1;
    }
    return 0;
}

